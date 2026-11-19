#include "runtime.h"
static void b4_entry_B074(void);
static void b4_entry_B077(void);
static void b7_entry_C1EC(void);
static void b7_entry_C1EF(void);
static void b7_entry_C216(void);
static void __attribute__((used)) b4_entry_B074(void) {
nmi_poll("b4_entry_B074");
nmi_poll("b4_entry_B074");
cycles += 3;
goto b4_LB08A;
nmi_poll("b4_entry_B074");
}
static void __attribute__((used)) b4_entry_B077(void) {
nmi_poll("b4_entry_B077");
A = RD(0x51); setZN(A);
cycles += 3;
nmi_poll("b4_entry_B077");
WR(0x47, A);
cycles += 3;
nmi_poll("b4_entry_B077");
Y = 0x11; setZN(Y);
cycles += 2;
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1EF();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1EC();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
A = 0x1B; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C216();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B077");
nmi_poll("b4_entry_B077");
b4_LB08A:;
cycles += 6;
return;
nmi_poll("b4_entry_B077");
}
