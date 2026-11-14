#include "runtime.h"
static void b6_entry_B013(void);
static void b6_entry_B016(void);
static void b6_LB02E(void);
static void b6_LB047(void);
static void b6_entry_B04B(void);
static void b7_entry_DF36(void);
static void b7_entry_DF68(void);
static void b7_entry_E0ED(void);
static void b7_entry_E0FA(void);
static void __attribute__((used)) b6_entry_B013(void) {
nmi_poll("b6_entry_B013");
nmi_poll("b6_entry_B013");
cycles += 3;
b6_entry_B04B(); return;
}
static void __attribute__((used)) b6_entry_B016(void) {
nmi_poll("b6_entry_B016");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
nmi_poll("b6_entry_B016");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DF68();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B016");
A = RD(0x52); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LB02E(); return; }
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x52) - 1); WR(0x52, _v); setZN(_v); }
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x50, A);
nmi_poll("b6_entry_B016");
cycles += 3;
b6_entry_B04B(); return;
}
static void __attribute__((used)) b6_LB02E(void) {
nmi_poll("b6_LB02E");
nmi_poll("b6_LB02E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_poll("b6_LB02E");
{ uint8_t _m = RD(0x4C); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
cycles += 2;
if (((P & 0x80))) { cycles += 1; b6_LB047(); return; }
nmi_poll("b6_LB02E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0FA();
S = (uint8_t)(S + 2);
nmi_poll("b6_LB02E");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b6_LB047(); return; }
cycles += 2;
A = 0x3C; setZN(A);
cycles += 3;
WR(0xA0, A);
nmi_poll("b6_LB02E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DF36();
S = (uint8_t)(S + 2);
nmi_poll("b6_LB02E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LB047(); return; }
cycles += 2;
A = 0x10; setZN(A);
cycles += 3;
WR(0x52, A);
b6_LB047();
return;
}
static void __attribute__((used)) b6_LB047(void) {
nmi_poll("b6_LB047");
cycles += 2;
A = 0x01; setZN(A);
cycles += 3;
WR(0x50, A);
cycles += 6;
return;
}
static void b6_entry_B04B(void) { __builtin_trap(); }
