#include <stdio.h>
#include <string.h>
#include "build/lifted_input.c"
#include "build/lifted_misc.c"
#include "build/lifted_jsr.c"
#include "build/lifted_trans.c"
#include "build/lifted_arith.c"
#include "build/lifted_g3.c"
#include "build/lifted_b6.c"
#include "build/lifted_b5.c"
static int failures = 0;
static void check(int ok, const char *msg) {
    printf("%s %s\n", ok ? "PASS" : "FAIL", msg);
    if (!ok) failures++;
}
static void run_case(const char *name, uint8_t pad, uint8_t want) {
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0xFB] = 0; ram[0xF7] = 0; ram[0xF8] = 0;
    pad_bits = pad; pad_pos1 = 0; pad_pos2 = 0; strobe = 0;
    b7_LE914();
    int ok = (ram[0xF7] == want && ram[0xF8] == want);
    if (!ok) failures++;
    printf("%-6s pad=%02X F7=%02X F8=%02X want=%02X %s\n",
        name, pad, ram[0xF7], ram[0xF8], want, ok ? "OK" : "FAIL");
}
int main(void) {
    run_case("none", 0x00, 0x00);
    run_case("A", 0x01, 0x80);
    run_case("B", 0x02, 0x40);
    run_case("Sel", 0x04, 0x20);
    run_case("Start", 0x08, 0x10);
    run_case("Up", 0x10, 0x08);
    run_case("Down", 0x20, 0x04);
    run_case("Left", 0x40, 0x02);
    run_case("Right", 0x80, 0x01);
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0xFF] = 0xFF;
    b7_entry_E895();
    check(ram[0xFF] == 0xFB && A == 0xFB && P == 0xA4, "E895 clears bit2, N set");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0xFF] = 0x00;
    b7_entry_E89F();
    check(ram[0xFF] == 0x04 && A == 0x04 && P == 0x24, "E89F sets bit2, no flags");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 5; S = 0xFD; P = 0x24;
    ram[0x7A] = 0x50; ram[0x7B] = 0x02; ram[0x255] = 0xAB;
    b7_entry_E996();
    check(A == 0xAB && Y == 6 && ram[0] == 0xAB && ram[0x7B] == 0x02, "E996 ind-y taken, no hi-inc");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0xFF; S = 0xFD; P = 0x24;
    ram[0x7A] = 0x50; ram[0x7B] = 0x02; ram[0x34F] = 0x77;
    b7_entry_E996();
    check(A == 0x77 && Y == 0 && ram[0] == 0x77 && ram[0x7B] == 0x03, "E996 ind-y wrap, hi-inc");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 3; X = 0; Y = 5; S = 0xFD; P = 0x24;
    ram[0x7A] = 0x50; ram[0x7B] = 0x02; ram[0x255] = 0xAB;
    b7_entry_E974();
    check(A == 0x00 && P == 0x27 && Y == 6 && S == 0xFD && ram[0] == 0xAB && ram[0x7B] == 0x02, "E974 jsr-loop counts 3 to 0");
    {
        char p[300];
        for (int i = 0; i < 8; i++) {
            snprintf(p, sizeof p, "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/banks/prg%d.bin", i);
            FILE *f = fopen(p, "rb");
            if (!f || fread(prg[i], 1, 16384, f) != 16384) { printf("FAIL rom load %d\n", i); return 1; }
            fclose(f);
        }
        swbank = prg[6];
    }
    check(prg[7][0xA39] == 0x59, "rom table sane");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0x10; S = 0xFD; P = 0x24;
    ram[0] = 0x50; ram[1] = 0x02; ram[2] = 0x60; ram[3] = 0x02; ram[4] = 0x70; ram[5] = 0x02;
    ram[0x261] = 0xC3; ram[0x271] = 0xD4; ram[0x281] = 0xE5;
    b7_LC7C7();
    check(A == 0xE5 && Y == 0x11 && P == 0xA4 && ram[0x14] == 0xC3 && ram[0x49] == 0xD4 && ram[0x4B] == 0xE5, "LC7C7 tya/eor/tay triple-indirect");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x14] = 0x07;
    b7_entry_CA14();
    check(A == 0x80 && X == 0x0E && P == 0xA4 && ram[0x49] == 0x59 && ram[0x4B] == 0x15 && ram[0x48] == 0x80 && ram[0x4A] == 0x80, "CA14 asl/tax rom-table pair");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x4C] = 0x03; ram[0x4D] = 0x05;
    b7_entry_D136();
    check(A == 0xF5 && ram[0x4C] == 0xF3 && ram[0x4D] == 0xF5, "D136 clear-bits path");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x4C] = 0x83; ram[0x4D] = 0x05;
    b7_entry_D136();
    check(A == 0xF5 && P == 0xA4 && ram[0x4C] == 0x93 && ram[0x4D] == 0xF5, "D136 set-bit path, N kept");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x403] = 0x10; ram[0x405] = 0x02; ram[0x49] = 0x04; ram[0x4B] = 0x01;
    b7_entry_D151();
    check(A == 0x01 && X == 0x01 && P == 0x24 && ram[0] == 0x0C && ram[1] == 0x01 && ram[2] == 0x00, "D151 fallthrough, rol chain, table");
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0] = 0x10; ram[1] = 0x02; ram[2] = 0x04; ram[3] = 0x01;
    b7_entry_D02D();
    check(A == 0xC0 && X == 0x05 && P == 0xA4 && ram[0] == 0x04 && ram[1] == 0x0C && ram[4] == 0x04 && ram[5] == 0x00 && ram[0x4C] == 0xC0 && ram[0x4D] == 0xFB, "D02D full divide path");
    for (int i = 0; i < 16; i++) ram[0x46+i] = (uint8_t)((i+1)*0x11);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    b7_entry_D7C0();
    check(A == 0xEE && X == 13 && Y == 0x0E && P == 0x27 && ram[0x401] == 0x22 && ram[0x40D] == 0xEE, "D7C0 copy loop, cpy exit");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    b7_entry_D7CF();
    check(A == 0xFF && X == 0 && P == 0xA4, "D7CF zero slot");
    memset(ram, 0, sizeof ram);
    A = 0; X = 5; Y = 0; S = 0xFD; P = 0x24;
    ram[0] = 7; ram[0x405] = 0xAA; ram[0x413] = 0;
    b7_entry_D7CF();
    check(A == 0xFF && X == 0x13 && P == 0xA4, "D7CF cpx loop, self-jmp");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x57] = 5;
    b7_entry_D804();
    check(A == 0 && X == 0 && Y == 5 && P == 0x26 && ram[0x46] == 0 && ram[0x4F] == 0, "D804 bcc-taken via entry call");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x57] = 10; ram[0xC6] = 0; ram[0x102] = 0x77;
    b7_entry_D804();
    check(A == 0 && X == 1 && Y == 10 && P == 0x27 && ram[0x46] == 0 && ram[0x4F] == 0 && ram[0x10B] == 0x77 && ram[0x102] == 0xFF && ram[0xC6] == 1, "D804 fallthrough, sta zp,y");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0xCD] = 5; ram[0xCE] = 0x80; ram[0xCF] = 0x02; ram[0xD0] = 0xBB; ram[0xD1] = 0xAA;
    b7_LE2AB();
    check(A == 0xBB && Y == 7 && P == 0x24 && ram[0xCD] == 7 && ram[0x285] == 0xAA && ram[0x286] == 0xBB, "LE2AB ind-sta pair, no wrap");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0xCD] = 0xFE; ram[0xCE] = 0x80; ram[0xCF] = 0x02; ram[0xD0] = 0xBB; ram[0xD1] = 0xAA;
    b7_LE2AB();
    check(A == 0xFF && Y == 0 && P == 0xA4 && ram[0xCD] == 0 && ram[0x37E] == 0xAA && ram[0x37F] == 0xBB && ram[0x6F3] == 0xFF, "LE2AB y-wrap path, sty");
    memset(ram, 0, sizeof ram);
    A = 0; X = 9; Y = 0; S = 0xFD; P = 0x24;
    b6_entry_B600();
    check(X == 0, "B600 dex self-loop counts 3 to 0");
    memset(ram, 0, sizeof ram);
    A = 0; X = 7; Y = 0; S = 0xFD; P = 0x24;
    ram[0x10] = 1;
    b6_entry_B610();
    check(X == 0, "B610 branch-to-entry calls B600");
    memset(ram, 0, sizeof ram);
    A = 0; X = 3; Y = 0; S = 0xFD; P = 0x24;
    ram[0x78A] = 0x01;
    b5_L839A();
    check(A == 0x21 && ram[0x78A] == 0x21, "839A ora bit5 indexed");
    memset(ram, 0, sizeof ram);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x7F5] = 0xFF;
    b5_LBEA6();
    check(A == 0xFE && ram[0x7F5] == 0xFE, "BEA6 and-clear bit0");
    if (failures) { printf("FAILURES=%d\n", failures); return 1; }
    printf("ALL LIFT TESTS PASS\n");
    return 0;
}
