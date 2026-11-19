import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_A571"
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
WANT=["b4_entry_A571","b4_entry_A574","b4_entry_A589"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D3="static void b4_entry_A571(void);"+NL+"static void b4_entry_A574(void);"+NL+"static void b4_entry_A589(void);"+NL
B1="static void b4_entry_8B96(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_8B96(void);"+NL+D3+"static void b4_L960E(void);"
B2="static void b4_entry_8B96(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_8B96(void);"+NL+D3+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0x8b96: if (swbank == prg[4]) b4_entry_8B96(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xa571: if (swbank == prg[4]) b4_entry_A571(); else __builtin_trap(); break;"+NL+"case 0xa574: if (swbank == prg[4]) b4_entry_A574(); else __builtin_trap(); break;"+NL+"case 0xa589: if (swbank == prg[4]) b4_entry_A589(); else __builtin_trap(); break;"+NL
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "A56E 6 entry_A56E"+NL+"A580 6 entry_A580", "A56E 6 entry_A56E"+NL+"A571 4 entry_A571"+NL+"A574 4 entry_A574"+NL+"A589 4 entry_A589"+NL+"A580 6 entry_A580")
rep(LIFT+"/PROV_ALL.txt", "entry_A56E 6"+NL+"entry_A580 6", "entry_A56E 6"+NL+"entry_A571 4"+NL+"entry_A574 4"+NL+"entry_A589 4"+NL+"entry_A580 6")
rep(LIFT+"/vec007A.txt", " BE61 BE64 8B96"+NL, " BE61 BE64 8B96 A571 A574 A589"+NL)
print("A571 port ok")
