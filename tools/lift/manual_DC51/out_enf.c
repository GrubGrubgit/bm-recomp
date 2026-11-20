#include "runtime.h"
static void b7_LDC64(void);
static void b7_LDC81(void);
static void b7_LDC9A(void);
static void b7_entry_DC51(void);
static void b7_entry_DC47(void);
static void __attribute__((used)) b7_entry_DC51(void) {
nmi_pc = 0xDC51;
nmi_poll("b7_entry_DC51");
A = RD(0x39); setZN(A);
cycles += 3;
nmi_pc = 0xDC53;
nmi_poll("b7_entry_DC51");
P = (uint8_t)((P & 0x7C) | (A & 1)); A = (uint8_t)(A >> 1); setZN(A);
cycles += 2;
nmi_pc = 0xDC54;
nmi_poll("b7_entry_DC51");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b7_LDC64(); return; }
nmi_pc = 0xDC56;
nmi_poll("b7_entry_DC51");
A = RD(0x39); setZN(A);
cycles += 3;
nmi_pc = 0xDC58;
nmi_poll("b7_entry_DC51");
{ uint8_t _m = RD(0x05); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 3;
nmi_pc = 0xDC5A;
nmi_poll("b7_entry_DC51");
{ uint8_t _m = 0x02; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xDC5C;
nmi_poll("b7_entry_DC51");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b7_LDC64(); return; }
nmi_pc = 0xDC5E;
nmi_poll("b7_entry_DC51");
A = RD(0x39); setZN(A);
cycles += 3;
nmi_pc = 0xDC60;
nmi_poll("b7_entry_DC51");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b7_LDC81(); return; }
nmi_pc = 0xDC62;
nmi_poll("b7_entry_DC51");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b7_LDC9A(); return; }
nmi_pc = 0xDC64;
nmi_poll("b7_entry_DC51");
b7_LDC64();
return;
}
static void __attribute__((used)) b7_LDC64(void) {
nmi_pc = 0xDC64;
nmi_poll("b7_LDC64");
X = RD(0x0D); setZN(X);
cycles += 3;
nmi_pc = 0xDC66;
nmi_poll("b7_LDC64");
nmi_poll("b7_LDC64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC64", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC69;
nmi_poll("b7_LDC64");
nmi_pc = 0xDC69;
nmi_poll("b7_LDC64");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDC6A;
nmi_poll("b7_LDC64");
nmi_poll("b7_LDC64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC64", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC6D;
nmi_poll("b7_LDC64");
nmi_pc = 0xDC6D;
nmi_poll("b7_LDC64");
A = X; setZN(A);
cycles += 2;
nmi_pc = 0xDC6E;
nmi_poll("b7_LDC64");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xDC6F;
nmi_poll("b7_LDC64");
{ uint8_t _m = 0x10; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xDC71;
nmi_poll("b7_LDC64");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xDC72;
nmi_poll("b7_LDC64");
nmi_poll("b7_LDC64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC64", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC75;
nmi_poll("b7_LDC64");
nmi_pc = 0xDC75;
nmi_poll("b7_LDC64");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDC76;
nmi_poll("b7_LDC64");
nmi_poll("b7_LDC64");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC64", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC79;
nmi_poll("b7_LDC64");
nmi_pc = 0xDC79;
nmi_poll("b7_LDC64");
A = X; setZN(A);
cycles += 2;
nmi_pc = 0xDC7A;
nmi_poll("b7_LDC64");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xDC7B;
nmi_poll("b7_LDC64");
{ uint8_t _m = 0x10; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xDC7D;
nmi_poll("b7_LDC64");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xDC7E;
nmi_poll("b7_LDC64");
A = RD(0x0000); setZN(A);
cycles += 3;
nmi_pc = 0xDC80;
nmi_poll("b7_LDC64");
cycles += 6;
return;
nmi_pc = 0xDC81;
nmi_poll("b7_LDC64");
}
static void __attribute__((used)) b7_LDC81(void) {
nmi_pc = 0xDC81;
nmi_poll("b7_LDC81");
X = RD(0x0D); setZN(X);
cycles += 3;
nmi_pc = 0xDC83;
nmi_poll("b7_LDC81");
X = (uint8_t)(X - 1); setZN(X);
cycles += 2;
nmi_pc = 0xDC84;
nmi_poll("b7_LDC81");
nmi_poll("b7_LDC81");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC81", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC87;
nmi_poll("b7_LDC81");
nmi_pc = 0xDC87;
nmi_poll("b7_LDC81");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDC88;
nmi_poll("b7_LDC81");
nmi_poll("b7_LDC81");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC81", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC8B;
nmi_poll("b7_LDC81");
nmi_pc = 0xDC8B;
nmi_poll("b7_LDC81");
A = X; setZN(A);
cycles += 2;
nmi_pc = 0xDC8C;
nmi_poll("b7_LDC81");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xDC8D;
nmi_poll("b7_LDC81");
{ uint8_t _m = 0x11; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xDC8F;
nmi_poll("b7_LDC81");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xDC90;
nmi_poll("b7_LDC81");
nmi_poll("b7_LDC81");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC81", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC93;
nmi_poll("b7_LDC81");
nmi_pc = 0xDC93;
nmi_poll("b7_LDC81");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDC94;
nmi_poll("b7_LDC81");
nmi_poll("b7_LDC81");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC81", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC97;
nmi_poll("b7_LDC81");
nmi_pc = 0xDC97;
nmi_poll("b7_LDC81");
A = RD(0x0000); setZN(A);
cycles += 3;
nmi_pc = 0xDC99;
nmi_poll("b7_LDC81");
cycles += 6;
return;
nmi_pc = 0xDC9A;
nmi_poll("b7_LDC81");
}
static void __attribute__((used)) b7_LDC9A(void) {
nmi_pc = 0xDC9A;
nmi_poll("b7_LDC9A");
X = RD(0x0D); setZN(X);
cycles += 3;
nmi_pc = 0xDC9C;
nmi_poll("b7_LDC9A");
nmi_poll("b7_LDC9A");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC9A", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDC9F;
nmi_poll("b7_LDC9A");
nmi_pc = 0xDC9F;
nmi_poll("b7_LDC9A");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDCA0;
nmi_poll("b7_LDC9A");
nmi_poll("b7_LDC9A");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC9A", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDCA3;
nmi_poll("b7_LDC9A");
nmi_pc = 0xDCA3;
nmi_poll("b7_LDC9A");
A = X; setZN(A);
cycles += 2;
nmi_pc = 0xDCA4;
nmi_poll("b7_LDC9A");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xDCA5;
nmi_poll("b7_LDC9A");
{ uint8_t _m = 0x11; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xDCA7;
nmi_poll("b7_LDC9A");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0xDCA8;
nmi_poll("b7_LDC9A");
nmi_poll("b7_LDC9A");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC9A", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDCAB;
nmi_poll("b7_LDC9A");
nmi_pc = 0xDCAB;
nmi_poll("b7_LDC9A");
X = (uint8_t)(X + 1); setZN(X);
cycles += 2;
nmi_pc = 0xDCAC;
nmi_poll("b7_LDC9A");
nmi_poll("b7_LDC9A");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DC47(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b7_LDC9A", "b7_entry_DC47", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xDCAF;
nmi_poll("b7_LDC9A");
nmi_pc = 0xDCAF;
nmi_poll("b7_LDC9A");
A = RD(0x0000); setZN(A);
cycles += 3;
nmi_pc = 0xDCB1;
nmi_poll("b7_LDC9A");
cycles += 6;
return;
nmi_pc = 0xDCB2;
nmi_poll("b7_LDC9A");
}
static void b7_entry_DC47(void) { __builtin_trap(); }
