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
    want=["b4_entry_B78F"]
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
    return blob
OFFB=bodies(open(LIFT+"/manual_B78F/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_B78F/out_enf.c").read())
assert OFFB==ENFB
D1B="static void b4_entry_B78F(void);"+NL
CASE1="case 0xB78F: if (swbank == prg[4]) b4_entry_B78F(); else __builtin_trap(); break;"+NL
D92="static void b4_entry_B792(void);"+NL+"static void b4_entry_B7BD(void);"
D9N="static void b4_entry_B78F(void);"+NL+"static void b4_entry_B792(void);"+NL+"static void b4_entry_B7BD(void);"
D7T="static void b4_entry_B785(void);"+NL+"static void b4_entry_B792(void);"
D7TN="static void b4_entry_B785(void);"+NL+D1B+"static void b4_entry_B792(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
CB4="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+"case 0xB792:"
CN4="case 0xB785: if (swbank == prg[4]) b4_entry_B785(); else __builtin_trap(); break;"+NL+CASE1+"case 0xB792:"
for nm,BB in (("bank4_off.c",OFFB),("bank4_enf.c",ENFB)):
    rep(GEN+"/"+nm, D92, D9N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
for nm,BB in (("combined_off.c",OFFB),("combined_enf.c",ENFB)):
    rep(GEN+"/"+nm, D92, D9N)
    rep(GEN+"/"+nm, D7T, D7TN)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, CB4, CN4)
rep(LIFT+"/ADDRMAP.txt", "B785 4 entry_B785"+NL+"B792 4 entry_B792", "B785 4 entry_B785"+NL+"B78F 4 entry_B78F"+NL+"B792 4 entry_B792")
rep(LIFT+"/PROV_ALL.txt", "entry_B785 4"+NL+"entry_B792 4", "entry_B785 4"+NL+"entry_B78F 4"+NL+"entry_B792 4")
rep(LIFT+"/vec007A.txt", "B785 B792", "B785 B78F B792")
print("B78F port ok")
