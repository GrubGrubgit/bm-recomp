import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
WR="/data/data/com.termux/files/home/ai-bridge/session-homes/sess-20261116-175343-0303/wrun"
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
# bank7 new (CF10/CF13 leaf + LC0CC/LC201 JMP stubs; LC024/D324 short-circuit needs no body)
OFFB7=bodies(open(WR+"/outcf_off.c").read(), ["b7_entry_CF10","b7_entry_CF13","b7_LC0CC","b7_LC201"])
ENFB7=bodies(open(WR+"/outcf_enf.c").read(), ["b7_entry_CF10","b7_entry_CF13","b7_LC0CC","b7_LC201"])
assert "b7_entry_CF10();" in OFFB7 and "b7_LC0CC" in OFFB7
# bank4 9072 only: 90E8 promoted in snip to entry_90E8 but gen already has
# byte-identical b4_L90E8 (JMP C117 tail from the 90C2 lift); 9B95-style dedup:
# repoint both BEQ/BNE sites to pre-existing b4_L90E8, discard the dup body.
OFFB4=bodies(open(WR+"/out9072_off.c").read(), ["b4_entry_9072","b4_entry_90E8"])
ENFB4=bodies(open(WR+"/out9072_enf.c").read(), ["b4_entry_9072","b4_entry_90E8"])
for _nm,_b in (("OFFB4",OFFB4),("ENFB4",ENFB4)):
    assert _b.count("b4_entry_90E8();")==2, (_nm, _b.count("b4_entry_90E8();"))
OFFB4=OFFB4.replace("b4_entry_9072","b4_entry_9072").replace("b4_entry_90E8();","b4_L90E8();")
ENFB4=ENFB4.replace("b4_entry_9072","b4_entry_9072").replace("b4_entry_90E8();","b4_L90E8();")
# drop the dup 90E8 body (keep only 9072), keep the 2 repointed call sites
def drop90E8(blob):
    i=blob.find("static void __attribute__((used)) b4_entry_90E8(void)")
    assert i>0
    j=blob.find(NL+"}", i)+len(NL+"}")
    return blob[:i].rstrip()+NL
OFFB4=drop90E8(OFFB4)
ENFB4=drop90E8(ENFB4)
assert "b4_entry_90E8" not in OFFB4 and "b4_entry_90E8" not in ENFB4
assert OFFB4.count("b4_L90E8();")==2 and ENFB4.count("b4_L90E8();")==2
# rewrites for bank4 body: b4_LC0CC/LC201 -> b7 (new); C01E/C0FF/C1E6/C117/D324 already b7; 8FF3/9007/8F21 stay b4
OFFB4=OFFB4.replace("b4_LC0CC","b7_LC0CC").replace("b4_LC201","b7_LC201")
ENFB4=ENFB4.replace("b4_LC0CC","b7_LC0CC").replace("b4_LC201","b7_LC201")
assert "b4_LC" not in OFFB4 and "b4_LC" not in ENFB4
# decls/cases: 9072 decl only (90E8 decl/body pre-exist as b4_L90E8); vec only observed 9072
D1B="static void b4_entry_9072(void);"+NL
CASE1="case 0x9072: if (swbank == prg[4]) b4_entry_9072(); else __builtin_trap(); break;"+NL
D3E="static void b4_entry_903E(void);"+NL+"static void b4_entry_B7BD(void);"
D3EN="static void b4_entry_903E(void);"+NL+D1B+"static void b4_entry_B7BD(void);"
D3ET="static void b4_entry_903E(void);"+NL+"static void b4_L960E(void);"
D3ETN="static void b4_entry_903E(void);"+NL+D1B+"static void b4_L960E(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
C3EO="case 0x903E: if (swbank == prg[4]) b4_entry_903E(); else __builtin_trap(); break;"+NL+"case 0xAF45:"
C3ENO="case 0x903E: if (swbank == prg[4]) b4_entry_903E(); else __builtin_trap(); break;"+NL+CASE1+"case 0xAF45:"
C3EE="case 0x903E: if (swbank == prg[4]) b4_entry_903E(); else __builtin_trap(); break;"+NL+"case 0xB64D:"
C3ENE="case 0x903E: if (swbank == prg[4]) b4_entry_903E(); else __builtin_trap(); break;"+NL+CASE1+"case 0xB64D:"
# bank4 files: decl + body (9072 only)
for nm,BB in (("bank4_off.c",OFFB4),("bank4_enf.c",ENFB4)):
    rep(GEN+"/"+nm, D3E, D3EN)
    rep(GEN+"/"+nm, B7B, BB+B7B)
# combined: decls (both decl blocks) + vec + bodies (bank7 CF 4 first so defined before use, then bank4 9072)
for nm,BB4,BB7,CO,CN in (("combined_off.c",OFFB4,OFFB7,C3EO,C3ENO),("combined_enf.c",ENFB4,ENFB7,C3EE,C3ENE)):
    rep(GEN+"/"+nm, D3E, D3EN)
    rep(GEN+"/"+nm, D3ET, D3ETN)
    rep(GEN+"/"+nm, B7B, BB7+BB4+B7B)
    rep(GEN+"/"+nm, CO, CN)
# ADDRMAP: 9072 between 903E/9060 (90E8 stays L90E8 in place); CF10/CF13 between CF0F/CF6F
rep(LIFT+"/ADDRMAP.txt", "903E 4 entry_903E"+NL+"9060 4 entry_9060", "903E 4 entry_903E"+NL+"9072 4 entry_9072"+NL+"9060 4 entry_9060")
rep(LIFT+"/ADDRMAP.txt", "CF0F 7 LCF0F"+NL+"CF6F 7 LCF6F", "CF0F 7 LCF0F"+NL+"CF10 7 entry_CF10"+NL+"CF13 7 entry_CF13"+NL+"CF6F 7 LCF6F")
rep(LIFT+"/PROV_ALL.txt", "entry_903E 4"+NL+"entry_9060 4", "entry_903E 4"+NL+"entry_9072 4"+NL+"entry_9060 4")
rep(LIFT+"/PROV_ALL.txt", "LCF0F 7"+NL+"LCF6F 7", "LCF0F 7"+NL+"entry_CF10 7"+NL+"entry_CF13 7"+NL+"LCF6F 7")
rep(LIFT+"/vec007A.txt", "B785 B78F B792 9014 903E"+NL, "B785 B78F B792 9014 903E 9072"+NL)
print("9072 port ok")
