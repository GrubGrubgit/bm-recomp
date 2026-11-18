#include "runtime.h"
static void b4_entry_B64D(void);
static void b4_entry_B650(void);
static void b4_LB65A(void);
static void b4_entry_B680(void);
static void __attribute__((used)) b4_entry_B64D(void) {
nmi_poll("b4_entry_B64D");
nmi_poll("b4_entry_B64D");
cycles += 3;
b4_LB65A(); return;
}
static void __attribute__((used)) b4_entry_B650(void) {
nmi_poll("b4_entry_B650");
cycles += 2;
A = 0x08; setZN(A);
nmi_poll("b4_entry_B650");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_B2B4(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B650", "b4_entry_B2B4", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B650");
X = RD(0x11); setZN(X);
cycles += 3;
cycles += 2;
X = (uint8_t)(X + 1); setZN(X);
cycles += 3;
WR(0x51, X);
b4_LB65A();
return;
}
static void __attribute__((used)) b4_LB65A(void) {
nmi_poll("b4_LB65A");
cycles += 6;
return;
}
static void b4_entry_B680(void) { __builtin_trap(); }
