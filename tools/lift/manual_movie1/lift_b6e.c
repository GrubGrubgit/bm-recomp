#include "runtime.h"
static void b6_entry_9FDA(void);
static void b6_entry_9FDD(void);
static void b6_entry_9FF8(void);
static void b6_entry_9FF8x(void);
static void b7_entry_D02D(void);
static void b7_entry_EF2B(void);
static void __attribute__((used)) b6_entry_9FDA(void) {
nmi_poll("b6_entry_9FDA");
nmi_poll("b6_entry_9FDA");
cycles += 3;
b6_entry_9FF8(); return;
nmi_poll("b6_entry_9FDA");
}
static void __attribute__((used)) b6_entry_9FDD(void) {
nmi_poll("b6_entry_9FDD");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b6_entry_9FDD");
nmi_poll("b6_entry_9FDD");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EF2B();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_9FDD");
nmi_poll("b6_entry_9FDD");
A = RD(0x3E); setZN(A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
WR(0x00, A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
A = RD(0x3F); setZN(A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
WR(0x01, A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
A = RD(0x7C); setZN(A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
WR(0x02, A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
A = RD(0x7D); setZN(A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
WR(0x03, A);
cycles += 3;
nmi_poll("b6_entry_9FDD");
nmi_poll("b6_entry_9FDD");
cycles += 3;
b7_entry_D02D(); return;
nmi_poll("b6_entry_9FDD");
}
static void __attribute__((used)) b6_entry_9FF8(void) {
nmi_poll("b6_entry_9FF8");
cycles += 6;
return;
nmi_poll("b6_entry_9FF8");
}
static void b6_entry_9FF8x(void) { __builtin_trap(); }
