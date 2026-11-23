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
M58B=LIFT+"/manual_B58B"
O58B=bodies(open(M58B+"/out_off.c").read(), ["b6_entry_B58B"])
E58B=bodies(open(M58B+"/out_enf.c").read(), ["b6_entry_B58B"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
N58B="static void b6_entry_B58B(void);"+NL
D_B="static void b6_entry_B57B(void);"+NL+"static void b6_entry_B58E(void);"+NL
for P in (PO,PE):
    rep(P, D_B, "static void b6_entry_B57B(void);"+NL+N58B+"static void b6_entry_B58E(void);"+NL, 2)
BB_B58E="static void __attribute__((used)) b6_entry_B58E(void) {"
rep(PO, BB_B58E, O58B+BB_B58E)
rep(PE, BB_B58E, E58B+BB_B58E)
CB="case 0xB4A3: if (swbank == prg[6]) b6_entry_B4A3(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB58B: if (swbank == prg[6]) b6_entry_B58B(); else __builtin_trap(); break;"+NL
for P in (PO,PE):
    rep(P, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B58D 4 LB58D"+NL+"B58E 6 entry_B58E"+NL, "B58D 4 LB58D"+NL+"B58B 6 entry_B58B"+NL+"B58E 6 entry_B58E"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B57B 6"+NL+"entry_B58E 6"+NL, "entry_B57B 6"+NL+"entry_B58B 6"+NL+"entry_B58E 6"+NL)
rep(LIFT+"/vec007A.txt", " B97A B4A3"+NL, " B97A B4A3 B58B"+NL)
print("port5i splice ok")

