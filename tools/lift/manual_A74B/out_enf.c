#include "runtime.h"
static void b4_entry_A74B(void);
static void __attribute__((used)) b4_entry_A74B(void) {
nmi_poll("b4_entry_A74B");
WR(0x50, A);
cycles += 3;
nmi_poll("b4_entry_A74B");
cycles += 6;
return;
}
