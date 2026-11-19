#include "runtime.h"
static void b4_entry_A571(void);
static void b4_entry_A574(void);
static void b4_entry_A589(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_A571(void) {
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_poll("b4_entry_A571");
b4_entry_A574();
return;
}
static void __attribute__((used)) b4_entry_A574(void) {
nmi_poll("b4_entry_A574");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A574");
WR(0x53, A);
cycles += 3;
nmi_poll("b4_entry_A574");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A574");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_A574");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_entry_A574");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A574");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_A574");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A574");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_A574");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_A574");
cycles += 6;
return;
nmi_poll("b4_entry_A574");
}
static void __attribute__((used)) b4_entry_A589(void) {
nmi_poll("b4_entry_A589");
cycles += 6;
return;
nmi_poll("b4_entry_A589");
}
static void b4_x(void) { __builtin_trap(); }
