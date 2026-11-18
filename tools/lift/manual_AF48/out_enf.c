#include "runtime.h"
static void b4_entry_AF45(void);
static void b4_entry_AF48(void);
static void b4_LAF66(void);
static void b4_entry_AF67(void);
static void b4_entry_AF6A(void);
static void b4_LB88(void);
static void b4_LB96(void);
static void b4_entry_AF99(void);
static void b7_entry_C01E(void);
static void b7_entry_C114(void);
static void b7_entry_C1EC(void);
static void b7_entry_C1EF(void);
static void b7_entry_C216(void);
static void __attribute__((used)) b4_entry_AF45(void) {
nmi_poll("b4_entry_AF45");
nmi_poll("b4_entry_AF45");
cycles += 3;
b4_LAF66(); return;
}
static void __attribute__((used)) b4_entry_AF48(void) {
nmi_poll("b4_entry_AF48");
A = RD(0x50); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 3;
WR(0x52, A);
cycles += 2;
A = 0x10; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x4C, A);
cycles += 3;
WR(0x4D, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
nmi_poll("b4_entry_AF48");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1EC(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_AF48", "b7_entry_C1EC", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_AF48");
cycles += 2;
A = 0x1B; setZN(A);
nmi_poll("b4_entry_AF48");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C216(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_AF48", "b7_entry_C216", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_AF48");
b4_LAF66();
return;
}
static void __attribute__((used)) b4_LAF66(void) {
nmi_poll("b4_LAF66");
cycles += 6;
return;
}
static void __attribute__((used)) b4_entry_AF67(void) {
nmi_poll("b4_entry_AF67");
nmi_poll("b4_entry_AF67");
cycles += 3;
b4_entry_AF99(); return;
}
static void __attribute__((used)) b4_entry_AF6A(void) {
nmi_poll("b4_entry_AF6A");
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
cycles += 2;
{ uint8_t _m = 0x03; A = (uint8_t)(A & _m); setZN(A); }
{ uint8_t _m = RD(0x50); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 3;
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_LB96(); return; }
cycles += 2;
P = (uint8_t)(P & 0xFE);
A = RD(0x51); setZN(A);
cycles += 3;
cycles += 2;
{ uint8_t _m = 0x03; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
WR(0x51, A);
cycles += 2;
{ uint8_t _m = 0x70; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; b4_LB88(); return; }
nmi_poll("b4_entry_AF6A");
cycles += 3;
b7_entry_C114(); return;
}
static void __attribute__((used)) b4_LB88(void) {
nmi_poll("b4_LB88");
A = RD(0x11); setZN(A);
cycles += 3;
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
P = (uint8_t)(P & 0xFE);
{ uint8_t _m = RD(0x52); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
cycles += 3;
WR(0x47, A);
Y = RD(0x51); setZN(Y);
cycles += 3;
nmi_poll("b4_LB88");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1EF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_LB88", "b7_entry_C1EF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_LB88");
b4_LB96();
return;
}
static void __attribute__((used)) b4_LB96(void) {
nmi_poll("b4_LB96");
nmi_poll("b4_LB96");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C01E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_LB96", "b7_entry_C01E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_LB96");
nmi_poll("b4_LB96");
cycles += 3;
b4_entry_AF99(); return;
}
static void b4_entry_AF99(void) { __builtin_trap(); }
