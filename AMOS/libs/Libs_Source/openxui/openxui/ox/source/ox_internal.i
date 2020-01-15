;==================================================
; Open XUI internal definitions

; OX class
;
; this is the node for every class that is actually loaded into the system

 STRUCTURE	oxClass,0
	STRUCT	oxC_node,MLN_SIZE
	APTR	oxC_header		; points back to loaded segment if any
	APTR	oxC_name
	APTR	oxC_verstring
	APTR	oxC_description
	APTR	oxC_author
	ULONG	oxC_owner		; *task to distinguish private classes
	UBYTE	oxC_flags
	UBYTE	oxC_pad
	UWORD	oxC_version
	UWORD	oxC_revision
	UWORD	oxC_opencount
	ULONG	oxC_objectsize
	APTR	oxC_dispatcher
	APTR	oxC_constructor
	APTR	oxC_initclass
	APTR	oxC_deinitclass
	APTR	oxC_makeexample
	ULONG	oxC_basesize
	APTR	oxC_base
	APTR	oxC_envarray
	LABEL	oxC_SIZEOF

	BITDEF	oxC,USER,0	; a class within the program, added with oxMakeClass() by the program


; OX environment variables

oxEt_text	= 0	; %00000000
oxEt_byte	= 1	; %00000001
oxEt_word	= 2	; %00000010
oxEt_long	= 3	; %00000011
oxEt_HEX	= 4	; %00000100
oxEtB_HEX	= 2	;   bit 2
oxEt_FLAG	= 8	; %00001000	envvariable is parsed for "ON" or "OFF"
oxEtB_FLAG	= 3	;  bit 3

;		= 16	; reserved

oxEt_COLOR	= 32	; this variable is a color, allways an ULONG
oxEt_PEN	= 48	; pens are allways UBYTE
oxEt_PATH	= 64	; this and the rest of types are APTRs to strings
oxEt_FILE	= 80	; path and file are different (!)
oxEt_FONT	= 96
oxEt_ICON	= 112	; icon used as image f.e. for a symbol on a button; drag and drop onto config editor
oxEt_IMAGE	= 128	; images for backfills and logo; drag and drop onto config editor


oxEt_SIZEMASK	= %00000011
oxEt_MASK	= %00001111	; format
oxEt_EMASK	= %11110000	; editor info

oxEt_FOLDER	= %11111111	; -1 means env structs marked by this are folders for next #numfold (see below) next structures
				; this is skipped in the load/save/restore/etc config processes

