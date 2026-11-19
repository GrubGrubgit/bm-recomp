#include "runtime.h"
static void b6_entry_B3E3(void);
static void b6_entry_B3E6(void);
static void b6_entry_B3FD(void);
static void __attribute__((used)) b6_entry_B3E3(void) {
nmi_poll("b6_entry_B3E3");
nmi_poll("b6_entry_B3E3");
cycles += 3;
b6_entry_B3FD(); return;
nmi_poll("b6_entry_B3E3");
}
static void __attribute__((used)) b6_entry_B3E6(void) {
nmi_poll("b6_entry_B3E6");
A = 0x16; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B3E6");
nmi_poll("b6_entry_B3E6");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_poll("b6_entry_B3E6");
nmi_poll("b6_entry_B3E6");
A = 0xB8; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B3E6");
WR(0x47, A);
cycles += 3;
nmi_poll("b6_entry_B3E6");
A = 0x08; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B3E6");
WR(0x4D, A);
cycles += 3;
nmi_poll("b6_entry_B3E6");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B3E6");
WR(0x4C, A);
cycles += 3;
nmi_poll("b6_entry_B3E6");
WR(0x50, A);
cycles += 3;
nmi_poll("b6_entry_B3E6");
A = 0x40; setZN(A);
cycles += 2;
nmi_poll("b6_entry_B3E6");
WR(0x51, A);
cycles += 3;
nmi_poll("b6_entry_B3E6");
b6_entry_B3FD();
return;
}
static void __attribute__((used)) b6_entry_B3FD(void) {
nmi_poll("b6_entry_B3FD");
cycles += 6;
return;
nmi_poll("b6_entry_B3FD");
}
