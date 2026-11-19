# Manual vec007A entry: bank4 B074/B077 (projectile init, type $54)

## Why manual
After the BDE7 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=B077 (port ff~5568, same LC987 chain): dispatch entry ObjType
at $80AC = L_B074, LC9AE +3 path to B077. Same thunk/+3 shape again.

## ROM decode (bank4 B074-B089; bytes verified vs ROM, not just disasm)
B074: JMP B08A ; direct-vec path (thunk to shared RTS)
B077: LDA 51 STA 47 / LDY 11 JSR C1EF / INC 46 / JSR C1EC /
LDA 1B JSR C216 / RTS (B089). Its own RTS; B08A is a second RTS byte.
Callees pre-exist: b7_entry_C1EF, b7_entry_C1EC, b7_entry_C216.
No bank7 additions, no LC rewrites (entry_ names used directly).

## Snip fixes
1. B074 jmp LB08A targets B077 region: lift emits an illegal
cross-function goto. wp inlines the RTS (JMP3 kept, plus RTS6).
Dead b4_LB08A label removed post-splice for a clean -Wall gate.
2. No fall-through handling needed: B077 ends in its own RTS.

## Cases
vec007A bank4 guarded cases for B074/B077. No B08A case: never a
vector value (direct path vectors B074, +3 path B077).

## Regen recipe
1. lift.py b074.snip OUT b4 entry_B074,entry_B077 stubs(C1EF,C1EC,
C216) with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpB074.py splices decls, bodies, cases into gen combined
off/enf (anchored on the BDE7 batch); ADDRMAP, PROV_ALL, vec007A.
