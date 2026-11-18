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
OFF_SRC=open(LIFT+"/manual_B563/out_off.c").read()
ENF_SRC=open(LIFT+"/manual_B563/out_enf.c").read()
def bodies(src):
    i=src.find("static void __attribute__((used)) b7_entry_C1FE")
    assert i>0, "C1FE body not found"
    return src[i:]
OFF_B=bodies(OFF_SRC)
ENF_B=bodies(ENF_SRC)
assert "b7_entry_C1FE" in OFF_B and "b7_entry_C20D" in OFF_B and "b4_entry_B563" in OFF_B
assert "b4_LB58D()" in OFF_B and "b4_entry_B58D" not in OFF_B
assert "b4_LB58D()" in ENF_B and "b4_entry_B58D" not in ENF_B
print("manual bodies ok", len(OFF_B), len(ENF_B))
for name in ("combined_off.c","combined_enf.c"):
    path=GEN+"/"+name
    s=open(path).read()
    old="static void b4_entry_B4F1(void);"+NL+"static void b4_entry_B64D(void);"
    assert s.count(old)==2, f"decl anchor {s.count(old)} in {name}"
    newd="static void b4_entry_B4F1(void);"+NL+"static void b4_entry_B563(void);"+NL+"static void b7_entry_C1FE(void);"+NL+"static void b7_entry_C20D(void);"+NL+"static void b4_entry_B64D(void);"
    open(path,"w").write(s.replace(old,newd))
    print("ok decls", name)
    rep(path, "case 0xB4F1: if (swbank == prg[4]) b4_entry_B4F1(); else __builtin_trap(); break;", "case 0xB4F1: if (swbank == prg[4]) b4_entry_B4F1(); else __builtin_trap(); break;"+NL+"case 0xB563: if (swbank == prg[4]) b4_entry_B563(); else __builtin_trap(); break;")
    B=OFF_B if name=="combined_off.c" else ENF_B
    rep(path, "static void __attribute__((used)) b4_entry_B680(void) {", B+"static void __attribute__((used)) b4_entry_B680(void) {")
for fn, old, newd in [
    (LIFT+"/ADDRMAP.txt", "B4F1 4 entry_B4F1"+NL+"B4EE 6 LB4EE", "B4F1 4 entry_B4F1"+NL+"B563 4 entry_B563"+NL+"B4EE 6 LB4EE"),
    (LIFT+"/ADDRMAP.txt", "C1F5 7 entry_C1F5"+NL+"C204 7 entry_C204", "C1F5 7 entry_C1F5"+NL+"C1FE 7 entry_C1FE"+NL+"C204 7 entry_C204"),
    (LIFT+"/ADDRMAP.txt", "C20A 7 entry_C20A"+NL+"C216 7 entry_C216", "C20A 7 entry_C20A"+NL+"C20D 7 entry_C20D"+NL+"C216 7 entry_C216"),
    (LIFT+"/PROV_ALL.txt", "entry_B4F1 4"+NL+"entry_B53A 4", "entry_B4F1 4"+NL+"entry_B563 4"+NL+"entry_B53A 4"),
    (LIFT+"/PROV_ALL.txt", "entry_C1F5 7"+NL+"entry_C204 7", "entry_C1F5 7"+NL+"entry_C1FE 7"+NL+"entry_C204 7"),
    (LIFT+"/PROV_ALL.txt", "entry_C20A 7"+NL+"entry_C216 7", "entry_C20A 7"+NL+"entry_C20D 7"+NL+"entry_C216 7"),
]:
    s=open(fn).read()
    assert s.count(old)==1, fn+old
    open(fn,"w").write(s.replace(old,newd))
    print("ok "+fn.split("/")[-1])
s=open(LIFT+"/vec007A.txt").read()
old="B4F1 B64D"
assert s.count(old)==1
open(LIFT+"/vec007A.txt","w").write(s.replace(old,"B4F1 B563 B64D"))
print("ok vec")
print("B563 port ok")
