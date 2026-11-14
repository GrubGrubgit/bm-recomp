src = open("combined_off.c").read()
NL = chr(10)
def rep(a, b):
    global src
    assert src.count(a) == 1, a[:60]
    src = src.replace(a, b)
rep("static void b6_entry_AFFF(void);" + NL + "static void b6_entry_B118(void);",
    "static void b6_entry_AFFF(void);" + NL + "static void b6_entry_B013(void);" + NL + "static void b6_entry_B016(void);" + NL + "static void b6_entry_B118(void);")
rep("static void b6_entry_B012(void);" + NL + "static void b6_entry_B04B(void);",
    "static void b6_entry_B012(void);" + NL + "static void b6_entry_B013(void);" + NL + "static void b6_entry_B016(void);" + NL + "static void b6_entry_B04B(void);")
rep("static void b6_LB05B(void);",
    "static void b6_LB02E(void);" + NL + "static void b6_LB047(void);" + NL + "static void b6_LB05B(void);")
rep("case 0xAFFF: b6_entry_AFFF(); break;",
    "case 0xAFFF: b6_entry_AFFF(); break;" + NL + "case 0xB013: b6_entry_B013(); break;" + NL + "case 0xB016: b6_entry_B016(); break;")
lift = open("b6d.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_B013", "b6_entry_B016", "b6_LB02E", "b6_LB047"]
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
rep("static void __attribute__((used)) b6_entry_B04B(void) {", blob + "static void __attribute__((used)) b6_entry_B04B(void) {")
open("combined_off.wp26", "w").write(src)
print("wp26 written", len(src))
