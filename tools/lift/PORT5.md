# Port5: vec007A bank6 area-5..8 actor-init vectors (warp traps, 2026-11-23)

## Why manual
The 0.2.47 tweaks menu added area warp (bm_warp). Warps to area idx 4,6,7
(game areas 5,7,8) trapped in vec007A default: first vectors B497/B91D/A8D5.
Headless warp matrix on production game.wasm reproduced all three.
Deeper soaks (warp + 4000f synthetic play) exposed 12 more in the same
family. All 15 were ByteTable gaps (da65 data) that are real game code on
the area-5+ actor-load path. The TAS corpus never leaves areas 1-3, so the
trace-driven vec007A table never observed them: coverage gap, not a
lifter bug. Natural area-5+ entry hits the same vectors.

## Vectors (all bank6, guarded swbank==prg[6] cases)
B494 (jmp B4A2 null), B497 (lda17 family), B91D (lda49/lsr/bcc fork),
B4A6 (long init, falls into B508), A8D5 (lda06 family), B97D (forked init,
falls into B9C0), BA03 (lda80 fork), B53D (forked init), B202 (lda13 leaf),
B58E (forked init, falls into B5FB), B57B (lda18 family), B575 (jmp F011),
B578 (jmp B58A null), B20F (forked init, falls into B23F), B253 (forked
init, falls into B26C). Fallthroughs transcribed as second entries (exact,
zero-cycle); same-bank external JMPs via stub slot; all JSR targets
pre-existing (xresolve verified, one each in ADDRMAP).

## Cases
Guarded bank6 cases appended after the B846/AC63 cluster in both
combined_off.c and combined_enf.c decl blocks (both), bodies (before the
fallthrough target body), switch, ADDRMAP, PROV_ALL, vec007A 6-line.
Splice scripts wp_port5.py (B494/B497/B91D/A8D5), wp_port5b.py
(B4A6/B97D), wp_port5c.py (BA03), wp_port5d.py + wp_port5d_fix.py
(B202/B53D; enf block2 lacks B3FE so its B202 decl went block1-only),
wp_port5e.py (B575/B578/B57B/B20F), wp_port5f.py (B58E/B253).

## Verify
gcc -fsyntax-only -Wall -Wextra: off zero warnings; enf warnings are
pre-existing (97 lines on HEAD too, none on the new functions).
Warp matrix 8/8 clean (1700f each), gameplay soaks 4x4000f + 4x15000f
(right/left/up/down/pause cycling) clean, full TAS movie-area13 replay
120568f trap-free on the final engine (proves no area 1-3 regression).
Areas 5-8 have no TAS oracle; soaks are the coverage. More ByteTable
gap vectors may exist deeper in areas 5-8 (same whack-a-mole applies).
