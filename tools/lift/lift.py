# lift.py: ca65 subset to portable C with explicit CPU state (see runtime.h).
# usage: lift.py ASM_PATH OUT_C BANK ENTRY[,ENTRY2,...]
# Each ENTRY label starts a new C function (forward-declared up top).
# - fall-through between entries becomes a tail call (asm PC advances).
# - jsr LABEL becomes a C call (decls same-file, TU order cross-file).
# - jmp LABEL: goto (same function) or tail call (another entry).
# - branches: goto (same function, incl. self top), call+return (entry).
# Unknown ops and outside-region targets fail fast.
import re
import sys
HEX = '0123456789ABCDEFabcdef'
def base_of(t):
    t = t.strip()
    if t.startswith('entry_'):
        t = t[6:]
    if t.startswith('$'):
        return '0x' + t[1:]
    if len(t) == 5 and t[0] == 'L' and all(c in HEX for c in t[1:]):
        return '0x' + t[1:]
    if len(t) == 4 and all(c in HEX for c in t):
        return '0x' + t
    assert t.isdigit(), 'bad address term: ' + t
    return str(int(t))
def addr_of(tok):
    tok = tok.strip()
    parts = re.split('([+-])', tok)
    if len(parts) == 1:
        return base_of(tok)
    out = []
    for i, q in enumerate(parts):
        if i % 2 == 1:
            assert q in ('+', '-'), 'bad op: ' + tok
            out.append(' ' + q + ' ')
        else:
            out.append(base_of(q))
    return '(' + ''.join(out) + ')'
def split_mem(arg):
    arg = arg.strip()
    if arg.startswith('('):
        j = arg.find(')')
        assert j > 0, 'bad indirect: ' + arg
        inner = arg[1:j].strip()
        sfx = arg[j+1:].strip()
        assert sfx in (',y', ',x'), 'bad indirect suffix: ' + arg
        return ('ind', addr_of(inner), 'Y' if sfx == ',y' else 'X')
    low = arg.lower()
    if low.endswith(',x'):
        return ('idx', addr_of(arg[:-2]), 'X')
    if low.endswith(',y'):
        return ('idx', addr_of(arg[:-2]), 'Y')
    return ('dir', addr_of(arg), None)
def rd_of(arg):
    kind, base, idx = split_mem(arg)
    if kind == 'ind':
        return 'RD((uint16_t)(RD(%s) | ((uint16_t)RD((uint16_t)((%s + 1) & 0xFF)) << 8)) + %s)' % (base, base, idx)
    if idx is not None:
        return 'RD((uint16_t)(%s + %s))' % (base, idx)
    return 'RD(%s)' % base
def wr_of(arg, val):
    kind, base, idx = split_mem(arg)
    if kind == 'ind':
        return 'WR((uint16_t)(RD(%s) | ((uint16_t)RD((uint16_t)((%s + 1) & 0xFF)) << 8)) + %s, %s);' % (base, base, idx, val)
    if idx is not None:
        return 'WR((uint16_t)(%s + %s), %s);' % (base, idx, val)
    return 'WR(%s, %s);' % (base, val)
def imm_of(arg):
    arg = arg.strip()
    assert arg[0:2] == '#$', arg
    return '0x' + arg[2:]
BR = {
    'bne': '(!(P & 0x02))',
    'beq': '((P & 0x02))',
    'bcc': '(!(P & 0x01))',
    'bcs': '((P & 0x01))',
    'bpl': '(!(P & 0x80))',
    'bmi': '((P & 0x80))',
    'bvs': '((P & 0x40))',
    'bvc': '(!(P & 0x40))',
}
asm_path, out_path, bank, entry_arg = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
stub_arg = sys.argv[5] if len(sys.argv) > 5 else ''
stubset = set(stub_arg.split(',')) if stub_arg else set()
entries = entry_arg.split(',')
vec_paths_in = []
amap_paths_in = []
prov_paths_in = []
jtab_paths_in = []
unwind_mode_in = []
for _a in sys.argv[6:]:
    if _a.startswith('VEC:'): vec_paths_in.append(_a[4:])
    elif _a.startswith('ADDRMAP:'): amap_paths_in.append(_a[8:])
    elif _a.startswith('PROV:'): prov_paths_in.append(_a[5:])
    elif _a.startswith('JMPTAB:'): jtab_paths_in.append(_a[7:])
    elif _a.startswith('UNWIND:'): unwind_mode_in.append(_a[7:])
    elif _a.startswith('XBANK:'): raise AssertionError('XBANK retired; use ADDRMAP')
    elif _a: vec_paths_in.append(_a)
assert len(unwind_mode_in) <= 1, 'one UNWIND mode for now'
unwind_mode = unwind_mode_in[0] if unwind_mode_in else 'off'
assert unwind_mode in ('off', 'log', 'enforce'), 'bad UNWIND mode: ' + unwind_mode
assert len(vec_paths_in) <= 1 and len(amap_paths_in) <= 1 and len(prov_paths_in) <= 1 and len(jtab_paths_in) <= 1, 'one spec file each for now'
vec_arg = vec_paths_in[0] if vec_paths_in else ''
banknum = int(bank[1:])
vecmap = {}
if vec_arg:
    for _vln in open(vec_arg):
        _p = _vln.split('#', 1)[0].split()
        if not _p:
            continue
        assert len(_p) >= 3, 'bad vec spec line'
        _va, _vb = int(_p[0], 16), int(_p[1])
        assert 0 <= _va <= 0xFFFF and _vb in (0, 1, 2, 3, 4, 5, 6, 7), 'bad vec header'
        vecmap.setdefault(_va, []).extend([(_vb, int(_t, 16)) for _t in _p[2:]])
def vecfn(_va):
    return '%s_vec_%04X' % (bank, _va)
_winlo = 0xC000 if banknum == 7 else 0x8000
_winhi = 0xFFFF if banknum == 7 else 0xBFFF
amap = {}
amap_arg = amap_paths_in[0] if amap_paths_in else ''
if amap_arg:
    for _aln in open(amap_arg):
        _ap = _aln.split('#', 1)[0].split()
        if not _ap:
            continue
        assert len(_ap) == 3, 'bad addrmap spec line'
        _aa, _ab, _an = int(_ap[0], 16), int(_ap[1]), _ap[2]
        assert 0 <= _aa <= 0xFFFF and _ab in (0, 1, 2, 3, 4, 5, 6, 7), 'bad addrmap header'
        assert (_aa, _ab) not in amap, 'dup addrmap addr'
        amap[(_aa, _ab)] = _an
slots = {}
jtab_arg = jtab_paths_in[0] if jtab_paths_in else ''
if jtab_arg:
    for _jln in open(jtab_arg):
        _jp = _jln.split('#', 1)[0].split()
        if not _jp:
            continue
        assert len(_jp) == 2, 'bad jmptab spec line'
        _ja, _jb = int(_jp[0], 16), int(_jp[1], 16)
        assert 0 <= _ja <= 0xFFFF and 0 <= _jb <= 0xFFFF, 'bad jmptab header'
        assert _ja not in slots, 'dup jmptab slot'
        slots[_ja] = _jb
prov = set()
prov_arg = prov_paths_in[0] if prov_paths_in else ''
if prov_arg:
    for _pln in open(prov_arg):
        _pp = _pln.split('#', 1)[0].split()
        if not _pp:
            continue
        assert len(_pp) == 2, 'bad prov spec line'
        assert _pp[1] in ('0', '1', '2', '3', '4', '5', '6', '7'), 'bad prov bank'
        prov.add((_pp[0], int(_pp[1])))
def labaddr_opt(lbl):
    t = lbl.strip()
    if t.startswith('entry_'): t = t[6:]
    elif t.startswith('L'): t = t[1:]
    else: return None
    if len(t) != 4: return None
    if not all(c in HEX for c in t): return None
    return int(t, 16)
def xresolve(lbl):
    a = labaddr_opt(lbl)
    if a is None: return None
    if (a, banknum) in amap: return None
    if a in slots: a = slots[a]
    hits = [(b, n) for ((aa, b), n) in amap.items() if aa == a]
    if not hits: return None
    assert len(hits) == 1, 'ambiguous addrmap addr: ' + lbl
    return hits[0]
def vectgt(_vb, _t):
    if _winlo <= _t <= _winhi:
        _hit = amap.get((_t, banknum))
        if _hit is not None:
            return '%s_%s' % (bank, _hit)
        return '%s_L%04X' % (bank, _t)
    _hit = amap.get((_t, _vb))
    if _hit is not None:
        return 'b%d_%s' % (_vb, _hit)
    return 'b%d_L%04X' % (_vb, _t)

lines = open(asm_path).read().split(chr(10))
src_order = []
all_labels = set()
self_tgt = set()
refd = set()
vecsites = set()
xcross = set()
pre_cur = None
for raw2 in lines:
    ln2 = raw2.split(';')[0]
    if not ln2.strip():
        continue
    s2 = ln2.strip()
    if ln2[0] != ' ' and ln2[0] != chr(9) and ':' in s2:
        nm, rr = s2.split(':', 1)
        nm = nm.strip()
        all_labels.add(nm)
        if nm in entries:
            pre_cur = nm
            if nm not in src_order:
                src_order.append(nm)
        s2 = rr.strip()
        if not s2:
            continue
    p2 = s2.split(None, 1)
    if len(p2) == 2 and p2[0] == 'jmp' and p2[1].strip().startswith('('):
        _vi = p2[1].strip()
        assert _vi.endswith(')'), 'bad jmp indirect: ' + _vi
        vecsites.add(int(base_of(_vi[1:-1].strip()), 16))
    elif len(p2) == 2 and (p2[0] in BR or p2[0] in ('jsr', 'jmp')):
        if len(p2) == 2 and p2[0] in BR or (len(p2) == 2 and p2[0] == 'jmp'):
            refd.add(p2[1].strip())
        _xr = xresolve(p2[1].strip())
        if _xr is not None:
            xcross.add(_xr)
        if p2[1].strip() == pre_cur and pre_cur is not None:
            self_tgt.add(pre_cur)
out = []
out.append('#include "runtime.h"')
for e in entries:
    out.append('static void %s_%s(void);' % (bank, e))
for e in sorted(stubset - set(entries)):
    if xresolve(e) is None:
        out.append('static void %s_%s(void);' % (bank, e))
for (_tb, _tn) in sorted(xcross):
    out.append('static void b%d_%s(void);' % (_tb, _tn))
for _va in sorted(vecsites):
    assert _va in vecmap, 'vec site without targets: %04X' % _va
    out.append('static void %s(void);' % vecfn(_va))
_vtdecl = set()
for _va in sorted(vecsites):
    for (_vb, _t) in vecmap[_va]:
        _vtdecl.add(vectgt(_vb, _t))
for _n in sorted(_vtdecl):
    out.append('static void %s(void);' % _n)
cur = None
found = set()
last_op = None
for raw in lines:
    ln = raw.split(';')[0]
    if not ln.strip():
        continue
    s = ln.strip()
    if ln[0] != ' ' and ln[0] != chr(9) and ':' in s:
        name, rest = s.split(':', 1)
        name = name.strip()
        if name in entries:
            if cur is not None:
                if last_op not in ('rts', 'jmp'):
                    assert cur != src_order[-1], 'unterminated entry: ' + cur
                    nx = src_order[src_order.index(cur) + 1]
                    out.append('%s_%s();' % (bank, nx))
                    out.append('return;')
                out.append('}')
            last_op = None
            out.append('static void __attribute__((used)) %s_%s(void) {' % (bank, name))
            if name in self_tgt:
                out.append('%s_%s_top:;' % (bank, name))
            cur = name
            found.add(name)
        else:
            assert cur is not None, 'label outside entry: ' + s
            if name in refd:
                out.append('%s_%s:;' % (bank, name))
        s = rest.strip()
        if not s:
            continue
    assert cur is not None, 'code outside entry: ' + s
    parts = s.split(None, 1)
    last_op = parts[0]
    op = parts[0]
    arg = parts[1].strip() if len(parts) > 1 else ''
    if op == 'ldx' and arg.startswith('#'):
        out.append('X = %s; setZN(X);' % imm_of(arg))
    elif op == 'ldx':
        out.append('X = %s; setZN(X);' % rd_of(arg))
    elif op == 'ldy' and arg.startswith('#'):
        out.append('Y = %s; setZN(Y);' % imm_of(arg))
    elif op == 'ldy':
        out.append('Y = %s; setZN(Y);' % rd_of(arg))
    elif op == 'lda' and arg.startswith('#'):
        out.append('A = %s; setZN(A);' % imm_of(arg))
    elif op == 'lda':
        out.append('A = %s; setZN(A);' % rd_of(arg))
    elif op == 'inx':
        out.append('X = (uint8_t)(X + 1); setZN(X);')
    elif op == 'dex':
        out.append('X = (uint8_t)(X - 1); setZN(X);')
    elif op == 'iny':
        out.append('Y = (uint8_t)(Y + 1); setZN(Y);')
    elif op == 'dey':
        out.append('Y = (uint8_t)(Y - 1); setZN(Y);')
    elif op == 'tax':
        out.append('X = A; setZN(X);')
    elif op == 'txa':
        out.append('A = X; setZN(A);')
    elif op == 'tay':
        out.append('Y = A; setZN(Y);')
    elif op == 'tya':
        out.append('A = Y; setZN(A);')
    elif op == 'tsx':
        out.append('X = S; setZN(X);')
    elif op == 'txs':
        out.append('S = X;')
    elif op == 'pha':
        out.append('stk[S] = A; S = (uint8_t)(S - 1);')
    elif op == 'plp':
        out.append('S = (uint8_t)(S + 1); P = (uint8_t)(stk[S] | 0x30);')
    elif op == 'php':
        out.append('stk[S] = (uint8_t)(P | 0x30); S = (uint8_t)(S - 1);')
    elif op == 'pla':
        out.append('S = (uint8_t)(S + 1); A = stk[S]; setZN(A);')
    elif op == 'sec':
        out.append('P = (uint8_t)(P | 0x01);')
    elif op == 'clc':
        out.append('P = (uint8_t)(P & 0xFE);')
    elif op == 'sei':
        out.append('P = (uint8_t)(P | 0x04);')
    elif op == 'cli':
        out.append('P = (uint8_t)(P & 0xFB);')
    elif op == 'cld':
        out.append('P = (uint8_t)(P & 0xF7);')
    elif op == 'stx':
        out.append(wr_of(arg, 'X'))
    elif op == 'sty':
        out.append(wr_of(arg, 'Y'))
    elif op == 'sta':
        out.append(wr_of(arg, 'A'))
    elif op == 'and':
        out.append('{ uint8_t _m = %s; A = (uint8_t)(A & _m); setZN(A); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'eor':
        out.append('{ uint8_t _m = %s; A = (uint8_t)(A ^ _m); setZN(A); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'ora':
        out.append('{ uint8_t _m = %s; A = (uint8_t)(A | _m); setZN(A); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'rol' and arg == 'a':
        out.append('{ uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (A >> 7)); A = (uint8_t)((A << 1) | _c); setZN(A); }')
    elif op == 'ror' and arg == 'a':
        out.append('{ uint8_t _c = (uint8_t)((P & 1) << 7); P = (uint8_t)((P & 0xFE) | (A & 1)); A = (uint8_t)(_c | (A >> 1)); setZN(A); }')
    elif op == 'rol':
        out.append('{ uint8_t _v = %s; uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (_v >> 7)); _v = (uint8_t)((_v << 1) | _c); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'ror':
        out.append('{ uint8_t _v = %s; uint8_t _c = (uint8_t)((P & 1) << 7); P = (uint8_t)((P & 0xFE) | (_v & 1)); _v = (uint8_t)(_c | (_v >> 1)); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'asl' and arg == 'a':
        out.append('P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);')
    elif op == 'lsr' and arg == 'a':
        out.append('P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);')
    elif op == 'asl':
        out.append('{ uint8_t _v = %s; P = (uint8_t)((P & 0xFE) | (_v >> 7)); _v = (uint8_t)(_v << 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'lsr':
        out.append('{ uint8_t _v = %s; P = (uint8_t)((P & 0xFE) | (_v & 1)); _v = (uint8_t)(_v >> 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'dec':
        out.append('{ uint8_t _v = (uint8_t)(%s - 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'inc':
        out.append('{ uint8_t _v = (uint8_t)(%s + 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'bit':
        out.append('{ uint8_t _m = %s; P = (uint8_t)((P & 0x3D) | (_m & 0xC0) | (((A & _m) == 0) ? 0x02 : 0)); }' % rd_of(arg))
    elif op == 'adc':
        out.append('{ uint8_t _m = %s; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'sbc':
        out.append('{ uint8_t _m = %s; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'cmp':
        out.append('{ uint8_t _m = %s; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'cpx':
        out.append('{ uint8_t _m = %s; uint8_t _r = (uint8_t)(X - _m); P = (uint8_t)((P & 0x7C) | (X >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op == 'cpy':
        out.append('{ uint8_t _m = %s; uint8_t _r = (uint8_t)(Y - _m); P = (uint8_t)((P & 0x7C) | (Y >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }' % (imm_of(arg) if arg.startswith('#') else rd_of(arg)))
    elif op in BR:
        cond = BR[op]
        _xr = xresolve(arg)
        if _xr is not None:
            out.append('if (%s) { b%d_%s(); return; }' % (cond, _xr[0], _xr[1]))
        elif arg == cur:
            out.append('if (%s) goto %s_%s_top;' % (cond, bank, cur))
        elif arg in entries or arg in stubset:
            out.append('if (%s) { %s_%s(); return; }' % (cond, bank, arg))
        else:
            assert arg in all_labels, 'branch target outside lifted regions: ' + arg
            out.append('if (%s) goto %s_%s;' % (cond, bank, arg))
    elif op == 'jsr':
        assert arg and arg[0] not in ('$', '#'), 'jsr needs a label target: ' + arg
        _xr = xresolve(arg)
        if _xr is not None:
            _callee = 'b%d_%s' % (_xr[0], _xr[1])
        else:
            _callee = '%s_%s' % (bank, arg)
        _caller = '%s_%s' % (bank, cur)
        if unwind_mode == 'off':
            out.append('S = (uint8_t)(S - 2);')
            out.append(_callee + '();')
            out.append('S = (uint8_t)(S + 2);')
        elif unwind_mode == 'log':
            out.append('S = (uint8_t)(S - 2);')
            out.append('{ uint8_t _uw_s = S; ' + _callee + '(); if (S != _uw_s) fprintf(stderr, ' + chr(34) + 'UNWIND caller=%s callee=%s S=%02X want=%02X' + chr(92) + 'n' + chr(34) + ', ' + chr(34) + _caller + chr(34) + ', ' + chr(34) + _callee + chr(34) + ', S, _uw_s); }')
            out.append('S = (uint8_t)(S + 2);')
        else:
            out.append('S = (uint8_t)(S - 2);')
            out.append('{ uint8_t _uw_s = S; ' + _callee + '(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, ' + chr(34) + 'UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X' + chr(92) + 'n' + chr(34) + ', ' + chr(34) + _caller + chr(34) + ', ' + chr(34) + _callee + chr(34) + ', S, _uw_s); } if (uw_abort) return; }')
            out.append('S = (uint8_t)(S + 2);')
    elif op == 'jmp' and arg.startswith('('):
        assert arg.endswith(')'), 'bad jmp indirect: ' + arg
        out.append('%s(); return;' % vecfn(int(base_of(arg[1:-1].strip()), 16)))
    elif op == 'jmp':
        assert arg and arg[0] not in ('$', '#', '('), 'jmp needs a plain label target: ' + arg
        _xr = xresolve(arg)
        if _xr is not None:
            out.append('b%d_%s(); return;' % (_xr[0], _xr[1]))
        elif arg == cur:
            out.append('goto %s_%s_top;' % (bank, cur))
        elif arg in entries or arg in stubset:
            out.append('%s_%s(); return;' % (bank, arg))
        else:
            assert arg in all_labels, 'jmp target outside lifted regions: ' + arg
            out.append('goto %s_%s;' % (bank, arg))
    elif op == 'rts':
        out.append('return;')
    elif op == 'nop':
        out.append(';')
    else:
        raise AssertionError('unsupported op: ' + s)
if cur is not None:
    if last_op not in ('rts', 'jmp'):
        assert cur != src_order[-1], 'unterminated final entry: ' + cur
        nx = src_order[src_order.index(cur) + 1]
        out.append('%s_%s();' % (bank, nx))
        out.append('return;')
    out.append('}')
for st in sorted(stubset):
    if xresolve(st) is None:
        out.append('static void %s_%s(void) { __builtin_trap(); }' % (bank, st))
for (_tb, _tn) in sorted(xcross):
    if (_tn, _tb) not in prov:
        out.append('static void b%d_%s(void) { __builtin_trap(); }' % (_tb, _tn))
_vtdef = set()
for _va in sorted(vecsites):
    for (_vb, _t) in vecmap[_va]:
        _vtdef.add(vectgt(_vb, _t))
_defined = set(['%s_%s' % (bank, _e) for _e in entries] + ['%s_%s' % (bank, _s) for _s in stubset])
for _n in sorted(_vtdef - _defined):
    _pb, _pl = int(_n[1]), _n.split('_', 1)[1]
    assert _n[0] == 'b' and _pb in (0, 1, 2, 3, 4, 5, 6, 7), 'bad vec def name: ' + _n
    if (_pl, _pb) not in prov:
        out.append('static void %s(void) { __builtin_trap(); }' % _n)
for _va in sorted(vecsites):
    out.append('static void %s(void) {' % vecfn(_va))
    out.append('uint16_t _v = (uint16_t)(RD(0x%04X) | ((uint16_t)RD(0x%04X) << 8));' % (_va, (_va + 1) & 0xFFFF))
    out.append('switch (_v) {')
    _seen = set()
    for (_vb, _t) in sorted(vecmap[_va]):
        assert _t not in _seen, 'vec target value under two banks: %04X' % _t
        _seen.add(_t)
        out.append('case 0x%04X: %s(); break;' % (_t, vectgt(_vb, _t)))
    out.append('default: __builtin_trap();')
    out.append('}')
    out.append('}')
missing = [e for e in entries if e not in found and e not in stubset]
assert not missing, 'entry labels not found: ' + ','.join(missing)
open(out_path, 'w').write(chr(10).join(out) + chr(10))
print('lifted ' + entry_arg + ' -> ' + out_path)
