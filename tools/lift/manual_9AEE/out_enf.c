#include "runtime.h"
static void b4_entry_9AEE(void);
static void b4_L9ADA(void);
static void b4_L9AF3(void);
static void __attribute__((used)) b4_entry_9AEE(void) {
nmi_pc = 0x9AEE;
nmi_poll("b4_entry_9AEE");
P = (uint8_t)(P | 0x01);
cycles += 2;
nmi_pc = 0x9AEF;
nmi_poll("b4_entry_9AEE");
{ uint8_t _m = 0x01; uint16_t _r = (uint16_t)A - _m - ((P & 1) ? 0 : 1); uint8_t _R = (uint8_t)_r; P = (uint8_t)((P & 0x3C) | (_R == 0 ? 0x02 : 0) | (_R & 0x80) | ((_r & 0x100) ? 0 : 0x01) | ((((A ^ _m) & (A ^ _R)) & 0x80) ? 0x40 : 0)); A = _R; }
cycles += 2;
nmi_pc = 0x9AF1;
nmi_poll("b4_entry_9AEE");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b4_L9ADA(); return; }
nmi_pc = 0x9AF3;
nmi_poll("b4_entry_9AEE");
nmi_poll("b4_entry_9AEE");
cycles += 3;
b4_L9AF3(); return;
nmi_pc = 0x9AF6;
nmi_poll("b4_entry_9AEE");
}
static void b4_L9ADA(void) { __builtin_trap(); }
static void b4_L9AF3(void) { __builtin_trap(); }
