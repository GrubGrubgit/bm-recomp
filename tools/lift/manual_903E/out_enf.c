#include "runtime.h"
static void b4_entry_903E(void);
static void b4_entry_9060(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_903E(void) {
nmi_poll("b4_entry_903E");
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x43, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x51) - 1); WR(0x51, _v); setZN(_v); }
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_entry_9060(); return; }
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 2;
A = 0x04; setZN(A);
cycles += 3;
WR(0x51, A);
cycles += 2;
A = 0x20; setZN(A);
cycles += 3;
WR(0x50, A);
cycles += 2;
A = 0x00; setZN(A);
cycles += 3;
WR(0x53, A);
X = RD(0x47); setZN(X);
cycles += 3;
A = RD((uint16_t)(0x906B + X)); setZN(A);
cycles += 4 + ((((0x906B + X) & 0xFF00) != 0x9000) ? 1 : 0);
cycles += 3;
WR(0x47, A);
cycles += 6;
return;
}
static void __attribute__((used)) b4_entry_9060(void) {
nmi_poll("b4_entry_9060");
cycles += 6;
return;
}
static void b4_x(void) { __builtin_trap(); }
