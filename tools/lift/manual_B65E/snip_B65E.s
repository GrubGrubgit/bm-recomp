entry_B65E:
        lda     #$80
        sta     $42
        lda     #$80
        sta     $43
        lda     $11
        eor     $51
        and     #$7F
        bne     entry_B680
        lda     #$03
        sta     $50
LB672:  jsr     entry_C12F
        beq     entry_B680
        lda     #$4E
        sta     $0400,x
        dec     $50
        bpl     LB672
        jmp     entry_B680
