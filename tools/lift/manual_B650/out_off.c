#include "runtime.h"
static void b4_entry_B64D(void);
static void b4_entry_B650(void);
static void b4_LB65A(void);
static void b4_entry_B680(void);
static void __attribute__((used)) b4_entry_B64D(void) {
nmi_poll("b4_entry_B64D");
nmi_poll("b4_entry_B64D");
cycles += 3;
nmi_poll("b4_entry_B64D");
b4_LB65A(); return;
}
static void __attribute__((used)) b4_entry_B650(void) {
nmi_poll("b4_entry_B650");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B650");
nmi_poll("b4_entry_B650");
cycles += 6;
nmi_poll("b4_entry_B650");
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B650");
X = RD(0x11); setZN(X);
cycles += 3;
nmi_poll("b4_entry_B650");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_poll("b4_entry_B650");
WR(0x51, X);
cycles += 3;
nmi_poll("b4_entry_B650");
b4_LB65A();
return;
}
static void __attribute__((used)) b4_LB65A(void) {
nmi_poll("b4_LB65A");
cycles += 6;
return;
}
static void b4_entry_B680(void) { __builtin_trap(); }
