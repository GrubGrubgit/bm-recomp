#include "runtime.h"
static void b4_entry_9072(void);
static void b4_entry_90E8(void);
static void b4_x(void);
static void b7_entry_C01E(void);
static void b7_entry_C0FF(void);
static void b7_entry_C117(void);
static void b7_entry_C1E6(void);
static void b7_entry_D324(void);
static void __attribute__((used)) b4_entry_9072(void) {
nmi_poll("b4_entry_9072");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_9072");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b4_entry_8FF3();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b4_entry_9007();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
{ uint8_t _v = (uint8_t)(RD(0x53) - 1); WR(0x53, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if (((P & 0x02))) { cycles += 1; b4_entry_90E8(); return; }
A = RD(0xBB); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b4_entry_9072"); goto b4_L908C; }
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b7_entry_C01E();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
b4_L908C:;
nmi_poll("b4_entry_9072");
cycles += 9; /* SLOT-JSR: JSR6+JMP3 */
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b7_entry_D324();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_9072"); goto b4_L90A2; }
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9072"); goto b4_L90A2; }
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_9072");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9072"); goto b4_L90A2; }
{ uint8_t _v = (uint8_t)(RD(0x51) + 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_9072");
b4_L90A2:;
A = RD(0x57); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_9072"); goto b4_L90AF; }
A = RD(0x47); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _m = RD(0x51); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 3;
nmi_poll("b4_entry_9072");
goto b4_L90B4;
b4_L90AF:;
A = RD(0x47); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _m = RD(0x51); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_9072");
b4_L90B4:;
WR(0x47, A);
cycles += 3;
nmi_poll("b4_entry_9072");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b4_LC0CC();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b4_LC201();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_9072");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_9072");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
cycles += 2;
nmi_poll("b4_entry_9072");
if ((!(P & 0x02))) { cycles += 1; b4_entry_90E8(); return; }
A = 0x01; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b7_entry_C1E6();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
A = RD(0x47); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9072");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b4_entry_9072");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _m = 0x60; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_9072");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (A >> 7)); A = (uint8_t)((A << 1) | _c); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _c = (uint8_t)(P & 1); P = (uint8_t)((P & 0xFE) | (A >> 7)); A = (uint8_t)((A << 1) | _c); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9072");
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9072");
WR(0x47, A);
cycles += 3;
nmi_poll("b4_entry_9072");
nmi_poll("b4_entry_9072");
cycles += 6;
nmi_poll("b4_entry_9072");
S = (uint8_t)(S - 2);
b4_entry_8F21();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9072");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_entry_9072");
WR(0x47, A);
cycles += 3;
nmi_poll("b4_entry_9072");
cycles += 6;
return;
}
static void __attribute__((used)) b4_entry_90E8(void) {
nmi_poll("b4_entry_90E8");
nmi_poll("b4_entry_90E8");
cycles += 3;
nmi_poll("b4_entry_90E8");
b7_entry_C117(); return;
}
static void b4_x(void) { __builtin_trap(); }
