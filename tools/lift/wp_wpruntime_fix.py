p = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/runtime.h"
s = open(p).read()

# FIX-A: $2002 read clears the vblank flag for the rest of the wall
# (hardware behavior; old model kept it set till wall end, so reset
# warmup waits finished in <1 wall and the port ticked from wall 1
# while hardware/Mesen ticks from wall 3).
old_vbl = ("static inline __attribute__((unused)) int in_vblank(void) {\n"
           "    return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;\n"
           "}")
assert s.count(old_vbl) == 1, "vbl anchor"
new_vbl = ("static uint64_t wall_no = 0;\n"
           "static uint64_t vbl_ack_wall = (uint64_t)-1;\n"
           "static inline int in_vblank_raw(void) {\n"
           "    return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;\n"
           "}\n"
           "static inline __attribute__((unused)) int in_vblank(void) {\n"
           "    return in_vblank_raw() && (wall_no != vbl_ack_wall);\n"
           "}")
s = s.replace(old_vbl, new_vbl, 1)

old_r2 = ("            uint8_t v = 0;\n"
          "            if (in_vblank()) v |= 0x80;")
assert s.count(old_r2) == 1, "r2 anchor"
new_r2 = ("            uint8_t v = 0;\n"
          "            if (in_vblank_raw()) { v |= 0x80; vbl_ack_wall = wall_no; }")
s = s.replace(old_r2, new_r2, 1)

# FIX-B: count walls per crossed NMI edge; strobe latch + strobe-held
# live read index by wall count, not the cycle counter (which keeps
# burning through NMI-off walls while the wall counter stalls, so the
# cycle index drifts ahead and pad edges land on the wrong walls).
old_edge = ("    while (cycles >= nmi_next_edge) {\n"
            "        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;")
assert s.count(old_edge) == 1, "edge anchor"
new_edge = ("    while (cycles >= nmi_next_edge) {\n"
            "        wall_no++;\n"
            "        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;")
s = s.replace(old_edge, new_edge, 1)

old_strobe = "uint64_t f = cycles / (uint64_t)CYCLES_PER_FRAME; uint8_t live = pad_sample_fn(f);"
assert s.count(old_strobe) == 1, "strobe anchor"
s = s.replace(old_strobe, "uint64_t f = wall_no; uint8_t live = pad_sample_fn(f);", 1)

old_live = "if (pad_sample_fn) { uint8_t live = pad_sample_fn(cycles / (uint64_t)CYCLES_PER_FRAME); return live & 1; }"
assert s.count(old_live) == 1, "live anchor"
s = s.replace(old_live, "if (pad_sample_fn) { uint8_t live = pad_sample_fn(wall_no); return live & 1; }", 1)

open(p, "w").write(s)
print("runtime.h FIX-A/B ok")
