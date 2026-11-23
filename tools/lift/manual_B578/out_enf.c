#include "runtime.h"
static void b6_entry_B578(void);
static void __attribute__((used)) b6_entry_B578(void) {
nmi_pc = 0xB578;
nmi_poll("b6_entry_B578");
nmi_poll("b6_entry_B578");
cycles += 3;
goto b6_LB58A;
nmi_pc = 0xB57B;
nmi_poll("b6_entry_B578");
b6_LB58A:;
cycles += 6;
return;
nmi_pc = 0xB58B;
nmi_poll("b6_entry_B578");
}
