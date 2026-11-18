entry_B64D:
        jmp     LB65A
entry_B650:
        lda     #$08
        jsr     entry_B2B4
        ldx     $11
        inx
        stx     $51
LB65A:  rts
