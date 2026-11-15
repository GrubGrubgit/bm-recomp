entry_80C9:
        lda     $89
        lda     $B3
        ldx     $CD
        ldx     $03
        tax
; gap 1 $34
        tax
        cli
        ldy     LAC84
        inc     L8B9F
        sta     L99AD,y
; gap 1 $F2
