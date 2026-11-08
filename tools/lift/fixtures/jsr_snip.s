entry_E974:
        pha
        jsr     entry_E996
        pla
LE979:  pha
        lda     L0000
        jsr     LE9A2
        pla
        sec
        sbc     #$01
        bne     LE979
        rts
LE9A2:  sta     $2007
        rts
