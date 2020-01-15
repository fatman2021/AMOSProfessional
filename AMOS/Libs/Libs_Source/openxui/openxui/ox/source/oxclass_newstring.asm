
        	include exec/funcdef.i
 		include exec/types.i

		include	exec/exec_lib.i

		include ox.i
		include	ox_lib.i

		include	easy.i

		include	graphics/regions.i
		include graphics/graphics_lib.i

		include	intuition/intuition_lib.i
		include	devices/inputevent.i

		include	"utility/tagitem.i"

;--------------------------------------------------------------------
; OX_NEWSTRING

		include	oxclass_newstring.i

; concept
; - no clipping, print only as many chars as fit
; - allways max lenght of 256 chars (internally + 1 for space or zero termination)

; todo
; - wenn objekt initialisiert ist und ein neuer string gesetzt wird, soll das DELFIRST bit gelöscht werden
;   (erst machen wenn xufilter das braucht um aus der liste den filenamen und den kommentar zu setzen obwohl
;   da von anfang an ein instabiler text steht)

 STRUCTURE	oxNewString,oxO_SIZEOF
	UWORD	oxNS_minwidth		; incl frames
	UWORD	oxNS_left
	UWORD	oxNS_top
	UWORD	oxNS_width
	UWORD	oxNS_height
	UWORD	oxNS_propw

	UWORD	oxNS_stringlenght
	APTR	oxNS_string
	UWORD	oxNS_maxlenght

	UWORD	oxNS_offset		; number of chars scrolled left out
	UWORD	oxNS_inpos		; cursor char from char offset
	UWORD	oxNS_visiblechars

	ULONG	oxNS_value
	ULONG	oxNS_minvalue
	ULONG	oxNS_maxvalue

	APTR	oxNS_drawinfo

	APTR	oxNS_prev		; for tab-linking
	APTR	oxNS_next
	APTR	oxNS_enterobject	; ptr to ptr, bit 0 must be clearedchecked to get ptr from ptr or from (a4,offset)
	APTR	oxNS_enterhook
	APTR	oxNS_edithook

	UBYTE	oxNS_senschar
	UBYTE	oxNS_flags

	LABEL	oxNS_SIZEOF

	; flags

	BITDEF	oxNS,HEX,0
	BITDEF	oxNS,DEZ,1
	BITDEF	oxNS,EVEN,2
	BITDEF	oxNS,DELFIRST,3		; click is not the first click - useful if you want the initial content
					; to dissappear when this gadget is clicked for the first time!
	BITDEF	oxNS,VISIBLE,5
	BITDEF	oxNS,OFF,6
	BITDEF	oxNS,ACTIVE,7

oxNS_BUFFERSIZE	= 255			; string buffer size

TRUE		= 1
FALSE		= 0

OXCLASS_VERSION		= 1
OXCLASS_REVISION	= 0

	OXCLASSHEADER

OXCLASS_NAME	dc.b	"newstring",0
OXCLASS_DESC	dc.b	"$VER: String Gadget v"
		dc.b	$30+OXCLASS_VERSION,".",$30+OXCLASS_REVISION," "
		dc.b	"can edit text, hex or dez, supports min//max value bounds. "
		dc.b	"Can call a hook and//or activate annother gadget when <enter> is pressed.",0
OXCLASS_AUTHOR	dc.b	"Andreas G. Szabo",0
		even

OXCLASS_TAGS	dc.l	oxCA_objectsize,oxNS_SIZEOF
		dc.l	oxCA_dispatcher,.dispatcher
		dc.l	oxCA_description,OXCLASS_DESC
		dc.l	oxCA_author,OXCLASS_AUTHOR
		dc.l	oxCA_makeexample,.cr_example
	;	dc.l	oxCA_basesize,
	;	dc.l	oxCA_envarray,
		dc.l	TAG_END

.dispatcher	cmp.w	#OXM_SET,d1
		beq	NS_SET

		cmp.w	#OXM_DRAW,d1
		beq	NS_DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	NS_UPDATE

		cmp.w	#OXM_INTUIMESSAGE,d1
		beq	NS_INTUI

		cmp.w	#OXM_GETLAYOUT,d1
		beq	NS_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	NS_SETLAYOUT

		cmp.w	#OXM_ACTIVATE,d1
		beq	NS_ACTIVATE

		cmp.w	#OXM_INACTIVE,d1
		beq	NS_INACTIVE

		cmp.w	#OXM_BACK,d1
		beq	NS_BACK

		cmp.w	#OXM_FRONT,d1
		beq	NS_FRONT

		cmp.w	#OXM_DEINIT,d1
		beq	NS_DEINIT

		cmp.w	#OXM_INIT,d1
		beq	NS_INIT

		cmp.w	#OXM_SETDEF,d1
		beq	NS_SETDEF

		cmp.w	#OXM_RELINK,d1
		beq	NS_RELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	NS_LINKPRIV

		rts

.cr_example	lea	.example(pc),a2
		moveq	#0,d2
		jmp	_LVOoxCreateObject(a6)

.example	dc.l	OX_BUFFER,.buffer

 STRUCTURE	newstringexample,0
	APTR	nsx_gad1
	APTR	nsx_gad2
	APTR	nsx_gad3
	APTR	nsx_gad4
	LABEL	nsx_SIZEOF

.buffer		dc.l	oxBfA_buffersize,nsx_SIZEOF
		dc.l	OX_VERTGROUP,.vg_tags
		dc.l	TAG_END

.vg_tags	dc.l	OXCLASS_NAME,.gad1
		dc.l	OXCLASS_NAME,.gad2
		dc.l	OX_HORIZGROUP,.hg
		dc.l	oxGA_hprop,1
		dc.l	oxGA_minspace,10
		dc.l	TAG_END

.hg		dc.l	OXCLASS_NAME,.gad3
		dc.l	OXCLASS_NAME,.gad4
		dc.l	oxGA_spaceprop,FALSE
		dc.l	TAG_END

.gad1		dc.l	oxA_propw,TRUE
		dc.l	oxNSA_string,.tx1
		dc.l	oxNSA_enterobject,OX_REL|nsx_gad4
		dc.l	OX_RELPTR,nsx_gad1
		dc.l	TAG_END

.gad2		dc.l	oxA_minwidth,200
		dc.l	oxNSA_ghosted,TRUE
		dc.l	oxNSA_string,.tx2
		dc.l	OX_RELPTR,nsx_gad2
		dc.l	oxNSA_enterobject,OX_REL|nsx_gad1
		dc.l	TAG_END

.gad3		dc.l	oxA_minwidth,50
		dc.l	oxA_senschar,"a"
		dc.l	oxNSA_dez,TRUE
		dc.l	oxNSA_value,222
		dc.l	oxNSA_maxlenght,3
		dc.l	oxNSA_minvalue,3
		dc.l	oxNSA_maxvalue,500
		dc.l	oxNSA_delfirst,TRUE
		dc.l	OX_RELPTR,nsx_gad3
		dc.l	oxNSA_enterobject,OX_REL|nsx_gad1
		dc.l	TAG_END

.gad4		dc.l	oxA_minwidth,35
		dc.l	oxA_senschar,"a"
		dc.l	oxNSA_dez,TRUE
		dc.l	oxNSA_value,20
		dc.l	oxNSA_maxlenght,4
		dc.l	oxNSA_minvalue,10
		dc.l	oxNSA_maxvalue,30
		dc.l	OX_RELPTR,nsx_gad4
		dc.l	oxNSA_enterobject,OX_REL|nsx_gad3
		dc.l	TAG_END

.tx1		dc.b	"Donau Dampf Schiff Fahrts Gesellschafts Vorstands Vorsteher Muetzen Krempe",0
.tx2		dc.b	"turned off",0
		even


NS_FRONT	bset	#oxNSB_VISIBLE,oxNS_flags(a0)
		rts

NS_BACK		bclr	#oxNSB_VISIBLE,oxNS_flags(a0)
		rts

NS_SETDEF	move.l	#oxNS_BUFFERSIZE,d0
		move.w	d0,oxNS_maxlenght(a3)
		move.w	#$40,oxNS_minwidth(a3)
		move.l	#$ffffffff,oxNS_maxvalue(a3)
		addq.l	#1,d0			; put a space for termination or cursor at end
		bsr	alloc_mem
		move.l	d0,oxNS_string(a3)
		beq.b	.rts
		move.l	d0,a0
		move.b	#$20,(a0)		; initial string cursor space

.rts		rts

NS_SET		movem.l	(a1),d0/d1/a1

.dri		cmp.w	#oxA_drawinfo,d0
		bne.b	.next
		move.l	d1,oxNS_drawinfo(a0)
		rts

.next		cmp.w	#oxA_next,d0
		bne.b	.prev
		move.l	d1,oxNS_next(a0)
		rts

.prev		cmp.w	#oxA_prev,d0
		bne.b	.propw
		move.l	d1,oxNS_prev(a0)
		rts

.propw		cmp.w	#oxA_propw,d0
		bne.b	.minwidth
		move.w	d1,oxNS_propw(a0)
		rts

.minwidth	cmp.w	#oxA_minwidth,d0
		bne.b	.senschar
		move.w	d1,oxNS_minwidth(a0)
		rts

.senschar	cmp.w	#oxA_senschar,d0
		bne.b	.enterhook
		move.b	d1,oxNS_senschar(a0)
		rts

.enterhook	cmp.w	#oxNSA_enterhook,d0
		bne.b	.edithook
		move.l	d1,oxNS_enterhook(a0)
		rts

.edithook	cmp.w	#oxNSA_edithook,d0
		bne.b	.enterob
		move.l	d1,oxNS_edithook(a0)
		rts

.enterob	cmp.w	#oxNSA_enterobject,d0
		bne.b	.maxl
		move.l	d1,oxNS_enterobject(a0)
		rts

.maxl		cmp.w	#oxNSA_maxlenght,d0
		bne.b	.str
		cmp.w	#oxNS_BUFFERSIZE,d1
		ble.b	.set_ml
		move.w	#oxNS_BUFFERSIZE,d1
.set_ml		move.w	d1,oxNS_maxlenght(a0)
		move.l	oxNS_string(a0),a1
		move.b	#" ",(a1,d1.w)
		cmp.w	oxNS_stringlenght(a0),d1
		bge	.clrpos
		move.w	d1,oxNS_stringlenght(a0)
.clrpos		clr.w	oxNS_offset(a0)
		clr.w	oxNS_inpos(a0)
		rts

.str		cmp.w	#oxNSA_string,d0
		bne.b	.ghosted

		clr.w	oxNS_offset(a0)
		clr.w	oxNS_inpos(a0)

		move.l	oxNS_string(a0),a1
		tst.l	d1		; if no text, set lenght to 0
		beq.b	.set_null_len
		move.l	d1,a2
		move.w	oxNS_maxlenght(a0),d1
		beq	.set_null_len
		moveq	#0,d0
.cpy_lp		move.b	(a2)+,(a1)+
		beq.b	.terminate
		addq.w	#1,d0
		dbf	d1,.cpy_lp
		subq.w	#1,d0
.terminate	move.b	#$20,-(a1)	; terminate with space so that there is a possible cursor pos at end
.set_len	move.w	d0,oxNS_stringlenght(a0)
		rts
.set_null_len	clr.w	oxNS_stringlenght(a0)
		move.b	#$20,(a1)
		rts

.ghosted	cmp.w	#oxNSA_ghosted,d0
		bne.b	.hex
		moveq	#oxNSF_OFF,d0
		bsr	.flag


		rts

.hex		cmp.w	#oxNSA_hex,d0
		bne.b	.dez
		moveq	#oxNSF_HEX,d0
		bra	.flag

.dez		cmp.w	#oxNSA_dez,d0
		bne.b	.even
		moveq	#oxNSF_DEZ,d0
		bra	.flag

.even		cmp.w	#oxNSA_even,d0
		bne.b	.min
		moveq	#oxNSF_EVEN,d0
		bra.b	.flag

.min		cmp.w	#oxNSA_minvalue,d0
		bne.b	.max
		move.l	d1,oxNS_minvalue(a0)
		rts

.max		cmp.w	#oxNSA_maxvalue,d0
		bne.b	.val
		move.l	d1,oxNS_maxvalue(a0)
		rts

.val		cmp.w	#oxNSA_value,d0
		bne.b	.df
		move.l	d1,oxNS_value(a3)

		btst	#oxOB_INITIALIZED,oxO_flags(a3)
		beq.b	.rts

		bra	calc_string

.rts		rts

.df		cmp.w	#oxNSA_delfirst,d0
		bne	.rts
		moveq	#oxNSF_DELFIRST,d0

.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxNS_flags(a0)
		rts
.clearflag	not.w	d0
		and.b	d0,oxNS_flags(a0)
		rts


NS_INIT		bsr	calc_string

		moveq	#1,d0
		rts

calc_value	; calc value from string

		moveq	#0,d0
		move.w	oxNS_stringlenght(a3),d0
		beq	.store_val

		move.l	oxNS_string(a3),a0

		btst	#oxNSB_HEX,oxNS_flags(a3)
		beq.b	.dez

		bsr	hex_to_val
		bra	.store_val

.dez		btst	#oxNSB_DEZ,oxNS_flags(a3)
		beq.b	calc_string

		bsr	dez_to_val

.store_val	move.l	d0,oxNS_value(a3)

calc_string	; check value and calc string from value

		move.l	oxNS_value(a3),d0

		cmp.l	oxNS_minvalue(a3),d0
		bls.b	.get_min

		cmp.l	oxNS_maxvalue(a3),d0
		bls.b	.even

		move.l	oxNS_maxvalue(a3),d0
		bra.b	.even

.get_min	move.l	oxNS_minvalue(a3),d0

.even		btst	#oxNSB_EVEN,oxNS_flags(a3)
		beq.b	.val_to_string
		bclr	#0,d0

.val_to_string	move.l	d0,oxNS_value(a3)

		move.l	oxNS_string(a3),a0
		move.l	a0,a1

		; calc text from value, set lenght

		btst	#oxNSB_HEX,oxNS_flags(a3)
		beq.b	.if_dez

		move.w	oxNS_maxlenght(a3),d1
		move.w	d1,oxNS_stringlenght(a3)
		adda.w	d1,a1
		move.b	#$20,(a1)
		bra	val_to_hex

.if_dez		btst	#oxNSB_DEZ,oxNS_flags(a3)
		beq.b	.rts

		bsr	val_to_dez
		move.b	#$20,(a0)
		sub.l	a1,a0
		move.w	a0,oxNS_stringlenght(a3)

.rts		rts


NS_DEINIT	move.l	oxNS_string(a3),d0
		beq.b	.rts

		move.l	d0,a0
		move.l	#oxNS_BUFFERSIZE,d0
		addq.l	#1,d0			; zero byte at end
		bra	free_mem

.rts		rts


NS_DRAW		; draw frame, dont fill inner (is done from NS_draw_string)

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a2
		move.l	oxDI_pentable(a1),a5

		movem.w	oxNS_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3
	
		move.b	oxPT_darkpen(a5),d4			; topleft color
		move.b	oxPT_shinepen(a5),d5			; bottomright color

		jsr	_LVOoxBevelBorder(a6)

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.b	oxPT_blackpen(a5),d4	; topleft color
		move.b	d4,d5			; bottomright color

		jsr	_LVOoxBevelBorder(a6)

NS_draw_string	; fill/draw inner content, not the frames 

		pushm	d0-a6

		move.l	oxB_gfxbase(a6),a6

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a2
		move.l	oxDI_pentable(a1),a5

		move.b	oxPT_inputpen(a5),d0		; block color
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	oxNS_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3

		addq.w	#2,d0
		addq.w	#2,d1
		subq.w	#3,d2
		subq.w	#3,d3

		movem.w	d0/d1,-(a7)

		move.l	a2,a1
		jsr	_LVORectFill(a6)		; can do image fill here

		movem.w	(a7)+,d0/d1

		addq.w	#2,d0
		addq.w	#2,d1
		add.w	rp_TxBaseline(a2),d1

		; print text that fits

		move.l	oxNS_string(a3),d5
		beq	.ghosted

		add.w	oxNS_offset(a3),d5

		movem.w	d0/d1,-(a7)

		pushm	a2/a3

		move.w	oxNS_width(a3),d2
		sub.w	#2+2+2+2,d2
		move.w	rp_TxHeight(a2),d3

		move.w	oxNS_stringlenght(a3),d0
		sub.w	oxNS_offset(a3),d0

		addq.w	#1,d0				; at least one space

		move.l	d5,a0
		moveq	#1,d1
		sub.l	a3,a3
		lea	-te_SIZEOF(a7),a7
		move.l	a2,a1
		move.l	a7,a2
		jsr	-696(a6)			; _LVOTextFit(a6)
		lea	te_SIZEOF(a7),a7

		popm	a2/a3

		move.w	d0,d4

		movem.w	(a7),d0/d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.b	oxPT_inputtextpen(a5),d0
		move.b	oxPT_inputpen(a5),d1
		moveq 	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		move.l	d5,a0
		move.l	a2,a1
		move.w	d4,d0
		jsr	_LVOText(a6)

		movem.w	(a7)+,d0/d1

		; print cursor if _ACTIVE bit is set

		btst	#oxNSB_ACTIVE,oxNS_flags(a3)
		beq	.ghosted

		movem.w	d0/d1,-(a7)

		; set front and back color and drawmode for cursor

		move.b	oxPT_inputtextpen(a5),d0
		move.b	oxPT_cursorpen(a5),d1
		moveq 	#RP_JAM2,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		; calc cursor pos and move to start point

		move.l	d5,a0
		move.w	oxNS_inpos(a3),d0

		move.l	a2,a1
		jsr	_LVOTextLength(a6)

		add.w	(a7)+,d0
		move.w	(a7)+,d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		; print cursor

		move.l	d5,a0
		adda.w	oxNS_inpos(a3),a0
		moveq	#1,d0
		move.l	a2,a1
		jsr	_LVOText(a6)

.ghosted	btst	#oxNSB_OFF,oxNS_flags(a3)
		beq.b	.restore

		lea	.ghostpattern(pc),a0
		move.l	a0,rp_AreaPtrn(a2)
		move.b	#1,rp_AreaPtSz(a2)
		move.b	oxPT_blackpen(a5),d0
		moveq	#0,d1
		moveq 	#RP_JAM1,d2
		move.l	a2,a1
		jsr	_LVOSetABPenDrMd(a6)

		movem.w	oxNS_left(a3),d0-d3

		add.w	d0,d2
		add.w	d1,d3
		add.w	#4,d0
		add.w	#3,d1
		subq.w	#5,d2
		subq.w	#4,d3

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

.restore	popm	d0-a6

		moveq	#1,d0
		rts

.ghostpattern	dc.w	%1000100010001000
		dc.w	%0010001000100010

NS_draw_string_rf

		movem.l	a0-a3,-(a7)

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_windowobject(a1),a0
		moveq	#0,d4
		jsr	_LVOoxBeginRefresh(a6)

		bsr	NS_draw_string

		movem.w	oxNS_left(a3),d0-d3

		moveq	#0,d4
		move.l	oxNS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0

		jsr	_LVOoxEndRefresh(a6)

		movem.l	(a7)+,a0-a3
rf_rts		rts

NS_UPDATE	; redraw string only when we are open and visible, do not redraw the frame

		move.l	oxNS_drawinfo(a3),a0
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a0)
		beq	rf_rts

		btst	#oxNSB_VISIBLE,oxNS_flags(a3)
		beq	rf_rts

		; (with double buffer)

		bra	NS_draw_string_rf

NS_GETLAYOUT	move.w	oxNS_minwidth(a0),oxLI_minwidth(a1)

		move.l	oxNS_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),d0			; line height
		addq.w	#8,d0				; frame and spacing
		move.w	d0,oxLI_minheight(a1)
		move.w	d0,oxNS_height(a0)		; fixed height
		move.w	oxNS_propw(a0),oxLI_propw(a1)
		clr.w	oxLI_proph(a1)

		moveq	#1,d0
		rts


NS_SETLAYOUT	move.w	oxLI_width(a1),d0

		tst.w	oxNS_propw(a0)
		bne.b	.setw

		move.w	oxNS_minwidth(a0),d0

.setw		move.w	d0,oxNS_width(a0)
		move.l	oxLI_left(a1),oxNS_left(a0)

		moveq	#1,d0
		rts

NS_INTUI	; listen for chars, cursor, del and bsp, enter or tab, allways call refresh full content

		btst	#oxNSB_OFF,oxNS_flags(a3)
		bne.b	.rts

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq.b	.button

		cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		beq	.key

		btst	#oxNSB_ACTIVE,oxNS_flags(a3)
		beq	.rts

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		bne.b	.rts

		; tab prev

		cmp.w	#$42,im_Code(a1)
		bne.b	.right

		move.l	oxNS_prev(a3),d4
		bra.b	.nextprev

.key		btst	#oxNSB_ACTIVE,oxNS_flags(a3)
		beq	.sens


		cmp.w	#$d,im_Code(a1)
		beq.b	.enter

		;  tab next

		cmp.w	#$9,im_Code(A1)
		bne	.entf

		move.l	oxNS_next(a3),d4

.nextprev	beq	.rts_used

		bsr	calc_value

		move.l	d4,a0
		moveq	#OXM_ACTIVATE,d1
		jsr	_LVOoxDoMethod(a6)

.rts_used	moveq	#1,d0
.rts		rts

.sens		move.b	oxNS_senschar(a3),d1
		cmp.b	im_Code+1(a1),d1
		beq	NS_ACTIVATE
		rts

.entf		cmp.w	#$7f,im_Code(a1)
		bne.b	.if_bsp

		; entfernen

		move.w	oxNS_stringlenght(a3),d0
		beq	.rts_used

		move.w	oxNS_offset(a3),d1
		add.w	oxNS_inpos(a3),d1

		move.l	oxNS_string(a3),a0
		adda.w	d1,a0

		sub.w	d1,d0
		beq	.rts_used

		subq.w	#1,d0

.entf_lp	move.b	1(a0),(a0)+
		dbf	d0,.entf_lp
		subq.w	#1,oxNS_stringlenght(a3)

		bra	.refresh

.if_bsp		cmp.w	#8,im_Code(a1)
		bne.b	.char

		; backspace

		move.l	oxNS_string(a3),a0
		adda.w	oxNS_offset(a3),a0
		adda.w	oxNS_inpos(a3),a0
		subq.l	#1,a0
		cmp.l	oxNS_string(a3),a0
		blt	.rts_used
.bsp_lp		move.b	1(a0),(a0)+
		bne.b	.bsp_lp

		tst.w	oxNS_stringlenght(a3)
		beq	.rts_used
		subq.w	#1,oxNS_stringlenght(a3)
		tst.w	oxNS_inpos(a3)
		beq.b	.sub_off
		subq.w	#1,oxNS_inpos(a3)

		bra.b	.refresh

.sub_off	tst.w	oxNS_offset(A3)
		beq.b	.rts_used
		subq.w	#1,oxNS_offset(A3)

		bra.b	.refresh

.char		move.b	im_Code+1(a1),d0

		btst	#oxNSB_HEX,oxNS_flags(a3)
		beq.b	.if_dez

		cmp.b	#"0",d0
		blt.b	.rts_used
		cmp.b	#"f",d0
		bgt.b	.rts_used
		cmp.b	#"a",d0
		bge.b	.is_atof
		cmp.b	#"9",d0
		ble.b	.write_char
		cmp.b	#"A",d0
		blt.b	.rts_used
		cmp.b	#"F",d0
		bgt.b	.rts_used

.is_atof	bclr	#5,d0		; make big AtoF
		bra.b	.write_char

.if_dez		btst	#oxNSB_DEZ,oxNS_flags(a3)
		beq.b	.write_char

		cmp.b	#"0",d0
		blt.b	.rts_used
		cmp.b	#"9",d0
		bgt.b	.rts_used

.write_char	bsr	.edit_hook		; send char, return new char

		tst.b	d0			; if 0 do nothing
		beq	.rts_used

		move.l	oxNS_string(a3),a0
		move.l	a0,a1
		adda.w	oxNS_offset(a3),a1
		adda.w	oxNS_inpos(a3),a1
		subq.l	#1,a1

		move.w	oxNS_stringlenght(a3),d1
		cmp.w	oxNS_maxlenght(a3),d1
		bge	.rts_used

		adda.w	d1,a0  
		addq.w	#1,oxNS_stringlenght(a3)

.einf_lp	move.b	(a0),1(a0)
		subq.l	#1,a0
		cmp.l	a0,a1
		bne.b	.einf_lp

		move.b	d0,1(a1)
		addq.w	#1,oxNS_inpos(a3)

		bsr	.find_lp
		bra	.refresh

.right		cmp.w	#CURSORRIGHT,im_Code(a1)
		bne	.left

.right1		move.w	oxNS_offset(a3),d1
		add.w	oxNS_inpos(a3),d1
		cmp.w	oxNS_stringlenght(a3),d1
		bge	.rts_used

		add.w	#1,oxNS_inpos(a3)

.find_lp	move.w	oxNS_inpos(a3),d0
		addq.w	#1,d0

		move.l	oxNS_string(a3),a0
		adda.w	oxNS_offset(a3),a0

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		push	a6
		move.l	oxB_gfxbase(a6),a6
		jsr	_LVOTextLength(a6)
		pop	a6

		move.w	oxNS_width(a3),d1
		subq.w	#8,d1	; frames and spacings
	;	subq.w	#7,d1
		cmp.w	d1,d0
		ble.b	.refresh
		subq.w	#1,oxNS_inpos(a3)
		addq.w	#1,oxNS_offset(a3)
		bra	.find_lp

.refresh	bsr	NS_draw_string_rf
		bra	.rts_used

.left		cmp.w	#CURSORLEFT,im_Code(a1)
		bne	.rts_unused

.left1		sub.w	#1,oxNS_inpos(a3)
		bge.b	.refresh
		clr.w	oxNS_inpos(a3)
		subq.w	#1,oxNS_offset(a3)
		bge.b	.refresh
		clr.w	oxNS_offset(a3)
		bra	.rts_used

.rts_unused	moveq	#0,d0
		rts

.button		cmp.w	#SELECTDOWN,im_Code(a1)
		bne.b	.rts

		movem.w	oxNS_left(a3),d0-d3
		bsr	is_in_rect
		beq.b	.rts_unused

		move.l	oxNS_string(a3),a0
		adda.w	oxNS_offset(a3),a0
		move.w	oxNS_stringlenght(a3),d0
		sub.w	oxNS_offset(a3),d0

		move.l	im_IDCMPWindow(a1),a1
		move.w	wd_GZZMouseX(a1),d2

		sub.w	oxNS_left(a3),d2

		subq.w	#4,d2				; left frames and spacings
		move.w	oxNS_height(a3),d3		; just a dummy value at least as big as the font height

		moveq	#1,d1
		pushm	a3/a6

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		sub.l	a3,a3
		lea	-te_SIZEOF(a7),a7
		move.l	a7,a2
		move.l	oxB_gfxbase(a6),a6
		jsr	-696(a6)			; _LVOTextFit(a6)
		lea	te_SIZEOF(a7),a7

		move.w	d0,d7

		pop	a3

		addq.w	#1,d0

		move.l	oxNS_string(a3),a0
		adda.w	oxNS_offset(a3),a0

		move.l	oxNS_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		jsr	_LVOTextLength(a6)

		pop	a6

		move.w	oxNS_width(a3),d1
		subq.w	#8,d1	; frames and spacings
	;	subq.w	#4,d1
		cmp.w	d1,d0
		ble.b	.set_active
		subq.w	#1,d7

.set_active	bset	#oxNSB_ACTIVE,oxNS_flags(a3)
		bne.b	.set_ip

		bsr	ns_reset			; sets d7 to 0 if delfirst

		move.l	a3,d1
		move.l	oxNS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)

.set_ip		move.w	d7,oxNS_inpos(a3)

		bra	.refresh


.edit_hook	; call edit hook, returns char in d0

		move.l	oxNS_edithook(a3),d1
.hook		beq	.rts1

		move.l	d1,a2

		; hooks get: a0 and a3 *list, a4 *base, a1 and a5 *message, a6 *oxbase

		move.l	oxO_userbase(a3),a4

		; nullterminate string for use in hook

		move.l	oxNS_string(a3),a1
		adda.w	oxNS_stringlenght(a3),a1
		clr.b	(a1)

		lea	-oxNSSI_SIZEOF(a7),a7
		move.l	a7,a1
		move.l	a1,a5

		move.l	a3,oxNSSI_object(a5)
		move.l	oxNS_string(a3),oxNSSI_string(a5)
		move.w	oxNS_stringlenght(a3),oxNSSI_lenght(a5)
		move.l	oxNS_value(a3),oxNSSI_value(a5)
		move.b	d0,oxNSSI_char(a5)
		move.l	a3,a0

		pushm	d2-d7/a2-a6
		jsr	(a2)
		popm	d2-d7/a2-a6

		; terminate string by space for internal use

		move.l	oxNS_string(a3),a1
		adda.w	oxNS_stringlenght(a3),a1
		move.b	#" ",(a1)

		lea	oxNSSI_SIZEOF(a7),a7

.rts1		rts

.enter		bsr	calc_value		; from string and fix value before and remake string form fixed value

		move.l	oxNS_value(a3),d0
		move.l	oxNS_enterhook(a3),d1
		bsr	.hook

		; activate enter object

		move.l	oxNS_enterobject(a3),d0
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
		jsr	_LVOoxDoMethod(a6)
		bra	.rts_used

.self_inact	; self-deactivate and remove link from window

		move.l	oxNS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWM_clrpriv,d1
		jsr	_LVOoxDoMethod(a6)
		bra	NS_INACTIVE_1

NS_ACTIVATE	bset	#oxNSB_ACTIVE,oxNS_flags(a3)
		bne	.rts_unused

		bsr	ns_reset

		move.l	a3,d1
		move.l	oxNS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)

		bsr	NS_draw_string_rf		; this draws cursor if _ACTIVE bit is set

		moveq	#1,d0
.rts_unused	rts

ns_reset	bclr	#oxNSB_DELFIRST,oxNS_flags(a3)
		beq.b	.rts

		clr.w	oxNS_inpos(a3)
		moveq	#0,d7

		clr.w	oxNS_stringlenght(a3)
		move.l	oxNS_string(a3),a0
		move.b	#" ",(a0)

		clr.l	oxNS_value(a3)

.rts		rts

NS_INACTIVE	bsr	calc_string			; if we clicked with mouse on/into annother gad

NS_INACTIVE_1	bclr	#oxNSB_ACTIVE,oxNS_flags(a3)
		beq	.rts_unused

		clr.w	oxNS_offset(a3)
		clr.w	oxNS_inpos(a3)

		bsr	NS_draw_string_rf		; does not draw cursor because _AVTIVE bit is clear

		moveq	#1,d0
.rts_unused	rts


NS_LINKPRIV	btst	#oxNSB_ACTIVE,oxNS_flags(a3)
		beq	.rts

		move.l	a0,d1
		move.l	oxNS_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)
		moveq	#1,d0
.rts		rts

NS_RELINK 	btst	#oxNSB_OFF,oxNS_flags(a3)
		bne.b	.rts

	  	lea	oxNS_prev(a0),a2
		jmp	_LVOoxRingConnect(a6)

.rts		rts

; misc support routines

is_in_rect	movem.l	d1-d3/a2,-(a7)

		move.l	im_IDCMPWindow(a1),a2
		movem.w	wd_GZZMouseX(a2),d4/d5

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

		moveq	#1,d0
.restack	movem.l	(a7)+,d1-d3/a2
		rts
.not_in_rect	moveq	#0,d0
		bra.b	.restack


alloc_mem	tst.l	d0
		beq.b	.rts
		movem.l	d1-a6,-(a7)
		move.l	#$10001,d1	; MEMF_PUBLIC | MEMF_CLEAR
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		movem.l	(a7)+,d1-a6
		tst.l	d0
.rts		rts

;------------------------------
; dez hex val string

;d0	;value
;a0	;*deststring
;>a0	;*behindnewchars

val_to_dez
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

dez_to_val
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

val_to_hex
	push	d2
	tst.w	d1
	ble.b	.pop
	ADDA.w	D1,A0		; d0=value / d1=strlen / a0=dest
	SUBQ.w	#1,D1
;	clr.b	(a0)		; terminate str
.lp	MOVE.B	D0,D2
	LSR.L	#4,D0
	ANDI.W	#$000F,D2
	MOVE.B	.chars(pc,D2.W),-(A0)
	DBF	D1,.lp
.pop	pop	d2
	RTS
.chars	DC.B	'0123456789ABCDEF'
	even

hex_to_val
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

free_mem	movem.l	d0-a6,-(a7)
		move.l	a0,a1		; aber in a1 wird gebraucht
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)
		movem.l	(a7)+,d0-a6
		rts


auto_request	; a0	*text
		; a6	*oxbase

		pushm	d0/d1/a0/a1/a2/a3/a6

		move.l	oxB_intbase(a6),a6

		lea	.it_body(pc),a1
		move.l	a0,it_IText(a1)	; insert *text into body intuitext
		sub.l	a0,a0		; no parent window
		sub.l	a2,a2		; no positive text
		lea	.it_ok(pc),a3	; negative text
		moveq	#0,d0
		moveq	#0,d1

		jsr	_LVOAutoRequest(a6)

		popm	d0/d1/a0/a1/a2/a3/a6
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

; Zak McKracken for president

