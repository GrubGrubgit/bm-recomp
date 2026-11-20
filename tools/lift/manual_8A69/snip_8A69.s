L8A69:
        nop
        nop
        nop
        lda     #$18
        sta     $40
        lda     #$10
        sta     $41
        jsr     entry_C0FF
        lda     #$00
        sta     $44
        jsr     entry_93BD
        inc     $51
        bne     LB8A84
        dec     $51
LB8A84: lda     $51
        cmp     #$A0
        bne     LB8A8F
        lda     #$02
        jsr     entry_C11A
LB8A8F: lda     $51
        lsr     a
        lsr     a
        tax
        cpx     #$18
        bcc     LB8A9A
        ldx     #$17
LB8A9A: lda     $8AA3,x
        clc
        adc     #$1B
        jmp     entry_C063
