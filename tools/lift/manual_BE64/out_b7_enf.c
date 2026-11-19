#include "runtime.h"
static void b7_entry_C048(void);
static void b7_entry_C051(void);
static void b7_entry_E107(void);
static void b7_entry_E120(void);
static void b7_entry_E0ED(void);
static void b7_entry_E0FA(void);
static void __attribute__((used)) b7_entry_C048(void) {
nmi_poll("b7_entry_C048");
nmi_poll("b7_entry_C048");
cycles += 3;
b7_entry_E107(); return;
nmi_poll("b7_entry_C048");
}
static void __attribute__((used)) b7_entry_C051(void) {
nmi_poll("b7_entry_C051");
nmi_poll("b7_entry_C051");
cycles += 3;
b7_entry_E120(); return;
nmi_poll("b7_entry_C051");
}
static void __attribute__((used)) b7_entry_E107(void) {
nmi_poll("b7_entry_E107");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_poll("b7_entry_E107");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b7_entry_E107");
nmi_poll("b7_entry_E107");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_E0ED(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_entry_E107", "b7_entry_E0ED", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b7_entry_E107");
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
WR(0x00, A);
cycles += 3;
nmi_poll("b7_entry_E107");
A = X; setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
{ uint8_t _m = RD(0x00); A = (uint8_t)(A | _m); setZN(A); }
cycles += 3;
nmi_poll("b7_entry_E107");
X = A; setZN(X);
cycles += 2;
nmi_poll("b7_entry_E107");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b7_entry_E107");
WR(0x00, A);
cycles += 3;
nmi_poll("b7_entry_E107");
A = X; setZN(A);
cycles += 2;
nmi_poll("b7_entry_E107");
cycles += 6;
return;
nmi_poll("b7_entry_E107");
}
static void __attribute__((used)) b7_entry_E120(void) {
nmi_poll("b7_entry_E120");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_poll("b7_entry_E120");
stk[S] = A; S = (uint8_t)(S - 1);
cycles += 3;
nmi_poll("b7_entry_E120");
nmi_poll("b7_entry_E120");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_E0FA(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_entry_E120", "b7_entry_E0FA", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b7_entry_E120");
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | ((A & 0x80) ? 1 : 0)); A = (uint8_t)(A << 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
WR(0x00, A);
cycles += 3;
nmi_poll("b7_entry_E120");
A = X; setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
{ uint8_t _m = RD(0x00); A = (uint8_t)(A | _m); setZN(A); }
cycles += 3;
nmi_poll("b7_entry_E120");
X = A; setZN(X);
cycles += 2;
nmi_poll("b7_entry_E120");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b7_entry_E120");
WR(0x00, A);
cycles += 3;
nmi_poll("b7_entry_E120");
A = X; setZN(A);
cycles += 2;
nmi_poll("b7_entry_E120");
cycles += 6;
return;
nmi_poll("b7_entry_E120");
}
static void b7_entry_E0ED(void) { __builtin_trap(); }
static void b7_entry_E0FA(void) { __builtin_trap(); }
