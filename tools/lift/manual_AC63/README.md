# Manual vec007A entry: bank6 AC63 JMP-ACD0 table-gap trampoline (TAS trap port-ff ~1800)

## Why manual
Constant-phase TAS probes (pads[ff+K], K=0/2/4) all trapped vec007A-unmapped
at v=AC63 within 4 frames of movie-time ~1800, while the adaptive wall+2 run
sailed past with FIRST-DIFF f=1801. Movie pads are all-zero until f=1801
(single-frame START tap) and f=1822 (START+R tap): the trap fires ~3 frames
after the START edge is consumed - the START/game-start path dispatches AC63.
The wall+2 run consumes START ~7 frames early and takes a different (mapped
but off-oracle) branch; constant-phase stays on the oracle path into AC63.

## Bank proof (bank6, not bank4)
- Mapped-bank probe (work/tas-bankid.cjs): reads the real swbank pointer
  (i32 at the exported swbank variable address; the export itself is the
  variable address, contents confirmed prg[0]-head-shaped preboot) at the
  trap: swbank-ptr=0x204b0 = prg[6] image base (images verified at
  0x84b0+N*0x4000 via all eight bank-head signatures, one hit each).
- ROM decode: bank6 $AC63 = 4C D0 AC = JMP $ACD0, exactly filling the
  disasm ByteTable gap $AC63-$AC65 between Code $AC3F-$AC62 and $AC66-$ACF9
  (prg6_auto.info). b6_entry_ACD0 pre-exists in gen.
- bank4 $AC63 = byte $02 (KIL, inside ByteTable $AC4F-$ACA1): executing it
  with bank4 mapped would JAM, so the dispatch is only sane with prg[6].
- ROM parity verified vs ROM file: bank6 offset 16+6*16384+0x2C63 = 4C D0 AC.

## Lift
lift.py ac63.snip OUT b6 entry_AC63 entry_ACD0(stub slot carries the bare
label; the stub() wrapper in older READMEs is descriptive, argv takes the
bare label) with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
The stub mechanism resolves the same-bank jmp edge to the pre-existing
b6_entry_ACD0 body with no transcription (cf. 8BFD stub(entry_8C16)):
spliced body is the 6-line trampoline poll/poll/cycles-3/tail-call.
WANT=[b6_entry_AC63] only. No pre-existing AC63 under any name.

## Cases
vec007A bank6 guarded case for AC63 (guard matches A9CE bank6 + 8BFD newest
slices; neighbors AC3F/AC66/ACFE are older unguarded cases, left as-is).
Appended to the 007A 6 line after B846.

## Regen recipe
1. lift.py as above (stub slot bare entry_ACD0).
2. wp_wpAC63.py splices decl (x2 sites), body (before b6_entry_AC66),
guarded case (after case 0xAC66) into gen combined off/enf; ADDRMAP
(AC63 6 between AC62/AC66), PROV_ALL, vec007A 6-line.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
