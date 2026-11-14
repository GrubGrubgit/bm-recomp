import re
src = open('combined_off.c').read()
# --- block1 decls (vec TU decls, entry-only) ---
a1 = 'static void b4_entry_AFF9(void);\nstatic void b4_entry_B6A9(void);'
assert src.count(a1) == 1
src = src.replace(a1, 'static void b4_entry_AFF6(void);\nstatic void b4_entry_AFF9(void);\nstatic void b4_entry_AFFF(void);\nstatic void b4_entry_B02F(void);\nstatic void b4_entry_B032(void);\nstatic void b4_entry_B040(void);\nstatic void b4_entry_B041(void);\nstatic void b4_entry_B044(void);\nstatic void b4_entry_B6A9(void);')
# --- block2 decls ---
a = 'static void b4_entry_AFF9(void);\nstatic void b4_entry_B004(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b4_entry_AFF6(void);\nstatic void b4_entry_AFF9(void);\nstatic void b4_entry_AFFF(void);\nstatic void b4_entry_B004(void);')
a = 'static void b4_entry_B02C(void);\nstatic void b4_entry_B054(void);'
assert src.count(a) == 1
src = src.replace(a, 'static void b4_entry_B02C(void);\nstatic void b4_entry_B02F(void);\nstatic void b4_entry_B032(void);\nstatic void b4_entry_B040(void);\nstatic void b4_entry_B041(void);\nstatic void b4_entry_B044(void);\nstatic void b4_entry_B054(void);')
# --- vec cases ---
a = 'case 0xAFF9: b4_entry_AFF9(); break;\ncase 0xB6A9: b4_entry_B6A9(); break;'
assert src.count(a) == 1
src = src.replace(a, 'case 0xAFF6: b4_entry_AFF6(); break;\ncase 0xAFF9: b4_entry_AFF9(); break;\ncase 0xAFFF: b4_entry_AFFF(); break;\ncase 0xB02F: b4_entry_B02F(); break;\ncase 0xB032: b4_entry_B032(); break;\ncase 0xB040: b4_entry_B040(); break;\ncase 0xB041: b4_entry_B041(); break;\ncase 0xB044: b4_entry_B044(); break;\ncase 0xB6A9: b4_entry_B6A9(); break;')
# --- bodies ---
lift = open('b4a.c').read()
parts = lift.split('static void __attribute__((used)) ')
order = ['b4_entry_AFF6', 'b4_entry_AFFF', 'b4_entry_B02F', 'b4_entry_B032', 'b4_entry_B040', 'b4_entry_B041', 'b4_entry_B044']
got = {}
for p in parts:
    name = p.split('(void)')[0]
    if name in order:
        cut = p.find('\nstatic void ')
        if cut >= 0: p = p[:cut] + '\n'
        got[name] = 'static void __attribute__((used)) ' + p.rstrip() + '\n'
assert set(got) == set(order), set(order) - set(got)
assert '__builtin_trap' not in '\n'.join(got.values())
aff = '\n'.join(got[k] for k in ['b4_entry_AFF6', 'b4_entry_AFFF'])
bxx = '\n'.join(got[k] for k in ['b4_entry_B02F', 'b4_entry_B032', 'b4_entry_B040', 'b4_entry_B041', 'b4_entry_B044'])
a = 'static void __attribute__((used)) b4_entry_B009(void) {'
assert src.count(a) == 1
src = src.replace(a, aff + a)
a = 'static void __attribute__((used)) b4_entry_B054(void) {'
assert src.count(a) == 1
src = src.replace(a, bxx + a)
open('combined_off.wp23', 'w').write(src)
print('wp23 written', len(src))
