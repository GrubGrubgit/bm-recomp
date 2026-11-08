import sys, struct, zlib
STRIDE = 4160
def png_gray(w, h, px):
    raw = b''.join(b'\x00' + bytes(row) for row in px)
    c = zlib.compress(raw, 6)
    def chunk(t, d):
        return struct.pack('>I', len(d)) + t + d + struct.pack('>I', zlib.crc32(t + d) & 0xffffffff)
    return (b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 0, 0, 0, 0)) +
            chunk(b'IDAT', c) + chunk(b'IEND', b''))
def render(snap_path, frame, out_path, chr_path):
    f = open(snap_path, 'rb').read()
    rec = f[frame * STRIDE:(frame + 1) * STRIDE]
    ram = rec[0:2048]
    vr = rec[2048:4096]
    ftr = rec[4096:4160]
    scx, scy, r2000 = ftr[32], ftr[33], ftr[34]
    bg_hi = 0x1000 if (r2000 & 0x10) else 0x0000
    spr_hi = 0x1000 if (r2000 & 0x08) else 0x0000
    spr16 = bool(r2000 & 0x20)
    chrom = open(chr_path, 'rb').read()
    def tile_px(base, t, row):
        lo = chrom[base + t * 16 + row]
        hi = chrom[base + t * 16 + row + 8]
        return [((lo >> (7 - c)) & 1) | (((hi >> (7 - c)) & 1) << 1) for c in range(8)]
    W, H = 256, 240
    px = [[0] * W for _ in range(H)]
    for y in range(H):
        for x in range(W):
            sx = (x + scx) % 256
            sy = (y + scy) % 480
            nt = 1 if sy >= 240 else 0
            if sy >= 240:
                sy -= 240
            tx, ty = sx // 8, sy // 8
            base = 0x400 if nt else 0x000
            t = vr[base + ty * 32 + tx]
            ax = vr[base + 0x3C0 + (ty // 4) * 8 + (tx // 4)]
            sh = (0 if (ty % 4) < 2 else 4) + (0 if (tx % 4) < 2 else 2)
            palhi = (ax >> sh) & 3
            pat = tile_px(bg_hi, t, sy % 8)
            c = pat[sx % 8]
            px[y][x] = (palhi * 64 + c * 21 + 40) % 256 if c else 0
    for s in range(64):
        oy = ram[0x200 + s * 4]
        ti = ram[0x200 + s * 4 + 1]
        at = ram[0x200 + s * 4 + 2]
        ox = ram[0x200 + s * 4 + 3]
        if oy >= 0xEF:
            continue
        hh = 16 if spr16 else 8
        palb = (at & 3) * 64 + 128
        fx = bool(at & 0x40)
        fy = bool(at & 0x80)
        for r in range(hh):
            rr = (hh - 1 - r) if fy else r
            t2 = (ti & 0xFE) + (rr // 8) if spr16 else ti
            b2 = spr_hi if spr16 else (0x1000 if (ti & 0) else bg_hi)
            pat = tile_px(spr_hi, t2, rr % 8)
            yy = oy + 1 + r
            if 0 <= yy < H:
                for c in range(8):
                    cc = (7 - c) if fx else c
                    v = pat[cc]
                    if v:
                        xx = ox + c
                        if 0 <= xx < W:
                            px[yy][xx] = (palb + v * 30) % 256
    open(out_path, 'wb').write(png_gray(W, H, px))
    print('wrote ' + out_path + ' sc=%d,%d r2000=%02X' % (scx, scy, r2000))
render(sys.argv[1], int(sys.argv[2]), sys.argv[3], sys.argv[4])
