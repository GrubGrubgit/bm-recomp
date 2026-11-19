# Manual vec007A entry: bank4 9FF1 (TAS trap port-ff ~7354)

## Why manual
After the 9F62 slice, the TAS-allbosses port trapped vec007A-unmapped
at v=9FF1 (same b7_LC987 dispatch chain, direct dispatch). Single entry.

## ROM decode (bytes verified vs ROM, bank4 = 8K bank 8)
9FF1 is an alternate entry into the 9F65-family object routine that
bypasses the LDA 0400 / CMP 03 / BNE preamble and starts at the
LDA 10 / STA 40 head (byte-identical to 9F6B onward). Body: BEQ LA001
else JMP C17A; LA001 LDA 15 AND 02 BEQ LA00C else LDA E0 BNE LA02F
else RTS; LA00C JSR A072 AND 03FC BEQ LA017 else JMP C14A;
LA017 LDA 00 JSR C147 BNE LA04D else init E0 / 3A / ORA 15,02
(the ORA is always-nonzero so BNE LA04D is always taken - kept
conditional, faithful); LA02F mask 15, JSR C060 + JSR A072, fold
03FC/A050,X/99, LDA 07, JMP C11A; LA04D JMP A058 (same-bank tail). Same-bank
JSR A072 resolves to pre-existing b4_entry_A072; all C-window targets
(C0FF/C17A/C14A/C147/C060/C216/C11A) auto-resolve via ADDRMAP.
9FEE-9FF0 are EA padding, no twin on the trap path.
## Lift
lift.py 9ff1.snip OUT b4 entry_9FF1 stub entry_A058 with ADDRMAP PROV
JMPTAB, UNWIND off (enforce for enf). Stub needed: LA04D jumps same-bank
to pre-existing b4_entry_A058 (lift refuses same-bank xref as plain jmp). New local labels LA001/LA00C/
LA017/LA02F/LA04D defined exactly once per gen, no collisions.
No pre-existing dup under any name.

## Cases
vec007A bank4 guarded case for 9FF1 only.

## Regen recipe
1. lift.py as above (stub slot needs explicit empty string so the
ADDRMAP:/PROV:/JMPTAB:/UNWIND: specs parse from argv 6 onward).
2. wp_wp9FF1.py splices decl, body, case into gen combined off/enf
(anchored on the 9F62 batch); ADDRMAP, PROV_ALL, vec007A.
3. gcc -fsyntax-only -Wall -Wextra both gens, zero warnings.

## Fix 2026-11-19 (LA04D target)
Original slice read the ROM tail as LA02F-fallthrough + LA04D=JMP C11A.
ROM bytes at A048-A04D are LDA 07 / JMP C11A / JMP A058: LA02F ends with
an explicit JMP C11A (A=7), and both BNE branches (A01C+2F, A02D+1E) land
on A04D=JMP A058, never on C11A. Mesen (accurate) takes A058 (B7 stays 4);
the mistranscription sent the port to C11A(255)->D1EF (B7=255, 15|=40), the
first position-breaking fork of the full TAS (wall 7369, y stuck 3944).
Fixed snip (explicit JMP C11A + LA04D JMP A058), re-lifted with stub entry_A058,
re-spliced 9FF1 bodies into gen off/enf via wp_fix_LA04D.py, gcc clean.
