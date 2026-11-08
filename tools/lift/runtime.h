#ifndef LIFT_RUNTIME_H
#define LIFT_RUNTIME_H
// Runtime shim for lifted Blaster Master code (prototype).
// CPU state + memory map (RAM, PRG images, pad MMIO with split ports).
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
int mmc_shift = 0, mmc_count = 0;
uint8_t mmc_ctrl = 0x0C;
static inline void setZN(uint8_t v) {
    P = (uint8_t)((P & 0x7D) | (v == 0 ? 0x02 : 0) | (v & 0x80));
}
static uint8_t RD(uint16_t a) {
    if (a >= 0xC000) return prg[7][a - 0xC000];
    if (a >= 0x8000) return swbank[a - 0x8000];
    if (a < 0x2000) return ram[a & 0x7FF];
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
    if (a == 0x4016) {
        if ((strobe == 0) && (v & 1)) { pad_pos1 = 0; pad_pos2 = 0; }
        strobe = v & 1;
        if (strobe) { pad_pos1 = 0; pad_pos2 = 0; }
        return;
    }
    if (a >= 0x8000) {
        if (v & 0x80) { mmc_count = 0; mmc_ctrl |= 0x0C; swbank = prg[0]; return; }
        mmc_shift = ((v & 1) << 4) | (mmc_shift >> 1);
        if (++mmc_count == 5) {
            int reg = (a >> 13) & 3;
            if (reg == 0) mmc_ctrl = (uint8_t)(mmc_shift & 0x1F);
            else if (reg == 3) swbank = prg[mmc_shift & 7];
            mmc_count = 0;
            mmc_shift = 0;
        }
        return;
    }
}

#endif
