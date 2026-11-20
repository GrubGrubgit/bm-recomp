# Fix b4_L8A69 phantom tail (TAS wall-7127 $27=00 fork).
# ROM ground truth (bank4 CPU $8A69): EA EA EA A9 18 85 40 ...
# 3x NOP then byte-identical to entry_8A6C. Gen lift renders phantom
# X=RD($8901)/LDA $86A3,X/LDA ($86,X)/STA ($1B),Y which occur NOWHERE
# in the PRG (byte scan); donor b4_entry_8A6C has TAX/LDA $8AA3,X /
# ADC #$1B/JMP C063 matching ROM. Phantom STA zeroes $27 via ($1B).

NL = chr(10)
def fix(path):
    s = open(path).read()
    ot = "static void __attribute__((used)) b4_L8A69(void) {"
    dt = "static void __attribute__((used)) b4_entry_8A6C(void) {"
    i = s.find(ot)
    assert i != -1, path + ": L8A69 missing"
    ie = s.find("static void", i + 10)
    assert ie != -1
    ob = s[i:ie]
    assert "0x8901" in ob, "no phantom 8901"
    assert "0x86A3" in ob, "no phantom 86A3"
    assert "((0x1B)" in ob, "no phantom 1B"
    assert "0x8AA3" not in ob, "already fixed?"
    j = s.find(dt)
    assert j != -1, path + ": donor missing"
    je = s.find("static void", j + 10)
    assert je != -1
    db = s[j:je]
    assert "0x8901" not in db, "donor dirty"
    assert "0x86A3" not in db, "donor dirty"
    assert "0x8AA3" in db, "donor missing 8AA3"
    assert "X = A; setZN(X);" in db, "donor missing TAX"
    nb = db.replace("b4_entry_8A6C", "b4_L8A69")
    q = chr(34)
    poll = "nmi_poll(" + q + "b4_L8A69" + q + ");"
    anchor = "{" + NL + poll + NL
    assert nb.count(anchor) == 1, "anchor x%d" % nb.count(anchor)
    unit = ";" + NL + "cycles += 2;" + NL + poll + NL
    nb = nb.replace(anchor, anchor + unit + unit + unit, 1)
    assert "0x8901" not in nb
    assert "0x86A3" not in nb
    assert "((0x86 + X)" not in nb
    assert "((0x1B)" not in nb
    assert "0x8AA3" in nb
    assert "b4_LB8A84" in nb and "b4_LB8A9A" in nb
    s = s[:i] + nb + s[ie:]
    open(path, "w").write(s)
    print(path + ": replaced %d -> %d" % (len(ob), len(nb)))

for p in ("gen/combined_off.c", "gen/combined_enf.c"):
    fix(p)
print("wp_fix_8A69 ok")
