#include "runtime.h"
static void b4_entry_BD5C(void);
static void b4_entry_BD5F(void);
static void b4_entry_BD69(void);
static void b4_entry_BD6C(void);
static void b4_entry_B2B4(void);
static void b4_entry_BD9D(void);
static void b4_entry_BE3E(void);
static void __attribute__((used)) b4_entry_BD5C(void) {
nmi_poll("b4_entry_BD5C");
nmi_poll("b4_entry_BD5C");
cycles += 3;
goto b4_LBD68;
nmi_poll("b4_entry_BD5C");
}
static void __attribute__((used)) b4_entry_BD5F(void) {
nmi_poll("b4_entry_BD5F");
A = 0x00; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BD5F");
WR(0x52, A);
cycles += 3;
nmi_poll("b4_entry_BD5F");
A = 0x0D; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BD5F");
nmi_poll("b4_entry_BD5F");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_B2B4();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BD5F");
nmi_poll("b4_entry_BD5F");
b4_LBD68:;
cycles += 6;
return;
nmi_poll("b4_entry_BD5F");
}
static void __attribute__((used)) b4_entry_BD69(void) {
nmi_poll("b4_entry_BD69");
nmi_poll("b4_entry_BD69");
cycles += 3;
b4_entry_BD9D(); return;
nmi_poll("b4_entry_BD69");
}
static void __attribute__((used)) b4_entry_BD6C(void) {
nmi_poll("b4_entry_BD6C");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BD6C");
WR(0x42, A);
cycles += 3;
nmi_poll("b4_entry_BD6C");
A = 0x80; setZN(A);
cycles += 2;
nmi_poll("b4_entry_BD6C");
WR(0x43, A);
cycles += 3;
nmi_poll("b4_entry_BD6C");
A = RD(0x52); setZN(A);
cycles += 3;
nmi_poll("b4_entry_BD6C");
cycles += 2;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD7A; }
nmi_poll("b4_entry_BD6C");
{ uint8_t _v = (uint8_t)(RD(0x52) - 1); WR(0x52, _v); setZN(_v); }
cycles += 5;
nmi_poll("b4_entry_BD6C");
b4_LBD7A:;
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_LC045();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD84; }
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_BD6C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_BD6C");
b4_LBD84:;
WR(0x00, A);
cycles += 3;
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_LC04E();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD90; }
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_poll("b4_entry_BD6C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_poll("b4_entry_BD6C");
b4_LBD90:;
{ uint8_t _m = RD(0x00); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 3;
nmi_poll("b4_entry_BD6C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD96; }
nmi_poll("b4_entry_BD6C");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_poll("b4_entry_BD6C");
b4_LBD96:;
{ uint8_t _m = 0x02; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_poll("b4_entry_BD6C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b4_entry_BD9D(); return; }
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
b4_entry_BE3E();
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 3;
b4_entry_BD9D(); return;
nmi_poll("b4_entry_BD6C");
}
static void b4_entry_B2B4(void) { __builtin_trap(); }
static void b4_entry_BD9D(void) { __builtin_trap(); }
static void b4_entry_BE3E(void) { __builtin_trap(); }
