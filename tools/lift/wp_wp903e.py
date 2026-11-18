import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
WR="/data/data/com.termux/files/home/ai-bridge/session-homes/sess-20261116-175343-0303/wrun"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, (path, old[:80], c)
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:56])
def bodies(src):
    parts=src.split("static void __attribute__((used)) ")
    want=["b4_entry_903E"]
    got={}
    for p in parts:
        nm=p.split("(void)")[0]
        if nm in want:
            cut=p.find(NL+"static void ")
            if cut>=0:
                p=p[:cut]+NL
            got[nm]="static void __attribute__((used)) "+p.rstrip()+NL
    assert set(got)==set(want), set(got)
    blob="".join([got[k] for k in want])
    assert "__builtin_trap" not in blob
    assert "b4_entry_9060();" in blob
    assert "b4_entry_903E" in blob
    return blob
OFFB=bodies(open(WR+"/out903e_off.c").read())
ENFB=bodies(open(WR+"/out903e_enf.c").read())
D1B="static void b4_entry_903E(void);"+NL
CASE1="case 0x903E: if (swbank == prg[4]) b4_entry_903E(); else __builtin_trap(); break;"+NL
D14="static void b4_entry_9014(void);"+NL+"static void b4_entry_B7BD(void);"
D14N="static void b4_entry_9014(void);"+NL+D1B+"static void b4_entry_B7BD(void);"
D14T="static void b4_entry_9014(void);"+NL+"static void b4_L960E(void);"
D14TN="static void b4_entry_9014(void);"+NL+D1B+"static void b4_L960E(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
C14O="case 0x9014: if (swbank == prg[4]) b4_entry_9014(); else __builtin_trap(); break;"+NL+"case 0xAF45:"
C14NO="case 0x9014: if (swbank == prg[4]) b4_entry_9014(); else __builtin_trap(); break;"+NL+CASE1+"case 0xAF45:"
C14E="case 0x9014: if (swbank == prg[4]) b4_entry_9014(); else __builtin_trap(); break;"+NL+"case 0xB64D:"
C14NE="case 0x9014: if (swbank == prg[4]) b4_entry_9014(); else __builtin_trap(); break;"+NL+CASE1+"case 0xB64D:"
for nm,BB in (("bank4_off.c",OFFB),("bank4_enf.c",ENFB)):
    rep(GEN+"/"+nm, D14, D14N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
for nm,BB,CO,CN in (("combined_off.c",OFFB,C14O,C14NO),("combined_enf.c",ENFB,C14E,C14NE)):
    rep(GEN+"/"+nm, D14, D14N)
    rep(GEN+"/"+nm, D14T, D14TN)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CO, CN)
rep(LIFT+"/ADDRMAP.txt", "9014 4 entry_9014"+NL+"9060 4 entry_9060", "9014 4 entry_9014"+NL+"903E 4 entry_903E"+NL+"9060 4 entry_9060")
rep(LIFT+"/PROV_ALL.txt", "entry_9014 4"+NL+"entry_9060 4", "entry_9014 4"+NL+"entry_903E 4"+NL+"entry_9060 4")
rep(LIFT+"/vec007A.txt", "B785 B78F B792 9014"+NL, "B785 B78F B792 9014 903E"+NL)
print("903E port ok")
