#include "runtime.h"
static void b6_entry_9BAA(void);
static void b6_entry_9BB1(void);
static void __attribute__((used)) b6_entry_9BAA(void) {
nmi_poll("b6_entry_9BAA");
nmi_poll("b6_entry_9BAA");
cycles += 3;
b6_entry_9BB1(); return;
}
static void b6_entry_9BB1(void) { __builtin_trap(); }
