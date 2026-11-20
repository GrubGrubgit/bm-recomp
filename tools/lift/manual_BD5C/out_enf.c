#include "runtime.h"
static void b4_entry_BD5C(void);
static void b4_entry_BD5F(void);
static void b4_entry_BD69(void);
static void b4_entry_BD6C(void);
static void b4_LC045(void);
static void b4_LC04E(void);
static void b4_entry_B2B4(void);
static void b4_entry_BD9D(void);
static void b4_entry_BE3E(void);
static void __attribute__((used)) b4_entry_BD5C(void) {
nmi_pc = 0xBD5C;
nmi_poll("b4_entry_BD5C");
nmi_poll("b4_entry_BD5C");
cycles += 3;
goto b4_LBD68;
nmi_pc = 0xBD5F;
nmi_poll("b4_entry_BD5C");
}
static void __attribute__((used)) b4_entry_BD5F(void) {
nmi_pc = 0xBD5F;
nmi_poll("b4_entry_BD5F");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0xBD61;
nmi_poll("b4_entry_BD5F");
WR(0x52, A);
cycles += 3;
nmi_pc = 0xBD63;
nmi_poll("b4_entry_BD5F");
A = 0x0D; setZN(A);
cycles += 2;
nmi_pc = 0xBD65;
nmi_poll("b4_entry_BD5F");
nmi_poll("b4_entry_BD5F");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_B2B4(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BD5F", "b4_entry_B2B4", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xBD68;
nmi_poll("b4_entry_BD5F");
nmi_pc = 0xBD68;
nmi_poll("b4_entry_BD5F");
b4_LBD68:;
cycles += 6;
return;
nmi_pc = 0xBD69;
nmi_poll("b4_entry_BD5F");
}
static void __attribute__((used)) b4_entry_BD69(void) {
nmi_pc = 0xBD69;
nmi_poll("b4_entry_BD69");
nmi_poll("b4_entry_BD69");
cycles += 3;
b4_entry_BD9D(); return;
nmi_pc = 0xBD6C;
nmi_poll("b4_entry_BD69");
}
static void __attribute__((used)) b4_entry_BD6C(void) {
nmi_pc = 0xBD6C;
nmi_poll("b4_entry_BD6C");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xBD6E;
nmi_poll("b4_entry_BD6C");
WR(0x42, A);
cycles += 3;
nmi_pc = 0xBD70;
nmi_poll("b4_entry_BD6C");
A = 0x80; setZN(A);
cycles += 2;
nmi_pc = 0xBD72;
nmi_poll("b4_entry_BD6C");
WR(0x43, A);
cycles += 3;
nmi_pc = 0xBD74;
nmi_poll("b4_entry_BD6C");
A = RD(0x52); setZN(A);
cycles += 3;
nmi_pc = 0xBD76;
nmi_poll("b4_entry_BD6C");
cycles += 2;
nmi_pc = 0xBD7A;
if (((P & 0x02))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD7A; }
nmi_pc = 0xBD78;
nmi_poll("b4_entry_BD6C");
{ uint8_t _v = (uint8_t)(RD(0x52) - 1); WR(0x52, _v); setZN(_v); }
cycles += 5;
nmi_pc = 0xBD7A;
nmi_poll("b4_entry_BD6C");
b4_LBD7A:;
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC045(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BD6C", "b4_LC045", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xBD7D;
nmi_poll("b4_entry_BD6C");
nmi_pc = 0xBD7D;
nmi_poll("b4_entry_BD6C");
cycles += 2;
nmi_pc = 0xBD84;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD84; }
nmi_pc = 0xBD7F;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBD81;
nmi_poll("b4_entry_BD6C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xBD82;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xBD84;
nmi_poll("b4_entry_BD6C");
b4_LBD84:;
WR(0x00, A);
cycles += 3;
nmi_pc = 0xBD86;
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_LC04E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BD6C", "b4_LC04E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xBD89;
nmi_poll("b4_entry_BD6C");
nmi_pc = 0xBD89;
nmi_poll("b4_entry_BD6C");
cycles += 2;
nmi_pc = 0xBD90;
if ((!(P & 0x80))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD90; }
nmi_pc = 0xBD8B;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0xFF; A = (uint8_t)(A ^ _m); setZN(A); }
cycles += 2;
nmi_pc = 0xBD8D;
nmi_poll("b4_entry_BD6C");
P = (uint8_t)(P & 0xFE);
cycles += 2;
nmi_pc = 0xBD8E;
nmi_poll("b4_entry_BD6C");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A + _m + (P & 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0x01 : 0) | ((((A ^ _R) & (_m ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0xBD90;
nmi_poll("b4_entry_BD6C");
b4_LBD90:;
{ uint8_t _m = RD(0x00); uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 3;
nmi_pc = 0xBD92;
nmi_poll("b4_entry_BD6C");
cycles += 2;
nmi_pc = 0xBD96;
if (((P & 0x01))) { cycles += 1; nmi_poll("b4_entry_BD6C"); goto b4_LBD96; }
nmi_pc = 0xBD94;
nmi_poll("b4_entry_BD6C");
A = RD(0x00); setZN(A);
cycles += 3;
nmi_pc = 0xBD96;
nmi_poll("b4_entry_BD6C");
b4_LBD96:;
{ uint8_t _m = 0x02; uint8_t _r = (uint8_t)(A - _m); P = (uint8_t)((P & 0x7C) | (A >= _m ? 1 : 0) | (_r == 0 ? 2 : 0) | (_r & 0x80)); }
cycles += 2;
nmi_pc = 0xBD98;
nmi_poll("b4_entry_BD6C");
cycles += 2;
if (((P & 0x01))) { cycles += 1; b4_entry_BD9D(); return; }
nmi_pc = 0xBD9A;
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_BE3E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_BD6C", "b4_entry_BE3E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_pc = 0xBD9D;
nmi_poll("b4_entry_BD6C");
nmi_pc = 0xBD9D;
nmi_poll("b4_entry_BD6C");
nmi_poll("b4_entry_BD6C");
cycles += 3;
b4_entry_BD9D(); return;
nmi_pc = 0xBDA0;
nmi_poll("b4_entry_BD6C");
}
static void b4_entry_B2B4(void) { __builtin_trap(); }
static void b4_entry_BD9D(void) { __builtin_trap(); }
static void b4_entry_BE3E(void) { __builtin_trap(); }
