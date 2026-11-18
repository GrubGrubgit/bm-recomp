entry_AF45:
        jmp     LAF66
entry_AF48:
        lda     $50
        asl     a
        asl     a
        asl     a
        asl     a
        asl     a
        asl     a
        sta     $52
        lda     #$10
        sta     $51
        lda     #$00
        sta     $4C
        sta     $4D
        inc     $46
        jsr     entry_C1EC
        lda     #$1B
        jsr     entry_C216
LAF66:  rts
entry_AF67:
        jmp     entry_AF99
entry_AF6A:
        lda     #$80
        sta     $42
        lda     #$80
        sta     $43
        lda     $11
        and     #$03
        cmp     $50
        bne     LB96
        clc
        lda     $51
        adc     #$03
        sta     $51
        cmp     #$70
        bcc     LB88
        jmp     entry_C114
LB88:   lda     $11
        asl     a
        asl     a
        clc
        adc     $52
        sta     $47
        ldy     $51
        jsr     entry_C1EF
LB96:   jsr     entry_C01E
        jmp     entry_AF99
