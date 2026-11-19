#include "runtime.h"
static void b6_entry_B3FE(void);
static void b6_entry_B401(void);
static void b6_entry_B457(void);
static void b7_entry_DECC(void);
static void b7_entry_DFD1(void);
static void b7_entry_E083(void);
static void b7_entry_E0D8(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_B3FE(void) {
nmi_poll("b6_entry_B3FE");
nmi_poll("b6_entry_B3FE");
cycles += 3;
b6_entry_B457(); return;
nmi_poll("b6_entry_B3FE");
}
static void __attribute__((used)) b6_entry_B401(void) {
nmi_poll("b6_entry_B401");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
WR(0x42, A);
cycles += 3;
nmi_poll("b6_entry_B401");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
WR(0x43, A);
cycles += 3;
nmi_poll("b6_entry_B401");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_poll("b6_entry_B401");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b6_entry_B401"); goto b6_LB43A; }
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b6_entry_B401"); goto b6_LB418; }
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0D8();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 3;
goto b6_LB420;
nmi_poll("b6_entry_B401");
b6_LB418:;
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b6_entry_B401");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b6_entry_B401"); goto b6_LB420; }
nmi_poll("b6_entry_B401");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
WR(0x4D, A);
cycles += 3;
nmi_poll("b6_entry_B401");
b6_LB420:;
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_entry_B401");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_B457(); return; }
nmi_poll("b6_entry_B401");
A = 0x46; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
{ uint8_t _v = (uint8_t)(RD(0x50) + 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
{ uint8_t _m = 0x07; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b6_entry_B401");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b6_entry_B401");
{ uint8_t _m = 0x20; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b6_entry_B401");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 3;
b6_entry_B457(); return;
nmi_poll("b6_entry_B401");
b6_LB43A:;
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
X = 0x00; setZN(X);
cycles += 2;
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DFD1();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_A2D4();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
A = RD(0x4D); setZN(A);
cycles += 3;
nmi_poll("b6_entry_B401");
{ uint8_t _m = 0x04; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b6_entry_B401");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b6_entry_B457(); return; }
nmi_poll("b6_entry_B401");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
WR(0x4D, A);
cycles += 3;
nmi_poll("b6_entry_B401");
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_entry_B401");
A = 0x70; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B401");
WR(0x51, A);
cycles += 3;
nmi_poll("b6_entry_B401");
nmi_poll("b6_entry_B401");
cycles += 3;
b6_entry_B457(); return;
nmi_poll("b6_entry_B401");
}
static void b6_entry_B457(void) { __builtin_trap(); }
