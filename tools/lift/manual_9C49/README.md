# Manual vec007A entries: bank6 ladder rungs 9C26-9C57

## Why manual
9C26-9C57 decode as .byte in disasm prg6.s (gap between lifted
entry_9C1F and entry_9C68; 9C1F already lifted and executes the whole
ladder inline, tail L9C5B already lifted).
Same family as 9F5D/A74B/A9CE/A194: da65 drops the gap labels.

## ROM decode (bank6 file offset 0x1C26, computed dispatch ladder)
Nine identical 7-byte rungs: [EA EA EA] LDA #imm BEQ/BNE $9C5B.
Rung bases: 9C1F(00) 9C26(01) 9C2D(02) 9C34(03) 9C3B(04) 9C42(05)
9C49(06) 9C50(07) 9C57(08). Every rung branch target lands on 9C5B.
Tail 9C5B: STA 50 / LDA 35 STA 46 / LDA FF STA 51 / JMP D2B9.
The game vectors directly into mid-ladder rungs (computed base+7k,
same class as the A74B base+3 alternate: 0 static refs expected).

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 14734 (wall 14743): vec=9C49 swbank=prg[6] (rung 6).
Mesen executes the ROM bytes there; region is live game code.
Post-fix probe locks vs Mesen through the trap region (dtw32).

## Cases
vec007A bank6 cases for all 8 mid-ladder rungs 9C26-9C57
(computed family: every rung is a structural twin of observed 9C49),
all guarded swbank==prg[6] else trap. Rung 0 (9C1F) case pre-exists.
Tail 9C5B reuses existing b6_L9C5B (no new entry; gets one if a
future trap names it as a vector).

## Regen recipe
1. python3 lift.py manual_9C49/ladder.snip OUT b6
   entry_9C1F,entry_9C26,entry_9C2D,entry_9C34,entry_9C3B,
   entry_9C42,entry_9C49,entry_9C50,entry_9C57,entry_9C5B x
   ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). OFF and ENF outputs are
   identical (no JSR in rungs). Reference outputs kept here.
   The lift emits a duplicate entry_9C5B tail; at splice it is
   discarded and rung calls repoint to the existing b6_L9C5B.
   Splice takes only the 8 rung bodies (wp_wp9c49.py does this).
2. python3 wp_wp9c49.py splices decls+bodies into gen bank6 off+enf,
   decls+cases into gen bank7t off+enf and combined off+enf, and
   updates ADDRMAP/PROV_ALL/vec007A. Combined diff is pure-add.
3. gcc -O0 -Wall -Wextra -c both combined files: clean;
   builtin_trap count +8 per combined/bank7t file (guarded elses).
4. Future whole-bank bank6 regens from prg6.s will DROP these bodies
(gap still .byte in disasm); re-apply step 2 after any such regen.
