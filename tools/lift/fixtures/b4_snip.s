LB1F9:  sta     $00
        asl     a
        asl     a
        asl     a
        asl     a
        clc
        adc     $48
        php
        sta     $48
        lda     $00
        cmp     #$80
        bcc     LB214
        ora     #$0F
        ror     a
        ror     a
        ror     a
        ror     a
        jmp     LB218
LB214:  lsr     a
        lsr     a
        lsr     a
        lsr     a
LB218:  plp
        adc     $49
        sta     $49
        rts
