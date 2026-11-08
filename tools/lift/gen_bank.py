# gen_bank.py: slice one bank's .s into kept groups, pick entries, lift one TU.
# usage: gen_bank.py ASM_S INFO BANKNUM OUT_SNIP OUT_C EXCL [EXCL ...]
# EXCL form: LO-HI hex (e.g. FDA5-FDAF). Kept = Code ranges minus EXCL.
# Groups are label-delimited; a group is dropped if it hits EXCL.
# Entries = jsr/jmp-abs targets + first label of each kept range run.
import sys, subprocess
s_path, info_path, banknum, snip_path, out_c = sys.argv[1:6]
banknum = int(banknum)
excl = []
vec_paths = []
amap_paths = []
prov_paths = []
jtab_paths = []
unwind_args = []
for e in sys.argv[6:]:
    if e.startswith('VEC:'):
        vec_paths.append(e[4:])
    elif e.startswith('ADDRMAP:'):
        amap_paths.append(e[8:])
    elif e.startswith('PROV:'):
        prov_paths.append(e[5:])
    elif e.startswith('JMPTAB:'):
        jtab_paths.append(e[7:])
    elif e.startswith('UNWIND:'):
        unwind_args.append(e)
    elif e.startswith('XBANK:'):
        raise AssertionError('XBANK retired; use ADDRMAP')
    else:
        a, b = e.split('-')
        excl.append((int(a, 16), int(b, 16)))
base = 0xC000 if banknum == 7 else 0x8000
ranges = []
for ln in open(info_path):
    if 'TYPE Code' not in ln or 'RANGE' not in ln: continue
    a = [int(x.split(';')[0], 16) for x in ln.split('$')[1:3]]
    if a[1] >= base: ranges.append((max(a[0], base), a[1]))
ranges.sort()
def in_code(a):
    return any(lo <= a <= hi for lo, hi in ranges)
def labaddr(nm):
    t = nm
    if t.startswith('entry_'): t = t[6:]
    elif t.startswith('L'): t = t[1:]
    else: raise AssertionError('bad label: ' + nm)
    assert len(t) == 4, 'bad label: ' + nm
    return int(t, 16)
def islab(ln):
    return ln and ln[0] not in (' ', chr(9), ';', '.') and ':' in ln.strip()
raw = open(s_path).read().splitlines()
groups = []
cur = None
for ln in raw:
    if ':=' in ln.split(';', 1)[0]:
        print('alias skipped: ' + ln.strip()[:40])
        continue
    if islab(ln):
        nm = ln.strip().split(':', 1)[0].strip()
        cur = [nm, labaddr(nm), [ln]]
        groups.append(cur)
    elif cur is not None and ln.strip() and not ln.strip().startswith(';'):
        st = ln.strip()
        if st.startswith('.'):
            print('directive dropped in %s: %s' % (cur[0], st[:40]))
            continue
        cur[2].append(ln)
def group_kind(lns):
    saw_directive = False
    for _ln in lns:
        _s = _ln.split(';', 1)[0]
        if ':' in _ln and _ln[0] not in (' ', chr(9)):
            _s = _s.split(':', 1)[1]
        _s = _s.strip()
        if not _s: continue
        if _s.startswith('.'): saw_directive = True; continue
        return 'code'
    return 'data' if saw_directive else 'alias'
kept = []
for i, (nm, ad, lns) in enumerate(groups):
    if not in_code(ad): continue
    end = groups[i+1][1] if i+1 < len(groups) else ad + 0x4000
    if group_kind(lns) == 'data':
        print('data drop %s (%04X)' % (nm, ad))
        continue
    if any(lo <= end - 1 and hi >= ad for lo, hi in excl):
        print('drop %s (%04X)' % (nm, ad))
        continue
    kept.append((nm, ad, lns))
print('kept groups:', len(kept), 'of', len(groups))
entries = set()
for j, (nm, ad, lns) in enumerate(kept):
    if j == 0 or kept[j-1][0] is None: entries.add(nm)
prev_end = None
for nm, ad, lns in kept:
    entries.add(nm)
tgt = set()
for nm, ad, lns in kept:
    for ln in lns:
        s = ln.split(';')[0].strip()
        if ':' in ln and ln[0] not in (' ', chr(9)):
            s = s.split(':', 1)[1].strip()
            if not s: continue
        p = s.split(None, 1)
        if len(p) == 2 and p[0] in ('jsr',) and p[1].strip()[0] not in ('$', '#'):
            tgt.add(p[1].strip())
        if len(p) == 2 and p[0] in ('bne','beq','bcc','bcs','bpl','bmi'):
            q = p[1].strip()
            if q and q[0] not in ('$', '#'):
                tgt.add(q)
        if len(p) == 2 and p[0] == 'jmp' and p[1].strip()[0] not in ('$', '#', '('):
            tgt.add(p[1].strip())
entries |= (tgt & set(nm for nm, ad, lns in kept))
keptnames = set(nm for nm, ad, lns in kept)
stubs = sorted(t for t in tgt if t not in keptnames)
print('stubs:', len(stubs), stubs[:12])
print('entries:', len(entries))
print('vec:', vec_paths)
print('addrmap:', amap_paths)
print('prov:', prov_paths)
print('jmptab:', jtab_paths)
out = []
for nm, ad, lns in kept:
    out.extend(lns)
open(snip_path, 'w').write(chr(10).join(out) + chr(10))
el = ','.join(sorted(entries))
lift_specs = ['VEC:' + p for p in vec_paths] + ['ADDRMAP:' + p for p in amap_paths] + ['PROV:' + p for p in prov_paths] + ['JMPTAB:' + p for p in jtab_paths] + unwind_args
r = subprocess.run(['python3', '/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/lift.py', snip_path, out_c, 'b%d' % banknum, el, ','.join(stubs)] + lift_specs, capture_output=True, text=True)
print('ELN:', len(el.split(','))); print(r.stdout[-500:]); print(r.stderr[-2000:])
sys.exit(r.returncode)
