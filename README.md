# Blaster Master (USA) -- static recompilation repo

Portable higher-level (C) recompilation of Blaster Master (USA, NES, MMC1).
Input: the verified disassembly in ../disasm (plus ../work/roms-dev assets).
No ROMs or copyrighted bytes are committed here -- only original code.

Approach (to be finalized after the tooling review):
- static recompilation of 6502 PRG banks to portable C, one translation
  unit per bank, with a small runtime shim (CPU helpers, PPU/APU stubs
  growing into an HLE layer as understanding improves);
- CHR/data extracted to asset files under assets/ (built locally, ignored);
- byte-parity test harness compares emulated behavior against the
  disassembly at bank/function granularity.

Status: scaffold only (hello build proves the C toolchain).
