#include "runtime.h"
static void b4_entry_9F5D(void);
static void b7_entry_C0DE(void);
static void __attribute__((used)) b4_entry_9F5D(void) {
nmi_poll("b4_entry_9F5D");
cycles += 2;
P = (uint8_t)(P & 0xFE);
nmi_poll("b4_entry_9F5D");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C0DE();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_9F5D");
cycles += 6;
return;
}
