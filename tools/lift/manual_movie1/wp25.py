src = open("combined_off.c").read()
NL = chr(10)
a = "static void b4_entry_AFF9(void);" + NL + "static void b4_entry_AFFF(void);" + NL + "static void b4_entry_B02F(void);"
assert src.count(a) == 1, "b1b4"
src = src.replace(a, "static void b4_entry_AFF9(void);" + NL + "static void b4_entry_B02F(void);")
a = "static void b6_entry_AD0B(void);" + NL + "static void b6_entry_B118(void);"
assert src.count(a) == 1, "b1b6"
src = src.replace(a, "static void b6_entry_AD0B(void);" + NL + "static void b6_entry_AFFC(void);" + NL + "static void b6_entry_AFFF(void);" + NL + "static void b6_entry_B118(void);")
a = "static void b4_entry_AFF9(void);" + NL + "static void b4_entry_AFFF(void);" + NL + "static void b4_entry_B004(void);"
assert src.count(a) == 1, "b2b4"
src = src.replace(a, "static void b4_entry_AFF9(void);" + NL + "static void b4_entry_B004(void);")
a = "static void b6_entry_AFD1(void);" + NL + "static void b6_entry_B04B(void);"
assert src.count(a) == 1, "b2b6"
src = src.replace(a, "static void b6_entry_AFD1(void);" + NL + "static void b6_entry_AFFC(void);" + NL + "static void b6_entry_AFFF(void);" + NL + "static void b6_entry_B012(void);" + NL + "static void b6_entry_B04B(void);")
a = "case 0xAFF9: b4_entry_AFF9(); break;" + NL + "case 0xAFFF: b4_entry_AFFF(); break;"
assert src.count(a) == 1, "vec"
src = src.replace(a, "case 0xAFF9: b4_entry_AFF9(); break;" + NL + "case 0xAFFC: b6_entry_AFFC(); break;" + NL + "case 0xAFFF: b6_entry_AFFF(); break;")
lift = open("b6c.c").read()
parts = lift.split("static void __attribute__((used)) ")
order = ["b6_entry_AFFC", "b6_entry_AFFF", "b6_entry_B012"]
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
i = src.find("static void __attribute__((used)) b4_entry_AFFF(void) {")
assert i >= 0, "body"
j = src.find("static void __attribute__((used)) ", i + 10)
assert j > i
body = src[i:j]
assert "b7_entry_D324" in body and "b4_entry_B004" in body, body[:200]
src = src[:i] + src[j:]
a = "static void __attribute__((used)) b6_entry_B04B(void) {"
assert src.count(a) == 1, "anchor"
src = src.replace(a, blob + a)
open("combined_off.wp25", "w").write(src)
print("wp25 written", len(src))
