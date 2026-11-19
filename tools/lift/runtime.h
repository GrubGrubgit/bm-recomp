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
int uw_888C;
int uw_9488;
int uw_9434;
int uw_9007;
const char *uw_caller;
const char *uw_callee;
uint64_t cycles;
uint16_t _cycpp;
uint64_t nmi_next_edge;
int nmi_armed;
int in_nmi;
void (*nmi_fire_fn)(void);
uint8_t (*pad_sample_fn)(uint64_t);
void (*nmi_log_fn)(const char *, uint64_t);
int (*uw_local_fn)(const char *, const char *, const char *);
#define CYCLES_PER_FRAME 29781
#define VBLANK_START (29781 - 2273)
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
uint8_t reg2001;
uint8_t ppu_openbus;
uint8_t pad_latch1, pad_latch2;
static int trim_L6CD = 0;
static int trim_8C00 = 0;

static inline void setZN(uint8_t v) {
    P = (uint8_t)((P & 0x7D) | (v == 0 ? 0x02 : 0) | (v & 0x80));
}
static uint64_t wall_no = 0;
static uint64_t pad_wall = 0;
static uint64_t vbl_ack_wall = (uint64_t)-1; static uint64_t ppu_mclk = 0; static uint64_t mcpu_clk = 108; static uint64_t synced_cyc = 9; static int ppu_scan = -1; static int ppu_dot = 340; static uint32_t ppu_frame = 1; static uint8_t vblank_on = 0; static uint8_t cpu_nmi = 0; static uint8_t cpu_nmi_prev = 0; static uint8_t need_nmi = 0; static uint8_t prevent_vbl = 0; static uint8_t frame_pad = 0; static uint8_t polled_pad = 0; static uint64_t last_poll_cyc = 9; static uint64_t max_poll_gap = 0; static const char *max_gap_site = "none"; static uint64_t max_gap_wall = 0; static uint64_t max_gap_cyc = 0;
static inline int in_vblank_raw(void) {
    return (cycles % CYCLES_PER_FRAME) >= (uint64_t)VBLANK_START;
}
static inline __attribute__((unused)) int in_vblank(void) {
    return in_vblank_raw() && (wall_no != vbl_ack_wall);
}
static inline void ppu_step(void) {
    if (ppu_dot < 340) {
        ppu_dot++;
        if (ppu_scan < 240) {
            if (ppu_scan == -1) {
                if (ppu_dot == 1) { vblank_on = 0; cpu_nmi = 0; }
                else if (ppu_dot == 339 && (ppu_frame & 1) && (reg2001 & 0x18)) { ppu_dot = 340; }
            }
        } else if (ppu_scan == 241 && ppu_dot == 1) {
            if (!prevent_vbl) { vblank_on = 1; if (reg2000 & 0x80) { cpu_nmi = 1; } }
            prevent_vbl = 0;
        }
    } else {
        ppu_dot = 0;
        ppu_scan++;
        if (ppu_scan > 260) { ppu_scan = -1; }
        else if (ppu_scan == 240) { wall_no++; ppu_frame++; pad_wall = wall_no - 1; } else if (ppu_scan == 241) { if (pad_sample_fn) polled_pad = pad_sample_fn(wall_no); }
    }
}
static inline void sync_dots(void) {
    if (cycles != synced_cyc) {
        mcpu_clk += (cycles - synced_cyc) * 12ULL;
        synced_cyc = cycles;
        uint64_t target = mcpu_clk - 1;
        while (ppu_mclk + 4 <= target) { ppu_step(); ppu_mclk += 4; }
        if (cpu_nmi && !cpu_nmi_prev) { need_nmi = 1; }
        cpu_nmi_prev = cpu_nmi;
    }
}
static inline void nmi_poll(const char *site); static void nmi_fire_now(uint64_t frame, const char *site) {
    frame_pad = pad_sample_fn ? pad_sample_fn(wall_no) : 0; pad_bits = frame_pad;
    { uint8_t sP = P;
      uint8_t sS = S;
      in_nmi = 1;
      cycles += 7; nmi_poll("auto");
      if (nmi_fire_fn) nmi_fire_fn();
      in_nmi = 0;
      if (S != sS) fprintf(stderr, "NMI-S-DRIFT %02X->%02X at %s\n", sS, S, site);
      P = sP; }
    if (nmi_log_fn) nmi_log_fn(site, frame);
}
static inline void nmi_poll(const char *site) {
    if (!nmi_armed || !nmi_fire_fn) return;
    { uint64_t _gap = cycles - last_poll_cyc; if (_gap > max_poll_gap) { max_poll_gap = _gap; max_gap_site = site; max_gap_wall = wall_no; max_gap_cyc = cycles; } }
    last_poll_cyc = cycles;
    sync_dots();
    if (in_nmi) return;
    if (need_nmi) {
        need_nmi = 0;
        nmi_fire_now(wall_no, site);
    }
}
static inline int vram_phys(uint16_t a) {
    uint16_t b = a;
    if (b >= 0x3000) b -= 0x1000;
    b -= 0x2000;
    int nt = (b >> 10) & 3;
    int off = b & 0x3FF;
    int mir = mmc_ctrl & 3;
    int phys;
    if (mir == 0) phys = 0;
    else if (mir == 1) phys = 1;
    else if (mir == 2) phys = (nt & 1);
    else phys = (nt >> 1);
    return phys * 0x400 + off;
}
static uint8_t ppu_memread(uint16_t a) {
    if (a < 0x2000) return 0;
    if (a >= 0x3F00) {
        int idx = (a - 0x3F00) & 0x1F;
        if ((idx & 3) == 0) idx &= 0x0F;
        return pal[idx];
    }
    return vram[vram_phys(a)];
}
static void ppu_memwrite(uint16_t a, uint8_t v) {
    if (a < 0x2000) return;
    if (a >= 0x3F00) {
        int idx = (a - 0x3F00) & 0x1F;
        if ((idx & 3) == 0) idx &= 0x0F;
        pal[idx] = v;
        return;
    }
    vram[vram_phys(a)] = v;
}
static uint8_t RD(uint16_t a) { sync_dots();
    if (a >= 0xC000) return prg[7][a - 0xC000];
    if (a >= 0x8000) return swbank[a - 0x8000];
    if (a < 0x2000) return ram[a & 0x7FF];
    if (a < 0x4000) {
        int r = a & 7;
        if (r == 2) {
            uint8_t v = 0;
            if (vblank_on) { v |= 0x80; }
            ppu_latch = 0;
            sc_latch = 0;
                        if (ppu_scan == 241 && ppu_dot == 0) { prevent_vbl = 1; }
            vblank_on = 0;
            cpu_nmi = 0;
            ppu_openbus = (uint8_t)((ppu_openbus & 0x1F) | (v & 0xE0));
            return (uint8_t)(v | (ppu_openbus & 0x1F));
        }
        if (r == 4) { ppu_openbus = oam[oam_addr]; return ppu_openbus; }
        if (r == 7) {
            uint16_t rpc = ppu_addr;
            uint8_t out;
            if (rpc >= 0x3F00) {
                int idx = (rpc - 0x3F00) & 0x1F;
                if ((idx & 3) == 0) idx &= 0x0F;
                out = pal[idx];
                ppu_openbus = (uint8_t)((ppu_openbus & 0xC0) | (out & 0x3F));
                ppu_buf = ppu_memread(rpc & 0x2FFF);
            } else {
                out = ppu_buf;
                ppu_openbus = out;
                ppu_buf = ppu_memread(rpc);
            }
            ppu_addr = rpc + ((reg2000 & 4) ? 32 : 1);
            return out;
        }
        return ppu_openbus;
    }
    if (a == 0x4015) return 0;
    if (a == 0x4016) {
        if (strobe) {
            if (pad_sample_fn) { uint8_t live = polled_pad; return live & 1; }
            return pad_latch1 & 1;
        }
        if (pad_pos1 < 8) return (uint8_t)((pad_latch1 >> (pad_pos1++)) & 1);
        return 0;
    }
    if (a == 0x4017) {
        if (strobe) return 0;
        if (pad_pos2 < 8) return (uint8_t)((pad_latch2 >> (pad_pos2++)) & 1);
        return 0;
    }
    return 0;
}
static void WR(uint16_t a, uint8_t v) { sync_dots();
    if (a < 0x2000) { ram[a & 0x7FF] = v; return; }
    if (a < 0x4000) {
        int r = a & 7;
        ppu_openbus = v;
        if (r == 0) {
            reg2000 = v;
            if (!(v & 0x80)) { cpu_nmi = 0; }
            else if (vblank_on) { cpu_nmi = 1; }
        }
        else if (r == 1) reg2001 = v;
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
        cycles += ((cycles & 1) ? 514 : 513);
        return;
    }
    if (a == 0x4016) {
        if (v & 1) {
            pad_pos1 = 0; pad_pos2 = 0;
            if (pad_sample_fn) { uint8_t live = polled_pad; pad_latch1 = live; pad_latch2 = 0; pad_bits = live; }
            else { pad_latch1 = 0; pad_latch2 = 0; }
        }
        strobe = v & 1;
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

