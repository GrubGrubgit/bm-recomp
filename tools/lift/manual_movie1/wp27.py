src = open("combined_off.c").read()
NL = chr(10)
def rep(a, b):
    global src
    assert src.count(a) == 1, a[:60]
    src = src.replace(a, b)
rep("static void b6_entry_9EE3(void);" + NL + "static void b6_entry_A0B9(void);",
    "static void b6_entry_9EE3(void);" + NL + "static void b6_entry_9FDA(void);" + NL + "static void b6_entry_9FDD(void);" + NL + "static void b6_entry_A0B9(void);")
rep("static void b6_entry_9F87(void);" + NL + "static void b6_entry_A009(void);",
    "static void b6_entry_9F87(void);" + NL + "static void b6_entry_9FDA(void);" + NL + "static void b6_entry_9FDD(void);" + NL + "static void b6_entry_9FF8(void);" + NL + "static void b6_entry_A009(void);")
rep("case 0x9EE3: b6_entry_9EE3(); break;" + NL + "case 0xA0B9: b6_entry_A0B9(); break;",
    "case 0x9EE3: b6_entry_9EE3(); break;" + NL + "case 0x9FDA: b6_entry_9FDA(); break;" + NL + "case 0x9FDD: b6_entry_9FDD(); break;" + NL + "case 0xA0B9: b6_entry_A0B9(); break;")
lift = open("b6e.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_9FDA", "b6_entry_9FDD", "b6_entry_9FF8"]
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
rep("static void __attribute__((used)) b6_entry_A0B9(void) {", blob + "static void __attribute__((used)) b6_entry_A0B9(void) {")
open("combined_off.wp27", "w").write(src)
print("wp27 written", len(src))
