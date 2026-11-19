#include "runtime.h"
static void b4_entry_B135(void);
static void b4_entry_B14B(void);
static void b7_entry_C01E(void);
static void b7_entry_C0FF(void);
static void b7_entry_C114(void);
static void b7_entry_C138(void);
static void b7_entry_C147(void);
static void b7_entry_C1AD(void);
static void __attribute__((used)) b4_entry_B135(void) {
nmi_poll("b4_entry_B135");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B135");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_B135");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B135");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_B135");
nmi_poll("b4_entry_B135");
cycles += 6;
nmi_poll("b4_entry_B135");
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C01E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b7_entry_C01E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
nmi_poll("b4_entry_B135");
cycles += 6;
nmi_poll("b4_entry_B135");
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C138(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b7_entry_C138", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
cycles += 2;
nmi_poll("b4_entry_B135");
if ((!(P & 0x80))) { cycles += 1; b4_entry_B14B(); return; }
nmi_poll("b4_entry_B135");
cycles += 6;
nmi_poll("b4_entry_B135");
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_9333(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b4_entry_9333", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
nmi_poll("b4_entry_B135");
cycles += 3;
nmi_poll("b4_entry_B135");
b7_entry_C114(); return;
}
static void __attribute__((used)) b4_entry_B14B(void) {
nmi_poll("b4_entry_B14B");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B14B");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_B14B");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B14B");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_B14B");
nmi_poll("b4_entry_B14B");
cycles += 6;
nmi_poll("b4_entry_B14B");
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0FF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B14B", "b7_entry_C0FF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B14B");
cycles += 2;
nmi_poll("b4_entry_B14B");
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_B14B"); goto b4_LB15B; }
nmi_poll("b4_entry_B14B");
cycles += 3;
nmi_poll("b4_entry_B14B");
b7_entry_C114(); return;
b4_LB15B:;
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B14B");
nmi_poll("b4_entry_B14B");
cycles += 6;
nmi_poll("b4_entry_B14B");
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C147(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B14B", "b7_entry_C147", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B14B");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B14B");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_B14B");
A = 0x4E; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B14B");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_B14B");
nmi_poll("b4_entry_B14B");
cycles += 3;
nmi_poll("b4_entry_B14B");
b7_entry_C1AD(); return;
}
