import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_92AC"
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
WANT=["b4_entry_92AC"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D1="static void b4_entry_92AC(void);"+NL
B1="static void b4_entry_923C(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_923C(void);"+NL+D1+"static void b4_L960E(void);"
B2="static void b4_entry_923C(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_923C(void);"+NL+D1+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0x923c: if (swbank == prg[4]) b4_entry_923C(); else __builtin_trap(); break;"+NL
CN=CB+"case 0x92ac: if (swbank == prg[4]) b4_entry_92AC(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "92A3 4 L92A3"+NL+"92AC 6 L92AC", "92A3 4 L92A3"+NL+"92AC 4 entry_92AC"+NL+"92AC 6 L92AC")
rep(LIFT+"/PROV_ALL.txt", "entry_926E 4"+NL+"entry_92AF 4", "entry_926E 4"+NL+"entry_92AC 4"+NL+"entry_92AF 4")
rep(LIFT+"/vec007A.txt", " 9F62 9FF1 9FEE 923C"+NL, " 9F62 9FF1 9FEE 923C 92AC"+NL)
print("92AC port ok")
