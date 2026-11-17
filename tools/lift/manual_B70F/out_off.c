#include "runtime.h"
static void b6_entry_B70F(void);
static void b6_entry_B713(void);
static void __attribute__((used)) b6_entry_B70F(void) {
nmi_poll("b6_entry_B70F");
{ uint8_t _m = RD(0x2B20); A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 4;
cycles += 2;
P = (uint8_t)(P & 0xBF);
nmi_poll("b6_entry_B70F");
cycles += 3;
b6_entry_B713(); return;
}
static void b6_entry_B713(void) { __builtin_trap(); }
