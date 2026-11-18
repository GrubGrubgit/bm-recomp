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
nmi_poll("b6_entry_9C1F");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x00; setZN(A);
cycles += 2;
if (((P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C26();
return;
}
static void __attribute__((used)) b6_entry_9C26(void) {
nmi_poll("b6_entry_9C26");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x01; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C2D();
return;
}
static void __attribute__((used)) b6_entry_9C2D(void) {
nmi_poll("b6_entry_9C2D");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x02; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C34();
return;
}
static void __attribute__((used)) b6_entry_9C34(void) {
nmi_poll("b6_entry_9C34");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x03; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C3B();
return;
}
static void __attribute__((used)) b6_entry_9C3B(void) {
nmi_poll("b6_entry_9C3B");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x04; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C42();
return;
}
static void __attribute__((used)) b6_entry_9C42(void) {
nmi_poll("b6_entry_9C42");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x05; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C49();
return;
}
static void __attribute__((used)) b6_entry_9C49(void) {
nmi_poll("b6_entry_9C49");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x06; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C50();
return;
}
static void __attribute__((used)) b6_entry_9C50(void) {
nmi_poll("b6_entry_9C50");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x07; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C57();
return;
}
static void __attribute__((used)) b6_entry_9C57(void) {
nmi_poll("b6_entry_9C57");
cycles += 2;
;
cycles += 2;
;
cycles += 2;
;
cycles += 2;
A = 0x08; setZN(A);
cycles += 2;
if ((!(P & 0x02))) { cycles += 1; b6_entry_9C5B(); return; }
b6_entry_9C5B();
return;
}
static void __attribute__((used)) b6_entry_9C5B(void) {
nmi_poll("b6_entry_9C5B");
cycles += 3;
WR(0x50, A);
cycles += 2;
A = 0x35; setZN(A);
cycles += 3;
WR(0x46, A);
cycles += 2;
A = 0xFF; setZN(A);
cycles += 3;
WR(0x51, A);
nmi_poll("b6_entry_9C5B");
cycles += 3;
b7_entry_D2B9(); return;
}
static void b6_x(void) { __builtin_trap(); }
