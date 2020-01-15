
        	include exec/funcdef.i
 		include exec/types.i

		include	"exec/lists.i"
		include	"exec/nodes.i"

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
; OX_NEWLIST

; bugs
; - (?) list gets intuimessage twice if it is active and returns "unused" (?)
;   this might be rather a concept problem: if ichbindran returns unused,
;   the message is sent on the normal path
; - minwidth ist um die sliderbreite groeßer als minwdith!

; concept ideen
; - oxNLA_autowidth um die spaltenbreite an den längsten itemtext anzupassen
; - oxNLA_minwidth1 bis 8, oxNLA_widthfixed1 bis 8
; - oxNLA_centertitles

		include	oxclass_newlist.i

TRUE		= 1
FALSE		= 0

 STRUCTURE	oxNewList,oxO_SIZEOF
	UWORD	oxNL_minwidth		; incl slider and all borders
	UWORD	oxNL_minheight		;	...
	UWORD	oxNL_left
	UWORD	oxNL_top
	UWORD	oxNL_width
	UWORD	oxNL_height
	UWORD	oxNL_propw
	UWORD	oxNL_proph

	STRUCT	oxNL_titles,4*8
	STRUCT	oxNL_titlelenghts,2*8

	UWORD	oxNL_sliderwidth
	UWORD	oxNL_separatorwidth

	UWORD	oxNL_sepyoffset		; start drawing separator line at top + this
	UWORD	oxNL_sepystart		; = this
	UWORD	oxNL_sepyend
	UWORD	oxNL_vertbortop		; add this to top to get contenttop
	UWORD	oxNL_vertborders	; substract this from height to get contentheight
	UWORD	oxNL_txheight		; stored here from screen rastport from SET drawinfo
	UWORD	oxNL_titleheight
	UWORD	oxNL_lineheight
	UWORD	oxNL_arrowpos		; y-center arrow in line
	UWORD	oxNL_feed		; pixel einzug pro folder level

	UWORD	oxNL_contentleft	; border and spacing added
	UWORD	oxNL_contenttop		; border, title and spacing added
	UWORD	oxNL_contentwidth	; for dividing per column
	UWORD	oxNL_contentheight	; for clipping

	UWORD	oxNL_minlines
	UWORD	oxNL_spacing
	UWORD	oxNL_columns		; initially 1

	APTR	oxNL_drawinfo

	APTR	oxNL_oldregion
	STRUCT	oxNL_Region,rg_SIZEOF
	STRUCT	oxNL_RegionRectangle,rr_SIZEOF

	APTR	oxNL_prev
	APTR	oxNL_next

	APTR	oxNL_receiver		; points to sliderobject by default
	APTR	oxNL_sliderobject
	APTR	oxNL_selfptr		; for connection from slider to here

	STRUCT	oxNL_list,MLH_SIZE	; chain of all visible nodes (calculated after each change)
	STRUCT	oxNL_backbone,MLH_SIZE	; chain of ALL nodes

	UBYTE	oxNL_flags
	UBYTE	oxNL_flags2
	UBYTE	oxNL_senschar
	UBYTE	oxNL_iflags
	UBYTE	oxNL_altpen
	UBYTE	oxNL_aligns		; each bit means colun # is right aligned

	APTR	oxNL_topitem
	APTR	oxNL_activeitem		; draw the dotted frame here
	APTR	oxNL_selecteditem
	UWORD	oxNL_lines		; visible lines, calced in setlayout
	UWORD	oxNL_bodylines		; max fit lines w/ 1 half visible
	UWORD	oxNL_items		; number of items in list
;	UWORD	oxNL_numsel		; number of selected items
	UWORD	oxNL_offset		; visible entry nr from top down
	UWORD	oxNL_inpos		; this is the selected line
	UWORD	oxNL_activeinpos	; this is the cursor line

	UWORD	oxNL_softpos
	;UWORD	oxNL_pixoffset
	UWORD	oxNL_oldpixoffset

	UWORD	oxNL_vdist		; paint items distance for soft in-line scrolling
	UWORD	oxNL_scrollpix

	ULONG	oxNL_userdata

	ULONG	oxNL_seconds		; check for doubleclick
	ULONG	oxNL_micros		; ..

	APTR	oxNL_dchook		; called on doubleclick
	APTR	oxNL_selhook		; called on select (when mouse button released)

					; hooks get: a0 and a3 *list, a4 *base, a5 *class, a6 *oxbase
					; (a1) *list, userdata.l, *item, item_userdata.l, itemnumber.w
	UWORD	oxNL_propsum
	STRUCT	oxNL_props,2*8	; initially 100/columns
	STRUCT	oxNL_widths,2*8		; calculated from percents in SETLAYOUT

	STRUCT	oxNL_arrow_right,bd_SIZEOF
	STRUCT	oxNL_arrow_down,bd_SIZEOF

	LABEL	oxNL_SIZEOF

	BITDEF	oxNL,MENULOOK,0		; e.g. for use in string-gadget with history function
	BITDEF	oxNL,TITLES,1		; draw column titles
	BITDEF	oxNL,MULTISELECT,2	; permanent multiselect
	BITDEF	oxNL,SEPARATORS,3
	BITDEF	oxNL,SLIDER,4
	BITDEF	oxNL,BOLDTITLES,5
	BITDEF	oxNL,MAXED,6
	BITDEF	oxNL,SHIFTMULTI,7	; allow multiselect when a shift key is hold down

	; flags 2	(use alternate set/clear func!)

	BITDEF	oxNL,ARROWCLICK,0

	; internal flags

	BITDEF	oxNLi,ACTIVE,0
	BITDEF	oxNLi,REFRESHALL,1
	BITDEF	oxNLi,MULTISELECTED,2
	BITDEF	oxNLi,FOLDERS,3

oxNL_DEFAULTSLIDERWIDTH	= $10

 STRUCTURE	oxNewListItem,0
	STRUCT	oxNLI_visible,LN_SIZE	; in list of the visible nodes
	STRUCT	oxNLI_bone,LN_SIZE	; in list of ALL nodes,
					; with pri and name (first column text) for sorting!
	STRUCT	oxNLI_strings,4*8	; max 8 columns
	STRUCT	oxNLI_lenghts,2*8
	STRUCT	oxNLI_offsets,2*8	; pixel dist of text if align is RIGHT
	ULONG	oxNLI_userdata
	UWORD	oxNLI_id
	APTR	oxNLI_folder		; folder where this item is a member of
	UWORD	oxNLI_numfold		; if # > 0 this is a foldern and the next # intems are in this folder
	UWORD	oxNLI_indent		; pixel dist of content between left edge of list and first text letter
	LABEL	oxNLI_SIZEOF

oxNLI_flags	=	LN_TYPE
oxNLI_name	=	LN_NAME		; for sorting. later add sort by column
oxNLI_pri	=	LN_PRI		; for "dirs first" or such

	BITDEF	oxNLI,SELECTED,0
	BITDEF	oxNLI,OFF,1		; cannot select this, written ghosted, no click report
	BITDEF	oxNLI,ALTCOLOR,2
	BITDEF	oxNLI,SEPARATOR,3	; this entry is just a separator

	BITDEF	oxNLI,OPEN,5		; this folder is open
	BITDEF	oxNLI,ARROW,6		; allways draw the arrow, even if folder has no elements

	BITDEF	oxNLI,ACTIVE,7		; cursor here, can be toggled un/selcted with space

; rem item:	sub one from its folders oxNLI_numfold, sub one from parent numfolds (*****)
;		remove item and all following numfold items from visible list (clear link) and backbone list

; add item	if no oxNLIA_folder is specified, add item at bottom of visible list and at bottom of backbone list,
;		set numfold to 0 and indent to 0 and OPEN to 0

;		if oxNLIA_folder is specified	- step numfold items forward from folder in backbone list
;						  and add there to backbone list, remember the node where added as folder_tail
;						- add 1 to _folders' numfold and to all parent numfolds (*****)
;						- if _folder is OPEN and its visible list node SUCC is != 0
;						  step forward numfold elements in the visible list,
;						  if a closed folder is encountered sub its numfold from the
;						  loop counter and if that is 0 add item at pos
;						- get indent from _folder, add one oxNL_feed and store in oxNLI_indent



OXCLASS_VERSION		= 1
OXCLASS_REVISION	= 0

	OXCLASSHEADER

OXCLASS_NAME	dc.b	"newlist",0
OXCLASS_DESC	dc.b	"$VER: list browser v",$30+OXCLASS_VERSION,".",$30+OXCLASS_REVISION,0
OXCLASS_AUTHOR	dc.b	"Andreas G. Szabo",0
		even

OXCLASS_TAGS	dc.l	oxCA_objectsize,oxNL_SIZEOF
		dc.l	oxCA_dispatcher,.dispatcher
		dc.l	oxCA_description,OXCLASS_DESC
		dc.l	oxCA_author,OXCLASS_AUTHOR
		dc.l	oxCA_makeexample,.cr_example
	;	dc.l	oxCA_basesize,
	;	dc.l	oxCA_envarray,
		dc.l	TAG_END


.dispatcher	cmp.w	#OXM_SET,d1
		beq	NL_SET

		cmp.w	#OXM_DRAW,d1
		beq	NL_DRAW

		cmp.w	#OXM_UPDATE,d1
		beq	NL_UPDATE

		cmp.w	#OXM_INTUIMESSAGE,d1
		beq	NL_INTUI

		cmp.w	#OXM_GETLAYOUT,d1
		beq	NL_GETLAYOUT

		cmp.w	#OXM_SETLAYOUT,d1
		beq	NL_SETLAYOUT

		cmp.w	#OXM_ACTIVATE,d1
		beq	NL_ACTIVATE

		cmp.w	#OXM_INACTIVE,d1
		beq	NL_INACTIVE

		cmp.w	#OXM_DEINIT,d1
		beq	NL_DEINIT

		cmp.w	#OXM_INIT,d1
		beq	NL_INIT

		cmp.w	#OXM_SETDEF,d1
		beq	NL_SETDEF

		cmp.l	#oxNLM_getitemtexts,d1
		beq	NL_getitexts

		cmp.w	#oxNLM_getnextitem,d1
		beq	NL_getnextitem

		cmp.w	#oxNLM_getitemuserdata,d1
		beq	NL_getitemuserdata

	;	cmp.w	#oxNLM_deleteitem,d1
	;	beq	NL_delitem

	; must remove from active item ptr before deleting item !

		cmp.w	#oxNLM_deselectitem,d1
		beq	NL_deselitem

		cmp.w	#oxNLM_activate,d1
		beq	NL_activate

		cmp.w	#oxNLM_sort,d1
		beq	NL_sort

		cmp.w	#OXM_RELINK,d1
		beq	NL_RELINK

		cmp.w	#OXM_LINKPRIV,d1
		beq	NL_LINKPRIV

		cmp.w	#oxNLM_setitemtext,d1
		beq	NL_setitemtext

		cmp.w	#OXM_GET,d1
		beq	NL_GET

		cmp.w	#OXM_NEWPENS,d1
		beq	NL_NEWPENS

		cmp.w	#oxNLM_unfold,d1
		beq	NL_openfolder

		cmp.w	#oxNLM_fold,d1
		beq	NL_closefolder

		rts

.cr_example	lea	.example(pc),a2
		moveq	#0,d2
		jmp	_LVOoxCreateObject(a6)

.example	dc.l	OX_BUFFER,.buffer

 STRUCTURE	newlistexample,0
	APTR	nlx_pages
	LABEL	nlx_SIZEOF

.buffer		dc.l	oxBfA_buffersize,nlx_SIZEOF
		dc.l	OX_VERTGROUP,.vg_tags
		dc.l	TAG_END

.vg_tags	dc.l	OX_HORIZGROUP,.hz_tags
		dc.l	OX_PAGES,.pages
		dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_minspace,2
		dc.l	TAG_END

.pages		dc.l	oxPgA_newmember,.page1
		dc.l	oxPgA_newmember,.page2
		dc.l	oxPgA_redraw,TRUE
		dc.l	OX_RELPTR,nlx_pages
		dc.l	TAG_END

.page1		dc.l	OXCLASS_NAME,.newlist_tags
.page2		dc.l	OXCLASS_NAME,.menulist_tags

.hz_tags	dc.l	OX_RADIO,.rad1
		dc.l	OX_LABEL,.lab1
		dc.l	OX_SPACE,.spc
		dc.l	oxGA_spaceprop,0
		dc.l	oxGA_minspace,5
		dc.l	OX_RADIO,.rad2
		dc.l	OX_LABEL,.lab2
		dc.l	TAG_END

.spc		dc.l	oxA_minwidth,20
		dc.l	oxA_propw,0
		dc.l	TAG_END

.rad1		dc.l	oxRadA_groupid,"OX"
		dc.l	oxA_selected,TRUE
		dc.l	oxRadA_senschar,"n"
		dc.l	oxRadA_hook,.hook1
		dc.l	TAG_END
.lab1		dc.l	oxLabA_text,.tx1
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END

.rad2		dc.l	oxRadA_groupid,"OX"
		dc.l	oxRadA_senschar,"m"
		dc.l	oxRadA_hook,.hook2
		dc.l	TAG_END
.lab2		dc.l	oxLabA_text,.tx2
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END

.hook1		moveq	#1,d1
.hk0		move.l	nlx_pages(a4),a0

		move.l	#oxPgA_number,d0
		jmp	_LVOoxSetAttr(a6)
	;	moveq	#OXM_DRAW,d1
	;	bra	_oxDoMethod

.hook2		moveq	#2,d1
		bra.b	.hk0

.tx1		dc.b	"newlook",0
.tx2		dc.b	"menulook",0
		even

.newlist_tags	dc.l	oxNLA_menulook,FALSE
		dc.l	oxNLA_separators,TRUE

.l_common_tags	dc.l	oxNLA_proph,1
		dc.l	oxNLA_propw,1
		dc.l	oxNLA_columns,3
		dc.l	oxNLA_prop1,5
		dc.l	oxNLA_prop2,4
		dc.l	oxNLA_prop3,4
		dc.l	oxNLA_align,RIGHT2|RIGHT3
		dc.l	oxNLA_titles,TRUE
		dc.l	oxNLA_boldtitles,TRUE
		dc.l	oxNLA_multiselect,TRUE
		dc.l	oxNLA_title1,.title1
		dc.l	oxNLA_title2,.title2
		dc.l	oxNLA_title3,.title3
		dc.l	oxNLA_item,.item1
		dc.l	oxNLA_item,.item2
		dc.l	oxNLA_item,.item3
		dc.l	TAG_END

.menulist_tags	dc.l	oxNLA_menulook,TRUE
		dc.l	oxNLA_slider,FALSE
		dc.l	oxNLA_separators,FALSE
		dc.l	TAG_MORE,.l_common_tags

.title1		dc.b	"Speise",0
.title2		dc.b	"Abholpreis",0
.title3		dc.b	"Lieferpreis",0
		even

.item1		dc.l	oxNLIA_text1,.text11
		dc.l	oxNLIA_text2,.text12
		dc.l	oxNLIA_text3,.text13
		dc.l	TAG_END
.item2		dc.l	oxNLIA_text1,.text21
		dc.l	oxNLIA_text2,.text22
		dc.l	oxNLIA_text3,.text23
		dc.l	TAG_END
.item3		dc.l	oxNLIA_text1,.text31
		dc.l	oxNLIA_text2,.text32
		dc.l	oxNLIA_text3,.text33
		dc.l	TAG_END

.text11		dc.b	"Suppe",0
.text12		dc.b	"3,00",0
.text13		dc.b	"4,00",0
.text21		dc.b	"Nudeln",0
.text22		dc.b	"5,70",0
.text23		dc.b	"6,80",0
.text31		dc.b	"Sushi",0
.text32		dc.b	"10,90",0
.text33		dc.b	"12,50",0
		even

NL_SETDEF	move.b	#oxNLF_SEPARATORS|oxNLF_SLIDER,oxNL_flags(a0)
		move.l	#$00400040,oxNL_minwidth(a0)
		move.w	#oxNL_DEFAULTSLIDERWIDTH,oxNL_sliderwidth(a0)
		move.w	#1,oxNL_separatorwidth(a0)
		move.w	#2,oxNL_spacing(a0)
		move.w	#5,oxNL_minlines(a0)
		move.w	#1,oxNL_columns(a0)

		; init pointers

		move.l	a0,oxNL_selfptr(a0)			; slider points here
		lea	oxNL_list(a0),a0
		NEWLIST	a0

		lea	oxNL_backbone(a3),a0
		NEWLIST	a0

		; init proportional column widths to equal

		lea	oxNL_props(a3),a1
		moveq	#7,d0
.lp		move.w	#1,(a1)+
		dbf	d0,.lp

		; set default line indent per tree sublevel

		move.w	#12,oxNL_feed(a3)

		; init arrows border structures

		lea	arrow_down(pc),a0
		lea	oxNL_arrow_down(a3),a1
		move.l	(a0)+,(a1)+
		move.l	(a0)+,(a1)+
		move.l	(a0)+,(a1)

		lea	arrow_right(pc),a0
		lea	oxNL_arrow_right(a3),a1
		move.l	(a0)+,(a1)+
		move.l	(a0)+,(a1)+
		move.l	(a0)+,(a1)

		rts

NL_NEWPENS	; use black pen to draw this arrows

		move.b	oxPT_blackpen(a1),oxNL_arrow_down+bd_FrontPen(a3)
		move.b	oxPT_blackpen(a1),oxNL_arrow_right+bd_FrontPen(a3)
		rts

; arrow border datas

arrow_down	; black
		dc.w	0,0			; left, top
		dc.b	1,0,0,4			; front-pen, back-pen, drawmode, xy-count
		dc.l	.coords
		dc.l	0

.coords		dc.w	1,4
		dc.w	6,9
		dc.w	11,4
		dc.w	1,4

arrow_right	; black
		dc.w	0,0			; left, top
		dc.b	1,0,0,4			; front-pen, back-pen, drawmode, xy-count
		dc.l	.coords
		dc.l	0

.coords		dc.w	4,1
		dc.w	4,11
		dc.w	9,6
		dc.w	4,1


NL_GET		move.l	(a1),d1
		cmp.w	#oxNLA_titleheight,d1
		bne	.rts

		btst	#oxNLB_TITLES,oxNL_flags(a0)	; no height if no title
		beq	.rts

		move.w	oxNL_txheight(a3),d0

		addq.w	#2,d0				; top borders
		addq.w	#3,d0				; spacing im title, oben 2 und unten 1

		subq.w	#1,d0				; black border

		btst	#oxNLB_MENULOOK,oxNL_flags(a0)
		bne.b	.newlook

		add.w	#3,d0				; old look title top and bottom border
		bra.b	.rts

.newlook	addq.w	#2,d0				; new look title bottom border

.rts		rts


NL_SET		movem.l	(a1),d0/d1/a1

		cmp.w	#oxA_prev,d0
		bne.b	.next
		move.l	d1,oxNL_prev(a0)
		rts

.next		cmp.w	#oxA_next,d0
		bne	.itemtext2
		move.l	d1,oxNL_next(a0)
		rts

.itemtext2	cmp.w	#oxNLA_itemtext2,d0
		bne.b	.softpos
		moveq	#1,d2

		bra	nl_sit

.softpos	cmp.w	#oxNLA_softpos,d0
		bne.b	.minwidth
		move.w	d1,oxNL_softpos(a0)
.rts1		rts

.minwidth	cmp.w	#oxNLA_minwidth,d0
		bne.b	.minheight
		move.w	d1,oxNL_minwidth(a0)
		rts

.minheight	cmp.w	#oxNLA_minheight,d0
		bne.b	.propw
		move.w	d1,oxNL_minheight(a0)
		rts

.propw		cmp.w	#oxNLA_propw,d0
		bne.b	.proph
		move.w	d1,oxNL_propw(a0)
		rts

.proph		cmp.w	#oxNLA_proph,d0
		bne.b	.minlines
		move.w	d1,oxNL_proph(a0)
		rts

.minlines	cmp.w	#oxNLA_minlines,d0
		bne.b	.columns
		move.w	d1,oxNL_minlines(a0)
		rts

.columns	cmp.w	#oxNLA_columns,d0
		bne.b	.senschar
		move.w	d1,oxNL_columns(a0)
		rts

.senschar	cmp.w	#oxNLA_senschar,d0
		bne.b	.dchook
		move.b	d1,oxNL_senschar(a0)
		rts

.dchook		cmp.w	#oxNLA_dchook,d0
		bne.b	.selhook
		move.l	d1,oxNL_dchook(a0)
		rts

.selhook	cmp.w	#oxNLA_selhook,d0
		bne.b	.newlook
		move.l	d1,oxNL_selhook(a0)
		rts

.newlook	cmp.w	#oxNLA_menulook,d0
		bne.b	.aligns
		moveq	#oxNLF_MENULOOK,d0
.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxNL_flags(a0)
		rts
.clearflag	not.w	d0
		and.b	d0,oxNL_flags(a0)
		rts

.aligns		cmp.w	#oxNLA_align,d0
		bne.b	.titles
		move.b	d1,oxNL_aligns(a0)
		rts

.titles		cmp.w	#oxNLA_titles,d0
		bne.b	.multiselect
		moveq	#oxNLF_TITLES,d0
		bra.b	.flag

.multiselect	cmp.w	#oxNLA_multiselect,d0
		bne.b	.shiftmulti
		moveq	#oxNLF_MULTISELECT,d0
		bra.b	.flag

.shiftmulti	cmp.w	#oxNLA_shiftmulti,d0
		bne.b	.separators
		move.b	#oxNLF_SHIFTMULTI,d0
		bra.b	.flag

.separators	cmp.w	#oxNLA_separators,d0
		bne.b	.slider
		moveq	#oxNLF_SEPARATORS,d0
		bsr.b	.flag
		tst.w	d1
		beq.b	.clr_spw
		move.w	#1,oxNL_separatorwidth(a0)
		rts

.clr_spw	clr.w	oxNL_separatorwidth(a0)
		rts

.slider		cmp.w	#oxNLA_slider,d0
		bne.b	.boldtitles
		moveq	#oxNLF_SLIDER,d0
		bsr.b	.flag
		tst.w	d1
		beq.b	.clr_sw
		move.w	#oxNL_DEFAULTSLIDERWIDTH,oxNL_sliderwidth(a0)
		rts

.clr_sw		clr.w	oxNL_sliderwidth(a0)
		rts

.boldtitles	cmp.w	#oxNLA_boldtitles,d0
		bne.b	.maxed
		moveq	#oxNLF_BOLDTITLES,d0
		bra.b	.flag

.maxed		cmp.w	#oxNLA_maxed,d0
		bne.b	.perc1
		moveq	#oxNLF_MAXED,d0
		bra.b	.flag

.perc1		cmp.w	#oxNLA_prop1,d0
		bne.b	.perc2
		move.w	d1,oxNL_props(a0)
		rts

.perc2		cmp.w	#oxNLA_prop2,d0
		bne.b	.perc3
		move.w	d1,oxNL_props+2(a0)
		rts

.perc3		cmp.w	#oxNLA_prop3,d0
		bne.b	.perc4
		move.w	d1,oxNL_props+2*2(a0)
		rts

.perc4		cmp.w	#oxNLA_prop4,d0
		bne.b	.perc5
		move.w	d1,oxNL_props+3*2(a0)
		rts

.perc5		cmp.w	#oxNLA_prop5,d0
		bne.b	.perc6
		move.w	d1,oxNL_props+4*2(a0)
		rts

.perc6		cmp.w	#oxNLA_prop6,d0
		bne.b	.perc7
		move.w	d1,oxNL_props+5*2(a0)
		rts

.perc7		cmp.w	#oxNLA_prop7,d0
		bne.b	.perc8
		move.w	d1,oxNL_props+6*2(a0)
		rts

.perc8		cmp.w	#oxNLA_prop8,d0
		bne.b	.titletexts
		move.w	d1,oxNL_props+7*2(a0)
		rts

.titletexts	cmp.w	#oxNLA_title1,d0
		blt.b	.dri
		cmp.w	#oxNLA_title8,d0
		bgt.b	.dri

		sub.w	#oxNLA_title1,d0

		; calc title lenght

		move.l	d1,a0

		moveq	#-1,d2
.l_lp		tst.b	(a0)+
		dbeq	d2,.l_lp
		not.w	d2

		move.w	d2,oxNL_titlelenghts(a3,d0.w)

		add.w	d0,d0
		move.l	d1,oxNL_titles(a3,d0.w)

		rts

.dri		cmp.l	#oxA_drawinfo,d0
		bne.b	.item
		move.l	d1,oxNL_drawinfo(a0)
		move.l	d1,a1
		move.l	oxDI_rastport(a1),a1
		move.w	rp_TxHeight(a1),oxNL_txheight(a3)

		rts

.item		cmp.w	#oxNLA_item,d0
		beq.b	NL_new_item

.rts		rts

NL_new_item	move.l	d1,a2

		moveq	#0,d2	; default append mode is at tail
		moveq	#0,d4	; default is not in a folder (add at top level)

		moveq	#oxNLI_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts
		move.l	d0,a4

.tag_loop	bsr	get_a_tag	; to d0/d1
		beq.b	.init

		cmp.w	#oxNLIA_id,d0
		bne.b	.userd
		move.w	d1,oxNLI_id(a4)
		bra.b	.tag_loop

.userd		cmp.w	#oxNLIA_userdata,d0
		blt.b	.texts
		bne.b	.prev
		move.l	d1,oxNLI_userdata(a4)
		bra.b	.tag_loop

.prev		; append mode

		cmp.w	#oxNLIA_previtem,d0
		bne.b	.folder
		move.l	d1,d2		; store append mode
		bra.b	.tag_loop

.folder		; insert into folder mode

		cmp.w	#oxNLIA_folder,d0
		bne.b	.separator
		move.l	d1,d4		; store folder
		bset	#oxNLiB_FOLDERS,oxNL_iflags(a3)
		bra.b	.tag_loop

.separator	cmp.w	#oxNLIA_separator,d0
		bne.b	.selected
		moveq	#oxNLIF_SEPARATOR,d0
		bra.b	.flag

.selected	cmp.w	#oxNLIA_selected,d0
		bne.b	.altcolor
		moveq	#oxNLIF_SELECTED,d0
		tst.w	d1
		beq.b	.flag
		move.l	a4,oxNL_selecteditem(a0)		; muss sichtbar sein?
	;	add.w	#1,oxNL_numsel(a0)
		bra.b	.flag

.altcolor	cmp.w	#oxNLIA_altcolor,d0
		bne.b	.off
		moveq	#oxNLIF_ALTCOLOR,d0
		bra.b	.flag

.off		cmp.w	#oxNLIA_off,d0
		bne.b	.pri
		moveq	#oxNLIF_OFF,d0
		bra.b	.flag

.pri		cmp.w	#oxNLIA_pri,d0
		bne.b	.tag_loop
		move.b	d1,oxNLI_pri(a4)
		bra.b	.tag_loop

.flag		tst.w	d1
		beq	.clearflag
		or.b	d0,oxNLI_flags(a4)
		bra.b	.tag_loop
.clearflag	not.w	d0
		and.b	d0,oxNLI_flags(a4)
		bra.b	.tag_loop

.texts		sub.w	#OX_ATTRIBS_CLASS,d0		; is step 2

		; calc string lenght

		moveq	#-1,d3
		move.l	d1,a1
.l_lp		tst.b	(a1)+
		dbeq	d3,.l_lp
		not.w	d3
		move.w	d3,oxNLI_lenghts(a4,d0.w)

		; write *string into NewListItem

		lsl.w	#1,d0				; x2 = step 4
		move.l	d1,oxNLI_strings(a4,d0.w)

		; if it is the leftmost string, write * into LN_NAME for sorting

		tst.w	d0
		bne.b	.tag_loop
		move.l	d1,oxNLI_name(a4)
		bra.b	.tag_loop

.init		; the first item is never in a folder and if this is the first item make it the top one

		tst.l	oxNL_topitem(a3)
		bne.b	.add

		move.l	a4,oxNL_topitem(a3)

.add		move.l	d4,oxNLI_folder(a4)
		bne	.add_to_folder

		addq.w	#1,oxNL_items(a3)

		lea	oxNL_list(a3),a0
		move.l	a4,a1
		ADDTAIL

		lea	oxNL_backbone(a3),a0
		lea	oxNLI_bone(a4),a1
		ADDTAIL

		bra	.return_ptr

; add item	if no oxNLIA_folder is specified, add item at bottom of visible list and at bottom of backbone list,
;		set numfold to 0 and indent to 0 and OPEN to 0

;		if oxNLIA_folder is specified	- step numfold items forward from folder in backbone list
;						  and add there to backbone list, remember the node where added as folder_tail
;						- add 1 to _folders' numfold and to all parent numfolds (*****)
;						- if _folder is OPEN and its visible list node SUCC is != 0
;						  step forward numfold elements in the visible list,
;						  if a closed folder is encountered sub its numfold from the
;						  loop counter and if that is 0 add item at pos
;						- get indent from _folder, add one oxNL_feed and store in oxNLI_indent

.add_to_folder	; folder in d4

		move.l	d4,a0

		lea	oxNLI_bone(a0),a0
		move.w	oxNLI_numfold-oxNLI_bone(a0),d0
		beq	.insert

		subq.w	#1,d0
.find_tail	move.l	(a0),a0
		dbf	d0,.find_tail

.insert		; insert node a4 after node a0

		lea	oxNLI_bone(a4),a1

		move.l	MLN_SUCC(a0),a2
		move.l	a2,MLN_SUCC(a1)
		move.l	a1,MLN_SUCC(a0)
		move.l	a1,MLN_PRED(a2)
		move.l	a0,MLN_PRED(a1)

		; shift item more to the right in pixels, starting from folders pixpos

		move.l	d4,a0

		move.w	oxNLI_indent(a0),d0
		add.w	oxNL_feed(a3),d0
		move.w	d0,oxNLI_indent(a4)

		; add 1 to folders numfold

		addq.w	#1,oxNLI_numfold(a0)

		; add 1 to all parent folders

		move.l	a0,a2

.parent_lp	move.l	oxNLI_folder(a2),d0
		beq	.if_open
		move.l	d0,a2
		addq.w	#1,oxNLI_numfold(a2)
		bra.b	.parent_lp

.if_open	; if folder ist open and visible

		btst	#oxNLIB_OPEN,oxNLI_flags(a0)
		beq	.return_ptr

		tst.l	oxNLI_visible(a0)
		beq	.return_ptr

		addq.w	#1,oxNL_items(a3)

		; insert item at correct pos in visible list

		move.w	oxNLI_numfold(a0),d0
.find_vis_end	subq.w	#1,d0
		beq	.insert_vis
		move.l	(a0),a0
		btst	#oxNLIB_OPEN,oxNLI_flags(a0)
		bne.b	.find_vis_end
		sub.w	oxNLI_numfold(a0),d0
		bra	.find_vis_end

.insert_vis	; insert node a4 at pos a0

		move.l	MLN_SUCC(a0),a2
		move.l	a2,MLN_SUCC(a4)
		move.l	a1,MLN_SUCC(a0)
		move.l	a1,MLN_PRED(a2)
		move.l	a0,MLN_PRED(a4)

.return_ptr	bsr	NL_refresh

		move.l	a4,d0
.rts		rts

; open folder	set folder OPEN to 1, if folder has visible link true: step all numfold items foward in backbone,
;								add the item to visible list at prev pos 
;								if that item is a closed folder, sub its numfold from
;								the counter and skip next numfold items in backbone

NL_openfolder	; a1 folder

		bset	#oxNLIB_OPEN,oxNLI_flags(a1)
		bne	.rts

		tst.l	oxNLI_visible(a1)
		beq	.rts

		move.w	oxNLI_numfold(a1),d0
		beq	.rts
.add_loop	subq.w	#1,d0
		bmi	.rf
		move.l	a1,a0
		lea	oxNLI_bone(a1),a1
		move.l	(a1),a1
		lea	-oxNLI_bone(a1),a1

.add_in_loop	; add item in folder to visible list

		move.l	MLN_SUCC(a0),a2
		move.l	a2,MLN_SUCC(a1)
		move.l	a1,MLN_SUCC(a0)
		move.l	a1,MLN_PRED(a2)
		move.l	a0,MLN_PRED(a1)

		; add 1 to number of visible items

		addq.w	#1,oxNL_items(a3)

		; see if folder is closed

		btst	#oxNLIB_OPEN,oxNLI_flags(a1)
		bne	.add_loop

		move.w	oxNLI_numfold(a1),d1
		beq	.add_loop

		sub.w	d1,d0
		beq	.rf

		subq.w	#1,d0

		move.l	a1,a0

		lea	oxNLI_bone(a1),a1

.skip_loop	move.l	(a1),a1
		dbf	d1,.skip_loop

		lea	-oxNLI_bone(a1),a1

		bra	.add_in_loop

.rf		bsr	NL_refresh

.rts		rts

; close folder	set folder OPEN to FALSE, remove all numfold items from visible list if linked, clear their SUCC pointers

NL_closefolder	; a1 folder

		bclr	#oxNLIB_OPEN,oxNLI_flags(a1)
		beq	.rts

		tst.l	oxNLI_visible(a1)
		beq	.rts

		move.l	a1,a2
		move.w	oxNLI_numfold(a2),d0
		beq	.rts
		subq.w	#1,d0

		move.l	(a2),a2
.forward	move.l	a2,a1
		REMOVE

		subq.w	#1,oxNL_items(a3)

		btst	#oxNLIB_OPEN,oxNLI_flags(a2)
		bne	.get_next
		sub.w	oxNLI_numfold(a2),d0
.get_next	move.l	a2,a1
		move.l	(a2),a2
		clr.l	oxNLI_visible(a1)
		dbf	d0,.forward

		bsr	NL_refresh

.rts		rts

NL_setitemtext	move.w	oxNLSIT_column(a1),d2
		move.l	oxNLSIT_text(a1),d1
		move.l	oxNLSIT_item(a1),a1

nl_sit		lsl.w	#2,d2
		moveq	#0,d0
		move.l	d1,oxNLI_strings(a1,d2.w)
		beq	.setl

		move.l	d1,a0
		moveq	#-1,d0
.len_lp		tst.b	(a0)+
		dbeq	d0,.len_lp
		not.w	d0
.setl		lsr.w	#1,d2
		move.w	d0,oxNLI_lenghts(a1,d2.w)

		; check if we are on screen

		move.l	oxNL_drawinfo(a3),d0
		beq.b	.rts1
		move.l	d0,a0
		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a0)
		beq	.rts1

		; redraw

		moveq	#0,d0
		move.l	oxNL_topitem(a3),a0
.lp		cmp.l	a0,a1
		beq.b	.redraw_line
		add.w	#1,d0
		cmp.w	oxNL_lines(a3),d0
		beq.b	.rts1

		move.l	(a0),a0
		tst.l	(a0)
		beq	.rts1
		bra.b	.lp

.redraw_line	moveq	#1,d1
		moveq	#TRUE,d7
		bra	NL_draw_items_rf

.rts1		rts


NL_getnextitem	; a1 *previtem or null means get first item

		move.l	a1,d0
		bne	.getnext

		move.l	oxNL_backbone(a3),a1
		tst.l	(a1)
		bne.b	.return_item		

.return_null	moveq	#0,d0
		rts

.getnext	lea	oxNLI_bone(a1),a1

		move.l	(a1),a1
		tst.l	(a1)
		beq.b	.return_null

.return_item	lea	-oxNLI_bone(a1),a1

		move.l	a1,d0
		rts


NL_getitemuserdata
		move.l	oxNLI_userdata(a1),d0
		rts


NL_getitexts	lea	oxNLI_strings(a1),a0
		move.l	a0,d0
		rts

NL_deselitem	bclr	#oxNLIB_SELECTED,oxNLI_flags(a1)
		clr.l	oxNL_selecteditem(a3)
		rts

NL_activate	move.l	oxNL_list(a3),d0
		beq.b	.rts
		move.l	d0,a1
		tst.l	(a1)
		beq.b	.rts

		bset	#oxNLiB_ACTIVE,oxNL_iflags(a3)
		move.l	a1,oxNL_activeitem(a3)
	;	move.l	a1,oxNL_topitem(a3)
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a1)
.rts		rts

NL_INIT		; build sum of all columns prop width values

		lea	oxNL_props(a0),a1
		moveq	#0,d1
		move.w	oxNL_columns(a0),d0
		subq.w	#1,d0
.lp		add.w	(a1)+,d1
		dbf	d0,.lp
		move.w	d1,oxNL_propsum(a0)

		; init clip region

		lea	oxNL_RegionRectangle(a0),a1
		move.l	a1,oxNL_Region+rg_RegionRectangle(a0)

		; create and set up slider

		btst	#oxNLB_SLIDER,oxNL_flags(a3)
		beq	.rts_ok

		move.l	a3,a1			; base
		lea	.slider_tags(pc),a2
		move.l	#OX_SLIDER,d2
		jsr	_LVOoxCreateObject(a6)
		move.l	d0,oxNL_sliderobject(a3)
		beq	.rts_fail

		push	d0
		move.l	d0,a1
		lea	oxO_list(a3),a0
		ADDTAIL
		pop	a0	; get back *sliderobject

		move.l	#oxA_drawinfo,d0
		move.l	oxNL_drawinfo(a3),d1
		jsr	_LVOoxSetAttr(a6)

.rts_ok		moveq	#1,d0
		rts
.rts_fail	moveq	#-1,d0
		rts


.slider_tags	dc.l	oxSlA_flags,oxSlF_pattern
		dc.l	OX_CONNECT,.proptolist
		dc.l	TAG_END

.proptolist	dc.l	oxCCA_target,oxNL_selfptr|OX_REL
		dc.l	oxCCA_attr,oxSlA_softval
		dc.l	oxCCA_newattr,oxNLA_softpos
		dc.l	TAG_END

NL_DEINIT	; dealloc all items

		move.l	oxNL_backbone+LH_HEAD(a0),d0
		beq	.rts

		move.l	d0,a2
.del_lp		tst.l	(a2)
		beq.b	.rts
		lea	-oxNLI_bone(a2),a0
		move.l	LN_SUCC(a2),a2
		moveq	#oxNLI_SIZEOF,d0
		bsr	free_mem
		bra	.del_lp

.rts		rts


NL_DRAW		; draw frame, titles and separators

		move.l	oxNL_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a2
		move.l	oxDI_pentable(a1),a5

		move.l	a6,a4

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		beq.b	.old_look

		; new look

		move.b	oxPT_blackpen(a5),d4
		move.b	d4,d5

		movem.w	oxNL_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		; sliderwidth is 0 if no slider

		sub.w	oxNL_sliderwidth(a3),d2

		jsr	_LVOoxBevelBorder(a6)

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d3
		subq.w	#1,d2

		; titleheight is 0 if no title

		add.w	oxNL_titleheight(a3),d1

		move.b	oxPT_shinepen(a5),d4
		move.b	oxPT_darkpen(a5),d5

		jsr	_LVOoxBevelBorder(a6)

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d3
		subq.w	#1,d2

		movem.w	d0/d1,-(a7)

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_listpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7)+,d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		bra.b	.both_looks

.old_look	move.b	oxPT_shinepen(a5),d5
		move.b	oxPT_darkpen(a5),d4

		movem.w	oxNL_left(a3),d0-d3
		add.w	d0,d2
		add.w	d1,d3
		subq.w	#1,d2
		subq.w	#1,d3

		jsr	_LVOoxBevelBorder(a6)

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d3
		subq.w	#1,d2

		move.b	oxPT_blackpen(a5),d4
		move.b	d4,d5

		jsr	_LVOoxBevelBorder(a6)

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d3
		subq.w	#1,d2

		movem.w	d0/d1,-(a7)

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_listpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7)+,d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

.both_looks	; titles box

		btst	#oxNLB_TITLES,oxNL_flags(a3)
		beq.b	.content

		movem.w	oxNL_left(a3),d0/d1/d2
		addq.w	#1,d0	; skip black border
		addq.w	#1,d1
		add.w	d0,d2
		subq.w	#3,d2	; sub black border and 1

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		bne.b	.sub_slider

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2

.sub_slider	sub.w	oxNL_sliderwidth(a3),d2
		move.w	d1,d3
		subq.w	#1,d3
		add.w	oxNL_titleheight(a3),d3

		move.b	oxPT_shinepen(a5),d4
		move.b	oxPT_darkpen(a5),d5

		move.l	a4,a6

		jsr	_LVOoxBevelBorder(a6)

		; titles background w/ image

		addq.w	#1,d0
		addq.w	#1,d1
		subq.w	#1,d2
		subq.w	#1,d3

		move.l	oxNL_drawinfo(a3),a1

		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.penfill

		move.l	oxDI_imagetable(a1),a1

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		beq.b	.ti

		move.l	oxIT_menusimage(a1),d6
		bne.b	.ifill

.ti		move.l	oxIT_titlesimage(a1),d6
		beq.b	.penfill

.ifill		move.l	d6,a0

		move.w	d0,d4
		move.w	d1,d5

		move.l	a2,a1

		jsr	_LVOoxImageFill(a6)

		bra.b	.black_line

.penfill	; titles background w/color

		movem.w	d0/d1,-(a7)

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_listpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	(a7),d0/d1

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1

.black_line	btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		bne.b	.titles_sep

		move.w	d3,d1
		addq.w	#2,d1
		subq.w	#1,d0

		move.l	oxB_gfxbase(a4),a6

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.b	oxPT_blackpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	d2,d0
		addq.w	#1,d0
		move.w	d3,d1
		addq.w	#2,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)

.titles_sep	; separators in titles

		btst	#oxNLB_SEPARATORS,oxNL_flags(a3)
		beq.b	.titles

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_darkpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	oxNL_left(a3),d4	;   left
		addq.w	#2,d4			; + border

		move.w	oxNL_top(a3),d5

		move.w	d5,d6
		addq.w	#2,d5

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		bne.b	.height

		addq.w	#1,d5

.height		add.w	oxNL_titleheight(a3),d6

		move.w	oxNL_columns(a3),d7
		subq.w	#1,d7

		push	a4

		lea	oxNL_widths(a3),a4
.tit_sep_loop	tst.w	d7		; 1 column = 0 separators
		beq.b	.pop

		add.w	(a4)+,d4

		move.w	d4,d0
		move.w	d5,d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	d4,d0
		move.w	d6,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)

		addq.w	#1,d4		; step over separator

		dbf	d7,.tit_sep_loop

.pop		pop	a4

.titles		; titles texts with clipping each

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_textpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

 STRUCTURE titleshelp,0
	UWORD	th_x1
	UWORD	th_y1
	UWORD	th_x2
	UWORD	th_y2
	APTR	th_title
	APTR	th_lenght
	APTR	th_width
	LABEL	th_SIZEOF

		lea	-th_SIZEOF(a7),a7

		lea	oxNL_titles(a3),a0
		move.l	a0,th_title(a7)
		lea	oxNL_titlelenghts(a3),a0
		move.l	a0,th_lenght(a7)
		lea	oxNL_widths(a3),a0
		move.l	a0,th_width(a7)

		move.w	oxNL_spacing(a3),d4

		movem.w	oxNL_left(a3),d0/d1

		addq.w	#2,d0			; left border
		add.w	d4,d0			; spacing
		addq.w	#3,d1			; top border
		move.w	d1,d3
		add.w	oxNL_titleheight(a3),d3

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		bne.b	.store

		addq.w	#1,d1

.store		movem.w	d0-d3,th_x1(a7)

		move.w	oxNL_columns(a3),d7
		subq.w	#1,d7

.title_loop	movem.w	th_x1(a7),d0-d3

		move.w	d0,d2
		move.l	th_width(a7),a0
		move.w	(a0)+,d5
		add.w	d5,d2
		add.w	oxNL_separatorwidth(a3),d5
		subq.w	#1,d2
		move.l	a0,th_width(a7)
		sub.w	d4,d2
		sub.w	d4,d2

		; install clip region

		movem.w	d0-d3,oxNL_Region+rg_bounds+ra_MinX(a3)
		sub.w	d0,d2
		sub.w	d1,d3
		movem.w	d2/d3,oxNL_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	oxB_layersbase(a4),a6
		lea	oxNL_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxNL_oldregion(a3)

		; print text

		move.l	oxB_gfxbase(a4),a6

		move.l	th_title(a7),a0
		move.l	(a0)+,d2
		move.l	a0,th_title(a7)
		tst.l	d2
		beq.b	.rem_clip

		movem.w	th_x1(a7),d0/d1
		add.w	rp_TxBaseline(a2),d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.l	th_lenght(a7),a0
		move.w	(a0)+,d0
		move.w	d0,d3
		move.l	a0,th_lenght(a7)

		move.l	d2,a0
		move.l	a2,a1
		jsr	_LVOText(a6)

		btst	#oxNLB_BOLDTITLES,oxNL_flags(a3)
		beq.b	.rem_clip

		movem.w	th_x1(a7),d0/d1
		add.w	rp_TxBaseline(a2),d1
		addq.w	#1,d0

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	d3,d0
		move.l	d2,a0
		move.l	a2,a1
		jsr	_LVOText(a6)

.rem_clip	; remove clip region

		move.l	oxB_layersbase(a4),a6
		move.l	oxNL_oldregion(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion

		add.w	d5,th_x1(a7)

		dbf	d7,.title_loop

		lea	th_SIZEOF(a7),a7

.content	; refresh d1 lines from line d0

		moveq	#0,d0
		move.w	oxNL_lines(a3),d1
		moveq	#FALSE,d7			; fill bg anew

		move.l	a4,a6

NL_draw_items	; add d0 to oxNL_topitem, draw until d1 lines are drawn
		; oxNL_vdist is in-line scroll distance from d0, is allays null or negative

 STRUCTURE	itemshelp,0
	UWORD	ih_fromline	; 0 to n-1
	UWORD	ih_lines	; n
	APTR	ih_startitem
	UWORD	ih_starty
	APTR	ih_width
	UWORD	ih_x1
	UWORD	ih_y1
	UWORD	ih_x2
	UWORD	ih_y2
	LABEL	ih_SIZEOF

		tst.w	d0
		bmi	.rts
		cmp.w	oxNL_lines(a3),d0
		bge	.rts
		cmp.w	oxNL_lines(a3),d1
		ble.b	NL_draw_items_ok

.rts		rts

NL_draw_items_ok pushm	d2-d7/a0-a6

		move.l	oxNL_drawinfo(a3),a2
		move.l	oxDI_pentable(a2),a5
		move.l	oxDI_rastport(a2),a2

		move.l	a6,a4
		move.l	oxB_gfxbase(a4),a6

		movem.w	d0/d1,-(a7)

		moveq	#RP_JAM1,d0
		move.l	a2,a1
		jsr	_LVOSetDrMd(a6)

		movem.w	(a7)+,d0/d1

		lea	-ih_SIZEOF(a7),a7

	bra.b	.refresh_lines


		move.w	d0,d4

		movem.w	d0/d1,ih_fromline(a7)

		movem.w	oxNL_contentleft(a3),d0-d3

		; fill x1 to x2

		add.w	d0,d2
		subq.w	#1,d2

		; text y

		move.w	d1,d5
		mulu	rp_TxHeight(a2),d4
		add.w	d4,d5
		add.w	oxNL_vdist(a3),d5
		move.w	d5,ih_starty(a7)

		tst.w	d7	; optionally not fill bg
		beq.b	.separators

		move.w	oxNL_scrollpix(a3),d4
		bmi.b	.up

		move.w	d1,d3
		add.w	d4,d1
		bra.b	.fill

.up		move.w	d3,d1
		add.w	d4,d3

		bra.b	.fill


.refresh_lines	move.w	d0,d4

		move.w	d1,d6
		mulu.w	rp_TxHeight(a2),d6

		movem.w	d0/d1,ih_fromline(a7)

		movem.w	oxNL_contentleft(a3),d0-d2/d5
		move.w	d1,d7
		add.w	d1,d5
		subq.w	#1,d5

		; fill x1 to x2

		add.w	d0,d2
		subq.w	#1,d2

		; print y, fill y1

		mulu	rp_TxHeight(a2),d4
		add.w	d4,d1
		add.w	oxNL_vdist(a3),d1
		move.w	d1,ih_starty(a7)

		tst.w	d7	; optionally not fill bg
		beq.b	.separators

		; fill y2

		move.w	d1,d3
		add.w	d6,d3
		subq.w	#1,d3

		; clip top

		cmp.w	d7,d1
		bge.b	.clip_bottom
		move.w	d7,d1

.clip_bottom	cmp.w	d5,d3
		ble.b	.fill
		move.w	d5,d3

.fill	;	; fill with image

	;	move.l	oxNL_drawinfo(a3),a1
	;	move.l	oxDI_imagetable(a1),a1
	;	move.l	oxIT_bgimage(a1),d4
	;	beq.b	.penfill

	;	move.l	d4,a0
	;	moveq	#0,d4
	;	moveq	#0,d5
	;	move.l	a2,a1
	;	move.l	a4,a6
	;	jsr	_LVOoxImageFill(a6)
	;	bra.b	.separators

.penfill	; new visible background w/color

		movem.w	d0/d1,-(a7)
		move.l	oxB_gfxbase(a4),a6
		move.b	oxPT_listpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)
		movem.w	(a7)+,d0/d1
		move.l	a2,a1
		jsr	_LVORectFill(a6)

.separators	; calc and draw content separators

		move.l	oxB_gfxbase(a4),a6

		btst	#oxNLB_SEPARATORS,oxNL_flags(a3)
		beq.b	.items

		move.b	oxPT_darkpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		movem.w	oxNL_left(a3),d4/d5	;   left    / top
		addq.w	#2,d4			; + border

		add.w	oxNL_vertbortop(a3),d5
		sub.w	oxNL_spacing(a3),d5

		move.w	d5,d6
		add.w	oxNL_contentheight(a3),d6
		add.w	oxNL_spacing(a3),d6
		addq.w	#1,d6	; ?, is required for unknown reason

		move.w	oxNL_columns(a3),d7
		subq.w	#1,d7

		push	a4

		lea	oxNL_widths(a3),a4
.sep_loop	tst.w	d7		; 1 column = 0 separators
		beq.b	.pop

		add.w	(a4)+,d4

		move.w	d4,d0
		move.w	d5,d1

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	d4,d0
		move.w	d6,d1

		move.l	a2,a1
		jsr	_LVODraw(a6)

		addq.w	#1,d4		; step over separator

		dbf	d7,.sep_loop

.pop		pop	a4

.items		; draw items that are within the refresh-range

		; init start item, is topitem + ih_fromline

		move.l	oxNL_topitem(a3),d0
		beq.b	.pop_ih
		move.l	d0,a0
		tst.l	(a0)			; empty list? dont draw items
		beq.b	.pop_ih
		move.w	ih_fromline(a7),d0

.to_loop	move.l	a0,d1

		move.l	(a0),a0
		tst.l	(a0)
		dbeq	d0,.to_loop

		move.l	d1,ih_startitem(a7)

		; select bar in one part over full line if no separators

		btst	#oxNLB_SEPARATORS,oxNL_flags(a3)
		bne.b	.columns

		move.l	oxB_gfxbase(a4),a6

		move.b	oxPT_listselpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		push	a4

		move.l	ih_startitem+4(a7),a4
		move.w	ih_starty+4(a7),d4		; vdist is allready added
		move.w	4+ih_lines(a7),d6
		subq.w	#1,d6

		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_selectimage(a0),d5

.sel_line_loop	btst	#oxNLIB_SELECTED,oxNLI_flags(a4)
		bne.b	.box_coords

		btst	#oxNLIB_ACTIVE,oxNLI_flags(a4)
		beq.b	.sll_c

.box_coords	; calc coords of select bg box and clip y

		move.w	d4,d1
		move.w	oxNL_contenttop(a3),d0
		moveq	#FALSE,d7
		cmp.w	d0,d1
		bge.b	.btm
		move.w	d0,d1
		moveq	#TRUE,d7
.btm		move.w	d1,d3
		add.w	rp_TxHeight(a2),d3

		add.w	oxNL_contentheight(a3),d0
		cmp.w	d0,d3
		ble.b	.sub_btm
		move.w	d0,d3

.sub_btm	subq.w	#1,d3
		move.w	oxNL_contentleft(a3),d0
		move.w	d0,d2
		add.w	oxNL_contentwidth(a3),d2
		subq.w	#1,d2

		tst.w	d7
		beq.b	.imagefill_bar

		add.w	oxNL_vdist(a3),d3

.imagefill_bar	btst	#oxNLIB_SELECTED,oxNLI_flags(a4)
		beq.b	.fullw_cursor

		move.l	a2,a1

		move.l	(a7),a6
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a6)
		beq.b	.onecolorbar

		tst.l	d5
		beq.b	.onecolorbar

		move.l	d5,a0

		movem.w	d0/d1/d4,-(a7)
		move.l	d5,-(a7)

		move.w	d0,d4
		move.w	d1,d5

		tst.w	d7
		beq.b	.fill_bar

		add.w	oxNL_vdist(a3),d5

.fill_bar	move.l	10(a7),a6

		jsr	_LVOoxImageFill(a6)		

		move.l	(a7)+,d5
		movem.w	(a7)+,d0/d1/d4
		bra.b	.fullw_cursor

.onecolorbar	movem.w	d0/d1,-(a7)

		move.l	4(a7),a6
		move.l	oxB_gfxbase(a6),a6
		jsr	_LVORectFill(a6)

		movem.w	(a7)+,d0/d1

.fullw_cursor	btst	#oxNLIB_ACTIVE,oxNLI_flags(a4)
		beq.b	.sll_c

		move.w	#%1010101010101010,rp_LinePtrn(a2)

		move.l	(a7),a6
		movem.l	d4/d5,-(a7)
		move.b	oxPT_cursorpen(a5),d4
		move.b	d4,d5	
		jsr	_LVOoxBevelBorder(a6)
		movem.l	(a7)+,d4/d5
		move.l	oxB_gfxbase(a6),a6

		move.w	#$ffff,rp_LinePtrn(a2)

.sll_c		add.w	oxNL_lineheight(a3),d4

		move.l	(a4),a4
		tst.l	(a4)
		dbeq	d6,.sel_line_loop

		pop	a4

.columns	; init columns loop

		move.l	oxB_gfxbase(a4),a6

		lea	oxNL_widths(a3),a0
		move.l	a0,ih_width(a7)

		movem.w	oxNL_contentleft(a3),d0-d3
		add.w	d1,d3
		subq.w	#1,d3

		moveq	#0,d7
.columns_loop	; column loop, install cliprect for column

		move.w	d0,d2

		move.l	ih_width(a7),a0
		move.w	(a0),d5
		add.w	d5,d2
		add.w	oxNL_separatorwidth(a3),d5
		subq.w	#1,d2
		addq.l	#2,ih_width(a7)

		sub.w	oxNL_spacing(a3),d2
		sub.w	oxNL_spacing(a3),d2

		movem.w	d0-d3,ih_x1(a7)

		; install clip region

		movem.w	d0-d3,oxNL_Region+rg_bounds+ra_MinX(a3)
		sub.w	d0,d2
		sub.w	d1,d3
		movem.w	d2/d3,oxNL_RegionRectangle+rr_bounds+ra_MaxX(a3)

		move.l	oxB_layersbase(a4),a6
		lea	oxNL_Region(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion
		move.l	d0,oxNL_oldregion(a3)

		; init line loop

		move.l	oxB_gfxbase(a4),a6

		push	a4

		move.l	ih_startitem+4(a7),a4
		move.w	ih_starty+4(a7),d4		; vdist is allready added
		move.w	4+ih_lines(a7),d6
		subq.w	#1,d6

.line_loop	; line loop

		; select-bar background

		btst	#oxNLB_SEPARATORS,oxNL_flags(a3)
		beq.b	.text

		btst	#oxNLIB_SELECTED,oxNLI_flags(a4)
		beq.b	.itembox_coords

		move.b	oxPT_listselpen(a5),d0
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

.itembox_coords	move.w	d4,d1
		move.w	d1,d3
		add.w	rp_TxHeight(a2),d3
		subq.w	#1,d3
		move.w	ih_x1+4(a7),d0
		move.w	ih_x2+4(a7),d2

		btst	#oxNLIB_SELECTED,oxNLI_flags(a4)
		beq.b	.cursor

		move.l	a2,a1

		move.l	(a7),a0
		btst	#oxBB_USEBGIMAGES,oxB_configflags(a0)
		beq.b	.one_color_bar

		pushm	d4/d5

		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_imagetable(a0),a0
		move.l	oxIT_selectimage(a0),d4
		tst.l	d4
		beq.b	.pop45

		move.l	d4,a0

		move.w	d0,d4
		move.w	d1,d5

		move.l	8(a7),a6
		movem.w	d0/d1,-(a7)
		jsr	_LVOoxImageFill(a6)
		move.l	oxB_gfxbase(a6),a6
		movem.w	(a7)+,d0/d1
		popm	d4/d5

.cursor		; cursor

		btst	#oxNLIB_ACTIVE,oxNLI_flags(a4)
		beq.b	.text

		move.w	#%1010101010101010,rp_LinePtrn(a2)

		move.l	(a7),a6
		movem.w	d4/d5,-(a7)
		move.b	oxPT_cursorpen(a5),d4
		move.b	d4,d5	
		jsr	_LVOoxBevelBorder(a6)
		movem.w	(a7)+,d4/d5
		move.l	oxB_gfxbase(a6),a6

		move.w	#$ffff,rp_LinePtrn(a2)

		bra.b	.text

.pop45		popm	d4/d5

.one_color_bar	pushm	d0/d1
		jsr	_LVORectFill(a6)
		popm	d0/d1

		bra.b	.cursor

.text		; text

		move.b	oxPT_listofftextpen(a5),d0

		btst	#oxNLIB_OFF,oxNLI_flags(a4)
		bne.b	.settextpen

		btst	#oxNLIB_SELECTED,oxNLI_flags(a4)
		bne.b	.selected

		move.b	oxPT_listalttextpen(a5),d0

		btst	#oxNLIB_ALTCOLOR,oxNLI_flags(a4)
		bne.b	.settextpen

		move.b	oxPT_listtextpen(a5),d0		
		bra.b	.settextpen

.selected	move.b	oxPT_listtextpen(a5),d0

		btst	#oxNLIB_ALTCOLOR,oxNLI_flags(a4)
		beq.b	.settextpen

		move.b	oxPT_listalttextpen(a5),d0

.settextpen	move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	d4,d1
		add.w	rp_TxBaseline(a2),d1
		move.w	ih_x1+4(a7),d0

		move.w	d7,d3
		add.w	d3,d3

		move.w	oxNLI_offsets(a4,d3.w),d2

		tst.w	d3
		bne	.add_align

		btst	#oxNLiB_FOLDERS,oxNL_iflags(a3)
		beq	.add_align

		tst.w	d2
		bne	.arrow

		add.w	oxNLI_indent(a4),d0

.arrow		movem.w	d0/d1,-(a7)

		tst.w	oxNLI_numfold(a4)
		beq	.arrowwidth

		lea	oxNL_arrow_right(a3),a1

		btst	#oxNLIB_OPEN,oxNLI_flags(a4)
		beq	.arrow_ypos

		lea	oxNL_arrow_down(a3),a1

.arrow_ypos	sub.w	rp_TxBaseline(a2),d1

		add.w	oxNL_arrowpos(a3),d1

		move.l	a2,a0
		move.l	4(a7),a6
		move.l	oxB_intbase(a6),a6
		jsr	_LVODrawBorder(a6)
		move.l	4(a7),a6
		move.l	oxB_gfxbase(a6),a6

.arrowwidth	add.w	#13,(a7)		; step over symbol more to the right

		movem.w	(a7)+,d0/d1

.add_align	add.w	d2,d0

		move.l	a2,a1
		jsr	_LVOMove(a6)

		move.w	oxNLI_lenghts(a4,d3.w),d1
		add.w	d3,d3
		move.l	oxNLI_strings(a4,d3.w),d0
		beq.b	.lp_c
		move.l	d0,a0
		move.w	d1,d0

		move.l	a2,a1
		jsr	_LVOText(a6)

		; ghost if off

		btst	#oxNLIB_OFF,oxNLI_flags(a4)
		beq.b	.lp_c

		move.b	oxPT_listpen(a5),d0		
		move.l	a2,a1
		jsr	_LVOSetAPen(a6)

		move.w	d4,d1
		move.w	d1,d3
		add.w	oxNL_lineheight(a3),d3
		subq.w	#1,d3
		move.w	ih_x1+4(a7),d0
		move.w	ih_x2+4(a7),d2

		lea	.ghostpattern(pc),a0
		move.b	#1,rp_AreaPtSz(a2)
		move.l	a0,rp_AreaPtrn(a2)

		move.l	a2,a1
		jsr	_LVORectFill(a6)

		clr.l	rp_AreaPtrn(a2)
		clr.b	rp_AreaPtSz(a2)

.lp_c		add.w	oxNL_lineheight(a3),d4

		move.l	(a4),a4
		tst.l	(a4)
		beq.b	.terminate
		dbf	d6,.line_loop

.terminate	pop	a4

		; remove cliprect for column

		move.l	oxB_layersbase(a4),a6
		move.l	oxNL_oldregion(a3),a1
		move.l	rp_Layer(a2),a0
		jsr	-174(a6)			; _LVOInstallClipRegion

		add.w	d5,ih_x1(a7)
		movem.w	ih_x1(a7),d0-d3

		addq.w	#1,d7
		cmp.w	oxNL_columns(a3),d7
		blt.b	.columns_loop

.pop_ih		lea	ih_SIZEOF(a7),a7
		popm	d2-d7/a0-a6
		moveq	#0,d0
.rts		rts

.ghostpattern	dc.w	%1000100010001000
		dc.w	%0010001000100010

NL_draw_items_rf
		tst.w	d0
		bmi	.rts
		cmp.w	oxNL_lines(a3),d0
		bge	.rts
		cmp.w	oxNL_lines(a3),d1
		bgt	.rts

		movem.l	a0-a3,-(a7)
		movem.w	d0/d1,-(a7)

		move.l	oxNL_drawinfo(a3),a1

		btst	#oxDIB_WINDOWOPEN,oxDI_flags(a1)
		beq	.no_draw

		move.l	oxDI_windowobject(a1),a0
		moveq	#0,d4
		jsr	_LVOoxBeginRefresh(a6)

		move.l	d0,a2

		movem.w	(a7),d0/d1

		bsr	NL_draw_items_ok

		movem.w	(a7)+,d4/d5
		movem.w	oxNL_contentleft(a3),d0-d3

		mulu.w	rp_TxHeight(a2),d4
		mulu.w	rp_TxHeight(a2),d5

		; calc copy y start

		move.w	d1,d6
		add.w	d4,d1
		add.w	oxNL_vdist(a3),d1
		cmp.w	d6,d1
		bge.b	.h
		move.w	d6,d1

.h		; calc copy height (geht nicht? macht erstmal nix, da unterhalb der liste nix verändert wird?)

		add.w	d1,d5
		add.w	d1,d3
		cmp.w	d3,d5
		ble	.h2
		move.w	d3,d5
.h2		sub.w	d1,d5

		move.w	d5,d3

		moveq	#0,d4
		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0

		jsr	_LVOoxEndRefresh(a6)

.pop		movem.l	(a7)+,a0-a3

		moveq	#1,d0
.rts		rts

.no_draw	addq.l	#4,a7
		bra	.pop


NL_refresh	; rethink and redraw list

		bsr	NL_fix

		; redraw list

		moveq	#TRUE,d7
		moveq	#0,d0
		move.w	oxNL_lines(a3),d1
		bsr	NL_draw_items_rf

		; redraw slider

		move.l	oxNL_sliderobject(a3),d0
		beq	.rts
		move.l	d0,a0

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.rts		rts


NL_fix		bclr	#oxNLiB_REFRESHALL,oxNL_iflags(a3)

		; make sure that list is refreshed in update

		clr.w	oxNL_oldpixoffset(a3)

		; see if list is empty

		tst.l	oxNL_topitem(a3)
		bne	.has_content

		clr.w	oxNL_vdist(a3)
		clr.w	oxNL_inpos(a3)
		clr.w	oxNL_offset(a3)

		bra	.slider

.has_content	move.w	oxNL_lines(a3),d1
		cmp.w	oxNL_items(a3),d1
		ble	.fixbottom

		; align to first item as top item

		clr.w	oxNL_vdist(a3)
		move.w	oxNL_inpos(a3),d0
		add.w	oxNL_offset(a3),d0
		move.w	d0,oxNL_inpos(a3)
		clr.w	oxNL_offset(a3)
		move.l	oxNL_list(a3),oxNL_topitem(a3)
		bra	.slider

.fixbottom	; if required: set correct inpos and calc top offset starting from bottom

		; is the offset smaller than items - lines?
		;	if yes go refresh!
		;	if not, set absolute offset as items - bodylines

		move.w	oxNL_items(a3),d0
		sub.w	oxNL_lines(a3),d0
		cmp.w	oxNL_offset(a3),d0
		bge	.slider

		move.w	oxNL_inpos(a3),d0
		add.w	oxNL_offset(a3),d0

		move.w	oxNL_items(a3),d1
		sub.w	oxNL_bodylines(a3),d1

		move.w	d1,oxNL_offset(a3)

		sub.w	d1,d0
		move.w	d0,oxNL_inpos(a3)

		; find new topitem backwards d1 items starting from last visible item

		move.l	MLH_TAILPRED+oxNL_list(a3),a0
		move.w	oxNL_bodylines(a3),d0

.find_top_loop	subq.w	#1,d0
		beq	.settop
		move.l	MLN_PRED(a0),a0
		bra	.find_top_loop

.settop		move.l	a0,oxNL_topitem(a3)

		; calc vdist

		move.w	oxNL_bodylines(a3),d0
		mulu.w	oxNL_lineheight(a3),d0
		sub.w	oxNL_contentheight(a3),d0

		neg.w	d0

		move.w	d0,oxNL_vdist(a3)

		bset	#oxNLiB_REFRESHALL,oxNL_iflags(a3)

.slider		; slider

		move.l	oxNL_sliderobject(a3),d0
		beq	.want_ref_all
		move.l	d0,a0

		moveq	#OXM_setprop,d1
		lea	-oxPI_SIZEOF(a7),a7
		move.l	a7,a1

		move.w	oxNL_items(a3),d0
		mulu.w	oxNL_lineheight(a3),d0
		move.w	d0,oxPI_max(a1)

		btst	#oxNLiB_REFRESHALL,oxNL_iflags(a3)
		bne	.sub

		move.w	oxNL_offset(a3),d0
		mulu.w	oxNL_lineheight(a3),d0
		sub.w	oxNL_vdist(a3),d0
		bra	.set_pot_body

.sub		sub.w	oxNL_contentheight(a3),d0

.set_pot_body	move.w	d0,oxPI_pot(a1)
		move.w	oxNL_contentheight(a3),oxPI_body(a1)

		jsr	_LVOoxDoMethod(a6)

		lea	oxPI_SIZEOF(a7),a7

.want_ref_all	bset	#oxNLiB_REFRESHALL,oxNL_iflags(a3)

		rts


NL_UPDATE	; redraw content: shift if moved and draw new lines only

		move.l	oxNL_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1

		; calc start entry

		move.w	oxNL_items(a3),d0		; total list entrys
		mulu.w	rp_TxHeight(a1),d0
		move.w	oxNL_contentheight(a3),d1
		ext.l	d1
		sub.l	d1,d0
		mulu.w	oxNL_softpos(a3),d0
		divu.w	#OXPROP_SOFTMAX,d0

		move.w	oxNL_oldpixoffset(a3),d6
		move.w	d0,oxNL_oldpixoffset(a3)
		sub.w	d0,d6
	;move.w	d6,oxNL_scrollpix(a3)

	;	beq.b	.rts				; no op if no visual change

		ext.l	d0
		divu	rp_TxHeight(a1),d0

		; calc pixel dist in the line

		move.l	d0,d1
		swap	d1
		neg.w	d1
		move.w	d1,oxNL_vdist(a3)

		moveq	#-1,d1
		lea	oxNL_list(a3),a0
.to_first_lp	move.l	(a0),a0
		tst.l	(a0)
		beq.b	.rts
		addq.w	#1,d1
		dbf	d0,.to_first_lp

		move.w	oxNL_offset(a3),d0
		add.w	oxNL_inpos(a3),d0
		sub.w	d1,d0
		move.w	d0,oxNL_inpos(a3)

		clr.w	oxNL_activeinpos(a3)

		move.w	d1,oxNL_offset(a3)
		move.l	a0,oxNL_topitem(a3)

		; set up drawing

		move.l	oxNL_drawinfo(a3),a1
		move.l	oxDI_pentable(a1),a5

		move.l	a6,a4

		moveq	#0,d4
		move.l	oxDI_windowobject(a1),a0
		jsr	_LVOoxBeginRefresh(a6)
		move.l	d0,a2

		; init redraw all lines

		moveq	#0,d0
		move.w	oxNL_lines(a3),d1

		bclr	#oxNLiB_REFRESHALL,oxNL_iflags(a3)
		bne.b	.redraw

		; scroll content and redraw newly visible lines only

		moveq	#0,d0		; dont scroll x
		move.w	d6,d1		; scroll y ammount as was oldpixoffset - pixoffset

		neg.w	d1		; scrolling down slides list up ...

		movem.w	oxNL_contentleft(a3),d2-d5
		add.w	d2,d4
		add.w	d3,d5
		subq.w	#1,d4
		subq.w	#1,d5
		move.l	oxB_gfxbase(a4),a6
		move.l	a2,a1
		jsr	_LVOScrollRaster(a6)

		; draw new lines only,
		; ammount must be allways positive

		tst.w	d6
		bge.w	.up
		neg.w	d6

		; scroll down

		move.w	oxNL_contentheight(a3),d0
		subq.w	#1,d0
		sub.w	d6,d0
		bge.b	.calc_lines
		moveq	#0,d0	; if from bottom to first is outside box set to 0
.calc_lines	ext.l	d0
		divu	rp_TxHeight(a2),d0

		move.w	oxNL_lines(a3),d1
		sub.w	d0,d1

		bra.b	.redraw	

.up		moveq	#0,d0
		move.w	oxNL_contentheight(a3),d1
		subq.w	#1,d1
		cmp.w	d6,d1
		ble.b	.calc_lines_up
		move.w	d6,d1

.calc_lines_up	ext.l	d1
		divu	rp_TxHeight(a2),d1
		addq.w	#2,d1

.redraw		moveq	#TRUE,d7 ; fill new bg with listcolor (overwrite auto color 0 for new areas)
		move.l	a4,a6

		bsr	NL_draw_items

		move.l	a4,a6

		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		moveq	#0,d4
		movem.w	oxNL_contentleft(a3),d0-d3
		jsr	_LVOoxEndRefresh(a6)

.rts		rts


NL_GETLAYOUT	move.l	oxNL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2
		move.l	rp_Font(a2),a2

		move.w	tf_YSize(a2),d2			; line height

		moveq	#2,d0				; top borders

		btst	#oxNLB_TITLES,oxNL_flags(a0)
		beq.b	.vertborders

		add.w	d2,d0				; title text height
		addq.w	#3,d0				; spacing im title, oben 2 und unten 1

		subq.w	#1,d0				; black border
		move.w	d0,oxNL_titleheight(a0)

		btst	#oxNLB_MENULOOK,oxNL_flags(a0)
		bne.b	.newlook

		add.w	#3,d0				; old look title top and bottom border
		bra.b	.vertborders

.newlook	addq.w	#2,d0				; new look title bottom border

.vertborders 	move.w	d0,oxNL_sepyoffset(a0)		; start draw separtor lines from top+sepyoffset

		add.w	oxNL_spacing(a0),d0		; vspace oben
		move.w	d0,oxNL_vertbortop(a0)		; start printing at this + font baseline

		addq.w	#2,d0				; borders bottom
		add.w	oxNL_spacing(a0),d0		; vspace bottom
		move.w	d0,oxNL_vertborders(a0)		; contentheight = height - vertborders

		; min space for minlines items or total items

		move.w	oxNL_minlines(a0),d3

		btst	#oxNLB_MAXED,oxNL_flags(a0)
		beq.b	.mul

		move.w	oxNL_items(a0),d3		; this is total ITEMS, not(!) visible lines

.mul		mulu.w	d3,d2
		add.w	d2,d0

		cmp.w	oxNL_minheight(a0),d0
		bge.b	.setwh
		move.w	oxNL_minheight(a0),d0

.setwh		move.w	oxNL_minwidth(a0),oxLI_minwidth(a1)
		move.w	d0,oxLI_minheight(a1)
		move.w	oxNL_propw(a0),oxLI_propw(a1)
		beq.b	.setph
		move.w	#$7fff,oxLI_maxwidth(a1)
.setph		move.w	oxNL_proph(a0),oxLI_proph(a1)
		beq.b	.ok
		move.w	#$7fff,oxLI_maxheight(a1)

.ok		moveq	#1,d0
		rts

NL_SETLAYOUT	move.l	oxLI_width(a1),oxNL_width(a0)
		move.l	oxLI_left(a1),oxNL_left(a0)

		move.l	oxNL_drawinfo(a0),a2
		move.l	oxDI_rastport(a2),a2

		move.w	rp_TxHeight(a2),d0
		move.w	d0,oxNL_lineheight(a3)

		; arrow y center

		sub.w	#12,d0
		asr.w	#1,d0

		move.w	d0,oxNL_arrowpos(a3)

		; content pos

		moveq	#2,d1			; boder
		add.w	oxNL_spacing(a0),d1	; spacing

		; left edge of entries area

		move.w	oxNL_left(a0),d0
		add.w	d1,d0
		move.w	d0,oxNL_contentleft(a0)

		; width of entries area, this is divided per percents below

		move.w	oxNL_width(a0),d0
		sub.w	d1,d0			; left and right borders and spacings
		sub.w	d1,d0

		; sliderwidth is 0 if no slider

		sub.w	oxNL_sliderwidth(a0),d0

		move.w	d0,oxNL_contentwidth(a0)

		; top of list entries area

		move.w	oxNL_top(a0),d0
		add.w	oxNL_vertbortop(a0),d0
		move.w	d0,oxNL_contenttop(a0)

		; height of list entries area

		moveq	#0,d0	; init for div

		move.w	oxNL_height(a0),d0
		sub.w	oxNL_vertborders(a0),d0
		move.w	d0,oxNL_contentheight(a0)

		; number of visible lines, add 1 to fill up the half-visible entry at bottom

		divu.w	rp_TxHeight(a2),d0

		move.l	d0,d1
		swap	d1
		tst.w	d1		; half visible line? -> + a full line
		beq.b	.set
		addq.w	#1,d0

.set		move.w	d0,oxNL_bodylines(a0)

		addq.w	#1,d0
		move.w	d0,oxNL_lines(a0)

		; vertical start and end of separator line

		move.w	oxNL_sepyoffset(a0),d0
		add.w	oxNL_top(a0),d0
		move.w	d0,oxNL_sepystart(a0)
		add.w	oxNL_contentheight(a0),d0
		add.w	oxNL_spacing(a0),d0
		move.w	d0,oxNL_sepyend(a0)

		; calc widths of columns (add prop values and div by that, mul by value)

		move.w	oxNL_width(a0),d0	;   width
		subq.w	#4,d0			; - borders
		sub.w	oxNL_sliderwidth(a0),d0	; - slider

		moveq	#0,d1			; column counter

		btst	#oxNLB_SEPARATORS,oxNL_flags(a0)
		beq.b	.get_sum

		sub.w	oxNL_columns(a0),d0	; sub space for separators

.get_sum	move.w	oxNL_propsum(a0),d3
	;	moveq	#0,d4
	;	move.w	d3,d4
	;	lsr.w	#1,d4			; runden: die Hälfte des Divisors

		move.b	oxNL_aligns(a3),d5
		lea	oxNL_props(a0),a1
		lea	oxNL_widths(a0),a2

		move.l	a6,a4
		move.l	oxB_gfxbase(a6),a6

.columns_loop	move.w	d0,d2
		mulu.w	(a1)+,d2
	;	add.l	d4,d2			;         zum Dividend addieren
		divu.w	d3,d2
		move.w	d2,(a2)+

		; calc horizontal pixel offsets of right aligned texts

		lsr.b	#1,d5
		bcc.b	.col_lpc

		pushm	d0-d4/a1/a2

		; items in a column loop, d5 align bits, d1 column, d2 column width

		move.w	d1,d3
		add.w	d3,d3
		move.w	d3,d4
		add.w	d4,d4

		lea	oxNL_list(a3),a2
.items_loop	move.l	(a2),a2
		tst.l	(a2)
		beq.b	.pop

		move.l	oxNLI_strings(a2,d4.w),d0
		beq.b	.items_loop
		move.l	d0,a0
		move.w	oxNLI_lenghts(a2,d3.w),d0
		move.l	oxNL_drawinfo(a3),a1
		move.l	oxDI_rastport(a1),a1
		jsr	_LVOTextLength(a6)
		move.w	d2,d1
		sub.w	d0,d1
		move.w	oxNL_spacing(a3),d0
		add.w	d0,d0
		sub.w	d0,d1
		move.w	d1,oxNLI_offsets(a2,d3.w)
		bra.b	.items_loop

.pop		popm	d0-d4/a1/a2

.col_lpc	addq.w	#1,d1
		cmp.w	oxNL_columns(a3),d1
		blt.b	.columns_loop

		move.l	a4,a6

		; fit list after window resize

		bsr	NL_fix

		; place slider and set its sizes

		move.l	oxNL_sliderobject(a3),d0
		beq	.rts_ok
		move.l	d0,a0

		lea	-oxLI_SIZEOF(a7),a7
		move.l	a7,a1

		movem.w	oxNL_left(a3),d0-d3
		add.w	d2,d0

		move.w	oxNL_sliderwidth(a3),d2
		sub.w	d2,d0

		subq.w	#1,d0			; border
		addq.w	#1,d2

		btst	#oxNLB_MENULOOK,oxNL_flags(a3)
		bne.b	.set_ltwh

		subq.w	#1,d0
		addq.w	#1,d1			; border
		subq.w	#2,d3

.set_ltwh	movem.w	d0-d3,oxLI_left(a1)

		moveq	#OXM_SETLAYOUT,d1
		jsr	_LVOoxDoMethod(a6)

		lea	oxLI_SIZEOF(a7),a7

.rts_ok		moveq	#1,d0
		rts


; call set/update on slider only if list pos is modified by mouse or cursor (in NL_INTUI)

NL_INTUI	tst.l	oxNL_topitem(a3)
		beq.b	.rts_unused

		cmp.l	#IDCMP_MOUSEBUTTONS,im_Class(a1)
		beq.b	.mousebuttons

		cmp.l	#IDCMP_VANILLAKEY,im_Class(a1)
		bne.b	.active

		; senschar

	 	move.b	oxNL_senschar(a0),d0
		cmp.b	im_Code+1(a1),d0
		beq.b	NL_ACTIVATE

		; vkey only if we are active

		btst	#oxNLiB_ACTIVE,oxNL_iflags(a0)
		beq	.rts_unused


	cmp.b	#"d",im_Code+1(a1)
	beq	.down1

	cmp.b	#"u",im_Code+1(a1)
	beq	.up1

		; check if <enter>

		cmp.b	#$d,im_Code+1(a1)
		beq.b	.prepare_sel
	
		; check if <space>

		cmp.b	#$20,im_Code+1(a1)
		bne.b	.tab_next

.prepare_sel	move.l	oxNL_activeitem(a3),a0
		move.w	oxNL_activeinpos(a3),d0
		bra	.select

.tab_next	; tab cycle next

		cmp.b	#$9,im_Code+1(A1)
		bne.b	.rts_unused		; allow other senschars to see this

		move.l	oxNL_next(a0),d0
		bra.b	.nextprev

.active		; tab cycle prev and cursor

		btst	#oxNLiB_ACTIVE,oxNL_iflags(a0)
		beq	.rts_unused

		cmp.l	#IDCMP_RAWKEY,im_Class(a1)
		bne.b	.rts_unused

		cmp.b	#$42,im_Code+1(a1)
		bne.b	.cursor

		move.l	oxNL_prev(a0),d0

.nextprev	beq.b	.rts_unused
		move.l	d0,a0

		moveq	#OXM_ACTIVATE,d1
		jsr	_LVOoxDoMethod(a6)
		bra.b	.rts_used

.cursor		cmp.w	#CURSORUP,im_Code(a1)
		bne.b	.csr_down

.up1		; cursor up

		move.w	oxNL_activeinpos(a3),d0
		subq.w	#1,oxNL_activeinpos(a3)
		bmi.b	.scroll_1up

		beq.b	.align	; if top entry is reached, align line to be fully visible

		move.l	oxNL_activeitem(a3),a0
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)

		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		move.l	oxNL_activeitem(a3),a0
		move.l	LN_PRED(a0),a0
		tst.l	(a0)
		beq	.rts_used
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		move.l	a0,oxNL_activeitem(a3)

		move.w	oxNL_activeinpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf
		bra	.rts_used

.align		move.l	oxNL_activeitem(a3),a0
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)

		move.l	oxNL_activeitem(a3),a0
		move.l	LN_PRED(a0),a0
		tst.l	(a0)
		beq	.rts_used
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		move.l	a0,oxNL_activeitem(a3)

		clr.w	oxNL_vdist(a3)
		bra.b	.refresh_all

.scroll_1up	clr.w	oxNL_activeinpos(a3)
		subq.w	#1,oxNL_offset(a3)
		bge.b	.pred

		clr.w	oxNL_offset(a3)
		bra.b	.rts_used

.pred		move.l	oxNL_topitem(a3),a1
		move.l	MLN_PRED(a1),a0
		tst.l	(a0)
		beq.b	.rts_used

		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a1)

		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		move.l	a0,oxNL_topitem(a3)
		move.l	a0,oxNL_activeitem(a3)

		addq.w	#1,oxNL_inpos(a3)
		clr.w	oxNL_vdist(a3)

.refresh_all	bset	#oxNLiB_REFRESHALL,oxNL_iflags(a3)

		; update slider

		move.l	oxNL_sliderobject(a3),d0
		beq.b	.rd

		move.l	d0,a0

		move.w	#oxSlA_pot,d0
		move.w	oxNL_offset(a3),d1

		move.l	oxNL_drawinfo(a3),a2
		move.l	oxDI_rastport(a2),a2

		mulu.w	rp_TxHeight(a2),d1
		sub.w	oxNL_vdist(a3),d1

		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.rd		; redraw list content

		moveq	#0,d0
		move.w	oxNL_lines(a3),d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf
		bra	.rts_used

.csr_down	; cursor down

		cmp.w	#CURSORDOWN,im_Code(a1)
		bne.b	.rts_used

.down1		move.l	oxNL_activeitem(a3),a0
		move.l	(a0),a1
		tst.l	(a1)
		beq.b	.rts_used
		move.l	a1,oxNL_activeitem(a3)

		bset	#oxNLIB_ACTIVE,oxNLI_flags(a1)
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)

		move.w	oxNL_activeinpos(a3),d2
		addq.w	#1,oxNL_activeinpos(a3)
		move.w	oxNL_activeinpos(a3),d0
		cmp.w	oxNL_bodylines(a3),d0
		bge.b	.scroll_1down

		; check if bottom line must be aligned

		move.w	oxNL_activeinpos(a3),d1
		addq.w	#1,d1

		mulu.w	oxNL_lineheight(a3),d1

		move.w	oxNL_contentheight(a3),d0
		cmp.w	d0,d1
		ble.b	.off_on

		sub.w	d1,d0

		move.w	d0,oxNL_vdist(a3)
		bra.b	.refresh_all

.off_on		; turn off old active, turn on new active

		move.w	d2,d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		move.w	oxNL_activeinpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7		
		bsr	NL_draw_items_rf

		bra	.rts_used

.scroll_1down	move.l	oxNL_topitem(a3),a0
		move.l	(a0),a0
		tst.l	(a0)
		beq.b	.rts_used
		move.l	a0,oxNL_topitem(a3)

		subq.w	#1,oxNL_activeinpos(a3)

		subq.w	#1,oxNL_inpos(a3)
		addq.w	#1,oxNL_offset(a3)

		; check if bottom line must be aligned

		move.w	oxNL_activeinpos(a3),d1
		addq.w	#1,d1

		mulu.w	oxNL_lineheight(a3),d1

		move.w	oxNL_contentheight(a3),d0
		cmp.w	d0,d1
		ble.b	.refresh_all

		sub.w	d1,d0

		move.w	d0,oxNL_vdist(a3)
		bra.b	.refresh_all

.rts_used	moveq	#1,d0
		rts

.rts_unused	moveq	#0,d0
.rts		rts

.mousebuttons	cmp.w	#SELECTDOWN,im_Code(a1)
 		bne.b	.rts

		; button pressed

		movem.w	oxNL_left(a3),d0-d2
		move.w	oxNL_titleheight(a3),d3
		addq.w	#2,d1
		sub.w	oxNL_sliderwidth(a3),d2
		addq.w	#2,d0
		bsr	is_in_rect
		bne	NL_title_select

		movem.w	oxNL_contentleft(a3),d0-d3
		bsr	is_in_rect
		beq.b	.rts_unused

		; go active

		bset	#oxNLiB_ACTIVE,oxNL_iflags(a3)
		bne	.calc

		move.l	a3,d1
		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)

.calc		; calc inpos, step to selected item from topitem and store in 
		; if selected under end of items return 0

		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_rastport(a0),a2
		move.l	oxDI_window(a0),a0
		moveq	#0,d0
		move.w	wd_GZZMouseY(a0),d0
		sub.w	oxNL_contenttop(a3),d0
		sub.w	oxNL_vdist(a3),d0
		divu	rp_TxHeight(a2),d0
		move.w	d0,d2
		lea	oxNL_topitem(a3),a0
.find_loop	move.l	(a0),a0
		tst.l	(a0)
		beq.b	.rts_used
		dbf	d2,.find_loop

.select		; do nothing if OFF item selected

		btst	#oxNLIB_OFF,oxNLI_flags(a0)
		bne.b	.rts_used

		; fork for multiselect/shift mode (if shiftmulti is set)

		btst	#oxNLB_MULTISELECT,oxNL_flags(a3)
		bne	.multiselect

		btst	#oxNLB_SHIFTMULTI,oxNL_flags(a3)
		beq	.single

		move.w	im_Qualifier(a1),d1
		and.w	#IEQUALIFIER_LSHIFT|IEQUALIFIER_RSHIFT,d1
		bne	.multiselect

.single		; single select

		; fall 0: wenn zuletzt multiselected, deaktiviere alle ausser dem aktiven

		bclr	#oxNLiB_MULTISELECTED,oxNL_iflags(a3)
		beq	.fall1

		lea	oxNL_list(a3),a2
.desel_all_loop	move.l	(a2),a2
		tst.l	(a2)
		beq.b	.da_refr
		cmp.l	a0,a2
		beq.b	.desel_all_loop
		bclr	#oxNLIB_SELECTED,oxNLI_flags(a2)
		bra.b	.desel_all_loop

.da_refr	push	d0

		moveq	#0,d0
		move.w	oxNL_lines(a3),d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		pop	d0

.fall1		; fall 1: active_item == selected_item == clicked_item
		; => vergleiche dc_timer mit timer und rufe ggf hook auf und lösche timer, dann exit
		;	wenn der timer nicht gleich ist, merke timer in dc_timer, dann exit

		move.l	oxNL_activeitem(a3),a2
		cmp.l	a0,a2
		bne.b	.fall2
		cmp.l	oxNL_selecteditem(a3),a0
		bne.b	.fall2

		bsr	.doubleclick

		bsr	.openclose

		bra	.rts_used

.fall2		; fall 2: active_item == selected_item
		; => deactivate and deselect active_item, draw it
		; => goto .sel_and_act

		cmp.l	oxNL_selecteditem(a3),a2
		bne.b	.fall3

		move.l	a2,d1	; tst only
		beq	.sel_and_act

		bclr	#oxNLIB_SELECTED,oxNLI_flags(a2)
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a2)

		pushm	d0/a0/a1

		move.w	oxNL_inpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		popm	d0/a0/a1
		bra.b	.sel_and_act

.fall3		; fall 3: selected_item != clicked_item
		; => deselect selected_item, draw it

		cmp.l	oxNL_selecteditem(a3),a0
		beq.b	.fall4

		pushm	d0/a0/a1

		move.l	oxNL_selecteditem(a3),a0

		move.l	a0,d1	; tst only
		beq	.3_re

		bclr	#oxNLIB_SELECTED,oxNLI_flags(a0)
		move.w	oxNL_inpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

.3_re		popm	d0/a0/a1

.fall4		; fall 4: active_item != clicked_item
		; => deactivate active_item, draw it

		cmp.l	oxNL_activeitem(a3),a0
		beq.b	.fall5

		pushm	d0/a0/a1

		move.l	oxNL_activeitem(a3),a0

		move.l	a0,d1	; tst only
		beq	.4_re

		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		move.w	oxNL_activeinpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

.4_re		popm	d0/a0/a1

.fall5		; fall 5: selected_item == clicked_item
		; => vergleiche dc_timer mit timer und rufe ggf hook auf und lösche timer
		;	wenn der timer nicht gleich ist, merke timer in dc_timer
		; => active_item = clicked_item, activate clicked_item, draw it

		cmp.l	oxNL_selecteditem(a3),a0
		bne	.sel_and_act

		bsr	.doubleclick

		move.l	im_Seconds(a1),oxNL_seconds(a3)
		move.l	im_Micros(a1),oxNL_micros(a3)

		move.l	a0,oxNL_activeitem(a3)
		move.w	d0,oxNL_activeinpos(a3)
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		bsr	.openclose

		bra.b	.rts_used

.sel_and_act	; store timer in dc_timer
		; select and activate clicked_item, draw it
		; active_item = clicked_item, selected_item = clicked_item
		; call select_hook

		push	a0

		move.l	im_Seconds(a1),oxNL_seconds(a3)
		move.l	im_Micros(a1),oxNL_micros(a3)

		move.l	a0,oxNL_activeitem(a3)
		move.l	a0,oxNL_selecteditem(a3)
		move.w	d0,oxNL_inpos(a3)
		move.w	d0,oxNL_activeinpos(a3)
		bset	#oxNLIB_SELECTED,oxNLI_flags(a0)
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		pop	a0

		bsr	.openclose

		bra	.selhook

.multiselect	; multiselect/shift

		; fall 1: actives item geklickt, gehe zu toggle item

		cmp.l	oxNL_activeitem(a3),a0
		beq.b	.ms_click

		; fall 2: inactives item geklickt, deaktiviere aktives item falls vorhanden

		tst.l	oxNL_activeitem(a3)
		beq.b	.ms_click

		clr.l	oxNL_seconds(a3)
		clr.l	oxNL_micros(a3)

		pushm	d0/a0

		move.l	oxNL_activeitem(a3),a0
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)

		move.w	oxNL_activeinpos(a3),d0
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		popm	d0/a0

.ms_click	move.l	a0,oxNL_activeitem(a3)
		move.w	d0,oxNL_activeinpos(a3)
		move.l	a0,oxNL_selecteditem(a3)
		move.w	d0,oxNL_inpos(a3)

		bset	#oxNLiB_MULTISELECTED,oxNL_iflags(a3)

		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		beq	.check_dc

		btst	#oxNLIB_SELECTED,oxNLI_flags(a0)
		beq.b	.store_timer

.check_dc	tst.l	oxNL_dchook(a3)
		beq	.ms_toggle

		bsr	.doubleclick
		bne.b	.open

.store_timer	move.l	im_Seconds(a1),oxNL_seconds(a3)
		move.l	im_Micros(a1),oxNL_micros(a3)

.ms_toggle	bchg	#oxNLIB_SELECTED,oxNLI_flags(a0)
		beq.b	.ms_ref

		clr.l	oxNL_selecteditem(a3)

		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

		bra	.close

.ms_ref		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

.selhook

;	push	a0
;	lea	.sel(pc),a0
;	bsr	auto_request
;	pop	a0

		move.l	oxNL_selhook(a3),d0
		beq	.rts_used

		move.l	d0,a2

		; hooks get: a0 and a3 *list, a4 *base, a1 and a5 *message, a6 *oxbase

		move.l	oxO_userbase(a3),a4

		lea	-oxNLSI_SIZEOF(a7),a7
		move.l	a7,a1
		move.l	a1,a5

		move.l	a3,oxNLSI_list(a5)
		move.l	oxNL_userdata(a3),oxNLSI_userdata(a5)
		move.l	a0,oxNLSI_item(a5)
		move.l	oxNLI_userdata(a0),oxNLSI_item_userdata(a5)
		move.w	oxNLI_id(a0),oxNLSI_item_id(a5)
		move.w	oxNL_offset(a3),d0
	;	add.w	oxNL_inpos(a3),d0
	;	move.w	d0,oxNLSI_item_number(a5)

		move.l	a3,a0
		moveq	#0,d0
		jsr	(a2)
		lea	oxNLSI_SIZEOF(a7),a7

		bra	.rts_used

.sel	dc.b	"item selected",0
.dc	dc.b	"item doubleclicked",0
	even

.doubleclick	; call doubleclick hook if left button doubleclicked on item

		pushm	d0/a0/a1/a3

		move.l	oxNL_seconds(a3),d0
		move.l	oxNL_micros(a3),d1
		move.l	im_Seconds(a1),d2
		move.l	im_Micros(a1),d3
		move.l	d2,oxNL_seconds(a3)
		move.l	d3,oxNL_micros(a3)

		pushm	a0/a6

		move.l	oxB_intbase(a6),a6
		jsr	_LVODoubleClick(a6)

		popm	a0/a6

		move.l	d0,-(a7)
		beq.b	.reget_d0

		; need two clicks again

		clr.l	oxNL_seconds(a3)
		clr.l	oxNL_micros(a3)

		; call dc hook, build message on stack

;	push	a0
;	lea	.dc(pc),a0
;	bsr	auto_request
;	pop	a0

		move.l	oxNL_dchook(a3),d0
		beq.b	.reget_d0

		move.l	d0,a2

		; hooks get: a0 and a3 *list, a4 *base, a1 and a5 *message, a6 *oxbase

		move.l	oxO_userbase(a3),a4

		lea	-oxNLSI_SIZEOF(a7),a7
		move.l	a7,a1
		move.l	a1,a5

		move.l	a3,oxNLSI_list(a5)
		move.l	oxNL_userdata(a3),oxNLSI_userdata(a5)
		move.l	a0,oxNLSI_item(a5)
		move.l	oxNLI_userdata(a0),oxNLSI_item_userdata(a5)
		move.w	oxNLI_id(a0),oxNLSI_item_id(a5)
		move.w	oxNL_offset(a3),d0
;		add.w	oxNL_inpos(a3),d0
;		move.w	d0,oxNLSI_item_number(a5)

		move.l	a3,a0
		moveq	#0,d0
		jsr	(a2)
		lea	oxNLSI_SIZEOF(a7),a7

.reget_d0	move.l	(a7)+,d0

		popm	d0/a0/a1/a3
		rts

.openclose	btst	#oxNLIB_OPEN,oxNLI_flags(a0)
		bne	.close

.open		; open / close folder if clicked

		tst.w	oxNLI_numfold(a0)
		beq	.oc_rts

		pushm	d0/a0/a1
		move.l	a0,a1

		bsr	NL_openfolder

		popm	d0/a0/a1

.oc_rts		rts

.close		; open / close folder if clicked

		tst.w	oxNLI_numfold(a0)
		beq	.oc_rts

		pushm	d0/a0/a1
		move.l	a0,a1

		bsr	NL_closefolder

		popm	d0/a0/a1

		rts


NL_title_select	; title clicked, future plans to activte different sort mechanisms

.rts		rts



NL_ACTIVATE	bset	#oxNLiB_ACTIVE,oxNL_iflags(a3)
		bne	.rts_unused

		move.l	a3,d1
		move.l	oxNL_drawinfo(a3),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)

		; align top to line

		move.w	oxNL_vdist(a3),d2
		beq	.activeitem

		clr.w	oxNL_vdist(a3)

		; update slider

		move.l	oxNL_sliderobject(a3),d0
		beq.b	.activeitem

		move.l	d0,a0

		move.w	#oxSlA_pot,d0
		move.w	oxNL_offset(a3),d1

		mulu.w	oxNL_lineheight(a3),d1

		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.activeitem	move.l	oxNL_topitem(a3),d0
		move.l	d0,oxNL_activeitem(a3)
		beq.b	.rts_unused

		bset	#oxNLiB_REFRESHALL,oxNL_iflags(a3)
		move.l	d0,a0
		bset	#oxNLIB_ACTIVE,oxNLI_flags(a0)

		clr.w	oxNL_activeinpos(a3)
	;	move.w	oxNL_offset(a3),d1
	;	mulu	oxNL_lineheight(a3),d1
	;	add.w	oxNL_vdist(a3),d1
	;	move.w	d1,oxNL_oldpixoffset(a3)

		moveq	#0,d0
		move.w	oxNL_lines(a3),d1

		tst.w	d2
		bne.b	.ref
		moveq	#1,d1

.ref		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

.rts_used	moveq	#1,d0
		rts

.rts_unused	moveq	#0,d0
		rts


NL_INACTIVE	bclr	#oxNLiB_ACTIVE,oxNL_iflags(a3)
		beq	.rts_unused

		clr.l	oxNL_seconds(a3)
		clr.l	oxNL_micros(a3)

		move.l	oxNL_activeitem(a3),d1
		beq.b	.rts_unused

		clr.l	oxNL_activeitem(a3)

		move.l	d1,a0
		bclr	#oxNLIB_ACTIVE,oxNLI_flags(a0)
		beq.b	.rts_unused

		move.w	oxNL_activeinpos(a3),d0
		bmi.b	.rts1
		moveq	#1,d1
		moveq	#TRUE,d7
		bsr	NL_draw_items_rf

.rts1		moveq	#1,d0

.rts_unused	rts


NL_LINKPRIV	btst	#oxNLiB_ACTIVE,oxNL_iflags(a0)
		beq	.rts

		move.l	a0,d1
		move.l	oxNL_drawinfo(a0),a0
		move.l	oxDI_windowobject(a0),a0
		move.l	#oxWA_ichbindran,d0
		jsr	_LVOoxSetAttr(a6)
		moveq	#1,d0
.rts		rts

NL_RELINK   ;	move.l	oxNL_list(a0),a2
	;	tst.l	(a2)
	;	beq.b	.rts
		lea	oxNL_prev(a0),a2
		jmp	_LVOoxRingConnect(a6)

.rts		rts


NL_sort		; doto handle name of null 

		clr.l	oxNL_topitem(a3)
		lea	oxNL_list(a3),a0
		bsr	sortlist
		move.l	oxNL_list(a3),a0
		tst.l	(a0)
		beq	.rts
		move.l	a0,oxNL_topitem(a3)
.rts		rts

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
;	  move.l  4.w,a6
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
  move.l  ln_Name(a4),d0
	bne	.b

	lea	messa(pc),a0
	bsr	auto_request

.b	move.l	d0,a1
  bsr    strcmp
  ble.s  dontswap
  move.l  a3,a1

	push	a6
	move.l	4.w,a6

  jsr    _LVORemove(a6)
  move.l  a5,a0
  move.l  a3,a1
  move.l  a4,a2
  jsr    _LVOInsert(a6)

	pop	a6

  move.l  a3,a4
dontswap:
  dbra.w  d3,loop4
exit3:
  dbra.w  d2,loop3
listempty:
  movem.l (a7)+,d2-d4/a2-a6
  rts

messa	dc.b	"no name",0
	even

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


alloc_mem	tst.l	d0
		beq.b	.rts
		movem.l	d1-a6,-(a7)
		move.l	#$10001,d1	; MEMF_PUBLIC | MEMF_CLEAR
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		movem.l	(a7)+,d1-a6
		tst.l	d0
.rts		rts


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


