#include "runtime.h"
static void b4_entry_B08B(void);
static void b4_entry_B08E(void);
static void b4_entry_B09E(void);
static void b7_entry_C114(void);
static void b7_entry_E0A5(void);
static void __attribute__((used)) b4_entry_B08B(void) {
nmi_pc = 0xB08B;
nmi_poll("b4_entry_B08B");
nmi_poll("b4_entry_B08B");
cycles += 3;
b4_entry_B09E(); return;
nmi_pc = 0xB08E;
nmi_poll("b4_entry_B08B");
}
static void __attribute__((used)) b4_entry_B08E(void) {
nmi_pc = 0xB08E;
nmi_poll("b4_entry_B08E");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB090;
nmi_poll("b4_entry_B08E");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xB092;
nmi_poll("b4_entry_B08E");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB094;
nmi_poll("b4_entry_B08E");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xB096;
nmi_poll("b4_entry_B08E");
nmi_poll("b4_entry_B08E");
cycles += 9; /* SLOT-JSR: JSR6+JMP3 */
S = (uint8_t)(S - 2);
b7_entry_E0A5();
S = (uint8_t)(S + 2);
nmi_pc = 0xB099;
nmi_poll("b4_entry_B08E");
nmi_pc = 0xB099;
nmi_poll("b4_entry_B08E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B09E(); return; }
nmi_pc = 0xB09B;
nmi_poll("b4_entry_B08E");
nmi_poll("b4_entry_B08E");
cycles += 3;
b7_entry_C114(); return;
nmi_pc = 0xB09E;
nmi_poll("b4_entry_B08E");
}
static void b4_entry_B09E(void) { __builtin_trap(); }
