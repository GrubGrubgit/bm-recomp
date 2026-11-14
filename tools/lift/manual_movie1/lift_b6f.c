#include "runtime.h"
static void b6_entry_9FF9(void);
static void b6_entry_9FFC(void);
static void b6_entry_A029(void);
static void b6_entry_A02F(void);
static void b6_entry_A032(void);
static void b6_entry_A046(void);
static void b6_entry_A047(void);
static void b6_entry_A04A(void);
static void b6_entry_A083(void);
static void b6_entry_A089(void);
static void b6_entry_A08C(void);
static void b6_entry_A0B5(void);
static void b6_LA03F(void);
static void b6_LA097(void);
static void b6_LA0AB(void);
static void b6_entry_9B81(void);
static void b6_entry_9E9E(void);
static void b6_entry_A009(void);
static void b6_entry_A063(void);
static void b7_entry_D81C(void);
static void b7_entry_DFA0(void);
static void b7_entry_E083(void);
static void b7_entry_E0D8(void);
static void b7_entry_E0ED(void);
static void b7_entry_E0FA(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_9FF9(void) {
nmi_poll("b6_entry_9FF9");
nmi_poll("b6_entry_9FF9");
cycles += 3;
b6_entry_A009(); return;
}
static void __attribute__((used)) b6_entry_9FFC(void) {
nmi_poll("b6_entry_9FFC");
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x43, A);
nmi_poll("b6_entry_9FFC");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9FFC");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A029(); return; }
nmi_poll("b6_entry_9FFC");
cycles += 3;
b6_entry_A009(); return;
}
static void __attribute__((used)) b6_entry_A029(void) {
nmi_poll("b6_entry_A029");
nmi_poll("b6_entry_A029");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9B81();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A029");
nmi_poll("b6_entry_A029");
cycles += 3;
b7_entry_D81C(); return;
}
static void __attribute__((used)) b6_entry_A02F(void) {
nmi_poll("b6_entry_A02F");
nmi_poll("b6_entry_A02F");
cycles += 3;
b6_entry_A046(); return;
}
static void __attribute__((used)) b6_entry_A032(void) {
nmi_poll("b6_entry_A032");
nmi_poll("b6_entry_A032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A032");
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b6_LA03F(); return; }
cycles += 2;
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
b6_LA03F();
return;
}
static void __attribute__((used)) b6_LA03F(void) {
nmi_poll("b6_LA03F");
cycles += 3;
WR(0x4C, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
nmi_poll("b6_LA03F");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9E9E();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA03F");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A046(void) {
nmi_poll("b6_entry_A046");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A047(void) {
nmi_poll("b6_entry_A047");
nmi_poll("b6_entry_A047");
cycles += 3;
b6_entry_A063(); return;
}
static void __attribute__((used)) b6_entry_A04A(void) {
nmi_poll("b6_entry_A04A");
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x43, A);
cycles += 2;
A = 0x02; setZN(A);
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DFA0();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A04A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A083(); return; }
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A04A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A063(); return; }
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0FA();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A04A");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_A083(); return; }
nmi_poll("b6_entry_A04A");
cycles += 3;
b6_entry_A063(); return;
}
static void __attribute__((used)) b6_entry_A083(void) {
nmi_poll("b6_entry_A083");
nmi_poll("b6_entry_A083");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9B81();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A083");
nmi_poll("b6_entry_A083");
cycles += 3;
b7_entry_D81C(); return;
}
static void __attribute__((used)) b6_entry_A089(void) {
nmi_poll("b6_entry_A089");
nmi_poll("b6_entry_A089");
cycles += 3;
b6_entry_A0B5(); return;
}
static void __attribute__((used)) b6_entry_A08C(void) {
nmi_poll("b6_entry_A08C");
nmi_poll("b6_entry_A08C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_A08C");
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b6_LA097(); return; }
cycles += 2;
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
b6_LA097();
return;
}
static void __attribute__((used)) b6_LA097(void) {
nmi_poll("b6_LA097");
cycles += 2;
{ uint8_t _m = 0x10; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x01))) { cycles += 1; b6_entry_A0B5(); return; }
cycles += 2;
{ uint8_t _m = 0x0A; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x01))) { cycles += 1; b6_entry_A0B5(); return; }
cycles += 2;
X = A; setZN(X);
A = RD((uint16_t)(0xA0EB + X)); setZN(A);
cycles += 4 + ((((0xA0EB + X) & 0xFF00) != 0xA000) ? 1 : 0);
cycles += 3;
WR(0x47, A);
cycles += 2;
A = Y; setZN(A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b6_LA0AB(); return; }
nmi_poll("b6_LA097");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0D8();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA097");
b6_LA0AB();
return;
}
static void __attribute__((used)) b6_LA0AB(void) {
nmi_poll("b6_LA0AB");
cycles += 2;
Y = 0x30; setZN(Y);
nmi_poll("b6_LA0AB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA0AB");
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
nmi_poll("b6_LA0AB");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9E9E();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA0AB");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_A0B5(void) {
nmi_poll("b6_entry_A0B5");
cycles += 6;
return;
}
static void b6_entry_9B81(void) { __builtin_trap(); }
static void b6_entry_9E9E(void) { __builtin_trap(); }
static void b6_entry_A009(void) { __builtin_trap(); }
static void b6_entry_A063(void) { __builtin_trap(); }
