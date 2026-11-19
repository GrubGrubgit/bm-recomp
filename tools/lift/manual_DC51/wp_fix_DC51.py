import pathlib
B = pathlib.Path('/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe')
GEN = B / 'recomp/gen'
NL = chr(10)
Q = chr(34)
BUGGY = ('{ uint8_t _m = RD(0x05); A = (uint8_t)(A ^ _m); setZN(A); }' + NL + 'cycles += 3;' + NL + 'nmi_poll(' + Q + 'b7_entry_DC51' + Q + ');' + NL + 'cycles += 3;' + NL + 'nmi_poll(' + Q + 'b7_entry_DC51' + Q + ');' + NL + '{ uint8_t _m = 0x02; A = (uint8_t)(A & _m); setZN(A); }')
FIXED = ('{ uint8_t _m = RD(0x05); A = (uint8_t)(A ^ _m); setZN(A); }' + NL + 'cycles += 3;' + NL + 'nmi_poll(' + Q + 'b7_entry_DC51' + Q + ');' + NL + '{ uint8_t _m = 0x02; A = (uint8_t)(A & _m); setZN(A); }')
for genf in ('combined_off.c', 'combined_enf.c'):
    p = GEN / genf
    src = p.read_text()
    n = src.count(BUGGY)
    assert n == 1, (genf, n)
    src = src.replace(BUGGY, FIXED)
    p.write_text(src)
    print('fixed', genf)
