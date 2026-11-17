import os
BASE = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT = BASE + "/recomp/tools/lift"
GEN = BASE + "/recomp/gen"
INC = LIFT + "/forkfix_fns.c.inc"
NL = chr(10)
def rep(path, old, new, expect=1):
    s = open(path).read()
    c = s.count(old)
    assert c == expect, "anchor count %d != %d in %s: %s" % (c, expect, path, old[:70])
    s = s.replace(old, new)
    open(path, "w").write(s)
    print("ok %s :: %s" % (os.path.basename(path), old[:50]))
forkblock = open(INC).read()
assert len(forkblock.splitlines()) >= 900, "forkblock too short"
assert "b6_LA74B" in forkblock and "b4_LB4A9" in forkblock, "forkblock content"
CASES_25 = """case 0x9398: if (swbank == prg[4]) b4_L9398(); else __builtin_trap(); break;
case 0x95CF: if (swbank == prg[4]) b4_L95CF(); else __builtin_trap(); break;
case 0x95D2: if (swbank == prg[4]) b4_L95D2(); else __builtin_trap(); break;
case 0x95D6: if (swbank == prg[4]) b4_L95D6(); else __builtin_trap(); break;
case 0x95D9: if (swbank == prg[4]) b4_L95D9(); else __builtin_trap(); break;
case 0x95DD: if (swbank == prg[4]) b4_L95DD(); else __builtin_trap(); break;
case 0x95E0: if (swbank == prg[4]) b4_L95E0(); else __builtin_trap(); break;
case 0x95E4: if (swbank == prg[4]) b4_L95E4(); else __builtin_trap(); break;
case 0x95E7: if (swbank == prg[4]) b4_L95E7(); else __builtin_trap(); break;
case 0x95EB: if (swbank == prg[4]) b4_L95EB(); else __builtin_trap(); break;
case 0x95EE: if (swbank == prg[4]) b4_L95EE(); else __builtin_trap(); break;
case 0x95F2: if (swbank == prg[4]) b4_L95F2(); else __builtin_trap(); break;
case 0x95F5: if (swbank == prg[4]) b4_L95F5(); else __builtin_trap(); break;
case 0x95F9: if (swbank == prg[4]) b4_L95F9(); else __builtin_trap(); break;
case 0x95FC: if (swbank == prg[4]) b4_L95FC(); else __builtin_trap(); break;
case 0x9600: if (swbank == prg[4]) b4_L9600(); else __builtin_trap(); break;
case 0x9603: if (swbank == prg[4]) b4_L9603(); else __builtin_trap(); break;
case 0x9607: if (swbank == prg[4]) b4_L9607(); else __builtin_trap(); break;
case 0x960A: if (swbank == prg[4]) b4_L960A(); else __builtin_trap(); break;
case 0x961B: if (swbank == prg[4]) b4_L961B(); else __builtin_trap(); break;
case 0x961E: if (swbank == prg[4]) b4_L961E(); else __builtin_trap(); break;
case 0xB446: if (swbank == prg[4]) b4_LB446(); else __builtin_trap(); break;
case 0xB449: if (swbank == prg[4]) b4_LB449(); else __builtin_trap(); break;
case 0xB44F: if (swbank == prg[4]) b4_LB44F(); else __builtin_trap(); break;
case 0xB452: if (swbank == prg[4]) b4_LB452(); else __builtin_trap(); break;"""
B70F_BODY = """static void __attribute__((used)) b6_entry_B70F(void) {
nmi_poll("b6_entry_B70F");
{ uint8_t _m = RD(0x2B20); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 4;
cycles += 2;
P = (uint8_t)(P & 0xBF);
nmi_poll("b6_entry_B70F");
cycles += 3;
b6_entry_B713(); return;
}"""
for name in ("combined_off.c", "combined_enf.c"):
    path = GEN + "/" + name
    is_off = (name == "combined_off.c")
    # P1 uw decls
    rep(path, "int uw_abort;", "int uw_abort;" + NL + "int uw_888C;" + NL + "int uw_9488;")
    # P2 big block before vec
    rep(path,
        "static void b7_L0000(void) { __builtin_trap(); }" + NL + "static void b7_vec_007A(void) {",
        "static void b7_L0000(void) { __builtin_trap(); }" + NL + forkblock + NL + "static void b7_vec_007A(void) {")
    # P3 A74B/A74E + A76A/A76D
    rep(path,
        "case 0xA74B: b4_entry_A74B(); break;" + NL + "case 0xA74E: b4_entry_A74E(); break;",
        "case 0xA74B: if (swbank == prg[6]) b6_LA74B(); else b4_entry_A74B(); break;" + NL + "case 0xA74E: if (swbank == prg[6]) b6_LA74E(); else b4_entry_A74E(); break;" + NL + "case 0xA76A: if (swbank == prg[6]) b6_LA76A(); else __builtin_trap(); break;" + NL + "case 0xA76D: if (swbank == prg[6]) b6_LA76D(); else __builtin_trap(); break;")
    # P4 8A69
    rep(path,
        "case 0x8A69: b6_entry_8A69(); break;",
        "case 0x8A69: if (swbank == prg[4]) b4_L8A69(); else b6_entry_8A69(); break;")
    # P5 938E
    rep(path,
        "case 0x938E: b6_L938E(); break;",
        "case 0x938E: if (swbank == prg[4]) b4_L938E(); else b6_L938E(); break;")
    # P6 A237 family
    rep(path,
        "case 0xA205: b6_entry_A205(); break;" + NL + "case 0xA3E5: b6_entry_A3E5(); break;",
        "case 0xA205: b6_entry_A205(); break;" + NL + "case 0xA237: if (swbank == prg[6]) b6_LA237(); else __builtin_trap(); break;" + NL + "case 0xA23A: if (swbank == prg[6]) b6_LA23A(); else __builtin_trap(); break;" + NL + "case 0xA24D: if (swbank == prg[6]) b6_LA24D(); else __builtin_trap(); break;" + NL + "case 0xA250: if (swbank == prg[6]) b6_LA250(); else __builtin_trap(); break;" + NL + "case 0xA3E5: b6_entry_A3E5(); break;")
    # P7 B70C/B70F/B719/B71C (after B6F7, before B835)
    rep(path,
        "case 0xB6F7: b6_entry_B6F7(); break;" + NL + "case 0xB835: b6_entry_B835(); break;",
        "case 0xB6F7: b6_entry_B6F7(); break;" + NL + "case 0xB70C: if (swbank == prg[4]) b4_LB70C(); else __builtin_trap(); break;" + NL + "case 0xB70F: if (swbank == prg[4]) b4_LB70F(); else b6_entry_B70F(); break;" + NL + "case 0xB719: if (swbank == prg[4]) b4_LB719(); else __builtin_trap(); break;" + NL + "case 0xB71C: if (swbank == prg[4]) b4_LB71C(); else __builtin_trap(); break;" + NL + "case 0xB835: b6_entry_B835(); break;")
    # P8 25 cases after 9395
    rep(path,
        "case 0x9395: b4_entry_9395(); break;" + NL + "case 0x96F1: b4_entry_96F1(); break;",
        "case 0x9395: b4_entry_9395(); break;" + NL + CASES_25 + NL + "case 0x96F1: b4_entry_96F1(); break;")
    # P15a B70F decl early (B6F7->B835 block)
    rep(path,
        "static void b6_entry_B6F7(void);" + NL + "static void b6_entry_B835(void);",
        "static void b6_entry_B6F7(void);" + NL + "static void b6_entry_B70F(void);" + NL + "static void b6_entry_B835(void);")
    # P15b B70F decl late (B6F7,B708 block)
    rep(path,
        "static void b6_entry_B6F7(void);" + NL + "static void b6_entry_B708(void);",
        "static void b6_entry_B6F7(void);" + NL + "static void b6_entry_B708(void);" + NL + "static void b6_entry_B70F(void);")
    # NOTE late decl puts B70F after B708 to keep diff minimal; probe has it between B6F7/B708? No, probe late has B6F7,B708,B70F,B713. Same result.
    # Fix order: move B70F before B708? Probe order is B6F7,B708,B70F,B713. Our insert gives B6F7,B708,B70F. Good.
    # P15c B70F body before B713 def
    rep(path,
        "static void __attribute__((used)) b6_entry_B713(void) {",
        B70F_BODY + NL + "static void __attribute__((used)) b6_entry_B713(void) {")
    if is_off:
        # P9/P10 uw_9488 checks (two jsr-944C sites)
        rep(path,
            "b4_entry_944C();" + NL + "S = (uint8_t)(S + 2);",
            "b4_entry_944C();" + NL + "if (uw_9488) {uw_9488=0; return;}" + NL + "S = (uint8_t)(S + 2);",
            expect=2)
        # P11 uw_9488 set
        rep(path,
            'static void __attribute__((used)) b4_entry_9488(void) {' + NL + 'nmi_poll("b4_entry_9488");' + NL + 'cycles += 2;',
            'static void __attribute__((used)) b4_entry_9488(void) {' + NL + 'nmi_poll("b4_entry_9488");' + NL + 'uw_9488 = 1;' + NL + 'cycles += 2;')
        # P12 uw_888C set
        rep(path,
            'static void __attribute__((used)) b6_L88E3(void) {' + NL + 'nmi_poll("b6_L88E3");' + NL + 'cycles += 4;',
            'static void __attribute__((used)) b6_L88E3(void) {' + NL + 'nmi_poll("b6_L88E3");' + NL + 'uw_888C = 1;' + NL + 'cycles += 4;')
        # P13 uw_888C check
        rep(path,
            "b6_entry_888C();" + NL + "S = (uint8_t)(S + 2);",
            "b6_entry_888C();" + NL + "if (uw_888C) { uw_888C = 0; return; }" + NL + "S = (uint8_t)(S + 2);")
        # P14 B047 fallthrough (plain return shape so patch_tailcalls musttail still matches)
        rep(path,
            'static void __attribute__((used)) b6_LB047(void) {' + NL + 'nmi_poll("b6_LB047");' + NL + 'cycles += 2;' + NL + 'A = 0x01; setZN(A);' + NL + 'cycles += 3;' + NL + 'WR(0x50, A);' + NL + 'cycles += 6;' + NL + 'return;' + NL + '}',
            'static void __attribute__((used)) b6_LB047(void) {' + NL + 'nmi_poll("b6_LB047");' + NL + 'cycles += 2;' + NL + 'A = 0x01; setZN(A);' + NL + 'cycles += 3;' + NL + 'WR(0x50, A);' + NL + 'b6_entry_B04B(); return;' + NL + '}')
print("fork1-4 port ok")
