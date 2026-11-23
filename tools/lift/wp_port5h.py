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
M4A3=LIFT+"/manual_B4A3"
O4A3=bodies(open(M4A3+"/out_off.c").read(), ["b6_entry_B4A3"])
E4A3=bodies(open(M4A3+"/out_enf.c").read(), ["b6_entry_B4A3"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
N4A3="static void b6_entry_B4A3(void);"+NL
D_B1="static void b6_entry_B401(void);"+NL+"static void b6_entry_B494(void);"+NL
D_B2="static void b6_entry_B401(void);"+NL+"static void b6_entry_B457(void);"+NL
rep(PO, D_B1, "static void b6_entry_B401(void);"+NL+N4A3+"static void b6_entry_B494(void);"+NL)
rep(PE, D_B1, "static void b6_entry_B401(void);"+NL+N4A3+"static void b6_entry_B494(void);"+NL)
rep(PO, D_B2, "static void b6_entry_B401(void);"+NL+N4A3+"static void b6_entry_B457(void);"+NL)
BB_B4A6="static void __attribute__((used)) b6_entry_B4A6(void) {"
rep(PO, BB_B4A6, O4A3+BB_B4A6)
rep(PE, BB_B4A6, E4A3+BB_B4A6)
CB="case 0xB97A: if (swbank == prg[6]) b6_entry_B97A(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB4A3: if (swbank == prg[6]) b6_entry_B4A3(); else __builtin_trap(); break;"+NL
for P in (PO,PE):
    rep(P, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B497 6 entry_B497"+NL+"B4A6 6 entry_B4A6"+NL, "B497 6 entry_B497"+NL+"B4A3 6 entry_B4A3"+NL+"B4A6 6 entry_B4A6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B497 6"+NL+"entry_B4A6 6"+NL, "entry_B497 6"+NL+"entry_B4A3 6"+NL+"entry_B4A6 6"+NL)
rep(LIFT+"/vec007A.txt", " B253 B97A"+NL, " B253 B97A B4A3"+NL)
print("port5h splice ok")

