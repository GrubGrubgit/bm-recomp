#include "runtime.h"
static void b4_entry_BE54(void);
static void b4_entry_BE57(void);
static void b4_entry_B2B4(void);
static void __attribute__((used)) b4_entry_BE54(void) {
nmi_pc = 0xBE54;
nmi_poll("b4_entry_BE54");
nmi_poll("b4_entry_BE54");
cycles += 3;
goto b4_LBE60;
nmi_pc = 0xBE57;
nmi_poll("b4_entry_BE54");
}
static void __attribute__((used)) b4_entry_BE57(void) {
nmi_pc = 0xBE57;
nmi_poll("b4_entry_BE57");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBE59;
nmi_poll("b4_entry_BE57");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xBE5B;
nmi_poll("b4_entry_BE57");
A = 0x0E; setZN(A);
cycles += 2;
nmi_pc = 0xBE5D;
nmi_poll("b4_entry_BE57");
nmi_poll("b4_entry_BE57");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_pc = 0xBE60;
nmi_poll("b4_entry_BE57");
nmi_pc = 0xBE60;
nmi_poll("b4_entry_BE57");
b4_LBE60:;
cycles += 6;
return;
nmi_pc = 0xBE61;
nmi_poll("b4_entry_BE57");
}
static void b4_entry_B2B4(void) { __builtin_trap(); }
