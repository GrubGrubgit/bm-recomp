#include "runtime.h"
static void b4_entry_80C9(void);
static void b4_ADDRMAP:/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/ADDRMAP.txt(void);
static void b4_entry_80C9_KIL(void);
static void __attribute__((used)) b4_entry_80C9(void) {
nmi_poll("b4_entry_80C9");
A = RD(0x89); setZN(A);
cycles += 3;
A = RD(0xB3); setZN(A);
cycles += 3;
X = RD(0xCD); setZN(X);
cycles += 3;
X = RD(0x03); setZN(X);
cycles += 3;
cycles += 2;
X = A; setZN(X);
cycles += 4;
cycles += 2;
P = (uint8_t)(P & 0xFB);
Y = RD(0xAC84); setZN(Y);
cycles += 4;
cycles += 6;
{ uint8_t _v = (uint8_t)(RD(0x8B9F) + 1); WR(0x8B9F, _v); setZN(_v); }
cycles += 5;
WR((uint16_t)(0x99AD + Y), A);
{ b4_entry_80C9_KIL(); return; }
}
static void b4_ADDRMAP:/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/ADDRMAP.txt(void) { __builtin_trap(); }
static void b4_entry_80C9_KIL(void) { __builtin_trap(); }
