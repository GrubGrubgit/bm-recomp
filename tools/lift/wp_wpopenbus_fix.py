import os
BASE = "/data/data/com.termux/files/home/storage/AiAgent/def7cmrvqe"
FILES = [BASE+"/recomp/tools/lift/runtime.h", BASE+"/recomp/gen/combined_off.c", BASE+"/recomp/gen/combined_enf.c", BASE+"/work/probe/pgame.c"]
NL = chr(10)
REPS = [
# 1. latch declaration after reg2001
("uint8_t reg2001;", "uint8_t reg2001;"+NL+"uint8_t ppu_openbus;"),
# 2. every PPU-reg write latches the bus (Mesen PPU::WriteRAM SetOpenBus pre-switch)
("    if (a < 0x4000) {"+NL+"        int r = a & 7;"+NL+"        if (r == 0) reg2000 = v;",
 "    if (a < 0x4000) {"+NL+"        int r = a & 7;"+NL+"        ppu_openbus = v;"+NL+"        if (r == 0) reg2000 = v;"),
# 3. 2002 read: latch[7:5]=status (port has vblank only; sprite bits unemulated, documented gap)
("            ppu_latch = 0;"+NL+"            sc_latch = 0;"+NL+"            return v;",
 "            ppu_latch = 0;"+NL+"            sc_latch = 0;"+NL+"            ppu_openbus = (uint8_t)((ppu_openbus & 0x1F) | (v & 0xE0));"+NL+"            return v;"),
# 4. 2004 OAMDATA read latches the value (Mesen mask 0x00)
("        if (r == 4) return oam[oam_addr];",
 "        if (r == 4) { ppu_openbus = oam[oam_addr]; return ppu_openbus; }"),
# 5a. 2007 palette read: latch[5:0]=palette (Mesen ApplyOpenBus 0xC0 path)
("                out = pal[idx];",
 "                out = pal[idx];"+NL+"                ppu_openbus = (uint8_t)((ppu_openbus & 0xC0) | (out & 0x3F));"),
# 5b. 2007 VRAM read: latch=buffered byte (Mesen mask 0x00 path)
("                out = ppu_buf;",
 "                out = ppu_buf;"+NL+"                ppu_openbus = out;"),
# 6. write-only PPU mirrors (2000/2001/2003/2005/2006) read back the latch, not 0
("            ppu_addr = rpc + ((reg2000 & 4) ? 32 : 1);"+NL+"            return out;"+NL+"        }"+NL+"        return 0;",
 "            ppu_addr = rpc + ((reg2000 & 4) ? 32 : 1);"+NL+"            return out;"+NL+"        }"+NL+"        return ppu_openbus;"),
]
for path in FILES:
    s = open(path).read()
    for old, new in REPS:
        assert s.count(old) == 1, "anchor in "+path+": "+old[:60]
        s = s.replace(old, new, 1)
    open(path, "w").write(s)
    print("fixed "+path)
print("openbus fix ok")
