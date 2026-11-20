# Manual b4_L8A69 phantom-tail fix (TAS wall-7127 $27=00 fork)

## Symptom
Full 110003 wall-indexed rescore on recomp 7429a3f (LA100 fix): first fork
wall 9676 (mark nd, $300-7FF only); dense presnap 7100-7160 vs Mesen shows
the true first gameplay fork at wall 7127: zp $27 (port 00 vs Mesen 8D) +
$3D (38 vs 2C) + OAM $200-237 (49B) + stack echo; hi ($300+) exact.
w=7126 exact except benign $1E4+ stack residue. $3D heals by 7136; OAM
settles to a stable 67B shape; $27 persists (pointer ($1B)=$0027 clobbered).
Slot-0 LC9AE reads $15=0x40 in port (skip path -> vec 8A69 -> L8A69 STIND),
while Mesen preserves $27=8D (increment path -> vec 8A6C). $15 END=0x40 in
BOTH engines at 7126, so Mesen must dispatch 8A6C with $15==0 at slot-0:
either Mesen clears $15 first (no clearer runs in port: WR-hook complete,
no LC334/LCE08; pops F7/F8/FD proven balanced PHA/PLA pairs in LE633 and
LC9AE, RD-hook proves zero $1E4+ reads) or the two vec targets differ
functionally. They do: tag250 STIND ($1B,Y) fires ONLY on the 8A69 path.

## Root cause (ROM-byte-verified, no oracle needed)
Bank4 CPU $8A69 bytes: EA EA EA A9 18 85 40 A9 10 85 41 ... = 3x NOP then
byte-identical to $8A6C (A9 18 85 40 ... A5 51 4A 4A AA E0 18 90 02 A2 17
BD A3 8A 18 69 1B 4C 63 C0 ...). The gen lift of b4_L8A69 renders the tail
as X=RD($8901) / LDA $86A3,X / LDA ($86,X) / STA ($1B),Y, but the byte
patterns AD 01 89 / BD A3 86 / A1 86 / 91 1B occur NOWHERE in the entire
128K PRG (full byte scan; the lone 91 27 at bank2:$9404 is tilemap data).
Donor b4_entry_8A6C correctly renders TAX / LDA $8AA3,X / CLC / ADC #$1B /
JMP C063, matching ROM. The phantom STA ($1B),Y writes A=00 to [($1B)] =
$0027 (self-pointer: ($1B) holds $0027 at slot-0), zeroing $27; the $3D/OAM
fork follows via the LEC9B copy-window shift ($3D delta $0C = 12 OAM slots).
Introduced in fork1-4d (a5181c5); tick-proven only through f7329 frames and
never byte-audited against ROM.

## Proof (device ~/w72p probes, binding-safe, no ROM in app)
- WR-hook ($27/$3C/$3D/$7A/$7B/$15/OAM): the ONLY $27 write in 7126-7127 is
  the tag250 STIND at main#7127 c=212248423 (_cycpp=0027 Y=0 A=00), inside
  slot-0 L8A69 after its C11A/D1EF; 7126 slot-0 (vec 8A6C) executes no STIND.
- vec log: 7126 slot-0 _v=8A6C, 7127 slot-0 _v=8A69; LC9AE $15 reads 0 then
  0x40 (port); Mesen END states force $15==0 at its 7127 slot-0.
- Pops F7/F8 = LE633 restores of LE61B PHA(X)/PHA(Y) (vals 0x40/0x7A match
  pushes, balanced); FD = LC9AE PLA of its PHA(X) (0x40). No residue reads.
- Fresh lift.py on snip_8A69.s (this dir) reproduces the CORRECT tail only
  (TAX, $8AA3, ADC #$1B; zero phantom markers); the buggy shape is asserted
  from the gen lift (forkfix), never hand-tuned.

## Fix (OFF + ENF, overlap-twin pattern)
- New b4_L8A69 body = 3x NOP (EA EA EA, 6 cycles, lift-rendered as ;-units)
  + b4_entry_8A6C body verbatim with b4_entry_8A6C -> b4_L8A69 (polls +
  decl; goto labels b4_LB8Axx are function-scoped, no clash).
- ENF same shape (its donor has identical correct tail + unwind guards).
- gcc -fsyntax-only -Wall -Wextra clean on both gens.

## Regen recipe
1. lift.py snip_8A69.s (this dir): python3 lift.py manual_8A69/snip_8A69.s
   manual_8A69/out_off.c b4 L8A69 entry_C0FF,entry_93BD,entry_C11A,entry_C063
   - confirm correct tail (TAX/$8AA3/ADC $1B, no $8901/$86A3/($86/($1B).
2. python3 wp_fix_8A69.py (asserts phantom in L8A69 + correct donor 8A6C,
   splices gen/combined_off.c + gen/combined_enf.c only).
3. gcc -fsyntax-only -Wall -Wextra clean on both gens.
4. Recomp commit, frontend ENGINE_PIN bump, tools/build_game.sh rebuild,
   full 110003 wall-indexed rescore: expect 7127 fork healed (and the 9676
   mark fork with it, since ($27)=$AE8D is restored for DA3C/LDAF7).
