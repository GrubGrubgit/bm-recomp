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
nmi_pc = 0x9FF9;
nmi_poll("b6_entry_9FF9");
nmi_poll("b6_entry_9FF9");
cycles += 3;
b6_entry_A009(); return;
nmi_pc = 0x9FFC;
nmi_poll("b6_entry_9FF9");
}
static void __attribute__((used)) b6_entry_9FFC(void) {
nmi_pc = 0x9FFC;
nmi_poll("b6_entry_9FFC");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0x9FFE;
nmi_poll("b6_entry_9FFC");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xA000;
nmi_poll("b6_entry_9FFC");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0xA002;
nmi_poll("b6_entry_9FFC");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xA004;
nmi_poll("b6_entry_9FFC");
nmi_poll("b6_entry_9FFC");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_pc = 0xA007;
nmi_poll("b6_entry_9FFC");
nmi_pc = 0xA007;
nmi_poll("b6_entry_9FFC");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A029(); return; }
nmi_pc = 0xA009;
nmi_poll("b6_entry_9FFC");
nmi_poll("b6_entry_9FFC");
cycles += 3;
b6_entry_A009(); return;
nmi_pc = 0xA00C;
nmi_poll("b6_entry_9FFC");
}
static void __attribute__((used)) b6_entry_A029(void) {
nmi_pc = 0xA029;
nmi_poll("b6_entry_A029");
nmi_poll("b6_entry_A029");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9B81();
S = (uint8_t)(S + 2);
nmi_pc = 0xA02C;
nmi_poll("b6_entry_A029");
nmi_pc = 0xA02C;
nmi_poll("b6_entry_A029");
nmi_poll("b6_entry_A029");
cycles += 3;
b7_entry_D81C(); return;
nmi_pc = 0xA02F;
nmi_poll("b6_entry_A029");
}
static void __attribute__((used)) b6_entry_A02F(void) {
nmi_pc = 0xA02F;
nmi_poll("b6_entry_A02F");
nmi_poll("b6_entry_A02F");
cycles += 3;
b6_entry_A046(); return;
nmi_pc = 0xA032;
nmi_poll("b6_entry_A02F");
}
static void __attribute__((used)) b6_entry_A032(void) {
nmi_pc = 0xA032;
nmi_poll("b6_entry_A032");
nmi_poll("b6_entry_A032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_pc = 0xA035;
nmi_poll("b6_entry_A032");
nmi_pc = 0xA035;
nmi_poll("b6_entry_A032");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xA037;
nmi_poll("b6_entry_A032");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0xA038;
nmi_poll("b6_entry_A032");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b6_LA03F(); return; }
nmi_pc = 0xA03A;
nmi_poll("b6_entry_A032");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xA03C;
nmi_poll("b6_entry_A032");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xA03D;
nmi_poll("b6_entry_A032");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xA03F;
nmi_poll("b6_entry_A032");
b6_LA03F();
return;
}
static void __attribute__((used)) b6_LA03F(void) {
nmi_pc = 0xA03F;
nmi_poll("b6_LA03F");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xA041;
nmi_poll("b6_LA03F");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA043;
nmi_poll("b6_LA03F");
nmi_poll("b6_LA03F");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9E9E();
S = (uint8_t)(S + 2);
nmi_pc = 0xA046;
nmi_poll("b6_LA03F");
nmi_pc = 0xA046;
nmi_poll("b6_LA03F");
cycles += 6;
return;
nmi_pc = 0xA047;
nmi_poll("b6_LA03F");
}
static void __attribute__((used)) b6_entry_A046(void) {
nmi_pc = 0xA046;
nmi_poll("b6_entry_A046");
cycles += 6;
return;
nmi_pc = 0xA047;
nmi_poll("b6_entry_A046");
}
static void __attribute__((used)) b6_entry_A047(void) {
nmi_pc = 0xA047;
nmi_poll("b6_entry_A047");
nmi_poll("b6_entry_A047");
cycles += 3;
b6_entry_A063(); return;
nmi_pc = 0xA04A;
nmi_poll("b6_entry_A047");
}
static void __attribute__((used)) b6_entry_A04A(void) {
nmi_pc = 0xA04A;
nmi_poll("b6_entry_A04A");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0xA04C;
nmi_poll("b6_entry_A04A");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xA04E;
nmi_poll("b6_entry_A04A");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0xA050;
nmi_poll("b6_entry_A04A");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xA052;
nmi_poll("b6_entry_A04A");
A = 0x02; setZN(A);
cycles += 2;
nmi_pc = 0xA054;
nmi_poll("b6_entry_A04A");
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DFA0();
S = (uint8_t)(S + 2);
nmi_pc = 0xA057;
nmi_poll("b6_entry_A04A");
nmi_pc = 0xA057;
nmi_poll("b6_entry_A04A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A083(); return; }
nmi_pc = 0xA059;
nmi_poll("b6_entry_A04A");
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_pc = 0xA05C;
nmi_poll("b6_entry_A04A");
nmi_pc = 0xA05C;
nmi_poll("b6_entry_A04A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_A063(); return; }
nmi_pc = 0xA05E;
nmi_poll("b6_entry_A04A");
nmi_poll("b6_entry_A04A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0FA();
S = (uint8_t)(S + 2);
nmi_pc = 0xA061;
nmi_poll("b6_entry_A04A");
nmi_pc = 0xA061;
nmi_poll("b6_entry_A04A");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_A083(); return; }
nmi_pc = 0xA063;
nmi_poll("b6_entry_A04A");
nmi_poll("b6_entry_A04A");
cycles += 3;
b6_entry_A063(); return;
nmi_pc = 0xA066;
nmi_poll("b6_entry_A04A");
}
static void __attribute__((used)) b6_entry_A083(void) {
nmi_pc = 0xA083;
nmi_poll("b6_entry_A083");
nmi_poll("b6_entry_A083");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9B81();
S = (uint8_t)(S + 2);
nmi_pc = 0xA086;
nmi_poll("b6_entry_A083");
nmi_pc = 0xA086;
nmi_poll("b6_entry_A083");
nmi_poll("b6_entry_A083");
cycles += 3;
b7_entry_D81C(); return;
nmi_pc = 0xA089;
nmi_poll("b6_entry_A083");
}
static void __attribute__((used)) b6_entry_A089(void) {
nmi_pc = 0xA089;
nmi_poll("b6_entry_A089");
nmi_poll("b6_entry_A089");
cycles += 3;
b6_entry_A0B5(); return;
nmi_pc = 0xA08C;
nmi_poll("b6_entry_A089");
}
static void __attribute__((used)) b6_entry_A08C(void) {
nmi_pc = 0xA08C;
nmi_poll("b6_entry_A08C");
nmi_poll("b6_entry_A08C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_pc = 0xA08F;
nmi_poll("b6_entry_A08C");
nmi_pc = 0xA08F;
nmi_poll("b6_entry_A08C");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0xA090;
nmi_poll("b6_entry_A08C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b6_LA097(); return; }
nmi_pc = 0xA092;
nmi_poll("b6_entry_A08C");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xA094;
nmi_poll("b6_entry_A08C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xA095;
nmi_poll("b6_entry_A08C");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xA097;
nmi_poll("b6_entry_A08C");
b6_LA097();
return;
}
static void __attribute__((used)) b6_LA097(void) {
nmi_pc = 0xA097;
nmi_poll("b6_LA097");
{ uint8_t _m = 0x10; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xA099;
nmi_poll("b6_LA097");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b6_entry_A0B5(); return; }
nmi_pc = 0xA09B;
nmi_poll("b6_LA097");
{ uint8_t _m = 0x0A; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xA09D;
nmi_poll("b6_LA097");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b6_entry_A0B5(); return; }
nmi_pc = 0xA09F;
nmi_poll("b6_LA097");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xA0A0;
nmi_poll("b6_LA097");
A = RD((uint16_t)(0xA0EB + X)); setZN(A);
cycles += 4 + ((((0xA0EB + X) & 0xFF00) != 0xA000) ? 1 : 0);
nmi_pc = 0xA0A3;
nmi_poll("b6_LA097");
WR(0x47, A);
cycles += 3;
nmi_pc = 0xA0A5;
nmi_poll("b6_LA097");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0xA0A6;
nmi_poll("b6_LA097");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b6_LA0AB(); return; }
nmi_pc = 0xA0A8;
nmi_poll("b6_LA097");
nmi_poll("b6_LA097");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E0D8();
S = (uint8_t)(S + 2);
nmi_pc = 0xA0AB;
nmi_poll("b6_LA097");
nmi_pc = 0xA0AB;
nmi_poll("b6_LA097");
b6_LA0AB();
return;
}
static void __attribute__((used)) b6_LA0AB(void) {
nmi_pc = 0xA0AB;
nmi_poll("b6_LA0AB");
Y = 0x30; setZN(Y);
cycles += 2;
nmi_pc = 0xA0AD;
nmi_poll("b6_LA0AB");
nmi_poll("b6_LA0AB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_pc = 0xA0B0;
nmi_poll("b6_LA0AB");
nmi_pc = 0xA0B0;
nmi_poll("b6_LA0AB");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA0B2;
nmi_poll("b6_LA0AB");
nmi_poll("b6_LA0AB");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9E9E();
S = (uint8_t)(S + 2);
nmi_pc = 0xA0B5;
nmi_poll("b6_LA0AB");
nmi_pc = 0xA0B5;
nmi_poll("b6_LA0AB");
cycles += 6;
return;
nmi_pc = 0xA0B6;
nmi_poll("b6_LA0AB");
}
static void __attribute__((used)) b6_entry_A0B5(void) {
nmi_pc = 0xA0B5;
nmi_poll("b6_entry_A0B5");
cycles += 6;
return;
nmi_pc = 0xA0B6;
nmi_poll("b6_entry_A0B5");
}
static void b6_entry_9B81(void) { __builtin_trap(); }
static void b6_entry_9E9E(void) { __builtin_trap(); }
static void b6_entry_A009(void) { __builtin_trap(); }
static void b6_entry_A063(void) { __builtin_trap(); }
