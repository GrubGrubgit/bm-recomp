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
    want=["b6_entry_98A3","b6_entry_98A5","b6_entry_98A7","b6_entry_98AB","b6_entry_98F5"]
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
    assert "b6_entry_9916" in blob  # tail target pre-exists, kept
    assert "b6_entry_9B95();" in blob  # rewritten below to existing b6_L9B95
    assert "b6_entry_98F5();" in blob  # split-entry tail (snip L98F5->entry_98F5)
    return blob.replace("b6_entry_9B95();", "b6_L9B95();")
OFFB=bodies(open(LIFT+"/manual_98AB/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_98AB/out_enf.c").read())
DECL5=( "static void b6_entry_98A3(void);"+NL+"static void b6_entry_98A5(void);"+NL
    +"static void b6_entry_98A7(void);"+NL+"static void b6_entry_98AB(void);"+NL
    +"static void b6_entry_98F5(void);"+NL )
CASE1="case 0x98AB: if (swbank == prg[6]) b6_entry_98AB(); else __builtin_trap(); break;"+NL
D89="static void b6_entry_9885(void);"+NL+"static void b6_entry_9916(void);"
D89N="static void b6_entry_9885(void);"+NL+DECL5+"static void b6_entry_9916(void);"
D78="static void b6_entry_9885(void);"+NL+"static void b6_entry_9B98(void);"
D78N="static void b6_entry_9885(void);"+NL+"static void b6_entry_98AB(void);"+NL+"static void b6_entry_9B98(void);"
B91="static void __attribute__((used)) b6_entry_9916(void) {"
C78="case 0x9885: if (swbank == prg[6]) b6_entry_9885(); else __builtin_trap(); break;"+NL+"case 0x9B98: b6_entry_9B98(); break;"
C7N="case 0x9885: if (swbank == prg[6]) b6_entry_9885(); else __builtin_trap(); break;"+NL+CASE1+"case 0x9B98: b6_entry_9B98(); break;"
for nm,BB in (("bank6_off.c",OFFB),("bank6_enf.c",ENFB)):
    rep(GEN+"/"+nm, D89, D89N)
    rep(GEN+"/"+nm, B91, BB+B91)
for nm in ("bank7t_off.c","bank7t_enf.c"):
    rep(GEN+"/"+nm, D78, D78N)
    rep(GEN+"/"+nm, C78, C7N)
for nm,BB in (("combined_off.c",OFFB),("combined_enf.c",ENFB)):
    rep(GEN+"/"+nm, D89, D89N)
    rep(GEN+"/"+nm, D78, D78N)
    rep(GEN+"/"+nm, B91, BB+B91)
    rep(GEN+"/"+nm, C78, C7N)
rep(LIFT+"/ADDRMAP.txt", "9885 6 entry_9885"+NL+"9884 4 L9884", "9885 6 entry_9885"+NL+"98A3 6 entry_98A3"+NL+"98A5 6 entry_98A5"+NL+"98A7 6 entry_98A7"+NL+"98AB 6 entry_98AB"+NL+"98F5 6 entry_98F5"+NL+"9884 4 L9884")
rep(LIFT+"/PROV_ALL.txt", "entry_9885 6"+NL+"entry_9916 6", "entry_9885 6"+NL+"entry_98A3 6"+NL+"entry_98A5 6"+NL+"entry_98A7 6"+NL+"entry_98AB 6"+NL+"entry_98F5 6"+NL+"entry_9916 6")
rep(LIFT+"/vec007A.txt", "9885 9B98", "9885 98AB 9B98")
print("98AB port ok")
