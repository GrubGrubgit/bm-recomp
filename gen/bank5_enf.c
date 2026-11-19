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
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_entry_8000");
WR(0xE0, A);
cycles += 3;
nmi_poll("b5_entry_8000");
X = 0xB4; setZN(X);
cycles += 2;
nmi_poll("b5_entry_8000");
b5_L8006();
return;
}
static void __attribute__((used)) b5_L8006(void) {
b5_L8006_top:;
nmi_poll("b5_L8006");
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
nmi_poll("b5_L8006");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_poll("b5_L8006");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b5_L8006"); goto b5_L8006_top; }
nmi_poll("b5_L8006");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_L8006");
nmi_poll("b5_L8006");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_BE17(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_L8006", "b5_entry_BE17", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_L8006");
nmi_poll("b5_L8006");
b5_entry_8012();
return;
}
static void __attribute__((used)) b5_entry_8012(void) {
nmi_poll("b5_entry_8012");
cycles += 6;
return;
nmi_poll("b5_entry_8012");
}
static void __attribute__((used)) b5_entry_8013(void) {
nmi_poll("b5_entry_8013");
WR(0xE9, A);
cycles += 3;
nmi_poll("b5_entry_8013");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_8013");
X = A; setZN(X);
cycles += 2;
nmi_poll("b5_entry_8013");
A = RD((uint16_t)(0x84B0 + X)); setZN(A);
cycles += 4 + ((((0x84B0 + X) & 0xFF00) != 0x8400) ? 1 : 0);
nmi_poll("b5_entry_8013");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_entry_8013");
A = RD((uint16_t)(0x84B1 + X)); setZN(A);
cycles += 4 + ((((0x84B1 + X) & 0xFF00) != 0x8400) ? 1 : 0);
nmi_poll("b5_entry_8013");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_entry_8013");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b5_entry_8013");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_entry_8013");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_8013");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L806D(); return; }
nmi_poll("b5_entry_8013");
b5_L802A();
return;
}
static void __attribute__((used)) b5_L802A(void) {
nmi_poll("b5_L802A");
X = A; setZN(X);
cycles += 2;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L802A");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L802A");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L802A");
WR((uint16_t)(0x0712 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L802A");
WR((uint16_t)(0x071B + X), A);
cycles += 5;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L802A");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L802A");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
WR((uint16_t)(0x072D + X), A);
cycles += 5;
nmi_poll("b5_L802A");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0736 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
WR((uint16_t)(0x073F + X), A);
cycles += 5;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
A = X; setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
WR(0x07FF, A);
cycles += 4;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L802A");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L802A");
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
nmi_poll("b5_L802A");
{ uint8_t _m = 0x80; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0775 + X), A);
cycles += 5;
nmi_poll("b5_L802A");
b5_L806D();
return;
}
static void __attribute__((used)) b5_L806D(void) {
nmi_poll("b5_L806D");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L806D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L802A(); return; }
nmi_poll("b5_L806D");
b5_L8071();
return;
}
static void __attribute__((used)) b5_L8071(void) {
nmi_poll("b5_L8071");
A = RD(0xE9); setZN(A);
cycles += 3;
nmi_poll("b5_L8071");
nmi_poll("b5_L8071");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_BDF6(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_L8071", "b5_entry_BDF6", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_L8071");
nmi_poll("b5_L8071");
b5_entry_8076();
return;
}
static void __attribute__((used)) b5_entry_8076(void) {
nmi_poll("b5_entry_8076");
cycles += 6;
return;
nmi_poll("b5_entry_8076");
}
static void __attribute__((used)) b5_entry_8077(void) {
nmi_poll("b5_entry_8077");
nmi_poll("b5_entry_8077");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_BE23(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_entry_8077", "b5_entry_BE23", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_8077");
nmi_poll("b5_entry_8077");
b5_entry_807A();
return;
}
static void __attribute__((used)) b5_entry_807A(void) {
nmi_poll("b5_entry_807A");
A = 0xFF; setZN(A);
cycles += 2;
nmi_poll("b5_entry_807A");
WR(0xEA, A);
cycles += 3;
nmi_poll("b5_entry_807A");
WR(0xEB, A);
cycles += 3;
nmi_poll("b5_entry_807A");
WR(0xEC, A);
cycles += 3;
nmi_poll("b5_entry_807A");
WR(0xED, A);
cycles += 3;
nmi_poll("b5_entry_807A");
X = 0x08; setZN(X);
cycles += 2;
nmi_poll("b5_entry_807A");
b5_L8086();
return;
}
static void __attribute__((used)) b5_L8086(void) {
nmi_poll("b5_L8086");
nmi_poll("b5_L8086");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_808C(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_L8086", "b5_entry_808C", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_L8086");
nmi_poll("b5_L8086");
b5_entry_8089();
return;
}
static void __attribute__((used)) b5_entry_8089(void) {
nmi_poll("b5_entry_8089");
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
nmi_poll("b5_entry_8089");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8086(); return; }
nmi_poll("b5_entry_8089");
b5_entry_808C();
return;
}
static void __attribute__((used)) b5_entry_808C(void) {
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0x0724 + X)); setZN(A);
cycles += 4 + ((((0x724 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_808C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8071(); return; }
nmi_poll("b5_entry_808C");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_808C");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_808C");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0xEA + Y)); setZN(A);
cycles += 4 + ((((0xEA + Y) & 0xFF00) != 0x0) ? 1 : 0);
nmi_poll("b5_entry_808C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80A2(); return; }
nmi_poll("b5_entry_808C");
WR((uint16_t)(0xEA + Y), X);
cycles += 4;
nmi_poll("b5_entry_808C");
A = 0xFF; setZN(A);
cycles += 2;
nmi_poll("b5_entry_808C");
b5_L80A2();
return;
}
static void __attribute__((used)) b5_L80A2(void) {
nmi_poll("b5_L80A2");
WR(0xE4, A);
cycles += 3;
nmi_poll("b5_L80A2");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80AC(); return; }
nmi_poll("b5_L80A2");
nmi_poll("b5_L80A2");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_82CE(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_L80A2", "b5_entry_82CE", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_L80A2");
nmi_poll("b5_L80A2");
b5_entry_80A9();
return;
}
static void __attribute__((used)) b5_entry_80A9(void) {
nmi_poll("b5_entry_80A9");
nmi_poll("b5_entry_80A9");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_835C(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_entry_80A9", "b5_entry_835C", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_80A9");
nmi_poll("b5_entry_80A9");
b5_L80AC();
return;
}
static void __attribute__((used)) b5_L80AC(void) {
nmi_poll("b5_L80AC");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x072D + X)) - 1); WR((uint16_t)(0x072D + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L80AC");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8071(); return; }
nmi_poll("b5_L80AC");
A = RD((uint16_t)(0x071B + X)); setZN(A);
cycles += 4 + ((((0x71B + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L80AC");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_L80AC");
b5_entry_80B6();
return;
}
static void __attribute__((used)) b5_entry_80B6(void) {
nmi_poll("b5_entry_80B6");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_80B6");
b5_entry_80B8();
return;
}
static void __attribute__((used)) b5_entry_80B8(void) {
nmi_poll("b5_entry_80B8");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_entry_80B8");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DB(); return; }
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E7(); return; }
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80FF(); return; }
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xD0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DE(); return; }
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xE0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E1(); return; }
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xF0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E4(); return; }
nmi_poll("b5_entry_80B8");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_entry_80B8");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_poll("b5_entry_80B8");
nmi_poll("b5_entry_80B8");
cycles += 3;
b5_entry_827A(); return;
nmi_poll("b5_entry_80B8");
}
static void __attribute__((used)) b5_L80DB(void) {
nmi_poll("b5_L80DB");
nmi_poll("b5_L80DB");
cycles += 3;
b5_L821D(); return;
nmi_poll("b5_L80DB");
}
static void __attribute__((used)) b5_L80DE(void) {
nmi_poll("b5_L80DE");
nmi_poll("b5_L80DE");
cycles += 3;
b5_entry_813F(); return;
nmi_poll("b5_L80DE");
}
static void __attribute__((used)) b5_L80E1(void) {
nmi_poll("b5_L80E1");
nmi_poll("b5_L80E1");
cycles += 3;
b5_L819C(); return;
nmi_poll("b5_L80E1");
}
static void __attribute__((used)) b5_L80E4(void) {
nmi_poll("b5_L80E4");
nmi_poll("b5_L80E4");
cycles += 3;
b5_L81C2(); return;
nmi_poll("b5_L80E4");
}
static void __attribute__((used)) b5_L80E7(void) {
nmi_poll("b5_L80E7");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_L80E7");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L80E7");
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L80E7");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_poll("b5_L80E7");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L80E7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L80E7");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L80FA(); return; }
nmi_poll("b5_L80E7");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_poll("b5_L80E7");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
nmi_poll("b5_L80E7");
b5_L80FA();
return;
}
static void __attribute__((used)) b5_L80FA(void) {
nmi_poll("b5_L80FA");
WR((uint16_t)(0x0712 + X), A);
cycles += 5;
nmi_poll("b5_L80FA");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
nmi_poll("b5_L80FA");
b5_L80FF();
return;
}
static void __attribute__((used)) b5_L80FF(void) {
nmi_poll("b5_L80FF");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_L80FF");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8118(); return; }
nmi_poll("b5_L80FF");
A = RD((uint16_t)(0x0736 + X)); setZN(A);
cycles += 4 + ((((0x736 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L80FF");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L810E(); return; }
nmi_poll("b5_L80FF");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L80FF");
WR((uint16_t)(0x0736 + X), A);
cycles += 5;
nmi_poll("b5_L80FF");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
nmi_poll("b5_L80FF");
b5_L810E();
return;
}
static void __attribute__((used)) b5_L810E(void) {
nmi_poll("b5_L810E");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0736 + X)) - 1); WR((uint16_t)(0x0736 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L810E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L810E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
nmi_poll("b5_L810E");
b5_L8118();
return;
}
static void __attribute__((used)) b5_L8118(void) {
nmi_poll("b5_L8118");
A = RD((uint16_t)(0x073F + X)); setZN(A);
cycles += 4 + ((((0x73F + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8118");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8124(); return; }
nmi_poll("b5_L8118");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L8118");
WR((uint16_t)(0x073F + X), A);
cycles += 5;
nmi_poll("b5_L8118");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
nmi_poll("b5_L8118");
b5_L8124();
return;
}
static void __attribute__((used)) b5_L8124(void) {
nmi_poll("b5_L8124");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x073F + X)) - 1); WR((uint16_t)(0x073F + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L8124");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L8124");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
nmi_poll("b5_L8124");
b5_L812E();
return;
}
static void __attribute__((used)) b5_L812E(void) {
nmi_poll("b5_L812E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L812E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L812E");
WR(0xE3, A);
cycles += 3;
nmi_poll("b5_L812E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L812E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L812E");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_L812E");
A = RD(0xE3); setZN(A);
cycles += 3;
nmi_poll("b5_L812E");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_L812E");
nmi_poll("b5_L812E");
cycles += 3;
b5_entry_80B6(); return;
nmi_poll("b5_L812E");
}
static void __attribute__((used)) b5_entry_813F(void) {
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0xC2; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_813F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L815E(); return; }
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0xC3; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_813F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8159(); return; }
nmi_poll("b5_entry_813F");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_813F");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_813F");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L8151(); return; }
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_813F");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8153(); return; }
nmi_poll("b5_entry_813F");
b5_L8151();
return;
}
static void __attribute__((used)) b5_L8151(void) {
nmi_poll("b5_L8151");
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8151");
b5_L8153();
return;
}
static void __attribute__((used)) b5_L8153(void) {
nmi_poll("b5_L8153");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_poll("b5_L8153");
nmi_poll("b5_L8153");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L8153");
}
static void __attribute__((used)) b5_L8159(void) {
nmi_poll("b5_L8159");
{ uint8_t _v = (uint8_t)(RD(0xE0) + 1); WR(0xE0, _v); setZN(_v); }
cycles += 5;
nmi_poll("b5_L8159");
nmi_poll("b5_L8159");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L8159");
}
static void __attribute__((used)) b5_L815E(void) {
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L815E");
{ uint8_t _m = 0x80; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L815E");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_poll("b5_L815E");
{ uint8_t _m = 0x80; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L815E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L817B(); return; }
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L815E");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L815E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8184(); return; }
nmi_poll("b5_L815E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L815E");
WR((uint16_t)(0x0751 + X), A);
cycles += 5;
nmi_poll("b5_L815E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L815E");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_poll("b5_L815E");
b5_L817B();
return;
}
static void __attribute__((used)) b5_L817B(void) {
nmi_poll("b5_L817B");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_L817B");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_poll("b5_L817B");
b5_L8180();
return;
}
static void __attribute__((used)) b5_L8180(void) {
nmi_poll("b5_L8180");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L8180");
nmi_poll("b5_L8180");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L8180");
}
static void __attribute__((used)) b5_L8184(void) {
nmi_poll("b5_L8184");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8184");
{ uint8_t _m = 0x10; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8184");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_poll("b5_L8184");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_poll("b5_L8184");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8184");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8184");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_poll("b5_L8184");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_L8184");
nmi_poll("b5_L8184");
cycles += 3;
b5_L8180(); return;
nmi_poll("b5_L8184");
}
static void __attribute__((used)) b5_L819C(void) {
nmi_poll("b5_L819C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_L819C");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L819C");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L819C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81BC(); return; }
nmi_poll("b5_L819C");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L819C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L81A8(); return; }
nmi_poll("b5_L819C");
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L819C");
b5_L81A8();
return;
}
static void __attribute__((used)) b5_L81A8(void) {
nmi_poll("b5_L81A8");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_poll("b5_L81A8");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81A8");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x07AB + X), A);
cycles += 5;
nmi_poll("b5_L81A8");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x07A2 + X), A);
cycles += 5;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_poll("b5_L81A8");
nmi_poll("b5_L81A8");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L81A8");
}
static void __attribute__((used)) b5_L81BC(void) {
nmi_poll("b5_L81BC");
WR((uint16_t)(0x075A + X), A);
cycles += 5;
nmi_poll("b5_L81BC");
nmi_poll("b5_L81BC");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L81BC");
}
static void __attribute__((used)) b5_L81C2(void) {
nmi_poll("b5_L81C2");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_L81C2");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81F7(); return; }
nmi_poll("b5_L81C2");
A = Y; setZN(A);
cycles += 2;
nmi_poll("b5_L81C2");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b5_L81C2");
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L81C2");
WR(0xE5, A);
cycles += 3;
nmi_poll("b5_L81C2");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b5_L81C2");
WR(0xE6, A);
cycles += 3;
nmi_poll("b5_L81C2");
A = RD(0xE1); setZN(A);
cycles += 3;
nmi_poll("b5_L81C2");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_poll("b5_L81C2");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_poll("b5_L81C2");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81C2");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_L81C2");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81C2");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b5_L81C2");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81C2");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_L81C2");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b5_L81C2");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_L81C2");
nmi_poll("b5_L81C2");
cycles += 3;
b5_entry_80B6(); return;
nmi_poll("b5_L81C2");
}
static void __attribute__((used)) b5_L81F7(void) {
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L81F7");
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L81F7");
WR(0xE5, A);
cycles += 3;
nmi_poll("b5_L81F7");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b5_L81F7");
WR(0xE6, A);
cycles += 3;
nmi_poll("b5_L81F7");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81F7");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81F7");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L81F7");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L81F7");
nmi_poll("b5_L81F7");
cycles += 3;
b5_entry_80B8(); return;
nmi_poll("b5_L81F7");
}
static void __attribute__((used)) b5_L821D(void) {
nmi_poll("b5_L821D");
WR(0xE3, A);
cycles += 3;
nmi_poll("b5_L821D");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L821D");
WR((uint16_t)(0x072D + X), A);
cycles += 5;
nmi_poll("b5_L821D");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L821D");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L821D");
A = Y; setZN(A);
cycles += 2;
nmi_poll("b5_L821D");
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b5_L821D");
WR((uint16_t)(0x071B + X), A);
cycles += 5;
nmi_poll("b5_L821D");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_poll("b5_L821D");
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b5_L821D");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_poll("b5_L821D");
A = RD(0xE4); setZN(A);
cycles += 3;
nmi_poll("b5_L821D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8298(); return; }
nmi_poll("b5_L821D");
A = RD(0xE3); setZN(A);
cycles += 3;
nmi_poll("b5_L821D");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_entry_827A(); return; }
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L821D");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x83EE + Y)); setZN(A);
cycles += 4 + ((((0x83EE + Y) & 0xFF00) != 0x8300) ? 1 : 0);
nmi_poll("b5_L821D");
WR(0xE1, A);
cycles += 3;
nmi_poll("b5_L821D");
WR((uint16_t)(0x0790 + X), A);
cycles += 5;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x83EF + Y)); setZN(A);
cycles += 4 + ((((0x83EF + Y) & 0xFF00) != 0x8300) ? 1 : 0);
nmi_poll("b5_L821D");
{ uint8_t _m = 0x08; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L821D");
WR(0xE2, A);
cycles += 3;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L821D");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_L821D");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8260(); return; }
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L821D");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0712 + X)); setZN(A);
cycles += 4 + ((((0x712 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L821D");
WR((uint16_t)(0x4001 + Y), A);
cycles += 5;
nmi_poll("b5_L821D");
b5_L8260();
return;
}
static void __attribute__((used)) b5_L8260(void) {
nmi_poll("b5_L8260");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8260");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L826A(); return; }
nmi_poll("b5_L8260");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_poll("b5_L8260");
WR((uint16_t)(0x4003 + Y), A);
cycles += 5;
nmi_poll("b5_L8260");
b5_L826A();
return;
}
static void __attribute__((used)) b5_L826A(void) {
nmi_poll("b5_L826A");
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L826A");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L826A");
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b5_L826A");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_poll("b5_L826A");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L826A");
{ uint8_t _m = 0x40; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L826A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L829D(); return; }
nmi_poll("b5_L826A");
b5_entry_827A();
return;
}
static void __attribute__((used)) b5_entry_827A(void) {
nmi_poll("b5_entry_827A");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_827A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_827A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_827A");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_827A");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b5_entry_827A");
{ uint8_t _m = 0x08; uint8_t _r = (uint8_t)(Y - _m); P = (uint8_t)((P & 0x7C) | (Y >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_827A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L828D(); return; }
nmi_poll("b5_entry_827A");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_entry_827A");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_poll("b5_entry_827A");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8298(); return; }
nmi_poll("b5_entry_827A");
b5_L828D();
return;
}
static void __attribute__((used)) b5_L828D(void) {
nmi_poll("b5_L828D");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_poll("b5_L828D");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_L828D");
WR((uint16_t)(0x4001 + Y), A);
cycles += 5;
nmi_poll("b5_L828D");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_poll("b5_L828D");
b5_L8298();
return;
}
static void __attribute__((used)) b5_L8298(void) {
nmi_poll("b5_L8298");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8298");
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8298");
b5_L829D();
return;
}
static void __attribute__((used)) b5_L829D(void) {
nmi_poll("b5_L829D");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L829D");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82CD(); return; }
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L829D");
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L829D");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L82CD(); return; }
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L829D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L82CD(); return; }
nmi_poll("b5_L829D");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L829D");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_poll("b5_L829D");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L829D");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L829D");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L829D");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82CA(); return; }
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L829D");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_poll("b5_L829D");
WR(0xE7, A);
cycles += 3;
nmi_poll("b5_L829D");
b5_L82CA();
return;
}
static void __attribute__((used)) b5_L82CA(void) {
nmi_poll("b5_L82CA");
nmi_poll("b5_L82CA");
cycles += 3;
b5_entry_8383(); return;
nmi_poll("b5_L82CA");
}
static void __attribute__((used)) b5_L82CD(void) {
nmi_poll("b5_L82CD");
cycles += 6;
return;
nmi_poll("b5_L82CD");
}
static void __attribute__((used)) b5_entry_82CE(void) {
nmi_poll("b5_entry_82CE");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_82CE");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82D4(); return; }
nmi_poll("b5_entry_82CE");
cycles += 6;
return;
nmi_poll("b5_entry_82CE");
}
static void __attribute__((used)) b5_L82D4(void) {
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x07A2 + X)); setZN(A);
cycles += 4 + ((((0x7A2 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L82D4");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L8342(); return; }
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L82D4");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L830E(); return; }
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L82D4");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82F6(); return; }
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L82D4");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L82D4");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L82D4");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_poll("b5_L82D4");
nmi_poll("b5_L82D4");
cycles += 3;
b5_entry_82F9(); return;
nmi_poll("b5_L82D4");
}
static void __attribute__((used)) b5_L82F6(void) {
nmi_poll("b5_L82F6");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) + 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L82F6");
b5_entry_82F9();
return;
}
static void __attribute__((used)) b5_entry_82F9(void) {
nmi_poll("b5_entry_82F9");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_82F9");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_82F9");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_82F9");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_entry_833C(); return; }
nmi_poll("b5_entry_82F9");
b5_L8303();
return;
}
static void __attribute__((used)) b5_L8303(void) {
nmi_poll("b5_L8303");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8303");
{ uint8_t _m = 0x40; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8303");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_poll("b5_L8303");
nmi_poll("b5_L8303");
cycles += 3;
b5_entry_833C(); return;
nmi_poll("b5_L8303");
}
static void __attribute__((used)) b5_L830E(void) {
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L830E");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L830E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L832A(); return; }
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L830E");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L830E");
WR(0x07FF, A);
cycles += 4;
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0799 + X)); setZN(A);
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L830E");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b5_L830E");
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
nmi_poll("b5_L830E");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_poll("b5_L830E");
nmi_poll("b5_L830E");
cycles += 3;
b5_entry_832D(); return;
nmi_poll("b5_L830E");
}
static void __attribute__((used)) b5_L832A(void) {
nmi_poll("b5_L832A");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) - 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L832A");
b5_entry_832D();
return;
}
static void __attribute__((used)) b5_entry_832D(void) {
nmi_poll("b5_entry_832D");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_832D");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b5_entry_832D");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_832D");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8303(); return; }
nmi_poll("b5_entry_832D");
b5_entry_833C();
return;
}
static void __attribute__((used)) b5_entry_833C(void) {
nmi_poll("b5_entry_833C");
A = RD((uint16_t)(0x07AB + X)); setZN(A);
cycles += 4 + ((((0x7AB + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_833C");
WR((uint16_t)(0x07A2 + X), A);
cycles += 5;
nmi_poll("b5_entry_833C");
b5_L8342();
return;
}
static void __attribute__((used)) b5_L8342(void) {
nmi_poll("b5_L8342");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x07A2 + X)) - 1); WR((uint16_t)(0x07A2 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L8342");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8342");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L8342");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L8342");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_L8342");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_L8342");
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8342");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L8342");
{ uint8_t _m = RD((uint16_t)(0x0790 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x790 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8342");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_L8342");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L8342");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_poll("b5_L8342");
b5_L835B();
return;
}
static void __attribute__((used)) b5_L835B(void) {
nmi_poll("b5_L835B");
cycles += 6;
return;
nmi_poll("b5_L835B");
}
static void __attribute__((used)) b5_entry_835C(void) {
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L835B(); return; }
nmi_poll("b5_entry_835C");
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L835B(); return; }
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_835C");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83AC(); return; }
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0751 + X)); setZN(A);
cycles += 4 + ((((0x751 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_835C");
WR(0xE7, A);
cycles += 3;
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_835C");
WR(0xE8, A);
cycles += 3;
nmi_poll("b5_entry_835C");
b5_entry_8376();
return;
}
static void __attribute__((used)) b5_entry_8376(void) {
nmi_poll("b5_entry_8376");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_8376");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_8376");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_entry_8376");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8395(); return; }
nmi_poll("b5_entry_8376");
WR(0xE7, A);
cycles += 3;
nmi_poll("b5_entry_8376");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) + 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_entry_8376");
b5_entry_8383();
return;
}
static void __attribute__((used)) b5_entry_8383(void) {
nmi_poll("b5_entry_8383");
A = RD(0xE4); setZN(A);
cycles += 3;
nmi_poll("b5_entry_8383");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8394(); return; }
nmi_poll("b5_entry_8383");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_entry_8383");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_entry_8383");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_8383");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_entry_8383");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_8383");
A = RD(0xE7); setZN(A);
cycles += 3;
nmi_poll("b5_entry_8383");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_poll("b5_entry_8383");
b5_L8394();
return;
}
static void __attribute__((used)) b5_L8394(void) {
nmi_poll("b5_L8394");
cycles += 6;
return;
nmi_poll("b5_L8394");
}
static void __attribute__((used)) b5_L8395(void) {
nmi_poll("b5_L8395");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L8395");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L8395");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L83A3(); return; }
nmi_poll("b5_L8395");
b5_L839A();
return;
}
static void __attribute__((used)) b5_L839A(void) {
nmi_poll("b5_L839A");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L839A");
{ uint8_t _m = 0x20; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L839A");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_poll("b5_L839A");
cycles += 6;
return;
nmi_poll("b5_L839A");
}
static void __attribute__((used)) b5_L83A3(void) {
nmi_poll("b5_L83A3");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_L83A3");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_L83A3");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_poll("b5_L83A3");
nmi_poll("b5_L83A3");
cycles += 3;
b5_entry_8376(); return;
nmi_poll("b5_L83A3");
}
static void __attribute__((used)) b5_L83AC(void) {
nmi_poll("b5_L83AC");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83AC");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L83B5(); return; }
nmi_poll("b5_L83AC");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) - 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L83AC");
cycles += 6;
return;
nmi_poll("b5_L83AC");
}
static void __attribute__((used)) b5_L83B5(void) {
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83B5");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83B5");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83D8(); return; }
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83B5");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
nmi_poll("b5_L83B5");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) - 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83B5");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83B5");
WR(0xE7, A);
cycles += 3;
nmi_poll("b5_L83B5");
nmi_poll("b5_L83B5");
cycles += 3;
b5_entry_8383(); return;
nmi_poll("b5_L83B5");
}
static void __attribute__((used)) b5_L83D8(void) {
nmi_poll("b5_L83D8");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83D8");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83D8");
{ uint8_t _m = 0x0F; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_L83D8");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
nmi_poll("b5_L83D8");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) + 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
cycles += 7;
nmi_poll("b5_L83D8");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_poll("b5_L83D8");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_L83D8");
WR(0xE7, A);
cycles += 3;
nmi_poll("b5_L83D8");
nmi_poll("b5_L83D8");
cycles += 3;
b5_entry_8383(); return;
nmi_poll("b5_L83D8");
}
static void __attribute__((used)) b5_entry_BDF6(void) {
nmi_poll("b5_entry_BDF6");
{ uint8_t _m = 0x54; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_BDF6");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_LBE16(); return; }
nmi_poll("b5_entry_BDF6");
A = RD(0xBDBC); setZN(A);
cycles += 4;
nmi_poll("b5_entry_BDF6");
WR(0x07F0, A);
cycles += 4;
nmi_poll("b5_entry_BDF6");
A = RD(0xBDBD); setZN(A);
cycles += 4;
nmi_poll("b5_entry_BDF6");
WR(0x07F1, A);
cycles += 4;
nmi_poll("b5_entry_BDF6");
b5_LBE06();
return;
}
static void __attribute__((used)) b5_LBE06(void) {
nmi_poll("b5_LBE06");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b5_LBE06");
WR(0x07F2, A);
cycles += 4;
nmi_poll("b5_LBE06");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_LBE06");
WR(0x07F3, A);
cycles += 4;
nmi_poll("b5_LBE06");
WR(0x07F4, A);
cycles += 4;
nmi_poll("b5_LBE06");
WR(0x07F5, A);
cycles += 4;
nmi_poll("b5_LBE06");
b5_LBE16();
return;
}
static void __attribute__((used)) b5_LBE16(void) {
nmi_poll("b5_LBE16");
cycles += 6;
return;
nmi_poll("b5_LBE16");
}
static void __attribute__((used)) b5_entry_BE17(void) {
nmi_poll("b5_entry_BE17");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BE17");
WR(0x07F1, A);
cycles += 4;
nmi_poll("b5_entry_BE17");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BE17");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_entry_BE17");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE06(); return; }
nmi_poll("b5_entry_BE17");
b5_entry_BE23();
return;
}
static void __attribute__((used)) b5_entry_BE23(void) {
nmi_poll("b5_entry_BE23");
A = RD(0x07F1); setZN(A);
cycles += 4;
nmi_poll("b5_entry_BE23");
WR(0xBE, A);
cycles += 3;
nmi_poll("b5_entry_BE23");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBE16(); return; }
nmi_poll("b5_entry_BE23");
{ uint8_t _v = (uint8_t)(RD(0x07F2) - 1); WR(0x07F2, _v); setZN(_v); }
cycles += 6;
nmi_poll("b5_entry_BE23");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE16(); return; }
nmi_poll("b5_entry_BE23");
A = RD(0x07F0); setZN(A);
cycles += 4;
nmi_poll("b5_entry_BE23");
WR(0xBD, A);
cycles += 3;
nmi_poll("b5_entry_BE23");
b5_entry_BE34();
return;
}
static void __attribute__((used)) b5_entry_BE34(void) {
nmi_poll("b5_entry_BE34");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_entry_BE34");
b5_entry_BE36();
return;
}
static void __attribute__((used)) b5_entry_BE36(void) {
nmi_poll("b5_entry_BE36");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_entry_BE36");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE58(); return; }
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE50(); return; }
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBEAF(); return; }
nmi_poll("b5_entry_BE36");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BE36");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_entry_BE36");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BE36");
WR(0x07F1, A);
cycles += 4;
nmi_poll("b5_entry_BE36");
cycles += 6;
return;
nmi_poll("b5_entry_BE36");
}
static void __attribute__((used)) b5_LBE50(void) {
nmi_poll("b5_LBE50");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_poll("b5_LBE50");
{ uint8_t _m = 0x01; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b5_LBE50");
WR(0x07F5, A);
cycles += 4;
nmi_poll("b5_LBE50");
b5_LBE58();
return;
}
static void __attribute__((used)) b5_LBE58(void) {
nmi_poll("b5_LBE58");
WR(0xBF, A);
cycles += 3;
nmi_poll("b5_LBE58");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b5_LBE58");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0x07F2, A);
cycles += 4;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBE58");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b5_LBE58");
A = Y; setZN(A);
cycles += 2;
nmi_poll("b5_LBE58");
{ uint8_t _m = RD(0xBD); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b5_LBE58");
WR(0x07F0, A);
cycles += 4;
nmi_poll("b5_LBE58");
A = RD(0xBE); setZN(A);
cycles += 3;
nmi_poll("b5_LBE58");
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b5_LBE58");
WR(0x07F1, A);
cycles += 4;
nmi_poll("b5_LBE58");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_poll("b5_LBE58");
{ uint8_t _m = 0x01; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_LBE58");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEA6(); return; }
nmi_poll("b5_LBE58");
A = RD(0xBF); setZN(A);
cycles += 3;
nmi_poll("b5_LBE58");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b5_LBE58");
X = A; setZN(X);
cycles += 2;
nmi_poll("b5_LBE58");
A = RD((uint16_t)(0xBDBE + X)); setZN(A);
cycles += 4 + ((((0xBDBE + X) & 0xFF00) != 0xBD00) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0xBD, A);
cycles += 3;
nmi_poll("b5_LBE58");
A = RD((uint16_t)(0xBDBF + X)); setZN(A);
cycles += 4 + ((((0xBDBF + X) & 0xFF00) != 0xBD00) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0xBE, A);
cycles += 3;
nmi_poll("b5_LBE58");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0x4010, A);
cycles += 4;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0x4011, A);
cycles += 4;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0x4012, A);
cycles += 4;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBE58");
WR(0x4013, A);
cycles += 4;
nmi_poll("b5_LBE58");
A = 0x1F; setZN(A);
cycles += 2;
nmi_poll("b5_LBE58");
WR(0x4015, A);
cycles += 4;
nmi_poll("b5_LBE58");
b5_LBEA6();
return;
}
static void __attribute__((used)) b5_LBEA6(void) {
nmi_poll("b5_LBEA6");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_poll("b5_LBEA6");
{ uint8_t _m = 0xFE; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_LBEA6");
WR(0x07F5, A);
cycles += 4;
nmi_poll("b5_LBEA6");
cycles += 6;
return;
nmi_poll("b5_LBEA6");
}
static void __attribute__((used)) b5_LBEAF(void) {
nmi_poll("b5_LBEAF");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b5_LBEAF");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_LBEC9(); return; }
nmi_poll("b5_LBEAF");
A = RD(0x07F3); setZN(A);
cycles += 4;
nmi_poll("b5_LBEAF");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEBE(); return; }
nmi_poll("b5_LBEAF");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBEAF");
WR(0x07F3, A);
cycles += 4;
nmi_poll("b5_LBEAF");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
nmi_poll("b5_LBEAF");
b5_LBEBE();
return;
}
static void __attribute__((used)) b5_LBEBE(void) {
nmi_poll("b5_LBEBE");
{ uint8_t _v = (uint8_t)(RD(0x07F3) - 1); WR(0x07F3, _v); setZN(_v); }
cycles += 6;
nmi_poll("b5_LBEBE");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBEBE");
nmi_poll("b5_LBEBE");
cycles += 3;
b5_entry_BE36(); return;
nmi_poll("b5_LBEBE");
}
static void __attribute__((used)) b5_LBEC9(void) {
nmi_poll("b5_LBEC9");
A = RD(0x07F4); setZN(A);
cycles += 4;
nmi_poll("b5_LBEC9");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBED5(); return; }
nmi_poll("b5_LBEC9");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBEC9");
WR(0x07F4, A);
cycles += 4;
nmi_poll("b5_LBEC9");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
nmi_poll("b5_LBEC9");
b5_LBED5();
return;
}
static void __attribute__((used)) b5_LBED5(void) {
nmi_poll("b5_LBED5");
{ uint8_t _v = (uint8_t)(RD(0x07F4) - 1); WR(0x07F4, _v); setZN(_v); }
cycles += 6;
nmi_poll("b5_LBED5");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBED5");
nmi_poll("b5_LBED5");
cycles += 3;
b5_entry_BE36(); return;
nmi_poll("b5_LBED5");
}
static void __attribute__((used)) b5_LBEE0(void) {
nmi_poll("b5_LBEE0");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBEE0");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBEE0");
WR(0xBF, A);
cycles += 3;
nmi_poll("b5_LBEE0");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_poll("b5_LBEE0");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_poll("b5_LBEE0");
WR(0xBE, A);
cycles += 3;
nmi_poll("b5_LBEE0");
A = RD(0xBF); setZN(A);
cycles += 3;
nmi_poll("b5_LBEE0");
WR(0xBD, A);
cycles += 3;
nmi_poll("b5_LBEE0");
nmi_poll("b5_LBEE0");
cycles += 3;
b5_entry_BE34(); return;
nmi_poll("b5_LBEE0");
}
static void __attribute__((used)) b5_entry_BF52(void) {
nmi_poll("b5_entry_BF52");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BF52");
WR(0x40, A);
cycles += 3;
nmi_poll("b5_entry_BF52");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b5_entry_BF52");
WR(0x41, A);
cycles += 3;
nmi_poll("b5_entry_BF52");
nmi_poll("b5_entry_BF52");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0FF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_entry_BF52", "b7_entry_C0FF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_entry_BF52");
nmi_poll("b5_entry_BF52");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBF62(); return; }
nmi_poll("b5_entry_BF52");
nmi_poll("b5_entry_BF52");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b5_entry_BF52");
}
static void __attribute__((used)) b5_LBF62(void) {
nmi_poll("b5_LBF62");
A = 0x0F; setZN(A);
cycles += 2;
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b5_entry_B2C5(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_LBF62", "b5_entry_B2C5", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C138(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_LBF62", "b7_entry_C138", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0A2(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b5_LBF62", "b7_entry_C0A2", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF75(); return; }
nmi_poll("b5_LBF62");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b5_LBF62");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_LBF62");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF89(); return; }
nmi_poll("b5_LBF62");
b5_LBF75();
return;
}
static void __attribute__((used)) b5_LBF75(void) {
nmi_poll("b5_LBF75");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b5_LBF75");
WR(0x44, A);
cycles += 3;
nmi_poll("b5_LBF75");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b5_LBF75");
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b5_LBF75");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF84(); return; }
nmi_poll("b5_LBF75");
A = 0x46; setZN(A);
cycles += 2;
nmi_poll("b5_LBF75");
nmi_poll("b5_LBF75");
cycles += 3;
b5_entry_BF86(); return;
nmi_poll("b5_LBF75");
}
static void __attribute__((used)) b5_LBF84(void) {
nmi_poll("b5_LBF84");
A = 0x47; setZN(A);
cycles += 2;
nmi_poll("b5_LBF84");
b5_entry_BF86();
return;
}
static void __attribute__((used)) b5_entry_BF86(void) {
nmi_poll("b5_entry_BF86");
nmi_poll("b5_entry_BF86");
cycles += 3;
b7_entry_C063(); return;
nmi_poll("b5_entry_BF86");
}
static void __attribute__((used)) b5_LBF89(void) {
nmi_poll("b5_LBF89");
cycles += 6;
return;
nmi_poll("b5_LBF89");
}
static void __attribute__((used)) b5_entry_BFE5(void) {
nmi_poll("b5_entry_BFE5");
nmi_poll("b5_entry_BFE5");
cycles += 3;
b5_entry_8000(); return;
nmi_poll("b5_entry_BFE5");
}
static void __attribute__((used)) b5_entry_BFE8(void) {
nmi_poll("b5_entry_BFE8");
nmi_poll("b5_entry_BFE8");
cycles += 3;
b5_entry_8013(); return;
nmi_poll("b5_entry_BFE8");
}
static void __attribute__((used)) b5_entry_BFF1(void) {
nmi_poll("b5_entry_BFF1");
nmi_poll("b5_entry_BFF1");
cycles += 3;
b5_entry_8077(); return;
nmi_poll("b5_entry_BFF1");
}
static void b5_entry_B2C5(void) { __builtin_trap(); }
