#include "runtime.h"
static void b6_entry_B575(void);
static void b7_entry_F011(void);
static void __attribute__((used)) b6_entry_B575(void) {
nmi_pc = 0xB575;
nmi_poll("b6_entry_B575");
nmi_poll("b6_entry_B575");
cycles += 3;
b7_entry_F011(); return;
nmi_pc = 0xB578;
nmi_poll("b6_entry_B575");
}
