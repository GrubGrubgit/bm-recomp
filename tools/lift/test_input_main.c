#include <stdio.h>
#include "build/lifted_input.c"
#include "build/lifted_misc.c"
#include "build/lifted_jsr.c"
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
    memset(stk, 0, sizeof stk);
    A = 3; X = 0; Y = 5; S = 0xFD; P = 0x24;
    ram[0x7A] = 0x50; ram[0x7B] = 0x02; ram[0x255] = 0xAB;
    b7_entry_E974();
    check(A == 0x00 && P == 0x27 && Y == 6 && S == 0xFD && ram[0] == 0xAB && ram[0x7B] == 0x02, "E974 jsr-loop counts 3 to 0");
    if (failures) { printf("FAILURES=%d\n", failures); return 1; }
    printf("ALL LIFT TESTS PASS\n");
    return 0;
}
