#include "runtime.h"
static void b4_entry_A571(void);
static void b4_entry_A574(void);
static void b4_entry_A589(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_A571(void) {
nmi_pc = 0xA571;
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_pc = 0xA572;
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_pc = 0xA573;
nmi_poll("b4_entry_A571");
;
cycles += 2;
nmi_pc = 0xA574;
nmi_poll("b4_entry_A571");
b4_entry_A574();
return;
}
static void __attribute__((used)) b4_entry_A574(void) {
nmi_pc = 0xA574;
nmi_poll("b4_entry_A574");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xA576;
nmi_poll("b4_entry_A574");
WR(0x53, A);
cycles += 3;
nmi_pc = 0xA578;
nmi_poll("b4_entry_A574");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xA57A;
nmi_poll("b4_entry_A574");
WR(0x50, A);
cycles += 3;
nmi_pc = 0xA57C;
nmi_poll("b4_entry_A574");
WR(0x51, A);
cycles += 3;
nmi_pc = 0xA57E;
nmi_poll("b4_entry_A574");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xA580;
nmi_poll("b4_entry_A574");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xA582;
nmi_poll("b4_entry_A574");
A = 0x08; setZN(A);
cycles += 2;
nmi_pc = 0xA584;
nmi_poll("b4_entry_A574");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0xA586;
nmi_poll("b4_entry_A574");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA588;
nmi_poll("b4_entry_A574");
cycles += 6;
return;
nmi_pc = 0xA589;
nmi_poll("b4_entry_A574");
}
static void __attribute__((used)) b4_entry_A589(void) {
nmi_pc = 0xA589;
nmi_poll("b4_entry_A589");
cycles += 6;
return;
nmi_pc = 0xA58A;
nmi_poll("b4_entry_A589");
}
static void b4_x(void) { __builtin_trap(); }
