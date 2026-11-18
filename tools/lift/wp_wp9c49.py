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
    want=["b6_entry_9C26","b6_entry_9C2D","b6_entry_9C34","b6_entry_9C3B","b6_entry_9C42","b6_entry_9C49","b6_entry_9C50","b6_entry_9C57"]
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
    assert "entry_9C5B" not in "".join(got.values()).replace("b6_entry_9C5B();", "b6_L9C5B();")
    blob="".join([got[k] for k in want])
    return "".join([got[k] for k in want]).replace("b6_entry_9C5B();", "b6_L9C5B();")
OFFB=bodies(open(LIFT+"/manual_9C49/out_off.c").read())
ENFB=bodies(open(LIFT+"/manual_9C49/out_enf.c").read())
assert OFFB==ENFB
DECLS="static void b6_entry_9C26(void);"+NL+"static void b6_entry_9C2D(void);"+NL+"static void b6_entry_9C34(void);"+NL+"static void b6_entry_9C3B(void);"+NL+"static void b6_entry_9C42(void);"+NL+"static void b6_entry_9C49(void);"+NL+"static void b6_entry_9C50(void);"+NL+"static void b6_entry_9C57(void);"+NL
CASES="case 0x9C26: if (swbank == prg[6]) b6_entry_9C26(); else __builtin_trap(); break;"+NL+"case 0x9C2D: if (swbank == prg[6]) b6_entry_9C2D(); else __builtin_trap(); break;"+NL+"case 0x9C34: if (swbank == prg[6]) b6_entry_9C34(); else __builtin_trap(); break;"+NL+"case 0x9C3B: if (swbank == prg[6]) b6_entry_9C3B(); else __builtin_trap(); break;"+NL+"case 0x9C42: if (swbank == prg[6]) b6_entry_9C42(); else __builtin_trap(); break;"+NL+"case 0x9C49: if (swbank == prg[6]) b6_entry_9C49(); else __builtin_trap(); break;"+NL+"case 0x9C50: if (swbank == prg[6]) b6_entry_9C50(); else __builtin_trap(); break;"+NL+"case 0x9C57: if (swbank == prg[6]) b6_entry_9C57(); else __builtin_trap(); break;"+NL
D19="static void b6_entry_9C1F(void);"+NL+"static void b6_entry_9C68(void);"
D9N="static void b6_entry_9C1F(void);"+NL+DECLS+"static void b6_entry_9C68(void);"
B68="static void __attribute__((used)) b6_entry_9C68(void) {"
CAA="case 0x9C1F: b6_entry_9C1F(); break;"+NL+"case 0x9C68: b6_entry_9C68(); break;"
CAB="case 0x9C1F: b6_entry_9C1F(); break;"+NL+CASES+"case 0x9C68: b6_entry_9C68(); break;"
for nm in ("bank6_off.c","bank6_enf.c"):
    rep(GEN+"/"+nm, D19, D9N)
    rep(GEN+"/"+nm, B68, OFFB+B68)
for nm in ("bank7t_off.c","bank7t_enf.c"):
    rep(GEN+"/"+nm, D19, D9N)
    rep(GEN+"/"+nm, CAA, CAB)
for nm in ("combined_off.c","combined_enf.c"):
    rep(GEN+"/"+nm, D19, D9N, 2)
    rep(GEN+"/"+nm, B68, OFFB+B68)
    rep(GEN+"/"+nm, CAA, CAB)
rep(LIFT+"/ADDRMAP.txt", "9C1F 6 entry_9C1F"+NL+"9C23 4 L9C23", "9C1F 6 entry_9C1F"+NL+"9C26 6 entry_9C26"+NL+"9C2D 6 entry_9C2D"+NL+"9C34 6 entry_9C34"+NL+"9C3B 6 entry_9C3B"+NL+"9C42 6 entry_9C42"+NL+"9C49 6 entry_9C49"+NL+"9C50 6 entry_9C50"+NL+"9C57 6 entry_9C57"+NL+"9C23 4 L9C23")
rep(LIFT+"/PROV_ALL.txt", "entry_9C1F 6"+NL+"entry_9C68 6", "entry_9C1F 6"+NL+"entry_9C26 6"+NL+"entry_9C2D 6"+NL+"entry_9C34 6"+NL+"entry_9C3B 6"+NL+"entry_9C42 6"+NL+"entry_9C49 6"+NL+"entry_9C50 6"+NL+"entry_9C57 6"+NL+"entry_9C68 6")
rep(LIFT+"/vec007A.txt", "9C1F 9C68", "9C1F 9C26 9C2D 9C34 9C3B 9C42 9C49 9C50 9C57 9C68")
print("9C49 port ok")
