#include "runtime.h"
static void b6_entry_8A58(void);
static void __attribute__((used)) b6_entry_8A58(void) {
nmi_pc = 0x8A58;
nmi_poll("b6_entry_8A58");
nmi_poll("b6_entry_8A58");
cycles += 3;
goto b6_L8A65;
nmi_pc = 0x8A5B;
nmi_poll("b6_entry_8A58");
b6_L8A65:;
cycles += 6;
return;
nmi_pc = 0x8A66;
nmi_poll("b6_entry_8A58");
}
