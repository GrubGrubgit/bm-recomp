#include "runtime.h"
static void b4_entry_B792(void);
static void b4_entry_B7BD(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_B792(void) {
nmi_poll("b4_entry_B792");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B792");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_B792");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B792");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_B792");
A = RD(0x50); setZN(A);
cycles += 3;
nmi_poll("b4_entry_B792");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_B792"); goto b4_LB7B6; }
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC04E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B792", "b4_LC04E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_entry_B7BD(); return; }
nmi_poll("b4_entry_B792");
{ uint8_t _v = (uint8_t)(RD(0x50) + 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_B792");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B792");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC045(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B792", "b4_LC045", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 2;
if (((P & 0x80))) { cycles += 1; nmi_poll("b4_entry_B792"); goto b4_LB7B2; }
nmi_poll("b4_entry_B792");
A = 0x38; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B792");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_B792"); goto b4_LB7B4; }
nmi_poll("b4_entry_B792");
b4_LB7B2:;
A = 0xC8; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B792");
b4_LB7B4:;
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_B792");
b4_LB7B6:;
nmi_poll("b4_entry_B792");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC02D(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B792", "b4_LC02D", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B7BD(); return; }
nmi_poll("b4_entry_B792");
{ uint8_t _v = (uint8_t)(RD(0x50) - 1); WR(0x50, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_B792");
nmi_poll("b4_entry_B792");
cycles += 3;
b4_entry_B7BD(); return;
nmi_poll("b4_entry_B792");
}
static void __attribute__((used)) b4_entry_B7BD(void) {
nmi_poll("b4_entry_B7BD");
cycles += 6;
return;
nmi_poll("b4_entry_B7BD");
}
static void b4_x(void) { __builtin_trap(); }
