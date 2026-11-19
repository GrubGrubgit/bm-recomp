# Manual vec007A entry: bank4 92AC (TAS trap port-ff ~10423)

## Why manual
After the 923C slice, the TAS-allbosses port trapped vec007A-unmapped
at v=92AC (same b7_LC987 dispatch chain, direct dispatch).

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
92AC is JMP 92B6 (4C B6 92) sitting right after the L92A3 RTS (60 at
92AB): the second JMP-trampoline in this code region after 923C.
entry_92AF (DEC 51 at 92AF) follows immediately. No data-table
overlap here - just a 3-byte trampoline between two routines.

## Lift
lift.py 92ac.snip OUT b4 entries(entry_92AC,entry_92B6) with ADDRMAP
PROV JMPTAB, UNWIND off (enforce for enf). Same-bank jmp needs the
target in ENTRIES, so the 92B6 body is transcribed as scaffolding and
re-emitted but NOT spliced: gen already holds the older-lift
b4_entry_92B6 body (outlined-tail shape with b4_L92C6 call; the old
body stands, validated by all runs to date). Spliced body is the
6-line trampoline: poll, poll, cycles 3, b4_entry_92B6 tail call.
Data-table reads use the L931F/L9324 label form (labaddr_opt needs
the full 4-hex-digit address; LA-form would parse as 0xAxxx).
WANT=[b4_entry_92AC] only. Bank6 has an unrelated L92AC label
(ADDRMAP key is addr+bank, no clash).

## Cases
vec007A bank4 guarded case for 92AC only.

## Regen recipe
1. lift.py as above (stub slot explicit empty string).
2. wp_wp92AC.py splices decl, body, case into gen combined off/enf
(anchored on the 923C batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
