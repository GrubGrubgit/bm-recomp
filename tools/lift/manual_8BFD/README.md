# Manual vec007A entry: bank4 8BFD (TAS trap port-ff ~53861)

## Why manual
After the 92AC slice, the TAS-allbosses port trapped vec007A-unmapped
at v=8BFD (same b7_LC987 dispatch chain, direct dispatch).

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
8BFD is the JMP half of the L8BF9 data table tail: the table read by
the 8BEF routine is L8BF9 indexed 0-6 (10 18 20 18 4C 16 8C); bytes
8BFD-8BFF (4C 16 8C) decode as JMP 8C16, and the game dispatches
there directly - an overlap trampoline like 923C/92AC. The 8BEF
routine and its table reads are untouched (pre-existing 8BE5-body).

## Lift
lift.py 8bfd.snip OUT b4 entry_8BFD stub(entry_8C16) with ADDRMAP PROV
JMPTAB, UNWIND off (enforce for enf). The stub mechanism resolves the
same-bank jmp edge to the pre-existing b4_entry_8C16 body with no
transcription (cf. A07B/9EB3 stubs in the A58C slice): spliced body is
the 6-line trampoline poll/poll/cycles-3/tail-call. The lift-emitted
8C16 trap-stub decl+def are dropped by the WANT extractor (same as
prior stub slices). WANT=[b4_entry_8BFD] only. No pre-existing 8BFD
under any name.

## Cases
vec007A bank4 guarded case for 8BFD only.

## Regen recipe
1. lift.py as above (stub slot carries entry_8C16; specs from argv 6).
2. wp_wp8BFD.py splices decl, body, case into gen combined off/enf
(anchored on the 92AC batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
