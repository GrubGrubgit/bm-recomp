#include "runtime.h"
static void b6_entry_B497(void);
static void __attribute__((used)) b6_entry_B497(void) {
nmi_pc = 0xB497;
nmi_poll("b6_entry_B497");
A = 0x17; setZN(A);
cycles += 2;
nmi_pc = 0xB499;
nmi_poll("b6_entry_B497");
nmi_poll("b6_entry_B497");
cycles += 6;
stk[S] = 0xB4; S = (uint8_t)(S - 1);
stk[S] = 0x9B; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b6_entry_A2E9(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B497", "b6_entry_A2E9", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB49C;
nmi_poll("b6_entry_B497");
nmi_pc = 0xB49C;
nmi_poll("b6_entry_B497");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xB49E;
nmi_poll("b6_entry_B497");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xB4A0;
nmi_poll("b6_entry_B497");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0xB4A2;
nmi_poll("b6_entry_B497");
cycles += 6;
return;
nmi_pc = 0xB4A3;
nmi_poll("b6_entry_B497");
}
