import os

LIFT = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/tools/lift"
P = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/probe/pgame.c"
s = open(P).read()

# A74B body from the committed lift output (off TU; enf identical)
out = open(os.path.join(LIFT, "manual_A74B", "out_off.c")).read()
parts = out.split("static void __attribute__((used)) ")
body = None
for q in parts:
    if q.split("(void)")[0] == "b4_entry_A74B":
        cut = q.find("\nstatic void ")
        if cut >= 0:
            q = q[:cut] + "\n"
        assert "__builtin_trap" not in q
        body = "static void __attribute__((used)) " + q.rstrip() + "\n"
assert body is not None

DECL = "static void b4_entry_A74B(void);"
CASE = "case 0xA74B: b4_entry_A74B(); break;"

# bank7t vec section: decl + case (sorted 9FBA < A74B < A74E; A74E present here)
da = "static void b4_entry_9FBA(void);\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_AFBC(void);"
assert s.count(da) == 1, "vec decl"
s = s.replace(da, "static void b4_entry_9FBA(void);\n" + DECL + "\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_AFBC(void);", 1)
ca = "case 0x9FBA: b4_entry_9FBA(); break;\ncase 0xA74E: b4_entry_A74E(); break;\ncase 0xAFBC: b4_entry_AFBC(); break;"
assert s.count(ca) == 1, "vec case"
s = s.replace(ca, "case 0x9FBA: b4_entry_9FBA(); break;\n" + CASE + "\ncase 0xA74E: b4_entry_A74E(); break;\ncase 0xAFBC: b4_entry_AFBC(); break;", 1)

# bank4 section: decl (neighbors A6DE/A7A2) + body before A74E body
bd = "static void b4_entry_A6DE(void);\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_A7A2(void);"
assert s.count(bd) == 1, "bank4 decl"
s = s.replace(bd, "static void b4_entry_A6DE(void);\n" + DECL + "\nstatic void b4_entry_A74E(void);\nstatic void b4_entry_A7A2(void);", 1)
ba = "static void __attribute__((used)) b4_entry_A74E(void) {"
assert s.count(ba) == 1, "bank4 body"
s = s.replace(ba, body + ba, 1)

open(P, "w").write(s)
print("pgame.c A74B ok")
