#include "runtime.h"
static void b4_entry_903E(void);
static void b4_entry_9060(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_903E(void) {
nmi_poll("b4_entry_903E");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_903E");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_903E");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b4_entry_903E");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_903E");
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_903E");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_entry_9060(); return; }
nmi_poll("b4_entry_903E");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_903E");
A = 0x04; setZN(A);
cycles += 2;
nmi_poll("b4_entry_903E");
WR(0x51, A);
cycles += 3;
nmi_poll("b4_entry_903E");
A = 0x20; setZN(A);
cycles += 2;
nmi_poll("b4_entry_903E");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_903E");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_903E");
WR(0x53, A);
cycles += 3;
nmi_poll("b4_entry_903E");
X = RD(0x47); setZN(X);
cycles += 3;
nmi_poll("b4_entry_903E");
A = RD((uint16_t)(0x906B + X)); setZN(A);
cycles += 4 + ((((0x906B + X) & 0xFF00) != 0x9000) ? 1 : 0);
nmi_poll("b4_entry_903E");
WR(0x47, A);
cycles += 3;
nmi_poll("b4_entry_903E");
cycles += 6;
return;
nmi_poll("b4_entry_903E");
}
static void __attribute__((used)) b4_entry_9060(void) {
nmi_poll("b4_entry_9060");
cycles += 6;
return;
nmi_poll("b4_entry_9060");
}
static void b4_x(void) { __builtin_trap(); }
