#include "runtime.h"
static void b4_entry_923C(void);
static void b4_entry_926E(void);
static void b7_entry_C0A2(void);
static void b7_entry_C0FF(void);
static void b7_entry_C117(void);
static void b7_entry_C138(void);
static void b7_entry_C1AD(void);
static void __attribute__((used)) b4_entry_923C(void) {
nmi_poll("b4_entry_923C");
nmi_poll("b4_entry_923C");
cycles += 3;
b4_entry_926E(); return;
nmi_poll("b4_entry_923C");
}
static void __attribute__((used)) b4_entry_926E(void) {
nmi_poll("b4_entry_926E");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x40, A);
cycles += 3;
nmi_poll("b4_entry_926E");
A = 0x10; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x41, A);
cycles += 3;
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0FF(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_926E", "b7_entry_C0FF", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 2;
if (((P & 0x02))) { cycles += 2; nmi_poll("b4_entry_926E"); goto b4_LA27E; }
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 3;
b7_entry_C117(); return;
nmi_poll("b4_entry_926E");
b4_LA27E:;
nmi_poll("b4_entry_926E");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C138(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_926E", "b7_entry_C138", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0A2(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_926E", "b7_entry_C0A2", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_926E"); goto b4_LA291; }
nmi_poll("b4_entry_926E");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x44, A);
cycles += 3;
nmi_poll("b4_entry_926E");
A = 0x4C; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C1AD(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_926E", "b7_entry_C1AD", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
b4_LA291:;
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b4_entry_926E");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_poll("b4_entry_926E");
{ uint8_t _m = RD(0x50); uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 3;
nmi_poll("b4_entry_926E");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_926E"); goto b4_LA29A; }
nmi_poll("b4_entry_926E");
A = 0xF0; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
b4_LA29A:;
WR(0x3F, A);
cycles += 3;
nmi_poll("b4_entry_926E");
A = 0x3C; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x45, A);
cycles += 3;
nmi_poll("b4_entry_926E");
nmi_poll("b4_entry_926E");
cycles += 3;
b7_entry_C1AD(); return;
nmi_poll("b4_entry_926E");
A = 0x11; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x46, A);
cycles += 3;
nmi_poll("b4_entry_926E");
A = 0x09; setZN(A);
cycles += 2;
nmi_poll("b4_entry_926E");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_entry_926E");
cycles += 6;
return;
nmi_poll("b4_entry_926E");
}
