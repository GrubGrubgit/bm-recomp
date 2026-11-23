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
M=LIFT+"/manual_BA03"
OB=bodies(open(M+"/out_off.c").read(), ["b6_entry_BA03"])
EB=bodies(open(M+"/out_enf.c").read(), ["b6_entry_BA03"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
NB="static void b6_entry_BA03(void);"+NL
D1="static void b6_entry_B97D(void);"+NL+"static void __attribute__((used)) b7_entry_C00C(void) {"
D2="static void b6_entry_B9C0(void);"+NL+"static void b6_entry_BA43(void);"+NL
for P in (PO,PE):
    rep(P, D1, "static void b6_entry_B97D(void);"+NL+NB+"static void __attribute__((used)) b7_entry_C00C(void) {")
    rep(P, D2, "static void b6_entry_B9C0(void);"+NL+NB+"static void b6_entry_BA43(void);"+NL)
CB="case 0xB97D: if (swbank == prg[6]) b6_entry_B97D(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xBA03: if (swbank == prg[6]) b6_entry_BA03(); else __builtin_trap(); break;"+NL
BB="static void __attribute__((used)) b6_entry_BA43(void) {"
for P in (PO,PE):
    rep(P, CB, CN)
rep(PO, BB, OB+BB)
rep(PE, BB, EB+BB)
rep(LIFT+"/ADDRMAP.txt", "B9C0 6 entry_B9C0"+NL+"B9C9 4 LB9C9"+NL, "B9C0 6 entry_B9C0"+NL+"BA03 6 entry_BA03"+NL+"B9C9 4 LB9C9"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B9C0 6"+NL+"entry_BA43 6"+NL, "entry_B9C0 6"+NL+"entry_BA03 6"+NL+"entry_BA43 6"+NL)
rep(LIFT+"/vec007A.txt", " B4A6 B97D"+NL, " B4A6 B97D BA03"+NL)
print("port5c splice ok")
