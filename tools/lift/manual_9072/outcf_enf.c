#include "runtime.h"
static void b7_LC0CC(void);
static void b7_LC201(void);
static void b7_entry_CF10(void);
static void b7_entry_CF13(void);
static void b7_x(void);
static void __attribute__((used)) b7_entry_CF10(void) {
nmi_pc = 0xCF10;
nmi_poll("b7_entry_CF10");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xCF11;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = 0x40; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xCF13;
nmi_poll("b7_entry_CF10");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0xCF14;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xCF16;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = 0x40; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xCF18;
nmi_poll("b7_entry_CF10");
cycles += 2;
nmi_pc = 0xCF1F;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b7_entry_CF10"); goto b7_LCF1F; }
nmi_pc = 0xCF1A;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xCF1C;
nmi_poll("b7_entry_CF10");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xCF1D;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = 0x81; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xCF1F;
nmi_poll("b7_entry_CF10");
b7_LCF1F:;
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xCF20;
nmi_poll("b7_entry_CF10");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0xCF21;
nmi_poll("b7_entry_CF10");
cycles += 2;
nmi_pc = 0xCF27;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF10"); goto b7_LCF27; }
nmi_pc = 0xCF23;
nmi_poll("b7_entry_CF10");
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
nmi_pc = 0xCF26;
nmi_poll("b7_entry_CF10");
cycles += 6;
return;
nmi_pc = 0xCF27;
nmi_poll("b7_entry_CF10");
b7_LCF27:;
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xCF29;
nmi_poll("b7_entry_CF10");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_pc = 0xCF2A;
nmi_poll("b7_entry_CF10");
{ uint8_t _m = RD((uint16_t)(0xCF2E + X)); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
nmi_pc = 0xCF2D;
nmi_poll("b7_entry_CF10");
cycles += 6;
return;
nmi_pc = 0xCF2E;
nmi_poll("b7_entry_CF10");
}
static void __attribute__((used)) b7_entry_CF13(void) {
nmi_pc = 0xCF13;
nmi_poll("b7_entry_CF13");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0xCF14;
nmi_poll("b7_entry_CF13");
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xCF16;
nmi_poll("b7_entry_CF13");
{ uint8_t _m = 0x40; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xCF18;
nmi_poll("b7_entry_CF13");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF1F3; }
nmi_pc = 0xCF1A;
nmi_poll("b7_entry_CF13");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xCF1C;
nmi_poll("b7_entry_CF13");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xCF1D;
nmi_poll("b7_entry_CF13");
{ uint8_t _m = 0x81; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xCF1F;
nmi_poll("b7_entry_CF13");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xCF20;
nmi_poll("b7_entry_CF13");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0xCF21;
nmi_poll("b7_entry_CF13");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF273; }
nmi_pc = 0xCF23;
nmi_poll("b7_entry_CF13");
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
nmi_pc = 0xCF26;
nmi_poll("b7_entry_CF13");
cycles += 6;
return;
nmi_pc = 0xCF27;
nmi_poll("b7_entry_CF13");
b7_LCF1F3:;
X = A; setZN(X);
cycles += 2;
nmi_poll("b7_entry_CF13");
A = Y; setZN(A);
cycles += 2;
nmi_poll("b7_entry_CF13");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF273; }
nmi_poll("b7_entry_CF13");
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
nmi_poll("b7_entry_CF13");
cycles += 6;
return;
nmi_poll("b7_entry_CF13");
b7_LCF273:;
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b7_entry_CF13");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b7_entry_CF13");
{ uint8_t _m = RD((uint16_t)(0xCF2E + X)); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
nmi_poll("b7_entry_CF13");
cycles += 6;
return;
nmi_poll("b7_entry_CF13");
}
static void __attribute__((used)) b7_LC0CC(void) {
nmi_pc = 0xC0CC;
nmi_poll("b7_LC0CC");
nmi_poll("b7_LC0CC");
cycles += 3;
b7_entry_CF10(); return;
nmi_pc = 0xC0CF;
nmi_poll("b7_LC0CC");
}
static void __attribute__((used)) b7_LC201(void) {
nmi_pc = 0xC201;
nmi_poll("b7_LC201");
nmi_poll("b7_LC201");
cycles += 3;
b7_entry_CF13(); return;
nmi_pc = 0xC204;
nmi_poll("b7_LC201");
}
static void b7_x(void) { __builtin_trap(); }
