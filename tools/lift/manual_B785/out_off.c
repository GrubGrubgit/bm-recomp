#include "runtime.h"
static void b4_entry_B785(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_B785(void) {
nmi_poll("b4_entry_B785");
A = 0x0B; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B785");
nmi_poll("b4_entry_B785");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B785");
nmi_poll("b4_entry_B785");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B785");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_B785");
cycles += 6;
return;
nmi_poll("b4_entry_B785");
}
static void b4_x(void) { __builtin_trap(); }
