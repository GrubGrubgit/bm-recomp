import re, sys
from py65.devices.mpu6502 import MPU
from py65.disassembler import Disassembler
W='/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/work/banks/'
INFO='/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe/disasm/info/prg7_auto.info'
prg=open(W+'prg7.bin','rb').read()
m=MPU(); m.memory[0xC000:0x10000]=prg; d=Disassembler(m)
ranges=[]
for ln in open(INFO):
    if 'TYPE Code' not in ln or 'RANGE' not in ln: continue
    a=[int(x.split(';')[0],16) for x in ln.split('$')[1:3]]
    if a[1]>=0xC000: ranges.append((max(a[0],0xC000),a[1]))
ranges.sort()
cset=set()
for lo,hi in ranges:
    cset.update(range(lo,hi+1))
SUP={'ldx','lda','ldy','inx','dex','iny','dey','tax','txa','tay','tya','tsx','txs','pha','pla','php','sec','clc','sei','cli','stx','sty','sta','and','eor','ora','rol','ror','asl','lsr','dec','inc','bit','adc','sbc','cmp','cpx','cpy','bne','beq','bcc','bcs','bpl','bmi','bvs','bvc','jsr','jmp','rts','rti','nop','brk'}
def mode_of(txt, op):
    arg=txt[len(op):].strip()
    if not arg: return 'imp'
    if arg.startswith('#'): return 'imm'
    if arg.startswith('('): return 'ind'
    if arg=='A': return 'acc'
    if arg.endswith(',X') or arg.endswith(',Y'): return 'idx'
    return 'abs'
LIFTMEM={'lda','ldx','ldy','sta','stx','sty','adc','sbc','cmp','cpx','cpy','asl','lsr','rol','ror','inc','dec','bit'}
tot=0; clean=0; blockers={}
for lo,hi in ranges:
    pc=lo; bl=[]
    while pc<=hi:
        try: n,txt=d.instruction_at(pc)
        except Exception as e: bl.append((pc,'DECODE-ERR')); break
        op=txt.split()[0].lower()
        if op not in SUP: bl.append((pc,'UNDOC '+txt))
        elif op=='jmp' and '(' in txt: bl.append((pc,'JMP-IND '+txt))
        elif op in ('jsr','jmp'):
            mm=re.search(r'\$([0-9A-Fa-f]{4})',txt)
            t=int(mm.group(1),16) if mm else None
            if t is None or t not in cset: bl.append((pc,'X-CODE '+txt))
        elif op in ('brk','rti'): bl.append((pc,'SYS '+txt))
        pc+=n; tot+=1
    if bl: blockers[(lo,hi)]=bl
    else: clean+=1
print('bank7 code ranges:',len(ranges),'insns:',tot,'clean:',clean,'blocked:',len(blockers))
cats={}
for r,bl in blockers.items():
    for a,msg in bl:
        k=msg.split()[0]; cats[k]=cats.get(k,0)+1
print('blocker kinds:',cats)
for r,bl in sorted(blockers.items())[:25]:
    print('%04X-%04X:'%(r[0],r[1]),['%04X %s'%(a,m) for a,m in bl[:4]],'...' if len(bl)>4 else '')
