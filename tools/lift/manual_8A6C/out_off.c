#include "runtime.h"
static void b4_entry_8A6C(void);
static void b7_entry_C063(void);
static void b7_entry_C0FF(void);
static void b7_entry_C11A(void);
static void __attribute__((used)) b4_entry_8A6C(void) {
nmi_poll("b4_entry_8A6C");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_8A6C");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_8A6C");
nmi_poll("b4_entry_8A6C");
cycles += 6;
nmi_poll("b4_entry_8A6C");
S = (uint8_t)(S - 2);
b7_entry_C0FF();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_8A6C");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_8A6C");
nmi_poll("b4_entry_8A6C");
cycles += 6;
nmi_poll("b4_entry_8A6C");
S = (uint8_t)(S - 2);
b4_entry_93BD();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_8A6C");
{ uint8_t _v = (uint8_t)(RD(0x51) + 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_8A6C");
cycles += 2;
nmi_poll("b4_entry_8A6C");
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_8A6C"); goto b4_LB8A84; }
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_8A6C");
b4_LB8A84:;
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_entry_8A6C");
{ uint8_t _m = 0xA0; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_8A6C");
cycles += 2;
nmi_poll("b4_entry_8A6C");
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_8A6C"); goto b4_LB8A8F; }
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
nmi_poll("b4_entry_8A6C");
cycles += 6;
nmi_poll("b4_entry_8A6C");
S = (uint8_t)(S - 2);
b7_entry_C11A();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_8A6C");
b4_LB8A8F:;
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_entry_8A6C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_8A6C");
X = A; setZN(X);
cycles += 2;
nmi_poll("b4_entry_8A6C");
{ uint8_t _m = 0x18; uint8_t _r = (uint8_t)(X - _m); P = (uint8_t)((P & 0x7C) | (X >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_8A6C");
cycles += 2;
nmi_poll("b4_entry_8A6C");
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b4_entry_8A6C"); goto b4_LB8A9A; }
X = 0x17; setZN(X);
cycles += 2;
nmi_poll("b4_entry_8A6C");
b4_LB8A9A:;
A = RD((uint16_t)(0x8AA3 + X)); setZN(A);
cycles += 4 + ((((0x8AA3 + X) & 0xFF00) != 0x8A00) ? 1 : 0);
nmi_poll("b4_entry_8A6C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_8A6C");
{ uint8_t _m = 0x1B; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_8A6C");
nmi_poll("b4_entry_8A6C");
cycles += 3;
nmi_poll("b4_entry_8A6C");
b7_entry_C063(); return;
}
