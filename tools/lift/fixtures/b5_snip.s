L839A:  lda     $0787,x
        ora     #$20
        sta     $0787,x
        rts

LBEA6:  lda     $07F5
        and     #$FE
        sta     $07F5
        rts
