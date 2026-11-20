#include "runtime.h"
static void b6_entry_9C1F(void);
static void b6_entry_9C26(void);
static void b6_entry_9C2D(void);
static void b6_entry_9C34(void);
static void b6_entry_9C3B(void);
static void b6_entry_9C42(void);
static void b6_entry_9C49(void);
static void b6_entry_9C50(void);
static void b6_entry_9C57(void);
static void b6_entry_9C5B(void);
static void b6_x(void);
static void b7_entry_D2B9(void);
static void __attribute__((used)) b6_entry_9C1F(void) {
nmi_pc = 0x9C1F;
nmi_poll("b6_entry_9C1F");
;
cycles += 2;
nmi_pc = 0x9C20;
nmi_poll("b6_entry_9C1F");
;
cycles += 2;
nmi_pc = 0x9C21;
nmi_poll("b6_entry_9C1F");
;
cycles += 2;
nmi_pc = 0x9C22;
nmi_poll("b6_entry_9C1F");
A = 0x00; setZN(A);
cycles += 2;
nmi_pc = 0x9C24;
nmi_poll("b6_entry_9C1F");
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C26;
nmi_poll("b6_entry_9C1F");
b6_entry_9C26();
return;
}
static void __attribute__((used)) b6_entry_9C26(void) {
nmi_pc = 0x9C26;
nmi_poll("b6_entry_9C26");
;
cycles += 2;
nmi_pc = 0x9C27;
nmi_poll("b6_entry_9C26");
;
cycles += 2;
nmi_pc = 0x9C28;
nmi_poll("b6_entry_9C26");
;
cycles += 2;
nmi_pc = 0x9C29;
nmi_poll("b6_entry_9C26");
A = 0x01; setZN(A);
cycles += 2;
nmi_pc = 0x9C2B;
nmi_poll("b6_entry_9C26");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C2D;
nmi_poll("b6_entry_9C26");
b6_entry_9C2D();
return;
}
static void __attribute__((used)) b6_entry_9C2D(void) {
nmi_pc = 0x9C2D;
nmi_poll("b6_entry_9C2D");
;
cycles += 2;
nmi_pc = 0x9C2E;
nmi_poll("b6_entry_9C2D");
;
cycles += 2;
nmi_pc = 0x9C2F;
nmi_poll("b6_entry_9C2D");
;
cycles += 2;
nmi_pc = 0x9C30;
nmi_poll("b6_entry_9C2D");
A = 0x02; setZN(A);
cycles += 2;
nmi_pc = 0x9C32;
nmi_poll("b6_entry_9C2D");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C34;
nmi_poll("b6_entry_9C2D");
b6_entry_9C34();
return;
}
static void __attribute__((used)) b6_entry_9C34(void) {
nmi_pc = 0x9C34;
nmi_poll("b6_entry_9C34");
;
cycles += 2;
nmi_pc = 0x9C35;
nmi_poll("b6_entry_9C34");
;
cycles += 2;
nmi_pc = 0x9C36;
nmi_poll("b6_entry_9C34");
;
cycles += 2;
nmi_pc = 0x9C37;
nmi_poll("b6_entry_9C34");
A = 0x03; setZN(A);
cycles += 2;
nmi_pc = 0x9C39;
nmi_poll("b6_entry_9C34");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C3B;
nmi_poll("b6_entry_9C34");
b6_entry_9C3B();
return;
}
static void __attribute__((used)) b6_entry_9C3B(void) {
nmi_pc = 0x9C3B;
nmi_poll("b6_entry_9C3B");
;
cycles += 2;
nmi_pc = 0x9C3C;
nmi_poll("b6_entry_9C3B");
;
cycles += 2;
nmi_pc = 0x9C3D;
nmi_poll("b6_entry_9C3B");
;
cycles += 2;
nmi_pc = 0x9C3E;
nmi_poll("b6_entry_9C3B");
A = 0x04; setZN(A);
cycles += 2;
nmi_pc = 0x9C40;
nmi_poll("b6_entry_9C3B");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C42;
nmi_poll("b6_entry_9C3B");
b6_entry_9C42();
return;
}
static void __attribute__((used)) b6_entry_9C42(void) {
nmi_pc = 0x9C42;
nmi_poll("b6_entry_9C42");
;
cycles += 2;
nmi_pc = 0x9C43;
nmi_poll("b6_entry_9C42");
;
cycles += 2;
nmi_pc = 0x9C44;
nmi_poll("b6_entry_9C42");
;
cycles += 2;
nmi_pc = 0x9C45;
nmi_poll("b6_entry_9C42");
A = 0x05; setZN(A);
cycles += 2;
nmi_pc = 0x9C47;
nmi_poll("b6_entry_9C42");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C49;
nmi_poll("b6_entry_9C42");
b6_entry_9C49();
return;
}
static void __attribute__((used)) b6_entry_9C49(void) {
nmi_pc = 0x9C49;
nmi_poll("b6_entry_9C49");
;
cycles += 2;
nmi_pc = 0x9C4A;
nmi_poll("b6_entry_9C49");
;
cycles += 2;
nmi_pc = 0x9C4B;
nmi_poll("b6_entry_9C49");
;
cycles += 2;
nmi_pc = 0x9C4C;
nmi_poll("b6_entry_9C49");
A = 0x06; setZN(A);
cycles += 2;
nmi_pc = 0x9C4E;
nmi_poll("b6_entry_9C49");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C50;
nmi_poll("b6_entry_9C49");
b6_entry_9C50();
return;
}
static void __attribute__((used)) b6_entry_9C50(void) {
nmi_pc = 0x9C50;
nmi_poll("b6_entry_9C50");
;
cycles += 2;
nmi_pc = 0x9C51;
nmi_poll("b6_entry_9C50");
;
cycles += 2;
nmi_pc = 0x9C52;
nmi_poll("b6_entry_9C50");
;
cycles += 2;
nmi_pc = 0x9C53;
nmi_poll("b6_entry_9C50");
A = 0x07; setZN(A);
cycles += 2;
nmi_pc = 0x9C55;
nmi_poll("b6_entry_9C50");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C57;
nmi_poll("b6_entry_9C50");
b6_entry_9C57();
return;
}
static void __attribute__((used)) b6_entry_9C57(void) {
nmi_pc = 0x9C57;
nmi_poll("b6_entry_9C57");
;
cycles += 2;
nmi_pc = 0x9C58;
nmi_poll("b6_entry_9C57");
;
cycles += 2;
nmi_pc = 0x9C59;
nmi_poll("b6_entry_9C57");
;
cycles += 2;
nmi_pc = 0x9C5A;
nmi_poll("b6_entry_9C57");
A = 0x08; setZN(A);
cycles += 2;
nmi_pc = 0x9C5C;
nmi_poll("b6_entry_9C57");
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
nmi_pc = 0x9C5E;
nmi_poll("b6_entry_9C57");
b6_entry_9C5B();
return;
}
static void __attribute__((used)) b6_entry_9C5B(void) {
nmi_pc = 0x9C5B;
nmi_poll("b6_entry_9C5B");
WR(0x50, A);
cycles += 3;
nmi_pc = 0x9C5D;
nmi_poll("b6_entry_9C5B");
A = 0x35; setZN(A);
cycles += 2;
nmi_pc = 0x9C5F;
nmi_poll("b6_entry_9C5B");
WR(0x46, A);
cycles += 3;
nmi_pc = 0x9C61;
nmi_poll("b6_entry_9C5B");
A = 0xFF; setZN(A);
cycles += 2;
nmi_pc = 0x9C63;
nmi_poll("b6_entry_9C5B");
WR(0x51, A);
cycles += 3;
nmi_pc = 0x9C65;
nmi_poll("b6_entry_9C5B");
nmi_poll("b6_entry_9C5B");
cycles += 3;
b7_entry_D2B9(); return;
nmi_pc = 0x9C68;
nmi_poll("b6_entry_9C5B");
}
static void b6_x(void) { __builtin_trap(); }
