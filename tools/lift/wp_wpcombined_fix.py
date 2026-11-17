GEN = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen"

REPS = [
    # FIX-A vblank def
    ("""static inline __attribute__((unused)) int in_vblank(void) {
    return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;
}""",
     """static uint64_t wall_no = 0;
static uint64_t vbl_ack_wall = (uint64_t)-1;
static inline int in_vblank_raw(void) {
    return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;
}
static inline __attribute__((unused)) int in_vblank(void) {
    return in_vblank_raw() && (wall_no != vbl_ack_wall);
}"""),
    # FIX-A $2002 ack
    ("""            uint8_t v = 0;
            if (in_vblank()) v |= 0x80;""",
     """            uint8_t v = 0;
            if (in_vblank_raw()) { v |= 0x80; vbl_ack_wall = wall_no; }"""),
    # FIX-B edge counting
    ("""    while (cycles >= nmi_next_edge) {
        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;""",
     """    while (cycles >= nmi_next_edge) {
        wall_no++;
        uint64_t f = nmi_next_edge / CYCLES_PER_FRAME;"""),
    # FIX-B strobe latch index
    ("uint64_t f = cycles / (uint64_t)CYCLES_PER_FRAME; uint8_t live = pad_sample_fn(f);",
     "uint64_t f = wall_no; uint8_t live = pad_sample_fn(f);"),
    # FIX-B strobe-held live read index
    ("if (pad_sample_fn) { uint8_t live = pad_sample_fn(cycles / (uint64_t)CYCLES_PER_FRAME); return live & 1; }",
     "if (pad_sample_fn) { uint8_t live = pad_sample_fn(wall_no); return live & 1; }"),
]

for variant in ("off", "enf"):
    path = GEN + "/combined_" + variant + ".c"
    s = open(path).read()
    for old, new in REPS:
        assert s.count(old) == 1, "anchor in " + variant + ": " + old[:60]
        s = s.replace(old, new, 1)
    open(path, "w").write(s)
    print("fixed " + path)

print("combined FIX-A/B ok")
