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
nmi_pc = 0xA5C2;
nmi_poll("b6_entry_A5C2");
nmi_poll("b6_entry_A5C2");
cycles += 3;
b6_entry_A605(); return;
nmi_pc = 0xA5C5;
nmi_poll("b6_entry_A5C2");
}
static void __attribute__((used)) b6_entry_A5C5(void) {
nmi_pc = 0xA5C5;
nmi_poll("b6_entry_A5C5");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xA5C7;
nmi_poll("b6_entry_A5C5");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xA5C9;
nmi_poll("b6_entry_A5C5");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xA5CB;
nmi_poll("b6_entry_A5C5");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xA5CD;
nmi_poll("b6_entry_A5C5");
A = RD(0x51); setZN(A);
cycles += 3;
nmi_pc = 0xA5CF;
nmi_poll("b6_entry_A5C5");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LA5DB(); return; }
nmi_pc = 0xA5D1;
nmi_poll("b6_entry_A5C5");
A = 0x43; setZN(A);
cycles += 2;
nmi_pc = 0xA5D3;
nmi_poll("b6_entry_A5C5");
nmi_poll("b6_entry_A5C5");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_pc = 0xA5D6;
nmi_poll("b6_entry_A5C5");
nmi_pc = 0xA5D6;
nmi_poll("b6_entry_A5C5");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA5D8;
nmi_poll("b6_entry_A5C5");
nmi_poll("b6_entry_A5C5");
cycles += 3;
b6_entry_A605(); return;
nmi_pc = 0xA5DB;
nmi_poll("b6_entry_A5C5");
}
static void __attribute__((used)) b6_LA5DB(void) {
nmi_pc = 0xA5DB;
nmi_poll("b6_LA5DB");
nmi_poll("b6_LA5DB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_pc = 0xA5DE;
nmi_poll("b6_LA5DB");
nmi_pc = 0xA5DE;
nmi_poll("b6_LA5DB");
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_A605(); return; }
nmi_pc = 0xA5E0;
nmi_poll("b6_LA5DB");
nmi_poll("b6_LA5DB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_pc = 0xA5E3;
nmi_poll("b6_LA5DB");
nmi_pc = 0xA5E3;
nmi_poll("b6_LA5DB");
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xA5E5;
nmi_poll("b6_LA5DB");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_LA5EE(); return; }
nmi_pc = 0xA5E7;
nmi_poll("b6_LA5DB");
A = 0x60; setZN(A);
cycles += 2;
nmi_pc = 0xA5E9;
nmi_poll("b6_LA5DB");
X = 0x60; setZN(X);
cycles += 2;
nmi_pc = 0xA5EB;
nmi_poll("b6_LA5DB");
nmi_poll("b6_LA5DB");
cycles += 3;
b6_LA5F2(); return;
nmi_pc = 0xA5EE;
nmi_poll("b6_LA5DB");
}
static void __attribute__((used)) b6_LA5EE(void) {
nmi_pc = 0xA5EE;
nmi_poll("b6_LA5EE");
A = 0xA0; setZN(A);
cycles += 2;
nmi_pc = 0xA5F0;
nmi_poll("b6_LA5EE");
X = 0xA0; setZN(X);
cycles += 2;
nmi_pc = 0xA5F2;
nmi_poll("b6_LA5EE");
b6_LA5F2();
return;
}
static void __attribute__((used)) b6_LA5F2(void) {
nmi_pc = 0xA5F2;
nmi_poll("b6_LA5F2");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xA5F3;
nmi_poll("b6_LA5F2");
{ uint8_t _m = RD(0x47); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_pc = 0xA5F5;
nmi_poll("b6_LA5F2");
WR(0x47, A);
cycles += 3;
nmi_pc = 0xA5F7;
nmi_poll("b6_LA5F2");
WR(0x50, X);
cycles += 3;
nmi_pc = 0xA5F9;
nmi_poll("b6_LA5F2");
Y = 0x10; setZN(Y);
cycles += 2;
nmi_pc = 0xA5FB;
nmi_poll("b6_LA5F2");
nmi_poll("b6_LA5F2");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_pc = 0xA5FE;
nmi_poll("b6_LA5F2");
nmi_pc = 0xA5FE;
nmi_poll("b6_LA5F2");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xA600;
nmi_poll("b6_LA5F2");
WR(0x51, A);
cycles += 3;
nmi_pc = 0xA602;
nmi_poll("b6_LA5F2");
{ uint8_t _v = (uint8_t)(RD(0x46) - 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA604;
nmi_poll("b6_LA5F2");
cycles += 6;
return;
nmi_pc = 0xA605;
nmi_poll("b6_LA5F2");
}
static void b6_entry_A605(void) { __builtin_trap(); }
