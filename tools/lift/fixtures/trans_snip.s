LC7C7:  tya
        eor     #$01
        tay
        lda     (L0000),y
        sta     $14
        lda     ($02),y
        sta     $49
        lda     ($04),y
        sta     $4B
        rts
entry_CA14:
        lda     $14
        and     #$0F
        asl     a
        tax
        lda     LCA2B,x
        sta     $49
        lda     LCA2C,x
        sta     $4B
        lda     #$80
        sta     $48
        sta     $4A
        rts
