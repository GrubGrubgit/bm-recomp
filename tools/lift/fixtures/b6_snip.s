entry_B600:
        ldx     #$03
LB604:  dex
        bne     LB604
        rts

entry_B610:
        lda     $10
        bne     entry_B600
        rts
