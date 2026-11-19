# Manual vec007A entries: bank4 BE61/BE64 + bank7 leaves C048/C051/E107/E120

## Why manual
After the BE54 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=BE64 (port ff~5780, same LC987 chain): dispatch entry ObjType
at $808E = L_BE61, LC9AE +3 path to BE64 (zombie-head main). BE61 is
a JMP BE95 thunk (pre-existing target); both needed vec cases.
BE64 calls two bank7 JMP trampolines (C048, C051) whose bodies were
never lifted, so this slice adds bank7 leaves: C048/C051 stubs plus
the E107/E120 delta-to-player routines they jump to.

## ROM decode (bytes verified vs ROM)
BE61: JMP BE95. BE64: LDA C0 STA42/43 / JSR C048 STA 4C /
LDA 3F LDX 4C JSR C14D / LDX 03 JSR C20A STA 4C / JSR C051 STA 4D /
LDA 3F LDX 4D JSR C14D / LDX 03 JSR C20A STA 4D / JSR C02D,
falling through to BE95 at zero cycles.
C048: JMP E107. C051: JMP E120.
E107: LDA 00 PHA / JSR E0ED / ASLx4 STA 00 / TXA LSRx4 ORA 00 /
TAX PLA STA 00 TXA RTS (delta X recombined from q12.4).
E120: same shape with JSR E0FA (delta Y).
All callees beyond the new leaves pre-existed (C14D/C20A/E0ED/E0FA,
LC02D stub, BE95).

## Snip fixes
1. Bank7 leaf snip uses jmp entry_E107/E120 (tail calls, exact JMP3).
jsr entry_E0ED/E0FA auto-resolve via ADDRMAP to b7 (fixed bank).
ADDMAP and PROV lines for C048/C051 were added before lifting
(lift xresolve needs them); the wp script asserts nothing about
them, only about the BE61/BE64 lines it owns.
2. BE64 snip: jsr entry_C048/C051/C14D/C20A auto-resolve to b7
via ADDRMAP fixed-bank hits; only LC02D needs the b4-to-b7 rewrite.
3. Terminal fall-through into BE95 spelled as explicit jmp in-snip;
wp strips the phantom JMP3 plus dup polls.
4. BE61 needs no code beyond its tail call (target pre-existed).

## Cases
vec007A bank4 guarded cases for BE61/BE64.

## Regen recipe
1. lift.py beleaf.snip OUT b7 entries(C048,C051,E107,E120)
stubs(E0ED,E0FA) with ADDRMAP PROV JMPTAB, UNWIND off/enf.
2. lift.py be64.snip OUT b4 entries(BE61,BE64) stub(BE95), same specs.
3. wp_wpBE64.py splices bank7 leaves first (defined before use),
then bank4 bodies (before b4_entry_B7BD), decls, cases (after be57);
ADDRMAP, PROV_ALL, vec007A bank4 line.
