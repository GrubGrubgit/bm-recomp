#include "runtime.h"
static void b5_L8006(void);
static void b5_L802A(void);
static void b5_L806D(void);
static void b5_L8071(void);
static void b5_L8086(void);
static void b5_L80A2(void);
static void b5_L80AC(void);
static void b5_L80DB(void);
static void b5_L80DE(void);
static void b5_L80E1(void);
static void b5_L80E4(void);
static void b5_L80E7(void);
static void b5_L80FA(void);
static void b5_L80FF(void);
static void b5_L810E(void);
static void b5_L8118(void);
static void b5_L8124(void);
static void b5_L812E(void);
static void b5_L8151(void);
static void b5_L8153(void);
static void b5_L8159(void);
static void b5_L815E(void);
static void b5_L817B(void);
static void b5_L8180(void);
static void b5_L8184(void);
static void b5_L819C(void);
static void b5_L81A8(void);
static void b5_L81BC(void);
static void b5_L81C2(void);
static void b5_L81F7(void);
static void b5_L821D(void);
static void b5_L8260(void);
static void b5_L826A(void);
static void b5_L828D(void);
static void b5_L8298(void);
static void b5_L829D(void);
static void b5_L82CA(void);
static void b5_L82CD(void);
static void b5_L82D4(void);
static void b5_L82F6(void);
static void b5_L8303(void);
static void b5_L830E(void);
static void b5_L832A(void);
static void b5_L8342(void);
static void b5_L835B(void);
static void b5_L8394(void);
static void b5_L8395(void);
static void b5_L839A(void);
static void b5_L83A3(void);
static void b5_L83AC(void);
static void b5_L83B5(void);
static void b5_L83D8(void);
static void b5_LBE06(void);
static void b5_LBE16(void);
static void b5_LBE50(void);
static void b5_LBE58(void);
static void b5_LBEA6(void);
static void b5_LBEAF(void);
static void b5_LBEBE(void);
static void b5_LBEC9(void);
static void b5_LBED5(void);
static void b5_LBEE0(void);
static void b5_LBF62(void);
static void b5_LBF75(void);
static void b5_LBF84(void);
static void b5_LBF89(void);
static void b5_entry_8000(void);
static void b5_entry_8012(void);
static void b5_entry_8013(void);
static void b5_entry_8076(void);
static void b5_entry_8077(void);
static void b5_entry_807A(void);
static void b5_entry_8089(void);
static void b5_entry_808C(void);
static void b5_entry_80A9(void);
static void b5_entry_80B6(void);
static void b5_entry_80B8(void);
static void b5_entry_813F(void);
static void b5_entry_827A(void);
static void b5_entry_82CE(void);
static void b5_entry_82F9(void);
static void b5_entry_832D(void);
static void b5_entry_833C(void);
static void b5_entry_835C(void);
static void b5_entry_8376(void);
static void b5_entry_8383(void);
static void b5_entry_BDF6(void);
static void b5_entry_BE17(void);
static void b5_entry_BE23(void);
static void b5_entry_BE34(void);
static void b5_entry_BE36(void);
static void b5_entry_BF52(void);
static void b5_entry_BF86(void);
static void b5_entry_BFE5(void);
static void b5_entry_BFE8(void);
static void b5_entry_BFF1(void);
static void b5_entry_B2C5(void);
static void b7_entry_C063(void);
static void b7_entry_C0A2(void);
static void b7_entry_C0FF(void);
static void b7_entry_C138(void);
static void b7_entry_C17A(void);
static void __attribute__((used)) b5_entry_8000(void) {
nmi_poll("b5_entry_8000");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0xE0, A);
cycles += 2;
X = 0xB4; setZN(X);
b5_L8006();
return;
}
static void __attribute__((used)) b5_L8006(void) {
b5_L8006_top:;
nmi_poll("b5_L8006");
cycles += 2;
X = (uint8_t)(X - 1); setZN(X);
cycles += 5;
WR((uint16_t)(0x0700 + X), A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b5_L8006"); goto b5_L8006_top; }
cycles += 4;
WR(0x4015, A);
nmi_poll("b5_L8006");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_BE17();
S = (uint8_t)(S + 2);
nmi_poll("b5_L8006");
b5_entry_8012();
return;
}
static void __attribute__((used)) b5_entry_8012(void) {
nmi_poll("b5_entry_8012");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_8013(void) {
nmi_poll("b5_entry_8013");
cycles += 3;
WR(0xE9, A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
X = A; setZN(X);
A = RD((uint16_t)(0x84B0 + X)); setZN(A);
cycles += 4 + ((((0x84B0 + X) & 0xFF00) != 0x8400) ? 1 : 0);
cycles += 3;
WR(0xE1, A);
A = RD((uint16_t)(0x84B1 + X)); setZN(A);
cycles += 4 + ((((0x84B1 + X) & 0xFF00) != 0x8400) ? 1 : 0);
cycles += 3;
WR(0xE2, A);
cycles += 2;
A = 0x0F; setZN(A);
cycles += 4;
WR(0x4015, A);
cycles += 2;
Y = 0x00; setZN(Y);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L806D(); return; }
b5_L802A();
return;
}
static void __attribute__((used)) b5_L802A(void) {
nmi_poll("b5_L802A");
cycles += 2;
X = A; setZN(X);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0700 + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0709 + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0712 + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x071B + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0724 + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
A = 0x01; setZN(A);
cycles += 5;
WR((uint16_t)(0x072D + X), A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x0736 + X), A);
cycles += 5;
WR((uint16_t)(0x073F + X), A);
cycles += 5;
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
WR((uint16_t)(0x0787 + X), A);
cycles += 2;
A = X; setZN(A);
cycles += 4;
WR(0x07FF, A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
cycles += 2;
{ uint8_t _m = 0x80; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 5;
WR((uint16_t)(0x0775 + X), A);
b5_L806D();
return;
}
static void __attribute__((used)) b5_L806D(void) {
nmi_poll("b5_L806D");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L802A(); return; }
b5_L8071();
return;
}
static void __attribute__((used)) b5_L8071(void) {
nmi_poll("b5_L8071");
A = RD(0xE9); setZN(A);
cycles += 3;
nmi_poll("b5_L8071");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_BDF6();
S = (uint8_t)(S + 2);
nmi_poll("b5_L8071");
b5_entry_8076();
return;
}
static void __attribute__((used)) b5_entry_8076(void) {
nmi_poll("b5_entry_8076");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_8077(void) {
nmi_poll("b5_entry_8077");
nmi_poll("b5_entry_8077");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_BE23();
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_8077");
b5_entry_807A();
return;
}
static void __attribute__((used)) b5_entry_807A(void) {
nmi_poll("b5_entry_807A");
cycles += 2;
A = 0xFF; setZN(A);
cycles += 3;
WR(0xEA, A);
cycles += 3;
WR(0xEB, A);
cycles += 3;
WR(0xEC, A);
cycles += 3;
WR(0xED, A);
cycles += 2;
X = 0x08; setZN(X);
b5_L8086();
return;
}
static void __attribute__((used)) b5_L8086(void) {
nmi_poll("b5_L8086");
nmi_poll("b5_L8086");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_808C();
S = (uint8_t)(S + 2);
nmi_poll("b5_L8086");
b5_entry_8089();
return;
}
static void __attribute__((used)) b5_entry_8089(void) {
nmi_poll("b5_entry_8089");
cycles += 2;
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8086(); return; }
b5_entry_808C();
return;
}
static void __attribute__((used)) b5_entry_808C(void) {
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0x0724 + X)); setZN(A);
cycles += 4 + ((((0x724 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8071(); return; }
cycles += 3;
WR(0xE2, A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
Y = A; setZN(Y);
A = RD((uint16_t)(0xEA + Y)); setZN(A);
cycles += 4 + ((((0xEA + Y) & 0xFF00) != 0x0) ? 1 : 0);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80A2(); return; }
cycles += 4;
WR((uint16_t)(0xEA + Y), X);
cycles += 2;
A = 0xFF; setZN(A);
b5_L80A2();
return;
}
static void __attribute__((used)) b5_L80A2(void) {
nmi_poll("b5_L80A2");
cycles += 3;
WR(0xE4, A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80AC(); return; }
nmi_poll("b5_L80A2");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_82CE();
S = (uint8_t)(S + 2);
nmi_poll("b5_L80A2");
b5_entry_80A9();
return;
}
static void __attribute__((used)) b5_entry_80A9(void) {
nmi_poll("b5_entry_80A9");
nmi_poll("b5_entry_80A9");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_835C();
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_80A9");
b5_L80AC();
return;
}
static void __attribute__((used)) b5_L80AC(void) {
nmi_poll("b5_L80AC");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x072D + X)) - 1); WR((uint16_t)(0x072D + X), _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8071(); return; }
A = RD((uint16_t)(0x071B + X)); setZN(A);
cycles += 4 + ((((0x71B + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 3;
WR(0xE1, A);
b5_entry_80B6();
return;
}
static void __attribute__((used)) b5_entry_80B6(void) {
nmi_poll("b5_entry_80B6");
cycles += 2;
Y = 0x00; setZN(Y);
b5_entry_80B8();
return;
}
static void __attribute__((used)) b5_entry_80B8(void) {
nmi_poll("b5_entry_80B8");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DB(); return; }
cycles += 2;
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E7(); return; }
cycles += 2;
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80FF(); return; }
cycles += 2;
{ uint8_t _m = 0xD0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DE(); return; }
cycles += 2;
{ uint8_t _m = 0xE0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E1(); return; }
cycles += 2;
{ uint8_t _m = 0xF0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E4(); return; }
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x0724 + X), A);
nmi_poll("b5_entry_80B8");
cycles += 3;
b5_entry_827A(); return;
}
static void __attribute__((used)) b5_L80DB(void) {
nmi_poll("b5_L80DB");
nmi_poll("b5_L80DB");
cycles += 3;
b5_L821D(); return;
}
static void __attribute__((used)) b5_L80DE(void) {
nmi_poll("b5_L80DE");
nmi_poll("b5_L80DE");
cycles += 3;
b5_entry_813F(); return;
}
static void __attribute__((used)) b5_L80E1(void) {
nmi_poll("b5_L80E1");
nmi_poll("b5_L80E1");
cycles += 3;
b5_L819C(); return;
}
static void __attribute__((used)) b5_L80E4(void) {
nmi_poll("b5_L80E4");
nmi_poll("b5_L80E4");
cycles += 3;
b5_L81C2(); return;
}
static void __attribute__((used)) b5_L80E7(void) {
nmi_poll("b5_L80E7");
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0700 + X), A);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L80FA(); return; }
cycles += 5;
WR((uint16_t)(0x0709 + X), A);
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
b5_L80FA();
return;
}
static void __attribute__((used)) b5_L80FA(void) {
nmi_poll("b5_L80FA");
cycles += 5;
WR((uint16_t)(0x0712 + X), A);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
b5_L80FF();
return;
}
static void __attribute__((used)) b5_L80FF(void) {
nmi_poll("b5_L80FF");
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8118(); return; }
A = RD((uint16_t)(0x0736 + X)); setZN(A);
cycles += 4 + ((((0x736 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L810E(); return; }
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0736 + X), A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
b5_L810E();
return;
}
static void __attribute__((used)) b5_L810E(void) {
nmi_poll("b5_L810E");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0736 + X)) - 1); WR((uint16_t)(0x0736 + X), _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
b5_L8118();
return;
}
static void __attribute__((used)) b5_L8118(void) {
nmi_poll("b5_L8118");
A = RD((uint16_t)(0x073F + X)); setZN(A);
cycles += 4 + ((((0x73F + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8124(); return; }
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x073F + X), A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
b5_L8124();
return;
}
static void __attribute__((used)) b5_L8124(void) {
nmi_poll("b5_L8124");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x073F + X)) - 1); WR((uint16_t)(0x073F + X), _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
b5_L812E();
return;
}
static void __attribute__((used)) b5_L812E(void) {
nmi_poll("b5_L812E");
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xE3, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xE2, A);
A = RD(0xE3); setZN(A);
cycles += 3;
cycles += 3;
WR(0xE1, A);
nmi_poll("b5_L812E");
cycles += 3;
b5_entry_80B6(); return;
}
static void __attribute__((used)) b5_entry_813F(void) {
nmi_poll("b5_entry_813F");
cycles += 2;
{ uint8_t _m = 0xC2; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L815E(); return; }
cycles += 2;
{ uint8_t _m = 0xC3; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8159(); return; }
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L8151(); return; }
cycles += 2;
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8153(); return; }
b5_L8151();
return;
}
static void __attribute__((used)) b5_L8151(void) {
nmi_poll("b5_L8151");
cycles += 2;
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
b5_L8153();
return;
}
static void __attribute__((used)) b5_L8153(void) {
nmi_poll("b5_L8153");
cycles += 5;
WR((uint16_t)(0x0700 + X), A);
nmi_poll("b5_L8153");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L8159(void) {
nmi_poll("b5_L8159");
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0xE0) + 1); WR(0xE0, _v); setZN(_v); }
nmi_poll("b5_L8159");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L815E(void) {
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x80; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0787 + X), A);
cycles += 2;
{ uint8_t _m = 0x80; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L817B(); return; }
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8184(); return; }
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0751 + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x076C + X), A);
b5_L817B();
return;
}
static void __attribute__((used)) b5_L817B(void) {
nmi_poll("b5_L817B");
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x0763 + X), A);
b5_L8180();
return;
}
static void __attribute__((used)) b5_L8180(void) {
nmi_poll("b5_L8180");
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
nmi_poll("b5_L8180");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L8184(void) {
nmi_poll("b5_L8184");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A | _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
WR((uint16_t)(0x076C + X), A);
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0763 + X), A);
cycles += 2;
A = 0x00; setZN(A);
nmi_poll("b5_L8184");
cycles += 3;
b5_L8180(); return;
}
static void __attribute__((used)) b5_L819C(void) {
nmi_poll("b5_L819C");
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81BC(); return; }
cycles += 2;
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L81A8(); return; }
cycles += 2;
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
b5_L81A8();
return;
}
static void __attribute__((used)) b5_L81A8(void) {
nmi_poll("b5_L81A8");
cycles += 5;
WR((uint16_t)(0x0748 + X), A);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 5;
WR((uint16_t)(0x07AB + X), A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x07A2 + X), A);
cycles += 5;
WR((uint16_t)(0x0799 + X), A);
nmi_poll("b5_L81A8");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L81BC(void) {
nmi_poll("b5_L81BC");
cycles += 5;
WR((uint16_t)(0x075A + X), A);
nmi_poll("b5_L81BC");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L81C2(void) {
nmi_poll("b5_L81C2");
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81F7(); return; }
cycles += 2;
A = Y; setZN(A);
cycles += 3;
stk[S] = A; S = (uint8_t)(S - 1);
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 3;
WR(0xE5, A);
cycles += 2;
A = 0x01; setZN(A);
cycles += 3;
WR(0xE6, A);
A = RD(0xE1); setZN(A);
cycles += 3;
cycles += 2;
Y = 0x00; setZN(Y);
cycles += 6;
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
A = RD(0xE2); setZN(A);
cycles += 3;
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 6;
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 4;
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 6;
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 2;
Y = A; setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 3;
stk[S] = A; S = (uint8_t)(S - 1);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xE2, A);
cycles += 4;
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 3;
WR(0xE1, A);
nmi_poll("b5_L81C2");
cycles += 3;
b5_entry_80B6(); return;
}
static void __attribute__((used)) b5_L81F7(void) {
nmi_poll("b5_L81F7");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 3;
WR(0xE5, A);
cycles += 2;
A = 0x01; setZN(A);
cycles += 3;
WR(0xE6, A);
cycles += 2;
Y = 0x00; setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xE1, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xE2, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
nmi_poll("b5_L81F7");
cycles += 3;
b5_entry_80B8(); return;
}
static void __attribute__((used)) b5_L821D(void) {
nmi_poll("b5_L821D");
cycles += 3;
WR(0xE3, A);
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x072D + X), A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
A = Y; setZN(A);
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 5;
WR((uint16_t)(0x071B + X), A);
A = RD(0xE2); setZN(A);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 5;
WR((uint16_t)(0x0724 + X), A);
A = RD(0xE4); setZN(A);
cycles += 3;
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8298(); return; }
A = RD(0xE3); setZN(A);
cycles += 3;
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_entry_827A(); return; }
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
Y = A; setZN(Y);
A = RD((uint16_t)(0x83EE + Y)); setZN(A);
cycles += 4 + ((((0x83EE + Y) & 0xFF00) != 0x8300) ? 1 : 0);
cycles += 3;
WR(0xE1, A);
cycles += 5;
WR((uint16_t)(0x0790 + X), A);
A = RD((uint16_t)(0x83EF + Y)); setZN(A);
cycles += 4 + ((((0x83EF + Y) & 0xFF00) != 0x8300) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x08; A = (uint8_t)(A | _m); setZN(A); }
cycles += 3;
WR(0xE2, A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8260(); return; }
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x4000 + Y), A);
A = RD((uint16_t)(0x0712 + X)); setZN(A);
cycles += 4 + ((((0x712 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x4001 + Y), A);
b5_L8260();
return;
}
static void __attribute__((used)) b5_L8260(void) {
nmi_poll("b5_L8260");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L826A(); return; }
A = RD(0xE2); setZN(A);
cycles += 3;
cycles += 5;
WR((uint16_t)(0x4003 + Y), A);
b5_L826A();
return;
}
static void __attribute__((used)) b5_L826A(void) {
nmi_poll("b5_L826A");
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 5;
WR((uint16_t)(0x4002 + Y), A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x40; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L829D(); return; }
b5_entry_827A();
return;
}
static void __attribute__((used)) b5_entry_827A(void) {
nmi_poll("b5_entry_827A");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
Y = A; setZN(Y);
cycles += 2;
A = 0x10; setZN(A);
cycles += 2;
{ uint8_t _m = 0x08; uint8_t _r = (uint8_t)(Y - _m); P = (uint8_t)((P & 0x7C) | (Y >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L828D(); return; }
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x4000 + Y), A);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8298(); return; }
b5_L828D();
return;
}
static void __attribute__((used)) b5_L828D(void) {
nmi_poll("b5_L828D");
cycles += 5;
WR((uint16_t)(0x4000 + Y), A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 5;
WR((uint16_t)(0x4001 + Y), A);
cycles += 5;
WR((uint16_t)(0x4002 + Y), A);
b5_L8298();
return;
}
static void __attribute__((used)) b5_L8298(void) {
nmi_poll("b5_L8298");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
b5_L829D();
return;
}
static void __attribute__((used)) b5_L829D(void) {
nmi_poll("b5_L829D");
cycles += 5;
WR((uint16_t)(0x0700 + X), A);
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82CD(); return; }
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L82CD(); return; }
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L82CD(); return; }
cycles += 2;
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0787 + X), A);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0763 + X), A);
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82CA(); return; }
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x076C + X), A);
cycles += 3;
WR(0xE7, A);
b5_L82CA();
return;
}
static void __attribute__((used)) b5_L82CA(void) {
nmi_poll("b5_L82CA");
nmi_poll("b5_L82CA");
cycles += 3;
b5_entry_8383(); return;
}
static void __attribute__((used)) b5_L82CD(void) {
nmi_poll("b5_L82CD");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_82CE(void) {
nmi_poll("b5_entry_82CE");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82D4(); return; }
cycles += 6;
return;
}
static void __attribute__((used)) b5_L82D4(void) {
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x07A2 + X)); setZN(A);
cycles += 4 + ((((0x7A2 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L8342(); return; }
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L830E(); return; }
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82F6(); return; }
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0799 + X), A);
nmi_poll("b5_L82D4");
cycles += 3;
b5_entry_82F9(); return;
}
static void __attribute__((used)) b5_L82F6(void) {
nmi_poll("b5_L82F6");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) + 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
b5_entry_82F9();
return;
}
static void __attribute__((used)) b5_entry_82F9(void) {
nmi_poll("b5_entry_82F9");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_entry_833C(); return; }
b5_L8303();
return;
}
static void __attribute__((used)) b5_L8303(void) {
nmi_poll("b5_L8303");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x40; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0748 + X), A);
nmi_poll("b5_L8303");
cycles += 3;
b5_entry_833C(); return;
}
static void __attribute__((used)) b5_L830E(void) {
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L832A(); return; }
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 4;
WR(0x07FF, A);
A = RD((uint16_t)(0x0799 + X)); setZN(A);
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)(P | 0x01);
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
cycles += 5;
WR((uint16_t)(0x0799 + X), A);
nmi_poll("b5_L830E");
cycles += 3;
b5_entry_832D(); return;
}
static void __attribute__((used)) b5_L832A(void) {
nmi_poll("b5_L832A");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) - 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
b5_entry_832D();
return;
}
static void __attribute__((used)) b5_entry_832D(void) {
nmi_poll("b5_entry_832D");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8303(); return; }
b5_entry_833C();
return;
}
static void __attribute__((used)) b5_entry_833C(void) {
nmi_poll("b5_entry_833C");
A = RD((uint16_t)(0x07AB + X)); setZN(A);
cycles += 4 + ((((0x7AB + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x07A2 + X), A);
b5_L8342();
return;
}
static void __attribute__((used)) b5_L8342(void) {
nmi_poll("b5_L8342");
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x07A2 + X)) - 1); WR((uint16_t)(0x07A2 + X), _v); setZN(_v); }
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
Y = A; setZN(Y);
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD((uint16_t)(0x0790 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x790 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x4002 + Y), A);
b5_L835B();
return;
}
static void __attribute__((used)) b5_L835B(void) {
nmi_poll("b5_L835B");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_835C(void) {
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L835B(); return; }
cycles += 2;
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L835B(); return; }
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83AC(); return; }
A = RD((uint16_t)(0x0751 + X)); setZN(A);
cycles += 4 + ((((0x751 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 3;
WR(0xE7, A);
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 3;
WR(0xE8, A);
b5_entry_8376();
return;
}
static void __attribute__((used)) b5_entry_8376(void) {
nmi_poll("b5_entry_8376");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
Y = A; setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8395(); return; }
cycles += 3;
WR(0xE7, A);
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) + 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
b5_entry_8383();
return;
}
static void __attribute__((used)) b5_entry_8383(void) {
nmi_poll("b5_entry_8383");
A = RD(0xE4); setZN(A);
cycles += 3;
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8394(); return; }
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
Y = A; setZN(Y);
A = RD(0xE7); setZN(A);
cycles += 3;
cycles += 5;
WR((uint16_t)(0x4000 + Y), A);
b5_L8394();
return;
}
static void __attribute__((used)) b5_L8394(void) {
nmi_poll("b5_L8394");
cycles += 6;
return;
}
static void __attribute__((used)) b5_L8395(void) {
nmi_poll("b5_L8395");
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L83A3(); return; }
b5_L839A();
return;
}
static void __attribute__((used)) b5_L839A(void) {
nmi_poll("b5_L839A");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x20; A = (uint8_t)(A | _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0787 + X), A);
cycles += 6;
return;
}
static void __attribute__((used)) b5_L83A3(void) {
nmi_poll("b5_L83A3");
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 5;
WR((uint16_t)(0x0763 + X), A);
nmi_poll("b5_L83A3");
cycles += 3;
b5_entry_8376(); return;
}
static void __attribute__((used)) b5_L83AC(void) {
nmi_poll("b5_L83AC");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L83B5(); return; }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) - 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
cycles += 6;
return;
}
static void __attribute__((used)) b5_L83B5(void) {
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 5;
WR((uint16_t)(0x0763 + X), A);
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83D8(); return; }
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) - 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 3;
WR(0xE7, A);
nmi_poll("b5_L83B5");
cycles += 3;
b5_entry_8383(); return;
}
static void __attribute__((used)) b5_L83D8(void) {
nmi_poll("b5_L83D8");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
{ uint8_t _m = 0x0F; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
cycles += 7;
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) + 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
cycles += 2;
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 3;
WR(0xE7, A);
nmi_poll("b5_L83D8");
cycles += 3;
b5_entry_8383(); return;
}
static void __attribute__((used)) b5_entry_BDF6(void) {
nmi_poll("b5_entry_BDF6");
cycles += 2;
{ uint8_t _m = 0x54; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_LBE16(); return; }
A = RD(0xBDBC); setZN(A);
cycles += 4;
cycles += 4;
WR(0x07F0, A);
A = RD(0xBDBD); setZN(A);
cycles += 4;
cycles += 4;
WR(0x07F1, A);
b5_LBE06();
return;
}
static void __attribute__((used)) b5_LBE06(void) {
nmi_poll("b5_LBE06");
cycles += 2;
A = 0x01; setZN(A);
cycles += 4;
WR(0x07F2, A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 4;
WR(0x07F3, A);
cycles += 4;
WR(0x07F4, A);
cycles += 4;
WR(0x07F5, A);
b5_LBE16();
return;
}
static void __attribute__((used)) b5_LBE16(void) {
nmi_poll("b5_LBE16");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_BE17(void) {
nmi_poll("b5_entry_BE17");
cycles += 2;
A = 0x00; setZN(A);
cycles += 4;
WR(0x07F1, A);
cycles += 2;
A = 0x0F; setZN(A);
cycles += 4;
WR(0x4015, A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE06(); return; }
b5_entry_BE23();
return;
}
static void __attribute__((used)) b5_entry_BE23(void) {
nmi_poll("b5_entry_BE23");
A = RD(0x07F1); setZN(A);
cycles += 4;
cycles += 3;
WR(0xBE, A);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBE16(); return; }
cycles += 6;
{ uint8_t _v = (uint8_t)(RD(0x07F2) - 1); WR(0x07F2, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE16(); return; }
A = RD(0x07F0); setZN(A);
cycles += 4;
cycles += 3;
WR(0xBD, A);
b5_entry_BE34();
return;
}
static void __attribute__((used)) b5_entry_BE34(void) {
nmi_poll("b5_entry_BE34");
cycles += 2;
Y = 0x00; setZN(Y);
b5_entry_BE36();
return;
}
static void __attribute__((used)) b5_entry_BE36(void) {
nmi_poll("b5_entry_BE36");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE58(); return; }
cycles += 2;
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE50(); return; }
cycles += 2;
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBEAF(); return; }
cycles += 2;
A = 0x0F; setZN(A);
cycles += 4;
WR(0x4015, A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 4;
WR(0x07F1, A);
cycles += 6;
return;
}
static void __attribute__((used)) b5_LBE50(void) {
nmi_poll("b5_LBE50");
A = RD(0x07F5); setZN(A);
cycles += 4;
cycles += 2;
{ uint8_t _m = 0x01; A = (uint8_t)(A | _m); setZN(A); }
cycles += 4;
WR(0x07F5, A);
b5_LBE58();
return;
}
static void __attribute__((used)) b5_LBE58(void) {
nmi_poll("b5_LBE58");
cycles += 3;
WR(0xBF, A);
cycles += 2;
A = 0x0F; setZN(A);
cycles += 4;
WR(0x4015, A);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x07F2, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
P = (uint8_t)(P & 0xFE);
cycles += 2;
A = Y; setZN(A);
{ uint8_t _m = RD(0xBD); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 4;
WR(0x07F0, A);
A = RD(0xBE); setZN(A);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
WR(0x07F1, A);
A = RD(0x07F5); setZN(A);
cycles += 4;
cycles += 2;
{ uint8_t _m = 0x01; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEA6(); return; }
A = RD(0xBF); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
X = A; setZN(X);
A = RD((uint16_t)(0xBDBE + X)); setZN(A);
cycles += 4 + ((((0xBDBE + X) & 0xFF00) != 0xBD00) ? 1 : 0);
cycles += 3;
WR(0xBD, A);
A = RD((uint16_t)(0xBDBF + X)); setZN(A);
cycles += 4 + ((((0xBDBF + X) & 0xFF00) != 0xBD00) ? 1 : 0);
cycles += 3;
WR(0xBE, A);
cycles += 2;
Y = 0x00; setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x4010, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x4011, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x4012, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x4013, A);
cycles += 2;
A = 0x1F; setZN(A);
cycles += 4;
WR(0x4015, A);
b5_LBEA6();
return;
}
static void __attribute__((used)) b5_LBEA6(void) {
nmi_poll("b5_LBEA6");
A = RD(0x07F5); setZN(A);
cycles += 4;
cycles += 2;
{ uint8_t _m = 0xFE; A = (uint8_t)(A & _m); setZN(A); }
cycles += 4;
WR(0x07F5, A);
cycles += 6;
return;
}
static void __attribute__((used)) b5_LBEAF(void) {
nmi_poll("b5_LBEAF");
cycles += 2;
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_LBEC9(); return; }
A = RD(0x07F3); setZN(A);
cycles += 4;
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEBE(); return; }
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x07F3, A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
b5_LBEBE();
return;
}
static void __attribute__((used)) b5_LBEBE(void) {
nmi_poll("b5_LBEBE");
cycles += 6;
{ uint8_t _v = (uint8_t)(RD(0x07F3) - 1); WR(0x07F3, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
nmi_poll("b5_LBEBE");
cycles += 3;
b5_entry_BE36(); return;
}
static void __attribute__((used)) b5_LBEC9(void) {
nmi_poll("b5_LBEC9");
A = RD(0x07F4); setZN(A);
cycles += 4;
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBED5(); return; }
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 4;
WR(0x07F4, A);
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
b5_LBED5();
return;
}
static void __attribute__((used)) b5_LBED5(void) {
nmi_poll("b5_LBED5");
cycles += 6;
{ uint8_t _v = (uint8_t)(RD(0x07F4) - 1); WR(0x07F4, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
nmi_poll("b5_LBED5");
cycles += 3;
b5_entry_BE36(); return;
}
static void __attribute__((used)) b5_LBEE0(void) {
nmi_poll("b5_LBEE0");
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xBF, A);
cycles += 2;
Y = (uint8_t)(Y + 1); setZN(Y);
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
cycles += 3;
WR(0xBE, A);
A = RD(0xBF); setZN(A);
cycles += 3;
cycles += 3;
WR(0xBD, A);
nmi_poll("b5_LBEE0");
cycles += 3;
b5_entry_BE34(); return;
}
static void __attribute__((used)) b5_entry_BF52(void) {
nmi_poll("b5_entry_BF52");
cycles += 2;
A = 0x10; setZN(A);
cycles += 3;
WR(0x40, A);
cycles += 2;
A = 0x10; setZN(A);
cycles += 3;
WR(0x41, A);
nmi_poll("b5_entry_BF52");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_BF52");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBF62(); return; }
nmi_poll("b5_entry_BF52");
cycles += 3;
b7_entry_C17A(); return;
}
static void __attribute__((used)) b5_LBF62(void) {
nmi_poll("b5_LBF62");
cycles += 2;
A = 0x0F; setZN(A);
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
b5_entry_B2C5();
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C138();
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0A2();
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF75(); return; }
A = RD(0x11); setZN(A);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF89(); return; }
b5_LBF75();
return;
}
static void __attribute__((used)) b5_LBF75(void) {
nmi_poll("b5_LBF75");
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x44, A);
A = RD(0x11); setZN(A);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF84(); return; }
cycles += 2;
A = 0x46; setZN(A);
nmi_poll("b5_LBF75");
cycles += 3;
b5_entry_BF86(); return;
}
static void __attribute__((used)) b5_LBF84(void) {
nmi_poll("b5_LBF84");
cycles += 2;
A = 0x47; setZN(A);
b5_entry_BF86();
return;
}
static void __attribute__((used)) b5_entry_BF86(void) {
nmi_poll("b5_entry_BF86");
nmi_poll("b5_entry_BF86");
cycles += 3;
b7_entry_C063(); return;
}
static void __attribute__((used)) b5_LBF89(void) {
nmi_poll("b5_LBF89");
cycles += 6;
return;
}
static void __attribute__((used)) b5_entry_BFE5(void) {
nmi_poll("b5_entry_BFE5");
nmi_poll("b5_entry_BFE5");
cycles += 3;
b5_entry_8000(); return;
}
static void __attribute__((used)) b5_entry_BFE8(void) {
nmi_poll("b5_entry_BFE8");
nmi_poll("b5_entry_BFE8");
cycles += 3;
b5_entry_8013(); return;
}
static void __attribute__((used)) b5_entry_BFF1(void) {
nmi_poll("b5_entry_BFF1");
nmi_poll("b5_entry_BFF1");
cycles += 3;
b5_entry_8077(); return;
}
static void b5_entry_B2C5(void) { __builtin_trap(); }
