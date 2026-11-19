# Manual DC51 cycle fix (TAS wall-8566 frame miss)

## Symptom
Full 110003 wall-indexed run on clean engine (recomp d84fab4): first
player-pos divergence at wall 8574 (0481/0483 enemy slot 9 spawned in
port, never in Mesen), rooted at wall 8566: port 0100 spawn-kinds
clobbered because NMI#8567 entered with S=0x01 (PHAx3 prologue hit
0101/0100/01FF). No stack leak (all 1761 JSR + PHA/PLA/PHP/PLP
balanced; sim0 tracks 8560-68 exactly). Main 8566 ran +3275 cycles long
(28141 vs 24870), missing E936 before the scheduled NMI, so 12.7 stayed
0 and NMI#8567 took the short EC51 path (1591 vs 4864).

## Root cause
b7_entry_DC51 double-charges the EOR/AND pair. ROM bytes at DC51
(a5 39 4a b0 0e a5 39 45 05 29 02 f0 06 ...): lda 39 / lsr / bcs /
lda 39 / eor 05 (3cy) / and 02 imm (2cy) / beq ... Lifted gen charged
EOR zp as 3 AND an extra 3 with no instruction between (8 for the pair
instead of 5): OVERCOUNT +3 per DC51 call that reaches the EOR (BCS
not-taken, i.e. 39 even).
Probe (cycle-neutral dbg_ev, direct ram array read, no RD PPU
perturbation): DC51 ran 9x at wall_no 8566, all with 39=0 (even),
so +27 cycles. 39 is constant for the frame (LD908 stx 39 once, X=0
path via LD8FE/LD908/LD943/D95E/LD975). 9x3 = 27, the razor-edge miss.

## Proof
- ROM bytes (bank7 PRG, base DC51): a5 39 4a b0 0e a5 39 45 05 29 02
  f0 06 a5 39 f0 1f d0 36 ... (single 45 05, single 29 02).
- Hand count: EOR zp=3, AND imm=2, total 5. Gen charged 8.
- Fresh lift.py on dc51.snip (this dir): EOR single +3, AND +2 (see
  out_off.c / out_enf.c heads). Gen differs by exactly the duplicate
  pair; all other cycle lines in DC51/LDC64/LDC81/LDC9A are identical
  between fresh lift and gen (poll-placement drift from the fb5ba78
  boundary-poll fix is deliberately left untouched here).
- Probe DC51 39 log (F1.61, wall_no-tagged): wall_no 8566 n=9
  vals all zero. No other wall in 8564-68 runs DC51.
- Inner-piece cross-check (F2 92001-92007, wall_no 8566): E74D 2x125
  (59+66 ROM-exact, one BEQ taken one not), F19B 2x94 (47 ROM-exact),
  LDCDD 33x429 (13 ROM-exact early-exit), D9AF 4x272 (68), D9D3 8x512
  (64), D9F5 16x960 (60), F1BC 1x26 (ROM 26; its old SBC-missing plus
  ORA-double pair nets zero and is left alone). DA15 6195 and the
  LD908 chain 755 are otherwise ROM-clean, so DC51 +27 is the gap.

## Fix
Delete the duplicate cycles line plus its nmi_poll line between the
EOR block and the AND block in b7_entry_DC51, in both
gen/combined_off.c and gen/combined_enf.c. wp_fix_DC51.py anchors on
the exact 6-line buggy block (asserts count 1 per file) and replaces
it with the 4-line fresh-lift-verbatim block. Poll placement elsewhere
untouched (fb5ba78 migration out of scope).

## Regen recipe
1. lift.py dc51.snip (this dir) with entries
   entry_DC51,LDC64,LDC81,LDC9A plus stub entry_DC47, ADDRMAP/PROV/JMPTAB,
   UNWIND off (out_off.c) and enforce (out_enf.c). Confirm EOR head is
   single-charge.
2. python3 wp_fix_DC51.py (asserts plus splices both gens).
3. gcc -fsyntax-only -Wall -Wextra clean on both gens.
4. Recomp commit, frontend ENGINE_PIN bump, tools/build_game.sh
   rebuild, full 110003 wall-indexed rescore: expect first-diff past
   8574 and badmarks collapse.
