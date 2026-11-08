#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "build/lifted_vec.c"
#include "build/lifted_xbank.c"
#include "build/lifted_ramcall.c"
static int failures = 0;
static void check(int ok, const char *msg) {
    fputs(ok ? "PASS " : "FAIL ", stdout);
    puts(msg);
    if (!ok) failures++;
}
static int traps_on(uint8_t lo, uint8_t hi) {
    ram[0x7A] = lo; ram[0x7B] = hi;
    fflush(stdout);
    pid_t pid = fork();
    if (pid == 0) { b7_vec_007A(); _exit(0); }
    int st = 0;
    waitpid(pid, &st, 0);
    if (WIFEXITED(st)) return WEXITSTATUS(st) != 0;
    return 1;
}
static int call_traps(void (*fn)(void)) {
    fflush(stdout);
    pid_t pid = fork();
    if (pid == 0) { fn(); _exit(0); }
    int st = 0;
    waitpid(pid, &st, 0);
    if (WIFEXITED(st)) return WEXITSTATUS(st) != 0;
    return 1;
}
int main(void) {
    memset(ram, 0, sizeof ram);
    memset(ram + 0x100, 0, 0x100);
    A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
    ram[0x10] = 0;
    ram[0x7A] = 0x00; ram[0x7B] = 0xC9;
    b7_vec_007A();
    check(ram[0x10] == 1, "vec C900 dispatches to same-bank probe");
    check(traps_on(0xFF, 0xFF), "vec FFFF hits default trap");
    check(traps_on(0x27, 0x81), "vec 8127 reaches listed b6 stub trap");
    check(traps_on(0xF1, 0x8A), "vec 8AF1 reaches listed b4 stub trap");
    check(call_traps(b7_entry_XBPB), "xbank LBFE8 stub traps");
    swbank = prg[0]; mmc_shift = 0; mmc_count = 0;
    WR(0xE000, 0x01); WR(0xE000, 0x00); WR(0xE000, 0x01);
    WR(0xE000, 0x00); WR(0xE000, 0x00);
    check(swbank == prg[5], "mmc 5-write selects prg bank 5");
    WR(0xA000, 0x01); WR(0xA000, 0x01); WR(0xA000, 0x01);
    WR(0xA000, 0x01); WR(0xA000, 0x01);
    check(swbank == prg[5], "mmc chr-reg writes leave prg bank alone");
    WR(0x8000, 0x80);
    check(swbank == prg[0] && mmc_count == 0, "mmc reset restores bank 0");
    check(call_traps(b7_LC3AA), "ramcall LC3AA traps at first stub");
    if (failures) {
        char b[64];
        sprintf(b, "FAILURES=%d", failures);
        puts(b);
        return 1;
    }
    puts("ALL VEC TESTS PASS");
    return 0;
}
