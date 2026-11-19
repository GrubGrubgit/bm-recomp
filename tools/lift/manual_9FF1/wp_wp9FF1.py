import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_9FF1"
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
WANT=["b4_entry_9FF1"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D1="static void b4_entry_9FF1(void);"+NL
B1="static void b4_entry_9F62(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_9F62(void);"+NL+D1+"static void b4_L960E(void);"
B2="static void b4_entry_9F62(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_9F62(void);"+NL+D1+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0x9f62: if (swbank == prg[4]) b4_entry_9F62(); else __builtin_trap(); break;"+NL
CN=CB+"case 0x9ff1: if (swbank == prg[4]) b4_entry_9FF1(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "9FB4 4 L9FB4"+NL+"9FB7 4 entry_9FB7", "9FB4 4 L9FB4"+NL+"9FF1 4 entry_9FF1"+NL+"9FB7 4 entry_9FB7")
rep(LIFT+"/PROV_ALL.txt", "entry_9FD3 4"+NL+"entry_A058 4", "entry_9FD3 4"+NL+"entry_9FF1 4"+NL+"entry_A058 4")
rep(LIFT+"/vec007A.txt", " A589 A58C 9F62"+NL, " A589 A58C 9F62 9FF1"+NL)
print("9FF1 port ok")
