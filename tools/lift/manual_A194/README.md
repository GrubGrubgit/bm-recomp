# Manual vec007A entries: bank6 A164/A191/A194/A1AD/A1B0 (+LA190/LA1AC)

## Why manual
A164-A1CB decodes as .byte in disasm prg6.s (gap between lifted
regions; A1CC already lifted as entry_A1CC).
Same family as 9F5D/A74B/A9CE: da65 drops the gap labels.

## ROM decode (bank6 file offset 0x2164, all clean boundaries)
A164: JSR DECC / LDA 6 / JSR A2E9 / LDA 63 STA 46 / LDA 1 STA 50 /
  LDA E8 STA 4D / LDA 11 STA 4C / JSR E0ED / BPL A188 /
  LDA 0 SEC SBC 4C STA 4C / LDA 0 STA 51 STA 47 STA 52 / RTS.
A191: JMP LA1AC (shared RTS, like A9CB).
A194: JSR EB71 / AND 1F CLC ADC B0 STA 47 / LDA 40 STA 51 / LDY 20 /
  JSR E1BD / JSR D2B9 / INC 46 / RTS (falls into LA1AC).
A1AD: JMP entry_A1CC (twin of B719/A9DE pattern).
A1B0: LDA 80 STA 42 / LDA 80 STA 43 / DEC 51 BNE A1BF / JMP D81C /
  LDA 2 LDX 0 / JSR DFD1 / JSR D2DE / JSR D2FE,
  falls into entry_A1CC (existing).

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 13745 (wall 13754): vec=A194 swbank=prg[6].
Mesen executes the ROM bytes there; region is live game code.
Post-fix probe frames 13745-14399 lock vs Mesen walls (dtw32:
same allowed runs plus transients as pre-fix prefix).

## Cases
vec007A bank6 cases for observed A194 plus twins A1AD/A1B0
(B719/B71C justification), all guarded swbank==prg[6] else trap.
A164/A191 bodies lifted without cases (unobserved; A191 is JMP-to-RTS.
Each gets a case if a future trap names it).

## Regen recipe
1. python3 lift.py manual_A194/a194.snip OUT b6
   entry_A164,LA190,entry_A191,entry_A194,LA1AC,entry_A1AD,entry_A1B0,entry_A1CC
   x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). Reference outputs kept
   here as out_off.c/out_enf.c; regen must match apart from header.
   The trailing entry_A1CC anchor (RTS body) exists only so the A1B0
   fall-through lifts as a tail call; its body is discarded at splice.
2. python3 wp_wpa194.py splices decls+bodies into gen bank6 off+enf,
   decls+cases into gen bank7t off+enf and combined off+enf, and
   updates ADDRMAP/PROV_ALL/vec007A. Combined diff is pure-add.
3. gcc -O0 -Wall -Wextra -c both combined files: clean;
   builtin_trap count +3 per combined/bank7t file (guarded elses).
4. Future whole-bank bank6 regens from prg6.s will DROP these bodies
(gap still .byte in disasm); re-apply step 2 after any such regen.
