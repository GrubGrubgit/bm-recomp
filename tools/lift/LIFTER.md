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

## Whole-bank bank6 (DONE 2026-11-08)
lift.py bank-prefix is now the bank argv (was hardcoded b7_); bank7 TU regen
is byte-identical, and make test still passes -- behavior-preserving proof.
xbank spec lines grew an optional TARGET (LABEL BANK [TARGET]): bank6 and
bank7 da65 names differ per file (LD136 vs entry_D136), so work/bank6xmap.py
maps by ADDRESS to the bank7 kept-label name (entry_-preferred). 77 refs, all
to real bank7 fns, 0 unmapped. (One lift bug fixed en route: _xt overwrite.)
gen_bank.py auto-drops data-only groups (directives, no code) but keeps pure
alias labels (fall-through is correct for them); referenced data becomes loud
traps (LCE02 pattern). Bank7 regen with auto-drop is byte-identical (its data
was already out) -- safe. survey.py takes BANK argv and accepts fixed-bank
targets. Bank6 survey: 109 ranges, 4982 insns, ALL clean, no new ops needed.
Bank6 TU with ZERO excludes + xbank_b6t7: 875 fns, 8699 lines, 0 b6 stubs,
RC=0 zero warnings. Fixture b6_snip.s locks the b6 prefix (self-loop +
branch-to-entry); make test 30/30 + 9/9. Deferred to bank5 link-up: combined
TU needs static/collision handling (xbank prov-skip + C-label namespacing).

## Whole-bank bank5 (DONE 2026-11-08)
Bank5 is the music engine + data tables. Survey: 9 Code ranges, 625 insns,
4 blocked ranges all music DATA with JAM guards. Proven never-executed:
0 hits across trace0+trace1 (17.4M insns, 575K in bank5). BFE5/BFE8/BFF1
are trampolines to entry_8000/8013/8077. The lone jsr entry_B2C5 sits
inside a data island (false ref); its trap is honest -- executing it would
hang hardware. Excluded the 4 data ranges.
xbank_b5.txt gained TARGETs (LBFE5 5 entry_BFE5) so the combined link will
resolve; bank7 regen now calls b5_entry_BFE5 (RC=0, only 3 lines differ).
Bank5 TU: 4 excludes + xbank_b5t7 (5 refs to bank7): 91 fns, RC=0, 0 b5
stubs. Fixture b5_snip.s (closed L839A ora-bit5 / LBEA6 and-clear-bit0);
make test 32/32 + 9/9. work/bank6xmap.py takes BANK argv.
Fixed lift xbank TARGET overwrite bug; fixtures regression-cover it.

## Combined-TU link (DONE 2026-11-08): ADDRMAP + PROV retire xbank

Cross-bank calls no longer need hand-written xbank spec files. lift.py takes
ADDRMAP:path (lines ADDR BANK LABEL: every kept label of every lifted bank,
built by tools/lift/gen_addr.py from the kept-group .snips; committed as
tools/lift/ADDRMAP.txt, 1916 addrs across banks 5/6/7) and resolves
label-form jsr/jmp-plain/branch operands by address: same-bank hits keep the
existing local logic, cross-bank hits emit bT_name() calls with forward
decls (unique-or-fail-fast; bank7 refs only hit single-bank addrs today).
PROV:path (lines LABEL BANK: the union of kept labels, committed as
tools/lift/PROV_ALL.txt) gates trap definitions: a cross/vec target whose
(name, bank) is provided gets a decl but no trap body, so the sibling TU
text provides the single definition. Standalone builds omit PROV and keep
loud traps (current behavior; prov-flavored standalone .o files compile
RC=0 with benign -Wundefined-internal notes for the decls).
Vec target names also resolve via ADDRMAP (bank7 switch now calls real
b6_entry_* instead of b6_L* stubs); bank4 targets (bank4 not yet lifted)
fall back to L-form trap stubs. XBANK: is retired (fail-fast) and the
xbank_*.txt + fixtures/xbank_mini.txt specs are deleted; fixtures use
fixtures/addrmap_mini.txt (BFE5/8, C900, 8127; 8AF1 deliberately missing
to cover the fallback path). C labels are C-bank-namespaced (bN_ prefix on
label defs and goto targets) so the combined TU cannot collide.
make test still passes with ZERO test-main changes (32/32 + 9/9).

Combined TU work/combined.c concatenates the three prov-flavored TUs under
one runtime.h (include guard): 1962 functions, compiles RC=0 with ZERO
warnings under plain -Wall -Wextra. Transitive-closure analysis over the
call graph from the 76 bank6 vec targets: 33 have trap-free closures
(up to 92 fns); 41 reach bank4-fallback traps (bank4 not lifted yet).
Parity sweep (work/parity.py driving work/smoke.c + work/smoke_oracle.py,
zero-state, vector-dispatched through b7_vec_007A, compared against py65
running real ROM bytes): 33/33 oracle-agreeing -- registers exact, RAM
exact modulo stack-page jsr-residue bytes. Residue soundness is enforced, not
assumed: the oracle logs every executed absolute/indexed/indirect-y read of
0x0100-0x01FF plus any MMC-area write, and the driver only accepts masked
bytes that no executed read touched (observed maxima: 10 residue bytes,
1 stack read elsewhere, 0 MMC writes). Recipe to extend: lift bank4, append
its snip to gen_addr.py inputs, regen ADDRMAP/PROV_ALL, regen all TUs.

## Stack/absolute aliasing fix (DONE 2026-11-08, found by the sweep)

The first smoke run showed 4 differing bytes (stack slots FA-FD): py65 keeps
jsr return-address residue in 0x100-0x1FF while stk[] was a separate array.
Worse, the split also broke real code: bank7 does absolute stack-page data
traffic (LCACA cmp $0100,y; sta $0100,x / $010A,x), which must share cells
with pha/pla. runtime.h now aliases: #define stk (ram + 0x100) (test-main
and harness memsets updated to ram + 0x100). Remaining model gap G1: jsr
is a C call so it leaves no residue -- covered by the guarded mask above.

## Whole-bank bank4 (DONE 2026-11-08)

Survey: 102 ranges / 4224 insns. Single exclude 80C9-80DE, proven DATA
island (0 executions over 82M+ edge records plus 17.4M full-trace insns,
all logs scanned). Everything else lifts, with three new lift features:

- PLP + PHP, py65-exact (pulled/residue bits forced: stk[S] | 0x30).
  Needed for B1B6-B284. Fixture fixtures/b4_snip.s is the real B1F9
  php/plp block with two oracle-locked tests (bcc path and ora path).
- jsr S-move: every lifted jsr emits S -= 2 around the C call and
  S += 2 after, mirroring hardware stack-pointer movement (no dummy
  writes; residue bytes still a documented gap, see G1).
- JMPTAB slot map for fixed-bank jump-table slots called from the
  C window: slots C015/C024/C0C0 resolve to D37D/D324/D7B6 (each
  verified in ROM as JMP to a kept label). lift.py takes JMPTAB:path
  and xresolve consults slots after the same-bank check; gen_bank.py
  forwards JMPTAB:. Spec file: tools/lift/JMPTAB.txt.

Census of all 528 bank4 label refs: only those 3 C-window addrs lack
bank7 kept names (all others auto-resolve via ADDRMAP); all 76 bank4
stubs are C-window labels (no switchable-window dropped-label hazard).
Fixture renames: fixtures/xbank_snip.s -> fixtures/addrmap_snip.s
(+ test_vec_main.c message). make test 34/34 + 9/9.

Regen (byte-reproducible from committed sources + disasm input):
  gen_bank.py banks/prg4_auto.s info/prg4_auto.info 4 bank4.snip bank4.c \
    80C9-80DE ADDRMAP:ADDRMAP.txt PROV:PROV_ALL.txt JMPTAB:JMPTAB.txt
Verified: rerun reproduces bank4.snip and bank4.c byte-identically.
ADDRMAP/PROV 1916 -> 2529 entries; all 4 TUs regen RC=0 (bank4: 613
kept groups); combined TU recompiles RC=0 with zero warnings under
plain -Wall -Wextra. Trap defs down to 6 honest ones: b7_L0000 /
LCE02 / LCEB1 / LEB91 plus deferred b6_L9B98 / b6_L9BDB (vec targets
into bank6 gaps, 625 cold hits; deliberately kept trapping).
Closure (path-insensitive over combined.c): bank6 33 closed / 41 open,
bank4 28 closed / 10 open. Analysis-correctness note: match trap defs
with a capture group and no post-split (a no-group findall + [1] split
yields a bogus single trap named 'void' and silently reports 38 closed).
Open targets confirmed live at runtime via trap instrumentation
(replacing trap bodies with print+exit): 9B67/970F both hit b7_LCEB1.

Parity sweep (smoke.c/smoke_oracle.py bank-parametric, shadow-stack
oracle that breaks only on RTS with an empty shadow return stack):
bank6 33/33 re-verified on current build (3 exact + 30 masked-sound,
max 10 residue bytes, 0 MMC writes). Bank4 28: 26 PASS (7 exact +
19 masked-sound, max 4 residue bytes, 0 MMC) plus two zero-state
artifacts, both crash-family, both proven on hardware semantics:
- 4:9A8E SKIP (oracle cap, depth 1): unbalanced return strands a
  frame; execution wanders into the BRK vector and spins in the EB97
  handler (RTI loop). The lifter cannot agree with hardware that
  never returns.
- 4:8FC3 documented gap G2: entry_9007 with $46==0 runs jsr LC1CE
  (balanced), then pla/pla eats its own caller's live return address
  (8FD3) and rts pulls the outer frame. Under zero-state S=FD that
  is $0000 -> PC=$0001 -> BRK -> 920A RTS break (S=F8, A=$30).
  The lifter models rts as a clean C return to 8FD4 (exit 0, S=FF).
  Real-hardware behavior verified by instrumented oracle trace.

Model gap G2 (new, gameplay-relevant): the pla-n-plus-rts stack-unwind
idiom (early-exit abort past live frames) is not modeled -- a C return
always resumes the direct caller. Fixing it needs an explicit return
stack or longjmp design; deferred until a reached routine depends on it.

## Snapshot-init parity + D7A0-class fix (DONE 2026-11-08)

D7A0-class disassembly bug: da65 ByteTable gaps inside live code lift as phantom fall-through calls (missing body + rts, wrong-body neighbors, phantom double-jsr). Found via snapshot FAIL cluster (8F9F/8FA2/8FC3 regs, 9E1A/9E1D regs, 9B14/99B0/9B17 stack bytes -- all fixed by this unit), proven by C-side stderr instrumentation + oracle traces. Root cause is analyze.py LEN holes (stage +0x95 only; full rollout blocked by bank0 false descent, see CURRENT_TASK). Newly decoded regions (D795/D7A9/D7B6/D7BA, LCE02/LCEB1, bank4 A4A7/A8C9/A8D9/A8ED/AB9B/ABA8/AE64/AE71, bank7 C267/CDF8/...) are validated by parity, not trusted blindly.

Regen recipe v2 (two-pass; run from recomp/tools/lift with absolute paths):
  pass1 bank7: gen_bank.py banks/prg7_auto.s info/prg7_auto.info 7 bank7t.snip bank7t.c FB10-FB12 FDA5-FDAF FDF4-FDF4 EB96-EB97 EBF4-EBF4 VEC:vec007A.txt ADDRMAP:ADDRMAP.txt PROV:PROV_ALL.txt
  pass1 bank4: gen_bank.py banks/prg4_auto.s info/prg4_auto.info 4 bank4.snip bank4.c 80C9-80DE ADDRMAP:ADDRMAP.txt PROV:PROV_ALL.txt JMPTAB:JMPTAB.txt
  maps: gen_addr.py ADDRMAP.txt PROV_ALL.txt bank7t.snip 7 bank6.snip 6 bank5.snip 5 bank4.snip 4  (expect pure additions)
  pass2: rerun all four (bank6 zero excludes + ADDRMAP + PROV; bank5 4 excludes A002-A009 B008-B00A B00E-B014 B2C5-B2D2 + ADDRMAP + PROV) with the new maps.
  combined: runtime.h + TU bodies minus the runtime include line, in 7t/6/5/4 order; cc -O2 -Wall -Wextra must be warning-free.
Bank7 excludes rationale (5): data x3 + rti/brk system (lift.py fails fast on rti; LEBF4 brk heads a palette table). Excludes were recovered from old-info-vs-old-snip diff; rebuild.sh does NOT record them (it only seeds descents). JMPTAB is only needed where C-window refs exist (bank4: C015/C024/C0C0); VEC only where the (007A) dispatcher lives (bank7).

Parity (new build): zero-state bank6 33/33, bank4 32 closed (new 970C/970F/9B64/9B67) = 28 PASS + 3 cap-SKIP + 1 G2-FAIL (8FC3). Snapshot (73 records, 22 relevant): bank6 396/396, bank4 290 PASS + 20 G2-SKIP + 10 crash-FAIL. Sweep driver: smoke.c/smoke_oracle.py (zero-state) and smoke_snap.c/oracle_snap.py/sweep_snap.py snapfile [idx...] (snapshot-init, skips D-flag + non-4/6 banks). oracle_snap shadows the return stack (RTS-with-empty-stack = done), logs stack-page sreads excluding pure stores (G1-residue soundness), and models MMC shift/commit with modemode flag.

Model gap G2 generalized (deferred): any unbalanced/shared-tail rts, pla-eaten frames, interpreter RTS-dispatch, or mid-function entries diverge by construction (C-return vs hardware stack-pop). Proven case: snap15-9B64 runs 4311 steps in-closure, then rts pops live snapshot stack into the main-loop input poll. Zero-state crash family (9A8E/970C/9B64: BRK-vector wander, RAM wander, NMI-handler spin) is the same class. Fixing needs an explicit return stack or longjmp design; deferred until a reached routine depends on it.
Analysis pitfall: closed_targets must not treat a missing root as closed (vacuous closure) -- sweep.py now WARNs+skips unknown roots.
Regen recipe v3 (current): analyze.py LEN2 now also holds the 12 indirect-ALU ops (01/11/21/31/41/51/61/71/C1/D1/E1/F1) plus 0x95. Two bank-data carves via analyze.py --excl (wired per-bank in rebuild.sh): bank0 806D-807E, bank2 B2C6-B2CC -- both decode as code only by sliding through undoc/JAM/BRK bytes with zero execution evidence anywhere. Never carve a lifted bank on decode-shape alone; carving needs no-exec PLUS a halt-byte (JAM/BRK) or equivalent. Unlabeled dead Code ranges (e.g. FDB0-FDB7) are inert: gen_bank only lifts labeled groups and ADDRMAP only lists kept labels.
How new D7A0-class gaps were found (repeatable): execset.py builds the executed-(bank,pc) set over all trace/edge logs in one pass; verdict.py intersects it with gapcheck gaps. Interior execution (beyond the lo endpoint) in a ByteTable gap means linear code until proven otherwise; lo-endpoint-only hits are usually scanbytes-oplen boundary artifacts or jump-table adjacency (G2 class). Confirm by manual decode + clean control flow, then extend LEN, rebuild, review every info diff range-by-range (any bank0-3 growth or halt-byte inclusion = false descent, carve it), regen, resweep.

## Stack-unwind safety net / G2 closure (DONE 2026-11-08)

Problem: rts-as-C-return diverges wherever 6502 code eats live return
addresses and returns past its caller: entry_9007 (lda $46 / bne shared
rts; $46==0 path runs jsr LC1CE then pla/pla/rts, eating the 8FD3 frame
and popping wilderness) and the bank7 D710 hub (a shared-tail rts reached
both by direct beq/bcc branches for balanced returns and by a pla/pla +
lda #$FF unwind block eating one frame, e.g. via the D711 -> LD6CD chain,
resuming mid-code such as D773). Zero-state 8FC3 FAIL plus 9A8E/970C/9B64
SKIPs plus snapshot 20 SKIP + 10 FAIL all traced to these two shapes with
py65 step traces (8FC3: 82 steps to the 9010 escape; D710 escapes at
depths 2/5 with popped D772/9B09/993C/0000 against shadow tops).

Mechanism (lift.py UNWIND:off|log|enforce, forwarded by gen_bank.py;
runtime.h gains int uw_abort): every jsr site emits S -= 2, a snapshot of
S, the callee call, then: first S mismatch sets uw_abort with one stderr
UNWIND-ESCAPE note (caller/callee/S/want) and every level returns
immediately, preserving S, so the closure unwinds to the driver, which
dumps the escape state. Balanced callees see S == snapshot and behave
bit-identically to before. Tail calls, branch-to-entry calls and the vec
dispatch propagate automatically through bare returns. Fixtures build with
the default off mode, so make test covers the off path.

Oracle side (work-local oracle_esc.py / oracle_snap_esc.py + sweep_esc.py):
the shadow-stack oracle stops at the FIRST rts whose popped PC + 1 differs
from the shadow top and reports the pre-rts state as done (root-level
empty-shadow rule unchanged). Sound residue-taint tracks the one known
C/hardware stack divergence (G1: lifted jsr pushes no residue bytes):
JSR/BRK pushes mark stack bytes, pha/php/stores propagate the pushing
reg taint, pla/plp/loads/transfers/ALU propagate into A/X/Y, a sticky bit
records any flag-setting op with a tainted source, and snapshot/zero-state
initial bytes are clean (both sides copy the same init). sweep_esc masks
tainted A/X/Y (and P when any of those or the flag bit is tainted) plus
tainted-mem RAM bytes on escape-dones; S is never masked. Balanced dones
verify zero taint.

Verification (phased): Phase-1 log build reproduces baseline verdicts
exactly (61 PASS + 3 SKIP + 1 FAIL zero-state) with UNWIND firing only on
the 4 known-divergent targets and silence on all 61 PASS paths; txs owners
(C29E/C2AC/LE351/F23B) statically proven unreached by every closed closure.
Phase-2 enforce + escape-stop: zero-state 65/65 PASS (10 exact + 55
masked) with 8FC3 FAIL and 9A8E/970C/9B64 SKIP all converting to PASS;
snapshot 716/716 PASS (106 exact + 610 masked) with all 20 former SKIP and
10 former FAIL converting. C-side and oracle-side escapes agree 1:1 (4
zero-state + 30 snapshot, all on the two documented shapes, zero
one-sided escapes). Parity is now agreement up to the first stack escape.

Regen recipe v4 (UNWIND:enforce appended to each gen_bank line; maps and
excludes unchanged): bank7t with 5 excludes + VEC + ADDRMAP + PROV, bank6
with ADDRMAP + PROV, bank5 with 4 excludes + ADDRMAP + PROV, bank4 with
80C9-80DE + ADDRMAP + PROV + JMPTAB, all plus UNWIND:enforce; combined.c
as before (7t/6/5/4 order, -Wall -Wextra clean); smoke drivers init
uw_abort = 0. Counts unchanged (972/875/91/622, 4 named traps + default).

Forward note: full-game-loop integration will need target-resume (jumping
to the popped mid-function continuation instead of unwinding to the
driver). The escape logs already record the exact resume PCs
(UNWIND-ESCAPE caller/callee/S on the C side, ORACLE-ESCAPE
pc/popped/want/depth on the oracle side), so that design starts from
measured data, not guesswork.

Dead-path census (same unit): 900E/900F/9010, the 9434-block trailing
pla/pla, the 91A1 pla-x4 abort cluster and the 903A chain show zero hits
in the full 5541-PC exec census over all trace and edge logs; only the
synthetic zero-state init ($46==0) forces the 9007 unwind, while real
gameplay traces always take the balanced bne path there.

Bank0-3 verdict (same unit, full corpus): zero executed PCs, zero
crossing edges, zero edge destinations in banks 0-3. Islands catalogued
but unreached (bank0: 111 decoded ops incl. prologue idioms; bank1: one
jmp; bank2: $BF53-$BF8A 56-byte island with a jsr into the carved JAM
region, byte-identical copy present in bank3; bank3: $BF53 island plus
ora/asl/brk slides). Not lifted, no blind tapes run; next hunt should be
a directed boss/deep-dungeon tape with RAM-position feedback, then a
re-census. Stub verdict: no bodies (all traps silent across both esc
sweeps: L0000 init trampoline and LEB91 NMI are harness-unreached by
design, b6_L9B98/L9BDB never execute, vec default is by design).

G4 game-loop pilot (title, no-input): frame-locked parity via cooperative hook.

rti support: lift.py emits RTI as bare return and accepts it in
fall-through tail-call tuples. Fixture fixtures/rti_snip.s covers the real
NMI restore tail LEB91 (pla/tay/pla/tax/pla/rti); make test locks A/P/S.
The NMI path is therefore liftable: the EB96-EB97 exclude was removed from
the regen, so the LEB91 restore tail and entry_EB97 are real lifted code
(bank7 972->974 kept entries; NMI vector EB7E now has a complete body).

PPU model in runtime.h (G4): vram 2KB + palette with tracer-identical
mirror mapping, ppu_addr + latch, ppu_buf with the same read side effects,
OAM + $4014 DMA, scx/scy + latch, reg2000, chr0/chr1, mmc_ctrl. $2002 bit7
toggles on a read counter (every 3rd read returns 0x80); every $2002 read
resets both latches. Census: all 13 in-ROM $2002 reads discard the value
(reset bpl-spins and setup reads; no sprite0 polling anywhere, no $4015
reads). $2007 reads are absent from the reset path. APU $4010/$4015/$4017
writes are dropped in both models.

Dispatch seeding (attempted first, then superseded): walk_dispatch.py
collects jsr fall-through RET addrs over reset, forced-NMI and snapshot
walks (63 RET, 0 ESC on the title path; minus 4 labeled and the 0009
wilderness artifact = 58 NEEDs: 54 bank7 + 4 bank5) plus 23 ground-truth
fall-throughs from the trace0 execution stream (22 bank7 + 80A9 bank5).
Bank7 seeds ride disasm/tools/rebuild.sh fixed entry list, bank5 seeds ride
work/banks/prg5.bin.tentries; ADDRMAP/PROV grew 2560->2620->2643 by pure
addition, ROM-PARITY-OK after every rebuild. gen_dispatch.py builds a
2643-case pop-dispatch table. This pop-and-continue design FAILED at the
first park release (STUCK pop-dispatch 7 C978): lifted jsr does S-=2/+2
with NO stk[] writes, so the popped resume bytes are stale pha/NMI residue,
not the E936-caller return. Hw-accurate stk pushes at every jsr were
considered and rejected (lift.py tracks no per-jsr address; the C stack
cannot resume the abandoned chain anyway). The dispatch table and seeds
stay (harmless, and the 81 sites are real code), but the loop driver does
not use them.

Cooperative design (what works): a work-local hook (hook_g4.py) patches a
fresh combined_g4.c copy (canonical TUs untouched): G4_dump() as the first
statement of b7_entry_E936 (exactly the tracer dump point: pre-exec, so A,
P, $12 and PC all agree with the tracer record with zero masking), then
the two lifted stores (A=0x80, $12=$80), then G4_advance() (pad schedule,
nested-NMI guard, HANG check on reg2000.7, park-limit exit), then the
normal LE93A spin, which exits immediately because the just-fired NMI took
the palette branch and released $12. The NMI (b7_entry_EB7E with P
save/restore, S-drift check) runs as a nested C call each boundary, exactly
matching hardware on the title path (measured: 1 park/frame, 1 NMI/park,
every NMI parked with $12=$80, zero mid-compute NMIs). No alarm, no
longjmp, no dispatch, no wall-clock dependence: fully deterministic.
Nested-guard counter stays 0 (the NMI subtree never re-enters E936).

Tracer bug found by this unit: do_bit used mask 0x3A, clobbering I and C
(real BIT preserves I/D/C). It showed as a park1 P divergence (tracer
0x20 vs lifted 0xA4, I-bit only) after the first NMI. Fixed to 0x3D in
recomp/tools/trace/trace.c (matches the lifted emitter); behavior-neutral
(the NMI gate never consults I), dump-P only. All park references were
regenerated after the fix.

References (work-local, regenerable): trace_park.c = E936-entry park
dumps; trace_park_nonmi.c = same with NMIs suppressed until the first park
(isolates main-thread parity from NMI timing). sweep_g4c.py compares with
ONLY the $0100-$01FF stack page masked (C stack cannot mirror 6502
return-address pushes; S is still compared exact); sweep_g4e.py additionally
selects PC==E936 records so frame-boundary -r snaps cannot misalign the
tail.

Results (no-input title): 28/28 parks EXACT-mod-stack vs the no-pre-park
reference (frames 3..30; A/X/Y/S/P, all RAM, all VRAM, PPU regs, PC, bank,
frame all exact; stackmasked 15 at park0 growing to 28 as both stacks fill
with push residue). Vs the standard reference the ONLY differences are the
single pre-park NMI's effects, fully accounted: $EA-$ED=FF (NMI sound tick
via BFF1/8077), $10 counter +1 lagging by exactly 1 every park (EC51 path),
nothing else. Park0-vs-driver comparison after the dump-point-exact hook
needs no A/$12/P masking at all.

Gameplay probe (tape3, Start at 500): title-phase parity holds through
~park 402 (HW frame ~408; 2 frames of nominal-vs-HW slip accumulate from
NMI-disabled loader frames, visible only in the frame-lo footer byte).
The driver stops at nominal frame ~500 (Start) on a G2 unwind in the
game-start path (UNWIND-ESCAPE LE3DC->E4AB, S=FD vs F7). Gameplay
continuation therefore needs G2 target-resume in the loop driver (next
unit); mid-compute NMIs (seen in longer dungeon tapes) additionally need
cycle timing the lifted code does not have yet. Neither is chased here.

Regen recipe unchanged (canonical TUs carry no hook; esc sweeps re-verified
on the canonical build: zero-state 65/65 PASS, snapshot 716/716 PASS).
The committed trace binary is git-ignored and rebuilt by its Makefile.
snapshots in snaps.bin predate the do_bit fix (their P bytes have I=0);
harmless (I is behavior-neutral in both models) but regenerate them next
time snapshots are rebuilt.
## G2 target-resume gameplay (DONE 2026-11-09 -- 2000-park tape3 run)

Gameplay continuation past Start needed target-resume (jumping to the
popped mid-function continuation instead of unwinding to the driver).

Mechanism (committed): lift.py UNWIND:resume behaves like enforce but
also records uw_caller/uw_callee (runtime.h gains the two globals); the
work-local loop driver (g4_loop3.c) keeps an escape table
caller/callee -> (resume_fn, S) and re-enters from the resume entry.

Two escapes, two shapes:
- LE3DC->E4AB (game-start, S=FD want=F7): resume b7_entry_C2AC, S=0xFF.
  C2AC starts with txs (stack reset), so root re-entry is exact; the
  driver resumed past game-start (620 parks, nested=0).
- D697->LD6CD (dungeon collision, S=F7 want=F5): resume b6_entry_A314,
  S=0xF9 (actual+2). A314 is the fall-through tail of b6_entry_A30A
  (A30A jsr D697; A314: sta $45 ... rts), so root re-entry just runs
  the tail and returns (DONE root-return at 1004 parks). Mid-function
  resumes cannot work as fresh roots -- the outer C frames are lost.

In-function resume (work-local patch, patch_rs_A30A_trap.py): at the
A30A->D697 site, a propagated D697/LD6CD escape is caught instead of
returned: clear uw_abort/caller/callee and fall through, so the normal
S+=2 sets S=F9 and the next call runs b6_entry_A314 inside A30A's
frame. A30A then returns to its caller with S mismatched, which the
outer jsr site reports as a fresh escape -- chained one level per
driver iteration until a loop top or txs entry is reached. Generic rule
for lift.py later: if a propagated escape's resume equals the site's
lexically-next call, handle locally (clear + continue) instead of
returning; otherwise propagate.

Vec-gap stubs 9B98/9BDB (work-local inline, patch_vec_inline.py): both
are +3-nop mid-function entries (9B98 into L9B95, 9BDB into L9BD8;
params 0A/4B vs 0C/4D). The vec switch called trap stubs; the patch
inlines each tail body (skipping the 3 harmless nops) with correct
caller names for unwind reporting. Proper fix later is seeding the two
entries in disasm (pure-add); the inline is behavior-identical.

Verification (tape3, 230-entry wander): g4 done parks=2000 nmis=1999
nested=0, no ESC-UNKNOWN, no traps. Alignment vs tracer parksT3b.bin
(index search +/-12): title exact at off=+1 (1 real diff = $10 lag-by-1
plus the one pre-park NMI tick $EA-$ED at park0); overworld 2 diffs
($10 + frame-lo footer from the +2-frame nominal/HW phase offset after
NMI-disabled loader frames); game-start transient around parks 495-511
(input-sample slip, reconverges); dungeon stable off=-1 with 6-10 diffs
($10/counters, $75-77 RAM, palette 101D-101F, X reg 1029, frame footer)
-- NMI-timing residuals (driver fires 1 boundary NMI/park; hardware
fires mid-compute NMIs in the dungeon, sometimes 2/park), not game-logic
divergence: offset never drifts over 1900+ joined parks. Cycle-timed
mid-compute NMIs remain future work; not needed for trajectory parity.

Disasm seed: bank6 A314 (rebuild.sh +E A314, info/prg6_auto.info label;
ROM-PARITY-OK; bank6 63.3pct). Regen (two-pass: new snips with old maps,
gen_addr pure-add 2643->2644, then enforce+resume regen with new maps):
bank7 1050, bank6 876 (+A314), bank5 96, bank4 622; combined -Wall -Wextra
clean. Canonical (enforce) re-verify: make test ALL PASS, esc zero 65/65
PASS, esc snap 716/716 PASS (logs sweep_esc_zero_A314.log,
sweep_esc_snap_A314.log). Resume TUs differ from enforce only by the
uw_caller/uw_callee recordings per jsr site.


## Cycle-timed mid-compute NMIs (DONE 2026-11-09 -- dungeon RAM/VRAM exactness)

Gameplay trajectory is now bit-exact vs hardware over the full 2000-park
tape3 run: every sampled park matches with zero real diffs, NMI histogram
identical (79 double-NMI parks + one 11-NMI park at the exact same park
indices), no drift over 1900+ joined parks.

NMI census (work/census_nmi.py on traceT3b.bin, 20M recs, 1984 parks):
1904x1 NMI, 79x2, 1x11. The single-NMI parks all fire from the E93A/E93C
boundary spin (already modeled); only ~80 parks take scattered mid-compute
NMIs, from fixed-bank PCs plus one bank6 ECC0 site.

Design: keep the boundary NMI, add lifted cycle counting + poll points so
mid-compute NMIs fire nested at the correct vblank edge. Tracer reference
counts verified: jsr/rts/rti 6, jmp abs 3, jmp ind 5, NMI entry 7, DMA
$4014 +512 on top of the STA, php/pha 3, plp/pla 4, branches 2+1+pagecross.
Only `.byte` directives occur in bank .s files (structural `.code` /
`.segment` carry no bytes).

Mechanism (committed): lift.py counts `cycles` per op (helpers labnum,
num_of_expr, mem_mode, cyc_pre, op_len; (zp),Y double-read via _cycpp so
the page-cross test sees the true base; `; gap N` markers from gen_bank.py
keep the address counter exact across directives), +512 in the $4014 path,
+7 NMI entry in nmi_fire_now. Poll points: every function entry, every jsr
(pre + post), every branch-taken goto, every jmp site. runtime.h
nmi_poll fires per vblank edge crossed (while cycles >= nmi_next_edge,
frame = edge/CPF, next_edge += CPF) when reg2000.7 is set, via
driver-supplied nmi_fire_fn / pad_sample_fn / nmi_log_fn hooks; in_nmi
guard preserves the nested-guard semantics. RD($2002) and RD($4016/17)
mirror the tracer exactly (0xC0 in vblank; live per-cycle pad sampling),
which fixed a 1-frame title lag (reset $2002 spin) and a 1-frame Start
transient (stale latched pad_bits).

Small-base ,y rule (fixed 2026-11-09): the 6502 has no zp,Y form for STA/LDA/CMP/AND/EOR/ORA/ADC/SBC, so a small base with ,y is always absolute (3 bytes): STA costs 5, loads/ALU cost 4 plus page-cross. LDX/STX keep zp,Y; every small ,x site confirmed zp by ROM-opcode census (all 59 small-base indexed sites checked; 8 STA abs,Y + 5 LDA abs,Y corrected). cyc_pre/op_len encode this; gameplay bit-exact to 11400 parks.

Two stale-build lessons (work-local, not committed): a `-nt` poll loop
reported BUILT from a pre-existing binary while the real build still ran,
so one 2000-park run used a no-live-pad binary (extra title frame at
Start, +1 E936, +1 NMI, uniform +1 index shift afterward, reconverging).
Rebuilt + reran: deterministic (two 510-park runs byte-identical), extra
frame gone.

Driver (work-local g4_loop4.c): nmi_next_edge init, pad/frame from
cycles/CPF, per-fire (park, frame, cycles, site) log. Escape table
unchanged (LE3DC/E4AB -> C2AC S=FF; D697/LD6CD -> A314 S=F9).

Verification (tape3): g4 done parks=2000 nmis=2089 nested=0, no
ESC-UNKNOWN/traps/HANG/S-DRIFT. Title 28/28 EXACT-mod-stack vs the
standard (with-NMI) reference. Zone alignment vs parksT3b.bin (rec0 is a
frame-0 boundary snap, hence uniform off=+1 index): every sampled park in
all six zones real=0 with equal frames, no drift. NMI-per-park histogram:
{1:1920, 2:79, 11:1} with multi indices bit-identical to tracer (incl the
11-NMI park 898). Sub-frame phase vs tracer at E936: within ~30 cycles
over 15M cycles.

Regen: enforce+resume TUs with cycle codegen (1050/876/96/622 groups,
-Wall -Wextra clean; TUs grow ~90KB from cycle/poll lines); work-local
patches re-applied (A30A catch, vec bodies with cycle/poll lines, E936
hook anchor with cycles). Canonical (enforce) re-verify: make test ALL
PASS, esc zero 65/65 PASS, esc snap 716/716 PASS (logs
sweep_esc_zero_cycle.log, sweep_snap_cycle.log). Polls are inert when
disarmed (armless + null fire fn), so zero-state/snapshot parity is
unaffected by cycle counting.


## Vec-gap entries seeded in disasm (DONE 2026-11-09 -- work-local inline removed)

9B98/9BDB were +3-nop mid-function entries (tails of L9B95/L9BD8) reached
only via the 007A vec dispatcher; the vec switch called trap stubs, worked
around work-locally by inlining each tail body. Proper fix: seed both as
descent entries (rebuild.sh bank6 +E now `A314 9B98 9BDB`; analyze.py
auto-emits the LABELs; ROM-PARITY-OK, bank6 still 63.3pct since no new
bytes are decoded). Every kept label is already a lift entry, so no
lifter change was needed: pass-1 regen with old maps kept the new groups,
gen_addr pure-added 2644->2646 (9B98/9BDB x2 files), pass-2 regen resolves
the vec cases to real b6_entry_9B98/b6_entry_9BDB (cycle/poll-counted by
construction; the hand-written inline bodies are deleted, trap stubs gone).

Side fix (work-local sweep.py): closed_targets enumerated from the stale
plain combined.c, so the new entries WARN-skipped; it now reads the tested
combined_enf.c (same call graph, current bodies). Zero-state esc: 67/67
PASS (35 bank6 incl new 9B98/9BDB masked=2 noesc + 32 bank4), no FAIL/SKIP.
Gameplay re-verified after the change: title 28/28 EXACT, 2000-park tape3
run bit-exact (zones all real=0, NMI histogram bit-identical), esc snap
740/740 PASS (716 + 24 new-entry snapshot runs).


## In-function resume generalized into lift.py (DONE 2026-11-09 -- work-local A30A catch deleted)

The A30A->D697 work-local catch (clear abort, fall through S+=2, run A314
in-frame) is now a lift.py rule: in UNWIND:resume mode each jsr site
records its lexically-next call (backpatched `/*UW_NEXT*/` at function
fall-through into entry E, only when the jsr is the final insn -- the
last_op == 'jsr' guard skips branch-tailed functions where straight-line
next is ambiguous). At runtime the site calls the driver hook
uw_local_fn(uw_caller, uw_callee, next) with the RECORDED escape pair
(first version passed the site pair and never matched -- fixed); the
driver clears the abort and continues in-frame iff its escrow maps the
escape to a resume whose name equals next. Otherwise (unknown escape,
branch-tailed, enforce/off builds with null hook) it propagates exactly
as before.

Net effect on this game: the D697/LD6CD escape (resume A314 == A30A's
fall-through) is caught at all 900+ dungeon occurrences -- zero
D697 RESUME lines in the 2000-park log, only the game-start LE3DC row
still root-resumes by design (its next, E3E0, differs from C2AC).
combined_rs carries 1000+ next-annotations, enforce TU byte-identical in
behavior (no hook). 2000-park run bit-exact (zones real=0, NMI histogram
bit-identical, nmis=2089). Canonical: make test ALL PASS, esc zero 67/67,
esc snap 740/740.
## Bank0 family coverage (DONE 2026-11-09 -- dark-code unit)

Bank0 contains 4 instances (BD99/BE0A/BE91/BF4E) of a prologue family byte-identical to ~40 live bank4 instances + 1 bank5 (BE91-variant x6 in bank4): `lda #imm / sta $40 / sta $41 / jsr LC0FF / beq / jmp LC17A`, then per-instance payloads (BD99 calls seeded BE3A; BE0A/BE91/BF4E call bank0-local LB310/LB2C1/LB2F3 + fixed trampolines). Never executes in the full corpus (6720-PC census incl. dungeon traces); no static callers or vector targets; modes 4/6 map bank0 for data reads only (mode-forcing proven). BD99 was unseeded inside ByteTable B317-BDDB; seeding merged BD99-BDDE to Code (+75B, parity-safe).
TU policy for dark code: lift the coherent cluster with gen_bank excludes for data-decodes (bank0: 8080-80A0 JAM, BFE5-BFE7/BFF1-BFF3 jmp-into-data), auto-drop turns undoc/data callees into honest traps, vec007A carries a manual bank0 line (family evidence, zero-exec noted) so closed-target sweeps test what is statically closed (BE3A verified PASS masked=2 zero-state + 4 bank0-snap inits; majors excluded by their data-callee traps; tails BDDC/BF82 excluded by fixed-closure traps).
xresolve window rule (lift.py): for banknum 0-6, a 0x8000-0xBFFF target with no same-bank amap entry resolves to None (trap). Rationale: with bank B mapped, jsr $8xxx always runs bank B's bytes; a dropped same-bank group means data/undoc, and falling through to another bank's same-named code is silent wrong-bank execution (observed: bank0 LB2C1/L93BB -> real bank6 code). Bank7 is exempt (its window is C000-FFFF; DEC2-to-BFE5/BFE8/BFF1 cross-bank intent is established by traces). Cross-call census (xcensus.py) confirmed all other TUs unaffected.
Regen recipe v5 (current): pass1 bank0 with old maps, gen_addr over 5 snips (pure-add check), pass2 all five banks in enforce + resume modes, combined_enf/combined_rs links, smoke rebuilds; re-verify make test + esc zero + esc snap + gameplay (2000-park NMI/zones) + title before commit.
Remaining dark regions (documented, not lifted): bank1 (single jmp-in-data, BRK-verified), bank2/3 BF53 (family copies calling JAM/slide data -- dead variants), bank0 8080/BFE5/BFF1 (data). Boss/area-4/6 execution remains unreached -- no blind tapes; a directed deep-dungeon run with position feedback is the next hunt if boss coverage is wanted.
## Small-base ,y is always absolute (DONE 2026-11-09 -- LD981 -10/row)

The 6502 has no zp,Y form for STA/LDA/CMP/AND/EOR/ORA/ADC/SBC (only LDX has zp,Y; STX has zp,Y but no abs,Y).
A small base with ,y is ALWAYS absolute (3 bytes, abs,Y timing). The lifter treated small-base ,y
stores/loads as zero-page: the LD981 copy loop (`sta $25,y`, 10 iters/row) was charged 4 instead of 5
cycles/iter = -10 per DC-row (found by $2000-write watch + $06-span analysis: exactly 10 short per row,
call counts matching; ROM proof D983 = `99 25 00` = STA abs,Y). Census of all 59 small-base indexed sites
in the 5 snips vs ROM opcodes: 8 STA abs,Y + 5 LDA abs,Y sites wrong; every small ,x confirmed zp;
`stx $EA,y` confirmed zp,Y (0x96); `L0000,x` confirmed zp. Fix: `sta ,y` always 5 cycles;
LDA-family zp+Y uses the abs cross-page formula; op_len returns 3 for sta/lda/cmp/and/eor/ora/adc/sbc
small ,y. RD/WR addresses unchanged.
## Sample-after-charge: loads read before charging cycles (DONE 2026-11-09 -- reset-phase -2)

The tracer samples memory (RD) BEFORE charging the instruction's cycles; the lifter emitted
`cycles += N; RD(addr)`. For straight-line code the totals match, but observable timing differs at
polling edges: the PPU-warmup double spin (LF250/LF255 `lda $2002 / bpl`) exits one iteration
later/earlier depending on order, worth -7 cycles here. Combined with the unmodeled 9-cycle reset
fetch (FFF4 INC + FFF7 JMP F23B; reset vector FFFC=FFF4 -- G started cycles=0 at b7_entry_F23B,
skipping 9 cycles), the boot entry offset was a flat -2 (proven by HIT-vs-proftrace boot pairing,
4550 pairs, flat deltas; the +5 advance-mean was a logger artifact: phaseG stamps G4_advance =
E936 entry + 5). Fix: LOAD_SWAP_OPS (LOAD_OPS + bit/cpx/cpy) emit the body before the charge;
pointer-fetch `_cycpp` line of (zp),y stays first; stores/RMW untouched (order-irrelevant); +9 reset
cycles modeled (`cycles = 9` at driver init). Boot pairing flat +0 over 4550 pairs after both.
## Branch page-cross compares (PC+2), not the opcode address (DONE 2026-11-09 -- 17 sites, D418 -1/group)

Hardware charges a taken branch +1 iff the TARGET page differs from the (PC+2) page, where PC+2 is
the address after the 2-byte branch instruction. The lifter compared the OPCODE address page
(cur_addr) with the target page. These differ only when the branch opcode sits at XXFF (last byte
of a page): then cur_addr is in page XX but PC+2 is in page XX+1. Consequences, both directions:
overcharge (+1) for forward branches at XXFF into page XX+1 (e.g. BEQ D3FF->D418: opcode D3FF page D3
vs target D4 claimed cross; PC+2=D401 page D4 = no cross; G charged 4, HW 3 -- this was the
measured -1-per-D418-group: 3 groups/park = -3/park for G in the D418 segment); undercharge (-1)
for backward branches at XXFF back into page XX (e.g. BMI F6FF->F6F8 loop: claimed no-cross, true
cross since PC+2=F701 is page F7). Fix (lift.py + lift_g4.py, identical one line):
`_px = 1 if ((cur_addr + 2) & 0xFF00) != (_tgt & 0xFF00) else 0`.
Regen diff is exactly the affected sites (bank7t 7, bank6 6, bank4 4, banks 5/0 clean -- 17 sites:
16 overcharges + 1 undercharge), ROM-verified at both exemplars. Full 22800-park run bit-exact
(22748 common frames, 0 differing; E936 deltas within +-100 everywhere; 0 HW NMI frames missing).

## Tape-free completion verdicts (2026-11-11 -- no traces used)
Static census from committed `disasm/asm/` + single-byte ROM reads:
Code ranges prg0:12 prg1:1 prg2:1 prg3:3 prg4:100 prg5:9 prg6:108 prg7:107.
Combined TU carries 8 `__builtin_trap` sites, each with a static verdict:
b7_L0000 + vec-dispatch default (unreachable by construction, zero hits in
22800-park runs); b7_LEB91 (NMI-return tail; sole static caller EB8A sits
past a never-returning jsr LEB98, taken path falls through from LEB8D);
b5_entry_B2C5 (bank5-window data; the 9 prg4.s `jsr B2C5` callers resolve
same-bank to the real b4_entry_B2C5); b0_L93BB/LB2C1/LB2F3/LB310 (bank0
dark-family data callees, callers zero-exec). Dark regions: bank1 8630
(zero callers), bank2/3 BF53 (zero callers each), bank0 8080/BFE5/BFF1
(jmp-into-data). No engine change; bosses/late areas are lifted but
unplayed (frontend L7 covers with real input). APU capture is L2 adapter
work (event log from the NES APU spec + bank5 TU), not re-lifting.
