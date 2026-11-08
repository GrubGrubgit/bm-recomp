# gen_addr.py: build ADDRMAP + PROV from kept-group snips.
# usage: gen_addr.py OUTMAP OUTPROV SNIP1 BANK1 [SNIP2 BANK2 ...]
# A kept label is a col-0 name: line. ADDRMAP: ADDR BANK LABEL. PROV: LABEL BANK.
import sys
outmap, outprov = sys.argv[1], sys.argv[2]
pairs = sys.argv[3:]
assert len(pairs) % 2 == 0, 'need SNIP BANK pairs'
HEX = '0123456789ABCDEFabcdef'
def labaddr(nm):
    t = nm
    if t.startswith('entry_'): t = t[6:]
    elif t.startswith('L'): t = t[1:]
    else: raise AssertionError('bad label: ' + nm)
    assert len(t) == 4, 'bad label: ' + nm
    return int(t, 16)
amap = {}
for i in range(0, len(pairs), 2):
    snip, b = pairs[i], int(pairs[i+1])
    for ln in open(snip):
        if ':=' in ln.split(';', 1)[0]: continue
        if ln and ln[0] not in (' ', chr(9), ';', '.') and ':' in ln:
            nm = ln.split(':', 1)[0].strip()
            if not nm: continue
            a = labaddr(nm)
            assert (a, b) not in amap, 'dup addr in bank'
            amap[(a, b)] = nm
ml = ['%04X %d %s' % (a, b, amap[(a, b)]) for (a, b) in sorted(amap)]
open(outmap, 'w').write(chr(10).join(ml) + chr(10))
pl = ['%s %d' % (amap[k], k[1]) for k in sorted(amap, key=lambda k: (k[1], amap[k]))]
open(outprov, 'w').write(chr(10).join(pl) + chr(10))
print('addrmap addrs: %d prov: %d' % (len(ml), len(pl)))
