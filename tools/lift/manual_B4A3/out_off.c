#include "runtime.h"
static void b6_entry_B4A3(void);
static void b6_entry_B508(void);
static void __attribute__((used)) b6_entry_B4A3(void) {
nmi_pc = 0xB4A3;
nmi_poll("b6_entry_B4A3");
nmi_poll("b6_entry_B4A3");
cycles += 3;
b6_entry_B508(); return;
nmi_pc = 0xB4A6;
nmi_poll("b6_entry_B4A3");
}
static void b6_entry_B508(void) { __builtin_trap(); }
