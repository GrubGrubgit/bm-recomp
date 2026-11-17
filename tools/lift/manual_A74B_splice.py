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


DECL = "static void b4_entry_A74B(void);"
CASE = "case 0xA74B: b4_entry_A74B(); break;"


def splice(path, decl_anchor, case_anchor, body_anchor, body_text, decl_new, case_new):
    s = open(path).read()
    if decl_anchor is not None:
        assert s.count(decl_anchor) == 1, "decl anchor in " + path
        s = s.replace(decl_anchor, decl_new, 1)
    if case_anchor is not None:
        assert s.count(case_anchor) == 1, "case anchor in " + path
        s = s.replace(case_anchor, case_new, 1)
    if body_anchor is not None:
        assert s.count(body_anchor) == 1, "body anchor in " + path
        s = s.replace(body_anchor, body_text + body_anchor, 1)
    open(path, "w").write(s)
    print("spliced " + path)


off_body = body_of("out_off.c")
enf_body = body_of("out_enf.c")

# bank4 TU: decl + body before A74E (off and enf)
for variant, body in (("off", off_body), ("enf", enf_body)):
    p = os.path.join(GEN, "bank4_" + variant + ".c")
    splice(p,
           "static void b4_entry_A74E(void);",
           None,
           "static void __attribute__((used)) b4_entry_A74E(void) {",
           body, DECL, None)

# bank7t TU: decl + case before AFBC (A74E absent here; A74B slots sorted anyway)
for variant in ("off", "enf"):
    p = os.path.join(GEN, "bank7t_" + variant + ".c")
    s = open(p).read()
    da = "static void b4_entry_9FBA(void);\nstatic void b4_entry_AFBC(void);"
    assert s.count(da) == 1, "bank7t decl anchor " + variant
    s = s.replace(da, "static void b4_entry_9FBA(void);\n" + DECL + "\nstatic void b4_entry_AFBC(void);", 1)
    ca = "case 0x9FBA: b4_entry_9FBA(); break;\ncase 0xAFBC: b4_entry_AFBC(); break;"
    assert s.count(ca) == 1, "bank7t case anchor " + variant
    s = s.replace(ca, "case 0x9FBA: b4_entry_9FBA(); break;\n" + CASE + "\ncase 0xAFBC: b4_entry_AFBC(); break;", 1)
    open(p, "w").write(s)
    print("spliced " + p)

# combined: bank7t-section decl+case, bank4-section decl+body
for variant, body in (("off", off_body), ("enf", enf_body)):
    p = os.path.join(GEN, "combined_" + variant + ".c")
    s = open(p).read()
    da = "static void b4_entry_9FBA(void);\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_AFBC(void);"
    assert s.count(da) == 1, "combined vec decl anchor " + variant
    s = s.replace(da, "static void b4_entry_9FBA(void);\n" + DECL + "\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_AFBC(void);", 1)
    ca = "case 0x9FBA: b4_entry_9FBA(); break;\ncase 0xA74E: b4_entry_A74E(); break;\ncase 0xAFBC: b4_entry_AFBC(); break;"
    assert s.count(ca) == 1, "combined vec case anchor " + variant
    s = s.replace(ca, "case 0x9FBA: b4_entry_9FBA(); break;\n" + CASE + "\ncase 0xA74E: b4_entry_A74E(); break;\ncase 0xAFBC: b4_entry_AFBC(); break;", 1)
    ba = "static void __attribute__((used)) b4_entry_A74E(void) {"
    assert s.count(ba) == 1, "combined body anchor " + variant
    # bank4-section decl anchor (neighbors A6DE/A7A2)
    bd = "static void b4_entry_A6DE(void);\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_A7A2(void);"
    assert s.count(bd) == 1, "combined bank4 decl anchor " + variant
    s = s.replace(bd, "static void b4_entry_A6DE(void);\n" + DECL + "\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_A7A2(void);", 1)
    s = s.replace(ba, body + ba, 1)
    open(p, "w").write(s)
    print("spliced " + p)

print("splice A74B ok")
