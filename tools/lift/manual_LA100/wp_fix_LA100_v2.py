import pathlib
B = pathlib.Path('/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe')
GEN = B / 'recomp/gen'
NL = chr(10)
OFF = GEN / 'combined_off.c'
s = OFF.read_text()
# v2: stranded-resume guard. v1 bodies (EXIT / continue) both wrong:
# EXIT skipped a tail HW runs (+2 via double-consumed entry slot);
# continue re-ran it (spare tail, same +2). Stranded resume (the LC987
# whose C9A4 was unwound) must skip BOTH S+=2 (slot already balanced
# via the LA100 tail RTS-pop) and the tail (already ran via check-1).
# Normal later LC987s (fresh ids) run S+=2 + tail as usual.
# (1) decls: per-call sequence + stranded-id stack (4-deep, multi-unwind safe)
old = 'int uw_LA100;'
assert s.count(old) == 1 and 'uw_seq' not in s
s = s.replace(old, old + NL + 'int uw_seq=0; int uw_sid[4]; int uw_sidd=0;')
print('decl v2 ok')
# (2) LA100 tail: record stranded id (youngest LC987 at unwind time)
old = 'S = (uint8_t)(S + 2);' + NL + 'uw_LA100++;'
assert s.count(old) == 1, ('LA100 tail', s.count(old))
s = s.replace(old, 'S = (uint8_t)(S + 2);' + NL + 'uw_LA100++; if (uw_sidd<4) uw_sid[uw_sidd++]=uw_seq;')
print('LA100 tail v2 ok')
# (3) LC987 entry: per-call sequence id
old = 'static void __attribute__((used)) b7_LC987(void) {' + NL + 'nmi_pc = 0xC987;'
assert s.count(old) == 1, ('LC987 entry', s.count(old))
s = s.replace(old, 'static void __attribute__((used)) b7_LC987(void) {' + NL + 'int my_lc987 = ++uw_seq;' + NL + 'nmi_pc = 0xC987;')
print('LC987 entry v2 ok')
# (4) LC987 resume: stranded (id recorded) -> consume + return (skip S+=2 and tail);
#     normal -> S+=2 + tail. S+=2 MUST follow the guard.
cands = (
  'S = (uint8_t)(S + 2);' + NL + 'if (uw_LA100) { uw_LA100--; b7_LC990_EXIT(); return; }',
  'S = (uint8_t)(S + 2);' + NL + 'if (uw_LA100) { uw_LA100--; b7_LC987_after_C9A4(); return; }',
)
old = next((c for c in cands if s.count(c) == 1), None)
assert old is not None, 'LC987 check v1'
new = ('if (uw_LA100) { int uw_hit=-1; for (int uw_k=0; uw_k<uw_sidd; uw_k++) { if (uw_sid[uw_k]==my_lc987) uw_hit=uw_k; }' + NL + 'if (uw_hit>=0) { uw_sid[uw_hit]=uw_sid[--uw_sidd]; uw_LA100--; return; } }' + NL + 'S = (uint8_t)(S + 2);')
s = s.replace(old, new)
print('LC987 check v2 ok')
OFF.write_text(s)
print('LA100 fix v2 spliced (OFF only)')
