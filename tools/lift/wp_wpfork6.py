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
OFF_BODY = open(LIFT + "/manual_B650/out_off.c").read()
ENF_BODY = open(LIFT + "/manual_B650/out_enf.c").read()
def bodies(src):
    i = src.find("static void __attribute__((used)) b4_entry_B64D")
    j = src.find("static void b4_entry_B680(void) { __builtin_trap(); }")
    assert i > 0 and j > i, "body bounds"
    return src[i:j]
OFF_B = bodies(OFF_BODY)
ENF_B = bodies(ENF_BODY)
assert "b4_LB65A" in OFF_B and "b4_entry_B650" in OFF_B, "off body"
assert "UNWIND-ESCAPE" in ENF_B, "enf body"
DECL_OLD = "static void b4_entry_B623(void);" + NL + "static void b4_entry_B680(void);"
DECL_NEW = ("static void b4_entry_B623(void);" + NL + "static void b4_entry_B64D(void);" + NL +
            "static void b4_entry_B650(void);" + NL + "static void b4_LB65A(void);" + NL + "static void b4_entry_B680(void);")
CASE_OFF_OLD = "case 0xB044: b4_entry_B044(); break;" + NL + "case 0xB6A9:"
CASE_OFF_NEW = ("case 0xB044: b4_entry_B044(); break;" + NL +
            "case 0xB64D: if (swbank == prg[4]) b4_entry_B64D(); else __builtin_trap(); break;" + NL +
            "case 0xB650: if (swbank == prg[4]) b4_entry_B650(); else __builtin_trap(); break;" + NL + "case 0xB6A9:")
CASE_ENF_OLD = "case 0xB6A9: b4_entry_B6A9(); break;"
CASE_ENF_NEW = ("case 0xB64D: if (swbank == prg[4]) b4_entry_B64D(); else __builtin_trap(); break;" + NL +
            "case 0xB650: if (swbank == prg[4]) b4_entry_B650(); else __builtin_trap(); break;" + NL + CASE_ENF_OLD)
BODY_ANCHOR = "static void __attribute__((used)) b4_entry_B680(void) {"
TOP_OFF_OLD = "static void b4_entry_B044(void);" + NL + "static void b4_entry_B6A9(void);"
TOP_OFF_NEW = ("static void b4_entry_B044(void);" + NL + "static void b4_entry_B64D(void);" + NL +
       "static void b4_entry_B650(void);" + NL + "static void b4_LB65A(void);" + NL + "static void b4_entry_B6A9(void);")
TOP_ENF_OLD = "static void b4_entry_AFF9(void);" + NL + "static void b4_entry_B6A9(void);"
TOP_ENF_NEW = ("static void b4_entry_AFF9(void);" + NL + "static void b4_entry_B64D(void);" + NL +
       "static void b4_entry_B650(void);" + NL + "static void b4_LB65A(void);" + NL + "static void b4_entry_B6A9(void);")
rep(GEN + "/combined_off.c", TOP_OFF_OLD, TOP_OFF_NEW)
rep(GEN + "/combined_enf.c", TOP_ENF_OLD, TOP_ENF_NEW)
rep(GEN + "/combined_off.c", DECL_OLD, DECL_NEW)
rep(GEN + "/combined_off.c", BODY_ANCHOR, OFF_B + BODY_ANCHOR)
rep(GEN + "/combined_off.c", CASE_OFF_OLD, CASE_OFF_NEW)
rep(GEN + "/combined_enf.c", DECL_OLD, DECL_NEW)
rep(GEN + "/combined_enf.c", BODY_ANCHOR, ENF_B + BODY_ANCHOR)
rep(GEN + "/combined_enf.c", CASE_ENF_OLD, CASE_ENF_NEW)
print("fork6 port ok")
