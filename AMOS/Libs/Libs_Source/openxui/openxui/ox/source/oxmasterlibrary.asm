; ----------------------------------------

; $VER: OXMASTER.LIBRARY v1 m68k source

; 2003/2009/2010 by PseudoDOS / silva@psi5.com
; (C) Andreas G. Szabo all rights reserved

; ----------------------------------------

;POSSIBLE TASKS
;- wenn ne liste aufgeklappt wird, so weit runter scrollen dass alle neu sichtbaren zeilen ins feld rücken, aber maximal nur
;  um so viele zeilen verschieben so dass der folder selbst höchstens an der oberkante hin kommt 
;- globales oxA_propw u.ä. und das von create abarbeiten lassen statt lokales oxXXA_propw für classeigenen dispatcher
;- move linkpriv and active flag to object part of object and a custom routine?
;- ACTIVE ? in objekt standard-flags
;- automagische hadnhabung von front/back und dass DRAW dann (nicht) ausgeführt wird.
;- make setattrs call update if all tags done
;- frame: x/y offset for content when its bigger than visible part, makes sense with scrollers
;- "bullshit" mini guru handler
;- group: bei aufteilung des platzes an die elemente optimiert runden damit die ganze breite
;  oder höhe voll ausgenutzt wird und bei vielen elementen kein platz übrig bleibt
;-  beginrefresh copy etc siehe ox.i
;- BroadcastAttrs (mehrzahl also mit tagliste)
;- setlayout erst wenn fenster offen und dependete objektteile erzeugt worden sind,
;  dependente objektteile sind zb das colorwheel gagdget das erst erzeugt werden kann wenn
;  das fenster schon offen ist
;- case insensitivity for senschars
;- shift+backspace in string deletes complete string, shift+cursor ganz links oder ganz rechts

; FILEREQUESTER class to show power of ox
;- default paths via popup menu
;- options / menu: show (.info) (monthday) (year) (time); comment/edit; dirsfirst/dirslast/dirsmixes; sort names/size/time a-z/z-a

;KNOWN BUGS

;- wenn OFF geschaltet wird und vorher ON war und eine andere configvariable ausgewählt wird, bleibt
;  natürlich bis auf den rechten teil (der erneuert wird) alles tab mit bg image bestehen. es wäre gut
;  wenn der wert nicht sofort aktiv wird; das image müsste auch dropped werden wenn man auf OFF geht...
;- wheel: num pens zu groß aber wennich einen weglasse ist der verlauf unfertig
;- vertikales zentrieren von text im feld setzt den text zu tief, field höhe wächst wenn es wide ist,
;  auch wenn das nicht erwünscht ist
;- leere liste soll nicht mit relinkt werden, eine mit inhalt aber schon
;  (test oxL_list auf null hat nicht funktioniert, es war immer "kein entry vorhanden")
;- tabs und pages können nicht (crash) on the fly hinuz- or weggefügt werden solange
;  die drawinfo nicht empfangen wurde 
;- scrollen mit knob maus soll an der selben stelle des knobs bleiben auch wenn maus über den rand raus geht

OXREVISION	=	0	; <- revision, ox.i contains version

		; revision: fixes
		; version : new features, not compatible

oxVERSTRING	MACRO
		dc.b	"Open eXternal User Interfaces master library ",$30+OXVERSION,".",$30+OXREVISION,$a
		dc.b	"2003-2010 by Andreas G. Szabó <silva@psi5.com>",$a
		dc.b	"all rights reserved -- www.psi5.com/~silva/afilter",0
		ENDM

LIBS_VER	=	39

TRUE		= 1
FALSE		= 0

       		IFND EXEC_FUNCDEF_I
        	include exec/funcdef.i
        	ENDC
 		IFND EXEC_TYPES_I
 		include exec/types.i
 		ENDC

		include	exec/exec_lib.i
		include	"dos/dosextens.i"
		include	"dos/dos_lib.i"
		include	"dos/var.i"
		include	"exec/resident.i"
		include	"exec/initializers.i"
		include	"exec/libraries.i"
		include	"exec/lists.i"
		include	"exec/types.i"
		include	"exec/memory.i"

		include ox.i
		include ox_internal.i

		include	easy.i

		IFND UITLITY_TAGITEM_I
		include	"utility/tagitem.i"
		ENDC
		IFND INTUITION_INTUITION_I
		include	"intuition/intuition.i"
		ENDC

		include	"intuition/intuition_lib.i"

		include	intuition/intuitionbase.i
		include	intuition/screens.i
		INCLUDE	intuition/gadgetclass.i
		include	intuition/classes.i
		include	intuition/icclass.i
		include	graphics/text.i
		include	graphics/gfx.i
		include	graphics/gfxbase.i
		include	graphics/cybergraphics.i
		include	graphics/regions.i
		include graphics/graphics_lib.i
	;	include layers/layers_lib.i
		include	datatypes/datatypes.i
		include	datatypes/pictureclass.i
		include workbench/wb_lib.i
		include workbench/workbench.i

		include	hardware/blit.i

		section	code

; *** library starts here ***************************************

		moveq	#-1,d0		; note: any code of any size may be here as exec searches for the ROMTag
		rts

		; romtag structure (exec/resident.i)

ROMTag		dc.w	RTC_MATCHWORD
		dc.l	ROMTag
		dc.l	EndOfLib	; at bottom of this file
		dc.b	RTF_AUTOINIT
		dc.b	OXVERSION
		dc.b	NT_LIBRARY
		dc.b	0
		dc.l	.name
		dc.l	.id
		dc.l	.inittable

.name		oxNAME
		dc.b	"$VER: "
.id		oxVERSTRING
		even

oxLIB_VERSTRING	= .id
oxLIB_NAME		= .name

.inittable	dc.l	oxB_SIZEOF
		dc.l	functiontable
		dc.l	.initdata
		dc.l	mylibInit

.initdata	INITBYTE	LN_TYPE,NT_LIBRARY
		INITLONG	LN_NAME,.name
		INITBYTE	LIB_FLAGS,LIBF_SUMUSED!LIBF_CHANGED
		INITWORD	LIB_VERSION,OXVERSION
		INITWORD	LIB_REVISION,OXREVISION
		INITLONG	LIB_IDSTRING,.id
		dc.l	0

AUTHOR_NAME	dc.b	"Andreas G. Szabó",0
		even

functiontable	dc.l	libOpen
		dc.l	libClose
		dc.l	libExpunge
		dc.l	libNull

		dc.l	_oxInit
		dc.l	_oxCreateOnly
		dc.l	_oxCreateObject
		dc.l	_oxCreateCustom
		dc.l	_oxAddMember
		dc.l	_oxRemMember
		dc.l	_oxDoMethod
		dc.l	_oxSetAttr
		dc.l	_oxSetAttrs
		dc.l	_oxGetAttr
		dc.l	_oxBroadcast
		dc.l	_oxBroadcastAttr
		dc.l	_oxNotify
		dc.l	_oxBroadcastUpdate

		dc.l	_oxFreeObject

		dc.l	_oxMakeClass
		dc.l	_oxDeleteClass
		dc.l	_oxOpenClass
		dc.l	_oxCloseClass

		dc.l	_oxBevelBorder
		dc.l	_oxCreateExample

		dc.l	_oxFindObjectByID
		dc.l	_oxRelink

		dc.l	_oxGlobalRefreshGUI
		dc.l	_oxBeginRefresh
		dc.l	_oxEndRefresh

		dc.l	default_prefs_all	; put default config into bases
		dc.l	restore_prefs		; from ENV:
		dc.l	load_prefs		; from ENVARC:
		dc.l	store_prefs		; to ENV:
		dc.l	save_prefs		; to ENVARC:

		dc.l	_oxImageFill
		dc.l	_oxImageDraw
		dc.l	_oxImageDrawClip
		dc.l	_oxGetImageSize
		dc.l	_oxGetImage
		dc.l	_oxDropImage

		dc.l	_oxRingConnect
		dc.l	_oxRefresh

		dc.l	-1


firstclass	dc.l	buffer

mylibInit	; d0 *oxBase, a0 library *seglist, a6 *execbase
		move.l	a5,-(a7)
		lea	seglist(pc),a5
		move.l	a0,(a5)+
		move.l	d0,(a5)+
		move.l	a6,(a5)
		move.l	d0,a5
		move.l	a6,oxB_sysbase(a5)
		bsr	Initox
		tst.l	d0
		beq.b	.free
		move.l	a5,d0
		bra.b	.end
.free		bsr	freelibmem
		moveq	#0,d0
.end		move.l	(a7)+,a5
		; d0 = 0 means init failed, no library
		rts

libOpen		; a6 *oxBase
		addq.w	#1,LIB_OPENCNT(a6)
		bclr	#LIBB_DELEXP,LIB_FLAGS(a6)
		move.l	a6,d0
		; return d0 *oxBase or 0 if failed
		rts

; note: I did not completely understand why and what to do in
;       the Close() and Expunge() routines, just copied some
;	code from other sources that works for MY puposes.
;	They are irrelevant to ox itself.

libClose	; a6 *oxBase
		subq.w	#1,LIB_OPENCNT(a6)
		bne.b	return_null
		btst	#LIBB_DELEXP,LIB_FLAGS(a6)
		beq.b	return_null

libExpunge	; a6 *oxBase
		tst.w	LIB_OPENCNT(a6)
		beq.b	.doit
		bset	#LIBB_DELEXP,LIB_FLAGS(a6)
		bra.b	return_null

.doit		movem.l	d2/a5/a6,-(a7)
		move.l	a6,a5
		move.l	oxB_sysbase(a5),a6
		move.l	seglist(pc),d2
		move.l	a5,a1
		jsr	_LVORemove(a6)
		bsr	Freeox
		bsr.b	freelibmem
		move.l	d2,d0
		movem.l	(a7)+,d2/a5/a6
		; return d0 *seglist of this library
		rts
libNull
return_null	moveq	#0,d0
		rts

freelibmem	moveq	#0,d0
		move.w	LIB_NEGSIZE(a5),d0
		move.l	a5,a1
		sub.l	d0,a1
		add.w	LIB_POSSIZE(a5),d0
		jmp	_LVOFreeMem(a6)


; -----------------------------------
; open other libs and link in internal classes


Initox:
		; gets a5 *oxBase, a6 *execbase
		; returns d0 = 0 = fail, <>0 = OK

		pushm	d1-a6

		move.l	a5,a4
		lea	libs_table(pc),a2
		bsr	libs_opener
		beq	.restack

		lea	oxB_intbase(a5),a0
		lea	intbase(pc),a1
		movem.l	(a0),d1-d7
		movem.l	d1-d7,(a1)

		lea	oxB_classlist(a5),a0
		NEWLIST	a0

		lea	oxB_applist(a5),a0
		NEWLIST	a0

		lea	oxB_imagelist(a5),a0
		NEWLIST	a0

		; check for morphos

		lea	.morphos(pc),a1
		jsr	_LVOFindResident(a6)
		tst.l	d0
		beq.b	.config

		bset	#oxBB_MORPHOS,oxB_configflags(a5)

.config		; read set config

		move.l	a5,a6
		lea	config,a2
		move.l	a2,oxB_config(a6)
		bsr	default_prefs_lib
		bsr	restore_prefs			; load from ENV:

		; add internal classes

 STRUCTURE	oxIClass,0
	APTR	oxIC_next
	UWORD	oxIC_version
	UWORD	oxIC_revision
	APTR	oxIC_name
	APTR	oxIC_tags

		lea	class_index,a5
		lea	firstclass(pc),a4
.next_iclass	move.l	(a4),d0				; oxIC_next
		beq.b	.return_ok

		move.l	d0,a4
		move.w	oxIC_version(a4),d0
		move.w	oxIC_revision(a4),d1
		move.l	oxIC_name(a4),a0
		move.l	oxIC_tags(a4),a1

		bsr	mcl		; Make Class / read prefs for class

		move.l	d0,(a5)+

		bra	.next_iclass

.return_ok	moveq	#-1,d0

.restack	popm	d1-a6
		rts

.morphos	dc.b	"MorphOS",0
		even


libs_table	; *name, version, offset in base

		dc.l	.intname,LIBSVER,oxB_intbase
		dc.l	.gfxname,LIBSVER,oxB_gfxbase
		dc.l	.layersname,LIBSVER,oxB_layersbase
		dc.l	.dosname,LIBSVER,oxB_dosbase
		dc.l	.dtname,LIBSVER,oxB_dtbase
		dc.l	.wbname,LIBSVER,oxB_wbbase
		dc.l	.iconname,LIBSVER,oxB_iconbase
		dc.l	0

.intname	dc.b	"intuition.library",0
.gfxname	dc.b	"graphics.library",0
.layersname	dc.b	"layers.library",0
.dosname	dc.b	"dos.library",0
.dtname		dc.b	"datatypes.library",0
.wbname		dc.b	"workbench.library",0
.iconname	dc.b	"icon.library",0
		even

libs_opener	; a4	*base
		; a2	*libstable

		move.l	4.w,a6

		move.l	a2,a3

.open_loop	tst.l	(a2)
		beq.b	.rts

		move.l	(a2)+,a1
		move.l	(a2)+,d0
		move.l	(a2)+,d2

		tst.l	(a4,d2.w)
		bne.b	.open_loop

		jsr	_LVOOpenLibrary(a6)
	;	move.l	(a2)+,d1
		move.l	d0,(a4,d2.w)
		bne.b	.open_loop

	;	tst.l	d1			; retry TRUE? (there MUST be annother entry for the same lib with retry FALSE)
	;	bne.b	.open_loop

		; report "you need..."

		move.l	-8(a2),a1		; -12
	;	cmp.b	#":",7(a1)
	;	bne	.req
	;	lea	13(a1),a1

.req		move.l	a1,-(a7)
		move.l	-12(a2),-(a7)		; -16
		move.l	a7,a1
		lea	.template(pc),a0
		bsr	auto_request
		addq.l	#8,a7

		move.l	a3,a2
		bra.b	libs_closer

.rts		moveq	#TRUE,d0
		rts

.template	dc.b	"You need %s with at least version %ld.",0
		even

libs_closer	; a4	*base
		; a2	*libstable

		move.l	4.w,a6

.close_loop	tst.l	(a2)
		beq.b	.rts

		addq.l	#8,a2
		move.l	(a2)+,d1
	;	addq.l	#4,a2
		move.l	(a4,d1.w),d0
		beq.b	.close_loop

		clr.l	(a4,d1.w)

		move.l	d0,a1
		jsr	_LVOCloseLibrary(a6)
		bra.b	.close_loop

.rts		moveq	#FALSE,d0
		rts

; close other libs and classes

Freeox:
		; gets a5 *oxBase, a6 *execbase
		; returns nothing

		pushm	d1-a6

		move.l	a5,a6

		; free config strings

		move.l	oxB_config(a5),a2

		bsr	free_strings

		lea	oxB_classlist(a5),a2
		move.l	(a2),a2
.free_c_lp	tst.l	(a2)
		beq.b	.close_libs

		move.l	a2,a1
		move.l	(a2),a2
		bsr	cc_doit			; calls free class here !!!!!

		bra.b	.free_c_lp

.close_libs	move.l	a6,a4
		lea	libs_table(pc),a2
		bsr	libs_closer

		popm	d1-a6
		rts



; library functions
; -----------------


free_strings	; free dynamic env strings that have been allocatd by the prefs routines

.loop		tst.l	(a2)
		beq.b	.rts

		move.b	oxE_type(a2),d0
		cmp.b	#$ff,d0			; skip folders
		beq.b	.fc_lpc

		and.b	#oxEt_MASK,d0		; only text is interesting
		bne.b	.fc_lpc

		move.w	oxE_offset(a2),d1
		move.l	(a5,d1.w),d0
		beq.b	.fc_lpc

		clr.l	(a5,d1.w)

		cmp.l	oxE_default(a2),d0
		beq.b	.fc_lpc

		move.l	d0,a0
		bsr	free_rem

.fc_lpc		lea	oxE_SIZEOF(a2),a2
		bra.b	.loop

.rts		rts


;=============================================================================
; apply default prefs

default_prefs_all	; read classes and lib default prefs

		pushm	d2-d7/a2-a5

		lea	oxB_classlist(a6),a4
.classes_loop	move.l	(a4),a4
		tst.l	(a4)
		beq	default_prefs

		move.l	oxC_envarray(a4),d0
		beq	.classes_loop

		move.l	oxC_base(a4),a5
		move.l	d0,a2

.env_loop	bsr	default_pref

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

		bra	.classes_loop

default_prefs_lib	; read lib default prefs

		pushm	d2-d7/a2-a5

default_prefs	move.l	oxB_config(a6),a2
		move.l	a6,a5

.env_loop	bsr	default_pref

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

		popm	d2-d7/a2-a5
		rts

default_pref	; a5 base
		; a2 env

		move.l	oxE_default(a2),d2
		move.w	oxE_offset(a2),d1
		move.b	oxE_type(a2),d0

		cmp.b	#$ff,d0
		beq.b	.rts

		and.b	#oxEt_MASK,d0		; mask out editor side types
		bclr	#oxEtB_HEX,d0
		bclr	#oxEtB_FLAG,d0
		beq.b	.bwl

		; clear / set flag bit

		moveq	#0,d3

		cmp.b	#oxEt_byte,d0
		bne.b	.bit_word
		move.b	(a5,d1.w),d3
		bra.b	.bit_setclr

.bit_word	cmp.b	#oxEt_word,d0
		bne.b	.bit_long
		move.w	(a5,d1.w),d3
		bra.b	.bit_setclr

.bit_long	cmp.b	#oxEt_long,d0
		bne.b	.rts
		move.l	(a5,d1.w),d3

.bit_setclr	move.b	oxE_flagbit(a2),d4
		exg	d2,d3
		tst.l	d3
		beq.b	.clr

		bset	d4,d2
		bra.b	.bwl

.clr		bclr	d4,d2

.bwl		tst.b	d0
		bne.b	.byte

		; test old text for remove, if none goto write long text ptr

		move.l	(a5,d1.w),d0
		beq.b	.long

		cmp.l	d0,d2
		beq.b	.rts

		move.l	d0,a0
		bsr	free_rem

		bra.b	.long

		; copy default value into field

.byte		cmp.b	#oxEt_byte,d0
		bne.b	.word
		move.b	d2,(a5,d1.w)
		bra.b	.rts

.word		cmp.b	#oxEt_word,d0
		bne.b	.long
		move.w	d2,(a5,d1.w)
		bra.b	.rts

.long		move.l	d2,(a5,d1.w)

.rts		rts


;=============================================================================
; load prefs from ENVARC:

load_prefs	pushm	d2-d7/a2-a5

		lea	tx_ox_envarc(pc),a0
		move.l	a0,d6
		lea	tx_class_envarc(pc),a0
		move.l	a0,d7

		bra	get_prefs	

;=============================================================================
; restore prefs from ENV:

restore_prefs	pushm	d2-d7/a2-a5

		; init

		lea	tx_ox_env(pc),a0
		move.l	a0,d6
		lea	tx_class_env(pc),a0
		move.l	a0,d7

get_prefs	; lib

		move.l	oxB_config(a6),a2
		move.l	a6,a5

.env_loop	; build full name string

		move.l	oxE_name(a2),-(a7)
		move.l	a7,a1
		move.l	d6,a0
		bsr	string_format

		addq.l	#4,a7
		beq	.pop

		push	d0
		move.l	d0,a1

		bsr	get_pref

		; free temp string

		pop	a0
		bsr	free_rem

		; point to next env in array

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

		; classes

		lea	oxB_classlist(a6),a4
.classes_loop	move.l	(a4),a4
		tst.l	(a4)
		beq	.pop

		tst.l	oxC_name(a4)
		beq	.classes_loop

		move.l	oxC_envarray(a4),d0
		beq	.classes_loop

		move.l	oxC_base(a4),a5
		move.l	d0,a2

		bsr	restore_class_prefs

		bra	.classes_loop

.pop		popm	d2-d7/a2-a5
		rts

restore_class_prefs	; a5 base
			; a4 class
			; a2 env array
			; d7 path

		; iterate through class env

.env_loop	; build full name string

		move.l	oxE_name(a2),-(a7)
		move.l	oxC_name(a4),-(a7)
		move.l	a7,a1
		move.l	d7,a0
		bsr	string_format

		addq.l	#8,a7
		beq	.rts

		push	d0
		move.l	d0,a1

		bsr	get_pref

		; free temp string

		pop	a0
		bsr	free_rem

		; point to next env in array

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

.rts		rts

tx_class_env	dc.b	"ox/classes/%s/%s",0
tx_ox_env	dc.b	"ox/%s",0
tx_class_envarc	dc.b	"ENVARC:ox/classes/%s/%s",0
tx_ox_envarc	dc.b	"ENVARC:ox/%s",0
text_on		dc.b	"ON",0
text_off	dc.b	"OFF",0
text_none	dc.b	"NONE",0
		even

get_pref	; a5 base
		; a1 name	path w/ name
		; a2 env

		move.l	a1,d1

		lea	-256(a7),a7
		move.l	a7,d2
		move.l	#255,d3 ; ?

		pushm	a1/a6

		move.l	#GVF_GLOBAL_ONLY+LV_VAR,d4
		move.l	dosbase(pc),a6
		jsr	-906(a6)			; _LVOGetVar() (setvar = 900)

		popm	a1/a6

		; if there is no pref for this env-var, make one (for revert)

		tst.l	d0
		bge.b	.d2

		move.l	#GVF_GLOBAL_ONLY+LV_VAR,d4		; ENV: mode
		bsr	set_pref

		bra	.rts

.d2		move.l	d2,a0

		move.w	oxE_offset(a2),d4
		move.b	oxE_type(a2),d5

		cmp.b	#$ff,d5
		beq.b	.rts

		and.b	#oxEt_MASK,d5		; mask out editor side types
		bne.b	.val_or_flag

		; text, free old string if any and alloc new

		move.l	(a5,d4.w),d1
		beq.b	.if_none

		clr.l	(a5,d4.w)

		cmp.l	oxE_default(a2),d1
		beq.b	.if_none

		push	a0
		move.l	d1,a0
		bsr	free_rem
		pop	a0

.if_none	cmp.b	#"N",(a0)
		bne.b	.alloc_new
		cmp.b	#"O",1(a0)
		bne.b	.alloc_new
		cmp.b	#"N",2(a0)
		bne.b	.alloc_new
		cmp.b	#"E",3(a0)
		bne.b	.alloc_new
		tst.b	4(a0)
		bne.b	.alloc_new

		clr.b	(a0)
		moveq	#0,d0

.alloc_new	addq.l	#1,d0			; len + null byte
		bsr	alloc_rem
		beq.b	.rts
		move.l	d0,a1

.cpy_lp		move.b	(a0)+,(a1)+
		bne.b	.cpy_lp

		bra.b	.setlong

.val_or_flag	bclr	#oxEtB_FLAG,d5
		bne.b	.flag

		bclr	#oxEtB_HEX,d5
		bne.b	.hex

		cmp.b	#"#",(a0)		; allow leading # for dezimal numbers
		bne.b	.dtv
		addq.l	#1,a0
		subq.l	#1,d0
		beq.b	.rts
.dtv		bsr	DezToVal
		bra.b	.size

.hex		cmp.b	#"$",(a0)
		bne.b	.nodollar
		addq.l	#1,a0
		subq.l	#1,d0
		beq.b	.rts
.nodollar	bsr	HexToVal
		bra.b	.size

.flag		move.b	oxE_flagbit(a2),d1

		cmp.b	#oxEt_byte,d5
		bne.b	.read_word
		move.b	(a5,d4.w),d0
		bra.b	.if_on_or_off
.read_word	cmp.b	#oxEt_word,d5
		bne.b	.read_long
		move.w	(a5,d4.w),d0
		bra.b	.if_on_or_off
.read_long	cmp.b	#oxEt_long,d5
		bne.b	.rts
		move.l	(a5,d4.w),d0

.if_on_or_off	cmp.b	#"O",(a0)+
		bne.b	.rts
		cmp.b	#"N",(a0)+
		bne.b	.off
		bset	d1,d0
		bra.b	.size
.off		bclr	d1,d0

.size		cmp.b	#oxEt_byte,d5
		bne.b	.word
		move.b	d0,(a5,d4.w)
		bra.b	.rts

.word		cmp.b	#oxEt_word,d5
		bne.b	.long
		move.w	d0,(a5,d4.w)
		bra.b	.rts

.long		cmp.b	#oxEt_long,d5
		bne.b	.rts
.setlong	move.l	d0,(a5,d4.w)

.rts		; free getvar buffer

		lea	256(a7),a7
		rts

;=============================================================================
; store prefs to ENV:

store_prefs	pushm	d2-d7/a2-a5
		move.l	#GVF_GLOBAL_ONLY+LV_VAR,d4			; ENV: mode
		bra	set_prefs

;=============================================================================
; store prefs to ENV: and save prefs to ENVARC:

save_prefs	pushm	d2-d7/a2-a5
		move.l	#GVF_GLOBAL_ONLY+LV_VAR+GVF_SAVE_VAR,d4		; + ENVARC: mode

set_prefs	; lib

		move.l	oxB_config(a6),a2
		move.l	a6,a5

.env_loop	; build full name string

		move.l	oxE_name(a2),-(a7)
		move.l	a7,a1
		lea	tx_ox_env(pc),a0
		bsr	string_format

		addq.l	#4,a7
		beq	.pop

		push	d0
		move.l	d0,a1

		bsr	set_pref

		; free temp string

		pop	a0
		bsr	free_rem

		; point to next env in array

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

		; classes

		lea	oxB_classlist(a6),a4
.classes_loop	move.l	(a4),a4
		tst.l	(a4)
		beq	.pop

		tst.l	oxC_name(a4)
		beq	.classes_loop

		move.l	oxC_envarray(a4),d0
		beq	.classes_loop

		move.l	oxC_base(a4),a5
		move.l	d0,a2

.c_env_loop	; build full name string

		move.l	oxE_name(a2),-(a7)
		move.l	oxC_name(a4),-(a7)
		move.l	a7,a1
		lea	tx_class_env(pc),a0
		bsr	string_format

		addq.l	#8,a7
		beq	.pop

		push	d0
		move.l	d0,a1

		bsr	set_pref

		; free temp string

		pop	a0
		bsr	free_rem

		; point to next env in array

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.c_env_loop

		bra	.classes_loop

.pop		popm	d2-d7/a2-a5
		rts

set_pref	; a5 base
		; a1 name	path w/ name
		; a2 env
		; d4		mode env: or envarc:

		lea	-256(a7),a7

		move.w	oxE_offset(a2),d3
		move.b	oxE_type(a2),d5

		cmp.b	#$ff,d5
		beq.b	.rts

		and.b	#oxEt_MASK,d5		; mask out editor side types
		bne.b	.get_sized

		; text

		move.l	(a5,d3.w),d2
		bne.b	.setvar

		; if var is null, write "NONE" string

		lea	text_none(pc),a0
		move.l	a0,d2
		bra.b	.setvar

.get_sized	; get from base sized

		moveq	#0,d0
		move.b	d5,d0
		bclr	#oxEtB_FLAG,d0
		bclr	#oxEtB_HEX,d0

		cmp.b	#oxEt_byte,d0
		bne.b	.word
		move.b	(a5,d3.w),d0
		moveq	#2,d1
		bra.b	.val_or_flag

.word		cmp.b	#oxEt_word,d0
		bne.b	.long
		move.w	(a5,d3.w),d0
		moveq	#4,d1
		bra.b	.val_or_flag

.long		cmp.b	#oxEt_long,d0
		bne.b	.rts
		move.l	(a5,d3.w),d0
		moveq	#8,d1

.val_or_flag	bclr	#oxEtB_FLAG,d5
		bne.b	.flag

		move.l	a7,d2
		move.l	a7,a0

		bclr	#oxEtB_HEX,d5
		bne.b	.hex

		; make dez

		move.b	#"#",(a0)+
		moveq	#8,d1
		bsr	ValToDez
		bra.b	.setvar

.hex		; make hex

		move.b	#"$",(a0)+
		bsr	ValToHex
		bra.b	.setvar

.flag		move.b	oxE_flagbit(a2),d1
		btst	d1,d0
		beq.b	.off

		lea	text_on(pc),a0
		bra.b	.setoo

.off		lea	text_off(pc),a0
.setoo		move.l	a0,d2

.setvar		move.l	a1,d1
		moveq	#-1,d3

		push	a6

		move.l	dosbase(pc),a6
		jsr	-900(a6)	; _LVOSetVar()

		pop	a6

.rts		lea	256(a7),a7
		rts


;============================================================
; Make Class, Delete Class, Open Class, Close Class

_oxMakeClass	;	a1	tags

		moveq	#0,d0
		moveq	#0,d1
		sub.l	a0,a0
		bra	mcl

mcl		;	d0	version
		;	d1	revision
		;	a0	name
		;	a1	tags

		pushm	d2/d7/a2-a6

		move.l	libbase(pc),a6

		move.w	d0,d2

		; get memory for class structure

		moveq	#oxC_SIZEOF,d0
		bsr	alloc_mem
		beq	.pop
		move.l	d0,a3

		; set xyz

		move.w	d2,oxC_version(a3)
		move.w	d1,oxC_revision(a3)
		move.l	a0,oxC_name(a3)

		; set owner task

		move.l	a1,a2

		push	a6

		sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		move.l	d0,oxC_owner(a3)

		pop	a6

		; parse tags

.get_a_tag	bsr	get_a_tag
		beq	.alloc_base

		cmp.w	#oxCA_objectsize,d0
		bne	.dis
		move.l	d1,oxC_objectsize(a3)
		bra	.get_a_tag

.dis		cmp.w	#oxCA_dispatcher,d0
		bne	.con
		move.l	d1,oxC_dispatcher(a3)
		bra	.get_a_tag

.con		cmp.w	#oxCA_constructor,d0
		bne	.ver
		move.l	d1,oxC_constructor(a3)
		bra	.get_a_tag

.ver		cmp.w	#oxCA_verstring,d0
		bne	.desc
		move.l	d1,oxC_verstring(a3)
		bra	.get_a_tag

.desc		cmp.w	#oxCA_description,d0
		bne	.auth
		move.l	d1,oxC_description(a3)
		bra	.get_a_tag

.auth		cmp.w	#oxCA_author,d0
		bne	.clinit
		move.l	d1,oxC_author(a3)
		bra	.get_a_tag

.clinit		cmp.w	#oxCA_initclass,d0
		bne	.cldeinit
		move.l	d1,oxC_initclass(a3)
		bra	.get_a_tag

.cldeinit	cmp.w	#oxCA_deinitclass,d0
		bne	.ex
		move.l	d1,oxC_deinitclass(a3)
		bra	.get_a_tag

.ex		cmp.w	#oxCA_makeexample,d0
		bne	.base
		move.l	d1,oxC_makeexample(a3)
		bra	.get_a_tag

.base		cmp.w	#oxCA_basesize,d0
		bne	.env
		move.l	d1,oxC_basesize(a3)
		bra	.get_a_tag

.env		cmp.w	#oxCA_envarray,d0
		bne	.get_a_tag
		move.l	d1,oxC_envarray(a3)
		bra	.get_a_tag

.alloc_base	; alloc base if wanted

		move.l	oxC_basesize(a3),d0
		beq	.init
		bsr	alloc_mem
		beq	.free_class

		move.l	d0,oxC_base(a3)
		move.l	d0,a5

		move.l	oxC_envarray(a3),d0
		beq	.init
		move.l	d0,a2

.env_loop	bsr	default_pref

		lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		bne	.env_loop

		; get class prefs from ENV: only if class has a name (is not made by user)

		tst.l	oxC_name(a3)
		beq	.init

		move.l	a3,a4	; class
		move.l	oxC_envarray(a3),a2
		lea	tx_class_env(pc),a0
		move.l	a0,d7

		bsr	restore_class_prefs

.init		; call init, gets pointer to base in a5 if any

		move.l	oxC_initclass(a3),d0
		beq	.add

		move.l	d0,a0
		pushm	d2-d7/a2-a6
		moveq	#0,d0
		jsr	(a0)
		popm	d2-d7/a2-a6

		tst.l	d0
		beq	.free_base

.add		; add to class list

		addq.w	#1,oxC_opencount(a3)

		; class without name is private, do not add to list

		tst.l	oxC_name(a3)
		beq	.return_ptr

		lea	oxB_classlist(a6),a0
		move.l	a3,a1
		ADDTAIL

.return_ptr	move.l	a3,d0
		bra	.pop

.free_base	; free base

		move.l	a5,a0
		move.l	oxC_basesize(a3),d0
		bsr	free_mem

.free_class	; free class structure

		move.l	a3,a0
		moveq	#oxC_SIZEOF,d0
		bsr	free_mem
		moveq	#0,d0

		; return	0	or 	pointer to class

.pop		popm	d2/d7/a2-a6
		rts


 STRUCTURE	oxClassHeader,0
	ULONG	oxCH_rts		; moveq	#-1,d0, rts
	ULONG	oxCH_match		; "XOXO"
	UWORD	oxCH_forlibver
	LABEL	oxCH_IClass

; STRUCTURE	oxIClass,0
;	APTR	oxIC_next
;	UWORD	oxIC_version
;	UWORD	oxIC_revision
;	APTR	oxIC_name
;	APTR	oxIC_tags


_oxOpenClass		; a1	*name
			; d0	version, null if any
			; returns d0 *class or null if failed

		pushm	d1-a6
		move.l	d0,d5	; required version

		move.l	a1,a3

		; search for class if its allready open

		move.l	libbase(pc),a6
		lea	oxB_classlist(a6),a2
.get_next_name	move.l	(a2),a2
		tst.l	(a2)
		beq.b	.name_not_found

		move.l	a3,a1
		move.l	oxC_name(a2),a0

		bsr	MatchStringsNoCase
		bne.b	.get_next_name

		; check required version

		cmp.w	oxC_version(a2),d5
		ble	.ver_ok

		; show error

		move.l	a1,-(a7)
		move.l	d5,-(a7)
		move.l	a7,a1
		lea	.ver_mismatch(pc),a0
		bsr	auto_request
		addq.l	#8,a7

		bra	.fail

.ver_ok		addq.w	#1,oxC_opencount(a2)
		move.l	a2,d0
		bra	.return

.name_not_found	move.l	oxB_dosbase(a6),a6

		; try load from progdir first

		lea	.altclasspath(pc),a0
		move.l	a0,d1
		moveq	#ACCESS_READ,d2
		jsr	_LVOLock(a6)
		move.l	d0,d1
		bne	.cd

		; try load from libs:

		lea	.classpath(pc),a0
		move.l	a0,d1
		jsr	_LVOLock(a6)
		move.l	d0,d1
		beq	.fail
.cd		move.l	d0,d7
		jsr	_LVOCurrentDir(a6)
		move.l	d0,d6

		move.l	a3,d1
		jsr	_LVOLoadSeg(a6)
		move.l	d0,d4
		beq.b	.fail_unlock

		move.l	d0,a4
		add.l	a4,a4
		lea	4(a4,a4.l),a4

		cmp.l	#"XOXO",oxCH_match(a4)
		bne.b	.fail_unloads
		cmp.w	#OXVERSION,oxCH_forlibver(a4)
		bgt.b	.fail_unloads

		cmp.w	oxCH_IClass+oxIC_version(a4),d5
		ble	.extver_ok

		move.l	oxCH_IClass+oxIC_name(a4),-(a7)
		move.l	d5,-(a7)
		move.l	a7,a1
		lea	.ver_mismatch(pc),a0
		bsr	auto_request
		addq.l	#8,a7

		bra	.fail_unloads

.extver_ok	move.l	oxCH_IClass+oxIC_name(a4),a0
		move.l	oxCH_IClass+oxIC_tags(a4),a1
		move.w	oxCH_IClass+oxIC_version(a4),d0
		move.w	oxCH_IClass+oxIC_revision(a4),d1

		bsr	mcl	; Make Class

		move.l	d0,a3
		move.l	a4,oxC_header(a3)

		move.l	d0,d2
		beq	.fail_unloads

		move.l	d6,d1
		jsr	_LVOCurrentDir(a6)
		move.l	d7,d1
		jsr	_LVOUnLock(a6)

		move.l	d2,d0

.return		popm	d1-a6
		rts

.fail_unloads	move.l	d4,d1
		jsr	_LVOUnLoadSeg(a6)

.fail_unlock	tst.l	d7		; do we have a lock?
		beq.b	.fail
		move.l	d6,d1
		jsr	_LVOCurrentDir(a6)
		move.l	d7,d1
		jsr	_LVOUnLock(a6)

.fail		moveq	#0,d0

		popm	d1-a6
		rts

.classpath	dc.b	"libs:ox",0
.altclasspath	dc.b	"progdir:libs/ox",0
.ver_mismatch	dc.b	"Please insert version %ld of >%s< class into libs:ox/.",0
		even

MatchStringsNoCase:	; zwei Strings vergleichen, groß/klein egal

			; a0	*stringone nullterminiert
			; a1	*stringtwo nullterminiert

			;>ccr	eq = strings identisch, ne = strings verschieden

		pushm	d0/d1/a0/a1
.msn_lp		move.b	(a0)+,d0
		move.b	(a1)+,d1
		beq.b	.msn_1
		cmp.b	#"a",d0
		blt.b	.msn_a
		cmp.b	#"z",d0
		bgt.b	.msn_a
		bclr	#5,d0
.msn_a		cmp.b	#"a",d1
		blt.b	.msn_b
		cmp.b	#"z",d1
		bgt.b	.msn_b
		bclr	#5,d1
.msn_b		cmp.b	d0,d1
		beq.b	.msn_lp
		bra.b	.msn_x
.msn_1		tst.b	d0
.msn_x		popm	d0/d1/a0/a1
		rts

_oxDeleteClass	; pendant to MakeClass()

		; d2	class

		move.l	d2,a1

		; do only discard custom classes (have no name)

		tst.l	oxC_name(a1)
		beq	cc_doit
		rts

_oxCloseClass	; pendant to OpenClass()

		; d2	class
		; a6	*oxbase

		move.l	d2,a1

		; do not discard custom classes, must be done with DeleteClass()

		tst.l	oxC_name(a1)
		beq	cc_rts

		; do not discard internal classes until lib is closed

		tst.l	oxC_header(a1)
		beq.b	cc_rts

		; sub opencount for external classes, discard class if counter reaches 0

		subq.w	#1,oxC_opencount(a1)
		bne.b	cc_rts

cc_doit		; comes here from deinit lib

		; call deinit

		move.l	oxC_deinitclass(a1),d0
		beq	.free_strings

		move.l	d0,a0
		pushm	d0-a6
		move.l	libbase(pc),a6
		move.l	oxC_base(a1),a5
		moveq	#0,d0
		jsr	(a0)
		popm	d0-a6

.free_strings	move.l	oxC_envarray(a1),d0
		beq	.free_base
		move.l	d0,a2
		move.l	oxC_base(a1),d0
		beq	.free_base

		push	a5
		move.l	d0,a5

		bsr	free_strings
		pop	a5

.free_base	; free base

		move.l	oxC_base(a1),a0
		move.l	oxC_basesize(a1),d0
		beq	.rem
		bsr	free_mem

.rem		tst.l	(a1)
		beq	.free_class
		push	a1
		REMOVE
		pop	a1

.free_class	; free class

		move.l	oxC_header(a1),d1

		move.l	a1,a0
		moveq	#oxC_SIZEOF,d0
		bsr	free_mem

		; remove and free external class,
		; but dont unload internal classes (guru)

		tst.l	d1
		beq	cc_rts

		subq.l	#4,d1
		lsr.l	#2,d1

		push	a6
		move.l	oxB_dosbase(a6),a6
		jsr	_LVOUnLoadSeg(a6)
		pop	a6

cc_rts		rts


oxInit		movem.l	d0/d1/a0,-(a7)
		bsr.b	.doinit
		bsr.b	.ini
		movem.l	(a7)+,d0/d1/a0
		rts

.ini		lea	oxO_list(a0),a0
.next_member	move.l	(a0),a0
		tst.l	(a0)
		beq.b	.rts

		bsr.b	.doinit

		push	a0
		bsr.b	.ini
		pop	a0

		bra.b	.next_member

.rts		rts

.doinit		btst	#oxOB_INITIALIZED,oxO_flags(a0)
		bne.b	.rts

		moveq	#OXM_INIT,d1
		bsr	_oxDoMethod

		tst.w	d0
		ble.b	.rts

		bset	#oxOB_INITIALIZED,oxO_flags(a0)

		rts

_oxInit		; a0	top object (usually the first member or a custom-linked)

		bsr	oxInit

	;	pushm	d0-d2/a0/a1

	;	lea	-oxCI_SIZEOF(a7),a7
	;	clr.l	oxCI_lastgadget(a7)
	;	move.l	a7,a1
	;	moveq	#OXM_INIT,d1
	;	moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
	;	bsr	_oxBroadcast
	;	lea	oxCI_SIZEOF(a7),a7

	;	popm	d0-d2/a0/a1

	rts

_oxRelink	; a0 top object, also called

		pushm	d0-d2/a0/a1

		lea	-oxRL_SIZEOF(a7),a7
		clr.l	oxRL_first(a7)
		clr.l	oxRL_last(a7)
		move.l	a7,a1
		moveq	#OXM_RELINK,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		lea	oxRL_SIZEOF(a7),a7

		popm	d0-d2/a0/a1
		rts


_oxCreateExample	; a0	*class

		pushm	d1-d7/a0-a6

		moveq	#0,d0			; default result is null

		move.l	oxC_makeexample(a0),d0
		beq	.pop
		move.l	d0,a2
		move.l	oxC_base(a0),a5
		jsr	(a2)

.pop		popm	d1-d7/a0-a6
		rts


_oxCreateOnly		; d2 / a1 / a2	this without any init

		bra.b	c_start

_oxCreateCustom	;	a0	*major		the object whereto this one should be attached,
			;				a value of NULL means do not attach
			;	a1	*base
			;	a2	*taglist

			;	d2	class		value that was returned by MakeClass(),
			;				if zero read it from (a2)+

			pushm	d2/a0/a1/a2/a5

			tst.l	d2
			bne	.has_class

			; if class was zero, read class and ptr to taglist from the 'taglist' ptr

			move.l	(a2)+,d2
			move.l	(a2),a2

.has_class		move.l	d2,a5

			bsr	.create_cust
			beq	.pop_rts

			push	d0

			move.l	d0,a1

			; only add if there is a parent (major) object given

			move.l	a0,d0
			beq	.pop

			bsr	_oxAddMember

.pop			pop	d0

.pop_rts		popm	d2/a0/a1/a2/a5
			rts

.create_cust		pushm	d2-d7/a0-a6
			move.l	a1,a4
			bra	create_ob


_oxCreateObject	;	d2	type		if null it is read from (a2)+ 
			;	a1	*base
			;	a2	*taglist

			; - make tree of ox object of type from tags in taglist
			; - call init for all in tree via broadcast
			; - return pointer to ox object in d0

		bsr.b	c_start
		beq.b	c_rts
		push	a0
		move.l	d0,a0
		bsr	_oxInit
		bsr	_oxRelink
		pop	a0
c_rts		tst.l	d0
		rts

c_start		pushm	d2-d7/a0-a6
		tst.l	d2
		bne.b	.go

		; this is tricky: if the initial object-type is NULL,
		;		  the ox goes to read type and tagspointer
		;		  from initial tagspointer 

		move.l	(a2)+,d2
		move.l	(a2)+,a2
.go		move.l	a1,a4
		bra.b	c_in

c_recursive	pushm	d2-d7/a0-a6
c_in
		btst	#0,d2
		bne.b	.lookup_class

		; open class

		move.l	d2,a1
		moveq	#0,d0	; version egal
		bsr	_oxOpenClass
		move.l	d0,a5

		tst.l	d0
		bne.b	create_ob

		; show requester

		move.l	a1,-(a7)
		move.l	a7,a1
		lea	.need_class_text(pc),a0
		bsr	auto_request
		addq.l	#4,a7

		moveq	#0,d0

		popm	d2-d3/a0-a6
		rts


.need_class_text	dc.b	"Please insert the >%s< class into libs:ox/.",0
			even

.lookup_class	lea	class_index,a5
		sub.l	#OX_INTERNAL_CLASSES,d2	; is step 2
		lsl.w	#1,d2				; x2 = step 4
		move.l	(a5,d2.w),a5

create_ob	; create, *class in a5

		move.l	oxC_constructor(a5),d0
		beq	.auto

		move.l	d0,a0
		move.l	libbase(pc),a6
		moveq	#0,d0	; default return value!

		pushm	a2/a4/a5
		jsr	(a0)
		popm	a2/a4/a5

		tst.l	d0
		bne	.return

.auto		move.l	oxC_objectsize(a5),d0
		move.l	#MEMF_PUBLIC+MEMF_CLEAR,d1
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		tst.l	d0
		beq	.return

		move.l	d0,a3
		move.l	a5,oxO_Class(a3)
		move.l	a4,oxO_userbase(a3)

		move.l	a3,a0
		moveq	#OXM_SETDEF,d1
		bsr	_oxDoMethod

		lea	oxO_list(a3),a0
		NEWLIST	a0

		move.l	a2,d1		; if dont do tags if tag data is null (d1 scratch)
		beq.b	.return_ptr

		push	a2

.attr_funcs	bsr	get_a_tag
		beq	.tagsptr_back

		btst	#0,d0		; ignore name-pointers
		beq	.attr_funcs

		cmp.w	#OX_ATTRIBS_SYSTEM,d0
		blt	.tagfuncs

		cmp.w	#OXA_FREEHOOK,d0
		bne.b	.usd
		move.l	d1,oxO_freehook(a3)
		bra.b	.attr_funcs

.usd		cmp.w	#OXA_USERDATA,d0
		bne.b	.id
		move.l	d1,oxO_userdata(a3)
		bra.b	.attr_funcs

.id		cmp.w	#OXA_ID,d0
		bne.b	.setattr
		move.l	d1,oxO_ID(a3)
		bra.b	.attr_funcs

.setattr	move.l	a3,a0
		bsr	_oxSetAttr
		bra	.attr_funcs

.tagfuncs	cmp.w	#OX_PUTPTR,d0
		bne	.relptr
		move.l	d1,a0		; StoragePtr
		move.l	a3,(a0)
		bra	.attr_funcs

.relptr		cmp.w	#OX_RELPTR,d0
		bne	.custom
		lea	(a4,d1.l),a0	; storage offset
		move.l	a3,(a0)
		bra	.attr_funcs

.custom		cmp.w	#OX_CUSTOM,d0
		bne	.attr_funcs
		pushm	d4-d7/a2-a6
		move.l	d1,a2
		move.l	a3,a0
		move.l	a4,a1
		moveq	#0,d0
		move.l	libbase(pc),a6
		jsr	(a2)
		popm	d4-d7/a2-a6
		bra	.attr_funcs

.tagsptr_back	pop	a2

		; get new base for members if present

		move.l	a3,a0
		move.l	#oxA_buffer,d0
		bsr	_oxGetAttr
		tst.l	d0
		beq.b	.members
		move.l	d0,a4

		; make recursively the members

.members	bsr	get_a_tag
		beq	.return_ptr

		btst	#0,d0
		beq.b	.member

		cmp.w	#OX_MAXIDTAG,d0
		bgt	.members

.member		push	a2
		move.l	d0,d2
		move.l	d1,a2
		bsr	c_recursive	; self call
		pop	a2
		tst.l	d0
		ble	.members

		move.l	d0,a1
		lea	oxO_list(a3),a0
		ADDTAIL				; d0 destroyed
		bra	.members

.return_ptr	move.l	a3,d0

.return		popm	d2-d7/a0-a6
		rts


_oxAddMember	; a0 parent, a1 member

		push	d1

		move.l	#OXM_ADD,d1
		bsr	_oxDoMethod

		tst.l	d0			; default add if no custom
		bne.b	.rts_pop

		lea	oxO_list(a0),a0
		ADDTAIL				; d0 destroyed

.rts_pop	pop	d1
		rts

_oxRemMember	; a1 member

		REMOVE
		rts

_oxGlobalRefreshGUI

		pushm	a2/a6
		move.l	libbase(pc),a6
		lea	oxB_applist(a6),a2

.app_lp		move.l	(a2),a2
		tst.l	(a2)
		beq.b	.rts_pop

		move.l	oxApp_task(a2),a1
		moveq	#0,d0
		move.b	oxApp_refreshsigbit(a2),d1
		bset	d1,d0
		move.l	4.w,a6
		jsr	_LVOSignal(a6)

		bra.b	.app_lp

.rts_pop	popm	a2/a6
		rts

_oxDoMethod		;	a0	pointer to oxObject
			;	d1	ox method ID
			;	a1	parameter, e.g. ox message

			; may return something in d0

			; check after some classes (e.g.) three if
			; a1 is really a good register in witch
			; the stuff is sent to a dispatcher (guess not)

		pushm	d1-d7/a0-a6
		moveq	#0,d2
		bra.b	dmtd1

dmtd		pushm	d1-d7/a0-a6	
		bset	#OXBMODE_ISBROADCAST_BIT,d2

dmtd1		move.l	a0,d3	; scratch, avoid do it on empty pointers, usually present if
		beq.b	.pop	;	something was wrong on create an object tree

		move.l	oxO_Class(a0),a5

		move.l	oxC_dispatcher(a5),a2
		move.l	oxC_base(a5),a5

		moveq	#0,d0			; NULL default result NULL
		move.l	libbase(pc),a6

		move.l	a0,a3
		move.l	oxO_userbase(a0),a4
		jsr	(a2)

.pop		popm	d1-d7/a0-a6
		rts

_oxSetAttr		;	a0	pointer to oxObject
			;	d0	ox attribute ID
			;	d1	ox attribute value

		movem.l	d0/d1/a1,-(a7)
		move.l	a7,a1
		moveq	#OXM_SET,d1
		bsr	_oxDoMethod
		addq.l	#4,a7
		movem.l	(a7)+,d1/a1
		rts

_oxSetAttrs		;	a0	dest. object
			;	a1	taglist of attribute/value pairs

		push	a2
		move.l	a1,a2

.lp		bsr	get_a_tag
		beq.b	.pop
		bsr	_oxSetAttr
		bra.b	.lp

.pop		pop	a2
		rts

_oxGetAttr		;	a0	pointer to oxObject
			;	d0	ox attribute ID
			; 	a1	ptr to structure to fill
			; 	returns attribute value in d0

		push	d1
		movem.l	d0/a1,-(a7)
		move.l	a7,a1
		moveq	#OXM_GET,d1
		bsr	_oxDoMethod
		addq.l	#4,a7
		pop	a1
		pop	d1
		rts


_oxNotify	; a0 	*self
		; d0	attrib
		; d1	value

		; set attr and update one level down eg through connects

		movem.l	d0/d1/d2/a1,-(a7)
		moveq	#OXBMODE_EVERYBODY,d2
		move.l	a7,a1
		moveq	#OXM_NOTIFY,d1
		bsr.b	_oxBroadcast
		movem.l	(a7)+,d0/d1/d2/a1
		rts

_oxBroadcastUpdate	; a0 * target objects
			; d0 attribut
			; d1 value

		movem.l	d1/d2,-(a7)
		moveq	#OXBMODE_EVERYBODY,d2
		moveq	#OXM_UPDATE,d1
		bsr	_oxBroadcast
		movem.l	(a7)+,d1/d2

		rts


_oxBroadcastAttr	; a0 * target objects
			; d0 attribut
			; d1 value

		movem.l	d0/d1/d2,-(a7)
		moveq	#OXBMODE_EVERYBODY,d2
		move.l	a7,a1
		moveq	#OXM_SET,d1
		bsr	_oxBroadcast
		movem.l	(a7)+,d0-d2

		rts

_oxBroadcast		; does the method with every member until
			; non zero value is returned
			; (access order equals creation order)

		pushm	d2/a0

		cmp.w	#OXM_DRAW,d1
		bne.b	.bb
		bset	#OXBMODE_STOPLEVEL_BIT,d2
.bb		bsr.b	.b
		popm	d2/a0
		rts
.b
	; !! dont call Broadcast with DEINIT if there are members !!!,
	; !! allways use _FreeObject (bottom up) !!!

	; ? make second variant that is class dependent ( zB broadcasts custom rp only to OX_BUTTON )


			;	a0	pointer to oxObject
			;	d1	ox method ID
			;	a1	parameter, e.g. ox message
			;	d2	mode

		bclr	#OXBMODE_SELF_BIT,d2
		beq.b	.first_member

		bsr.b	dmtd		; _oxDoMethod

		; react here on stoplevel/untiltrue

		btst	#OXBMODE_STOPLEVEL_BIT,d2
		beq.b	.if_ut
		tst.l	d0
		bne.b	.return

.if_ut		btst	#OXBMODE_UNTILTRUE_BIT,d2
		beq.b	.first_member
		tst.l	d0
		bne.b	.return

.first_member	lea	oxO_list(a0),a0
.next_member	move.l	(a0),a0		; get first member and so on (list must be initialized!) 
		tst.l	(a0)
		beq.b	.return_false

					; default d0 0 wird in domethd gesezt
		bsr.b	dmtd		; _oxDoMethod

		btst	#OXBMODE_UNTILTRUE_BIT,d2
		beq	.test_stop
		tst.l	d0
		bne	.return

.test_stop	btst	#OXBMODE_STOPLEVEL_BIT,d2
		beq.b	.members
		tst.l	d0
		bne.b	.next_member

.members	push	a0
		bsr	.first_member
		pop	a0

		btst	#OXBMODE_UNTILTRUE_BIT,d2
		beq	.next_member
		tst.l	d0
		beq	.next_member

.return		rts

.return_false	moveq	#0,d0
		rts

_oxFindObjectByID	;	a0	pointer to oxObject
			;	d1	custom object ID

		lea	oxO_list(a0),a0
		moveq	#0,d0
.next_member
		move.l	(a0),a0		; get first member and so on (list must be initialized!) 
		tst.l	(a0)
		beq.b	.obj_not_here

		cmp.l	oxO_ID(a0),d1
		beq.b	.return_ptr

		push	a0
		bsr	_oxFindObjectByID
		pop	a0

	;	bne			; ?!?!?!??! durchreichen an custom verlinkte, domethod und dort erneut
					;           aufruf von FInd...
	

		tst.l	d0
		beq	.next_member

.obj_not_here	rts

.return_ptr	move.l	a0,d0
		rts


_oxFreeObject		;	a0	pointer to oxObject

		pushm	d0-d2/a1/a2/a6

		push	a0

		lea	oxO_list(a0),a0
		move.l	(a0),d0		; get first node
		beq.b	.remove_node
		move.l	d0,a0
.members	tst.l	(a0)
		beq	.remove_node

		move.l	(a0),-(a7)	; get next node
		bsr	_oxFreeObject	;
					;
		pop	a0		; get it here

		bra	.members

.remove_node	move.l	(a7),a1

		tst.l	oxO_node+LN_SUCC(a1)
		beq	.deinit_this
		tst.l	oxO_node+LN_PRED(a1)
		beq	.deinit_this

		REMOVE			; *member a1

.deinit_this	move.l	(a7),a0

		moveq	#OXM_DEINIT,d1
		bsr	_oxDoMethod

		move.l	(a7),a0

		move.l	oxO_freehook(a0),d0
		beq.b	.close_class

		move.l	d0,a1		; call custom destructor, e.g. to free userdata
		pushm	d0-d7/a1-a5
		move.l	a0,a3
		move.l	oxO_userbase(a3),a4
		move.l	libbase(pc),a6
		jsr	(a1)
		popm	d0-d7/a1-a5

.close_class	pop	a1

		move.l	oxO_Class(a1),a2
		move.l	oxC_objectsize(a2),d0
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)

		; free class after last instance has been deleted

		move.l	a2,d2
		move.l	libbase(pc),a6
		bsr	_oxCloseClass

		popm	d0-d2/a1/a2/a6

		rts

_oxRefresh	; a0 *windowobject, a1 *object, d0-d3 left, top, width, height

		movem.w	d0-d3,-(a7)
		move.l	a0,-(a7)
		move.l	a1,-(a7)

		bsr	_oxBeginRefresh

		moveq	#OXM_DRAW,d1
		move.l	(a7)+,a0
		moveq	#OXBMODE_EVERYBODY|OXBMODE_SELF,d2
		bsr	_oxBroadcast

		move.l	(a7)+,a0
		movem.w	(a7)+,d0-d3

		moveq	#0,d4
		bra	_oxEndRefresh




OXICLASSHEADER	MACRO		; name, version, revision, next (name)

\1		dc.l	\4			; next class, may be 0
		dc.w	\2			; version
		dc.w	\3			; revision
		dc.l	.name
		dc.l	.tags
.name		dc.b	"\1",0
		even
.tags
		ENDM


;--------------------------------------------------------------------
; dispatchers get:
;
; message pointer in	...	a1
; method ID in		...	d1
; pointer to ox object	...	a0
; pointer to oxbase	...	a6
;
; return succes != 0
;
; may scratch		...	d1-d7/a0-a6


;--------------------------------------------------------------------
; OX_BUFFER

 STRUCTURE	oxBuffer,oxO_SIZEOF
	APTR	oxBf_buffer
	LABEL	oxBf_SIZEOF

	OXICLASSHEADER	buffer, 1, 0, application

	dc.l	oxCA_objectsize,oxBf_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
;	dc.l	oxCA_makeexample,.example
	dc.l	TAG_END

.desc		dc.b	"$VER: this invisible object is for storing variables that are local "
		dc.b	"to a whole branch of objects.",0
		even

.dispatcher	cmp.w	#OXM_DEINIT,d1
		bne.b	.SET

		move.l	oxBf_buffer(a0),d0
		beq.b	.rts

		move.l	d0,a0
		bra	free_rem

.SET		cmp.w	#OXM_SET,d1
		bne.b	.GET

		movem.l	(a1),d0/d1

		cmp.l	#oxBfA_buffersize,d0
		bne.b	.rts

		move.l	d1,d0
		bsr	alloc_rem
		move.l	d0,oxBf_buffer(a0)

.rts		rts

.GET		cmp.w	#OXM_GET,d1
		bne.b	.GETLAYOUT

		move.l	(a1),d1

		cmp.l	#oxA_buffer,d1
		bne	.rts

		move.l	oxBf_buffer(a0),d0
		rts

.GETLAYOUT	cmp.w	#OXM_GETLAYOUT,d1
		bne.b	.SETLAYOUT

.down		move.l	oxO_list(a3),a0
		tst.l	(a0)
		beq.b	.rts

		bra	_oxDoMethod

.SETLAYOUT	cmp.w	#OXM_SETLAYOUT,d1
		beq.b	.down

		rts

;--------------------------------------------------------------------
; OX_APP

 STRUCTURE	oxApp,oxO_SIZEOF
	UBYTE	oxApp_flags
	UBYTE	oxApp_quitflag
	APTR	oxApp_quitreq
	APTR	oxApp_msgport
	APTR	oxApp_task
	ULONG	oxApp_waitsigmask
	UBYTE	oxApp_refreshsigbit
	UBYTE	oxApp_idcmpsigbit
	UBYTE	oxApp_appsigbit
	UBYTE	oxApp_pad
	APTR	oxApp_newsizewindow
	LABEL	oxApp_SIZEOF

	OXICLASSHEADER	application, 1, 0, connect

	dc.l	oxCA_objectsize,oxApp_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,.create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: ox Application Class 1.0 provides the shared messageport "
		dc.b	"for all windows of this task.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		bne.b	.if_get

		movem.l	(a1),d0/d1

		cmp.l	#oxAA_flags,d0
		bne.b	.rts4
		move.b	d1,oxApp_flags(a0)

.rts4		rts

.if_get		cmp.w	#OXM_GET,d1
		bne.b	.quit

		move.l	(a1),d1

		cmp.l	#oxAA_quitflag,d1
		bne	.if_msgport


		moveq	#0,d0
		move.b	oxApp_quitflag(a0),d0
		rts

.if_msgport	cmp.l	#oxAA_msgport,d1
		bne	.rts
		move.l	oxApp_msgport(a0),d0
		rts

.quit		cmp.w	#oxAM_QUIT,d1
		bne.b	.run

		btst	#oxAB_quitreq,oxApp_flags(a0)
		beq.b	.set_quit

		move.l	oxApp_quitreq(a0),d0
		bne.b	.open_qr

		push	a0

		lea	.ex_quitreq(pc),a2
		move.l	#OX_WINDOW,d2
		bsr	_oxCreateObject

		pop	a0

		move.l	d0,oxApp_quitreq(a0)
		beq	.set_quit

.open_qr	move.l	d0,a0
		move.l	#oxWM_OPEN,d1
		bra	_oxDoMethod

.set_quit	move.b	#1,oxApp_quitflag(a0)

		rts

.create_ex	lea	.ex_quitbutton(pc),a2
		move.l	#OX_BUTTON,d2
		bra	_oxCreateObject

.ex_quitbutton	dc.l	oxBA_text,.text
		dc.l	oxBA_linechar,1
		dc.l	oxBA_hook,.sigtask_quit
		dc.l	TAG_END
.text		dc.b	"quit",0
		even

.sigtask_quit	sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		move.l	d0,a0
		move.l	TC_Userdata(a0),a0
		move.l	#oxAM_QUIT,d1
		bra	_oxDoMethod

.ex_quitreq	; (window)
		dc.l	oxWA_title,.qrwin_title
		dc.l	oxWA_undermouse,-1
		dc.l	oxWA_layout,-1
		dc.l	OX_VERTGROUP,.ex_vert
		dc.l	TAG_END
.ex_vert	dc.l	OX_FIELD,.qt_field
		dc.l	OX_HORIZGROUP,.ex_horiz
		dc.l	TAG_END
.ex_horiz	dc.l	OX_BUTTON,.no_button
		dc.l	OX_BUTTON,.yes_button
		dc.l	oxGA_equal,-1
		dc.l	oxGA_minspace,20
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.no_button	dc.l	oxBA_text,.notext
		dc.l	oxBA_hook,.no_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END
.yes_button	dc.l	oxBA_text,.yestext
		dc.l	oxBA_hook,.quit_hook
		dc.l	oxBA_linechar,1
		dc.l	oxA_active,1
		dc.l	TAG_END
.qt_field	dc.l	oxFdA_text,.quittext
		dc.l	oxFdA_flags,oxFdF_WIDE
		dc.l	TAG_END
.qrwin_title	dc.b	"ox Choice",0
.quittext	dc.b	"Do you really want to Quit?",0
.yestext	dc.b	"yes",0
.notext		dc.b	"no",0
		even

.no_hook	move.l	intbase(pc),a1
		move.l	ib_ActiveWindow(a1),a1
		move.l	wd_UserData(a1),a0
		move.l	#oxWM_CLOSE,d1
		bra	_oxDoMethod

.quit_hook	bsr.b	.no_hook			; first close window
		sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		move.l	d0,a0
		move.l	TC_Userdata(a0),a0
		moveq	#-1,d0
		move.b	d0,oxApp_quitflag(a0)		; this is App-Class, so we know the offset
.rts2		rts

	; run loop here ********************************************

.run		cmp.w	#oxAM_RUN,d1
		bne.b	.init

		move.l	a0,a3

.wait_again	move.l	4.w,a6

		move.l	oxApp_waitsigmask(a3),d0
		jsr	_LVOWait(a6)

		move.b	oxApp_refreshsigbit(a3),d1
		btst	d1,d0
		beq.b	.tst_idcmp

		push	d0

		; do gui refresh

		move.l	a3,a0		
		move.l	#OXM_UPDATE,d1
		moveq	#OXBMODE_STOPLEVEL,d2
		bsr	_oxBroadcast

		pop	d0

.tst_idcmp	move.b	oxApp_idcmpsigbit(a3),d1
		btst	d1,d0
		beq.b	.if_quit

.get_again	move.l	oxApp_msgport(a3),a0
		jsr	_LVOGetMsg(a6)
		tst.l	d0
		beq	.if_NEWSIZE

		move.l	d0,a2

		; see if it is an AppMessage

		cmp.l	#"PDOS",am_ID(a2)
		bne.b	.intui

		cmp.w	#AMTYPE_APPWINDOW,am_Type(a2)
		bne.b	.reply_am

		move.l	am_UserData(a2),a0
		move.l	wd_UserData(a0),a0
		moveq	#OXM_APPWINMESSAGE,d1
		moveq	#OXBMODE_EVERYBODY,d2	;+OXBMODE_UNTILTRUE,d2
		move.l	a2,a1
		bsr	_oxBroadcast	

.reply_am	move.l	a2,a1
		move.l	4.w,a6
		jsr	_LVOReplyMsg(a6)

		bra.b	.get_again

.intui		; copy message so that it can be sent back before window may close

		lea	-oxExtM_SIZEOF(a7),a7
		move.l	a7,a1
		moveq	#im_SIZEOF/2,d1
		subq.w	#1,d1
.cpm_lp		move.w	(a2)+,(a1)+
		dbf	d1,.cpm_lp

		cmp.l	#IDCMP_IDCMPUPDATE,im_Class(a7)
		bne.b	.reply
		move.l	im_IAddress(a7),a0
		move.l	4(a0),oxExtM_gadget(a7)	; first tag-data is GA_ID (word, the lower 16it)

.reply		move.l	d0,a1
		move.l	4.w,a6
		jsr	_LVOReplyMsg(a6)

		; window new size, flush much messages for os4 instant-resize compatibility

		cmp.l	#IDCMP_NEWSIZE,im_Class(a7)
		bne.b	.allg_domethod
		move.l	im_IDCMPWindow(a7),oxApp_newsizewindow(a3)
		bra.b	.pop_my_msg

.allg_domethod	move.l	a7,a1
		move.l	#OXM_INTUIMESSAGE,d1
		move.l	im_IDCMPWindow(a1),a0 
		move.l	wd_UserData(a0),a0
		jsr	_oxDoMethod(pc)

.pop_my_msg	lea	oxExtM_SIZEOF(a7),a7
		bra	.get_again


.if_NEWSIZE	move.l	oxApp_newsizewindow(a3),d0
		beq.b	.if_quit
		move.l	d0,a0
		move.l	wd_UserData(a0),a0		; get pointer to ox window object
		move.l	#oxWM_NEWSIZE,d1
		jsr	_oxDoMethod(pc)
		clr.l	oxApp_newsizewindow(a3)

.if_quit	tst.b	oxApp_quitflag(a3)
		beq	.wait_again

		move.l	oxApp_quitreq(a3),d0
		beq.b	.rts

		clr.l	oxApp_quitreq(a3)

		move.l	d0,a0
		bra	_oxFreeObject

	; end of run loop ********************************************

.init		cmp.w	#OXM_INIT,d1
		bne.b	.deinit

		push	a0
		move.l	a0,a1

		move.l	libbase(pc),a6
		lea	oxB_applist(a6),a0

		; a0 parent, a1 member
		ADDTAIL				; d0 destroyed

		move.l	4.w,a6

		sub.l	a1,a1
		jsr	_LVOFindTask(a6)
		pop	a0
		tst.l	d0
		beq.b	.fail
		move.l	d0,a2
		move.l	a0,TC_Userdata(a2)

		move.l	a2,oxApp_task(a0)

		move.l	a0,a3

		moveq	#-1,d0
		jsr	_LVOAllocSignal(a6)
		tst.b	d0
		bmi.b	.fail
		move.b	d0,oxApp_refreshsigbit(a3)
		moveq	#0,d2
		bset	d0,d2

		; make common windows messageport

		jsr	_LVOCreateMsgPort(a6)
		move.l	d0,oxApp_msgport(a3)
		beq.b	.fail				; Create() cannot handle fail at mom

		move.l	d0,a0
		move.b	MP_SIGBIT(a0),d0
		move.b	d0,oxApp_idcmpsigbit(a3)
		bset	d0,d2
		move.l	d2,oxApp_waitsigmask(a3)

.ok		moveq	#1,d0
		rts
.fail		moveq	#-1,d0
		rts

.deinit		cmp.w	#OXM_DEINIT,d1
		bne.b	.rts

		push	a0

		; remove app from oxbase applist

		move.l	a0,a1
		REMOVE

		move.l	4.w,a6

		; free refresh sig bit

		move.l	(a7),a0

		move.b	oxApp_refreshsigbit(a0),d0
		jsr	_LVOFreeSignal(a6)

		; free common windows messageport

		pop	a0

		move.l	oxApp_msgport(a0),a0
		jmp	_LVODeleteMsgPort(a6)

.rts		rts

;--------------------------------------------------------------------
; OX_CONNECT

 STRUCTURE	oxConn,oxO_SIZEOF
	APTR	oxConn_target		; ptr to ptr
	APTR	oxConn_hook
	ULONG	oxConn_attr
	ULONG	oxConn_newattr
	LABEL	oxConn_SIZEOF

	OXICLASSHEADER	connect, 1, 0, window

	dc.l	oxCA_objectsize,oxConn_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,CC_EXAMPLE
	dc.l	TAG_END

.desc		dc.b	"$VER: drag the slider or enter a number",$a
		dc.b	"to adjust the gauge",0	
		even

.dispatcher	cmp.w	#OXM_NOTIFY,d1
		beq.b	CC_NOTIFY

		cmp.w	#OXM_SET,d1
		bne.b	CC_UPDATE

		movem.l (a1),d0/d1

		cmp.l	#oxCCA_target,d0
		bne.b	.attr
		move.l	d1,oxConn_target(a0)
		rts
.attr		cmp.l	#oxCCA_attr,d0
		bne.b	.newattr
		move.l	d1,oxConn_attr(a0)
		rts
.newattr	cmp.l	#oxCCA_newattr,d0
		bne.b	.rts
		move.l	d1,oxConn_newattr(a0)

.rts		rts	

CC_NOTIFY	movem.l (a1),d0/d1

		move.l	oxConn_attr(a0),d2
		beq.b	.set			; attr 0 goes directly
		cmp.l	d0,d2
		bne.b	.rts
		move.l	oxConn_newattr(a0),d0
.set		move.l	oxConn_target(a0),d2
		bclr	#0,d2
		beq.b	.addr
		move.l	(a4,d2.w),a0
		bra	_oxSetAttr
.addr		move.l	d2,a0
		move.l	(a0),a0
		bra	_oxSetAttr

.rts		rts

CC_UPDATE	cmp.w	#OXM_UPDATE,d1
		bne.b	.rts

		move.l	oxConn_target(a0),d0
		bclr	#0,d0
		beq.b	.addr
		move.l	(a4,d0.w),a0
		bra	_oxDoMethod
.addr		move.l	d0,a0
		move.l	(a0),a0
		bra	_oxDoMethod
.rts		rts

CC_EXAMPLE	lea	.example(pc),a2
		moveq	#0,d2
		bra	_oxCreateObject

 STRUCTURE cex,0
	APTR	cex_gauge
	APTR	cex_prop
	APTR	cex_string
	LABEL	cex_SIZEOF

.example	dc.l	OX_BUFFER,.buffer

.buffer		dc.l	oxBfA_buffersize,cex_SIZEOF
		dc.l	OX_HORIZGROUP,.group
		dc.l	TAG_END
	
.group		dc.l	OX_STRING,.string
		dc.l	OX_SLIDER,.slider
		dc.l	OX_FIELD,.gauge
		dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.string		dc.l	OX_CONNECT,.strtoprop
		dc.l	OX_CONNECT,.strtogauge
		dc.l	OX_RELPTR,cex_string
		dc.l	oxSA_value,0
		dc.l	oxSA_maxval,5
		dc.l	oxSA_minval,1
		dc.l	oxSA_flags,oxSF_DEZ
		dc.l	TAG_END

.slider		dc.l	OX_CONNECT,.proptostr
		dc.l	OX_CONNECT,.proptogauge
		dc.l	OX_RELPTR,cex_prop
		dc.l	oxSlA_flip,1
		dc.l	oxSlA_base1,1
		dc.l	oxSlA_max,5
		dc.l	oxSlA_pot,0
	;	dc.l	oxSlA_body,4
		dc.l	TAG_END

.gauge		dc.l	oxFdA_flags,oxFdF_GAUGE|oxFdF_WIDE|oxFdF_UPDATEREDRAW
	;	dc.l	oxFdA_percent,0
	;	dc.l	oxFdA_minwidth,120
		dc.l	OX_RELPTR,cex_gauge
		dc.l	oxFdA_hprop,1
		dc.l	TAG_END

.strtoprop	dc.l	oxCCA_target,cex_prop|OX_REL
		dc.l	oxCCA_attr,oxSA_softval
		dc.l	oxCCA_newattr,oxSlA_softval
		dc.l	TAG_END

.proptostr	dc.l	oxCCA_target,cex_string|OX_REL
		dc.l	oxCCA_attr,oxSlA_pot
		dc.l	oxCCA_newattr,oxSA_value
		dc.l	TAG_END

.proptogauge	dc.l	oxCCA_target,cex_gauge|OX_REL
		dc.l	oxCCA_attr,oxSlA_softval
		dc.l	oxCCA_newattr,oxFdA_softval
		dc.l	TAG_END

.strtogauge	dc.l	oxCCA_target,cex_gauge|OX_REL
		dc.l	oxCCA_attr,oxSA_softval
		dc.l	oxCCA_newattr,oxFdA_softval
		dc.l	TAG_END

;--------------------------------------------------------------------
; OX_WINDOW

; window object

 STRUCTURE	oxWindow,oxO_SIZEOF
	APTR	oxWin_title
	APTR	oxWin_tags
	UWORD	oxWin_flags
	UWORD	oxWin_spacing		; spacing between borders and content in pixel 
	APTR	oxWin_firstgadget
	APTR	oxWin_sizeicon
	UWORD	oxWin_sizewidth
	UWORD	oxWin_sizeheight
	APTR	oxWin_pubscreen
	ULONG	oxWin_idcmp
	APTR	oxWin_msgport
	APTR	oxWin_closehook
	APTR	oxWin_activeobject
	APTR	oxWin_tickuser
	UWORD	oxWin_wantedwidth	; (inner)
	UWORD	oxWin_wantedheight
	UWORD	oxWin_minwidth
	UWORD	oxWin_minheight
	APTR	oxWin_frontrastport
	APTR	oxWin_offrastport
	APTR	oxWin_appwindow
	APTR	oxWin_intuimessagehook
	APTR	oxWin_newsizehook

	LABEL	oxWin_drawinfo
	UBYTE	oxWin_drawflags
	UBYTE	oxWin_pad
	APTR	oxWin_pentable
	APTR	oxWin_imagetable
	APTR	oxWin_window
	APTR	oxWin_rastport
	APTR	oxWin_font
	APTR	oxWin_fixedfont
	APTR	oxWin_self

	STRUCT	oxWin_theimagetable,oxIT_SIZEOF

	STRUCT	oxWin_sizeg,gg_SIZEOF	; this is the custom window sizing gadget

	LABEL	oxWin_SIZEOF

	BITDEF	oxWin,UNDERMOUSE,0
	BITDEF	oxWin,LAYOUT,1
	BITDEF	oxWin,PATTERN,2
	BITDEF	oxWin,PATTSTYLE2,3
	BITDEF	oxWin,SIGTASKCLOSE,4
	BITDEF	oxWin,NOAUTOCLOSE,5
	BITDEF	oxWin,BORDERLESS,6
	BITDEF	oxWin,FILLBG,7

	OXICLASSHEADER	window, 1, 0, boopsi

	dc.l	oxCA_objectsize,oxWin_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	TAG_END

.desc		dc.b	"$VER: ox Window 1.0, internal",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq.b	.INTUI

		cmp.w	#OXM_SET,d1
		beq	.SET
		cmp.w	#OXM_GET,d1
		beq	.GET

		cmp.w	#oxWM_OPEN,d1
		beq	.open

		cmp.w	#oxWM_CLOSE,d1
		beq	.CLOSE

		cmp.w	#oxWM_NEWSIZE,d1
		beq	oxWin_NEWSIZE

		cmp.w	#OXM_UPDATE,d1
		beq	.UPDATE

		cmp.w	#OXM_DEINIT,d1
		beq	.DEINIT

		cmp.w	#OXM_INIT,d1
		beq	.INIT

		cmp.w	#OXM_RELINK,d1
		beq.b	.RELINK

		cmp.w	#OXM_SETDEF,d1
		beq	.SETDEF

		cmp.w	#OXM_DRAW,d1
		beq	oxWin_DRAW

		cmp.w	#oxWM_clrpriv,d1
		beq.b	.clrpriv

		cmp.w	#oxWM_refreshgadgets,d1
		beq.b	win_refgads

.return		rts

.clrpriv	clr.l	oxWin_activeobject(a0)
		rts

.SETDEF		move.w	#10,oxWin_spacing(a0)
		move.l	#IDCMP_NEWSIZE|IDCMP_CLOSEWINDOW|IDCMP_MOUSEBUTTONS|IDCMP_MOUSEMOVE|IDCMP_RAWKEY|IDCMP_VANILLAKEY|IDCMP_IDCMPUPDATE|IDCMP_INACTIVEWINDOW,oxWin_idcmp(a0)	;|IDCMP_INTUITICKS IDCMP_REFRESHWINDOW|

		move.w	#oxWinF_FILLBG|oxWinF_UNDERMOUSE+oxWinF_LAYOUT+oxWinF_PATTERN,oxWin_flags(a0)

		lea	oxWin_theimagetable(a3),a1
		move.l	a1,oxWin_imagetable(a3)

		move.l	gfxbase(pc),a0
		move.l	gb_DefaultFont(a0),oxWin_fixedfont(a3)

		rts

.defaultwintags	dc.l	WA_NewLookMenus,-1
		dc.l	WA_MenuHelp,-1
		dc.l	WA_ReportMouse,-1
		dc.l	WA_SmartRefresh,-1	; SmartRefresh required for copy/paste rectangular areas?
		dc.l	WA_AutoAdjust,-1
		dc.l	WA_Activate,-1
		dc.l	WA_GimmeZeroZero,-1
		dc.l	WA_BackFill,LAYERS_NOBACKFILL
		dc.l	TAG_END

.RELINK		clr.l	oxRL_first(a1)		; ensure that a new ring for each win
		clr.l	oxRL_last(a1)		; ..
		rts

.INIT		btw	oxWinB_BORDERLESS,oxWin_flags(a3)
		beq	.sizegad
		clr.w	oxWin_spacing(a3)
		bcw	oxWinB_FILLBG,oxWin_flags(a3)
		bra	.set_self

.file		dc.b	"windowsize",0
		even

.sizegad	; make sizing gadgegt if icon lib version > 44

		move.l	oxB_iconbase(a6),a0
		cmp.w	#44,LIB_VERSION(a0)
		blt.b	.set_self

		; no custom sizing gad under morphos (mos icon.library cannot handle amiga-os icons)

		btst	#oxBB_MORPHOS,oxB_configflags(a6)
		bne	.set_self

		lea	.file(pc),a0

		bsr	_oxGetIcon

		move.l	d0,oxWin_sizeicon(a3)
		beq	.set_self

		; get sizing icon size

		lea	oxWin_sizewidth(a3),a1

		move.l	d0,a0
		bsr	_oxGetIconSize

		; make gadget

		lea	oxWin_sizeg(a3),a0


		movem.w	(a1),d0/d1

		neg.w	d0
		neg.w	d1

		movem.w	d0/d1,gg_LeftEdge(a0)
		movem.w	(a1),d0/d1
		addq.w	#8,d0
		addq.w	#8,d1
		movem.w	d0/d1,gg_Width(a0)

		move.w	#GADGHNONE|GRELBOTTOM|GRELRIGHT,gg_Flags(a0)
		move.w	#GADGIMMEDIATE,gg_Activation(a0)
		move.w	#SIZING|SYSGADGET,gg_GadgetType(a0)

		move.l	a0,oxWin_firstgadget(a3)

.set_self	move.l	a3,oxWin_self(a3)

		move.l	oxB_intbase(a6),a6

		sub.l	a0,a0
		jsr	_LVOLockPubScreen(a6)
		move.l	d0,oxWin_pubscreen(a3)
		beq	.rts_fail

		move.l	d0,a0
		lea	sc_RastPort(a0),a1			; set rastport from screen to get font sizes
		move.l	a1,oxWin_rastport(a3)
		move.l	rp_Font(a1),oxWin_font(a3)

		lea	oxWin_drawinfo(a3),a1
		move.l	a1,d1
		move.l	a3,a0
		move.l	#oxA_drawinfo,d0
		bsr	_oxBroadcastAttr

		sub.l	a0,a0
		move.l	oxWin_pubscreen(a3),a1
		jsr	_LVOUnlockPubScreen(a6)

		sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		move.l	d0,a0
		move.l	TC_Userdata(a0),a0
		move.l	#oxAA_msgport,d0
		jsr	_oxGetAttr(pc)
		move.l	d0,oxWin_msgport(a3)

		; if we are not attached to the app yet, do it
		; this is for windows that are created not from the app-tree
		; but manually by Create() from annother class init function

		tst.l	oxO_node(a3)
		bne.b	.rts_ok

		move.l	a3,a1
		bsr	_oxAddMember

.rts_ok		moveq	#1,d0
		rts
.rts_fail	moveq	#-1,d0
		rts



.INTUI		move.l	im_Class(a1),d2

	;	cmp.l	#IDCMP_REFRESHWINDOW,d2
	;	beq	oxWin_DR

		cmp.l	#IDCMP_CLOSEWINDOW,d2
		bne	.if_ticks

		btw	oxWinB_SIGTASKCLOSE,oxWin_flags(a0)
		beq	.if_cls_hook

		push	a0

		sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		tst.l	d0
		beq.b	.pop3
		move.l	d0,a0
		move.l	TC_Userdata(a0),d0
		beq.b	.pop3
		move.l	d0,a0
		move.l	#oxAM_QUIT,d1
		bsr	_oxDoMethod

.pop3		pop	a0

.if_cls_hook	move.l	oxWin_closehook(a0),d0
		beq	.if_aucl			; auto close if no hook

		pushm	a0/a6
		move.l	libbase(pc),a6
		move.l	d0,a1
		moveq	#0,d0
		jsr	(a1)
		popm	a0/a6
		tst.l	d0			; auto close if return is TRUE
		beq	.return
		bra	.CLOSE

.if_aucl	btw	oxWinB_NOAUTOCLOSE,oxWin_flags(a0)
		beq.b	.CLOSE
		rts

.if_ticks	cmp.l	#IDCMP_INTUITICKS,d2
		bne.b	.tell_prime

		move.l	oxWin_tickuser(a0),d0
		beq	.tell_prime
		move.l	d0,a0
		jmp	_oxDoMethod(pc)

.tell_prime	; aktives objekt zuerst informieren

		move.l	oxWin_activeobject(a0),d0
		beq	.ihook
		push	a0
		move.l	d0,a0
		bsr	_oxDoMethod
		pop	a0
		tst.l	d0
		beq	.ihook

		rts

.ihook		move.l	oxWin_intuimessagehook(a0),d0
		beq	.to_all

		pushm	d1/a0/a1
		move.l	d0,a2
		moveq	#0,d0
		move.l	oxO_userbase(a0),a4
		jsr	(a2)
		popm	d1/a0/a1

		tst.l	d0
		beq	.to_all
		rts

.to_all		moveq	#OXBMODE_EVERYBODY,d2	;|OXBMODE_UNTILTRUE,d2
		jmp	_oxBroadcast(pc)

.DEINIT		; comes here twice
		; 			1. if hook or prog called CLOSE on window
		;			2. when object is disposed via OXM_DEINIT
		; (problem to be solved by writing extra close code where f.e. sizeicon is not freed)

		tst.l	oxWin_window(a3)
		beq	.return

		move.l	oxWin_sizeicon(a3),d0
		beq	.CLOSE

		move.l	d0,a0
		bsr	_oxDropIcon

		clr.l	oxWin_sizeicon(a3)

.CLOSE		tst.l	oxWin_window(a3)
		beq	.return

		bsr	drop_offcanvas

		; remove glist

		move.l	oxWin_window(a3),d0

		move.l	oxWin_firstgadget(a3),d1
		beq	.close

		push	d0


		move.l	d1,a1
		move.l	d0,a0
		moveq	#-1,d0
		move.l	intbase(pc),a6
		jsr	_LVORemoveGList(a6)

		pop	d0

.close		; close window

		pushm	d0-a6

		move.l	a3,a0

		moveq	#OXM_WINDOWCLOSING,d1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		clr.l	oxWin_window(a3)	; merk dass jetzt zu ist
		bclr	#oxDIB_WINDOWOPEN,oxWin_drawflags(a3)
		clr.l	oxWin_rastport(a3)

		; free pens and images

		bsr	.freepens		; *oxwin a3	
		bsr	.freeimages		; ..

		; remove appwindow

		move.l	oxWin_appwindow(a3),d0
		beq.b	.free_pentable
		move.l	d0,a0
		move.l	wbbase(pc),a6
		jsr	_LVORemoveAppWindow(a6)

.free_pentable	; free pentable , free pens is above (!)

		move.l	oxWin_pentable(a3),a0
		moveq	#oxPT_SIZEOF,d0
		bsr	free_mem

		popm	d0-a6

		; strip remaining intuimessages

		move.l	4.w,a6
		pushm	d0/d1/a0/a1
		jsr	_LVOForbid(a6)
		popm	d0/d1/a0/a1

		move.l	d0,a0
		push	a0
		move.l	intbase(pc),a6

		; clear idcmp flags

		move.l	wd_UserPort(a0),a2

		clr.l	wd_UserPort(a0)
		moveq	#0,d0
		jsr	_LVOModifyIDCMP(a6)
		move.l	(a7),d2			; d2 *window

		move.l	4.w,a6

		move.l	MP_MSGLIST+LH_HEAD(a2),a2
.strip_lp	tst.l	(a2)
		beq.b	.clswin

		cmp.l	im_IDCMPWindow(a2),d2
		bne.b	.get_next

		move.l	LN_SUCC(a2),a3		; get next before removing this

		move.l	a2,a1
		jsr	_LVORemove(a6)
		move.l	a2,a1
		jsr	_LVOReplyMsg(a6)

		move.l	a3,a2

		bra.b	.strip_lp

.get_next	move.l	LN_SUCC(a2),a2		; get_next w/o removing this
		bra.b	.strip_lp

.clswin		move.l	4.w,a6
		pushm	d0/d1/a0/a1
		jsr	_LVOPermit(a6)
		popm	d0/d1/a0/a1

		pop	a0
		move.l	intbase(pc),a6
		jmp	_LVOCloseWindow(a6)

.return_unused	moveq	#0,d0
		rts

.return_used	moveq	#1,d0
		rts

.open		; open window

		move.l	intbase(pc),a6

		move.l	oxWin_window(a0),d0
		beq	.open_real
		move.l	d0,a0

		push	a0
		jsr	_LVOWindowToFront(a6)
		pop	a0
		jsr	_LVOActivateWindow(a6)

		bra.b	.return_used


.open_real	move.l	a0,a3

		; obtain pubscreen / rastport / font

		sub.l	a0,a0
		jsr	_LVOLockPubScreen(a6)
		move.l	d0,oxWin_pubscreen(a3)
		beq	.fail

		move.l	d0,a0
		lea	sc_RastPort(a0),a1			; set rastport from screen to get font sizes
		move.l	a1,oxWin_rastport(a3)
		move.l	rp_Font(a1),oxWin_font(a3)		; w/o window

		; obtain info on size-gadget height

		moveq	#0,d6		; pre-init size gadget height to 0 if finding it failed

		move.l	oxWin_pubscreen(a3),a0

		jsr	_LVOGetScreenDrawInfo(a6)
		move.l	d0,d7
		beq.b	.misc

		clr.l	-(a7)			; TAG_END
		move.l	d0,-(a7)		; SYSIA_DrawInfo
		move.l	#SYSIA_DrawInfo,-(a7)
		move.l	#SIZEIMAGE,-(a7)
		move.l	#SYSIA_Which,-(a7)
		move.l	oxWin_pubscreen(a3),a0
		move.l	#SYSISIZE_MEDRES,d1
		move.w	sc_Flags(a0),d0
		and.w	#SCREENHIRES,d0
		bne.b	.set_sysi_size
		move.l	#SYSISIZE_LOWRES,d1
.set_sysi_size	move.l	d1,-(a7)
		move.l	#SYSIA_Size,-(a7)

		sub.l	a0,a0
		lea	.sysiname(pc),a1
		move.l	a7,a2
		jsr	_LVONewObjectA(a6)
		tst.l	d0
		beq.b	.untag

		move.l	d0,a0

		move.w	ig_Height(a0),d6

		jsr	_LVODisposeObject(a6)

.untag		lea	8*3+4(a7),a7

		move.l	oxWin_pubscreen(a3),a0
		move.l	d7,a1
		jsr	_LVOFreeScreenDrawInfo(a6)

.misc		move.l	a3,a0

		; prepare window taglist for under_mouse and layout minwidth

		move.l	a3,a0
		move.l	oxWin_tags(a0),d0	; custom tags, dont forget to set up GZZ
		bne	.start_tags

		lea	.defaultwintags(pc),a1
		move.l	a1,d0

.start_tags	move.l	d0,a1

		; get required width d2 and height d3

		btw	oxWinB_LAYOUT,oxWin_flags(a0)
		beq	.wihe_from_tags

		; get (/ set?) layout
		pushm	a0/a1

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_maxwidth(a1)

		lea	oxO_list(a3),a0
		move.l	(a0),a0			; get first member, getlayout only for first member
		tst.l	(a0)
		beq.b	.nomembers
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		moveq	#0,d2
		moveq	#0,d3
		movem.w	oxLI_minwidth(a1),d2/d3

		move.w	oxWin_spacing(a3),d0
		add.w	d0,d0
		add.w	d0,d2
		add.w	d0,d3

		movem.w	d2/d3,oxWin_minwidth(a3)

		moveq	#0,d4
		moveq	#0,d5
		movem.w	oxLI_maxwidth(a1),d4/d5
		
		bra.b	.restack

.nomembers	move.w	#80,d3

.restack	lea	oxLI_SIZEOF(a7),a7

		popm	a0/a1
		bra.b	.stacktags

.wihe_from_tags	; try get width/height from tags

		moveq	#0,d2
		moveq	#0,d3
		moveq	#0,d4
		moveq	#0,d5
		move.l	a1,a2

.readtags_loop	bsr	get_a_tag
		beq	.stacktags
		cmp.l	#WA_InnerWidth,d0
		beq	.found_w

		cmp.l	#WA_InnerHeight,d0
		beq	.found_h

		cmp.l	#WA_Width,d0
		bne	.h
.found_w	move.w	d1,d2
		bra	.readtags_loop

.h		cmp.l	#WA_Height,d0
		bne	.readtags_loop
.found_h	move.w	d1,d3
		bra	.readtags_loop		

.stacktags	; d2/d3 now width and height either from tags (?) or from layout

		cmp.w	#80,d2
		bgt.b	.wok		; width must be minimum 80px;
		move.w	#80,d2
.wok
		btw	oxWinB_LAYOUT,oxWin_flags(a3)
		beq	.nosetl

		push	a1

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		move.l	oxWin_wantedwidth(A3),d0
		cmp.w	d3,d0
		blt.b	.wanted_w
		move.w	d0,d3
.wanted_w	swap	d0
		cmp.w	d2,d0
		blt.b	.wanted_hw_ok
		move.w	d0,d2
.wanted_hw_ok
		move.w	oxWin_spacing(a3),d0

		move.w	d0,oxLI_left(a1)
		move.w	d0,oxLI_top(a1)
		add.w	d0,d0
		sub.w	d0,d2				; inner größe wegen rand
		sub.w	d0,d3
		movem.w	d2/d3,oxLI_width(a1)
		add.w	d0,d2				; for fenster größe
		add.w	d0,d3

		lea	oxO_list(a3),a0
		move.l	(a0),a0			; get first member, setlayout only for first member
		tst.l	(a0)
		beq.b	.nomember
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod
.nomember
		lea	oxLI_SIZEOF(a7),a7

		pop	a1

.nosetl		; link in user tags as next list

		move.l	a1,-(a7)
		moveq	#TAG_MORE,d0
		move.l	d0,-(a7)

		move.l	oxWin_firstgadget(a3),d0
		move.l	d0,-(a7)
		move.l	#WA_Gadgets,-(a7)

		moveq	#0,d0
		btw	oxWinB_BORDERLESS,oxWin_flags(a3)
		beq	.set_bdl
		move.l	#$ff,d0
		clr.l	oxWin_title(a3)
.set_bdl	move.l	d0,-(a7)
		move.l	#WA_Borderless,-(a7)
		not.b	d0

		clr.l	-(a7)

		move.l	libbase(pc),a0
		btst	#oxBB_MORPHOS,oxB_configflags(a0)
		bne	.siz
		move.l	iconbase(pc),a0
		cmp.w	#44,LIB_VERSION(a0)
		bge.b	.sizg
.siz		not.l	(a7)
.sizg		move.l	#WA_SizeGadget,-(a7)
		move.l	d0,-(a7)
		move.l	#WA_SizeBBottom,-(a7)
		move.l	d0,-(a7)
		move.l	#WA_DragBar,-(a7)
		move.l	d0,-(a7)
		move.l	#WA_CloseGadget,-(a7)
		move.l	d0,-(a7)
		move.l	#WA_DepthGadget,-(a7)

		move.l	d2,-(a7)
		move.l	#WA_InnerWidth,-(a7)

		move.l	d3,-(a7)
		move.l	#WA_InnerHeight,-(a7)

		; add window frame + sizegadgetheight to innersize = minsize

		move.l	oxWin_pubscreen(a3),a0

		movem.w	oxWin_minwidth(a3),d2/d3

		moveq	#0,d0
		move.b	sc_WBorTop(a0),d0
		addq	#1,d0
		add.w	sc_RastPort+rp_TxHeight(a0),d0
		add.w	d0,d3
		add.w	d6,d3		; add height of size-gadget

		move.b	sc_WBorLeft(a0),d0
		add.b	sc_WBorRight(a0),d0
		add.w	d0,d2

		move.l	d2,-(a7)
		move.l	#WA_MinWidth,-(a7)

		move.l	d3,-(a7)
		move.l	#WA_MinHeight,-(a7)

		move.l	d4,-(a7)
		move.l	#WA_MaxWidth,-(a7)

		move.l	d5,-(a7)
		move.l	#WA_MaxHeight,-(a7)

		move.l	oxWin_title(a3),-(a7)
		move.l	#WA_Title,-(a7)

		btw	oxWinB_UNDERMOUSE,oxWin_flags(a3)
		beq	.tags_ok

		asr.w	#1,d2
		asr.w	#1,d3
		move.l	ib_MouseY(a6),d1
		sub.w	d2,d1
		move.l	d1,-(a7)
		move.l	#WA_Left,-(a7)
		swap	d1
		sub.w	d3,d1
		move.l	d1,-(a7)
		move.l	#WA_Top,-(a7)

.tags_ok 	move.l	a7,a1

		sub.l	a0,a0
		jsr	_LVOOpenWindowTagList(a6)

		push	d0
		beq.b	.unlock

		moveq	#oxPT_SIZEOF,d0
		bsr	alloc_mem
		move.l	d0,oxWin_pentable(a3)
		beq.b	.unlock			; 0 is fail

		bsr	.allocpens		; *oxwin a3

		move.l	a3,a0
		move.l	oxWin_pentable(a3),a1
		moveq	#OXM_NEWPENS,d1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		move.l	(a7),oxWin_window(a3)
		bsr	.allocimages

		bsr	.send_inherit

		move.l	(a7),a0
		move.l	wd_RPort(a0),a1
		move.l	a1,oxWin_rastport(a3)
		move.l	a1,oxWin_frontrastport(a3)
		bset	#oxDIB_WINDOWOPEN,oxWin_drawflags(a3)
		move.l	a3,a0

		moveq	#OXM_WINDOWOPEN,d1
		move.l	(a7),a1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		; manage front and back (tabs and pages behind off)
		moveq	#OXM_FRONT,d1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

	;	; dumm dass ich hier nochmal senden muss fuer später erzeugte objekte...
	;	; dass objekt dem die aussen erzeigte objekte angehängt werdn sollte
	;	; über OXM_ADD die drawinfo runtersenden... 

	;	lea	oxWin_drawinfo(a3),a1
	;	move.l	a1,d1
	;	move.l	#oxA_drawinfo,d0
	;	bsr	_oxBroadcastAttr

.unlock		; unlock pubscreen
		
		sub.l	a0,a0				; NULL name
		move.l	oxWin_pubscreen(a3),a1
		jsr	_LVOUnlockPubScreen(a6)	

		pop	d0

		; restore stack

		lea	30*4(a7),a7

		btw	oxWinB_UNDERMOUSE,oxWin_flags(a3)
		beq	.stack_ok

		lea	4*4(a7),a7
.stack_ok
		move.l	d0,oxWin_window(a3)
		beq	.fail

		; store pointer to window-object in open window

		move.l	d0,a0
		move.l	a3,wd_UserData(a0)

		; set global msgport

		move.l	oxWin_msgport(a3),wd_UserPort(a0)

		push	a0

		; insert window as appwindow

		move.l	#"PDOS",d0	; ID	-	erkenne appmessage zwischen idcmp-messages 
		move.l	(a7),a0		; *intuiwindow to add as appwindow
		move.l	a0,d1		; userdata *intuiwindow
		move.l	oxWin_msgport(a3),a1
		sub.l	a2,a2
		move.l	wbbase(pc),a6
		jsr	_LVOAddAppWindowA(a6)
		move.l	d0,oxWin_appwindow(a3)

		; set idcmp flags

		move.l	(a7),a0

		move.l	intbase(pc),a6
		move.l	oxWin_idcmp(a3),d0
		jsr	_LVOModifyIDCMP(a6)

		; set font from screen

		pop	a0

		move.l	wd_RPort(a0),a1

		move.l	oxWin_font(a3),a0
		move.l	gfxbase(pc),a6
		jsr	_LVOSetFont(a6)

		bsr	get_offcanvas

		moveq	#OXM_LINKPRIV,d1
		move.l	a3,a0
		moveq	#OXBMODE_EVERYBODY,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

		bsr	oxWin_DR

	;	moveq	#OXM_DRAW,d1
	;	move.l	a3,a0
	;	moveq	#OXBMODE_EVERYBODY,d2
	;	bsr	_oxBroadcast

.success	moveq	#1,d0
		rts
.fail
.false		moveq	#0,d0
		rts

.sysiname	dc.b	"sysiclass",0
		even

.UPDATE		tst.l	oxWin_window(a3)
		beq.b	.stop

		moveq	#OXM_DROPGFXBUFFERS,d1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		bsr	.freepens
		bsr	.allocpens

		move.l	a3,a0
		move.l	oxWin_pentable(a3),a1
		moveq	#OXM_NEWPENS,d1
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		bsr	.freeimages
		bsr	.allocimages

		bsr	.send_inherit

		bsr	drop_offcanvas
		bsr	get_offcanvas

		bra.b	oxWin_DR

.stop		moveq	#-1,d0
		rts

.send_inherit	lea	-oxI_SIZEOF(a7),a7

		; set parameters for OXM_INHERIT

;	UBYTE	oxI_fillstyle	; pen, pattern, image
;	UBYTE	oxI_pattsize	; size for area pattern
;	UBYTE	oxI_frontpen
;	UBYTE	oxI_backpen
;	APTR	oxI_data	; pointer to pattern or pointer to image

		clr.b	oxI_fillstyle(a7)

		; try image first

		move.l	oxWin_theimagetable+oxIT_winbgimage(a3),oxI_data(a7)
		beq	.pattern
		move.b	#oxFILLSTYLE_IMAGE,oxI_fillstyle(a7)
		bra	.s_i

.pattern	btw	oxWinB_PATTERN,oxWin_flags(a3)
		beq	.pen

		move.l	oxWin_pentable(a3),a0
		move.b	oxPT_patternBpen(a0),oxI_frontpen(a7)
		move.b	oxPT_patternApen(a0),oxI_backpen(a7)
		lea	pattern1(pc),a0
		btw	oxWinB_PATTSTYLE2,oxWin_flags(a3)
		beq	.set_pat
		lea	pattern2(pc),a0
.set_pat	move.l	a0,oxI_data(a7)
		move.b	#oxFILLSTYLE_PATTERN,oxI_fillstyle(a7)
		move.b	#1,oxI_pattsize(a7)
		bra	.s_i

.pen		move.b	#oxFILLSTYLE_PEN,oxI_fillstyle(a7)
		move.l	oxWin_pentable(a3),a0
		move.b	oxPT_backpen(a0),oxI_frontpen(a7)

.s_i		move.l	a7,a1
		move.l	a3,a0
		moveq	#OXM_INHERIT,d1
		moveq	#OXBMODE_STOPLEVEL,d2
		bsr	_oxBroadcast
		lea	oxI_SIZEOF(a7),a7
		rts


.allocimages	push	a6

		move.l	libbase(pc),a6

		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.pop_2

		lea	oxB_imagetable(a6),a0
		move.l	oxWin_imagetable(a3),a1
		move.l	oxWin_window(a3),a2

		moveq	#oxIT_IMAGES,d2
.getimgs_lp	move.l	(a0)+,d0	
		beq.b	.gi_lp_c

		; d0 *imagename, a2 *window

		bsr	_oxGetImage
.gi_lp_c	move.l	d0,(a1)+
		dbf	d2,.getimgs_lp

.pop_2		pop	a6
		rts

.freeimages	move.l	oxWin_imagetable(a3),a2
		moveq	#oxIT_IMAGES,d2
.dropimages_lp	move.l	(a2)+,d0
		beq.b	.lp_c
		clr.l	-4(a2)
		move.l	d0,a0
		bsr	_oxDropImage
.lp_c		dbf	d2,.dropimages_lp
		rts

.allocpens	; a3 *oxwin

		pushm	d2-d6/a2/a4/a5/a6

		move.l	oxWin_pentable(a3),a4
		move.l	oxWin_pubscreen(a3),a2
		move.l	sc_ViewPort+vp_ColorMap(a2),a2
		move.l	libbase(pc),a5
		move.b	oxB_configflags(a5),d6
		lea	oxB_colortable(a5),a0
		move.l	gfxbase(pc),a6

		moveq	#0,d4			; reset alloc bits
		clr.l	(a4)+			; ...
		moveq	#0,d3
		moveq	#oxPT_COLORS,d5
		btst	#oxBB_4COLORMODE,d6
		beq.b	.ap_lp
		moveq	#3,d5

.ap_lp		move.l	(a0)+,d1		; read color vaule $rrggbb

		pushm	d3/d4/a0/a3

		moveq	#0,d2
		moveq	#0,d3
		move.b	d1,d3
		lsr.l	#8,d1
		move.b	d1,d2
		lsr.l	#8,d1

		move.l	d1,d0
		move.l	#$01010101,d1

		bsr	_mulu32	; d1*d0 to d0
		move.l	d0,d4

		move.l	d2,d0
		bsr	_mulu32
		move.l	d0,d2

		move.l	d3,d0
		bsr	_mulu32
		move.l	d0,d3

		move.l	d4,d1

		move.l	a2,a0			; colormap
		lea	.pens_tags(pc),a1
		jsr	_LVOObtainBestPenA(a6)

		tst.l	d0
		bge.b	.setbit

		move.l	d4,d1

		move.l	a2,a3
		moveq	#-1,d4
		jsr	_LVOFindColor(a6)
		popm	d3/d4/a0/a3
		bra.b	.setpen

.setbit		popm	d3/d4/a0/a3
		bset	d3,d4

.setpen		move.b	d0,(a4)+

		addq.w	#1,d3
		cmp.w	d5,d3
		ble.b	.ap_lp

		move.l	oxWin_pentable(a3),a4
		move.l	d4,oxPT_allocs(a4)

		btst	#oxBB_4COLORMODE,d6
		beq.b	.pops

		; 4 color-mode: map lowest 4 pens into higher pens

		move.l	oxWin_pentable(a3),a0
		move.b	oxPT_backpen(a0),d0
		move.b	oxPT_blackpen(a0),d1
		move.b	oxPT_whitepen(a0),d2
		move.b	oxPT_colorpen(a0),d3

		move.b	d0,oxPT_buttonpen(a0)
		move.b	d0,oxPT_tabspen(a0)
		move.b	d1,oxPT_textpen(a0)
		move.b	d1,oxPT_cursorpen(a0)
		move.b	d2,oxPT_shinepen(a0)
		move.b	d3,oxPT_darkpen(a0)
		move.b	d3,oxPT_patternApen(a0)
		move.b	d0,oxPT_patternBpen(a0)

		move.b	d0,oxPT_listpen(a0)
		move.b	d3,oxPT_listselpen(a0)
		move.b	d1,oxPT_listtextpen(a0)
		move.b	d2,oxPT_listalttextpen(a0)
		move.b	d3,oxPT_listofftextpen(a0)

		move.b	d0,oxPT_inputpen(a0)
		move.b	d2,oxPT_inputtextpen(a0)

.pops		popm	d2-d6/a2/a4/a5/a6
		bra.b	.success

.pens_tags	dc.l	OBP_Precision,PRECISION_EXACT
                dc.l    OBP_FailIfBad,0
		dc.l	TAG_END

.freepens	; a3 *oxwin

		pushm	d3/d4/a2/a4/a6

		move.l	oxWin_pentable(a3),a4
		move.l	oxWin_pubscreen(a3),a2
		move.l	sc_ViewPort+vp_ColorMap(a2),a2
		move.l	gfxbase(pc),a6

		moveq	#0,d0
		move.l	(a4)+,d4		; alloc bits

		moveq	#0,d3

.fp_lp		moveq	#0,d0			; must be ulong
		move.b	(a4)+,d0		; read pen value
		bclr	d3,d4
		beq.b	.fp_lp_c		; dont free if bit is null

		move.l	a2,a0
		jsr	_LVOReleasePen(a6)
.fp_lp_c	addq.w	#1,d3
		cmp.w	#oxPT_COLORS,d3
		ble.b	.fp_lp

		move.l	oxWin_pentable(a3),a4
		clr.l	(a4)	; oxPT_allocs
		popm	d3/d4/a2/a4/a6
		rts

.GET		move.l	(a1),d1

		cmp.l	#oxA_drawinfo,d1
		bne.b	.false
		lea	oxWin_drawinfo(a0),a0
		move.l	a0,d0
		rts

.SET		movem.l	(a1),d0/d1

		cmp.l	#oxWA_title,d0
		beq	.wa_title

		cmp.l	#oxWA_tags,d0
		beq	.wa_ostags
		cmp.l	#oxWA_undermouse,d0
		beq	.wa_undermouse
		cmp.l	#oxWA_layout,d0
		beq	.wa_layout
		cmp.l	#oxWA_pattern,d0
		beq	.wa_patt
		cmp.l	#oxWA_IDCMP,d0
		beq.b	.wa_idcmp
		cmp.l	#oxWA_closehook,d0
		beq.b	.wa_clsh
		cmp.l	#oxWA_wantedwidth,d0
		beq	.wa_wid
		cmp.l	#oxWA_wantedheight,d0
		beq	.wa_hig
		cmp.l	#oxWA_ichbindran,d0
		beq.b	.ichbindran
		cmp.l	#oxWA_tickuser,d0
		beq.b	.tickuser
		cmp.l	#oxWA_pattstyle2,d0
		beq	.patt2
		cmp.l	#oxWA_sigtaskclose,d0
		beq	.stc
		cmp.l	#oxWA_noautoclose,d0
		beq	.nac
		cmp.l	#oxWA_intuimessagehook,d0
		beq	.wa_imh
		cmp.l	#oxWA_newsizehook,d0
		beq	.wa_nsh
		cmp.w	#oxWA_borderless,d0
		beq	.wa_bdl
		cmp.w	#oxWA_gadgets,d0
		beq	W_AddGadgets
		bra	.false

.wa_nsh		move.l	d1,oxWin_newsizehook(a0)
		rts

.wa_imh		move.l	d1,oxWin_intuimessagehook(a0)
		rts

.wa_title	move.l	d1,oxWin_title(a0)
		rts

.tickuser	move.l	oxWin_idcmp(a0),d0
		move.l	d1,oxWin_tickuser(a0)
		beq	.ticks_off
		or.l	#IDCMP_INTUITICKS,d0
		bra.b	.setticksonoff

.ticks_off	clr.l	oxWin_tickuser(a0)
		move.l	#IDCMP_INTUITICKS,d1
		not.l	d1
		and.l	d1,d0

.setticksonoff	move.l	oxWin_window(a0),a0
		move.l	intbase(pc),a6
		jmp	_LVOModifyIDCMP(a6)


.ichbindran	; deactivate active object if any and set new active object

		move.l	oxWin_activeobject(a0),d0
		beq.b	.setactive
		cmp.l	d0,d1
		beq	.rts
		pushm	d1/a0
		move.l	d0,a0
		move.l	#OXM_INACTIVE,d1
		bsr	_oxDoMethod
		popm	d1/a0
.setactive	move.l	d1,oxWin_activeobject(a0)
.rts		rts

.wa_wid		move.w	d1,oxWin_wantedwidth(a0)
		rts
.wa_hig		move.w	d1,oxWin_wantedheight(a0)	
		rts

.wa_clsh	move.l	d1,oxWin_closehook(a0)
		rts

.wa_idcmp	move.l	d1,oxWin_idcmp,(a0)
		rts

.wa_patt	move.w	#oxWinF_PATTERN,d0
		bra.b	.wa_flag

.wa_layout	move.w	#oxWinF_LAYOUT,d0
		bra.b	.wa_flag

.wa_ostags	move.l	d1,oxWin_tags(a0)
		rts

.wa_undermouse	move.w	#oxWinF_UNDERMOUSE,d0
		bra.b	.wa_flag

.patt2		move.w	#oxWinF_PATTSTYLE2,d0
		bra.b	.wa_flag

.stc		move.w	#oxWinF_SIGTASKCLOSE,d0
		bra.b	.wa_flag

.wa_bdl		moveq	#oxWinF_BORDERLESS,d0
		bra	.wa_flag

.nac		move.w	#oxWinF_NOAUTOCLOSE,d0

.wa_flag	tst.w	d1
		beq	.clearflag
		or.w	d0,oxWin_flags(a0)
		rts

.clearflag	not.w	d0
		and.w	d0,oxWin_flags(a0)
		rts

W_AddGadgets	lea	oxWin_firstgadget(a3),a0

		; find the end of the gadgets list to add later

.loop		tst.l	(a0)
		beq	.set
		move.l	(a0),a0
		bra	.loop

.set		move.l	d1,(a0)
		rts

get_offcanvas	; get new layer, rasport and bitmap for offscreen drawing

		;	a3	*object

		pushm	a2/a4/a6

		; get other canvas only if DOUBLEBUFFER flag is set in oxbase

		move.l	libbase(pc),a0
		btst	#oxBB_DOUBLEBUFFER,oxB_configflags(a0)
		beq.b	.pop

		moveq	#rp_SIZEOF,d0
		bsr	alloc_mem
		move.l	d0,oxWin_offrastport(a3)
		beq.b	.pop

		move.l	d0,a1

		move.l	gfxbase(pc),a6
		jsr	_LVOInitRastPort(a6)

		; layer and bitmap

		move.l	oxWin_offrastport(a3),a1

		move.l	oxWin_font(a3),a0
		jsr	_LVOSetFont(a6)

		; init off bitmap and layer into off-rastport

		move.l	oxWin_rastport(a3),a0
		move.l	rp_BitMap(a0),a0
		moveq	#BMA_DEPTH,d1
		jsr	_LVOGetBitMapAttr(a6)
		move.l	d0,d2

		moveq	#0,d0			; bitmap size must be ULONG
		moveq	#0,d1

		move.l	oxWin_window(a3),a4
		move.l	wd_WScreen(a4),a0
		movem.w	wd_Width(a4),d0/d1

		add.w	#100,d0			; sicherheitsstreifen wegen problematischer randzone 

		move.l	#BMF_MINPLANES,d3

		move.l	sc_RastPort+rp_BitMap(a0),a0	; friend bitmap
		jsr	_LVOAllocBitMap(a6)

		move.l	oxWin_offrastport(a3),a0

		move.l	d0,rp_BitMap(a0)
		beq.b	.rem_rp

		move.l	layersbase(pc),a6
		jsr	-144(a6)			;_LVONewLayerInfo(a6)
		tst.l	d0
		beq.b	.rem_bm

		move.l	d0,a0
		push	a0	; merken falls kein speicher für layer

		moveq	#0,d0
		moveq	#0,d1
		moveq	#0,d2
		moveq	#0,d3
		movem.w	wd_Width(a4),d2/d3

		add.l	#100,d2			; sicherheitsstreifen s.o.

		subq.w	#1,d2
		subq.w	#1,d3

		move.l	oxWin_offrastport(a3),a1
		move.l	rp_BitMap(a1),a1

		moveq	#LAYERSIMPLE,d4
		sub.l	a2,a2
		jsr	-36(a6)				;_LVOCreateUpfrontLayer(a6)

		move.l	oxWin_offrastport(a3),a0
		move.l	d0,rp_Layer(a0)

		pop	a0
		bne.b	.pop

		; rem layerinfo

		jsr	-150(a6)			;_LVODisposeLayerInfo(a6)

.rem_bm		move.l	oxWin_offrastport(a3),a0
		move.l	rp_BitMap(a0),a0
		jsr	_LVOFreeBitMap(a6)

.rem_rp		move.l	oxWin_offrastport(a3),a0
		moveq	#rp_SIZEOF,d0
		bsr	free_mem
		clr.l	oxWin_offrastport(a3)		; do all without double buffer

.pop		popm	a2/a4/a6
		rts

drop_offcanvas	; drop layer, rasport and bitmap for offscreen drawing

		; 	a3	*object

		pushm	a2/a6

		move.l	oxWin_offrastport(a3),d0
		beq.b	.pop

		clr.l	oxWin_offrastport(a3)

		move.l	d0,a2

		move.l	layersbase(pc),a6

		move.l	rp_Layer(a2),a1
		move.l	lr_LayerInfo(a1),-(a7)
		jsr	-90(a6)				;_LVODeleteLayer(a6)
		pop	a0
		jsr	-150(a6)			;_LVODisposeLayerInfo(a6)

		move.l	gfxbase(pc),a6
		jsr	_LVOWaitBlit(a6)

		move.l	rp_BitMap(a2),a0
		jsr	_LVOFreeBitMap(a6)

		move.l	a2,a0
		moveq	#rp_SIZEOF,d0
		bsr	free_mem

.pop		popm	a2/a6
		rts

oxWin_NEWSIZE	tst.l	oxWin_window(a0)
		beq.b	wu_rts_neg

		move.l	a0,a3

		; rethink size of off-screen drawing area (for doublebuffering)

		bsr	drop_offcanvas
		bsr	get_offcanvas

		; stack layout-info struct

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		move.w	oxWin_spacing(a3),d0

		move.w	d0,oxLI_left(a1)
		move.w	d0,oxLI_top(a1)

		add.w	d0,d0
		move.l	oxWin_window(a3),a0
		movem.w	wd_GZZWidth(a0),d2/d3

		sub.w	d0,d2
		sub.w	d0,d3
		movem.w	d2/d3,oxLI_width(a1)

		btw	oxWinB_LAYOUT,oxWin_flags(a3)
		beq	.size_hook

		lea	oxO_list(a3),a0
		move.l	(a0),a0			; get first member, getlayout only for first member
		tst.l	(a0)
		beq.b	.size_hook

		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

.size_hook	; call new size hook

		move.l	oxWin_newsizehook(a3),d0
		beq.b	.refresh

		push	a3

		move.l	d0,a2
		jsr	(a2)

		pop	a3

.refresh	; refresh

		bsr.b	oxWin_DR

		lea	oxLI_SIZEOF(a7),a7

wu_rts_neg	moveq	#-1,d0
		rts

oxWin_DRAW	move.l	a0,a3
oxWin_DR	tst.l	oxWin_window(a3)
		beq.b	.rts_stop

		move.l	a3,a0
		moveq	#OXRMODEF_ALL,d4
		bsr	_oxBeginRefresh

		move.l	d0,a2
		move.l	oxWin_window(a3),a4

		bsr.b	drawbg

		moveq	#OXM_DRAW,d1
		move.l	a3,a0
		moveq	#OXBMODE_EVERYBODY,d2
		bsr	_oxBroadcast

		; position and draw sizing icon

		move.l	oxWin_sizeicon(a3),d2
		beq	.end_ref

		move.l	oxWin_window(a3),a0
		movem.w	wd_GZZWidth(a0),d0/d1

		move.l	d2,a0

		sub.w	oxWin_sizewidth(a3),d0
		sub.w	oxWin_sizeheight(a3),d1

		move.l	a2,a1

		moveq	#FALSE,d2
		bsr	_oxDrawIcon

.end_ref	move.l	a3,a0
		moveq	#OXRMODEF_ALL,d4
		bsr	_oxEndRefresh

.rts_stop	moveq	#-1,d0
		rts

_oxBeginRefresh	; set draw to off_rasport / -bitmap and layer

			; *windowobject a0

		move.l	oxWin_offrastport(a0),d0
		beq.b	.ret_front_rp

		move.l	d0,oxWin_rastport(a0)

	;	btst	#OXRMODEB_ALL,d4			et COPY

		move.l	oxWin_offrastport(a0),d0
		rts
.ret_front_rp	move.l	oxWin_rastport(a0),d0
		rts

_oxEndRefresh		; revert to front-rastport and blit back-bitmap into front-rastport

		; a0	*windowobject

		pushm	d0-d6/a0/a1/a6

		tst.l	oxWin_offrastport(a0)
		beq.b	.pop

		move.l	oxWin_frontrastport(a0),d0
		move.l	d0,oxWin_rastport(a0)

		; copy off-bitmap to front-bitmap

		move.l	gfxbase(pc),a6
		jsr	_LVOWaitTOF(a6)
	
		move.l	7*4(a7),a0

		btst	#OXRMODEB_ALL,4*4+3(a7)
		bne.b	.all

		movem.l	(a7),d0/d1/d4/d5
		bra.b	.blit

.all		move.l	oxWin_window(a0),a1
		movem.w	wd_GZZWidth(a1),d4/d5
		moveq	#0,d0
		moveq	#0,d1

.blit		move.l	oxWin_frontrastport(a0),a1
		move.l	oxWin_offrastport(a0),a0
		move.l	rp_BitMap(a0),a0
		move.w	d0,d2
		move.w	d1,d3
		move.b	#$c0,d6
		jsr	_LVOBltBitMapRastPort(a6)

.pop		popm	d0-d6/a0/a1/a6
.rts		rts

win_refgads	move.l	oxWin_window(a0),a1
		move.l	wd_FirstGadget(a1),d0
		beq.b	.rts
		move.l	d0,a0
		move.l	intbase(pc),a6
		jmp	_LVORefreshGadgets(a6)

.rts		rts

drawbg		; blank	inner window area before redraw 

		bsr.b	win_pattern
		bne.b	.nofill

		move.l	a2,a1
		moveq	#0,d0		; block color
		move.l	gfxbase(pc),a6
		jsr	_LVOSetAPen(a6)

		moveq	#0,d0
		moveq	#0,d1
		movem.w	wd_GZZWidth(a4),d2/d3
		move.l	a2,a1
		jsr	_LVORectFill(a6)
.nofill
		rts

win_pattern	btw	oxWinB_FILLBG,oxWin_flags(a3)
		beq	.rts_true

		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.if_pattern

		move.l	oxWin_theimagetable+oxIT_winbgimage(a3),d0
		beq.b	.if_pattern

		move.l	d0,a0
		move.l	a2,a1

		moveq	#0,d0
		moveq	#0,d1
		movem.w	wd_GZZWidth(a4),d2/d3

		moveq	#0,d4
		moveq	#0,d5

		bsr	_oxImageFill
		bra.b	.rts_true

.if_pattern	btw	oxWinB_PATTERN,oxWin_flags(a3)
		beq.b	.rts

		move.l	oxWin_pentable(a3),a5
		move.l	gfxbase(pc),a6

		lea	winpattern1(pc),a1

		btw	oxWinB_PATTSTYLE2,oxWin_flags(a3)
		beq.b	.patt

		lea	winpattern2(pc),a1

.patt		move.w	(a1)+,d0
		move.b	d0,rp_AreaPtSz(a2)
		move.b	(a1)+,d0
		move.b	(a5,d0.w),d0
		moveq	#0,d1
		move.b	(a1)+,d1
		move.b	(a5,d1.w),d1
		move.l	a1,rp_AreaPtrn(a2)
		moveq 	#RP_JAM2,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		moveq	#0,d0
		moveq	#0,d1
		movem.w	wd_GZZWidth(a4),d2/d3
		move.l	a2,a1
		jsr	_LVORectFill(a6)

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

.rts_true	moveq	#1,d0
.rts		rts

winpattern1	dc.w	1		; Höhe in Zeilen-1
pattern1	dc.b	oxPT_patternBpen,oxPT_patternApen	; Farben f,b
		dc.w	%1000100010001000,%0010001000100010
winpattern2	dc.w	1
pattern2	dc.b	oxPT_patternBpen,oxPT_patternApen	; Farben f,b
		dc.w	%1010101010101010,%0101010101010101

fixedfont	dc.l	.name		; ta_Name	name of the desired font
		dc.w	15		; ta_YSize	height of the desired font
		dc.b	0		; ta_Style	desired font style
		dc.b	FPF_DESIGNED	; ta_Flags	font preferences flags
.name		dc.b	"courier.font",0
		even

alloc_pens	; allocate up to 32 pens (no more)!

		; a0 *oxwin
		; a1 *colortable
		; a2 *pentable	(destination whereto the pens are written)
		; a3 static color table for 4 color mode
		; d0 num pens, base 0

		;>d0 alloc mask

		pushm	d2-d7/a2-a6

		move.l	libbase(pc),a6
		btst	#oxBB_4COLORMODE,oxB_configflags(a6)
		beq.b	.multicolor

		; 4 color mode

		move.l	oxWin_pentable(a0),a0
		moveq	#0,d1

.4_loop		move.b	(a3)+,d1
		move.b	4(a0,d1.w),d1
		move.b	d1,(a2)+
		dbf	d0,.4_loop

		moveq	#0,d0
		bra	.pop

.multicolor	move.l	a1,a4

		move.w	d0,d5			; counter
		moveq	#-1,d6			; alloc mask

		move.l	oxWin_pubscreen(a0),a3
		move.l	sc_ViewPort+vp_ColorMap(a3),a3

		move.l	gfxbase(pc),a6

.alloc_loop	move.l	(a4)+,d1		; read color vaule $rrggbb

		moveq	#0,d2
		moveq	#0,d3
		move.b	d1,d3
		lsr.l	#8,d1
		move.b	d1,d2
		lsr.l	#8,d1

		move.l	d1,d0
		move.l	#$01010101,d1

		bsr	_mulu32	; d1*d0 to d0
		move.l	d0,d4

		move.l	d2,d0
		bsr	_mulu32
		move.l	d0,d2

		move.l	d3,d0
		bsr	_mulu32
		move.l	d0,d3

		move.l	d4,d1

		move.l	a3,a0			; colormap
		lea	.pens_tags(pc),a1
		jsr	_LVOObtainBestPenA(a6)

		tst.l	d0
		bge.b	.setpen

		bclr	d5,d6			; if bit is clear, no allocation was done for the corresponding color

		move.l	d4,d1

		moveq	#-1,d4
		jsr	_LVOFindColor(a6)

.setpen		move.b	d0,(a2)+
		dbf	d5,.alloc_loop

		move.l	d6,d0

.pop		popm	d2-d7/a2-a6
		rts

.pens_tags	dc.l	OBP_Precision,PRECISION_EXACT
                dc.l    OBP_FailIfBad,0
		dc.l	TAG_END

free_pens	; d0 numpens, base 0
		; d1 allocmask, each bit 0 to numpens indicates wether
		;    the corresponding color was allocated (TRUE = yes)
		; a0 ox window object
		; a2 pentable

		pushm	d2/d3/a0-a3/a6

		move.l	oxWin_pubscreen(a0),a3
		move.l	sc_ViewPort+vp_ColorMap(a3),a3

		move.l	gfxbase(pc),a6

		move.w	d0,d2
		move.l	d1,d3

.loop		moveq	#0,d0
		move.b	(a2)+,d0

		btst	d2,d3
		beq	.continue_loop

		move.l	a3,a0
		jsr	_LVOReleasePen(a6)

.continue_loop	dbf	d2,.loop

		popm	d2/d3/a0-a3/a6

		rts

;--------------------------------------------------------------------
; OX_BOOPSI

; boopsi object

 STRUCTURE	oxBoopsi,oxO_SIZEOF
	APTR	oxBop_boopsiobject
	APTR	oxBop_classname
	APTR	oxBop_tags
	UWORD	oxBop_flags
	LABEL	oxBop_SIZEOF

	BITDEF	oxBop,GADGET,0

	OXICLASSHEADER	boopsi, 1, 0, field

	dc.l	oxCA_objectsize,oxBop_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
;	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	TAG_END

.dispatcher	cmp.w	#OXM_DRAW,d1
		beq	.DRAW


		cmp.w	#OXM_SET,d1
		beq	.SET
		cmp.w	#OXM_GET,d1
		beq	.GET

	;	cmp.w	#oxWM_,d1
	;	beq	.
	;	cmp.w	#oxWM_,d1
	;	beq	.

		cmp.w	#OXM_DEINIT,d1
		beq	.DEINIT
		cmp.w	#OXM_INIT,d1
		beq	.INIT

.return		rts

.DRAW		btw	oxBopB_GADGET,oxBop_flags(a0)
		beq	.return

	rts

		move.l	oxBop_boopsiobject(a0),a0
	;	move.l	oxD_window(a1),a1
		suba.l	a2,a2
		moveq	#1,d0
		move.l	intbase(pc),a6
		jmp	_LVORefreshGList(a6)

.DEINIT		move.l	oxBop_boopsiobject(a0),d0
		beq	.return
		move.l	d0,a0
		move.l	intbase(pc),a6
		jsr	_LVODisposeObject(a6)
		rts

.INIT		move.l	a0,a3
		move.l	a1,a5

		move.l	oxBop_classname(a0),d0
		beq	.fail
		move.l	d0,a1
		move.l	oxBop_tags(a0),d0
		beq	.fail
		move.l	d0,a2
		sub.l	a0,a0
		move.l	intbase(pc),a6
		jsr	_LVONewObjectA(a6)

		move.l	d0,oxBop_boopsiobject(a3)
		beq	.fail

		move.l	d0,a4		; a4 pointer to boopsi object

		; via previous and to window auto connection
		; support only for boopsi "gadgetclass" f.f.

		move.l	-4(a4),a0	; get boopsi class pointer
.getid		move.l	cl_ID(a0),d1
		bne	.ifclass
.super		move.l	cl_Super(a0),d0
		beq	.success
		move.l	d0,a0
		bra	.getid

.ifclass	move.l	d1,a1
		lea	.gc_name(pc),a2
.loop		cmp.b	(a2)+,(a1)+
		bne	.super
		tst.b	(a2)
		bne	.loop
		tst.b	(a1)
		bne	.super

		; set a flag this object is an intuition gadget
		; that can be drawn or added to intuition windows

		or.w	#oxBopF_GADGET,oxBop_flags(a3)

;		move.l	oxCI_lastgadget(a5),d0
;		beq	.set_prev

		; auto link to previous gadget

;		move.l	d0,a0
;		move.l	a4,gg_NextGadget(a0)

;.set_prev	move.l	a4,oxCI_lastgadget(a5)

.success	moveq	#1,d0
		rts

.fail		moveq	#-1,d0
		rts
.false		moveq	#0,d0
		rts

.GET		move.l	(a1),d1

;		cmp.l	#oxA_GadgetPointer,d1
;		beq	.a_gadptr

		bra	.false

.a_gadptr	btw	oxBopB_GADGET,oxBop_flags(a0)
		beq	.false
		move.l	oxBop_boopsiobject(a0),d0
		rts

.SET		movem.l	(a1),d0/d1

		cmp.l	#oxBOPA_TAGS,d0
		beq	.a_bpstags
		cmp.l	#oxBOPA_TYPE,d0
		beq	.a_type

		rts

.a_bpstags	move.l	d1,oxBop_tags(a0)
		rts

.a_type		move.l	d1,oxBop_classname(a0)
		rts

.gc_name	dc.b	"gadgetclass",0
		even



		; send a tag from stack to a (boopsi) gadget

;		clr.l	-(A7)	; TAG_END
;		move.l	d0,-(a7)
;		move.l	#GA_Previous,-(a7)

;		move.l	a7,a3
;		move.l	a4,a0		; gadget
;		sub.l	a2,a2
;		sub.l	a1,a1		; try NULL window
	;	jsr	_LVOSetGadgetAttrsA(a6)

;		lea	12(a7),a7


;--------------------------------------------------------------------
; OX_FIELD

 STRUCTURE	oxField,oxO_SIZEOF
	APTR	oxFd_text
	APTR	oxFd_wrappedtext
	UWORD	oxFd_linecount
	UWORD	oxFd_minlines
	UWORD	oxFd_minwidth
	UWORD	oxFd_minheight
	UWORD	oxFd_left
	UWORD	oxFd_top
	UWORD	oxFd_width
	UWORD	oxFd_height
	UWORD	oxFd_hprop
	UWORD	oxFd_vprop

	APTR	oxFd_oldregion
	STRUCT	oxFd_Region,rg_SIZEOF
	STRUCT	oxFd_RegionRectangle,rr_SIZEOF

	UWORD	oxFd_TextWidth		; calculated
	UWORD	oxFd_TextHeight	; calculated

	UWORD	oxFd_contentleft
	UWORD	oxFd_contenttop

	WORD	oxFd_percent		; for gauge-mode
	STRUCT	oxFd_perctext,6	; contains "xxx%",0

	UBYTE	oxFd_flags
	UBYTE	oxFd_fillpen
	UBYTE	oxFd_gaugepen
	UBYTE	oxFd_pad

	ULONG	oxFd_color

	APTR	oxFd_colormap		; gets it from intui-window
	APTR	oxFd_drawinfo

	APTR	oxFd_fill_imagename
	APTR	oxFd_fill_image
	APTR	oxFd_inherited_image

	UBYTE	oxFd_custompen
	UBYTE	oxFd_iflags

	STRUCT	oxFd_valstring,12

	LABEL	oxFd_SIZEOF

	BITDEF	oxFdi,INHERIT,0
	BITDEF	oxFdi,FIXEDFONT,6
	BITDEF	oxFdi,HASCOLOR,7


	OXICLASSHEADER	field, 1, 0, frame

	dc.l	oxCA_objectsize,oxFd_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,.create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: The field-gadget is for displaying any text, a color or a gauge. It is able "
		dc.b	"to /blayout/x the text wide, narrow or wrapped and to clip it if it does not fit.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	.SET

		cmp.w	#OXM_GET,d1
		beq	.GET

		cmp.w	#OXM_DRAW,d1
		beq	.DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	.UPDATE	

		cmp.w	#OXM_GETLAYOUT,d1
		beq	.GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	.SETLAYOUT

		cmp.w	#OXM_SETDEF,d1
		beq	.SETDEF

		cmp.w	#OXM_DEINIT,d1 
		beq	.DEINIT

		cmp.w	#OXM_INIT,d1 
		beq	.INIT

		cmp.w	#OXM_WINDOWCLOSING,d1 
		beq	.WINDOWCLOSING

		cmp.w	#OXM_WINDOWOPEN,d1 
		beq	.WINDOWOPEN

		cmp.w	#OXM_FRONT,d1 
		beq	.FRONT

		cmp.w	#OXM_BACK,d1 
		beq	.BACK

		cmp.w	#OXM_INHERIT,d1 
		beq	.INHERIT

		cmp.w	#OXM_NEWPENS,d1
		beq	.NEWPENS

		rts

.FRONT		bset	#oxOB_VISIBLE,oxO_flags(a0)
		rts
.BACK		bclr	#oxOB_VISIBLE,oxO_flags(a0)
		rts

.create_ex	lea	.ex_group(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

.ex_group	dc.l	oxGA_spaceprop,1
	;	dc.l	OX_FIELD,.ex_wide
	dc.l	OX_VERTGROUP,.wide_g
		dc.l	OX_VERTGROUP,.nar_g
		dc.l	TAG_END

.wide_g		dc.l	OX_FIELD,.ex_wide
		dc.l	TAG_END

.nar_g		dc.l	OX_HORIZGROUP,.nar_gi
		dc.l	OX_HORIZGROUP,.gauge_g
		dc.l	TAG_END

.nar_gi		dc.l	OX_FIELD,.ex_narrow
		dc.l	TAG_END

.gauge_g	dc.l	OX_FIELD,.ex_gauge
		dc.l	TAG_END

.ex_gauge	dc.l	oxFdA_flags,oxFdF_GAUGE	;+oxFdF_WIDE ;text zu tief
		dc.l	oxFdA_percent,40
		dc.l	oxFdA_minwidth,90
		dc.l	TAG_END

.ex_wide	dc.l	oxFdA_text,.ex_wide_text
		dc.l	oxFdA_flags,oxFdF_WIDE		;+oxFdF_BDLESS
		dc.l	TAG_END

.ex_narrow	dc.l	oxFdA_text,.ex_narrow_text
		dc.l	oxFdA_flags,oxFdF_LAYOUT
		dc.l	oxFdA_minlines,4
		dc.l	oxFdA_minwidth,103
		dc.l	TAG_END

.ex_wide_text	dc.b	"this is",$a
		dc.b	"wide",0
.ex_narrow_text	dc.b	"A /ifield/x /hcan do/x /b/aautomagic/x /uword-wrap/x.",0
		even

.SETDEF		lea	oxFd_RegionRectangle(a0),a1
		move.l	a1,oxFd_Region+rg_RegionRectangle(a0)

		move.w	#1,oxFd_linecount(a0)

		moveq	#-1,d0			; no color allocated
		move.l	d0,oxFd_color(a0)

		or.b	#oxFdiF_INHERIT,oxFd_iflags(a0)

		rts

.WINDOWOPEN	push	a1

		move.l	wd_WScreen(a1),a1
		move.l	sc_ViewPort+vp_ColorMap(a1),oxFd_colormap(a0)

		move.l	a0,a3

		move.l	oxFd_color(a3),d7
		bmi.b	.get_image

		bsr.b	.alloc_pen

.get_image	pop	a2

		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.rts4

		move.l	oxFd_fill_imagename(a3),d0
		move.l	libbase(pc),a6
		bsr	_oxGetImage
		move.l	d0,oxFd_fill_image(a3)
.rts4		rts

.WINDOWCLOSING	move.l	oxFd_fill_image(a0),d0
		beq.b	.rts4
		clr.l	oxFd_fill_image(a0)
		move.l	d0,a0
		jmp	_oxDropImage

.INIT		bra	.new_wrapped_text_buffer

.new_wrapped_text_buffer

		btst	#oxFdB_LAYOUT,oxFd_flags(a3)
		beq.b	.rts4

		move.l	oxFd_text(a3),d0
		beq.b	.rts4

		move.l	d0,a0

		moveq	#-1,d0
.l		tst.b	(a0)+
		dbeq	d0,.l
		not.l	d0

		addq	#1,d0

		bsr	alloc_rem
		move.l	d0,oxFd_wrappedtext(a3)
		rts

.DEINIT		move.l	a0,a3

		bsr.b	.WINDOWCLOSING

		; free wrapped text if present

		move.l	oxFd_wrappedtext(a3),d0
		beq.b	.release_pen

		move.l	d0,a0
		bsr	free_rem

.release_pen	bclr	#oxFdiB_HASCOLOR,oxFd_iflags(a3)
		beq.b	.rts
		tst.l	oxFd_colormap(a3)
		beq.b	.rts
		moveq	#0,d0			; d0 must be ULONG
		move.b	oxFd_custompen(a3),d0
		move.l	oxFd_colormap(a3),a0
		move.l	gfxbase(pc),a6
		jmp	_LVOReleasePen(a6)

.GET		move.l	(a1),d1

		cmp.l	#oxFdA_visiblelines,d1
		bne.b	.null
		
		move.w	oxFd_height(a0),d0
		subq.w	#8,d0	; rahmen wegrechnen

		move.l	oxFd_drawinfo(a0),d1
		beq.b	.null
		move.l	d1,a1
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a1)
		beq.b	.null

		btst	#oxFdiB_FIXEDFONT,oxFd_iflags(a0)
		beq.b	.font
		move.l	oxDI_fixedfont(a1),a0
		bra.b	.calc
.font		move.l	oxDI_font(a1),a0

.calc		move.w	tf_YSize(a0),d1
		divu.w	d1,d0
		rts
.null		moveq	#0,d0
		rts

.NEWPENS	move.b	oxPT_backpen(a1),oxFd_fillpen(a0)
		move.b	oxPT_colorpen(a1),oxFd_gaugepen(a0)

		rts

.INHERIT	clr.l	oxFd_inherited_image(a3)

		btst	#oxFdiB_INHERIT,oxFd_iflags(a3)
		beq	.rts18

		cmp.b	#oxFILLSTYLE_IMAGE,oxI_fillstyle(a1)
		bne.b	.ih_pen_patt

		move.l	oxI_data(a1),oxFd_inherited_image(a3)
		rts

.ih_pen_patt	;cmp.b	#oxFILLSTYLE_PEN,oxI_fillstyle(a1)
		;bne.b	.pattern

		move.b	oxI_frontpen(a1),oxFd_fillpen(a3)
		bset	#oxFdB_FILL,oxFd_flags(a3)

.rts18		rts

.SET		movem.l	(a1),d0/d1

		cmp.w	#oxFdA_inherit,d0
		bne	.val
		moveq	#oxFdiF_INHERIT,d0
.iflag		tst.w	d1
		beq	.cleariflag
		or.b	d0,oxFd_iflags(a0)
		rts
.cleariflag	not.b	d0
		and.b	d0,oxFd_iflags(a0)
		rts

.val		cmp.l	#oxFdA_value,d0
		bne.b	.di
		lea	oxFd_valstring(a0),a1
		move.l	a1,oxFd_text(a0)
		move.l	a1,a0
		move.l	d1,d0
		bra	ValToDez

.di		cmp.l	#oxA_drawinfo,d0
		bne.b	.if_color
		move.l	d1,oxFd_drawinfo(a0)
		rts

.if_color	cmp.l	#oxFdA_color,d0
		bne.b	.if_text

		bset	#oxFdB_FILL,oxFd_flags(a0)

		move.l	a0,a3
		move.l	d1,d7

		; only do something if we are open and active

		tst.l	oxFd_colormap(a3)
		beq.b	.set_color	; if we arent active, no color can be allocated, so just overwrite it

		bclr	#oxFdiB_HASCOLOR,oxFd_iflags(a3)
		beq.b	.alloc

		; free old pen

		moveq	#0,d0			; d0 must be ULONG
		move.b	oxFd_custompen(a3),d0
		move.l	oxFd_colormap(a3),a0
		move.l	gfxbase(pc),a6
		jsr	_LVOReleasePen(a6)

.alloc		bsr	.alloc_pen
	;	bsr	.draw_redraw

.set_color	move.l	d7,oxFd_color(a3)

		rts

.alloc_pen	bset	#oxFdiB_HASCOLOR,oxFd_iflags(a3)
		bne.b	.rts
		move.l	d7,d1
		bsr	WG_24toRGB
		pushm	d1-d3
		moveq	#0,d4		; shared access
		moveq	#-1,d0		; any pen
		move.l	oxFd_colormap(a3),a0
		move.l	gfxbase(pc),a6
		jsr	_LVOObtainPen(a6)
		popm	d1-d3
		tst.l	d0
		bge.b	.set_pen
		push	a3
		moveq	#-1,d4
		move.l	oxFd_colormap(a3),a3
		jsr	_LVOFindColor(a6)
		pop	a3
		bclr	#oxFdiB_HASCOLOR,oxFd_iflags(a3)
.set_pen	move.b	d0,oxFd_custompen(a3)
		rts

.if_text	cmp.l	#oxFdA_text,d0
		bne	.if_min
		bclr	#oxFdB_GAUGE,oxFd_flags(a0)
		move.l	d1,oxFd_text(a0)
		beq	.set_linecount	; clear it
		move.l	d1,a1
		moveq	#1,d1
.lines_lp	move.b	(a1)+,d0
		beq.b	.set_linecount
		cmp.b	#$a,d0
		bne.b	.lines_lp
		addq.w	#1,d1
		bra.b	.lines_lp
.set_linecount	move.w	d1,oxFd_linecount(a0)
		rts

.if_min		cmp.l	#oxFdA_minlines,d0
		bne	.if_hprop
		move.w	d1,oxFd_minlines(a0)
		rts
.if_hprop	cmp.l	#oxFdA_hprop,d0
		bne.b	.if_vprop
		move.w	d1,oxFd_hprop(a0)
		rts
.if_vprop	cmp.l	#oxFdA_vprop,d0
		bne.b	.if_flags
		move.w	d1,oxFd_vprop(a0)
		rts
.if_flags	cmp.l	#oxFdA_flags,d0
		bne.b	.if_fill
		btst	#oxFdB_GAUGE,d1
		beq.b	.notgauge
		bset	#oxFdB_CENTER,d1
	;	bset	#oxFdB_FILL,d1
		or.b	d1,oxFd_flags(a0)
		moveq	#0,d1
		bra.b	.perc		
.notgauge	or.b	d1,oxFd_flags(a0)
		rts
.if_fill	cmp.l	#oxFdA_fillpen,d0
		bne.b	.if_gp
		move.b	d1,oxFd_fillpen(a0)
		bset	#oxFdB_FILL,oxFd_flags(a0)
		rts

.if_gp		cmp.l	#oxFdA_gaugepen,d0
		bne.b	.if_minw
		move.b	d1,oxFd_gaugepen(a0)
		bset	#oxFdB_GAUGE,oxFd_flags(a0)
		rts

.if_minw	cmp.l	#oxFdA_minwidth,d0
		bne.b	.if_perc
		move.w	d1,oxFd_minwidth(a0)
		bra.b	.rts
.if_perc	cmp.l	#oxFdA_percent,d0
		bne.b	.if_softval
.perc		move.w	d1,oxFd_percent(a0)
		bset	#oxFdB_GAUGE,oxFd_flags(a0)
		lea	oxFd_perctext(a0),a1
		move.l	a1,oxFd_text(a0)
		move.l	a1,a0
		moveq	#0,d0
		move.w	d1,d0
		bsr	ValToDez
		move.b	#"%",(a0)+
		clr.b	(a0)
		rts
.if_softval	cmp.l	#oxFdA_softval,d0
		bne.b	.if_image
		move.l	d1,d0
		moveq	#0,d1
		move.w	#100,d1
		mulu.w	d0,d1
		move.w	#OXPROP_SOFTMAX,d0
;		sub.w	oxFd_softbody(a0),d0

		; runden: die Hälfte des Divisors zum Dividend addieren,
		; 	  (divd + divs / 2) / divs
		;  damit damit mittlerer wert = 50%

		moveq	#0,d2
		move.w	d0,d2
		lsr.w	#1,d2
		add.l	d2,d1
		;     divs divd  
		divu.w	d0,d1

		ext.l	d1

		bra.b	.perc
;.if_body	cmp.l	#oxFdA_softbody,d0
;		bne.b	.if_image
;		move.w	d1,oxFd_softbody(a0)
;		rts
.if_image	cmp.l	#oxFdA_imagename,d0
		bne.b	.fixfont
		move.l	d1,oxFd_fill_imagename(a0)
		rts

.fixfont	cmp.l	#oxFdA_fixedfont,d0
		bne.b	.rts
		or.b	#oxFdiF_FIXEDFONT,oxFd_iflags(a0)

.rts		rts

.UPDATE		move.l	oxFd_drawinfo(a0),a2

		tst.l	oxDI_rastport(a2)
		beq	.rts1

		move.l	oxDI_rastport(a2),a2
		move.l	a0,a3

		btst	#oxFdB_LAYOUT,oxFd_flags(a3)
		beq.b	.get_sizes

		move.l	oxFd_wrappedtext(a3),d0
		beq.b	.make_new

		move.l	d0,a0
		bsr	free_rem

.make_new	bsr	.new_wrapped_text_buffer

		bsr	wrap_text

.get_sizes	bsr	.gettextsizes
		bsr	.centercontent

		btst	#oxFdB_UPDATEREDRAW,oxFd_flags(a3)
		beq.b	.rts1

		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		moveq	#OXRMODEF_ALL,d4
		bsr	_oxBeginRefresh
		move.l	d0,a2			; now use this rastport as returned

		bsr.b	.draw_subrou

		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		moveq	#0,d4
		movem.w	oxFd_left(a3),d0-d3
		bra	_oxEndRefresh

		rts

.DRAW		move.l	a0,a3
.draw_redraw	move.l	oxFd_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

.draw_subrou	move.l	oxFd_drawinfo(a3),a5

		btst	#oxDIB_WINDOWOPEN,oxDI_flags(A5)
		beq.b	.rts1

		btst	#oxOB_VISIBLE,oxO_flags(a3)	; dont draw if we are in the back
		beq.b	.rts1

		move.l	oxDI_pentable(a5),a5

		move.l	gfxbase(pc),a6

		movem.w	oxFd_left(a3),d0-d3
		subq.w	#1,d2
		subq.w	#1,d3
		add.w	d0,d2
		add.w	d1,d3

		btst	#oxFdB_BDLESS,oxFd_flags(a3)
		bne.b	.nohole

		move.b	oxPT_blackpen(a5),d4
		move.b	oxPT_shinepen(a5),d5

	bra.b	.nohole2
		move.b	oxPT_darkpen(a5),d4


.nohole2	bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3


	bra.b	.nohole				; field frame inner hole

		move.b	oxPT_blackpen(a5),d4
		move.b	d4,d5

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

.nohole
		movem.w	d0-d3,-(a7)

		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.erase

		move.l	oxFd_inherited_image(a3),d4
		bne	.img_fill

		move.l	oxFd_fill_image(a3),d4
		bne.b	.img_fill

		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_bgimage(a0),d4
		beq.b	.erase

.img_fill	move.l	d4,a0
		move.l	a2,a1

		moveq	#0,d4
		moveq	#0,d5

		bsr	_oxImageFill
		bra.b	.if_gauge

.erase		move.l	gfxbase(pc),a6

		btst	#oxFdB_GAUGE,oxFd_flags(a3)
		bne.b	.erase_old

		btst	#oxFdB_FILL,oxFd_flags(a3)
		beq.b	.if_gauge

.erase_old	move.l	a2,a1

		move.b	oxFd_fillpen(a3),d0
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

.if_gauge	btst	#oxFdB_GAUGE,oxFd_flags(a3)
		beq.b	.if_penfill

		movem.w	(a7),d0/d1

		btst	#oxFdB_3DGAUGE,oxFd_flags(a3)
		bne.b	.centerperc

		addq.w	#2,d0
		addq.w	#2,d1
		subq.w	#2,d2
		subq.w	#2,d3

.centerperc	sub.w	d0,d2
		mulu.w	oxFd_percent(a3),d2
		tst.w	d2
		beq.b	.jam

		divu.w	#100,d2
		add.w	d0,d2

		btst	#oxFdB_3DGAUGE,oxFd_flags(a3)
		beq.b	.fill_gauge

		move.b	oxPT_blackpen(a5),d5
		move.b	oxPT_shinepen(a5),d4
		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

.fill_gauge	move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.1color_gauge

		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_gaugeimage(a0),d4
		beq.b	.1color_gauge
		move.l	d4,a0
		move.l	a2,a1

	;	sub.w	d0,d2
	;	sub.w	d1,d3
	;	addq.w	#1,d2
	;	addq.w	#1,d3

		move.w	d0,d4
		move.w	d1,d5	

		bsr	_oxImageFill
		bra.b	.jam

.1color_gauge	movem.w	d0/d1,-(a7)
		move.l	a2,a1
		move.b	oxPT_colorpen(a5),d0
		btst	#oxFdB_FILL,oxFd_flags(a3)
		beq.b	.set_gauge_pen
		move.b	oxFd_gaugepen(a3),d0
.set_gauge_pen	jsr	_LVOSetAPen(a6)
		movem.w	(a7)+,d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		bra.b	.jam

.if_penfill	btst	#oxFdiB_HASCOLOR,oxFd_iflags(a3)
		beq.b	.jam

		move.l	a2,a1
		moveq	#0,d0
		move.b	oxFd_custompen(a3),d0
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1

		addq.w	#2,d0
		addq.w	#2,d1
		subq.w	#2,d2
		subq.w	#2,d3

		move.l	a2,a1
		jsr	_LVORectFill(a6)

.jam		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		move.l	a2,a1
		move.b	oxPT_textpen(a5),d0
		jsr	_LVOSetAPen(a6)

		move.w	oxFd_contenttop(a3),d0
		add.w	oxFd_top(a3),d0

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.add_baseline
		addq.w	#3,d0

.add_baseline	add.w	rp_TxBaseline(a2),d0
		addq.w	#4,d0
		move.w	d0,rp_cp_y(a2)

		movem.w	(a7)+,d0-d3

		move.l	oxFd_text(a3),d4
		beq.b	.rts1
		move.l	d4,a4

		; evtl set fixed font

		btst	#oxFdiB_FIXEDFONT,oxFd_iflags(a3)
		beq.b	.inst_clip

		pushm	d0/d1

		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_fixedfont(a0),a0
		move.l	a2,a1
		jsr	_LVOSetFont(a6)

		popm	d0/d1

.inst_clip	; install clipping text notdrawn outside box

		addq.w	#4,d0
		subq.w	#4,d2
		addq.w	#3,d1		; vert-sapcing is one pix smaller
		subq.w	#3,d3

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.region
		addq.w	#3,d0		; add WIDE
		subq.w	#3,d2
		addq.w	#3,d1		; v and h spacing add for wide frame is equal 
		subq.w	#3,d3

.region		movem.w	d0-d3,oxFd_Region+rg_bounds+ra_MinX(a3)
		sub.w	d0,d2
		sub.w	d1,d3
		movem.w	d2/d3,oxFd_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	layersbase(pc),a6
		lea	oxFd_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxFd_oldregion(a3)

		move.l	gfxbase(pc),a6

		; decide if wordwrap or not (text is wrapped in UPDATE and SETLAYOUT)

		btst	#oxFdB_LAYOUT,oxFd_flags(a3)
		beq.b	.nx_txdraw_lp

		move.l	oxFd_wrappedtext(a3),d4
		beq.b	.nx_txdraw_lp

		; print layouted text

 STRUCTURE	layouthelp,0
	UWORD	yh_left
	UWORD	yh_y
	UWORD	yh_lineheight
	UWORD	yh_count
	APTR	yh_start
	APTR	yh_stylestackupper
	APTR	yh_stylestacklower
	APTR	yh_instylestack
	LABEL	yh_SIZEOF

;		//	= /
;		/i	= italic
;		/u	= underlined
;		/b	= bold
;		/h	= hilite (white)
;		/a	= alternate color (blue)
;		/x	= revert

		lea	-yh_SIZEOF(a7),a7

		move.l	d4,yh_start(a7)

		; calc height of line

		move.w	rp_TxHeight(a2),d0
		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.set_lineheight
		addq.w	#4,d0		; add wide spacing
.set_lineheight	move.w	d0,yh_lineheight(a7)

		; text line left pos, y is in rp

		move.w	oxFd_contentleft(a3),d0
		add.w	oxFd_left(a3),d0
		addq.w	#5,d0
		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.store_left
		addq.w	#3,d0	; add WIDE
.store_left	move.w	d0,yh_left(a7)			; get left x pos

		move.w	rp_cp_y(a2),yh_y(a7)		; get first y pos

		moveq	#0,d2				; start with no style change

.start_line	move.w	yh_left(a7),d0
		move.w	yh_y(a7),d1
		move.l	a2,a1
		jsr	_LVOMove(a6)

		; work on line

.on_line	tst.w	d2
		beq.b	.find_part

		cmp.b	#"i",d2
		bne.b	.bold
		moveq	#FSF_ITALIC,d0
		bra.b	.setss

.bold		cmp.b	#"b",d2
		bne.b	.underlined
		moveq	#FSF_BOLD,d0
		bra.b	.setss

.underlined	cmp.b	#"u",d2
		bne.b	.hilite
		moveq	#FSF_UNDERLINED,d0
		bra.b	.setss

.hilite		cmp.b	#"h",d2
		bne.b	.alt
		moveq	#2,d0
		bra.b	.pen

.alt		cmp.b	#"a",d2
		bne.b	.x
		moveq	#3,d0

.pen		move.l	a2,a1
		jsr	_LVOSetAPen(a6)
		bra.b	.find_part

.x		cmp.b	#"x",d2
		bne.b	.find_part
		moveq	#1,d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)
		moveq	#0,d0
		bne.b	.setss
		moveq	#-1,d1
		bra.b	.resetss

.setss		move.l	d0,d1
.resetss	move.l	a2,a1
		jsr	_LVOSetSoftStyle(a6)

.find_part	moveq	#0,d2				; reset to no style change

		moveq	#0,d0				; part length 
		move.l	yh_start(a7),a1
.find_part_loop	move.b	(a1)+,d1
		beq.b	.print_part
		cmp.b	#$a,d1
		beq.b	.print_part

		cmp.b	#"/",d1
		bne.b	.add_char
		move.b	(a1)+,d2
		beq.b	.print_part
		cmp.b	#"/",d2
		bne.b	.print_part			; style
		moveq	#0,d2
		addq.w	#1,d0
		bra.b	.print_part

.add_char	addq.w	#1,d0
		bra.b	.find_part_loop

.print_part	move.l	yh_start(a7),a0
		move.l	a1,yh_start(a7)
		move.l	a2,a1
		jsr	_LVOText(a6)

		move.l	yh_start(a7),a0
		tst.b	-1(a0)
		beq.b	.fix_stack
		cmp.b	#$a,-1(a0)
		bne.b	.on_line

		; step cursor to next line

		move.w	yh_lineheight(a7),d1
		add.w	d1,yh_y(a7)
		bra.b	.start_line

.fix_stack	moveq	#0,d0
		moveq	#-1,d1
		move.l	a2,a1
		jsr	_LVOSetSoftStyle(a6)

		lea	yh_SIZEOF(a7),a7
		bra.b	.remove_clip

.nx_txdraw_lp	; print raw text w/o checks for layout infos

		move.l	a4,a0
		moveq	#-1,d0
.txdraw_lp	addq.w	#1,d0
		move.b	(a4)+,d1
		beq.b	.tx_draw
		cmp.b	#$a,d1
		bne.b	.txdraw_lp

.tx_draw	move.w	oxFd_contentleft(a3),d1
		add.w	oxFd_left(a3),d1
		addq.w	#5,d1

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.set_x
		addq.w	#3,d1		; add WIDE

.set_x		move.w	d1,rp_cp_x(a2)

		move.l	a2,a1
		jsr	_LVOText(a6)

		move.w	rp_TxHeight(a2),d0

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.add_fonty
		addq.w	#4,d0		; add wide spacing

.add_fonty	add.w	d0,rp_cp_y(a2)

		tst.b	-1(a4)
		bne.b	.nx_txdraw_lp

.remove_clip	; remove clip in layer

		move.l	layersbase(pc),a6
		move.l	oxFd_oldregion(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion

		; evtl reset font

		btst	#oxFdiB_FIXEDFONT,oxFd_iflags(a3)
		beq.b	.rts1
		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_font(a0),a0
		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOSetFont(a6)

		moveq	#0,d0
.rts1		rts

.centercontent	; center text in button

		btst	#oxFdB_CENTER,oxFd_flags(a3)
		beq.b	.leftalign

		cmp.w	#1,oxFd_linecount(a3)
		bgt.b	.leftalign	

		movem.w	oxFd_width(a3),d2/d3

		moveq	#5,d0
		moveq	#4,d1
		sub.w	d0,d2
		sub.w	d0,d2
		sub.w	d1,d3
		sub.w	d1,d3

		movem.w	oxFd_TextWidth(a3),d4/d5


		sub.w	d4,d2
		sub.w	d5,d3

		lsr.w	#1,d2
		lsr.w	#1,d3

		moveq	#0,d3		; override vert center because it doesnt work
		bra.b	.set_lt

.leftalign	moveq	#0,d2
		moveq	#0,d3
.set_lt		movem.w	d2/d3,oxFd_contentleft(a3)
		rts

.gettextsizes	btst	#oxFdiB_FIXEDFONT,oxFd_iflags(a3)
		beq.b	.lines

		move.l	gfxbase(pc),a6
		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_fixedfont(a0),a0
		move.l	a2,a1
		jsr	_LVOSetFont(a6)

.lines		move.w	rp_TxHeight(a2),d2
		move.w	oxFd_minlines(a3),d1
		move.w	oxFd_linecount(a3),d0
		cmp.w	d1,d0
		bge.b	.mul
		move.w	d1,d0
.mul		mulu.w	d0,d2

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.set_height

		subq.w	#1,d0
		beq.b	.set_height

		mulu.w	#4,d0
		add.w	d0,d2

.set_height	move.w	d2,oxFd_TextHeight(a3)

		; text breite

		move.l	gfxbase(pc),a6
		move.l	oxFd_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		move.w	#0,d2	; start textwidth

		move.l	oxFd_text(a3),d0
		beq.b	.reset_font

		; wenn WRAP on ist, finde breitestes wort für minimale feldbreite
		; (ist nicht unbedingt nötig aber kann man machen)

		btst	#oxFdB_LAYOUT,oxFd_flags(a3)
		beq.b	.no_wrap

		move.l	d0,a4

.zeilenschleife	moveq	#0,d0		; wortlänge in buchstaben
		move.l	a4,a0		; zeilenanfang
.wortschleife	move.b	(a4)+,d1
		beq.b	.zeile_ende
		cmp.b	#" ",d1
		beq.b	.zeile_ende
		cmp.b	#$a,d1
		beq.b	.zeile_ende
		addq.w	#1,d0
		bra.b	.wortschleife

.zeile_ende	move.l	a2,a1
		jsr	_LVOTextLength(a6)
		cmp.w	d0,d2
		bge.b	.wenn_ende
		move.w	d0,d2
.wenn_ende	tst.b	-1(a4)
		bne.b	.zeilenschleife

		bra.b	.set_txwidth

.no_wrap	; finde zeile mit gößter breite fuer minimale feldbreite

		move.l	d0,a4
.nx_txw_lp	move.l	a4,a0
		moveq	#-1,d0
.txw_lp		addq.w	#1,d0
		move.b	(a4)+,d1
		beq.b	.calc_width
		cmp.b	#$a,d1
		bne.b	.txw_lp

.calc_width	move.l	a2,a1
		jsr	_LVOTextLength(a6)

		cmp.w	d0,d2
		bge.b	.nx_txw
		move.w	d0,d2

.nx_txw		tst.b	-1(a4)
		bne.b	.nx_txw_lp

.set_txwidth	move.w	d2,oxFd_TextWidth(a3)

.reset_font	btst	#oxFdiB_FIXEDFONT,oxFd_iflags(a3)
		beq.b	.rts2

		move.l	gfxbase(pc),a6
		move.l	oxFd_drawinfo(a3),a0
		move.l	oxDI_font(a0),a0
		move.l	a2,a1
		jmp	_LVOSetFont(a6)

.rts2		rts

.GETLAYOUT	move.l	oxFd_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	a0,a3

		push	a1
		bsr	.gettextsizes
		pop	a1

		; addiere content und rahmen

		movem.w	oxFd_TextWidth(a3),d0/d1
		moveq	#4,d3
		moveq	#5,d2
		add.w	d3,d1
		add.w	d3,d1
		add.w	d2,d0
		add.w	d2,d0
	;	addq.w	#1,d1	; +1 wäre oben und unten gleich viel spacing aber bei kleinen
				; buchstaben sieht dann der text zu weit oben aus
				; (betrifft übrigens auch die buttons!)


; evtl todo: borderless bei getlayout berücksichtigen falls field dann keiner sein soll

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.set_prop

		add.w	#6,d0	; add wide frame x2 to width and height
		add.w	#6,d1

.set_prop	move.l	oxFd_hprop(a3),oxLI_propw(a1)

		cmp.w	oxFd_minwidth(a3),d0
		bge.b	.set_mins
		move.w	oxFd_minwidth(a3),d0

.set_mins	movem.w	d0/d1,oxLI_minwidth(a1)
		move.w	d1,oxFd_minheight(a3)
 
		moveq	#1,d0			; method used
		rts

.SETLAYOUT	move.l	oxLI_width(a1),oxFd_width(a0)
		tst.w	oxFd_vprop(a0)
		bne.b	.setlt
		move.w	oxFd_minheight(a0),oxFd_height(a0)
.setlt		move.l	oxLI_left(a1),oxFd_left(a0)

		move.l	a0,a3
		bsr	.centercontent

		bsr	wrap_text

		moveq	#1,d0
		rts

wrap_text	; *object a3

		btst	#oxFdB_LAYOUT,oxFd_flags(a3)
		beq.b	.rts

		; first copy unbroken text to wrapped text buffer

		move.l	oxFd_wrappedtext(a3),d0
		beq.b	.rts
		move.l	d0,a0

		move.l	oxFd_text(a3),d0
		beq	.rts

		move.l	d0,a1
.cpy		move.b	(a1)+,(a0)+
		bne.b	.cpy

		; init wrap

		move.l	gfxbase(pc),a6
		move.l	oxFd_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		; calc and store width of space

		lea	.space(pc),a0
		moveq	#1,d0
		move.l	a2,a1
		jsr	_LVOTextLength(a6)
		move.w	d0,d7				; width of 1 space char

		; get and store field width minus border and spacing

		move.w	oxFd_width(a3),d6
		sub.w	#10,d6

		; evtl todo: borderless

		; wide

		btst	#oxFdB_WIDE,oxFd_flags(a3)
		beq.b	.start

		subq	#6,d6				; sub wide frame x2 from width

.start		move.l	oxFd_wrappedtext(a3),a5

		tst.b	(a5)
		beq.b	.rts

		push	a3
		lea	-256(a7),a7
		move.l	a7,a3

.while_words	bsr	.get_word	; first of a line

		; SpaceLeft := LineWidth - Width(word)

		move.w	d6,d5
		sub.w	d0,d5

.while_misc	; while( ( word:=next() ) AND char<>$a AND Width(word)+SpaceWidth<SpaceLeft)

		tst.b	-1(a5)
		beq.b	.pop

		move.l	a5,a4
		bsr	.get_word

		cmp.b	#$a,-1(a4)
		beq.b	.while_words

		add.w	d7,d0
		sub.w	d0,d5
		bgt.b	.while_misc

		move.b	#$a,-1(a4)
		move.l	a4,a5
		bra.b	.while_words

.pop		lea	256(a7),a7
		pop	a3
.rts		rts

.get_word	; a5 *word, >a5 *after word+space

		move.l	a3,a0		; word buffer
		moveq	#0,d0		; word lenght in chars
		move.w	#255,d2		; length of word buffer

.gw_loop	move.b	(a5)+,d1
		beq.b	.textlength
		cmp.b	#$a,d1
		beq.b	.textlength
		cmp.b	#" ",d1
		beq.b	.textlength

		; skip styles and colors

		cmp.b	#"/",d1
		bne.b	.add
		move.b	(a5)+,d1
		beq.b	.textlength
		cmp.b	#"/",d1
		bne.b	.gw_loop

.add		; use this char

		addq	#1,d0
		move.b	d1,(a0)+
		dbf	d2,.gw_loop	; stop at end of word buffer

.textlength	move.l	a3,a0
		move.l	a2,a1
		jmp	_LVOTextLength(a6)

.space		dc.b	" "
		even

;--------------------------------------------------------------------
; OX_FRAME

 STRUCTURE	oxFrame,oxO_SIZEOF
	UWORD	oxFr_left
	UWORD	oxFr_top
	UWORD	oxFr_width
	UWORD	oxFr_height
	UWORD	oxFr_hprop
	UWORD	oxFr_vprop

	UWORD	oxFr_minx		; if not zero: in getlayout tell these as size
	UWORD	oxFr_miny		; instead of the real content size,
					; then do clipping on the content wobei zb im falle von
					; center der inhalt auch nach links/oben aus dem rahmen gehen kann

	APTR	oxFr_oldregion
	STRUCT	oxFr_Region,rg_SIZEOF
	STRUCT	oxFr_RegionRectangle,rr_SIZEOF

	APTR	oxFr_drawinfo

	UWORD	oxFr_spacing		; innerhalb des rahmens zum inhalt hin
	UWORD	oxFr_contentleft
	UWORD	oxFr_contenttop
	UWORD	oxFr_contentwidth	; read from obj
	UWORD	oxFr_contentheight	; read from obj
	UWORD	oxFr_contentpropw
	UWORD	oxFr_contentproph

	UBYTE	oxFr_framestyle	; 0 none, 1 strong, 2 shadow, 3 gng, 4 bevel
	UBYTE	oxFr_fillstyle		; 0 none, 1 pattern1, 2 pattern2, 3 pen
	UBYTE	oxFr_hzalign		; horiz:  1 left, 0 middle, 2 right
	UBYTE	oxFr_vtalign		; vert:	  1 top,  0 middle, 2 bottom
	UBYTE	oxFr_flags

	UBYTE	oxFr_fillpen		; if fillstyle is pen
	UBYTE	oxFr_bpen

	UBYTE	oxFr_pattsize
	APTR	oxFr_pattern		; format see window

	APTR	oxFr_fill_imagename
	APTR	oxFr_fill_image

	APTR	oxFr_icdhook

	APTR	oxFr_window
	ULONG	oxFr_OXBMODE

	LABEL	oxFr_SIZEOF

	BITDEF	oxFr,ACTIVE,0
	BITDEF	oxFr,BOTTOMZERO,1
	BITDEF	oxFr,INHERIT,2

	OXICLASSHEADER	frame, 1, 0, tabs

	dc.l	oxCA_objectsize,oxFr_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,.fr_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Frame for centering, clipping or aligning of any "
		dc.b	"content. Drop a pic into the right frame to dispaly it there clipped to the frame size. "
		dc.b	"But you will see more of the pic when you resize the window.",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq.b	.FrINTUI

		cmp.w	#OXM_SET,d1
		beq	.SET

		cmp.w	#OXM_DRAW,d1
		beq	.DRAW

		cmp.w	#OXM_REFRESH,d1
		beq.b	.REFRESH

		cmp.w	#OXM_SETDEF,d1
		beq.b	.SETDEF

		cmp.w	#OXM_UPDATE,d1
		beq	.UPDATE	

		cmp.w	#OXM_GETLAYOUT,d1
		beq	.GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	.SETLAYOUT

		cmp.w	#OXM_WINDOWCLOSING,d1
		beq.b	.deinit

		cmp.w	#OXM_WINDOWOPEN,d1
		beq.b	.winopen

		cmp.w	#OXM_DEINIT,d1
		beq.b	.deinit

		cmp.w	#OXM_APPWINMESSAGE,d1
		bne.b	.INHERIT

		tst.l	oxFr_icdhook(a0)
		beq.b	.rts0

		movem.w	oxFr_left(a0),d0-d3
		move.l	am_UserData(a1),a2
		moveq	#0,d4
		moveq	#0,d5
		move.b	wd_BorderLeft(a2),d4
		move.b	wd_BorderTop(a2),d5
		neg.w	d4
		neg.w	d5
		add.w	am_MouseX(a1),d4
		add.w	am_MouseY(a1),d5
		cmp.w	d4,d0
		bgt.b	.rts0
		add.w	d2,d0
		subq.w	#1,d0
		cmp.w	d4,d0
		blt.b	.rts0
		cmp.w	d5,d1
		bgt.b	.rts0
		add.w	d3,d1
		subq.w	#1,d1
		cmp.w	d5,d1
		blt.b	.rts0

		; call icon drop hook

		move.l	am_NumArgs(a1),d1
		move.l	am_ArgList(a1),a1

		; a0 must be *self fro call!!

		move.l	oxFr_icdhook(a0),a2
		jsr	(a2)

.rts1		moveq	#1,d0
		rts

.rts0		moveq	#0,d0
.rts		rts

.FrINTUI	cmp.l	#IDCMP_MOUSEMOVE,im_Class(a1)
		bne.b	.rts0

		tst.l	oxFr_icdhook(a0)
		beq.b	.rts0

		movem.w	oxFr_left(a0),d0-d3
		bsr	_is_in_rect
		beq	.if_clearptr

		bset	#oxFrB_ACTIVE,oxFr_flags(a0)
		bne.b	.rts1

		; set pointer / activate window to see it

		move.l	intbase(pc),a6

		move.l	im_IDCMPWindow(a1),a0
		push	a0
	;	push	a1

	;	jsr	_LVOActivateWindow(a6)

	;	pop	a1
	;	move.l	(a7),a0
		lea	drop_pointer,a1
		movem.w	(a1)+,d0-d3

		jsr	_LVOSetPointer(a6)

		pop	a0

		; ich bin dran


		moveq	#1,d0
		rts

.if_clearptr	bclr	#oxFrB_ACTIVE,oxFr_flags(a0)
		beq.b	.rts0

		move.l	im_IDCMPWindow(a1),a0

		move.l	intbase(pc),a6
		jsr	_LVOClearPointer(a6)
		bra.b	.rts0

.deinit		tst.l	oxFr_fill_imagename(a0)
		beq	.rts

		move.l	oxFr_fill_image(a0),d0
		beq.b	.rts
		clr.l	oxFr_fill_image(a0)
		move.l	d0,a0
		bra	_oxDropImage

.winopen	move.l	a1,oxFr_window(a0)

		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.rts

		move.l	oxFr_fill_imagename(a3),d0
		move.l	a1,a2	; window
		bsr	_oxGetImage
		move.l	d0,oxFr_fill_image(a3)
		beq	.rts12
		bclr	#oxFrB_INHERIT,oxFr_flags(a3)
.rts12		rts



 STRUCTURE	oxFrameExampleInfo,0
		APTR	oxFEI_imageframe
		APTR	oxFEI_image
		LABEL	oxFEI_SIZEOF

.fr_create_ex	lea	.example(pc),a2
		moveq	#0,d2
		bra	_oxCreateObject

.example	dc.l	OX_BUFFER,.buffer

.buffer		dc.l	oxBfA_buffersize,oxFEI_SIZEOF
		dc.l	OX_HORIZGROUP,.frames_group
		dc.l	TAG_END

.frames_group	dc.l	OX_FRAME,.example_frame1
		dc.l	OX_FRAME,.example_frame2
		dc.l	OX_FRAME,.example_frame3
		dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	oxGA_equal,1
		dc.l	TAG_END

.example_frame1	dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_STRONG
		dc.l	oxFrA_fillstyle,oxFr_PATT1
		dc.l	oxFrA_hzalign,oxFr_LEFT
		dc.l	OX_BUTTON,.ex_button
		dc.l	TAG_END

.example_frame2	dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_SHADOW
		dc.l	oxFrA_fillstyle,oxFr_NONE
		dc.l	oxFrA_vtalign,oxFr_BOTTOM
		dc.l	OX_BUTTON,.ex_button
		dc.l	TAG_END

.example_frame3	dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_BEVEL
		dc.l	oxFrA_fillpen,oxPT_backpen
		dc.l	oxFrA_hzalign,oxFr_MIDDLE
		dc.l	oxFrA_vtalign,oxFr_MIDDLE
		dc.l	oxFrA_minx,50
		dc.l	oxFrA_miny,50
		dc.l	OX_IMAGE,.ex_i
		dc.l	OX_RELPTR,oxFEI_imageframe
		dc.l	oxFrA_icdhook,.getfile
		dc.l	TAG_END

.ex_button	dc.l	oxBA_text,.ex_text
		dc.l	TAG_END
.ex_text	dc.b	"ok",0
		even
.ex_i	;	dc.l	oxImA_filename,.file
		dc.l	OX_RELPTR,oxFEI_image
		dc.l	TAG_END
;.file		dc.b	"bigimage.jpg",0
		even

.getfile	; the dir+filename is stored in the image node (if a new one is allocated)

		move.l	a0,a3

		; build filename on stack

		move.l	a1,a2

		move.l	(a2)+,d1
		lea	-256(a7),a7
		clr.b	(a7)		; pre-terminate if name error
		move.l	a7,d2
		moveq	#127,d3
		move.l	dosbase(pc),a6
		jsr	-402(a6)	; _LVONameFromLock(a6)
		tst.l	d0
		beq.b	.ok

		move.l	a7,a1
.to_after_dir	tst.b	(a1)+
		bne.b	.to_after_dir
		subq.l	#1,a1
		move.b	#"/",(a1)+
		subq	#1,d3
		move.l	(a2),a0
.cp_name_lp	move.b	(a0)+,(a1)+
		beq.b	.ok
		dbf	d3,.cp_name_lp
.ok
		; set new filename to image (triggers image to free current image)

		move.l	oxFEI_image(a4),a0
		move.l	a7,d1
		move.l	#oxImA_filename,d0
		bsr	_oxSetAttr

		; send update to frame above image (invokes redraw self,
		; send new drawinfos to image and draw it)

		move.l	oxFEI_imageframe(a4),a0
		move.l	#OXM_UPDATE,d1
		bsr	_oxDoMethod

		; free the filename on stack

		lea	256(a7),a7

		rts

.SET		movem.l	(a1),d0/d1

		cmp.l	#oxFrA_bottomzero,d0
		bne.b	.if_icd
		moveq	#oxFrF_BOTTOMZERO,d0
.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxFr_flags(a0)
		rts
.clearflag	not.b	d0
		and.b	d0,oxFr_flags(a0)
		rts

.if_icd		cmp.l	#oxFrA_icdhook,d0
		bne.b	.if_di
		move.l	d1,oxFr_icdhook(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.if_hprop
		move.l	d1,oxFr_drawinfo(a0)
		rts
.if_hprop	cmp.l	#oxFrA_hprop,d0
		bne.b	.if_vprop
		move.w	d1,oxFr_hprop(a0)
		rts
.if_vprop	cmp.l	#oxFrA_vprop,d0
		bne.b	.if_minx
		move.w	d1,oxFr_vprop(a0)
		rts
.if_minx	cmp.l	#oxFrA_minx,d0
		bne.b	.if_miny
		move.w	d1,oxFr_minx(a0)
		rts
.if_miny	cmp.l	#oxFrA_miny,d0
		bne.b	.if_spacing
		move.w	d1,oxFr_miny(a0)
		rts
.if_spacing	cmp.l	#oxFrA_spacing,d0
		bne.b	.if_fill
		move.w	d1,oxFr_spacing(a0)
		rts
.if_fill	cmp.l	#oxFrA_fillstyle,d0
		bne.b	.if_fillpen
		move.b	d1,oxFr_fillstyle(a0)
		rts
.if_fillpen	cmp.l	#oxFrA_fillpen,d0
		bne.b	.if_frame
		move.b	d1,oxFr_fillpen(a0)
		move.b	#oxFr_PEN,oxFr_fillstyle(a0)
		rts
.if_frame	cmp.l	#oxFrA_framestyle,d0
		bne.b	.if_patt
		move.b	d1,oxFr_framestyle(a0)
		rts
.if_patt	cmp.l	#oxFrA_pattern,d0
		bne	.if_hza
		move.l	d1,oxFr_pattern(a0)
		rts
.if_hza		cmp.l	#oxFrA_hzalign,d0
		bne.b	.if_vta
		move.b	d1,oxFr_hzalign(a0)
		rts
.if_vta		cmp.l	#oxFrA_vtalign,d0
		bne.b	.if_imname
		move.b	d1,oxFr_vtalign(a0)
		rts
.if_imname	cmp.l	#oxFrA_imagename,d0
		bne.b	.rts
		move.l	d1,oxFr_fill_imagename(a0)
		rts

.SETDEF	;	move.w	#5,oxFr_spacing(a0)
		move.b	#oxFr_IMAGE,oxFr_fillstyle(a0)

		lea	oxFr_RegionRectangle(a0),a1
		move.l	a1,oxFr_Region+rg_RegionRectangle(a0)

		or.b	#oxFrF_INHERIT,oxFr_flags(a0)

		rts

.NEWPENS	cmp.w	#OXM_NEWPENS,d1
		bne	.rts18

		move.b	oxPT_backpen(a1),oxFr_fillpen(a3)
		rts

.INHERIT	cmp.w	#OXM_INHERIT,d1
		bne	.NEWPENS

		btst	#oxFrB_INHERIT,oxFr_flags(a3)
		beq	.rts18

		cmp.b	#oxFILLSTYLE_IMAGE,oxI_fillstyle(a1)
		bne.b	.ih_pen

		move.l	oxI_data(a1),oxFr_fill_image(a3)
		move.b	#oxFr_IMAGE,oxFr_fillstyle(a3)

		bra	.rts18

.ih_pen		;cmp.b	#oxFILLSTYLE_PEN,oxI_fillstyle(a1)
		;bne.b	.pattern

		move.b	oxI_frontpen(a1),oxFr_fillpen(a3)
		move.b	#oxFr_PEN,oxFr_fillstyle(a3)

.rts18		; returns 0 in d0 (not changed)

		rts

.UPDATE		move.l	oxFr_drawinfo(a3),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

		move.l	oxO_list(a3),a0
		tst.l	(a0)
		beq.b	.sizes
		moveq	#OXM_UPDATE,d0
		bsr	_oxDoMethod

.sizes		bsr	.getcontentsizes
		bsr	.aligncontent
		bsr	.setcontentsizes

		bsr	.draw_subrou

		moveq	#0,d0
		rts

.REFRESH	move.l	a0,a1
		movem.w	oxFr_left(a0),d0-d3
		move.l	oxFr_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		bra	_oxRefresh

.DRAW		move.l	a0,a3
		move.l	d2,oxFr_OXBMODE(a3)

		move.l	oxFr_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

.draw_subrou	move.l	gfxbase(pc),a6

		move.b	oxFr_framestyle(a3),d7
		beq.b	.fill

		movem.w	oxFr_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		cmp.b	#oxFr_SHADOW,d7
		bne.b	.if_strong

		addq.w	#1,d0
		addq.w	#1,d1

		moveq	#1,d4
		moveq	#1,d5

		bsr	_draw_bevel_border

		subq.w	#1,d0
		subq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		moveq	#2,d4
		moveq	#2,d5

		bsr	_draw_bevel_border

		bra.b	.fill

.if_strong	cmp.b	#oxFr_STRONG,d7
		bne.b	.if_gng

		moveq	#2,d4
		moveq	#1,d5

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		moveq	#2,d4
		moveq	#1,d5

		bsr	_draw_bevel_border

		bra	.fill

.if_gng		cmp.b	#oxFr_GNG,d7
		bne	.bevel

		moveq	#3,d4
		moveq	#1,d5

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		moveq	#1,d4
		moveq	#3,d5

		bsr	_draw_bevel_border

		bra.b	.fill

.bevel		cmp.b	#oxFr_BEVEL,d7
		bne	.fill
	
		moveq	#1,d4
		moveq	#2,d5

		bsr	_draw_bevel_border

.fill		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.if_stylefill

	;	tst.l	oxFr_fill_imagename(a3)
	;	beq.b	.if_stylefill

		move.l	oxFr_fill_image(a3),d0
		bne.b	.pre_image_fill

		move.l	oxFr_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_bgimage(a0),d0
		beq.b	.if_stylefill

.pre_image_fill	move.l	d0,a0

		movem.w	oxFr_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq	#1,d2
		subq	#1,d3

		tst.b	oxFr_framestyle(a3)
		beq.b	.image_fill

		moveq	#2,d4	

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.double_frame

		subq	#1,d4

.double_frame	add.w	d4,d0
		sub.w	d4,d2
		add.w	d4,d1
		sub.w	d4,d3

.image_fill	cmp.b	#oxFr_IMAGE,oxFr_fillstyle(a3)
		bne.b	.if_stylefill		

		move.l	oxFr_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		moveq	#0,d4
		moveq	#0,d5

		bsr	_oxImageFill

		bra.b	.draw_member

.if_stylefill	move.b	oxFr_fillstyle(a3),d7
		beq	.draw_member

	;	moveq	#0,d0
		move.b	oxFr_fillpen(a3),d0
	;	move.b	(a5,d0.w),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		cmp.b	#oxFr_PEN,d7
		beq.b	.fill_rect

		lea	winpattern1(pc),a4

		cmp.b	#oxFr_PATT1,d7
		beq.b	.patt

		cmp.b	#oxFr_PATT2,d7
		beq.b	.patt2

		cmp.b	#oxFr_CUSTOM,d7
		bne	.fill_rect		; war .draw_member

		move.l	oxFr_pattern(a3),a4

		bra.b	.patt

.patt2		lea	winpattern2(pc),a4

.patt		move.w	(a4)+,d0
		move.b	d0,rp_AreaPtSz(a2)
		move.b	(a4)+,d0
		move.b	(a5,d0.w),d0
		moveq	#0,d1
		move.b	(a4)+,d1
		move.b	(a5,d1.w),d1
		move.l	a4,rp_AreaPtrn(a2)
		moveq 	#RP_JAM2,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

.fill_rect	movem.w	oxFr_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		tst.b	oxFr_framestyle(a3)
		beq.b	.fill_inner

		moveq	#2,d4	

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.doppel_frame

		subq	#1,d4

.doppel_frame	add.w	d4,d0
		sub.w	d4,d2
		add.w	d4,d1
		sub.w	d4,d3

.fill_inner	movem.w	d0-d3,-(a7)

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		movem.w	(a7)+,d0-d3

.draw_member	movem.w	oxFr_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		move.w	oxFr_spacing(a3),d4

		tst.b	oxFr_framestyle(a3)
		beq.b	.add_frmspc

		addq	#2,d4	

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.add_frmspc

		subq	#1,d4

.add_frmspc	add.w	d4,d0
		sub.w	d4,d2
		add.w	d4,d1
		sub.w	d4,d3

		movem.w	d0-d3,oxFr_Region+rg_bounds+ra_MinX(a3)
		sub.w	d0,d2
		sub.w	d1,d3
		movem.w	d2/d3,oxFr_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	layersbase(pc),a6
		lea	oxFr_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxFr_oldregion(a3)

		moveq	#OXM_DRAW,d1
		move.l	a3,a0
		move.l	oxFr_OXBMODE(a3),d2
		bclr	#OXBMODE_SELF_BIT,d2
		bsr	_oxBroadcast

		move.l	rp_Layer(a2),a0
		move.l	oxFr_oldregion(a3),a1
		move.l	layersbase(pc),a6
		jsr	-174(a6)

		moveq	#1,d0	; stop message here
		rts

.aligncontent	; center content in this frame

		moveq	#0,d3

		tst.b	oxFr_framestyle(a3)
		beq.b	.add_space_cent

		moveq	#2,d3

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.add_space_cent
		subq.w	#1,d3

.add_space_cent	add.w	oxFr_spacing(a3),d3
		add.w	d3,d3

		tst.w	oxFr_contentpropw(a3)
		bne.b	.clr_left

		move.w	oxFr_width(a3),d2
		sub.w	d3,d2
		sub.w	oxFr_contentwidth(a3),d2

		tst.b	oxFr_hzalign(a3)
		beq.b	.middle_hz
		bmi.b	.clr_left		; left
		bra.b	.set_left		; right

.middle_hz	asr.w	#1,d2
		bra.b	.set_left

.clr_left	moveq	#0,d2
.set_left	move.w	d2,oxFr_contentleft(a3)

		tst.w	oxFr_contentproph(a3)
		bne.b	.clr_top

		move.w	oxFr_height(a3),d2
		sub.w	d3,d2
		sub.w	oxFr_contentheight(a3),d2

		tst.b	oxFr_vtalign(a3)
		beq.b	.middle_vt
		bmi.b	.clr_top		; top
		bra.b	.set_top		; bottom

.middle_vt	asr.w	#1,d2
		bra.b	.set_top

.clr_top	moveq	#0,d2
.set_top	move.w	d2,oxFr_contenttop(a3)

		rts


.getcontentsizes
		; member abfragen (es kann nur einen geben)

		move.l	oxO_list(a3),a0
		tst.l	(a0)
		beq.b	.return_used

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		clr.l	oxLI_propw(a1)
		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_maxwidth(a1)

		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		move.l	oxLI_minwidth(a1),oxFr_contentwidth(a3)
		move.l	oxLI_propw(a1),oxFr_contentpropw(a3)
		lea	oxLI_SIZEOF(a7),a7

		rts

.GETLAYOUT	move.l	a0,a3

		push	a1
		bsr	.getcontentsizes
		pop	a1

		; addiere content und rahmen

		movem.w	oxFr_contentwidth(a3),d0/d1

		move.w	oxFr_minx(a3),d2
		beq.b	.xok
		move.w	d2,d0
.xok
		move.w	oxFr_miny(a3),d2
		beq.b	.yok
		move.w	d2,d1
.yok
		move.w	oxFr_spacing(a3),d3

		tst.b	oxFr_framestyle(a3)
		beq.b	.add_space

		add.w	#2,d3		; frame

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.add_space
		subq.w	#1,d3

.add_space	add.w	d3,d3
		add.w	d3,d1		; height
		add.w	d3,d0		; width

		move.l	oxFr_hprop(a3),oxLI_propw(a1)
		movem.w	d0/d1,oxLI_minwidth(a1)
 
		moveq	#1,d0			; method used
		rts

.setcontentsizes	; member platzieren (es kann nur einen geben)

		lea	oxO_list(a3),a0
		move.l	(a0),a0
		tst.l	(a0)
		beq.b	.rts3

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		moveq	#0,d2

		tst.b	oxFr_framestyle(a3)
		beq.b	.add_space_set

		moveq.w	#2,d2		; frame

		cmp.b	#oxFr_BEVEL,oxFr_framestyle(a3)
		bne.b	.add_space_set
		subq.w	#1,d2

.add_space_set	move.w	oxFr_spacing(a3),d3
		add.w	d2,d3
		swap	d3
		move.w	oxFr_spacing(a3),d3
		add.w	d2,d3

		move.l	oxFr_contentleft(a3),oxLI_left(a1)
		move.l	oxFr_left(a3),d0
		add.l	d0,oxLI_left(a1)
		add.l	d3,oxLI_left(a1)

		add.w	d3,d3

		move.w	oxFr_contentwidth(a3),oxLI_width(a1)
		tst.w	oxFr_contentpropw(a3)
		beq.b	.check_y
		move.w 	oxFr_width(a3),oxLI_width(a1)
		sub.w	d3,oxLI_width(a1)

.check_y	move.w	oxFr_contentheight(a3),oxLI_height(a1)
		tst.w	oxFr_contentproph(a3)
		beq.b	.setl
		move.w 	oxFr_height(a3),oxLI_height(a1)
		sub.w	d3,oxLI_height(a1)

.setl		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		lea	oxLI_SIZEOF(a7),a7

.rts3		rts


.SETLAYOUT	move.l	oxLI_width(a1),oxFr_width(a0)
		move.l	oxLI_left(a1),oxFr_left(a0)

		move.l	a0,a3
		bsr	.aligncontent

		bsr	.setcontentsizes


.return_used	moveq	#1,d0
		rts

;--------------------------------------------------------------------
; OX_TABS	(simple)

 STRUCTURE	oxTabs,oxO_SIZEOF
	UWORD	oxTb_left
	UWORD	oxTb_top
	UWORD	oxTb_width
	UWORD	oxTb_height
	UWORD	oxTb_griffheight
	APTR	oxTb_current		; * current tab (object)
	STRUCT	oxTb_list,MLH_SIZE	; list of all tabs (tabnodes w/ ptr to object)

	APTR	oxTb_drawinfo
	APTR	oxTb_fill_imagename
	APTR	oxTb_fill_image
	UBYTE	oxTb_flags
	UBYTE	oxTb_pad

	LABEL	oxTb_border
	STRUCT	oxTb_border_black,bd_SIZEOF
	STRUCT	oxTb_border_black_coords,4*8
	STRUCT	oxTb_border_white,bd_SIZEOF
	STRUCT	oxTb_border_white_coords,4*3
	STRUCT	oxTb_border_color,bd_SIZEOF
	STRUCT	oxTb_border_color_coords,4*3

	APTR	oxTb_offbitmap		; for saving griff-area bg
	APTR	oxTb_offrastport

	ULONG	oxTb_coloralloc
	LABEL	oxTb_pentable
	UBYTE	oxTb_backpen
	UBYTE	oxTb_textpen

	LABEL	oxTb_SIZEOF

	BITDEF	oxTb,REDRAW,0		; redraw when tab changed
   ;	BITDEF	oxTb,IMAGEFILL,1	; has fill with datatypes image pattern


 STRUCTURE	oxTabNode,MLN_SIZE
	APTR	oxTN_object		; * this tabs object (object)
	APTR	oxTN_title
	UWORD	oxTN_titlelenght
	UWORD	oxTN_width
	UBYTE	oxTN_flags
	UBYTE	oxTN_pad

	LABEL	oxTN_backborder
	STRUCT	oxTN_backborder_black,bd_SIZEOF
	STRUCT	oxTN_backborder_black_coords,4*6
	STRUCT	oxTN_backborder_white,bd_SIZEOF
	STRUCT	oxTN_backborder_white_coords,4*4
	STRUCT	oxTN_backborder_color,bd_SIZEOF
	STRUCT	oxTN_backborder_color_coords,4*3

	LABEL	oxTN_border
	STRUCT	oxTN_border_black,bd_SIZEOF
	STRUCT	oxTN_border_black_coords,4*6
	STRUCT	oxTN_border_white,bd_SIZEOF
	STRUCT	oxTN_border_white_coords,4*4
;	STRUCT	oxTN_border_white2,bd_SIZEOF		; right white line
;	STRUCT	oxTN_border_white2_coords,4*2
	STRUCT	oxTN_border_color,bd_SIZEOF
	STRUCT	oxTN_border_color_coords,4*3

	LABEL	oxTN_SIZEOF

	BITDEF	oxTN,ISINFRONT,0	; dont check on-tab-mouseclick -> no to front -> no redraw

 STRUCTURE	tabbase,0
	LABEL	tbb_colortable
	ULONG	tbb_backcolor
	ULONG	tbb_textcolor
	LABEL	tbb_SIZEOF

	OXICLASSHEADER	tabs, 1, 0, pages

	dc.l	oxCA_objectsize,oxTb_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,tb_create_ex
	dc.l	oxCA_basesize,tbb_SIZEOF
	dc.l	oxCA_envarray,.env
	dc.l	TAG_END

.env		dc.l	.backcolor,$AAAAAA,0			; name, default
		dc.b	oxET_COLOR,0				; type, flagbit
		dc.w	tbb_backcolor				; offset, base
		dc.l	0					; description

		dc.l	.textcolor,$000000,0			; name, default
		dc.b	oxET_COLOR,0				; type, flagbit
		dc.w	tbb_textcolor				; offset
		dc.l	0					; description

		dc.l	0	; terminate array

.desc		dc.b	"$VER: Tabs 1.0",0
.backcolor	dc.b	"back color",0
.textcolor	dc.b	"title text",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq	TbINTUI

		cmp.w	#OXM_DRAW,d1
		beq	TbDRAW

		cmp.w	#OXM_SET,d1
		beq	TbSET

		cmp.w	#OXM_SETDEF,d1
		beq	TbSETDEF

		cmp.w	#OXM_INIT,d1
		beq	TbINIT

		cmp.w	#OXM_DEINIT,d1
		beq	TbDEINIT

		cmp.w	#OXM_GETLAYOUT,d1
		beq	TbGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	TbSETLAYOUT

		cmp.w	#OXM_WINDOWCLOSING,d1
		beq	.winclose

		cmp.w	#OXM_WINDOWOPEN,d1 
		beq	TbWINOPEN

		cmp.w	#OXM_DROPGFXBUFFERS,d1
		beq	Tb_drop_bmp

		cmp.w	#OXM_FRONT,d1
		beq	.depht

		cmp.w	#OXM_NEWPENS,d1
		beq	.pens

		cmp.w	#OXM_INHERIT,d1
		beq	.inherit

.return		rts

.inherit	lea	-oxI_SIZEOF(a7),a7

		; set parameters for OXM_INHERIT

;	UBYTE	oxI_fillstyle	; pen, pattern, image
;	UBYTE	oxI_pattsize	; size for area pattern
;	UBYTE	oxI_frontpen
;	UBYTE	oxI_backpen
;	APTR	oxI_data	; pointer to pattern or pointer to image

		; try image first

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_imagetable(a1),a0
		move.l	oxIT_bgimage(a0),oxI_data(a7)
		beq	.pen_patt

		move.b	#oxFILLSTYLE_IMAGE,oxI_fillstyle(a7)
		bra	.s_i

.pen_patt	move.b	#oxFILLSTYLE_PEN,oxI_fillstyle(a7)
		move.b	oxTb_backpen(a3),oxI_frontpen(a7)

.s_i		move.l	a7,a1

		lea	oxTb_list(a3),a2
.inh_bc_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.restack

		move.l	oxTN_object(a2),a0

	;	moveq	#OXM_INHERIT,d1
		moveq	#OXBMODE_STOPLEVEL+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.inh_bc_lp

.restack	lea	oxI_SIZEOF(a7),a7

		moveq	#TRUE,d0			; stop parent message here
		rts


.winclose	bsr	.wincls

.free_pens	; set parameters for free_pens

		; d0 numpens, base 0
		; d1 allocmask, each bit 0 to numpens indicates wether
		;    the corresponding color was allocated (TRUE = yes)
		; a0 ox window object
		; a2 pentable

		move.l	oxTb_coloralloc(a3),d1
		moveq	#1,d0

		move.l	oxTb_drawinfo(a3),a2
		move.l	oxDI_windowobject(a2),a0

		lea	oxTb_pentable(a3),a2

		; if no pens allocated this following call does nothing,
		; so it is safe to call it even if alloc_pens was not called before
		; the magic lies in the "coloralloc" ULONG, where each bit tells
		; us wether the corresponding pen (pen 0 = bit 0) has been allocated

		bra	free_pens

.newpens	; free currently allocated pens, if any

		bsr	.free_pens

		; set parameters for alloc_pens

		; a0 *oxwin
		; a1 *colortable
		; a2 *pentable	(destination whereto the pens are written)
		; a3 static pens for 4 color mode
		; d0 num pens, base 0

		push	a3

		move.l	oxTb_drawinfo(a3),a2
		move.l	oxDI_windowobject(a2),a0

		lea	tbb_colortable(a5),a1
		lea	oxTb_pentable(a3),a2
		lea	.static(pc),a3
		moveq	#1,d0

		bsr	alloc_pens

		pop	a3

		move.l	d0,oxTb_coloralloc(a3)

		rts

.static		dc.b	oxBACKPEN,oxBLACKPEN
		even

.depht		move.l	oxTb_current(a0),d3
		lea	oxTb_list(a0),a2
.lp		move.l	(a2),a2
		tst.l	(a2)
		beq.b	.rts

		moveq	#OXM_BACK,d1

		move.l	oxTN_object(a2),a0	; current gets FRONT from above
		cmp.l	a0,d3

	beq.b	.lp

	;	bne.b	.send_depth

	;	moveq	#OXM_FRONT,d1

.send_depth	moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.lp

.rts		rts

.wincls		pushm	d0/d1/a0/a1

		move.l	oxTb_fill_image(a3),d0
		beq.b	.dbmp
		clr.l	oxTb_fill_image(a3)
		move.l	d0,a0
		bsr	_oxDropImage

.dbmp		movem.l	(a7),d0/d1/a0/a1
		bsr.b	Tb_drop_bmp
		popm	d0/d1/a0/a1
		bra.b	TbBcToAll

.pens		pushm	d0/d1/a1

		bsr	TbSETBrColors

		; set colors for all tabs

		lea	oxTb_list(a3),a2
.pens_loop	move.l	(a2),a2
		tst.l	(a2)
		beq	.np
		bsr	TbInitTabColors
		bra.b	.pens_loop

.np		bsr	.newpens

		popm	d0/d1/a1
		bra	TbBcToAll

TbWINOPEN	pushm	d0/d1/a0/a1

		moveq	#0,d0

		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.clr

		move.l	oxTb_fill_imagename(a0),d0
		move.l	a1,a2	; window
		bsr	_oxGetImage
		beq.b	.pop

.clr		move.l	d0,oxTb_fill_image(a0)

.pop		popm	d0/d1/a0/a1
		bra.b	TbBcToAll

TbSETDEF	lea	oxTb_border_black_coords(a0),a2
		move.l	a2,oxTb_border_black+bd_XY(a0)
		lea	oxTb_border_white(a0),a2
		move.l	a2,oxTb_border_black+bd_NextBorder(a0)
		move.b	#8,oxTb_border_black+bd_Count(a0)

		lea	oxTb_border_white_coords(a0),a2
		move.l	a2,oxTb_border_white+bd_XY(a0)
		lea	oxTb_border_color(a0),a2
		move.l	a2,oxTb_border_white+bd_NextBorder(a0)
		move.b	#3,oxTb_border_white+bd_Count(a0)

		lea	oxTb_border_color_coords(a0),a2
		move.l	a2,oxTb_border_color+bd_XY(a0)
		move.b	#3,oxTb_border_color+bd_Count(a0)

		lea	oxTb_list(a0),a0
		NEWLIST	a0
		rts

TbSETBrColors	; initialised separately for global prefs change

		move.b	oxPT_blackpen(a1),d1
		move.b	oxPT_shinepen(a1),d2
		move.b	oxPT_darkpen(a1),d3

		move.b	d1,oxTb_border_black+bd_FrontPen(a3)
		move.b	d2,oxTb_border_white+bd_FrontPen(a3)
		move.b	d3,oxTb_border_color+bd_FrontPen(a3)
		rts

TbInitTabNode	; tabnode a1

		push	a2

		; when tab is in back

		lea	oxTN_backborder_black_coords(a1),a2
		move.l	a2,oxTN_backborder_black+bd_XY(a1)
		lea	oxTN_backborder_white(a1),a2
		move.l	a2,oxTN_backborder_black+bd_NextBorder(a1)
		move.b	#6,oxTN_backborder_black+bd_Count(a1)

		lea	oxTN_backborder_white_coords(a1),a2
		move.l	a2,oxTN_backborder_white+bd_XY(a1)
		lea	oxTN_backborder_color(a1),a2
		move.l	a2,oxTN_backborder_white+bd_NextBorder(a1)
		move.b	#4,oxTN_backborder_white+bd_Count(a1)

		lea	oxTN_backborder_color_coords(a1),a2
		move.l	a2,oxTN_backborder_color+bd_XY(a1)
		move.b	#3,oxTN_backborder_color+bd_Count(a1)

		; when tab is in front

		lea	oxTN_border_black_coords(a1),a2
		move.l	a2,oxTN_border_black+bd_XY(a1)
		lea	oxTN_border_white(a1),a2
		move.l	a2,oxTN_border_black+bd_NextBorder(a1)
		move.b	#6,oxTN_border_black+bd_Count(a1)

		lea	oxTN_border_white_coords(a1),a2
		move.l	a2,oxTN_border_white+bd_XY(a1)
		lea	oxTN_border_color(a1),a2
		move.l	a2,oxTN_border_white+bd_NextBorder(a1)
		move.b	#4,oxTN_border_white+bd_Count(a1)

	;	lea	oxTN_border_white2_coords(a1),a2
	;	move.l	a2,oxTN_border_white2+bd_XY(a1)
	;	lea	oxTN_border_color(a1),a2
	;	move.l	a2,oxTN_border_white2+bd_NextBorder(a1)
	;	move.b	#2,oxTN_border_white2+bd_Count(a1)

		lea	oxTN_border_color_coords(a1),a2
		move.l	a2,oxTN_border_color+bd_XY(a1)
		move.b	#3,oxTN_border_color+bd_Count(a1)

		pop	a2

		rts

TbInitTabColors	; *tabnode in a2

		move.b	oxPT_blackpen(a1),d1
		move.b	oxPT_shinepen(a1),d2
		move.b	oxPT_darkpen(a1),d3

		move.b	d1,oxTN_backborder_black+bd_FrontPen(a2)
		move.b	d2,oxTN_backborder_white+bd_FrontPen(a2)
		move.b	d3,oxTN_backborder_color+bd_FrontPen(a2)
		move.b	d1,oxTN_border_black+bd_FrontPen(a2)
		move.b	d2,oxTN_border_white+bd_FrontPen(a2)
	;	move.b	d2,oxTN_border_white2+bd_FrontPen(a2)
		move.b	d3,oxTN_border_color+bd_FrontPen(a2)
		rts

TbINIT		bsr	TbBcToAll			; initialisiere objekte der verdeckten tabs,
							; wurde zwar beim create dieser objekte schon
							; gemacht aber hat zB im fall von radios
							; nicht geklappt weil die dazu eine drawinfo brauchen
		moveq	#rp_SIZEOF,d0
		bsr	alloc_mem
		move.l	d0,oxTb_offrastport(a3)
		beq.b	.rts_fail

		move.l	d0,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOInitRastPort(a6)
		moveq	#1,d0
		rts
.rts_fail	moveq	#-1,d0
		rts

Tb_drop_bmp	move.l	oxTb_offbitmap(a3),d0
		clr.l	oxTb_offbitmap(a3)
		move.l	d0,a0
		move.l	gfxbase(pc),a6
		jmp	_LVOFreeBitMap(a6)

TbDEINIT	; do a free at all listed objects, except the active one if its still linked below
		; well, lets just test if the list is empty and if it is then all can be free from here 

		move.l	oxTb_fill_image(a3),d0
		beq.b	.dbmp
		clr.l	oxTb_fill_image(a3)
		move.l	d0,a0
		bsr	_oxDropImage

.dbmp		bsr.b	Tb_drop_bmp

.free_rp	move.l	oxTb_offrastport(a3),d0
		beq.b	.norp
		move.l	d0,a0
		moveq	#rp_SIZEOF,d0
		bsr	free_mem

.norp		move.l	oxTb_current(a3),d2
		move.l	oxTb_list+LH_HEAD(a3),a2

	; wurde schon von freeobject disposed
	;	lea	oxO_list(a3),a1
	;	IFEMPTY a1,.del_lp
	;	move.l	(a1),a1
	;	REMOVE

.del_lp		tst.l	(a2)
		beq.b	.rts

		move.l	oxTN_object(a2),a0
		cmp.l	a0,d2			; aktuelles nicht freigeben weil es durch DEINIT
		beq.b	.freetngetnext		; schon von unten her freigegeben wurde

		bsr	_oxFreeObject

.freetngetnext	move.l	a2,a0

		move.l	(a2),a2			; weiter in liste

		move.l	#oxTN_SIZEOF,d0	; free TN
		bsr	free_mem
		bra	.del_lp
.rts		rts


TbSET		movem.l	(a1),d2/d3

		cmp.w	#oxTbA_newtab,d2
		beq.b	.newtab

		cmp.w	#oxTbA_imagename,d2
		bne.b	.if_di
		move.l	d3,oxTb_fill_imagename(a0)
	;	bset	#oxTbB_PATTFILL,oxTb_flags(a0)
		rts

.if_di		cmp.w	#oxA_drawinfo,d2
		bne.b	.rts
		move.l	d3,oxTb_drawinfo(a0)
		bra.b	TbBcToAll

.newtab		; kommt a0 *tabsobject rein, d3 parameter is *newtab

		move.l	d3,a2

		move.l	#oxTN_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts

		move.l	d0,a1

		move.l	8(a2),a3
		move.l	a3,oxTN_title(a1)
		moveq	#-1,d1
.len_lp		addq.w	#1,d1
		tst.b	(a3)+
		bne.b	.len_lp
		move.w	d1,oxTN_titlelenght(a1)

		bsr.b	TbInitTabNode
 
		move.l	(a2)+,d2
		move.l	(a2),a2
		push	a1
		move.l	oxO_userbase(a0),a1
		bsr	_oxCreateOnly	; init wird dann von TbINIT aus an invisible gesendet
		pop	a1

		move.l	d0,oxTN_object(a1)
		beq.b	.free

		; first created tab is default at front

		tst.l	oxTb_current(a0)
		bne.b	.addtolist
		move.l	d0,oxTb_current(a0)

		bset	#oxTNB_ISINFRONT,oxTN_flags(a1)

		; a0 *tabsobject

		bsr	TbSetCurrent

.addtolist	lea	oxTb_list(a0),a0

		; a1 tabnode, a0 tabnodes list

		ADDTAIL

.rts		rts


.free		move.l	a1,a0
		move.l	#oxTN_SIZEOF,d0
		bra	free_mem

TbBcToAll	move.l	oxTb_current(a3),d3
		lea	oxTb_list(a3),a2
.lp		move.l	(a2),a2
		tst.l	(a2)
		beq	.rts

		move.l	oxTN_object(a2),a0	; skip current that gets it autoamtedly
		cmp.l	a0,d3
		beq.b	.lp

		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.lp

.rts		rts

TbSetCurrent	; exchange Member by new current

		; a0 Tabsobject

		pushm	a0/a1

		pea	oxO_list(a0)			; 4(a7)
		move.l	oxTb_current(a0),-(a7)		; (a7)

		;	4(a7)	*memberlist
		;	(a7)	*current object

		move.l	4(a7),a1
		IFEMPTY	a1,.add_current

		move.l	(a1),a1	
		REMOVE

.add_current	move.l	4(a7),a0
		move.l	(a7),a1

		ADDHEAD			; A0-list(destroyed) A1-node D0-(destroyed)

		lea	8(a7),a7

		popm	a0/a1

		rts

; end of handling


TbGETLAYOUT	move.l	oxTb_drawinfo(a0),a4
		move.l	oxDI_rastport(a4),a4
		move.l	a1,a3

		move.w	rp_TxHeight(a4),d0
		addq.w	#4+4,d0
		move.w	d0,oxTb_griffheight(a0)

		clr.l	oxLI_minwidth(a3)
		clr.l	oxLI_propw(a3)

		moveq	#0,d6	; griffe breite summe

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		lea	oxTb_list(a0),a2
.ask_all_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.addtabwidths

		push	a1

		move.l	oxTN_title(a2),a0
		move.w	oxTN_titlelenght(a2),d0
		move.l	a4,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)
		add.w	#10,d0			; 2+3 left, 2+3 right (frame 2 + spacing 3)
		move.w	d0,oxTN_width(a2)
		add.w	d0,d6			; add to griffleisten breite
		add.w	#1,d6			; pro tab title 1 pixel space

		pop	a1

		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_propw(a1)

		move.l	oxTN_object(a2),a0
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		move.w	oxLI_minwidth(a1),d0
		cmp.w	oxLI_minwidth(a3),d0
		ble.b	.test_h
		move.w	d0,oxLI_minwidth(a3)

.test_h		move.w	oxLI_minheight(a1),d0
		cmp.w	oxLI_minheight(a3),d0
		ble.b	.merge_prop
		move.w	d0,oxLI_minheight(a3)

.merge_prop	move.l	oxLI_propw(a1),d0
		or.l	d0,oxLI_propw(a3)
		bra.b	.ask_all_lp

.addtabwidths	add.w	#14,oxLI_minwidth(a3)		; left and right border 5+2 pix, frame and spacing
		addq.w	#2,d6				; breite ganze griffeleiste (spacing)

		cmp.w	oxLI_minwidth(a3),d6
		ble.b	.addtoheight
		move.w	d6,oxLI_minwidth(a3)

.addtoheight	add.w	#2+5+5+4+4,oxLI_minheight(a3)	; bottom 2, spacing 5, top 5, leiste 4+4+fonthöhe
		move.w	rp_TxHeight(a4),d0		; read from rastport
		add.w	d0,oxLI_minheight(a3)

		; allow max size if prop may grow

		tst.w	oxLI_propw(a3)
		beq.b	.if_proph
		move.w	#$7fff,oxLI_maxwidth(a3)
.if_proph	tst.w	oxLI_proph(a3)
		beq.b	.res
		move.w	#$7fff,oxLI_maxheight(a3)

.res		lea	oxLI_SIZEOF(a7),a7
		moveq	#1,d0
		rts

TbSETLAYOUT	pushm	a0/a1

		move.l	a0,a3
		move.l	oxTb_offbitmap(a0),d0
		beq.b	.nodel
		move.l	d0,a0
		move.l	gfxbase(pc),a6
		jsr	_LVOFreeBitMap(a6)
		clr.l	oxTb_offbitmap(a3)

.nodel		popm	a0/a1

		move.l	a0,a3

		; calc content pos and size in the tab area with borders and spacings 

		move.l	oxLI_left(a1),oxTb_left(a0)
		move.l	oxLI_width(a1),oxTb_width(a0)

		; sub tabs widths

		move.l	oxTb_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.w	rp_TxHeight(a2),d0
		add.w	#7,oxLI_left(a1)
		add.w	#5+4+4,oxLI_top(a1)
		add.w	d0,oxLI_top(a1)
		sub.w	#14,oxLI_width(a1)
		sub.w	#2+5+5+4+4,oxLI_height(a1)
		sub.w	d0,oxLI_height(a1)

		; now do to all, d1 is still SETLAYOUT, a1 remains *layoutinfo with modiefied valuez
		; this time dont skip current because LAYOUT messages come w/o broadcast only with Do()

		lea	oxTb_list(a0),a2
.lp		move.l	(a2),a2
		tst.l	(a2)
		beq	.calc_coords

		; calc coords for all tabs inactive state 

		; BLACK

		lea	oxTN_backborder_black_coords(a2),a4

		; bottom left

		clr.w	(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#3,d7			; 2 because dist from top is allready 1 for inactive tabs
		move.w	d7,(a4)+

		; top left

		clr.w	(a4)+
		move.w	#4,(a4)+

		; round top left

		move.w	#3,(a4)+
		move.w	#1,(a4)+

		; top right

		move.w	oxTN_width(a2),d0
		subq.w	#4,d0
		move.w	d0,(a4)+
		move.w	#1,(a4)+

		; round top right

		move.w	oxTN_width(a2),d0
		subq.w	#1,d0
		move.w	d0,(a4)+
		move.w	#4,(a4)+

		; bottom right

		move.w	d0,(a4)+
		move.w	oxTb_griffheight(a3),d0
		subq.w	#3,d0
		move.w	d0,(a4)+

		; WHITE

		lea	oxTN_backborder_white_coords(a2),a4

		; bottom left

		move.w	#1,(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#3,d7
		move.w	d7,(a4)+

		; top left

		move.w	#1,(a4)+
		move.w	#4,(a4)+

		; top left 2 (roundnes)

		move.w	#3,(a4)+
		moveq	#2,d1
		move.w	d1,(a4)+

		; top right

		move.w	oxTN_width(a2),d0
		subq.w	#4,d0
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; COLOR		top right 2

		lea	oxTN_backborder_color_coords(a2),a4

		addq.w	#1,d0
		addq.w	#1,d1
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; top right 1

		addq.w	#1,d0
		addq.w	#1,d1
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; bottom right

		move.w	d0,(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#3,d7
		move.w	d7,(a4)+

		; calc coords for all tabs ACTIVE state slightly different from inactive style 

		; BLACK

		lea	oxTN_border_black_coords(a2),a4

		; bottom left

		clr.w	(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#2,d7			; 2 because dist from top is allready 1 for inactive tabs
		move.w	d7,(a4)+

		; top left

		clr.w	(a4)+
		move.w	#3,(a4)+

		; round top left

		move.w	#3,(a4)+
		clr.w	(a4)+

		; top right

		move.w	oxTN_width(a2),d0
		subq.w	#3,d0
		move.w	d0,(a4)+
		clr.w	(a4)+

		; round top right

		move.w	oxTN_width(a2),d0
		move.w	d0,(a4)+
		move.w	#3,(a4)+

		; bottom right

		move.w	d0,(a4)+
		move.w	oxTb_griffheight(a3),d0
		subq.w	#2,d0
		move.w	d0,(a4)+

		; WHITE

		lea	oxTN_border_white_coords(a2),a4

		; bottom left

		move.w	#1,(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#2,d7
		move.w	d7,(a4)+

		; top left

		move.w	#1,(a4)+
		move.w	#3,(a4)+

		; top left 2 (roundnes)

		move.w	#3,(a4)+
		moveq	#1,d1
		move.w	d1,(a4)+

		; top right

		move.w	oxTN_width(a2),d0
		subq.w	#3,d0
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; COLOR		top right 2

		lea	oxTN_border_color_coords(a2),a4

		addq.w	#1,d0
		addq.w	#1,d1
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; top right 1

		addq.w	#1,d0
		addq.w	#1,d1
		move.w	d0,(a4)+
		move.w	d1,(a4)+

		; bottom right

		move.w	d0,(a4)+
		move.w	oxTb_griffheight(a3),d7
		subq.w	#1,d7
		move.w	d7,(a4)+



		; tell sizes

		move.l	oxTN_object(a2),a0	; skip current that gets it autoamtedly
		move.l	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod
		bra.b	.lp

.calc_coords	; reinit ther U shaped borders

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a0
		move.w	rp_TxHeight(a0),d7

		lea	oxTb_border_black_coords(a3),a1

		;                          v
		; left black frame edge    |____|

		clr.w	(a1)+
		move.w	d7,d0
		addq.w	#7,d0
		move.w	d0,(a1)+

		; bottom left frame edge 1

		clr.w	(a1)+
		move.w	oxTb_height(a3),d0
		subq.w	#2,d0
		move.w	d0,(a1)+

		; bottom left edge 2

		move.w	#1,(a1)+
		addq.w	#1,d0
		move.w	d0,(a1)+

		; right bottom edge 2

		move.w	oxTb_width(a3),d1
		subq.w	#2,d1
		move.w	d1,(a1)+
		move.w	d0,(a1)+

		; right bottom edge 1

		addq.w	#1,d1
		move.w	d1,(a1)+
		subq.w	#1,d0
		move.w	d0,(a1)+

		; right edge

		move.w	d1,(a1)+
		moveq	#7,d0
		add.w	d7,d0
		move.w	d0,(a1)+

		; right	edge 2 (roundness)

		subq.w	#1,d1
		move.w	d1,(a1)+
		subq.w	#1,d0
		move.w	d0,(a1)+

		; to left top

		move.w	#1,(a1)+
		move.w	d0,(a1)+

		lea	oxTb_border_white_coords(a3),a1

		; white right top

		move.w	oxTb_width(a3),d1
		subq.w	#3,d1
		move.w	d1,(a1)+
		move.w	oxTb_griffheight(a3),d1
		subq.w	#1,d1
		move.w	d1,(a1)+

		; white top left

		moveq	#1,d1
		move.w	d1,(a1)+
		move.w	d7,d0
		addq.w	#7,d0
		move.w	d0,(a1)+

		; bottom left white endpoint

		move.w	d1,(a1)+
		move.w	oxTb_height(a3),d0
		subq.w	#2,d0
		move.w	d0,(a1)+

		; bottom blue

		lea	oxTb_border_color_coords(a3),a1

		; bottom left edge 2

		addq.w	#1,d1
		move.w	d1,(a1)+
		move.w	d0,(a1)+

		; right bottom edge 1

		move.w	oxTb_width(a3),d1
		sub.w	#2,d1
		move.w	d1,(a1)+
		move.w	d0,(a1)+

		; right edge

		move.w	d1,(a1)+
		moveq	#7,d0
		add.w	d7,d0
		move.w	d0,(a1)

		moveq	#1,d0
		rts


TbDRAW		move.l	a0,a3
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_pentable(a1),a5

		move.l	gfxbase(pc),a6

		move.l	oxDI_rastport(a1),a1
		moveq 	#RP_JAM2,d0
		jsr	_LVOSetDrMd(a6)

		; save griffleiste bg clip	(get)

		tst.l	oxTb_offbitmap(a3)
		bne.b	.put

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a0
		move.l	rp_BitMap(a0),a0
		moveq	#BMA_DEPTH,d1
		jsr	_LVOGetBitMapAttr(a6)
		move.l	d0,d2
		
		move.l	#BMF_MINPLANES,d3
		moveq	#0,d0
		moveq	#0,d1
		move.w	oxTb_width(a3),d0
		move.w	oxTb_griffheight(a3),d1

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_window(a0),a0
		move.l	wd_WScreen(a0),a0		; friend to screen bitmap
		move.l	sc_RastPort+rp_BitMap(a0),a0

		jsr	_LVOAllocBitMap(a6)

		move.l	d0,oxTb_offbitmap(a3)		; set new offbitmap with actual dimens
		beq.b	.fill_tab_area

		move.l	oxTb_offrastport(a3),a1	; also ok for ClipBlit
		move.l	d0,rp_BitMap(a1)

		; get bg

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a0

		movem.w	oxTb_left(a3),d0/d1

		moveq	#0,d2
		moveq	#0,d3

		move.w	oxTb_width(a3),d4
		move.w	oxTb_griffheight(a3),d5

		move.b	#$0C0,d6

		jsr	_LVOClipBlit(a6)

		bra.b	.fill_tab_area

.put            ; put saved bg into window

		move.l	oxTb_offrastport(a3),a0
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		movem.w	oxTb_left(a3),d2/d3

		moveq	#0,d0
		moveq	#0,d1

		move.w	oxTb_width(a3),d4
		move.w	oxTb_griffheight(a3),d5

		move.b	#$C0,d6

		jsr	_LVOClipBlit(a6)

.fill_tab_area	; if wanted, fill tab area with tiled pattern image

		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.penfill

		move.l	oxTb_fill_image(a3),d7
		bne.b	.imagefill

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_bgimage(a0),d7
		beq.b	.penfill

.imagefill	move.l	d7,a0
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		movem.w	oxTb_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		addq.w	#2,d0
		add.w	oxTb_griffheight(a3),d1
		subq.w	#3,d2
		subq.w	#3,d3

		moveq	#0,d4
		moveq	#0,d5

		bsr	_oxImageFill
		bra.b	.draw_bdy_bordr

.penfill	; fill tabs area with tabs bg pen

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
	;	move.b	oxPT_tabspen(a5),d0	; tabs bg color

	move.b	oxTb_backpen(a3),d0

		jsr 	_LVOSetAPen(a6)

		movem.w	oxTb_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		addq.w	#2,d0
		add.w	oxTb_griffheight(a3),d1
		subq.w	#3,d2
		subq.w	#3,d3

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		jsr	_LVORectFill(a6)

.draw_bdy_bordr	lea	oxTb_border(a3),a1

		movem.w	oxTb_left(a3),d0/d1
		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a0
		move.l	intbase(pc),a6
		jsr	_LVODrawBorder(a6)

		movem.w	oxTb_left(a3),d4/d5
		addq.w	#1,d4

		lea	oxTb_list(a3),a2
.tabs_lp	move.l	(a2),a2
		tst.l	(a2)
		beq.b	.rts

		; fill tabtitle

		move.l	gfxbase(pc),a6
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
	;	move.b	oxPT_tabspen(a5),d0	; tabs bg color

	move.b	oxTb_backpen(a3),d0

		jsr 	_LVOSetAPen(a6)

		move.w	oxTb_top(a3),d1
		move.w	d1,d3
		add.w	oxTb_griffheight(a3),d3
		subq.w	#3,d3
		addq.w	#3,d1
		move.w	d4,d0
		addq.w	#2,d0
		move.w	d4,d2
		add.w	oxTN_width(a2),d2
		subq.w	#3,d2

		btst	#oxTNB_ISINFRONT,oxTN_flags(a2)
		beq.b	.fill

		addq.w	#2,d3
		subq.w	#1,d1
		addq.w	#1,d2

.fill		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.rectfill

		; if present, fill with image

		move.l	oxTb_fill_image(a3),d7
		bne.b	.imagef_tabbody

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_bgimage(a0),d7
		beq.b	.rectfill

.imagef_tabbody	move.l	d7,a0
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		pushm	d4/d5

		moveq	#0,d4
		moveq	#0,d5

		bsr	_oxImageFill

		popm	d4/d5

		bra.b	.griff_border

.rectfill	; fill with pen

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		jsr	_LVORectFill(a6)

.griff_border	lea	oxTN_backborder(a2),a1

		btst	#oxTNB_ISINFRONT,oxTN_flags(a2)
		beq.b	.draw
		
		lea	oxTN_border(a2),a1

.draw		move.w	d4,d0
		move.w	d5,d1
		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a0
		move.l	intbase(pc),a6
		jsr	_LVODrawBorder(a6)

		; draw title texts

		move.l	gfxbase(pc),a6

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
	;	move.b	oxPT_textpen(a5),d0

	move.b	oxTb_textpen(a3),d0

		move.b	oxPT_tabspen(a5),d1
		moveq 	#RP_JAM1,d2
		jsr 	_LVOSetABPenDrMd(a6)

		move.w	d4,d0
		addq.w	#5,d0
		move.w	oxTb_top(a3),d1
		addq.w	#4,d1
		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		add.w	rp_TxBaseline(a1),d1
		move.l	oxTN_title(a2),a0

		btst	#oxTNB_ISINFRONT,oxTN_flags(a2)
		bne.b	.text

		addq.w	#1,d1

.text		movem.w	d0/d1,-(a7)

		push	a1

		jsr	_LVOMove(a6)

		pop	a1

		move.w	oxTN_titlelenght(a2),d0
		jsr	_LVOText(a6)
		movem.w	(a7)+,d0/d1

		btst	#oxTNB_ISINFRONT,oxTN_flags(a2)
		beq.b	.stepwidth

		addq.w	#1,d0

		move.l	oxTb_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		move.l	oxTN_title(a2),a0

		push	a1

		jsr	_LVOMove(a6)

		pop	a1

		move.w	oxTN_titlelenght(a2),d0
		jsr	_LVOText(a6)

.stepwidth	add.w	oxTN_width(a2),d4
		addq.w	#1,d4

		btst	#oxTNB_ISINFRONT,oxTN_flags(a2)
		beq.b	.tabs_lp

		addq.w	#1,d4

		bra.b	.tabs_lp


.rts		moveq	#0,d0
		rts

TbINTUI		move.l	a0,a3

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		bne.b	.return_unused

		cmp.w	#SELECTDOWN,im_Code(a1)
 		bne.b	.return_unused

		movem.w	oxTb_left(a0),d0-d2
		addq.w	#1,d0
		move.w	d0,d4
		move.w	oxTb_griffheight(a0),d3
		bsr	_is_in_rect
		beq	.return_unused

		lea	oxTb_list(a0),a2
.clr_lp		move.l	(a2),a2
		tst.l	(a2)
		beq	.set

		bclr	#oxTNB_ISINFRONT,oxTN_flags(a2)
		beq.b	.clr_lp

		pushm	d0/d1/a0

		move.l	oxTN_object(a2),a0
		moveq	#OXM_BACK,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

		popm	d0/d1/a0

.set		lea	oxTb_list(a0),a2
.set_lp		move.l	(a2),a2
		tst.l	(a2)
		beq	.return_unused

		move.w	d4,d0
		move.w	oxTN_width(a2),d2
		add.w	d2,d4
		addq.w	#1,d4
		bsr	_is_in_rect
		beq	.set_lp

		bset	#oxTNB_ISINFRONT,oxTN_flags(a2)

		push	a0

		move.l	oxTN_object(a2),a0
		moveq	#OXM_FRONT,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

		pop	a0

		move.l	oxTN_object(a2),d0
		cmp.l	oxTb_current(a0),d0
		beq.b	.return_unused
		move.l	d0,oxTb_current(a0)

		bsr	TbSetCurrent

		; remove last active object from window "ichbindran"

		push	a0

		move.l	oxTb_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWM_clrpriv,d1
		bsr	_oxDoMethod

		; let link active object to window "ichbindran"

		moveq	#OXM_LINKPRIV,d1
		moveq	#OXBMODE_EVERYBODY,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

		; link tab-chain ring

		bsr	_oxRelink

		; refresh tab

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		moveq	#OXRMODEF_ALL,d4
		bsr	_oxBeginRefresh

		pop	a0

		move.l	#OXM_DRAW,d1
		moveq	#OXBMODE_EVERYBODY|OXBMODE_SELF,d2
		bsr	_oxBroadcast

		move.l	oxTb_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0

		movem.w	oxTb_left(a3),d0-d3

		moveq	#0,d4
		bsr	_oxEndRefresh

		moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts


tb_create_ex	lea	.tabs(pc),a2
		move.l	#OX_TABS,d2
		bra	_oxCreateObject

.tabs		dc.l	oxTbA_newtab,.tab1
		dc.l	oxTbA_newtab,.tab2
		dc.l	oxTbA_newtab,.tab3
 		dc.l	TAG_END

.tab1		dc.l	OX_FRAME,.frame1,.title1	; newtab structures, if more tags here how to send to new tabnode?
.tab2		dc.l	OX_FRAME,.frame2,.title2
.tab3		dc.l	OX_FRAME,.frame3,.title3

.title1		dc.b	"tab 1",0
.title2		dc.b	"and tab 2",0
.title3		dc.b	"noch ein tab",0
		even

.frame1		dc.l	oxFrA_spacing,0
		dc.l	oxFrA_hprop,1
		dc.l	oxFrA_vprop,1
		dc.l	oxFrA_framestyle,0
		dc.l	oxFrA_fillstyle,0
		dc.l	oxFrA_hzalign,oxFr_LEFT
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	OX_BUTTON,.ex_but1
		dc.l	TAG_END

.frame2		dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_SHADOW
		dc.l	oxFrA_hzalign,oxFr_MIDDLE
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	OX_LABEL,.ex_lab2
		dc.l	TAG_END

.wheelgrad	dc.l	TAG_END

.frame3		dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_GNG
		dc.l	oxFrA_fillstyle,oxFr_PEN
		dc.l	oxFrA_hzalign,oxFr_RIGHT
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	OX_LABEL,.ex_lab3
		dc.l	TAG_END

.ex_but1	dc.l	oxBA_text,.ex_text1
		dc.l	TAG_END
.ex_lab2	dc.l	oxLabA_text,.ex_text2
		dc.l	TAG_END
.ex_lab3	dc.l	oxLabA_text,.ex_text3
		dc.l	TAG_END

.ex_text1	dc.b	"button on tab",0
.ex_text2	dc.b	"Tab 2",0
.ex_text3	dc.b	"Tab 3",0
		even

;--------------------------------------------------------------------
; OX_PAGES

 STRUCTURE	oxPages,oxO_SIZEOF
	UWORD	oxPg_left
	UWORD	oxPg_top
	UWORD	oxPg_width
	UWORD	oxPg_height
	APTR	oxPg_current		; * current page (object)
	STRUCT	oxPg_list,MLH_SIZE	; list of all pages (objects)

	UBYTE	oxPg_flags
	UBYTE	oxPg_pad

	APTR	oxPg_drawinfo

	LABEL	oxPg_SIZEOF


	BITDEF	oxPg,REDRAW,0		; redraw when page changed


 STRUCTURE	oxPageNode,MLN_SIZE
	APTR	oxPN_object
	LABEL	oxPN_SIZEOF


	OXICLASSHEADER	pages, 1, 0, space

	dc.l	oxCA_objectsize,oxPg_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,pg_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Pages are multiple contents at the same place, only one can be at front.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	.SET

		cmp.w	#OXM_GET,d1
		beq	.GET

		cmp.w	#OXM_SETDEF,d1
		beq	PgSETDEF

		cmp.w	#OXM_DEINIT,d1
		beq	PgDEINIT

		cmp.w	#OXM_INIT,d1
		beq.b	.rts_true

		cmp.w	#OXM_GETLAYOUT,d1
		beq	PgGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	.PgSETLAYOUT

		cmp.w	#OXM_DRAW,d1
		beq.b	.draw

		cmp.w	#OXM_APPWINMESSAGE,d1
		beq.b	.bc_to_current

		cmp.w	#OXM_INTUIMESSAGE,d1
		beq.b	.bc_to_current

		cmp.w	#OXM_WINDOWOPEN,d1 
		beq	.bc_to_all

		cmp.w	#OXM_WINDOWCLOSING,d1
		bne.b	.if_relink

		cmp.w	#OXM_INHERIT,d1
		beq	.INHERIT

		bra.b	.bc_to_all

.draw		bra.b	.bc_to_current		; wenn schon broadcast rein kommt kann nicht doppelt werden
						; weil kein member am standard anschluss hängt

.INHERIT	lea	oxPg_list(a0),a2
.bc_inh_loop	move.l	(a2),a2
		tst.l	(a2)
		beq	.rts5

		move.l	oxPN_object(a2),a0
		moveq	#OXBMODE_STOPLEVEL+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.bc_inh_loop

.rts5		rts	; no direct members, no termination needed


.PgSETLAYOUT	move.l	oxLI_left(a1),oxPg_left(a0)
		move.l	oxLI_width(a1),oxPg_width(a0)
		bra	.do_to_all

.if_relink	cmp.w	#OXM_RELINK,d1
		beq.b	.bc_to_current

	;bra.b	.bc_to_all

		cmp.w	#OXM_BACK,d1
		beq.b	.bc_to_all

		cmp.w	#OXM_FRONT,d1
		bne.b	.bc_to_all

		push	a0

		moveq	#OXM_FRONT,d1
		move.l	oxPg_current(a0),a0
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast

		pop	a0

		moveq	#OXM_BACK,d1

		; bc to back/invisible pages

		move.l	oxPg_current(a0),d3
		lea	oxPg_list(a0),a2
.bc_to_invis_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.rts_true

		move.l	oxPN_object(a2),a0
		cmp.l	d3,a0
		beq.b	.bc_to_invis_lp

		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.bc_to_invis_lp

.bc_to_all      lea	oxPg_list(a0),a2
.bc_to_all_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.rts_true

		move.l	oxPN_object(a2),a0
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.bc_to_all_lp

.rts_true	moveq	#1,d0
		rts

.do_to_all	lea	oxPg_list(a0),a2
.do_to_all_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.rts_true

		move.l	oxPN_object(a2),a0
		bsr	_oxDoMethod
		bra.b	.do_to_all_lp

.bc_to_current	move.l	oxPg_current(a0),d0		; get * current page (object)
		beq	.rts_true
		move.l	d0,a0
		or.w	#OXBMODE_SELF,d2
		bsr	_oxBroadcast
		bra.b	.rts_true

.SET		movem.l	(a1),d2/d3

		cmp.l	#oxPgA_redraw,d2
		bne.b	.if_number
		tst.b	d3
		beq.b	.clr_redr
		bset	#oxPgB_REDRAW,oxPg_flags(a0)
		rts
.clr_redr	bclr	#oxPgB_REDRAW,oxPg_flags(a0)
		rts

;		cmp.l	#oxPgA_propw,d2
;		bne.b	.if_proph
;		move.w	d3,oxPg_propw(a0)
;		rts
;.if_proph	cmp.l	#oxPgA_proph,d2
;		bne.b	.if_current
;		move.w	d3,oxPg_proph(a0)
;		rts
.if_number	cmp.l	#oxPgA_number,d2
		bne.b	.if_current

		tst.l	d3
		beq.b	.set_curr

		subq.w	#1,d3

		lea	oxPg_list(a0),a2
.findnum_lp	move.l	(a2),a2
		tst.l	(a2)
		beq.b	.rts_true
		dbf	d3,.findnum_lp

		move.l	oxPN_object(a2),d3

		bra.b	.set_curr

.if_current	cmp.l	#oxPgA_current,d2
		bne.b	.if_newmember

	;	move.l	oxPg_current(a0),d0
	;	beq.b	.set_curr

	;	tst.l	oxPg_windowobject(a0)
	;	beq.b	.set_curr

	;	push	a0
	;	moveq	#OXM_INACTIVE,d1
	;	bsr.b	.bc_to_all
	;	pop	a0

.set_curr	cmp.l	oxPg_current(a0),d3
		beq.b	.rts4

		push	a0

		move.l	oxPg_current(a0),d0
		beq.b	.to_front

		move.l	d0,a0
		moveq	#OXM_BACK,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

	;	moveq	#0,d1
	;	move.l	oxPg_drawinfo(a3),a0
	;	move.l	oxDI_windowobject(a0),a0
	;	move.l	#oxWA_ichbindran,d0
	;	bsr	_oxSetAttr

.to_front	tst.l	d3
		beq.b	.pop

		move.l	d3,a0
		moveq	#OXM_FRONT,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2	;+OXBMODE_UNTILTRUE
		bsr	_oxBroadcast

	;	moveq	#OXM_LINKPRIV,d1
	;	moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2	;+OXBMODE_UNTILTRUE
	;	bsr	_oxBroadcast

.pop		pop	a0

		move.l	d3,oxPg_current(a0)

		move.l	oxPg_drawinfo(a0),d0
		beq	.rts4

		push	a0

		move.l	d0,a0
		move.l	oxDI_windowobject(a0),a0

		bsr	_oxRelink		; also required when current set to null,
						; required to remove previous links
		pop	a0

		btst	#oxPgB_REDRAW,oxPg_flags(a0)
		beq.b	.rts4

		move.l	oxPg_current(a0),d0		; get * current page (object)
		beq	.rts_true

		move.l	d0,a1
		movem.w	oxPg_left(a0),d0-d3
		move.l	oxPg_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		bsr	_oxRefresh

		bra	.rts_true

.rts4		rts


.if_newmember	cmp.l	#oxPgA_newmember,d2
		bne.b	.if_member

		tst.l	d3
		beq.b	.rts4

		; make new member

		moveq	#oxPN_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts1

		move.l	d0,a1
		
		move.l	d3,a2			; get first tag class-id and taglist
		move.l	(a2),d2			; this may be the only item here
		move.l	4(a2),a2

		pushm	a0/a1
		move.l	a4,a1
		bsr	_oxCreateObject
		popm	a0/a1

		move.l	d0,oxPN_object(a1)
		beq.b	.free

.set_current	tst.l	oxPg_current(a0)
		bne.b	.addtolist
		move.l	d0,oxPg_current(a0)

		move.l	oxPg_drawinfo(a0),d0
		beq.b	.addtolist

		pushm	a0/a1

		move.l	d0,a0
		move.l	oxDI_windowobject(a0),a0

		bsr	_oxRelink
		popm	a0/a1

.addtolist	lea	oxPg_list(a0),a0
		ADDTAIL

.rts1		rts

.free		move.l	a1,a0
		moveq	#oxPN_SIZEOF,d0
		bra	free_mem

.if_member	cmp.l	#oxPgA_member,d2
		bne	.if_dri

		tst.l	d3
		beq.b	.rts1

		; add precreated member

		moveq	#oxPN_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts1

		move.l	d0,a1
		move.l	d3,oxPN_object(a1)

		pushm	a0/a1

		move.l	oxPg_drawinfo(a0),-(a7)
		move.l	#oxA_drawinfo,-(a7)
		move.l	d3,a0
		move.l	#OXM_SET,d1
		move.l	a7,a1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		bsr	_oxBroadcast
		addq.l	#8,a7

	;	move.l	oxPg_drawinfo(a0),d1
	;	move.l	#oxA_drawinfo,d0
	;	move.l	d3,a0
	;	bsr	_oxBroadcastAttr	Self was a solution

		; nochmal init nachdem jetzt die neuen members *drawinfo haben
		; (bit bei schon initialisierten objekten ist gesetzt)

		bsr	_oxInit

		popm	a0/a1

		move.l	d3,d0

		bra.b	.set_current

.if_dri		cmp.l	#oxA_drawinfo,d2
		bne.b	.bc_to_all
		move.l	d3,oxPg_drawinfo(a0)
		bra	.bc_to_all

.GET		move.l	(a1),d1

		cmp.l	#oxPgA_member,d1
		bne.b	.rts

		moveq	#0,d0
		lea	oxPg_list(a0),a0
		move.l	8(a0),a0
		tst.l	(a0)
		beq.b	.rts1
		move.l	a0,d0
.rts		rts

 STRUCTURE	oxPageExampleInfo,0
		APTR	oxPEI_pages
		LABEL	oxPEI_SIZEOF

pg_create_ex	lea	.buffer(pc),a2
		move.l	#OX_BUFFER,d2
		bra	_oxCreateObject

.buffer		dc.l	OX_HORIZGROUP,.hzgroup
		dc.l	oxBfA_buffersize,oxPEI_SIZEOF
		dc.l	TAG_END

.hzgroup	dc.l	OX_VERTGROUP,.controlbuttons
		dc.l	OX_PAGES,.pages
		dc.l	oxGA_hprop,1
		dc.l	oxGA_vprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.controlbuttons	dc.l	OX_BUTTON,.ctrla
		dc.l	OX_BUTTON,.ctrlb
		dc.l	OX_BUTTON,.ctrlc
		dc.l	TAG_END

.ctrla		dc.l	oxBA_hook,.hk1
		dc.l	oxBA_text,.tx1
		dc.l	oxBA_linechar,6
		dc.l	TAG_END

.ctrlb		dc.l	oxBA_hook,.hk2
		dc.l	oxBA_text,.tx2
		dc.l	oxBA_linechar,6
		dc.l	TAG_END

.ctrlc		dc.l	oxBA_hook,.hk3
		dc.l	oxBA_text,.tx3
		dc.l	oxBA_linechar,6
		dc.l	TAG_END

.tx1		dc.b	"page 1",0
.tx2		dc.b	"page 2",0
.tx3		dc.b	"page 3",0
		even

.hk1		moveq	#1,d1
.hk0		move.l	oxPEI_pages(a4),a0
		move.l	#oxPgA_number,d0
		bra	_oxSetAttr
	;	moveq	#OXM_DRAW,d1
	;	bra	_oxDoMethod

.hk2		moveq	#2,d1
		bra.b	.hk0

.hk3		moveq	#3,d1
		bra.b	.hk0


.pages		dc.l	oxPgA_newmember,.page1
		dc.l	oxPgA_newmember,.page2
		dc.l	oxPgA_newmember,.page3
		dc.l	oxPgA_redraw,1
		dc.l	OX_RELPTR,oxPEI_pages
		dc.l	TAG_END

.page1		dc.l	OX_FRAME,.frame1
.page2		dc.l	OX_FRAME,.frame2
.page3		dc.l	OX_FRAME,.frame3

.frame1		dc.l	oxFrA_spacing,5
		dc.l	oxFrA_hprop,1
		dc.l	oxFrA_framestyle,oxFr_STRONG
		dc.l	oxFrA_fillstyle,oxFr_PATT1
		dc.l	oxFrA_hzalign,oxFr_LEFT
		dc.l	oxFrA_vtalign,oxFr_TOP
	;	dc.l	OX_LABEL,.ex_lab1
		dc.l	OX_BUTTON,.btn
		dc.l	TAG_END

.btn		dc.l	oxBA_text,.tx
		dc.l	TAG_END

.tx		dc.b	"button here",0
		even

.frame2		dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_SHADOW
		dc.l	oxFrA_hzalign,oxFr_MIDDLE
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	OX_LABEL,.ex_lab2
		dc.l	TAG_END

.frame3		dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_GNG
		dc.l	oxFrA_fillstyle,oxFr_PEN
		dc.l	oxFrA_hzalign,oxFr_RIGHT
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	OX_LABEL,.ex_lab3
		dc.l	TAG_END

.ex_lab1	dc.l	oxLabA_text,.ex_text1
		dc.l	TAG_END
.ex_lab2	dc.l	oxLabA_text,.ex_text2
		dc.l	TAG_END
.ex_lab3	dc.l	oxLabA_text,.ex_text3
		dc.l	TAG_END

.ex_text1	dc.b	"Page 1",0
.ex_text2	dc.b	"Page 2",0
.ex_text3	dc.b	"Page 3",0
		even

PgSETDEF	;bset	#oxPgB_REDRAW,oxPg_flags(a0)
		lea	oxPg_list(a0),a0
		NEWLIST	a0
		rts

PgDEINIT	move.l	oxPg_list+LH_HEAD(a0),d0
		beq	.rts
		move.l	d0,a2
.del_lp		tst.l	(a2)
		beq.b	.rts

		move.l	oxPN_object(a2),a0
		bsr	_oxFreeObject

		move.l	a2,a0

		move.l	LN_SUCC(a2),a2
		moveq	#oxPN_SIZEOF,d0
		bsr	free_mem
		bra	.del_lp
.rts		rts

PgGETLAYOUT	move.l	a1,a3

		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_propw(a1)

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		lea	oxPg_list(a0),a2
.ask_all_lp	move.l	(a2),a2
		tst.l	(a2)
		beq	.restack

		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_propw(a1)

		move.l	a2,a0
		move.l	oxPN_object(a0),a0
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		move.w	oxLI_minwidth(a1),d0
		cmp.w	oxLI_minwidth(a3),d0
		ble.b	.test_h
		move.w	d0,oxLI_minwidth(a3)

.test_h		move.w	oxLI_minheight(a1),d0
		cmp.w	oxLI_minheight(a3),d0
		ble.b	.merge_prop
		move.w	d0,oxLI_minheight(a3)

.merge_prop	move.l	oxLI_propw(a1),d0
		or.l	d0,oxLI_propw(a3)

		bra.b	.ask_all_lp

.restack	lea	oxLI_SIZEOF(a7),a7
		moveq	#1,d0
		rts

;;;; pointer isle

seglist		dc.l	0	; lib exe segs hunks
libbase		dc.l	0
sysbase		dc.l	0
intbase		dc.l	0
gfxbase		dc.l	0
layersbase	dc.l	0
dosbase		dc.l	0	; for loading classes and evtl logging 
dtbase		dc.l	0
wbbase		dc.l	0
iconbase	dc.l	0

;;;;;;;;;;;;;;;;;;;;;;;;;;; support routines

_oxBevelBorder

_draw_bevel_border	;	a2	pointer to rastport
			;	d0-d3	x1,y1,x2,y2
			;	d4	topleft color
			;	d5	btmright color

			; does remove overlapping of topleft and btmright
			; lines when drawing but overlaps where cannot
			; be seen because of same palette number

		movem.l	a0/a1/a6,-(a7)
		movem.w	d0/d1/d2,-(a7)

		move.l	gfxbase(pc),a6

		; topleft color

		move.w	d4,d0
		moveq	#0,d1
		moveq 	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		; top

		move.w	4(a7),d0	; right-1
		subq.w	#1,d0
		move.w	2(a7),d1	; top
		move.l	a2,a1
		jsr	_LVOMove(a6)
		movem.w	(a7),d0/d1	; left top
		move.l	a2,a1
		jsr	_LVODraw(a6)

		; left

		move.w	(a7),d0
		move.w	d3,d1
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to left bottom

		; bottomright color

		move.w	d5,d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		; bottomleft to bottom right

		movem.w	(a7),d0/d1
		addq.w	#1,d0		; left + 1
		move.w	d3,d1		; bottom
		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	4(a7),d0
		move.w	d3,d1
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to right bottom

		; bottom right to top right

		move.w	4(a7),d0
		move.w	2(a7),d1
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to right top

		movem.w	(a7)+,d0/d1/d2
		movem.l	(a7)+,a0/a1/a6
		rts


_draw_button_hole	;	a2	pointer to rastport
			;	d0-d3	x1,y1,x2,y2
			;	d4	hole color
			;	d6	<>0 is round edges


		movem.l	d7/a0/a1/a6,-(a7)

		moveq	#0,d7
		tst.b	d6
		beq.b	.use
		moveq	#1,d7
.use
		move.l	gfxbase(pc),a6

		movem.w	d0/d1,-(a7)

		; hole color (usually black or very dark)

		push	d2
		move.w	d4,d0
		moveq	#0,d1
		moveq 	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)
		pop	d2

		; top

		move.w	d2,d0		; right
		sub.w	d7,d0		; round right -r
		move.w	2(a7),d1	; top
		move.l	a2,a1
		jsr	_LVOMove(a6)
		movem.w	(a7),d0/d1
		add.w	d7,d0		; round left  +r
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to left+1 top

		; left

		movem.w	(a7),d0/d1
		add.w	d7,d1		; round top+r
		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	(a7),d0
		move.w	d3,d1
		sub.w	d7,d1		; round bottom-r
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to left bottom-r

		; bottom

		move.w	(a7),d0
		add.w	d7,d0		; round left+r
		move.w	d3,d1
		move.l	a2,a1
		jsr	_LVOMove(a6)
		move.w	d2,d0
		sub.w	d7,d0		; round right-r
		move.w	d3,d1
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to right-r bottom

		; right

		move.w	d2,d0
		move.w	d3,d1
		sub.w	d7,d1
		move.l	a2,a1
		jsr	_LVOMove(a6)
		move.w	d2,d0
		move.w	2(a7),d1
		add.w	d7,d1		; round top+r
		move.l	a2,a1
		jsr	_LVODraw(a6)	; to right top+r

		movem.w	(a7)+,d0/d1
		movem.l	(a7)+,d7/a0/a1/a6
		rts

alloc_rem	tst.l	d0
		beq.b	.rts
		addq.l	#4,d0
		movem.l	d1/d2/a0/a1/a6,-(a7)
		move.l	d0,d2
		move.l	#$10001,d1	; MEMF_PUBLIC | MEMF_CLEAR
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		tst.l	d0
		bne.b	.ok

		lea	out_of_memory(pc),a0
		bsr	auto_request
		moveq	#0,d0
		bra	.pop

.ok		move.l	d0,a0
		move.l	d2,(a0)+
		move.l	a0,d0
.pop		movem.l	(a7)+,d1/d2/a0/a1/a6
.rts		rts

out_of_memory	dc.b	"OXMASTER OUT OF MEMORY!",0
		even

alloc_mem	tst.l	d0
		beq.b	.rts
		movem.l	d1-a6,-(a7)
		move.l	#$10001,d1	; MEMF_PUBLIC | MEMF_CLEAR
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		tst.l	d0
		bne.b	.pop

		lea	out_of_memory(pc),a0
		bsr	auto_request
		moveq	#0,d0

.pop		movem.l	(a7)+,d1-a6
.rts		rts

;d0 size
;a0 *Mem            			(ist günstiger als a1)

free_rem	movem.l	d0-a6,-(a7)
		move.l -(a0),d0
		bra.b	fob

free_mem	movem.l	d0-a6,-(a7)
fob		move.l	a0,a1		; aber in a1 wird gebraucht
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)
		movem.l	(a7)+,d0-a6
		rts

;------------------------------
; dez hex val string

;d0	;value
;a0	;*deststring
;>a0	;*behindnewchars

ValToDez:
	movem.l	d1-d4/a1-a2,-(a7)
	push	a0		; Pufferstart merken
	moveq	#10-1,d1	; 10 Stellen (wg. dbf -1)
	lea	divtable(pc),a2	; Divisionstabelle
	move.l	(a2)+,d3	; = 1000000000 f. ersten Durchlauf
	moveq	#0,d2		; Flagge für führende Nullen
.lp1	moveq	#-1,d4		; Zähler für Subtraktionen ohne Überlauf
.2	addq.w	#1,d4		; plus 1 = im Bereich von 0 bis 9
	sub.l	d3,d0		; Subtraktion
	bpl.s	.2		; Solange kein Überlauf (bcc.s)
	add.l	d3,d0		; Negativen (Überlauf!) Wert korrigieren
	move.l	(a2)+,d3	; Neuen Wert aus Tabelle, entspricht d3 / 10
	add.w	#$30,d4		; Nach ASCII wandeln
	tst.w	d2		; Schon Ziffern in Puffer abgelegt?
	bne.b	.4		; Falls ja, auch Nullziffer ablegen
	cmp.b	#"0",d4		; Ist es eine Nullziffer?
	beq.b	.5		; Falls ja, führende Null nicht ablegen
	st	d2		; Sonst Flagge setzen
.4	move.b	d4,(a0)+	; Ziffer ablegen
.5	dbf	d1,.lp1		; Anzahl Stellen
	cmp.l	(a7)+,a0	; Pufferadresse = initiale Adresse?
	bne.b	.pop		; Wenn nicht,
	move.b	#"0",(a0)+	; sonst Nullziffer ablegen (d0 war 0)
.pop
	clr.b	(a0)		; String Terminierung (Puffer muss 11
				; Bytes groß sein)
	movem.l	(a7)+,d1-d4/a1-a2
	rts

divtable
	dc.l	1000000000
	dc.l	100000000
	dc.l	10000000
	dc.l	1000000
	dc.l	100000
	dc.l	10000
	dc.l	1000
	dc.l	100
	dc.l	10
	dc.l	1

;d0.w	;number of chars
;a0	;*string
;>d0	;value

DezToVal:
	movem.l	d1-d3/a0,-(a7)
	lea	(a0,d0.w),a0
	subq.w	#1,d0
	moveq	#1,d2
	moveq	#0,d3
.dv_lp	moveq	#0,d1
	move.b	-(a0),d1
	sub.w	#$30,d1
	mulu.w	d2,d1
	mulu.w	#10,d2
	add.l	d1,d3
	dbf	d0,.dv_lp
	move.l	d3,d0
	movem.l	(a7)+,d1-d3/a0
	rts

ValToHex:
	push	d2
	tst.w	d1
	ble.b	.pop
	ADDA.w	D1,A0		; d0=value / d1=strlen / a0=dest
	SUBQ.w	#1,D1
	clr.b	(a0)		; terminate str
.lp	MOVE.B	D0,D2
	LSR.L	#4,D0
	ANDI.W	#$000F,D2
	MOVE.B	.chars(pc,D2.W),-(A0)
	DBF	D1,.lp
.pop	pop	d2
	RTS
.chars	DC.B	'0123456789ABCDEF'
	even

HexToVal:
	pushm	d1/d2

	subq.w	#1,d0		; d0=len a0=String, zahl to d0
	bge.b	.HZ0
	moveq	#0,d0
	move.b	#"0",(a0)
.HZ0	moveq	#0,d2
.HZ1:	move.b	(a0)+,d1
	sub.b	#$30,d1
	cmp.b	#$A,d1
	blt.s	.HZ2
	subq.b	#7,d1
	and.w	#$f,d1
.HZ2:	lsl.l	#4,d2
	or.b	d1,d2
	dbf	d0,.HZ1
	move.l	d2,d0

	popm	d1/d2
	rts
;------------------------------
; sort list

lh_Head    EQU    0
ln_Succ    EQU    0
ln_Name    EQU    10

;inputs:
; a0 - string 1
; a1 - string 2
strcmp:
  moveq  #0,d0
  moveq  #0,d1
loop1:
  move.b  (a1)+,d1
  move.b  (a0)+,d0
  beq.s  exit1
  cmp.b  d0,d1
  beq.s  loop1
exit1:
  sub.l  d1,d0
  rts

;inputs:
; a0 - pointer to list
countnodes:
  moveq  #-1,d0
  move.l  lh_Head(a0),d1
  beq.s  exit2 ; should never happen
loop2:
  move.l  d1,a0
  addq.l  #1,d0
  move.l  ln_Succ(a0),d1
  bne.s  loop2
exit2:
  rts

;inputs:
; a0 - pointer to list
sortlist:
  movem.l d2-d4/a2-a6,-(a7)
  move.l  4.w,a6
  move.l  a0,a5 ; save list pointer in a5
  bsr    countnodes
  move.l  d0,d2
  move.l  d0,d4
  subq.w  #1,d2
  subq.w  #2,d4
  blt    listempty
loop3:
  move.l  lh_Head(a5),a4
  move.l  d4,d3
loop4:
  move.l  a4,a3
  move.l  ln_Succ(a3),a4
  move.l  ln_Name(a3),a0
  move.l  ln_Name(a4),a1
  bsr    strcmp
  ble.s  dontswap
  move.l  a3,a1
  jsr    _LVORemove(a6)
  move.l  a5,a0
  move.l  a3,a1
  move.l  a4,a2
  jsr    _LVOInsert(a6)
  move.l  a3,a4
dontswap:
  dbra.w  d3,loop4
exit3:
  dbra.w  d2,loop3
listempty:
  movem.l (a7)+,d2-d4/a2-a6
  rts


;-------------------------------------------
; multiply and divide long

; D0 = D0 * D1
_mulu32
    MOVEM.L    D1-D3,-(SP)
    MOVE.W    D1,D2
    MULU.W    D0,D2
    MOVE.L    D1,D3
    SWAP    D3
    MULU.W    D0,D3
    SWAP    D3
    CLR.W    D3
    ADD.L    D3,D2
    SWAP    D0
    MULU.W    D1,D0
    SWAP    D0
    CLR.W    D0
    ADD.L    D2,D0
    MOVEM.L    (SP)+,D1-D3
    RTS

; D0.L = D0.L / D1.L unsigned

_divu32
    MOVEM.L    D1/D2/D3,-(SP)
    SWAP    D1
    TST.W    D1
    BNE.B   .hardldv
    SWAP    D1
    MOVE.W    D1,D3
    MOVE.W    D0,D2
    CLR.W    D0
    SWAP    D0
    DIVU.W    D3,D0
    MOVE.L    D0,D1
    SWAP    D0
    MOVE.W    D2,D1
    DIVU.W    D3,D1
    MOVE.W    D1,D0
    CLR.W    D1
    SWAP    D1
    MOVEM.L    (SP)+,D1/D2/D3
    RTS

.hardldv
    SWAP    D1
    MOVE.L    D1,D3
    MOVE.L    D0,D1
    CLR.W    D1
    SWAP    D1
    SWAP    D0
    CLR.W    D0
    MOVEQ    #16-1,D2
.loop
    ADD.L    D0,D0
    ADDX.L    D1,D1
    CMP.L    D1,D3
    BHI.B    .blah
    SUB.L    D3,D1
    ADDQ.W    #1,D0
.blah
    DBRA    D2,.loop
    MOVEM.L    (SP)+,D1/D2/D3
    RTS




;--------------------------------------------------------------------
; OX_SPACE

 STRUCTURE	oxSpace,oxO_SIZEOF
	UWORD	oxSp_minwidth
	UWORD	oxSp_minheight
	UWORD	oxSp_propw
	UWORD	oxSp_proph
	LABEL	oxSp_SIZEOF


	OXICLASSHEADER	space, 1, 0, button

	dc.l	oxCA_objectsize,oxSp_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
;	dc.l	oxCA_makeexample,.sp_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Space Object can eat up space on the display "
		dc.b	"or add fixed object distances.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	SpSET

		cmp.w	#OXM_SETDEF,d1
		beq.b	SpSETDEF

		cmp.w	#OXM_GETLAYOUT,d1
		beq	SpGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	SpSETLAYOUT

		rts

.sp_create_ex

	rts

SpSET		movem.l	(a1),d0/d1

		cmp.l	#oxA_propw,d0
		bne.b	.if_vprop
		move.w	d1,oxSp_propw(a0)
		rts
.if_vprop	cmp.l	#oxA_proph,d0
		bne.b	.if_minw
		move.w	d1,oxSp_proph(a0)
		rts
.if_minw	cmp.l	#oxA_minwidth,d0
		bne.b	.if_minh
		move.w	d1,oxSp_minwidth(a0)
		rts
.if_minh	cmp.l	#oxA_minheight,d0
		bne.b	.rts
		move.b	d1,oxSp_minheight(a0)

.rts		rts

SpSETDEF	moveq	#-1,d1			; per default eat up all space
		move.l	d1,oxSp_propw(a0)
		rts

SpGETLAYOUT	move.l	oxSp_propw(a0),oxLI_propw(a1)
		move.l	oxSp_minwidth(a0),oxLI_minwidth(a1)

		moveq	#1,d0			; method used
		rts

SpSETLAYOUT	moveq	#1,d0
		rts

;--------------------------------------------------------------------
; OX_BUTTON

 STRUCTURE	oxButton,oxO_SIZEOF
	APTR	oxBtn_text
	UWORD	oxBtn_textlenght
	UBYTE	oxBtn_senschar		; ascii character number to press this button (calc from l...)
	UBYTE	oxBtn_linechar		; number of char in text that should be underlined
	UWORD	oxBtn_left
	UWORD	oxBtn_top
	UWORD	oxBtn_width
	UWORD	oxBtn_height
	UWORD	oxBtn_hprop
	UWORD	oxBtn_vprop
	UWORD	oxBtn_flags
	APTR	oxBtn_hook

	; the part considered to be global / known by class

	UWORD	oxBtn_HorizontalSpacing
	UWORD	oxBtn_VerticalSpacing
	UWORD	oxBtn_ContentLeft		; calculated ...
	UWORD	oxBtn_ContentTop		; calculated ...

	APTR	oxBtn_drawinfo

	APTR	oxBtn_prev		; for auto-linking at creation time
	APTR	oxBtn_next		; for example for switching with tab/shifttab 

	; content cliprect

	; the node text / text calculated part

	UWORD	oxBtn_TextWidth	; calculated
	UWORD	oxBtn_TextHeight	; calculated

	ULONG	oxBtn_coloralloc
	LABEL	oxBtn_pentable
	UBYTE	oxBtn_backpen
	UBYTE	oxBtn_textpen

	LABEL	oxBtn_SIZEOF

	BITDEF	oxBtn,ACTIVE,0
	BITDEF	oxBtn,MOUSEING,1	; button clicked and mouse moving
	BITDEF	oxBtn,GHOSTED,2

 STRUCTURE	buttonbase,0
	UBYTE	btb_flags
	UBYTE	btb_pad
	LABEL	btb_colortable
	ULONG	btb_backcolor
	ULONG	btb_textcolor
	LABEL	btb_SIZEOF

	BITDEF	btb,ROUNDNESS,0

	OXICLASSHEADER	button, 1, 0, radio

	dc.l	oxCA_objectsize,oxBtn_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,btn_create_ex
	dc.l	oxCA_basesize,btb_SIZEOF
	dc.l	oxCA_envarray,.env
	dc.l	TAG_END

.env		dc.l	.roundness,TRUE,0			; name, default, temp
		dc.b	oxET_FLAGBYTE,btbB_ROUNDNESS		; type, flagbit
		dc.w	btb_flags				; offset
		dc.l	.rd_desc				; description

		dc.l	.backcolor,$AAAAAA,0			; name, default
		dc.b	oxET_COLOR,0				; type, flagbit
		dc.w	btb_backcolor				; offset, base
		dc.l	0					; description

		dc.l	.textcolor,$000000,0			; name, default
		dc.b	oxET_COLOR,0				; type, flagbit
		dc.w	btb_textcolor				; offset
		dc.l	0					; description

		dc.l	0	; terminate array

.desc		dc.b	"$VER: ox Button internal class version 1.0",0

.roundness	dc.b	"round edges",0
.rd_desc	dc.b	"Activate this if you want to have round button edges.",0
.backcolor	dc.b	"back color",0
.textcolor	dc.b	"text color",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq	.INTUI

		cmp.w	#OXM_SET,d1
		beq	.SET
		cmp.w	#OXM_GET,d1
		beq	.GET

		cmp.w	#OXM_DRAW,d1
		beq	.DRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	.GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	.SETLAYOUT

		cmp.w	#OXM_DEINIT,d1
		beq	.DEINIT
		cmp.w	#OXM_INIT,d1
		beq	.INIT

		cmp.w	#OXM_ACTIVATE,d1
		beq	.go_active

		cmp.w	#OXM_INACTIVE,d1
		beq	.go_inactive

		cmp.w	#OXM_RELINK,d1
		beq	.RELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	.LINKPRIV

		cmp.w	#OXM_WINDOWCLOSING,d1
		beq.b	.wincl

		cmp.w	#OXM_NEWPENS,d1
		beq	.newpens

.return		rts


.wincl		; set parameters for free_pens

		; d0 numpens, base 0
		; d1 allocmask, each bit 0 to numpens indicates wether
		;    the corresponding color was allocated (TRUE = yes)
		; a0 ox window object
		; a2 pentable

		move.l	oxBtn_coloralloc(a3),d1
		moveq	#1,d0

		move.l	oxBtn_drawinfo(a3),a2
		move.l	oxDI_windowobject(a2),a0

		lea	oxBtn_pentable(a3),a2

		; if no pens allocated this following call does nothing,
		; so it is safe to call it even if alloc_pens was not called before
		; the magic lies in the "coloralloc" ULONG, where each bit tells
		; us wether the corresponding pen (pen 0 = bit 0) has been allocated

		bra	free_pens

.newpens	; free currently allocated pens, if any

		bsr	.wincl

		; set parameters for alloc_pens

		; a0 *oxwin
		; a1 *colortable
		; a2 *pentable	(destination whereto the pens are written)
		; d0 num pens, base 0

		move.l	oxBtn_drawinfo(a3),a2
		move.l	oxDI_windowobject(a2),a0

		push	a3

		lea	btb_colortable(a5),a1
		lea	oxBtn_pentable(a3),a2
		lea	.static(pc),a3
		moveq	#1,d0

		bsr	alloc_pens

		pop	a3

		move.l	d0,oxBtn_coloralloc(a3)

		rts

.static		dc.b	0,1
		even

.go_active	btst	#oxBtnB_GHOSTED,oxBtn_flags+1(a0)
		beq.b	.set_act_mode

		move.l	oxBtn_next(a0),d0
		beq.b	.return_unused

		; activate next

		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bra	_oxDoMethod

.set_act_mode	; set active mode

		bset	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)

		push	a0
		move.l	a0,d1
		move.l	oxBtn_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
.no_dran	pop	a0

		; hilite underline

		bsr	.g_init

		push	a3

		move.b	oxPT_shinepen(a5),d6		; hilitepen
		bsr	.underline

		; draw select-frame

		pop	a3

.draw_sel	move.b	oxPT_cursorpen(a5),d4		; cursorpen
		move.b	d4,d5					; topleft color
		move.w	#%1010101010101010,rp_LinePtrn(a2)

.draw_seldesel	movem.w	oxBtn_left(a3),d0-d3

	;	addq.w	#2,d0
	;	addq.w	#2,d1
	;	subq.w	#5,d2
	;	subq.w	#5,d3

		addq.w	#3,d0
		addq.w	#3,d1
		subq.w	#7,d2
		subq.w	#7,d3

		add.w	d0,d2
		add.w	d1,d3

		bsr	_draw_bevel_border
		move.w	#$FFFF,rp_LinePtrn(a2)

		rts

.go_inactive	; norm underline

		bclr	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)
		beq.b	.return_unused

		bra	.DRAW

		bsr	.g_init

		push	a3

		moveq	#1,d6
		bsr	.underline

		pop	a3

		move.b	oxPT_buttonpen(a5),d4
		move.b	d4,d5

		bra	.draw_seldesel

.g_init		move.l	a0,a3
		move.l	oxBtn_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

		move.l	gfxbase(pc),a6
		move.l	oxBtn_left(a0),d0
		add.l	oxBtn_ContentLeft(a0),d0
		move.w	d0,d1
		swap	d0
		rts

.INTUI		btst	#oxBtnB_GHOSTED,oxBtn_flags+1(a0)
		bne.b	.return_unused

		move.l	oxBtn_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6

		cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq.b	.vkeys

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		beq	.rkeys

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq.b	.buttons

		btw	oxBtnB_MOUSEING,oxBtn_flags(a0)
		beq	.rts

		cmp.l	#IDCMP_MOUSEMOVE,im_Class(a1)
		beq.b	.moved

.buttons	cmp.w	#SELECTDOWN,im_Code(a1)
 		beq.b	.if_inside

		cmp.w	#SELECTUP,im_Code(a1)
		bne	.return

		bra	.released

.rkeys		cmp.w	#$42,im_Code(a1)
		bne	.return_unused

		btst	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)
		beq	.return_unused
	
		move.l	oxBtn_prev(a0),d0
		bra	.nextprev

.vkeys		; enter

		cmp.w	#$d,im_Code(a1)
		beq	.sel_hook

		; active char key

	 	move.b	oxBtn_senschar(a0),d0

		cmp.b	im_Code+1(a1),d0
		bne	.if_is_active

		btw	oxBtnB_ACTIVE,oxBtn_flags(a0)
		bne	.return_unused

		bsr	.go_active
		bra	.return_used

.if_is_active	btw	oxBtnB_ACTIVE,oxBtn_flags(a0)
		beq	.return_unused

		; tab?

		cmp.w	#$9,im_Code(A1)
		bne	.return_unused

		move.l	oxBtn_next(a0),d0

.nextprev	push	d0
		bsr	.go_inactive

		; activate next / prev

		pop	d0
		beq	.return_used
		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod

.return_used	moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts

.if_inside	movem.w	oxBtn_left(a0),d0-d3
		bsr	_is_in_rect
		beq.b	.return			; go_inactive

		; button pressed with mouse

		or.w	#oxBtnF_MOUSEING+oxBtnF_ACTIVE,oxBtn_flags(a0)

		pushm	d0-a6
		bsr	.go_active
		popm	d0-a6

		move.b	oxPT_darkpen(a5),d4		; topleft color
		move.b	oxPT_shinepen(a5),d5		; bottomright color
.draw_border	moveq	#0,d6		; thickness

		movem.w	oxBtn_left(a0),d0-d3

	;	move.l	libbase(pc),a1
	;	btst	#oxBCFB_HOLES,oxB_configflags(a1)
	;	beq.b	.db_nohole

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#2,d2
		subq.w	#2,d3

.db_nohole	subq.w	#1,d2
		subq.w	#1,d3

		add.w	d0,d2
		add.w	d1,d3

		pushm	a0-a6
		bsr	_draw_bevel_border
		popm	a0-a6
		rts

.moved		btw	oxBtnB_MOUSEING,oxBtn_flags(a0)
		beq.b	.return

		movem.w	oxBtn_left(a0),d0-d3
		bsr	_is_in_rect
		bne.b	.inside

		; outside

		move.b	oxPT_shinepen(a5),d4		; topleft color
		move.b	oxPT_darkpen(a5),d5		; bottomright color
		bra.b	.draw_border

.inside		move.b	oxPT_shinepen(a5),d5		; topleft color
		move.b	oxPT_darkpen(a5),d4		; bottomright color


		bra.b	.draw_border

.released	btw	oxBtnB_MOUSEING,oxBtn_flags(a0)
		beq	.return

		move.b	oxPT_shinepen(a5),d4		; topleft color
		move.b	oxPT_darkpen(a5),d5		; bottomright color
		bsr.b	.draw_border

		bclr	#oxBtnB_MOUSEING,oxBtn_flags+1(a0)

		movem.w	oxBtn_left(a0),d0-d3
		bsr	_is_in_rect
		beq	.return

.sel_hook	btst	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)
		beq	.return

		move.l	oxBtn_hook(a0),d0
		beq.b	.return
		move.l	d0,a2
		move.l	libbase(pc),a6
		move.l	oxO_userbase(a0),a4
		jsr	(a2)

		bra.b	.return_used
.DEINIT
.rts5		rts


.LINKPRIV	btst	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)
		beq	.rts5

		move.l	a0,d1
		move.l	oxBtn_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		moveq	#1,d0
		rts


.RELINK		btw	oxBtnB_GHOSTED,oxBtn_flags(a0)
		bne.b	.rts5
		lea	oxBtn_prev(a0),a2

		bra	_ringconnect


		btst	#oxBtnB_ACTIVE,oxBtn_flags+1(a0)
		beq	_ringconnect

		push	a0

		move.l	a0,d1
		move.l	oxBtn_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr

.pop		pop	a0

		bra	_ringconnect

.INIT		move.l	#$00050002,d4
		move.l	d4,oxBtn_HorizontalSpacing(a0)

		moveq	#2,d2
		moveq	#2,d3

		add.w	d4,d3
		swap	d4
		add.w	d4,d2

		movem.w	d2/d3,oxBtn_ContentLeft(a0)

		; calc sensechar

		moveq	#0,d0
		clr.b	oxBtn_senschar(a0)
		move.b	oxBtn_linechar(a0),d0
		beq	.rts_ok
		move.l	oxBtn_text(a0),d1
		beq	.rts_ok
		move.l	d1,a1
		subq.w	#1,d0
		adda.w	d0,a1
		move.b	(a1),oxBtn_senschar(a0)
.rts_ok		moveq	#1,d0
		rts

.SET		movem.l	(a1),d0/d1

		cmp.l	#oxBA_left,d0
		bne	.a
		move.w	d1,oxBtn_left(a0)
		rts
.a		cmp.l	#oxBA_top,d0
		bne	.b
		move.w	d1,oxBtn_top(a0)
		rts
.b		cmp.l	#oxBA_width,d0
		bne	.c
		move.w	d1,oxBtn_width(a0)
		rts
.c		cmp.l	#oxBA_height,d0
		bne	.d
		move.w	d1,oxBtn_height(a0)
		rts
.d		cmp.l	#oxBA_text,d0
		bne	.e
		move.l	d1,oxBtn_text(a0)
		move.l	d1,a1
		moveq	#-1,d0
.len_lp		addq.w	#1,d0
		tst.b	(a1)+
		bne.b	.len_lp
		move.w	d0,oxBtn_textlenght(a0)
		rts
.e		
		
.f		cmp.l	#oxBA_hprop,d0
		bne.b	.g
		move.w	d1,oxBtn_hprop(a0)
		rts
.g		cmp.l	#oxBA_vprop,d0
		bne.b	.h
		move.w	d1,oxBtn_vprop(a0)
		rts
.h		cmp.l	#oxBA_linechar,d0
		bne.b	.sen
		move.b	d1,oxBtn_linechar(a0)
		rts
.sen		cmp.l	#oxBA_senschar,d0
		bne	.i
		move.b	d1,oxBtn_senschar(a0)
		rts
.i		cmp.l	#oxBA_hook,d0
		bne.b	.if_dri
		move.l	d1,oxBtn_hook(a0)
		rts

.if_dri		cmp.l	#oxA_drawinfo,d0
		bne	.if_act
		move.l	d1,oxBtn_drawinfo(a0)
		rts

.if_act		cmp.l	#oxA_active,d0
		bne	.if_prev
		moveq	#oxBtnF_ACTIVE,d0
		bra.b	.flag

.if_prev	cmp.l	#oxA_prev,d0
		bne.b	.if_next
		move.l	d1,oxBtn_prev(a0)

.if_next	cmp.l	#oxA_next,d0
		bne	.if_ghost
		move.l	d1,oxBtn_next(a0)
		rts

.if_ghost	cmp.l	#oxBA_ghosted,d0
		bne.b	.rts
		moveq	#oxBtnF_GHOSTED,d0
		bsr.b	.flag

		move.l	oxBtn_drawinfo(a0),d0
		beq.b	.rts
		move.l	d0,a1
		move.l	oxDI_windowobject(a1),d0

		push	a0

		move.l	d0,a0
		bsr	_oxRelink

		pop	a0

		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a1)
		beq.b	.rts

		bsr	.DRAW

.rts		rts

.flag		tst.w	d1
		beq	.clearflag
		or.w	d0,oxBtn_flags(a0)
		rts

.clearflag	not.w	d0
		and.w	d0,oxBtn_flags(a0)
		rts

.GET
		moveq	#0,d0
		rts

.GETLAYOUT	move.l	oxBtn_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a5
		move.l	a0,a3

		push	a1

		move.w	tf_YSize(a5),oxBtn_TextHeight(a3)

		move.w	oxBtn_textlenght(a3),d0
		move.l	oxBtn_text(a3),a0
		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)

		move.w	d0,oxBtn_TextWidth(a3)

		pop	a1

		; addiere content und rahmen

		move.l	oxBtn_TextWidth(a3),d0	; breite und höhe
		move.l	oxBtn_ContentLeft(a3),d2
		add.l	d2,d0 ; spacing?
		add.l	d2,d0 ; rahmen?

		move.l	oxBtn_hprop(a3),oxLI_propw(a1)
		move.l	d0,oxLI_minwidth(a1)
 
		moveq	#1,d0			; method used
		rts

.SETLAYOUT	move.l	oxLI_width(a1),oxBtn_width(a0)
		move.l	oxLI_left(a1),oxBtn_left(a0)

		; center text in button

		movem.w	oxBtn_width(a0),d2/d3
		movem.w	oxBtn_TextWidth(a0),d4/d5

		sub.w	d4,d2
		sub.w	d5,d3

		asr.w	#1,d2
		asr.w	#1,d3

		movem.w	d2/d3,oxBtn_ContentLeft(a0)

		moveq	#1,d0
		rts

.DRAW		move.l	a5,a4	; base

		move.l	oxBtn_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

		move.l	a0,a3		; object

		; draw button

		movem.w	oxBtn_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		move.l	gfxbase(pc),a6

		movem.w	d0-d3,-(a7)

		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.penfill

		move.l	oxBtn_drawinfo(a3),d0
		beq.b	.penfill

		move.l	d0,a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_buttonbgimage(a0),d0
		beq.b	.penfill

		move.l	d0,a0

		move.l	oxBtn_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		movem.w	oxBtn_left(a3),d0-d3

		addq.w	#2,d0
		addq.w	#2,d1

		add.w	d0,d2
		add.w	d1,d3

		subq.w	#5,d2
		subq.w	#5,d3

		move.w	d0,d4
		move.w	d1,d5

		bsr	_oxImageFill

		bra.b	.hole

.penfill	move.b	oxPT_buttonpen(a5),d0

	move.b	oxBtn_backpen(a3),d0

		move.l	a2,a1
		jsr	_LVOSetAPen(a6)
		movem.w	(a7),d0/d1
		addq.w	#2,d0		; avoid fill round edges
		addq.w	#2,d1
		subq.w	#2,d2
		subq.w	#2,d3

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		move.l	libbase(pc),a0
	;	btst	#oxBB_HOLES,oxB_configflags(a0)
	;	beq.b	.nohole

.hole		movem.w	(a7),d0-d3

		; hole

		move.b	oxPT_blackpen(a5),d4	; hole color

		move.l	libbase(pc),a0
		btst	#btbB_ROUNDNESS,btb_flags(a4)
		sne	d6
		bsr	_draw_button_hole

.nohole		movem.w	(a7)+,d0-d3

		; Bevel Border

		addq.w	#1,d1
		subq.w	#1,d3
		addq.w	#1,d0
		subq.w	#1,d2

		move.b	oxPT_shinepen(a5),d4		; topleft color
		move.b	oxPT_darkpen(a5),d5		; bottomright color

		bsr	_draw_bevel_border

		; Text

		movem.w	oxBtn_left(a3),d0/d1
		move.l	oxBtn_ContentLeft(a3),d2
		add.w	d2,d1
		swap	d2
		add.w	d2,d0

		movem.w	d0/d1,-(a7)

		add.w	rp_TxBaseline(a2),d1
		move.l	a2,a1
		jsr	_LVOMove(a6)

	;	move.b	oxPT_textpen(a5),d0

		move.b	oxBtn_textpen(a3),d0

		moveq	#0,d1
		moveq	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		move.l	oxBtn_text(a3),a0
		move.w	oxBtn_textlenght(a3),d0
		move.l	a2,a1
		jsr	_LVOText(a6)	

		; underline a char

		movem.w	(A7)+,d0/d1

		move.b	oxPT_textpen(a5),d6

		bsr	.underline

		btst	#oxBtnB_ACTIVE,oxBtn_flags+1(a3)
		beq.b	.d_gho
		bsr	.draw_sel
		bra.b	.d_gho

;.d_desel	move.b	oxPT_buttonpen(a5),d4
;		move.b	d4,d5
;		bsr	.draw_seldesel
.d_gho		bra	.ghosted


.underline	move.w	oxBtn_flags(a3),d2

		push	a3

		moveq	#0,d5
		move.b	oxBtn_linechar(a3),d5
		move.l	oxBtn_text(a3),a3

		btst	#oxBtnB_ACTIVE,d2
		bne	.white_under
		bra	.under

.white_under	move.b	oxPT_shinepen(a5),d6
.under		bsr	_underline_char

		pop	a3

		moveq	#0,d0
		rts

.ghosted	; if GHOSTED

		btst	#oxBtnB_GHOSTED,oxBtn_flags+1(a3)
		beq.b	.rts4

		lea	ghostpattern(pc),a4
		move.w	(a4)+,d0
		move.b	d0,rp_AreaPtSz(a2)
		move.b	(a4)+,d0
		move.b	oxPT_blackpen(a5),d0
		moveq	#0,d1
		move.b	(a4)+,d1
		moveq 	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		move.l	a4,rp_AreaPtrn(a2)

		movem.w	oxBtn_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		add.w	#3,d0
		add.w	#3,d1
		subq.w	#4,d2
		subq.w	#4,d3

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

.rts4		moveq	#0,d0
		rts

ghostpattern	dc.w	1
		dc.b	1,0		; Farben f,b

		dc.w	%1000100010001000
		dc.w	%0010001000100010

; make tab-chains

_oxRingConnect
_ringconnect	pushm	d0/d1/a0
		move.l	oxRL_first(a1),4(a2)		; first -> _next
		bne.b	.has_first
		move.l	a0,oxRL_first(a1)
		move.l	a0,oxRL_last(a1)
		bra.b	.get_regs_back

.has_first	move.l	oxRL_last(a1),(a2)		; last -> _prev
		move.l	a0,d1

		;  this --> next in last

		move.l	oxRL_last(a1),a0
		move.l	#oxA_next,d0
		bsr	_oxSetAttr

		; this --> prev in first

		move.l	oxRL_first(a1),a0
		move.l	#oxA_prev,d0
		bsr	_oxSetAttr

		move.l	d1,oxRL_last(a1)
.get_regs_back	popm	d0/d1/a0
		rts

btn_create_ex	lea	btn_example(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

btn_example	dc.l	OX_BUTTON,.button
		dc.l	OX_BUTTON,.button
		dc.l	TAG_END

.button		dc.l	oxBA_text,.text
		dc.l	oxBA_linechar,2
		dc.l	TAG_END
.text		dc.b	"example button",0
		even

;--------------------------------------------------------------------
; OX_RADIO

 STRUCTURE	oxRadio,oxO_SIZEOF
	UBYTE	oxRad_senschar
	UBYTE	oxRad_flags
	UWORD	oxRad_left
	UWORD	oxRad_top

	APTR	oxRad_hook
	UWORD	oxRad_groupid		; same IDs share one may be pressed
	APTR	oxRad_shared		; pointer to pointer to active radio

	APTR	oxRad_drawinfo

	APTR	oxRad_prev		; for auto-linking at creation time
	APTR	oxRad_next		; for example for switching with tab/shifttab 

	LABEL	oxRad_SIZEOF

	BITDEF	oxRad,ACTIVE,0
	BITDEF	oxRad,SELECTED,1

 STRUCTURE	oxRadGroup,MLN_SIZE
		APTR	oxRG_windowobj
		UWORD	oxRG_ID
		UWORD	oxRG_users
		APTR	oxRG_shared
		LABEL	oxRG_SIZEOF

 STRUCTURE	radiobase,0
	APTR	rb_icon
	LABEL	rb_SIZEOF

	OXICLASSHEADER	radio, 1, 0, check

	dc.l	oxCA_objectsize,oxRad_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,rad_create_ex
	dc.l	oxCA_initclass,.initclass
	dc.l	oxCA_deinitclass,.deinitclass
	dc.l	oxCA_basesize,rb_SIZEOF
	dc.l	TAG_END

.desc		dc.b	"$VER: ox Radio Button 1.0",$a
		dc.b	"internal class by A.Szabo",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq	RadINTUI

		cmp.w	#OXM_SET,d1
		beq	RadSET

;		cmp.w	#OXM_GET,d1
;		beq	.GET

		cmp.w	#OXM_DRAW,d1
		beq	RadDRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	RadGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	RadSETLAYOUT

		cmp.w	#OXM_DEINIT,d1
		beq	RadDEINIT

		cmp.w	#OXM_INIT,d1
		beq	RadINIT

		cmp.w	#OXM_ACTIVATE,d1
		beq	rad_go_active

		cmp.w	#OXM_INACTIVE,d1
		beq	rad_go_inactive

		cmp.w	#OXM_RELINK,d1
		beq.b	RadRELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq.b	RadLINKPRIV

		cmp.w	#OXM_NEWPENS,d1
		beq.b	.pens

.return		rts

.initclass	lea	groupslist(pc),a0
		NEWLIST	a0

		; get radio selected symbol

		lea	.radioname(pc),a0
		bsr	_oxGetIcon
		move.l	d0,rb_icon(a5)

		moveq	#1,d0
.rts		rts

.radioname	dc.b	"radio",0
		even

.deinitclass	move.l	rb_icon(a5),d0
		beq	.rts
		move.l	d0,a0
		bra	_oxDropIcon

.pens	; hack,not working with multiple screens that have ther own pens !!

		lea	radio_border,a0
		move.b	oxPT_blackpen(a1),4(a0)
		move.l	12(a0),a0
		move.b	oxPT_shinepen(a1),4(a0)
		move.l	12(a0),a0
		move.b	oxPT_darkpen(a1),4(a0)
		lea	radio_border_p,a0
		move.b	oxPT_blackpen(a1),4(a0)
		move.l	12(a0),a0
		move.b	oxPT_darkpen(a1),4(a0)
		move.l	12(a0),a0
		move.b	oxPT_shinepen(a1),4(a0)
		rts

groupslist	dc.l	0,0,0

RadINIT		move.l	a0,a3

		tst.l	oxRad_drawinfo(a3)		; kommt nicht wenn auf hinterem tab
		beq.b	.rts_nix

		lea	groupslist(pc),a0
		move.w	oxRad_groupid(a3),d1
		beq.b	.rts_ok

		move.l	oxRad_drawinfo(a3),a1
		move.l	oxDI_windowobject(a1),d2

		move.l	a0,a1

.next		move.l	(a1),a1
		tst.l	(a1)
		beq.b	.new

		cmp.w	oxRG_ID(a1),d1
		bne.b	.next

		cmp.l	oxRG_windowobj(a1),d2
		bne.b	.next

		addq.w	#1,oxRG_users(a1)

		bra.b	.setme

.new		moveq	#oxRG_SIZEOF,d0
		bsr	alloc_mem
		beq.b	.rts_fail
		move.l	d0,a1
		move.w	#1,oxRG_users(a1)
		move.w	d1,oxRG_ID(a1)
		move.l	d2,oxRG_windowobj(a1)

		ADDTAIL

.setme		lea	oxRG_shared(a1),a0
		move.l	a0,oxRad_shared(a3)

		btst	#oxRadB_SELECTED,oxRad_flags(a3)
		beq.b	.rts_ok
		move.l	a3,oxRG_shared(a1)

.rts_ok		moveq	#1,d0
		rts
.rts_fail	moveq	#-1,d0
		rts
.rts_nix	moveq	#0,d0
		rts

RadDEINIT	move.l	oxRad_shared(a0),d0
		beq.b	.rts

		move.l	d0,a1
		lea	-oxRG_shared(a1),a1

		subq.w	#1,oxRG_users(a1)
		bne.b	.rts

		push 	a1
		REMOVE
		pop	a0

		moveq	#oxRG_SIZEOF,d0
		bra	free_mem

.rts		rts

RadINTUI	cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq.b	.vkeys

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		beq	.rkeys

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		bne.b	rad_unused

		cmp.w	#SELECTDOWN,im_Code(a1)
 		bne	rad_unused

		movem.w	oxRad_left(a0),d0/d1
		moveq	#17,d2
		moveq	#17,d3
		bsr	_is_in_rect
		beq	rad_unused

.select		bsr	rad_go_active			;  could make this configurable

; .select   war hier
		bset	#oxRadB_SELECTED,oxRad_flags(a0)
		bne	rad_unused
		move.l	oxRad_shared(a0),d0
		beq	.rad_redraw
		move.l	d0,a1
		move.l	(a1),d0
		beq	.rad_redraw_set
		cmp.l	d0,a0
		beq	rad_used
		pushm	a0/a1
		move.l	d0,a0
		bclr	#oxRadB_SELECTED,oxRad_flags(a0)
		bsr	RadDRAW				; draw previously selected radio in off-mode
		popm	a0/a1
.rad_redraw_set	move.l	a0,(a1)
.rad_redraw	bsr	RadDRAW				; draw newly selected radio in on-mode
							; (does copy a0 to a3)
		move.l	oxRad_hook(a3),d0
		beq	rad_used
		move.l	d0,a2
		move.l	libbase(pc),a6
		move.l	oxO_userbase(a3),a4
		jsr	(a2)
		bra	rad_used

.vkeys		move.w	im_Code(a1),d1
		cmp.b	oxRad_senschar(a0),d1
		beq.b	.select

		btst	#oxRadB_ACTIVE,oxRad_flags(a0)
		beq.b	rad_unused

		cmp.b	#$20,d1
		beq.b	.select

		cmp.b	#9,d1			; tab
		bne.b	rad_unused

		move.l	oxRad_next(a0),d0
.activate_np	beq.b	rad_unused

		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod
		bra.b	rad_used

.rkeys		cmp.b	#$42,im_Code+1(a1)
		bne.b	rad_unused

		btst	#oxRadB_ACTIVE,oxRad_flags(a0)
		beq	rad_unused
	
		move.l	oxRad_prev(a0),d0
		bra.b	.activate_np

rad_used	moveq	#1,d0
		rts
rad_unused	moveq	#0,d0
		rts

rad_go_inactive	bclr	#oxRadB_ACTIVE,oxRad_flags(a0)
		beq.b	rad_unused
		bsr	RadDRAW
		bra.b	rad_used

rad_go_active	bset	#oxRadB_ACTIVE,oxRad_flags(a0)
		bne.b	rad_unused

		push	a0
		move.l	a0,d1
		move.l	oxRad_drawinfo(a0),d0
		beq.b	.no_dran
		move.l	d0,a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
.no_dran	move.l	(a7),a0

		bsr	RadDRAW
		pop	a0
		bra.b	rad_used

RadRELINK	lea	oxRad_prev(a0),a2
		bra	_ringconnect

RadLINKPRIV	btst	#oxRadB_ACTIVE,oxRad_flags(a0)
		beq	.rts

		move.l	a0,d1
		move.l	oxRad_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		moveq	#1,d0
.rts		rts

RadSET		movem.l	(a1),d0/d1
		cmp.l	#oxRadA_groupid,d0
		bne.b	.sc
		move.w	d1,oxRad_groupid(a0)
		rts
.sc		cmp.l	#oxRadA_senschar,d0
		bne	.i
		move.b	d1,oxRad_senschar(a0)
		rts
.i		cmp.l	#oxRadA_hook,d0
		bne.b	.if_di
		move.l	d1,oxRad_hook(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.if_act
		move.l	d1,oxRad_drawinfo(a0)
		rts
.if_act		cmp.l	#oxA_active,d0
		bne	.if_sel
		or.b	#oxRadF_ACTIVE,oxRad_flags(a0)
		rts

.if_sel		cmp.l	#oxA_selected,d0
		bne	.if_prev
		or.b	#oxRadF_SELECTED,oxRad_flags(a0)
		rts

.if_prev	cmp.l	#oxA_prev,d0
		bne.b	.if_next
		move.l	d1,oxRad_prev(a0)
		rts

.if_next	cmp.l	#oxA_next,d0
		bne	.rts
		move.l	d1,oxRad_next(a0)

.rts		rts


RadDRAW		; draw radiobutton

		move.l	a0,a3
		move.l	oxRad_drawinfo(a3),a2
		move.l	oxDI_pentable(a2),a4
		move.l	oxDI_rastport(a2),a2

		move.l	gfxbase(pc),a6

		moveq 	#RP_JAM2,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		move.l	a2,a1
		move.b	oxPT_buttonpen(a4),d0
		jsr	_LVOSetAPen(a6)

		movem.w	oxRad_left(a3),d0/d1
		move.w	d0,d2
		move.w	d1,d3
		addq.w	#2,d0
		addq.w	#2,d1
		add.w	#12,d2
		add.w	#12,d3
		move.l	a2,a1
		jsr	_LVORectFill(a6)

		btst	#oxRadB_SELECTED,oxRad_flags(a3)
		beq.b	.draw_border

.draw_image	move.l	rb_icon(a5),d0
		beq	.draw_border
		move.l	d0,a0
		movem.w	oxRad_left(a3),d0/d1
		addq.w	#2,d0
		addq.w	#2,d1
		moveq	#FALSE,d2	; not selected
		move.l	a2,a1
		bsr	_oxDrawIcon

.draw_border	move.l	intbase(pc),a6

		move.l	a2,a0
		lea	radio_border,a1

		btst	#oxRadB_SELECTED,oxRad_flags(a3)
		beq.b	.db

		lea	radio_border_p,a1

.db		movem.w	oxRad_left(a3),d0/d1
		jsr	_LVODrawBorder(a6)

		btst	#oxRadB_ACTIVE,oxRad_flags(a3)
		beq.b	.clr_sel

		move.b	oxPT_cursorpen(a4),d4			; topleft color
		move.b	d4,d5					; bottomright color
		move.w	#%1010101010101010,rp_LinePtrn(a2)

		bra.b	.draw_seldesel

.clr_sel	move.b	oxPT_buttonpen(a4),d4			; topleft color
		move.b	d4,d5

.draw_seldesel	move.l	gfxbase(pc),a6

		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		movem.w	oxRad_left(a3),d0/d1

		addq.w	#3,d0
		addq.w	#3,d1
		move.w	d0,d2
		move.w	d1,d3
		addq.w	#8,d2
		addq.w	#8,d3

		bsr	_draw_bevel_border
		move.w	#$FFFF,rp_LinePtrn(a2)

		moveq	#0,d0
		rts

RadGETLAYOUT	move.l	oxRad_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.w	rp_TxHeight(a2),d1		; fonthöhe plus
		addq.w	#8,d1				; obre und unter ränder
		moveq	#15,d0
		movem.w	d0/d1,oxLI_minwidth(a1)
		moveq	#1,d0
		rts

RadSETLAYOUT	move.l	oxLI_left(a1),oxRad_left(a0)
		move.w	oxLI_height(a1),d0
		sub.w	#15,d0
		asr.w	#1,d0
		add.w	d0,oxRad_top(a0)
		moveq	#1,d0
		rts

rad_create_ex	lea	example_radios(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

example_radios	; (horizgroup)
		dc.l	OX_VERTGROUP,.radios
		dc.l	OX_VERTGROUP,.labels
		dc.l	oxGA_vprop,0
		dc.l	oxGA_hprop,0
		dc.l	TAG_END
.radios		dc.l	OX_RADIO,.rad1
		dc.l	OX_RADIO,.rad2
		dc.l	OX_RADIO,.rad3
		dc.l	oxGA_minspace,0
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.labels		dc.l	OX_LABEL,.lab1
		dc.l	OX_LABEL,.lab2
		dc.l	OX_LABEL,.lab3
		dc.l	oxGA_minspace,0
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.rad1		dc.l	oxRadA_senschar,"a"
	;	dc.l	oxA_selected,1			; 0 geht zur zeit nicht (tag ganz weglasse)
		dc.l	oxRadA_groupid,1
		dc.l	TAG_END
.lab1		dc.l	oxLabA_text,.tex1
		dc.l	oxLabA_linechar,15
		dc.l	TAG_END
.tex1		dc.b	"select option a",0
		even

.rad2		dc.l	oxRadA_senschar,"b"
		dc.l	oxRadA_groupid,1
		dc.l	TAG_END
.lab2		dc.l	oxLabA_text,.tex2
		dc.l	oxLabA_linechar,8
		dc.l	TAG_END
.tex2		dc.b	"option b",0
		even

.rad3		dc.l	oxRadA_senschar,"c"
		dc.l	oxRadA_groupid,1
		dc.l	oxA_selected,1			; 0 geht zur zeit nicht
		dc.l	TAG_END
.lab3		dc.l	oxLabA_text,.tex3
		dc.l	oxLabA_linechar,11
		dc.l	TAG_END
.tex3		dc.b	"or option c",0
		even

;--------------------------------------------------------------------
; OX_CHECK

 STRUCTURE	oxCheck,oxO_SIZEOF
	UBYTE	oxChk_senschar
	UBYTE	oxChk_flags
	UWORD	oxChk_left
	UWORD	oxChk_top

	APTR	oxChk_hook

	APTR	oxChk_drawinfo

	APTR	oxChk_prev		; for auto-linking at creation time
	APTR	oxChk_next		; for example for switching with tab/shifttab 

	LABEL	oxChk_SIZEOF

	BITDEF	oxChk,ACTIVE,0
	BITDEF	oxChk,SELECTED,1

 STRUCTURE	checkbase,0
	APTR	cb_icon
	LABEL	cb_SIZEOF

	OXICLASSHEADER	check, 1, 0, string

	dc.l	oxCA_objectsize,oxChk_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,chk_create_ex
	dc.l	oxCA_initclass,.initclass
	dc.l	oxCA_deinitclass,.deinitclass
	dc.l	oxCA_basesize,cb_SIZEOF
	dc.l	TAG_END

.desc		dc.b	"$VER: Check-Mark 1.0",$a
		dc.b	"ox internal class by A. Szabo",0
		even

.dispatcher
		cmp.w	#OXM_INTUIMESSAGE,d1
		beq	ChkINTUI

		cmp.w	#OXM_SET,d1
		beq	ChkSET

		cmp.w	#OXM_GET,d1
		beq	ChkGET

		cmp.w	#OXM_DRAW,d1
		beq	ChkDRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	ChkGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	ChkSETLAYOUT

		cmp.w	#OXM_INIT,d1
		beq	ChkINIT

		cmp.w	#OXM_ACTIVATE,d1
		beq	go_active

		cmp.w	#OXM_INACTIVE,d1
		beq	go_inactive

		cmp.w	#OXM_RELINK,d1
		beq.b	ChkRELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	ChkLINKPRIV

		rts

.initclass	; get check selected symbol

		lea	.checkname(pc),a0
		bsr	_oxGetIcon
		move.l	d0,cb_icon(a5)

		moveq	#1,d0
.rts		rts

.checkname	dc.b	"check",0
		even

.deinitclass	move.l	cb_icon(a5),d0
		beq	.rts
		move.l	d0,a0
		bra	_oxDropIcon

ChkINTUI	cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq.b	.vkeys

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		beq	.rkeys

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		bne.b	unused

		cmp.w	#SELECTDOWN,im_Code(a1)
 		bne.b	unused

		movem.w	oxChk_left(a0),d0/d1
		moveq	#17,d2
		moveq	#17,d3
		bsr	_is_in_rect
		beq.b	unused

		bsr	go_active			;  could make this configurable

.toggle		moveq	#0,d0
		bchg	#oxChkB_SELECTED,oxChk_flags(a0)
		seq	d0

		pushm	d0/a0

		bsr	ChkDRAW

		popm	d0/a0

		move.l	oxChk_hook(a0),d1
		beq.b	used

		push	a6

		move.l	libbase(pc),a6

		move.l	d1,a2
		move.l	a0,a3
		jsr	(a2)

		pop	a6

		bra.b	used

.vkeys		move.w	im_Code(a1),d1
		cmp.b	oxChk_senschar(a0),d1
		beq.b	.toggle

		btst	#oxChkB_ACTIVE,oxChk_flags(a0)
		beq.b	unused

		cmp.b	#$20,d1
		beq.b	.toggle

		cmp.b	#9,d1			; tab
		bne.b	unused

		move.l	oxChk_next(a0),d0
.activate_next	beq.b	unused

		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod
		bra.b	used

.rkeys		cmp.b	#$42,im_Code+1(a1)
		bne.b	unused

		btst	#oxChkB_ACTIVE,oxChk_flags(a0)
		beq	unused
	
		move.l	oxChk_prev(a0),d0
		bra.b	.activate_next

used		moveq	#1,d0
		rts
unused		moveq	#0,d0
		rts

go_inactive	bclr	#oxChkB_ACTIVE,oxChk_flags(a0)
		beq.b	unused
		bsr	ChkDRAW
		bra.b	used

go_active	bset	#oxChkB_ACTIVE,oxChk_flags(a0)
		bne.b	unused

		push	a0
		move.l	a0,d1
		move.l	oxChk_drawinfo(a0),d0
		beq.b	.no_dran
		move.l	d0,a1
		move.l	oxDI_windowobject(a1),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
.no_dran	move.l	(a7),a0

		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a1)
		beq.b	used
		bsr	ChkDRAW
		pop	a0
		bra.b	used

ChkLINKPRIV	btst	#oxChkB_ACTIVE,oxChk_flags(a0)
		beq	.rts

		move.l	a0,d1
		move.l	oxChk_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		moveq	#1,d0
.rts		rts

ChkRELINK	lea	oxChk_prev(a0),a2
		bra	_ringconnect

ChkINIT		rts

ChkSET		movem.l	(a1),d0/d1
		cmp.l	#oxChkA_senschar,d0
		bne	.i
		move.b	d1,oxChk_senschar(a0)
		rts
.i		cmp.l	#oxChkA_hook,d0
		bne.b	.if_di
		move.l	d1,oxChk_hook(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.if_act
		move.l	d1,oxChk_drawinfo(a0)
		rts
.if_act		cmp.l	#oxA_active,d0
		bne	.if_sel
		or.b	#oxChkF_ACTIVE,oxChk_flags(a0)
		rts

.if_sel		cmp.l	#oxA_selected,d0
		bne	.if_prev
		moveq	#oxChkF_SELECTED,d0
		bra.b	.flag

.if_prev	cmp.l	#oxA_prev,d0
		bne.b	.if_next
		move.l	d1,oxChk_prev(a0)
		rts

.if_next	cmp.l	#oxA_next,d0
		bne	.rts
		move.l	d1,oxChk_next(a0)

.rts		rts

.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxChk_flags(a0)
		rts

.clearflag	not.w	d0
		and.b	d0,oxChk_flags(a0)
		rts


ChkGET		move.l	(a1),d2
		cmp.l	#oxA_selected,d2
		bne.b	.rts
		btst	#oxChkB_SELECTED,oxChk_flags(a0)
		sne	d0
.rts		rts

ChkDRAW		; draw checkbox

		move.l	a0,a3
		move.l	oxChk_drawinfo(a3),a2
		move.l	oxDI_pentable(a2),a4
		move.l	oxDI_rastport(a2),a2

		move.l	gfxbase(pc),a6

		movem.w	oxChk_left(a3),d0/d1
		move.w	d0,d2
		move.w	d1,d3
		add.w	#16,d2
		add.w	#16,d3

		move.b	oxPT_darkpen(a4),d4
		move.b	oxPT_shinepen(a4),d5

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.b	oxPT_blackpen(a4),d4
		move.b	d4,d5

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1

		pushm	d0/d1

		move.l	a2,a1

		move.b	oxPT_buttonpen(a4),d0
		jsr	_LVOSetAPen(a6)

		popm	d0/d1

		subq.w	#1,d2
		subq.w	#1,d3

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		btst	#oxChkB_SELECTED,oxChk_flags(a3)
		beq.b	.if_active

.draw_image	move.l	cb_icon(a5),d0
		beq	.if_active
		move.l	d0,a0
		movem.w	oxChk_left(a3),d0/d1
		addq.w	#2,d0
		addq.w	#2,d1
		moveq	#FALSE,d2	; not selected
		move.l	a2,a1
		bsr	_oxDrawIcon

.if_active	btst	#oxChkB_ACTIVE,oxChk_flags(a3)
		beq.b	.rts

		move.b	oxPT_cursorpen(a4),d4
		move.b	d4,d5
		move.w	#%1010101010101010,rp_LinePtrn(a2)

		move.l	gfxbase(pc),a6

		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		movem.w	oxChk_left(a3),d0/d1

		addq.w	#2,d0
		addq.w	#2,d1
		move.w	d0,d2
		move.w	d1,d3
		add.w	#12,d2
		add.w	#12,d3

		bsr	_draw_bevel_border
		move.w	#$FFFF,rp_LinePtrn(a2)

.rts		moveq	#0,d0
		rts

ChkGETLAYOUT	move.l	oxChk_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.w	rp_TxHeight(a2),d1		; fonthöhe plus
		addq.w	#8,d1				; obre und unter ränder
		moveq	#17,d0
		movem.w	d0/d1,oxLI_minwidth(a1)
		moveq	#1,d0
		rts

ChkSETLAYOUT	move.l	oxLI_left(a1),oxChk_left(a0)
		move.w	oxLI_height(a1),d0
		sub.w	#17,d0
		asr.w	#1,d0
		add.w	d0,oxChk_top(a0)		; obere ränder, soll mal y-centr werden
		moveq	#1,d0
		rts

chk_create_ex	lea	example_checks(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

example_checks	; (horizgroup)
		dc.l	OX_VERTGROUP,.checks
		dc.l	OX_VERTGROUP,.labels
		dc.l	TAG_END
.checks		dc.l	OX_CHECK,.chk1
		dc.l	OX_CHECK,.chk2
		dc.l	OX_CHECK,.chk3
		dc.l	oxGA_minspace,0
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.labels		dc.l	OX_LABEL,.lab1
		dc.l	OX_LABEL,.lab2
		dc.l	OX_LABEL,.lab3
		dc.l	oxGA_minspace,0
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.chk1		dc.l	oxChkA_senschar,"a"
		dc.l	oxA_selected,1
		dc.l	TAG_END
.lab1		dc.l	oxLabA_text,.tex1
		dc.l	oxLabA_linechar,16
		dc.l	TAG_END
.tex1		dc.b	"this is option a",0
		even

.chk2		dc.l	oxChkA_senschar,"b"
		dc.l	TAG_END
.lab2		dc.l	oxLabA_text,.tex2
		dc.l	oxLabA_linechar,8
		dc.l	TAG_END
.tex2		dc.b	"option b",0
		even

.chk3		dc.l	oxChkA_senschar,"c"
	;	dc.l	oxA_active,-1
		dc.l	TAG_END
.lab3		dc.l	oxLabA_text,.tex3
		dc.l	oxLabA_linechar,12
		dc.l	TAG_END
.tex3		dc.b	"and option c",0
		even

;--------------------------------------------------------------------
; OX_STRING

 STRUCTURE	oxString,oxO_SIZEOF
	UWORD	oxS_minwidth	; in pixel
	APTR	oxS_string	; buffer
	APTR	oxS_deftext
	UWORD	oxS_lenght	; in chars
	UWORD	oxS_maxlenght	; of buffer in chars
	UWORD	oxS_offset
	UWORD	oxS_inpos
	UWORD	oxS_oldinpos
	UWORD	oxS_visiblechars
	UWORD	oxS_left
	UWORD	oxS_top
	UWORD	oxS_width
	UWORD	oxS_height
	UWORD	oxS_prop

	UWORD	oxS_horizontalspacing
	UWORD	oxS_verticalspacing
	UBYTE	oxS_flags
	UBYTE	oxS_senschar

	APTR	oxS_enterobject
	APTR	oxS_hook
	APTR	oxS_drawinfo

	APTR	oxS_prev		; for auto-linking at creation time
	APTR	oxS_next		; for example for switching with tab/shifttab 

	ULONG	oxS_value	; for hex/dez operating modes
	ULONG	oxS_minval
	ULONG	oxS_maxval

	; content cliprect

	LABEL	oxS_SIZEOF

	BITDEF	oxS,FRONT,6
	BITDEF	oxS,ACTIVE,7		; other (public) flags defined in ox.i


oxS_DEFAULTMAXLENGHT	EQU	50


	OXICLASSHEADER	string, 0, 4, label

	dc.l	oxCA_objectsize,oxS_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,str_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: ox String Input internal class version 0.4",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq	.INTUI

		cmp.w	#OXM_SET,d1
		beq	oxS_SET
	
		cmp.w	#OXM_GET,d1
		beq	oxS_GET

		cmp.w	#OXM_DRAW,d1
		beq	.oxS_DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	.oxS_UPDATE

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxS_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxS_SETLAYOUT

		cmp.w	#OXM_DEINIT,d1
		beq	S_DEINIT

		cmp.w	#OXM_INIT,d1
		beq	S_INIT

		cmp.w	#OXM_SETDEF,d1
		beq	S_SETDEF

		cmp.w	#OXM_ACTIVATE,d1
		beq	.go_active

		cmp.w	#OXM_INACTIVE,d1
		beq	.go_inactive

		cmp.w	#OXM_RELINK,d1
		beq	.RELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	.LINKPRIV

		cmp.w	#OXM_FRONT,d1
		beq.b	.FRONT

		cmp.w	#OXM_BACK,d1
		beq.b	.BACK

		cmp.w	#OXM_WINDOWOPEN,d1
		beq.b	.winopen

.return		rts

.FRONT		bset	#oxSB_FRONT,oxS_flags(a0)
		rts

.BACK		bclr	#oxSB_FRONT,oxS_flags(a0)
		rts

.LINKPRIV	btst	#oxSB_ACTIVE,oxS_flags(a0)
		beq	.rts	; d0 allready null set from DoMethod

		move.l	a0,d1
		move.l	oxS_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		moveq	#1,d0
.rts		rts

.RELINK		lea	oxS_prev(a0),a2
		bra	_ringconnect

.winopen	move.l	a0,a3
		bsr	oxS_vischars
		move.w	d6,oxS_visiblechars(A3)
		rts

.oxS_UPDATE	move.l	a0,a3
		bsr	oxS_vischars
		move.w	d6,oxS_visiblechars(A3)

		btst	#oxSB_DEZ,oxS_flags(a3)
		bne.b	.range
		btst	#oxSB_HEX,oxS_flags(a3)
		beq.b	.test
.range		move.l	oxS_value(a3),d0
		bsr.b	s_hexdezcalc

.test		; test for refresh

		move.l	oxS_drawinfo(a3),d0
		beq	.rts
		move.l	d0,a0
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a0)
		beq	.rts

		btst	#oxSB_FRONT,oxS_flags(a3)
		beq	.rts

		move.l	oxS_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6

		bra.b	s_drawinact

.oxS_DRAW	movem.w	oxS_left(a0),d0-d3

		move.l	oxS_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2
		bsr	_in_frame

		move.w	oxS_visiblechars(a3),d6

		move.b	oxPT_inputtextpen(a5),d4
		move.b	oxPT_inputpen(a5),d5

		move.l	oxS_string(a3),a4
		bsr	oxS_print

		; redraw cursor after window update zB resize

 		btst	#oxSB_ACTIVE,oxS_flags(a3)
		bne	.set_cursor

		moveq	#0,d0
		rts

.if_sens	cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		bne.b	.return_unused

		move.b	oxS_senschar(a0),d1
		cmp.b	im_Code+1(a1),d1
		beq	.go_active
		moveq	#1,d0
		rts

.INTUI		move.l	oxS_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6
		move.l	a0,a3

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq.b	.buttons

		btst	#oxSB_ACTIVE,oxS_flags(a0)
		beq	.if_sens

		cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq	.key

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		bne.b	.return

		; handle cursor keys

		cmp.w	#$42,im_Code(a1)
		bne.b	.if_right

		move.l	oxS_prev(a0),d0
		bra.b	.nextprev

.if_right	cmp.w	#CURSORRIGHT,im_Code(a1)
		bne	.if_left

		tst.w	oxS_offset(a3)
		bne.b	.test_offset

		move.w	oxS_visiblechars(a3),d0
		cmp.w	oxS_inpos(a3),d0
		ble.b	.test_offset

		addq.w	#1,oxS_inpos(a3)
		bra	.move_cursor

.test_offset	move.w	oxS_offset(a3),d0
		add.w	oxS_inpos(a3),d0
		cmp.w	oxS_lenght(a3),d0
		bge.b	.return_unused

		addq.w	#1,oxS_offset(a3)

		move.w	oxS_visiblechars(a3),d0
		cmp.w	oxS_inpos(a3),d0
		bgt.b	.rethink

		subq.w	#1,oxS_inpos(a3)
.rethink
		bsr	s_recalc_fit
		bra	.redraw



.if_left	cmp.w	#CURSORLEFT,im_Code(a1)
		bne	.return_unused

		tst.w	oxS_inpos(a3)
		beq	.sub_offset
		sub.w	#1,oxS_inpos(a3)
		bra.b	.move_cursor
.sub_offset	tst.w	oxS_offset(a3)
		beq.b	.return_unused
		subq.w	#1,oxS_offset(a3)

		bsr	s_recalc_fit
		bra	.redraw

		; handle character key

.key		cmp.w	#$d,im_Code(a1)
		bne.b	.if_vtab

		move.l	oxS_enterobject(a3),d0
		beq	.self_inact

		bclr	#0,d0
		beq.b	.abs

		lea	(a4,d0.l),a0		; get pointer from base
		bra	.get

.abs		move.l	d0,a0

.get		move.l	(a0),d0
		beq	.self_inact
		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod

.return_used	moveq	#1,d0
		rts

.self_inact	move.l	oxS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWM_clrpriv,d1
		bsr	_oxDoMethod

		move.l	a3,a0
		bsr	.go_inactive
		bra.b	.return_used

.if_vtab	;  to right tab?

		cmp.w	#$9,im_Code(A1)
		bne	.if_entf

		move.l	oxS_next(a0),d0

.nextprev	push	d0
		bsr	.go_inactive

		; activate next / prev

		pop	d0
		beq	.return_used
		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod

		moveq	#1,d0
		rts

.if_entf	cmp.w	#$7f,im_Code(a1)
		bne.b	.if_bsp

		; entfernen

		move.l	oxS_string(a3),a0
		adda.w	oxS_offset(a3),a0
		adda.w	oxS_inpos(a3),a0
		tst.b	1(a0)
		beq	.return
.entf_lp	move.b	1(a0),(a0)+
		bne.b	.entf_lp
		subq.w	#1,oxS_lenght(a3)

		bsr	s_recalc_fit

		bra.b	.redraw

.if_bsp		cmp.w	#8,im_Code(a1)
		bne.b	.char

		; backspace

		move.l	oxS_string(a3),a0
		adda.w	oxS_offset(a3),a0
		adda.w	oxS_inpos(a3),a0
		subq.l	#1,a0
		cmp.l	oxS_string(a3),a0
		blt	.return
.bsp_lp		move.b	1(a0),(a0)+
		bne.b	.bsp_lp

		tst.w	oxS_lenght(a3)
		beq	.return
		subq.w	#1,oxS_lenght(a3)
		tst.w	oxS_inpos(a3)
		beq.b	.sub_off
		subq.w	#1,oxS_inpos(a3)

		bsr	s_recalc_fit

		bra.b	.redraw

.sub_off	tst.w	oxS_offset(A3)
		beq.b	.return_used
		subq.w	#1,oxS_offset(A3)

		bsr	s_recalc_fit

		bra.b	.redraw

.char		move.b	im_Code+1(a1),d0
		btst	#oxSB_HEX,oxS_flags(a3)
		beq.b	.if_dez

		cmp.b	#"0",d0
		blt.b	.return_used
		cmp.b	#"f",d0
		bgt.b	.return_used
		cmp.b	#"a",d0
		bge.b	.is_atof
		cmp.b	#"9",d0
		ble.b	.write_char
		cmp.b	#"A",d0
		blt.b	.return_used
		cmp.b	#"F",d0
		bgt.b	.return_used

.is_atof	bclr	#5,im_Code+1(a1)	; make big AtoF
		bra.b	.write_char

.if_dez		btst	#oxSB_DEZ,oxS_flags(a3)
		beq.b	.write_char

		cmp.b	#"0",d0
		blt.b	.return_used
		cmp.b	#"9",d0
		bgt.b	.return_used

.write_char	move.l	oxS_string(a3),a0
		move.l	a0,a4
		adda.w	oxS_offset(a3),a4
		adda.w	oxS_inpos(a3),a4
		subq.l	#1,a4

		move.w	oxS_lenght(a3),d0
		cmp.w	oxS_maxlenght(a3),d0
		bge	.return

		adda.w	oxS_lenght(a3),a0
		addq.l	#1,a0
		addq.w	#1,oxS_lenght(a3)

.einfügen_lp	move.b	(a0),1(a0)
		subq.l	#1,a0
		cmp.l	a0,a4
		bne.b	.einfügen_lp

		move.b	im_Code+1(a1),1(a4)
		addq.w	#1,oxS_inpos(a3)

	;	sub.w	oxS_offset(a3),d0
	;	sub.w	oxS_inpos(a3),d0
	;	bge.b	.recalc

	;	addq.w	#1,oxS_offset(a3)

.recalc		bsr	s_recalc_fit

.redraw		bsr	s_clear

		move.w	oxS_visiblechars(a3),d6

		move.l	oxS_string(a3),a4
		adda.w	oxS_offset(a3),a4
		move.b	oxPT_inputtextpen(a5),d4	; altetextpen
		move.b	oxPT_inputpen(a5),d5

		bsr	oxS_print		; has coords ind d0/d1 from .clear
		bra	.set_cursor

.go_active	; (activated from other object)

		move.l	oxS_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6
		move.l	a0,a3

		clr.w	oxS_offset(a3)
		clr.w	oxS_inpos(a3)
		move.l	oxS_string(a3),a0
		adda.w	oxS_lenght(a3),a0
		move.b	#$20,(a0)		; tmp overwrite zero end with space for cursor at end

		bset	#oxSB_ACTIVE,oxS_flags(a3)

		move.l	a3,d1
		move.l	oxS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		bra	.set_cursor

.buttons	cmp.w	#SELECTDOWN,im_Code(a1)
		bne.b	.return

		movem.w	oxS_left(a3),d0-d3
		bsr	_is_in_rect
		beq.b	.if_sel

		btst	#oxSB_ACTIVE,oxS_flags(a3)
		bne.b	.mousepos

		push	a1
		move.l	a3,d1
		move.l	oxS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		pop	a1

		clr.w	oxS_offset(a3)
		clr.w	oxS_inpos(a3)
		move.l	oxS_string(a3),a0
		adda.w	oxS_lenght(a3),a0
		move.b	#$20,(a0)		; tmp overwrite zero end with space for cursor at end

.mousepos	; calc cursor pos into oxS_inpos from mouse pos

		move.l	oxS_string(a3),a0
		adda.w	oxS_offset(a3),a0
		move.w	oxS_lenght(a3),d0
		sub.w	oxS_offset(a3),d0
		move.w	rp_TxHeight(a2),d3
		move.w	im_MouseX(a1),d2
		sub.w	oxS_left(a3),d2
		move.w	oxS_horizontalspacing(a3),d1
		sub.w	d1,d2
		sub.w	d1,d2
		subq	#1,d2
		move.l	a2,a1
		moveq	#1,d1
		pushm	a2/a3
		sub.l	a3,a3
		lea	-te_SIZEOF(a7),a7
		move.l	a7,a2
		jsr	-696(a6)			; _LVOTextFit(a6)
		lea	te_SIZEOF(a7),a7
		popm	a2/a3
		move.w	d0,oxS_inpos(a3)

		bset	#oxSB_ACTIVE,oxS_flags(a3)
		beq.b	.set_cursor

		; erase cursor at old pos

.move_cursor	move.b	oxPT_inputtextpen(a5),d4		; alttext
		move.b	oxPT_inputpen(a5),d5
		move.w	oxS_oldinpos(a3),d7
		bsr	.cursor

		; draw cursor at new pos

.set_cursor	move.b	oxPT_inputtextpen(a5),d4
		move.b	oxPT_cursorpen(a5),d5

		move.w	oxS_inpos(a3),d7
		move.w	d7,oxS_oldinpos(a3)

.cursor		movem.w	oxS_left(a3),d0/d1

		addq.w	#2,d0
		addq.w	#2,d1

		movem.w	d0/d1,rp_cp_x(a2)		; curso to text baseline/edge

		move.w	d7,d0
		move.l	oxS_string(a3),a0
		adda.w	oxS_offset(a3),a0
		move.l	a0,a4
		adda.w	d7,a4

		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)

		add.w	d0,rp_cp_x(a2)
		movem.w	rp_cp_x(a2),d0/d1

		moveq	#1,d6	; cursor width 1 char

		pushm	d0/d1

		moveq 	#RP_JAM2,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		popm	d0/d1

		bsr	oxS_print

		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		bra.b	.return_used

.return_unused	moveq	#0,d0
		rts
	
.if_sel		bra	.return_unused

	;	bst	#oxSB_ACTIVE,oxS_flags(a3)
	;	beq.b	.return_unused

		; release (mous outside click after inside)

.go_inactive	move.l	oxS_drawinfo(a0),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6
		move.l	a0,a3

		bclr	#oxSB_ACTIVE,oxS_flags(a3)

		; terminate string with NULL (sometimes needed?)

		move.l	oxS_string(a3),a0
		adda.w	oxS_lenght(a3),a0
		clr.b	(a0)

		; calc values and check for bounds, eventually redraw before leaving

		btst	#oxSB_HEX,oxS_flags(a3)
		beq.b	.if_is_dez

		move.l	oxS_string(a3),a0
		move.w	oxS_lenght(a3),d0
		bsr	HexToVal

		bsr	S_valminmax

		move.l	d0,oxS_value(a3)
		move.l	oxS_string(a3),a0

		move.w	oxS_maxlenght(a3),d1
		move.w	d1,oxS_lenght(a3)
		bsr	ValToHex
		bra.b	.res

.if_is_dez	btst	#oxSB_DEZ,oxS_flags(a3)
		beq.b	.res

		move.l	oxS_string(a3),a0
		move.w	oxS_lenght(a3),d0
		bgt.b	.d_to_v
		move.b	#"0",(a0)
		clr.b	1(a0)
		moveq	#0,d0
		bra.b	.vmm		;.set_dez_val

.d_to_v		bsr	DezToVal

.vmm		bsr.b	S_valminmax

.set_dez_val	move.l	d0,oxS_value(a3)
		move.l	oxS_string(a3),a0

		bsr	ValToDez
		moveq	#-1,d0
		move.l	oxS_string(a3),a0
.lp		addq.w	#1,d0
		tst.b	(a0)+
		bne.b	.lp
		move.w	d0,oxS_lenght(a3)
	
.res		; notify members

		move.b	oxS_flags(a3),d0
		and.b	#oxSF_HEX+oxSF_DEZ,d0
		beq.b	.hook

		move.l	a3,a0
		move.l	oxS_value(a0),d1
		move.l	#oxSA_value,d0
		bsr	_oxNotify

		moveq	#0,d1
		move.w	#OXPROP_SOFTMAX,d1
		move.l	oxS_value(a0),d0
		sub.l	oxS_minval(a0),d0
		mulu.w	d0,d1
		move.l	oxS_maxval(a0),d0
		sub.l	oxS_minval(a0),d0
		beq.b	.ext
		divu.w	d0,d1
.ext		ext.l	d1
		move.l	#oxSA_softval,d0
		bsr	_oxNotify

		bsr	_oxBroadcastUpdate

.hook		; call hook if any and reset to start w/o cursor

		pushm	d0-a6
		move.l	oxS_hook(a3),d3
		beq.b	.pop
		move.l	a3,a0
		move.l	oxS_value(a3),d1
		move.l	oxS_string(a3),a1
		moveq	#0,d2
		move.w	oxS_lenght(a3),d2
		moveq	#0,d0
		move.l	d3,a2
		move.l	libbase(pc),a6
		move.l	oxO_userbase(a3),a4
		jsr	(a2)
.pop		popm	d0-a6

		clr.w	oxS_inpos(a3)
		clr.w	oxS_offset(a3)

		move.l	oxS_drawinfo(a3),d0
		beq	.return_used
		move.l	d0,a0
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a0)
		beq	.return_used

s_drawinact	move.l	oxS_drawinfo(a3),a5
		move.l	oxDI_pentable(a5),a5

		bsr	s_clear
		bsr	s_recalc_fit

		move.w	oxS_visiblechars(a3),d6
		move.l	oxS_string(a3),a4
		move.b	oxPT_inputtextpen(a5),d4
		move.b	oxPT_inputpen(a5),d5

		bsr	oxS_print
		moveq	#0,d0
		rts

s_recalc_fit	bsr	oxS_vischars
		move.w	d6,oxS_visiblechars(a3)
		rts

s_clear		; draw w/o cursor

		move.b	oxPT_inputpen(a5),d0		; block color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	oxS_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		subq.w	#3,d2
		subq.w	#3,d3
	
		addq.w	#2,d0
		addq.w	#2,d1

		movem.w	d0/d1,-(a7)

		cmp.w	d0,d2	; avoid guru if coords are broken
		blt	.rts
		cmp.w	d1,d3
		blt	.rts
		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1
.rts		rts


S_SETDEF	move.w	#oxS_DEFAULTMAXLENGHT,oxS_maxlenght(a0)
		move.w	#$40,oxS_minwidth(a0)
		move.w	#1,oxS_prop(a0)
		move.l	#$00050002,oxS_horizontalspacing(a0)		; make global to class??

		move.l	#$ffffffff,oxS_maxval(a0)

		moveq	#0,d0
		move.w	oxS_maxlenght(a0),d0
		addq.l	#1,d0			; zero byte at ende
		bsr	alloc_mem
		move.l	d0,oxS_string(a0)
		move.l	d0,a0
		move.b	#$20,(a0)		; initial string cursor space
.rts		rts

S_DEINIT	move.l	oxS_string(a0),d0
		beq.b	.rts
		move.l	a0,a1
		move.l	d0,a0
		moveq	#0,d0
		move.w	oxS_maxlenght(a1),d0
		addq.l	#1,d0			; zero byte at end
		bra	free_mem

.rts		rts

S_valminmax	cmp.l	oxS_minval(a3),d0
		bls.b	.get_min

		cmp.l	oxS_maxval(a3),d0
		bls.b	.even

		move.l	oxS_maxval(a3),d0
		bra.b	.even

.get_min	move.l	oxS_minval(a3),d0

.even		btst	#oxSB_EVEN,oxS_flags(a3)
		beq.b	.set_val
		addq.l	#1,d0
		bclr	#0,d0

.set_val	move.l	d0,oxS_value(a3)
		rts

s_hexdezcalc	; a3 *self, d0 value.l

		; default is dez

		bsr.b	S_valminmax

		btst	#oxSB_HEX,oxS_flags(a3)
		bne.b	.hex

		move.l	oxS_string(a3),a0

		bsr	ValToDez
		moveq	#-1,d0
		move.l	oxS_string(a3),a0
.lp		addq.w	#1,d0
		tst.b	(a0)+
		bne.b	.lp

		move.w	d0,oxS_lenght(a3)
		rts

.hex		move.l	oxS_string(a3),a0

		move.w	oxS_maxlenght(a3),d1
		move.w	d1,oxS_lenght(a3)
		bra	ValToHex

S_INIT		move.l	a0,a3
		move.b	oxS_flags(a3),d0
		and.b	#oxSF_HEX+oxSF_DEZ,d0
		beq.b	.rts_ok
		move.l	oxS_value(a3),d0
		bsr.b	s_hexdezcalc
.rts_ok		moveq	#1,d0
		rts


oxS_SET	movem.l	(a1),d0/d1

		cmp.l	#oxA_active,d0
		bne	.0
		or.w	#oxSF_ACTIVE,oxS_flags(a0)
		rts

.0		cmp.l	#oxSA_minwidth,d0
		bne	.if_value
		move.w	d1,oxS_minwidth(a0)
		rts
.if_value	cmp.l	#oxSA_value,d0
		bne	.if_flags
		move.l	d1,oxS_value(a0)
		rts

.if_flags	cmp.l	#oxSA_flags,d0
		bne.b	.if_minval
		move.b	d1,oxS_flags(a0)
		rts

.if_minval	cmp.l	#oxSA_minval,d0
		bne.b	.if_maxval
		move.l	d1,oxS_minval(a0)
		rts
.if_maxval	cmp.l	#oxSA_maxval,d0
		bne.b	.a
		move.l	d1,oxS_maxval(a0)
		rts

.a		cmp.l	#oxSA_prop,d0
		bne	.b
		move.w	d1,oxS_prop(a0)
		rts


.b		cmp.l	#oxSA_maxlenght,d0
		bne	.c

		move.l	d1,d0			; if new lenght is null, leave old string in place
		beq.b	.rts

		move.l	d1,d3			; save new lenght to d3
		move.l	a0,a1			; save *object to a1 

		addq.l	#1,d0			; zero et end
		bsr	alloc_mem
		move.l	d0,d2			; save *newmem to d2
		beq	.rts			; if fail terminate

		move.l	oxS_string(a1),d0	; old string to copy?
		beq.b	.set_new
		move.l	d0,a0
		move.l	d2,a2

		; new max is count in d1

.scpy_lp	move.b	(a0)+,(a2)+
		beq.b	.copied
		dbf	d1,.scpy_lp
.copied		
		move.l	d0,a0
		moveq	#0,d0
		move.w	oxS_maxlenght(a1),d0
		addq.w	#1,d0			; zero at end
		bsr	free_mem

.set_new	move.l	d2,oxS_string(a1)
		move.w	d3,oxS_maxlenght(a1)

		cmp.w	oxS_lenght(a1),d3		; shrink existing string lenght to smaller maxlenght
		bge.b	.rts
		move.w	d3,oxS_lenght(a1)
		rts


.c		cmp.l	#oxSA_text,d0
		bne.b	.if_eo
		moveq	#0,d0
		tst.l	d1		; if no text, set lenght to 0
		beq.b	.set_len
		move.l	oxS_string(a0),a1
		move.l	d1,a2
		move.w	oxS_maxlenght(a0),d1
		beq	.set_len
		subq.w	#1,d1
		moveq	#0,d0
.cpy_lp		move.b	(a2)+,(a1)+
		beq.b	.set_len
		addq.w	#1,d0
		dbf	d1,.cpy_lp
.set_len	move.w	d0,oxS_lenght(a0)
.rts		rts

.if_eo		cmp.l	#oxSA_enterobject,d0
		bne	.if_hook
		move.l	d1,oxS_enterobject(a0)
		rts
.if_hook	cmp.l	#oxSA_hook,d0
		bne.b	.if_di
		move.l	d1,oxS_hook(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.if_prev
		move.l	d1,oxS_drawinfo(a0)
		rts
.if_prev	cmp.l	#oxA_prev,d0
		bne.b	.if_next
		move.l	d1,oxS_prev(a0)
		rts

.if_next	cmp.l	#oxA_next,d0
		bne	.if_sens
		move.l	d1,oxS_next(a0)
		rts

.if_sens	cmp.l	#oxSA_senschar,d0
		bne	.rts
		move.b	d1,oxS_senschar(a0)
		rts

oxS_GET	move.l	(a1),d0

		cmp.l	#oxSA_text,d0
		bne.b	.a
		move.l	oxS_string(a0),d0
		rts
.a		cmp.l	#oxSA_lenght,d0
		bne.b	.ret_false
		moveq	#0,d0
		move.w	oxS_lenght(a0),d0
.rts		rts
.ret_false	moveq	#0,d0
		rts

oxS_GETLAYOUT	move.w	oxS_minwidth(a0),oxLI_minwidth(a1)

		move.l	oxS_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),d0			; line height
		add.w	#4,d0				; border
		move.w	oxS_verticalspacing(a0),d1	; vspace oben und unten

		add.w	d1,d0
		add.w	d1,d0
		move.w	d0,oxLI_minheight(a1)
		move.w	d0,oxS_height(a0)		; fixed height
		move.w	oxS_prop(a0),oxLI_propw(a1)
		clr.w	oxLI_proph(a1)

		moveq	#1,d0
		rts

oxS_SETLAYOUT	;move.l	oxSL_ClipDomain(a1),oxO_ParentClipper(a0)

		move.w	oxLI_width(a1),oxS_width(a0)
		move.l	oxLI_left(a1),oxS_left(a0)

		move.l	a0,a3

		bsr	oxS_vischars
		move.w	d6,oxS_visiblechars(A3)

		moveq	#1,d0
		rts

oxS_vischars	; set d6 to visible size from offset position 

		pushm	d0-d3

		moveq	#0,d6

		move.l	oxS_drawinfo(a3),d2
		beq.b	.rts_pop
		move.l	d2,a2

		tst.l	oxDI_rastport(a2)
		beq.b	.rts_pop

		move.l	oxDI_rastport(a2),a2

		move.l	oxS_string(a3),a0
		adda.w	oxS_offset(a3),a0
		move.w	oxS_lenght(a3),d0
		sub.w	oxS_offset(a3),d0
		move.w	rp_TxHeight(a2),d3
		move.w	oxS_width(a3),d2
		move.w	oxS_horizontalspacing(a3),d1
		sub.w	d1,d2
		sub.w	d1,d2
		subq	#4,d2	; border
		moveq	#1,d1
		pushm	a2/a3
		sub.l	a3,a3
		lea	-te_SIZEOF(a7),a7
		move.l	a2,a1
		move.l	a7,a2
		move.l	gfxbase(pc),a6
		jsr	-696(a6)			; _LVOTextFit(a6)
		lea	te_SIZEOF(a7),a7
		popm	a2/a3
		move.w	d0,d6
.rts_pop	popm	d0-d3
		rts


oxS_print	add.w	oxS_horizontalspacing(a3),d0
		add.w	oxS_verticalspacing(a3),d1

		move.l	oxS_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		move.l	rp_Font(a2),a0
		add.w	tf_Baseline(a0),d1
		movem.w	d0/d1,rp_cp_x(a2)		; cursor to text baseline/edge

		move.l	gfxbase(pc),a6


		move.w	d4,d0		; text color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	d5,d0		; bg color
		move.l	a2,a1
		jsr	_LVOSetBPen(a6)

		move.l	a4,a0
		move.w	d6,d0
		move.l	a2,a1
		jmp	_LVOText(a6)


_in_frame	; coords/sizes must be in d0-d3 

		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3
	
_in_frame_rb	; right bottom

		bsr	_in_frame_nofill_rb

		movem.w	d0/d1,-(a7)

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1
		rts

_in_frame_nofill	add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

_in_frame_nofill_rb
		move.b	oxPT_darkpen(a5),d4			; topleft color
		move.b	oxPT_shinepen(a5),d5			; bottomright color
		moveq	#0,d6			; thickness

		move.l	a0,a3
		move.l	gfxbase(pc),a6

		bsr	_draw_bevel_border

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.b	oxPT_blackpen(a5),d4	; topleft color
		move.b	d4,d5			; bottomright color
		moveq	#0,d6			; thickness

		bsr	_draw_bevel_border

		movem.w	d0-d3,-(a7)

		move.b	oxPT_inputpen(a5),d0		; block color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7)+,d0-d3

		addq.w	#1,d0		; fill inner area
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3
		rts


str_create_ex	lea	example_string(pc),a2
		move.l	#OX_STRING,d2
		bra	_oxCreateObject

example_string	dc.l	oxSA_text,.text
		dc.l	oxSA_prop,1
		dc.l	oxSA_minwidth,200
		dc.l	TAG_END
.text		dc.b	"example text input",0
		even

;--------------------------------------------------------------------
; OX_LABEL

 STRUCTURE	oxLabel,oxO_SIZEOF
	APTR	oxLab_text	; buffer
	UWORD	oxLab_lenght	; in chars
	UWORD	oxLab_left
	UWORD	oxLab_top
	UWORD	oxLab_linechar
	APTR	oxLab_drawinfo
	LABEL	oxLab_SIZEOF

	OXICLASSHEADER	label, 1, 0, title

	dc.l	oxCA_objectsize,oxLab_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,.create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Label ox internal class 1.0",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	oxLab_SET

		cmp.w	#OXM_DRAW,d1
		beq	oxLab_DRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxLab_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxLab_SETLAYOUT

	;	cmp.w	#OXM_SETDEF,d1
	;	bne.b	.rts

	;	move.w	#-1,oxLab_linechar(a0)

.rts		rts

.create_ex	lea	.example(pc),a2
		move.l	#OX_LABEL,d2
		bra	_oxCreateObject

.example	dc.l	oxLabA_text,.ex_text
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.ex_text	dc.b	"label:",0
		even

oxLab_SET	movem.l	(a1),d0/d1

		cmp.l	#oxLabA_text,d0
		bne	.linechar
		move.l	d1,oxLab_text(a0)
		move.l	d1,a1
		moveq	#-1,d0
.lp		addq.w	#1,d0	
		tst.b	(a1)+
		bne.b	.lp
		move.w	d0,oxLab_lenght(a0)
.rts		rts
.linechar	cmp.l	#oxLabA_linechar,d0
		bne.b	.if_di
		move.w	d1,oxLab_linechar(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.rts
		move.l	d1,oxLab_drawinfo(a0)

		rts

oxLab_GETLAYOUT
		move.l	oxLab_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),oxLI_minheight(a1)	; label text height
		addq.w	#8,oxLI_minheight(a1)	; obre und unter ränder vom button daneben für
						; gleiche höhe
		push	a1

		move.l	oxLab_drawinfo(a0),a1
		move.l	oxDI_rastport(a1),a1
		move.w	oxLab_lenght(a0),d0
		move.l	oxLab_text(a0),a0
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)

		addq.w	#1,d0			; add shadow size

		pop	a1

		clr.l	oxLI_propw(a1)
		move.w	d0,oxLI_minwidth(a1)
		beq	.ret_unu
		moveq	#1,d0
		rts
.ret_unu	moveq	#0,d0
		rts

oxLab_SETLAYOUT
		move.l	oxLI_left(a1),oxLab_left(a0)

		moveq	#1,d0
		rts

oxLab_DRAW	movem.w	oxLab_left(a0),d0/d1
		move.l	a0,a3
		move.l	oxLab_drawinfo(a3),a5
		move.l	oxDI_rastport(a5),a2
		add.w	rp_TxBaseline(a2),d1
		addq.w	#4,d1			; top borders

		movem.w	d0/d1,-(a7)

		addq.w	#1,d0			; shadow pos
		addq.w	#1,d1

		move.l	gfxbase(pc),a6

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_blackpen(a1),d0 ; text shadow color
		moveq 	#0,d1
		moveq	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		move.w	oxLab_lenght(a3),d0
		move.l	oxLab_text(a3),a0
		move.l	a2,a1
		jsr	_LVOText(a6)

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_whitepen(a1),d0 ; lite text color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1
		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	oxLab_lenght(a3),d0
		move.l	oxLab_text(a3),a0
		move.l	a2,a1
		jsr	_LVOText(a6)

		; underline a char

		move.w	oxLab_linechar(a3),d5
		move.l	oxLab_text(a3),a3
		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_whitepen(a1),d6

		movem.w	(a7)+,d0/d1
		sub.w	rp_TxBaseline(a2),d1

		bsr.b	_underline_char

		moveq	#0,d0
		rts

_underline_char	; d0/d1	x/y
		; a3	*text
		; a2 	*rastport
		; d5	charpos
		; d6	color

		tst.w	d5
		beq.b	.rts
		subq.w	#1,d5

		tst.b	(a3)
		beq.b	.rts

		push	a3

		add.w	rp_TxHeight(a2),d1
		subq.w	#1,d1

		movem.w	d0/d1,-(a7)

		move.l	gfxbase(pc),a6

		moveq	#0,d0
		move.b	d6,d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		; chars from left to pos

		move.w	d5,d0
		move.l	a3,a0
		move.l	a2,a1
		jsr	_LVOTextLength(a6)
		add.w	d0,(a7)

		movem.w	(a7),d0/d1
		move.l	a2,a1
		jsr	_LVOMove(a6)

		adda.w	d5,a3
		move.l	a3,a0	

		; one char at pos

		moveq	#1,d0
		move.l	a2,a1
		jsr	_LVOTextLength(a6)

		add.w	d0,(a7)
		movem.w	(a7)+,d0/d1
		subq.w	#1,d0

		move.l	a2,a1
		jsr	_LVODraw(a6)	; underline char

		pop	a3

.rts		rts

_is_in_rect	movem.l	d1-d7/a0-a6,-(a7)

		move.l	im_IDCMPWindow(a1),a2

		moveq	#0,d4
		moveq	#0,d5
		move.b	wd_BorderLeft(a2),d4
		move.b	wd_BorderTop(a2),d5
		neg.w	d4
		neg.w	d5
		add.w	im_MouseX(a1),d4
		add.w	im_MouseY(a1),d5

		cmp.w	d4,d0
		bgt.b	.not_in_rect

		add.w	d2,d0
		subq.w	#1,d0
		cmp.w	d4,d0
		blt.b	.not_in_rect

		cmp.w	d5,d1
		bgt.b	.not_in_rect

		add.w	d3,d1
		subq.w	#1,d1
		cmp.w	d5,d1
		blt.b	.not_in_rect

		movem.l	(a7)+,d1-d7/a0-a6

		moveq	#1,d0
		rts
.not_in_rect
		movem.l	(a7)+,d1-d7/a0-a6

		moveq	#0,d0
		rts

;--------------------------------------------------------------------
; OX_TITLE

 STRUCTURE	oxTitle,oxO_SIZEOF
	APTR	oxT_text	; buffer
	UWORD	oxT_lenght	; in chars
	UWORD	oxT_textwidth
	UWORD	oxT_lineyoffset
	UWORD	oxT_left
	UWORD	oxT_top
	UWORD	oxT_width
	UWORD	oxT_linechar
	APTR	oxT_drawinfo
	LABEL	oxT_SIZEOF


	OXICLASSHEADER	title, 1, 0, list

	dc.l	oxCA_objectsize,oxT_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,.create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: ox Title Internal Class 1.0",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	oxT_SET

		cmp.w	#OXM_DRAW,d1
		beq	oxT_DRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxT_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxT_SETLAYOUT

.rts		rts

.create_ex	lea	.example(pc),a2
		move.l	#OX_TITLE,d2
		bra	_oxCreateObject

.example	dc.l	oxTA_text,.ex_text
		dc.l	oxTA_linechar,9
		dc.l	TAG_END
.ex_text	dc.b	"example title",0
		even

oxT_SET	movem.l	(a1),d0/d1

		cmp.l	#oxTA_text,d0
		bne	.linechar
		move.l	d1,oxT_text(a0)
		move.l	d1,a1
		moveq	#-1,d0
.lp		addq.w	#1,d0	
		tst.b	(a1)+
		bne.b	.lp
		move.w	d0,oxT_lenght(a0)
.rts		rts
.linechar	cmp.l	#oxTA_linechar,d0
		bne.b	.if_di
		move.w	d1,oxT_linechar(a0)
		rts
.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.rts
		move.l	d1,oxT_drawinfo(a0)

		rts



oxT_GETLAYOUT	
		move.l	oxT_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),d0
		move.w	d0,oxLI_minheight(a1)	; label text height

		asr.w	#1,d0		; center line vert
		move.w	d0,oxT_lineyoffset(a0)	
		move.l	a0,a3

		push	a1

		move.w	oxT_lenght(a0),d0
		move.l	oxT_text(a0),a0
		move.l	oxT_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)

		pop	a1

		move.w	d0,oxT_textwidth(a3)
		add.w	#40,d0			; -- Titel --(--------)

		move.w	d0,oxLI_minwidth(a1)
		move.l	#$FFFF0000,oxLI_propw(a1)

		moveq	#1,d0
		rts

oxT_SETLAYOUT	move.l	oxLI_left(a1),oxT_left(a0)
		move.w	oxLI_width(a1),oxT_width(a0)

		moveq	#1,d0
		rts

oxT_DRAW	movem.w	oxT_left(a0),d0/d1

		move.w	d1,d3

		move.l	a0,a3
		move.l	oxT_drawinfo(a0),a5
		move.l	oxDI_rastport(a5),a2
		add.w	rp_TxBaseline(a2),d1

		move.l	gfxbase(pc),a6

		movem.w	d0/d1,-(a7)

		add.w	oxT_lineyoffset(a0),d3

		addq.w	#1,d3

		move.w	d3,d1
		addq.w	#1,d0
		addq.w	#1,d1

		movem.w	d0/d1,-(a7)

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_blackpen(a1),d0		; dark line color
		moveq	#0,d1
		moveq	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)
	
		movem.w	(a7),d0/d1
		add.w	#15,d0

		move.l	a2,a1
		jsr	_LVODraw(a6)	; left title line shadow

		movem.w	(a7)+,d0/d1

		add.w	#25,d0
		add.w	oxT_textwidth(a3),d0

		push	d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		pop	d1

		move.w	(a7),d0
		add.w	oxT_width(a3),d0
		subq.w	#1,d0
	
		move.l	a2,a1
		jsr	_LVODraw(a6)	; right title line shadow

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_whitepen(a1),d0		; lite line color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	(a7),d0
		move.w	d3,d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	(a7),d0
		add.w	#15,d0
		move.w	d3,d1

		push	d0

		move.l	a2,a1
		jsr	_LVODraw(a6)	; left title line lite

		pop	d0

		add.w	oxT_textwidth(a3),d0
		add.w	#10,d0
		move.w	d3,d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	(a7),d0
		add.w	oxT_width(a3),d0
		subq.w	#1,d0
		move.w	d3,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)	; right title line lite

		movem.w	(a7),d0/d1

		addq.w	#1,d0			; shadow pos
		addq.w	#1,d1

		add.w	#20,d0

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_blackpen(a1),d0	; dark text color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	oxT_lenght(a3),d0
		move.l	oxT_text(a3),a0
		move.l	a2,a1
		jsr	_LVOText(a6)

		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_whitepen(a1),d0	; lite text color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1
		add.w	#20,d0
		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	oxT_lenght(a3),d0
		move.l	oxT_text(a3),a0
		move.l	a2,a1
		jsr	_LVOText(a6)

		; underline a char

		move.w	oxT_linechar(a3),d5

		move.l	oxT_text(a3),a3
		move.l	oxDI_pentable(a5),a1
		move.b	oxPT_whitepen(a1),d6

		movem.w	(a7)+,d0/d1
		add.w	#20,d0
		sub.w	rp_TxBaseline(a2),d1

		bsr	_underline_char

		moveq	#0,d0
		rts


;--------------------------------------------------------------------
; OX_LIST

 STRUCTURE	oxList,oxO_SIZEOF
	UWORD	oxL_minwidth
	UWORD	oxL_minheight
	UWORD	oxL_left
	UWORD	oxL_top
	UWORD	oxL_width
	UWORD	oxL_height
	UWORD	oxL_propw
	UWORD	oxL_proph
	UWORD	oxL_leftpercent	; prozentuale breite des linken bereichs, 0 kein rechter bereich!
	UWORD	oxL_leftwidth

	UWORD	oxL_minlines
	UWORD	oxL_spacing

	APTR	oxL_drawinfo
	APTR	oxL_oldregion

	STRUCT	oxL_Region,rg_SIZEOF
	STRUCT	oxL_RegionRectangle,rr_SIZEOF

	APTR	oxL_prev
	APTR	oxL_next

	APTR	oxL_receiver		; points to sliderobject by default
	APTR	oxL_sliderobject
	APTR	oxL_selfptr		; for connection from slider to here
	UWORD	oxL_sliderwidth	; still to get by GetAttr

	STRUCT	oxL_list,MLH_SIZE
	UBYTE	oxL_flags
	UBYTE	oxL_senschar
	UBYTE	oxL_internalflags
	UBYTE	oxL_pad

	APTR	oxL_topitem
	APTR	oxL_activeitem
	APTR	oxL_firstonitem 
	APTR	oxL_lastonitem
	APTR	oxL_prevselected
	UWORD	oxL_lines		; calculated in setlayout()
	UWORD	oxL_items		; number of items in list
	UWORD	oxL_offset		; visible entry nr from top down
	UWORD	oxL_inpos
	UWORD	oxL_oldinpos

	ULONG	oxL_userdata

	ULONG	oxL_seconds		; check for doubleclick
	ULONG	oxL_micros		; ..

	APTR	oxL_dchook		; on doubleclick
	APTR	oxL_selhook		; on select (when mouse button released)

	LABEL	oxL_SIZEOF

	BITDEF	oxL,reset,0
	BITDEF	oxL,update,1
	BITDEF	oxL,incomming,2


; oxLA_addline  a1 (textl, textr, flags, userdata)  returns *oxListItem

 STRUCTURE	oxListItem,0
	STRUCT	oxLIt_node,LN_SIZE	; with pri and name for sorting!
	UWORD	oxLIt_textlenght
	APTR	oxLIt_rtext
	UWORD	oxLIt_rtextlenght
	ULONG	oxLIt_userdata
	LABEL	oxLIt_SIZEOF

oxLIt_flags	=	LN_TYPE
oxLIt_text	=	LN_NAME
oxLIt_pri	=	LN_PRI



	OXICLASSHEADER	list, 0, 4, slider

	dc.l	oxCA_objectsize,oxL_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	TAG_END

.dispatcher	cmp.w	#OXM_SET,d1
		beq	oxL_SET
		cmp.w	#OXM_GET,d1
		beq	oxL_GET

		cmp.w	#OXM_DRAW,d1
		beq	oxL_DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	oxL_UPDATE

		cmp.w	#OXM_INTUIMESSAGE,d1
		beq	oxL_INTUI

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxL_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxL_SETLAYOUT

		cmp.w	#OXM_ACTIVATE,d1
		beq	oxL_go_active


		cmp.w	#OXM_INACTIVE,d1
		beq	oxL_go_inactive

		cmp.w	#OXM_DEINIT,d1
		beq	.DEINIT

		cmp.w	#OXM_INIT,d1
		beq	.INIT

		cmp.w	#OXM_SETDEF,d1
		beq	.SETDEF

		cmp.w	#oxLM_newitem,d1
		beq	.newitem

		cmp.w	#oxLM_newitemtags,d1
		beq	newitemtags

		cmp.l	#oxLM_getitemtext,d1
		beq	.getitext

		cmp.l	#oxLM_getitemrtext,d1
		beq	.getirtext

		cmp.w	#oxLM_getnextitem,d1
		beq	.getnextitem

		cmp.w	#oxLM_getitemuserdata,d1
		beq	.getitemuserdat

		cmp.w	#oxLM_deleteitem,d1
		beq	.delitem

		cmp.w	#oxLM_deselectitem,d1
		beq	.deselitem

;		cmp.w	#oxLM_setitemtext,d1
;		beq.b	.setitemtext

		cmp.w	#oxLM_sort,d1
		beq	oxL_sort

		cmp.w	#OXM_RELINK,d1
		beq	.RELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	.LINKPRIV

		rts

;.setitemtext	movem.l	(a1),

.getnextitem	move.l	a1,d0
		bne.b	.next
		lea	oxL_list(a0),a1
.next		move.l	(a1),a1
		tst.l	(a1)
		beq	.ret_null
		move.l	a1,d0
		rts
.ret_null	moveq	#0,d0
		rts

.getitemuserdat	move.l	oxLIt_userdata(a1),d0
		rts

.getitext	move.l	oxLIt_text(a1),d0
		rts
.getirtext	move.l	oxLIt_rtext(a1),d0
		rts

.deselitem	bclr	#oxLIB_SELECTED,oxLIt_flags(a1)
		bra	oxL_DRAW

.delitem	move.l	a0,a3
		subq.w	#1,oxL_items(a0)

		push	a1

		REMOVE	; *item is in a1

		clr.l	oxL_topitem(a3)

		move.l	oxL_list(a3),a0
		tst.l	(a0)
		beq.b	.clr
		move.l	a0,oxL_topitem(a3)

.clr		clr.l	oxL_activeitem(a3)
		clr.l	oxL_firstonitem(a3)
		clr.l	oxL_lastonitem(a3)
		clr.l	oxL_prevselected(a3)

		clr.w	oxL_offset(a3)
		clr.w	oxL_inpos(a3)
		clr.w	oxL_oldinpos(a3)

		pop	a0
		moveq	#oxLIt_SIZEOF,d0
		bra	free_mem


.newitem	; a0 *list
		; a1 *newitem

		moveq	#oxLIt_SIZEOF,d0
		bsr	alloc_mem
		beq	.return_nix
		move.l	d0,a3
		move.l	oxOLI_text(a1),a2
		move.l	a2,oxLIt_text(a3)
		beq.b	.if_rtext
		moveq	#-1,d0
.lef_lp		addq.w	#1,d0
		tst.b	(a2)+
		bne.b	.lef_lp
		move.w	d0,oxLIt_textlenght(a3)
.if_rtext	move.l	oxOLI_rtext(a1),a2
		move.l	a2,oxLIt_rtext(a3)
		beq.b	.cpy_flags
		moveq	#-1,d0
.rig_lp		addq.w	#1,d0
		tst.b	(a2)+
		bne.b	.rig_lp
		move.w	d0,oxLIt_rtextlenght(a3)
.cpy_flags	move.b	oxOLI_flags(a1),oxLIt_flags(a3)
		move.b	oxOLI_pri(a1),oxLIt_pri(a3)
		move.l	oxOLI_userdata(a1),oxLIt_userdata(a3)

		; zahl der items um 1 erhöhen

		addq.w	#1,oxL_items(a0)

		; pointer initialisieren

		bsr	L_initpointers

		; einhängen

		move.l	a3,a1
		lea	oxL_list(a0),a0
		ADDTAIL
		move.l	a3,d0		; return *item
		rts
.return_nix	moveq #0,d0
		rts

.SETDEF		lea	oxL_RegionRectangle(a0),a1
		move.l	a1,oxL_Region+rg_RegionRectangle(a0)

		move.l	a0,oxL_selfptr(a0)		; slider points here
	;	lea	oxL_sliderobject(a0),a1
	;	move.l	a1,oxL_receiver(a0)
		move.l	#$00400040,oxL_minwidth(a0)
	;	move.w	#1,oxL_proph(a0)
		move.w	#2,oxL_spacing(a0)
		move.w	#8,oxL_minlines(a0)
		lea	oxL_list(a0),a0
		NEWLIST	a0
.rts		rts

.LINKPRIV	btst	#oxLB_ACTIVE,oxL_flags(a0)
		beq	.rts

		move.l	a0,d1
		move.l	oxL_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		moveq	#1,d0
		rts

.RELINK		move.l	oxL_list(a0),a2
		tst.l	(a2)
	;	beq.b	.rts
		lea	oxL_prev(a0),a2
		bra	_ringconnect

.INIT		move.l	a0,a3

		btst	#oxLB_NOSLIDER,oxL_flags(a3)
		bne	.rts_ok

		move.w	#$f,oxL_sliderwidth(a3)

		lea	.list_slider_tags(pc),a2
		move.l	#OX_SLIDER,d2
		jsr	_oxCreateObject(pc)
		move.l	d0,oxL_sliderobject(a3)
		beq	.rts_fail

		push	d0
		move.l	d0,a1
		lea	oxO_list(a3),a0
		ADDTAIL
		pop	a0

		move.l	#oxA_receiver,d0
		lea	oxL_selfptr(a3),a1
		move.l	a1,d1
		jsr	_oxSetAttr(pc)
		move.l	#oxA_drawinfo,d0
		move.l	oxL_drawinfo(a3),d1
		bsr	_oxSetAttr		

.rts_ok		moveq	#1,d0
		rts
.rts_fail	moveq	#-1,d0
		rts


.list_slider_tags	dc.l	oxSlA_flags,oxSlF_pattern
			dc.l	TAG_END


.DEINIT		; dealloc slider if present (currently dealloc. by global FreeObj beacuse it was
		;				also added as member to the listview)

		move.l	oxL_sliderobject(a0),d0
	;	beq	.de_items

	;	push	a0
	;	move.l	d0,a0
	;	jsr	_oxFreeObject(pc)
	;	pop	a0
	;	clr.l	oxL_sliderobject(a0)

.de_items	; dealloc all items

		move.l	oxL_list+LH_HEAD(a0),d0
		beq	.rts
		move.l	d0,a2
.del_lp		tst.l	(a2)
		beq.b	.rts
		move.l	a2,a0
		move.l	LN_SUCC(a2),a2
		moveq	#oxLIt_SIZEOF,d0
		bsr	free_mem
		bra	.del_lp


oxL_sort	lea	oxL_list(a0),a0
		bra	sortlist

oxL_SET	movem.l	(a1),d0/d1/a1

		cmp.l	#oxLA_minwidth,d0
		bne	.a
		move.w	d1,oxL_minwidth(a0)
		rts

.a		cmp.l	#oxLA_minheight,d0
		bne	.b
		move.w	d1,oxL_minheight(a0)
		rts

.b		cmp.l	#oxLA_propw,d0
		bne	.c
		move.w	d1,oxL_propw(a0)
		rts

.c		cmp.l	#oxLA_proph,d0
		bne	.d
		move.w	d1,oxL_proph(a0)
		rts
.d		cmp.l	#oxLA_minlines,d0
		bne.b	.if_perc
		move.w	d1,oxL_minlines(a0)
		rts
.if_perc	cmp.l	#oxLA_leftpercent,d0
		bne	.if_flags
		move.w	d1,oxL_leftpercent(a0)
		rts
.if_flags	cmp.l	#oxLA_flags,d0
		bne	.if_prev
		move.b	d1,oxL_flags(a0)
		rts

.if_prev	cmp.l	#oxA_prev,d0
		bne.b	.if_next
		move.l	d1,oxL_prev(a0)
		rts

.if_next	cmp.l	#oxA_next,d0
		bne	.if_di
		move.l	d1,oxL_next(a0)

.if_di		cmp.l	#oxA_drawinfo,d0
		bne	.if_sens
		move.l	d1,oxL_drawinfo(a0)
		rts

.if_sens	cmp.l	#oxLA_senschar,d0
		bne	.if_rec
		move.b	d1,oxL_senschar(a0)
		rts

.if_rec		cmp.l	#oxA_receiver,d0
		bne	.if_dch
		move.l	d1,oxL_receiver(a0)
		rts

.if_dch		cmp.l	#oxLA_dchook,d0
		bne.b	.if_selh
		move.l	d1,oxL_dchook(a0)
		rts

.if_selh	cmp.l	#oxLA_selhook,d0
		bne.b	.if_pos
		move.l	d1,oxL_selhook(a0)
		rts

.if_pos		cmp.l	#oxA_pos,d0
		bne.b	.if_itemrtext

		cmp.w	oxL_offset(a0),d1
		beq	.rts

		bset	#oxLB_update,oxL_internalflags(a0)

		move.w	d1,oxL_offset(a0)
		move.l	oxL_list+LH_HEAD(a0),d0
		beq	.rts
		move.l	d0,a5
		bra.b	.totop_inlp
.totop_lp	move.l	LN_SUCC(a5),a5
.totop_inlp	tst.l	(a5)
		beq.b	.rts
		dbf	d1,.totop_lp
		move.l	a5,oxL_topitem(a0)
		rts

.if_itemrtext	cmp.l	#oxLA_itemrtext,d0
		bne.b	.itemtext

		move.l	a0,a3

		move.l	d1,oxLIt_rtext(a1)
		beq.b	.clr

		move.l	d1,a0
		moveq	#-1,d1
.r_lp		addq.w	#1,d1
		tst.b	(a0)+
		bne.b	.r_lp
.clr		move.w	d1,oxLIt_rtextlenght(a1)

		move.l	a1,a5		; a3 *list, a5 *item
		bra	_draw_line

.itemtext	cmp.l	#oxLA_itemtext,d0
		bne.b	.item

		move.l	a0,a3

		move.l	d1,oxLIt_text(a1)
		beq.b	.cl

		move.l	d1,a0
		moveq	#-1,d1
.l_lp		addq.w	#1,d1
		tst.b	(a0)+
		bne.b	.l_lp
.cl		move.w	d1,oxLIt_textlenght(a1)

		move.l	a1,a5		; a3 *list, a5 *item
		bra	_draw_line

.item		cmp.l	#oxLA_item,d0
		beq.b	new_item

.rts		rts

newitemtags	; method! returns *item!
		move.l	a1,a2
		bsr	n_i
		move.l	a3,d0
		rts

new_item	move.l	d1,a2

n_i		moveq	#oxLIt_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts
		move.l	d0,a3

.tag_loop	bsr	get_a_tag
		beq.b	.init

		cmp.w	#oxLIA_text,d0
		bne.b	.rtext
		move.l	d1,oxLIt_text(a3)
		move.l	d1,a1

		moveq	#-1,d0
.lef_lp		tst.b	(a1)+
		dbeq	d0,.lef_lp
		not.w	d0
		move.w	d0,oxLIt_textlenght(a3)
		bra.b	.tag_loop

.rtext		cmp.w	#oxLIA_righttext,d0
		bne.b	.userd
		move.l	d1,oxLIt_rtext(a3)
		move.l	d1,a1

		moveq	#-1,d0
.rig_lp		tst.b	(a1)+
		dbeq	d0,.rig_lp
		not.w	d0
		move.w	d0,oxLIt_rtextlenght(a3)
		bra.b	.tag_loop

.userd		cmp.w	#oxLIA_userdata,d0
		bne.b	.flags
		move.l	d1,oxLIt_userdata(a3)
		bra.b	.tag_loop

.flags		cmp.w	#oxLIA_flags,d0
		bne.b	.prev
		move.b	d1,oxLIt_flags(a3)
		btst	#oxLIB_SELECTED,d1
		bne.b	.do_sel
		bra.b	.tag_loop

.prev		cmp.w	#oxLIA_previtem,d0
		bne.b	.selected
		move.l	d1,d2		; store append mode
		bra.b	.tag_loop

.selected	cmp.w	#oxLIA_selected,d0
		bne.b	.tag_loop
		tst.l	d1
		beq.b	.tag_loop
		bset	#oxLIB_SELECTED,oxLIt_flags(a3)

.do_sel		btst	#oxLB_MULTISELECT,oxL_flags(a0)
		bne.b	.tag_loop

		; deselect others items if not multiselect

		move.l	a3,oxL_prevselected(a0)

		lea	oxL_list(a0),a1
.item_loop	move.l	(a1),a1
		tst.l	(a1)
		beq.b	.tag_loop
		bclr	#oxLIB_SELECTED,oxLIt_flags(a1)
		bra.b	.item_loop

.init		; if this is the first item make it the top one

		tst.l	oxL_topitem(a0)
		bne.b	.add

		move.l	a3,oxL_topitem(a0)

.add		; add item to list

		addq.w	#1,oxL_items(a0)

		move.l	a3,a1
		lea	oxL_list(a0),a0

		tst.l	d2
		beq.b	.addtail
		bmi.b	.addhead

		; add new node at pos d2

		move.l	d2,a0
		move.l	MLN_SUCC(a0),a2
		move.l	a2,MLN_SUCC(a1)
		move.l	a1,MLN_SUCC(a0)
		move.l	a1,MLN_PRED(a2)
		move.l	a0,MLN_PRED(a1)

		rts

.addtail	ADDTAIL
		rts

.addhead	ADDHEAD
.rts		rts


L_initpointers	; init current/item related fields in oxList

		; get first and last ON status items for moving in table with cursor

		btst	#oxOLIB_OFF,oxLIt_flags(a3)
		bne.b	.get_top

.get_first	tst.l	oxL_firstonitem(a0)
		bne.b	.get_last
		move.l	a3,oxL_firstonitem(a0)
.get_last	move.l	a3,oxL_lastonitem(a0)

.get_top	tst.l	oxL_topitem(a0)
		bne.b	.not_first
		move.l	a3,oxL_topitem(a0)
.not_first
		; actives als actives eintragen, default überscheiben

		btst	#oxOLIB_ACTIVE,oxLIt_flags(a3)
		beq.b	.if_selected
		tst.l	oxL_activeitem(a0)
		bne	.clr_active
		move.l	a3,oxL_activeitem(a0)
		bra.b	.if_selected

.clr_active	bclr	#oxOLIB_ACTIVE,oxLIt_flags(a3)

.if_selected	; selected as prevselected merken für nicht-multiselect 

		tst.l	oxL_prevselected(a0)
		bne.b	.is_sel
		btst	#oxOLIB_SELECTED,oxLIt_flags(a3)
		beq.b	.rts
		move.l	a3,oxL_prevselected(a0)
		bra	.rts
.is_sel		btst	#oxLB_MULTISELECT,oxL_flags(a0)
		bne.b	.rts
		bclr	#oxOLIB_SELECTED,oxLIt_flags(a3)

.rts		rts


oxL_GET	move.l 	(a1),d1
		cmp.l	#oxA_pos,d1
		bne	.rts
		move.w	oxL_offset(a0),d0
.rts		rts

oxL_GETLAYOUT	move.l	oxL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),d0			; line height

		mulu.w	oxL_minlines(a0),d0

		add.w	#4,d0				; border
		move.w	oxL_spacing(a0),d2	; vspace oben und unten
		add.w	d2,d0
		add.w	d2,d0

		cmp.w	oxL_minheight(a0),d0
		bge.b	.setwh
		move.w	oxL_minheight(a0),d0

.setwh		move.w	oxL_minwidth(a0),oxLI_minwidth(a1)
		move.w	d0,oxLI_minheight(a1)
		move.w	oxL_propw(a0),oxLI_propw(a1)
		beq.b	.setph
		move.w	#$7fff,oxLI_maxwidth(a1)
.setph		move.w	oxL_proph(a0),oxLI_proph(a1)
		beq.b	.return_used
		move.w	#$7fff,oxLI_maxheight(a1)

.return_used	moveq	#1,d0
		rts

oxL_SETLAYOUT	move.l	oxLI_width(a1),oxL_width(a0)
		move.l	oxLI_left(a1),oxL_left(a0)

		bset	#oxLB_reset,oxL_internalflags(a3)

		move.l	oxL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2

		moveq	#0,d0
		move.w	oxL_height(a0),d0
		subq.w	#4,d0	; borders
		move.w	oxL_spacing(a0),d1
		add.w	d1,d1
		sub.w	d1,d0

		divu.w	rp_TxHeight(a2),d0

		move.w	d0,oxL_lines(a0)

		; default actives ist erstes ON von oben

		tst.l	oxL_activeitem(a0)
		bne.b	.get_pix
		move.l	oxL_firstonitem(a0),d0
		bne.b	.hasfirston
		move.l	oxL_list+LH_HEAD(a0),d0
.hasfirston	move.l	d0,a1
		tst.l	(a1)
		beq.b	.get_pix
		move.l	a1,oxL_activeitem(a0)
		bset	#oxOLIB_ACTIVE,oxLIt_flags(a1)

		; inpos von oben bis zum aktiven item 

.get_pix	clr.w	oxL_inpos(a0)
		clr.w	oxL_offset(a0)

		moveq	#0,d0
		move.l	oxL_list+LH_HEAD(a0),a5
		tst.l	(a5)
		sub.l	a4,a4
		beq.b	.reset_postop
		move.l	a5,oxL_topitem(a0)
		move.l	a5,a4
.find_active_lp	tst.l	(a5)
		beq.b	.reset_postop

		btst	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		bne.b	.set_inpos

		move.w	d0,d3
		add.w	#1,d3
		cmp.w	oxL_lines(a0),d3
		bge.b	.offset

		addq.w	#1,d0
		bra.b	.next_m

.offset		move.l	oxL_topitem(a0),a3
		move.l	LN_SUCC(a3),a3
		move.l	a3,oxL_topitem(a0)
		addq.w	#1,oxL_offset(a0)

.next_m		move.l	LN_SUCC(a5),a5
		bra.b	.find_active_lp

.reset_postop	move.l	a4,oxL_topitem(a0)
		moveq	#0,d0

.set_inpos	move.w	d0,oxL_inpos(a0)

		; set slider to list values and place it right

		move.l	a0,a3

		btst	#oxLB_NOSLIDER,oxL_flags(a3)
		bne.b	.columns				

		move.l	oxL_sliderobject(a3),d0
		beq	.columns
		move.l	d0,a0

		moveq	#OXM_setprop,d1
		lea	-oxPI_SIZEOF(a7),a7
		move.l	a7,a1
		move.w	oxL_items(a3),oxPI_max(a1)
		move.w	oxL_offset(a3),oxPI_pot(a1)
		move.w	oxL_lines(a3),oxPI_body(a1)
		jsr	_oxDoMethod(pc)
		lea	oxPI_SIZEOF(a7),a7

		; slider platzieren

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		move.w	oxL_left(a3),d0
		add.w	oxL_width(a3),d0
		subq.w	#1,d0			; border
		sub.w	oxL_sliderwidth(a3),d0
		move.w	d0,oxLI_left(a1)
		move.w 	oxL_top(a3),d1
		addq.w	#1,d1			; border
		move.w	d1,oxLI_top(a1)
		move.w	oxL_sliderwidth(a3),oxLI_width(a1)
		move.w	oxL_height(a3),d1
		subq.w	#2,d1
		move.w	d1,oxLI_height(a1)

		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		lea	oxLI_SIZEOF(a7),a7

.columns	; linke und rechte spalte %ual aufteilen

		move.w	oxL_leftpercent(a3),d4
		beq	.return_used

		move.w	oxL_width(a3),d2

		sub.w	oxL_sliderwidth(a3),d2

		subq.w	#5,d2	; borders
		swap	d2
		clr.w	d2
		swap	d2
		mulu	d4,d2
		divu	#100,d2
		move.w	d2,oxL_leftwidth(a3)

.return_used	moveq	#1,d0
		rts

oxL_UPDATE	; ?? recalc lenghts of all item strings ??

		bclr	#oxLB_update,oxL_internalflags(a3)
		beq	oxL_return_unused

		bset	#oxLB_incomming,oxL_internalflags(a3)

	;	moveq	#0,d4
	;	move.l	oxL_drawinfo(a3),a0
	;	move.l	oxDI_windowobject(a0),a0
	;	bsr	_oxBeginRefresh

		bsr.b	oxL_DR

	;	move.l	oxL_drawinfo(a3),a0
	;	move.l	oxDI_windowobject(a0),a0
	;	moveq	#0,d4
	;	movem.w	oxL_left(a3),d0-d3
	;	bra	_oxEndRefresh

	rts


oxL_DRAW	bclr	#oxLB_incomming,oxL_internalflags(a3)

oxL_DR		movem.w	oxL_left(a3),d0-d3
		move.l	oxL_drawinfo(a3),a2

		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

		bclr	#oxLB_reset,oxL_internalflags(a3)
	;	beq.b	.draw_content

		bsr	_in_frame_nofill

		sub.w	oxL_sliderwidth(a3),d2
		btst	#oxLB_NOSLIDER,oxL_flags(a3)
		bne.b	.fillbg
		addq.b	#1,d2
.fillbg
		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.rectfill

	bra.b	.rectfill


		move.l	oxL_drawinfo(a3),a1
		move.l	oxDI_imagetable(a1),a1
	;	move.l	oxIT_listbgimage(a1),d4
		beq.b	.rectfill

		move.l	d4,a0

		move.l	a2,a1
		bsr	_oxImageFill
		bra.b	.evtl_line

.rectfill	pushm	d0/d1

		move.b	oxPT_listpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)
		popm 	d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

.evtl_line	tst.w	oxL_leftpercent(a3)
		beq.b	.draw_content

		btst	#oxLB_NOSEPARATOR,oxL_flags(a3)
		bne	.draw_content

		; vertical separator between left and right side

		move.b	oxPT_darkpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	oxL_left(a3),d0-d3

		subq.w	#5,d3
		addq.w	#2,d0
		addq.w	#2,d1

		add.w	oxL_leftwidth(a3),d0
		move.w	d0,d2

		add.w	d1,d3

		movem.w	d2/d3,rp_cp_x(a2)

		move.l	a2,a1
		jsr	_LVODraw(a6)

.draw_content	move.w	oxL_top(a3),d1
		addq.w	#2,d1
		add.w	oxL_spacing(a3),d1

		move.l	oxL_topitem(a3),d0
		beq.b	.slider

		move.l	d0,a5
		move.w	oxL_lines(a3),d0
		beq.b	.slider

		subq.w	#1,d0
.line_lp	movem.w	d0/d1,-(a7)
		bsr.b	_draw_it
		movem.w	(a7)+,d0/d1
		add.w	rp_TxHeight(a2),d1

		move.l	LN_SUCC(a5),a5
		tst.l	(a5)
		beq.b	.slider

		dbf	d0,.line_lp

.slider		; update slider values and redraw it

		btst	#oxLB_incomming,oxL_internalflags(a3)
		bne.b	.rts_0

		move.l	oxL_sliderobject(a3),d0
		beq	.rts_0

		move.l	d0,a0
		lea	-oxPI_SIZEOF(a7),a7
		move.l	a7,a1
		moveq	#OXM_setprop,d1

		move.w	oxL_items(a3),oxPI_max(a1)
		move.w	oxL_offset(a3),oxPI_pot(a1)
		move.w	oxL_lines(a3),oxPI_body(a1)
		jsr	_oxDoMethod(pc)
		lea	oxPI_SIZEOF(a7),a7
		move.l	#OXM_UPDATE,d1
		jsr	_oxDoMethod(pc)

.rts_0		moveq	#0,d0
		rts

_draw_line	; a3 *list, a5 *item

		move.l	oxL_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		move.w	oxL_top(a3),d1
		addq.w	#2,d1
		add.w	oxL_spacing(a3),d1
		move.l	oxL_topitem(a3),d0
		beq.b	.rts
		move.l	d0,a4
		move.w	oxL_lines(a3),d0
		beq.b	.rts
		subq.w	#1,d0
.find_lp	cmp.l	a4,a5
		beq.b	_draw_it
		add.w	rp_TxHeight(a2),d1
		move.l	LN_SUCC(a4),a4
		tst.l	(a4)
		beq.b	.rts
		dbf	d0,.find_lp
.rts		rts

_draw_it	; (the table line), d1 ypos

		move.w	oxL_left(a3),d0
		move.w	oxL_width(a3),d2

		sub.w	oxL_sliderwidth(a3),d2
		btst	#oxLB_NOSLIDER,oxL_flags(a3)
		bne.b	.addframes
		addq.w	#1,d2

.addframes	add.w	d0,d2
		addq.w	#4,d0
		subq.w	#5,d2

		move.l	gfxbase(pc),a6

		move.w	d1,d3
		add.w	rp_TxHeight(a2),d3
		subq.w	#1,d3

		movem.w	d0-d3,-(a7)

		move.l	oxL_drawinfo(a3),a0
		move.l	oxDI_pentable(a0),a0

		move.b	oxPT_listtextpen(a0),d4
		move.b	oxPT_listpen(a0),d5
		move.b	oxLIt_flags(a5),d6
		beq.b	.draw

		btst	#oxOLIB_OFF,d6
		beq.b	.if_sel
		move.b	oxPT_listofftextpen(a5),d4
		move.b	oxPT_listpen(a0),d5
		bra.b	.draw

.if_sel		btst	#oxOLIB_SELECTED,d6
		beq.b	.if_altcolor
		move.b	oxPT_listtextpen(a0),d4
		btst	#oxOLIB_ALTCOLOR,d6
		beq.b	.sel
		move.b	oxPT_listalttextpen(a0),d4
.sel		move.b	oxPT_listselpen(a0),d5
		bra.b	.draw

.if_altcolor	btst	#oxOLIB_ALTCOLOR,d6
		beq.b	.draw
		move.b	oxPT_listalttextpen(a0),d4
		move.b	oxPT_listpen(a0),d5

.draw		; no background?

		; background

		move.w	d5,d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1

		move.w	oxL_leftwidth(a3),d5
		beq	.one_column_bg
		btst	#oxLB_NOSEPARATOR,oxL_flags(a3)
		bne.b	.one_column_bg

		pushm	d0/d1/d2

		add.w	d5,d0

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		popm	d0/d1/d2

		move.w	d0,d2
		add.w	d5,d2

		subq.w	#4,d2		; inner spacing

.one_column_bg	move.l	a2,a1
		jsr	_LVORectFill(a6)	

.if_active	move.w	oxL_leftwidth(a3),d5

		btst	#oxLB_ACTIVE,oxL_flags(a3)
		beq.b	.texts

		btst	#oxOLIB_OFF,d6
		bne.b	.texts

		btst	#oxOLIB_ACTIVE,d6
		beq.b	.texts

		pushm	d4/d5

		move.l	oxL_drawinfo(a3),a0
		move.l	oxDI_pentable(a0),a0		
		move.b	oxPT_cursorpen(a0),d4
		move.b	d4,d5

		move.w	#%1010101010101010,rp_LinePtrn(a2)

		movem.w 8(a7),d0/d1

		bsr	_draw_bevel_border

		move.w	#$ffff,rp_LinePtrn(a2)

		popm	d4/d5

.texts		; colors and drawmode

		move.l	gfxbase(pc),a6

		moveq 	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		move.w	d4,d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		; has left side text

		tst.l	oxLIt_text(a5)
		beq	.nolefttext

		; cliprect

		movem.w	(a7),d0-d3
		movem.w	d0/d1,oxL_Region+rg_bounds+ra_MinX(a3)
		tst.w	d5	; has left column width?
		beq.b	.setmax
		move.w	d0,d2
		add.w	d5,d2
		subq.w	#5,d2	; frame
.setmax		movem.w	d2/d3,oxL_Region+rg_bounds+ra_MaxX(a3)
		sub.w	d0,d2
		sub.w	d1,d3
		movem.w	d2/d3,oxL_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	layersbase(pc),a6
		lea	oxL_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxL_oldregion(a3)

		movem.w	(a7),d0/d1
		add.w	rp_TxBaseline(a2),d1
		movem.w	d0/d1,rp_cp_x(a2)

		move.l	oxLIt_text(a5),d0
		move.l	d0,a0
		move.w	oxLIt_textlenght(a5),d0
		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOText(a6)

		move.l	layersbase(pc),a6
		move.l	oxL_oldregion(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
.nolefttext
		move.l	oxLIt_rtext(a5),d5
		beq.b	.norighttext

		move.l	(a7),d0
		move.w	oxL_leftwidth(a3),d1
		beq.b	.no_left
		swap	d0
		add.w	d1,d0
		addq.w	#1,d0
		swap	d0
.no_left	move.l	d0,oxL_Region+rg_bounds+ra_MinX(a3)
		move.l	4(a7),d1
		move.l	d1,oxL_Region+rg_bounds+ra_MaxX(a3)
		sub.l	d0,d1
		move.l	d1,oxL_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	layersbase(pc),a6
		lea	oxL_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxL_oldregion(a3)

		btst	#oxLB_RIGHT_ALIGN_LEFT,oxL_flags(a3)
		beq	.align_right

		movem.w	(a7),d0/d1
		add.w	oxL_leftwidth(a3),d0
		addq.w	#1,d0		; annother pix spacing in rel to center separator line
		
		bra.b	.set_rtext_xy

.align_right	move.l	d5,a0
		move.w	oxLIt_rtextlenght(a5),d0
		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOTextLength(a6)
		move.w	d0,d4

		movem.w	(a7),d0/d1
		add.w	oxL_width(a3),d0
		sub.w	d4,d0

		sub.w	oxL_sliderwidth(a3),d0
		btst	#oxLB_NOSLIDER,oxL_flags(a3)
		bne.b	.subframes
		addq.w	#1,d0

.subframes	subq	#8,d0
.set_rtext_xy	add.w	rp_TxBaseline(a2),d1
		movem.w	d0/d1,rp_cp_x(a2)

		move.l	d5,a0
		move.w	oxLIt_rtextlenght(a5),d0
		move.l	a2,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOText(a6)

		move.l	layersbase(pc),a6
		move.l	oxL_oldregion(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
.norighttext
		movem.w (a7)+,d0-d3
		rts

oxL_INTUI	move.l	oxL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6
		move.l	a0,a3

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq.b	oxL_buttons

		cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq	.key

		btst	#oxLB_ACTIVE,oxL_flags(a0)
		beq	.return_unused

		cmp.l	#IDCMP_MOUSEMOVE,im_Class(a1)
		beq	oxL_mousemove

		cmp.l	#IDCMP_INTUITICKS,im_Class(a1)
		beq	oxL_ticks

		; raw keys

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		bne.b	.return_unused

		cmp.w	#$42,im_Code(a1)
		bne.b	oxL_if_up

		move.l	oxL_prev(a0),d0
		bra.b	.nextprev

.key		; vanilla keys

	 	move.b	oxL_senschar(a0),d0
		cmp.b	im_Code+1(a1),d0
		beq	oxL_go_active

		btst	#oxLB_ACTIVE,oxL_flags(a0)
		beq	.return_unused

		cmp.b	#$20,im_Code+1(a1)
		beq.b	.space_toggle

		cmp.w	#$9,im_Code(A1)
		bne.b	.return_unused

		move.l	oxL_next(a0),d0
		bra.b	.nextprev

.return_unused	moveq	#0,d0
		rts

.nextprev	push	d0
	;	bsr	oxL_go_inactive

		; activate next / prev

		pop	d0
		beq	.return_used
		move.l	d0,a0
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod

.return_used	moveq	#1,d0
		rts

.space_toggle	btst	#oxLB_MULTISELECT,oxL_flags(a3)
		bne.b	.select_new

		move.l	oxL_prevselected(a3),d0
		beq.b	.select_new

		move.l	d0,a5
		bclr	#oxOLIB_SELECTED,oxLIt_flags(a5)
		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

.select_new	move.l	oxL_activeitem(a3),a5
		move.l	a5,oxL_prevselected(a3)
		btst	#oxOLIB_UNSELECTABLE,oxLIt_flags(a5)
		bne.b	.selhook
		bchg	#oxOLIB_SELECTED,oxLIt_flags(a5)

		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

.selhook	move.l	oxL_selhook(a3),d0
		beq	.if_down

		pushm	d1-a6

		move.l	a3,a0
		move.l	a5,a1
		move.l	oxL_userdata(a3),a2
		move.l	oxO_userbase(a3),a4
		move.l	oxLIt_userdata(a5),a3
		move.l	libbase(pc),a6

		move.l	d0,a5
		jsr	(a5)

		popm	d1-a6

.if_down	; option: space toggle sends cursor down

		btst	#oxLB_AUTODOWN,oxL_flags(A3)
		bne.b	.autodown

		moveq	#1,d0			; used, dont send again in for-all-broadcast

		rts

.autodown	cmp.l	oxL_lastonitem(a3),a5
		beq	_draw_line
		bra.b	oxL_down

oxL_if_up	cmp.w	#CURSORUP,im_Code(a1)
		bne.b	oxL_if_down

oxL_up		tst.w	oxL_inpos(a3)
		beq.b	up_offset
		subq.w	#1,oxL_inpos(a3)

		move.l	oxL_activeitem(a3),a5
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)

		btst	#oxOLIB_OFF,oxLIt_flags(a5)
		bne.b	.off
	pushm	a0-a4
		bsr	_draw_line
	popm	a0-a4
.off
		move.l	LN_PRED(a5),a5
		move.l	a5,oxL_activeitem(a3)

		bset	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		bra	_draw_line

up_mouse

up_offset	tst.w	oxL_offset(a3)
		beq.b	oxL_return_unused
		subq.w	#1,oxL_offset(a3)

		move.l	oxL_topitem(a3),a5
		move.l	LN_PRED(a5),d0
		beq	oxL_return_unused
		move.l	d0,a5
		move.l	a5,oxL_topitem(a3)

		move.l	oxL_activeitem(a3),a5
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)

		move.l	LN_PRED(a5),d0
		beq	oxL_return_unused
		move.l	d0,a5
		move.l	a5,oxL_activeitem(a3)

		bset	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		bra	oxL_DRAW

oxL_return_unused	moveq	#0,d0
			rts

oxL_return_used	moveq	#1,d0
			rts

oxL_ticks	movem.w	oxL_left(a3),d0-d3
		sub.w	oxL_sliderwidth(a3),d2
		bsr	_is_in_rect
		bne.b	oxL_return_unused

oxL_mousemove	btst	#oxLB_MOUSEPRESSEDON,oxL_flags(a3)
		beq.b	oxL_return_unused

		move.l	im_IDCMPWindow(a1),a4

		moveq	#0,d5
		move.b	wd_BorderTop(a4),d5
		neg.w	d5
		add.w	im_MouseY(a1),d5

		move.w	oxL_top(a3),d0
		move.w	oxL_height(a3),d2
		subq.w	#1,d2
		add.w	d0,d2
		cmp.w	d5,d0
		bge	up_mouse
		cmp.w	d5,d2
		ble	down_mouse

		bsr	 oxL_mouse

		bra.b	oxL_return_used

oxL_if_down	cmp.w	#CURSORDOWN,im_Code(a1)
		bne.b	oxL_return_unused

oxL_down	move.w	oxL_items(a3),d1
		sub.w	oxL_offset(a3),d1
		subq.w	#1,d1
		cmp.w	oxL_inpos(a3),d1
		ble.b	oxL_return_unused

		move.w	oxL_inpos(a3),d0
		add.w	#1,d0
		cmp.w	oxL_lines(a3),d0
		bge.b	down_offset
		move.w	d0,oxL_inpos(a3)

		move.l	oxL_activeitem(a3),a5
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)
	pushm	a0-a4 ;???????????????????????????????????????
		bsr	_draw_line
	popm	a0-a4

		move.l	LN_SUCC(a5),a5
		move.l	a5,oxL_activeitem(a3)

		bset	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		bra	_draw_line

down_mouse	move.w	oxL_lines(a3),d0

down_offset	add.w	oxL_offset(a3),d0
		cmp.w	oxL_items(a3),d0
		bge.b	oxL_return_unused
		addq.w	#1,oxL_offset(a3)

		move.l	oxL_topitem(a3),a5
		move.l	LN_SUCC(a5),a5
		move.l	a5,oxL_topitem(a3)

		move.l	oxL_activeitem(a3),a5
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		move.l	LN_SUCC(a5),a5
		move.l	a5,oxL_activeitem(a3)

		bset	#oxOLIB_ACTIVE,oxLIt_flags(a5)

		bra	oxL_DRAW


oxL_buttons	cmp.w	#SELECTDOWN,im_Code(a1)
 		beq.b	oxL_if_inside

		btst	#oxLB_ACTIVE,oxL_flags(a3)
		beq	oxL_return_unused

		cmp.w	#SELECTUP,im_Code(a1)
		beq	l_mouseup
		bra	oxL_return_unused	

oxL_if_inside	movem.w	oxL_left(a3),d0-d3

		sub.w	oxL_sliderwidth(a3),d2

		bsr	_is_in_rect
		beq	oxL_return_unused

	;	bne.b	oxL_mouse
	;
	;	btst	#oxLB_ACTIVE,oxL_flags(a3)
	;	beq	oxL_return_unused
	;
	;	bsr	oxL_go_inactive	; cancel active state when clicked outside
	;
	;	bra	oxL_return_unused	

oxL_mouse	bset	#oxLB_MOUSEPRESSEDON,oxL_flags(a3)

		move.l	oxL_activeitem(a3),d0
		beq.b	.if_multisel

		move.l	d0,a5
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		beq.b	.if_multisel

		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

.if_multisel	; if not multiselect, clear prev item

		btst	#oxLB_MULTISELECT,oxL_flags(a3)
		bne.b	.set_current

		move.l	oxL_prevselected(a3),d0
		beq.b	.set_current

		move.l	d0,a5

		bclr	#oxOLIB_SELECTED,oxLIt_flags(a5)
		bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)

		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

.set_current	; list clicked with mouse calc pos item

	;	move.l	im_IDCMPWindow(a1),a0
	;	moveq	#0,d0
	;	move.b	wd_BorderTop(a0),d0
	;	neg.w	d0
	;	add.w	im_MouseY(a1),d0

		moveq	#0,d0
		move.w	im_MouseY(a1),d0
		add.w	#1,d0

		sub.w	oxL_top(a3),d0
		subq.w	#4,d0	; border
		sub.w	oxL_spacing(a3),d0
		sub.w	oxL_spacing(a3),d0

		divu.w	rp_TxHeight(a2),d0
		tst.w	d0
		beq.b	.isnull

		subq.w	#1,d0

.isnull		move.w	d0,oxL_inpos(a3)

		move.w	d0,d1

		move.l	oxL_topitem(a3),d5
		beq.b	.return_unused
		move.l	d5,a5

		move.w	oxL_lines(a3),d2
		cmp.w	d2,d1
		bge.b	.return_unused

		move.w	oxL_items(a3),d2
		cmp.w	d2,d1
		bge.b	.return_unused

		tst.w	d1
		beq	.is_no_inpos
		subq.w	#1,d1

.to_undermouse	tst.l	(a5)
		beq.b	.return_unused
		move.l	LN_SUCC(a5),a5
		dbf	d1,.to_undermouse
.is_no_inpos
		move.l	a5,oxL_activeitem(a3)

		move.l	a5,oxL_prevselected(a3)

		btst	#oxOLIB_UNSELECTABLE,oxLIt_flags(a5)
		bne.b	.gact
		bchg	#oxOLIB_SELECTED,oxLIt_flags(a5)

.gact		; turn on list

		pushm	d0-a6
		move.l	a3,a0
		bsr	oxL_go_active
		popm	d0-a6

.return_used	moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts

l_mouseup	movem.w	oxL_left(a3),d0-d3
		sub.w	oxL_sliderwidth(a3),d2
		bsr	_is_in_rect
		beq	oxL_return_unused

		move.l	oxL_activeitem(a3),d0
		beq.b	oxL_return_unused
		move.l	d0,a5
	;	bclr	#oxOLIB_ACTIVE,oxLIt_flags(a5)
		bclr	#oxLB_MOUSEPRESSEDON,oxL_flags(a3)

		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

		bsr	oxL_hooks


.return_used	moveq	#1,d0
.rts		rts

oxL_hooks	pushm	d1-a6

		move.l	oxL_selhook(a3),d0
		beq	.if_double

		move.l	a3,a0
		move.l	a5,a1
		move.l	oxL_userdata(a3),a2
		move.l	oxO_userbase(a3),a4

		move.l	oxLIt_userdata(a5),a3
		move.l	libbase(pc),a6

		move.l	d0,a5
		jsr	(a5)

		movem.l	(a7),d1-a6

.if_double	move.w	oxL_inpos(a3),d4
		move.w	oxL_oldinpos(a3),d5
		move.w	d4,oxL_oldinpos(a3)

		move.l	oxL_seconds(a3),d0
		move.l	oxL_micros(a3),d1
		move.l	im_Seconds(a1),d2
		move.l	im_Micros(a1),d3
		move.l	d2,oxL_seconds(a3)
		move.l	d3,oxL_micros(a3)

		cmp.w	d5,d4
		bne.b	.return_unused

		move.l	intbase(pc),a6
		jsr	_LVODoubleClick(a6)
		tst.l	d0
		beq	.return_unused

		move.l	oxL_dchook(a3),d0
		beq	.return_unused

		move.l	a3,a0
		move.l	a5,a1
		move.l	oxL_userdata(a3),a2
		move.l	oxO_userbase(a3),a4
		move.l	oxLIt_userdata(a5),a3

		move.l	libbase(pc),a6

		move.l	d0,a5
		jsr	(a5)

		moveq	#1,d0
		bra.b	.resta
.return_unused	moveq	#0,d0
.resta		popm	d1-a6
		rts

oxL_go_active	move.l	a0,a3
		
		move.l	oxL_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6

		bset	#oxLB_ACTIVE,oxL_flags(a3)
		bne	.win_unknown

		move.l	a3,d1
		move.l	oxL_drawinfo(a3),d0
		beq.b	.win_unknown
		move.l	d0,a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		move.l	#oxWA_tickuser,d0
		bsr	_oxSetAttr
.win_unknown
		move.l	oxL_activeitem(a3),d0
		bne.b	.has_active
		move.l	oxL_list+LH_HEAD(a3),a5
		tst.l	(a5)
		beq.b	.return_unused
		move.l	a5,oxL_activeitem(a3)
		bra.b	.gotit
.has_active	move.l	d0,a5
.gotit		
		bset	#oxOLIB_ACTIVE,oxLIt_flags(a5)
	;	bne	.return_used		

		pushm	a0-a4
		bsr	_draw_line
		popm	a0-a4

.return_used	moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts

oxL_go_inactive
		move.l	oxL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	gfxbase(pc),a6

		bclr	#oxLB_ACTIVE,oxL_flags(a0)
		beq	.return_unused

		move.l	oxL_activeitem(a0),d0
		beq.b	.return_unused

		move.l	d0,a5
	
		move.l	a0,a3

		bsr	_draw_line

		moveq	#0,d1
		move.l	oxL_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_tickuser,d0
		bsr	_oxSetAttr

.return_used		moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts

;--------------------------------------------------------------------
; OX_SLIDER (vert)

 STRUCTURE	oxSlider,oxO_SIZEOF
	UWORD	oxSl_minwidth
	UWORD	oxSl_minheight
	UWORD	oxSl_left
	UWORD	oxSl_top
	UWORD	oxSl_right
	UWORD	oxSl_bottom
	UWORD	oxSl_mousepos
	UWORD	oxSl_pixsize	; inner pixel height of container (the refresh area)
	UWORD	oxSl_knobpix	; pixel size of knob = pixsize * body / max
	UWORD	oxSl_pixpos	; pixel dist of knob = (pixsize - ?knobpix?) * pot / max
	UWORD	oxSl_minknobpix
	UWORD	oxSl_pot	; number of scrolled out items = ??
	UWORD	oxSl_body	; number of visible items
	UWORD	oxSl_max	; number of items total
	UWORD	oxSl_min	; added to pot before sent down
	UWORD	oxSl_oldsoft
	UWORD	oxSl_softval
	UWORD	oxSl_softbody	; these three are internal for smooth scolling
	UWORD	oxSl_softmax	
	UBYTE	oxSl_flags
	UBYTE	oxSl_pad
	APTR	oxSl_receiver
	APTR	oxSl_drawinfo
	ULONG	oxSl_seconds
	LABEL	oxSl_SIZEOF


	OXICLASSHEADER	slider, 0, 9, horizgroup

	dc.l	oxCA_objectsize,oxSl_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,SL_create_ex
	dc.l	TAG_END	

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq	slider_INTUI

		cmp.w	#OXM_SET,d1
		beq	slider_SET

		cmp.w	#OXM_GETLAYOUT,d1
		beq	slider_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	slider_SETLAYOUT

		cmp.w	#OXM_setprop,d1
		beq	slider_setprop

		cmp.w	#OXM_INIT,d1
		beq.b	slider_INIT

		cmp.w	#OXM_DRAW,d1
		beq	slider_DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	slider_INCOMMINGUPDATE

		cmp.w	#OXM_SETDEF,d1
		beq.b	slider_SETDEF

		cmp.w	#OXM_WINDOWCLOSING,d1
		beq.b	slider_WINCLS

		cmp.w	#OXM_INACTIVE,d1
		beq	oxSl_go_inact

		rts

SL_create_ex	lea	.example(pc),a2
		moveq	#0,d2
		bra	_oxCreateObject

.example	dc.l	OX_BUFFER,.buffer

 STRUCTURE	slx,0
	APTR	slx_slider1
	APTR	slx_slider2
	APTR	slx_slider3
	APTR	slx_slider4
	LABEL	slx_SIZEOF

.buffer		dc.l	oxBfA_buffersize,slx_SIZEOF
		dc.l	OX_HORIZGROUP,.hzgroup
		dc.l	TAG_END

.hzgroup	dc.l	OX_SLIDER,.slider
		dc.l	OX_SLIDER,.slider2
		dc.l	OX_SLIDER,.sliderA
		dc.l	OX_SLIDER,.slider4
		dc.l	oxGA_vprop,1
		dc.l	TAG_END

.slider		dc.l	oxSlA_minheight,100		; funzt net
		dc.l	oxSlA_max,8
		dc.l	OX_CONNECT,.toA
		dc.l	OX_CONNECT,.to2
		dc.l	OX_RELPTR,slx_slider1
		dc.l	TAG_END
.slptr		dc.l	0

.toA		dc.l	oxCCA_target,slx_slider2|OX_REL
.more		dc.l	oxCCA_attr,oxSlA_softval
		dc.l	oxCCA_newattr,oxSlA_softval
		dc.l	TAG_END

.to2		dc.l	oxCCA_target,slx_slider3|OX_REL
		dc.l	TAG_MORE,.more

.sliderA	dc.l	oxSlA_minheight,100		; funzt net
		dc.l	oxSlA_max,8
		dc.l	OX_RELPTR,slx_slider2
		dc.l	OX_CONNECT,.to
		dc.l	TAG_END
.slAptr		dc.l	0

.to		dc.l	oxCCA_target,slx_slider1|OX_REL
		dc.l	TAG_MORE,.more

.slider2	dc.l	oxSlA_minheight,100		; funzt net
		dc.l	oxSlA_max,40
		dc.l	oxSlA_body,20
		dc.l	oxSlA_flip,TRUE
		dc.l	OX_RELPTR,slx_slider3
		dc.l	OX_CONNECT,.to4
		dc.l	TAG_END
.sl2ptr		dc.l	0

.to4		dc.l	oxCCA_target,slx_slider4|OX_REL
		dc.l	TAG_MORE,.more

.slider4	dc.l	oxSlA_minheight,100		; funzt net
		dc.l	oxSlA_max,40
		dc.l	oxSlA_body,20
		dc.l	OX_RELPTR,slx_slider4
		dc.l	OX_CONNECT,.to2
		dc.l	TAG_END
.sl4ptr		dc.l	0


slider_WINCLS	clr.l	oxSl_knobpix(a0)	;knopix,pixpos
		bclr	#oxSlB_LAYOUTSET,oxSl_flags(a0)
		rts

slider_SETDEF	move.l	#$00120030,oxSl_minwidth(a0)
		move.w	#$20,oxSl_minknobpix(a0)

		move.b	#oxSlF_in_frame+oxSlF_pattern,oxSl_flags(a0)

		move.w	#0,oxSl_pot(a0)	; number of scrolled out items = ??
		move.w	#1,oxSl_body(a0)	; number of visible items
		move.w	#1,oxSl_max(a0)	; number of items total

		; init soft draging

		move.w	#0,oxSl_softval(a0)			; highres for position
		move.w	#OXPROP_SOFTMAX,oxSl_softbody(a0)	; highres for visible
		move.w	#OXPROP_SOFTMAX,oxSl_softmax(a0)	; highres for total

		rts

slider_SET	movem.l	(a1),d0/d1

		cmp.l	#oxSlA_flip,d0
		bne.b	.base1
		moveq	#oxSlF_FLIP,d0

.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxSl_flags(a0)
		rts

.clearflag	not.w	d0
		and.b	d0,oxSl_flags(a0)
		rts

.base1		cmp.l	#oxSlA_base1,d0
		bne.b	.softval
		moveq	#oxSlF_BASE1,d0
		bra.b	.flag

.softval	cmp.w	#oxSlA_softval,d0
		bne.b	.0

		move.w	#OXPROP_SOFTMAX,d0
		sub.w	oxSl_softbody(a3),d0
		mulu.w	d0,d1

		divu.w	#OXPROP_SOFTMAX,d1

		btst	#oxSlB_FLIP,oxSl_flags(a3)
		beq.b	.set_sv

		move.w	#OXPROP_SOFTMAX,d0
		sub.w	d1,d0
		sub.w	oxSl_softbody(a3),d0
		move.w	d0,d1

.set_sv		move.w	d1,oxSl_softval(a0)

		rts
.0		cmp.w	#oxSlA_pot,d0
		bne.b	.a
		move.w	d1,oxSl_pot(a0)

		bsr	slider_INIT

		rts


.a		cmp.l	#oxSlA_body,d0
		bne.b	.b
		move.w	d1,oxSl_body(a0)
		rts
.b		cmp.l	#oxSlA_flags,d0
		bne.b	.i
		move.b	d1,oxSl_flags(a0)
		rts
.i		cmp.l	#oxA_drawinfo,d0
		bne.b	.h
		move.l	d1,oxSl_drawinfo(a0)
		rts
.h		cmp.l	#oxSlA_max,d0
		bne.b	.f
		move.w	d1,oxSl_max(a0)
		rts
.f		cmp.l	#oxA_receiver,d0
		bne	.g
		move.l	d1,oxSl_receiver(a0)
.g
		rts

slider_GETLAYOUT
		move.l	oxSl_minwidth(a0),oxLI_minwidth(a1)
		moveq	#1,d0
		rts


slider_setprop	move.w	oxPI_max(a1),oxSl_max(a0)
		move.w	oxPI_pot(a1),oxSl_pot(a0)
		move.w	oxPI_body(a1),oxSl_body(a0)

slider_INIT	tst.w	oxSl_max(a0)
		beq.b	.rts_ok

		move.w	oxSl_softmax(a0),d0

		btst	#oxSlB_FLIP,oxSl_flags(a0)
		bne.b	.init_flip

		mulu.w	oxSl_pot(a0),d0
		bra.b	.init_calc

.init_flip	move.w	oxSl_max(a0),d1
		sub.w	oxSl_pot(a0),d1
		sub.w	oxSl_body(a0),d1
		mulu.w	d1,d0

.init_calc
		move.w	oxSl_max(a0),d1
		divu.w	d1,d0

		move.w	oxSl_softval(a0),oxSl_oldsoft(a0)

		move.w	d0,oxSl_softval(a0)

		move.w	oxSl_softmax(a0),d0

		; check if visible is greater items, if so use max as body

		move.w	oxSl_body(a0),d1
		cmp.w	oxSl_max(a0),d1
		bge	.set_softbody

		mulu.w	oxSl_body(a0),d0
		divu.w	oxSl_max(a0),d0

.set_softbody	move.w	d0,oxSl_softbody(a0)

.rts_ok		moveq	#1,d0
		rts

slider_SETLAYOUT
		movem.w	oxLI_left(a1),d0-d3
		add.w	d0,d2
		subq.w	#1,d2
		add.w	d1,d3
		subq.w	#1,d3
		movem.w	d0-d3,oxSl_left(a0)

		; calc total pixsize of useable container

		sub.w	d1,d3
		subq.w	#2,d3					; sub hole frame

		btst	#oxSlB_in_frame,oxSl_flags(a0)	; sub in-frame
		beq.b	.set_size

		subq.w	#2,d3

.set_size	move.w	d3,oxSl_pixsize(a0)

		bset	#oxSlB_LAYOUTSET,oxSl_flags(a0)

		moveq	#1,d0
		rts

slider_INCOMMINGUPDATE

		btst	#oxSlB_LAYOUTSET,oxSl_flags(a3)
		beq.b	.rts

	;	moveq	#0,d4
	;	move.l	oxSl_drawinfo(a3),a0
	;	move.l	oxDI_windowobject(a0),a0
	;	bsr	_oxBeginRefresh

		bsr	slider_UPDATE

	;	move.l	oxSl_drawinfo(a3),a0
	;	move.l	oxDI_windowobject(a0),a0
	;	moveq	#0,d4
	;	movem.w	oxSl_left(a3),d0-d3
	;	sub.w	d0,d2
	;	sub.w	d1,d3
	;	addq.w	#1,d2
	;	addq.w	#1,d3
	;	bra	_oxEndRefresh

.rts		rts

slider_DRAW
slider_UPDATE	move.l	oxSl_drawinfo(a3),a5
		move.l	oxDI_pentable(a5),a5

		btst	#oxSlB_LAYOUTSET,oxSl_flags(a3)
		beq.b	.rts

		move.l	gfxbase(pc),a6
		move.l	oxSl_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		; recalc pixel dist and knob pixel size

		; knob size = total size * vis. items / items
		; knob pos = ( total size - knobsize ) * pred. items / ( items - vis.items)

		; pred. items = ??

;knobpix = (body/max * pixsize) +1
;If (knobpix<10) knobpix=10

		move.w	oxSl_pixsize(a3),d4

		move.w	oxSl_softbody(a3),d0
		beq.b	.is_max

		move.w	oxSl_softmax(a3),d1
		beq.b	.is_max

		cmp.w	d1,d0
		bge.b	.is_max

		mulu.w	d0,d4
		divu.w	d1,d4

		cmp.w	oxSl_pixsize(a3),d4
		beq.b	.is_max
		addq.w	#1,d4
.is_max
		cmp.w	oxSl_minknobpix(a3),d4
		bge.b	.no_min
		move.w	oxSl_minknobpix(a3),d4
.no_min
		move.w	d4,oxSl_knobpix(a3)

		move.w	oxSl_pixsize(a3),d5
		sub.w	oxSl_knobpix(a3),d5
		mulu.w	oxSl_softval(a3),d5
		move.w	oxSl_softmax(a3),d1
		beq.b	.set_pixpos
		sub.w	oxSl_softbody(a3),d1
		beq.b	.set_pixpos

		; runden: die Hälfte des Divisors zum Dividend addieren,
		; 	  (divd + divs / 2) / divs

		moveq	#0,d2
		move.w	d1,d2
		lsr.w	#1,d2
		add.l	d2,d5
		;     divs divd  
		divu.w	d1,d5

.set_pixpos	move.w	d5,oxSl_pixpos(a3)

		movem.w	oxSl_left(a3),d0-d3

		btst	#oxSlB_in_frame,oxSl_flags(a3)
		beq.b	.draw_hole

		; draw in-frame

		move.b	oxPT_darkpen(a5),d4		; topleft color
		move.b	oxPT_shinepen(a5),d5		; bottomright color

		bsr	_draw_bevel_border

		; black hole
	
		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

.draw_hole	move.b	oxPT_blackpen(a5),d4		; topleft color
		move.b	d4,d5				; bottomright color

		bsr	_draw_bevel_border

		; background

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.l	gfxbase(pc),a6

		btst	#oxSlB_pattern,oxSl_flags(a3)
		beq.b	.no_pattern

		movem.w	d0/d1/d2,-(a7)

		lea	sliderpattern(pc),a4
		move.w	(a4)+,d0
		move.b	d0,rp_AreaPtSz(a2)
		move.b	(a4)+,d0
		move.b	(a5,d0.w),d0
		moveq	#0,d1
		move.b	(a4)+,d1
		move.l	a4,rp_AreaPtrn(a2)
		move.b	(a5,d1.w),d1
		moveq 	#RP_JAM2,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		movem.w	(a7),d0/d1/d2
		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1/d2

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

		bra.b	.draw_knob

.no_pattern	movem.w	d0/d1,-(a7)

		move.l	a2,a1
		move.b	oxPT_inputpen(a5),d0		; block color
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1

.draw_knob	add.w	oxSl_pixpos(a3),d1
		move.w	d1,d3
		add.w	oxSl_knobpix(a3),d3

		move.b	oxPT_shinepen(a5),d4	; topleft color
		move.b	oxPT_darkpen(a5),d5	; bottomright color

		bsr	_draw_bevel_border

		movem.w	d0/d1,-(a7)

		move.b	oxPT_buttonpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7)+,d0/d1

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.l	libbase(pc),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.rectfill

		move.l	oxSl_drawinfo(a3),a1
		move.l	oxDI_imagetable(a1),a1
		move.l	oxIT_sliderimage(a1),d4
		beq.b	.rectfill

		movem.w	d2-d3,-(a7)

		move.l	d4,a0

		move.w	d0,d4
		move.w	d1,d5

		move.l	a2,a1
		bsr	_oxImageFill
		bra.b	.pop

.rectfill	movem.w	d0/d1,-(a7)
		move.l	a2,a1
		jsr	_LVORectFill(a6)
		movem.w	(a7)+,d0/d1
		bra.b	.profile

.pop		movem.w	(a7)+,d2-d3

.profile	; draw slider profile		

		sub.w	d1,d3
		asr.w	#1,d3
		add.w	d3,d1
		move.w	d1,d3

		addq.w	#1,d0
		subq.w	#1,d2

		move.w	d0,-(a7)

		movem.w	d0/d3,rp_cp_x(a2)

		move.b	oxPT_darkpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	d2,d0
		move.w	d3,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)

		move.b	oxPT_shinepen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	(a7)+,d0

		addq.w	#1,d3
		movem.w	d0/d3,rp_cp_x(a2)

		move.w	d2,d0
		move.w	d3,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)

.rts		moveq	#0,d0
		rts

sliderpattern	dc.w	1				; Höhe in Zeilen-1
		dc.b	oxPT_inputpen,oxPT_blackpen	; Farben f,b
		dc.w	%1010101010101010
		dc.w	%0101010101010101

slider_INTUI	cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq	.mousebuttons

		btst	#oxSlB_ACTIVE,oxSl_flags(a3)
		beq	.return_unused

		cmp.l	#IDCMP_MOUSEMOVE,im_Class(a1)
		beq	.mousemove

		cmp.l	#IDCMP_INTUITICKS,im_Class(a1)
		beq	.ticks

		rts

.mousebuttons	cmp.w	#SELECTDOWN,im_Code(a1)
 		beq.b	.if_inside

		btst	#oxSlB_ACTIVE,oxSl_flags(a3)
		beq	.return_unused

		cmp.w	#SELECTUP,im_Code(a1)
		beq	.mouseup
		bra	.return_unused	

.if_inside	movem.w	oxSl_left(a3),d0-d3
		bsr	_is_in_rect_br
		beq	.return_unused

		; mouse pressed inside container

		move.l	im_Seconds(a1),oxSl_seconds(a3)

		move.l	a3,d1
		move.l	oxSl_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr
		move.l	#oxWA_tickuser,d0
		bsr	_oxSetAttr
.no_win
		bset	#oxSlB_ACTIVE,oxSl_flags(a3)

		move.w	oxSl_top(a3),d1

		add.w	oxSl_pixpos(a3),d1			; hole border
		btst	#oxSlB_in_frame,oxSl_flags(a3)	; inframe
		beq	.add_pixpos
		addq.w	#1,d1
.add_pixpos	move.w	d1,d3
		add.w	oxSl_knobpix(a3),d3

		cmp.w	d5,d1
		bgt.b	.above_knob
		cmp.w	d5,d3
		blt.b	.below_knob

		; mouse pressed on knob

		bset	#oxSlB_SLIDING,oxSl_flags(a3)

		move.w	im_MouseY(a1),oxSl_mousepos(a3)

		moveq	#0,d1
		move.l	oxSl_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_tickuser,d0
		bsr	_oxSetAttr

		bra	.return_used

.mousemove	btst	#oxSlB_SLIDING,oxSl_flags(a3)
		beq.b	.return_unused

.ticks		move.l	im_IDCMPWindow(a1),a2
		moveq	#0,d5
		move.b	wd_BorderTop(a2),d5
		neg.w	d5
		add.w	im_MouseY(a1),d5

		move.w	oxSl_top(a3),d1

		addq.w	#1,d1					; hole boder
		btst	#oxSlB_in_frame,oxSl_flags(a3)	; inframe
		beq	.sel_knob
		addq.w	#1,d1

.sel_knob	btst	#oxSlB_SLIDING,oxSl_flags(a3)
		beq.b	.not_sliding

		; pixpos um mausdistanz verändern, ränder beachten,
		; softval = (maximum-visible)*pixpos/(container-knob)

		moveq	#0,d0
	
		move.w	oxSl_pixsize(a3),d1
		sub.w	oxSl_knobpix(a3),d1
		beq.b	.set

		move.w	im_MouseY(a1),d2

		move.w	oxSl_mousepos(a3),d0
		sub.w	d2,d0
		sub.w	d0,oxSl_pixpos(a3)
		bge.b	.greater

		clr.w	oxSl_pixpos(a3)
		bra.b	.calc

.greater 	cmp.w	oxSl_pixpos(a3),d1
		bge.b	.pos

		move.w	d1,oxSl_pixpos(a3)
		bra.b	.calc

.pos		move.w	d2,oxSl_mousepos(a3)

.calc		move.w	oxSl_softmax(a3),d0
		sub.w	oxSl_softbody(a3),d0
		mulu.w	oxSl_pixpos(a3),d0

; die Hälfte des Divisors zum Dividend addieren, dann ist das Ergebnis gerundet.
;  TRUNC(a / b + .5) = TRUNC((a + b / 2) / b)

	;	moveq	#0,d2
	;	move.w	d1,d2
	;	lsr.w	#1,d2
	;	add.l	d2,d0

		;    divis divid 
		divu.w	d1,d0

.set		move.w	d0,oxSl_softval(a3)
		bra	.redraw		

.not_sliding	move.l	oxSl_seconds(a3),d0
		cmp.l	im_Seconds(a1),d0
		beq.b	.return_unused

		add.w	oxSl_pixpos(a3),d1
		move.w	d1,d3

		add.w	oxSl_knobpix(a3),d3

		cmp.w	d5,d1
		bgt.b	.above_knob
		cmp.w	d5,d3
		blt.b	.below_knob

		bra	.return_used

.above_knob	; mouse pressed above knob inside container

		tst.w	oxSl_softval(a3)
		beq	.return_unused

		move.w	oxSl_softbody(a3),d0
		sub.w	d0,oxSl_softval(a3)
		bge	.redraw
		clr.w	oxSl_softval(a3)
		bra	.redraw

.below_knob	; mouse pressed below knob inside container

		move.w	oxSl_softmax(a3),d0
		move.w	d0,d1
		sub.w	oxSl_softbody(a3),d1
		cmp.w	oxSl_softval(a3),d1
		beq	.return_unused

		move.w	oxSl_softbody(a3),d1
		sub.w	d1,d0
		add.w	d1,oxSl_softval(a3)
		cmp.w	oxSl_softval(a3),d0
		bge	.redraw
		move.w	d0,oxSl_softval(a3)

.redraw		move.l	a3,a0

		; notify connects

		moveq	#0,d1
		btst	#oxSlB_FLIP,oxSl_flags(a3)
		bne.b	.softval_flip

		move.w	oxSl_softval(a3),d1
		bra.b	.calc_softval

.softval_flip	move.w	#OXPROP_SOFTMAX,d1
		sub.w	oxSl_softval(a3),d1
		sub.w	oxSl_softbody(a3),d1

.calc_softval	mulu.w	#OXPROP_SOFTMAX,d1
		move.w	#OXPROP_SOFTMAX,d0
		sub.w	oxSl_softbody(a3),d0
		beq.b	.verify
		divu.w	d0,d1

.verify		cmp.w	oxSl_oldsoft(a3),d1
		beq.b	.return_used
		move.w	d1,oxSl_oldsoft(a3)

		ext.l	d1

		move.l	#oxSlA_softval,d0
		bsr	_oxNotify

		; recalc pot

		moveq	#0,d1

		move.w	oxSl_max(a3),d1

		btst	#oxSlB_FLIP,oxSl_flags(a3)
		bne.b	.pot_flip

		mulu.w	oxSl_softval(a3),d1
		bra.b	.calc_pot

.pot_flip	move.w	oxSl_softmax(a3),d0
		sub.w	oxSl_softval(a3),d0
		sub.w	oxSl_softbody(a3),d0
		mulu.w	d0,d1

.calc_pot	move.w	oxSl_softmax(a3),d0

		; runden: die Hälfte des Divisors zum Dividend addieren,
		; 	  (divd + divs / 2) / divs
		;  damit verteilung der werte gleichmäßig liegen	

		moveq	#0,d2
		move.w	d0,d2
		lsr.w	#1,d2
		add.l	d2,d1
		;     divs divd  
		divu.w	d0,d1

		ext.l	d1

		btst	#oxSlB_BASE1,oxSl_flags(a3)
		beq.b	.notif_pot
		addq.w	#1,d1
.notif_pot	move.l	#oxSlA_pot,d0
		bsr	_oxNotify

		bsr	_oxBroadcastUpdate

		; set receiver parallel prop

		move.l	oxSl_receiver(a3),d0
		bsr	_GetPtrPtr		; get a0 *target here
		beq	.draw

		move.l	#oxA_pos,d0
		jsr	_oxSetAttr(pc)

		; send redraw to receiver (allready in a0)

		move.l	#OXM_UPDATE,d1
		jsr	_oxDoMethod(pc)

.draw		moveq	#0,d4
		move.l	oxSl_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		bsr	_oxBeginRefresh

		bsr	slider_UPDATE

		move.l	oxSl_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		moveq	#0,d4
		movem.w	oxSl_left(a3),d0-d3
		sub.w	d0,d2
		sub.w	d1,d3
		addq.w	#1,d2
		addq.w	#1,d3
		bsr	_oxEndRefresh

.return_used	moveq	#1,d0
		rts

.return_unused	moveq	#0,d0
		rts

.mouseup
oxSl_go_inact	bclr	#oxSlB_ACTIVE,oxSl_flags(a0)
		bclr	#oxSlB_SLIDING,oxSl_flags(a0)

		moveq	#0,d1
		move.l	oxSl_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_tickuser,d0
		bsr	_oxSetAttr

		move.l	oxSl_receiver(a3),d0
		bsr	_GetPtrPtr
		beq	.return_used
		moveq	#OXM_ACTIVATE,d1
		bsr	_oxDoMethod

.return_used	moveq	#1,d0
		rts

_GetPtrPtr	beq	.rts
		move.l	d0,a0
		move.l	(a0),d0
		beq	.rts
		move.l	d0,a0
.rts		rts

_is_in_rect_br	; w/ bottom/right

		move.l	im_IDCMPWindow(a1),a2
		moveq	#0,d4
		moveq	#0,d5
		move.b	wd_BorderLeft(a2),d4
		move.b	wd_BorderTop(a2),d5
		neg.w	d4
		neg.w	d5
		add.w	im_MouseX(a1),d4
		add.w	im_MouseY(a1),d5
		cmp.w	d4,d0
		bgt.b	.not_in_rect
		cmp.w	d4,d2
		blt.b	.not_in_rect
		cmp.w	d5,d1
		bgt.b	.not_in_rect
		cmp.w	d5,d3
		blt.b	.not_in_rect
		moveq	#1,d0
		rts
.not_in_rect	moveq	#0,d0
		rts

;--------------------------------------------------------------------
; OX_HORIZGROUP / OX_VERTGROUP

 STRUCTURE	oxGroup,oxO_SIZEOF
	STRUCT	oxG_MM,oxLI_SIZEOF	; prop inside here
	UWORD	oxG_flags
	UWORD	oxG_minspace		; wird * members-1 zu minimaler platzbedarf gezählt
	UWORD	oxG_spaceprop

	UWORD	oxG_totalspace		; wird bei SETLAYOUT von width abgezogen
	UWORD	oxG_member_count	; zahl der members
	UWORD	oxG_width_sum		; minimaler platztbedarf
	UWORD	oxG_height_sum		; .. 
	UWORD	oxG_widest		; breite des breitesten objekts,
					; bei EQUAL überschreibt dies * member_count den min platz
	UWORD	oxG_heightest		; das höchste objekt bestimmt die zeilenhöhe

	UWORD	oxG_propsum		; alle propwerte zusammen ist teiler für breite
					; dann pro element mal seinem propwert
	APTR	oxG_growingmember	; *to dieses objekt soll allen platz bekommen
	UWORD	oxG_const		; feste breite des nicht wachsenden bereichs mit spacing
	LABEL	oxG_SIZEOF

	BITDEF	oxG,EQUAL,0



	OXICLASSHEADER	horizgroup, 1, 0, vertgroup

	dc.l	oxCA_objectsize,oxG_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,HG_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Format content horizontal.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	group_SET

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxHG_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxHG_SETLAYOUT

		cmp.w	#OXM_SETDEF,d1
		beq.b	oxHG_SETDEF

		rts

HG_create_ex	lea	.example(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

.example	dc.l	OX_BUTTON,.button
		dc.l	OX_BUTTON,.button1
		dc.l	OX_BUTTON,.button
		dc.l	OX_BUTTON,.button1
		dc.l	TAG_END
.button		dc.l	oxBA_text,.text
		dc.l	TAG_END
.button1	dc.l	oxBA_text,.text1
		dc.l	TAG_END
.text		dc.b	"Andreas",0
.text1		dc.b	"Szabo",0
		even

oxHG_SETDEF	move.w	#10,oxG_minspace(a0)
		move.w	#1,oxG_spaceprop(a0)
	;	or.w	#oxGF_EQUAL,oxG_flags(a0)
		rts


oxHG_GETLAYOUT	move.l	oxO_list+LH_HEAD(a0),a2
		tst.l	(a2)
		beq	.nop

		; return this frame prop
		move.l	oxG_MM+oxLI_propw(a0),oxLI_propw(a1)

		clr.l	oxG_MM+oxLI_minwidth(a0)
		clr.w	oxG_member_count(a0)
		clr.w	oxG_width_sum(a0)
		clr.w	oxG_propsum(a0)
		clr.w	oxG_widest(a0)

		movem.l	a0/a1,-(a7)
		lea	-oxLI_SIZEOF(a7),a7

		move.l	a0,a3
		bra.b	.get_member

.member_loop	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.done

.get_member	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_maxwidth(a1)
		clr.l	oxLI_propw(a1)
		bsr	_oxDoMethod
		tst.w	d0
		beq.b	.member_loop

		; werte des objekts mit einbeziehen

		addq.w	#1,oxG_member_count(a3)
		move.w	oxLI_minwidth(a7),d0
		add.w	d0,oxG_width_sum(a3)	; width von member zu summe
		cmp.w	oxG_widest(a3),d0	; widest < width
		blt.b	.have_max_width
		move.w	d0,oxG_widest(a3)
.have_max_width
		move.w	oxLI_minheight(a7),d0
		cmp.w	oxG_heightest(a3),d0
		blt.b	.have_max_hight
		move.w	d0,oxG_heightest(a3)
.have_max_hight
		move.w	oxLI_propw(a7),d0
		beq.b	.noprop	

		move.w	oxLI_minwidth(a7),d7		; rette breite des wachsenden breichs
		move.l	a2,oxG_growingmember(a3)	; merke objekt dass allen platz bekommt

		add.w	d0,oxG_propsum(a3)
.noprop
		bra.b	.member_loop

.done		move.l	oxLI_SIZEOF+4(a7),a1		; get back return vars

		move.w	oxG_member_count(a3),d1
		move.w	oxG_width_sum(a3),d0

		btw 	oxGB_EQUAL,oxG_flags(a3)
		beq.b	.mixedwidth

		move.w	oxG_widest(a3),d0
		mulu.w	d1,d0

.mixedwidth	move.w	d0,oxLI_minwidth(a1)
		subq.w	#1,d1
		mulu.w	oxG_minspace(a3),d1
		move.w	d1,oxG_totalspace(a3)
		add.w	d1,oxLI_minwidth(a1)

		tst.w	oxG_propsum(a3)
		beq.b	.noprop2
		move.w	oxLI_minwidth(a1),d1
		sub.w	d7,d1
		move.w	d1,oxG_const(a3)	; breite des nicht wachsenden bereichs mit space
.noprop2
		move.w	oxG_heightest(a3),oxLI_minheight(a1)

	;	tst.w	oxG_spaceprop(a3)
	;	bne.b 	.setmax
	;	tst.w	oxG_propsum(a3)
	;	beq.b	.nomax

		move.w	oxG_MM+oxLI_propw(a3),oxLI_propw(a1)
		beq.b	.if_proph
		move.w	#$7fff,oxLI_maxwidth(a1)
.if_proph	move.w	oxG_MM+oxLI_proph(a3),oxLI_proph(a1)
		beq.b	.minw
		move.w	#$7fff,oxLI_maxheight(a1)

.minw		move.w	oxG_MM+oxLI_minwidth(a3),d1
		cmp.w	oxLI_minwidth(a1),d1
		ble.b	.minh
		move.w	d1,oxLI_minwidth(a1)

.minh		move.w	oxG_MM+oxLI_minheight(a3),d1
		cmp.w	oxLI_minheight(a1),d1
		ble.b	.used
		move.w	d1,oxLI_minheight(a1)

.used		moveq	#1,d0	; return hello

		lea	oxLI_SIZEOF(a7),a7
		addq.l	#8,a7

.rts		rts
.nop		moveq	#0,d0
		rts

oxHG_SETLAYOUT	move.l	oxO_list+LH_HEAD(a0),a2
		tst.l	(a2)
		beq	.nop

		tst.w	oxG_member_count(a0)
		beq.b	.nop

		movem.l	a0/a1,-(a7)
		lea	-oxLI_SIZEOF(a7),a7

		btw	oxGB_EQUAL,oxG_flags(a0)
		bne.b	.eq

		; free widths

		tst.w	oxG_spaceprop(a0)
		beq.b	.freenosprop

		; free widths and space growing

		moveq	#0,d0
		moveq	#0,d5
		move.w	oxLI_width(a1),d5
		sub.w	oxG_width_sum(a0),d5
		move.w	oxG_member_count(a0),d0
		subq.w	#1,d0
		beq.b	.no_spc_div
		divu.w	d0,d5
.no_spc_div
		move.w	oxLI_height(a1),oxLI_height(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d3,oxLI_top(a7)

		bra.b	.fwsg_set_memb

.fwsg_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.fwsg_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.fwsg_memb_lp

		move.w	oxLI_minwidth(a7),d4

		move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d2,oxLI_left(a1)
		move.w	d4,oxLI_width(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.fwsg_memb_lp

		add.w	d4,d2
		add.w	d5,d2

		bra.b	.lef_memb_lp

		; ---------------------

.freenosprop	tst.w	oxG_propsum(a0)
		bne.b	.onegrowing

		; objects fixed with free width to left of box

		move.w	oxG_minspace(a0),d5

		move.w	oxLI_height(a1),oxLI_height(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d3,oxLI_top(a7)

		bra.b	.lef_set_memb

.lef_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.lef_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.lef_memb_lp

		move.w	oxLI_minwidth(a7),d4

		move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d2,oxLI_left(a1)
		move.w	d4,oxLI_width(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.lef_memb_lp

		add.w	d4,d2
		add.w	d5,d2

		bra.b	.lef_memb_lp

		; ----------------------

.onegrowing	; one member object takes all space

		move.w	oxG_minspace(a0),d5		

		move.w	oxLI_width(a1),d6
		sub.w	oxG_const(a0),d6
		move.l	oxG_growingmember(a0),a3

		; d6 jetzt platz für breitestes objekt

		move.w	oxLI_height(a1),oxLI_height(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d3,oxLI_top(a7)

		bra.b	.one_set_memb

.one_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.one_set_memb	cmp.l	a3,a2
		bne.b	.one_get

		move.w	d6,d4		; platz für wachsendes

		bra.b	.one_set

.one_get	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.one_memb_lp

		move.w	oxLI_minwidth(a7),d4

.one_set	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d2,oxLI_left(a1)
		move.w	d4,oxLI_width(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.one_memb_lp

		add.w	d4,d2
		add.w	d5,d2

		bra.b	.one_memb_lp

		; ----------------------------

.eq		tst.w	oxG_spaceprop(a0)
		beq.b	.eqnospaceprop

		; equal widths and space growing

		move.w	oxG_member_count(a0),d0

		move.w	d0,d2			; copy m_count from d0 to d1
		move.w	oxG_widest(a0),d4	; set d4 to heightest member
		mulu.w	d4,d0			; set d0 to minimum total height needed by members
	
		move.w	oxLI_width(a1),d5
		sub.w	d0,d5			; sub that total height from avail height

		subq.w	#1,d2			; calc number of spaces
		beq.b	.nospdiv

		swap	d2			; calc height of one space to d5
		swap	d5
		clr.w	d2
		clr.w	d5
		swap	d2
		swap	d5
		divu.w	d2,d5
.nospdiv
		move.w	oxLI_height(a1),oxLI_height(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d3,oxLI_top(a7)
		move.w	d4,oxLI_width(a7)

		bra.b	.eqsp_set_memb

.eqsp_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.eqsp_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d2,oxLI_left(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.eqsp_memb_lp

		add.w	d4,d2
		add.w	d5,d2

		bra.b	.eqsp_memb_lp

.eqnospaceprop	; equal widths all growing and space stays minimum

		; a0 * dieses group-objekt

		moveq	#0,d0
		move.w	oxLI_width(a1),d0
		sub.w	oxG_totalspace(a0),d0
		divu.w	oxG_member_count(a0),d0

		move.w	d0,oxLI_width(a7)
		move.w	oxLI_height(a1),oxLI_height(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d3,oxLI_top(a7)

		move.l	a0,a3
		bra.b	.set_member

.member_loop	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.set_member	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d2,oxLI_left(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.member_loop

		add.w	oxLI_width(a7),d2
		add.w	oxG_minspace(a3),d2

		bra.b	.member_loop

.restack	lea	oxLI_SIZEOF(a7),a7
		addq.l	#8,a7

		moveq	#1,d0
		rts
.nop		moveq	#0,d0
		rts

;--------------------------------------------------------------------
; OX_VERTGROUP


	OXICLASSHEADER	vertgroup, 1, 0, icon

	dc.l	oxCA_objectsize,oxG_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,VG_create_ex
	dc.l	TAG_END

.desc		dc.b	"$VER: Format content vertical.",0
		even

.dispatcher	cmp.w	#OXM_SET,d1
		beq	group_SET

		cmp.w	#OXM_GETLAYOUT,d1
		beq	oxVG_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	oxVG_SETLAYOUT

		cmp.w	#OXM_SETDEF,d1
		beq.b	oxVG_SETDEF

		rts

VG_create_ex	lea	.example(pc),a2
		move.l	#OX_VERTGROUP,d2
		bra	_oxCreateObject

.example	dc.l	OX_TITLE,.title
		dc.l	OX_FIELD,.field
		dc.l	OX_BUTTON,.button
		dc.l	TAG_END
.title		dc.l	oxTA_text,.text1
		dc.l	TAG_END
.field		dc.l	oxFdA_text,.text
		dc.l	TAG_END
.button		dc.l	oxBA_text,.btext
		dc.l	TAG_END
.text		dc.b	"Andreas G. Szabo",$a
		dc.b	"München",0
.text1		dc.b	"personal Info",0
.btext		dc.b	"ok",0
		even

oxVG_SETDEF 	move.w	#10,oxG_minspace(a0)
	;	move.w	#1,oxG_spaceprop(a0)
	;	or.w	#oxGF_EQUAL,oxG_flags(a0)
		rts

group_SET	movem.l	(a1),d0/d1

		cmp.l	#oxGA_equal,d0
		bne.b	.a
		moveq	#oxGF_EQUAL,d0
		bra.b	.flag

.a		cmp.l	#oxGA_minspace,d0
		bne	.b
		move.w	d1,oxG_minspace(a0)
		rts

.b		cmp.l	#oxGA_spaceprop,d0
		bne	.c
		move.w	d1,oxG_spaceprop(a0)
		rts

.c		cmp.l	#oxGA_hprop,d0
		bne	.d
		move.w	d1,oxG_MM+oxLI_propw(a0)
		rts

.d		cmp.l	#oxGA_vprop,d0
		bne.b	.e
		move.w	d1,oxG_MM+oxLI_proph(a0)
		rts

.e		cmp.l	#oxGA_minwidth,d0
		bne.b	.f
		move.w	d1,oxG_MM+oxLI_minwidth(a0)
		rts

.f		cmp.l	#oxGA_minheight,d0
		bne.b	.rts
		move.w	d1,oxG_MM+oxLI_minheight(a0)

.rts		rts

.flag		tst.w	d1
		beq	.clearflag
		or.w	d0,oxG_flags(a0)
		rts

.clearflag	not.w	d0
		and.w	d0,oxG_flags(a0)
		rts

oxVG_GETLAYOUT	move.l	oxO_list+LH_HEAD(a0),a2
		tst.l	(a2)
		beq	.nop

		; return this frame prop
		move.l	oxG_MM+oxLI_propw(a0),oxLI_propw(a1)

	;	clr.l	oxG_MM+oxLI_minwidth(a0)
		clr.w	oxG_member_count(a0)
		clr.w	oxG_height_sum(a0)
		clr.w	oxG_propsum(a0)
		clr.w	oxG_heightest(a0)

		movem.l	a0/a1,-(a7)
		lea	-oxLI_SIZEOF(a7),a7

		move.l	a0,a3
		bra.b	.get_member

.member_loop	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.done

.get_member	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		clr.l	oxLI_minwidth(a1)
		clr.l	oxLI_maxwidth(a1)
		clr.l	oxLI_propw(a1)
		bsr	_oxDoMethod
		tst.w	d0
		beq.b	.member_loop

		; werte des objekts mit einbeziehen

		addq.w	#1,oxG_member_count(a3)
		move.w	oxLI_minheight(a7),d0

		add.w	d0,oxG_height_sum(a3)	; width von member zu summe

		cmp.w	oxG_heightest(a3),d0	; widest < width
		blt.b	.have_heightest
		move.w	d0,oxG_heightest(a3)
.have_heightest
		move.w	oxLI_minwidth(a7),d0
		cmp.w	oxG_widest(a3),d0
		blt.b	.have_max_width
		move.w	d0,oxG_widest(a3)
.have_max_width

		move.w	oxLI_proph(a7),d0
		beq.b	.noprop	

		move.w	oxLI_minheight(a7),d7		; rette breite des wachsenden breichs
		move.l	a2,oxG_growingmember(a3)	; merke objekt dass allen platz bekommt

		add.w	d0,oxG_propsum(a3)
.noprop
		bra.b	.member_loop

.done		move.l	oxLI_SIZEOF+4(a7),a1		; get back return vars

		move.w	oxG_member_count(a3),d1
		move.w	oxG_height_sum(a3),d0
		btw 	oxGB_EQUAL,oxG_flags(a3)
		beq.b	.mixedheight
		move.w	oxG_heightest(a3),d0
		mulu.w	d1,d0
.mixedheight	move.w	d0,oxLI_minheight(a1)
		subq.w	#1,d1
		mulu.w	oxG_minspace(a3),d1
		move.w	d1,oxG_totalspace(a3)
		add.w	d1,oxLI_minheight(a1)

		tst.w	oxG_propsum(a3)
		beq.b	.noprop2
		move.w	oxLI_minheight(a1),d1
		sub.w	d7,d1
		move.w	d1,oxG_const(a3)	; höhe des nicht wachsenden bereichs mit space
.noprop2
		move.w	oxG_widest(a3),oxLI_minwidth(a1)

	;	tst.w	oxG_spaceprop(a3)
	;	bne.b 	.setmax
	;		tst.w	oxG_propsum(a3)
	;	beq.b	.nomax

		move.w	oxG_MM+oxLI_propw(a3),oxLI_propw(a1)
		beq.b	.if_proph
		move.w	#$7fff,oxLI_maxwidth(a1)
.if_proph	move.w	oxG_MM+oxLI_proph(a3),oxLI_proph(a1)
		beq.b	.minw
		move.w	#$7fff,oxLI_maxheight(a1)

.minw		move.w	oxG_MM+oxLI_minwidth(a3),d1
		cmp.w	oxLI_minwidth(a1),d1
		ble.b	.minh
		move.w	d1,oxLI_minwidth(a1)

.minh		move.w	oxG_MM+oxLI_minheight(a3),d1
		cmp.w	oxLI_minheight(a1),d1
		ble.b	.used
		move.w	d1,oxLI_minheight(a1)

.used		moveq	#1,d0	; return hello

		lea	oxLI_SIZEOF(a7),a7
		addq.l	#8,a7

.rts		rts
.nop		moveq	#0,d0
		rts

oxVG_SETLAYOUT	move.l	oxO_list+LH_HEAD(a0),a2
		tst.l	(a2)
		beq	.nop

		tst.w	oxG_member_count(a0)
		beq.b	.nop

		movem.l	a0/a1,-(a7)
		lea	-oxLI_SIZEOF(a7),a7

		btw	oxGB_EQUAL,oxG_flags(a0)
		bne.b	.eq

		; free heights

		tst.w	oxG_spaceprop(a0)
		beq.b	.freenosprop

		; free heights and space growing

		moveq	#0,d0
		moveq	#0,d5
		move.w	oxLI_height(a1),d5
		sub.w	oxG_height_sum(a0),d5
		move.w	oxG_member_count(a0),d0
		subq.w	#1,d0
		beq.b	.no_spc_div
		divu.w	d0,d5
.no_spc_div
		move.w	oxLI_width(a1),oxLI_width(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d2,oxLI_left(a7)

		bra.b	.fwsg_set_memb

.fwsg_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.fwsg_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.fwsg_memb_lp

		move.w	oxLI_minheight(a7),d4

		move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d3,oxLI_top(a1)
		move.w	d4,oxLI_height(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.fwsg_memb_lp

		add.w	d4,d3
		add.w	d5,d3

		bra.b	.top_memb_lp

		; ---------------------

.freenosprop	tst.w	oxG_propsum(a0)
		bne.b	.onegrowing

		; objects fixed with free height to top of box

		move.w	oxG_minspace(a0),d5

		move.w	oxLI_width(a1),oxLI_width(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d2,oxLI_left(a7)

		bra.b	.top_set_memb

.top_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.top_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		clr.w	oxLI_minheight(a1)
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.top_memb_lp

		move.w	oxLI_minheight(a7),d4

		move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d3,oxLI_top(a1)
		move.w	d4,oxLI_height(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.top_memb_lp

		add.w	d4,d3
		add.w	d5,d3

		bra.b	.top_memb_lp

.onegrowing	; one member object takes all space

		move.w	oxG_minspace(a0),d5		

		move.w	oxLI_height(a1),d6
		sub.w	oxG_const(a0),d6
		move.l	oxG_growingmember(a0),a3

		; d6 jetzt platz für breitestes objekt

		move.w	oxLI_width(a1),oxLI_width(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d2,oxLI_left(a7)

		bra.b	.one_set_memb

.one_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.one_set_memb	cmp.l	a3,a2
		bne.b	.one_get

		move.w	d6,d4		; platz für wachsendes

		bra.b	.one_set

.one_get	move.l	a2,a0	; dest
		move.l	a7,a1
		moveq	#OXM_GETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.one_memb_lp

		move.w	oxLI_minheight(a7),d4

.one_set	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d3,oxLI_top(a1)
		move.w	d4,oxLI_height(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.one_memb_lp

		add.w	d4,d3
		add.w	d5,d3

		bra.b	.one_memb_lp

		; ----------------------------

.eq		tst.w	oxG_spaceprop(a0)
		beq.b	.eqnospaceprop

		; equal heights and space growing

		move.w	oxG_member_count(a0),d0

		move.w	d0,d2			; copy m_count from d0 to d1
		move.w	oxG_heightest(a0),d4	; set d4 to heightest member
		mulu.w	d4,d0			; set d0 to minimum total height needed by members
	
		move.w	oxLI_height(a1),d5
		sub.w	d0,d5			; sub that total height from avail height

		subq.w	#1,d2			; calc number of spaces
		beq.b	.nospdiv

		swap	d2			; calc height of one space to d5
		swap	d5
		clr.w	d2
		clr.w	d5
		swap	d2
		swap	d5
		divu.w	d2,d5
.nospdiv
		move.w	oxLI_width(a1),oxLI_width(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d2,oxLI_left(a7)
		move.w	d4,oxLI_height(a7)

		bra.b	.eqsp_set_memb

.eqsp_memb_lp	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.eqsp_set_memb	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d3,oxLI_top(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.eqsp_memb_lp

		add.w	d4,d3
		add.w	d5,d3

		bra.b	.eqsp_memb_lp

.eqnospaceprop	; equal heights all growing and space stays minimum

		; a0 * dieses group-objekt

		moveq	#0,d0
		move.w	oxLI_height(a1),d0
		sub.w	oxG_totalspace(a0),d0
		divu.w	oxG_member_count(a0),d0

		move.w	d0,oxLI_height(a7)

		move.w	oxLI_width(a1),oxLI_width(a7)
		movem.w	oxLI_left(a1),d2/d3
		move.w	d2,oxLI_left(a7)


		move.l	a0,a3
		bra.b	.set_member

.member_loop	move.l	oxO_node+LN_SUCC(a2),a2
		tst.l	(a2)
		beq.b	.restack

.set_member	move.l	a2,a0	; dest
		move.l	a7,a1
		move.w	d3,oxLI_top(a1)
		moveq	#OXM_SETLAYOUT,d1
		bsr	_oxDoMethod

		tst.w	d0
		beq.b	.member_loop

		add.w	oxLI_height(a7),d3
		add.w	oxG_minspace(a3),d3

		bra.b	.member_loop

.restack	lea	oxLI_SIZEOF(a7),a7
		addq.l	#8,a7

		moveq	#1,d0
		rts
.nop		moveq	#0,d0
		rts

;--------------------------------------------------------------------
; OX_ICON

		include libraries/icon_lib.i
	;	include	workbench/icon.i

; Tags for use with DrawIconStateA() and GetIconRectangleA().

ICONA_Dummy	equ (TAG_USER+$9000)

; Drawing information to use (struct DrawInfo *).
ICONDRAWA_DrawInfo 		equ (ICONA_Dummy+66)

; Draw the icon without the surrounding frame (BOOL).
ICONDRAWA_Frameless		equ (ICONA_Dummy+70)

; Erase the background before drawing a borderless icon (BOOL).
ICONDRAWA_EraseBackground	equ (ICONA_Dummy+71)

; Draw the icon without the surrounding border and frame (BOOL).
ICONDRAWA_Borderless		equ (ICONA_Dummy+83)

; The icon to be drawn refers to a linked object (BOOL).
ICONDRAWA_IsLink		equ (ICONA_Dummy+89)


 STRUCTURE	oxIcon,oxO_SIZEOF
	UWORD	oxIc_left
	UWORD	oxIc_top
	UWORD	oxIc_width
	UWORD	oxIc_height

	APTR	oxIc_drawinfo

	APTR	oxIc_diskobject
	APTR	oxIc_filename

	UBYTE	oxIc_flags
	UBYTE	oxIc_pad

	LABEL	oxIc_SIZEOF


	BITDEF	oxIc,PRESSED,0		; draw in alternate state
	BITDEF	oxIc,SHARED,1		; dont free icon at DEINIT
	BITDEF	oxIc,V44,2		; version of icon.library for comaptibility to v39 or v44, if v is 44 then this flag is set



	OXICLASSHEADER	icon, 1, 0, image

	dc.l	oxCA_objectsize,oxIc_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,IcCREX
	dc.l	TAG_END

.desc		dc.b	"$VER: Class to display icons w// transparent bg even for old icons.",0
		even

.dispatcher	cmp.w	#OXM_DRAW,d1
		beq	IcDRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	IcGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	IcSETLAYOUT

		cmp.w	#OXM_SET,d1
		beq	IcSET

		cmp.w	#OXM_GET,d1
		beq	IcGET

		cmp.w	#OXM_INIT,d1
		beq	IcINIT

		cmp.w	#OXM_DEINIT,d1
		beq	IcDEINIT

		rts

IcCREX		lea	.ex_g(pc),a2
		move.l	#OX_HORIZGROUP,d2
		bra	_oxCreateObject

.ex_g		dc.l	OX_ICON,.ex_icon
		dc.l	OX_ICON,.ex_icon_p
		dc.l	TAG_END

.ex_icon	dc.l	oxIcA_filename,.file
		dc.l	TAG_END

.ex_icon_p	dc.l	oxIcA_filename,.file
		dc.l	oxIcA_pressed,1
		dc.l	TAG_END
.file		dc.b	"sys:prefs",0
		even

IcGET		move.l	(a1),d0
		cmp.w	#oxA_width,d0
		bne.b	.h
		move.w	oxIc_width(a3),d0
		rts

.h		cmp.w	#oxA_height,d0
		bne	.rts
		move.w	oxIc_height(a3),d0
.rts		rts

IcSET		movem.l	(a1),d0/d1

		cmp.w	#oxA_left,d0
		bne.b	.top
		move.w	d1,oxIc_left(a3)
		rts

.top		cmp.w	#oxA_top,d0
		bne	.dri
		move.w	d1,oxIc_top(a3)
		rts

.dri		cmp.l	#oxA_drawinfo,d0
		bne.b	.if_file
		move.l	d1,oxIc_drawinfo(a0)
		rts

.if_file	cmp.l	#oxIcA_filename,d0
		bne.b	.if_diskobj
		move.l	d1,oxIc_filename(a0)
		rts

.if_diskobj	cmp.l	#oxIcA_diskobject,d0
		bne.b	.if_pressed
		move.l	d1,oxIc_diskobject(a0)
		bset	#oxIcB_SHARED,oxIc_flags(a0)
		rts

.if_pressed	cmp.l	#oxIcA_pressed,d0
		bne.b	.rts
		tst.b	d1
		bne.b	.pressed
		bclr	#oxIcB_PRESSED,oxIc_flags(a0)
		rts
.pressed	bset	#oxIcB_PRESSED,oxIc_flags(a0)
	
.rts		rts

IcINIT		tst.l	oxIc_diskobject(a0)
		bne.b	.get_size

		move.l	oxIc_filename(a0),d0
		beq.b	.rts_fail

		move.l	d0,a0

		bsr	_oxGetIcon

		move.l	d0,oxIc_diskobject(a3)
		beq.b	.rts_fail

.get_size	move.l	oxIc_diskobject(a3),d0
		beq.b	.rts_fail

		move.l	d0,a0
		lea	oxIc_width(a3),a1
		bsr	_oxGetIconSize

		; d0 is allready set here by get_icon_size
		rts
.rts_fail	moveq	#-1,d0
		rts

IcDEINIT	btst	#oxIcB_SHARED,oxIc_flags(a0)
		bne.b	.rts
		move.l	oxIc_diskobject(a0),d0
		beq.b	.rts
		move.l	d0,a0
		bsr	_oxDropIcon
.rts		rts

IcDRAW		move.l	oxIc_diskobject(a3),d0
		beq.b	.rts

		move.l	d0,a0
		movem.w	oxIc_left(a3),d0/d1

		move.l	oxIc_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		moveq	#0,d2
		btst	#oxIcB_PRESSED,oxIc_flags(a3)
		sne	d2

		bra	_oxDrawIcon

.rts		rts

IcGETLAYOUT	move.l	oxIc_width(a3),oxLI_minwidth(a1)
		moveq	#1,d0			; method used
		rts

IcSETLAYOUT 	move.l	oxLI_left(a1),oxIc_left(a0)
		moveq	#1,d0
		rts

;================================
; icon routines


_oxGetIcon	; a0	filename

		push	d2

		move.l	a0,d0
		moveq	#PRESET_ICON,d1
		bsr	find_preset

		tst.l	d0
		beq	.popd2

		pushm	d0/d1

		move.l	d0,a0

		bsr	.gi

		popm 	d1/d2

		tst.w	d2
		beq	.popd2

		move.l	d1,a0
		bsr	free_rem
.popd2		pop	d2
		rts

.gi		; get icon subroutine

		pushm	d3/a2/a6

		move.l	iconbase(pc),a6

		move.l	libbase(pc),a1
		btst	#oxBB_MORPHOS,oxB_configflags(a1)
		bne	.old

		cmp.w	#44,LIB_VERSION(a6)
		bge.b	.gitl

.old		jsr	_LVOGetDiskObject(a6)

		tst.l	d0
		beq	.pop

		; make blit mask and store in do_Gadget+gg_MutualExclude 

		move.l	d0,a2

		move.l	do_Gadget+gg_GadgetRender(a2),a0

		moveq	#0,d0
		moveq	#0,d1
		movem.w	ig_Width(a0),d0/d1

		; calc size of one plane of the image

		move.w	d0,d2

		add.w	#15,d2
		lsr.w	#3,d2
		bclr	#0,d2
		mulu.w	ig_Height(a0),d2

		move.l	gfxbase(pc),a6
		jsr	_LVOAllocRaster(a6)
		move.l	d0,do_Gadget+gg_MutualExclude(a2)
		beq	.pop

		move.l	d0,a0
		move.w	d2,d0
		subq.w	#1,d0
.clr_loop	clr.b	(a0)+
		dbf	d0,.clr_loop

		move.l	do_Gadget+gg_GadgetRender(a2),a1
		move.l	ig_ImageData(a1),a0

		move.b	ig_PlanePick(a1),d0
		moveq	#0,d1
		moveq	#7,d3
.count_loop	asr.b	#1,d0
		bcc	.cl_continue
		addq.w	#1,d1
.cl_continue	dbf	d3,.count_loop

		subq.w	#1,d1
.plane_loop	move.w	d2,d0
		subq.w	#1,d0
		move.l	do_Gadget+gg_MutualExclude(a2),a1
.or_loop	move.b	(a0)+,d3
		or.b	d3,(a1)+
		dbf	d0,.or_loop
		dbf	d1,.plane_loop

		move.l	a2,d0
		bra.b	.pop

.gitl		lea	.tags(pc),a1
		jsr	-180(a6)		; _LVOGetIconTagList

.pop		popm	d3/a2/a6
		rts

.tags		dc.l	TAG_END

_oxGetIconSize	; a0 *icon
		; a1 dest

		pushm	d2/d3/a1-a4/a6

		move.l	libbase(pc),a2
		btst	#oxBB_MORPHOS,oxB_configflags(a2)
		bne	.old

		move.l	iconbase(pc),a2
		cmp.w	#44,LIB_VERSION(a2)

		bge.b	.gira

.old		move.l	do_Gadget+gg_Width(a0),(a1)
		moveq	#1,d0
		popm	d2/d3/a1-a4/a6
		rts

.gira		; get size v44+

		move.l	a0,a1
		sub.l	a0,a0	; rp may be null if no label
		sub.l	a2,a2
		lea	.tags(pc),a4

		lea	-ra_SIZEOF(a7),a7

		move.l	a7,a3

		move.l	iconbase(pc),a6
		jsr	-168(a6)		;	_LVOGetIconRectangleA

		tst.l	d0
		beq.b	.fail
		movem.w	(a7),d0-d3
		sub.w	d0,d2
		sub.w	d1,d3
		addq.w	#1,d2
		addq.w	#1,d3
		lea	ra_SIZEOF(a7),a7

		move.w	d2,d0
		move.w	d3,d1

		popm	d2/d3/a1-a4/a6

		movem.w	d0/d1,(a1)

		moveq	#1,d0
		rts

.fail		lea	ra_SIZEOF(a7),a7
		popm	d2/d3/a1-a4/a6
		moveq	#-1,d0
		rts

.tags		dc.l	ICONDRAWA_Borderless,1
		dc.l	TAG_END

_oxDrawIcon	; d0	x
		; d1	y
		; d2	state	TRUE = PRESSED
		; a0	icon
		; a1	rastport

		pushm	d2-d6/a2-a4/a6
		push	a1

		move.l	libbase(pc),a2
		btst	#oxBB_MORPHOS,oxB_configflags(a2)
		bne	.old

		move.l	iconbase(pc),a6
		cmp.w	#44,LIB_VERSION(a6)
		bge.b	.disa

.old		; draw with BltMaskBitMapRastPort()

		move.l	do_Gadget+gg_MutualExclude(a0),a2	; mask

		move.l	do_Gadget+gg_GadgetRender(a0),a1
	;	tst.w	d2
	;	beq.b	.draw_old

	;	move.l	do_Gadget+gg_SelectRender(a0),d2
	;	beq.b	.draw_old
	;	move.l	d2,a1

.draw_old	move.l	(a7),a3		; rastport
		move.l	a1,a4		; image

		move.l	gfxbase(pc),a6

		; store drawing coords

		move.w	d0,d2
		move.w	d1,d3

		; peek destination window rastport bitmap depht

		move.l	rp_BitMap(a3),a0
		moveq	#BMA_DEPTH,d1
		jsr	_LVOGetBitMapAttr(a6)

		cmp.w	#8,d0
		ble.b	.get_bm_mem
		moveq	#8,d0

.get_bm_mem	lea	-bm_SIZEOF(a7),a7

		; store depth for use in loop below

		move.w	d0,d6
		subq.w	#1,d6			; depth counter

		; init bitmap

		move.l	a7,a0
		movem.w	d2/d3,-(a7)

		movem.w	ig_Width(a4),d1/d2
		jsr	_LVOInitBitMap(a6)

		; setup plane pointers

		move.l	ig_ImageData(a4),a0	; current plane pointer
		lea	4+bm_Planes(a7),a1	; planes pointers pointer

		move.b	ig_PlanePick(a4),d2
		move.b	ig_PlaneOnOff(a4),d3
		moveq	#1,d5			; mask for bit of interest

		move.w	ig_Width(a4),d4
		add.w	#15,d4
		lsr.w	#3,d4
		bclr	#0,d4
		mulu.w	ig_Height(a4),d4	; byte size of a plane

.depth_loop	move.b	d2,d1
		and.b	d5,d1
		beq	.noplane

		move.l	a0,d0
		adda.w	d4,a0
		bra	.set_plane

.noplane	moveq	#-1,d0

		move.b	d3,d1
		and.b	d5,d1
		bne	.set_plane

		moveq	#0,d0

.set_plane	move.l	d0,(a1)+

		lsl.b	#1,d5
		dbf	d6,.depth_loop

		; BltMaskBitMapRastPort()

		moveq	#0,d0
		moveq	#0,d1
		movem.w	(a7)+,d2/d3
		move.l	a7,a0
		move.l	a3,a1		; rastport
		movem.w	ig_Width(a4),d4/d5
		move.b	#ABC|ABNC|ANBC,d6
		jsr	_LVOBltMaskBitMapRastPort(a6)
		lea	bm_SIZEOF(a7),a7
		bra.b	.pop

.disa		; draw with icon-library v44+

		move.l	a0,a1
		sub.l	a2,a2
		tst.w	d2
		bne	.selected
		moveq	#IDS_NORMAL,d2
		bra	.rp
.selected	moveq	#IDS_SELECTED,d2
.rp		move.l	(a7),a0			; on stack rastport
		lea	.tags(pc),a3
		jsr	-162(a6)		;	_LVODrawIconStateA

.pop		pop	a1
		popm	d2-d6/a2-a4/a6
		moveq	#0,d0
		rts

.tags		dc.l	ICONDRAWA_EraseBackground,0
		dc.l	ICONDRAWA_Frameless,1
		dc.l	ICONDRAWA_Borderless,1
		dc.l	TAG_END

_oxDropIcon	; a0 *icon

		push	a6

		move.l	do_Gadget+gg_MutualExclude(a0),d0
		beq	.freedo

		push	a0

		move.l	d0,a1

		move.l	do_Gadget+gg_GadgetRender(a0),a0
		movem.w	ig_Width(a0),d0/d1

		move.l	a1,a0
		move.l	gfxbase(pc),a6
		jsr	_LVOFreeRaster(a6)

		pop	a0

.freedo		move.l	iconbase(pc),a6
		jsr	_LVOFreeDiskObject(a6)

		pop	a6
		rts

;--------------------------------------------------------------------
; OX_IMAGE


 STRUCTURE	oxImage,oxO_SIZEOF
	UWORD	oxIm_left
	UWORD	oxIm_top

	UWORD	oxIm_width
	UWORD	oxIm_height

	APTR	oxIm_drawinfo

	APTR	oxIm_image
	APTR	oxIm_filename

	LABEL	oxIm_SIZEOF



	OXICLASSHEADER	image, 1, 0, wheelgrad

	dc.l	oxCA_objectsize,oxIm_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
;	dc.l	oxCA_makeexample,ImCREX
	dc.l	TAG_END

.desc		dc.b	"$VER: OX class to display gif, jpg or whatever images with datatypes, but w//o transparence.",0
		even

.dispatcher	cmp.w	#OXM_DRAW,d1
		beq	ImDRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	ImGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	ImSETLAYOUT

		cmp.w	#OXM_SET,d1
		beq	ImSET

		cmp.w	#OXM_INIT,d1
		beq	ImINIT

		cmp.w	#OXM_DEINIT,d1
		beq	ImDEINIT_ff

		cmp.w	#OXM_WINDOWOPEN,d1
		beq	ImWINOPEN

		cmp.w	#OXM_UPDATE,d1
		beq	ImUPDATE

rts22		moveq	#0,d0
		rts

ImDRAW		move.l	oxIm_image(a0),d2
		beq.b	rts22

		movem.w	oxIm_left(a0),d0/d1
		move.l	oxIm_drawinfo(a0),a1
		move.l	oxDI_rastport(a1),a1

		move.l	d2,a0
		bsr	_oxImageDraw

		moveq	#0,d0
		rts

ImCREX		lea	.ex_f(pc),a2
		move.l	#OX_FRAME,d2
		bra	_oxCreateObject

.ex_f		dc.l	oxFrA_spacing,0
		dc.l	oxFrA_framestyle,oxFr_GNG
		dc.l	oxFrA_fillstyle,oxFr_NONE
		dc.l	OX_IMAGE,.ex_i
		dc.l	TAG_END

.ex_i		dc.l	oxImA_filename,.file
		dc.l	TAG_END
.file		dc.b	"smallimage.jpg",0
		even

ImWINOPEN	btst	#oxBB_LOADIMAGES,oxB_configflags(a6)
		beq.b	.rts
		move.l	oxIm_filename(a0),d0
		beq.b	.rts
		move.l	a1,a2
		bsr	_oxGetImage
		move.l	d0,oxIm_image(a0)

.rts		rts

ImUPDATE	push	a0
		bsr	ImDEINIT
		pop	a0
		move.l	oxIm_drawinfo(a0),d0
		beq.b	.rts
		move.l	d0,a1
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a1)
		beq.b	.rts
		move.l	oxDI_window(a1),a1
		bra	ImWINOPEN

.rts		rts


ImSET		movem.l	(a1),d0/d1

		cmp.l	#oxA_drawinfo,d0
		bne.b	.if_file
		move.l	d1,oxIm_drawinfo(a0)
		rts

.if_file	cmp.l	#oxImA_filename,d0
		bne.b	.rts

		move.l	a0,a3
		move.l	d1,d2

		; test for remove old image

		move.l	oxIm_image(a0),d0
		beq.b	.set_new_image

		move.l	d0,a0
		bsr	_oxDropImage
		clr.l	oxIm_image(a3)

		; free old filename

		move.l	oxIm_filename(a3),d0
		beq.b	.set_new_image
		move.l	d0,a0
		bsr	free_rem

.set_new_image	tst.l	d2
		beq.b	.clear

		move.l	d2,a0
		move.l	a0,a1
		moveq	#0,d0
.namlen_lp	addq.w	#1,d0
		tst.b	(a1)+
		bne.b	.namlen_lp

		bsr	alloc_rem

		move.l	d0,oxIm_filename(a3)
		beq.b	.rts

		move.l	d0,a1
.cpnam_lp	move.b	(a0)+,(a1)+
		bne.b	.cpnam_lp

.rts		rts

.clear		clr.l	oxIm_filename(a3)
		rts

ImINIT		rts

ImDEINIT_ff	move.l	a0,a3

		move.l	oxIm_filename(a3),d0
		beq.b	ImDE
		move.l	d0,a0
		bsr	free_rem

		bra.b	ImDE

ImDEINIT	; free filename

		move.l	a0,a3

ImDE		move.l	oxIm_image(a3),d0
		beq.b	.rts
		move.l	d0,a0
		bra	_oxDropImage

.rts		rts

ImGETLAYOUT	move.l	oxIm_filename(a0),d0
		beq.b	.rts

		lea	oxLI_minwidth(a1),a2

		bsr	_oxGetImageSize

		moveq	#1,d0
.rts		rts

ImSETLAYOUT	move.l	oxLI_left(a1),oxIm_left(a0)
		moveq	#1,d0
		rts



;--------------------------------------------------------------------
; OX_WHEELGRAD

		include gadgets/colorwheel.i
		include gadgets/gradientslider.i
		include	libraries/colorwheel_lib.i
		include	intuition/gadgetclass.i


oxWG_NUMPENS	=	1	; bug makes 3 out of 1?!?!

 STRUCTURE	oxWheelGrad,oxO_SIZEOF
	UWORD	oxWG_left
	UWORD	oxWG_top
	UWORD	oxWG_width
	UWORD	oxWG_height
	UWORD	oxWG_minsize

	APTR	oxWG_window
	APTR	oxWG_drawinfo

	APTR	oxWG_wheel
	APTR	oxWG_slider

	UBYTE	oxWG_flags

	UBYTE	oxWG_fillbgcolor
	STRUCT	oxWG_fillbghook,h_SIZEOF

	STRUCT	oxWG_pens,4*oxWG_NUMPENS+2	; for slider, terminated by $FFFF 

	ULONG	oxWG_color

	STRUCT	oxWG_RGB,3*4
	STRUCT	oxWG_HSB,3*4

	APTR	oxWG_hook

	LABEL	oxWG_SIZEOF

	BITDEF	oxWG,FRONT,0
	BITDEF	oxWG,PENS,1

	BITDEF	oxWG,OLDVERSION,3		; version <= 40: recreate wheelgrad every draw
	BITDEF	oxWG,NEWVERSION,4		; version > 44: use backfill hook

	BITDEF	oxWG,UPDATE,6
	BITDEF	oxWG,ACTIVE,7


	OXICLASSHEADER	wheelgrad, 1, 0, 0

	dc.l	oxCA_objectsize,oxWG_SIZEOF
	dc.l	oxCA_dispatcher,.dispatcher
	dc.l	oxCA_constructor,.constructor
	dc.l	oxCA_description,.desc
	dc.l	oxCA_author,AUTHOR_NAME
	dc.l	oxCA_makeexample,WGCREX
	dc.l	oxCA_initclass,WGINITCLASS
	dc.l	oxCA_deinitclass,WGDEINITCLASS
	dc.l	TAG_END

.desc		dc.b	"$VER: This is a door to the Amiga BOOPSI Colorwheel and Gradientslider. It is working "
		dc.b	"only under AmigaOS 3.5+ and currently not under Morphos.",0
		even

.dispatcher	cmp.w	#OXM_INTUIMESSAGE,d1
		beq.b	WG_INPUT

		cmp.w	#OXM_DRAW,d1
		beq	WGDRAW

		cmp.w	#OXM_GETLAYOUT,d1
		beq	WGGETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	WGSETLAYOUT

		cmp.w	#OXM_SET,d1
		beq	WGSET

		cmp.w	#OXM_SETDEF,d1
		beq	WGSETDEF

		cmp.w	#OXM_INIT,d1
		beq	WGINIT

		cmp.w	#OXM_DEINIT,d1
		beq	WGDEINIT

		cmp.w	#OXM_WINDOWCLOSING,d1
		beq	WGDEINIT		; must dispose wheel before screen closes

		cmp.w	#OXM_WINDOWOPEN,d1
		beq	WG_WINOPEN

		cmp.w	#OXM_FRONT,d1
		beq.b	WG_FRONT

		cmp.w	#OXM_BACK,d1
		beq.b	WG_BACK

		cmp.w	#OXM_INACTIVE,d1
		beq	WG_inactive

.rts		rts

.constructor	btst	#oxBB_MORPHOS,oxB_configflags(a6)
		bne.b	.make_alt
		move.l	wheelbase(pc),a0
		cmp.w	#44,LIB_VERSION(a0)
		bge.b	.rts
.make_alt	lea	.alt(pc),a2
		moveq	#0,d2
		move.l	a4,a1
		bra	_oxCreateOnly

.alt		dc.l	OX_FIELD,.alt_tags
.alt_tags	dc.l	oxFdA_text,.alt_text
		dc.l	oxFdA_flags,oxFdF_LAYOUT
		dc.l	oxFdA_minlines,5
		dc.l	oxFdA_minwidth,103
		dc.l	oxFdA_hprop,TRUE
		dc.l	oxFdA_vprop,TRUE
		dc.l	TAG_END

.alt_text	dc.b	"To have the COLORWHEEL you need AmigaOS 3.5+.",0
		even

WG_inactive	bclr	#oxWGB_ACTIVE,oxWG_flags(a0)
		rts

WGINITCLASS	moveq	#LIBS_VER,d0
		lea	wheelname(pc),a1
		move.l	4.w,a6
		jsr	_LVOOpenLibrary(a6)
		move.l	d0,wheelbase
		beq.b	.rts

		moveq	#LIBS_VER,d0
		lea	slidername(pc),a1
		jsr	_LVOOpenLibrary(a6)
		move.l	d0,sliderbase
		bne.b	.rts

		move.l	wheelbase(pc),a1
	;	jsr		expunge
		jsr	_LVOCloseLibrary(a6)
		moveq	#0,d0
.rts		rts

wheelbase	dc.l	0
sliderbase	dc.l	0
wheelname	dc.b	"gadgets/"
wheelgadname	dc.b	"colorwheel.gadget",0
slidername	dc.b	"gadgets/"
slidergadname	dc.b	"gradientslider.gadget",0
		even

WGDEINITCLASS	move.l	wheelbase(pc),a6
	;	jsr	-18(a6)		; expunge
		move.l	a6,a1
		move.l	4.w,a6
		jsr	_LVOCloseLibrary(a6)

		move.l	sliderbase(pc),a6
	;	jsr	-18(a6)		; expunge
		move.l	a6,a1
		move.l	4.w,a6
		jmp	_LVOCloseLibrary(a6)

WGCREX		lea	.ex_w(pc),a2
		move.l	#OX_WHEELGRAD,d2
		bra	_oxCreateObject

.ex_w		dc.l	oxWGA_minsize,80
		dc.l	TAG_END

WGSET		movem.l	(a1),d0/d1

		cmp.l	#oxA_drawinfo,d0
		bne.b	.if_size
		move.l	d1,oxWG_drawinfo(a0)
		rts

.if_size	cmp.l	#oxWGA_minsize,d0
		bne.b	.if_color
		move.w	d1,oxWG_minsize(a0)
		rts

.if_color	cmp.l	#oxWGA_color,d0
		bne.b	.if_hook
		bset	#oxWGB_UPDATE,oxWG_flags(a0)
		move.l	d1,oxWG_color(a0)
		rts

.if_hook	cmp.l	#oxWGA_hook,d0
		bne.b	.rts
		move.l	d1,oxWG_hook(a0)
.rts		rts

WG_WINOPEN	move.l	a1,oxWG_window(a0)

		move.l	a0,a4

		; alloc pens for gradient slider

		move.l	oxWG_color(a4),d1
		bsr	WG_24toRGB

		lea	oxWG_RGB(a4),a0
		movem.l	d1-d3,(a0)
		lea	oxWG_HSB(a4),a1
		move.l	wheelbase(pc),a6
		jsr	_LVOConvertRGBToHSB(a6)

		; get *colormap from screen

		move.l	oxWG_window(a4),a0
		move.l	wd_WScreen(a0),a0
		move.l	sc_ViewPort+vp_ColorMap(a0),-(a7)

		; num pen

		lea	oxWG_pens(a4),a3
		moveq	#0,d5

.pens_lp	; adjust brightness to gradient

		moveq	#-1,d2		; is $FFFFFFFF
		move.l	d2,d0
		moveq	#oxWG_NUMPENS,d1
		bsr	_divu32
		move.l	d5,d1
		bsr	_mulu32
		sub.l	d0,d2
		move.l	d2,oxWG_HSB+cw_Brightness(a4)

		; make rgb from hsb		

		lea	oxWG_RGB(a4),a1
		lea	oxWG_HSB(a4),a0
		move.l	wheelbase(pc),a6
		jsr	_LVOConvertHSBToRGB(a6)

		; alloc pen from rgb values

		move.l	(a7),a0
		moveq	#-1,d0
		movem.l	oxWG_RGB(a4),d1-d3
		moveq	#PEN_EXCLUSIVE,d4
		move.l	gfxbase(pc),a6
		jsr	_LVOObtainPen(a6)		
		move.w	d0,(a3)+
		addq.w	#1,d5
		cmp.w	#oxWG_NUMPENS,d5
		ble.b	.pens_lp
		move.w	#-1,(a3)

		bset	#oxWGB_PENS,oxWG_flags(a4)

		addq.l	#4,a7

		move.l	intbase(pc),a6

		; dont precreate when in legacy mode

		btst	#oxWGB_OLDVERSION,oxWG_flags(a4)
		bne.b	.rts

		; create slider boopsi gadget

		moveq	#110,d0
		moveq	#0,d1
		moveq	#20,d2
		moveq	#100,d3

		bsr	WG_create_sl
		beq.b	.rts

		; create wheel boopsi gadget

		moveq	#0,d0
		moveq	#0,d1
		moveq	#100,d2
		moveq	#100,d3

		bsr	WG_create_wh
		beq.b	.dispose_slider

		; set size and pos attrs as got from window before it opened
		; dont set them to front here! is done by window after it opened

		bra	WG_setl

.dispose_slider	move.l	oxWG_slider(a4),a0
		jsr	_LVODisposeObject(a6)
		clr.l	oxWG_slider(a4)
.rts		rts

WG_create_sl	move.l	#TAG_END,-(a7)

		move.l	d3,-(a7)
		move.l	#GA_Height,-(a7)
		move.l	d2,-(a7)
		move.l	#GA_Width,-(a7)
		move.l	d1,-(a7)
		move.l	#GA_Top,-(a7)
		move.l	d0,-(a7)
		move.l	#GA_Left,-(a7)

		move.l	#LORIENT_VERT,-(a7)
		move.l	#PGA_Freedom,-(a7)

		moveq	#10,d0
		move.l	d0,-(A7)
		move.l	#GRAD_KnobPixels,-(a7)
		pea	oxWG_pens(a4)
		move.l	#GRAD_PenArray,-(a7)
		move.l	a4,-(a7)
		move.l	#GA_ID,-(a7)
		move.l	#ICTARGET_IDCMP,-(a7)
		move.l	#ICA_TARGET,-(a7)

		move.l	a7,a2
		sub.l	a0,a0
		lea	slidergadname(pc),a1
		jsr	_LVONewObjectA(a6)
		adda.w	#76,a7
		move.l	d0,oxWG_slider(a4)
		rts

WG_create_wh	move.l	#TAG_END,-(a7)

		move.l	d3,-(a7)
		move.l	#GA_Height,-(a7)
		move.l	d2,-(a7)
		move.l	#GA_Width,-(a7)
		move.l	d1,-(a7)
		move.l	#GA_Top,-(a7)
		move.l	d0,-(a7)
		move.l	#GA_Left,-(a7)

		move.l	oxWG_color(a4),d1
		bsr.b	WG_24toRGB

		move.l	d1,-(a7)
		move.l	#WHEEL_Red,-(a7)
		move.l	d2,-(a7)
		move.l	#WHEEL_Green,-(a7)
		move.l	d3,-(a7)
		move.l	#WHEEL_Blue,-(a7)

		move.l	oxWG_window(a4),a0
		move.l	wd_WScreen(a0),-(a7)
		move.l	#WHEEL_Screen,-(a7)
		move.l	oxWG_slider(a4),-(a7)
		move.l	#WHEEL_GradientSlider,-(a7)
		move.l	#ICTARGET_IDCMP,-(a7)
		move.l	#ICA_TARGET,-(a7)
		move.l	a4,-(a7)
		move.l	#GA_ID,-(a7)

		pea	oxWG_fillbghook(a4)
	;	move.l	#LAYERS_NOBACKFILL,-(a7)
		move.l	#GA_BackFill,-(a7)

	;	moveq	#1,d0
	;	move.l	d0,-(a7)
	;	move.l	#WHEEL_BevelBox,-(a7)

		move.l	a7,a2
		sub.l	a0,a0
		lea	wheelgadname(pc),a1
		jsr	_LVONewObjectA(a6)
		adda.w	#100,a7
		move.l	d0,oxWG_wheel(a4)
		rts

	movem.l	a3/a4/a6,-(a7)
		movem.w	d2/d3,-(a7)
		move.l	h_Data(a0),a3
		addq.l	#4,a1
		move.l	a1,a4

		bra.b	.penfill


		movem.w	(a1)+,d0-d3

.penfill	move.l	a2,a1
		moveq	#1,d0
		move.l	gfxbase(pc),a6
		jsr	_LVOSetAPen(a6)
		movem.w	(a4)+,d0-d3
		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d2/d3
		movem.l	(a7)+,a3/a4/a6
		rts

WG_fillbghook	movem.l	d2-d5/a3-a6,-(a7)
		lea	4(a1),a3
		move.l	h_Data(a0),a5

	;move.l	(a3),$70000


		btst	#oxWGB_NEWVERSION,oxWG_flags(a5)
		beq.b	.pop

		move.l	oxWG_drawinfo(a5),a4
		lea	-rp_SIZEOF(a7),a7

		move.l	a7,a1
		move.l	gfxbase(pc),a6
		jsr	_LVOInitRastPort(a6)

		move.l	a7,a1
		move.l	rp_BitMap(a2),rp_BitMap(a1)

		move.l	libbase(pc),a6
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.pen_fill

		move.l	oxDI_imagetable(a4),a0
		move.l	oxIT_bgimage(a0),d0
		bne.b	.image_fill

.pen_fill	move.l	oxDI_pentable(a4),a0
		move.b	oxPT_backpen(a0),d0
		move.l	gfxbase(pc),a6
		jsr	_LVOSetAPen(a6)
		move.l	a7,a1
		movem.w	(a3)+,d0-d3
		jsr	_LVORectFill(a6)
		bra.b	.restack

.image_fill	move.l	d0,a0
		movem.w	(a3)+,d0-d3

		movem.l	(a3),d4/d5

		bsr	_oxImageFill
.restack	lea	rp_SIZEOF(a7),a7
.pop		movem.l	(a7)+,d2-d5/a3-a6
		rts


WG_setpalette	; oxWG_HSB contains new color as got from setattr or from the wheel when it was changed
		; a4 *self

		; d7

		; setting palette requires ViewPort address

		move.l	oxWG_window(a4),a0
		move.l	wd_WScreen(a0),a0
		pea	sc_ViewPort(a0)

		; num pen

		lea	oxWG_pens(a4),a3
		moveq	#0,d5

.pens_lp	; adjust brightness to gradient

		moveq	#-1,d2		; is $FFFFFFFF
		move.l	d2,d0
		moveq	#oxWG_NUMPENS,d1
		bsr	_divu32
		move.l	d5,d1
		bsr	_mulu32
		sub.l	d0,d2
		move.l	d2,oxWG_HSB+cw_Brightness(a4)

		; make rgb from hsb		

		lea	oxWG_RGB(a4),a1
		lea	oxWG_HSB(a4),a0
		move.l	wheelbase(pc),a6
		jsr	_LVOConvertHSBToRGB(a6)

		; alloc pen from rgb values

		move.l	(a7),a0
		moveq	#0,d0
		move.w	(a3)+,d0
		bmi.b	.fix_stack
		movem.l	oxWG_RGB(a4),d1-d3
		move.l	gfxbase(pc),a6
		jsr	_LVOSetRGB32(a6)		
		addq.w	#1,d5
		bra.b	.pens_lp
.fix_stack	addq.l	#4,a7
		rts

WG_24toRGB	; input d1 $FFFFFF (max)
		; result d1,d2,d3

		push	d4

		moveq	#0,d2
		moveq	#0,d3
		move.b	d1,d3
		lsr.l	#8,d1
		move.b	d1,d2
		lsr.l	#8,d1

		move.l	d1,d0
		move.l	#$01010101,d1

		bsr	_mulu32	; d1*d0 to d0
		move.l	d0,d4

		move.l	d2,d0
		bsr	_mulu32
		move.l	d0,d2

		move.l	d3,d0
		bsr	_mulu32
		move.l	d0,d3

		move.l	d4,d1

		pop	d4
		rts

WG_RGBto24	; input		d1 = RED	$00000000 bis $ffffffff
		; 		d2 = GREEN	$00000000 bis $ffffffff
		; 		d3 = BLUE	$00000000 bis $ffffffff
		; output: d0 = $rrggbb

		moveq	#24,d0

		lsr.l	d0,d1
		lsr.l	d0,d2
		lsr.l	d0,d3

		moveq	#0,d0

		move.b	d1,d0
		lsl.l	#8,d0
		move.b	d2,d0
		lsl.l	#8,d0
		move.b	d3,d0

		rts

WG_FRONT	move.l	a0,a4

WG_add		bset	#oxWGB_FRONT,oxWG_flags(a4)
		bne.b	.rts

		tst.l	oxWG_wheel(a4)
		beq.b	.rts

		move.l	intbase(pc),a6

		move.l	oxWG_window(a4),a0
		move.l	oxWG_slider(a4),a1
		moveq	#0,d0
		jsr	_LVOAddGadget(a6)

		move.l	oxWG_window(a4),a0
		move.l	oxWG_wheel(a4),a1
		moveq	#0,d0
		jmp	_LVOAddGadget(a6)

.rts		rts

WGSETDEF	move.w	#80,oxWG_minsize(a0)
		move.l	#$FFFFFF,oxWG_color(a0)

		lea	WG_fillbghook(pc),a1
		move.l	a1,oxWG_fillbghook+h_Entry(a0)
		move.l	a0,oxWG_fillbghook+h_Data(a0)

		move.l	wheelbase(pc),a6

		cmp.w	#40,LIB_VERSION(a6)
		bgt.b	.ver
		bset	#oxWGB_OLDVERSION,oxWG_flags(a0)

.ver		cmp.w	#45,LIB_VERSION(a6)
		ble.b	.rts
		bset	#oxWGB_NEWVERSION,oxWG_flags(a0)

.rts		rts

WGINIT		rts

WGDEINIT	move.l	a0,a3

		; remove from window glist

		bsr.b	WG_rem

		; get rid of wheel and slider objects

		move.l	intbase(pc),a6

		move.l	oxWG_wheel(a3),a0		; pointer may be null !
		jsr	_LVODisposeObject(a6)		; (then routine has no effect)
		move.l	oxWG_slider(a3),a0
		jsr	_LVODisposeObject(a6)

		; eventually free gradient pens

		bclr	#oxWGB_PENS,oxWG_flags(a3)
		beq.b	.rts

		move.l	oxWG_window(a3),a0
		move.l	wd_WScreen(a0),a0
		move.l	sc_ViewPort+vp_ColorMap(a0),-(a7)

		clr.l	oxWG_window(a3)

		move.l	gfxbase(pc),a6

		lea	oxWG_pens(a3),a2
.pens_lp	moveq	#0,d0			; d0 must be ULONG
		move.w	(a2)+,d0
		bmi.b	.fix_stack			; if not all pens got, dont free all
		move.l	(a7),a0
		jsr	_LVOReleasePen(a6)
		bra.b	.pens_lp
.fix_stack	addq.l	#4,a7

.rts		rts

WG_BACK		move.l	a0,a3

WG_rem		bclr	#oxWGB_FRONT,oxWG_flags(a3)
		beq.b	.rts

		tst.l	oxWG_wheel(a3)
		beq.b	.rts

		move.l	intbase(pc),a6

		move.l	oxWG_window(a3),d0
		beq.b	.rts

		move.l	d0,a0
		move.l	oxWG_slider(a3),a1
		jsr	_LVORemoveGadget(a6)

		move.l	oxWG_window(a3),a0
		move.l	oxWG_wheel(a3),a1
		jmp	_LVORemoveGadget(a6)

.rts		rts

WGDRAW		move.l	a0,a4
		move.l	intbase(pc),a6

		btst	#oxWGB_OLDVERSION,oxWG_flags(a4)
		beq.b	.if_draw

		push	d2

		move.l	a4,a3
		bsr.b	WG_rem

		move.l	oxWG_wheel(a4),a0
		jsr	_LVODisposeObject(a6)
		clr.l	oxWG_wheel(a4)
		move.l	oxWG_slider(a4),a0
		jsr	_LVODisposeObject(a6)
		clr.l	oxWG_slider(a4)

		bsr	WG_calcslider
		bsr	WG_create_sl
		beq.b	.pop_rts

		bsr	WG_calcwheel
		bsr	WG_create_wh
		beq.b	.dispose_slider

		bsr	WG_add

		pop	d2

.if_draw	tst.l	oxWG_wheel(a4)
		beq.b	.rts

		bclr	#oxWGB_UPDATE,oxWG_flags(a4)
		bne.b	.update

		bsr	wg_refresh

.rts		moveq	#1,d0
		rts

.update		move.l	oxWG_color(a4),d1

		bsr	WG_24toRGB
		movem.l	d1-d3,oxWG_RGB(a4)

		tst.l	oxWG_wheel(a4)
		beq.b	.rts

		movem.l	d1-d3,-(a7)

		lea	oxWG_RGB(a4),a0
		lea	oxWG_HSB(a4),a1
		move.l	wheelbase(pc),a6
		jsr	_LVOConvertRGBToHSB(a6)

		bsr	WG_setpalette

		movem.l	(a7)+,d1-d3

		clr.l	-(a7)	; TAG_END
		move.l	d1,-(a7)
		move.l	#WHEEL_Red,-(a7)
		move.l	d2,-(a7)
		move.l	#WHEEL_Green,-(a7)
		move.l	d3,-(a7)
		move.l	#WHEEL_Blue,-(a7)
		move.l	oxWG_wheel(a4),a0
		move.l	a7,a1
		move.l	intbase(pc),a6
		jsr	_LVOSetAttrsA(a6)
		adda.w	#28,a7

		bsr	wg_refresh

		moveq	#1,d0
		rts

.dispose_slider	move.l	oxWG_slider(a4),a0
		jsr	_LVODisposeObject(a6)
		clr.l	oxWG_slider(a4)

.pop_rts	addq.l	#4,a7	; skip d2
		bra	.rts


wg_refresh	move.l	#GREDRAW_REDRAW,-(a7)
		move.l	oxWG_drawinfo(a4),a0
		move.l	oxDI_rastport(a0),-(a7)
		clr.l	-(a7)
		move.l	#GM_RENDER,-(a7)
		move.l	oxWG_wheel(a4),a0
		move.l	oxWG_window(a4),a1
		sub.l	a2,a2	; no requester
		move.l	a7,a3
		jsr	_LVODoGadgetMethodA(a6)

		move.l	oxWG_slider(a4),a0
		move.l	oxWG_window(a4),a1
		jsr	_LVODoGadgetMethodA(a6)

.pop		lea	4*4(a7),a7
		rts

WGGETLAYOUT	move.w	oxWG_minsize(a0),d0
		move.w	d0,d1			; square wheel
		add.w	#30,d0			; 20 pix slider, 10 pix space to wheel

		movem.w	d0/d1,oxLI_minwidth(a1)

		move.l	#$7fff7fff,oxLI_propw(a1)
		moveq	#1,d0
		rts

WGSETLAYOUT	move.l	oxLI_left(a1),oxWG_left(a0)
		move.l	oxLI_width(a1),oxWG_width(a0)

		move.l	a0,a4

WG_setl		; come here from set window/ make newobject

		tst.l	oxWG_slider(a4)
		beq.b	.rts0

		btst	#oxWGB_OLDVERSION,oxWG_flags(a4)
		bne.b	.rts1

		bsr	WG_calcslider

		move.l	#TAG_END,-(a7)
		move.l	d3,-(a7)
		move.l	#GA_Height,-(a7)
		move.l	d2,-(a7)
		move.l	#GA_Width,-(a7)
		move.l	d1,-(a7)
		move.l	#GA_Top,-(a7)
		move.l	d0,-(a7)
		move.l	#GA_Left,-(a7)

		move.l	oxWG_slider(a4),a0

	;	move.l	oxWG_window(a4),a1

		move.l	a7,a1
		move.l	intbase(pc),a6
		jsr	_LVOSetAttrsA(a6)
		lea	36(a7),a7

		bsr	WG_calcwheel

		move.l	#TAG_END,-(a7)
		move.l	d3,-(a7)
		move.l	#GA_Height,-(a7)
		move.l	d2,-(a7)
		move.l	#GA_Width,-(a7)
		move.l	d1,-(a7)
		move.l	#GA_Top,-(a7)
		move.l	d0,-(a7)
		move.l	#GA_Left,-(a7)

		move.l	oxWG_wheel(a4),a0

	;	move.l	oxWG_window(a4),a1

		move.l	a7,a1
		jsr	_LVOSetAttrsA(a6)
		lea	36(a7),a7

.rts1		moveq	#1,d0
		rts
.rts0		moveq	#0,d0
		rts

WG_calcslider	movem.w	oxWG_left(a4),d0-d3

		sub.w	#30,d2
		cmp.w	d3,d2
		ble.b	.flips
		move.w	d3,d2
		bra.b	.flops
.flips		move.w	d2,d3
.flops		movem.w	oxWG_left(a4),d0-d2

		add.w	d2,d0
		moveq	#20,d2
		sub.w	d2,d0
		rts

WG_calcwheel	movem.w	oxWG_left(a4),d0-d3

		sub.w	#30,d2
		cmp.w	d3,d2
		ble.b	.flip
		move.w	d3,d2
		bra.b	.flop
.flip		move.w	d2,d3
.flop
		rts


WG_INPUT	; *intuimessage a1

		cmp.l	#IDCMP_IDCMPUPDATE,im_Class(a1)
		bne.b	.rts_false

		; dont use id in old OS because from the wheel it isn't set

		btst	#oxWGB_OLDVERSION,oxWG_flags(a0)
		bne.b	.area

		; filter out messages from other gadgets

		move.l	oxExtM_gadget(a1),d1
		move.w	a0,d0			; little hack, geht nur solange nicht zwei untere wörter von zwei 
		cmp.w	d0,d1			; idcmpupdate-gadget-addressen gleich sind. SEHR unwahrscheinlich
		bne.b	.rts_false		; und daher sieg des praktischen ueber das erlaubte
						; (weil intuition/boopsi in der gad-id nur ein WORD hat)

		bra.b	.go_active

.area		; filter out messages that are not in our area,
		; do this only for old OS because there gad-id doesnt work for wheel

		movem.w	oxWG_left(a0),d0-d3
		bsr	_is_in_rect
		beq.b	.rts_false

.go_active	; go active (prev selected obj is inactivated from window subsequently)

		move.l	a0,a4

		bset	#oxWGB_ACTIVE,oxWG_flags(a4)
		bne.b	.normal

		move.l	a4,d1
		move.l	oxWG_drawinfo(a4),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		bsr	_oxSetAttr

.normal		move.l	#WHEEL_HSB,d0
		move.l	oxWG_wheel(a4),a0
		lea	oxWG_HSB(a4),a1
		move.l	intbase(pc),a6
		jsr	_LVOGetAttr(a6)

		bsr	WG_setpalette

		; refresh slider

		move.l	oxWG_slider(a4),a0
		move.l	oxWG_window(a4),a1
		moveq	#1,d0
		move.l	intbase(pc),a6
		jsr	_LVORefreshGList(a6)

		; read RGB from wheel

		move.l	#WHEEL_RGB,d0
		move.l	oxWG_wheel(a4),a0
		lea	oxWG_RGB(a4),a1
		move.l	intbase(pc),a6
		jsr	_LVOGetAttr(a6)

		movem.l	oxWG_RGB(a4),d1-d3
		bsr	WG_RGBto24
		move.l	d0,oxWG_color(a4)

		move.l	oxWG_hook(a4),d0
		beq.b	.rts_true

		move.l	libbase(pc),a6
		move.l	d0,a5
		move.l	oxWG_color(a4),d1
		move.l	a4,a0
		jsr	(a5)

.rts_true	moveq	#1,d0
		rts

.rts_false	moveq	#0,d0
		rts

;----------------------

auto_request	; a0	*text
		; a1	data	

		bsr	string_format
		beq.b	.print		; if no memory for string try w/o format
					; (not really usefull though)
		move.l	d0,a0

		bsr	 .print

		bra	free_rem

.print		pushm	a0/a2/a3/a6

		move.l	libbase(pc),a6
		move.l	oxB_intbase(a6),d0
		beq	.pop
		move.l	d0,a6

		lea	.it_body(pc),a1
		move.l	a0,it_IText(a1)	; insert *text into body intuitext
		sub.l	a0,a0		; no parent window
		sub.l	a2,a2		; no positive text
		lea	.it_ok(pc),a3	; negative text
		moveq	#0,d0
		moveq	#0,d1

		jsr	_LVOAutoRequest(a6)

.pop		popm	a0/a2/a3/a6
		rts

.it_body	dc.b	1,0		; the pens for rendering the text, front,back
		dc.b	0		; the mode for rendering the text
		dc.b	0		; pad
    		dc.w	0,0		; relative start location for the text, x,y
  		dc.l	0		; font, if NULL, you accept the defaults
		dc.l	0		; pointer to null-terminated text
		dc.l	0		; pointer to another IntuiText to render

.it_ok		dc.b	1,0		; the pens for rendering the text, front,back
		dc.b	0		; the mode for rendering the text
		dc.b	0		; pad
    		dc.w	0,0		; relative start location for the text, x,y
  		dc.l	0		; font, if NULL, you accept the defaults
		dc.l	.ok		; pointer to null-terminated text
		dc.l	0		; pointer to another IntuiText to render

.ok		dc.b	"OK",0
		even

string_format	; gets	a0	*templatestring
		;	a1	*datastream
		; gives	d0	*string new, must be freed with free_rem
		;				(automatizeable in objects)
		;		0 = no memory

		pushm	d1/a0-a3/a6

		move.l	4.w,a6

		clr.l	-(a7)
		move.l	a7,a3
		lea	.str_len_hook(pc),a2
		jsr	_LVORawDoFmt(a6)
		move.l	(a7)+,d0
		bsr	alloc_rem
		beq.b	.xfrsf_end

		move.l	d0,a3
		movem.l	4(a7),a0/a1
.string_into	lea	.put_str_hook(pc),a2
		jsr	_LVORawDoFmt(a6)
		move.l	a3,d0

.xfrsf_end	popm	d1/a0-a3/a6
		rts

.put_str_hook	move.b	d0,(a3)+
		rts
.str_len_hook	addq.l	#1,(a3)
		rts

;======================================================
; extended tag function, maybe not utilitylib compat.
;======================================================

get_a_tag	move.l	(a2)+,d0
		beq.b	.rts
		move.l	(a2)+,d1
		cmp.l	#3,d0		; return anything that is bigger 3 (system tags)
		bgt.b	.rts

		; system tags

		cmp.l	#TAG_IGNORE,d0
		beq.b	get_a_tag
		cmp.l	#TAG_MORE,d0
		beq.b	.more
		cmp.l	#TAG_SKIP,d0
		beq.b	.skip
.rts		rts
.skip		lsl.l	#3,d1
		add.l	d1,a2
		bra.b	get_a_tag
.more		move.l	d1,a2
		bra.b	get_a_tag


_oxImageDrawClip	; same as ImageDraw but is clipped to box

		; d0/d1/d2/d3 left/top/width/height
		; a0 *imagenode
		; a1 *rastport

		cmp.l	#0,a0
		beq.b	.rts

		movem.w	d0-d6,-(a7)
		push	a6

		move.w	d2,d4
		move.w	d3,d5

		move.w	d0,d2
		move.w	d1,d3

		move.l	oxIN_bitmapheader(a0),a6
	
		cmp.w	bmh_Width(a6),d4
		ble.b	.if_too_high
		move.w	bmh_Width(a6),d4
.if_too_high	cmp.w	bmh_Height(a6),d5
		ble.b	.get_bitmap
		move.w	bmh_Height(a6),d5

.get_bitmap	move.l	oxIN_bitmap(a0),a0

		moveq	#0,d0
		moveq	#0,d1

		move.b	#$C0,d6
		move.l	gfxbase(pc),a6
		jsr	_LVOBltBitMapRastPort(a6)

		pop	a6
		movem.w	(a7)+,d0-d6
.rts		rts

_oxImageDraw	; d0/d1 left/top
		; a0 *imagenode
		; a1 *rastport

		cmp.l	#0,a0
		beq.b	.rts

		movem.w	d0-d6,-(a7)
		pushm	a2/a6

		move.w	d0,d2
		move.w	d1,d3

		move.l	oxIN_bitmapheader(a0),a2
		move.l	oxIN_bitmap(a0),a0

		moveq	#0,d0
		moveq	#0,d1

		move.w	bmh_Width(a2),d4
		move.w	bmh_Height(a2),d5

		move.b	#$C0,d6
		move.l	gfxbase(pc),a6
		jsr	_LVOBltBitMapRastPort(a6)

		popm	a2/a6
		movem.w	(a7)+,d0-d6
.rts		rts


_oxImageFill	; d0-d3	left, top, right, bottom
		; d4/d5 preshift
		; a0 *imagenode	may be null
		; a1 *rastport

		cmp.l	#0,a0
		beq.b	.rts

		pushm	a0/a1/a2/a6
		movem.l	d2-d7,-(a7)
		movem.w	d0/d1/d4/d5,-(a7)
;		move.l	rp_BitMap(a1),-(a7)
		move.l	a1,-(a7)
		move.l	oxIN_bitmap(a0),-(a7)
		move.l	oxIN_bitmapheader(a0),a2

		move.l	gfxbase(pc),a6

 STRUCTURE	ImageFillHelp,0
	UWORD	ifh_width
	UWORD	ifh_height
	UWORD	ifh_1stxoffset
	UWORD	ifh_1styoffset
	UWORD	ifh_restx
	UWORD	ifh_resty
	UWORD	ifh_xrepeats
	UWORD	ifh_yrepeats
	UWORD	ifh_currentx
	UWORD	ifh_currenty
	LABEL	ifh_SIZEOF
	APTR	ifh_bitmap
	APTR	ifh_rastport
	UWORD	ifh_left
	UWORD	ifh_top
	UWORD	ifh_xpreshift
	UWORD	ifh_ypreshift

		lea	-ifh_SIZEOF(a7),a7

		; startpunkt festlegen

		move.w	d0,ifh_currentx(a7)
		move.w	d1,ifh_currenty(a7)

		; left und top offset berechnen, damit
		; mehrere gefüllte flächen nahtlos zusammen passen

		moveq	#0,d4
		move.w	d0,d4

		sub.w	ifh_xpreshift(a7),d4

		divu.w	bmh_Width(a2),d4
		swap	d4
		move.w	d4,ifh_1stxoffset(a7)

		moveq	#0,d5
		move.w	d1,d5

		sub.w	ifh_ypreshift(a7),d5

		divu.w	bmh_Height(a2),d5
		swap	d5
		move.w	d5,ifh_1styoffset(a7)

		; höhe und breite, zahl der widerholungen und restgröße berechnen

		sub.w	d0,d2
		addq.w	#1,d2
		move.w	d2,ifh_width(a7)
		moveq	#0,d6
		move.w	d2,d6
		move.w	bmh_Width(a2),d2
		clr.w	ifh_xrepeats(a7)
		sub.w	d2,d6
		bge.b	.div_x
		add.w	ifh_1stxoffset(a7),d6
		bra.b	.set_rx

.div_x		add.w	ifh_1stxoffset(a7),d6
		divu.w	d2,d6
		move.w	d6,ifh_xrepeats(a7)
		swap	d6

.set_rx		move.w	d6,ifh_restx(a7)

		sub.w	d1,d3
		addq.w	#1,d3
		move.w	d3,ifh_height(a7)
		moveq	#0,d7
		move.w	d3,d7
		move.w	bmh_Height(a2),d3
		clr.w	ifh_yrepeats(a7)
		sub.w	d3,d7
		bge.b	.div_y
		add.w	ifh_1styoffset(a7),d7
		bra.b	.set_ry

.div_y		add.w	ifh_1styoffset(a7),d7
		divu.w	d3,d7
		move.w	d7,ifh_yrepeats(a7)
		swap	d7

.set_ry		move.w	d7,ifh_resty(a7)

		; init x- and yrepcount

		moveq	#0,d6
		moveq	#0,d7

.loop_y

.loop_x		move.w	bmh_Width(a2),d4
		move.w	bmh_Height(a2),d5
		move.w	ifh_1stxoffset(a7),d0
		move.w	ifh_1styoffset(a7),d1

		tst.w	d6
		bne.b	.no_xoffset
		sub.w	d0,d4
		bra.b	.if_yoffset
.no_xoffset	moveq	#0,d0

.if_yoffset	tst.w	d7
		bne.b	.no_yoffset
		sub.w	d1,d5
		bra.b	.offsets_ok
.no_yoffset	moveq	#0,d1
.offsets_ok
		; nur noch ein rest übrig?

		cmp.w	ifh_xrepeats(a7),d6
		ble.b	.not_restx
		move.w	ifh_restx(a7),d4
.not_restx	cmp.w	ifh_yrepeats(a7),d7
		ble.b	.not_resty
		move.w	ifh_resty(a7),d5
.not_resty
		; test fit

		cmp.w	ifh_width(a7),d4
		ble.b	.if_higher
		move.w	ifh_width(a7),d4
.if_higher	cmp.w	ifh_height(a7),d5
		ble.b	.size_ok
		move.w	ifh_height(a7),d5
.size_ok
		; left top im dest-rastport

		move.w	ifh_currentx(a7),d2
		move.w	ifh_currenty(a7),d3		

		movem.l	ifh_SIZEOF(a7),a0/a1
		push	d6
		move.b	#$C0,d6
		jsr	_LVOBltBitMapRastPort(a6)
		pop	d6

		; advance x

		add.w	d4,ifh_currentx(a7)
		addq.w	#1,d6
		move.w	ifh_xrepeats(a7),d2
		addq.w	#1,d2
		cmp.w	d2,d6
		ble.b	.loop_x

		; reset xpos to left

		move.w	ifh_left(a7),ifh_currentx(a7)
		moveq	#0,d6

		; advance y

		add.w	d5,ifh_currenty(a7)
		addq.w	#1,d7
		move.w	ifh_yrepeats(a7),d3
		addq.w	#1,d3
		cmp.w	d3,d7
		ble.b	.loop_y

		lea	ifh_SIZEOF(a7),a7
		addq	#8,a7
		movem.w	(a7)+,d0/d1/d4/d5
		movem.l	(a7)+,d2-d7
		popm	a0/a1/a2/a6
.rts		rts

_oxGetImageSize ; d0 *imagename
		; a2 *storage w,h

		move.l	d0,a0
		moveq	#PRESET_IMAGE,d1
		bsr	find_preset
		tst.l	d0
		beq.b	.rts
		pushm	d0/d1
		bsr	getimgsize
		pop	a0
		pop	d1
		beq.b	.rts
		bsr	free_rem

.rts		rts

getimgsize	pushm	d2/a2/a6

		; see if the image is allready loaded

		; screen field isnt used here because sizes are the same for all loaded versions of an image

		move.l	libbase(pc),a6
		move.l	d0,a0		; name to compare to

		lea	oxB_imagelist(a6),a6
.get_next	move.l	(a6),a6
		tst.l	(a6)
		beq.b	.get_new

		; compare names

		move.l	oxIN_imagename(a6),a1
		bsr	MatchStringsNoCase
		bne.b	.get_next

		move.l	oxIN_bitmapheader(a6),a0

		move.w	bmh_Width(a0),(a2)+
		move.w	bmh_Height(a0),(a2)

		bra.b	.pop

.get_new	; *** get image from disk ***

		clr.l	(a2)		; return nothing if some error happens

		pushm	d0/d2/d3/d4/d5

		; get buffer to read into

		move.l	#1024,d3
		move.l	d3,d0
		bsr	alloc_rem
		move.l	d0,d5
		beq.b	.result

		; open file

		move.l	dosbase(pc),a6

		move.l	(a7),d1
		move.l	#MODE_OLDFILE,d2
		jsr	_LVOOpen(a6)
		move.l	d0,d4
		beq.b	.free_buffer

		; read some bytes

		move.l	d0,d1
		move.l	d5,d2

		jsr	_LVORead(a6)
		move.l	d0,d3
		ble.b	.close			; if nothing to read (0) or error (-1)

		move.l	d5,a0

		; see if file is BMP, extract sizes

		cmp.w	#"BM",(a0)
		bne.b	.if_iff

		move.b	$13(a0),d0
		lsl.w	#8,d0
		move.b	$12(a0),d0
		move.b	$17(a0),d1
		lsl.w	#8,d1
		move.b	$16(a0),d1

		btst	#7,$19(a0)
		beq.b	.write_size

		neg.w	d1

		bra.b	.write_size

.if_iff		; see if file is IFF, extract sizes

		cmp.l	#"BMHD",$c(a0)
		bne.b	.if_gif

		movem.w	$14(a0),d0/d1

		bra.b	.write_size

.if_gif		; see if file is GIF, extract size

		cmp.l	#"GIF8",(a0)
		bne.b	.if_png

		move.b	7(a0),d0
		lsl.w	#8,d0
		move.b	6(a0),d0
		move.b	9(a0),d1
		lsl.w	#8,d1
		move.b	8(a0),d1

		bra.b	.write_size

.if_png		; see if file is PNG, extract size

		cmp.l	#"IHDR",$c(a0)
		bne.b	.if_jpg

		movem.l	$10(a0),d0/d1

		bra.b	.write_size

.if_jpg		; see if file is JPG

		lea	(a0,d3.w),a1
		subq.l	#4,a1			; ehm, nicht über rand hinaus lesen?

		cmp.w	#$FFD8,(a0)+
		bne.b	.close

		; search for the "Start Of Frame 0" tag
		
.findtag_lp	cmp.b	#$ff,(a0)+
		bne.b	.findtag_lp_c
		cmp.b	#$C0,(a0)		; baseline jpg
		beq.b	.found
		cmp.b	#$C2,(a0)		; progressive jpg
		beq.b	.found

.findtag_lp_c	cmp.l	a0,a1
		bgt.b	.findtag_lp

		bra.b	.close

.found		; extract the sizes from JPG image

		addq.l	#4,a0

		move.b	(a0)+,d1
		lsl.w	#8,d1
		move.b	(a0)+,d1
		move.b	(a0)+,d0
		lsl.w	#8,d0
		move.b	(a0),d0

.write_size	movem.w	d0/d1,(a2)

.close		; close file

		move.l	d4,d1
		jsr	_LVOClose(a6)

.free_buffer	; free buffer mem

		move.l	d5,a0
		bsr	free_rem

.result		; result

		popm	d0/d2/d3/d4/d5

		tst.l	(a2)
		bne.b	.pop
	
		; *** get image with datatypes ***		

		move.l	dtbase(pc),a6

		clr.l	-(a7)	; TAG_END
		move.l	#GID_PICTURE,-(a7)
		move.l	#DTA_GroupID,-(A7)
		move.l	#PMODE_V43,-(a7)
		move.l	#PDTA_DestMode,-(a7)
		clr.l	-(a7)		; dont remap
		move.l	#PDTA_Remap,-(A7)
		move.l	a7,a0
		jsr	-48(a6)		;	_LVONewDTObjectA
		lea	28(a7),a7
		move.l	d0,d2
		beq.b	.pop

		move.l	d0,a0
		clr.l	-(a7)
		clr.l	-(a7)	; TAG_END
		pea	4(a7)
		move.l	#PDTA_BitMapHeader,-(a7)
		move.l	a7,a2
		jsr	-66(a6)		;	GetDTAttrsA
		lea	12(a7),a7
		move.l	(a7)+,a0

		move.l	(a7),a2

		move.w	bmh_Width(a0),(a2)+
		move.w	bmh_Height(a0),(a2)

		move.l	d2,a0
		jsr	-54(a6)		; _LVODisposeDTObject

.pop		popm	d2/a2/a6
		rts

PRESET_ICON	= 0
PRESET_IMAGE	= 1

find_preset	; this function tries some paths to find the required preset file image or icon

		; d0	*name
		; d1	preset type PRESET_IMAGE or PRESET_ICON

		; returns d0 *fullpath/filename or null if not found or something went wrong
		;     and d1 TRUE if string was allocated for the path

 STRUCTURE	fdi_help,0
	APTR	fdi_name
	APTR	fdi_alloc
	LABEL	fdi_SIZEOF

		tst.l	d0
		beq.b	.rts

		pushm	d2/d3/a2/a6		
		lea	-fdi_SIZEOF(a7),a7

		move.l	d1,d3

		move.l	a7,a2
		move.l	d0,fdi_name(a2)

		; see if the name for the preset has an absolute path in it

		move.l	d0,a0

.find_dp_loop	tst.b	(a0)
		beq.b	.try_subdir
		cmp.b	#":",(a0)+
		bne.b	.find_dp_loop

		; yeah, so we do, lets return the original path
		; and a flag that no memory was allocated for the path

		moveq	#FALSE,d1
		lea	fdi_SIZEOF(a7),a7
		popm	d2/d3/a2/a6
		rts

.try_subdir	; see if the dir for the preset is absolute

		move.l	libbase(pc),a0

		cmp.b	#PRESET_IMAGE,d3		
		bne	.ico
		move.l	oxB_imagesdir(a0),a1
		lea	.abs_path(pc),a0
		bra	.store
.ico		move.l	oxB_iconsdir(a0),a1
		lea	.abs_path_icon(pc),a0
.store		move.l	a1,d0
.try_sd_loop	tst.b	(a1)
		beq.b	.try_test_path
		cmp.b	#":",(a1)+
		bne.b	.try_sd_loop

		move.l	fdi_name(a2),-(a7)
		move.l	d0,-(a7)
		move.l	a7,a1
		bsr	string_format
		addq.l	#8,a7

		moveq	#TRUE,d1
		bra	.return

.try_test_path	move.l	fdi_name(a2),-(a7)

		bsr	.makepath

		move.l	a1,-(a7)
		pea	.progdir_path(pc)

		move.l	a7,a1
		bsr	string_format
		lea	12(a7),a7

		move.l	d0,fdi_alloc(a2)
		beq.b	.return

		move.l	d0,d1
		move.l	#ACCESS_READ,d2
		move.l	dosbase(pc),a6
		jsr	_LVOLock(a6)

		move.l	d0,d1
		beq.b	.try_path

.unlock_ok	jsr	_LVOUnLock(a6)
		move.l	fdi_alloc(a2),d0
		moveq	#TRUE,d1
		bra	.return

.makepath	move.l	libbase(pc),a0
		move.l	oxB_imagesdir(a0),a1
		lea	.images_template(pc),a0
		cmp.b	#PRESET_IMAGE,d3
		beq	.make

		move.l	libbase(pc),a0
		move.l	oxB_iconsdir(a0),a1
		lea	.icons_template(pc),a0

.make		rts

.try_path	move.l	fdi_alloc(a2),a0
		bsr	free_rem

; should rather be done for the imagepath, but i think its automated by the filerequester...
;		move.l	fdi_name(a2),a0
;.find_end_loop	tst.b	(a0)+
;		bne.b	.find_end_loop
;		subq.l	#1,a0
;		cmp.b	#"/",-(a0)
;		bne.b	.build
;		clr.b	(a0)		; remove slash if any

.build		move.l	fdi_name(a2),-(a7)

		bsr	.makepath

		move.l	a1,-(a7)
		move.l	libbase(pc),a1
		move.l	oxB_presetspath(a1),-(a7)

		move.l	a7,a1
		bsr	string_format
		lea	12(a7),a7

		move.l	d0,fdi_alloc(a2)
		beq.b	.return

		move.l	d0,d1
		move.l	#ACCESS_READ,d2
		move.l	dosbase(pc),a6
		jsr	_LVOLock(a6)

		move.l	d0,d1
		bne.b	.unlock_ok

		move.l	fdi_alloc(a2),a0
		bsr	free_rem

.return		lea	fdi_SIZEOF(a7),a7

		push	d0
		beq	.pop

		; remove .info so that icon library can find it

		cmp.b	#PRESET_ICON,d3
		bne	.pop

		move.l	d0,a0
.find_end	tst.b	(a0)+
		bne.b	.find_end
		clr.b	-6(a0)

.pop		pop	d0

		popm	d2/d3/a2/a6
.rts		rts

.progdir_path	dc.b	"progdir:presets/ox",0		; "sys:prefs/presets/ox" is default and searched AFTER this,
							; so that all can testrun without installation
.images_template dc.b	"%s/images/%s/%s",0		; <path>/images/<subdir>/<filename>
.icons_template	dc.b	"%s/icons/%s/%s.info",0		; <path>/icons/<subdir>/<filename>
.abs_path	dc.b	"%s/%s",0			; <absolute subdir>/<filename>
.abs_path_icon	dc.b	"%s/%s.info",0
		even




_oxGetImage	; d0 *imagename
		; a2 *window

		pushm	d1/d2/a0/a1

		moveq	#PRESET_IMAGE,d1
		bsr	find_preset
		tst.l	d0
		beq.b	.pop
		push	d0
		bsr	getimg
		pop	a0
		tst.l	d1
		beq.b	.pop
		bsr	free_rem

.pop		popm	d1/d2/a0/a1
		rts

getimg		; get only one of each name/screen (remap/resolution)

 		pushm	d1/d2/a0-a6

		tst.l	d0
		beq.b	.return_false

		move.l	wd_WScreen(a2),a2

		move.l	libbase(pc),a6
		lea	oxB_imagelist(a6),a5
.get_next	move.l	(a5),a5
		tst.l	(a5)
		beq.b	.get_new

		; compare names

		move.l	d0,a0
		move.l	oxIN_imagename(a5),a1
		bsr	MatchStringsNoCase
		bne.b	.get_next

		cmp.l	oxIN_screen(a5),a2
		bne.b	.get_next

		addq.w	#1,oxIN_userscount(a5)
		move.l	a5,d0
		popm	d1/d2/a0-a6
		rts

.get_new	move.l	d0,a3
		move.l	a6,a5
		move.l	dtbase(pc),a6

		; get image from disk

		clr.l	-(a7)	; TAG_END
		move.l	#GID_PICTURE,-(a7)
		move.l	#DTA_GroupID,-(A7)
		move.l	#1,-(a7)
		move.l	#PDTA_Remap,-(a7)
		move.l	#PMODE_V43,-(a7)
		move.l	#PDTA_DestMode,-(a7)
		move.l	a2,-(a7)		; screen
		move.l	#PDTA_Screen,-(a7)
		move.l	a7,a0
		jsr	-48(a6)		;	_LVONewDTObjectA
		lea	36(a7),a7
		move.l	d0,d1
		beq.b	.return_false

		; alloc image node

		moveq	#0,d3
		move.l	a3,a0
.name_len_lp	addq.w	#1,d3		; länge incl null am ende
		tst.b	(a0)+
		bne.b	.name_len_lp

		moveq	#oxIN_SIZEOF,d0
		add.w	d3,d0		; add space for name buffer (damit der übermittelte string temp sein kann)
		bsr	alloc_rem
		beq.b	.return_false

		move.l	d0,a1

		lea	oxIN_SIZEOF(a1),a0
		move.l	a0,oxIN_imagename(a1)

.copy_name_lp	move.b	(a3)+,(a0)+
		bne.b	.copy_name_lp

		move.l	d1,oxIN_dtobject(a1)
		move.l	a2,oxIN_screen(a1)
		addq.w	#1,oxIN_userscount(a1)

		move.l	a1,a4

		lea	oxB_imagelist(a5),a0
		ADDTAIL

		move.l	oxIN_dtobject(a4),a0	; dt object
		sub.l	a1,a1			; no win
		move.l	a1,a2			; no requester
		move.l	#1,-(a7)
		clr.l	-(a7)
		move.l	#DTM_PROCLAYOUT,-(a7)
		move.l	a7,a3
		jsr	-90(a6)		;	_LVODoDTMethodA
		lea	12(a7),a7

;	tst.l	d0
;	bmi.b	.drop_image

		move.l	oxIN_dtobject(a4),a0
		clr.l	-(a7)
		pea	oxIN_bitmapheader(a4)
		move.l	#PDTA_BitMapHeader,-(a7)
		pea	oxIN_bitmap(a4)
		move.l	#PDTA_DestBitMap,-(a7)
		move.l	a7,a2
		jsr	-66(a6)		;	GetDTAttrsA
		lea	20(a7),a7

		move.l	oxIN_bitmapheader(a4),d0
		beq.b	.drop_image
		move.l	d0,a0
		tst.l	bmh_Width(a0)
		beq.b	.drop_image

		move.l	a4,d0

.return_false	popm	d1/d2/a0-a6
		rts

.drop_image	move.l	a4,d0
		popm	d1/d2/a0-a6
		pushm	a0/a1/a6
		move.l	d0,a0
		bra.b	drop_image


_oxDropImage	; a0 *oxImageNode

		; befreien platz für imagenode+namestring

		subq.w	#1,oxIN_userscount(a0)
		bne.b	di_rts

		pushm	a0/a1/a6

drop_image	move.l	oxIN_dtobject(a0),-(a7)

		push	a0

		move.l	a0,a1
		REMOVE

		pop	a0
		bsr	free_rem

		move.l	(a7)+,a0
		move.l	dtbase(pc),a6
		jsr	-54(a6)		; _LVODisposeDTObject

		popm	a0/a1/a6
		moveq	#0,d0
di_rts		rts


EndOfLib


; env variables array of oxEnv structures, see ox.i


	section	config,data

config		dc.l	.opfolder,0,0			; folder name, default: 0 = folded / !0 = unfolded
		dc.b	oxEt_FOLDER,0			; type, unused
		dc.w	3				; number of next items in this folder (subfolders counted as 1)
		dc.l	.opdesc				; folder description (optional)

		dc.l	.doublebuffer,1,0			; name, default
		dc.b	oxEt_byte+oxEt_FLAG,oxBB_DOUBLEBUFFER   ; type, flagbit
		dc.w	oxB_configflags		; offset
		dc.l	.dbdesc				; description

		dc.l	.4colormode,0,0			; name, default
		dc.b	oxEt_byte+oxEt_FLAG,oxBB_4COLORMODE   ; type, flagbit
		dc.w	oxB_configflags		; offset
		dc.l	.4col_desc			; description

		dc.l	.ppath,.presets_path,0		; name, default
		dc.b	oxEt_text,0			; type, flagbit
		dc.w	oxB_presetspath		; offset
		dc.l	0				; description

		dc.l	.colfolder,0,0			; folder name, default: 0 = folded / !0 = unfolded
		dc.b	oxEt_FOLDER,0			; type, unused
		dc.w	19				; number of next items in this folder (subfolders counted as 1)
		dc.l	.coldesc				; folder description (optional)

		dc.l	.bcolor,$AAAAAA,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_backcolor		; offset, base
		dc.l	0				; description

		dc.l	.blcolor,$000000,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_blackcolor		; offset
		dc.l	0				; description

		dc.l	.wcolor,$ffffff,0			; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_whitecolor		; offset
		dc.l	0				; description

		dc.l	.ccolor,$8592b6,0			; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_colorcolor		; offset
		dc.l	0				; description

		dc.l	.tcolor,$000000,0			; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_textcolor		; offset
		dc.l	0				; description

		dc.l	.crcolor,$000000,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_cursorcolor	; offset
		dc.l	0				; description

		dc.l	.dcolor,$757d8c,0			; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_darkcolor		; offset
		dc.l	0				; description

		dc.l	.scolor,$e9e9e9,0			; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_shinecolor		; offset
		dc.l	0				; description

		dc.l	.btncolor,$AAAAAA,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_buttoncolor		; offset
		dc.l	0				; description

		dc.l	.tbcolor,$AAAAAA,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_tabscolor		; offset
		dc.l	0				; description

		dc.l	.ptAcolor,$AAAAAA,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_patternAcolor		; offset
		dc.l	0				; description

		dc.l	.ptBcolor,$697bc8,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_patternBcolor		; offset
		dc.l	0				; description

		dc.l	.listcolor,$aaaaaa,0 ;a2a0a7		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_listcolor		; offset
		dc.l	0				; description

		dc.l	.listselcolor,$8592b6,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_listselcolor		; offset
		dc.l	0				; description

		dc.l	.listtextcolor,$000000,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_listtextcolor	; offset
		dc.l	0				; description

		dc.l	.listaltcolor,$eaeaea,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_listalttextcolor	; offset
		dc.l	0				; description

		dc.l	.listoffcolor,$7c7c7c,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_listofftextcolor	; offset
		dc.l	0				; description

		dc.l	.inputcolor,$a19e9b,0		; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_inputcolor	; offset
		dc.l	0				; description

		dc.l	.inputtextcolor,$ffffff,0	; name, default
		dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
		dc.w	oxB_colortable+oxCT_inputtextcolor	; offset
		dc.l	0				; description

	;	dc.l	.inputseltextcolor,$ffffff,0	; name, default
	;	dc.b	oxEt_long+oxEt_HEX+oxEt_COLOR,0	; type, flagbit
	;	dc.w	oxB_colortable+oxCT_inputseltextcolor	; offset
	;	dc.l	0				; description

		dc.l	.icofolder,0,0			; folder name, default: 0 = folded / !0 = unfolded
		dc.b	oxEt_FOLDER,0			; type, unused
		dc.w	1				; number of next items in this folder (subfolders counted as 1)
		dc.l	.icodesc			; folder description (optional)

		dc.l	.icons_subdir,.default,0	; name, default
		dc.b	oxEt_text,0			; type, flagbit
		dc.w	oxB_iconsdir			; offset
		dc.l	0				; description

		dc.l	.imgfolder,0,0			; folder name, default: 0 = folded / !0 = unfolded
		dc.b	oxEt_FOLDER,0			; type, unused
		dc.w	11				; number of next items in this folder (subfolders counted as 1)
		dc.l	.imgdesc				; folder description (optional)

		dc.l	.usebgimages,1,0		; name, default
		dc.b	oxEt_byte+oxEt_FLAG,oxBB_USEBGIMAGES   ; type, flagbit
		dc.w	oxB_configflags		; offset
		dc.l	.usebgimgdesc			; description

		dc.l	.useimages,1,0			; name, default
		dc.b	oxEt_byte+oxEt_FLAG,oxBB_LOADIMAGES   ; type, flagbit
		dc.w	oxB_configflags		; offset
		dc.l	.useimgdesc			; description

		dc.l	.images_subdir,.default,0	; name, default
		dc.b	oxEt_text,0			; type, flagbit
		dc.w	oxB_imagesdir			; offset
		dc.l	0				; description

		dc.l	.bgimg,.defbgimg,0		; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_bgimage	; offset
		dc.l	0				; description

		dc.l	.winbgimg,.defwinbgimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_winbgimage	; offset
		dc.l	0				; description

		dc.l	.buttonbgimg,.defbuttonbgimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_buttonbgimage	; offset
		dc.l	0				; description

		dc.l	.gaugeimg,.defgaugeimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_gaugeimage	; offset
		dc.l	0				; description

		dc.l	.sliderimg,.defsliderimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_sliderimage	; offset
		dc.l	0				; description

		dc.l	.titlesimg,.deftitlesimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_titlesimage	; offset
		dc.l	0				; description

		dc.l	.menusimg,.defmenusimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_menusimage	; offset
		dc.l	0				; description

		dc.l	.selectimg,.defselectimg,0	; name, default
		dc.b	oxEt_IMAGE,0			; type, flagbit
		dc.w	oxB_imagetable+oxIT_selectimage	; offset
		dc.l	0				; description

	;	dc.l	.listbgimg,.deflistbgimg,0	; name, default
	;	dc.b	oxEt_IMAGE,0			; type, flagbit
	;	dc.w	oxB_imagetable+oxIT_listbgimage	; offset
	;	dc.l	0				; description

		dc.l	0	; end

.4colormode	dc.b	"4colormode",0
.4col_desc	dc.b	"Use the first 4 colors only and map "
		dc.b	"them into the higher.",$a,$a
		dc.b	"For example: buttoncolor and tabscolor are replaced by backcolor.",$a,$a
		dc.b	"This is usefull if you don't want to config the whole lot of colors separately or "
		dc.b	"if your system is low on colors.",0

.opfolder	dc.b	"options",0
.colfolder	dc.b	"colors",0
.imgfolder	dc.b	"images",0
.icofolder	dc.b	"icons",0

.bcolor		dc.b	"back color",0
.blcolor	dc.b	"black color",0
.wcolor		dc.b	"white color",0
.ccolor		dc.b	"color color",0
.tcolor		dc.b	"text color",0
.crcolor	dc.b	"cursor color",0
.dcolor		dc.b	"dark color",0
.scolor		dc.b	"shine color",0
.btncolor	dc.b	"button color",0
.tbcolor	dc.b	"tabs color",0
.ptAcolor	dc.b	"patternA color",0
.ptBcolor	dc.b	"patternB color",0

.listcolor	dc.b	"list color",0
.listselcolor	dc.b	"listsel color",0
.listtextcolor	dc.b	"listtext color",0
.listaltcolor	dc.b	"listalttext color",0
.listoffcolor	dc.b	"listofftext color",0

.inputcolor	dc.b	"input color",0
.inputtextcolor	dc.b	"inputtext color",0
.inputseltextcolor dc.b	"inputseltext color",0

.winbgimg	dc.b	"window back image",0
.bgimg		dc.b	"misc back image",0
.buttonbgimg	dc.b	"button image",0
.gaugeimg	dc.b	"gauge image",0
.sliderimg	dc.b	"slider image",0
.titlesimg	dc.b	"titles image",0
.menusimg	dc.b	"menus image",0
.selectimg	dc.b	"listbar image",0

.opdesc		dc.b	"Edit general global options.",0
.imgdesc	dc.b	"Set up all the back//fill images.",0
.icodesc	dc.b	"Configure the global symbols.",0
.pfdesc		dc.b	"Here you can edit the pen numbers directly. Usefull if you are low on colors.",0
.coldesc	dc.b	"Here you can edit all the colors.",0
.useimgdesc	dc.b	"Load and display Images. Turn this of on slow systems.",0

.usebgimgdesc	dc.b	"Turn this off to use the colors instead of backfill images!",0

.ppath		dc.b	"presets path",0
.images_subdir	dc.b	"skin images dir",0
.icons_subdir	dc.b	"icon theme",0

.usebgimages	dc.b	"use skin",0
.useimages	dc.b	"show pics",0
.doublebuffer	dc.b	"doublebuffer",0
.dbdesc		dc.b	"This is for soft redraw of elements, on the cost of speed.",0

.defbgimg	dc.b	"background.jpg",0
;.deflistbgimg	dc.b	"background.jpg",0
.defbuttonbgimg	dc.b	"button.jpg",0
.defwinbgimg	dc.b	"window.jpg",0
.defgaugeimg	dc.b	"gauge.jpg",0
.defsliderimg	dc.b	"slider.jpg",0
.deftitlesimg	dc.b	"titles.jpg",0
.defmenusimg	dc.b	"menus.jpg",0
.defselectimg	dc.b	"select.jpg",0

.presets_path	dc.b	"sys:prefs/presets/ox",0
.default	dc.b	"default",0

		even

	section	borders,data

radio_border	; black	
		dc.w	0,0			; left, top
		dc.b	1,0,0,9			; front-pen, back-pen, drawmode, xy-count
		dc.l	.coords_black
		dc.l	.white

.coords_black	dc.w	3,0
		dc.w	11,0
		dc.w	14,3
		dc.w	14,11
		dc.w	11,14
		dc.w	3,14
		dc.w	0,11
		dc.w	0,3
		dc.w	2,1

.white		dc.w	0,0
		dc.b	2,0,0,5
		dc.l	.coords_white
		dc.l	.blue

.coords_white	dc.w	11,1
		dc.w	3,1
		dc.w	1,3
		dc.w	1,11
		dc.w	2,12

.blue		dc.w	0,0
		dc.b	3,0,0,5
		dc.l	.coords_blue
		dc.l	0

.coords_blue	dc.w	12,2
		dc.w	13,3
		dc.w	13,11
		dc.w	11,13
		dc.w	3,13


radio_border_p	; black	
		dc.w	0,0
		dc.b	1,0,0,9
		dc.l	.coords_black
		dc.l	.white

.coords_black	dc.w	3,0
		dc.w	11,0
		dc.w	14,3
		dc.w	14,11
		dc.w	11,14
		dc.w	3,14
		dc.w	0,11
		dc.w	0,3
		dc.w	2,1

.white		dc.w	0,0
		dc.b	3,0,0,5
		dc.l	.coords_white
		dc.l	.blue

.coords_white	dc.w	11,1
		dc.w	3,1
		dc.w	1,3
		dc.w	1,11
		dc.w	2,12

.blue		dc.w	0,0
		dc.b	2,0,0,5
		dc.l	.coords_blue
		dc.l	0

.coords_blue	dc.w	12,2
		dc.w	13,3
		dc.w	13,11
		dc.w	11,13
		dc.w	3,13

	section	images,data_c

drop_pointer	dc.w	15,16
		dc.w	-7,-7

		dc.w	0,0

		dc.w	%0000000100000000,0
		dc.w	%0000000100000000,0
		dc.w	%0000000100000000,0
		dc.w	%0000010101000000,0
		dc.w	%0000001110000000,0
		dc.w	%0001000100001000,0
		dc.w	%0000100000010000,0
		dc.w	%1111110000111111,0
		dc.w	%0000100000010000,0
		dc.w	%0001000100001000,0
		dc.w	%0000001110000000,0
		dc.w	%0000010101000000,0
		dc.w	%0000000100000000,0
		dc.w	%0000000100000000,0
		dc.w	%0000000100000000,0

		dc.w	0,0

wait_pointer	dc.w	16,16
		dc.w	-6,0

		dc.w	0,0

		dc.w	$0400, $07C0
		dc.w	$0000, $07C0
		dc.w	$0100, $0380
		dc.w	$0000, $07E0
		dc.w	$07C0, $1FF8
		dc.w	$1FF0, $3FEC
		dc.w	$3FF8, $7FDE
		dc.w	$3FF8, $7FBE
		dc.w	$7FFC, $FF7F
		dc.w	$7EFC, $FFFF
		dc.w	$7FFC, $FFFF
		dc.w	$3FF8, $7FFE
		dc.w	$3FF8, $7FFE
		dc.w	$1FF0, $3FFC
		dc.w	$07C0, $1FF8
		dc.w	$0000, $07E0

		dc.w	0,0

	section	buffers,bss

class_index	blk.l	OX_NUMBER_OF_INTERNAL_CLASSES

; ox eXternal User Interfaces
		END

