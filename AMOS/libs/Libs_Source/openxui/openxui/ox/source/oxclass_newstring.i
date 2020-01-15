	IFND LIBRARIES_OX_CLASSES_NEWSTRING_I
LIBRARIES_OX_CLASSES_NEWSTRING_I	SET	1

; newlist class for open source external user interfaces
; Andreas G. Szabo

		include	p:ox.i
		include exec/types.i

; hooks get: a0 and a3 *stringgad, a1 and a5 *oxNSSelInfo (see below), a4 *base from oxO_userbase(a3)

 STRUCTURE	oxNSSelInfo,0
	APTR	oxNSSI_object
	APTR	oxNSSI_string		; * to internal buffer (!)
	UWORD	oxNSSI_lenght
	ULONG	oxNSSI_value
	UBYTE	oxNSSI_char		; for edithook only, hook must return new char or 0 in d0,
					; where 0 means to skip that input
	UBYTE	oxNSSI_pad
	LABEL	oxNSSI_SIZEOF

; string attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxNSA_enterhook		; called when enter is pressed, gets oXNSelInfo in a1 and value in d0
	XITEM	oxNSA_edithook		; called on every char input, gets oXNSelInfo in a1 and char in d0

	XITEM	oxNSA_enterobject	; this object is acitvated when enter is pressed

	XITEM	oxNSA_maxlenght
	XITEM	oxNSA_string		; set string into buffer (copied)

	XITEM	oxNSA_hex
	XITEM	oxNSA_dez
	XITEM	oxNSA_even

	XITEM	oxNSA_minvalue
	XITEM	oxNSA_maxvalue
	XITEM	oxNSA_value
	XITEM	oxNSA_softvalue

	XITEM	oxNSA_ghosted

	XITEM	oxNSA_delfirst		; clear the content of the gadget when it is activcated the first time! 

; string methods

		ENUM	OX_METHODS_CLASS

; Zak McKracken for President

	ENDC
