
	IFND LIBRARIES_OX_LIB_I
LIBRARIES_OX_LIB_I	SET	1

; $VER: oxmaster.library   eXternal User Interfaces
;
; -----------------------------------------------------
; m68k assembler includefile and developer informations
; -----------------------------------------------------
;
; 2009 by PseudoDOS/silva@psi5.com
;
; (C) Andreas G. Szabo all rights reserved


	IFND EXEC_TYPES_I
	include "exec/types.i"
	ENDC

; OX library functions
; ---------------------

	LIBINIT

; init ox obejct(s) starting with *object in a0

	LIBDEF	_LVOoxInit			;			a0
						;			*object


; create ox object(s), do not init and not tab-link them

	LIBDEF	_LVOoxCreateOnly		; d0		=	d2	a1	a2
						; *object		type	*base	*tags
						; 0 = fail


; create, init and tab-link ox object(s) starting with type d2 and taglist *a2.

	LIBDEF	_LVOoxCreateObject		; d0		=	d2	a1	a2
						; *object		type	*base	*tags
						; 0 = fail

	LIBDEF	_LVOoxCreateCustom		; d0		=	d2	a0	a1	a2
						; *object		class	*parent	*base	*tags
						; 0 = fail

	LIBDEF	_LVOoxAddMember		;			a0		a1
						;			*head object	*member object


	LIBDEF	_LVOoxRemMember		;			a1
						;			*member object


; call object class function

	LIBDEF	_LVOoxDoMethod			; d0		=	d1		a0		a1
						; result		method ID	*object		*message


	LIBDEF	_LVOoxSetAttr			;			d0		d1		a0
						;			attrib ID	value		*object


	LIBDEF	_LVOoxSetAttrs			;			a0		a1
						;			*object		*tags


	LIBDEF	_LVOoxGetAttr			; d0		=	d0		a0
						; value			attrib ID	*object


	LIBDEF	_LVOoxBroadcast		;			d1		d2	a0	   a1
						;			method ID	mode	*head	   *message


	LIBDEF	_LVOoxBroadcastAttr		;			d0		d1	a0
						;			attrib ID	value	*head


	LIBDEF	_LVOoxNotify			;

	LIBDEF	_LVOoxBroadcastUpdate

	LIBDEF	_LVOoxFreeObject		;			a0
						;			*object(s)

;	custom classed defined by the propgram

	LIBDEF	_LVOoxMakeClass		;d0			a2
						;classhandle		*taglist

	LIBDEF	_LVOoxDeleteClass		;			d2
						;			classhandle

;	external classes (load ony needed if a special version is required or the class should be sticky)
 
	LIBDEF	_LVOoxOpenClass		;d0			d0	a1
						;classhandle		version	*name

	LIBDEF	_LVOoxCloseClass		;			d2
						;			classhandle

; add and remove classes that are IN programs

	LIBDEF	_LVOoxBevelBorder
	LIBDEF	_LVOoxCreateExample

	LIBDEF	_LVOoxFindObjectByID
	LIBDEF	_LVOoxRelink

	LIBDEF	_LVOoxGlobalRefreshGUI



; You can use BeginRefresh() and EndRefresh() around drawing to soften it by doublebuffering (no more flashing).
; If there was no memory for an off-bitmap at window creation time, these functions do nothing!

	LIBDEF	_LVOoxBeginRefresh		; d0		=	d0-d3	   d4		a0
						; *rastport		x,y,w,h	   flags	*window (object)

						; flags		OXRMODEF_COPY	get current content as basis
						;		OXRMODEF_ALL	ignore x,y,w,h and work on full window


	LIBDEF	_LVOoxEndRefresh		;			d0-d3	   d4		a0
						;			x,y,w,h    flags	*window (object)

						; flags		OXRMODEF_SYSGADS	redraw sysgads after refresh
						;		OXRMODEF_ALL		same as for oxBeginRefresh()


; the following prefs routines allways work on the global AND the class specific prefs
; it is not possibe to work on a class specififc pref only

	LIBDEF	_LVOoxDefaultPrefs		; get default config into bases
	LIBDEF	_LVOoxRestorePrefs		; from ENV:
	LIBDEF	_LVOoxLoadPrefs		; from ENVARC:
	LIBDEF	_LVOoxStorePrefs		; to ENV:
	LIBDEF	_LVOoxSavePrefs		; to ENVARC:

	LIBDEF	_LVOoxImageFill
	LIBDEF	_LVOoxImageDraw
	LIBDEF	_LVOoxImageDrawClip
	LIBDEF	_LVOoxGetImageSize
	LIBDEF	_LVOoxGetImage
	LIBDEF	_LVOoxDropImage


; function to chain objects for tab-cycle

	LIBDEF	_LVOoxRingConnect			;		a1		a0		a2 *prevnext
							;		oxRelinkInfo	*this_object	*prev/*next of this

	LIBDEF	_LVOoxRefresh

; end of includefile here  --- Zak McKracken 4 president! ---

	ENDC
