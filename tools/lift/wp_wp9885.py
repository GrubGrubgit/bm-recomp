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
    want=["b6_entry_9885"]
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
OFFB=bodies(open(LIFT+"/manual_9885/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_9885/out_enf.c").read())
D1B="static void b6_entry_9885(void);"+NL
CASE1="case 0x9885: if (swbank == prg[6]) b6_entry_9885(); else __builtin_trap(); break;"+NL
D96="static void b6_entry_983E(void);"+NL+"static void b6_entry_9916(void);"
D9N="static void b6_entry_983E(void);"+NL+D1B+"static void b6_entry_9916(void);"
D78="static void b6_entry_978B(void);"+NL+"static void b6_entry_9B98(void);"
D7N="static void b6_entry_978B(void);"+NL+D1B+"static void b6_entry_9B98(void);"
B91="static void __attribute__((used)) b6_entry_9916(void) {"
C78="case 0x978B: b6_entry_978B(); break;"+NL+"case 0x9B98: b6_entry_9B98(); break;"
C7N="case 0x978B: b6_entry_978B(); break;"+NL+CASE1+"case 0x9B98: b6_entry_9B98(); break;"
for nm,BB in (("bank6_off.c",OFFB),("bank6_enf.c",ENFB)):
    rep(GEN+"/"+nm, D96, D9N)
    rep(GEN+"/"+nm, B91, BB+B91)
for nm in ("bank7t_off.c","bank7t_enf.c"):
    rep(GEN+"/"+nm, D78, D7N)
    rep(GEN+"/"+nm, C78, C7N)
for nm,BB in (("combined_off.c",OFFB),("combined_enf.c",ENFB)):
    rep(GEN+"/"+nm, D96, D9N)
    rep(GEN+"/"+nm, D78, D7N)
    rep(GEN+"/"+nm, B91, BB+B91)
    rep(GEN+"/"+nm, C78, C7N)
rep(LIFT+"/ADDRMAP.txt", "9881 6 L9881"+NL+"9884 4 L9884", "9881 6 L9881"+NL+"9885 6 entry_9885"+NL+"9884 4 L9884")
rep(LIFT+"/PROV_ALL.txt", "entry_983E 6"+NL+"entry_9916 6", "entry_983E 6"+NL+"entry_9885 6"+NL+"entry_9916 6")
rep(LIFT+"/vec007A.txt", "978B 9B98", "978B 9885 9B98")
print("9885 port ok")
