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
