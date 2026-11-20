#include "runtime.h"
static void b6_entry_9885(void);
static void b6_entry_9707(void);
static void b6_x(void);
static void b7_entry_D790(void);
static void b7_entry_DECC(void);
static void __attribute__((used)) b6_entry_9885(void) {
nmi_pc = 0x9885;
nmi_poll("b6_entry_9885");
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_D790(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_9885", "b7_entry_D790", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0x9888;
nmi_poll("b6_entry_9885");
nmi_pc = 0x9888;
nmi_poll("b6_entry_9885");
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b6_entry_9707(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_9885", "b6_entry_9707", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0x988B;
nmi_poll("b6_entry_9885");
nmi_pc = 0x988B;
nmi_poll("b6_entry_9885");
A = RD((uint16_t)(0x98A4 + X)); setZN(A);
cycles += 4 + ((((0x98A4 + X) & 0xFF00) != 0x9800) ? 1 : 0);
nmi_pc = 0x988E;
nmi_poll("b6_entry_9885");
WR(0x4C, A);
cycles += 3;
nmi_pc = 0x9890;
nmi_poll("b6_entry_9885");
A = RD((uint16_t)(0x98A3 + X)); setZN(A);
cycles += 4 + ((((0x98A3 + X) & 0xFF00) != 0x9800) ? 1 : 0);
nmi_pc = 0x9893;
nmi_poll("b6_entry_9885");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0x9895;
nmi_poll("b6_entry_9885");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0x9897;
nmi_poll("b6_entry_9885");
A = 0xC0; setZN(A);
cycles += 2;
nmi_pc = 0x9899;
nmi_poll("b6_entry_9885");
WR(0x51, A);
cycles += 3;
nmi_pc = 0x989B;
nmi_poll("b6_entry_9885");
WR(0x52, A);
cycles += 3;
nmi_pc = 0x989D;
nmi_poll("b6_entry_9885");
A = 0x2F; setZN(A);
cycles += 2;
nmi_pc = 0x989F;
nmi_poll("b6_entry_9885");
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_DECC(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_9885", "b7_entry_DECC", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0x98A2;
nmi_poll("b6_entry_9885");
nmi_pc = 0x98A2;
nmi_poll("b6_entry_9885");
cycles += 6;
return;
nmi_pc = 0x98A3;
nmi_poll("b6_entry_9885");
}
static void b6_x(void) { __builtin_trap(); }
