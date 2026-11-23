#include "runtime.h"
static void b6_entry_B202(void);
static void __attribute__((used)) b6_entry_B202(void) {
nmi_pc = 0xB202;
nmi_poll("b6_entry_B202");
A = 0x13; setZN(A);
cycles += 2;
nmi_pc = 0xB204;
nmi_poll("b6_entry_B202");
nmi_poll("b6_entry_B202");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x06; S = (uint8_t)(S - 1);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_pc = 0xB207;
nmi_poll("b6_entry_B202");
nmi_pc = 0xB207;
nmi_poll("b6_entry_B202");
A = 0x4F; setZN(A);
cycles += 2;
nmi_pc = 0xB209;
nmi_poll("b6_entry_B202");
WR(0x46, A);
cycles += 3;
nmi_pc = 0xB20B;
nmi_poll("b6_entry_B202");
cycles += 6;
return;
nmi_pc = 0xB20C;
nmi_poll("b6_entry_B202");
}
