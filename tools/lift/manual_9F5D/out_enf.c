#include "runtime.h"
static void b4_entry_9F5D(void);
static void b7_entry_C0DE(void);
static void __attribute__((used)) b4_entry_9F5D(void) {
nmi_poll("b4_entry_9F5D");
cycles += 2;
P = (uint8_t)(P & 0xFE);
nmi_poll("b4_entry_9F5D");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C0DE(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_9F5D", "b7_entry_C0DE", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9F5D");
cycles += 6;
return;
}
