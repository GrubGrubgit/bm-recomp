import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_B074"
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
WANT=["b4_entry_B074","b4_entry_B077"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
OLD_GOTO="cycles += 3;"+NL+"goto b4_LB08A;"
assert OFF.count(OLD_GOTO)==1 and ENF.count(OLD_GOTO)==1
OFF=OFF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
ENF=ENF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
assert "goto b4_LB08A" not in OFF and "goto b4_LB08A" not in ENF
D2="static void b4_entry_B074(void);"+NL+"static void b4_entry_B077(void);"+NL
B1="static void b4_entry_BDEA(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_BDEA(void);"+NL+D2+"static void b4_L960E(void);"
B2="static void b4_entry_BDEA(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_BDEA(void);"+NL+D2+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0xbdea: if (swbank == prg[4]) b4_entry_BDEA(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xb074: if (swbank == prg[4]) b4_entry_B074(); else __builtin_trap(); break;"+NL+"case 0xb077: if (swbank == prg[4]) b4_entry_B077(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "B071 6 LB071"+NL+"B09E 4 entry_B09E", "B071 6 LB071"+NL+"B074 4 entry_B074"+NL+"B077 4 entry_B077"+NL+"B09E 4 entry_B09E")
rep(LIFT+"/PROV_ALL.txt", "entry_B054 4"+NL+"entry_B09E 4", "entry_B054 4"+NL+"entry_B074 4"+NL+"entry_B077 4"+NL+"entry_B09E 4")
rep(LIFT+"/vec007A.txt", " BDE7 BDEA"+NL, " BDE7 BDEA B074 B077"+NL)
print("B074 port ok")
