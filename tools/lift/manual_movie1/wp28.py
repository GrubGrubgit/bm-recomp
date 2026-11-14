src = open("combined_off.c").read()
NL = chr(10)
def rep(a, b):
    global src
    assert src.count(a) == 1, a[:70]
    src = src.replace(a, b)
rep("static void b6_entry_9FDD(void);" + NL + "static void b6_entry_A0B9(void);",
    "static void b6_entry_9FDD(void);" + NL + "static void b6_entry_9FF9(void);" + NL + "static void b6_entry_9FFC(void);" + NL + "static void b6_entry_A02F(void);" + NL + "static void b6_entry_A032(void);" + NL + "static void b6_entry_A047(void);" + NL + "static void b6_entry_A04A(void);" + NL + "static void b6_entry_A089(void);" + NL + "static void b6_entry_A08C(void);" + NL + "static void b6_entry_A0B9(void);")
rep("static void b6_entry_A009(void);" + NL + "static void b6_entry_A02C(void);",
    "static void b6_entry_A009(void);" + NL + "static void b6_entry_A029(void);" + NL + "static void b6_entry_A02C(void);" + NL + "static void b6_entry_A02F(void);" + NL + "static void b6_entry_A032(void);" + NL + "static void b6_entry_A046(void);" + NL + "static void b6_entry_A047(void);" + NL + "static void b6_entry_A04A(void);")
rep("static void b6_entry_A063(void);" + NL + "static void b6_entry_A0B9(void);",
    "static void b6_entry_A063(void);" + NL + "static void b6_entry_A083(void);" + NL + "static void b6_entry_A089(void);" + NL + "static void b6_entry_A08C(void);" + NL + "static void b6_entry_A0B5(void);" + NL + "static void b6_entry_A0B9(void);")
rep("static void b6_LA019(void);",
    "static void b6_LA019(void);" + NL + "static void b6_LA03F(void);")
rep("static void b6_LA073(void);" + NL + "static void b6_LA0E5(void);",
    "static void b6_LA073(void);" + NL + "static void b6_LA097(void);" + NL + "static void b6_LA0AB(void);" + NL + "static void b6_LA0E5(void);")
rep("case 0x9FDD: b6_entry_9FDD(); break;",
    "case 0x9FDD: b6_entry_9FDD(); break;" + NL + "case 0x9FF9: b6_entry_9FF9(); break;" + NL + "case 0x9FFC: b6_entry_9FFC(); break;" + NL + "case 0xA02F: b6_entry_A02F(); break;" + NL + "case 0xA032: b6_entry_A032(); break;" + NL + "case 0xA047: b6_entry_A047(); break;" + NL + "case 0xA04A: b6_entry_A04A(); break;" + NL + "case 0xA089: b6_entry_A089(); break;" + NL + "case 0xA08C: b6_entry_A08C(); break;")
lift = open("b6f.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_9FF9", "b6_entry_9FFC", "b6_entry_A029", "b6_entry_A02F", "b6_entry_A032", "b6_entry_A046", "b6_entry_A047", "b6_entry_A04A", "b6_entry_A083", "b6_entry_A089", "b6_entry_A08C", "b6_entry_A0B5", "b6_LA03F", "b6_LA097", "b6_LA0AB"]
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
open("combined_off.wp28", "w").write(src)
print("wp28 written", len(src))
