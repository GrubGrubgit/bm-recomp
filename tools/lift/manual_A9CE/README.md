# Manual vec007A entries: bank6 A9CB/A9CE/A9DE/A9E1 (+LA9DD)

## Why manual
A9CB-AA02 decodes as .byte in disasm prg6.s (tail of the LA9C3 chain).
The normal info-range regen can never produce these entries.
Same family as 9F5D/A74B: da65 drops the gap labels.

## ROM decode (bank6 file offset 0x29CB, all clean boundaries)
A9CB: JMP A9DD (shared RTS).
A9CE: LDA 7 / JSR A2E9 / LDA 0 STA 4C STA 4D / LDA 1 STA 50 / RTS.
A9DE: JMP AA03 (twin of B719 pattern).
A9E1: LDA 80 STA 42 / LDA 80 STA 43 / LDA 50 BEQ A9FA / JSR E005 /
  BEQ A9F8 / LDA 0 STA 4C / BEQ AA03 / INC 50 / LDA 11 JSR D2B1 /
  BMI AA03 / DEC 50, falls into entry_AA03 (existing).

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 13269 (wall 13278): vec=A9CE swbank=prg[6].
Mesen executes the ROM bytes there; region is live game code.
Post-fix probe frames 13269-13743 lock vs Mesen walls (dtw32:
same allowed runs plus transients as pre-fix prefix, f10192 gone).

## Cases
vec007A bank6 cases added for observed A9CE plus twins A9DE/A9E1
(B719/B71C justification), all guarded swbank==prg[6] else trap.
A9CB body lifted without a case (JMP-to-RTS, unobserved;
gets a case if a future trap names it).

## Regen recipe
1. python3 lift.py manual_A9CE/a9ce.snip OUT b6
   entry_A9CB,entry_A9CE,LA9DD,entry_A9DE,entry_A9E1,entry_AA03
   x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). Reference outputs kept
   here as out_off.c/out_enf.c; regen must match apart from header.
   The trailing entry_AA03 anchor (RTS body) exists only so the A9E1
   fall-through lifts as a tail call; its body is discarded at splice.
2. python3 wp_wpa9ce.py splices decls+bodies into gen bank6 off+enf,
   decls+cases into gen bank7t off+enf and combined off+enf, and
   updates ADDRMAP/PROV_ALL/vec007A. Combined diff is pure-add.
3. gcc -O0 -Wall -Wextra -c both combined files: clean;
   builtin_trap count +3 per combined/bank7t file (guarded elses).
4. Future whole-bank bank6 regens from prg6.s will DROP these bodies
(gap still .byte in disasm); re-apply step 2 after any such regen.
