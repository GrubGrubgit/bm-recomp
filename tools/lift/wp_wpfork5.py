import os
BASE = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
LIFT = BASE + "/recomp/tools/lift"
GEN = BASE + "/recomp/gen"
RT = LIFT + "/runtime.h"
NL = chr(10)
AMP2 = chr(38) + chr(38)
def rep(path, old, new, expect=1):
    s = open(path).read()
    c = s.count(old)
    assert c == expect, "anchor count %d != %d in %s: %s" % (c, expect, path, old[:70])
    s = s.replace(old, new)
    open(path, "w").write(s)
    print("ok %s :: %s" % (os.path.basename(path), old[:50]))
DMA_OLD = "        cycles += 512;"
DMA_NEW = "        cycles += ((cycles " + chr(38) + " 1) ? 514 : 513);"
NMI_OLD = "        nmi_next_edge += (uint64_t)CYCLES_PER_FRAME;"
NMI_NEW = ("        { uint64_t fl = (uint64_t)CYCLES_PER_FRAME; if ((reg2001 " + chr(38) + " 0x18) " + AMP2 + " (wall_no " + chr(38) + " 1)) fl -= 1; nmi_next_edge += fl; }")
PAD_OLD = "    while (cycles >= pad_next) { pad_wall++; pad_next += (uint64_t)CYCLES_PER_FRAME; }"
PAD_NEW = ("    while (cycles >= pad_next) { pad_wall++; { uint64_t pfl = (uint64_t)CYCLES_PER_FRAME; if ((reg2001 " + chr(38) + " 0x18) " + AMP2 + " (pad_wall " + chr(38) + " 1)) pfl -= 1; pad_next += pfl; } }")
for path in (RT, GEN + "/combined_off.c", GEN + "/combined_enf.c"):
    rep(path, DMA_OLD, DMA_NEW)
    rep(path, NMI_OLD, NMI_NEW)
    rep(path, PAD_OLD, PAD_NEW)
for path in (GEN + "/combined_off.c", GEN + "/combined_enf.c"):
    rep(path, "int uw_abort;" + NL + "int uw_888C;" + NL + "int uw_9488;", "int uw_abort;" + NL + "int uw_888C;" + NL + "int uw_9488;" + NL + "int uw_9007;")
OFF = GEN + "/combined_off.c"
rep(OFF, 'nmi_poll("b4_entry_9007");' + NL + 'cycles += 4;' + NL + 'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL + 'cycles += 4;' + NL + 'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL + 'b4_L9010();', 'nmi_poll("b4_entry_9007");' + NL + 'cycles += 4;' + NL + 'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL + 'cycles += 4;' + NL + 'S = (uint8_t)(S + 1); A = stk[S]; setZN(A);' + NL + 'uw_9007 = 1;' + NL + 'b4_L9010();')
rep(OFF, "b4_entry_9007();" + NL + "S = (uint8_t)(S + 2);", "b4_entry_9007();" + NL + "if (uw_9007) { uw_9007 = 0; return; }" + NL + "S = (uint8_t)(S + 2);", expect=2)
print("fork5 port ok")
