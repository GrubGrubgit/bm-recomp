import os
BASE = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT = BASE + "/recomp/tools/lift"
GEN = BASE + "/recomp/gen"
NL = chr(10)
def rep(path, old, new, expect=1):
    s = open(path).read()
    c = s.count(old)
    assert c == expect, "anchor count %d != %d in %s: %s" % (c, expect, path, old[:70])
    s = s.replace(old, new)
    open(path, "w").write(s)
    print("ok %s :: %s" % (os.path.basename(path), old[:50]))
def bodies(src, start, stop):
    i = src.find(start)
    j = src.find(stop)
    assert i > 0 and j > i, (start, stop)
    return src[i:j]
C1EF_OFF = bodies(open(LIFT + "/manual_C1EF/out_off.c").read(), "static void __attribute__((used)) b7_entry_C1EF", "static void b7_entry_E1BD(void) { __builtin_trap(); }")
C1EF_ENF = bodies(open(LIFT + "/manual_C1EF/out_enf.c").read(), "static void __attribute__((used)) b7_entry_C1EF", "static void b7_entry_E1BD(void) { __builtin_trap(); }")
AF_OFF = bodies(open(LIFT + "/manual_AF48/out_off.c").read(), "static void __attribute__((used)) b4_entry_AF45", "static void b4_entry_AF99(void) { __builtin_trap(); }")
AF_ENF = bodies(open(LIFT + "/manual_AF48/out_enf.c").read(), "static void __attribute__((used)) b4_entry_AF45", "static void b4_entry_AF99(void) { __builtin_trap(); }")
assert "b4_LAF66" in AF_OFF and "b4_LB96" in AF_OFF, "af off"
assert "b7_entry_C1EF();" in AF_OFF, "af calls C1EF"
AF_DECLS = ("static void b4_entry_AF45(void);" + NL + "static void b4_entry_AF48(void);" + NL +
            "static void b4_LAF66(void);" + NL + "static void b4_entry_AF67(void);" + NL +
            "static void b4_entry_AF6A(void);" + NL + "static void b4_LB88(void);" + NL + "static void b4_LB96(void);" + NL)
AF_CASES = ("case 0xAF45: if (swbank == prg[4]) b4_entry_AF45(); else __builtin_trap(); break;" + NL +
            "case 0xAF48: if (swbank == prg[4]) b4_entry_AF48(); else __builtin_trap(); break;" + NL +
            "case 0xAF67: if (swbank == prg[4]) b4_entry_AF67(); else __builtin_trap(); break;" + NL +
            "case 0xAF6A: if (swbank == prg[4]) b4_entry_AF6A(); else __builtin_trap(); break;" + NL)
C1EF_BODY_ANCHOR = "static void __attribute__((used)) b7_entry_C1EC(void) {"
AF_BODY_ANCHOR = "static void __attribute__((used)) b4_entry_B680(void) {"
# OFF
rep(GEN + "/combined_off.c", "static void b4_entry_A74E(void);" + NL + "static void b4_entry_AFBC(void);",
    "static void b4_entry_A74E(void);" + NL + AF_DECLS + "static void b4_entry_AFBC(void);")
rep(GEN + "/combined_off.c", "static void b4_entry_AF2A(void);" + NL + "static void b4_entry_AF99(void);",
    "static void b4_entry_AF2A(void);" + NL + AF_DECLS + "static void b4_entry_AF99(void);")
rep(GEN + "/combined_off.c", "static void b7_entry_C1EC(void);" + NL + "static void b7_entry_C1F5(void);",
    "static void b7_entry_C1EC(void);" + NL + "static void b7_entry_C1EF(void);" + NL + "static void b7_entry_C1F5(void);", expect=2)
rep(GEN + "/combined_off.c", C1EF_BODY_ANCHOR, C1EF_OFF + C1EF_BODY_ANCHOR)
rep(GEN + "/combined_off.c", AF_BODY_ANCHOR, AF_OFF + AF_BODY_ANCHOR)
rep(GEN + "/combined_off.c", "case 0xB044: b4_entry_B044(); break;" + NL + "case 0xB64D:",
    "case 0xB044: b4_entry_B044(); break;" + NL + AF_CASES + "case 0xB64D:")
# ENF
rep(GEN + "/combined_enf.c", "static void b4_entry_A74E(void);" + NL + "static void b4_entry_AFBC(void);",
    "static void b4_entry_A74E(void);" + NL + AF_DECLS + "static void b4_entry_AFBC(void);")
rep(GEN + "/combined_enf.c", "static void b4_entry_AF2A(void);" + NL + "static void b4_entry_AF99(void);",
    "static void b4_entry_AF2A(void);" + NL + AF_DECLS + "static void b4_entry_AF99(void);")
rep(GEN + "/combined_enf.c", "static void b7_entry_C1EC(void);" + NL + "static void b7_entry_C1F5(void);",
    "static void b7_entry_C1EC(void);" + NL + "static void b7_entry_C1EF(void);" + NL + "static void b7_entry_C1F5(void);", expect=2)
rep(GEN + "/combined_enf.c", C1EF_BODY_ANCHOR, C1EF_ENF + C1EF_BODY_ANCHOR)
rep(GEN + "/combined_enf.c", AF_BODY_ANCHOR, AF_ENF + AF_BODY_ANCHOR)
rep(GEN + "/combined_enf.c", "case 0xB64D: if (swbank == prg[4]) b4_entry_B64D();",
    AF_CASES + "case 0xB64D: if (swbank == prg[4]) b4_entry_B64D();")
print("fork8 port ok")
