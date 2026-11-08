LE914:  ldx     $FB
        inx
        stx     $4016
        dex
        stx     $4016
        ldx     #$08
entry_E920:
        lda     $4016
        and     #$03
        cmp     #$01
        rol     $F7
        lda     $4017
        and     #$03
        cmp     #$01
        rol     $F8
        dex
        bne     entry_E920
        rts
