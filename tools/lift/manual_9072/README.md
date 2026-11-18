# Manual vec007A entry: bank4 9072 (+bank7 CF10/CF13/LC0CC/LC201)

## Why manual
9072-90E7 decodes as .byte in disasm prg4.s (gap between entry_9007
and entry_9137 families; neighbors 9011/903B JMPs unobserved). 28-byte
bank4 gap 903E done prior; this is the next trap on the Mesen movie
trajectory. Same family as prior gap lifts.

## ROM decode (bank4, 118 bytes 9072-90E7)
9072: LDA40 STA42 / LDA40 STA43 / JSR 8FF3 / JSR 9007 / DEC53 /
BEQ 90E8 / LDA BB LSR / BCC L908C / JSR C01E / L908C: JSR C024 /
LDA11 LSR / BCS L90A2 / DEC50 BNE L90A2 / LDA18 STA50 / DEC51 /
BNE L90A2 / INC51 / L90A2: LDA57 LSR / BCS L90AF / LDA47 ADC51 /
JMP L90B4 / L90AF: LDA47 SBC51 / L90B4: STA47 / PHA /
JSR C0CC STA4C / PLA / JSR C201 STA4D / LDA10 STA40/41 /
JSR C0FF / BNE 90E8 / LDA01 JSR C1E6 / LDA47 PHA ADC60 ASL ROL
ROL AND03 STA47 / JSR 8F21 / PLA STA47 / RTS (at 90E7).
90E8: JMP C117 (3-byte tail; BEQ@9082 and BNE@90CD both tail there).
Callees: 8FF3/9007/8F21 same-bank b4 (pre-existing); C01E/C0FF/C1E6/
C117 fixed-bank b7 (pre-existing, lift emits b7 directly); C024 is a
JMPTAB slot (C024->D324) so lift short-circuits to 9cy SLOT-JSR
b7_entry_D324 (slotfix rule); C0CC/C201 are fixed-bank JMP
trampolines (JMP CF10 / JMP CF13, 3cy each) NOT in JMPTAB, so plain
6cy JSR to b7_LC0CC/LC201 (new, this lift).

## Bank7 leaf (CF10-CF2D, ROM fixed bank)
CF10: CLC ADC40 TAY AND7F CMP40 / BCC LCF1F / EORFF CLC ADC81 /
LCF1F: TAX TYA / BMI LCF27 / LDA CF2E,X RTS / LCF27: LDA00 SEC
SBC CF2E,X RTS. CF13 is the alternate entry (skips the CLC ADC40):
shares the tail (snip duplicates it as LCF1F3/LCF273 to avoid
cross-function goto). LC0CC: JMP CF10; LC201: JMP CF13 (lifted as
b7 JMP-stub functions, same pattern as b7_LC02D/C045/C04E).
LC024/D324 stub DROPPED from cf.snip (dead: 9072 never calls LC024;
C024 short-circuits via JMPTAB). CF2E is a data table (RD abs,X).

## Snip fixes (vs naive transcription)
1. Labels at col 0 (L908C/L90A2/L90AF/L90B4/LCF1F/LCF1F3/LCF27/LCF273).
2. LSR/ASL/ROL with explicit A operand (lift.py requires acc mode as
plain A; bare shifts fail to parse).
3. ENTRY lists quoted; stub placeholder x as argv5
(placeholder: ADDRMAP/PROV/JMPTAB are argv6+); cf snip same way. Correct invocation: lift.py SNIP OUT bX ENTRIES x

-- omitting x shifts ADDRMAP into the stub slot and silently
empties amap/slots (ENF was first misbuilt that way: 6cy + b4_LC024
instead of 9cy + b7_D324; caught by off-vs-enf diff, rebuilt).
4. 90E8 promoted to entry_90E8 in snip (branch target), but gen
already holds byte-identical b4_L90E8 (JMP C117 tail from the 90C2
lift): splice repoints both call sites to b4_L90E8 and discards the
dup body (9B95 precedent). ADDRMAP keeps 90E8 4 L90E8 in place.

## Hardware legitimacy
Native probe (903E tree) on Mesen movie-area13 inputs trapped
vec007A default at probe-frame 19454: vec=9072 swbank=prg[4],
A=72 X=6F Y=00 S=FB P=24. Mesen executes the ROM bytes there.

## Cases
vec007A bank4 guarded case for observed 9072 only. No twins
(90E8 JMP deduped to b4_L90E8, no case; C117/C01E/C0FF/C1E6/D324
fixed-bank targets need none).

## Regen recipe
1. python3 lift.py manual_9072/9072.snip OUT b4 entry_9072,entry_90E8
x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
UNWIND:off (enforce for enf). Reference outputs here
(out9072_off.c/out9072_enf.c) differ ONLY in JSR unwind wraps.
2. python3 lift.py manual_9072/cf.snip OUT b7 entry_CF10,entry_CF13
x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt
UNWIND:off/enforce. Reference outputs here (outcf_off.c/outcf_enf.c)
are byte-identical (JMP tails only, no JSR).
3. python3 wp_wp9072.py splices: 9072 decl+body into gen bank4
 off/enf; CF/LC bodies + 9072 decls/bodies/case into combined
 off/enf (CF first, defined-before-use); ADDRMAP/PROV_ALL
 (9072 4, CF10/CF13 7); vec007A bank4 line +9072.
