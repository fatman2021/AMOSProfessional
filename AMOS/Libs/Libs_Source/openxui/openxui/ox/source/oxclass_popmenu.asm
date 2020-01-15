

       		IFND EXEC_FUNCDEF_I
        	include exec/funcdef.i
        	ENDC
 		IFND EXEC_TYPES_I
 		include exec/types.i
 		ENDC

		include	exec/exec_lib.i
		include	"dos/dos_lib.i"
		include	"exec/resident.i"
		include	"exec/initializers.i"
		include	"exec/libraries.i"
		include	"exec/lists.i"
	;	include	"lvo.i"
		include	"exec/types.i"
		include	"exec/memory.i"

		include ox.i
		include	ox_lib.i
		include oxclass_popmenu.i
		include oxclass_newlist.i


		include	easy.i

		IFND UITLITY_TAGITEM_I
		include	"utility/tagitem.i"
		ENDC
		IFND INTUITION_INTUITION_I
		include	"intuition/intuition.i"
		ENDC

		include	intuition/intuitionbase.i
		include	intuition/screens.i
		INCLUDE	intuition/gadgetclass.i
		include	intuition/classes.i
		include	graphics/text.i

 STRUCTURE	oxPopMenu,oxO_SIZEOF
	APTR	oxPM_window
	APTR	oxPM_list
	APTR	oxPM_title
	APTR	oxPM_hook
	STRUCT	oxPM_drag,gg_SIZEOF	; this is the menu window dragging gadget
	LABEL	oxPM_SIZEOF

TRUE		= 1
FALSE		= 0

OXCLASS_VERSION		= 1
OXCLASS_REVISION	= 0

	OXCLASSHEADER

OXCLASS_NAME	dc.b	"popmenu",0
OXCLASS_DESC	dc.b	"$VER: Popup Menu v"
		dc.b	$30+OXCLASS_VERSION,".",$30+OXCLASS_REVISION,0
OXCLASS_AUTHOR	dc.b	"Andreas G. Szabo",0
		even

OXCLASS_TAGS	dc.l	oxCA_objectsize,oxPM_SIZEOF
		dc.l	oxCA_dispatcher,.dispatcher
		dc.l	oxCA_description,OXCLASS_DESC
		dc.l	oxCA_author,OXCLASS_AUTHOR
		dc.l	oxCA_makeexample,.cr_example
	;	dc.l	oxCA_basesize,
	;	dc.l	oxCA_envarray,
		dc.l	TAG_END

.dispatcher	cmp.w	#OXM_SET,d1
		beq	PM_SET

		cmp.w	#OXM_GET,d1			; for buffer/userbase = *popmenu
		beq	PM_GET

		cmp.w	#OXM_SETDEF,d1
		beq	PM_SETDEF

		cmp.w	#OXM_INIT,d1
		beq	PM_INIT

		cmp.w	#OXM_DEINIT,d1
		beq	PM_DEINIT

		cmp.w	#oxPMM_popup,d1
		beq	PM_popup

		rts

	; kein close window bei freeobject (deinit) weil fesnter automatisch
	; geschlossen wird wenn freeobject da forbei kommt

;-----------------------
; example stuff

.cr_example	lea	.example(pc),a2
		moveq	#0,d2
		jsr	_LVOoxCreateObject(a6)
		push	d0
		beq.b	.return_pop

		move.l	d0,a0
		move.l	#oxA_buffer,d0
		jsr	_LVOoxGetAttr(a6)

		; buffer as userbase to a1

		move.l	d0,a1

		lea	OXCLASS_NAME(pc),a0
		move.l	a0,d2
		lea	.example_pm(pc),a2
		jsr	_LVOoxCreateObject(a6)

.return_pop	pop	d0
		rts

 STRUCTURE	btnbuffer,0
		APTR	btnbuff_menu
		LABEL	btnbuff_SIZEOF

.example	dc.l	OX_BUFFER,.buffer

.buffer		dc.l	oxBfA_buffersize,btnbuff_SIZEOF
		dc.l	OX_BUTTON,.launch_button
		dc.l	TAG_END

.launch_button	dc.l	oxBA_text,.text
		dc.l	oxBA_linechar,1
		dc.l	oxBA_hook,.popup_hook
		dc.l	OXA_FREEHOOK,free_menu
		dc.l	TAG_END
.text		dc.b	"pop up the menu",0
		even

.example_pm	dc.l	OX_RELPTR,btnbuff_menu
		dc.l	oxPMA_item,.item1
		dc.l	oxPMA_item,.item2
		dc.l	oxPMA_item,.item3
		dc.l	oxPMA_item,.item4
		dc.l	oxPMA_item,.item5
		dc.l	oxPMA_item,.item6
		dc.l	oxPMA_item,.item7
		dc.l	oxPMA_item,.item8
		dc.l	oxPMA_item,.item9
		dc.l	oxPMA_title,.title
		dc.l	TAG_END

.title		dc.b	"Auswahl",0
		even

.item1		dc.l	oxPMIA_text,.text1
		dc.l	TAG_END
.item2		dc.l	oxPMIA_text,.text2
		dc.l	TAG_END
.item3		dc.l	oxPMIA_text,.text3
		dc.l	TAG_END
.item4		dc.l	oxPMIA_text,.text4
		dc.l	TAG_END
.item5		dc.l	oxPMIA_text,.text5
		dc.l	TAG_END
.item6		dc.l	oxPMIA_text,.text6
		dc.l	oxPMIA_off,TRUE
		dc.l	TAG_END
.item7		dc.l	oxPMIA_text,.text7
		dc.l	TAG_END
.item8		dc.l	oxPMIA_text,.text8
		dc.l	TAG_END
.item9		dc.l	oxPMIA_text,.text9
		dc.l	TAG_END

.text1		dc.b	"Suppe",0
.text2		dc.b	"Nudeln",0
.text3		dc.b	"Sushi",0
.text4		dc.b	"Reis",0
.text5		dc.b	"Tee",0
.text6		dc.b	"Pudding",0
.text7		dc.b	"Kaffe",0
.text8		dc.b	"Sahne",0
.text9		dc.b	"Zucker",0
		even

.popup_hook	; (for example)

		move.l	btnbuff_menu(a4),a0		; get *filereq from base
		move.w	#oxPMM_popup,d1
		jmp	_LVOoxDoMethod(a6)

free_menu	move.l	btnbuff_menu(a4),a0
		jmp	_LVOoxFreeObject(a6)

;--------------------------
; class stuff

PM_SETDEF	move.l	a3,a1			; set oxPopMenu as userbase for window tree to
						; store *window and *list by Create()
		lea	menu_tree(pc),a2
		move.w	#OX_WINDOW,d2
		jsr	_LVOoxCreateObject(a6)	; result is set via OX_RELPTR into oxPM_window

		tst.l	d0
		beq	.rts

		move.l	oxPM_list(a3),a0
		move.w	#oxNLA_titleheight,d0
		jsr	_LVOoxGetAttr(a6)

		; make dragbar gadgegt from titleheight

		move.w	d0,oxPM_drag+gg_Height(a3)
		beq	.rts

		move.w	#GADGHNONE|GRELWIDTH,oxPM_drag+gg_Flags(a3)
		move.w	#WDRAGGING|SYSGADGET,oxPM_drag+gg_GadgetType(a3)

		move.w	#oxWA_gadgets,d0
		lea	oxPM_drag(a3),a0
		move.l	a0,d1
		move.l	oxPM_window(a3),a0
		jsr	_LVOoxSetAttr(a6)

.rts		rts

PM_GET		move.l	(a1),d1

		cmp.w	#oxA_buffer,d1
		bne.b	.rts
		move.l	a0,d0

.rts		rts

PM_SET		movem.l	(a1),d0/d1/a1

		cmp.w	#oxPMA_title,d0
		bne	.hook
		move.l	oxPM_list(a3),a0
		move.w	#oxNLA_title1,d0
		jmp	_LVOoxSetAttr(a6)

.hook		cmp.w	#oxPMA_hook,d0
		bne	.item
		move.l	d1,oxPM_hook(a3)
		rts
.item		cmp.w	#oxPMA_item,d0
		beq	PM_new_item

		rts


 STRUCTURE	oxNewItemTemp,0
	APTR	oxNIT_text
	UBYTE	oxNIT_flags		; see below
	UBYTE	oxNIT_pad
	UWORD	oxNIT_id
	LABEL	oxNIT_SIZEOF

	BITDEF	oxPMI,OFF,0


PM_new_item	move.l	d1,a2

		lea	-oxNIT_SIZEOF(a7),a7
		move.l	a7,a1

		clr.l	(a1)
		clr.l	4(a1)

.tag_loop	bsr	get_a_tag	; to d0/d1
		beq.b	.init

		cmp.w	#oxPMIA_text,d0
		bne.b	.id
		move.l	d1,oxNIT_text(a1)
		bra.b	.tag_loop

.id		cmp.w	#oxPMIA_id,d0
		bne.b	.off
		move.w	d1,oxNIT_id(a1)
		bra.b	.tag_loop

.off		cmp.w	#oxPMIA_off,d0
		bne.b	.tag_loop
		moveq	#oxPMIF_OFF,d0

.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxNIT_flags(a1)
		bra.b	.tag_loop
.clearflag	not.w	d0
		and.b	d0,oxNIT_flags(a1)
		bra.b	.tag_loop

.init
		; create list item from oxNewItemTemp

		move.l	a7,a5	; store stackpointer weil wir wissen nicht wie lang die tagliste wird

		clr.l	-(a7)	; TAG_END

		move.l	oxNIT_text(a1),-(a7)
		move.l	#oxNLIA_text1,-(a7)
		move.w	oxNIT_id(a1),d0
		move.l	d0,-(a7)
		move.l	#oxNLIA_id,-(a7)
		moveq	#FALSE,d0
		btst	#oxPMIB_OFF,oxNIT_flags(a1)
		beq.b	.i2
		moveq 	#TRUE,d0
.i2		move.l	d0,-(a7)
		move.l	#oxNLIA_off,-(a7)

		move.l	a7,d1

		move.l	oxPM_list(a3),a0
		move.w	#oxNLA_item,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	a5,a7

		lea	oxNIT_SIZEOF(a7),a7

		rts


	OXCLASSNAME	newlist

menu_tree	;(window)
		dc.l	oxWA_undermouse,-1
		dc.l	oxWA_layout,-1
		dc.l	newlist,.list
		dc.l	OX_RELPTR,oxPM_window
		dc.l	oxWA_borderless,TRUE
		dc.l	oxWA_intuimessagehook,idcmp_hook
		dc.l	TAG_END

.list		dc.l	oxNLA_menulook,TRUE
		dc.l	oxNLA_slider,FALSE
		dc.l	oxNLA_separators,FALSE
		dc.l	oxNLA_proph,TRUE
		dc.l	oxNLA_propw,TRUE
		dc.l	oxNLA_titles,TRUE
		dc.l	oxNLA_boldtitles,TRUE
		dc.l	oxNLA_title1,.title1
		dc.l	oxNLA_maxed,TRUE
	;	dc.l	oxNLA_active,TRUE
		dc.l	OX_RELPTR,oxPM_list
		dc.l	oxNLA_selhook,select_hook
		dc.l	TAG_END

.title1		dc.b	"select",0
		even

PM_INIT		move.l	oxPM_list(a3),a0
		move.l	#oxNLM_activate,d1
		jsr	_LVOoxDoMethod(a6)

		moveq	#1,d0
		rts


PM_DEINIT	rts


PM_popup	move.l	oxPM_window(a3),a0
		move.l	#oxWM_OPEN,d1
		jmp	_LVOoxDoMethod(a6)

select_hook	; a1 selinfo, a4 base

		; lass den user den select-balken ein bischen sehen 
		pushm	a1/a6
		move.l	oxB_dosbase(a6),a6
		move.l	#13,d1
		jsr	_LVODelay(a6)
		popm	a1/a6

		; item deselektieren

		move.l	oxPM_list(a4),a0
		move.l	oxNLSI_item(a1),a1
		move.w	#oxNLM_deselectitem,d1
		jsr	_LVOoxDoMethod(a6)

		; aus der list! userbase für *oxPopupMenu benutzen!
		move.l	oxPM_window(a4),a0
		move.l	#oxWM_CLOSE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	oxPM_hook(a4),d0
		beq	.rts
		move.l	d0,a2
		jmp	(a2)
.rts		rts

idcmp_hook	cmp.l	#IDCMP_INACTIVEWINDOW,im_Class(a1)
		bne.b	.rts

		; close alles submenus

		; close main menu
		; aus der list! userbase für *oxPopupMenu benutzen!
		move.l	oxPM_window(a4),a0
		move.l	#oxWM_CLOSE,d1
		jsr	_LVOoxDoMethod(a6)
		moveq	#1,d0			; no need to send forth to all because only one window
						; could have been active
.rts		rts

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

; Zak McKracken for president!

