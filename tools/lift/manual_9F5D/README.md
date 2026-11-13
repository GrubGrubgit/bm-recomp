# Manual vec007A entry: bank4 9F5D (enemy/Jason behavior site)

## Why manual
9F5D is the SECOND BYTE of ldx #$18 inside the 9F41 function (bytes
A2 18 | 20 DE C0 | 60). It is a live vec007A dispatch target (hit 2026-11-14:
Jason walking Area B, C971 slot loop -> C9A4 -> jmp (007A) with 7A=9F5D;
jsnes confirms the real game never takes this path on the same inputs, but the
site is a legitimate game code path, so it must be lifted).
da65 silently drops a LABEL placed mid-instruction, so the normal
info-range -> .s -> gen_bank regen can NEVER produce this entry. Do not try to
seed it in prg4_auto.info (verified: ROM-PARITY-OK but label vanishes).

## Regen recipe (bank4 / bank7t full regen + this patch)
1. Regen bank4 enf+off and bank7t enf+off with the standard recipe
   (gen_bank.py; bank4 EXCL covers the entry_80C9 group; bank7t EXCL covers
   LEBF4, FB10, FDA5; VEC/ADDRMAP/PROV/JMPTAB as in the last full-regen logs).
2. Re-apply this entry EXACTLY as follows (order matters, keep sorted order):
   - tools/lift/vec007A.txt bank4 line: insert 9F5D between 9E1D and 9F65.
   - tools/lift/ADDRMAP.txt: insert line 9F5D 4 entry_9F5D between the
     9F41 and 9F65 lines.
   - tools/lift/PROV_ALL.txt: insert line entry_9F5D 4 between the
     entry_9F41 4 and entry_9F65 4 lines.
   - Re-lift JUST this entry (machine codegen, do not hand-write):
     python3 lift.py manual_9F5D/snip_9F5D.s OUT b4 entry_9F5D LC0DE
     ADDRMAP:ADDRMAP.txt PROV:PROV_ALL.txt JMPTAB:JMPTAB.txt UNWIND:off
     (and again with UNWIND:enforce for the enf TU). Reference outputs are
     kept as manual_9F5D/out_off.c and out_enf.c - the regen must match them
     apart from the file header.
   - gen/bank4 off+enf: add fwd decl for b4_entry_9F5D between the 9F41
     and 9F65 decls; insert the lifted function body immediately before
     b4_entry_9F65.
   - gen/bank7t off+enf: add fwd decl between 9E1D and 9F65 decls; add
     case 0x9F5D between the 0x9E1D and 0x9F65 cases.
3. Rebuild gen/combined enf+off with the committed formula
   (runtime.h + bodies 7t,0,4,6,5 minus their include line, single joins)
   and verify the ONLY diff vs the pre-entry combined files is the four
   9F5D hunks per file.
4. gcc -O0 -Wall -Wextra -c both combined files: must be clean;
   builtin_trap count must stay 7 per file.
