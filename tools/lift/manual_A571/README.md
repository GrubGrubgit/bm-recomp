# Manual vec007A entries: bank4 A571/A574/A589 (boss init, 3 NOPs + init)

## Why manual
After the 8B96 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=A571 (port ff~6385, same LC987 chain): dispatch entry ObjType
at $80C8 = L_A571. Direct dispatch.

## ROM decode (bytes verified vs ROM)
A571: NOP NOP NOP (3xEA), falling into A574 at zero cycles.
A574: LDA 80 STA 53 / LDA 00 STA 50 STA 51 / LDA 00 STA 4C /
LDA 08 STA 4D / INC 46 / RTS (boss HP/scratch/velocity init,
advance type). A589: RTS (twin at $80CA, direct path).
No callees at all: pure straight-line init.

## Snip fixes
None beyond the standard shape. The A571-to-A574 fall-through uses
the supported convention: consecutive entries in the ENTRIES list,
and lift emits a zero-cycle tail call (verified: bare call, no
phantom cycles). A589 rts terminates its own region.

## Cases
vec007A bank4 guarded cases for A571/A574/A589. A589 included
pre-emptively (the $80CA direct path twin); A58C (+3 main) left for
the trap loop.

## Regen recipe
1. lift.py a571.snip OUT b4 entries(A571,A574,A589) stub(x)
with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpA571.py splices decls, bodies, cases into gen combined
off/enf (anchored on the 8B96 batch); ADDRMAP, PROV_ALL, vec007A.
