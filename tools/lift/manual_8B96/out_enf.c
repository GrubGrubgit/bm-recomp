#include "runtime.h"
static void b4_entry_8B96(void);
static void b4_entry_8BCF(void);
static void __attribute__((used)) b4_entry_8B96(void) {
nmi_poll("b4_entry_8B96");
nmi_poll("b4_entry_8B96");
cycles += 3;
b4_entry_8BCF(); return;
nmi_poll("b4_entry_8B96");
}
static void b4_entry_8BCF(void) { __builtin_trap(); }
