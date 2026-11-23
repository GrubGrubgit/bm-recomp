# Manual vec007A entry: bank4 9AEE (TAS trap port-ff ~9527)

## Why manual
The TAS-allbosses port (presnap scoring, clean to wall 7999 with a
5-byte micro-residual) traps vec007A-unmapped at port-ff ~9527
(code 0x9AEE, same b7_LC977 enemy-loop dispatch chain as the 9072/9FEE
family, called from b7_entry_C3D5). No pre-existing 9AEE under any name
(interior nmi_pc only, inside b4_L9AEA).

## ROM decode (bytes verified vs ROM at file offset 72446)
9AEE: SEC (38) / SBC #$01 (E9 01) / BNE L9ADA (D0 E7; 9AF3-25 = 9ADA) /
fallthrough to L9AF3 (A5 3F = LDA $3F ...). So 9AEE is a legit resume
point: re-enter the L9ADA loop-decrement step, or fall into L9AF3.
Ends via L9B0A: RTS. Bank4-unique: bank0/5/6/7t gens have zero 9AEE hits,
so the vec case is unguarded (same convention as neighbors
9A80/9A8B/9A8E).

## Lift
lift.py 9aee.snip OUT b4 entry_9AEE, stubs L9ADA,L9AF3 (branch/jmp refs
to existing bank4 TU functions), with ADDRMAP PROV JMPTAB, UNWIND off
(off) / enforce (enf; identical, no jsr in snip). Stub trap decls+defs
for L9ADA/L9AF3 are STRIPPED (bodies already in bank4 TU); only
b4_entry_9AEE is spliced.
WANT is b4_entry_9AEE only.

## Hand-shape (B563 class)
Pure lift cannot spell ROM fallthrough: the snip-level `jmp L9AF3`
emits a 3-cycle JMP charge, but HW falls through from BNE-not-taken to
9AF3 at zero cycles. The splice drops exactly that `cycles += 3;` line
(polls + call kept). Norm-verified: lifted SEC/SBC/BNE lines are
byte-identical to the TU b4_L9AEA 9AEE-9AF1 segment (modulo poll-site
names); the remainder is the zero-cycle tail call b4_L9AF3().

## Cases
vec007A bank4 unguarded case for 9AEE only, inserted 9A8E..9AEE..9B0E
(matching ROM/ADDRMAP order).

## Regen recipe
1. lift.py as above (stub slot is `L9ADA,L9AF3`; ADDRMAP/PROV/JMPTAB are
   argv 6+; UNWIND off for out_off.c, enforce for out_enf.c).
2. wp_wp9AEE.py: norm-checks vs TU, hand-shapes the tail, splices decl
   (both decl regions), body (ahead of 9B0E), case (after 9A8E) into gen
   combined off+enf; plus ADDRMAP, PROV_ALL, vec007A bank4 slot.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
