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

## Whole-bank op survey (2026-11-08, decoded non-byte lines)
prg7 (5764 ops): jmp218 adc206 clc186 lsr126 asl93 tax59 ldy50 txa49
  eor34 ror30 bit28 dec24 tay21 tya13 dey10 bvs10 cpx8 txs4 sty4 cpy4
  bvc2 rti2 tsx1 sei1 cld1. prg6 (4503): jmp290 adc129 lsr119 clc115
  dec47 eor29 ldy28 tax27 bit25 asl21 cpx10 bvs5 sty5 txa5 ror2 bvc1
  tay1. prg4 (3858): jmp179 adc117 clc98 lsr64 asl39 tax38 dec31 ldy24
  ror24 cpx17 eor14 txa5 bit5 tay4 tya3 cpy2 sty2 php2 cli1 bvs1.
  prg5 (552): jmp25 asl14 adc11 tay9 clc8 ldy7 dec5 eor3 tya3 tax2
  lsr2 cpx2 txa1 cpy1. prg0-3: tiny decoded residue (jmp/clc/asl/php).
Round 4 order (bank7-driven): transfers tax/txa/tay/tya/tsx/txs/dey/dec,
shifts asl/lsr/ror, adc+eor+clc, cpx/cpy, bit+bvs/bvc, ldy/sty, jmp-goto
(absolute; indirect stays a trace-fed switch), rti/sei/cli/cld as
NMI-runtime notes. Fixture-driven, one group at a time.

## Round 4 group 1 (DONE 2026-11-08): transfers + eor + acc shifts
New ops: tax/txa/tay/tya/tsx/txs, dey, dec-mem, eor-imm, asl-a/lsr-a
(correct C + setZN order, V untouched). runtime.h: 8x16KB prg images
+ swbank pointer; RD serves fixed bank + switchable window from real
bytes (test loads work/banks/prgN.bin, asserts table sanity). New
fixture trans_snip.s: real LC7C7 (tya/eor/tay + triple (zp),y with $
and L pointer forms) + real entry_CA14 (and/asl-a/tax + lda abs,x
from ROM tables LCA2B/LCA2C). make test: 17/17 PASS, incl. CA14 vs
real bytes (X=0E -> 59/15) and LC7C7 pointer-chain values. txs/dey/
dec-mem/lsr-a/tsx emitters share tested patterns, await fixtures.
Next group: shifts-mem/ror + adc + ldy/sty + cpx/cpy.

## Round 4 group 2 (DONE 2026-11-08): arithmetic + mem shifts + bit
New ops: clc, adc imm/mem, sbc mem, cmp mem, bit zp/mem, ror/asl/lsr mem
(via shared rd/wr helpers, V untouched by shifts, BIT preserves C).
Fixtures arith_snip.s: real entry_D136 (bit/bmi/clc/adc mask helper),
real entry_D151+D161 fallthrough (sbc abs, rol chain, ROM table), real
entry_D02D 73-line divide routine (ror/asl/lsr mem, sbc/cmp/adc mem,
bit, full branch family). make test: 21/21 PASS. Two real bugs found
by py65-oracle cross-check (installed pip py65, ran ROM bytes): (1)
ADC overflow subexpression used SBC shape, set phantom V on F0+05;
fixed to ((A^R)&(M^R)). (2) Multi-entry files broke asm fallthrough
(D151 ends mid-C-function); lift now appends tail-call + return when
a function closes on a non-rts op. Whole-bank rule established.
Still untested emitters: txs/tsx/dey/dec-mem/lsr-a/bvs/bvc (pattern-
shared, fixtures pending). Next: ldy/sty/cpx/cpy + jmp-goto, then
whole-function lifting across info Code ranges.
