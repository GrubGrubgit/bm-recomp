entry_D136:
        lda     #$10
        bit     $4C
        bmi     LD13E
        lda     #$F0
LD13E:  clc
        adc     $4C
        sta     $4C
        lda     #$10
        bit     $4D
        bmi     LD150
        lda     #$F0
        clc
        adc     $4D
        sta     $4D
LD150:  rts
entry_D151:
        lda     $0403
        sec
        sbc     $49
        sta     L0000
        lda     $0405
        sec
        sbc     $4B
        sta     $01
entry_D161:
        lda     L0000
        sec
        sbc     $01
        asl     a
        asl     a
        rol     $02
        lda     L0000
        clc
        adc     $01
        asl     a
        asl     a
        rol     $02
        lda     $02
        and     #$03
        tax
        lda     LD17D,x
        tax
        rts
entry_D02D:
        lda     #$00
        sta     $04
        lda     L0000
        sec
        sbc     $02
        ror     $04
        bmi     LD03F
        lda     $02
        sec
        sbc     L0000
LD03F:  sta     L0000
        lda     $01
        sec
        sbc     $03
        ror     $04
        bmi     LD04F
        lda     $03
        sec
        sbc     $01
LD04F:  sta     $01
        cmp     L0000
        beq     LD083
        bcs     LD061
        ldx     $01
        lda     L0000
        sta     $01
        stx     L0000
        inc     $04
LD061:  lda     #$20
        sta     $05
        ldx     #$00
LD067:  asl     L0000
        bcs     LD071
        lda     L0000
        cmp     $01
        bcc     LD07D
LD071:  lda     L0000
        sec
        sbc     $01
        sta     L0000
        txa
        clc
        adc     $05
        tax
LD07D:  lsr     $05
        bne     LD067
        beq     LD085
LD083:  ldx     #$40
LD085:  lda     LD0B4,x
        sta     $4C
        lda     LD0F5,x
        sta     $4D
        lda     #$01
        bit     $04
        beq     LD09D
        ldx     $4C
        lda     $4D
        sta     $4C
        stx     $4D
LD09D:  asl     $04
        bcc     LD0A8
        lda     #$00
        sec
        sbc     $4D
        sta     $4D
LD0A8:  asl     $04
        bcc     LD0B3
        lda     #$00
        sec
        sbc     $4C
        sta     $4C
LD0B3:  rts
