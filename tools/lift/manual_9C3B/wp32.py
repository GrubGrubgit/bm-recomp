import sys
D = '/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen/'
R = '/data/data/com.termux/files/home/ai-bridge/session-homes/sess-20261107-174920-5205/wrun/regen/'
NL = chr(10)
def read(p):
    return open(p).read()
def rep_once(src, a, b, tag):
    assert src.count(a) == 1, tag
    return src.replace(a, b)
def span(src, start_anchor, end_anchor, tag):
    i = src.find(start_anchor)
    assert i >= 0, 'start ' + tag
    j = src.find(end_anchor, i)
    assert j > i, 'end ' + tag
    return src[i:j]
L9C23 = 'static void __attribute__((used)) b4_L9C23(void) {'
L9C63 = 'static void __attribute__((used)) b4_L9C63(void) {'
D9C3B = 'static void b4_entry_9C3B(void);'
D9B94 = 'static void b4_entry_9B94(void);'
D9C6A = 'static void b4_entry_9C6A(void);'
def vec_lines(b7src):
    l9 = [l for l in b7src.split(NL) if l.startswith('case 0x9C3B:')]
    la = [l for l in b7src.split(NL) if l.startswith('case 0xA74E:')]
    assert len(l9) == 1 and len(la) == 1
    return l9[0], la[0]
def do_pair(tu_name, comb_name, b4regen, b7regen):
    tu = read(D + tu_name)
    co = read(D + comb_name)
    rg = read(R + b4regen)
    b7 = read(R + b7regen)
    # 1. new bodies span from regen
    newb = span(rg, L9C23, L9C63, 'regen span')
    assert 'b4_entry_9C3B();' in newb
    # 2. old span in TU + combined
    oldb_tu = span(tu, L9C23, L9C63, 'tu old span')
    assert 'b4_entry_9C3B' not in oldb_tu
    assert '0x9D73' in oldb_tu
    oldb_co = span(co, L9C23, L9C63, 'combined old span')
    assert 'b4_entry_9C3B' not in oldb_co
    assert '0x9D73' in oldb_co
    tu = rep_once(tu, oldb_tu, newb, 'tu bodies')
    co = rep_once(co, oldb_co, newb, 'combined bodies')
    # 3. decl after 9B94
    assert tu.count(D9B94) == 1 and co.count(D9B94) == 1
    assert D9C3B not in tu and D9C3B not in co
    tu = rep_once(tu, D9B94 + NL, D9B94 + NL + D9C3B + NL, 'tu decl')
    co = rep_once(co, D9B94 + NL, D9B94 + NL + D9C3B + NL, 'combined decl')
    # 4. vec cases
    c9, ca = vec_lines(b7)
    for nm, cs, pre, post in (('9C3B', c9, 'case 0x9B67:', 'case 0x9E06:'), ('A74E', ca, 'case 0x9FBA:', 'case 0xAFBC:')):
        assert co.count(cs) == 0, nm + ' already present'
        pre_lines = [l for l in co.split(NL) if l.startswith(pre)]
        post_lines = [l for l in co.split(NL) if l.startswith(post)]
        assert len(pre_lines) == 1 and len(post_lines) == 1, nm + ' anchors'
        assert co.find(pre_lines[0]) < co.find(post_lines[0]), nm + ' order'
        co = rep_once(co, pre_lines[0] + NL, pre_lines[0] + NL + cs + NL, 'vec ' + nm)
    # 5. A74E decl+body must already exist in combined
    assert co.count('static void b4_entry_A74E(void);') == 1
    assert co.count('b4_entry_A74E(void) {') == 1
    open(D + tu_name, 'w').write(tu)
    open(D + comb_name, 'w').write(co)
    print('wrote', tu_name, len(tu), comb_name, len(co))
do_pair('bank4_off.c', 'combined_off.c', 'b4_off.c', 'b7_off.c')
do_pair('bank4_enf.c', 'combined_enf.c', 'b4_enf.c', 'b7_off.c')
print('SPLICE-OK')
