entry_E895:
        lda     $FF
        and     #$FB
        sta     $2000
        sta     $FF
        rts
entry_E89F:
        lda     $FF
        ora     #$04
        sta     $2000
        sta     $FF
        rts
entry_E996:
        lda     (L007A),y
        sta     L0000
        iny
        bne     LE99F
        inc     $7B
LE99F:  lda     L0000
        rts
