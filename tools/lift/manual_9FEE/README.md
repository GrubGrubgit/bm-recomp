# Manual vec007A entry: bank4 9FEE (TAS trap port-ff ~7355)

## Why manual
After the 9FF1 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=9FEE (same b7_LC987 dispatch chain, direct dispatch). The trap
landed one frame after the 9FF1 fix at the same site.

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
9FEE: NOP NOP NOP (3xEA), falling into 9FF1 at zero cycles - the same
shape as the earlier A571 (3 NOPs) to A574 fall-through. No pre-existing
dup under any name.

## Lift
lift.py 9fee.snip OUT b4 entries(entry_9FEE,entry_9FF1) with ADDRMAP PROV
JMPTAB, UNWIND off (enforce for enf). The 9FF1 body is re-emitted in
the lift output but NOT spliced (already in gen); the 9FEE body ends in
a zero-cycle tail call b4_entry_9FF1(), verified byte-identical re-lift of
the 9FF1 body (diff of extracted bodies: IDENTICAL), which validates the
re-transcription. WANT=[b4_entry_9FEE] only.

## Cases
vec007A bank4 guarded case for 9FEE only.

## Regen recipe
1. lift.py as above (stub slot explicit empty string; entry list is
entry_9FEE,entry_9FF1 so the fall-through has a same-list target).
2. wp_wp9FEE.py splices decl, body, case into gen combined off/enf
(anchored on the 9FF1 batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
