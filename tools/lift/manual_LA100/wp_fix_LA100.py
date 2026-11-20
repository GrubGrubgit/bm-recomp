import pathlib
B = pathlib.Path('/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe')
GEN = B / 'recomp/gen'
NL = chr(10)
Q = chr(34)
OFF = GEN / 'combined_off.c'
# --- region helpers (quote-free anchors, function-local) ---
def region(s, fn):
    i = s.find(fn + '(void) {')
    assert i > 0, fn
    return i
s = OFF.read_text()
# (1) decl (fork9 pattern: after uw_9434)
old = 'int uw_9434;'
assert s.count(old) == 1
s = s.replace(old, old + NL + 'int uw_LA100;')
# (2) prototypes
old = 'static void b7_LC990(void);'
assert s.count(old) == 1
s = s.replace(old, old + NL + 'static void b7_LC987_after_C9A4(void);' + NL + 'static void b7_LC990_EXIT(void);')
# (3) LA100 tail: RTS-pop + flag, plain return (was: PLA,PLA,plain return)
old = ('b7_entry_C11A();' + NL +
'S = (uint8_t)(S + 2);' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL +
'cycles += 4;' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL +
'cycles += 4;' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'cycles += 6;' + NL +
'return;' + NL +
'}')
assert s.count(old) == 1, ('LA100 tail', s.count(old))
new = ('b7_entry_C11A();' + NL +
'S = (uint8_t)(S + 2);' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL +
'cycles += 4;' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL +
'cycles += 4;' + NL +
'nmi_poll(' + Q + 'b4_LA100' + Q + ');' + NL +
'S = (uint8_t)(S + 2);' + NL +
'uw_LA100++;' + NL +
'cycles += 6;' + NL +
'return;' + NL +
'}')
s = s.replace(old, new)
# (4) check-1 in the three A07B callers (region-limited, quote-free)
for fn in ['b4_entry_A58C', 'b4_entry_970F', 'b4_entry_9B67']:
    i = region(s, fn)
    j = s.find('b4_LA63E', i) if fn == 'b4_entry_A58C' else i + 4000
    body = s[i:j]
    old = 'b4_entry_A07B();' + NL + 'S = (uint8_t)(S + 2);'
    assert body.count(old) == 1, (fn, body.count(old))
    new = ('b4_entry_A07B();' + NL +
    'if (uw_LA100) { b7_LC987_after_C9A4(); return; }' + NL +
    'S = (uint8_t)(S + 2);')
    s = s[:i] + body.replace(old, new) + s[j:]
    print('check-1 ok', fn)
# (5) LC987: split tail into after_C9A4 + resume-check to loop exit
old = ('S = (uint8_t)(S - 2);' + NL +
'b7_entry_C9A4();' + NL +
'S = (uint8_t)(S + 2);' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'cycles += 6;' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'S = (uint8_t)(S - 2);' + NL +
'b7_LC928();')
assert s.count(old) == 1, ('LC987 split', s.count(old))
new = ('S = (uint8_t)(S - 2);' + NL +
'b7_entry_C9A4();' + NL +
'S = (uint8_t)(S + 2);' + NL +
'if (uw_LA100) { uw_LA100--; b7_LC990_EXIT(); return; }' + NL +
'b7_LC987_after_C9A4();' + NL +
'return;' + NL +
'}' + NL +
'static void __attribute__((used)) b7_LC987_after_C9A4(void) {' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'cycles += 6;' + NL +
'nmi_poll(' + Q + 'b7_LC987' + Q + ');' + NL +
'S = (uint8_t)(S - 2);' + NL +
'b7_LC928();')
s = s.replace(old, new)
print('LC987 split ok')
# (6) LC990: split loop-exit into LC990_EXIT
old = ('nmi_poll(' + Q + 'b7_LC990' + Q + ');' + NL +
'if ((!(P & 0x01))) { cycles += 1; b7_LC977(); return; }' + NL +
'A = 0x00; setZN(A);')
assert s.count(old) == 1, ('LC990 split', s.count(old))
new = ('nmi_poll(' + Q + 'b7_LC990' + Q + ');' + NL +
'if ((!(P & 0x01))) { cycles += 1; b7_LC977(); return; }' + NL +
'b7_LC990_EXIT();' + NL +
'return;' + NL +
'}' + NL +
'static void __attribute__((used)) b7_LC990_EXIT(void) {' + NL +
'A = 0x00; setZN(A);')
s = s.replace(old, new)
print('LC990 split ok')
OFF.write_text(s)
print('LA100 fix spliced (OFF only)')
