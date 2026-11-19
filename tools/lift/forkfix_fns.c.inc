static void b6_entry_A2E9(void);
static void b4_entry_93BD(void);
static void b4_entry_B2B4(void);
static void b4_entry_B747(void);
static void b4_L960E(void);
static void b4_entry_9633(void);
static void b4_entry_96BF(void);
static void b4_entry_9638(void);
static void b4_LB4A9(void);
static void b4_entry_B243(void);
static void b4_entry_B264(void);
static void b4_entry_B2C5(void);
static void b7_LC015(void);
static void b7_LC054(void);
static void b7_LC04B(void);
static void b6_entry_A79E(void);
static void b6_entry_B1DE(void);
static void b6_entry_A25D(void);
static void b6_entry_9E9E(void);
static void b7_entry_E1BD(void);
static void b6_entry_9B81(void);
static void b6_LA27D(void);
static void __attribute__((used)) b6_LA74B(void) {
nmi_poll("b6_LA74B");
cycles += 3;
return;
}
static void __attribute__((used)) b6_LA74E(void) {
nmi_poll("b6_LA74E");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b6_LA74E");
nmi_poll("b6_LA74E");
cycles += 6;
nmi_poll("b6_LA74E");
S = (uint8_t)(S - 2);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA74E");
A = RD(0x49); setZN(A);
cycles += 3;
nmi_poll("b6_LA74E");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b6_LA74E");
cycles += 2;
nmi_poll("b6_LA74E");
if ((!(P & 0x01))) { cycles += 1; goto b6_LA75D_in; }
nmi_poll("b6_LA74E");
A = 0xF4; setZN(A);
cycles += 2;
nmi_poll("b6_LA74E");
cycles += 3;
nmi_poll("b6_LA74E");
goto b6_LA75F_in;
b6_LA75D_in:;
nmi_poll("b6_LA74E");
A = 0x0C; setZN(A);
cycles += 2;
nmi_poll("b6_LA74E");
b6_LA75F_in:;
nmi_poll("b6_LA74E");
WR(0x4C, A);
cycles += 3;
nmi_poll("b6_LA74E");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b6_LA74E");
WR(0x4D, A);
cycles += 3;
nmi_poll("b6_LA74E");
WR(0x50, A);
cycles += 3;
nmi_poll("b6_LA74E");
WR(0x51, A);
cycles += 3;
nmi_poll("b6_LA74E");
cycles += 6;
return;
}
static void __attribute__((used)) b4_L938E(void) {
nmi_poll("b4_L938E");
A = 0x03; setZN(A);
cycles += 2;
nmi_poll("b4_L938E");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_L938E");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_L938E");
cycles += 6;
return;
}
static void __attribute__((used)) b4_L8A69(void) {
nmi_poll("b4_L8A69");
;
cycles += 2;
nmi_poll("b4_L8A69");
;
cycles += 2;
nmi_poll("b4_L8A69");
;
cycles += 2;
nmi_poll("b4_L8A69");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_L8A69");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_L8A69");
nmi_poll("b4_L8A69");
cycles += 6;
nmi_poll("b4_L8A69");
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_L8A69");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_L8A69");
nmi_poll("b4_L8A69");
cycles += 6;
nmi_poll("b4_L8A69");
S = (uint8_t)(S - 2);
b4_entry_93BD();
S = (uint8_t)(S + 2);
nmi_poll("b4_L8A69");
{ uint8_t _v = (uint8_t)(RD(0x51) + 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_L8A69");
cycles += 2;
nmi_poll("b4_L8A69");
if ((!(P & 0x02))) { cycles += 1; goto b4_L8A84_in; }
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_L8A69");
b4_L8A84_in:;
nmi_poll("b4_L8A69");
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_L8A69");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_L8A69");
cycles += 2;
nmi_poll("b4_L8A69");
if ((!(P & 0x02))) { cycles += 1; goto b4_L8A8F_in; }
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
nmi_poll("b4_L8A69");
cycles += 6;
nmi_poll("b4_L8A69");
S = (uint8_t)(S - 2);
b7_entry_C11A();
S = (uint8_t)(S + 2);
nmi_poll("b4_L8A69");
b4_L8A8F_in:;
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_L8A69");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_L8A69");
X = RD(0x8901); setZN(X);
cycles += 2;
nmi_poll("b4_L8A69");
cycles += 4;
nmi_poll("b4_L8A69");
cycles += 2;
nmi_poll("b4_L8A69");
if ((!(P & 0x01))) { cycles += 1; goto b4_L8A9A_in; }
X = 0x17; setZN(X);
cycles += 2;
nmi_poll("b4_L8A69");
b4_L8A9A_in:;
nmi_poll("b4_L8A69");
A = RD((uint16_t)(0x86A3 + X)); setZN(A);
cycles += 4 + ((((0x86A3 + X) & 0xFF00) != 0x8600) ? 1 : 0);
nmi_poll("b4_L8A69");
;
cycles += 2;
nmi_poll("b4_L8A69");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_L8A69");
cycles += 6;
nmi_poll("b4_L8A69");
{ _cycpp = (uint16_t)(RD((uint16_t)((0x86 + X) & 0xFF)) | ((uint16_t)RD((uint16_t)(((0x86 + X) + 1) & 0xFF)) << 8)); }
A = RD(_cycpp); setZN(A);
cycles += 6;
nmi_poll("b4_L8A69");
{ _cycpp = (uint16_t)(RD(0x1B) | ((uint16_t)RD((uint16_t)(((0x1B) + 1) & 0xFF)) << 8)); }
WR((uint16_t)(_cycpp + Y), A);
cycles += 6;
nmi_poll("b4_L8A69");
cycles += 3;
nmi_poll("b4_L8A69");
b7_entry_C063();
return;
}
static void __attribute__((used)) b6_LA24D(void) {
nmi_poll("b6_LA24D");
cycles += 3;
nmi_poll("b6_LA24D");
b6_entry_A25D();
return;
}
static void __attribute__((used)) b6_LA250(void) {
nmi_poll("b6_LA250");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b6_LA250");
WR(0x42, A);
cycles += 3;
nmi_poll("b6_LA250");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b6_LA250");
WR(0x43, A);
cycles += 3;
nmi_poll("b6_LA250");
nmi_poll("b6_LA250");
cycles += 6;
nmi_poll("b6_LA250");
S = (uint8_t)(S - 2);
b7_entry_E083();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA250");
cycles += 2;
nmi_poll("b6_LA250");
if ((!(P & 0x02))) { cycles += 1; goto b6_LA27A_in; }
b6_entry_A25D();
return;
b6_LA27A_in:;
nmi_poll("b6_LA250");
cycles += 6;
nmi_poll("b6_LA250");
S = (uint8_t)(S - 2);
b6_entry_9B81();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA250");
b6_LA27D();
return;
}
static void __attribute__((used)) b6_LA237(void) {
nmi_poll("b6_LA237");
cycles += 3;
nmi_poll("b6_LA237");
b6_entry_A25D();
return;
}
static void __attribute__((used)) b6_LA23A(void) {
nmi_poll("b6_LA23A");
A = RD(0x9D); setZN(A);
cycles += 3;
nmi_poll("b6_LA23A");
WR(0x47, A);
cycles += 3;
nmi_poll("b6_LA23A");
A = RD(0x9E); setZN(A);
cycles += 3;
nmi_poll("b6_LA23A");
Y = A; setZN(Y);
cycles += 2;
nmi_poll("b6_LA23A");
nmi_poll("b6_LA23A");
cycles += 6;
nmi_poll("b6_LA23A");
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA23A");
cycles += 6;
nmi_poll("b6_LA23A");
S = (uint8_t)(S - 2);
b7_entry_D2B9();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA23A");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_LA23A");
nmi_poll("b6_LA23A");
cycles += 6;
nmi_poll("b6_LA23A");
S = (uint8_t)(S - 2);
b6_entry_9E9E();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA23A");
cycles += 6;
return;
}
static void __attribute__((used)) b6_LA76A(void) {
nmi_poll("b6_LA76A");
cycles += 3;
nmi_poll("b6_LA76A");
b6_entry_A79E();
return;
}
static void __attribute__((used)) b6_LA76D(void) {
nmi_poll("b6_LA76D");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b6_LA76D");
WR(0x42, A);
cycles += 3;
nmi_poll("b6_LA76D");
A = 0xC0; setZN(A);
cycles += 2;
nmi_poll("b6_LA76D");
WR(0x43, A);
cycles += 3;
nmi_poll("b6_LA76D");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_poll("b6_LA76D");
cycles += 2;
nmi_poll("b6_LA76D");
if ((!(P & 0x02))) { cycles += 1; goto b6_LA780_in; }
nmi_poll("b6_LA76D");
cycles += 6;
nmi_poll("b6_LA76D");
S = (uint8_t)(S - 2);
b7_entry_E005();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA76D");
cycles += 2;
nmi_poll("b6_LA76D");
if (((P & 0x02))) { cycles += 1; goto b6_LA79E_in; }
{ uint8_t _v = (uint8_t)(RD(0x50) + 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_LA76D");
b6_LA780_in:;
nmi_poll("b6_LA76D");
cycles += 6;
nmi_poll("b6_LA76D");
S = (uint8_t)(S - 2);
b7_entry_DF68();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA76D");
cycles += 6;
nmi_poll("b6_LA76D");
S = (uint8_t)(S - 2);
b7_entry_E0ED();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA76D");
{ uint8_t _m = RD(0x4C); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
nmi_poll("b6_LA76D");
cycles += 2;
nmi_poll("b6_LA76D");
if (((P & 0x80))) { cycles += 1; goto b6_LA79B_in; }
A = RD(0x4C); setZN(A);
cycles += 3;
nmi_poll("b6_LA76D");
{ uint8_t _m = 0x80; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b6_LA76D");
WR(0x9D, A);
cycles += 3;
nmi_poll("b6_LA76D");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b6_LA76D");
WR(0x9E, A);
cycles += 3;
nmi_poll("b6_LA76D");
A = 0x48; setZN(A);
cycles += 2;
nmi_poll("b6_LA76D");
WR(0xA0, A);
cycles += 3;
nmi_poll("b6_LA76D");
nmi_poll("b6_LA76D");
cycles += 6;
nmi_poll("b6_LA76D");
S = (uint8_t)(S - 2);
b7_entry_DF36();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA76D");
b6_LA79B_in:;
cycles += 6;
nmi_poll("b6_LA76D");
S = (uint8_t)(S - 2);
b6_entry_B1DE();
S = (uint8_t)(S + 2);
nmi_poll("b6_LA76D");
b6_LA79E_in:;
b6_entry_A79E();
return;
}
static void __attribute__((used)) b7_LC02D(void) {
nmi_poll("b7_LC02D");
nmi_poll("b7_LC02D");
cycles += 3;
nmi_poll("b7_LC02D");
b7_entry_E083(); return;
}
static void __attribute__((used)) b7_LC045(void) {
nmi_poll("b7_LC045");
nmi_poll("b7_LC045");
cycles += 3;
nmi_poll("b7_LC045");
b7_entry_E0ED(); return;
}
static void __attribute__((used)) b7_LC04E(void) {
nmi_poll("b7_LC04E");
nmi_poll("b7_LC04E");
cycles += 3;
nmi_poll("b7_LC04E");
b7_entry_E0FA(); return;
}
static void __attribute__((used)) b4_LB719(void) {
nmi_poll("b4_LB719");
cycles += 3;
nmi_poll("b4_LB719");
b4_entry_B747(); return;
}
static void __attribute__((used)) b4_LB71C(void) {
nmi_poll("b4_LB71C");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_LB71C");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_LB71C");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_LB71C");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_LB71C");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_poll("b4_LB71C");
cycles += 2;
nmi_poll("b4_LB71C");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB740_in; }
nmi_poll("b4_LB71C");
cycles += 6;
nmi_poll("b4_LB71C");
S = (uint8_t)(S - 2);
b7_LC045();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB71C");
cycles += 2;
nmi_poll("b4_LB71C");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB747_in; }
{ uint8_t _v = (uint8_t)(RD(0x50) + 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_LB71C");
nmi_poll("b4_LB71C");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_LB71C");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_LB71C");
nmi_poll("b4_LB71C");
cycles += 6;
nmi_poll("b4_LB71C");
S = (uint8_t)(S - 2);
b7_LC04E();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB71C");
cycles += 2;
nmi_poll("b4_LB71C");
if (((P & 0x80))) { cycles += 1; goto b4_LB73C_in; }
A = 0x38; setZN(A);
cycles += 2;
nmi_poll("b4_LB71C");
cycles += 2;
nmi_poll("b4_LB71C");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB73E_in; }
b4_LB73C_in:;
nmi_poll("b4_LB71C");
A = 0xC8; setZN(A);
cycles += 2;
nmi_poll("b4_LB71C");
b4_LB73E_in:;
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_LB71C");
b4_LB740_in:;
nmi_poll("b4_LB71C");
cycles += 6;
nmi_poll("b4_LB71C");
S = (uint8_t)(S - 2);
b7_LC02D();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB71C");
cycles += 2;
nmi_poll("b4_LB71C");
if (((P & 0x02))) { cycles += 1; goto b4_LB747_in; }
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_LB71C");
b4_LB747_in:;
b4_entry_B747();
return;
}
static void __attribute__((used)) b4_LB70C(void) {
nmi_poll("b4_LB70C");
cycles += 3;
nmi_poll("b4_LB70C");
cycles += 6;
return;
}
static void __attribute__((used)) b4_LB70F(void) {
nmi_poll("b4_LB70F");
A = 0x0A; setZN(A);
cycles += 2;
nmi_poll("b4_LB70F");
nmi_poll("b4_LB70F");
cycles += 6;
nmi_poll("b4_LB70F");
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB70F");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_LB70F");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_LB70F");
cycles += 6;
return;
}
static void __attribute__((used)) b4_L9398(void) {
nmi_poll("b4_L9398");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_L9398");
cycles += 2;
nmi_poll("b4_L9398");
if (((P & 0x80))) { cycles += 1; goto b4_L93BA_in; }
nmi_poll("b4_L9398");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_L9398");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_L9398");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_L9398");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_L9398");
nmi_poll("b4_L9398");
cycles += 6;
nmi_poll("b4_L9398");
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_L9398");
cycles += 2;
nmi_poll("b4_L9398");
if ((!(P & 0x02))) { cycles += 1; goto b4_L93BA_in; }
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_L9398");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_L9398");
A = 0x51; setZN(A);
cycles += 2;
nmi_poll("b4_L9398");
X = RD(0x51); setZN(X);
cycles += 3;
nmi_poll("b4_L9398");
{ uint8_t _m = 0x02; uint8_t _r = (uint8_t)(X - _m); P = (uint8_t)((P & 0x7C) | (X >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_L9398");
cycles += 2;
nmi_poll("b4_L9398");
if (((P & 0x01))) { cycles += 1; goto b4_L93B7_in; }
A = 0x52; setZN(A);
cycles += 2;
nmi_poll("b4_L9398");
b4_L93B7_in:;
nmi_poll("b4_L9398");
cycles += 3;
nmi_poll("b4_L9398");
b7_entry_C063(); return;
b4_L93BA_in:;
nmi_poll("b4_L9398");
cycles += 3;
nmi_poll("b4_L9398");
b7_entry_C114(); return;
}
static void __attribute__((used)) b4_L95D2(void) {
nmi_poll("b4_L95D2");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_L95D2");
cycles += 2;
nmi_poll("b4_L95D2");
if (((P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95CF(void) {
nmi_poll("b4_L95CF");
cycles += 2;
nmi_poll("b4_L95CF");
cycles += 2;
nmi_poll("b4_L95CF");
cycles += 2;
nmi_poll("b4_L95CF");
b4_L95D2(); return;
}
static void __attribute__((used)) b4_L95D9(void) {
nmi_poll("b4_L95D9");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b4_L95D9");
cycles += 2;
nmi_poll("b4_L95D9");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95D6(void) {
nmi_poll("b4_L95D6");
cycles += 2;
nmi_poll("b4_L95D6");
cycles += 2;
nmi_poll("b4_L95D6");
cycles += 2;
nmi_poll("b4_L95D6");
b4_L95D9(); return;
}
static void __attribute__((used)) b4_L95E0(void) {
nmi_poll("b4_L95E0");
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_L95E0");
cycles += 2;
nmi_poll("b4_L95E0");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95DD(void) {
nmi_poll("b4_L95DD");
cycles += 2;
nmi_poll("b4_L95DD");
cycles += 2;
nmi_poll("b4_L95DD");
cycles += 2;
nmi_poll("b4_L95DD");
b4_L95E0(); return;
}
static void __attribute__((used)) b4_L95E7(void) {
nmi_poll("b4_L95E7");
A = 0x03; setZN(A);
cycles += 2;
nmi_poll("b4_L95E7");
cycles += 2;
nmi_poll("b4_L95E7");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95E4(void) {
nmi_poll("b4_L95E4");
cycles += 2;
nmi_poll("b4_L95E4");
cycles += 2;
nmi_poll("b4_L95E4");
cycles += 2;
nmi_poll("b4_L95E4");
b4_L95E7(); return;
}
static void __attribute__((used)) b4_L95EE(void) {
nmi_poll("b4_L95EE");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b4_L95EE");
cycles += 2;
nmi_poll("b4_L95EE");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95EB(void) {
nmi_poll("b4_L95EB");
cycles += 2;
nmi_poll("b4_L95EB");
cycles += 2;
nmi_poll("b4_L95EB");
cycles += 2;
nmi_poll("b4_L95EB");
b4_L95EE(); return;
}
static void __attribute__((used)) b4_L95F5(void) {
nmi_poll("b4_L95F5");
A = 0x05; setZN(A);
cycles += 2;
nmi_poll("b4_L95F5");
cycles += 2;
nmi_poll("b4_L95F5");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95F2(void) {
nmi_poll("b4_L95F2");
cycles += 2;
nmi_poll("b4_L95F2");
cycles += 2;
nmi_poll("b4_L95F2");
cycles += 2;
nmi_poll("b4_L95F2");
b4_L95F5(); return;
}
static void __attribute__((used)) b4_L95FC(void) {
nmi_poll("b4_L95FC");
A = 0x06; setZN(A);
cycles += 2;
nmi_poll("b4_L95FC");
cycles += 2;
nmi_poll("b4_L95FC");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L95F9(void) {
nmi_poll("b4_L95F9");
cycles += 2;
nmi_poll("b4_L95F9");
cycles += 2;
nmi_poll("b4_L95F9");
cycles += 2;
nmi_poll("b4_L95F9");
b4_L95FC(); return;
}
static void __attribute__((used)) b4_L9603(void) {
nmi_poll("b4_L9603");
A = 0x07; setZN(A);
cycles += 2;
nmi_poll("b4_L9603");
cycles += 2;
nmi_poll("b4_L9603");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L9600(void) {
nmi_poll("b4_L9600");
cycles += 2;
nmi_poll("b4_L9600");
cycles += 2;
nmi_poll("b4_L9600");
cycles += 2;
nmi_poll("b4_L9600");
b4_L9603(); return;
}
static void __attribute__((used)) b4_L960A(void) {
nmi_poll("b4_L960A");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_L960A");
cycles += 2;
nmi_poll("b4_L960A");
if ((!(P & 0x02))) { cycles += 1; b4_L960E(); return; }
b4_L960E();
return;
}
static void __attribute__((used)) b4_L9607(void) {
nmi_poll("b4_L9607");
cycles += 2;
nmi_poll("b4_L9607");
cycles += 2;
nmi_poll("b4_L9607");
cycles += 2;
nmi_poll("b4_L9607");
b4_L960A(); return;
}
static void __attribute__((used)) b4_L960E(void) {
nmi_poll("b4_L960E");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_L960E");
A = 0x23; setZN(A);
cycles += 2;
nmi_poll("b4_L960E");
WR(0x46, A);
cycles += 3;
nmi_poll("b4_L960E");
A = 0xFF; setZN(A);
cycles += 2;
nmi_poll("b4_L960E");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_L960E");
nmi_poll("b4_L960E");
cycles += 3;
nmi_poll("b4_L960E");
b7_entry_C1EC(); return;
}
static void __attribute__((used)) b4_L961B(void) {
nmi_poll("b4_L961B");
cycles += 3;
nmi_poll("b4_L961B");
b4_entry_9633(); return;
}
static void __attribute__((used)) b4_L961E(void) {
nmi_poll("b4_L961E");
cycles += 6;
nmi_poll("b4_L961E");
S = (uint8_t)(S - 2);
b7_entry_C138();
S = (uint8_t)(S + 2);
nmi_poll("b4_L961E");
cycles += 2;
nmi_poll("b4_L961E");
if (((P & 0x80))) { cycles += 1; goto b4_L961E_rts; }
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_L961E");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_L961E");
cycles += 2;
nmi_poll("b4_L961E");
if ((!(P & 0x02))) { cycles += 1; goto b4_L9630_in; }
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_L961E");
cycles += 2;
nmi_poll("b4_L961E");
if ((!(P & 0x02))) { cycles += 1; goto b4_L9630_in; }
nmi_poll("b4_L961E");
cycles += 3;
nmi_poll("b4_L961E");
b4_entry_96BF(); return;
b4_L9630_in:;
nmi_poll("b4_L961E");
cycles += 3;
nmi_poll("b4_L961E");
b4_entry_9638(); return;
b4_L961E_rts:;
cycles += 6;
return;
}
static void __attribute__((used)) b4_LB446(void) {
nmi_poll("b4_LB446");
cycles += 3;
nmi_poll("b4_LB446");
cycles += 6;
return;
}
static void __attribute__((used)) b4_LB449(void) {
nmi_poll("b4_LB449");
A = 0x05; setZN(A);
cycles += 2;
nmi_poll("b4_LB449");
nmi_poll("b4_LB449");
cycles += 6;
nmi_poll("b4_LB449");
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB449");
cycles += 6;
return;
}
static void __attribute__((used)) b7_LC015(void) {
nmi_poll("b7_LC015");
nmi_poll("b7_LC015");
cycles += 3;
nmi_poll("b7_LC015");
b7_entry_D37D(); return;
}
static void __attribute__((used)) b7_LC054(void) {
nmi_poll("b7_LC054");
nmi_poll("b7_LC054");
cycles += 3;
nmi_poll("b7_LC054");
b7_entry_E152(); return;
}
static void __attribute__((used)) b7_LC04B(void) {
nmi_poll("b7_LC04B");
nmi_poll("b7_LC04B");
cycles += 3;
nmi_poll("b7_LC04B");
b7_entry_E139(); return;
}
static void __attribute__((used)) b4_LB44F(void) {
nmi_poll("b4_LB44F");
cycles += 3;
nmi_poll("b4_LB44F");
b4_LB4A9(); return;
}
static void __attribute__((used)) b4_LB452(void) {
nmi_poll("b4_LB452");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_LB452");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_LB452");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_LB452");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_LC04B();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_LB452");
A = 0x3F; setZN(A);
cycles += 2;
nmi_poll("b4_LB452");
X = 0x4C; setZN(X);
cycles += 2;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C14D();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
X = 0x03; setZN(X);
cycles += 2;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C20A();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C027();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b4_entry_B243();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_LC015();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_LC054();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_LB452");
A = 0x3F; setZN(A);
cycles += 2;
nmi_poll("b4_LB452");
X = 0x4D; setZN(X);
cycles += 2;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C14D();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
X = 0x03; setZN(X);
cycles += 2;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C20A();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_LB452");
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C03F();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b4_entry_B264();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C018();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C1B3();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_LB452");
cycles += 2;
nmi_poll("b4_LB452");
if ((!(P & 0x02))) { cycles += 1; b4_LB4A9(); return; }
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_LB452");
{ uint8_t _m = 0xCF; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_LB452");
cycles += 2;
nmi_poll("b4_LB452");
if ((!(P & 0x02))) { cycles += 1; b4_LB4A9(); return; }
nmi_poll("b4_LB452");
cycles += 6;
nmi_poll("b4_LB452");
S = (uint8_t)(S - 2);
b7_entry_C12F();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB452");
cycles += 2;
nmi_poll("b4_LB452");
if (((P & 0x02))) { cycles += 1; b4_LB4A9(); return; }
A = 0x58; setZN(A);
cycles += 2;
nmi_poll("b4_LB452");
WR((uint16_t)(0x0400 + X), A);
cycles += 5;
nmi_poll("b4_LB452");
b4_LB4A9();
return;
}
static void __attribute__((used)) b4_LB4A9(void) {
nmi_poll("b4_LB4A9");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_LB4A9");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_LB4A9");
nmi_poll("b4_LB4A9");
cycles += 6;
nmi_poll("b4_LB4A9");
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB4A9");
cycles += 2;
nmi_poll("b4_LB4A9");
if (((P & 0x02))) { cycles += 1; goto b4_LB4B9_in; }
cycles += 3;
nmi_poll("b4_LB4A9");
b7_entry_C17A(); return;
b4_LB4B9_in:;
nmi_poll("b4_LB4A9");
A = 0x05; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
nmi_poll("b4_LB4A9");
cycles += 6;
nmi_poll("b4_LB4A9");
S = (uint8_t)(S - 2);
b4_entry_B2C5();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB4A9");
cycles += 6;
nmi_poll("b4_LB4A9");
S = (uint8_t)(S - 2);
b7_entry_C138();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB4A9");
cycles += 6;
nmi_poll("b4_LB4A9");
S = (uint8_t)(S - 2);
b7_entry_C0A2();
S = (uint8_t)(S + 2);
nmi_poll("b4_LB4A9");
cycles += 2;
nmi_poll("b4_LB4A9");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB4CC_in; }
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_LB4A9");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_LB4A9");
cycles += 2;
nmi_poll("b4_LB4A9");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB4E0_in; }
b4_LB4CC_in:;
nmi_poll("b4_LB4A9");
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_LB4A9");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_LB4A9");
{ uint8_t _m = 0x08; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_LB4A9");
cycles += 2;
nmi_poll("b4_LB4A9");
if ((!(P & 0x02))) { cycles += 1; goto b4_LB4DB_in; }
A = 0x46; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
cycles += 3;
nmi_poll("b4_LB4A9");
goto b4_LB4DD_in;
b4_LB4DB_in:;
nmi_poll("b4_LB4A9");
A = 0x47; setZN(A);
cycles += 2;
nmi_poll("b4_LB4A9");
b4_LB4DD_in:;
nmi_poll("b4_LB4A9");
cycles += 3;
nmi_poll("b4_LB4A9");
b7_entry_C063(); return;
b4_LB4E0_in:;
cycles += 6;
return;
}
