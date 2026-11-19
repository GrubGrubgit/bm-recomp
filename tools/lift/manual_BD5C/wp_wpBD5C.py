import os
BASE="/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT=BASE+"/recomp/tools/lift"
GEN=BASE+"/recomp/gen"
M=LIFT+"/manual_BD5C"
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
WANT=["b4_entry_BD5C","b4_entry_BD5F","b4_entry_BD69","b4_entry_BD6C"]
OFF=bodies(open(M+"/out_off.c").read(), WANT)
ENF=bodies(open(M+"/out_enf.c").read(), WANT)
# BD5C is JMP LBD68 where LBD68 is RTS in BD5F's region: lift emits a
# cross-function goto (illegal C). Inline: JMP3 (already counted) + RTS6.
OLD_GOTO="cycles += 3;"+NL+"goto b4_LBD68;"
assert OFF.count(OLD_GOTO)==1 and ENF.count(OLD_GOTO)==1
OFF=OFF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
ENF=ENF.replace(OLD_GOTO, "cycles += 3;"+NL+"cycles += 6;"+NL+"return;")
# LC-prefixed fixed-bank refs in a b4 snip lift as b4_LCxxxx; true home is bank7.
OFF=OFF.replace("b4_LC045","b7_LC045").replace("b4_LC04E","b7_LC04E")
ENF=ENF.replace("b4_LC045","b7_LC045").replace("b4_LC04E","b7_LC04E")
assert "b4_LC" not in OFF and "b4_LC" not in ENF
# BD6C tail: ROM falls through BD9C->BD9D (0cy); snip spells it as an
# explicit jmp so lift terminates the region. Strip the phantom JMP3 +
# dup polls (nmi_poll is idempotent; BE3E epilogue + BD9D head poll).
OLD_TAIL=( 'nmi_poll("b4_entry_BD6C");'+NL )*3 + "cycles += 3;"+NL+"b4_entry_BD9D(); return;"
assert OFF.count(OLD_TAIL)==1 and ENF.count(OLD_TAIL)==1, (OFF.count(OLD_TAIL), ENF.count(OLD_TAIL))
OFF=OFF.replace(OLD_TAIL, "b4_entry_BD9D(); return;")
ENF=ENF.replace(OLD_TAIL, "b4_entry_BD9D(); return;")
D4=( "static void b4_entry_BD5C(void);"+NL+"static void b4_entry_BD5F(void);"+NL
   + "static void b4_entry_BD69(void);"+NL+"static void b4_entry_BD6C(void);"+NL )
B1="static void b4_entry_9072(void);"+NL+"static void b4_L960E(void);"
B1N="static void b4_entry_9072(void);"+NL+D4+"static void b4_L960E(void);"
B2="static void b4_entry_9072(void);"+NL+"static void b4_entry_B7BD(void);"
B2N="static void b4_entry_9072(void);"+NL+D4+"static void b4_entry_B7BD(void);"
B7B="static void __attribute__((used)) b4_entry_B7BD(void) {"
C9072="case 0x9072: if (swbank == prg[4]) b4_entry_9072(); else __builtin_trap(); break;"+NL
CN=( C9072+"case 0xBD5C: if (swbank == prg[4]) b4_entry_BD5C(); else __builtin_trap(); break;"+NL
   + "case 0xBD5F: if (swbank == prg[4]) b4_entry_BD5F(); else __builtin_trap(); break;"+NL
   + "case 0xBD69: if (swbank == prg[4]) b4_entry_BD69(); else __builtin_trap(); break;"+NL
   + "case 0xBD6C: if (swbank == prg[4]) b4_entry_BD6C(); else __builtin_trap(); break;"+NL )
for nm,BB in (("combined_off.c",OFF),("combined_enf.c",ENF)):
    rep(GEN+"/"+nm, B1, B1N)
    rep(GEN+"/"+nm, B2, B2N)
    rep(GEN+"/"+nm, B7B, BB+B7B)
    rep(GEN+"/"+nm, C9072, CN)
rep(LIFT+"/ADDRMAP.txt",
    "BD4A 4 entry_BD4A"+NL+"BD99 0 entry_BD99",
    "BD4A 4 entry_BD4A"+NL+"BD5C 4 entry_BD5C"+NL+"BD5F 4 entry_BD5F"+NL+"BD69 4 entry_BD69"+NL+"BD6C 4 entry_BD6C"+NL+"BD99 0 entry_BD99")
rep(LIFT+"/PROV_ALL.txt",
    "entry_BD4A 4"+NL+"entry_BD9D 4",
    "entry_BD4A 4"+NL+"entry_BD5C 4"+NL+"entry_BD5F 4"+NL+"entry_BD69 4"+NL+"entry_BD6C 4"+NL+"entry_BD9D 4")
rep(LIFT+"/vec007A.txt", " 903E 9072"+NL, " 903E 9072 BD5C BD5F BD69 BD6C"+NL)
print("BD5C port ok")
