# Manual vec007A entry: bank6 8A58 (TAS trap port-ff ~25240)

## Why manual
After the DC51 cycle fix (a4b71fb), the TAS-allbosses port runs clean
past the old wall-8574 fork and traps vec007A-unmapped at ff ~25240
(code 0x8a58, same b7_LC987 enemy-loop dispatch chain, direct dispatch).
First new coverage since the 8BFD trap at ff ~53861 on the old engine.

## ROM decode (bytes verified vs ROM, bank6 = 8K bank 12)
Bank6 8A58 bytes: 4c 65 8a 20 28 cd d0 02 e6 46 4c ad d1 60 ...
8A58 is JMP 8A65; 8A65 holds 60 (RTS) closing the 8A5B L8A62 tail
(JMP D1AD at 8A62). So 8A58 is a return-only trampoline (JMP 3cy +
RTS 6cy = 9cy). The disassembler leaves 8A58 as raw bytes
(.byte 4C,65,8A) with entry_8A5B starting after; neighboring .byte
60,4C,74,8A is the RTS plus the dead JMP 8A74 at 8A66.
(Bank4 at 8A58 is a 9-vector enemy table ending at 8A6C code; the trap
bank was proven 6 by swbank-ptr probe, ptr 0x204c0 = prg6 base 0x204b0
plus 0x10, same shape as the AC63 bank proof. Do not confuse with
bank4 8A6C, a different enemy init already lifted.)

## Lift
lift.py 8a58.snip OUT b6 entry_8A58 with ADDRMAP PROV JMPTAB,
UNWIND off (out_off.c) and enforce (out_enf.c). No stubs: L8A65 RTS
is local to the snip. Spliced body is the trampoline plus local RTS
(JMP 3cy, RTS 6cy). WANT is b6_entry_8A58 only. No pre-existing 8A58
under any name.

## Cases
vec007A bank6 guarded case for 8A58 only: if swbank equals prg6 run
the body, else trap (same convention as AC63).

## Regen recipe
1. lift.py as above (stub slot is empty string so ADDRMAP/PROV/JMPTAB
   plus UNWIND specs parse from argv 6).
2. wp_wp8A58.py splices decl (both decl regions), body (ahead of
   8A5B), case (after 8A31) into gen combined off/enf; plus ADDRMAP,
   PROV_ALL, vec007A bank6 slot.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.
