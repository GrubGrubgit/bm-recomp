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
M58E=LIFT+"/manual_B58E"
M253=LIFT+"/manual_B253"
O58E=bodies(open(M58E+"/out_off.c").read(), ["b6_entry_B58E"])
E58E=bodies(open(M58E+"/out_enf.c").read(), ["b6_entry_B58E"])
O253=bodies(open(M253+"/out_off.c").read(), ["b6_entry_B253"])
E253=bodies(open(M253+"/out_enf.c").read(), ["b6_entry_B253"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
N58E="static void b6_entry_B58E(void);"+NL
N253="static void b6_entry_B253(void);"+NL
D_B20F="static void b6_entry_B20F(void);"+NL+"static void b6_entry_B401(void);"+NL
D_B57B1="static void b6_entry_B57B(void);"+NL+"static void b6_entry_B6E7(void);"+NL
D_B57B2="static void b6_entry_B57B(void);"+NL+"static void b6_entry_B5FB(void);"+NL
D_B23F="static void b6_entry_B23F(void);"+NL+"static void b6_entry_B26C(void);"+NL
rep(PO, D_B20F, "static void b6_entry_B20F(void);"+NL+N253+"static void b6_entry_B401(void);"+NL, 2)
rep(PE, D_B20F, "static void b6_entry_B20F(void);"+NL+N253+"static void b6_entry_B401(void);"+NL, 1)
for P in (PO,PE):
    rep(P, D_B57B1, "static void b6_entry_B57B(void);"+NL+N58E+"static void b6_entry_B6E7(void);"+NL)
    rep(P, D_B57B2, "static void b6_entry_B57B(void);"+NL+N58E+"static void b6_entry_B5FB(void);"+NL)
    rep(P, D_B23F, "static void b6_entry_B23F(void);"+NL+N253+"static void b6_entry_B26C(void);"+NL)
BB_B5FB="static void __attribute__((used)) b6_entry_B5FB(void) {"
BB_B26C="static void __attribute__((used)) b6_entry_B26C(void) {"
rep(PO, BB_B5FB, O58E+BB_B5FB)
rep(PE, BB_B5FB, E58E+BB_B5FB)
rep(PO, BB_B26C, O253+BB_B26C)
rep(PE, BB_B26C, E253+BB_B26C)
CB="case 0xB20F: if (swbank == prg[6]) b6_entry_B20F(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB58E: if (swbank == prg[6]) b6_entry_B58E(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB253: if (swbank == prg[6]) b6_entry_B253(); else __builtin_trap(); break;"+NL
for P in (PO,PE):
    rep(P, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B57D 4 entry_B57D"+NL+"B58D 4 LB58D"+NL, "B57D 4 entry_B57D"+NL+"B58D 4 LB58D"+NL+"B58E 6 entry_B58E"+NL)
rep(LIFT+"/ADDRMAP.txt", "B24F 6 LB24F"+NL+"B25D 4 LB25D"+NL, "B24F 6 LB24F"+NL+"B253 6 entry_B253"+NL+"B25D 4 LB25D"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B57B 6"+NL+"entry_B5FB 6"+NL, "entry_B57B 6"+NL+"entry_B58E 6"+NL+"entry_B5FB 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B23F 6"+NL+"entry_B26C 6"+NL, "entry_B23F 6"+NL+"entry_B253 6"+NL+"entry_B26C 6"+NL)
rep(LIFT+"/vec007A.txt", " B575 B578 B57B B20F"+NL, " B575 B578 B57B B20F B58E B253"+NL)
print("port5f splice ok")
