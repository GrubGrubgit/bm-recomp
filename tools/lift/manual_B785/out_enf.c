#include "runtime.h"
static void b4_entry_B785(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_B785(void) {
nmi_poll("b4_entry_B785");
cycles += 2;
A = 0x0B; setZN(A);
nmi_poll("b4_entry_B785");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_B2B4(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B785", "b4_entry_B2B4", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B785");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x50, A);
cycles += 6;
return;
}
static void b4_x(void) { __builtin_trap(); }
