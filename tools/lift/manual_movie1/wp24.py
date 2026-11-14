src = open('combined_off.c').read()
# trim flag decl
a = 'static int trim_L6CD = 0;'
assert src.count(a) == 1
src = src.replace(a, a + '\nstatic int trim_8C00 = 0;')
# block1 decls
a = 'static void b6_entry_8A69(void);\nstatic void b6_entry_8C64(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_entry_8A69(void);\nstatic void b6_entry_8B74(void);\nstatic void b6_entry_8B77(void);\nstatic void b6_entry_8BE5(void);\nstatic void b6_entry_8C00(void);\nstatic void b6_entry_8C64(void);')
# block2 entry decls
a = 'static void b6_entry_8B69(void);\nstatic void b6_entry_8B8A(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_entry_8B69(void);\nstatic void b6_entry_8B74(void);\nstatic void b6_entry_8B77(void);\nstatic void b6_entry_8B8A(void);')
a = 'static void b6_entry_8B8A(void);\nstatic void b6_entry_8BA7(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_entry_8B8A(void);\nstatic void b6_entry_8BE5(void);\nstatic void b6_entry_8BA7(void);')
a = 'static void b6_LB8C8(void);\nstatic void b6_LB8DE(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_LB8C8(void);\nstatic void b6_L8C08(void);\nstatic void b6_L8C0A(void);\nstatic void b6_LB8DE(void);')
a = 'static void b6_entry_8BC8(void);\nstatic void b6_entry_8C32(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b6_entry_8BC8(void);\nstatic void b6_entry_8C00(void);\nstatic void b6_entry_8C32(void);')
# vec cases
a = 'case 0x8A69: b6_entry_8A69(); break;\ncase 0x8C64: b6_entry_8C64(); break;'
assert src.count(a) == 1
src = src.replace(a, 'case 0x8A69: b6_entry_8A69(); break;\ncase 0x8B74: b6_entry_8B74(); break;\ncase 0x8B77: b6_entry_8B77(); break;\ncase 0x8C64: b6_entry_8C64(); break;')
# bodies
lift = open('b6b.c').read()
parts = lift.split('static void __attribute__((used)) ')
order = ['b6_entry_8B74', 'b6_entry_8B77', 'b6_entry_8BE5', 'b6_entry_8C00', 'b6_L8C08', 'b6_L8C0A']
got = {}
for p in parts:
    name = p.split('(void)')[0]
    if name in order:
        cut = p.find('\nstatic void ')
        if cut >= 0: p = p[:cut] + '\n'
        got[name] = 'static void __attribute__((used)) ' + p.rstrip() + '\n'
assert set(got) == set(order), set(order) - set(got)
assert '__builtin_trap' not in '\n'.join(got.values())
# trim edits
b = got['b6_entry_8C00']
i = b.rfind('return;')
assert i > 0
b = b[:i] + 'trim_8C00 = 1;\n' + b[i:]
got['b6_entry_8C00'] = b
b = got['b6_entry_8B77']
a2 = 'b6_entry_8BE5();\nS = (uint8_t)(S + 2);'
assert b.count(a2) == 1
got['b6_entry_8B77'] = b.replace(a2, 'b6_entry_8BE5();\nif (trim_8C00) { trim_8C00 = 0; return; }\nS = (uint8_t)(S + 2);')
blob1 = '\n'.join(got[k] for k in ['b6_entry_8B74', 'b6_entry_8B77'])
blob2 = '\n'.join(got[k] for k in ['b6_entry_8BE5', 'b6_entry_8C00', 'b6_L8C08', 'b6_L8C0A'])
a = 'static void __attribute__((used)) b6_entry_8B8A(void) {'
assert src.count(a) == 1
src = src.replace(a, blob1 + a)
a = 'static void __attribute__((used)) b6_entry_8C32(void) {'
assert src.count(a) == 1
src = src.replace(a, blob2 + a)
open('combined_off.wp24', 'w').write(src)
print('wp24 written', len(src))
