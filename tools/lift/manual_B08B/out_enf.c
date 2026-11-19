#include "runtime.h"
static void b4_entry_B08B(void);
static void b4_entry_B08E(void);
static void b4_entry_B09E(void);
static void b7_entry_C114(void);
static void b7_entry_E0A5(void);
static void __attribute__((used)) b4_entry_B08B(void) {
nmi_poll("b4_entry_B08B");
nmi_poll("b4_entry_B08B");
cycles += 3;
b4_entry_B09E(); return;
nmi_poll("b4_entry_B08B");
}
static void __attribute__((used)) b4_entry_B08E(void) {
nmi_poll("b4_entry_B08E");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B08E");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_B08E");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B08E");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_B08E");
nmi_poll("b4_entry_B08E");
cycles += 9; /* SLOT-JSR: JSR6+JMP3 */
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_E0A5(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B08E", "b7_entry_E0A5", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B08E");
nmi_poll("b4_entry_B08E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B09E(); return; }
nmi_poll("b4_entry_B08E");
nmi_poll("b4_entry_B08E");
cycles += 3;
b7_entry_C114(); return;
nmi_poll("b4_entry_B08E");
}
static void b4_entry_B09E(void) { __builtin_trap(); }
