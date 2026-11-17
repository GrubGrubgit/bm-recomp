import os

LIFT = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift"
os.makedirs(os.path.join(LIFT, "manual_A74B"), exist_ok=True)

# 1. snip (da65 drops mid-gap labels, so manual snip like 9F5D; machine codegen only)
snip = "entry_A74B:\n        sta     $50\n        rts\n"
p = os.path.join(LIFT, "manual_A74B", "snip_A74B.s")
open(p, "w").write(snip)
print("snip written")

# 2. ROM parity: bank4 (prg[4]) file offset 16+4*16384+(0xA74B-0x8000); expect 85 50 60
rom = open("/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/roms-dev/blaster-master-usa.nes", "rb").read()
o = 16 + 4 * 16384 + (0xA74B - 0x8000)
have = rom[o:o + 3].hex()
assert have == "855060", "ROM parity: %s" % have
print("ROM-PARITY-OK at file offset %s" % hex(o))

# 3. maps (sorted inserts; 9F5D/9C3B reverted so A74B slots before A74E)
v = os.path.join(LIFT, "vec007A.txt")
s = open(v).read()
old = "9FBA A74E AFBC"
assert s.count(old) == 1, "vec anchor"
s = s.replace(old, "9FBA A74B A74E AFBC", 1)
open(v, "w").write(s)

a = os.path.join(LIFT, "ADDRMAP.txt")
s = open(a).read()
old = "A74E 4 entry_A74E\n"
assert s.count(old) == 1, "addrmap anchor"
s = s.replace(old, "A74B 4 entry_A74B\n" + old, 1)
open(a, "w").write(s)

r = os.path.join(LIFT, "PROV_ALL.txt")
s = open(r).read()
old = "entry_A74E 4\n"
assert s.count(old) == 1, "prov anchor"
s = s.replace(old, "entry_A74B 4\n" + old, 1)
open(r, "w").write(s)
print("maps updated")

# 4. README record
readme = """# Manual vec007A entry: bank4 A74B (STA $50 tail twin of A74E)

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
"""
open(os.path.join(LIFT, "manual_A74B", "README.md"), "w").write(readme)
print("setup A74B ok")
