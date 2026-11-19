#include "runtime.h"
static void b4_entry_BE61(void);
static void b4_entry_BE64(void);
static void b4_entry_BE95(void);
static void b7_entry_C048(void);
static void b7_entry_C051(void);
static void b7_entry_C14D(void);
static void b7_entry_C20A(void);
static void __attribute__((used)) b4_entry_BE61(void) {
nmi_poll("b4_entry_BE61");
nmi_poll("b4_entry_BE61");
cycles += 3;
b4_entry_BE95(); return;
nmi_poll("b4_entry_BE61");
}
static void __attribute__((used)) b4_entry_BE64(void) {
nmi_poll("b4_entry_BE64");
A = 0xC0; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BE64");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
A = 0xC0; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BE64");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C048(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C048", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
A = 0x3F; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BE64");
X = 0x4C; setZN(X);
cycles += 2;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C14D(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C14D", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
X = 0x03; setZN(X);
cycles += 2;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C20A(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C20A", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C051(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C051", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
A = 0x3F; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BE64");
X = 0x4D; setZN(X);
cycles += 2;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C14D(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C14D", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
X = 0x03; setZN(X);
cycles += 2;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C20A(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b7_entry_C20A", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC02D(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BE64", "b4_LC02D", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
nmi_poll("b4_entry_BE64");
cycles += 3;
b4_entry_BE95(); return;
nmi_poll("b4_entry_BE64");
}
static void b4_entry_BE95(void) { __builtin_trap(); }
