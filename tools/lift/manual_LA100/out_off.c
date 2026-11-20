#include "runtime.h"
static void b4_LA100(void);
static void b4_LC10E(void);
static void b4_LC11A(void);
static void b4_entry_A072(void);
static void __attribute__((used)) b4_LA100(void) {
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
cycles += 6;
S = (uint8_t)(S - 2);
b4_LC10E();
S = (uint8_t)(S + 2);
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_A072();
S = (uint8_t)(S + 2);
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
{ uint8_t _m = RD(0x03FB); A = (uint8_t)(A | _m); setZN(A); }
cycles += 4;
nmi_poll("b4_LA100");
WR(0x03FB, A);
cycles += 4;
nmi_poll("b4_LA100");
A = 0x5A; setZN(A);
cycles += 2;
nmi_poll("b4_LA100");
WR(0x46, A);
cycles += 3;
nmi_poll("b4_LA100");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
cycles += 6;
S = (uint8_t)(S - 2);
b4_LC11A();
S = (uint8_t)(S + 2);
nmi_poll("b4_LA100");
nmi_poll("b4_LA100");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_LA100");
S = (uint8_t)(S + 1); A = stk[S]; setZN(A);
cycles += 4;
nmi_poll("b4_LA100");
cycles += 6;
return;
nmi_poll("b4_LA100");
}
static void b4_LC10E(void) { __builtin_trap(); }
static void b4_LC11A(void) { __builtin_trap(); }
static void b4_entry_A072(void) { __builtin_trap(); }
