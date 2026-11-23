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
M57B=LIFT+"/manual_B57B"
M575=LIFT+"/manual_B575"
M578=LIFT+"/manual_B578"
M20F=LIFT+"/manual_B20F"
O57B=bodies(open(M57B+"/out_off.c").read(), ["b6_entry_B57B"])
E57B=bodies(open(M57B+"/out_enf.c").read(), ["b6_entry_B57B"])
O575=bodies(open(M575+"/out_off.c").read(), ["b6_entry_B575"])
E575=bodies(open(M575+"/out_enf.c").read(), ["b6_entry_B575"])
O578=bodies(open(M578+"/out_off.c").read(), ["b6_entry_B578"])
E578=bodies(open(M578+"/out_enf.c").read(), ["b6_entry_B578"])
O20F=bodies(open(M20F+"/out_off.c").read(), ["b6_entry_B20F"])
E20F=bodies(open(M20F+"/out_enf.c").read(), ["b6_entry_B20F"])
PO=GEN+"/combined_off.c"
PE=GEN+"/combined_enf.c"
D_B202="static void b6_entry_B202(void);"+NL+"static void b6_entry_B401(void);"+NL
N20F="static void b6_entry_B20F(void);"+NL
rep(PO, D_B202, "static void b6_entry_B202(void);"+NL+N20F+"static void b6_entry_B401(void);"+NL, 2)
rep(PE, D_B202, "static void b6_entry_B202(void);"+NL+N20F+"static void b6_entry_B401(void);"+NL, 1)
N5758="static void b6_entry_B575(void);"+NL+"static void b6_entry_B578(void);"+NL+"static void b6_entry_B57B(void);"+NL
D53D67="static void b6_entry_B53D(void);"+NL+"static void b6_entry_B6E7(void);"+NL
D_D5557="static void b6_entry_B557(void);"+NL+"static void b6_entry_B5FB(void);"+NL
for P in (PO,PE):
    rep(P, D53D67, "static void b6_entry_B53D(void);"+NL+N5758+"static void b6_entry_B6E7(void);"+NL)
    rep(P, D_D5557, "static void b6_entry_B557(void);"+NL+N5758+"static void b6_entry_B5FB(void);"+NL)
BB_B23F="static void __attribute__((used)) b6_entry_B23F(void) {"
BB_B6E7="static void __attribute__((used)) b6_entry_B6E7(void) {"
rep(PO, BB_B23F, O20F+BB_B23F)
rep(PE, BB_B23F, E20F+BB_B23F)
rep(PO, BB_B6E7, O575+O578+O57B+BB_B6E7)
rep(PE, BB_B6E7, E575+E578+E57B+BB_B6E7)
CB="case 0xB53D: if (swbank == prg[6]) b6_entry_B53D(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xB575: if (swbank == prg[6]) b6_entry_B575(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB578: if (swbank == prg[6]) b6_entry_B578(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB57B: if (swbank == prg[6]) b6_entry_B57B(); else __builtin_trap(); break;"+NL
CN=CN+"case 0xB20F: if (swbank == prg[6]) b6_entry_B20F(); else __builtin_trap(); break;"+NL
for P in (PO,PE):
    rep(P, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B202 6 entry_B202"+NL+"B214 4 LB214"+NL, "B202 6 entry_B202"+NL+"B20F 6 entry_B20F"+NL+"B214 4 LB214"+NL)
rep(LIFT+"/ADDRMAP.txt", "B56E 6 LB56E"+NL+"B57D 4 entry_B57D"+NL, "B56E 6 LB56E"+NL+"B575 6 entry_B575"+NL+"B578 6 entry_B578"+NL+"B57B 6 entry_B57B"+NL+"B57D 4 entry_B57D"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B202 6"+NL+"entry_B23F 6"+NL, "entry_B202 6"+NL+"entry_B20F 6"+NL+"entry_B23F 6"+NL)
rep(LIFT+"/PROV_ALL.txt", "entry_B557 6"+NL+"entry_B5FB 6"+NL, "entry_B557 6"+NL+"entry_B575 6"+NL+"entry_B578 6"+NL+"entry_B57B 6"+NL+"entry_B5FB 6"+NL)
rep(LIFT+"/vec007A.txt", " B202 B53D"+NL, " B202 B53D B575 B578 B57B B20F"+NL)
print("port5e splice ok")
