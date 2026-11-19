#include "runtime.h"
static void b4_entry_A58C(void);
static void b4_entry_A65A(void);
static void b4_entry_A667(void);
static void b4_entry_9EB3(void);
static void b4_entry_A07B(void);
static void b7_entry_C00C(void);
static void b7_entry_C012(void);
static void b7_entry_C027(void);
static void b7_entry_C03F(void);
static void b7_entry_C0D2(void);
static void b7_entry_C0FF(void);
static void b7_entry_C141(void);
static void b7_entry_C144(void);
static void b7_entry_C18C(void);
static void b7_entry_C207(void);
static void b7_entry_C216(void);
static void __attribute__((used)) b4_entry_A58C(void) {
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_A07B();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5EF; }
nmi_poll("b4_entry_A58C");
A = RD(0x53); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5EF; }
nmi_poll("b4_entry_A58C");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x3F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5C1; }
nmi_poll("b4_entry_A58C");
A = RD(0x0403); setZN(A);
cycles += 4;
nmi_poll("b4_entry_A58C");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = RD(0x49); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A58C");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5AC; }
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5AA; }
nmi_poll("b4_entry_A58C");
A = 0x06; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5AC; }
nmi_poll("b4_entry_A58C");
b4_LA5AA:;
A = 0xFA; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
b4_LA5AC:;
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = RD(0x0405); setZN(A);
cycles += 4;
nmi_poll("b4_entry_A58C");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = RD(0x4B); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A58C");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5BF; }
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5BD; }
nmi_poll("b4_entry_A58C");
A = 0x06; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5BF; }
nmi_poll("b4_entry_A58C");
b4_LA5BD:;
A = 0xFA; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
b4_LA5BF:;
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
b4_LA5C1:;
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C03F();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
X = 0x04; setZN(X);
cycles += 2;
nmi_poll("b4_entry_A58C");
Y = 0x06; setZN(Y);
cycles += 2;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C012();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5DD; }
nmi_poll("b4_entry_A58C");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = RD(0x4D); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5D9; }
nmi_poll("b4_entry_A58C");
A = 0xFC; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5DB; }
nmi_poll("b4_entry_A58C");
b4_LA5D9:;
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
b4_LA5DB:;
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
b4_LA5DD:;
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C027();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
X = 0x04; setZN(X);
cycles += 2;
nmi_poll("b4_entry_A58C");
Y = 0x06; setZN(Y);
cycles += 2;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C00C();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x0F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA5EF; }
nmi_poll("b4_entry_A58C");
{ uint8_t _v = (uint8_t)(RD(0x51) + 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_A58C");
b4_LA5EF:;
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_A65A();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
A = RD(0x03FD); setZN(A);
cycles += 4;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA628; }
nmi_poll("b4_entry_A58C");
A = RD(0x4F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x06; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA628; }
nmi_poll("b4_entry_A58C");
A = RD(0x53); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA628; }
nmi_poll("b4_entry_A58C");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C144();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA620; }
nmi_poll("b4_entry_A58C");
A = 0x11; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C216();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
b4_LA620:;
A = RD(0x53); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA628; }
nmi_poll("b4_entry_A58C");
A = 0xC0; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x4F, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
b4_LA628:;
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x20; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA632; }
nmi_poll("b4_entry_A58C");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA638; }
nmi_poll("b4_entry_A58C");
b4_LA632:;
{ uint8_t _m = 0xB0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA63E; }
nmi_poll("b4_entry_A58C");
A = 0xFC; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
b4_LA638:;
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
b4_LA63E:;
A = RD(0x10); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x07; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA64B; }
nmi_poll("b4_entry_A58C");
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A58C");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A58C"); goto b4_LA64D; }
nmi_poll("b4_entry_A58C");
b4_LA64B:;
{ uint8_t _m = 0x01; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A58C");
b4_LA64D:;
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A58C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_A58C");
{ uint8_t _m = 0x18; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_A58C");
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_9EB3();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A58C");
nmi_poll("b4_entry_A58C");
cycles += 6;
return;
nmi_poll("b4_entry_A58C");
}
static void __attribute__((used)) b4_entry_A65A(void) {
nmi_poll("b4_entry_A65A");
A = 0xE0; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A65A");
b4_LA65C:;
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b4_entry_A65A");
nmi_poll("b4_entry_A65A");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_A667();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A65A");
nmi_poll("b4_entry_A65A");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_entry_A65A");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_A65A");
{ uint8_t _m = 0x20; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_A65A");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_A65A"); goto b4_LA65C; }
nmi_poll("b4_entry_A65A");
cycles += 6;
return;
nmi_poll("b4_entry_A65A");
}
static void __attribute__((used)) b4_entry_A667(void) {
nmi_poll("b4_entry_A667");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x11); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A667");
WR(0x00, A);
cycles += 3;
nmi_poll("b4_entry_A667");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A667");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b4_entry_A667");
A = RD(0x3E); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A667");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b4_entry_A667");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0D2();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
WR(0x01, A);
cycles += 3;
nmi_poll("b4_entry_A667");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x3E); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A667");
WR(0x3E, A);
cycles += 3;
nmi_poll("b4_entry_A667");
{ uint8_t _c = (uint8_t)((P & 1) << 7); P = (uint8_t)((P & 0xFE) | (A & 1)); A = (uint8_t)(_c | (A >> 1)); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x01); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
nmi_poll("b4_entry_A667");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_A667"); goto b4_LA6AC; }
nmi_poll("b4_entry_A667");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_poll("b4_entry_A667");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x51); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C207();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
WR(0x01, A);
cycles += 3;
nmi_poll("b4_entry_A667");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x3F); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_A667");
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_A667");
{ uint8_t _c = (uint8_t)((P & 1) << 7); P = (uint8_t)((P & 0xFE) | (A & 1)); A = (uint8_t)(_c | (A >> 1)); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_A667");
{ uint8_t _m = RD(0x01); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
nmi_poll("b4_entry_A667");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_A667"); goto b4_LA6AC; }
nmi_poll("b4_entry_A667");
A = RD(0x03FD); setZN(A);
cycles += 4;
nmi_poll("b4_entry_A667");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_A667"); goto b4_LA6A1; }
nmi_poll("b4_entry_A667");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C141();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
b4_LA6A1:;
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A667");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_A667");
A = 0xA7; setZN(A);
cycles += 2;
nmi_poll("b4_entry_A667");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C18C();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_A667");
nmi_poll("b4_entry_A667");
b4_LA6AC:;
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_entry_A667");
WR(0x3E, A);
cycles += 3;
nmi_poll("b4_entry_A667");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_entry_A667");
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_A667");
cycles += 6;
return;
nmi_poll("b4_entry_A667");
}
static void b4_entry_9EB3(void) { __builtin_trap(); }
static void b4_entry_A07B(void) { __builtin_trap(); }
