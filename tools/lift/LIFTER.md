# Lifter (6502 to portable C) -- prototype status

Goal: translate each analyzed Code range (per-bank) into C functions with
explicit CPU state (see runtime.h), resolving JSR/RTS as C calls, JMP-ind
ROM tables as switches over tracer-observed targets, and RAM vectors
(e.g. (007A) dispatcher at C9D2) as runtime switches fed by trace edges.
Bank switches become runtime calls switching PRG image pointers; the
fixed bank (C000-FFFF) is shared code.

## Prototype (DONE 2026-11-08)
lift.py handles a ca65 subset (labels incl. label+insn on one line,
ldx/inx/dex/stx/lda/and/cmp/rol/bne/rts/nop) and emits one C function
per entry label with goto labels inside. runtime.h provides CPU state +
RAM + split-port pad MMIO. Test: fixtures/input_snip.s is the real
input-strobe routine LE914 from bank7 (da65 output verbatim); make test
lifts it and runs 9 pad vectors -- all pass, Left gives F7=F8=02,
cross-checked against tracer -w F7 on hardware (same 02 from E929).
Tracer -w CLI bug found during cross-check and fixed.

## Next
Widen op coverage (sta/sty/txa/tay/branches/jsr/rts-as-call, flags),
whole-function lifting across Code ranges from info files, jump-table
switches from tracefeed data, then a parity harness: lifted bank vs
tracer watch diffs on recorded tapes.

## Round 2 (DONE 2026-11-08)
lift.py v2: multi-entry files (ENTRY list, forward decls emitted),
Lxxxx label operands, (zp),y indirect with page-wrap, zp/abs indexed
lda/sta, lda immediate, ora immediate, iny, inc zp, full branch family
emission. runtime.h gained an include guard (multi-TU inclusion).
New fixture misc_snip.s: real LE895/LE89F (PPU-mask helpers) + LE996
(indirect vector loader). make test: 9 pad + 4 misc checks ALL PASS,
incl. E996 bne taken/not-taken (Y=5 vs Y=FF wrap to hi-inc path).
Test-honest gaps: beq/bcc/bcs/bpl/bmi emitters share the bne pattern
but no lifted routine exercises them yet; WR drops 2000-2007 PPU
writes (runtime has no PPU); LE936-style NMI-spinwaits cannot run bare.
Next: jsr-as-C-call with forward decls; target test is LE8A9-head
(lda/sta zp, pha/pla, cmp zp, beq, 3x jsr LE914 with P1/P2 compare),
which needs pha/pla, cmp zp, and external-callee stubs.

## Round 3 (DONE 2026-11-08)
Subroutine calls + 6502 stack: pha/pla via stk[256]+S (runtime.h), sec,
sbc immediate with full flags (N/Z/C/V, borrow chain, 0x3C preserve),
jsr label-target emitted as a C call (same-file via forward decls,
cross-file via earlier TU inclusion; numeric targets fail fast).
New fixture jsr_snip.s: real entry_E974 (pha/jsr-E996/pla countdown
loop with sec/sbc/bne) + LE9A2 (sta 2007, effect dropped: no PPU).
make test: 14/14 PASS, incl. E974 from A=3 ending A=0 P=0x27 Y=6
S=0xFD (stack balanced, exact-flags check locks sbc encoding).
Remaining branch emitters still routine-untested; cmp-zp/pha/pla now
covered, so LE8A9-head is liftable except external-RAM-vector beq
semantics are in-snippet already (beq LE8C2 needs its body: undoc).
Next: parity harness (lifted bank vs tracer watch diffs on tapes);
then whole-function lifting across info Code ranges.
