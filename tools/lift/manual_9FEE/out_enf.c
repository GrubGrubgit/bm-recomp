#include "runtime.h"
static void b4_entry_9FEE(void);
static void b4_entry_9FF1(void);
static void b7_entry_C060(void);
static void b7_entry_C0FF(void);
static void b7_entry_C11A(void);
static void b7_entry_C147(void);
static void b7_entry_C14A(void);
static void b7_entry_C17A(void);
static void b7_entry_C216(void);
static void __attribute__((used)) b4_entry_9FEE(void) {
nmi_poll("b4_entry_9FEE");
;
cycles += 2;
nmi_poll("b4_entry_9FEE");
;
cycles += 2;
nmi_poll("b4_entry_9FEE");
;
cycles += 2;
nmi_poll("b4_entry_9FEE");
b4_entry_9FF1();
return;
}
static void __attribute__((used)) b4_entry_9FF1(void) {
nmi_poll("b4_entry_9FF1");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0FF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b7_entry_C0FF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_9FF1"); goto b4_LA001; }
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 3;
b7_entry_C17A(); return;
nmi_poll("b4_entry_9FF1");
b4_LA001:;
A = RD(0x15); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = 0x02; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9FF1");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9FF1"); goto b4_LA00C; }
nmi_poll("b4_entry_9FF1");
A = RD(0xE0); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9FF1"); goto b4_LA02F; }
nmi_poll("b4_entry_9FF1");
cycles += 6;
return;
nmi_poll("b4_entry_9FF1");
b4_LA00C:;
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_A072(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b4_entry_A072", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = RD(0x03FC); A = (uint8_t)(A & _m); setZN(A); }
cycles += 4;
nmi_poll("b4_entry_9FF1");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9FF1"); goto b4_LA017; }
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 3;
b7_entry_C14A(); return;
nmi_poll("b4_entry_9FF1");
b4_LA017:;
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C147(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b7_entry_C147", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9FF1"); goto b4_LA04D; }
nmi_poll("b4_entry_9FF1");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
WR(0xE0, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
A = 0x3A; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C216(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b7_entry_C216", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
A = RD(0x15); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = 0x02; A = (uint8_t)(A | _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9FF1");
WR(0x15, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9FF1"); goto b4_LA04D; }
nmi_poll("b4_entry_9FF1");
b4_LA02F:;
A = RD(0x15); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = 0xFD; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_9FF1");
WR(0x15, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C060(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b7_entry_C060", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_A072(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9FF1", "b4_entry_A072", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9FF1");
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = RD(0x03FC); A = (uint8_t)(A | _m); setZN(A); }
cycles += 4;
nmi_poll("b4_entry_9FF1");
WR(0x03FC, A);
cycles += 4;
nmi_poll("b4_entry_9FF1");
A = RD((uint16_t)(0xA050 + X)); setZN(A);
cycles += 4 + ((((0xA050 + X) & 0xFF00) != 0xA000) ? 1 : 0);
nmi_poll("b4_entry_9FF1");
{ uint8_t _m = RD(0x99); A = (uint8_t)(A | _m); setZN(A); }
cycles += 3;
nmi_poll("b4_entry_9FF1");
WR(0x99, A);
cycles += 3;
nmi_poll("b4_entry_9FF1");
A = 0x07; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9FF1");
b4_LA04D:;
nmi_poll("b4_entry_9FF1");
cycles += 3;
b7_entry_C11A(); return;
nmi_poll("b4_entry_9FF1");
}
