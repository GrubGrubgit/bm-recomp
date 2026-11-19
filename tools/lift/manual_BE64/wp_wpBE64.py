import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_BE64"
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
OFF7=bodies(open(M+"/out_b7_off.c").read(), ["b7_entry_C048","b7_entry_C051","b7_entry_E107","b7_entry_E120"])
ENF7=bodies(open(M+"/out_b7_enf.c").read(), ["b7_entry_C048","b7_entry_C051","b7_entry_E107","b7_entry_E120"])
WANT4=["b4_entry_BE61","b4_entry_BE64"]
OFF4=bodies(open(M+"/out_b4_off.c").read(), WANT4)
ENF4=bodies(open(M+"/out_b4_enf.c").read(), WANT4)
OFF4=OFF4.replace("b4_LC02D","b7_LC02D")
ENF4=ENF4.replace("b4_LC02D","b7_LC02D")
assert "b4_LC02D" not in OFF4 and "b4_LC02D" not in ENF4
OLD_TAIL=('nmi_poll("b4_entry_BE64");'+NL)*3+"cycles += 3;"+NL+"b4_entry_BE95(); return;"
assert OFF4.count(OLD_TAIL)==1 and ENF4.count(OLD_TAIL)==1, (OFF4.count(OLD_TAIL), ENF4.count(OLD_TAIL))
OFF4=OFF4.replace(OLD_TAIL, "b4_entry_BE95(); return;")
ENF4=ENF4.replace(OLD_TAIL, "b4_entry_BE95(); return;")
D4="static void b4_entry_BE61(void);"+NL+"static void b4_entry_BE64(void);"+NL
B1="static void b4_entry_BE57(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_BE57(void);"+NL+D4+"static void b4_L960E(void);"
B2="static void b4_entry_BE57(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_BE57(void);"+NL+D4+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB="case 0xbe57: if (swbank == prg[4]) b4_entry_BE57(); else __builtin_trap(); break;"+NL
CN=CB+"case 0xbe61: if (swbank == prg[4]) b4_entry_BE61(); else __builtin_trap(); break;"+NL+"case 0xbe64: if (swbank == prg[4]) b4_entry_BE64(); else __builtin_trap(); break;"+NL
for nm,BB7,BB4 in (("combined_off.c",OFF7,OFF4),("combined_enf.c",ENF7,ENF4)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB7+BB4+B7B)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "BE57 4 entry_BE57"+NL+"BE16 5 LBE16", "BE57 4 entry_BE57"+NL+"BE61 4 entry_BE61"+NL+"BE64 4 entry_BE64"+NL+"BE16 5 LBE16")
rep(LIFT+"/PROV_ALL.txt", "entry_BE57 4"+NL+"entry_BE3E 4", "entry_BE57 4"+NL+"entry_BE61 4"+NL+"entry_BE64 4"+NL+"entry_BE3E 4")
rep(LIFT+"/vec007A.txt", " BE54 BE57"+NL, " BE54 BE57 BE61 BE64"+NL)
print("BE64 port ok")
