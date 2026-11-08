#include <stdio.h>
#include "build/lifted_input.c"
static int failures = 0;
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
    if (failures) { printf("FAILURES=%d\n", failures); return 1; }
    printf("ALL LIFT TESTS PASS\n");
    return 0;
}
