# Manual vec007A entry: bank4 8B96 (thunk to 8BCF)

## Why manual
After the BE64 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=8B96 (port ff~6385, same LC987 chain): dispatch entry ObjType
at $810C = L_8B96. Direct dispatch (8B96 itself, not a +3 twin).

## ROM decode (bytes verified vs ROM)
8B96: JMP 8BCF. Target b4_entry_8BCF pre-existed (chain to 8C16).
Single-instruction slice: no new code beyond the vec case and decl.

## Cases
vec007A bank4 guarded case for 8B96.

## Regen recipe
1. lift.py b896.snip OUT b4 entry_8B96 stub(8BCF) with ADDRMAP PROV
JMPTAB, UNWIND off (enforce for enf).
2. wp_wp8B96.py splices decl, body, case into gen combined off/enf
(anchored on the BE64 batch); ADDRMAP, PROV_ALL, vec007A.
