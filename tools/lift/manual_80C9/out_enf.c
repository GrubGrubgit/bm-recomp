#include "runtime.h"
static void b4_entry_80C9(void);
static void b4_entry_80C9_KIL(void);
static void __attribute__((used)) b4_entry_80C9(void) {
nmi_pc = 0x80C9;
nmi_poll("b4_entry_80C9");
A = RD(0x89); setZN(A);
cycles += 3;
nmi_pc = 0x80CB;
nmi_poll("b4_entry_80C9");
A = RD(0xB3); setZN(A);
cycles += 3;
nmi_pc = 0x80CD;
nmi_poll("b4_entry_80C9");
X = RD(0xCD); setZN(X);
cycles += 3;
nmi_pc = 0x80CF;
nmi_poll("b4_entry_80C9");
X = RD(0x03); setZN(X);
cycles += 3;
nmi_pc = 0x80D1;
nmi_poll("b4_entry_80C9");
X = A; setZN(X);
cycles += 2;
nmi_pc = 0x80D2;
nmi_poll("b4_entry_80C9");
cycles += 4;
P = (uint8_t)(P & 0xFB);
cycles += 2;
nmi_pc = 0x80D5;
nmi_poll("b4_entry_80C9");
Y = RD(0xAC84); setZN(Y);
cycles += 4;
nmi_pc = 0x80D8;
nmi_poll("b4_entry_80C9");
{ uint8_t _v = (uint8_t)(RD(0x8B9F) + 1); WR(0x8B9F, _v); setZN(_v); }
cycles += 6;
nmi_pc = 0x80DB;
nmi_poll("b4_entry_80C9");
WR((uint16_t)(0x99AD + Y), A);
cycles += 5;
nmi_pc = 0x80DE;
nmi_poll("b4_entry_80C9");
{ b4_entry_80C9_KIL(); return; }
}
static void b4_entry_80C9_KIL(void) { __builtin_trap(); }
