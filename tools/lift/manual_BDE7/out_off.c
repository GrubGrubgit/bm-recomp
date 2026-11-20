#include "runtime.h"
static void b4_entry_BDE7(void);
static void b4_entry_BDEA(void);
static void b4_entry_BE0E(void);
static void b7_entry_C12F(void);
static void __attribute__((used)) b4_entry_BDE7(void) {
nmi_pc = 0xBDE7;
nmi_poll("b4_entry_BDE7");
nmi_poll("b4_entry_BDE7");
cycles += 3;
b4_entry_BE0E(); return;
nmi_pc = 0xBDEA;
nmi_poll("b4_entry_BDE7");
}
static void __attribute__((used)) b4_entry_BDEA(void) {
nmi_pc = 0xBDEA;
nmi_poll("b4_entry_BDEA");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xBDEC;
nmi_poll("b4_entry_BDEA");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xBDEE;
nmi_poll("b4_entry_BDEA");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xBDF0;
nmi_poll("b4_entry_BDEA");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xBDF2;
nmi_poll("b4_entry_BDEA");
nmi_poll("b4_entry_BDEA");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C12F();
S = (uint8_t)(S + 2);
nmi_pc = 0xBDF5;
nmi_poll("b4_entry_BDEA");
nmi_pc = 0xBDF5;
nmi_poll("b4_entry_BDEA");
cycles += 2;
nmi_pc = 0xBE01;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_BDEA"); goto b4_LBE01; }
nmi_pc = 0xBDF7;
nmi_poll("b4_entry_BDEA");
A = 0x54; setZN(A);
cycles += 2;
nmi_pc = 0xBDF9;
nmi_poll("b4_entry_BDEA");
WR((uint16_t)(0x0400 + X), A);
cycles += 5;
nmi_pc = 0xBDFC;
nmi_poll("b4_entry_BDEA");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_pc = 0xBDFE;
nmi_poll("b4_entry_BDEA");
WR((uint16_t)(0x040B + X), A);
cycles += 5;
nmi_pc = 0xBE01;
nmi_poll("b4_entry_BDEA");
b4_LBE01:;
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xBE02;
nmi_poll("b4_entry_BDEA");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_pc = 0xBE04;
nmi_poll("b4_entry_BDEA");
{ uint8_t _m = 0x08; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xBE06;
nmi_poll("b4_entry_BDEA");
WR(0x50, A);
cycles += 3;
nmi_pc = 0xBE08;
nmi_poll("b4_entry_BDEA");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xBE0A;
nmi_poll("b4_entry_BDEA");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_entry_BE0E(); return; }
nmi_pc = 0xBE0C;
nmi_poll("b4_entry_BDEA");
{ uint8_t _v = (uint8_t)(RD(0x46) - 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xBE0E;
nmi_poll("b4_entry_BDEA");
nmi_poll("b4_entry_BDEA");
cycles += 3;
b4_entry_BE0E(); return;
nmi_pc = 0xBE11;
nmi_poll("b4_entry_BDEA");
}
static void b4_entry_BE0E(void) { __builtin_trap(); }
