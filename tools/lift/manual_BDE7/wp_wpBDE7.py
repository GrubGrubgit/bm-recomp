import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_BDE7"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, (path, old[:80], c)
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:56])
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
WANT=["b4_entry_BDE7","b4_entry_BDEA"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
T1="nmi_poll(QQb4_entry_BDEAQQ);"
T1=T1.replace("QQ", chr(34))
OLD_TAIL=(T1+NL)*2+"cycles += 3;"+NL+"b4_entry_BE0E(); return;"
assert OFF.count(OLD_TAIL)==1 and ENF.count(OLD_TAIL)==1, (OFF.count(OLD_TAIL), ENF.count(OLD_TAIL))
OFF=OFF.replace(OLD_TAIL, "b4_entry_BE0E(); return;")
ENF=ENF.replace(OLD_TAIL, "b4_entry_BE0E(); return;")
D2="static void b4_entry_BDE7(void);"+NL+"static void b4_entry_BDEA(void);"+NL
B1="static void b4_entry_BD6C(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_BD6C(void);"+NL+D2+"static void b4_L960E(void);"
B2="static void b4_entry_BD6C(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_BD6C(void);"+NL+D2+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0xBD6C: if (swbank == prg[4]) b4_entry_BD6C(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xbde7: if (swbank == prg[4]) b4_entry_BDE7(); else __builtin_trap(); break;"+NL+"case 0xbdea: if (swbank == prg[4]) b4_entry_BDEA(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "BDE0 4 entry_BDE0"+NL+"BDF6 5 entry_BDF6", "BDE0 4 entry_BDE0"+NL+"BDE7 4 entry_BDE7"+NL+"BDEA 4 entry_BDEA"+NL+"BDF6 5 entry_BDF6")
rep(LIFT+"/PROV_ALL.txt", "entry_BDE0 4"+NL+"entry_BE0E 4", "entry_BDE0 4"+NL+"entry_BDE7 4"+NL+"entry_BDEA 4"+NL+"entry_BE0E 4")
rep(LIFT+"/vec007A.txt", " BD69 BD6C"+NL, " BD69 BD6C BDE7 BDEA"+NL)
print("BDE7 port ok")
