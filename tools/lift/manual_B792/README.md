# Manual vec007A entry: bank4 B792

## Why manual
B792-B7BB decodes as .byte in disasm prg4.s (gap between entry_B785
and entry_B7BD). Same family as prior gap lifts.

## ROM decode (bank4 file offset 0x3792, 42 bytes)
B792: LDA80 STA42 / LDA80 STA43 / LDA50 / BNE LB7B0 / JSR C04E /
BNE B7BD / INC50 / LDA00 STA4D / JSR C045 / BMI LB7B2 / LDA38 /
BNE LB7B4 / LB7B2: LDA C8 / LB7B4: STA4C / JSR C02D / BEQ B7BD /
DEC50 / fall into B7BD (pre-existing entry).
JSR targets C04E/C045/C02D are fixed-bank JMP trampolines
(b7_LC04E/C045/C02D, each 3cy). Lift emits 6cy JSR plus the
trampoline call (total 9, correct; the slotfix 9cy short-circuit
applies only to JMPTAB-listed trampolines, and C04E/C045/C02D
are not in JMPTAB).

## Snip fixes (vs naive transcription)
1. Snip labels must start at column 0 (lift.py ignores indented
labels); LB7B2/LB7B4 unindented, and LB7B0 added at B7B0 (the BNE
instruction itself is the B79C branch target).
2. Interior labels use LB7B0 form (L plus full 4-hex addr) so the
lifter computes page-cross correctly (all same B7 page, plus 0).
3. Snip ends with jmp entry_B7BD even though ROM falls through
(no JMP byte): lift-identical tail call. entry_B7BD is in the
ENTRY list with an rts stub body so branches resolve; splice
discards the dup and keeps calls to the pre-existing
b4_entry_B7BD (same pattern as 9C49 to b6_L9C5B).
4. jsr LC0xx lifts to b4_LC0xx (wrong bank letter); splice
rewrites all three to b7_LC0xx (checked pre-existing).

## Hardware legitimacy
Native probe trapped vec007A default at probe-frame 17039:
vec=B792 swbank=prg[4], A=92 X=8F Y=00 S=FB P=A4.
Mesen executes the ROM bytes there.

## Cases
vec007A bank4 case for observed B792 only, guarded
swbank==prg[4]. No twins (neighbors B78F JMP and B7BD entry
already lifted; B785 observed earlier).

## Regen recipe
1. python3 lift.py manual_B792/b792.snip OUT b4
   entry_B792,entry_B7BD x
   ADDRMAP plus PROV plus JMPTAB args as usual, UNWIND off/enforce.
   Reference outputs here (differ only in JSR unwind wraps).
   The lift emits a duplicate rts-only entry_B7BD; splice discards
   it. Splice takes only the 1 body (wp_wpb792.py does this).
2. python3 wp_wpb792.py splices decl plus body into gen bank4
   off plus enf, combined off plus enf (decls in both decl blocks
   plus guarded case; case anchor per-file as with B785), plus
   ADDRMAP and PROV_ALL (1 entry) and vec007A (B792).
