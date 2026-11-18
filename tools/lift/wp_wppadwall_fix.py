import os

RUNTIME = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift/runtime.h"
GEN = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen"
PGAME = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/probe/pgame.c"
PMAIN = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/probe/probe_main.c"

REPS_CORE = [
    # sample by completed-wall count, not edge count: boundaries at k*FRAME
    ("static uint64_t wall_no = 0;",
     "static uint64_t wall_no = 0;\n"
     "static uint64_t pad_wall = 0;\n"
     "static uint64_t pad_next = CYCLES_PER_FRAME;"),
    ("""    while (cycles >= nmi_next_edge) {
        wall_no++;
        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;
        nmi_next_edge += (uint64_t)CYCLES_PER_FRAME;
        if (reg2000 & 0x80) nmi_fire_now(f, site);
    }""",
     """    while (cycles >= nmi_next_edge) {
        wall_no++;
        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;
        nmi_next_edge += (uint64_t)CYCLES_PER_FRAME;
        if (reg2000 & 0x80) nmi_fire_now(f, site);
    }
    while (cycles >= pad_next) { pad_wall++; pad_next += (uint64_t)CYCLES_PER_FRAME; }"""),
    # strobe latch index
    ("uint64_t f = wall_no; uint8_t live = pad_sample_fn(f);",
     "uint64_t f = pad_wall; uint8_t live = pad_sample_fn(f);"),
    # strobe-held live read index
    ("if (pad_sample_fn) { uint8_t live = pad_sample_fn(wall_no); return live & 1; }",
     "if (pad_sample_fn) { uint8_t live = pad_sample_fn(pad_wall); return live & 1; }"),
    # NMI auto-sample index (equals edge frame at fire instant; unify the rule)
    ("if (pad_sample_fn) pad_bits = pad_sample_fn(frame);",
     "if (pad_sample_fn) pad_bits = pad_sample_fn(pad_wall);"),
]

for path in (RUNTIME, GEN + "/combined_off.c", GEN + "/combined_enf.c", PGAME):
    s = open(path).read()
    for old, new in REPS_CORE:
        assert s.count(old) == 1, "anchor in " + path + ": " + old[:50]
        s = s.replace(old, new, 1)
    open(path, "w").write(s)
    print("fixed " + path)

t = open(PMAIN).read()
old = "wall_no = 0; vbl_ack_wall = (uint64_t)-1;"
assert t.count(old) == 1, "pmain anchor"
t = t.replace(old, old + " pad_wall = 0; pad_next = (uint64_t)CYCLES_PER_FRAME;", 1)
open(PMAIN, "w").write(t)
print("fixed probe_main reset")

print("pad_wall fix ok")
