#include "runtime.h"
static void b4_entry_B78F(void);
static void b4_entry_B7BD(void);
static void b4_x(void);
static void __attribute__((used)) b4_entry_B78F(void) {
nmi_poll("b4_entry_B78F");
nmi_poll("b4_entry_B78F");
cycles += 3;
b4_entry_B7BD(); return;
nmi_poll("b4_entry_B78F");
}
static void __attribute__((used)) b4_entry_B7BD(void) {
nmi_poll("b4_entry_B7BD");
cycles += 6;
return;
nmi_poll("b4_entry_B7BD");
}
static void b4_x(void) { __builtin_trap(); }
