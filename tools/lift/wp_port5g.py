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
M97A=LIFT+"/manual_B97A"
O97A=bodies(open(M97A+"/out_off.c").read(), ["b6_entry_B97A"])
E97A=bodies(open(M97A+"/out_enf.c").read(), ["b6_entry_B97A"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
N97A="static void b6_entry_B97A(void);"+NL
D_B1="static void b6_entry_B91D(void);"+NL+"static void b6_entry_B97D(void);"+NL
D_B2="static void b6_entry_B935(void);"+NL+"static void b6_entry_B97D(void);"+NL
for P in (PO,PE):
    rep(P, D_B1, "static void b6_entry_B91D(void);"+NL+N97A+"static void b6_entry_B97D(void);"+NL)
    rep(P, D_B2, "static void b6_entry_B935(void);"+NL+N97A+"static void b6_entry_B97D(void);"+NL)
BB_B97D="static void __attribute__((used)) b6_entry_B97D(void) {"
rep(PO, BB_B97D, O97A+BB_B97D)
rep(PE, BB_B97D, E97A+BB_B97D)
CB="case 0xB253: if (swbank == prg[6]) b6_entry_B253(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB97A: if (swbank == prg[6]) b6_entry_B97A(); else __builtin_trap(); break;"+NL
for P in (PO,PE):
    rep(P, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B935 6 entry_B935"+NL+"B97D 6 entry_B97D"+NL, "B935 6 entry_B935"+NL+"B97A 6 entry_B97A"+NL+"B97D 6 entry_B97D"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B935 6"+NL+"entry_B97D 6"+NL, "entry_B935 6"+NL+"entry_B97A 6"+NL+"entry_B97D 6"+NL)
rep(LIFT+"/vec007A.txt", " B58E B253"+NL, " B58E B253 B97A"+NL)
print("port5g splice ok")

