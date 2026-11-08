entry_C9A4:
        ldx     #$40
        lda     $14
        and     #$08
        beq     LC9AE
        ldx     #$60
LC9AE:  txa
        pha
        jsr     entry_EA3A
        pla
        lsr     a
        lsr     a
        lsr     a
        lsr     a
        and     #$0F
        sta     $D3
        lda     $46
        sec
        sbc     #$01
        jsr     entry_EB51
        lda     $15
        bne     LC9D3
        clc
        lda     L007A
        adc     #$03
        sta     L007A
        bcc     LC9D3
        inc     $7B
LC9D3:  jmp     (L007A)

LC900:  inc     $10
        rts
