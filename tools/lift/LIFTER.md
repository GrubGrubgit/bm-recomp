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

## Round 4 group 3 (DONE 2026-11-08): loads/stores Y, compares, jumps
New ops: ldy imm/mem, sty, cpx/cpy imm/mem, jmp (same-fn goto, self via
top label, entry tail-call, outside-region fail-fast). Control rules
completed: fall-through tail-call, branch-to-entry call+return,
self-branch/jmp top labels, unreferenced labels not emitted (keeps
-Wall clean). New fixture g3_snip.s: real D7C0 (zp,y copy loop, cpy
exit), D7CF (cpx, self-jmp countdown), D804/D81C (bcc-to-entry call +
fall-through, sta zp,y), LE2AB (sta (zp),y pair, sty, y-wrap path).
make test: 28/28 PASS, all py65-oracle-agreeing. Two lifter bugs found
by the new tests: double bank prefix on entry calls; fall-through only.
Remaining: ror/rol full confidence (used, more fixtures welcome),
rti/sei/cli/cld (NMI notes), undoc ALU, jmp-indirect RAM/ROM switches.
Next: whole-function lifting across info Code ranges, then parity
harness (lifted bank vs tracer watch diffs on tapes).

## Whole-bank liftability survey (DONE 2026-11-08, tools/lift/survey.py)
Linear-sweeps every bank7 Code range with py65 (6268 insns, 130 ranges):
122 ranges lift TODAY, 8 blocked, all categorized: DATA-with-label
(FDA5 SIGN text, FDF4 RAM text, FB10 table base near THANKS: exclude),
DYNAMIC (C3CF JSR $0000 RAM call: abort/log stub), CROSS-BANK (DEC2
range calls bank5 BFE5/BFE8/BFF1: needs bank-switch call support),
TRACE-SWITCH (C9D3 JMP ($007A): targets known from edges), SYSTEM
(EB96/97 RTI, EBF4 BRK: stubs), TRIVIAL (F23C CLD: added with sei/cli,
pattern-shared, fixtures pending). Whole-bank lift = all Code ranges
as entries + bank-switch calls + RAM-vector switch + stubs.

## Whole-bank bank7 milestone (DONE 2026-11-08)
gen_bank.py slices prg7_auto.s by label address into Code-range groups
(drops excluded islands, unlabeled .byte directives, := aliases), lifts
one TU. Entries: all kept labels (coarse but correct; minimal entries
later). Missing refs become LOUD trap stubs (10: cross-bank DEC2 set,
LC3AA/LC9AE/LCE02/LCEB1/LEB91). Excluded: FDA5-FDAF + FDF4 + FB10-FB12
(data), C9D2-C9D4 (RAM-vector switch, next), C3CF-C3D1 (RAM call stub,
next), EB96-97/EBF4 (system stubs, next), DEC2-E01A (bank5 calls, next).
New ops en route: bvs/bvc, rol-a/ror-a, and/ora/eor mem forms, +N/-N
address exprs (MMC LFFFA+5 writes, dropped by WR for now), entry_-form
and bare-hex operands. Recipe: gen_bank.py prg7_auto.s info 7 snip out
with the 8 excludes; gcc -O2 -Wall -Wextra -Wno-unused-function.
Result: 910 functions, 9673 lines, RC=0 zero warnings, 517KB object
(used-attr forced emission: this gcc drops unreferenced statics).
28/28 fixture tests still pass after every lift.py change.
Next: bank-switch calls (lift DEC2/bank5), C9D3 vector switch with
trace targets, stub bodies, minimal entries, parity harness, banks 6/4.

## RAM-vector switch (DONE 2026-11-08)
lift.py lifts jmp (ADDR) as a tail call to a generated b7_vec_AAAA()
switch over RD(lo)|(RD(hi)<<8). Targets come from edge logs via an
optional 6th argv spec file (lines: VECADDR BANK TGT...). Same-bank
(>=C000) targets call b7_ fns; switchable-window targets call bN_ trap
stubs until banks 4/6 lift (link-time: then replaced by real decls).
gen_bank.py forwards trailing VEC:path args to lift.py.
Census over all 9 edge logs: single site jmp (L007A) at bank7 C9D3,
735770 hits, 112 distinct targets split bank6 (76) + bank4 (36), no
overlap -- so value-dispatch is unambiguous today (asserted in lift;
bank-aware dispatch comes with swbank tracking). Spec committed as
tools/lift/vec007A.txt with edge-log provenance header.
Whole-bank bank7 regen (7 excludes, C9D2-C9D4 now kept, +VEC spec):
912 functions, 10045 lines, 9 stubs (LC9AE now real), RC=0 zero
warnings, 517KB object. Fixture vec_snip.s is the real entry_C9A4
dispatcher + an LC900 inc-probe; mini spec maps C900 same-bank (returns)
plus 8127/8AF1 cross-bank (trap). make test: 28/28 + 4/4 vec PASS
(dispatch executes probe; unknown/default + listed cross-bank trap in
forked children; no-spec lift fails fast). Remaining excludes: data x3,
RAM-call, system, DEC2 cross-bank (bank-switch calls next).

## Cross-bank calls + MMC runtime (DONE 2026-11-08)
lift.py takes tagged spec args: VEC:path (vector switch, bare path still vec)
and XBANK:path (lines LABEL BANK). jsr/jmp-plain to an xbank label emits
bN_label() with decls + trap stubs (skipped from the b7 stub loops); same-bank
xbank targets reuse real fns via the _defined guard.
runtime.h WR now emulates MMC1 serial writes (shift/count/commit, reg3 selects
swbank, bit7 resets to prg[0]); CHR regs ignored and PRG-mode bits unmodeled,
same simplification as the tracer. Writes to ROM vectors (LFFFA+5) clock the
shifter exactly like hardware -- no special case.
Real spec tools/lift/xbank_b5.txt (LBFE5/BFE8/BFF1 -> bank5). Bank7 TU regen
with 6 excludes (DEC2-E01A kept): 949 fns, 10364 lines, 7 stubs (3 xbank + 4
local), RC=0 zero warnings. DEC2 lifts to DF05(); b5_LBFE5(); DF0A().
gen_bank.py no longer treats col-0 := aliases as groups (LDFFF := *+1 and the
LBFE5/8/F1 address aliases); hoisted alias-skip runs before islab().
Fixtures: xbank_snip.s (real entry_DEC2 + XBPB probe), xbank_mini.txt; test
gains call_traps helper + xbank trap + 3 MMC checks (select/chr-ignored/reset).
make test: 28/28 + 8/8 PASS. Remaining excludes: data x3, RAM-call, system.

## Stub-bodies verdict + RAM call live (DONE 2026-11-08)
RTI sites (LEB91 NMI tail, entry_EB97) are dead interrupt vectors: kept NMI
prologue refs jmp LEB91, but nothing calls the handler without hardware NMI,
so the trap stub is correct and loud. LEBF4 brk is a data-table head
(palette, read by lda LEBF4,y via RD) -- stays excluded as data.
LCE02/LCEB1 stubs are data bytes at branch targets: trap-if-reached is honest;
the parity harness will say if the game ever executes them.
The one live stub was LC3AA (game init, beq-referenced): jsr L0000 (L0000 :=
$0000 alias) needs no new lift code -- jsr-to-stub already traps loudly.
Dropped C3CF-C3D1; TU regen with 5 excludes: 950 fns, 10384 lines, 7 stubs
(L0000 replaces LC3AA), RC=0. Fixture ramcall_snip.s is the real LC3AA body;
test: codegen has b7_L0000() + trap def, forked call traps. 28/28 + 9/9 PASS.
Bank7 is now complete: everything lifted except 3 data islands, 2 dead
vectors + 1 data table (excluded), and 7 documented loud traps.
