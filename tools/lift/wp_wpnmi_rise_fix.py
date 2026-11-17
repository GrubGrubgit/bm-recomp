import os

RUNTIME = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/runtime.h"
GEN = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen"
PGAME = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/probe/pgame.c"

# Hardware-grounded: /NMI is level-sensitive (vblank-flag AND enable bit7),
# CPU-edge-triggered. Enabling NMI mid-vblank (0->1 rise on $2000 bit7)
# while the flag is set pulls /NMI low -> NMI fires. The old model only
# sampled reg2000 at wall-edge polls, so a mid-vblank ON (Blaster Master
# f6811: OFF at vblank start, ON ~33cy after the LF1CC check) lost NMI 6821
# and forked (probe f6812 nd=57 cascade). Proven in probe: WR-rise fire
# heals 6811-6830 with BAD list byte-identical to force-fire, full-7638
# clean 6811-7329 except allowed 7064-7069 flickers.
OLD = "        if (r == 0) reg2000 = v;"
NEW = ("        if (r == 0) {\n"
       "            uint8_t old2000 = reg2000;\n"
       "            reg2000 = v;\n"
       "            if (!(old2000 & 0x80) && (v & 0x80)) {\n"
       "                if (nmi_armed && nmi_fire_fn && !in_nmi && in_vblank()) {\n"
       "                    nmi_fire_now(wall_no, \"WR2000-rise\");\n"
       "                }\n"
       "            }\n"
       "        }")

for path in (RUNTIME, GEN + "/combined_off.c", GEN + "/combined_enf.c", PGAME):
    if not os.path.exists(path):
        print("skip missing " + path)
        continue
    s = open(path).read()
    assert s.count(OLD) == 1, "anchor in " + path
    s = s.replace(OLD, NEW, 1)
    open(path, "w").write(s)
    print("fixed " + path)
print("nmi rise fix ok")
