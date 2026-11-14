#include "runtime.h"
static void b6_entry_8B74(void);
static void b6_entry_8B77(void);
static void b6_entry_8BE5(void);
static void b6_entry_8C00(void);
static void b6_L8C08(void);
static void b6_L8C0A(void);
static void b6_entry_8B8A(void);
static void b6_entry_8C32(void);
static void b6_entry_8C4D(void);
static void b7_entry_D2DB(void);
static void __attribute__((used)) b6_entry_8B74(void) {
nmi_poll("b6_entry_8B74");
nmi_poll("b6_entry_8B74");
cycles += 3;
b6_entry_8B8A(); return;
}
static void __attribute__((used)) b6_entry_8B77(void) {
nmi_poll("b6_entry_8B77");
cycles += 2;
A = 0x4C; setZN(A);
cycles += 3;
WR(0x45, A);
A = RD(0x8B8F); setZN(A);
cycles += 4;
cycles += 3;
WR(0x7A, A);
A = RD(0x8B90); setZN(A);
cycles += 4;
cycles += 3;
WR(0x7B, A);
cycles += 2;
Y = 0x00; setZN(Y);
nmi_poll("b6_entry_8B77");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_8BE5();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_8B77");
nmi_poll("b6_entry_8B77");
cycles += 3;
b6_entry_8B8A(); return;
}
static void __attribute__((used)) b6_entry_8BE5(void) {
nmi_poll("b6_entry_8BE5");
Y = RD(0x51); setZN(Y);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x08; uint8_t _r = (uint8_t)(Y - _m); P = (uint8_t)((P & 0x7C) | (Y >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x02))) { cycles += 2; b6_entry_8C00(); return; }
{ _cycpp = (uint16_t)(RD(0x7A) | ((uint16_t)RD((uint16_t)(((0x7A) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0x4C, A);
cycles += 2;
A = Y; setZN(A);
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x08; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
Y = A; setZN(Y);
{ _cycpp = (uint16_t)(RD(0x7A) | ((uint16_t)RD((uint16_t)(((0x7A) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0x4D, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x51) + 1); WR(0x51, _v); setZN(_v); }
nmi_poll("b6_entry_8BE5");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_8C32();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_8BE5");
nmi_poll("b6_entry_8BE5");
cycles += 3;
b7_entry_D2DB(); return;
}
static void __attribute__((used)) b6_entry_8C00(void) {
nmi_poll("b6_entry_8C00");
A = RD(0x47); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x80))) { cycles += 1; b6_L8C08(); return; }
cycles += 2;
A = 0x0F; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_L8C0A(); return; }
b6_L8C08();
return;
}
static void __attribute__((used)) b6_L8C08(void) {
nmi_poll("b6_L8C08");
cycles += 2;
A = 0x80; setZN(A);
b6_L8C0A();
return;
}
static void __attribute__((used)) b6_L8C0A(void) {
nmi_poll("b6_L8C0A");
cycles += 3;
WR(0x47, A);
A = RD(0x50); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x10; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
Y = A; setZN(Y);
{ _cycpp = (uint16_t)(RD(0x7A) | ((uint16_t)RD((uint16_t)(((0x7A) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0x46, A);
cycles += 2;
Y = 0x14; setZN(Y);
{ _cycpp = (uint16_t)(RD(0x7A) | ((uint16_t)RD((uint16_t)(((0x7A) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0x4C, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0x7A) | ((uint16_t)RD((uint16_t)(((0x7A) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0x4D, A);
nmi_poll("b6_L8C0A");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_8C32();
S = (uint8_t)(S + 2);
nmi_poll("b6_L8C0A");
A = RD(0x45); setZN(A);
cycles += 3;
nmi_poll("b6_L8C0A");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_8C4D();
S = (uint8_t)(S + 2);
nmi_poll("b6_L8C0A");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x50, A);
cycles += 3;
WR(0x51, A);
cycles += 4;
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 6;
return;
}
static void b6_entry_8B8A(void) { __builtin_trap(); }
static void b6_entry_8C32(void) { __builtin_trap(); }
static void b6_entry_8C4D(void) { __builtin_trap(); }
