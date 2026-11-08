# lift.py prototype: subset of ca65 (labels, core ALU/load/store/branch ops)
# to portable C with explicit CPU state (see runtime.h).
# usage: lift.py ASM_PATH OUT_C BANK ENTRY_LABEL
import sys
def addrnum(op):
    op = op.strip()
    assert op[0] == '$', op
    return '0x' + op[1:]
def immnum(op):
    op = op.strip()
    assert op[0:2] == '#$', op
    return '0x' + op[2:]
OPS = set(['ldx','inx','dex','stx','lda','and','cmp','rol','bne','rts','nop'])
asm_path, out_path, bank, entry = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
lines = open(asm_path).read().split(chr(10))
out = []
out.append('#include "runtime.h"')
first = True
for raw in lines:
    ln = raw.split(';')[0]
    if not ln.strip():
        continue
    s = ln.strip()
    if ln[0] != ' ' and ln[0] != chr(9) and ':' in s:
        name, rest = s.split(':', 1)
        name = name.strip()
        if first and name == entry:
            out.append('static void %s_%s(void) {' % (bank, name))
            first = False
        else:
            out.append('%s:;' % name)
        s = rest.strip()
        if not s:
            continue
    parts = s.split(None, 1)
    assert parts[0] in OPS, 'unsupported op: ' + s
    op = parts[0]
    arg = parts[1].strip() if len(parts) > 1 else ''
    if op == 'ldx' and arg.startswith('#'):
        out.append('X = %s; setZN(X);' % immnum(arg))
    elif op == 'ldx':
        out.append('X = RD(%s); setZN(X);' % addrnum(arg))
    elif op == 'inx':
        out.append('X = (uint8_t)(X + 1); setZN(X);')
    elif op == 'dex':
        out.append('X = (uint8_t)(X - 1); setZN(X);')
    elif op == 'stx':
        out.append('WR(%s, X);' % addrnum(arg))
    elif op == 'lda':
        out.append('A = RD(%s); setZN(A);' % addrnum(arg))
    elif op == 'and':
        out.append('A = (uint8_t)(A & %s); setZN(A);' % immnum(arg))
    elif op == 'cmp':
        out.append('{ uint8_t _r = (uint8_t)(A - %s); P = (uint8_t)((P & 0x7C) | (A >= %s ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }' % (immnum(arg), immnum(arg)))
    elif op == 'rol':
        out.append('{ uint8_t _v = RD(%s); uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (_v >> 7)); _v = (uint8_t)((_v << 1) | _c); WR(%s, _v); setZN(_v); }' % (addrnum(arg), addrnum(arg)))
    elif op == 'bne':
        out.append('if (!(P & 0x02)) goto %s;' % arg)
    elif op == 'rts':
        out.append('return;')
    elif op == 'nop':
        out.append(';')
assert not first, 'entry label not found: ' + entry
out.append('}')
open(out_path, 'w').write(chr(10).join(out) + chr(10))
print('lifted ' + entry + ' -> ' + out_path)
