entry_C05D:
        jmp     entry_D02D
entry_B102:
        inc     $46
        jsr     entry_C0FF
        lda     $3E
        sta     $00
        lda     $3F
        sta     $01
        lda     $7C
        sta     $02
        lda     $7D
        sta     $03
        jsr     entry_C05D
        lda     $4D
        ldx     #$01
        jsr     entry_C20A
        sta     $4D
        lda     $4C
        ldx     #$01
        jsr     entry_C20A
        sta     $4C
        lda     #$1A
        jsr     entry_C216
        rts
