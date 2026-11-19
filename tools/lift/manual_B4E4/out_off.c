#include "runtime.h"
static void b4_entry_B4E4(void);
static void __attribute__((used)) b4_entry_B4E4(void) {
nmi_poll("b4_entry_B4E4");
A = 0x06; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B4E4");
nmi_poll("b4_entry_B4E4");
cycles += 6;
nmi_poll("b4_entry_B4E4");
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B4E4");
A = 0x33; setZN(A);
cycles += 2;
nmi_poll("b4_entry_B4E4");
WR(0x46, A);
cycles += 3;
nmi_poll("b4_entry_B4E4");
cycles += 6;
return;
}
