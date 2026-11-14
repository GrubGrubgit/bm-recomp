src = open("combined_off.c").read()
NL = chr(10)
def rep(a, b):
    global src
    assert src.count(a) == 1, a[:80]
    src = src.replace(a, b)
rep("static void b6_entry_B2EF(void);" + NL + "static void b6_entry_B3E3(void);" + NL + "static void b6_entry_B3E6(void);" + NL + "static void b6_entry_B6E7(void);",
    "static void b6_entry_B2EF(void);" + NL + "static void b6_entry_B3E3(void);" + NL + "static void b6_entry_B3E6(void);" + NL + "static void b6_entry_B3FE(void);" + NL + "static void b6_entry_B401(void);" + NL + "static void b6_entry_B6E7(void);")
rep("static void b6_entry_B3FD(void);" + NL + "static void b6_entry_B457(void);",
    "static void b6_entry_B3FD(void);" + NL + "static void b6_entry_B3FE(void);" + NL + "static void b6_entry_B401(void);" + NL + "static void b6_entry_B457(void);")
rep("case 0xB3E6: b6_entry_B3E6(); break;",
    "case 0xB3E6: b6_entry_B3E6(); break;" + NL + "case 0xB3FE: b6_entry_B3FE(); break;" + NL + "case 0xB401: b6_entry_B401(); break;")
lift = open("b6h.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_B3FE", "b6_entry_B401"]
got = {}
for p in parts:
    name = p.split("(void)")[0]
    if name in order:
        cut = p.find(NL + "static void ")
        if cut >= 0: p = p[:cut] + NL
        got[name] = "static void __attribute__((used)) " + p.rstrip() + NL
assert set(got) == set(order), set(order) - set(got)
assert "__builtin_trap" not in NL.join(got.values())
blob = NL.join(got[k] for k in order)
rep("static void __attribute__((used)) b6_entry_A063(void) {", blob + "static void __attribute__((used)) b6_entry_A063(void) {")
open("combined_off.wp30", "w").write(src)
print("wp30 written", len(src))
