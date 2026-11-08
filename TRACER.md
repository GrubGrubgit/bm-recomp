# Headless tracer -- design (next build step)

Problem (confirmed by tools/survey.sh): decoded code holds 0 JMP-indirect
targets and almost no bank-switch writes. Static descent stops at every
JMP ($xxxx) and every bank boundary. Fix per plan: runtime traces
(PC + active PRG bank) from a headless C emulator core compiled in Termux,
then feed exact targets/bank states back into ../disasm as entries.

Core (own code, in tools/trace/): minimal 6502 CPU (all documented opcodes;
undocumented trap-and-log), MMC1 (shift register, PRG 16KB mode, CHR modes),
PPU stub ($2002 vblank bit on a cycle counter, $2000/$2001 latches, $4014
DMA as memcpy to stub memory, 2KB VRAM backing, no rendering), APU stub
(writes ignored, $4015 reads return idle bits), controllers ($4016/$4017
shift from a scripted input tape: power-on, wait N frames, press
start/d-pad to walk menus and first areas).

Log format (binary, tools/trace/log.h): per-instruction 4 bytes PC + 1 byte
PRG bank at $8000 (or log on bank-switch + indirect-jump events only --
decide by size; full log is about 72KB per frame, fine for minutes).
Consumer tools/tracefeed.py maps trace records to new disasm entries
(JMP-indirect target + bank state at execution) and reruns rebuild.sh.

Success metric: static coverage percent per bank + count of resolved jump
table slots. Fallback if own core stalls: port a stripped QuickNES core.
## Edge-record semantics (2026-11-07 fix)
Edge src is the TRUE insn address for all types. (Was: JSR/JMP/JMP-ind
logged insn+1 because the opcode fetch had already advanced PC; fixed with
PC - 1 in those three cases. Implied-op edges were always correct.) All
logs generated before the fix are stale for JMP-ind vector resolution only;
they were regenerated. Lesson: any future edge consumer must treat src as
the opcode address (vector pointer operand lives at src+1/src+2).
## First real indirect dispatch found (edgeplay, 36000f)
Fixed-bank code at C9D2 runs JMP (007A): pointer in ROM, target is a
zero-page RAM vector. With bank6 mapped it dispatches to 6 bank6 routines
(8124/8127/815C/815F/92DB/92DE, first seen ~frame 1500). This is the
pattern the tracer was built for: static analysis can never resolve a RAM
vector, only runtime edges can. tracefeed reports such sites as RAM@addr.
## Pad-register fix (2026-11-08, the big one)
mem_rd shared ONE pad_pos counter for $4016 and $4017 while the game
reads them ALTERNATELY ($4016,$4017,$4016,...). Result: P1 received only
EVEN pad bits (A,Select,Up,Left), P2 got ODD bits (B,Start,Down,Right).
Symptoms were bizarre: LEFT started the game (only P1-visible button with
an effect on title), Start/Right/Down/B did NOTHING, tank frozen in Area 1
(P1 input stuck at title-era value), false "auto-start" (attract timer),
and a wild goose chase through boot timing. Fixed with separate
pad_pos1/pad_pos2, both reset on strobe -- verified: Start@500 begins the
game, tank drives, scroll moves, every frame differs. LESSON: when facing
unexplained input behavior, diff the pad path against hardware FIRST
(separate shift registers per port, strobe resets both, unread bits read
as 0 here). Old logs (trace0/trace1/edge0/edgeplay/edgeA-D) are STALE
(inputs meant different buttons) and must be regenerated.
## PPU upgrade (same day)
$2000/$2002/$2005/$2006/$2007 now behave (scroll regs, PPUADDR latch,
buffered PPUDATA, palette, horizontal mirroring, $2002 latch reset).
CHR-ROM loaded. -r snapshots extended to 4160B (ram+vram+64B footer with
pal/scroll/reg2000). CPU behavior verified unchanged (600f no-input run
is bit-identical: 5815190 insns, final $EC70). snap2png.py renders
snapshots with the real CHR (grayscale) -- this gave us EYES.
## -w CLI footgun (2026-11-08, fixed)
-w LO consumed the NEXT arg as HI whenever it did not start with dash,
so -w F7 plus tape silently ate the tape path as HI (=0, range F7..00
never fires, no tape loaded line). Fixed: HI is consumed only if the next
arg fully parses as hex (strtol endptr check); tape paths contain slash so
they are left alone. Verified: -w F7 plus tape now loads the tape and
fires (24144 hits on sL run, ROL F7 at E929 writes 02 under Left).
Lesson: optional numeric args must validate before consuming; always
check for the tape loaded line on stderr when a watch run is silent.
