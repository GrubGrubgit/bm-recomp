#include "runtime.h"
static void b6_entry_B57B(void);
static void __attribute__((used)) b6_entry_B57B(void) {
nmi_pc = 0xB57B;
nmi_poll("b6_entry_B57B");
A = 0x18; setZN(A);
cycles += 2;
nmi_pc = 0xB57D;
nmi_poll("b6_entry_B57B");
nmi_poll("b6_entry_B57B");
cycles += 6;
stk[S] = 0xB5; S = (uint8_t)(S - 1);
stk[S] = 0x7F; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b6_entry_A2E9(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B57B", "b6_entry_A2E9", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB580;
nmi_poll("b6_entry_B57B");
nmi_pc = 0xB580;
nmi_poll("b6_entry_B57B");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xB582;
nmi_poll("b6_entry_B57B");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0xB584;
nmi_poll("b6_entry_B57B");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xB586;
nmi_poll("b6_entry_B57B");
A = 0x02; setZN(A);
cycles += 2;
nmi_pc = 0xB588;
nmi_poll("b6_entry_B57B");
WR(0x50, A);
cycles += 3;
nmi_pc = 0xB58A;
nmi_poll("b6_entry_B57B");
cycles += 6;
return;
nmi_pc = 0xB58B;
nmi_poll("b6_entry_B57B");
}
