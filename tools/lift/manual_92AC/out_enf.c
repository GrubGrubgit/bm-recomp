#include "runtime.h"
static void b4_entry_92AC(void);
static void b4_entry_92B6(void);
static void b7_entry_C0A2(void);
static void b7_entry_C0FF(void);
static void b7_entry_C117(void);
static void b7_entry_C138(void);
static void b7_entry_C189(void);
static void b7_entry_C19E(void);
static void b7_entry_C1AD(void);
static void b7_entry_C1B3(void);
static void b7_entry_C1E6(void);
static void __attribute__((used)) b4_entry_92AC(void) {
nmi_poll("b4_entry_92AC");
nmi_poll("b4_entry_92AC");
cycles += 3;
b4_entry_92B6(); return;
nmi_poll("b4_entry_92AC");
}
static void __attribute__((used)) b4_entry_92B6(void) {
nmi_poll("b4_entry_92B6");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
A = 0x18; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0FF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C0FF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_92B6"); goto b4_LA2C6; }
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 3;
b7_entry_C117(); return;
nmi_poll("b4_entry_92B6");
b4_LA2C6:;
A = 0x02; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1E6(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C1E6", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C138(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C138", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0A2(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C0A2", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_92B6"); goto b4_LA31E; }
nmi_poll("b4_entry_92B6");
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_entry_92B6");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
X = A; setZN(X);
cycles += 2;
nmi_poll("b4_entry_92B6");
A = RD((uint16_t)(0x9324 + X)); setZN(A);
cycles += 4 + ((((0x9324 + X) & 0xFF00) != 0x9300) ? 1 : 0);
nmi_poll("b4_entry_92B6");
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_92B6"); goto b4_LA31E; }
nmi_poll("b4_entry_92B6");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
A = RD((uint16_t)(0x931F + X)); setZN(A);
cycles += 4 + ((((0x931F + X) & 0xFF00) != 0x9300) ? 1 : 0);
nmi_poll("b4_entry_92B6");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_92B6");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_92B6");
{ uint8_t _m = 0x06; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C19E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C19E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1B3(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C1B3", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_92B6");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_92B6");
{ uint8_t _m = 0x10; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_92B6");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_92B6");
{ uint8_t _m = RD(0x3E); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_92B6");
WR(0x3E, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1B3(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_92B6", "b7_entry_C1B3", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_92B6");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_92B6");
{ uint8_t _m = 0x10; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_92B6");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_92B6");
{ uint8_t _m = RD(0x3F); uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_92B6");
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
A = RD(0x10); setZN(A);
cycles += 3;
nmi_poll("b4_entry_92B6");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_92B6"); goto b4_LA317; }
nmi_poll("b4_entry_92B6");
A = 0x5A; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 3;
b7_entry_C189(); return;
nmi_poll("b4_entry_92B6");
b4_LA317:;
A = 0x5C; setZN(A);
cycles += 2;
nmi_poll("b4_entry_92B6");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_92B6");
nmi_poll("b4_entry_92B6");
cycles += 3;
b7_entry_C1AD(); return;
nmi_poll("b4_entry_92B6");
b4_LA31E:;
cycles += 6;
return;
nmi_poll("b4_entry_92B6");
}
