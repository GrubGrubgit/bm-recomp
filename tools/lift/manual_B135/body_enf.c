static void __attribute__((used)) b4_entry_B135(void) {
nmi_poll("b4_entry_B135");
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x42, A);
cycles += 2;
A = 0x40; setZN(A);
cycles += 3;
WR(0x43, A);
nmi_poll("b4_entry_B135");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C01E(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b7_entry_C01E", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
nmi_poll("b4_entry_B135");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b7_entry_C138(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b7_entry_C138", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
cycles += 2;
if ((!(P & 0x80))) { cycles += 1; b4_entry_B14B(); return; }
nmi_poll("b4_entry_B135");
cycles += 6;
S = (uint8_t)(S - 2);
{ uint8_t _uw_s = S; b4_entry_9333(); if (S != _uw_s && !uw_abort) { uw_abort = 1; fprintf(stderr, "UNWIND-ESCAPE caller=%s callee=%s S=%02X want=%02X\n", "b4_entry_B135", "b4_entry_9333", S, _uw_s); } if (uw_abort) return; }
S = (uint8_t)(S + 2);
nmi_poll("b4_entry_B135");
nmi_poll("b4_entry_B135");
cycles += 3;
b7_entry_C114(); return;
}
