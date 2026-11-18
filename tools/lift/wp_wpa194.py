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
    want=["b6_entry_A164","b6_LA190","b6_entry_A191","b6_entry_A194","b6_LA1AC","b6_entry_A1AD","b6_entry_A1B0"]
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
OFFB=bodies(open(LIFT+"/manual_A194/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_A194/out_enf.c").read())
D7="static void b6_entry_A164(void);"+NL+"static void b6_LA190(void);"+NL+"static void b6_entry_A191(void);"+NL+"static void b6_entry_A194(void);"+NL+"static void b6_LA1AC(void);"+NL+"static void b6_entry_A1AD(void);"+NL+"static void b6_entry_A1B0(void);"+NL
D3="static void b6_entry_A194(void);"+NL+"static void b6_entry_A1AD(void);"+NL+"static void b6_entry_A1B0(void);"+NL
CASES="case 0xA194: if (swbank == prg[6]) b6_entry_A194(); else __builtin_trap(); break;"+NL+"case 0xA1AD: if (swbank == prg[6]) b6_entry_A1AD(); else __builtin_trap(); break;"+NL+"case 0xA1B0: if (swbank == prg[6]) b6_entry_A1B0(); else __builtin_trap(); break;"+NL
D13="static void b6_entry_A13D(void);"+NL+"static void b6_entry_A1CC(void);"
D9N="static void b6_entry_A13D(void);"+NL+D7+"static void b6_entry_A1CC(void);"
DA5="static void b6_entry_A125(void);"+NL+"static void b6_entry_A1F4(void);"
DA3="static void b6_entry_A125(void);"+NL+D3+"static void b6_entry_A1F4(void);"
BCC="static void __attribute__((used)) b6_entry_A1CC(void) {"
CAA="case 0xA125: b6_entry_A125(); break;"+NL+"case 0xA1F4: b6_entry_A1F4(); break;"
CAB="case 0xA125: b6_entry_A125(); break;"+NL+CASES+"case 0xA1F4: b6_entry_A1F4(); break;"
for nm,BB in (("bank6_off.c",OFFB),("bank6_enf.c",ENFB)):
    rep(GEN+"/"+nm, D13, D9N)
    rep(GEN+"/"+nm, BCC, BB+BCC)
for nm in ("bank7t_off.c","bank7t_enf.c"):
    rep(GEN+"/"+nm, DA5, DA3)
    rep(GEN+"/"+nm, CAA, CAB)
for nm,BB in (("combined_off.c",OFFB),("combined_enf.c",ENFB)):
    rep(GEN+"/"+nm, D13, D9N)
    rep(GEN+"/"+nm, DA5, DA3)
    rep(GEN+"/"+nm, BCC, BB+BCC)
    rep(GEN+"/"+nm, CAA, CAB)
rep(LIFT+"/ADDRMAP.txt", "A15F 6 LA15F"+NL+"A188 6 LA188", "A15F 6 LA15F"+NL+"A164 6 entry_A164"+NL+"A188 6 LA188")
rep(LIFT+"/ADDRMAP.txt", "A188 6 LA188"+NL+"A1CC 6 entry_A1CC", "A188 6 LA188"+NL+"A190 6 LA190"+NL+"A191 6 entry_A191"+NL+"A194 6 entry_A194"+NL+"A1AC 6 LA1AC"+NL+"A1AD 6 entry_A1AD"+NL+"A1B0 6 entry_A1B0"+NL+"A1BF 6 LA1BF"+NL+"A1CC 6 entry_A1CC")
rep(LIFT+"/PROV_ALL.txt", "entry_A13D 6"+NL+"entry_A1CC 6", "entry_A13D 6"+NL+"entry_A164 6"+NL+"entry_A191 6"+NL+"entry_A194 6"+NL+"entry_A1AD 6"+NL+"entry_A1B0 6"+NL+"entry_A1CC 6")
rep(LIFT+"/PROV_ALL.txt", "LA188 6"+NL+"LA1EB 6", "LA188 6"+NL+"LA190 6"+NL+"LA1AC 6"+NL+"LA1BF 6"+NL+"LA1EB 6")
rep(LIFT+"/vec007A.txt", "A125 A1F4", "A125 A194 A1AD A1B0 A1F4")
print("A194 port ok")
