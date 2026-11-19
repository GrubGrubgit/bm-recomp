# Manual vec007A entry: bank4 A58C (TAS trap port-ff ~6414)

## Why manual
After the A571/A574/A589 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=A58C (same b7_LC987 dispatch chain, direct dispatch). Single entry, no
+3 twin on the trap path.

## ROM decode (bytes verified vs ROM)
A58C: jsr A07B; flag-gated branches (P bit2/bit7) into the shared LA5xx tail
family (LA5EF/LA5C1/LA5AC/LA5AA/LA5BF/LA5BD/LA5DD/LA5D9/LA5DB - pre-existing
from earlier slices); mid-body fixed-bank jsr C03F/C012/C027/C00C/C0FF/C144/
C216 (auto-resolve to b7_) and jsr 9EB3 (pre-existing b4_entry_9EB3); local
immediates #$06/#$FA stored to $4C/$4D (transcription checked against ROM
bytes: STA $4C, not $06); continues through LA620..LA64D; ends rts.
No terminal fall-through: rts terminates its own region. The snip also
traces the jsr target A65A and its jsr target A667 (see below).

## A65A/A667 pre-existed - NOT re-ported
The first wp run listed b4_entry_A65A + b4_entry_A667 (snip entries at
a58c.snip:103/112), but gen already held behavior-identical bodies from
an older lift (b4_entry_A65A + b4_LA65C + b4_LA667, local-label style;
ADDRMAP + PROV canonical lines). Dropped the re-port: A58C body calls
the pre-existing b4_entry_A65A() as its jsr edge; shared LA5xx labels
resolve to pre-existing. Manual dedup removed the wp-inserted dup fwd
decls (b4_entry_A65A x2 per gen) and the dup ADDRMAP/PROV lines, so the
final diff is A58C-only (decls x2 sites + body + case 0xa58c + ADDRMAP/
PROV/vec lines). wp_wpA58C.py was corrected to WANT=[A58C] accordingly.

## Cases
vec007A bank4 guarded case for A58C only.

## Regen recipe
1. lift.py a58c.snip OUT b4 entries(A58C,A65A,A667) stub(A07B,9EB3)
with ADDRMAP PROV JMPTAB, UNWIND off (enforce for enf).
2. wp_wpA58C.py splices decl, body, case into gen combined off/enf
(anchored on the A589 batch); ADDRMAP, PROV_ALL, vec007A - A58C only.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
