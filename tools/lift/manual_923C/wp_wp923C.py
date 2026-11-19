import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_923C"
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
WANT=["b4_entry_923C"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D1="static void b4_entry_923C(void);"+NL
B1="static void b4_entry_9FEE(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_9FEE(void);"+NL+D1+"static void b4_L960E(void);"
B2="static void b4_entry_9FEE(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_9FEE(void);"+NL+D1+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0x9fee: if (swbank == prg[4]) b4_entry_9FEE(); else __builtin_trap(); break;"+NL
CN=CB+"case 0x923c: if (swbank == prg[4]) b4_entry_923C(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "9236 4 entry_9236"+NL+"923F 4 entry_923F", "9236 4 entry_9236"+NL+"923C 4 entry_923C"+NL+"923F 4 entry_923F")
rep(LIFT+"/PROV_ALL.txt", "entry_9236 4"+NL+"entry_923F 4", "entry_9236 4"+NL+"entry_923C 4"+NL+"entry_923F 4")
rep(LIFT+"/vec007A.txt", " 9F62 9FF1 9FEE"+NL, " 9F62 9FF1 9FEE 923C"+NL)
print("923C port ok")
