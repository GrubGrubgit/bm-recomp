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
M494=LIFT+"/manual_B494"
M497=LIFT+"/manual_B497"
M91D=LIFT+"/manual_B91D"
MA8D5=LIFT+"/manual_A8D5"
O494=bodies(open(M494+"/out_off.c").read(), ["b6_entry_B494"])
E494=bodies(open(M494+"/out_enf.c").read(), ["b6_entry_B494"])
O497=bodies(open(M497+"/out_off.c").read(), ["b6_entry_B497"])
E497=bodies(open(M497+"/out_enf.c").read(), ["b6_entry_B497"])
O91D=bodies(open(M91D+"/out_off.c").read(), ["b6_entry_B91D"])
E91D=bodies(open(M91D+"/out_enf.c").read(), ["b6_entry_B91D"])
OA8D5=bodies(open(MA8D5+"/out_off.c").read(), ["b6_entry_A8D5"])
EA8D5=bodies(open(MA8D5+"/out_enf.c").read(), ["b6_entry_A8D5"])
NA8D5="static void b6_entry_A8D5(void);"+NL
NB49497="static void b6_entry_B494(void);"+NL+"static void b6_entry_B497(void);"+NL
NB91D="static void b6_entry_B91D(void);"+NL
D_A="static void b6_entry_A871(void);"+NL+"static void b6_entry_A8FB(void);"+NL
D_B="static void b6_entry_B401(void);"+NL+"static void b6_entry_B6E7(void);"+NL
D_C="static void b6_entry_B846(void);"+NL+"static void __attribute__((used)) b7_entry_C00C(void) {"
D_D="static void b6_entry_A89F(void);"+NL+"static void b6_entry_A8FB(void);"+NL
D_E="static void b6_entry_B491(void);"+NL+"static void b6_entry_B4DD(void);"+NL
D_F="static void b6_entry_B846(void);"+NL+"static void b6_entry_B859(void);"+NL
CB="case 0xB846: b6_entry_B846(); break;"+NL
CN=CB+"case 0xB494: if (swbank == prg[6]) b6_entry_B494(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB497: if (swbank == prg[6]) b6_entry_B497(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB91D: if (swbank == prg[6]) b6_entry_B91D(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xA8D5: if (swbank == prg[6]) b6_entry_A8D5(); else __builtin_trap(); break;"+NL
BB_A8FB="static void __attribute__((used)) b6_entry_A8FB(void) {"
BB_B508="static void __attribute__((used)) b6_entry_B508(void) {"
BB_B935="static void __attribute__((used)) b6_entry_B935(void) {"
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
for P in (PO,PE):
    rep(P, D_A, "static void b6_entry_A871(void);"+NL+NA8D5+"static void b6_entry_A8FB(void);"+NL)
    rep(P, D_B, "static void b6_entry_B401(void);"+NL+NB49497+"static void b6_entry_B6E7(void);"+NL)
    rep(P, D_D, "static void b6_entry_A89F(void);"+NL+NA8D5+"static void b6_entry_A8FB(void);"+NL)
    rep(P, D_E, "static void b6_entry_B491(void);"+NL+NB49497+"static void b6_entry_B4DD(void);"+NL)
    rep(P, D_F, "static void b6_entry_B846(void);"+NL+NB91D+"static void b6_entry_B859(void);"+NL)
    rep(P, CB, CN)
for P in (PO,PE):
    rep(P, D_C, "static void b6_entry_B846(void);"+NL+NB91D+"static void __attribute__((used)) b7_entry_C00C(void) {")
rep(PO, BB_A8FB, OA8D5+BB_A8FB)
rep(PE, BB_A8FB, EA8D5+BB_A8FB)
rep(PO, BB_B508, O494+O497+BB_B508)
rep(PE, BB_B508, E494+E497+BB_B508)
rep(PO, BB_B935, O91D+BB_B935)
rep(PE, BB_B935, E91D+BB_B935)
rep(LIFT+"/ADDRMAP.txt", "B491 6 entry_B491"+NL+"B4A9 4 entry_B4A9"+NL, "B491 6 entry_B491"+NL+"B494 6 entry_B494"+NL+"B497 6 entry_B497"+NL+"B4A9 4 entry_B4A9"+NL)
rep(LIFT+"/ADDRMAP.txt", "B910 6 LB910"+NL+"B935 6 entry_B935"+NL, "B910 6 LB910"+NL+"B91D 6 entry_B91D"+NL+"B935 6 entry_B935"+NL)
rep(LIFT+"/ADDRMAP.txt", "A8ED 4 LA8ED"+NL+"A8FB 6 entry_A8FB"+NL, "A8ED 4 LA8ED"+NL+"A8D5 6 entry_A8D5"+NL+"A8FB 6 entry_A8FB"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B491 6"+NL+"entry_B4DD 6"+NL, "entry_B491 6"+NL+"entry_B494 6"+NL+"entry_B497 6"+NL+"entry_B4DD 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B8EF 6"+NL+"entry_B935 6"+NL, "entry_B8EF 6"+NL+"entry_B91D 6"+NL+"entry_B935 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_A89F 6"+NL+"entry_A8FB 6"+NL, "entry_A89F 6"+NL+"entry_A8D5 6"+NL+"entry_A8FB 6"+NL)
rep(LIFT+"/vec007A.txt", " B843 B846 AC63"+NL, " B843 B846 AC63 B494 B497 B91D A8D5"+NL)
print("port5 splice ok")
