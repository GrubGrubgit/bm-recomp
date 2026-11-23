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
nmi_pc = 0x8000;
nmi_poll("b5_entry_8000");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x8002;
nmi_poll("b5_entry_8000");
WR(0xE0, A);
cycles += 3;
nmi_pc = 0x8004;
nmi_poll("b5_entry_8000");
X = 0xB4; setZN(X);
cycles += 2;
nmi_pc = 0x8006;
nmi_poll("b5_entry_8000");
b5_L8006();
return;
}
static void __attribute__((used)) b5_L8006(void) {
b5_L8006_top:;
nmi_pc = 0x8006;
nmi_poll("b5_L8006");
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
nmi_pc = 0x8007;
nmi_poll("b5_L8006");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_pc = 0x800A;
nmi_poll("b5_L8006");
cycles += 2;
nmi_pc = 0x8006;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b5_L8006"); goto b5_L8006_top; }
nmi_pc = 0x800C;
nmi_poll("b5_L8006");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0x800F;
nmi_poll("b5_L8006");
nmi_poll("b5_L8006");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0x11; S = (uint8_t)(S - 1);
b5_entry_BE17();
S = (uint8_t)(S + 2);
nmi_pc = 0x8012;
nmi_poll("b5_L8006");
nmi_pc = 0x8012;
nmi_poll("b5_L8006");
b5_entry_8012();
return;
}
static void __attribute__((used)) b5_entry_8012(void) {
nmi_pc = 0x8012;
nmi_poll("b5_entry_8012");
cycles += 6;
return;
nmi_pc = 0x8013;
nmi_poll("b5_entry_8012");
}
static void __attribute__((used)) b5_entry_8013(void) {
nmi_pc = 0x8013;
nmi_poll("b5_entry_8013");
WR(0xE9, A);
cycles += 3;
nmi_pc = 0x8015;
nmi_poll("b5_entry_8013");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8016;
nmi_poll("b5_entry_8013");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0x8017;
nmi_poll("b5_entry_8013");
A = RD((uint16_t)(0x84B0 + X)); setZN(A);
cycles += 4 + ((((0x84B0 + X) & 0xFF00) != 0x8400) ? 1 : 0);
nmi_pc = 0x801A;
nmi_poll("b5_entry_8013");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x801C;
nmi_poll("b5_entry_8013");
A = RD((uint16_t)(0x84B1 + X)); setZN(A);
cycles += 4 + ((((0x84B1 + X) & 0xFF00) != 0x8400) ? 1 : 0);
nmi_pc = 0x801F;
nmi_poll("b5_entry_8013");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x8021;
nmi_poll("b5_entry_8013");
A = 0x0F; setZN(A);
cycles += 2;
nmi_pc = 0x8023;
nmi_poll("b5_entry_8013");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0x8026;
nmi_poll("b5_entry_8013");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0x8028;
nmi_poll("b5_entry_8013");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L806D(); return; }
nmi_pc = 0x802A;
nmi_poll("b5_entry_8013");
b5_L802A();
return;
}
static void __attribute__((used)) b5_L802A(void) {
nmi_pc = 0x802A;
nmi_poll("b5_L802A");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0x802B;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x802C;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x802E;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_pc = 0x8031;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8032;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8034;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_pc = 0x8037;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8038;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x803A;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0712 + X), A);
cycles += 5;
nmi_pc = 0x803D;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x803E;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8040;
nmi_poll("b5_L802A");
WR((uint16_t)(0x071B + X), A);
cycles += 5;
nmi_pc = 0x8043;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8044;
nmi_poll("b5_L802A");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8046;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_pc = 0x8049;
nmi_poll("b5_L802A");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x804A;
nmi_poll("b5_L802A");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0x804C;
nmi_poll("b5_L802A");
WR((uint16_t)(0x072D + X), A);
cycles += 5;
nmi_pc = 0x804F;
nmi_poll("b5_L802A");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x8051;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0736 + X), A);
cycles += 5;
nmi_pc = 0x8054;
nmi_poll("b5_L802A");
WR((uint16_t)(0x073F + X), A);
cycles += 5;
nmi_pc = 0x8057;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_pc = 0x805A;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_pc = 0x805D;
nmi_poll("b5_L802A");
A = X; setZN(A);
cycles += 2;
nmi_pc = 0x805E;
nmi_poll("b5_L802A");
WR(0x07FF, A);
cycles += 4;
nmi_pc = 0x8061;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8062;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8063;
nmi_poll("b5_L802A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8064;
nmi_poll("b5_L802A");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x8065;
nmi_poll("b5_L802A");
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
nmi_pc = 0x8068;
nmi_poll("b5_L802A");
{ uint8_t _m = 0x80; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0x806A;
nmi_poll("b5_L802A");
WR((uint16_t)(0x0775 + X), A);
cycles += 5;
nmi_pc = 0x806D;
nmi_poll("b5_L802A");
b5_L806D();
return;
}
static void __attribute__((used)) b5_L806D(void) {
nmi_pc = 0x806D;
nmi_poll("b5_L806D");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x806F;
nmi_poll("b5_L806D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L802A(); return; }
nmi_pc = 0x8071;
nmi_poll("b5_L806D");
b5_L8071();
return;
}
static void __attribute__((used)) b5_L8071(void) {
nmi_pc = 0x8071;
nmi_poll("b5_L8071");
A = RD(0xE9); setZN(A);
cycles += 3;
nmi_pc = 0x8073;
nmi_poll("b5_L8071");
nmi_poll("b5_L8071");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0x75; S = (uint8_t)(S - 1);
b5_entry_BDF6();
S = (uint8_t)(S + 2);
nmi_pc = 0x8076;
nmi_poll("b5_L8071");
nmi_pc = 0x8076;
nmi_poll("b5_L8071");
b5_entry_8076();
return;
}
static void __attribute__((used)) b5_entry_8076(void) {
nmi_pc = 0x8076;
nmi_poll("b5_entry_8076");
cycles += 6;
return;
nmi_pc = 0x8077;
nmi_poll("b5_entry_8076");
}
static void __attribute__((used)) b5_entry_8077(void) {
nmi_pc = 0x8077;
nmi_poll("b5_entry_8077");
nmi_poll("b5_entry_8077");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0x79; S = (uint8_t)(S - 1);
b5_entry_BE23();
S = (uint8_t)(S + 2);
nmi_pc = 0x807A;
nmi_poll("b5_entry_8077");
nmi_pc = 0x807A;
nmi_poll("b5_entry_8077");
b5_entry_807A();
return;
}
static void __attribute__((used)) b5_entry_807A(void) {
nmi_pc = 0x807A;
nmi_poll("b5_entry_807A");
A = 0xFF; setZN(A);
cycles += 2;
nmi_pc = 0x807C;
nmi_poll("b5_entry_807A");
WR(0xEA, A);
cycles += 3;
nmi_pc = 0x807E;
nmi_poll("b5_entry_807A");
WR(0xEB, A);
cycles += 3;
nmi_pc = 0x8080;
nmi_poll("b5_entry_807A");
WR(0xEC, A);
cycles += 3;
nmi_pc = 0x8082;
nmi_poll("b5_entry_807A");
WR(0xED, A);
cycles += 3;
nmi_pc = 0x8084;
nmi_poll("b5_entry_807A");
X = 0x08; setZN(X);
cycles += 2;
nmi_pc = 0x8086;
nmi_poll("b5_entry_807A");
b5_L8086();
return;
}
static void __attribute__((used)) b5_L8086(void) {
nmi_pc = 0x8086;
nmi_poll("b5_L8086");
nmi_poll("b5_L8086");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0x88; S = (uint8_t)(S - 1);
b5_entry_808C();
S = (uint8_t)(S + 2);
nmi_pc = 0x8089;
nmi_poll("b5_L8086");
nmi_pc = 0x8089;
nmi_poll("b5_L8086");
b5_entry_8089();
return;
}
static void __attribute__((used)) b5_entry_8089(void) {
nmi_pc = 0x8089;
nmi_poll("b5_entry_8089");
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
nmi_pc = 0x808A;
nmi_poll("b5_entry_8089");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8086(); return; }
nmi_pc = 0x808C;
nmi_poll("b5_entry_8089");
b5_entry_808C();
return;
}
static void __attribute__((used)) b5_entry_808C(void) {
nmi_pc = 0x808C;
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0x0724 + X)); setZN(A);
cycles += 4 + ((((0x724 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x808F;
nmi_poll("b5_entry_808C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8071(); return; }
nmi_pc = 0x8091;
nmi_poll("b5_entry_808C");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x8093;
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8096;
nmi_poll("b5_entry_808C");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8098;
nmi_poll("b5_entry_808C");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x8099;
nmi_poll("b5_entry_808C");
A = RD((uint16_t)(0xEA + Y)); setZN(A);
cycles += 4 + ((((0xEA + Y) & 0xFF00) != 0x0) ? 1 : 0);
nmi_pc = 0x809C;
nmi_poll("b5_entry_808C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80A2(); return; }
nmi_pc = 0x809E;
nmi_poll("b5_entry_808C");
WR((uint16_t)(0xEA + Y), X);
cycles += 4;
nmi_pc = 0x80A0;
nmi_poll("b5_entry_808C");
A = 0xFF; setZN(A);
cycles += 2;
nmi_pc = 0x80A2;
nmi_poll("b5_entry_808C");
b5_L80A2();
return;
}
static void __attribute__((used)) b5_L80A2(void) {
nmi_pc = 0x80A2;
nmi_poll("b5_L80A2");
WR(0xE4, A);
cycles += 3;
nmi_pc = 0x80A4;
nmi_poll("b5_L80A2");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L80AC(); return; }
nmi_pc = 0x80A6;
nmi_poll("b5_L80A2");
nmi_poll("b5_L80A2");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0xA8; S = (uint8_t)(S - 1);
b5_entry_82CE();
S = (uint8_t)(S + 2);
nmi_pc = 0x80A9;
nmi_poll("b5_L80A2");
nmi_pc = 0x80A9;
nmi_poll("b5_L80A2");
b5_entry_80A9();
return;
}
static void __attribute__((used)) b5_entry_80A9(void) {
nmi_pc = 0x80A9;
nmi_poll("b5_entry_80A9");
nmi_poll("b5_entry_80A9");
cycles += 6;
stk[S] = 0x80; S = (uint8_t)(S - 1);
stk[S] = 0xAB; S = (uint8_t)(S - 1);
b5_entry_835C();
S = (uint8_t)(S + 2);
nmi_pc = 0x80AC;
nmi_poll("b5_entry_80A9");
nmi_pc = 0x80AC;
nmi_poll("b5_entry_80A9");
b5_L80AC();
return;
}
static void __attribute__((used)) b5_L80AC(void) {
nmi_pc = 0x80AC;
nmi_poll("b5_L80AC");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x072D + X)) - 1); WR((uint16_t)(0x072D + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x80AF;
nmi_poll("b5_L80AC");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8071(); return; }
nmi_pc = 0x80B1;
nmi_poll("b5_L80AC");
A = RD((uint16_t)(0x071B + X)); setZN(A);
cycles += 4 + ((((0x71B + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x80B4;
nmi_poll("b5_L80AC");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x80B6;
nmi_poll("b5_L80AC");
b5_entry_80B6();
return;
}
static void __attribute__((used)) b5_entry_80B6(void) {
nmi_pc = 0x80B6;
nmi_poll("b5_entry_80B6");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0x80B8;
nmi_poll("b5_entry_80B6");
b5_entry_80B8();
return;
}
static void __attribute__((used)) b5_entry_80B8(void) {
nmi_pc = 0x80B8;
nmi_poll("b5_entry_80B8");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x80BA;
nmi_poll("b5_entry_80B8");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x80BB;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80BD;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DB(); return; }
nmi_pc = 0x80BF;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80C1;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E7(); return; }
nmi_pc = 0x80C3;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80C5;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80FF(); return; }
nmi_pc = 0x80C7;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xD0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80C9;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80DE(); return; }
nmi_pc = 0x80CB;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xE0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80CD;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E1(); return; }
nmi_pc = 0x80CF;
nmi_poll("b5_entry_80B8");
{ uint8_t _m = 0xF0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x80D1;
nmi_poll("b5_entry_80B8");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L80E4(); return; }
nmi_pc = 0x80D3;
nmi_poll("b5_entry_80B8");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x80D5;
nmi_poll("b5_entry_80B8");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_pc = 0x80D8;
nmi_poll("b5_entry_80B8");
nmi_poll("b5_entry_80B8");
cycles += 3;
b5_entry_827A(); return;
nmi_pc = 0x80DB;
nmi_poll("b5_entry_80B8");
}
static void __attribute__((used)) b5_L80DB(void) {
nmi_pc = 0x80DB;
nmi_poll("b5_L80DB");
nmi_poll("b5_L80DB");
cycles += 3;
b5_L821D(); return;
nmi_pc = 0x80DE;
nmi_poll("b5_L80DB");
}
static void __attribute__((used)) b5_L80DE(void) {
nmi_pc = 0x80DE;
nmi_poll("b5_L80DE");
nmi_poll("b5_L80DE");
cycles += 3;
b5_entry_813F(); return;
nmi_pc = 0x80E1;
nmi_poll("b5_L80DE");
}
static void __attribute__((used)) b5_L80E1(void) {
nmi_pc = 0x80E1;
nmi_poll("b5_L80E1");
nmi_poll("b5_L80E1");
cycles += 3;
b5_L819C(); return;
nmi_pc = 0x80E4;
nmi_poll("b5_L80E1");
}
static void __attribute__((used)) b5_L80E4(void) {
nmi_pc = 0x80E4;
nmi_poll("b5_L80E4");
nmi_poll("b5_L80E4");
cycles += 3;
b5_L81C2(); return;
nmi_pc = 0x80E7;
nmi_poll("b5_L80E4");
}
static void __attribute__((used)) b5_L80E7(void) {
nmi_pc = 0x80E7;
nmi_poll("b5_L80E7");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0x80E8;
nmi_poll("b5_L80E7");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x80EB;
nmi_poll("b5_L80E7");
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x80ED;
nmi_poll("b5_L80E7");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_pc = 0x80F0;
nmi_poll("b5_L80E7");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x80F2;
nmi_poll("b5_L80E7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x80F3;
nmi_poll("b5_L80E7");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L80FA(); return; }
nmi_pc = 0x80F5;
nmi_poll("b5_L80E7");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_pc = 0x80F8;
nmi_poll("b5_L80E7");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
nmi_pc = 0x80FA;
nmi_poll("b5_L80E7");
b5_L80FA();
return;
}
static void __attribute__((used)) b5_L80FA(void) {
nmi_pc = 0x80FA;
nmi_poll("b5_L80FA");
WR((uint16_t)(0x0712 + X), A);
cycles += 5;
nmi_pc = 0x80FD;
nmi_poll("b5_L80FA");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_entry_80B8(); return; }
nmi_pc = 0x80FF;
nmi_poll("b5_L80FA");
b5_L80FF();
return;
}
static void __attribute__((used)) b5_L80FF(void) {
nmi_pc = 0x80FF;
nmi_poll("b5_L80FF");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0x8100;
nmi_poll("b5_L80FF");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8118(); return; }
nmi_pc = 0x8102;
nmi_poll("b5_L80FF");
A = RD((uint16_t)(0x0736 + X)); setZN(A);
cycles += 4 + ((((0x736 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8105;
nmi_poll("b5_L80FF");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L810E(); return; }
nmi_pc = 0x8107;
nmi_poll("b5_L80FF");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8109;
nmi_poll("b5_L80FF");
WR((uint16_t)(0x0736 + X), A);
cycles += 5;
nmi_pc = 0x810C;
nmi_poll("b5_L80FF");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
nmi_pc = 0x810E;
nmi_poll("b5_L80FF");
b5_L810E();
return;
}
static void __attribute__((used)) b5_L810E(void) {
nmi_pc = 0x810E;
nmi_poll("b5_L810E");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0736 + X)) - 1); WR((uint16_t)(0x0736 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x8111;
nmi_poll("b5_L810E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
nmi_pc = 0x8113;
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8114;
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8115;
nmi_poll("b5_L810E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8116;
nmi_poll("b5_L810E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
nmi_pc = 0x8118;
nmi_poll("b5_L810E");
b5_L8118();
return;
}
static void __attribute__((used)) b5_L8118(void) {
nmi_pc = 0x8118;
nmi_poll("b5_L8118");
A = RD((uint16_t)(0x073F + X)); setZN(A);
cycles += 4 + ((((0x73F + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x811B;
nmi_poll("b5_L8118");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8124(); return; }
nmi_pc = 0x811D;
nmi_poll("b5_L8118");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x811F;
nmi_poll("b5_L8118");
WR((uint16_t)(0x073F + X), A);
cycles += 5;
nmi_pc = 0x8122;
nmi_poll("b5_L8118");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L812E(); return; }
nmi_pc = 0x8124;
nmi_poll("b5_L8118");
b5_L8124();
return;
}
static void __attribute__((used)) b5_L8124(void) {
nmi_pc = 0x8124;
nmi_poll("b5_L8124");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x073F + X)) - 1); WR((uint16_t)(0x073F + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x8127;
nmi_poll("b5_L8124");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L812E(); return; }
nmi_pc = 0x8129;
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x812A;
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x812B;
nmi_poll("b5_L8124");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x812C;
nmi_poll("b5_L8124");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_entry_80B8(); return; }
nmi_pc = 0x812E;
nmi_poll("b5_L8124");
b5_L812E();
return;
}
static void __attribute__((used)) b5_L812E(void) {
nmi_pc = 0x812E;
nmi_poll("b5_L812E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x812F;
nmi_poll("b5_L812E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8131;
nmi_poll("b5_L812E");
WR(0xE3, A);
cycles += 3;
nmi_pc = 0x8133;
nmi_poll("b5_L812E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8134;
nmi_poll("b5_L812E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8136;
nmi_poll("b5_L812E");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x8138;
nmi_poll("b5_L812E");
A = RD(0xE3); setZN(A);
cycles += 3;
nmi_pc = 0x813A;
nmi_poll("b5_L812E");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x813C;
nmi_poll("b5_L812E");
nmi_poll("b5_L812E");
cycles += 3;
b5_entry_80B6(); return;
nmi_pc = 0x813F;
nmi_poll("b5_L812E");
}
static void __attribute__((used)) b5_entry_813F(void) {
nmi_pc = 0x813F;
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0xC2; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x8141;
nmi_poll("b5_entry_813F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L815E(); return; }
nmi_pc = 0x8143;
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0xC3; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x8145;
nmi_poll("b5_entry_813F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8159(); return; }
nmi_pc = 0x8147;
nmi_poll("b5_entry_813F");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0x8148;
nmi_poll("b5_entry_813F");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x814B;
nmi_poll("b5_entry_813F");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_L8151(); return; }
nmi_pc = 0x814D;
nmi_poll("b5_entry_813F");
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x814F;
nmi_poll("b5_entry_813F");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8153(); return; }
nmi_pc = 0x8151;
nmi_poll("b5_entry_813F");
b5_L8151();
return;
}
static void __attribute__((used)) b5_L8151(void) {
nmi_pc = 0x8151;
nmi_poll("b5_L8151");
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8153;
nmi_poll("b5_L8151");
b5_L8153();
return;
}
static void __attribute__((used)) b5_L8153(void) {
nmi_pc = 0x8153;
nmi_poll("b5_L8153");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_pc = 0x8156;
nmi_poll("b5_L8153");
nmi_poll("b5_L8153");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x8159;
nmi_poll("b5_L8153");
}
static void __attribute__((used)) b5_L8159(void) {
nmi_pc = 0x8159;
nmi_poll("b5_L8159");
{ uint8_t _v = (uint8_t)(RD(0xE0) + 1); WR(0xE0, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0x815B;
nmi_poll("b5_L8159");
nmi_poll("b5_L8159");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x815E;
nmi_poll("b5_L8159");
}
static void __attribute__((used)) b5_L815E(void) {
nmi_pc = 0x815E;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8160;
nmi_poll("b5_L815E");
{ uint8_t _m = 0x80; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8162;
nmi_poll("b5_L815E");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_pc = 0x8165;
nmi_poll("b5_L815E");
{ uint8_t _m = 0x80; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8167;
nmi_poll("b5_L815E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L817B(); return; }
nmi_pc = 0x8169;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x816B;
nmi_poll("b5_L815E");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x816D;
nmi_poll("b5_L815E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L8184(); return; }
nmi_pc = 0x816F;
nmi_poll("b5_L815E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8170;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8172;
nmi_poll("b5_L815E");
WR((uint16_t)(0x0751 + X), A);
cycles += 5;
nmi_pc = 0x8175;
nmi_poll("b5_L815E");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8176;
nmi_poll("b5_L815E");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8178;
nmi_poll("b5_L815E");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_pc = 0x817B;
nmi_poll("b5_L815E");
b5_L817B();
return;
}
static void __attribute__((used)) b5_L817B(void) {
nmi_pc = 0x817B;
nmi_poll("b5_L817B");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x817D;
nmi_poll("b5_L817B");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_pc = 0x8180;
nmi_poll("b5_L817B");
b5_L8180();
return;
}
static void __attribute__((used)) b5_L8180(void) {
nmi_pc = 0x8180;
nmi_poll("b5_L8180");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8181;
nmi_poll("b5_L8180");
nmi_poll("b5_L8180");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x8184;
nmi_poll("b5_L8180");
}
static void __attribute__((used)) b5_L8184(void) {
nmi_pc = 0x8184;
nmi_poll("b5_L8184");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8187;
nmi_poll("b5_L8184");
{ uint8_t _m = 0x10; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8189;
nmi_poll("b5_L8184");
WR((uint16_t)(0x0709 + X), A);
cycles += 5;
nmi_pc = 0x818C;
nmi_poll("b5_L8184");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_pc = 0x818F;
nmi_poll("b5_L8184");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8192;
nmi_poll("b5_L8184");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8194;
nmi_poll("b5_L8184");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_pc = 0x8197;
nmi_poll("b5_L8184");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x8199;
nmi_poll("b5_L8184");
nmi_poll("b5_L8184");
cycles += 3;
b5_L8180(); return;
nmi_pc = 0x819C;
nmi_poll("b5_L8184");
}
static void __attribute__((used)) b5_L819C(void) {
nmi_pc = 0x819C;
nmi_poll("b5_L819C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0x819D;
nmi_poll("b5_L819C");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x819F;
nmi_poll("b5_L819C");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x81A0;
nmi_poll("b5_L819C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81BC(); return; }
nmi_pc = 0x81A2;
nmi_poll("b5_L819C");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x81A4;
nmi_poll("b5_L819C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L81A8(); return; }
nmi_pc = 0x81A6;
nmi_poll("b5_L819C");
{ uint8_t _m = 0x80; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x81A8;
nmi_poll("b5_L819C");
b5_L81A8();
return;
}
static void __attribute__((used)) b5_L81A8(void) {
nmi_pc = 0x81A8;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_pc = 0x81AB;
nmi_poll("b5_L81A8");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x81AD;
nmi_poll("b5_L81A8");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x81AE;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x07AB + X), A);
cycles += 5;
nmi_pc = 0x81B1;
nmi_poll("b5_L81A8");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x81B3;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x07A2 + X), A);
cycles += 5;
nmi_pc = 0x81B6;
nmi_poll("b5_L81A8");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_pc = 0x81B9;
nmi_poll("b5_L81A8");
nmi_poll("b5_L81A8");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x81BC;
nmi_poll("b5_L81A8");
}
static void __attribute__((used)) b5_L81BC(void) {
nmi_pc = 0x81BC;
nmi_poll("b5_L81BC");
WR((uint16_t)(0x075A + X), A);
cycles += 5;
nmi_pc = 0x81BF;
nmi_poll("b5_L81BC");
nmi_poll("b5_L81BC");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x81C2;
nmi_poll("b5_L81BC");
}
static void __attribute__((used)) b5_L81C2(void) {
nmi_pc = 0x81C2;
nmi_poll("b5_L81C2");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0x81C3;
nmi_poll("b5_L81C2");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L81F7(); return; }
nmi_pc = 0x81C5;
nmi_poll("b5_L81C2");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0x81C6;
nmi_poll("b5_L81C2");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_pc = 0x81C7;
nmi_poll("b5_L81C2");
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x81CA;
nmi_poll("b5_L81C2");
WR(0xE5, A);
cycles += 3;
nmi_pc = 0x81CC;
nmi_poll("b5_L81C2");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0x81CE;
nmi_poll("b5_L81C2");
WR(0xE6, A);
cycles += 3;
nmi_pc = 0x81D0;
nmi_poll("b5_L81C2");
A = RD(0xE1); setZN(A);
cycles += 3;
nmi_pc = 0x81D2;
nmi_poll("b5_L81C2");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0x81D4;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_pc = 0x81D6;
nmi_poll("b5_L81C2");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_pc = 0x81D8;
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x81D9;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_pc = 0x81DB;
nmi_poll("b5_L81C2");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_pc = 0x81DC;
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x81DD;
nmi_poll("b5_L81C2");
WR((uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)((0xE5 + 1) & 0xFF)) << 8)) + Y, A);
cycles += 6;
nmi_pc = 0x81DF;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x81E2;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x81E5;
nmi_poll("b5_L81C2");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) + 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x81E8;
nmi_poll("b5_L81C2");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x81E9;
nmi_poll("b5_L81C2");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x81EB;
nmi_poll("b5_L81C2");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x81EC;
nmi_poll("b5_L81C2");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_pc = 0x81ED;
nmi_poll("b5_L81C2");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x81EF;
nmi_poll("b5_L81C2");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x81F1;
nmi_poll("b5_L81C2");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_pc = 0x81F2;
nmi_poll("b5_L81C2");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x81F4;
nmi_poll("b5_L81C2");
nmi_poll("b5_L81C2");
cycles += 3;
b5_entry_80B6(); return;
nmi_pc = 0x81F7;
nmi_poll("b5_L81C2");
}
static void __attribute__((used)) b5_L81F7(void) {
nmi_pc = 0x81F7;
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x81FA;
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x81FD;
nmi_poll("b5_L81F7");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0775 + X)) - 1); WR((uint16_t)(0x0775 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x8200;
nmi_poll("b5_L81F7");
A = RD((uint16_t)(0x0775 + X)); setZN(A);
cycles += 4 + ((((0x775 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8203;
nmi_poll("b5_L81F7");
WR(0xE5, A);
cycles += 3;
nmi_pc = 0x8205;
nmi_poll("b5_L81F7");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0x8207;
nmi_poll("b5_L81F7");
WR(0xE6, A);
cycles += 3;
nmi_pc = 0x8209;
nmi_poll("b5_L81F7");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0x820B;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x820D;
nmi_poll("b5_L81F7");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x820F;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8210;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8212;
nmi_poll("b5_L81F7");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x8214;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8215;
nmi_poll("b5_L81F7");
{ _cycpp = (uint16_t)(RD(0xE5) | ((uint16_t)RD((uint16_t)(((0xE5) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8217;
nmi_poll("b5_L81F7");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x8218;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8219;
nmi_poll("b5_L81F7");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x821A;
nmi_poll("b5_L81F7");
nmi_poll("b5_L81F7");
cycles += 3;
b5_entry_80B8(); return;
nmi_pc = 0x821D;
nmi_poll("b5_L81F7");
}
static void __attribute__((used)) b5_L821D(void) {
nmi_pc = 0x821D;
nmi_poll("b5_L821D");
WR(0xE3, A);
cycles += 3;
nmi_pc = 0x821F;
nmi_poll("b5_L821D");
{ _cycpp = (uint16_t)(RD(0xE1) | ((uint16_t)RD((uint16_t)(((0xE1) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8221;
nmi_poll("b5_L821D");
WR((uint16_t)(0x072D + X), A);
cycles += 5;
nmi_pc = 0x8224;
nmi_poll("b5_L821D");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8225;
nmi_poll("b5_L821D");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x8226;
nmi_poll("b5_L821D");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0x8227;
nmi_poll("b5_L821D");
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_pc = 0x8229;
nmi_poll("b5_L821D");
WR((uint16_t)(0x071B + X), A);
cycles += 5;
nmi_pc = 0x822C;
nmi_poll("b5_L821D");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_pc = 0x822E;
nmi_poll("b5_L821D");
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0x8230;
nmi_poll("b5_L821D");
WR((uint16_t)(0x0724 + X), A);
cycles += 5;
nmi_pc = 0x8233;
nmi_poll("b5_L821D");
A = RD(0xE4); setZN(A);
cycles += 3;
nmi_pc = 0x8235;
nmi_poll("b5_L821D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8298(); return; }
nmi_pc = 0x8237;
nmi_poll("b5_L821D");
A = RD(0xE3); setZN(A);
cycles += 3;
nmi_pc = 0x8239;
nmi_poll("b5_L821D");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_entry_827A(); return; }
nmi_pc = 0x823B;
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x823C;
nmi_poll("b5_L821D");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x823D;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x83EE + Y)); setZN(A);
cycles += 4 + ((((0x83EE + Y) & 0xFF00) != 0x8300) ? 1 : 0);
nmi_pc = 0x8240;
nmi_poll("b5_L821D");
WR(0xE1, A);
cycles += 3;
nmi_pc = 0x8242;
nmi_poll("b5_L821D");
WR((uint16_t)(0x0790 + X), A);
cycles += 5;
nmi_pc = 0x8245;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x83EF + Y)); setZN(A);
cycles += 4 + ((((0x83EF + Y) & 0xFF00) != 0x8300) ? 1 : 0);
nmi_pc = 0x8248;
nmi_poll("b5_L821D");
{ uint8_t _m = 0x08; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x824A;
nmi_poll("b5_L821D");
WR(0xE2, A);
cycles += 3;
nmi_pc = 0x824C;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x824F;
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8250;
nmi_poll("b5_L821D");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x8251;
nmi_poll("b5_L821D");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x8252;
nmi_poll("b5_L821D");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_L8260(); return; }
nmi_pc = 0x8254;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8257;
nmi_poll("b5_L821D");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_pc = 0x825A;
nmi_poll("b5_L821D");
A = RD((uint16_t)(0x0712 + X)); setZN(A);
cycles += 4 + ((((0x712 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x825D;
nmi_poll("b5_L821D");
WR((uint16_t)(0x4001 + Y), A);
cycles += 5;
nmi_pc = 0x8260;
nmi_poll("b5_L821D");
b5_L8260();
return;
}
static void __attribute__((used)) b5_L8260(void) {
nmi_pc = 0x8260;
nmi_poll("b5_L8260");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8263;
nmi_poll("b5_L8260");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L826A(); return; }
nmi_pc = 0x8265;
nmi_poll("b5_L8260");
A = RD(0xE2); setZN(A);
cycles += 3;
nmi_pc = 0x8267;
nmi_poll("b5_L8260");
WR((uint16_t)(0x4003 + Y), A);
cycles += 5;
nmi_pc = 0x826A;
nmi_poll("b5_L8260");
b5_L826A();
return;
}
static void __attribute__((used)) b5_L826A(void) {
nmi_pc = 0x826A;
nmi_poll("b5_L826A");
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x826D;
nmi_poll("b5_L826A");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x826E;
nmi_poll("b5_L826A");
{ uint8_t _m = RD(0xE1); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_pc = 0x8270;
nmi_poll("b5_L826A");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_pc = 0x8273;
nmi_poll("b5_L826A");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8276;
nmi_poll("b5_L826A");
{ uint8_t _m = 0x40; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8278;
nmi_poll("b5_L826A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L829D(); return; }
nmi_pc = 0x827A;
nmi_poll("b5_L826A");
b5_entry_827A();
return;
}
static void __attribute__((used)) b5_entry_827A(void) {
nmi_pc = 0x827A;
nmi_poll("b5_entry_827A");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x827D;
nmi_poll("b5_entry_827A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x827E;
nmi_poll("b5_entry_827A");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x827F;
nmi_poll("b5_entry_827A");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x8280;
nmi_poll("b5_entry_827A");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0x8282;
nmi_poll("b5_entry_827A");
{ uint8_t _m = 0x08; uint8_t _r = (uint8_t)(Y - _m); P = (uint8_t)((P & 0x7C) | (Y >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x8284;
nmi_poll("b5_entry_827A");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L828D(); return; }
nmi_pc = 0x8286;
nmi_poll("b5_entry_827A");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x8288;
nmi_poll("b5_entry_827A");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_pc = 0x828B;
nmi_poll("b5_entry_827A");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8298(); return; }
nmi_pc = 0x828D;
nmi_poll("b5_entry_827A");
b5_L828D();
return;
}
static void __attribute__((used)) b5_L828D(void) {
nmi_pc = 0x828D;
nmi_poll("b5_L828D");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_pc = 0x8290;
nmi_poll("b5_L828D");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x8292;
nmi_poll("b5_L828D");
WR((uint16_t)(0x4001 + Y), A);
cycles += 5;
nmi_pc = 0x8295;
nmi_poll("b5_L828D");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_pc = 0x8298;
nmi_poll("b5_L828D");
b5_L8298();
return;
}
static void __attribute__((used)) b5_L8298(void) {
nmi_pc = 0x8298;
nmi_poll("b5_L8298");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x829B;
nmi_poll("b5_L8298");
{ uint8_t _m = 0xBF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x829D;
nmi_poll("b5_L8298");
b5_L829D();
return;
}
static void __attribute__((used)) b5_L829D(void) {
nmi_pc = 0x829D;
nmi_poll("b5_L829D");
WR((uint16_t)(0x0700 + X), A);
cycles += 5;
nmi_pc = 0x82A0;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82A3;
nmi_poll("b5_L829D");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82CD(); return; }
nmi_pc = 0x82A5;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82A8;
nmi_poll("b5_L829D");
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82AA;
nmi_poll("b5_L829D");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L82CD(); return; }
nmi_pc = 0x82AC;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82AF;
nmi_poll("b5_L829D");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L82CD(); return; }
nmi_pc = 0x82B1;
nmi_poll("b5_L829D");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82B3;
nmi_poll("b5_L829D");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_pc = 0x82B6;
nmi_poll("b5_L829D");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82B8;
nmi_poll("b5_L829D");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_pc = 0x82BB;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82BE;
nmi_poll("b5_L829D");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82C0;
nmi_poll("b5_L829D");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82CA(); return; }
nmi_pc = 0x82C2;
nmi_poll("b5_L829D");
A = RD((uint16_t)(0x0709 + X)); setZN(A);
cycles += 4 + ((((0x709 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82C5;
nmi_poll("b5_L829D");
WR((uint16_t)(0x076C + X), A);
cycles += 5;
nmi_pc = 0x82C8;
nmi_poll("b5_L829D");
WR(0xE7, A);
cycles += 3;
nmi_pc = 0x82CA;
nmi_poll("b5_L829D");
b5_L82CA();
return;
}
static void __attribute__((used)) b5_L82CA(void) {
nmi_pc = 0x82CA;
nmi_poll("b5_L82CA");
nmi_poll("b5_L82CA");
cycles += 3;
b5_entry_8383(); return;
nmi_pc = 0x82CD;
nmi_poll("b5_L82CA");
}
static void __attribute__((used)) b5_L82CD(void) {
nmi_pc = 0x82CD;
nmi_poll("b5_L82CD");
cycles += 6;
return;
nmi_pc = 0x82CE;
nmi_poll("b5_L82CD");
}
static void __attribute__((used)) b5_entry_82CE(void) {
nmi_pc = 0x82CE;
nmi_poll("b5_entry_82CE");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82D1;
nmi_poll("b5_entry_82CE");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L82D4(); return; }
nmi_pc = 0x82D3;
nmi_poll("b5_entry_82CE");
cycles += 6;
return;
nmi_pc = 0x82D4;
nmi_poll("b5_entry_82CE");
}
static void __attribute__((used)) b5_L82D4(void) {
nmi_pc = 0x82D4;
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x07A2 + X)); setZN(A);
cycles += 4 + ((((0x7A2 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82D7;
nmi_poll("b5_L82D4");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L8342(); return; }
nmi_pc = 0x82D9;
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82DC;
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x40; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82DE;
nmi_poll("b5_L82D4");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_L830E(); return; }
nmi_pc = 0x82E0;
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82E3;
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82E5;
nmi_poll("b5_L82D4");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L82F6(); return; }
nmi_pc = 0x82E7;
nmi_poll("b5_L82D4");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82EA;
nmi_poll("b5_L82D4");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82EC;
nmi_poll("b5_L82D4");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x82ED;
nmi_poll("b5_L82D4");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82F0;
nmi_poll("b5_L82D4");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_pc = 0x82F3;
nmi_poll("b5_L82D4");
nmi_poll("b5_L82D4");
cycles += 3;
b5_entry_82F9(); return;
nmi_pc = 0x82F6;
nmi_poll("b5_L82D4");
}
static void __attribute__((used)) b5_L82F6(void) {
nmi_pc = 0x82F6;
nmi_poll("b5_L82F6");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) + 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x82F9;
nmi_poll("b5_L82F6");
b5_entry_82F9();
return;
}
static void __attribute__((used)) b5_entry_82F9(void) {
nmi_pc = 0x82F9;
nmi_poll("b5_entry_82F9");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x82FC;
nmi_poll("b5_entry_82F9");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x82FE;
nmi_poll("b5_entry_82F9");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8301;
nmi_poll("b5_entry_82F9");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_entry_833C(); return; }
nmi_pc = 0x8303;
nmi_poll("b5_entry_82F9");
b5_L8303();
return;
}
static void __attribute__((used)) b5_L8303(void) {
nmi_pc = 0x8303;
nmi_poll("b5_L8303");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8306;
nmi_poll("b5_L8303");
{ uint8_t _m = 0x40; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8308;
nmi_poll("b5_L8303");
WR((uint16_t)(0x0748 + X), A);
cycles += 5;
nmi_pc = 0x830B;
nmi_poll("b5_L8303");
nmi_poll("b5_L8303");
cycles += 3;
b5_entry_833C(); return;
nmi_pc = 0x830E;
nmi_poll("b5_L8303");
}
static void __attribute__((used)) b5_L830E(void) {
nmi_pc = 0x830E;
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8311;
nmi_poll("b5_L830E");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8313;
nmi_poll("b5_L830E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L832A(); return; }
nmi_pc = 0x8315;
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8318;
nmi_poll("b5_L830E");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x831A;
nmi_poll("b5_L830E");
WR(0x07FF, A);
cycles += 4;
nmi_pc = 0x831D;
nmi_poll("b5_L830E");
A = RD((uint16_t)(0x0799 + X)); setZN(A);
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8320;
nmi_poll("b5_L830E");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_pc = 0x8321;
nmi_poll("b5_L830E");
{ uint8_t _m = RD(0x07FF); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4;
nmi_pc = 0x8324;
nmi_poll("b5_L830E");
WR((uint16_t)(0x0799 + X), A);
cycles += 5;
nmi_pc = 0x8327;
nmi_poll("b5_L830E");
nmi_poll("b5_L830E");
cycles += 3;
b5_entry_832D(); return;
nmi_pc = 0x832A;
nmi_poll("b5_L830E");
}
static void __attribute__((used)) b5_L832A(void) {
nmi_pc = 0x832A;
nmi_poll("b5_L832A");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0799 + X)) - 1); WR((uint16_t)(0x0799 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x832D;
nmi_poll("b5_L832A");
b5_entry_832D();
return;
}
static void __attribute__((used)) b5_entry_832D(void) {
nmi_pc = 0x832D;
nmi_poll("b5_entry_832D");
A = RD((uint16_t)(0x0748 + X)); setZN(A);
cycles += 4 + ((((0x748 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8330;
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8332;
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8334;
nmi_poll("b5_entry_832D");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x8335;
nmi_poll("b5_entry_832D");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0x8337;
nmi_poll("b5_entry_832D");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x833A;
nmi_poll("b5_entry_832D");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8303(); return; }
nmi_pc = 0x833C;
nmi_poll("b5_entry_832D");
b5_entry_833C();
return;
}
static void __attribute__((used)) b5_entry_833C(void) {
nmi_pc = 0x833C;
nmi_poll("b5_entry_833C");
A = RD((uint16_t)(0x07AB + X)); setZN(A);
cycles += 4 + ((((0x7AB + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x833F;
nmi_poll("b5_entry_833C");
WR((uint16_t)(0x07A2 + X), A);
cycles += 5;
nmi_pc = 0x8342;
nmi_poll("b5_entry_833C");
b5_L8342();
return;
}
static void __attribute__((used)) b5_L8342(void) {
nmi_pc = 0x8342;
nmi_poll("b5_L8342");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x07A2 + X)) - 1); WR((uint16_t)(0x07A2 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x8345;
nmi_poll("b5_L8342");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8348;
nmi_poll("b5_L8342");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x834A;
nmi_poll("b5_L8342");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x834B;
nmi_poll("b5_L8342");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x834C;
nmi_poll("b5_L8342");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x834D;
nmi_poll("b5_L8342");
A = RD((uint16_t)(0x075A + X)); setZN(A);
cycles += 4 + ((((0x75A + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8350;
nmi_poll("b5_L8342");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x8351;
nmi_poll("b5_L8342");
{ uint8_t _m = RD((uint16_t)(0x0790 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x790 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8354;
nmi_poll("b5_L8342");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0x8355;
nmi_poll("b5_L8342");
{ uint8_t _m = RD((uint16_t)(0x0799 + X)); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 4 + ((((0x799 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8358;
nmi_poll("b5_L8342");
WR((uint16_t)(0x4002 + Y), A);
cycles += 5;
nmi_pc = 0x835B;
nmi_poll("b5_L8342");
b5_L835B();
return;
}
static void __attribute__((used)) b5_L835B(void) {
nmi_pc = 0x835B;
nmi_poll("b5_L835B");
cycles += 6;
return;
nmi_pc = 0x835C;
nmi_poll("b5_L835B");
}
static void __attribute__((used)) b5_entry_835C(void) {
nmi_pc = 0x835C;
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x835F;
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L835B(); return; }
nmi_pc = 0x8361;
nmi_poll("b5_entry_835C");
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x8363;
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L835B(); return; }
nmi_pc = 0x8365;
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8368;
nmi_poll("b5_entry_835C");
{ uint8_t _m = 0x10; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x836A;
nmi_poll("b5_entry_835C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83AC(); return; }
nmi_pc = 0x836C;
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x0751 + X)); setZN(A);
cycles += 4 + ((((0x751 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x836F;
nmi_poll("b5_entry_835C");
WR(0xE7, A);
cycles += 3;
nmi_pc = 0x8371;
nmi_poll("b5_entry_835C");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8374;
nmi_poll("b5_entry_835C");
WR(0xE8, A);
cycles += 3;
nmi_pc = 0x8376;
nmi_poll("b5_entry_835C");
b5_entry_8376();
return;
}
static void __attribute__((used)) b5_entry_8376(void) {
nmi_pc = 0x8376;
nmi_poll("b5_entry_8376");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x8379;
nmi_poll("b5_entry_8376");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x837A;
nmi_poll("b5_entry_8376");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x837C;
nmi_poll("b5_entry_8376");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L8395(); return; }
nmi_pc = 0x837E;
nmi_poll("b5_entry_8376");
WR(0xE7, A);
cycles += 3;
nmi_pc = 0x8380;
nmi_poll("b5_entry_8376");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) + 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x8383;
nmi_poll("b5_entry_8376");
b5_entry_8383();
return;
}
static void __attribute__((used)) b5_entry_8383(void) {
nmi_pc = 0x8383;
nmi_poll("b5_entry_8383");
A = RD(0xE4); setZN(A);
cycles += 3;
nmi_pc = 0x8385;
nmi_poll("b5_entry_8383");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_L8394(); return; }
nmi_pc = 0x8387;
nmi_poll("b5_entry_8383");
A = RD((uint16_t)(0x0700 + X)); setZN(A);
cycles += 4 + ((((0x700 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x838A;
nmi_poll("b5_entry_8383");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x838C;
nmi_poll("b5_entry_8383");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x838D;
nmi_poll("b5_entry_8383");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0x838E;
nmi_poll("b5_entry_8383");
Y = A; setZN(Y);
cycles += 2;
nmi_pc = 0x838F;
nmi_poll("b5_entry_8383");
A = RD(0xE7); setZN(A);
cycles += 3;
nmi_pc = 0x8391;
nmi_poll("b5_entry_8383");
WR((uint16_t)(0x4000 + Y), A);
cycles += 5;
nmi_pc = 0x8394;
nmi_poll("b5_entry_8383");
b5_L8394();
return;
}
static void __attribute__((used)) b5_L8394(void) {
nmi_pc = 0x8394;
nmi_poll("b5_L8394");
cycles += 6;
return;
nmi_pc = 0x8395;
nmi_poll("b5_L8394");
}
static void __attribute__((used)) b5_L8395(void) {
nmi_pc = 0x8395;
nmi_poll("b5_L8395");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x8396;
nmi_poll("b5_L8395");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x8398;
nmi_poll("b5_L8395");
cycles += 2;
if (((P & 0x80))) { cycles += 1; b5_L83A3(); return; }
nmi_pc = 0x839A;
nmi_poll("b5_L8395");
b5_L839A();
return;
}
static void __attribute__((used)) b5_L839A(void) {
nmi_pc = 0x839A;
nmi_poll("b5_L839A");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x839D;
nmi_poll("b5_L839A");
{ uint8_t _m = 0x20; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0x839F;
nmi_poll("b5_L839A");
WR((uint16_t)(0x0787 + X), A);
cycles += 5;
nmi_pc = 0x83A2;
nmi_poll("b5_L839A");
cycles += 6;
return;
nmi_pc = 0x83A3;
nmi_poll("b5_L839A");
}
static void __attribute__((used)) b5_L83A3(void) {
nmi_pc = 0x83A3;
nmi_poll("b5_L83A3");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0x83A4;
nmi_poll("b5_L83A3");
{ _cycpp = (uint16_t)(RD(0xE7) | ((uint16_t)RD((uint16_t)(((0xE7) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0x83A6;
nmi_poll("b5_L83A3");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_pc = 0x83A9;
nmi_poll("b5_L83A3");
nmi_poll("b5_L83A3");
cycles += 3;
b5_entry_8376(); return;
nmi_pc = 0x83AC;
nmi_poll("b5_L83A3");
}
static void __attribute__((used)) b5_L83AC(void) {
nmi_pc = 0x83AC;
nmi_poll("b5_L83AC");
A = RD((uint16_t)(0x0763 + X)); setZN(A);
cycles += 4 + ((((0x763 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83AF;
nmi_poll("b5_L83AC");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L83B5(); return; }
nmi_pc = 0x83B1;
nmi_poll("b5_L83AC");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x0763 + X)) - 1); WR((uint16_t)(0x0763 + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x83B4;
nmi_poll("b5_L83AC");
cycles += 6;
return;
nmi_pc = 0x83B5;
nmi_poll("b5_L83AC");
}
static void __attribute__((used)) b5_L83B5(void) {
nmi_pc = 0x83B5;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x0787 + X)); setZN(A);
cycles += 4 + ((((0x787 + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83B8;
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83BA;
nmi_poll("b5_L83B5");
WR((uint16_t)(0x0763 + X), A);
cycles += 5;
nmi_pc = 0x83BD;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83C0;
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x20; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83C2;
nmi_poll("b5_L83B5");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_L83D8(); return; }
nmi_pc = 0x83C4;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83C7;
nmi_poll("b5_L83B5");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83C9;
nmi_poll("b5_L83B5");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
nmi_pc = 0x83CB;
nmi_poll("b5_L83B5");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) - 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x83CE;
nmi_poll("b5_L83B5");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83D1;
nmi_poll("b5_L83B5");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83D3;
nmi_poll("b5_L83B5");
WR(0xE7, A);
cycles += 3;
nmi_pc = 0x83D5;
nmi_poll("b5_L83B5");
nmi_poll("b5_L83B5");
cycles += 3;
b5_entry_8383(); return;
nmi_pc = 0x83D8;
nmi_poll("b5_L83B5");
}
static void __attribute__((used)) b5_L83D8(void) {
nmi_pc = 0x83D8;
nmi_poll("b5_L83D8");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83DB;
nmi_poll("b5_L83D8");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83DD;
nmi_poll("b5_L83D8");
{ uint8_t _m = 0x0F; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0x83DF;
nmi_poll("b5_L83D8");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_L839A(); return; }
nmi_pc = 0x83E1;
nmi_poll("b5_L83D8");
{ uint8_t _v = (uint8_t)(RD((uint16_t)(0x076C + X)) + 1); WR((uint16_t)(0x076C + X), _v); setZN(_v); }
cycles += 7;
nmi_pc = 0x83E4;
nmi_poll("b5_L83D8");
A = RD((uint16_t)(0x076C + X)); setZN(A);
cycles += 4 + ((((0x76C + X) & 0xFF00) != 0x700) ? 1 : 0);
nmi_pc = 0x83E7;
nmi_poll("b5_L83D8");
{ uint8_t _m = 0xDF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0x83E9;
nmi_poll("b5_L83D8");
WR(0xE7, A);
cycles += 3;
nmi_pc = 0x83EB;
nmi_poll("b5_L83D8");
nmi_poll("b5_L83D8");
cycles += 3;
b5_entry_8383(); return;
nmi_pc = 0x83EE;
nmi_poll("b5_L83D8");
}
static void __attribute__((used)) b5_entry_BDF6(void) {
nmi_pc = 0xBDF6;
nmi_poll("b5_entry_BDF6");
{ uint8_t _m = 0x54; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xBDF8;
nmi_poll("b5_entry_BDF6");
cycles += 2;
if ((!(P & 0x02))) { cycles += 2; b5_LBE16(); return; }
nmi_pc = 0xBDFA;
nmi_poll("b5_entry_BDF6");
A = RD(0xBDBC); setZN(A);
cycles += 4;
nmi_pc = 0xBDFD;
nmi_poll("b5_entry_BDF6");
WR(0x07F0, A);
cycles += 4;
nmi_pc = 0xBE00;
nmi_poll("b5_entry_BDF6");
A = RD(0xBDBD); setZN(A);
cycles += 4;
nmi_pc = 0xBE03;
nmi_poll("b5_entry_BDF6");
WR(0x07F1, A);
cycles += 4;
nmi_pc = 0xBE06;
nmi_poll("b5_entry_BDF6");
b5_LBE06();
return;
}
static void __attribute__((used)) b5_LBE06(void) {
nmi_pc = 0xBE06;
nmi_poll("b5_LBE06");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0xBE08;
nmi_poll("b5_LBE06");
WR(0x07F2, A);
cycles += 4;
nmi_pc = 0xBE0B;
nmi_poll("b5_LBE06");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBE0D;
nmi_poll("b5_LBE06");
WR(0x07F3, A);
cycles += 4;
nmi_pc = 0xBE10;
nmi_poll("b5_LBE06");
WR(0x07F4, A);
cycles += 4;
nmi_pc = 0xBE13;
nmi_poll("b5_LBE06");
WR(0x07F5, A);
cycles += 4;
nmi_pc = 0xBE16;
nmi_poll("b5_LBE06");
b5_LBE16();
return;
}
static void __attribute__((used)) b5_LBE16(void) {
nmi_pc = 0xBE16;
nmi_poll("b5_LBE16");
cycles += 6;
return;
nmi_pc = 0xBE17;
nmi_poll("b5_LBE16");
}
static void __attribute__((used)) b5_entry_BE17(void) {
nmi_pc = 0xBE17;
nmi_poll("b5_entry_BE17");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBE19;
nmi_poll("b5_entry_BE17");
WR(0x07F1, A);
cycles += 4;
nmi_pc = 0xBE1C;
nmi_poll("b5_entry_BE17");
A = 0x0F; setZN(A);
cycles += 2;
nmi_pc = 0xBE1E;
nmi_poll("b5_entry_BE17");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0xBE21;
nmi_poll("b5_entry_BE17");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE06(); return; }
nmi_pc = 0xBE23;
nmi_poll("b5_entry_BE17");
b5_entry_BE23();
return;
}
static void __attribute__((used)) b5_entry_BE23(void) {
nmi_pc = 0xBE23;
nmi_poll("b5_entry_BE23");
A = RD(0x07F1); setZN(A);
cycles += 4;
nmi_pc = 0xBE26;
nmi_poll("b5_entry_BE23");
WR(0xBE, A);
cycles += 3;
nmi_pc = 0xBE28;
nmi_poll("b5_entry_BE23");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBE16(); return; }
nmi_pc = 0xBE2A;
nmi_poll("b5_entry_BE23");
{ uint8_t _v = (uint8_t)(RD(0x07F2) - 1); WR(0x07F2, _v); setZN(_v); }
cycles += 6;
nmi_pc = 0xBE2D;
nmi_poll("b5_entry_BE23");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBE16(); return; }
nmi_pc = 0xBE2F;
nmi_poll("b5_entry_BE23");
A = RD(0x07F0); setZN(A);
cycles += 4;
nmi_pc = 0xBE32;
nmi_poll("b5_entry_BE23");
WR(0xBD, A);
cycles += 3;
nmi_pc = 0xBE34;
nmi_poll("b5_entry_BE23");
b5_entry_BE34();
return;
}
static void __attribute__((used)) b5_entry_BE34(void) {
nmi_pc = 0xBE34;
nmi_poll("b5_entry_BE34");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0xBE36;
nmi_poll("b5_entry_BE34");
b5_entry_BE36();
return;
}
static void __attribute__((used)) b5_entry_BE36(void) {
nmi_pc = 0xBE36;
nmi_poll("b5_entry_BE36");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE38;
nmi_poll("b5_entry_BE36");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBE39;
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xBE3B;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE58(); return; }
nmi_pc = 0xBE3D;
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xBE3F;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBE50(); return; }
nmi_pc = 0xBE41;
nmi_poll("b5_entry_BE36");
{ uint8_t _m = 0xC0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xBE43;
nmi_poll("b5_entry_BE36");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b5_LBEAF(); return; }
nmi_pc = 0xBE45;
nmi_poll("b5_entry_BE36");
A = 0x0F; setZN(A);
cycles += 2;
nmi_pc = 0xBE47;
nmi_poll("b5_entry_BE36");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0xBE4A;
nmi_poll("b5_entry_BE36");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBE4C;
nmi_poll("b5_entry_BE36");
WR(0x07F1, A);
cycles += 4;
nmi_pc = 0xBE4F;
nmi_poll("b5_entry_BE36");
cycles += 6;
return;
nmi_pc = 0xBE50;
nmi_poll("b5_entry_BE36");
}
static void __attribute__((used)) b5_LBE50(void) {
nmi_pc = 0xBE50;
nmi_poll("b5_LBE50");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_pc = 0xBE53;
nmi_poll("b5_LBE50");
{ uint8_t _m = 0x01; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBE55;
nmi_poll("b5_LBE50");
WR(0x07F5, A);
cycles += 4;
nmi_pc = 0xBE58;
nmi_poll("b5_LBE50");
b5_LBE58();
return;
}
static void __attribute__((used)) b5_LBE58(void) {
nmi_pc = 0xBE58;
nmi_poll("b5_LBE58");
WR(0xBF, A);
cycles += 3;
nmi_pc = 0xBE5A;
nmi_poll("b5_LBE58");
A = 0x0F; setZN(A);
cycles += 2;
nmi_pc = 0xBE5C;
nmi_poll("b5_LBE58");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0xBE5F;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE61;
nmi_poll("b5_LBE58");
WR(0x07F2, A);
cycles += 4;
nmi_pc = 0xBE64;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBE65;
nmi_poll("b5_LBE58");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xBE66;
nmi_poll("b5_LBE58");
A = Y; setZN(A);
cycles += 2;
nmi_pc = 0xBE67;
nmi_poll("b5_LBE58");
{ uint8_t _m = RD(0xBD); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_pc = 0xBE69;
nmi_poll("b5_LBE58");
WR(0x07F0, A);
cycles += 4;
nmi_pc = 0xBE6C;
nmi_poll("b5_LBE58");
A = RD(0xBE); setZN(A);
cycles += 3;
nmi_pc = 0xBE6E;
nmi_poll("b5_LBE58");
{ uint8_t _m = 0x00; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xBE70;
nmi_poll("b5_LBE58");
WR(0x07F1, A);
cycles += 4;
nmi_pc = 0xBE73;
nmi_poll("b5_LBE58");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_pc = 0xBE76;
nmi_poll("b5_LBE58");
{ uint8_t _m = 0x01; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBE78;
nmi_poll("b5_LBE58");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEA6(); return; }
nmi_pc = 0xBE7A;
nmi_poll("b5_LBE58");
A = RD(0xBF); setZN(A);
cycles += 3;
nmi_pc = 0xBE7C;
nmi_poll("b5_LBE58");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_pc = 0xBE7D;
nmi_poll("b5_LBE58");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xBE7E;
nmi_poll("b5_LBE58");
A = RD((uint16_t)(0xBDBE + X)); setZN(A);
cycles += 4 + ((((0xBDBE + X) & 0xFF00) != 0xBD00) ? 1 : 0);
nmi_pc = 0xBE81;
nmi_poll("b5_LBE58");
WR(0xBD, A);
cycles += 3;
nmi_pc = 0xBE83;
nmi_poll("b5_LBE58");
A = RD((uint16_t)(0xBDBF + X)); setZN(A);
cycles += 4 + ((((0xBDBF + X) & 0xFF00) != 0xBD00) ? 1 : 0);
nmi_pc = 0xBE86;
nmi_poll("b5_LBE58");
WR(0xBE, A);
cycles += 3;
nmi_pc = 0xBE88;
nmi_poll("b5_LBE58");
Y = 0x00; setZN(Y);
cycles += 2;
nmi_pc = 0xBE8A;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE8C;
nmi_poll("b5_LBE58");
WR(0x4010, A);
cycles += 4;
nmi_pc = 0xBE8F;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBE90;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE92;
nmi_poll("b5_LBE58");
WR(0x4011, A);
cycles += 4;
nmi_pc = 0xBE95;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBE96;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE98;
nmi_poll("b5_LBE58");
WR(0x4012, A);
cycles += 4;
nmi_pc = 0xBE9B;
nmi_poll("b5_LBE58");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBE9C;
nmi_poll("b5_LBE58");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBE9E;
nmi_poll("b5_LBE58");
WR(0x4013, A);
cycles += 4;
nmi_pc = 0xBEA1;
nmi_poll("b5_LBE58");
A = 0x1F; setZN(A);
cycles += 2;
nmi_pc = 0xBEA3;
nmi_poll("b5_LBE58");
WR(0x4015, A);
cycles += 4;
nmi_pc = 0xBEA6;
nmi_poll("b5_LBE58");
b5_LBEA6();
return;
}
static void __attribute__((used)) b5_LBEA6(void) {
nmi_pc = 0xBEA6;
nmi_poll("b5_LBEA6");
A = RD(0x07F5); setZN(A);
cycles += 4;
nmi_pc = 0xBEA9;
nmi_poll("b5_LBEA6");
{ uint8_t _m = 0xFE; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBEAB;
nmi_poll("b5_LBEA6");
WR(0x07F5, A);
cycles += 4;
nmi_pc = 0xBEAE;
nmi_poll("b5_LBEA6");
cycles += 6;
return;
nmi_pc = 0xBEAF;
nmi_poll("b5_LBEA6");
}
static void __attribute__((used)) b5_LBEAF(void) {
nmi_pc = 0xBEAF;
nmi_poll("b5_LBEAF");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0xBEB0;
nmi_poll("b5_LBEAF");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b5_LBEC9(); return; }
nmi_pc = 0xBEB2;
nmi_poll("b5_LBEAF");
A = RD(0x07F3); setZN(A);
cycles += 4;
nmi_pc = 0xBEB5;
nmi_poll("b5_LBEAF");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEBE(); return; }
nmi_pc = 0xBEB7;
nmi_poll("b5_LBEAF");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBEB9;
nmi_poll("b5_LBEAF");
WR(0x07F3, A);
cycles += 4;
nmi_pc = 0xBEBC;
nmi_poll("b5_LBEAF");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
nmi_pc = 0xBEBE;
nmi_poll("b5_LBEAF");
b5_LBEBE();
return;
}
static void __attribute__((used)) b5_LBEBE(void) {
nmi_pc = 0xBEBE;
nmi_poll("b5_LBEBE");
{ uint8_t _v = (uint8_t)(RD(0x07F3) - 1); WR(0x07F3, _v); setZN(_v); }
cycles += 6;
nmi_pc = 0xBEC1;
nmi_poll("b5_LBEBE");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
nmi_pc = 0xBEC3;
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEC4;
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEC5;
nmi_poll("b5_LBEBE");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEC6;
nmi_poll("b5_LBEBE");
nmi_poll("b5_LBEBE");
cycles += 3;
b5_entry_BE36(); return;
nmi_pc = 0xBEC9;
nmi_poll("b5_LBEBE");
}
static void __attribute__((used)) b5_LBEC9(void) {
nmi_pc = 0xBEC9;
nmi_poll("b5_LBEC9");
A = RD(0x07F4); setZN(A);
cycles += 4;
nmi_pc = 0xBECC;
nmi_poll("b5_LBEC9");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBED5(); return; }
nmi_pc = 0xBECE;
nmi_poll("b5_LBEC9");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBED0;
nmi_poll("b5_LBEC9");
WR(0x07F4, A);
cycles += 4;
nmi_pc = 0xBED3;
nmi_poll("b5_LBEC9");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b5_LBEE0(); return; }
nmi_pc = 0xBED5;
nmi_poll("b5_LBEC9");
b5_LBED5();
return;
}
static void __attribute__((used)) b5_LBED5(void) {
nmi_pc = 0xBED5;
nmi_poll("b5_LBED5");
{ uint8_t _v = (uint8_t)(RD(0x07F4) - 1); WR(0x07F4, _v); setZN(_v); }
cycles += 6;
nmi_pc = 0xBED8;
nmi_poll("b5_LBED5");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBEE0(); return; }
nmi_pc = 0xBEDA;
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEDB;
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEDC;
nmi_poll("b5_LBED5");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEDD;
nmi_poll("b5_LBED5");
nmi_poll("b5_LBED5");
cycles += 3;
b5_entry_BE36(); return;
nmi_pc = 0xBEE0;
nmi_poll("b5_LBED5");
}
static void __attribute__((used)) b5_LBEE0(void) {
nmi_pc = 0xBEE0;
nmi_poll("b5_LBEE0");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEE1;
nmi_poll("b5_LBEE0");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBEE3;
nmi_poll("b5_LBEE0");
WR(0xBF, A);
cycles += 3;
nmi_pc = 0xBEE5;
nmi_poll("b5_LBEE0");
Y = (uint8_t)(Y + 1); setZN(Y);
cycles += 2;
nmi_pc = 0xBEE6;
nmi_poll("b5_LBEE0");
{ _cycpp = (uint16_t)(RD(0xBD) | ((uint16_t)RD((uint16_t)(((0xBD) + 1) & 0xFF)) << 8)); }
A = RD((uint16_t)(_cycpp + Y)); setZN(A);
cycles += 5 + ((((_cycpp + Y) & 0xFF00) != (_cycpp & 0xFF00)) ? 1 : 0);
nmi_pc = 0xBEE8;
nmi_poll("b5_LBEE0");
WR(0xBE, A);
cycles += 3;
nmi_pc = 0xBEEA;
nmi_poll("b5_LBEE0");
A = RD(0xBF); setZN(A);
cycles += 3;
nmi_pc = 0xBEEC;
nmi_poll("b5_LBEE0");
WR(0xBD, A);
cycles += 3;
nmi_pc = 0xBEEE;
nmi_poll("b5_LBEE0");
nmi_poll("b5_LBEE0");
cycles += 3;
b5_entry_BE34(); return;
nmi_pc = 0xBEF1;
nmi_poll("b5_LBEE0");
}
static void __attribute__((used)) b5_entry_BF52(void) {
nmi_pc = 0xBF52;
nmi_poll("b5_entry_BF52");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0xBF54;
nmi_poll("b5_entry_BF52");
WR(0x40, A);
cycles += 3;
nmi_pc = 0xBF56;
nmi_poll("b5_entry_BF52");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0xBF58;
nmi_poll("b5_entry_BF52");
WR(0x41, A);
cycles += 3;
nmi_pc = 0xBF5A;
nmi_poll("b5_entry_BF52");
nmi_poll("b5_entry_BF52");
cycles += 6;
stk[S] = 0xBF; S = (uint8_t)(S - 1);
stk[S] = 0x5C; S = (uint8_t)(S - 1);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_pc = 0xBF5D;
nmi_poll("b5_entry_BF52");
nmi_pc = 0xBF5D;
nmi_poll("b5_entry_BF52");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b5_LBF62(); return; }
nmi_pc = 0xBF5F;
nmi_poll("b5_entry_BF52");
nmi_poll("b5_entry_BF52");
cycles += 3;
b7_entry_C17A(); return;
nmi_pc = 0xBF62;
nmi_poll("b5_entry_BF52");
}
static void __attribute__((used)) b5_LBF62(void) {
nmi_pc = 0xBF62;
nmi_poll("b5_LBF62");
A = 0x0F; setZN(A);
cycles += 2;
nmi_pc = 0xBF64;
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
stk[S] = 0xBF; S = (uint8_t)(S - 1);
stk[S] = 0x66; S = (uint8_t)(S - 1);
b5_entry_B2C5();
S = (uint8_t)(S + 2);
nmi_pc = 0xBF67;
nmi_poll("b5_LBF62");
nmi_pc = 0xBF67;
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
stk[S] = 0xBF; S = (uint8_t)(S - 1);
stk[S] = 0x69; S = (uint8_t)(S - 1);
b7_entry_C138();
S = (uint8_t)(S + 2);
nmi_pc = 0xBF6A;
nmi_poll("b5_LBF62");
nmi_pc = 0xBF6A;
nmi_poll("b5_LBF62");
nmi_poll("b5_LBF62");
cycles += 6;
stk[S] = 0xBF; S = (uint8_t)(S - 1);
stk[S] = 0x6C; S = (uint8_t)(S - 1);
b7_entry_C0A2();
S = (uint8_t)(S + 2);
nmi_pc = 0xBF6D;
nmi_poll("b5_LBF62");
nmi_pc = 0xBF6D;
nmi_poll("b5_LBF62");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF75(); return; }
nmi_pc = 0xBF6F;
nmi_poll("b5_LBF62");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_pc = 0xBF71;
nmi_poll("b5_LBF62");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBF73;
nmi_poll("b5_LBF62");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF89(); return; }
nmi_pc = 0xBF75;
nmi_poll("b5_LBF62");
b5_LBF75();
return;
}
static void __attribute__((used)) b5_LBF75(void) {
nmi_pc = 0xBF75;
nmi_poll("b5_LBF75");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBF77;
nmi_poll("b5_LBF75");
WR(0x44, A);
cycles += 3;
nmi_pc = 0xBF79;
nmi_poll("b5_LBF75");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_pc = 0xBF7B;
nmi_poll("b5_LBF75");
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBF7D;
nmi_poll("b5_LBF75");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b5_LBF84(); return; }
nmi_pc = 0xBF7F;
nmi_poll("b5_LBF75");
A = 0x46; setZN(A);
cycles += 2;
nmi_pc = 0xBF81;
nmi_poll("b5_LBF75");
nmi_poll("b5_LBF75");
cycles += 3;
b5_entry_BF86(); return;
nmi_pc = 0xBF84;
nmi_poll("b5_LBF75");
}
static void __attribute__((used)) b5_LBF84(void) {
nmi_pc = 0xBF84;
nmi_poll("b5_LBF84");
A = 0x47; setZN(A);
cycles += 2;
nmi_pc = 0xBF86;
nmi_poll("b5_LBF84");
b5_entry_BF86();
return;
}
static void __attribute__((used)) b5_entry_BF86(void) {
nmi_pc = 0xBF86;
nmi_poll("b5_entry_BF86");
nmi_poll("b5_entry_BF86");
cycles += 3;
b7_entry_C063(); return;
nmi_pc = 0xBF89;
nmi_poll("b5_entry_BF86");
}
static void __attribute__((used)) b5_LBF89(void) {
nmi_pc = 0xBF89;
nmi_poll("b5_LBF89");
cycles += 6;
return;
nmi_pc = 0xBF8A;
nmi_poll("b5_LBF89");
}
static void __attribute__((used)) b5_entry_BFE5(void) {
nmi_pc = 0xBFE5;
nmi_poll("b5_entry_BFE5");
nmi_poll("b5_entry_BFE5");
cycles += 3;
b5_entry_8000(); return;
nmi_pc = 0xBFE8;
nmi_poll("b5_entry_BFE5");
}
static void __attribute__((used)) b5_entry_BFE8(void) {
nmi_pc = 0xBFE8;
nmi_poll("b5_entry_BFE8");
nmi_poll("b5_entry_BFE8");
cycles += 3;
b5_entry_8013(); return;
nmi_pc = 0xBFEB;
nmi_poll("b5_entry_BFE8");
}
static void __attribute__((used)) b5_entry_BFF1(void) {
nmi_pc = 0xBFF1;
nmi_poll("b5_entry_BFF1");
nmi_poll("b5_entry_BFF1");
cycles += 3;
b5_entry_8077(); return;
nmi_pc = 0xBFF4;
nmi_poll("b5_entry_BFF1");
}
static void b5_entry_B2C5(void) { __builtin_trap(); }
