import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, old[:80]
    open(path,"w").write(s.replace(old,new))
    print("ok", os.path.basename(path), old[:56])
def bodies(src):
    parts=src.split("static void __attribute__((used)) ")
    want=["b4_entry_B785"]
    got={}
    for p in parts:
        nm=p.split("(void)")[0]
        if nm in want:
            cut=p.find(NL+"static void ")
            if cut>=0:
                p=p[:cut]+NL
            got[nm]="static void __attribute__((used)) "+p.rstrip()+NL
    assert set(got)==set(want)
    assert "__builtin_trap" not in "".join(got.values())
    return "".join([got[k] for k in want])
# NOTE: combined_off.c and combined_enf.c order the vec007A bank4 tail
# differently (off: B563 then AF45; enf: B563 then B64D), so the vec-case
# anchor is per-file below.
OFFB=bodies(open(LIFT+"/manual_B785/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_B785/out_enf.c").read())
D1B="static void b4_entry_B785(void);"+NL
CASE1="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL
D74="static void b4_entry_B747(void);"+NL+"static void b4_entry_B7BD(void);"
D7N="static void b4_entry_B747(void);"+NL+D1B+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
C56O="case 0xB563: if (swbank == prg[4]) b4_entry_B563(); else __builtin_trap(); break;"+NL+"case 0xAF45:"
C5NO="case 0xB563: if (swbank == prg[4]) b4_entry_B563(); else __builtin_trap(); break;"+NL+CASE1+"case 0xAF45:"
C56E="case 0xB563: if (swbank == prg[4]) b4_entry_B563(); else __builtin_trap(); break;"+NL+"case 0xB64D:"
C5NE="case 0xB563: if (swbank == prg[4]) b4_entry_B563(); else __builtin_trap(); break;"+NL+CASE1+"case 0xB64D:"
for nm,BB in (("bank4_off.c",OFFB),("bank4_enf.c",ENFB)):
    rep(GEN+"/"+nm, D74, D7N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
D7T="static void b4_entry_B747(void);"+NL+"static void b4_L960E(void);"
D7TN="static void b4_entry_B747(void);"+NL+D1B+"static void b4_L960E(void);"
for nm,BB,CO,CN in (("combined_off.c",OFFB,C56O,C5NO),("combined_enf.c",ENFB,C56E,C5NE)):
    rep(GEN+"/"+nm, D74, D7N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CO, CN)
    rep(GEN+"/"+nm, D7T, D7TN)
rep(LIFT+"/ADDRMAP.txt", "B77D 4 LB77D"+NL+"B787 6 entry_B787", "B77D 4 LB77D"+NL+"B785 4 entry_B785"+NL+"B787 6 entry_B787")
rep(LIFT+"/PROV_ALL.txt", "entry_B747 4"+NL+"entry_B7BD 4", "entry_B747 4"+NL+"entry_B785 4"+NL+"entry_B7BD 4")
rep(LIFT+"/vec007A.txt", "B650 B65E B6A9 B6B2", "B650 B65E B6A9 B6B2 B785")
print("B785 port ok")
