#include "runtime.h"
static void b6_entry_B97A(void);
static void b6_entry_B9C0(void);
static void __attribute__((used)) b6_entry_B97A(void) {
nmi_pc = 0xB97A;
nmi_poll("b6_entry_B97A");
nmi_poll("b6_entry_B97A");
cycles += 3;
b6_entry_B9C0(); return;
nmi_pc = 0xB97D;
nmi_poll("b6_entry_B97A");
}
static void b6_entry_B9C0(void) { __builtin_trap(); }
