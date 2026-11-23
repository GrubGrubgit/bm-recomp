#include "runtime.h"
static void b6_entry_B20F(void);
static void b6_entry_B23F(void);
static void b7_entry_D7F8(void);
static void b7_entry_DECC(void);
static void b7_entry_EB71(void);
static void b7_entry_EF2B(void);
static void __attribute__((used)) b6_entry_B20F(void) {
nmi_pc = 0xB20F;
nmi_poll("b6_entry_B20F");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB211;
nmi_poll("b6_entry_B20F");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xB213;
nmi_poll("b6_entry_B20F");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xB215;
nmi_poll("b6_entry_B20F");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xB217;
nmi_poll("b6_entry_B20F");
nmi_poll("b6_entry_B20F");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x19; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b7_entry_EF2B(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B20F", "b7_entry_EF2B", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB21A;
nmi_poll("b6_entry_B20F");
nmi_pc = 0xB21A;
nmi_poll("b6_entry_B20F");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_B23F(); return; }
nmi_pc = 0xB21C;
nmi_poll("b6_entry_B20F");
A = RD(0x11); setZN(A);
cycles += 3;
nmi_pc = 0xB21E;
nmi_poll("b6_entry_B20F");
{ uint8_t _m = 0x1F; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xB220;
nmi_poll("b6_entry_B20F");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_B23F(); return; }
nmi_pc = 0xB222;
nmi_poll("b6_entry_B20F");
nmi_poll("b6_entry_B20F");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x24; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b7_entry_EB71(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B20F", "b7_entry_EB71", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB225;
nmi_poll("b6_entry_B20F");
nmi_pc = 0xB225;
nmi_poll("b6_entry_B20F");
{ uint8_t _m = 0x60; A = (uint8_t)(A & _m); setZN(A); }
cycles += 2;
nmi_pc = 0xB227;
nmi_poll("b6_entry_B20F");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_B23F(); return; }
nmi_pc = 0xB229;
nmi_poll("b6_entry_B20F");
A = 0x28; setZN(A);
cycles += 2;
nmi_pc = 0xB22B;
nmi_poll("b6_entry_B20F");
nmi_poll("b6_entry_B20F");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x2D; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b6_entry_A29E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B20F", "b6_entry_A29E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB22E;
nmi_poll("b6_entry_B20F");
nmi_pc = 0xB22E;
nmi_poll("b6_entry_B20F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_B23F(); return; }
nmi_pc = 0xB230;
nmi_poll("b6_entry_B20F");
A = 0x7C; setZN(A);
cycles += 2;
nmi_pc = 0xB232;
nmi_poll("b6_entry_B20F");
WR((uint16_t)(0x0400 + X), A);
cycles += 5;
nmi_pc = 0xB235;
nmi_poll("b6_entry_B20F");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xB237;
nmi_poll("b6_entry_B20F");
WR((uint16_t)(0x0407 + X), A);
cycles += 5;
nmi_pc = 0xB23A;
nmi_poll("b6_entry_B20F");
A = 0x24; setZN(A);
cycles += 2;
nmi_pc = 0xB23C;
nmi_poll("b6_entry_B20F");
nmi_poll("b6_entry_B20F");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x3E; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b7_entry_DECC(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B20F", "b7_entry_DECC", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB23F;
nmi_poll("b6_entry_B20F");
nmi_pc = 0xB23F;
nmi_poll("b6_entry_B20F");
b6_entry_B23F();
return;
}
static void __attribute__((used)) b6_entry_B23F(void) {
nmi_pc = 0xB23F;
nmi_poll("b6_entry_B23F");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0xB241;
nmi_poll("b6_entry_B23F");
WR(0x40, A);
cycles += 3;
nmi_pc = 0xB243;
nmi_poll("b6_entry_B23F");
A = 0x10; setZN(A);
cycles += 2;
nmi_pc = 0xB245;
nmi_poll("b6_entry_B23F");
WR(0x41, A);
cycles += 3;
nmi_pc = 0xB247;
nmi_poll("b6_entry_B23F");
nmi_poll("b6_entry_B23F");
cycles += 6;
stk[S] = 0xB2; S = (uint8_t)(S - 1);
stk[S] = 0x49; S = (uint8_t)(S - 1);
{ uint8_t _uw_s = S; b7_entry_EF2B(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b6_entry_B23F", "b7_entry_EF2B", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xB24A;
nmi_poll("b6_entry_B23F");
nmi_pc = 0xB24A;
nmi_poll("b6_entry_B23F");
cycles += 2;
nmi_pc = 0xB24F;
if (((P & 0x02))) { cycles += 1; nmi_poll("b6_entry_B23F"); goto b6_LB24F; }
nmi_pc = 0xB24C;
nmi_poll("b6_entry_B23F");
nmi_poll("b6_entry_B23F");
cycles += 3;
b7_entry_D7F8(); return;
nmi_pc = 0xB24F;
nmi_poll("b6_entry_B23F");
b6_LB24F:;
cycles += 6;
return;
nmi_pc = 0xB250;
nmi_poll("b6_entry_B23F");
}
