#include "runtime.h"
static void b4_entry_B65E(void);
static void b4_entry_B680(void);
static void b7_entry_C12F(void);
static void __attribute__((used)) b4_entry_B65E(void) {
nmi_poll("b4_entry_B65E");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
A = RD(0x11); setZN(A);
cycles += 3;
{ uint8_t _m = RD(0x51); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x7F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_entry_B680(); return; }
cycles += 2;
A = 0x03; setZN(A);
cycles += 3;
WR(0x50, A);
b4_LB672:;
nmi_poll("b4_entry_B65E");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C12F(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B65E", "b7_entry_C12F", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B65E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B680(); return; }
cycles += 2;
A = 0x4E; setZN(A);
cycles += 5;
WR((uint16_t)(0x0400 + X), A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b4_entry_B65E"); goto b4_LB672; }
nmi_poll("b4_entry_B65E");
cycles += 3;
b4_entry_B680(); return;
}
static void b4_entry_B680(void) { __builtin_trap(); }
