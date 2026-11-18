entry_B563:
        lda     #$80
        sta     $42
        lda     #$80
        sta     $43
        lda     $11
        asl     a
        asl     a
        asl     a
        ldy     #$20
        jsr     entry_C1FE
        jsr     entry_C20D
        sta     $4D
        jsr     entry_C01E
        lda     #$10
        sta     $40
        lda     #$10
        sta     $41
        jsr     entry_C0FF
        beq     entry_B58D
        jmp     entry_C114
entry_B58D:
        rts
