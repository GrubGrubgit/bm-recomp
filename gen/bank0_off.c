#include "runtime.h"
static void b0_LBDA9(void);
static void b0_LBDBA(void);
static void b0_LBDCF(void);
static void b0_LBDDA(void);
static void b0_LBE1A(void);
static void b0_LBE31(void);
static void b0_LBEA1(void);
static void b0_LBEC3(void);
static void b0_LBEE7(void);
static void b0_LBF5E(void);
static void b0_LBF71(void);
static void b0_LBF80(void);
static void b0_LBF85(void);
static void b0_entry_BD99(void);
static void b0_entry_BDDC(void);
static void b0_entry_BE0A(void);
static void b0_entry_BE3A(void);
static void b0_entry_BE91(void);
static void b0_entry_BF4E(void);
static void b0_entry_BF82(void);
static void b0_L93BB(void);
static void b0_LB2C1(void);
static void b0_LB2F3(void);
static void b0_LB310(void);
static void b7_entry_C063(void);
static void b7_entry_C0A2(void);
static void b7_entry_C0FF(void);
static void b7_entry_C105(void);
static void b7_entry_C138(void);
static void b7_entry_C13E(void);
static void b7_entry_C144(void);
static void b7_entry_C17A(void);
static void b7_entry_C1AD(void);
static void b7_entry_C1B3(void);
static void b7_entry_C1B6(void);
static void __attribute__((used)) b0_entry_BD99(void) {
nmi_poll("b0_entry_BD99");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BD99");
WR(0x40, A);
cycles += 3;
nmi_poll("b0_entry_BD99");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BD99");
WR(0x41, A);
cycles += 3;
nmi_poll("b0_entry_BD99");
nmi_poll("b0_entry_BD99");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b0_entry_BD99");
nmi_poll("b0_entry_BD99");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBDA9(); return; }
nmi_poll("b0_entry_BD99");
nmi_poll("b0_entry_BD99");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b0_entry_BD99");
}
static void __attribute__((used)) b0_LBDA9(void) {
nmi_poll("b0_LBDA9");
A = 0x0D; setZN(A);
cycles += 2;
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
cycles += 6;
S = (uint8_t)(S - 2);
b0_LB310();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
Y = 0x01; setZN(Y);
cycles += 2;
nmi_poll("b0_LBDA9");
{ _cycpp = (uint16_t)(RD(0xA3) | ((uint16_t)RD((uint16_t)(((0xA3) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C144();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBDBA(); return; }
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
cycles += 6;
S = (uint8_t)(S - 2);
b0_entry_BE3A();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBDA9");
nmi_poll("b0_LBDA9");
b0_LBDBA();
return;
}
static void __attribute__((used)) b0_LBDBA(void) {
nmi_poll("b0_LBDBA");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b0_LBDBA");
WR(0x44, A);
cycles += 3;
nmi_poll("b0_LBDBA");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b0_LBDBA");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBDBA");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBDCF(); return; }
nmi_poll("b0_LBDBA");
nmi_poll("b0_LBDBA");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1B3();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBDBA");
nmi_poll("b0_LBDBA");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBDBA");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBDCF(); return; }
nmi_poll("b0_LBDBA");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_LBDBA");
WR(0x52, A);
cycles += 3;
nmi_poll("b0_LBDBA");
b0_LBDCF();
return;
}
static void __attribute__((used)) b0_LBDCF(void) {
nmi_poll("b0_LBDCF");
A = RD(0x52); setZN(A);
cycles += 3;
nmi_poll("b0_LBDCF");
{ uint8_t _m = 0x05; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBDCF");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBDDA(); return; }
nmi_poll("b0_LBDCF");
A = 0x3A; setZN(A);
cycles += 2;
nmi_poll("b0_LBDCF");
nmi_poll("b0_LBDCF");
cycles += 3;
b0_entry_BDDC(); return;
nmi_poll("b0_LBDCF");
}
static void __attribute__((used)) b0_LBDDA(void) {
nmi_poll("b0_LBDDA");
A = 0x39; setZN(A);
cycles += 2;
nmi_poll("b0_LBDDA");
b0_entry_BDDC();
return;
}
static void __attribute__((used)) b0_entry_BDDC(void) {
nmi_poll("b0_entry_BDDC");
nmi_poll("b0_entry_BDDC");
cycles += 3;
b7_entry_C063(); return;
nmi_poll("b0_entry_BDDC");
}
static void __attribute__((used)) b0_entry_BE0A(void) {
nmi_poll("b0_entry_BE0A");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE0A");
WR(0x40, A);
cycles += 3;
nmi_poll("b0_entry_BE0A");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE0A");
WR(0x41, A);
cycles += 3;
nmi_poll("b0_entry_BE0A");
nmi_poll("b0_entry_BE0A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b0_entry_BE0A");
nmi_poll("b0_entry_BE0A");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBE1A(); return; }
nmi_poll("b0_entry_BE0A");
nmi_poll("b0_entry_BE0A");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b0_entry_BE0A");
}
static void __attribute__((used)) b0_LBE1A(void) {
nmi_poll("b0_LBE1A");
A = 0x0D; setZN(A);
cycles += 2;
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
cycles += 6;
S = (uint8_t)(S - 2);
b0_LB310();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
Y = 0x01; setZN(Y);
cycles += 2;
nmi_poll("b0_LBE1A");
{ _cycpp = (uint16_t)(RD(0xA3) | ((uint16_t)RD((uint16_t)(((0xA3) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C144();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b0_LBE1A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBE31(); return; }
nmi_poll("b0_LBE1A");
A = RD(0x53); setZN(A);
cycles += 3;
nmi_poll("b0_LBE1A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBE31(); return; }
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
cycles += 6;
S = (uint8_t)(S - 2);
b0_LB2F3();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBE1A");
nmi_poll("b0_LBE1A");
b0_LBE31();
return;
}
static void __attribute__((used)) b0_LBE31(void) {
nmi_poll("b0_LBE31");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b0_LBE31");
WR(0x44, A);
cycles += 3;
nmi_poll("b0_LBE31");
A = 0x39; setZN(A);
cycles += 2;
nmi_poll("b0_LBE31");
nmi_poll("b0_LBE31");
cycles += 3;
b7_entry_C063(); return;
nmi_poll("b0_LBE31");
}
static void __attribute__((used)) b0_entry_BE3A(void) {
nmi_poll("b0_entry_BE3A");
nmi_poll("b0_entry_BE3A");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C105();
S = (uint8_t)(S + 2);
nmi_poll("b0_entry_BE3A");
nmi_poll("b0_entry_BE3A");
X = A; setZN(X);
cycles += 2;
nmi_poll("b0_entry_BE3A");
A = RD((uint16_t)(0xBDDF + X)); setZN(A);
cycles += 4 + ((((0xBDDF + X) & 0xFF00) != 0xBD00) ? 1 : 0);
nmi_poll("b0_entry_BE3A");
WR(0x50, A);
cycles += 3;
nmi_poll("b0_entry_BE3A");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE3A");
WR(0x51, A);
cycles += 3;
nmi_poll("b0_entry_BE3A");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE3A");
WR(0x52, A);
cycles += 3;
nmi_poll("b0_entry_BE3A");
A = 0x43; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE3A");
WR(0x46, A);
cycles += 3;
nmi_poll("b0_entry_BE3A");
cycles += 6;
return;
nmi_poll("b0_entry_BE3A");
}
static void __attribute__((used)) b0_entry_BE91(void) {
nmi_poll("b0_entry_BE91");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE91");
WR(0x40, A);
cycles += 3;
nmi_poll("b0_entry_BE91");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BE91");
WR(0x41, A);
cycles += 3;
nmi_poll("b0_entry_BE91");
nmi_poll("b0_entry_BE91");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b0_entry_BE91");
nmi_poll("b0_entry_BE91");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBEA1(); return; }
nmi_poll("b0_entry_BE91");
nmi_poll("b0_entry_BE91");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b0_entry_BE91");
}
static void __attribute__((used)) b0_LBEA1(void) {
nmi_poll("b0_LBEA1");
A = 0x0E; setZN(A);
cycles += 2;
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
cycles += 6;
S = (uint8_t)(S - 2);
b0_LB2C1();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b0_LBEA1");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b0_LBEA1");
{ uint8_t _m = 0x08; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b0_LBEA1");
WR(0x3F, A);
cycles += 3;
nmi_poll("b0_LBEA1");
A = 0x11; setZN(A);
cycles += 2;
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C13E();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
{ uint8_t _m = 0x24; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBEA1");
{ uint8_t _m = 0x04; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b0_LBEA1");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBEC3(); return; }
nmi_poll("b0_LBEA1");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b0_LBEA1");
WR(0x44, A);
cycles += 3;
nmi_poll("b0_LBEA1");
A = 0x4C; setZN(A);
cycles += 2;
nmi_poll("b0_LBEA1");
WR(0x45, A);
cycles += 3;
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1AD();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBEA1");
nmi_poll("b0_LBEA1");
b0_LBEC3();
return;
}
static void __attribute__((used)) b0_LBEC3(void) {
nmi_poll("b0_LBEC3");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b0_LBEC3");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b0_LBEC3");
{ uint8_t _m = 0x12; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b0_LBEC3");
WR(0x3F, A);
cycles += 3;
nmi_poll("b0_LBEC3");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b0_LBEC3");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b0_LBEC3");
Y = 0x06; setZN(Y);
cycles += 2;
nmi_poll("b0_LBEC3");
nmi_poll("b0_LBEC3");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1B6();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBEC3");
nmi_poll("b0_LBEC3");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b0_LBEC3");
{ uint8_t _m = RD(0x3F); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b0_LBEC3");
WR(0x3F, A);
cycles += 3;
nmi_poll("b0_LBEC3");
nmi_poll("b0_LBEC3");
cycles += 6;
S = (uint8_t)(S - 2);
b0_L93BB();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBEC3");
nmi_poll("b0_LBEC3");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b0_LBEC3");
WR(0x44, A);
cycles += 3;
nmi_poll("b0_LBEC3");
X = 0x25; setZN(X);
cycles += 2;
nmi_poll("b0_LBEC3");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b0_LBEC3");
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBEC3");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBEE7(); return; }
nmi_poll("b0_LBEC3");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_poll("b0_LBEC3");
b0_LBEE7();
return;
}
static void __attribute__((used)) b0_LBEE7(void) {
nmi_poll("b0_LBEE7");
A = X; setZN(A);
cycles += 2;
nmi_poll("b0_LBEE7");
nmi_poll("b0_LBEE7");
cycles += 3;
b7_entry_C063(); return;
nmi_poll("b0_LBEE7");
}
static void __attribute__((used)) b0_entry_BF4E(void) {
nmi_poll("b0_entry_BF4E");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BF4E");
WR(0x40, A);
cycles += 3;
nmi_poll("b0_entry_BF4E");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b0_entry_BF4E");
WR(0x41, A);
cycles += 3;
nmi_poll("b0_entry_BF4E");
nmi_poll("b0_entry_BF4E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b0_entry_BF4E");
nmi_poll("b0_entry_BF4E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b0_LBF5E(); return; }
nmi_poll("b0_entry_BF4E");
nmi_poll("b0_entry_BF4E");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b0_entry_BF4E");
}
static void __attribute__((used)) b0_LBF5E(void) {
nmi_poll("b0_LBF5E");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
cycles += 6;
S = (uint8_t)(S - 2);
b0_LB2C1();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C138();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0A2();
S = (uint8_t)(S + 2);
nmi_poll("b0_LBF5E");
nmi_poll("b0_LBF5E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBF71(); return; }
nmi_poll("b0_LBF5E");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b0_LBF5E");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBF5E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBF85(); return; }
nmi_poll("b0_LBF5E");
b0_LBF71();
return;
}
static void __attribute__((used)) b0_LBF71(void) {
nmi_poll("b0_LBF71");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b0_LBF71");
WR(0x44, A);
cycles += 3;
nmi_poll("b0_LBF71");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b0_LBF71");
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b0_LBF71");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b0_LBF80(); return; }
nmi_poll("b0_LBF71");
A = 0x46; setZN(A);
cycles += 2;
nmi_poll("b0_LBF71");
nmi_poll("b0_LBF71");
cycles += 3;
b0_entry_BF82(); return;
nmi_poll("b0_LBF71");
}
static void __attribute__((used)) b0_LBF80(void) {
nmi_poll("b0_LBF80");
A = 0x47; setZN(A);
cycles += 2;
nmi_poll("b0_LBF80");
b0_entry_BF82();
return;
}
static void __attribute__((used)) b0_entry_BF82(void) {
nmi_poll("b0_entry_BF82");
nmi_poll("b0_entry_BF82");
cycles += 3;
b7_entry_C063(); return;
nmi_poll("b0_entry_BF82");
}
static void __attribute__((used)) b0_LBF85(void) {
nmi_poll("b0_LBF85");
cycles += 6;
return;
nmi_poll("b0_LBF85");
}
static void b0_L93BB(void) { __builtin_trap(); }
static void b0_LB2C1(void) { __builtin_trap(); }
static void b0_LB2F3(void) { __builtin_trap(); }
static void b0_LB310(void) { __builtin_trap(); }
