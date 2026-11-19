import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_8B96"
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
WANT=["b4_entry_8B96"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D1="static void b4_entry_8B96(void);"+NL
B1="static void b4_entry_BE64(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_BE64(void);"+NL+D1+"static void b4_L960E(void);"
B2="static void b4_entry_BE64(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_BE64(void);"+NL+D1+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0xbe64: if (swbank == prg[4]) b4_entry_BE64(); else __builtin_trap(); break;"+NL
CN=CB+"case 0x8b96: if (swbank == prg[4]) b4_entry_8B96(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "8B8A 6 entry_8B8A"+NL+"8B99 4 entry_8B99", "8B8A 6 entry_8B8A"+NL+"8B96 4 entry_8B96"+NL+"8B99 4 entry_8B99")
rep(LIFT+"/PROV_ALL.txt", "entry_8B99 4"+NL+"entry_8BA4 4", "entry_8B99 4"+NL+"entry_8B96 4"+NL+"entry_8BA4 4")
rep(LIFT+"/vec007A.txt", " BE61 BE64"+NL, " BE61 BE64 8B96"+NL)
print("8B96 port ok")
