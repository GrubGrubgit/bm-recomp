entry_D7C0:
        ldy     #$01
LD7C2:  inx
        lda     $46,y
        sta     $0400,x
        iny
        cpy     #$0E
        bne     LD7C2
        rts
entry_D7CF:
        lda     $0400,x
        beq     LD7E0
        cpx     L0000
        beq     LD7E2
        txa
        clc
        adc     #$0E
        tax
        jmp     entry_D7CF

LD7E0:  lda     #$FF
LD7E2:  rts
entry_D804:
        ldy     $57
        cpy     #$08
        bcc     entry_D81C
        inc     $C6
        lda     $C6
        and     #$3F
        tax
        lda     $F8,y
        sta     $010A,x
        lda     #$FF
        sta     $F8,y
entry_D81C:
        lda     #$00
        sta     $46
        sta     $4F
        rts
LE2AB:  ldy     $CD
        lda     $D1
        sta     ($CE),y
        iny
        lda     $D0
        sta     ($CE),y
        iny
        bne     LE2BE
        lda     #$FF
        sta     $06F3
LE2BE:  sty     $CD
LE2C0:  rts
