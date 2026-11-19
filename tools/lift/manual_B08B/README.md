# Manual vec007A entry: bank4 B08B/B08E (projectile main, type $55)

## Why manual
After the B074 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=B08E (port ff~5569, same LC987 chain): dispatch entry ObjType
at $80AE = L_B08B, LC9AE +3 path to B08E. Same thunk/+3 shape again;
the same enemy object advancing its type each frame.

## ROM decode (bank4 B08B-B09D; bytes verified vs ROM)
B08B: JMP B09E ; direct-vec path.
B08E: LDA 80 STA42 / LDA 80 STA43 / JSR C030 / BEQ B09E / JMP C114.
BEQ is not-taken/taken inside one page (B099 to B09E): 2/3 cycles.
C030 is a JMPTAB slot to E0A5: lift short-circuits to a 9-cycle
SLOT-JSR b7_entry_E0A5 automatically. C114 resolves via ADDRMAP to
b7_entry_C114 automatically. No rewrites, no tail strip: both entries
terminate in jumps. Pre-existing: b4_entry_B09E.

## Cases
vec007A bank4 guarded cases for B08B/B08E.

## Regen recipe
1. lift.py b08b.snip OUT b4 entry_B08B,entry_B08E stub(B09E)
with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpB08B.py splices decls, bodies, cases into gen combined
off/enf (anchored on the B074 batch); ADDRMAP, PROV_ALL, vec007A.
