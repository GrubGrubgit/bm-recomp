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
OFF_SRC = open(LIFT + "/manual_B102/out_off.c").read()
ENF_SRC = open(LIFT + "/manual_B102/out_enf.c").read()
def bodies(src):
    i = src.find("static void __attribute__((used)) b7_entry_C05D")
    j = src.find("static void b4_entry_B680(void) { __builtin_trap(); }")
    # manual out has no B680 trap; take whole tail from C05D
    assert i > 0, "C05D not found"
    return src[i:]
OFF_B = bodies(OFF_SRC)
ENF_B = bodies(ENF_SRC)
assert "b4_entry_B102" in OFF_B and "b7_entry_C05D" in OFF_B, "off body"
assert "b4_entry_B102" in ENF_B, "enf body"
# decls: add B102 + C05D (C05D decl in b7 block? follow C1EF pattern: b7 decls near C1DA)
for name in ("combined_off.c", "combined_enf.c"):
    path = GEN + "/" + name
    # top decls for B102 (near B044/B6A9 block)
    rep(path,
        "static void b4_entry_B044(void);" + NL + "static void b4_entry_B64D(void);",
        "static void b4_entry_B044(void);" + NL + "static void b4_entry_B102(void);" + NL + "static void b4_entry_B64D(void);")
    # vec case for B102 (bank4 guarded, like B650)
    rep(path,
        "case 0xB044: b4_entry_B044(); break;" + NL + "case 0xB64D:",
        "case 0xB044: b4_entry_B044(); break;" + NL + "case 0xB102: if (swbank == prg[4]) b4_entry_B102(); else __builtin_trap(); break;" + NL + "case 0xB64D:")
# bodies: splice before B680 trap decl (like fork6)
for name, B in (("combined_off.c", OFF_B), ("combined_enf.c", ENF_B)):
    path = GEN + "/" + name
    rep(path,
        "static void __attribute__((used)) b4_entry_B680(void) {",
        B + "static void __attribute__((used)) b4_entry_B680(void) {")
# ADDRMAP / PROV / VEC updates
for fn, old, new in [
    (LIFT+"/ADDRMAP.txt", "B0EF 4 LB0EF"+NL+"B118 6 entry_B118", "B0EF 4 LB0EF"+NL+"B102 4 entry_B102"+NL+"B118 6 entry_B118"),
    (LIFT+"/ADDRMAP.txt", "C05A 7 entry_C05A"+NL+"C060 7 entry_C060", "C05A 7 entry_C05A"+NL+"C05D 7 entry_C05D"+NL+"C060 7 entry_C060"),
    (LIFT+"/PROV_ALL.txt", "entry_B0DF 4"+NL+"LB0EF 4", "entry_B0DF 4"+NL+"LB0EF 4"+NL+"entry_B102 4"),
]:
    s=open(fn).read()
    assert s.count(old)==1, fn+old
    open(fn,"w").write(s.replace(old,new))
    print("ok "+fn.split("/")[-1])
# PROV C05D (check exact anchor)
import re
s=open(LIFT+"/PROV_ALL.txt").read()
if ("entry_C05D" not in s):
    # find C05A line
    assert "entry_C05A 7" in s
    s=s.replace("entry_C05A 7", "entry_C05A 7"+NL+"entry_C05D 7")
    open(LIFT+"/PROV_ALL.txt","w").write(s)
    print("ok PROV C05D")
# VEC: add B102 to bank4 list (after B044, before B64D)
s=open(LIFT+"/vec007A.txt").read()
old="B044 B64D"
assert s.count(old)==1
open(LIFT+"/vec007A.txt","w").write(s.replace(old,"B044 B102 B64D"))
print("ok vec")
print("fork10 port ok")
