#include "runtime.h"
static void b6_entry_AFFC(void);
static void b6_entry_AFFF(void);
static void b6_entry_B012(void);
static void b6_entry_A2E9(void);
static void b7_entry_E1BD(void);
static void b7_entry_EB71(void);
static void __attribute__((used)) b6_entry_AFFC(void) {
nmi_pc = 0xAFFC;
nmi_poll("b6_entry_AFFC");
nmi_poll("b6_entry_AFFC");
cycles += 3;
b6_entry_B012(); return;
nmi_pc = 0xAFFF;
nmi_poll("b6_entry_AFFC");
}
static void __attribute__((used)) b6_entry_AFFF(void) {
nmi_pc = 0xAFFF;
nmi_poll("b6_entry_AFFF");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0xB001;
nmi_poll("b6_entry_AFFF");
nmi_poll("b6_entry_AFFF");
cycles += 6;
S = (uint8_t)(S - 2);
b6_entry_A2E9();
S = (uint8_t)(S + 2);
nmi_pc = 0xB004;
nmi_poll("b6_entry_AFFF");
nmi_pc = 0xB004;
nmi_poll("b6_entry_AFFF");
nmi_poll("b6_entry_AFFF");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_EB71();
S = (uint8_t)(S + 2);
nmi_pc = 0xB007;
nmi_poll("b6_entry_AFFF");
nmi_pc = 0xB007;
nmi_poll("b6_entry_AFFF");
WR(0x47, A);
cycles += 3;
nmi_pc = 0xB009;
nmi_poll("b6_entry_AFFF");
Y = 0x14; setZN(Y);
cycles += 2;
nmi_pc = 0xB00B;
nmi_poll("b6_entry_AFFF");
nmi_poll("b6_entry_AFFF");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E1BD();
S = (uint8_t)(S + 2);
nmi_pc = 0xB00E;
nmi_poll("b6_entry_AFFF");
nmi_pc = 0xB00E;
nmi_poll("b6_entry_AFFF");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xB010;
nmi_poll("b6_entry_AFFF");
WR(0x52, A);
cycles += 3;
nmi_pc = 0xB012;
nmi_poll("b6_entry_AFFF");
cycles += 6;
return;
nmi_pc = 0xB013;
nmi_poll("b6_entry_AFFF");
}
static void __attribute__((used)) b6_entry_B012(void) {
nmi_pc = 0xB012;
nmi_poll("b6_entry_B012");
cycles += 6;
return;
nmi_pc = 0xB013;
nmi_poll("b6_entry_B012");
}
static void b6_entry_A2E9(void) { __builtin_trap(); }
