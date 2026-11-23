#include "runtime.h"
static void b6_entry_B494(void);
static void __attribute__((used)) b6_entry_B494(void) {
nmi_pc = 0xB494;
nmi_poll("b6_entry_B494");
nmi_poll("b6_entry_B494");
cycles += 3;
goto b6_LB4A2;
nmi_pc = 0xB497;
nmi_poll("b6_entry_B494");
b6_LB4A2:;
cycles += 6;
return;
nmi_pc = 0xB4A3;
nmi_poll("b6_entry_B494");
}
