#include "runtime.h"
static void b4_entry_8BFD(void);
static void b4_entry_8C16(void);
static void __attribute__((used)) b4_entry_8BFD(void) {
nmi_poll("b4_entry_8BFD");
nmi_poll("b4_entry_8BFD");
cycles += 3;
b4_entry_8C16(); return;
nmi_poll("b4_entry_8BFD");
}
static void b4_entry_8C16(void) { __builtin_trap(); }
