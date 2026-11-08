// Runtime shim for lifted Blaster Master code (prototype).
// CPU state + memory map (RAM, PRG images, pad MMIO with split ports).
#include <stdint.h>
#include <stdio.h>
#include <string.h>
uint8_t ram[0x800];
uint8_t A, X, Y, S, P;
uint8_t pad_bits;
int pad_pos1, pad_pos2, strobe;
static inline void setZN(uint8_t v) {
    P = (uint8_t)((P & 0x7D) | (v == 0 ? 0x02 : 0) | (v & 0x80));
}
static uint8_t RD(uint16_t a) {
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
}
