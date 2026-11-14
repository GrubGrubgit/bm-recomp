src = open('combined_off.wp21').read()
assert src.count('static void b6_entry_A53D(void);') == 2
src = src.replace('static void b6_entry_A53D(void);',
                  'static void b6_entry_A53D(void);\nstatic void b6_entry_A5C2(void);\nstatic void b6_entry_A5C5(void);')
a = 'static void b6_LA59A(void);\nstatic void b6_LA615(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_LA59A(void);\nstatic void b6_LA5DB(void);\nstatic void b6_LA5EE(void);\nstatic void b6_LA5F2(void);\nstatic void b6_LA615(void);')
a = 'case 0xA53D: b6_entry_A53D(); break;'
assert src.count(a) == 1
src = src.replace(a, a + '\ncase 0xA5C2: b6_entry_A5C2(); break;\ncase 0xA5C5: b6_entry_A5C5(); break;')
lift = open('a5c5.c').read()
parts = lift.split('static void __attribute__((used)) ')
wanted = ['b6_entry_A5C2', 'b6_entry_A5C5', 'b6_LA5DB', 'b6_LA5EE', 'b6_LA5F2']
bodies = []
for p in parts:
    name = p.split('(void)')[0]
    if name in wanted:
        cut = p.find('\nstatic void ')
        if cut >= 0:
            p = p[:cut] + '\n'
        bodies.append('static void __attribute__((used)) ' + p.rstrip() + '\n')
assert len(bodies) == 5, len(bodies)
assert '__builtin_trap' not in '\n'.join(bodies)
blob = '\n'.join(bodies)
anchor = 'static void __attribute__((used)) b6_entry_A605(void) {'
assert src.count(anchor) == 1
src = src.replace(anchor, blob + anchor)
open('combined_off.wp22', 'w').write(src)
print('wp22 written', len(src))
