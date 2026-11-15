# Manual bank4 entry: 80C9 (dead KIL-terminated group)
80C9 was a harvested entry (no static callers, zero runtime hits) whose group
was EXCLed (80C9-80DE) because da65 emits the $34 DOP and $F2 KIL bytes as
.byte, which the lifter could not consume.
Lift support added (lift.py): gen_bank records gap VALUES (; gap N $xx...);
DOP $14/$34 + implied-operand fuses to cycles+=4; single-byte KIL emits a named
stub (bm_trap via patch_vendor) and everything after KIL in the entry is
skipped as dead data (KIL halts the CPU; post-KIL bytes can never execute).
Any other gap pattern fails loud. survey.py SUP fixed (sed/plp/cld were
already lifted; only the survey flagged them).
Snip truncates at the KIL (dead tail excluded, same output as full-regen
with dead-skip). Spliced per 9F5D precedent: ADDRMAP +80C9 4, PROV +entry,
bank4 off/enf decl+body, combined off/enf decl(x2)+body, patch_vendor 6->7.
Full-regen note: gen_bank will reproduce this body from the .s + new gap
support; the 80C9-80DE EXCL must then shrink to cover only the dead tail
(post-KIL bytes) or the lift will double-add ADDRMAP (gen_addr dup assert).
