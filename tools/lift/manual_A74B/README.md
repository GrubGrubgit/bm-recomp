# Manual vec007A entry: bank4 A74B (STA $50 tail twin of A74E)

## Why manual
A74B is 3 bytes before entry_A74E: the tail `STA $50; RTS` of a hidden
gap function (bytes 85 50 60 at ROM bank4 offset 0x1275b, ROM-PARITY-OK).
da65 decodes the gap as .byte, so the normal info-range regen can never
produce this entry (same reason as reverted-then-kept 9F5D family).

## Hardware legitimacy (not a 9C3B repeat)
- Computed +3 alternate: C9A4 derives base+3 when $15==0 (same family as
  the 2026-11-16 correction for 9C38/9C3B and 9F5A/9F5D). 0 static refs is
  EXPECTED for table+computed alternates, not evidence of bogosity.
- Body is `STA $50; RTS`: stores A, returns. No X/Y setup to skip (the
  9C3B condemnation was vec-path X garbage vs fallthrough X sprite index).
- Oracle: native probe on Mesen's exact input trajectory reaches it at
  probe-frame 4176 (game-time identical to Mesen wall 4180: slot0 type 1b,
  Y equal, X within one step). Mesen executes the ROM bytes there fine.

## Regen recipe
1. python3 lift.py manual_A74B/snip_A74B.s manual_A74B/out_off.c b4 entry_A74B "" ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt UNWIND:off
   (and again with UNWIND:enforce for out_enf.c). Reference outputs kept
   here; regen must match apart from the file header.
2. gen/bank4 off+enf: fwd decl + lifted body, sorted before A74E.
   gen/bank7t off+enf: fwd decl + case 0xA74B, sorted before A74E.
   (bank7t also gains the previously-missing A74E decl+case for record
   completeness; combined already had it.)
3. Rebuild gen/combined off+enf with the same splices (formula: runtime.h
   + bodies 7t,0,4,6,5); verify the ONLY diff vs prior combined is the
   A74B hunks. gcc -O0 -Wall -Wextra -c both: clean, traps stay 7/file.
