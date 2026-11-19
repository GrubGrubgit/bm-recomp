# Manual vec007A entry: bank4 923C (TAS trap port-ff ~10163)

## Why manual
After the 9FEE slice, the TAS-allbosses port trapped vec007A-unmapped
at v=923C (same b7_LC987 dispatch chain, direct dispatch).

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
923C is JMP 926E (4C 6E 92) hiding inside the L9238 data table: the
table bytes the 920E routine reads as data are only 9237-923B
(E0 / 00 20 00 E0, X-indexed 0-3); bytes 923C-923E decode as
JMP 926E and the game genuinely dispatches there - a trampoline
into the shared 926E tail. Disassembler groups 923C-923E with the
table .byte run; execution evidence (the trap) proves code. The 9236
RTS and 9237-923B table bytes are untouched (data, X-indexed reads
by the pre-existing 920E body).

## Lift
lift.py 923c.snip OUT b4 entries(entry_923C,entry_926E) with ADDRMAP
PROV JMPTAB, UNWIND off (enforce for enf). Same-bank jmp requires
the target in the ENTRIES list (lift asserts otherwise), so the 926E
body is transcribed as scaffolding and re-emitted in the lift output
but NOT spliced: gen already holds the older-lift b4_entry_926E body
(outlined-tail shape with b4_L927E call, versus current-lift inline
gotos - same callees, same cycle counts; the old body stands,
validated by all runs since the 9267 slice). Spliced body is the
6-line trampoline: poll, poll, cycles 3, b4_entry_926E tail call.
WANT=[b4_entry_923C] only. No pre-existing 923C under any name.

## Cases
vec007A bank4 guarded case for 923C only (no 926E case: the observed
dispatch value is 923C).

## Regen recipe
1. lift.py as above (stub slot explicit empty string).
2. wp_wp923C.py splices decl, body, case into gen combined off/enf
(anchored on the 9FEE batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
