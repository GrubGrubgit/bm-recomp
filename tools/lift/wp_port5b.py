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
M4A6=LIFT+"/manual_B4A6"
M97D=LIFT+"/manual_B97D"
O4A6=bodies(open(M4A6+"/out_off.c").read(), ["b6_entry_B4A6"])
E4A6=bodies(open(M4A6+"/out_enf.c").read(), ["b6_entry_B4A6"])
O97D=bodies(open(M97D+"/out_off.c").read(), ["b6_entry_B97D"])
E97D=bodies(open(M97D+"/out_enf.c").read(), ["b6_entry_B97D"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
D_B1="static void b6_entry_B494(void);"+NL+"static void b6_entry_B497(void);"+NL
D_C1="static void b6_entry_B91D(void);"+NL+"static void __attribute__((used)) b7_entry_C00C(void) {"
D_E1="static void b6_entry_B497(void);"+NL+"static void b6_entry_B4DD(void);"+NL
D_F1="static void b6_entry_B935(void);"+NL+"static void b6_entry_B965(void);"+NL
N4A6="static void b6_entry_B4A6(void);"+NL
N97D="static void b6_entry_B97D(void);"+NL
B401G="static void b6_entry_B401(void);"+NL
B6E7G="static void b6_entry_B6E7(void);"+NL
B491G="static void b6_entry_B491(void);"+NL
B4DDG="static void b6_entry_B4DD(void);"+NL
for P in (PO,PE):
    rep(P, B401G+D_B1+B6E7G, B401G+D_B1+N4A6+B6E7G)
    rep(P, B491G+D_B1+B4DDG, B491G+D_B1+N4A6+B4DDG)
    rep(P, D_C1, "static void b6_entry_B91D(void);"+NL+N97D+"static void __attribute__((used)) b7_entry_C00C(void) {")
    rep(P, D_F1, "static void b6_entry_B935(void);"+NL+N97D+"static void b6_entry_B965(void);"+NL)
CA8D5="case 0xA8D5: if (swbank == prg[6]) b6_entry_A8D5(); else __builtin_trap(); break;"+NL
CN2=CA8D5+"case 0xB4A6: if (swbank == prg[6]) b6_entry_B4A6(); else __builtin_trap(); break;"+NL
CN2=CN2+"case 0xB97D: if (swbank == prg[6]) b6_entry_B97D(); else __builtin_trap(); break;"+NL
BB_B508="static void __attribute__((used)) b6_entry_B508(void) {"
BB_B9C0="static void __attribute__((used)) b6_entry_B9C0(void) {"
for P in (PO,PE):
    rep(P, CA8D5, CN2)
rep(PO, BB_B508, O4A6+BB_B508)
rep(PE, BB_B508, E4A6+BB_B508)
rep(PO, BB_B9C0, O97D+BB_B9C0)
rep(PE, BB_B9C0, E97D+BB_B9C0)
rep(LIFT+"/ADDRMAP.txt", "B497 6 entry_B497"+NL+"B4A9 4 entry_B4A9"+NL, "B497 6 entry_B497"+NL+"B4A6 6 entry_B4A6"+NL+"B4A9 4 entry_B4A9"+NL)
rep(LIFT+"/ADDRMAP.txt", "B935 6 entry_B935"+NL+"B965 6 entry_B965"+NL, "B935 6 entry_B935"+NL+"B97D 6 entry_B97D"+NL+"B965 6 entry_B965"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B497 6"+NL+"entry_B4DD 6"+NL, "entry_B497 6"+NL+"entry_B4A6 6"+NL+"entry_B4DD 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B935 6"+NL+"entry_B965 6"+NL, "entry_B935 6"+NL+"entry_B97D 6"+NL+"entry_B965 6"+NL)
rep(LIFT+"/vec007A.txt", " B91D A8D5"+NL, " B91D A8D5 B4A6 B97D"+NL)
print("port5b splice ok")
