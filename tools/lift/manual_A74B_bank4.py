import os

LIFT = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift"
GEN = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen"


def body_of(out_name):
    s = open(os.path.join(LIFT, "manual_A74B", out_name)).read()
    parts = s.split("static void __attribute__((used)) ")
    for p in parts:
        name = p.split("(void)")[0]
        if name == "b4_entry_A74B":
            cut = p.find("\nstatic void ")
            if cut >= 0:
                p = p[:cut] + "\n"
            assert "__builtin_trap" not in p, "trap in body"
            return "static void __attribute__((used)) " + p.rstrip() + "\n"
    raise AssertionError("body not found in " + out_name)


DECL74B = "static void b4_entry_A74B(void);"
DECL74E = "static void b4_entry_A74E(void);"
BODY_ANCHOR = "static void __attribute__((used)) b4_entry_A74E(void) {"

off_body = body_of("out_off.c")
enf_body = body_of("out_enf.c")

for variant, body in (("off", off_body), ("enf", enf_body)):
    path = os.path.join(GEN, "bank4_" + variant + ".c")
    s = open(path).read()
    assert s.count(DECL74E) == 1, "decl anchor " + variant
    s = s.replace(DECL74E, DECL74B + "\n" + DECL74E, 1)
    assert s.count(BODY_ANCHOR) == 1, "body anchor " + variant
    s = s.replace(BODY_ANCHOR, body + BODY_ANCHOR, 1)
    open(path, "w").write(s)
    print("spliced " + path)

print("bank4 redo ok")
