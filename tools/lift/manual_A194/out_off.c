#include "runtime.h"
static void b6_entry_A164(void);
static void b6_LA190(void);
static void b6_entry_A191(void);
static void b6_entry_A194(void);
static void b6_LA1AC(void);
static void b6_entry_A1AD(void);
static void b6_entry_A1B0(void);
static void b6_entry_A1CC(void);
static void b6_x(void);
static void b7_entry_D2B9(void);
static void b7_entry_D2DE(void);
static void b7_entry_D2FE(void);
static void b7_entry_D81C(void);
static void b7_entry_DECC(void);
static void b7_entry_DFD1(void);
static void b7_entry_E0ED(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_A164(void) {
nmi_poll("b6_entry_A164");
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A164");
cycles += 2;
A = 0x06; setZN(A);
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A164");
cycles += 2;
A = 0x63; setZN(A);
cycles += 3;
WR(0x46, A);
cycles += 2;
A = 0x01; setZN(A);
cycles += 3;
WR(0x50, A);
cycles += 2;
A = 0xE8; setZN(A);
cycles += 3;
WR(0x4D, A);
cycles += 2;
A = 0x11; setZN(A);
cycles += 3;
WR(0x4C, A);
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A164");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b6_entry_A164"); goto b6_LA188; }
cycles += 2;
A = 0x00; setZN(A);
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD(0x4C); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 3;
WR(0x4C, A);
b6_LA188:;
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 3;
WR(0x47, A);
cycles += 3;
WR(0x52, A);
b6_LA190();
return;
}
static void __attribute__((used)) b6_LA190(void) {
nmi_poll("b6_LA190");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A191(void) {
nmi_poll("b6_entry_A191");
nmi_poll("b6_entry_A191");
cycles += 3;
b6_LA1AC(); return;
}
static void __attribute__((used)) b6_entry_A194(void) {
nmi_poll("b6_entry_A194");
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A194");
cycles += 2;
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0xB0; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
WR(0x47, A);
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 2;
Y = 0x20; setZN(Y);
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A194");
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D2B9();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A194");
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
b6_LA1AC();
return;
}
static void __attribute__((used)) b6_LA1AC(void) {
nmi_poll("b6_LA1AC");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A1AD(void) {
nmi_poll("b6_entry_A1AD");
nmi_poll("b6_entry_A1AD");
cycles += 3;
b6_entry_A1CC(); return;
}
static void __attribute__((used)) b6_entry_A1B0(void) {
nmi_poll("b6_entry_A1B0");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b6_entry_A1B0"); goto b6_LA1BF; }
nmi_poll("b6_entry_A1B0");
cycles += 3;
b7_entry_D81C(); return;
b6_LA1BF:;
cycles += 2;
A = 0x02; setZN(A);
cycles += 2;
X = 0x00; setZN(X);
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DFD1();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D2DE();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D2FE();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A1B0");
b6_entry_A1CC();
return;
}
static void __attribute__((used)) b6_entry_A1CC(void) {
nmi_poll("b6_entry_A1CC");
cycles += 6;
return;
}
static void b6_x(void) { __builtin_trap(); }
