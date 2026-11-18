import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, f"anchor {c}!={expect} in {path}: {old[:80]!r}"
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:60])
OFF_SRC=open(LIFT+"/manual_8A6C/out_off.c").read()
ENF_SRC=open(LIFT+"/manual_8A6C/out_enf.c").read()
def bodies(src):
    i=src.find("static void __attribute__((used)) b4_entry_8A6C")
    assert i>0, "8A6C body not found"
    return src[i:]
OFF_B=bodies(OFF_SRC)
ENF_B=bodies(ENF_SRC)
assert "b4_entry_8A6C" in OFF_B and "b4_entry_93BD" in OFF_B
print("manual bodies ok", len(OFF_B), len(ENF_B))
for name in ("combined_off.c","combined_enf.c"):
    path=GEN+"/"+name
    s=open(path).read()
    old="static void b4_entry_80C9_KIL(void);"+NL+"static void b4_entry_8AF1(void);"
    assert s.count(old)==2, f"decl anchor {s.count(old)} in {name}"
    new="static void b4_entry_80C9_KIL(void);"+NL+"static void b4_entry_8A6C(void);"+NL+"static void b4_entry_8AF1(void);"
    open(path,"w").write(s.replace(old,new))
    print("ok decls", name)
    rep(path, "case 0x8AF1: b4_entry_8AF1(); break;", "case 0x8A6C: if (swbank == prg[4]) b4_entry_8A6C(); else __builtin_trap(); break;"+NL+"case 0x8AF1: b4_entry_8AF1(); break;")
    B=OFF_B if name=="combined_off.c" else ENF_B
    rep(path, "static void __attribute__((used)) b4_entry_B680(void) {", B+"static void __attribute__((used)) b4_entry_B680(void) {")
for fn, old, new in [
    (LIFT+"/ADDRMAP.txt", "8AF1 4 entry_8AF1", "8A6C 4 entry_8A6C"+NL+"8AF1 4 entry_8AF1"),
    (LIFT+"/PROV_ALL.txt", "entry_8AF1 4", "entry_8A6C 4"+NL+"entry_8AF1 4"),
]:
    s=open(fn).read()
    assert s.count(old)==1, fn+old
    open(fn,"w").write(s.replace(old,new))
    print("ok "+fn.split("/")[-1])
s=open(LIFT+"/vec007A.txt").read()
old="8AF1 8AF4"
assert s.count(old)==1
open(LIFT+"/vec007A.txt","w").write(s.replace(old,"8A6C 8AF1 8AF4"))
print("ok vec")
print("8A6C port ok")
