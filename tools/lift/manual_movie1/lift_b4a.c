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
static void b7_entry_E0A5(void);
static void __attribute__((used)) b4_entry_B02F(void) {
nmi_pc = 0xB02F;
nmi_poll("b4_entry_B02F");
nmi_poll("b4_entry_B02F");
cycles += 3;
b4_entry_B040(); return;
nmi_pc = 0xB032;
nmi_poll("b4_entry_B02F");
}
static void __attribute__((used)) b4_entry_B032(void) {
nmi_pc = 0xB032;
nmi_poll("b4_entry_B032");
A = 0x40; setZN(A);
cycles += 2;
nmi_pc = 0xB034;
nmi_poll("b4_entry_B032");
WR(0x4D, A);
cycles += 3;
nmi_pc = 0xB036;
nmi_poll("b4_entry_B032");
{ uint8_t _v = (uint8_t)(RD(0x46) + 1); WR(0x46, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xB038;
nmi_poll("b4_entry_B032");
nmi_poll("b4_entry_B032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C1EC();
S = (uint8_t)(S + 2);
nmi_pc = 0xB03B;
nmi_poll("b4_entry_B032");
nmi_pc = 0xB03B;
nmi_poll("b4_entry_B032");
A = 0x52; setZN(A);
cycles += 2;
nmi_pc = 0xB03D;
nmi_poll("b4_entry_B032");
nmi_poll("b4_entry_B032");
cycles += 6;
S = (uint8_t)(S - 2);
b7_entry_C216();
S = (uint8_t)(S + 2);
nmi_pc = 0xB040;
nmi_poll("b4_entry_B032");
nmi_pc = 0xB040;
nmi_poll("b4_entry_B032");
cycles += 6;
return;
nmi_pc = 0xB041;
nmi_poll("b4_entry_B032");
}
static void __attribute__((used)) b4_entry_B040(void) {
nmi_pc = 0xB040;
nmi_poll("b4_entry_B040");
cycles += 6;
return;
nmi_pc = 0xB041;
nmi_poll("b4_entry_B040");
}
static void __attribute__((used)) b4_entry_B041(void) {
nmi_pc = 0xB041;
nmi_poll("b4_entry_B041");
nmi_poll("b4_entry_B041");
cycles += 3;
b4_entry_B054(); return;
nmi_pc = 0xB044;
nmi_poll("b4_entry_B041");
}
static void __attribute__((used)) b4_entry_B044(void) {
nmi_pc = 0xB044;
nmi_poll("b4_entry_B044");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB046;
nmi_poll("b4_entry_B044");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xB048;
nmi_poll("b4_entry_B044");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB04A;
nmi_poll("b4_entry_B044");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xB04C;
nmi_poll("b4_entry_B044");
nmi_poll("b4_entry_B044");
cycles += 9; /* SLOT-JSR: JSR6+JMP3 */
S = (uint8_t)(S - 2);
b7_entry_E0A5();
S = (uint8_t)(S + 2);
nmi_pc = 0xB04F;
nmi_poll("b4_entry_B044");
nmi_pc = 0xB04F;
nmi_poll("b4_entry_B044");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b4_entry_B054(); return; }
nmi_pc = 0xB051;
nmi_poll("b4_entry_B044");
nmi_poll("b4_entry_B044");
cycles += 3;
b7_entry_C114(); return;
nmi_pc = 0xB054;
nmi_poll("b4_entry_B044");
}
static void __attribute__((used)) b4_entry_AFF6(void) {
nmi_pc = 0xAFF6;
nmi_poll("b4_entry_AFF6");
nmi_poll("b4_entry_AFF6");
cycles += 3;
b4_entry_B009(); return;
nmi_pc = 0xAFF9;
nmi_poll("b4_entry_AFF6");
}
static void __attribute__((used)) b4_entry_AFFF(void) {
nmi_pc = 0xAFFF;
nmi_poll("b4_entry_AFFF");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xB001;
nmi_poll("b4_entry_AFFF");
nmi_poll("b4_entry_AFFF");
cycles += 9; /* SLOT-JSR: JSR6+JMP3 */
S = (uint8_t)(S - 2);
b7_entry_D324();
S = (uint8_t)(S + 2);
nmi_pc = 0xB004;
nmi_poll("b4_entry_AFFF");
nmi_pc = 0xB004;
nmi_poll("b4_entry_AFFF");
nmi_poll("b4_entry_AFFF");
cycles += 3;
b4_entry_B004(); return;
nmi_pc = 0xB007;
nmi_poll("b4_entry_AFFF");
}
static void b4_entry_B004(void) { __builtin_trap(); }
static void b4_entry_B009(void) { __builtin_trap(); }
static void b4_entry_B054(void) { __builtin_trap(); }
