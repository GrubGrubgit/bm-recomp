D = '/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/recomp/gen/'
NL = chr(10)
SW = 'static void b7_vec_007A(void) {'
for f in ('combined_off.c', 'combined_enf.c'):
    p = D + f
    s = open(p).read()
    sw = s.find(SW)
    assert sw > 0, f
    a = 'static void b4_entry_9B67(void);' + NL
    b = 'static void b4_entry_9C3B(void);' + NL
    assert s.count(a) == 2, f + ' 9B67'
    i = s.find(a)
    assert i < sw, f + ' 9B67 not in 7t block'
    s = s[:i] + a + b + s[i+len(a):]
    sw = s.find(SW)
    c = 'static void b4_entry_9FBA(void);' + NL
    d = 'static void b4_entry_A74E(void);' + NL
    assert s.count(c) == 2, f + ' 9FBA'
    j = s.find(c)
    assert j < sw, f + ' 9FBA not in 7t block'
    s = s[:j] + c + d + s[j+len(c):]
    open(p, 'w').write(s)
    print('decls added to', f, len(s))
print('DECL-OK')
