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
    want=["b4_entry_B792"]
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
    assert "b4_entry_B7BD();" in blob
    assert "b4_LC04E();" in blob and "b4_LC045();" in blob and "b4_LC02D();" in blob
    blob=blob.replace("b4_LC04E", "b7_LC04E").replace("b4_LC045", "b7_LC045").replace("b4_LC02D", "b7_LC02D")
    assert "b4_LC" not in blob
    return blob
# NOTE: combined_off.c and combined_enf.c order the vec007A bank4 tail
# differently (off: B785 then AF45; enf: B785 then B64D), so the vec-case
# anchor is per-file below (same pattern as wp_wpb785.py).
OFFB=bodies(open(LIFT+"/manual_B792/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_B792/out_enf.c").read())
D1B="static void b4_entry_B792(void);"+NL
CASE1="case 0xB792: if (swbank == prg[4]) b4_entry_B792(); else __builtin_trap(); break;"+NL
D85="static void b4_entry_B785(void);"+NL+"static void b4_entry_B7BD(void);"
D8N="static void b4_entry_B785(void);"+NL+D1B+"static void b4_entry_B7BD(void);"
D7T="static void b4_entry_B785(void);"+NL+"static void b4_L960E(void);"
D7TN="static void b4_entry_B785(void);"+NL+D1B+"static void b4_L960E(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
C85O="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+"case 0xAF45:"
C85NO="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+CASE1+"case 0xAF45:"
C85E="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+"case 0xB64D:"
C85NE="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+CASE1+"case 0xB64D:"
for nm,BB in (("bank4_off.c",OFFB),("bank4_enf.c",ENFB)):
    rep(GEN+"/"+nm, D85, D8N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
for nm,BB,CO,CN in (("combined_off.c",OFFB,C85O,C85NO),("combined_enf.c",ENFB,C85E,C85NE)):
    rep(GEN+"/"+nm, D85, D8N)
    rep(GEN+"/"+nm, D7T, D7TN)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CO, CN)
rep(LIFT+"/ADDRMAP.txt", "B785 4 entry_B785"+NL+"B787 6 entry_B787", "B785 4 entry_B785"+NL+"B792 4 entry_B792"+NL+"B787 6 entry_B787")
rep(LIFT+"/PROV_ALL.txt", "entry_B785 4"+NL+"entry_B7BD 4", "entry_B785 4"+NL+"entry_B792 4"+NL+"entry_B7BD 4")
rep(LIFT+"/vec007A.txt", "B6A9 B6B2 B785", "B6A9 B6B2 B785 B792")
print("B792 port ok")
