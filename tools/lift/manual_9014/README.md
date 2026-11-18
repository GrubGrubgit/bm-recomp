# Manual vec007A entry: bank4 9014

## Why manual
9014-903A decodes as .byte in disasm prg4.s (gap between entry_9007
and entry_9060). Same family as prior gap lifts.

## ROM decode (bank4 file offset 0x1014, 39 bytes)
9014: LDA57 / CMP01 / BNE L901F / LDA06 STA46 / RTS /
L901F: CMP05 / BCC L9026 / JMP C114 /
L9026: JSR 8E95 / LDA00 STA4C STA4D / LDA03 STA51 / INC46 /
LDA1B / JSR C216 / RTS (at 903A).
Neighbors: 9011 is JMP 903A (no-op twin, not observed, left for
later); 903B is JMP 9060; 903E starts another gap function
(LDA40..., not observed). Only observed 9014 lifted.
JSR/JMP targets 8E95 (bank4, same-bank direct) + C114/C216
(fixed-bank JMP trampolines, 3cy each; JSR6+trampoline=9 total).

## Snip fixes
1. Labels at col 0 (L901F/L9026); lifter computes page-cross
(all same 90 page, plus 0).
2. JMP C114 lifts to tail call (b7_entry_C114); JSR 8E95 stays
bank4 (b4_entry_8E95); JSR C216 lifts to b7 (rewritten from b4
by splice, checked pre-existing).
3. Single body, no dup entry, no fall-through (ends RTS).

## Hardware legitimacy
Native probe (B792-fixed tree) on Mesen movie-area13 inputs
trapped vec007A default at probe-frame 19437: vec=9014
swbank=prg[4], A=14 X=11 Y=00 S=FB P=24. Mesen executes the
ROM bytes there.

## Cases
vec007A bank4 guarded case for observed 9014 only. No twins
(9011 JMP-to-RTS + 903B JMP + 903E gap fn unobserved).

## Regen recipe
1. python3 lift.py manual_9014/9014.snip OUT b4 entry_9014 x
   ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (enforce for enf). Reference outputs here.
2. python3 wp_wp9014.py splices decl+body into gen bank4
   off/enf, combined off/enf (decls in both decl blocks +
   guarded case), plus ADDRMAP/PROV_ALL/vec007A.
