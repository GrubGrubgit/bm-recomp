entry_B4F1:
        lda     #$80
        sta     $42
        lda     #$80
        sta     $43
        lda     $11
        and     #$1F
        bne     LB54F
        jsr     entry_C1B3
        and     #$18
        bne     LB54F
        jsr     entry_C12F
        beq     LB54F
        stx     $05
        lda     #$34
        sta     $0400,x
        lda     $1C
        sta     $0402,x
        lda     $1D
        sta     $0403,x
        jsr     entry_C1B3
        bmi     LB52C
        lda     #$30
        sta     $0406,x
        inc     $0403,x
        jmp     LB53A

LB52C:  lda     #$D0
        sta     $0406,x
        lda     $0403,x
        clc
        adc     #$0F
        sta     $0403,x
LB53A:  jsr     entry_C1B3
        ldx     #$06
        jsr     entry_C20A
        clc
        adc     $4B
        ldx     $05
        sta     $0405,x
        lda     #$24
        jsr     entry_C216
LB54F:  lda     #$10
        sta     $40
        lda     #$10
        sta     $41
        jsr     entry_C0FF
        beq     LB55F
        jmp     entry_C17A

LB55F:  rts
