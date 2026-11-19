import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_BE54"
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
WANT=["b4_entry_BE54","b4_entry_BE57"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
OLD_GOTO="cycles += 3;"+NL+"goto b4_LBE60;"
assert OFF.count(OLD_GOTO)==1 and ENF.count(OLD_GOTO)==1
OFF=OFF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
ENF=ENF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
D2="static void b4_entry_BE54(void);"+NL+"static void b4_entry_BE57(void);"+NL
B1="static void b4_entry_B08E(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_B08E(void);"+NL+D2+"static void b4_L960E(void);"
B2="static void b4_entry_B08E(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_B08E(void);"+NL+D2+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0xb08e: if (swbank == prg[4]) b4_entry_B08E(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xbe54: if (swbank == prg[4]) b4_entry_BE54(); else __builtin_trap(); break;"+NL+"case 0xbe57: if (swbank == prg[4]) b4_entry_BE57(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "BE0E 4 entry_BE0E"+NL+"BE16 5 LBE16", "BE0E 4 entry_BE0E"+NL+"BE54 4 entry_BE54"+NL+"BE57 4 entry_BE57"+NL+"BE16 5 LBE16")
rep(LIFT+"/PROV_ALL.txt", "entry_BE0E 4"+NL+"entry_BE3E 4", "entry_BE0E 4"+NL+"entry_BE54 4"+NL+"entry_BE57 4"+NL+"entry_BE3E 4")
rep(LIFT+"/vec007A.txt", " B08B B08E"+NL, " B08B B08E BE54 BE57"+NL)
print("BE54 port ok")
