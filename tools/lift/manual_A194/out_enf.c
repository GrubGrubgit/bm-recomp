#include "runtime.h"
static void b6_LA190(void);
static void b6_LA1AC(void);
static void b6_entry_A164(void);
static void b6_entry_A191(void);
static void b6_entry_A194(void);
static void b6_entry_A1AD(void);
static void b6_entry_A1B0(void);
static void b6_entry_A1CC(void);
static void b6_entry_A2E9(void);
static void b6_x(void);
static void b7_entry_D2B9(void);
static void b7_entry_D2DE(void);
static void b7_entry_D2FE(void);
static void b7_entry_D81C(void);
static void b7_entry_DECC(void);
static void b7_entry_DFD1(void);
static void b7_entry_E0ED(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_A164(void) {
nmi_pc = 0xA164;
nmi_poll("b6_entry_A164");
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DECC(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A164", "b7_entry_DECC", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA167;
nmi_poll("b6_entry_A164");
nmi_pc = 0xA167;
nmi_poll("b6_entry_A164");
A = 0x06; setZN(A);
cycles += 2;
nmi_pc = 0xA169;
nmi_poll("b6_entry_A164");
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b6_entry_A2E9(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A164", "b6_entry_A2E9", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA16C;
nmi_poll("b6_entry_A164");
nmi_pc = 0xA16C;
nmi_poll("b6_entry_A164");
A = 0x63; setZN(A);
cycles += 2;
nmi_pc = 0xA16E;
nmi_poll("b6_entry_A164");
WR(0x46, A);
cycles += 3;
nmi_pc = 0xA170;
nmi_poll("b6_entry_A164");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0xA172;
nmi_poll("b6_entry_A164");
WR(0x50, A);
cycles += 3;
nmi_pc = 0xA174;
nmi_poll("b6_entry_A164");
A = 0xE8; setZN(A);
cycles += 2;
nmi_pc = 0xA176;
nmi_poll("b6_entry_A164");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0xA178;
nmi_poll("b6_entry_A164");
A = 0x11; setZN(A);
cycles += 2;
nmi_pc = 0xA17A;
nmi_poll("b6_entry_A164");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xA17C;
nmi_poll("b6_entry_A164");
nmi_poll("b6_entry_A164");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_E0ED(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A164", "b7_entry_E0ED", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA17F;
nmi_poll("b6_entry_A164");
nmi_pc = 0xA17F;
nmi_poll("b6_entry_A164");
cycles += 2;
nmi_pc = 0xA188;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b6_entry_A164"); goto b6_LA188; }
nmi_pc = 0xA181;
nmi_poll("b6_entry_A164");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xA183;
nmi_poll("b6_entry_A164");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_pc = 0xA184;
nmi_poll("b6_entry_A164");
{ uint8_t _m = RD(0x4C); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_pc = 0xA186;
nmi_poll("b6_entry_A164");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0xA188;
nmi_poll("b6_entry_A164");
b6_LA188:;
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xA18A;
nmi_poll("b6_entry_A164");
WR(0x51, A);
cycles += 3;
nmi_pc = 0xA18C;
nmi_poll("b6_entry_A164");
WR(0x47, A);
cycles += 3;
nmi_pc = 0xA18E;
nmi_poll("b6_entry_A164");
WR(0x52, A);
cycles += 3;
nmi_pc = 0xA190;
nmi_poll("b6_entry_A164");
b6_LA190();
return;
}
static void __attribute__((used)) b6_LA190(void) {
nmi_pc = 0xA190;
nmi_poll("b6_LA190");
cycles += 6;
return;
nmi_pc = 0xA191;
nmi_poll("b6_LA190");
}
static void __attribute__((used)) b6_entry_A191(void) {
nmi_pc = 0xA191;
nmi_poll("b6_entry_A191");
nmi_poll("b6_entry_A191");
cycles += 3;
b6_LA1AC(); return;
nmi_pc = 0xA194;
nmi_poll("b6_entry_A191");
}
static void __attribute__((used)) b6_entry_A194(void) {
nmi_pc = 0xA194;
nmi_poll("b6_entry_A194");
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_EB71(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A194", "b7_entry_EB71", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA197;
nmi_poll("b6_entry_A194");
nmi_pc = 0xA197;
nmi_poll("b6_entry_A194");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xA199;
nmi_poll("b6_entry_A194");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xA19A;
nmi_poll("b6_entry_A194");
{ uint8_t _m = 0xB0; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xA19C;
nmi_poll("b6_entry_A194");
WR(0x47, A);
cycles += 3;
nmi_pc = 0xA19E;
nmi_poll("b6_entry_A194");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0xA1A0;
nmi_poll("b6_entry_A194");
WR(0x51, A);
cycles += 3;
nmi_pc = 0xA1A2;
nmi_poll("b6_entry_A194");
Y = 0x20; setZN(Y);
cycles += 2;
nmi_pc = 0xA1A4;
nmi_poll("b6_entry_A194");
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_E1BD(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A194", "b7_entry_E1BD", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA1A7;
nmi_poll("b6_entry_A194");
nmi_pc = 0xA1A7;
nmi_poll("b6_entry_A194");
nmi_poll("b6_entry_A194");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_D2B9(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A194", "b7_entry_D2B9", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA1AA;
nmi_poll("b6_entry_A194");
nmi_pc = 0xA1AA;
nmi_poll("b6_entry_A194");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA1AC;
nmi_poll("b6_entry_A194");
b6_LA1AC();
return;
}
static void __attribute__((used)) b6_LA1AC(void) {
nmi_pc = 0xA1AC;
nmi_poll("b6_LA1AC");
cycles += 6;
return;
nmi_pc = 0xA1AD;
nmi_poll("b6_LA1AC");
}
static void __attribute__((used)) b6_entry_A1AD(void) {
nmi_pc = 0xA1AD;
nmi_poll("b6_entry_A1AD");
nmi_poll("b6_entry_A1AD");
cycles += 3;
b6_entry_A1CC(); return;
nmi_pc = 0xA1B0;
nmi_poll("b6_entry_A1AD");
}
static void __attribute__((used)) b6_entry_A1B0(void) {
nmi_pc = 0xA1B0;
nmi_poll("b6_entry_A1B0");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xA1B2;
nmi_poll("b6_entry_A1B0");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xA1B4;
nmi_poll("b6_entry_A1B0");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xA1B6;
nmi_poll("b6_entry_A1B0");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xA1B8;
nmi_poll("b6_entry_A1B0");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xA1BA;
nmi_poll("b6_entry_A1B0");
cycles += 2;
nmi_pc = 0xA1BF;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b6_entry_A1B0"); goto b6_LA1BF; }
nmi_pc = 0xA1BC;
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 3;
b7_entry_D81C(); return;
nmi_pc = 0xA1BF;
nmi_poll("b6_entry_A1B0");
b6_LA1BF:;
A = 0x02; setZN(A);
cycles += 2;
nmi_pc = 0xA1C1;
nmi_poll("b6_entry_A1B0");
X = 0x00; setZN(X);
cycles += 2;
nmi_pc = 0xA1C3;
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DFD1(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A1B0", "b7_entry_DFD1", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA1C6;
nmi_poll("b6_entry_A1B0");
nmi_pc = 0xA1C6;
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_D2DE(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A1B0", "b7_entry_D2DE", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA1C9;
nmi_poll("b6_entry_A1B0");
nmi_pc = 0xA1C9;
nmi_poll("b6_entry_A1B0");
nmi_poll("b6_entry_A1B0");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_D2FE(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_A1B0", "b7_entry_D2FE", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xA1CC;
nmi_poll("b6_entry_A1B0");
nmi_pc = 0xA1CC;
nmi_poll("b6_entry_A1B0");
b6_entry_A1CC();
return;
}
static void __attribute__((used)) b6_entry_A1CC(void) {
nmi_pc = 0xA1CC;
nmi_poll("b6_entry_A1CC");
cycles += 6;
return;
nmi_pc = 0xA1CD;
nmi_poll("b6_entry_A1CC");
}
static void b6_x(void) { __builtin_trap(); }
