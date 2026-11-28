import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, (path, old[:70], c)
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:50])
def bodies(src, want):
    parts=src.split("static void __attribute__((used)) ")
    got={}
    for p in parts:
        nm=p.split("(void)")[0]
        if nm in want:
            cut=p.find(NL+"static void ")
            if cut>=0:
                p=p[:cut]+NL
            got[nm]="static void __attribute__((used)) "+p.rstrip()+NL
    assert set(got)==set(want), (set(got), set(want))
    blob="".join([got[k] for k in want])
    assert "__builtin_trap" not in blob
    return blob
MB=LIFT+"/manual_B2EC"
OB=bodies(open(MB+"/out_off.c").read(), ["b6_entry_B2EC"])
EB=bodies(open(MB+"/out_enf.c").read(), ["b6_entry_B2EC"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
D1="static void b6_entry_B2AB(void);"+NL+"static void b6_entry_B2EF(void);"+NL
N1="static void b6_entry_B2AB(void);"+NL+"static void b6_entry_B2EC(void);"+NL+"static void b6_entry_B2EF(void);"+NL
D2="static void b6_entry_B2DB(void);"+NL+"static void b6_entry_B2EF(void);"+NL
N2="static void b6_entry_B2DB(void);"+NL+"static void b6_entry_B2EC(void);"+NL+"static void b6_entry_B2EF(void);"+NL
rep(PO, D1, N1)
rep(PE, D1, N1)
rep(PO, D2, N2)
rep(PE, D2, N2)
BB="static void __attribute__((used)) b6_entry_B2EF(void) {"
rep(PO, BB, OB+BB)
rep(PE, BB, EB+BB)
CB="case 0xB2EF: b6_entry_B2EF(); break;"+NL
CN="case 0xB2EC: b6_entry_B2EC(); break;"+NL+CB
rep(PO, CB, CN)
rep(PE, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B2EB 6 LB2EB"+NL+"B2EF 6 entry_B2EF"+NL, "B2EB 6 LB2EB"+NL+"B2EC 6 entry_B2EC"+NL+"B2EF 6 entry_B2EF"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B2DB 6"+NL+"entry_B2EF 6"+NL, "entry_B2DB 6"+NL+"entry_B2EC 6"+NL+"entry_B2EF 6"+NL)
rep(LIFT+"/vec007A.txt", " B2AB B2EF B3E3", " B2AB B2EC B2EF B3E3")
print("b2ec splice ok")
