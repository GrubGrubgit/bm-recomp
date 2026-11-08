# lift.py v2: ca65 subset to portable C with explicit CPU state (see runtime.h).
# usage: lift.py ASM_PATH OUT_C BANK ENTRY[,ENTRY2,...]
# Each ENTRY label starts a new C function (forward-declared up top);
# other labels become goto labels. Unknown ops fail fast.
import sys
def addr_of(tok):
    tok = tok.strip()
    if tok.startswith('$'):
        return '0x' + tok[1:]
    if len(tok) == 5 and tok[0] == 'L' and all(c in '0123456789ABCDEFabcdef' for c in tok[1:]):
        return '0x' + tok[1:]
    raise AssertionError('bad address operand: ' + tok)
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
asm_path, out_path, bank, entry_arg = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
entries = entry_arg.split(',')
lines = open(asm_path).read().split(chr(10))
out = []
out.append('#include "runtime.h"')
for e in entries:
    out.append('static void %s_%s(void);' % (bank, e))
cur = None
found = set()
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
                out.append('}')
            out.append('static void %s_%s(void) {' % (bank, name))
            cur = name
            found.add(name)
        else:
            assert cur is not None, 'label outside entry: ' + s
            out.append('%s:;' % name)
        s = rest.strip()
        if not s:
            continue
    assert cur is not None, 'code outside entry: ' + s
    parts = s.split(None, 1)
    op = parts[0]
    arg = parts[1].strip() if len(parts) > 1 else ''
    if op == 'ldx' and arg.startswith('#'):
        out.append('X = %s; setZN(X);' % imm_of(arg))
    elif op == 'ldx':
        out.append('X = %s; setZN(X);' % rd_of(arg))
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
    elif op == 'pla':
        out.append('S = (uint8_t)(S + 1); A = stk[S]; setZN(A);')
    elif op == 'sec':
        out.append('P = (uint8_t)(P | 0x01);')
    elif op == 'stx':
        out.append(wr_of(arg, 'X'))
    elif op == 'sta':
        out.append(wr_of(arg, 'A'))
    elif op == 'and':
        out.append('A = (uint8_t)(A & %s); setZN(A);' % imm_of(arg))
    elif op == 'eor':
        out.append('A = (uint8_t)(A ^ %s); setZN(A);' % imm_of(arg))
    elif op == 'ora':
        out.append('A = (uint8_t)(A | %s); setZN(A);' % imm_of(arg))
    elif op == 'cmp' and arg.startswith('#'):
        out.append('{ uint8_t _r = (uint8_t)(A - %s); P = (uint8_t)((P & 0x7C) | (A >= %s ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }' % (imm_of(arg), imm_of(arg)))
    elif op == 'rol':
        out.append('{ uint8_t _v = %s; uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (_v >> 7)); _v = (uint8_t)((_v << 1) | _c); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'dec':
        out.append('{ uint8_t _v = (uint8_t)(%s - 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'inc':
        out.append('{ uint8_t _v = (uint8_t)(%s + 1); %s setZN(_v); }' % (rd_of(arg), wr_of(arg, '_v')))
    elif op == 'asl' and arg == 'a':
        out.append('P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);')
    elif op == 'lsr' and arg == 'a':
        out.append('P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);')
    elif op == 'bne':
        out.append('if (!(P & 0x02)) goto %s;' % arg)
    elif op == 'beq':
        out.append('if (P & 0x02) goto %s;' % arg)
    elif op == 'bcc':
        out.append('if (!(P & 0x01)) goto %s;' % arg)
    elif op == 'bcs':
        out.append('if (P & 0x01) goto %s;' % arg)
    elif op == 'bpl':
        out.append('if (!(P & 0x80)) goto %s;' % arg)
    elif op == 'bmi':
        out.append('if (P & 0x80) goto %s;' % arg)
    elif op == 'sbc':
        out.append('{ uint8_t _m = %s; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }' % imm_of(arg))
    elif op == 'jsr':
        assert arg and arg[0] not in ('$', '#'), 'jsr needs a label target: ' + arg
        out.append('b7_%s();' % arg)
    elif op == 'rts':
        out.append('return;')
    elif op == 'nop':
        out.append(';')
    else:
        raise AssertionError('unsupported op: ' + s)
if cur is not None:
    out.append('}')
missing = [e for e in entries if e not in found]
assert not missing, 'entry labels not found: ' + ','.join(missing)
open(out_path, 'w').write(chr(10).join(out) + chr(10))
print('lifted ' + entry_arg + ' -> ' + out_path)
