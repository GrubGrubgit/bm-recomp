#include "runtime.h"
static void b6_entry_B2EC(void);
static void b6_entry_B308(void);
static void __attribute__((used)) b6_entry_B2EC(void) {
nmi_pc = 0xB2EC;
nmi_poll("b6_entry_B2EC");
nmi_poll("b6_entry_B2EC");
cycles += 3;
b6_entry_B308(); return;
nmi_pc = 0xB2EF;
nmi_poll("b6_entry_B2EC");
}
static void b6_entry_B308(void) { __builtin_trap(); }
