import pathlib
B = pathlib.Path("/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe")
GEN = B / "recomp/gen"
M = B / "recomp/tools/lift/manual_9FF1"
NL = chr(10)
TAG = "static void __attribute__((used)) "
def body_of(path, want):
    src = pathlib.Path(path).read_text()
    parts = src.split(TAG)
    for p in parts:
        if p.startswith(want + "(void)"):
            cut = p.find(NL + "static ")
            if cut >= 0:
                p = p[:cut] + NL
            return TAG + p.rstrip() + NL
    raise AssertionError((path, want))
def rep_body(genpath, newblob, want, nextfn):
    gp = GEN / genpath
    src = gp.read_text()
    head = src.index(TAG + want + "(void)")
    nxt = src.index(NL + TAG + nextfn + "(void)", head)
    newsrc = src[:head] + newblob + src[nxt + 1:]
    assert "__builtin_trap" not in newblob, "stub leaked"
    assert newsrc.count(TAG + want + "(void)") == 1
    gp.write_text(newsrc)
    print("spliced", genpath, want, "newlen", len(newblob))
for genf, outf in (("combined_off.c", "out_off.c"), ("combined_enf.c", "out_enf.c")):
    nb = body_of(str(M / outf), "b4_entry_9FF1")
    rep_body(genf, nb, "b4_entry_9FF1", "b4_entry_9FEE")
