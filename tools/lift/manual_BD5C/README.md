# Manual vec007A entry: bank4 spitter (BD5C/BD5F/BD69/BD6C)

## Why manual
Port trapped vec007A-unmapped v=BD5F swbank=4 at TAS-allbosses
game-time 5552 (port ff~5544): overhead object slot 9 type $41.
Bank4 dispatch table entry ObjType $41 sits at $8086 = L_BD5C;
LC9AE $15==0 path adds +3 to BD5F. Neither was ever observed by the
edge/St tracers, so vec007A.txt had no case and the lift never seeded
them. Same coverage-gap family as 9072/903E/9014 (trap-driven).

## ROM decode (bank4, 61 bytes BD5C-BD9C; disasm gap after entry_BD4A)
BD5C: JMP BD68 ; thunk (direct-vec path)
BD5F: LDA 00 STA52 / LDA 0D JSR B2B4 ; init (+3 path)
BD68: RTS
BD69: JMP BD9D ; $42 direct (skips main)
BD6C: LDA 80 STA42/43 / LDA52 BEQ / DEC52 / JSR C045 / BPL / EOR FF
CLC ADC 01 / STA00 / JSR C04E / BPL / EOR FF CLC ADC 01 / CMP00 BCS /
LDA00 / CMP 02 BCS BD9D / JSR BE3E ; $42 main (+3 path). Falls through
BD9C to BD9D at zero cycles. Callees pre-exist: B2B4/BD9D/BE3E same-bank
entries; C045/C04E are bank7 JMP-stub trampolines (b7_LC045 to E0ED,
b7_LC04E to Y-delta). No bank7 additions needed.

## Snip fixes (vs naive transcription)
1. Same-bank external entries (B2B4/BD9D/BE3E) passed as lift argv5
stub set; ENTRY would demand bodies in-snip.
2. BD5C jmp LBD68 targets BDFs region: lift emits an illegal
cross-function goto. wp inlines the RTS (JMP3 kept, plus RTS6).
3. LC045/LC04E lift as b4_LCxxxx (current-bank default); wp rewrites
to b7_LC045/b7_LC04E (incl. enf UNWIND log strings).
4. BD6C ends by ROM fall-through into BD9D (0cy). Snip spells an
explicit jmp entry_BD9D so lift terminates the region; wp strips
the phantom JMP3 plus dup polls (nmi_poll idempotent; BE3E epilogue
and BD9D head polls stand). Net: BE3E call, BD9D call, return, at
zero added cycles, matching the auto-fallthrough convention.
5. Dead b4_LBD68 label left in BD5F removed post-splice, keeps the
gcc -Wall -Wextra gate clean.

## Hardware legitimacy
Native and wasm port trapped vec007A default at probe-frame 5544 with
vec=BD5F swbank=prg4; Mesen executes the ROM bytes there (overhead
spitter init). All bytes verified against ROM bank4 BD5C-BD9C; the +3
arithmetic matches LC9AE (BD5C+3=BD5F, BD69+3=BD6C).

## Cases
vec007A bank4 guarded cases for BD5C/BD5F/BD69/BD6C. No BD68 case:
it is never a vector value (direct path vectors BD5C, +3 path BD5F).

## Regen recipe
1. lift.py spitter.snip OUT b4 entries(4) stubs(B2B4,BD9D,BE3E)
x ADDRMAP PROV JMPTAB UNWIND off (enforce for enf). Reference
outputs here (out_off.c/out_enf.c) differ ONLY in JSR unwind wraps.
2. wp_wpBD5C.py splices decls, bodies, cases into gen combined
off/enf (bodies before b4_entry_B7BD; cases after 9072); ADDRMAP
(BD5C/BD5F/BD69/BD6C bank4); PROV_ALL; vec007A bank4 line.
