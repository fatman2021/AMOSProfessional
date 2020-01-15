	IFND SILVA_EASY_I
SILVA_EASY_I	SET	1

bsw	MACRO
	IFGT	\1-7
	  bset	#\1-8,\2
        ENDC
	IFLE	\1-7
	  bset	#\1,1+\2
	ENDC
	ENDM

bcw	MACRO
	IFGT	\1-7
	  bclr	#\1-8,\2
        ENDC
	IFLE	\1-7
	  bclr	#\1,1+\2
	ENDC
	ENDM

btw	MACRO
	IFGT	\1-7
	  btst	#\1-8,\2
        ENDC
	IFLE	\1-7
	  btst	#\1,1+\2	; wenn Ziel (ax) ohne Offset -> Error!
	ENDC
	ENDM

* komfortable Rettungen  (Pseudo-Opcodes)

PUSH	MACRO
	IFEQ	NARG-1
		move.l	\1,-(a7)
	  ELSE
		IFEQ	NARG-2
			move.l	\1,\2,-(a7)
		  ELSE
			move.l	\1,\2,\3,-(a7)
		ENDC
	ENDC
	ENDM

POP	MACRO
	IFEQ	NARG-1
		move.l	(a7)+,\1
	  ELSE
		IFEQ	NARG-2
			move.l	(a7)+,\1,\2
		  ELSE
			move.l	(a7)+,\1,\2,\3
		ENDC
	ENDC
	ENDM

PUSHM	MACRO
	movem.l	\1,-(a7)
	ENDM

POPM	MACRO
	movem.l	(a7)+,\1
	ENDM

PUSHW	MACRO
	movem.w	/1,-(a7)
	ENDM

POPW	MACRO
	movem.w	(a7)+,/1
	ENDM

; end of includefile here  --- Zak McKracken 4 president! ---

	ENDC

