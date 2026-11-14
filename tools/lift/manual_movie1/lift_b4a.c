#include "runtime.h"
static void b4_entry_B02F(void);
static void b4_entry_B032(void);
static void b4_entry_B040(void);
static void b4_entry_B041(void);
static void b4_entry_B044(void);
static void b4_entry_AFF6(void);
static void b4_entry_AFFF(void);
static void b4_entry_B004(void);
static void b4_entry_B009(void);
static void b4_entry_B054(void);
static void b7_entry_C114(void);
static void b7_entry_C1EC(void);
static void b7_entry_C216(void);
static void b7_entry_D324(void);
static void b7_entry_E02F(void);
static void __attribute__((used)) b4_entry_B02F(void) {
nmi_poll("b4_entry_B02F");
nmi_poll("b4_entry_B02F");
cycles += 3;
b4_entry_B040(); return;
}
static void __attribute__((used)) b4_entry_B032(void) {
nmi_poll("b4_entry_B032");
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x4D, A);
cycles += 5;
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
nmi_poll("b4_entry_B032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1EC();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B032");
cycles += 2;
A = 0x52; setZN(A);
nmi_poll("b4_entry_B032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C216();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B032");
cycles += 6;
return;
}
static void __attribute__((used)) b4_entry_B040(void) {
nmi_poll("b4_entry_B040");
cycles += 6;
return;
}
static void __attribute__((used)) b4_entry_B041(void) {
nmi_poll("b4_entry_B041");
nmi_poll("b4_entry_B041");
cycles += 3;
b4_entry_B054(); return;
}
static void __attribute__((used)) b4_entry_B044(void) {
nmi_poll("b4_entry_B044");
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x80; setZN(A);
cycles += 3;
WR(0x43, A);
nmi_poll("b4_entry_B044");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_E02F();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B044");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B054(); return; }
nmi_poll("b4_entry_B044");
cycles += 3;
b7_entry_C114(); return;
}
static void __attribute__((used)) b4_entry_AFF6(void) {
nmi_poll("b4_entry_AFF6");
nmi_poll("b4_entry_AFF6");
cycles += 3;
b4_entry_B009(); return;
}
static void __attribute__((used)) b4_entry_AFFF(void) {
nmi_poll("b4_entry_AFFF");
cycles += 3;
WR(0x43, A);
nmi_poll("b4_entry_AFFF");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_D324();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_AFFF");
nmi_poll("b4_entry_AFFF");
cycles += 3;
b4_entry_B004(); return;
}
static void b4_entry_B004(void) { __builtin_trap(); }
static void b4_entry_B009(void) { __builtin_trap(); }
static void b4_entry_B054(void) { __builtin_trap(); }
