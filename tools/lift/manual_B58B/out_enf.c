#include "runtime.h"
static void b6_entry_B58B(void);
static void b6_entry_B5FB(void);
static void __attribute__((used)) b6_entry_B58B(void) {
nmi_pc = 0xB58B;
nmi_poll("b6_entry_B58B");
nmi_poll("b6_entry_B58B");
cycles += 3;
b6_entry_B5FB(); return;
nmi_pc = 0xB58E;
nmi_poll("b6_entry_B58B");
}
static void b6_entry_B5FB(void) { __builtin_trap(); }
