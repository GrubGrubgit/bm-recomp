import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, old[:80]
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:56])
def bodies(src):
    parts=src.split("static void __attribute__((used)) ")
    want=["b6_entry_A9CB","b6_entry_A9CE","b6_LA9DD","b6_entry_A9DE","b6_entry_A9E1"]
    got={}
    for p in parts:
        nm=p.split("(void)")[0]
        if nm in want:
            cut=p.find(NL+"static void ")
            if cut>=0:
                p=p[:cut]+NL
            got[nm]="static void __attribute__((used)) "+p.rstrip()+NL
    assert set(got)==set(want)
    assert "__builtin_trap" not in "".join(got.values())
    return "".join([got[k] for k in want])
OFFB=bodies(open(LIFT+"/manual_A9CE/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_A9CE/out_enf.c").read())
DECLS="static void b6_entry_A9CB(void);"+NL+"static void b6_entry_A9CE(void);"+NL+"static void b6_LA9DD(void);"+NL+"static void b6_entry_A9DE(void);"+NL+"static void b6_entry_A9E1(void);"+NL
CASES="case 0xA9CE: if (swbank == prg[6]) b6_entry_A9CE(); else __builtin_trap(); break;"+NL+"case 0xA9DE: if (swbank == prg[6]) b6_entry_A9DE(); else __builtin_trap(); break;"+NL+"case 0xA9E1: if (swbank == prg[6]) b6_entry_A9E1(); else __builtin_trap(); break;"+NL
D94="static void b6_entry_A994(void);"+NL+"static void b6_entry_AA03(void);"
D8A="static void b6_entry_A8FE(void);"+NL+"static void b6_entry_AA5D(void);"
BAA="static void __attribute__((used)) b6_entry_AA03(void) {"
CAA="case 0xA8FE: b6_entry_A8FE(); break;"+NL+"case 0xAA5D: b6_entry_AA5D(); break;"
CAB="case 0xA8FE: b6_entry_A8FE(); break;"+NL+CASES+"case 0xAA5D: b6_entry_AA5D(); break;"
D9N="static void b6_entry_A994(void);"+NL+DECLS+"static void b6_entry_AA03(void);"
D8N="static void b6_entry_A8FE(void);"+NL+DECLS+"static void b6_entry_AA5D(void);"
for nm,BB in (("bank6_off.c",OFFB),("bank6_enf.c",ENFB)):
    rep(GEN+"/"+nm, D94, D9N)
    rep(GEN+"/"+nm, BAA, BB+BAA)
for nm in ("bank7t_off.c","bank7t_enf.c"):
    rep(GEN+"/"+nm, D8A, D8N)
    rep(GEN+"/"+nm, CAA, CAB)
for nm,BB in (("combined_off.c",OFFB),("combined_enf.c",ENFB)):
    rep(GEN+"/"+nm, D94, D9N)
    rep(GEN+"/"+nm, D8A, D8N)
    rep(GEN+"/"+nm, BAA, BB+BAA)
    rep(GEN+"/"+nm, CAA, CAB)
rep(LIFT+"/ADDRMAP.txt", "A9CA 4 LA9CA"+NL+"AA03 6 entry_AA03", "A9CA 4 LA9CA"+NL+"A9CB 6 entry_A9CB"+NL+"A9CE 6 entry_A9CE"+NL+"A9DD 6 LA9DD"+NL+"A9DE 6 entry_A9DE"+NL+"A9E1 6 entry_A9E1"+NL+"A9F8 6 LA9F8"+NL+"A9FA 6 LA9FA"+NL+"AA03 6 entry_AA03")
rep(LIFT+"/PROV_ALL.txt", "entry_A994 6"+NL+"entry_AA03 6", "entry_A994 6"+NL+"entry_A9CB 6"+NL+"entry_A9CE 6"+NL+"entry_A9DE 6"+NL+"entry_A9E1 6"+NL+"entry_AA03 6")
rep(LIFT+"/PROV_ALL.txt", "LA9C3 6"+NL+"LAA13 6", "LA9C3 6"+NL+"LA9DD 6"+NL+"LA9F8 6"+NL+"LA9FA 6"+NL+"LAA13 6")
rep(LIFT+"/vec007A.txt", "A8FE AA5D", "A8FE A9CE A9DE A9E1 AA5D")
print("A9CE port ok")
