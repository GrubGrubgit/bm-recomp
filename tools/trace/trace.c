/* Headless Blaster Master (MMC1) tracer: logs PC + PRG bank per instruction.
 * Usage: trace ROM OUTFILE FRAMES [MAXM]
 * ROM must be mapper 1, 128KB PRG (8x16KB). No rendering, no sound.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static uint8_t ram[0x800];
static uint8_t prg[8][0x4000];
static uint8_t vram[0x800];
static uint8_t oam[0x100];

static uint8_t A, X, Y, S, P;
static uint16_t PC;
static int prg_bank;
static int mmc_shift, mmc_count, mmc_ctrl;
static uint64_t cycles;
static long insns;
static uint8_t reg2000;
static int nmi_count, mmc_writes;
static uint8_t pad_bits;
static int pad_pos;
static int strobe;
static int watch_lo, watch_hi, watch_on;
static int tape_fr[512];
static uint8_t tape_mk[512];
static int tape_n;
static FILE *edge_out;
static int edge_mode;
static uint16_t eshadow[512];
static uint8_t eshadow_plus[512];
static int esp;

#define CYCLES_PER_FRAME 29781
#define VBLANK_START (29781 - 2273)

static int in_vblank(void) {
  return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;
}

static void edge(int ty, uint16_t src, uint16_t dst);
static uint8_t mem_rd(uint16_t a) {
  if (a < 0x2000) return ram[a & 0x7FF];
  if (a < 0x4000) {
    int r = a & 7;
    if (r == 2) {
      uint8_t v = 0;
      if (in_vblank()) v |= 0xC0;
      return v;
    }
    if (r == 4) return oam[0];
    if (r == 7) return 0;
    return 0;
  }
  if (a < 0x4020) {
    if (a == 0x4015) return 0;
    if (a == 0x4016 || a == 0x4017) {
      if (pad_pos < 8) return (pad_bits >> (pad_pos++)) & 1;
      return 0;
    }
    return 0;
  }
  if (a < 0x6000) return 0;
  if (a < 0x8000) return 0;
  if (a < 0xC000) return prg[prg_bank][a - 0x8000];
  return prg[7][a - 0xC000];
}

static void mmc_write(uint16_t a, uint8_t v) {
  mmc_writes++;
  if (v & 0x80) {
    mmc_count = 0;
    mmc_ctrl |= 0x0C;
    prg_bank = 0;
    return;
  }
  mmc_shift = ((v & 1) << 4) | (mmc_shift >> 1);
  if (++mmc_count == 5) {
    int reg = (a >> 13) & 3;
    if (reg == 0) mmc_ctrl = mmc_shift & 0x1F;
    else if (reg == 3) { int nb = mmc_shift & 7; if (nb != prg_bank) { prg_bank = nb; edge(8, PC, (uint16_t)nb); } }
    mmc_count = 0;
    mmc_shift = 0;
  }
}

static void mem_wr(uint16_t a, uint8_t v) {
  if (watch_on && a >= (uint16_t)watch_lo && a <= (uint16_t)watch_hi)
    fprintf(stderr, "W $%04X=$%02X from $%04X b%d\n", a, v, PC, (PC >= 0xC000) ? 7 : prg_bank);
  if (a < 0x2000) { ram[a & 0x7FF] = v; return; }
  if (a < 0x4000) {
    int r = a & 7;
    if (r == 0) reg2000 = v;
    else if (r == 1) { }
    else if (r == 3) { }
    else if (r == 4) { }
    else if (r == 5) { }
    else if (r == 6) { }
    return;
  }
  if (a == 0x4014) {
    uint16_t base = (uint16_t)v << 8;
    int i;
    for (i = 0; i < 256; i++) oam[i] = mem_rd(base + i);
    cycles += 512;
    return;
  }
  if (a == 0x4016) {
    if ((strobe == 0) && (v & 1)) pad_pos = 0;
    strobe = v & 1;
    if (strobe) pad_pos = 0;
    return;
  }
  if (a == 0x4017) return;
  if (a < 0x4020) return;
  if (a < 0x6000) return;
  if (a < 0x8000) return;
  mmc_write(a, v);
}

static inline uint8_t fetch(void) { return mem_rd(PC++); }
static inline void edge(int ty, uint16_t src, uint16_t dst) {
  if (!edge_out) return;
  uint16_t fr = (uint16_t)(cycles / CYCLES_PER_FRAME);
  uint8_t r[8];
  r[0] = (uint8_t)ty; r[1] = src & 0xFF; r[2] = src >> 8;
  r[3] = dst & 0xFF; r[4] = dst >> 8;
  int b = prg_bank;
  r[5] = (uint8_t)b; r[6] = fr & 0xFF; r[7] = fr >> 8;
  fwrite(r, 1, 8, edge_out);
}
static inline void push(uint8_t v) { mem_wr(0x100 + S, v); S--; }
static inline uint8_t pull(void) { S++; return mem_rd(0x100 + S); }
static inline void setZN(uint8_t v) {
  P = (P & 0x7D) | (v ? (v & 0x80) : 0) | (v ? 0 : 0x02);
}
static inline void do_adc(uint8_t v) {
  unsigned t = (unsigned)A + (unsigned)v + (unsigned)(P & 1);
  uint8_t r = (uint8_t)(t & 0xFF);
  P = (P & 0x3C) | ((r == 0) << 1) | (r & 0x80) | ((t > 0xFF) ? 1 : 0) |
      ((((A ^ r) & (v ^ r)) & 0x80) ? 0x40 : 0);
  A = r;
}
static inline void do_sbc(uint8_t v) {
  int t = (int)A - (int)v - (1 - (P & 1));
  uint8_t r = (uint8_t)(t & 0xFF);
  P = (P & 0x3C) | ((r == 0) << 1) | (r & 0x80) | ((t >= 0) ? 1 : 0) |
      ((((A ^ r) & (A ^ v)) & 0x80) ? 0x40 : 0);
  A = r;
}
static inline void do_cmp(uint8_t reg, uint8_t v) {
  uint8_t r = reg - v;
  P = (P & 0x7C) | ((r == 0) << 1) | (r & 0x80) | ((reg >= v) ? 1 : 0);
}
static inline void do_bit(uint8_t v) {
  P = (P & 0x3A) | (v & 0xC0) | (((A & v) == 0) << 1);
}
#define BRA(cond) do { int8_t o = (int8_t)fetch(); cycles += 2;   if (cond) { uint16_t np = (uint16_t)(PC + o);   cycles += 1 + ((((PC ^ np) & 0xFF00) != 0) ? 1 : 0); PC = np; } } while (0)
#define LDA_RD(mode_call) do { A = (mode_call); setZN(A); } while (0)
/* Returns 0 normally, -1 on unimplemented opcode, -2 on BRK. */
static int exec_one(void) {
  uint8_t op = fetch();
  uint16_t a = 0;
  uint8_t v = 0;
  uint16_t t = 0;
  uint8_t r = 0;
  switch (op) {
    case 0xA9: A = fetch(); setZN(A); cycles += 2; break;
    case 0xA5: A = mem_rd(fetch()); setZN(A); cycles += 3; break;
    case 0xB5: A = mem_rd((fetch() + X) & 0xFF); setZN(A); cycles += 4; break;
    case 0xAD: a = fetch(); a |= (uint16_t)fetch() << 8; A = mem_rd(a); setZN(A); cycles += 4; break;
    case 0xBD: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; A = mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xB9: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; A = mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xA1: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); A = mem_rd(a); setZN(A); cycles += 6; break;
    case 0xB1: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; A = mem_rd(t); setZN(A); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xA2: X = fetch(); setZN(X); cycles += 2; break;
    case 0xA6: X = mem_rd(fetch()); setZN(X); cycles += 3; break;
    case 0xB6: X = mem_rd((fetch() + Y) & 0xFF); setZN(X); cycles += 4; break;
    case 0xAE: a = fetch(); a |= (uint16_t)fetch() << 8; X = mem_rd(a); setZN(X); cycles += 4; break;
    case 0xBE: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; X = mem_rd(t); setZN(X); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xA0: Y = fetch(); setZN(Y); cycles += 2; break;
    case 0xA4: Y = mem_rd(fetch()); setZN(Y); cycles += 3; break;
    case 0xB4: Y = mem_rd((fetch() + X) & 0xFF); setZN(Y); cycles += 4; break;
    case 0xAC: a = fetch(); a |= (uint16_t)fetch() << 8; Y = mem_rd(a); setZN(Y); cycles += 4; break;
    case 0xBC: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; Y = mem_rd(t); setZN(Y); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x85: mem_wr(fetch(), A); cycles += 3; break;
    case 0x95: mem_wr((fetch() + X) & 0xFF, A); cycles += 4; break;
    case 0x8D: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a, A); cycles += 4; break;
    case 0x9D: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a + X, A); cycles += 5; break;
    case 0x99: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a + Y, A); cycles += 5; break;
    case 0x81: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); mem_wr(a, A); cycles += 6; break;
    case 0x91: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); mem_wr(a + Y, A); cycles += 6; break;
    case 0x86: mem_wr(fetch(), X); cycles += 3; break;
    case 0x96: mem_wr((fetch() + Y) & 0xFF, X); cycles += 4; break;
    case 0x8E: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a, X); cycles += 4; break;
    case 0x84: mem_wr(fetch(), Y); cycles += 3; break;
    case 0x94: mem_wr((fetch() + X) & 0xFF, Y); cycles += 4; break;
    case 0x8C: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a, Y); cycles += 4; break;
    case 0xAA: X = A; setZN(X); cycles += 2; break;
    case 0xA8: Y = A; setZN(Y); cycles += 2; break;
    case 0x8A: A = X; setZN(A); cycles += 2; break;
    case 0x98: A = Y; setZN(A); cycles += 2; break;
    case 0xBA: X = S; setZN(X); cycles += 2; break;
    case 0x9A: S = X; cycles += 2; break;
    case 0xCA: X--; setZN(X); cycles += 2; break;
    case 0x88: Y--; setZN(Y); cycles += 2; break;
    case 0xE8: X++; setZN(X); cycles += 2; break;
    case 0xC8: Y++; setZN(Y); cycles += 2; break;
    case 0x69: do_adc(fetch()); cycles += 2; break;
    case 0x65: do_adc(mem_rd(fetch())); cycles += 3; break;
    case 0x75: do_adc(mem_rd((fetch() + X) & 0xFF)); cycles += 4; break;
    case 0x6D: a = fetch(); a |= (uint16_t)fetch() << 8; do_adc(mem_rd(a)); cycles += 4; break;
    case 0x7D: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; do_adc(mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x79: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; do_adc(mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x61: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); do_adc(mem_rd(a)); cycles += 6; break;
    case 0x71: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; do_adc(mem_rd(t)); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xE9: do_sbc(fetch()); cycles += 2; break;
    case 0xE5: do_sbc(mem_rd(fetch())); cycles += 3; break;
    case 0xF5: do_sbc(mem_rd((fetch() + X) & 0xFF)); cycles += 4; break;
    case 0xED: a = fetch(); a |= (uint16_t)fetch() << 8; do_sbc(mem_rd(a)); cycles += 4; break;
    case 0xFD: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; do_sbc(mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xF9: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; do_sbc(mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xE1: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); do_sbc(mem_rd(a)); cycles += 6; break;
    case 0xF1: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; do_sbc(mem_rd(t)); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x29: A &= fetch(); setZN(A); cycles += 2; break;
    case 0x25: A &= mem_rd(fetch()); setZN(A); cycles += 3; break;
    case 0x35: A &= mem_rd((fetch() + X) & 0xFF); setZN(A); cycles += 4; break;
    case 0x2D: a = fetch(); a |= (uint16_t)fetch() << 8; A &= mem_rd(a); setZN(A); cycles += 4; break;
    case 0x3D: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; A &= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x39: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; A &= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x21: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); A &= mem_rd(a); setZN(A); cycles += 6; break;
    case 0x31: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; A &= mem_rd(t); setZN(A); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x09: A |= fetch(); setZN(A); cycles += 2; break;
    case 0x05: A |= mem_rd(fetch()); setZN(A); cycles += 3; break;
    case 0x15: A |= mem_rd((fetch() + X) & 0xFF); setZN(A); cycles += 4; break;
    case 0x0D: a = fetch(); a |= (uint16_t)fetch() << 8; A |= mem_rd(a); setZN(A); cycles += 4; break;
    case 0x1D: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; A |= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x19: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; A |= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x01: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); A |= mem_rd(a); setZN(A); cycles += 6; break;
    case 0x11: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; A |= mem_rd(t); setZN(A); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x49: A ^= fetch(); setZN(A); cycles += 2; break;
    case 0x45: A ^= mem_rd(fetch()); setZN(A); cycles += 3; break;
    case 0x55: A ^= mem_rd((fetch() + X) & 0xFF); setZN(A); cycles += 4; break;
    case 0x4D: a = fetch(); a |= (uint16_t)fetch() << 8; A ^= mem_rd(a); setZN(A); cycles += 4; break;
    case 0x5D: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; A ^= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x59: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; A ^= mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x41: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); A ^= mem_rd(a); setZN(A); cycles += 6; break;
    case 0x51: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; A ^= mem_rd(t); setZN(A); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xC9: do_cmp(A, fetch()); cycles += 2; break;
    case 0xC5: do_cmp(A, mem_rd(fetch())); cycles += 3; break;
    case 0xD5: do_cmp(A, mem_rd((fetch() + X) & 0xFF)); cycles += 4; break;
    case 0xCD: a = fetch(); a |= (uint16_t)fetch() << 8; do_cmp(A, mem_rd(a)); cycles += 4; break;
    case 0xDD: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + X; do_cmp(A, mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xD9: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; do_cmp(A, mem_rd(t)); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xC1: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); do_cmp(A, mem_rd(a)); cycles += 6; break;
    case 0xD1: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; do_cmp(A, mem_rd(t)); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xE0: do_cmp(X, fetch()); cycles += 2; break;
    case 0xE4: do_cmp(X, mem_rd(fetch())); cycles += 3; break;
    case 0xEC: a = fetch(); a |= (uint16_t)fetch() << 8; do_cmp(X, mem_rd(a)); cycles += 4; break;
    case 0xC0: do_cmp(Y, fetch()); cycles += 2; break;
    case 0xC4: do_cmp(Y, mem_rd(fetch())); cycles += 3; break;
    case 0xCC: a = fetch(); a |= (uint16_t)fetch() << 8; do_cmp(Y, mem_rd(a)); cycles += 4; break;
    case 0x24: do_bit(mem_rd(fetch())); cycles += 3; break;
    case 0x2C: a = fetch(); a |= (uint16_t)fetch() << 8; do_bit(mem_rd(a)); cycles += 4; break;
    case 0x0A: { uint8_t ar = A << 1; P = (P & 0x7C) | ((ar == 0) << 1) | (ar & 0x80) | ((A & 0x80) ? 1 : 0); A = ar; } cycles += 2; break;
    case 0x06: a = fetch(); v = mem_rd(a); P = (P & 0x7C) | ((v << 1 == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, v << 1); cycles += 5; break;
    case 0x16: a = (fetch() + X) & 0xFF; v = mem_rd(a); P = (P & 0x7C) | ((v << 1 == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, v << 1); cycles += 6; break;
    case 0x0E: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); P = (P & 0x7C) | ((v << 1 == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, v << 1); cycles += 6; break;
    case 0x1E: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); P = (P & 0x7C) | ((v << 1 == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, v << 1); cycles += 7; break;
    case 0x4A: P = (P & 0x7C) | (((A >> 1) == 0) << 1) | ((A & 1) ? 1 : 0); A >>= 1; cycles += 2; break;
    case 0x46: a = fetch(); v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); mem_wr(a, v >> 1); cycles += 5; break;
    case 0x56: a = (fetch() + X) & 0xFF; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); mem_wr(a, v >> 1); cycles += 6; break;
    case 0x4E: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); mem_wr(a, v >> 1); cycles += 6; break;
    case 0x5E: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); mem_wr(a, v >> 1); cycles += 7; break;
    case 0x2A: r = (P & 1); P = (P & 0x7C) | (((A << 1 | r) == 0) << 1) | (((A << 1) | r) & 0x80) | ((A & 0x80) ? 1 : 0); A = (A << 1) | r; cycles += 2; break;
    case 0x26: a = fetch(); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, (v << 1) | r); cycles += 5; break;
    case 0x36: a = (fetch() + X) & 0xFF; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, (v << 1) | r); cycles += 6; break;
    case 0x2E: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, (v << 1) | r); cycles += 6; break;
    case 0x3E: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); mem_wr(a, (v << 1) | r); cycles += 7; break;
    case 0x6A: r = (P & 1); P = (P & 0x7C) | (((A >> 1 | (r << 7)) == 0) << 1) | ((A >> 1 | (r << 7)) & 0x80) | (A & 1); A = (A >> 1) | (r << 7); cycles += 2; break;
    case 0x66: a = fetch(); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); mem_wr(a, (v >> 1) | (r << 7)); cycles += 5; break;
    case 0x76: a = (fetch() + X) & 0xFF; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); mem_wr(a, (v >> 1) | (r << 7)); cycles += 6; break;
    case 0x6E: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); mem_wr(a, (v >> 1) | (r << 7)); cycles += 6; break;
    case 0x7E: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); mem_wr(a, (v >> 1) | (r << 7)); cycles += 7; break;
    case 0xE6: a = fetch(); v = mem_rd(a) + 1; mem_wr(a, v); setZN(v); cycles += 5; break;
    case 0xF6: a = (fetch() + X) & 0xFF; v = mem_rd(a) + 1; mem_wr(a, v); setZN(v); cycles += 6; break;
    case 0xEE: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a) + 1; mem_wr(a, v); setZN(v); cycles += 6; break;
    case 0xFE: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a) + 1; mem_wr(a, v); setZN(v); cycles += 7; break;
    case 0xC6: a = fetch(); v = mem_rd(a) - 1; mem_wr(a, v); setZN(v); cycles += 5; break;
    case 0xD6: a = (fetch() + X) & 0xFF; v = mem_rd(a) - 1; mem_wr(a, v); setZN(v); cycles += 6; break;
    case 0xCE: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a) - 1; mem_wr(a, v); setZN(v); cycles += 6; break;
    case 0xDE: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a) - 1; mem_wr(a, v); setZN(v); cycles += 7; break;
    case 0x10: BRA((P & 0x80) == 0); break;
    case 0x30: BRA((P & 0x80) != 0); break;
    case 0x50: BRA((P & 0x40) == 0); break;
    case 0x70: BRA((P & 0x40) != 0); break;
    case 0x90: BRA((P & 0x01) == 0); break;
    case 0xB0: BRA((P & 0x01) != 0); break;
    case 0xD0: BRA((P & 0x02) == 0); break;
    case 0xF0: BRA((P & 0x02) != 0); break;
    case 0x4C: { uint16_t ipc = PC; t = fetch(); t |= (uint16_t)fetch() << 8; PC = t; edge(2, ipc, t); cycles += 3; break; }
    case 0x6C: { uint16_t ipc = PC; t = fetch(); t |= (uint16_t)fetch() << 8; a = mem_rd(t) | ((uint16_t)mem_rd((t & 0xFF00) | ((t + 1) & 0xFF)) << 8); PC = a; edge(3, ipc, a); cycles += 5; break; }
    case 0x20: { uint16_t ipc = PC; a = fetch(); a |= (uint16_t)fetch() << 8; t = PC - 1; push((t >> 8) & 0xFF); push(t & 0xFF); if (esp < 512) { eshadow[esp] = t; eshadow_plus[esp] = 1; esp++; } PC = a; edge(1, ipc, a); cycles += 6; break; }
    case 0x60: { uint16_t ipc = PC; t = pull(); t |= (uint16_t)pull() << 8; PC = t + 1; if (esp > 0 && (uint16_t)(eshadow[esp-1] + eshadow_plus[esp-1]) == PC) esp--; else edge(4, ipc, PC); cycles += 6; break; }
    case 0x40: { uint16_t ipc = PC; P = pull() | 0x20; t = pull(); t |= (uint16_t)pull() << 8; PC = t; if (esp > 0 && (uint16_t)(eshadow[esp-1] + eshadow_plus[esp-1]) == PC) esp--; else edge(5, ipc, PC); cycles += 6; break; }
    case 0x00: { uint16_t ipc = PC; PC++; push((PC >> 8) & 0xFF); push(PC & 0xFF); push(P | 0x30); if (esp < 512) { eshadow[esp] = PC; eshadow_plus[esp] = 0; esp++; } P |= 0x04; PC = mem_rd(0xFFFE) | ((uint16_t)mem_rd(0xFFFF) << 8); edge(6, ipc, PC); cycles += 7; return -2; }
    case 0x08: push(P | 0x30); cycles += 3; break;
    case 0x28: P = pull() | 0x20; cycles += 4; break;
    case 0x48: push(A); cycles += 3; break;
    case 0x68: A = pull(); setZN(A); cycles += 4; break;
    case 0x78: P |= 0x04; cycles += 2; break;
    case 0x58: P &= ~0x04; cycles += 2; break;
    case 0x38: P |= 0x01; cycles += 2; break;
    case 0x18: P &= ~0x01; cycles += 2; break;
    case 0xF8: P |= 0x08; cycles += 2; break;
    case 0xD8: P &= ~0x08; cycles += 2; break;
    case 0xB8: P &= ~0x40; cycles += 2; break;
    case 0xEA: cycles += 2; break;
    case 0x1A: case 0x3A: case 0x5A: case 0x7A: case 0xDA: case 0xFA: cycles += 2; break;
    case 0x04: case 0x44: case 0x64: fetch(); cycles += 3; break;
    case 0x14: case 0x34: case 0x54: case 0x74: case 0xD4: case 0xF4: fetch(); cycles += 4; break;
    case 0x80: case 0x82: case 0x89: case 0xC2: case 0xE2: fetch(); cycles += 2; break;
    case 0x0C: fetch(); fetch(); cycles += 4; break;
    case 0x07: a = fetch(); v = mem_rd(a); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(a, v); A |= v; setZN(A); cycles += 5; break;
    case 0x17: a = (fetch() + X) & 0xFF; v = mem_rd(a); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(a, v); A |= v; setZN(A); cycles += 6; break;
    case 0x0F: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(a, v); A |= v; setZN(A); cycles += 6; break;
    case 0x1F: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(a, v); A |= v; setZN(A); cycles += 7; break;
    case 0x03: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(a, v); A |= v; setZN(A); cycles += 8; break;
    case 0x1B: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t); P = (P & 0x7C) | (((v << 1) == 0) << 1) | ((v << 1) & 0x80) | ((v & 0x80) ? 1 : 0); v <<= 1; mem_wr(t, v); A |= v; setZN(A); cycles += 8; break;
    case 0x27: a = fetch(); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(a, v); A &= v; setZN(A); cycles += 5; break;
    case 0x37: a = (fetch() + X) & 0xFF; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(a, v); A &= v; setZN(A); cycles += 6; break;
    case 0x2F: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(a, v); A &= v; setZN(A); cycles += 6; break;
    case 0x3F: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(a, v); A &= v; setZN(A); cycles += 7; break;
    case 0x23: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(a, v); A &= v; setZN(A); cycles += 8; break;
    case 0x3B: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t); r = (P & 1); P = (P & 0x7C) | ((((v << 1) | r) == 0) << 1) | ((((v << 1) | r)) & 0x80) | ((v & 0x80) ? 1 : 0); v = (v << 1) | r; mem_wr(t, v); A &= v; setZN(A); cycles += 8; break;
    case 0x47: a = fetch(); v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(a, v); A ^= v; setZN(A); cycles += 5; break;
    case 0x57: a = (fetch() + X) & 0xFF; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(a, v); A ^= v; setZN(A); cycles += 6; break;
    case 0x4F: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(a, v); A ^= v; setZN(A); cycles += 6; break;
    case 0x5F: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(a, v); A ^= v; setZN(A); cycles += 7; break;
    case 0x43: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(a, v); A ^= v; setZN(A); cycles += 8; break;
    case 0x5B: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t); P = (P & 0x7C) | (((v >> 1) == 0) << 1) | ((v & 1) ? 1 : 0); v >>= 1; mem_wr(t, v); A ^= v; setZN(A); cycles += 8; break;
    case 0x67: a = fetch(); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(a, v); do_adc(v); cycles += 5; break;
    case 0x77: a = (fetch() + X) & 0xFF; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(a, v); do_adc(v); cycles += 6; break;
    case 0x6F: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(a, v); do_adc(v); cycles += 6; break;
    case 0x7F: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(a, v); do_adc(v); cycles += 7; break;
    case 0x63: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(a, v); do_adc(v); cycles += 8; break;
    case 0x73: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t); r = (P & 1); P = (P & 0x7C) | ((((v >> 1) | (r << 7)) == 0) << 1) | ((((v >> 1) | (r << 7))) & 0x80) | (v & 1); v = (v >> 1) | (r << 7); mem_wr(t, v); do_adc(v); cycles += 8; break;
    case 0xC7: a = fetch(); v = mem_rd(a) - 1; mem_wr(a, v); do_cmp(A, v); cycles += 5; break;
    case 0xD7: a = (fetch() + X) & 0xFF; v = mem_rd(a) - 1; mem_wr(a, v); do_cmp(A, v); cycles += 6; break;
    case 0xCF: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a) - 1; mem_wr(a, v); do_cmp(A, v); cycles += 6; break;
    case 0xDF: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a) - 1; mem_wr(a, v); do_cmp(A, v); cycles += 7; break;
    case 0xC3: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a) - 1; mem_wr(a, v); do_cmp(A, v); cycles += 8; break;
    case 0xDB: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t) - 1; mem_wr(t, v); do_cmp(A, v); cycles += 8; break;
    case 0xE7: a = fetch(); v = mem_rd(a) + 1; mem_wr(a, v); do_sbc(v); cycles += 5; break;
    case 0xF7: a = (fetch() + X) & 0xFF; v = mem_rd(a) + 1; mem_wr(a, v); do_sbc(v); cycles += 6; break;
    case 0xEF: a = fetch(); a |= (uint16_t)fetch() << 8; v = mem_rd(a) + 1; mem_wr(a, v); do_sbc(v); cycles += 6; break;
    case 0xFF: a = fetch(); a |= (uint16_t)fetch() << 8; a += X; v = mem_rd(a) + 1; mem_wr(a, v); do_sbc(v); cycles += 7; break;
    case 0xE3: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); v = mem_rd(a) + 1; mem_wr(a, v); do_sbc(v); cycles += 8; break;
    case 0xFB: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; v = mem_rd(t) + 1; mem_wr(t, v); do_sbc(v); cycles += 8; break;
    case 0xA7: A = X = mem_rd(fetch()); setZN(A); cycles += 3; break;
    case 0xB7: A = X = mem_rd((fetch() + Y) & 0xFF); setZN(A); cycles += 4; break;
    case 0xAF: a = fetch(); a |= (uint16_t)fetch() << 8; A = X = mem_rd(a); setZN(A); cycles += 4; break;
    case 0xBF: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; A = X = mem_rd(t); setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0xA3: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); A = X = mem_rd(a); setZN(A); cycles += 6; break;
    case 0xB3: v = fetch(); a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); t = a + Y; A = X = mem_rd(t); setZN(A); cycles += 5 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    case 0x87: mem_wr(fetch(), A & X); cycles += 4; break;
    case 0x97: mem_wr((fetch() + Y) & 0xFF, A & X); cycles += 4; break;
    case 0x8F: a = fetch(); a |= (uint16_t)fetch() << 8; mem_wr(a, A & X); cycles += 4; break;
    case 0x83: v = (fetch() + X) & 0xFF; a = mem_rd(v) | ((uint16_t)mem_rd((v + 1) & 0xFF) << 8); mem_wr(a, A & X); cycles += 6; break;
    case 0x0B: case 0x2B: A &= fetch(); setZN(A); if (A & 0x80) P |= 1; cycles += 2; break;
    case 0x4B: A &= fetch(); P = (P & 0x7C) | ((A & 1) ? 1 : 0); A >>= 1; setZN(A); cycles += 2; break;
    case 0x6B: v = A & fetch(); r = (P & 1); A = (v >> 1) | (r << 7); setZN(A); P = (P & 0xBE) | (((A >> 6) & 1)) | ((((A >> 5) ^ (A >> 6)) & 1) << 6); cycles += 2; break;
    case 0xCB: v = A & X; t = fetch(); X = v - (t & 0xFF); setZN(X); P = (P & 0xFE) | ((v >= t) ? 1 : 0); cycles += 2; break;
    case 0xAB: A = X = fetch(); setZN(A); cycles += 2; break;
    case 0xBB: a = fetch(); a |= (uint16_t)fetch() << 8; t = a + Y; v = S & mem_rd(t); A = X = S = v; setZN(A); cycles += 4 + (((a ^ t) & 0xFF00) ? 1 : 0); break;
    default:
      fprintf(stderr, "UNDOC op=$%02X at PC=$%04X bank=%d A=$%02X X=$%02X Y=$%02X P=$%02X S=$%02X\n", op, PC - 1, prg_bank, A, X, Y, P, S);
      return -1;
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "usage: trace ROM OUTFILE FRAMES [MAXM-insn-millions]\n");
    return 1;
  }
  FILE *f = fopen(argv[1], "rb");
  if (!f) { fprintf(stderr, "cannot open ROM\n"); return 1; }
  uint8_t hdr[16];
  if (fread(hdr, 1, 16, f) != 16 || memcmp(hdr, "NES\032", 4) != 0) {
    fprintf(stderr, "bad iNES header\n");
    return 1;
  }
  int prg_n = hdr[4];
  int mapper = ((hdr[7] & 0xF0) | (hdr[6] >> 4));
  if (prg_n != 8 || mapper != 1) {
    fprintf(stderr, "need mapper1 8-bank PRG, got mapper=%d prg=%d\n", mapper, prg_n);
    return 1;
  }
  int i;
  for (i = 0; i < 8; i++) {
    if (fread(prg[i], 1, 0x4000, f) != 0x4000) {
      fprintf(stderr, "short PRG\n");
      return 1;
    }
  }
  fclose(f);
  FILE *out = fopen(argv[2], "wb");
  if (!out) { fprintf(stderr, "cannot open output\n"); return 1; }
  static char bigbuf[1 << 20];
  setvbuf(out, bigbuf, _IOFBF, sizeof bigbuf);
  int frames = atoi(argv[3]);
  long maxm = 20 * 1000000L;
  watch_lo = 0; watch_hi = 0; watch_on = 0;
  tape_n = 0;
  {
    int ai = 4;
    if (ai < argc && strcmp(argv[ai], "-w") != 0 && argv[ai][0] >= '0' && argv[ai][0] <= '9') { maxm = atol(argv[ai]) * 1000000L; ai++; }
    if (ai < argc && strcmp(argv[ai], "-w") == 0 && ai + 1 < argc) {
      watch_on = 1;
      watch_lo = (int)strtol(argv[ai+1], 0, 16);
      watch_hi = watch_lo;
      if (ai + 2 < argc && argv[ai+2][0] != '-') { watch_hi = (int)strtol(argv[ai+2], 0, 16); ai++; }
      ai++;
    }
    if (ai < argc && strcmp(argv[ai], "-e") == 0) { edge_mode = 1; ai++; }
    if (ai < argc) {
      FILE *tf = fopen(argv[ai], "r");
      if (tf) {
        int fr; unsigned mk;
        while (tape_n < 512 && fscanf(tf, "%d %x", &fr, &mk) == 2) { tape_fr[tape_n] = fr; tape_mk[tape_n] = (uint8_t)mk; tape_n++; }
        fclose(tf);
        fputs("tape loaded", stderr);
      }
    }
  }
  if (edge_mode && out) edge_out = out;
  A = 0; X = 0; Y = 0; S = 0xFD; P = 0x24;
  prg_bank = 0; mmc_shift = 0; mmc_count = 0; mmc_ctrl = 0x0C;
  reg2000 = 0; pad_bits = 0; pad_pos = 8; strobe = 0;
  cycles = 0; insns = 0; nmi_count = 0; mmc_writes = 0;
  PC = mem_rd(0xFFFC) | ((uint16_t)mem_rd(0xFFFD) << 8);
  printf("reset vector=$%04X\n", PC);
  uint64_t end = (uint64_t)frames * CYCLES_PER_FRAME;
  int last_vb = 0;
  uint16_t last_pc = 0;
  long same_pc = 0;
  int tape_idx = 0;
  while (cycles < end && insns < maxm) {
    if (tape_n) {
      int frnow = (int)(cycles / CYCLES_PER_FRAME);
      while (tape_idx + 1 < tape_n && frnow >= tape_fr[tape_idx + 1]) tape_idx++;
      pad_bits = tape_mk[tape_idx];
    }
    uint16_t pc0 = PC;
    int b0 = prg_bank;
    uint8_t rec[3];
    rec[0] = (uint8_t)(pc0 & 0xFF);
    rec[1] = (uint8_t)(pc0 >> 8);
    rec[2] = (uint8_t)b0;
    if (!edge_mode) fwrite(rec, 1, 3, out);
    insns++;
    int rc = exec_one();
    if (rc == -1) {
      printf("HALT undoc after %ld insns\n", insns);
      break;
    }
    if (rc == -2) fprintf(stderr, "note: BRK at $%04X bank=%d\n", pc0, b0);
    if (PC == last_pc) {
      if (++same_pc > 500000) {
        printf("STALL at $%04X bank=%d after %ld insns\n", PC, b0, insns);
        break;
      }
    } else {
      same_pc = 0;
      last_pc = PC;
    }
    {
      int vb = in_vblank();
      if (vb && !last_vb && (reg2000 & 0x80)) {
        { uint16_t ipc = PC; push((PC >> 8) & 0xFF); push(PC & 0xFF); push(P | 0x20); if (esp < 512) { eshadow[esp] = PC; eshadow_plus[esp] = 0; esp++; } P |= 0x04; PC = mem_rd(0xFFFA) | ((uint16_t)mem_rd(0xFFFB) << 8); edge(7, ipc, PC); }
        nmi_count++;
        cycles += 7;
      }
      last_vb = vb;
    }
  }
  fclose(out);
  printf("insns=%ld cycles=%llu nmis=%d mmc_writes=%d\n", insns, (unsigned long long)cycles, nmi_count, mmc_writes);
  printf("final PC=$%04X bank=%d A=$%02X X=$%02X Y=$%02X P=$%02X S=$%02X\n", PC, (PC >= 0xC000) ? 7 : prg_bank, A, X, Y, P, S);
  return 0;
}
