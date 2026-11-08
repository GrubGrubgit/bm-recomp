LC3AA:  jsr     entry_C772
        lda     #$00
        sta     $8E
        lda     #$00
        sta     $56
        jsr     LC928
        jsr     entry_C9D6
        jsr     entry_D7B6
        jsr     entry_CE0F
        lda     $C5
        bit     LE6E1
        beq     entry_C3D5
        lda     #$00
        sta     $56
        jsr     LC8DF
        jsr     L0000
        jmp     entry_C465
