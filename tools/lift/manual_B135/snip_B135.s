entry_B135:
        lda     #$40
        sta     $42
        lda     #$40
        sta     $43
        jsr     entry_C01E
        jsr     entry_C138
        bpl     entry_B14B
        jsr     entry_9333
        jmp     entry_C114
entry_B14B:
        lda     #$08
        sta     $40
        lda     #$08
        sta     $41
        jsr     entry_C0FF
        beq     LB15B
        jmp     entry_C114
LB15B:  lda     #$08
        jsr     entry_C147
        lda     #$00
        sta     $44
        lda     #$4E
        sta     $45
        jmp     entry_C1AD
