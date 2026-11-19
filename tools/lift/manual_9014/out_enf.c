#include "runtime.h"
static void b4_entry_9014(void);
static void b4_x(void);
static void b7_entry_C114(void);
static void b7_entry_C216(void);
static void __attribute__((used)) b4_entry_9014(void) {
nmi_poll("b4_entry_9014");
A = RD(0x57); setZN(A);
cycles += 3;
nmi_poll("b4_entry_9014");
{ uint8_t _m = 0x01; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_9014");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; nmi_poll("b4_entry_9014"); goto b4_L901F; }
nmi_poll("b4_entry_9014");
A = 0x06; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9014");
WR(0x46, A);
cycles += 3;
nmi_poll("b4_entry_9014");
cycles += 6;
return;
nmi_poll("b4_entry_9014");
b4_L901F:;
{ uint8_t _m = 0x05; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_9014");
cycles += 2;
if ((!(P & 0x01))) { cycles += 1; nmi_poll("b4_entry_9014"); goto b4_L9026; }
nmi_poll("b4_entry_9014");
nmi_poll("b4_entry_9014");
cycles += 3;
b7_entry_C114(); return;
nmi_poll("b4_entry_9014");
b4_L9026:;
nmi_poll("b4_entry_9014");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_8E95(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9014", "b4_entry_8E95", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9014");
nmi_poll("b4_entry_9014");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9014");
WR(0x4C, A);
cycles += 3;
nmi_poll("b4_entry_9014");
WR(0x4D, A);
cycles += 3;
nmi_poll("b4_entry_9014");
A = 0x03; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9014");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_entry_9014");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_9014");
A = 0x1B; setZN(A);
cycles += 2;
nmi_poll("b4_entry_9014");
nmi_poll("b4_entry_9014");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C216(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9014", "b7_entry_C216", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9014");
nmi_poll("b4_entry_9014");
cycles += 6;
return;
nmi_poll("b4_entry_9014");
}
static void b4_x(void) { __builtin_trap(); }
