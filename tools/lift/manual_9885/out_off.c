#include "runtime.h"
static void b6_entry_9885(void);
static void b6_x(void);
static void b7_entry_D790(void);
static void b7_entry_DECC(void);
static void __attribute__((used)) b6_entry_9885(void) {
nmi_poll("b6_entry_9885");
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D790();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9885");
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_9707();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9885");
A = RD((uint16_t)(0x98A4 + X)); setZN(A);
cycles += 4 + ((((0x98A4 + X) & 0xFF00) != 0x9800) ? 1 : 0);
cycles += 3;
WR(0x4C, A);
A = RD((uint16_t)(0x98A3 + X)); setZN(A);
cycles += 4 + ((((0x98A3 + X) & 0xFF00) != 0x9800) ? 1 : 0);
cycles += 3;
WR(0x4D, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 2;
A = 0xC0; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 3;
WR(0x52, A);
cycles += 2;
A = 0x2F; setZN(A);
nmi_poll("b6_entry_9885");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_DECC();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9885");
cycles += 6;
return;
}
static void b6_x(void) { __builtin_trap(); }
