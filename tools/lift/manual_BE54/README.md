# Manual vec007A entry: bank4 BE54/BE57 (zombie-head init)

## Why manual
After the B08B slice, the TAS-allbosses port trapped vec007A-unmapped
at v=BE57 (port ff~5779, same LC987 chain): dispatch entry ObjType
at $808C = L_BE54, LC9AE +3 path to BE57. Same thunk/+3 shape.

## ROM decode (bank4 BE54-BE60; bytes verified vs ROM)
BE54: JMP BE60 ; direct-vec path.
BE57: LDA 00 STA 4C / LDA 0E JSR B2B4 / RTS (BE60).
Lesson: the disasm prints STA LoadedObj+VPi (Velocity_X, $46+$06),
whose machine form is STA $4C. An earlier cut of this snip wrote
STA $06 and lift rightly refused it. Bytes rule; symbols serve.
Callees pre-exist (b4_entry_B2B4). No rewrites beyond the usual
cross-entry goto inline (JMP3 kept, plus RTS6) and dead-label drop.

## Cases
vec007A bank4 guarded cases for BE54/BE57. No BE60 case: never a
vector value. BE61 (twin at $808E, jmp BE95, pre-existing) and BE64
main are the predicted next traps, left for the trap-driven loop.

## Regen recipe
1. lift.py be54.snip OUT b4 entry_BE54,entry_BE57 stub(B2B4)
with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpBE54.py splices decls, bodies, cases into gen combined
off/enf (anchored on the B08B batch); ADDRMAP, PROV_ALL, vec007A.
