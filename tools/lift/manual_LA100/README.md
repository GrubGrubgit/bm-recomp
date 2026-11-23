# Manual LA100 2-level unwind (TAS wall-7126 first gameplay fork)

## Symptom
Full 110003 wall-indexed rescore on recomp e8254b1: exact through wall
7125 (pre-phase first=7299; post-phase first=1801 RAM-only), first real
gameplay fork at wall 7126: nd=68 (ndNo1E4) vs Mesen f=7126 =
$03D,$05D-5F (port 5,21,37 vs 0F),$0FD (232v168),OAM $2A4-2F3,
$618,$61B,$61C-62F (10B sprite staging),$655-657. Persists 7127+.
$10/$11/$14/$15/$45/$46/$470/$03FD/$F1/$FC/$4F/$51/$53 END-equal.

## Root cause
Bank4 LA100 ends `pla, pla, rts` (ROM bytes at $A100:
`20 0e c1 20 72 a0 0d fb 03 8d fb 03 a9 5a 85 46 a9 00 20 1a c1
68 68 60` = JSR C10E, JSR A072, ORA/STA $03FB, LDA#$5A/STA $46,
LDA#$00, JSR C11A, PLA, PLA, RTS). LA100 is reached by BRANCH
(LA0A3 BCS, $03FD INC-to->=$80: first wall ever at 7126 with
$10=232 even), so the stack holds [RET_C9A4-caller][RET_A07B-caller]:
the PLAs pop the JSR-A07B return and the RTS pops the JSR-C9A4 return,
resuming in b7_LC987 right after its JSR C9A4 (which then runs LC928 +
EC73 + loop). It is an INTENTIONAL routine transition-skip, same class
as fork9's L9434 (and the flagged-twin LA100 noted in the fork4
writeup). The lift renders the tail as two S+=1 pops plus a plain C
`return`, which returns into A07B/A58C and runs the whole tail
(A65A anchor, $03FD/$4F/$53 gates, C144/C216, LA63E, 9EB3 deploy,
$FD=232) that HW skips (Mesen: no deploy, $FD stale 168, $61x stale,
$470=90 via the caller-side LC928 writeback).

Callers of A07B (all vec-JMP-entered, so every unwind lands in the same
LC987-after-C9A4): b4_entry_A58C, b4_entry_970F, b4_entry_9B67.
C9A4 ends `jmp (L007A)` (no push, no epilogue), so the landing is exact.

## Proof (device ~/w72 probes, binding-safe, no ROM in app)
- S6 (forced `return` after C0FF at wall 7126): ndNo1E4 = 0 vs Mesen.
- Principled fix (this patch, counter + landing split): ndNo1E4 = 0 at
  7126, walls 7118-7126 all exact, 7125 still exact. CR trace: A07B
  entered but never returned at 7126 (unwind fired); 9EB3 never entered.
- Cycle-neutral (no added cycles+=, same polls) and S-neutral (explicit
  S math: -2-2+4=0 at landing; ENF-style S accounting holds; no
  NMI-S-DRIFT across the walls). uw counter (not boolean): multiple
  slots can unwind per frame; each LC987 resume consumes exactly one.
- Fresh lift.py on la100.snip (out_off.c, this dir) reproduces the buggy
  tail (PLA,PLA,plain return); only the tail shape is asserted from it,
  poll placement intentionally untouched (post-fb5ba78 drift out of scope).

## Fix (OFF only, fork9 uw_9434 pattern)
- `int uw_LA100;` decl (counter).
- LA100 tail: keep PLA,PLA (+4cy each), add RTS-pop `S += 2`, set
  `uw_LA100++`, plain return (resumes in the A07B caller via the
  musttail-replaced frames).
- check-1 in the three A07B callers (A58C/970F/9B67): after the A07B
  call, `if (uw_LA100) { b7_LC987_after_C9A4(); return; }` (skips the
  S+=2 whose bytes HW popped, runs the HW tail immediately so later
  slots observe HW-identical intermediate state).
- LC987 after its C9A4 call: `if (uw_LA100) { uw_LA100--;
  S += 2; b7_LC990_EXIT(); return; }` (C-stack resume after the forward
  chain returns: skip the already-run tail, exit the slot loop; S resync).
- New `b7_LC987_after_C9A4` = LC987 tail verbatim (LC928 + EC73 +
  LC990 call); new `b7_LC990_EXIT` = loop-exit verbatim (STA $4F + RTS).
- ENF untouched (fork9 precedent: ENF aborts loudly on unmodeled
  unwinds by design via UNWIND-ESCAPE).

## Regen recipe
1. lift.py la100.snip (this dir): `python3 lift.py \
   manual_LA100/la100.snip manual_LA100/out_off.c b4 LA100 \
   LC10E,entry_A072,LC11A UNWIND:off` - confirm buggy tail shape.
2. python3 wp_fix_LA100.py (asserts + splices gen/combined_off.c only).
3. gcc -fsyntax-only -Wall -Wextra clean on both gens.
4. Recomp commit, frontend ENGINE_PIN bump, tools/build_game.sh rebuild,
   full 110003 wall-indexed rescore: expect first-fork 7126 -> 7127
   (next hunt: ty90-dispatch path, OAM/sprite-shaped, $27/$3D/$200+).
# LA100 v2 appendix (stranded-resume guard; TAS wall-7126 fork, Nov 2026)

## Why v1 was not enough

v1 (`uw_LA100` flag, commit 7429a3f) fixed the landing: LA100 tail does the
RTS-pop (`S += 2`, `uw_LA100++`) and the three A07B callers redirect to
`b7_LC987_after_C9A4` (tail runs once, in the right place, later slots see
HW-identical state). But the ORIGINAL `LC987` resume -- reached when the C
stack unwinds back through the dispatch chain -- still executed its
unconditional `S += 2`, a spare +2 on top of the already-balanced slot.
Its two candidate treatments were both wrong (proven against the true-6502
emu and Mesen st-7125..7170):
- EXIT (`b7_LC990_EXIT`, skip the tail): missed a tail HW runs -- save/EC73/
  slot-increment skipped, spurious `C99F` + `STA $4F`, double-consumed entry
  slot. Same +2, plus game-state damage.
- continue (re-run `b7_LC987_after_C9A4`): spare tail, same +2.
Port frame net +2 vs Mesen at 7126 (Sold FD vs FD... offset persisted).

## v2: stranded-resume guard (this patch, `wp_fix_LA100_v2.py`)

Per-`LC987` sequence id + stranded-id stack. The `LC987` invocation whose
`C9A4` was unwound must skip BOTH its `S += 2` and its tail (the warp already
ran it via check-1); normal later `LC987`s (fresh ids, e.g. next slots run
inside the warp tail) run `S += 2` + tail as usual. `S += 2` MUST follow the
guard in both places.
- decl: `int uw_seq=0; int uw_sid[4]; int uw_sidd=0;` (kept next to
  `int uw_LA100;`). Depth 4: multi-unwind safe (nested warps drain LIFO;
 verified max depth in the 110003-frame TAS is below this).
- LA100 tail (after PLA,PLA): `S += 2;` (HW-true Sp) + `uw_LA100++` +
  `if (uw_sidd<4) uw_sid[uw_sidd++]=uw_seq;` (record youngest LC987 id).
- LC987 entry: `int my_lc987 = ++uw_seq;` (+ publish before the C9A4 call).
- LC987 resume replaces the v1 EXIT line:
  `if (uw_LA100) { search uw_sid[0..uw_sidd) for my_lc987; hit: swap-remove,
  uw_LA100--, return; }` then `S += 2;` + tail. Miss (normal later LC987)
  falls through to `S += 2` + tail.
- check-1 in the three A07B callers (A58C/970F/9B67) UNCHANGED (fires exactly
  when this chain warped: the LA100 tail just ran synchronously below it).
- New `b7_LC990_EXIT` from v1 is now unreferenced (kept, harmless).
- Cycle-neutral (no added `cycles+=`), S-neutral by construction.
- ENF untouched (fork9 precedent: ENF aborts loudly on unmodeled unwinds).

## Proof (device, binding-safe, no ROM in app)

- `~/emu65.py` true-6502 emu reproduces Mesen st-7126 EXACTLY from st-7125
  (REGSMATCH, RAMDIFF 0); handler pc-streams port-vs-emu identical (dedup
  ratio 0.9996); divergence is main-only => this fix's scope.
- Forensic: clean production tree (backup + fixppu + v2, zero TEMP) plus TEMP
  gates rebuilds to a pwalk log BIT-IDENTICAL (13.5MB) to the verified dev
  run: FIRE Sold=FD walls 7124-7130 = Mesen st-S; `verify7170.py` walls
  7100-7150 zero S divergences; port main S-runs 180/180 vs emu.
- Production: `-O3` FULL 110003 wall-indexed PRE rescore green, 0 badmarks,
  no unmapped-vector traps (see rescore log).

## Production recipe (OFF only)

1. base = `~/combined-9aee.bak` (has v1 + 9AEE/80C9/trims, no TEMP).
2. `python3 ~/fixppu.py` (HW-grounded $2000-landing fix; asserts anchors).
3. `python3 manual_LA100/wp_fix_LA100_v2.py` (asserts v1 shapes; 4 stages ok).
4. `gcc -fsyntax-only -Wall -Wextra` silent; `-O3` build; full rescore green.
5. TEMP (never committed): dbg_ev gates (789701/703/704/706/712/713 + quint +
   APU 789705), EA-inert (`ea_done`, wall 999999999), dbgev 4194304.
