entry_DEC2:
        jsr     entry_DF05
        jsr     LBFE5
        jsr     entry_DF0A
        rts

; synthetic probe: direct xbank call for trap test
entry_XBPB:
        jsr     LBFE8
        rts
