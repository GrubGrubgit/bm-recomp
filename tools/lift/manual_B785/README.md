# Manual vec007A entry: bank4 B785

## Why manual
B785-B78E decodes as .byte in disasm prg4.s (gap between the LB77E
table region and entry_B7BD).
Same family as 9F5D/A74B/A9CE/A194/9C49/98AB: da65 drops the gap labels.

## ROM decode (bank4 file offset 0x3785, 10 bytes)
B785: LDA 0B / JSR B2B4 / LDA 00 / STA 50 / RTS.
Straight-line helper, no branches, no tables. JSR B2B4 is same-bank
direct (entry_B2B4 pre-exists, 6cy like all lifted direct calls).
Neighbors: B78F is JMP B7BD, B792 starts another small function
(LDA80 STA42 ...); both left for future traps.

## Hardware legitimacy
Native probe on Mesen movie-area13 inputs trapped vec007A default
at probe-frame 17038: vec=B785 swbank=prg[4], regs A=85 X=82 Y=00
S=FB P=A4 (same A/X/P as the 9885 trap, same caller chain suspected).
Mesen executes the ROM bytes there; region is live game code.

## Cases
vec007A bank4 case for observed B785, guarded swbank==prg[4].
Guarded (not like the older unguarded bank4 cases) per the B102
fork10 precedent: all recent bank4 ports use the guarded form in
the combined dispatcher. bank7t dispatcher untouched (B102 precedent:
it carries only the old unguarded bank4 cases).

## Regen recipe
1. python3 lift.py manual_B785/b785.snip OUT b4 entry_B785 x
   ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
   UNWIND:off (and UNWIND:enforce for enf). Reference outputs kept
   here as out_off.c/out_enf.c (differ only in the JSR unwind wrap).
   Splice takes only the 1 body (wp_wpb785.py does this).
2. python3 wp_wpb785.py splices decl plus body into gen bank4
   off plus enf, combined off plus enf (decls in both decl blocks
   plus guarded case; note combined off and enf order the vec tail
   differently so the case anchor is per-file), plus ADDRMAP and
   PROV_ALL (1 entry) and vec007A (B785 at end of bank4 line).
