# Manual vec007A entry: bank6 98A3/98A5/98A7/98AB/98F5

## Why manual
98A3-98C0 decodes as .byte in disasm prg6.s (gap between lifted
entry_9885 region and entry_9916).
Same family as 9F5D/A74B/A9CE/A194/9C49: da65 drops the gap labels.

## ROM decode (bank6 file offset 0x18A3)
98A3: BEQ +0 stub -> 98A5: BPL +0 stub ->
98A7: BEQ 98F5 / ORA 99,X -> 98AB: LDA 80 STA42 / LDA 80 STA43 /
DEC51 BNE 98BD / JSR D790 / JMP 9B95.
98BD block: LDA52 BEQ 9916 / LDX50 LDA0400,X / BNE 98CC path /
0403,X SEC SBC49 ASL A with BEQ/BMI +2/-2/JSR-EB14 three-way
-> STA4C -> 98F0: LDX50 LDA0405,X ->
98F5 block: SEC SBC4B ASL A with BEQ/BMI +2/-2/JSR-EB14 three-way
-> STA4D -> JMP 9916 (pre-existing RTS).
9B95 (JMP target): NOPx3 / LDA 00 STA4F / LDA 0A STA51 /
LDA 4B STA46 / LDA 28 JSR DECC / RTS -- ALREADY lifted as
b6_L9B95 (3 NOPs) falling into b6_entry_9B98 (the rest); the snip
keeps entry_9B95 only so the JMP resolves, splice discards it and
rewrites the call to b6_L9B95 (same pattern as 9C49 to b6_L9C5B).

## Snip fix (vs first lift)
First lift had 98A7 BEQ to L-label L98F5 living inside the 98AB
function, which is a C cross-function goto and does not compile.
Fixed in snip: L98F5 promoted to entry_98F5 (fall-through from
98F0 becomes a tail call, 98A7 BEQ becomes call plus return).
All other gotos verified intra-function by grep.

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 15962: vec=98AB swbank=prg[6]. Mesen executes the
ROM bytes there; region is live game code.

## Cases
vec007A bank6 case for observed 98AB only, guarded
swbank==prg[6] else trap. Entries 98A3/98A5/98A7 get entries
(BEQ/BPL-fallthrough stubs chaining into 98AB/98F5)
but no vec cases; 98F5 is a branch and fall-through target only.
They get cases if a future trap names them.

## Regen recipe
1. python3 lift.py manual_98AB/b98ab.snip OUT b6
   entry_98A3,entry_98A5,entry_98A7,entry_98AB,entry_98F5,
   entry_9916,entry_9B95 x
   ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). Reference outputs kept
   here as out_off.c/out_enf.c (differ only in JSR unwind wraps).
   The lift emits duplicate entry_9916 (RTS) and entry_9B95 tails;
   at splice both are discarded (9916 and 9B95 pre-exist as
   b6_entry_9916 and b6_L9B95 plus b6_entry_9B98) and the 98AB JMP
   call is repointed to b6_L9B95. Splice takes only the 5 bodies
   (wp_wp98AB.py does this).
2. python3 wp_wp98AB.py splices decls plus bodies into gen bank6
   off plus enf, bank7t off plus enf (decl plus single 98AB case),
   combined off plus enf (both), plus ADDRMAP and PROV_ALL
   (5 entries) and vec007A (98AB only).
