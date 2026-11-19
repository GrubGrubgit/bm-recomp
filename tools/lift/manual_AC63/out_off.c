#include "runtime.h"
static void b6_entry_AC63(void);
static void b6_entry_ACD0(void);
static void __attribute__((used)) b6_entry_AC63(void) {
nmi_poll("b6_entry_AC63");
nmi_poll("b6_entry_AC63");
cycles += 3;
b6_entry_ACD0(); return;
nmi_poll("b6_entry_AC63");
}
static void b6_entry_ACD0(void) { __builtin_trap(); }
