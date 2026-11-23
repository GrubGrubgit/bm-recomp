import os
BASE = '/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe'
LIFT = BASE + '/recomp/tools/lift'
GEN = BASE + '/recomp/gen'
M = LIFT + '/manual_9AEE'
NL = chr(10)

def rep(path, old, new, expect=1):
    s = open(path).read()
    c = s.count(old)
    assert c == expect, (path, old[:80], c)
    open(path, 'w').write(s.replace(old, new))
    print('ok', os.path.basename(path), old[:60].replace(NL, '|'))

def bodies(src, want):
    parts = src.split('static void __attribute__((used)) ')
    got = {}
    for p in parts:
        nm = p.split('(void)')[0]
        if nm in want:
            cut = p.find(NL + 'static void ')
            if cut >= 0:
                p = p[:cut] + NL
            got[nm] = 'static void __attribute__((used)) ' + p.rstrip() + NL
    assert set(got) == set(want), (set(got), set(want))
    blob = ''.join([got[k] for k in want])
    assert '__builtin_trap' not in blob, 'stub trap leaked into WANT body'
    return blob

OFF = open(M + '/out_off.c').read()
ENF = open(M + '/out_enf.c').read()
assert OFF == ENF, 'off/enf lift differs (no jsr in snip, must be identical)'

# --- norm check: lifted SEC/SBC/BNE == TU b4_L9AEA 9AEE-9AF1 lines ---
gen = open(GEN + '/combined_off.c').read()
tu_fn = gen.split('static void __attribute__((used)) b4_L9AEA(void) {')[1].split(NL + '}' + NL)[0]
tu_seg = tu_fn.split('nmi_pc = 0x9AEE;')[1].split('b4_L9ADA(); return;')[0]
tu_seg = tu_seg.replace('b4_L9AEA', 'b4_entry_9AEE')
raw = bodies(OFF, ['b4_entry_9AEE'])
lift_seg = raw.split('nmi_pc = 0x9AEE;')[1].split('b4_L9ADA(); return;')[0]
lift_seg = lift_seg.replace('b4_L9AEA', 'b4_entry_9AEE')
assert tu_seg == lift_seg, ('NORM MISMATCH', repr(tu_seg), repr(lift_seg))
print('norm vs TU L9AEA 9AEE-9AF1: MATCH')

# --- hand-shape: ROM falls through BNE-not-taken to 9AF3 (0 cycles);
#     pure lift emits a JMP (3cy) for the snip-level `jmp L9AF3`.
#     Drop the phantom JMP charge (B563 hand-shape class). ---
TAIL_OLD = ('nmi_pc = 0x9AF3;' + NL +
            'nmi_poll("b4_entry_9AEE");' + NL +
            'nmi_poll("b4_entry_9AEE");' + NL +
            'cycles += 3;' + NL +
            'b4_L9AF3(); return;')
TAIL_NEW = ('nmi_pc = 0x9AF3;' + NL +
            'nmi_poll("b4_entry_9AEE");' + NL +
            'nmi_poll("b4_entry_9AEE");' + NL +
            'b4_L9AF3(); return;')
assert raw.count(TAIL_OLD) == 1, 'tail shape changed, inspect lift output'
BODY = raw.replace(TAIL_OLD, TAIL_NEW)
assert 'cycles += 3;' + NL + 'b4_L9AF3' not in BODY
print('hand-shape: JMP 3cy dropped, fallthrough exact')

WANT = BODY
# --- splice decls (both decl regions, both gens) ---
D1 = 'static void b4_entry_9A8E(void);' + NL + 'static void b4_entry_9B0E(void);'
D1N = 'static void b4_entry_9A8E(void);' + NL + 'static void b4_entry_9AEE(void);' + NL + 'static void b4_entry_9B0E(void);'
D2 = 'static void b4_entry_9AB6(void);' + NL + 'static void b4_entry_9B0E(void);'
D2N = 'static void b4_entry_9AB6(void);' + NL + 'static void b4_entry_9AEE(void);' + NL + 'static void b4_entry_9B0E(void);'
BB = 'static void __attribute__((used)) b4_entry_9B0E(void) {'
CB = 'case 0x9A8E: b4_entry_9A8E(); break;' + NL
CN = CB + 'case 0x9AEE: b4_entry_9AEE(); break;' + NL
for nm in ('combined_off.c', 'combined_enf.c'):
    rep(GEN + '/' + nm, D1, D1N)
    rep(GEN + '/' + nm, D2, D2N)
    rep(GEN + '/' + nm, BB, WANT + BB)
    rep(GEN + '/' + nm, CB, CN)
rep(LIFT + '/ADDRMAP.txt',
    '9AEA 6 L9AEA' + NL + '9AF3 4 L9AF3',
    '9AEA 6 L9AEA' + NL + '9AEE 4 entry_9AEE' + NL + '9AF3 4 L9AF3')
rep(LIFT + '/PROV_ALL.txt',
    'L9AEA 4' + NL + 'L9AF3 4',
    'L9AEA 4' + NL + 'entry_9AEE 4' + NL + 'L9AF3 4')
rep(LIFT + '/vec007A.txt', '9A8B 9A8E 9B0E', '9A8B 9A8E 9AEE 9B0E')
print('9AEE port ok')
