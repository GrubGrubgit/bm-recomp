import os
LIFT = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift"
os.makedirs(os.path.join(LIFT, "manual_B70F"), exist_ok=True)
snip = "entry_B70F:" + chr(10) + "        eor     $2B20" + chr(10) + "        clv" + chr(10) + "        jmp     entry_B713" + chr(10)
open(os.path.join(LIFT, "manual_B70F", "snip_B70F.s"), "w").write(snip)
print("snip written")
rom = open("/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/roms-dev/blaster-master-usa.nes", "rb").read()
o = 16 + 6 * 16384 + (0xB70F - 0x8000)
have = rom[o:o + 4].hex()
assert have == "4d202bb8", "ROM parity: " + have
print("ROM-PARITY-OK at file offset " + hex(o))
v = os.path.join(LIFT, "vec007A.txt")
s = open(v).read()
old = "B6E7 B6F7 B835 B843 B846"
assert s.count(old) == 1, "vec anchor"
open(v, "w").write(s.replace(old, "B6E7 B6F7 B70F B835 B843 B846", 1))
a = os.path.join(LIFT, "ADDRMAP.txt")
s = open(a).read()
old = "B710 6 LB710" + chr(10)
assert s.count(old) == 1, "addrmap anchor"
open(a, "w").write(s.replace(old, old + "B70F 6 entry_B70F" + chr(10), 1))
r = os.path.join(LIFT, "PROV_ALL.txt")
s = open(r).read()
old = "entry_B713 6" + chr(10)
assert s.count(old) == 1, "prov anchor"
open(r, "w").write(s.replace(old, "entry_B70F 6" + chr(10) + old, 1))
print("maps updated")
import subprocess
for mode, out in (("off", "out_off.c"), ("enforce", "out_enf.c")):
    cmd = ["python3", "lift.py", "manual_B70F/snip_B70F.s", "manual_B70F/" + out, "b6", "entry_B70F", "entry_B713", "ADDRMAP:./ADDRMAP.txt", "PROV:./PROV_ALL.txt", "JMPTAB:./JMPTAB.txt", "UNWIND:" + mode]
    rr = subprocess.run(cmd, cwd=LIFT, capture_output=True, text=True)
    print(rr.stdout.strip(), rr.stderr.strip()[-500:] if rr.stderr else "")
    assert rr.returncode == 0, "lift failed " + mode
print("lift ok")
