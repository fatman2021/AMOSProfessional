VERSION		EQU	47
REVISION	EQU	1

DATE	MACRO
		dc.b '11.10.1999'
		ENDM

VERS	MACRO
		dc.b 'gtlayout.library 47.1'
		ENDM

VSTRING	MACRO
		dc.b 'gtlayout.library 47.1 (11.10.1999)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: gtlayout.library 47.1 (11.10.1999)',0
		ENDM
