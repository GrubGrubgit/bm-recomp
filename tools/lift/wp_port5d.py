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
M53D=LIFT+"/manual_B53D"
M202=LIFT+"/manual_B202"
O53D=bodies(open(M53D+"/out_off.c").read(), ["b6_entry_B53D"])
E53D=bodies(open(M53D+"/out_enf.c").read(), ["b6_entry_B53D"])
O202=bodies(open(M202+"/out_off.c").read(), ["b6_entry_B202"])
E202=bodies(open(M202+"/out_enf.c").read(), ["b6_entry_B202"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
N202="static void b6_entry_B202(void);"+NL
N53D="static void b6_entry_B53D(void);"+NL
D_B3FE="static void b6_entry_B3FE(void);"+NL+"static void b6_entry_B401(void);"+NL
D_B4A6="static void b6_entry_B4A6(void);"+NL+"static void b6_entry_B6E7(void);"+NL
D_B508="static void b6_entry_B508(void);"+NL+"static void b6_entry_B557(void);"+NL
for P in (PO,PE):
    rep(P, D_B3FE, "static void b6_entry_B3FE(void);"+NL+N202+"static void b6_entry_B401(void);"+NL, 2)
    rep(P, D_B4A6, "static void b6_entry_B4A6(void);"+NL+N53D+"static void b6_entry_B6E7(void);"+NL)
    rep(P, D_B508, "static void b6_entry_B508(void);"+NL+N53D+"static void b6_entry_B557(void);"+NL)
CB="case 0xBA03: if (swbank == prg[6]) b6_entry_BA03(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB202: if (swbank == prg[6]) b6_entry_B202(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB53D: if (swbank == prg[6]) b6_entry_B53D(); else __builtin_trap(); break;"+NL
BB_B508="static void __attribute__((used)) b6_entry_B508(void) {"
BB_B557="static void __attribute__((used)) b6_entry_B557(void) {"
for P in (PO,PE):
    rep(P, CB, CN)
rep(PO, BB_B508, O202+BB_B508)
rep(PE, BB_B508, E202+BB_B508)
rep(PO, BB_B557, O53D+BB_B557)
rep(PE, BB_B557, E53D+BB_B557)
rep(LIFT+"/ADDRMAP.txt", "B1FE 6 LB1FE"+NL+"B214 4 LB214"+NL, "B1FE 6 LB1FE"+NL+"B202 6 entry_B202"+NL+"B214 4 LB214"+NL)
rep(LIFT+"/ADDRMAP.txt", "B53A 4 entry_B53A"+NL+"B54F 4 entry_B54F"+NL, "B53A 4 entry_B53A"+NL+"B53D 6 entry_B53D"+NL+"B54F 4 entry_B54F"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B1DE 6"+NL+"entry_B23F 6"+NL, "entry_B1DE 6"+NL+"entry_B202 6"+NL+"entry_B23F 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B508 6"+NL+"entry_B557 6"+NL, "entry_B508 6"+NL+"entry_B53D 6"+NL+"entry_B557 6"+NL)
rep(LIFT+"/vec007A.txt", " B4A6 B97D BA03"+NL, " B4A6 B97D BA03 B202 B53D"+NL)
print("port5d splice ok")
