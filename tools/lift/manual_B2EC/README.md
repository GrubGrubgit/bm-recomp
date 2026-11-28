# Manual vec007A entry: bank6 B2EC (type-125 direct-path thunk to B308)

## Why manual
Port trapped vec007A-unmapped v=B2EC swbank=6 at user movie frame 2521
(area 8 dungeon L1, slot 15 actor type 125 = 0x7D). Bank6 behavior table
word[125] at $8002+2*124 holds B2EC; LC9AE $15-path adds +3 only when
$15==0, here the direct vector B2EC was computed. B2EC was never observed
by edge/St tracers (only the +3 twin B2EF was), so vec007A.txt had no
case and the lift never seeded it. Same coverage-gap family as
BD5C/BD5F (bank4 spitter) and B4A3/B58B (bank6 trampolines).

## ROM decode (bank6, 3 bytes B2EC-B2EE; disasm marked ByteTable)
B2EC: 4C 08 B3 = JMP $B308 (direct-path thunk; +3 twin B2EF is the init
path: LDA #$80 STA $42/$43 ... and is already lifted as b6_entry_B2EF).
B308 body already exists in the build (b6_entry_B308, reached via other
paths), so the B2EC body is just the thunk. Off/enf identical (no JSR,
no unwind wraps), matching the B4A3/B58B trampoline shape byte for byte
(double nmi_poll, cycles += 3, call + return, dead fallthrough tail).

## Hardware legitimacy
JMP $B308 is unconditional ROM code on the taken path: the game computed
B2EC from its own behavior table (type 125 verified in ROM table at
bank6+2: word[125]=B2EC) with the actor live in slot 15. Mesen executes
the same bytes. User movie bmbug-f2521 replays the trap headless x2
(enhanced+saves on, matching the user log) before the fix.

## Cases
vec007A bank6 plain case for B2EC (bank6-only address, no bank4
collision, same guarded/plain convention as B2EF).

## Regen recipe
1. lift.py b2ec.snip OUT b6 entry_B2EC entry_B308 ADDRMAP PROV JMPTAB
UNWIND off (and enforce for out_enf.c). Reference outputs here.
2. wp_b2ec.py splices decls (both decl blocks, sorted), body (before
B2EF body), case (before B2EF case) into gen combined off/enf;
ADDRMAP (B2EC after B2EB line); PROV_ALL (entry_B2EC after entry_B2DB);
vec007A bank6 line (B2EC between B2AB and B2EF).
