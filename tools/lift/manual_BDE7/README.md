# Manual vec007A entry: bank4 spitter BDE7/BDEA (type $43/$44 family)

## Why manual
After the BD5C slice, the TAS-allbosses port trapped vec007A-unmapped
at v=BDEA (port ff~5568, same LC987 chain): dispatch entry ObjType
at $808A = L_BDE7, LC9AE +3 path to BDEA. Same family, same +3 shape
as BD5C/BD5F (direct thunk vs +3 main at adjacent table slots).

## ROM decode (bank4 BDE7-BE0D; disasm gap, verified vs ROM bytes)
BDE7: JMP BE0E ; direct-vec path (state advance handled elsewhere)
BDEA: LDA 80 STA42 / LDA 80 STA43 / JSR C12F / BEQ LBE01 /
LDA 54 STA 0400,X / LDA 50 STA 040B,X /
LBE01: CLC / LDA 50 ADC 08 STA 50 / DEC 51 / BNE BE0E / DEC 46 /
falls through BE0D to BE0E at zero cycles.
BDE3 is a 4-byte data table (A0 E0 20 60) read by L_BE3E, not code;
left untouched. Callees pre-exist: b7_entry_C12F, b4_entry_BE0E.

## Snip fixes
1. BEQ LBE01 crosses the BD/BE page (BDF5 to BE01): lift charges the
HW-correct 4 cycles. Verified against ROM layout, not assumed.
2. Mid-region BNE to external stub entry_BE0E via argv5 stubset:
lift emits a zero-return tail call, correct.
3. Terminal fall-through into BE0E spelled as explicit jmp in-snip;
wp strips the phantom JMP3 plus the two dup polls (BE0E head polls).
Net: BE0E call plus return at zero added cycles.
4. No LC rewrites needed (entry_C12F names the bank7 entry directly).

## Cases
vec007A bank4 guarded cases for BDE7/BDEA. No BE01 case: local label,
never a vector value.

## Regen recipe
1. lift.py bdea.snip OUT b4 entry_BDE7,entry_BDEA stubs(BE0E,C12F)
with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpBDE7.py splices decls, bodies, cases into gen combined
off/enf (anchored on the BD6C batch); ADDRMAP, PROV_ALL, vec007A.
