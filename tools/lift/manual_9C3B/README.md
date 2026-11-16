# vec007A entries: bank4 9C3B (user trap val 39995) + bank4 A74E (val 42830)
9C3B is the LDA $9D73,X instruction inside the L9C23 sprite-byte copy tail
(sta 06 / lda 4F / ora 03FD / ora 15 / bne L9C63 / asl-a x3 / and 01 / tax /
LDA 9D6F,X ...); instruction-aligned, so the normal seed -> regen flow works
(unlike 9F5D which needed a hand snip). A74E was already lifted (ADDRMAP had
it) but missing its dispatcher case.
Disasm: tools/rebuild.sh bank4 E-seeds += 9C3B; ROM-PARITY-OK; entry_9C3B lands
at lda L9D73,x exactly.
Lift (wp32.py + wp32b.py in this dir, assert-everything):
- vec007A.txt bank4 line: 9C3B between 9B67/9E06, A74E between 9FBA/AFBC.
- ADDRMAP += 9C3B 4 entry_9C3B; PROV += entry_9C3B 4 (both confirmed by
  regen maps: zero additions beyond the manual-splice set).
- gen_bank pass1 bank4 off+enf (80C9-80DE EXCL kept; 80C9/9F5D/b4a stay
  manual splices). Regen splits b4_L9C23 at 9C3B (call + new function).
- gen/bank4_off.c + gen/bank4_enf.c: committed + 9C3B decl + L9C23 split.
- gen/combined_off.c + gen/combined_enf.c: same + 2 vec cases (9C3B, A74E)
  + 2 bank7t-block fwd decls (9BAA precedent: bank7t TU left stale).
- gcc -O0 -Wall -Wextra clean on both combined; traps 7+default unchanged.
LIFTER NOTE (lift.py dead-gap rule, same commit): 2e20bac made unhandled
gap bytes fatal, which broke bank7t regen (C00C-class JMP-table tails after
terminal jmp). lift.py now skips gap bytes after jmp/rts/rti (unreachable,
old-lifter behavior) and still fails loud elsewhere. make test: same 8
pre-existing input-fixture failures before and after.
