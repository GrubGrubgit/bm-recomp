import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_AC63"
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
WANT=["b6_entry_AC63"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
D1="static void b6_entry_AC3F(void);"+NL+"static void b6_entry_AC66(void);"+NL
D1N="static void b6_entry_AC3F(void);"+NL+"static void b6_entry_AC63(void);"+NL+"static void b6_entry_AC66(void);"+NL
D2="static void b6_entry_AC62(void);"+NL+"static void b6_entry_AC66(void);"+NL
D2N="static void b6_entry_AC62(void);"+NL+"static void b6_entry_AC63(void);"+NL+"static void b6_entry_AC66(void);"+NL
BB="static void __attribute__((used)) b6_entry_AC66(void) {"
CB="case 0xAC66: b6_entry_AC66(); break;"+NL
CN=CB+"case 0xAC63: if (swbank == prg[6]) b6_entry_AC63(); else __builtin_trap(); break;"+NL
for nm,BB2 in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, D1, D1N)
    rep(GEN+"/"+nm, D2, D2N)
    rep(GEN+"/"+nm, BB, BB2+BB)
    rep(GEN+"/"+nm, CB, CN)
rep(LIFT+"/ADDRMAP.txt", "AC62 6 entry_AC62"+NL+"AC66 6 entry_AC66", "AC62 6 entry_AC62"+NL+"AC63 6 entry_AC63"+NL+"AC66 6 entry_AC66")
rep(LIFT+"/PROV_ALL.txt", "entry_AC62 6"+NL+"entry_AC66 6", "entry_AC62 6"+NL+"entry_AC63 6"+NL+"entry_AC66 6")
rep(LIFT+"/vec007A.txt", " B843 B846"+NL, " B843 B846 AC63"+NL)
print("AC63 port ok")
