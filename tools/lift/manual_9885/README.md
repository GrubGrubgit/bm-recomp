# Manual vec007A entry: bank6 9885

## Why manual
9885-98A2 decodes as .byte in disasm prg6.s (gap between lifted
entry_983E and entry_9916).
Same family as 9F5D/A74B/A9CE/A194/9C49: da65 drops the gap.

## ROM decode (bank6 file offset 0x1885, clean standalone function)
9885: JSR D790 / JSR 9707 / LDA 98A4,X STA 4C / LDA 98A3,X STA 4D /
  INC 46 / LDA C0 STA 51 STA 52 / LDA 2F JSR DECC / RTS.
Tables 98A4/98A3 read numerically with page-cross cycles.
No internal branches; no fall-through; no twins observed.

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 15961 (wall 15974): vec=9885 swbank=prg[6].
Mesen executes the ROM bytes there; region is live game code.
Post-fix probe locks vs Mesen through the trap region (dtw32).

## Cases
vec007A bank6 case for observed 9885 only, guarded
swbank==prg[6] else trap. Neighbors 98A3-98A6 (BEQ+0/BPL+0)
treated as padding; they get entries if a future trap names them.

## Regen recipe
1. python3 lift.py manual_9885/e9885.snip OUT b6 entry_9885 x
   ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). Reference outputs kept
   here as out_off.c/out_enf.c (differ only in JSR unwind wraps).
2. python3 wp_wp9885.py splices decl+body into gen bank6 off+enf,
   decl+case into gen bank7t off+enf and combined off+enf, and
   updates ADDRMAP/PROV_ALL/vec007A. Combined diff is pure-add.
3. gcc -O0 -Wall -Wextra -c both combined files: clean;
   builtin_trap count +1 per combined/bank7t file (guarded else).
4. Future whole-bank bank6 regens from prg6.s will DROP this body
(gap still .byte in disasm); re-apply step 2 after any such regen.
