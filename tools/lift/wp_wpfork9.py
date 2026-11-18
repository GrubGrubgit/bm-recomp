import os
BASE = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
GEN = BASE + "/recomp/gen"
NL = chr(10)
def rep(path, old, new, expect=1):
    s = open(path).read()
    c = s.count(old)
    assert c == expect, "anchor count %d != %d in %s: %s" % (c, expect, path, old[:70])
    s = s.replace(old, new)
    open(path, "w").write(s)
    print("ok %s :: %s" % (os.path.basename(path), old[:50]))
# P1 decl (OFF only, like uw_9488/uw_888C)
rep(GEN + "/combined_off.c", "int uw_9488;", "int uw_9488;" + NL + "int uw_9434;")
# P2 set flag in L9434 (OFF only)
rep(GEN + "/combined_off.c",
    'static void __attribute__((used)) b4_L9434(void) {' + NL + 'nmi_poll("b4_L9434");' + NL + 'cycles += 4;',
    'static void __attribute__((used)) b4_L9434(void) {' + NL + 'nmi_poll("b4_L9434");' + NL + 'uw_9434 = 1;' + NL + 'cycles += 4;')
# P3 check after 94A9 in L8C27 (OFF only)
rep(GEN + "/combined_off.c",
    "b4_entry_94A9();" + NL + "S = (uint8_t)(S + 2);" + NL + 'nmi_poll("b4_L8C27");',
    "b4_entry_94A9();" + NL + "if (uw_9434) { uw_9434 = 0; return; }" + NL + "S = (uint8_t)(S + 2);" + NL + 'nmi_poll("b4_L8C27");')
# P4 check after 9522 in L8C32 (OFF only)
rep(GEN + "/combined_off.c",
    "b4_entry_9522();" + NL + "S = (uint8_t)(S + 2);" + NL + 'nmi_poll("b4_L8C32");',
    "b4_entry_9522();" + NL + "if (uw_9434) { uw_9434 = 0; return; }" + NL + "S = (uint8_t)(S + 2);" + NL + 'nmi_poll("b4_L8C32");')
print("fork9 port ok")
