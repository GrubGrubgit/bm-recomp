import os
BASE='/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe'
LIFT=BASE+'/recomp/tools/lift'
GEN=BASE+'/recomp/gen'
M=LIFT+'/manual_8A58'
NL=chr(10)
def rep(path, old, new, expect=1):
    s=open(path).read()
    c=s.count(old)
    assert c==expect, (path, old[:80], c)
    open(path,'w').write(s.replace(old,new))
    print('ok', os.path.basename(path), old[:56])
def bodies(src, want):
    parts=src.split('static void __attribute__((used)) ')
    got={}
    for p in parts:
        nm=p.split('(void)')[0]
        if nm in want:
            cut=p.find(NL+'static void ')
            if cut>=0:
                p=p[:cut]+NL
            got[nm]='static void __attribute__((used)) '+p.rstrip()+NL
    assert set(got)==set(want), (set(got), set(want))
    blob=''.join([got[k] for k in want])
    assert '__builtin_trap' not in blob
    return blob
WANT=['b6_entry_8A58']
OFF=bodies(open(M+'/out_off.c').read(), WANT)
ENF=bodies(open(M+'/out_enf.c').read(), WANT)
D1='static void b6_entry_8A31(void);'+NL+'static void b6_entry_8A5B(void);'+NL
D1N='static void b6_entry_8A31(void);'+NL+'static void b6_entry_8A58(void);'+NL+'static void b6_entry_8A5B(void);'+NL
D2='static void b6_entry_8A52(void);'+NL+'static void b6_entry_8A5B(void);'+NL
D2N='static void b6_entry_8A52(void);'+NL+'static void b6_entry_8A58(void);'+NL+'static void b6_entry_8A5B(void);'+NL
BB='static void __attribute__((used)) b6_entry_8A5B(void) {'+NL
CB='case 0x8A31: b6_entry_8A31(); break;'+NL
CN=CB+'case 0x8A58: if (swbank == prg[6]) b6_entry_8A58(); else __builtin_trap(); break;'+NL
for nm,BB2 in (('combined_off.c',OFF),('combined_enf.c',ENF)):
    rep(GEN+'/'+nm, D1, D1N)
    rep(GEN+'/'+nm, D2, D2N)
    rep(GEN+'/'+nm, BB, BB2+BB)
    rep(GEN+'/'+nm, CB, CN)
rep(LIFT+'/ADDRMAP.txt', '8A52 6 entry_8A52'+NL+'8A5B 6 entry_8A5B', '8A52 6 entry_8A52'+NL+'8A58 6 entry_8A58'+NL+'8A5B 6 entry_8A5B')
rep(LIFT+'/PROV_ALL.txt', 'entry_8A52 6'+NL+'entry_8A5B 6', 'entry_8A52 6'+NL+'entry_8A58 6'+NL+'entry_8A5B 6')
rep(LIFT+'/vec007A.txt', '8A31 8A5B 8A69', '8A31 8A58 8A5B 8A69')
print('8A58 port ok')
