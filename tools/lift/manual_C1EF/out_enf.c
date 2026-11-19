#include "runtime.h"
static void b7_entry_C1EF(void);
static void b7_entry_E1BD(void);
static void __attribute__((used)) b7_entry_C1EF(void) {
nmi_poll("b7_entry_C1EF");
nmi_poll("b7_entry_C1EF");
cycles += 3;
b7_entry_E1BD(); return;
nmi_poll("b7_entry_C1EF");
}
static void b7_entry_E1BD(void) { __builtin_trap(); }
