#include "runtime.h"
static void b6_entry_98A3(void);
static void b6_entry_98A5(void);
static void b6_entry_98A7(void);
static void b6_entry_98AB(void);
static void b6_entry_98F5(void);
static void b6_entry_9916(void);
static void b6_entry_9B95(void);
static void b6_x(void);
static void b7_entry_D790(void);
static void b7_entry_DECC(void);
static void b7_entry_EB14(void);
static void __attribute__((used)) b6_entry_98A3(void) {
nmi_poll("b6_entry_98A3");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_98A5(); return; }
b6_entry_98A5();
return;
}
static void __attribute__((used)) b6_entry_98A5(void) {
nmi_poll("b6_entry_98A5");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b6_entry_98A7(); return; }
b6_entry_98A7();
return;
}
static void __attribute__((used)) b6_entry_98A7(void) {
nmi_poll("b6_entry_98A7");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_98F5(); return; }
{ uint8_t _m = RD((uint16_t)(0x99 + X)); A = (uint8_t)(A | _m); setZN(A); }
cycles += 4;
b6_entry_98AB();
return;
}
static void __attribute__((used)) b6_entry_98AB(void) {
nmi_poll("b6_entry_98AB");
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
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b6_entry_98AB"); goto b6_L98BD; }
nmi_poll("b6_entry_98AB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D790();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_98AB");
nmi_poll("b6_entry_98AB");
cycles += 3;
b6_entry_9B95(); return;
b6_L98BD:;
A = RD(0x52); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_9916(); return; }
X = RD(0x50); setZN(X);
cycles += 3;
A = RD((uint16_t)(0x0400 + X)); setZN(A);
cycles += 4 + ((((0x400 + X) & 0xFF00) != 0x400) ? 1 : 0);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b6_entry_98AB"); goto b6_L98CC; }
cycles += 3;
WR(0x52, A);
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_9916(); return; }
b6_L98CC:;
A = RD((uint16_t)(0x0403 + X)); setZN(A);
cycles += 4 + ((((0x403 + X) & 0xFF00) != 0x400) ? 1 : 0);
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD(0x49); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b6_entry_98AB"); goto b6_L98E9; }
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b6_entry_98AB"); goto b6_L98DF; }
A = RD(0x4C); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x02; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
nmi_poll("b6_entry_98AB");
cycles += 3;
goto b6_L98E4;
b6_L98DF:;
A = RD(0x4C); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)(P | 0x01);
cycles += 2;
{ uint8_t _m = 0x02; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
b6_L98E4:;
cycles += 3;
WR(0x4C, A);
nmi_poll("b6_entry_98AB");
cycles += 3;
goto b6_L98F0;
b6_L98E9:;
cycles += 2;
A = 0x10; setZN(A);
cycles += 2;
X = 0x4C; setZN(X);
nmi_poll("b6_entry_98AB");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB14();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_98AB");
b6_L98F0:;
X = RD(0x50); setZN(X);
cycles += 3;
A = RD((uint16_t)(0x0405 + X)); setZN(A);
cycles += 4 + ((((0x405 + X) & 0xFF00) != 0x400) ? 1 : 0);
b6_entry_98F5();
return;
}
static void __attribute__((used)) b6_entry_98F5(void) {
nmi_poll("b6_entry_98F5");
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD(0x4B); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b6_entry_98F5"); goto b6_L990F; }
cycles += 2;
if (((P & 0x80))) { cycles += 2; nmi_poll("b6_entry_98F5"); goto b6_L9905; }
A = RD(0x4D); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x02; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
nmi_poll("b6_entry_98F5");
cycles += 3;
goto b6_L990A;
b6_L9905:;
A = RD(0x4D); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)(P | 0x01);
cycles += 2;
{ uint8_t _m = 0x02; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
b6_L990A:;
cycles += 3;
WR(0x4D, A);
nmi_poll("b6_entry_98F5");
cycles += 3;
b6_entry_9916(); return;
b6_L990F:;
cycles += 2;
A = 0x10; setZN(A);
cycles += 2;
X = 0x4D; setZN(X);
nmi_poll("b6_entry_98F5");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB14();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_98F5");
b6_entry_9916();
return;
}
static void __attribute__((used)) b6_entry_9916(void) {
nmi_poll("b6_entry_9916");
cycles += 6;
return;
}
static void __attribute__((used)) b6_entry_9B95(void) {
nmi_poll("b6_entry_9B95");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x4F, A);
cycles += 2;
A = 0x0A; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 2;
A = 0x4B; setZN(A);
cycles += 3;
WR(0x46, A);
cycles += 2;
A = 0x28; setZN(A);
nmi_poll("b6_entry_9B95");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9B95");
cycles += 6;
return;
}
static void b6_x(void) { __builtin_trap(); }
