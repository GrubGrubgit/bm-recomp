src = open("combined_off.c").read()
NL = chr(10)
def rep(a, b):
    global src
    assert src.count(a) == 1, a[:80]
    src = src.replace(a, b)
rep("static void b6_entry_9BAD(void);" + NL + "static void b6_entry_9BDB(void);",
    "static void b6_entry_9BAA(void);" + NL + "static void b6_entry_9BAD(void);" + NL + "static void b6_entry_9BDB(void);")
rep("static void b6_entry_9BAD(void);" + NL + "static void b6_entry_9BB1(void);",
    "static void b6_entry_9BAA(void);" + NL + "static void b6_entry_9BAD(void);" + NL + "static void b6_entry_9BB1(void);")
rep("case 0x9BAD: b6_entry_9BAD(); break;",
    "case 0x9BAA: b6_entry_9BAA(); break;" + NL + "case 0x9BAD: b6_entry_9BAD(); break;")
lift = open("lift_b6i.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_9BAA"]
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
rep("static void __attribute__((used)) b6_entry_A063(void) {",
    blob + "static void __attribute__((used)) b6_entry_A063(void) {")
open("combined_off.wp31", "w").write(src)
print("wp31 written", len(src))
