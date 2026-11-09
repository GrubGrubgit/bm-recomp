#ifndef LIFT_RUNTIME_H
#define LIFT_RUNTIME_H
// Runtime shim for lifted Blaster Master code (prototype).
// CPU state + memory map (RAM, PRG images, pad MMIO with split ports).
// G4: PPU model mirroring the tracer (vram, palette, addr latch, OAM,
// scroll, reg2000, CHR bank regs). $2002 bit7 toggles on a read counter
// (all in-ROM consumers discard the value except reset bpl-spins).
#include <stdint.h>
#include <stdio.h>
#include <string.h>
uint8_t ram[0x800];
#define stk (ram + 0x100)
uint8_t prg[8][0x4000];
uint8_t *swbank = prg[0];
uint8_t A, X, Y, S, P;
uint8_t pad_bits;
int pad_pos1, pad_pos2, strobe;
int uw_abort;
const char *uw_caller;
const char *uw_callee;
int mmc_shift = 0, mmc_count = 0;
uint8_t mmc_ctrl = 0x0C;
uint8_t vram[0x800];
uint8_t pal[32];
uint16_t ppu_addr;
int ppu_latch;
uint8_t ppu_buf;
uint8_t oam[0x100];
uint8_t oam_addr;
uint8_t scx, scy;
int sc_latch;
uint8_t reg2000;
uint8_t chr0, chr1;
static int c2002 = 0;
static inline void setZN(uint8_t v) {
    P = (uint8_t)((P & 0x7D) | (v == 0 ? 0x02 : 0) | (v & 0x80));
}
static uint8_t ppu_memread(uint16_t a) {
    if (a < 0x2000) return 0;
    if (a >= 0x3F00) {
        int idx = (a - 0x3F00) & 0x1F;
        if ((idx & 3) == 0) idx &= 0x0F;
        return pal[idx];
    }
    if (a >= 0x3000) a -= 0x1000;
    a -= 0x2000;
    if (a >= 0x800) a -= 0x400;
    return vram[a & 0x7FF];
}
static void ppu_memwrite(uint16_t a, uint8_t v) {
    if (a < 0x2000) return;
    if (a >= 0x3F00) {
        int idx = (a - 0x3F00) & 0x1F;
        if ((idx & 3) == 0) idx &= 0x0F;
        pal[idx] = v;
        return;
    }
    if (a >= 0x3000) a -= 0x1000;
    a -= 0x2000;
    if (a >= 0x800) a -= 0x400;
    vram[a & 0x7FF] = v;
}
static uint8_t RD(uint16_t a) {
    if (a >= 0xC000) return prg[7][a - 0xC000];
    if (a >= 0x8000) return swbank[a - 0x8000];
    if (a < 0x2000) return ram[a & 0x7FF];
    if (a < 0x4000) {
        int r = a & 7;
        if (r == 2) {
            uint8_t v = 0;
            if ((c2002 % 3) == 2) v |= 0x80;
            c2002++;
            ppu_latch = 0;
            sc_latch = 0;
            return v;
        }
        if (r == 4) return oam[oam_addr];
        if (r == 7) {
            uint16_t rpc = ppu_addr;
            uint8_t out;
            if (rpc >= 0x3F00) {
                int idx = (rpc - 0x3F00) & 0x1F;
                if ((idx & 3) == 0) idx &= 0x0F;
                out = pal[idx];
                ppu_buf = ppu_memread(rpc & 0x2FFF);
            } else {
                out = ppu_buf;
                ppu_buf = ppu_memread(rpc);
            }
            ppu_addr = rpc + ((reg2000 & 4) ? 32 : 1);
            return out;
        }
        return 0;
    }
    if (a == 0x4015) return 0;
    if (a == 0x4016) {
        if (pad_pos1 < 8) return (uint8_t)((pad_bits >> (pad_pos1++)) & 1);
        return 0;
    }
    if (a == 0x4017) {
        if (pad_pos2 < 8) return (uint8_t)((pad_bits >> (pad_pos2++)) & 1);
        return 0;
    }
    return 0;
}
static void WR(uint16_t a, uint8_t v) {
    if (a < 0x2000) { ram[a & 0x7FF] = v; return; }
    if (a < 0x4000) {
        int r = a & 7;
        if (r == 0) reg2000 = v;
        else if (r == 1) { }
        else if (r == 3) oam_addr = v;
        else if (r == 4) oam[oam_addr++] = v;
        else if (r == 5) { if (!sc_latch) scx = v; else scy = v; sc_latch ^= 1; }
        else if (r == 6) { if (!ppu_latch) ppu_addr = (uint16_t)((uint16_t)v << 8) | (ppu_addr & 0xFF); else ppu_addr = (uint16_t)(ppu_addr & 0xFF00) | v; ppu_latch ^= 1; }
        else if (r == 7) { ppu_memwrite(ppu_addr, v); ppu_addr += (reg2000 & 4) ? 32 : 1; }
        return;
    }
    if (a == 0x4014) {
        uint16_t base = (uint16_t)v << 8;
        int i;
        for (i = 0; i < 256; i++) oam[i] = RD(base + i);
        return;
    }
    if (a == 0x4016) {
        if ((strobe == 0) && (v & 1)) { pad_pos1 = 0; pad_pos2 = 0; }
        strobe = v & 1;
        if (strobe) { pad_pos1 = 0; pad_pos2 = 0; }
        return;
    }
    if (a == 0x4017) return;
    if (a < 0x4020) return;
    if (a < 0x6000) return;
    if (a < 0x8000) return;
    if (v & 0x80) { mmc_count = 0; mmc_ctrl |= 0x0C; swbank = prg[0]; return; }
    mmc_shift = ((v & 1) << 4) | (mmc_shift >> 1);
    if (++mmc_count == 5) {
        int reg = (a >> 13) & 3;
        if (reg == 0) mmc_ctrl = (uint8_t)(mmc_shift & 0x1F);
        else if (reg == 1) chr0 = (uint8_t)(mmc_shift & 0x1F);
        else if (reg == 2) chr1 = (uint8_t)(mmc_shift & 0x1F);
        else if (reg == 3) swbank = prg[mmc_shift & 7];
        mmc_count = 0;
        mmc_shift = 0;
    }
    return;
}

#endif
