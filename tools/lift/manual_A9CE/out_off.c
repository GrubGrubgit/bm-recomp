#include "runtime.h"
static void b6_entry_A9CB(void);
static void b6_entry_A9CE(void);
static void b6_LA9DD(void);
static void b6_entry_A9DE(void);
static void b6_entry_A9E1(void);
static void b6_entry_AA03(void);
static void b6_x(void);
static void b7_entry_D2B1(void);
static void b7_entry_E005(void);
static void __attribute__((used)) b6_entry_A9CB(void) {
nmi_poll("b6_entry_A9CB");
nmi_poll("b6_entry_A9CB");
cycles += 3;
b6_LA9DD(); return;
}
static void __attribute__((used)) b6_entry_A9CE(void) {
nmi_poll("b6_entry_A9CE");
cycles += 2;
A = 0x07; setZN(A);
nmi_poll("b6_entry_A9CE");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A9CE");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x4C, A);
cycles += 3;
WR(0x4D, A);
cycles += 2;
A = 0x01; setZN(A);
cycles += 3;
WR(0x50, A);
b6_LA9DD();
return;
}
static void __attribute__((used)) b6_LA9DD(void) {
nmi_poll("b6_LA9DD");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A9DE(void) {
nmi_poll("b6_entry_A9DE");
nmi_poll("b6_entry_A9DE");
cycles += 3;
b6_entry_AA03(); return;
}
static void __attribute__((used)) b6_entry_A9E1(void) {
nmi_poll("b6_entry_A9E1");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
A = RD(0x50); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b6_entry_A9E1"); goto b6_LA9FA; }
nmi_poll("b6_entry_A9E1");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E005();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A9E1");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b6_entry_A9E1"); goto b6_LA9F8; }
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x4C, A);
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_AA03(); return; }
b6_LA9F8:;
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x50) + 1); WR(0x50, _v); setZN(_v); }
b6_LA9FA:;
cycles += 2;
A = 0x11; setZN(A);
nmi_poll("b6_entry_A9E1");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D2B1();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A9E1");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b6_entry_AA03(); return; }
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
b6_entry_AA03();
return;
}
static void __attribute__((used)) b6_entry_AA03(void) {
nmi_poll("b6_entry_AA03");
cycles += 6;
return;
}
static void b6_x(void) { __builtin_trap(); }
