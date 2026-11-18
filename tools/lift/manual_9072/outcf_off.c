#include "runtime.h"
static void b7_entry_CF10(void);
static void b7_entry_CF13(void);
static void b7_LC0CC(void);
static void b7_LC201(void);
static void b7_x(void);
static void __attribute__((used)) b7_entry_CF10(void) {
nmi_poll("b7_entry_CF10");
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x40; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
{ uint8_t _m = 0x40; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b7_entry_CF10"); goto b7_LCF1F; }
cycles += 2;
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x81; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
b7_LCF1F:;
cycles += 2;
X = A; setZN(X);
cycles += 2;
A = Y; setZN(A);
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF10"); goto b7_LCF27; }
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
cycles += 6;
return;
b7_LCF27:;
cycles += 2;
A = 0x00; setZN(A);
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD((uint16_t)(0xCF2E + X)); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
cycles += 6;
return;
}
static void __attribute__((used)) b7_entry_CF13(void) {
nmi_poll("b7_entry_CF13");
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
{ uint8_t _m = 0x40; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF1F3; }
cycles += 2;
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x81; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
X = A; setZN(X);
cycles += 2;
A = Y; setZN(A);
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF273; }
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
cycles += 6;
return;
b7_LCF1F3:;
cycles += 2;
X = A; setZN(X);
cycles += 2;
A = Y; setZN(A);
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b7_entry_CF13"); goto b7_LCF273; }
A = RD((uint16_t)(0xCF2E + X)); setZN(A);
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
cycles += 6;
return;
b7_LCF273:;
cycles += 2;
A = 0x00; setZN(A);
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD((uint16_t)(0xCF2E + X)); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0xCF2E + X) & 0xFF00) != 0xCF00) ? 1 : 0);
cycles += 6;
return;
}
static void __attribute__((used)) b7_LC0CC(void) {
nmi_poll("b7_LC0CC");
nmi_poll("b7_LC0CC");
cycles += 3;
b7_entry_CF10(); return;
}
static void __attribute__((used)) b7_LC201(void) {
nmi_poll("b7_LC201");
nmi_poll("b7_LC201");
cycles += 3;
b7_entry_CF13(); return;
}
static void b7_x(void) { __builtin_trap(); }
