; ***************************** Screen Replacement Plugin Calls

ScreenReplacementM MACRO
    tst.l      T_ScrnRepVct(a5)
    beq.s      .er\@               ; No -> Jump .erXX
    move.l     T_ScrnRepVct(a5),\2 ; This pointer is populated when the AgaSupport.lib is started
    add.l      \1*6,\2             ; Point to the chosen method to call 
    tst.l      (\2)                ; is the method defined ?
    beq.s      .er\@               ; No -> Jump .erXX
    jsr        (\2)                ; Yes -> Jsr chosen Method.
    rts
.er\@:
            ENDM


ScreenReplacement MACRO
    ScreenReplacementM \1,a0
            ENDM

ScreenReplacementA1 MACRO
    ScreenReplacementM \1,a1
            ENDM

ScreenReplacementA2 MACRO
    ScreenReplacementM \1,a2
            ENDM

ScreenReplacementA4 MACRO
    ScreenReplacementM \1,a4
            ENDM

; ***************************** calls

RestartWithAGACopperList       equ  0 ; Amos.library "CpInit" method.
InsertSpritesInCopper          equ  1 ; Amos.library "HsCop" method.
InsertScreenInCopper           equ  2 ; Amos.library "EcCopHo" replacement
ForceFullCopperRefresh         equ  3 ; Amos.library "EcForceCop" replacement
CopperRefresh                  equ  4 ; Amos.library "EcCopper" replacement
EndOfScreenCopper              equ  5 ; Amos.library "EcCopBa" replacement
CopperOnOff                    equ  6 ; Amos.library "TCopOn" replacement
CopperSwap                     equ  7 ; Amos.library "TCopSw" replacement
CopperSwapInternal             equ  8 ; Amos.library "TCpSw" replacement

ScreenOpen                     equ 20 ; Amos.libraru "EcCree" replacement
NewScreenClose                 equ 21 ; Amos.library "EcDel" method.
NewDualPlayfield               equ 22 ; Amos.library "EcDual" method.
SetColourRGB12                 equ 23 ; Amos.library "EcSCol" method.
 