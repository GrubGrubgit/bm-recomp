# Manual vec007A entry: bank4 903E

## Why manual
903E-9059 decodes as .byte in disasm prg4.s (gap between entry_9014
and entry_9060). Same family as prior gap lifts.

## ROM decode (bank4 file offset 0x103E, 28 bytes)
903E: LDA40 STA42 / LDA40 STA43 / DEC51 / BNE 9060 /
INC46 / LDA04 STA51 / LDA20 STA50 / LDA00 STA53 /
LDX47 / LDA 906B,X STA47 / RTS.
BNE tails to pre-existing entry_9060 (LDA10 STA40... JMP 8ECE).
LDA 906B,X reads the data table at 906B (C0 00 40 80...).

## Snip fixes
1. Labels at col 0 (none interior; BNE targets pre-existing
entry_9060). ENTRY list includes entry_9060 with rts stub so the
branch resolves; splice discards the dup (same pattern as B792
to B7BD). No bank rewrites (8E95 not referenced; C114/C216 not
referenced; 9060 same-bank b4).

## Hardware legitimacy
Native probe (9014 tree) on Mesen movie-area13 inputs trapped
vec007A default at probe-frame 19450: vec=903E swbank=prg[4],
A=3E X=3B Y=00 S=FB P=24. Mesen executes the ROM bytes there.

## Cases
vec007A bank4 guarded case for observed 903E only. No twins
(9011 JMP + 903B JMP + 906B table unobserved).

## Regen recipe
1. python3 lift.py manual_903E/903e.snip OUT b4
   entry_903E,entry_9060 x ADDRMAP/PROV/JMPTAB UNWIND off/enforce.
   Reference outputs here (differ only in JSR unwind wraps;
   there are no JSRs, so OFF==ENF expected except header).
2. python3 wp_wp903e.py splices decl+body into gen bank4
   off/enf, combined off/enf plus ADDRMAP/PROV_ALL/vec007A.
