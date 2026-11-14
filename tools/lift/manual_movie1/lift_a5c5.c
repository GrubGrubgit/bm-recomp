#include "runtime.h"
static void b6_entry_A5C2(void);
static void b6_entry_A5C5(void);
static void b6_LA5DB(void);
static void b6_LA5EE(void);
static void b6_LA5F2(void);
static void b6_entry_A605(void);
static void b7_entry_DECC(void);
static void b7_entry_E083(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_A5C2(void) {
nmi_poll("b6_entry_A5C2");
nmi_poll("b6_entry_A5C2");
cycles += 3;
b6_entry_A605(); return;
}
static void __attribute__((used)) b6_entry_A5C5(void) {
nmi_poll("b6_entry_A5C5");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
A = RD(0x51); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LA5DB(); return; }
cycles += 2;
A = 0x43; setZN(A);
nmi_poll("b6_entry_A5C5");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A5C5");
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
nmi_poll("b6_entry_A5C5");
cycles += 3;
b6_entry_A605(); return;
}
static void __attribute__((used)) b6_LA5DB(void) {
nmi_poll("b6_LA5DB");
nmi_poll("b6_LA5DB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA5DB");
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_A605(); return; }
nmi_poll("b6_LA5DB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA5DB");
cycles += 2;
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LA5EE(); return; }
cycles += 2;
A = 0x60; setZN(A);
cycles += 2;
X = 0x60; setZN(X);
nmi_poll("b6_LA5DB");
cycles += 3;
b6_LA5F2(); return;
}
static void __attribute__((used)) b6_LA5EE(void) {
nmi_poll("b6_LA5EE");
cycles += 2;
A = 0xA0; setZN(A);
cycles += 2;
X = 0xA0; setZN(X);
b6_LA5F2();
return;
}
static void __attribute__((used)) b6_LA5F2(void) {
nmi_poll("b6_LA5F2");
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD(0x47); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 3;
WR(0x47, A);
cycles += 3;
WR(0x50, X);
cycles += 2;
Y = 0x10; setZN(Y);
nmi_poll("b6_LA5F2");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA5F2");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) - 1); WR(0x46, _v); setZN(_v); }
cycles += 6;
return;
}
static void b6_entry_A605(void) { __builtin_trap(); }
