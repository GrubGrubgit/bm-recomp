#include "runtime.h"
static void b4_entry_80C9(void);
static void b4_ADDRMAP:/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/ADDRMAP.txt(void);
static void b4_entry_80C9_KIL(void);
static void __attribute__((used)) b4_entry_80C9(void) {
nmi_poll("b4_entry_80C9");
A = RD(0x89); setZN(A);
A = RD(0xB3); setZN(A);
cycles += 3;
nmi_poll("b4_entry_80C9");
X = RD(0xCD); setZN(X);
cycles += 3;
nmi_poll("b4_entry_80C9");
X = RD(0x03); setZN(X);
cycles += 3;
nmi_poll("b4_entry_80C9");
cycles += 3;
nmi_poll("b4_entry_80C9");
X = A; setZN(X);
cycles += 2;
nmi_poll("b4_entry_80C9");
cycles += 4;
nmi_poll("b4_entry_80C9");
P = (uint8_t)(P & 0xFB);
cycles += 2;
nmi_poll("b4_entry_80C9");
Y = RD(0xAC84); setZN(Y);
cycles += 4;
nmi_poll("b4_entry_80C9");
{ uint8_t _v = (uint8_t)(RD(0x8B9F) + 1); WR(0x8B9F, _v); setZN(_v); }
cycles += 6;
nmi_poll("b4_entry_80C9");
WR((uint16_t)(0x99AD + Y), A);
cycles += 5;
nmi_poll("b4_entry_80C9");
{ b4_entry_80C9_KIL(); return; }
}
static void b4_ADDRMAP:/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/ADDRMAP.txt(void) { __builtin_trap(); }
static void b4_entry_80C9_KIL(void) { __builtin_trap(); }
