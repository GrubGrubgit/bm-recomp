#include "runtime.h"
static void b4_entry_9F62(void);
static void __attribute__((used)) b4_entry_9F62(void) {
nmi_pc = 0x9F62;
nmi_poll("b4_entry_9F62");
cycles += 6;
return;
nmi_pc = 0x9F63;
nmi_poll("b4_entry_9F62");
}
