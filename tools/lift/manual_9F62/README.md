# Manual vec007A entry: bank4 9F62 (TAS trap port-ff ~7114)

## Why manual
After the A58C slice, the TAS-allbosses port trapped vec007A-unmapped
at v=9F62 (same b7_LC987 dispatch chain, direct dispatch). Single entry.

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
9F62: RTS ($60); 9F63/9F64 are $EA NOP padding before entry_9F65
(LDA $0400...). Direct RTS twin of the 9F65 dispatch entry - same
shape as the earlier A589 ($80CA) twin. No callees, no fall-through:
rts terminates its own region.

## Lift
lift.py 9f62.snip OUT b4 entry_9F62 (no stubs) with ADDRMAP PROV
JMPTAB, UNWIND off (enforce for enf). Output matches the A589 RTS
shape exactly (nmi_poll + cycles 6 + return). No pre-existing dup:
gen/ADDRMAP/PROV/vec had no 9F62 under any name.

## Cases
vec007A bank4 guarded case for 9F62 only.

## Regen recipe
1. lift.py as above (note: stub slot needs explicit '' so the
ADDRMAP:/PROV:/JMPTAB:/UNWIND: specs parse from argv[6:]).
2. wp_wp9F62.py splices decl, body, case into gen combined off/enf
(anchored on the A58C batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
