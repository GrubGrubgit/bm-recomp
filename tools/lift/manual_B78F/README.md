# Manual vec007A entry: bank4 B78F

## Why manual
B78F-B791 decodes as .byte in disasm prg4.s (gap between entry_B785
and entry_B792). Same family as prior gap lifts.

## ROM decode (bank4 file offset 0x378F, 3 bytes)
B78F: JMP B7BD (pre-existing entry). Trivial trampoline stub.

## Hardware legitimacy
Native probe trapped vec007A default at probe-frame 17788:
vec=B78F swbank=prg[4], A=40 X=8F Y=00 S=FB P=24.
Mesen executes the ROM bytes there.

## Cases
vec007A bank4 case for observed B78F only, guarded
swbank==prg[4].

## Regen recipe
1. python3 lift.py manual_B78F/b78f.snip OUT b4
   entry_B78F,entry_B7BD x, UNWIND off/enforce as usual.
   The snip defines entry_B78F plus an rts-only entry_B7BD stub
(entries must be snip-defined; splice discards the dup).
   Reference outputs here (off equals enf, no JSR).
   Splice takes only the 1 body (wp_wpb78f.py does this).
2. python3 wp_wpb78f.py splices decl plus body into gen bank4
   off plus enf, combined off plus enf (both decl blocks plus
   guarded case), plus ADDRMAP and PROV_ALL (1 entry) and
   vec007A (B78F between B785 and B792).
