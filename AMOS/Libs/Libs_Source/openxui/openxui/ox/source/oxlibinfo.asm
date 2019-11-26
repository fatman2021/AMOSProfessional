; ----------------------------------------

; $VER: OXMASTER PREFERENCES m68k source

; 2003, 2009, 2010 Andreas G. Szabo <silva@psi5.com>
; all rights reserved
; ----------------------------------------

        	IFND EXEC_FUNCDEF_I
        	include exec/funcdef.i
        	ENDC

        	IFND EXEC_TYPES_I
        	include exec/types.i
        	ENDC

PROCNAME	MACRO
procname	dc.b	"Open XUI Prefs and Info",0
		even
		ENDM
; bugs
; - das color preview feld wird bei de auswahl einer variable zweimal gezeichnet,
;   einmal beim allg. draw und dann hinterher nochmal allein das
; - image preview wird doppelt gezeichnet, einmal beim laden, dann beim refresh der page




		include	easy.i
		include	startup.i		; <----- cli/wb startup code here
		include ox.i
		include ox_lib.i
		include ox_internal.i

		include	oxclass_newlist.i
		include oxclass_newstring.i

		include	exec/memory.i
		IFND UITLITY_TAGITEM_I
		include	"utility/tagitem.i"
		ENDC
		IFND EXEC_LISTS_I
		include	"exec/lists.i"
		ENDC

		include	dos/dos.i
		include	dos/dos_lib.i

		include	libraries/asl.i
		include	libraries/asl_lib.i


TRUE		EQU	-1
FALSE		EQU	0


 STRUCTURE	example_globals,0
	APTR	g_oxbase
	APTR	g_winptr
	APTR	g_appptr
	APTR	g_aslbase
	APTR	g_asl_file_req
	APTR	g_menuwindow

		lea	globals,a4
		lea	libs_table(pc),a2
		bsr	libs_opener
		beq	tschuess

		moveq	#ASL_FileRequest,d0
		lea	.freq_tags(pc),a0
		move.l	g_aslbase(a4),a6
		jsr	_LVOAllocAslRequest(a6)
		move.l	d0,g_asl_file_req(a4)
		bne.b	.ox
		bra.b	close_libs

.freq_tags	dc.l	TAG_END

.ox		move.l	g_oxbase(a4),a6

		move.l	LIB_IDSTRING(a6),libver_text

		; step through directory and open all ext classes for listing,
		; to free them step trough classes list and close every external

		bsr	load_all_classes

		lea	oxapptags(pc),a2
		move.l	#OX_APP,d2
		move.l	a4,a1			; base
		jsr	_LVOoxCreateObject(a6)
		move.l	d0,g_appptr(a4)
		beq	close_classes

		move.l	classes_list_ptr(pc),d0
		beq	free_app

		lea	oxB_classlist(a6),a3
.add_clients_lp	move.l	(a3),a3
		tst.l	(a3)
		beq.b	.sortlist

		; storage element *class, *example

		pushm	d1/a0/a1/a6
		move.l	#16,d0
		move.l	#MEMF_PUBLIC,d1
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		popm	d1/a0/a1/a6
		tst.l	d0
		beq	.sortlist

		clr.l	-(a7)	; TAG_END
		move.l	d0,-(a7)
		move.l	#oxNLIA_userdata,-(a7)

		move.l	d0,d2

		move.l	d0,a0					; a0 *storage_element
		move.l	a3,(a0)+				; 0(a0) *class
		clr.l	(a0)+

		; version

		move.l	a0,-(a7)
		move.l	#oxNLIA_text2,-(a7)

		moveq	#0,d0
		move.w	oxC_version(a3),d0
		bsr	ValToDez
		move.b	#".",(a0)+
		moveq	#0,d0
		move.w	oxC_revision(a3),d0
		bsr	ValToDez
		clr.b	(a0)

		; create standard frame for every page

		push	d2

		move.l	#OX_FRAME,d2
		lea	frame_tags(pc),a2

		jsr	_LVOoxCreateObject(a6)

		pop	a2		; get back *storage_element

		tst.l	d0
		beq.b	.addlistnode

		move.l	d0,a0

		; create example and attach to standard frame

		push	a0

		move.l	a3,a0
		jsr	_LVOoxCreateExample(a6)

		pop	a0

		move.l	a0,d1

		tst.l	d0
		beq.b	.addpage

		push	a1

		move.l	d0,a1
		jsr	_LVOoxAddMember(a6)

		pop	a1

.addpage	move.l	pages_ptr(pc),a0
		move.l	#oxPgA_member,d0			; attr id
		jsr	_LVOoxSetAttr(a6)
		move.l	d1,4(a2)				; 4(a2) * new page (object)

.addlistnode	move.l	oxC_name(a3),a2
		move.l	a2,-(a7)
		move.l	#oxNLIA_text1,-(a7)

		lea	.text_user(pc),a2
		btst	#oxCB_USER,oxC_flags(a3)
		bne.b	.setrtext

		lea	.text_int(pc),a2
		tst.l	oxC_header(a3)
		beq.b	.setrtext
		lea	.text_ext(pc),a2
.setrtext	move.l	a2,-(a7)
		move.l	#oxNLIA_text3,-(a7)

		move.l	#oxNLA_item,d0
		move.l	a7,d1
		move.l	classes_list_ptr(pc),a0
		jsr	_LVOoxSetAttr(a6)

		lea	36(a7),a7
		bra.b	.add_clients_lp

.text_int	dc.b	"int",0
.text_ext	dc.b	"ext",0
.text_user	dc.b	"prg",0
		even

.sortlist	move.l	#oxNLM_sort,d1
		move.l	classes_list_ptr(pc),a0
		jsr	_LVOoxDoMethod(a6)

		sub.l	a1,a1
		move.l	#oxNLM_getnextitem,d1
		jsr	_LVOoxDoMethod(a6)
		beq	.restack
		move.l	d0,a1
		move.l	#oxNLM_getitemuserdata,d1	; get * storage element
		jsr	_LVOoxDoMethod(a6)
		beq.b	.restack
		move.l	d0,a0
		move.l	(a0),currentclassptr

.restack	bsr	fill_in_vars_list

		move.l	g_winptr(a4),d0
		beq	free_stor
		move.l	d0,a0
		move.l	#oxWM_OPEN,d1
		jsr	_LVOoxDoMethod(a6)
		tst.l	d0
		beq	free_stor

		move.l	g_appptr(a4),a0
		move.l	#oxAM_RUN,d1
		jsr	_LVOoxDoMethod(a6)

user_cleanup	lea	globals,a4
		move.l	g_oxbase(a4),a6

		; remove and free storage elements ,  pages are freed from pages-deinit

free_stor	move.l	classes_list_ptr(pc),a0
		sub.l	a1,a1
.free_el_lp	move.l	#oxNLM_getnextitem,d1
		jsr	_LVOoxDoMethod(a6)
		tst.l	d0
		beq	.freevarbuffers

		move.l	d0,a1

		move.l	#oxNLM_getitemuserdata,d1
		jsr	_LVOoxDoMethod(a6)
		tst.l	d0
		beq	.free_el_lp

		pushm	a0/a1/a6

		move.l	d0,a1
		moveq	#16,d0
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)

		popm	a0/a1/a6

		bra	.free_el_lp

.freevarbuffers	move.l	vars_list_ptr(pc),a0
		sub.l	a1,a1
.free_hd_lp	move.l	#oxNLM_getnextitem,d1
		jsr	_LVOoxDoMethod(a6)
		tst.l	d0
		beq	free_app

		move.l	d0,a1

		move.l	#oxNLM_getitemuserdata,d1
		jsr	_LVOoxDoMethod(a6)

		push	a0

		move.l	d0,a0

		; free basekeeper

		move.l	bk_env(a0),a2
		moveq	#bk_SIZEOF,d0
		bsr	free_mem

		pop	a0

		move.b	oxE_type(a2),d0

		cmp.b	#$ff,d0
		bne	.ifhexdez

		; if folder AND flag == neg then free env item

		tst.b	oxE_flagbit(a2)
		beq	.free_hd_lp

		push	a0

		move.l	a2,a0
		moveq	#oxE_SIZEOF+4,d0
		bsr	free_mem

		pop	a0

		bra	.free_hd_lp

.ifhexdez	and.b	#oxEt_MASK,d0
		beq.b	.free_hd_lp
		bclr	#oxEtB_FLAG,d0
		bne.b	.free_hd_lp

		move.l	#oxNLM_getitemtexts,d1
		jsr	_LVOoxDoMethod(a6)

		push	a0

		move.l	d0,a0
		move.l	4(a0),d0		; item text for column 2
		beq	.pop

		move.l	d0,a0

		bsr	free_rem

.pop		pop	a0
		bra	.free_hd_lp

free_app	move.l	g_appptr(a4),a0
		jsr	_LVOoxFreeObject(a6)

close_classes	bsr	close_all_classes

		move.l	g_asl_file_req(a4),d0
		beq.b	close_libs
		move.l	d0,a0
		move.l	g_aslbase(a4),a6
		jsr	_LVOFreeAslRequest(a6)

close_libs	move.l	g_oxbase(a4),d0
		
		move.l	d0,a6
		jsr	-18(a6)		; expunge

		lea	libs_table(pc),a2
		bra	libs_closer

tschuess	rts

libs_table	; *name, version, offset in base, retry (load lib from alternate location)

		dc.l	.oxname,OXVERSION,g_oxbase
		dc.l	.aslname,LIBSVER,g_aslbase
		dc.l	0

;.oxinprogdir	dc.b	"progdir:libs/"
.oxname	OXNAME
.aslname	AslName
		even

; inlcude classes

	OXCLASSNAME	newlist
	OXCLASSNAME	newstring

load_all_classes ; a6 *oxbase 	search for classes and load them all

		pushm	d0-a6

		move.l	a6,a4

		move.l	oxB_dosbase(a4),a6

		; try loading from progdir: first

		lea	.altclasspath(pc),a0
		move.l	a0,d1
		moveq	#ACCESS_READ,d2
		jsr	_LVOLock(a6)
		move.l	d0,d7
		bne	.cd

		; then try loading from libs:ox/

		lea	.classpath(pc),a0
		move.l	a0,d1
		moveq	#ACCESS_READ,d2
		jsr	_LVOLock(a6)
		move.l	d0,d7
		beq	.re

.cd		move.l	d0,d1
		jsr	_LVOCurrentDir(a6)
		push	d0

		move.l	#fib_SIZEOF,d0
		bsr	alloc_rem
		move.l	d0,d5
		beq	.leavedir

		move.l	d7,d1
		move.l	d5,d2
		jsr	_LVOExamine(a6)
		tst.l	d0
		beq.b	.freefib

.loadc_lp	move.l	d7,d1
		move.l	d5,d2
		jsr	_LVOExNext(a6)
		tst.l	d0
		beq.b	.ioerror
		move.l	d5,a0
		tst.l	fib_DirEntryType(a0)	; Verzeichnis? -> überlesen
		bgt.b	.loadc_lp

		lea	fib_FileName(a0),a1
		moveq	#0,d0

		move.l	a4,a6
		jsr	_LVOoxOpenClass(a6)
		move.l	oxB_dosbase(a4),a6
		bra.b	.loadc_lp

.ioerror	jsr	_LVOIoErr(a6)

		cmp.l	#ERROR_NO_MORE_ENTRIES,d0
		bne.b	.loadc_lp

.freefib	move.l	d5,a0
		bsr	free_rem

.leavedir	pop	d1
		jsr	_LVOCurrentDir(a6)
		move.l	d7,d1
		jsr	_LVOUnLock(a6)

.re		popm	d0-a6
		rts

.classpath	dc.b	"libs:ox",0
.altclasspath	dc.b	"progdir:libs/ox",0
		even

close_all_classes ; a6 *oxbase

		pushm	d3/a3

		move.l	oxB_classlist(a6),a3		; get first node
.loop		move.l	(a3),d3				; pre fetch next node, end if null
		beq.b	.rts

		move.l	a3,d2				; free class of this node
		jsr	_LVOoxCloseClass(a6)

		move.l	d3,a3				; copy next node to current node
		bra.b	.loop

.rts		popm	d3/a3
		rts

fill_in_vars_list
		move.l	oxbase(pc),a6

		; fill in ox variables

		move.l	a6,a5
		move.l	oxB_config(a6),a2
		bsr	.add_vars

		; make the classes folder

		lea	.classes_folder(pc),a2
		bsr	.add_vars

		move.l	d0,d5
		beq	.rts1

		; fill in class specific variables, loop for all classes that have an env array

		push	a4

		lea	oxB_classlist(a6),a4
.classes_loop	move.l	(a4),a4
		tst.l	(a4)
		beq	.pop

		tst.l	oxC_envarray(a4)
		beq	.classes_loop

		; make this class folder, set

		moveq	#oxE_SIZEOF+4,d0	; plus 4 is the array termination
		bsr	alloc_mem
		beq	.pop

		move.l	d0,a2
		move.l	oxC_name(a4),oxE_name(a2)
		move.b	#oxET_FOLDER,oxE_type(a2)
		move.b	#-1,oxE_flagbit(a2)	; means this folder was allocated, can be freed at quit
		lea	.cldesc(pc),a0
		move.l	a0,oxE_desc(a2)

		bsr	.add_to_fd

		push	d5

		move.l	d0,d5
		beq	.pop

		move.l	oxC_base(a4),a5
		move.l	oxC_envarray(a4),a2

		bsr	.add_to_fd

		pop	d5

		bra	.classes_loop

.pop2		pop	d5
.pop		pop	a4
.rts1		rts

.classes_folder	dc.l	.classes,0,0		; name, default and temp unused
		dc.b	oxEt_FOLDER,0		; type, alloc-flag (0 = this array item is not allocated)
		dc.w	0			; offset unused
		dc.l	.clfd_desc		; description

		dc.l	0	; terminate array

.classes	dc.b	"classes",0
.clfd_desc	dc.b	"All class specific variables are here in this folder.",0
.cldesc		dc.b	"Here are options for this class. If set, they override the global settings.",0
		even

.add_vars	moveq	#0,d5		; initial folder at top is 0
.add_to_fd	moveq	#-1,d6		; initial numfold is endless, use if (a2) 0 as end kriteria

		lea	-oxE_SIZEOF(a2),a2

.add_vars_lp	lea	oxE_SIZEOF(a2),a2
		tst.l	(a2)
		beq.b	.rts

		moveq	#bk_SIZEOF,d0
		bsr	alloc_mem
		beq	.rts

		move.l	d0,a0
		move.l	a5,(a0)+
		move.l	a2,(a0)

		clr.l	-(a7)				; TAGS_END
		move.l	d0,-(a7)			; basekeeper (base,env) im listitem verstauen
		move.l	#oxNLIA_userdata,-(a7)

		move.l	oxE_name(a2),d0
	;	addq.l	#4,d0				; skip "ox/"
		move.l	d0,-(a7)
		move.l	#oxNLIA_text1,-(a7)

		; allocrem string für variableninhalt wenn nicht text und nicht flag

		move.w	oxE_offset(a2),d1

		move.b	oxE_type(a2),d4

		move.b	d4,d7
		cmp.b	#$ff,d4
		beq	.make_item

		and.b	#oxEt_MASK,d4
		bne.b	.not_text

		; string

		move.l	(a5,d1.w),a3
		bra.b	.set_itemrtext

.not_text	move.b	d4,d3
		bclr	#oxEtB_HEX,d3
		bclr	#oxEtB_FLAG,d3

.get_var	moveq	#0,d2

		cmp.b	#oxEt_byte,d3
		bne.b	.var_word
		move.b	(a5,d1.w),d2
		bra.b	.ok

.var_word	cmp.b	#oxEt_word,d3
		bne.b	.var_long
		move.w	(a5,d1.w),d2
		bra.b	.ok

.var_long	move.l	(a5,d1.w),d2
.ok
		bclr	#oxEtB_FLAG,d4
		beq.b	.not_flag

		; flag

		lea	on(pc),a3
		move.b	oxE_flagbit(a2),d0
		btst	d0,d2
		bne.b	.set_itemrtext
		lea	off(pc),a3
		bra.b	.set_itemrtext

.not_flag	; alloc rem for hex/dez string, hex with $

		sub.l	a3,a3

		moveq	#10,d0
		bsr	alloc_rem

		tst.l	d0
		beq.b	.set_itemrtext

		move.l	d0,a0
		move.l	a0,a3
		move.l	d2,d0

		bclr	#oxEtB_HEX,d4
		bne.b	.hex

		; dez, var in d0

		move.b	#"#",(a0)+
		bsr.b	ValToDez
		clr.b	(a0)

		bra.b	.set_itemrtext

.hex		; hex, var in d0

		move.b	#"$",(a0)+
		moveq	#6,d1
		bsr	ValToHex

.set_itemrtext	move.l	a3,-(a7)
		move.l	#oxNLIA_text2,-(a7)
.make_item	move.l	d5,-(a7)
		move.l	#oxNLIA_folder,-(a7)
		move.l	a7,d1
		move.l	#oxNLA_item,d0
		move.l	vars_list_ptr(pc),a0
		jsr	_LVOoxSetAttr(a6)

		cmp.b	#$ff,d7
		bne.b	.restack

		pushm	d5/d6
		move.l	d0,d5
		beq	.restore

		move.w	oxE_numfold(a2),d6
		beq	.restore
		subq.w	#1,d6

		bsr	.add_vars_lp

.restore	popm	d5/d6

		bra	.restack2

.restack	lea	8(a7),a7

.restack2	lea	28(a7),a7

		tst.l	d0
		beq	.rts

		dbf	d6,.add_vars_lp

.rts		rts


update_vars_list
		; e.g. before refresh set all vairables into listitems new!
		; buffer vor hex/dez values used (allocated at startup just before RUN)

		move.l	oxbase(pc),a6

		sub.l	a1,a1
.item_loop	move.l	vars_list_ptr(pc),a0
		move.l	#oxNLM_getnextitem,d1
		jsr	_LVOoxDoMethod(a6)
		tst.l	d0
		beq.b	.done

		move.l	d0,a1

		move.l	#oxNLM_getitemuserdata,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	d0,a2

		move.l	bk_base(a2),a5
		move.l	bk_env(a2),a2

		; read env

		move.b	oxE_type(a2),d0
		cmp.b	#$ff,d0
		beq	.item_loop_cont

		and.b	#oxEt_MASK,d0
		beq.b	.string
		bclr	#oxEtB_FLAG,d0
		bne.b	.flag

		; hex/dez get buffer

		move.l	#oxNLM_getitemtexts,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	d0,a0
		move.l	4(a0),d0
		beq.b	.item_loop_cont
		move.l	d0,a0
		move.l	a0,a3	; use this later

		move.w	oxE_offset(a2),d1

		move.b	oxE_type(a2),d2
		and.b	#oxEt_SIZEMASK,d2

		; hex/dez get var from base

		moveq	#0,d0

		cmp.b	#oxEt_byte,d2
		bne.b	.var_word
		move.b	(a5,d1.w),d0
		moveq	#2,d1
		bra.b	.got_var

.var_word	cmp.b	#oxEt_word,d2
		bne.b	.var_long
		move.w	(a5,d1.w),d0
		moveq	#4,d1
		bra.b	.got_var

.var_long	move.l	(a5,d1.w),d0
		moveq	#8,d1
.got_var
		move.b	oxE_type(a2),d2
		btst	#oxEtB_HEX,d2
		bne.b	.hex

		move.b	#"#",(a0)+
		bsr.b	ValToDez
		clr.b	(a0)
		bra.b	.set_itemrtext

.hex		move.b	#"$",(a0)+

		; if it is a color use 6 chars only

		move.b	oxE_type(a2),d2
		and.b	#oxEt_EMASK,d2
		cmp.b	#oxEt_COLOR,d2
		bne.b	.vth
		moveq	#6,d1
.vth		bsr	ValToHex
		bra.b	.set_itemrtext

.flag		; update flag type variables

		move.w	oxE_offset(a2),d1

		moveq	#0,d2

		cmp.b	#oxEt_byte,d0
		bne.b	.flg_word
		move.b	(a5,d1.w),d2
		bra.b	.got_flag

.flg_word	cmp.b	#oxEt_word,d0
		bne.b	.flg_long
		move.w	(a5,d1.w),d2
		bra.b	.got_flag

.flg_long	move.l	(a5,d1.w),d2
.got_flag
		lea	on(pc),a3
		move.b	oxE_flagbit(a2),d0
		btst	d0,d2
		bne.b	.set_itemrtext
		lea	off(pc),a3
		bra.b	.set_itemrtext

.string		move.w	oxE_offset(a2),d1
		move.l	(a5,d1.w),a3

.set_itemrtext	move.l	a3,d1
		move.l	vars_list_ptr(pc),a0
		move.l	#oxNLA_itemtext2,d0
		jsr	_LVOoxSetAttr(a6)

.item_loop_cont	bra.b	.item_loop

.done		rts


on		dc.b	"ON",0
off		dc.b	"OFF",0
		even

globals
oxbase		dc.l	0	; oxmaster base
winptr		dc.l	0	; test window object to open and close
appptr		dc.l	0	; app object to handle all
		dc.l	0
		dc.l	0
		dc.l	0

oxapptags	dc.l	OX_WINDOW,mainwindow
	;	dc.l	oxAA_flags,oxAF_quitreq
		dc.l	TAG_END

mainwindow	dc.l	oxWA_title,.title
	;	dc.l	oxWA_wantedwidth,500
	;	dc.l	oxWA_wantedheight,340
		dc.l	oxWA_undermouse,-1
		dc.l	oxWA_layout,-1
		dc.l	OX_TABS,top_tabs
		dc.l	OX_PUTPTR,winptr
		dc.l	oxWA_sigtaskclose,-1
		dc.l	oxWA_noautoclose,-1
		dc.l	oxWA_pattstyle2,1
		dc.l	TAG_END

.title		dc.b	"Open XUI Prefs & Info",0
		even

top_tabs 	dc.l	oxTbA_newtab,.browse_classes
		dc.l	oxTbA_newtab,.browse_config
		dc.l	TAG_END

.browse_classes	dc.l	OX_VERTGROUP,top_group,.title_info		; ,tab_tags
.browse_config	dc.l	OX_VERTGROUP,config_group,.title_config

.title_info	dc.b	"informations",0
.title_config	dc.b	"preferences",0
lite_imagename	dc.b	"libs:ox/background.jpg",0
dark_imagename	dc.b	"libs:ox/background_dark.jpg",0
		even

config_group	dc.l	OX_HORIZGROUP,.list_and_edit
		dc.l	OX_HORIZGROUP,.cfg_buttons
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.list_and_edit	dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_VERTGROUP,.vg_items
		dc.l	OX_VERTGROUP,.vg_option
		dc.l	TAG_END

.vg_items	dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	OX_TITLE,.items_title
		dc.l	newlist,.config_list
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.vg_option ;	dc.l	oxGA_vprop,1
	;	dc.l	oxGA_hprop,1
	;	dc.l	oxGA_minwidth,220
		dc.l	OX_TITLE,.option_title
		dc.l	OX_FRAME,.opt_frame
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.opt_frame	; attached edit objects here

		dc.l	oxFrA_hzalign,oxFr_LEFT
		dc.l	oxFrA_vtalign,oxFr_TOP
		dc.l	oxFrA_vprop,1
		dc.l	oxFrA_hprop,1
		dc.l	OX_PUTPTR,option_frame
		dc.l	OX_PAGES,editor_pages
		dc.l	TAG_END

.items_title	dc.l	oxTA_text,.items
		dc.l	oxTA_linechar,5
		dc.l	TAG_END

.option_title	dc.l	oxTA_text,.option
	;	dc.l	oxTA_linechar,6
		dc.l	TAG_END


.config_list	dc.l	oxNLA_proph,1
		dc.l	oxNLA_propw,1
		dc.l	OX_PUTPTR,vars_list_ptr		; add items later
		dc.l	oxNLA_minwidth,300
		dc.l	oxNLA_minlines,3
		dc.l	oxNLA_columns,2
		dc.l	oxNLA_prop1,5
		dc.l	oxNLA_prop2,6
		dc.l	oxNLA_senschar,"e"
	;	dc.l	oxNLA_separators,FALSE
		dc.l	oxNLA_titles,TRUE
		dc.l	oxNLA_boldtitles,TRUE
		dc.l	oxNLA_selhook,var_select
		dc.l	oxNLA_title1,.title1
		dc.l	oxNLA_title2,.title2
	;	dc.l	oxNLA_multiselect,TRUE
		dc.l	TAG_END

.title1		dc.b	"variable",0
.title2		dc.b	"value",0
		even

.cfg_buttons	dc.l	OX_BUTTON,.canc_button
		dc.l	OX_BUTTON,.rev_button
		dc.l	OX_BUTTON,.def_button
		dc.l	OX_BUTTON,.last_button
		dc.l	OX_BUTTON,.test_button
		dc.l	OX_BUTTON,.save_button
		dc.l	OX_BUTTON,.ok_button
		dc.l	TAG_END

.space_tags	dc.l	TAG_END

.ok_button	dc.l	oxBA_text,.oktext		; use
		dc.l	oxBA_hook,.ok_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

.test_button	dc.l	oxBA_text,.testtext
		dc.l	oxBA_hook,.test_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

.save_button	dc.l	oxBA_text,.savetext
		dc.l	oxBA_hook,.save_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

.def_button	dc.l	oxBA_text,.deftext
		dc.l	oxBA_hook,.def_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

.last_button	dc.l	oxBA_text,.lasttext
		dc.l	oxBA_hook,.last_hook
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

.canc_button	dc.l	oxBA_text,.canctext
		dc.l	oxBA_hook,.canc_hook
		dc.l	oxBA_linechar,1
		dc.l	oxA_active,1
		dc.l	TAG_END

.rev_button	dc.l	oxBA_text,.revtext
		dc.l	oxBA_hook,.rev_hook
		dc.l	oxBA_linechar,3
		dc.l	TAG_END

.items		dc.b	"ox env variables",0
.option		dc.b	"item option",0

.oktext		dc.b	"use",0
.revtext	dc.b	"revert",0
.savetext	dc.b	"save",0
.lasttext	dc.b	"last saved",0
.canctext	dc.b	"cancel",0
.deftext	dc.b	"default",0
.testtext	dc.b	"test",0
		even

.ok_hook	jsr	_LVOoxStorePrefs(a6)

.ref_and_quit	jsr	_LVOoxGlobalRefreshGUI(a6)
		sub.l	a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		move.l	d0,a0
		move.l	TC_Userdata(a0),a0
		move.l	#oxAM_QUIT,d1
		move.l	oxbase(pc),a6
		jmp	_LVOoxDoMethod(a6)

.test_hook	bsr	update_vars_list
		jmp	_LVOoxGlobalRefreshGUI(a6)

.canc_hook	jsr	_LVOoxRestorePrefs(a6)
		bra.b	.ref_and_quit

.rev_hook	jsr	_LVOoxRestorePrefs(a6)
		bra.b	.call_reset

.last_hook	jsr	_LVOoxLoadPrefs(a6)
		bra.b	.call_reset

.def_hook	jsr	_LVOoxDefaultPrefs(a6)
		bra.b	.call_reset

.save_hook	jsr	_LVOoxSavePrefs(a6)
		bra.b	.ref_and_quit

.call_reset	move.l	reset_hook(pc),d0
		beq.b	.test_hook
		move.l	d0,a0
		jsr	(a0)
		bra.b	.test_hook

vars_list_ptr	dc.l	0

top_group	dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_FIELD,libver_field
		dc.l	OX_HORIZGROUP,list_and_text
		dc.l	TAG_END

libver_field	dc.l	OX_PUTPTR,libver_field_ptr
		dc.l	oxFdA_hprop,1
		dc.l	oxFdA_flags,oxFdF_WIDE
		dc.l	oxFdA_text
libver_text	dc.l	0
		dc.l	TAG_END

libver_field_ptr	dc.l	0

list_and_text	dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_VERTGROUP,left_group
		dc.l	OX_VERTGROUP,right_group
		dc.l	TAG_END

left_group	dc.l	oxGA_vprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_TITLE,classes_title
		dc.l	newlist,classes_list
		dc.l	TAG_END

classes_title	dc.l	oxTA_text,.text
		dc.l	oxTA_linechar,2
		dc.l	TAG_END
.text		dc.b	"classes",0
		even

right_group	dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	OX_TITLE,example_title
		dc.l	OX_PAGES,page_tags			; pages member here
		dc.l	OX_TITLE,info_title
		dc.l	OX_FIELD,class_text
		dc.l	TAG_END

frame_tags	; frame bevore all objects that are pagemembers

		dc.l	oxFrA_spacing,0
		dc.l	oxFrA_vprop,1
		dc.l	oxFrA_hprop,1
		dc.l	TAG_END

page_tags	dc.l	OX_PUTPTR,pages_ptr
		dc.l	oxPgA_newmember,.logo
		dc.l	oxPgA_redraw,1
		dc.l	TAG_END

.logo		dc.l	OX_FRAME,.logo_frame
.logo_frame	dc.l	OX_IMAGE,.logo_image
		dc.l	TAG_END
.logo_image	dc.l	oxImA_filename,.logoname
		dc.l	TAG_END
.logoname	dc.b	"/oxlogo.jpg",0
		even


pages_ptr	dc.l	0

example_title	dc.l	oxTA_text,.text
		dc.l	TAG_END
.text		dc.b	"example object(s)",0
		even

info_title	dc.l	oxTA_text,.text
		dc.l	TAG_END
.text		dc.b	"class info",0
		even

classes_list_ptr	dc.l	0

classes_list	dc.l	oxNLA_proph,1
		dc.l	oxNLA_propw,0
		dc.l	OX_PUTPTR,classes_list_ptr		; add items later
		dc.l	oxNLA_minwidth,200
		dc.l	oxNLA_minlines,3
		dc.l	oxNLA_columns,3
		dc.l	oxNLA_prop1,9
		dc.l	oxNLA_prop2,4
		dc.l	oxNLA_prop3,3
	;	dc.l	oxNLA_align,RIGHT3
		dc.l	oxNLA_senschar,"l"
	;	dc.l	oxNLA_separators,FALSE
		dc.l	oxNLA_titles,TRUE

	;	dc.l	oxNLA_multiselect,TRUE

		dc.l	oxNLA_boldtitles,TRUE
		dc.l	oxNLA_selhook,class_select
		dc.l	oxNLA_title1,.title1
		dc.l	oxNLA_title2,.title3
		dc.l	oxNLA_title3,.title2

	dc.l	OXA_ID,-1

		dc.l	TAG_END

.title1		dc.b	"name",0
.title2		dc.b	"type",0
.title3		dc.b	"vers.",0
		even

currentclassptr	dc.l	0

 STRUCTURE	basekeeper,0
	APTR	bk_base
	APTR	bk_env
	LABEL	bk_SIZEOF

var_select	; test set itemrtext (<- what does this mean here?)

		move.l	oxNLSI_item_userdata(a1),a3	; basekeeper
		move.l	(a3)+,a5			; class base or lib base
		move.l	(a3),a3				; oxEnv
		move.l	oxNLSI_item(a1),a1

		cmp.l	curr_item(pc),a1
		beq.b	.rts

		move.l	a1,curr_item
		move.l	a3,curr_env
		move.l	a5,curr_base

		moveq	#0,d0

		move.b	oxE_type(a3),d0
		beq.b	.string

		cmp.b	#oxEt_FOLDER,d0
		bne.b	.if

		clr.l	reset_hook

		move.l	oxE_desc(a3),d1
		move.l	folder_field_ptr(pc),a0
		move.l	#oxFdA_text,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	a0,d1
		bra	.set_curr

.if		bclr	#oxEtB_FLAG,d0
		beq.b	.emask

		; flag

		move.w	oxE_offset(a3),d1

		cmp.b	#oxEt_byte,d0
		bne.b	.var_word
		move.b	(a5,d1.w),d1
		bra.b	.ok
.var_word	cmp.b	#oxEt_word,d0
		bne.b	.var_long
		move.w	(a5,d1.w),d1
		bra.b	.ok
.var_long	move.l	(a5,d1.w),d1
.ok
		move.b	oxE_flagbit(a3),d0
		btst	d0,d1
		beq.b	.off
		moveq	#1,d0
		bra.b	.flgh
.off		moveq	#0,d0

.flgh		push	d0
		move.l	oxE_desc(a3),d1
		move.l	desc_field_ptr(pc),a0
		move.l	#oxFdA_text,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)
		pop	d0

		move.l	d0,d1
		move.l	#oxA_selected,d0
		move.l	flag_ptr(pc),a0
		jsr	_LVOoxSetAttr(a6)
		move.l	d1,d0

		bsr	flag_hook

		lea	flag_reset_hook(pc),a0
		lea	reset_hook(pc),a1
		move.l	a0,(a1)

		move.l	flaged_ptr(pc),d1
		bra.b	.set_curr

.emask		move.b	oxE_type(a3),d0
		and.b	#oxEt_EMASK,d0	
		cmp.b	#oxEt_COLOR,d0
		bne.b	.if_pen

		; color get value from base

		move.w	oxE_offset(a3),d0
		move.l	(a5,d0.w),d1

		push	d1

		btst	#31,d1
		bne.b	.inactive

		moveq	#1,d1
		bra.b	.set_act_check
.inactive	moveq	#0,d1

.set_act_check	move.l	#oxA_selected,d0
		move.l	col_act_ptr(pc),a0
	;	jsr	_LVOoxSetAttr(a6)

		pop	d1

		sub.l	a0,a0
		bsr	color_hook

		lea	color_reset_hook(pc),a0
		lea	reset_hook(pc),a1
		move.l	a0,(a1)
		move.l	colored_ptr(pc),d1
		bra	.set_curr

.if_pen		cmp.b	#oxEt_PEN,d0
		bne.b	.if_image

		move.l	oxE_desc(a3),d1
		move.l	pen_desc_ptr(pc),a0
		move.l	#oxFdA_text,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.w	oxE_offset(a3),d0
		moveq	#0,d1
		move.b	(a5,d0.w),d1

		move.l	s_pen_ptr(pc),a0
	 	move.l	#oxSA_value,d0
		jsr	_LVOoxSetAttr(a6)
		moveq	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		lea	pen_reset_hook(pc),a0
		lea	reset_hook(pc),a1
		move.l	a0,(a1)

		move.l	pen_ed_ptr(pc),d1
		bra	.set_curr

.if_image	cmp.b	#oxEt_IMAGE,d0
		bne.b	.nothing

		move.w	oxE_offset(a3),d1
		move.l	(a5,d1.w),d1

		move.l	image(pc),a0
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	img_name_str(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	img_frame(pc),a0
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		lea	image_reset_hook(pc),a0
		lea	reset_hook(pc),a1
		move.l	a0,(a1)

		move.l	imageed_ptr(pc),d1
		bra.b	.set_curr

.nothing	moveq	#0,d1
		bra.b	.set_curr

.string		move.w	oxE_offset(a3),d1
		move.l	(a5,d1.w),d1

		move.l	sedstr(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		lea	string_reset_hook(pc),a0
		move.l	a0,reset_hook

		move.l	stringed_ptr(pc),d1

.set_curr	move.l	edit_pages_ptr(pc),a0
		move.l	#oxPgA_current,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	option_frame(pc),a0
		move.w	#OXM_REFRESH,d1
		jsr	_LVOoxDoMethod(a6)

.rts		rts

reset_hook	dc.l	0		; call here from lastsaved and default buttons
curr_item	dc.l	0
curr_env	dc.l	0
curr_base	dc.l	0
option_frame	dc.l	0		; attach editor pages object here

edit_pages_ptr	dc.l	0

first_ptr	dc.l	0
stringed_ptr	dc.l	0
flaged_ptr	dc.l	0
colored_ptr	dc.l	0

folder_field_ptr	dc.l	0

editor_pages	dc.l	oxPgA_newmember,.first
		dc.l	oxPgA_newmember,.string
		dc.l	oxPgA_newmember,.flag
		dc.l	oxPgA_newmember,.color
		dc.l	oxPgA_newmember,.pen
		dc.l	oxPgA_newmember,.image
		dc.l	oxPgA_newmember,.folder
		dc.l	oxPgA_redraw,0
		dc.l	OX_PUTPTR,edit_pages_ptr
		dc.l	TAG_END

.first		dc.l	OX_FIELD,.field
.string		dc.l	OX_VERTGROUP,string_edit
.flag		dc.l	OX_VERTGROUP,flag_edit
.color		dc.l	OX_VERTGROUP,color_edit
.pen		dc.l	OX_VERTGROUP,pen_edit
.image		dc.l	OX_VERTGROUP,image_edit
.folder		dc.l	OX_FIELD,.folder_field

.folder_field	dc.l	oxFdA_hprop,1
		dc.l	OX_PUTPTR,folder_field_ptr
		dc.l	oxGA_spaceprop,0
		dc.l	oxFdA_flags,oxFdF_LAYOUT
		dc.l	oxFdA_minlines,16
		dc.l	TAG_END

.field		dc.l	oxFdA_hprop,1
	;	dc.l	oxFdA_vprop,1
		dc.l	oxFdA_text,.welcome
		dc.l	OX_PUTPTR,first_ptr
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.welcome	dc.b	"Welcome to OX!",$a
		dc.b	$a
		dc.b	"Select environment var",$a
		dc.b	"to edit from the list.",0
		even

sedstr		dc.l	0

string_edit 	dc.l	newstring,.string
		dc.l	OX_HORIZGROUP,.hz
		dc.l	OX_PUTPTR,stringed_ptr
		dc.l	TAG_END

.hz		dc.l	OX_SPACE,0
		dc.l	OX_BUTTON,.select
		dc.l	TAG_END

.string		dc.l	oxA_propw,1
		dc.l	oxA_minwidth,100
		dc.l	oxA_senschar,"p"
		dc.l	oxNSA_enterhook,.string_hook
		dc.l	OX_PUTPTR,sedstr
		dc.l	TAG_END

.string_hook	move.l	oxNSSI_string(a1),a1
		bra	exchange_string

.select		dc.l	oxBA_text,.tx_select
		dc.l	oxBA_hook,.select_hook
		dc.l	TAG_END
.tx_select	dc.b	"select",0
		even

.select_hook	; select file from requester

		move.l	g_asl_file_req(a4),a0
		clr.l	-(a7)
		move.l	#TRUE,-(a7)
		move.l	#ASLFR_DrawersOnly,-(a7)

		move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d1
		move.l	(a6,d1.w),-(a7)
		move.l	#ASLFR_InitialDrawer,-(a7)

		move.l	a7,a1
		move.l	g_aslbase(a4),a6
		jsr	_LVOAslRequest(a6)
		lea	8*2+4(a7),a7

		tst.l	d0
		beq.b	.rts

		move.l	g_oxbase(a4),a6

		move.l	g_asl_file_req(a4),a0
		move.l	fr_Drawer(a0),a1

		move.l	a1,d1
		move.l	sedstr(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		bra	exchange_string

.rts		rts

string_reset_hook
		move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d1
		move.l	(a6,d1.w),d1

		move.l	sedstr(pc),a0
		move.l	#oxNSA_string,d0
		jmp	_LVOoxSetAttr(a6)

flag_edit	dc.l	OX_HORIZGROUP,.checked
		dc.l	OX_PUTPTR,flaged_ptr
		dc.l	OX_FIELD,.desc_field
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.checked	dc.l	OX_CHECK,.check
		dc.l	OX_LABEL,.lab
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.check		dc.l	oxChkA_senschar,"o"
		dc.l	OX_PUTPTR,flag_ptr
		dc.l	oxChkA_hook,flag_hook
		dc.l	TAG_END
.lab		dc.l	oxLabA_text,.chlabt
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.chlabt		dc.b	"on / off",0
		even

.desc_field	dc.l	OX_PUTPTR,desc_field_ptr
		dc.l	oxFdA_flags,oxFdF_LAYOUT
		dc.l	oxFdA_minlines,16
	;	dc.l	oxFdA_vprop,1
		dc.l	TAG_END

desc_field_ptr	dc.l	0

pen_edit	dc.l	OX_HORIZGROUP,.label_n_input
		dc.l	OX_FIELD,.pen_desc_field
		dc.l	OX_PUTPTR,pen_ed_ptr
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.label_n_input	dc.l	OX_LABEL,.label
		dc.l	OX_STRING,.pen_input
		dc.l	TAG_END

.label		dc.l	oxLabA_text,.labt
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END

.labt		dc.b	"pen number",0
		even

.pen_input	dc.l	oxSA_minwidth,50
		dc.l	oxSA_maxlenght,3
		dc.l	oxSA_prop,0
		dc.l	oxSA_flags,oxSF_DEZ
		dc.l	oxSA_maxval,255
		dc.l	oxSA_senschar,"p"
		dc.l	oxSA_prop,0
		dc.l	oxSA_hook,pen_hook
		dc.l	OX_PUTPTR,s_pen_ptr
		dc.l	TAG_END

.pen_desc_field	dc.l	OX_PUTPTR,pen_desc_ptr
		dc.l	oxFdA_minlines,16
		dc.l	oxFdA_flags,oxFdF_LAYOUT
	;	dc.l	oxFdA_vprop,1
	;	dc.l	oxFdA_imagename,lite_imagename
		dc.l	TAG_END

s_pen_ptr	dc.l	0
pen_desc_ptr	dc.l	0
pen_ed_ptr	dc.l	0

pen_reset_hook	move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d0
		moveq	#0,d1
		move.b	(a6,d0.w),d1

		move.l	s_pen_ptr(pc),a0
	 	move.l	#oxSA_value,d0
		jmp	_LVOoxSetAttr(a6)

pen_hook	move.l	curr_item(pc),a1
		move.l	vars_list_ptr(pc),a0

		push	d1

		move.l	#oxNLM_getitemtexts,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	d0,a0
		move.l	4(a0),d0
		beq.b	.rts_pop		

		move.l	d0,a0	; buffer for var is 50 bytes groß
		move.l	a0,a1

		pop	d0

		; write new var into base

		move.l	curr_env(pc),a2
		move.w	oxE_offset(a2),d1
		move.b	d0,(a6,d1.w)

		; calc hex string from value into buffer

		addq.l	#1,a0	; skip #

		bsr	ValToDez
		clr.b	(a0)

		move.l	a1,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0
		jsr	_LVOoxSetAttr(a6)

		rts

.rts_pop	addq.l	#4,a7
		rts

; support routine to exchange string in oxbase

exchange_string	; exchange name in oxbase
		; a1 * string
		; a6 * oxbase

		move.l	curr_env(pc),a2
		move.w	oxE_offset(a2),d1
		move.l	(a6,d1.w),d0
		beq.b	.s_alloc_new

		cmp.l	oxE_default(a2),d0
		beq.b	.s_alloc_new

		move.l	d0,a0
		bsr	free_rem

.s_alloc_new	move.l	a1,a0
		moveq	#-1,d0
.s_len_lp	addq.l	#1,d0
		tst.b	(a0)+
		bne.b	.s_len_lp
		tst.l	d0
		beq.b	.s_clr
		addq.l	#2,d0
		bsr	alloc_rem
.s_clr		move.l	d0,(a6,d1.w)
		beq.b	.s_set_rtext
		move.l	d0,a0
.s_copy_lp	move.b	(a1)+,(a0)+
		bne.b	.s_copy_lp

.s_set_rtext	; set new name into vars list

		move.l	d0,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0

		jmp	_LVOoxSetAttr(a6)

; IMAGE editor

image_edit	dc.l	OX_PUTPTR,imageed_ptr
		dc.l	OX_FRAME,.dropbox
		dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_HORIZGROUP,.namgroup
		dc.l	OX_HORIZGROUP,.buttons
		dc.l	TAG_END

.namgroup	dc.l	OX_LABEL,.label
		dc.l	newstring,.string
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.label		dc.l	oxLabA_text,.tx_file
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END

.string		dc.l	oxA_propw,1
		dc.l	oxA_senschar,"f"
		dc.l	OX_PUTPTR,img_name_str
		dc.l	oxNSA_enterhook,.s_hook
		dc.l	TAG_END

.s_hook		move.l	oxNSSI_string(a1),a1
		push	a1
		bsr	exchange_string

		; set new filename to image (triggers image to free current image)

		pop	d1

		move.l	image(pc),a0
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		; send update to frame above image (invokes redraw self,
		; send new drawinfos to image and draw it)

		moveq	#OXM_UPDATE,d1
		move.l	img_frame(pc),a0
		jmp	_LVOoxDoMethod(a6)

.buttons	dc.l	OX_BUTTON,.clear
		dc.l	OX_BUTTON,.select
		dc.l	TAG_END

.clear		dc.l	oxBA_text,.tx_clear
		dc.l	oxBA_hook,.clrhook
		dc.l	TAG_END

.select		dc.l	oxBA_text,.tx_select
		dc.l	oxBA_hook,.selhook
		dc.l	TAG_END

.dropbox	dc.l	oxFrA_spacing,5
		dc.l	oxFrA_framestyle,oxFr_BEVEL
		dc.l	OX_VERTGROUP,.image_and_text
	;	dc.l	oxFrA_imagename,.backimg
		dc.l	oxFrA_icdhook,.getfile
		dc.l	TAG_END

.image_and_text	dc.l	OX_FRAME,.image_frame
		dc.l	OX_FIELD,.here_text_fd
		dc.l	oxGA_minspace,0
		dc.l	oxGA_vprop,1
		dc.l	oxGA_hprop,1
		dc.l	TAG_END

.image_frame	; dc.l	oxFrA_spacing,5
		dc.l	oxFrA_minx,80
		dc.l	oxFrA_miny,160
		dc.l	OX_IMAGE,.image
		dc.l	OX_PUTPTR,img_frame
		dc.l	TAG_END

.here_text_fd	dc.l	oxFdA_text,.text
		dc.l	oxFdA_flags,oxFdF_BDLESS|oxFdF_CENTER
	;	dc.l	oxFdA_imagename,.backimg
	;	dc.l	oxFdA_fillpen,oxPT_tabspen
		dc.l	TAG_END

.image	;	dc.l	oxImA_filename,.file
		dc.l	OX_PUTPTR,image
		dc.l	TAG_END

.tx_clear	dc.b	"clear / none",0
.tx_select	dc.b	"select",0
.tx_file	dc.b	"file:",0
.text		dc.b	"drop image here",0
.backimg	dc.b	"libs:ox/background_dark.jpg",0
		even

.clrhook	; free current name if any

		move.l	curr_env(pc),a2
		move.w	oxE_offset(a2),d1
		move.l	(a6,d1.w),d0
		beq.b	.clear_item
		cmp.l	oxE_default(a2),d0
		beq.b	.clear_item

		move.l	d0,a0
		bsr	free_rem

.clear_item	clr.l	(a6,d1.w)

		moveq	#0,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0
		jsr	_LVOoxSetAttr(a6)

.empty_frame	move.l	image(pc),a0
		moveq	#0,d1
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	img_name_str(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	img_frame(pc),a0
		jmp	_LVOoxDoMethod(a6)

.getfile	; build filename on stack

		move.l	a1,a2

		move.l	(a2)+,d1
		lea	-256(a7),a7
		clr.b	(a7)		; pre-terminate if name error
		move.l	a7,d2
		moveq	#127,d3
		push	a6
		move.l	oxB_dosbase(a6),a6
		jsr	-402(a6)	; _LVONameFromLock(a6)
		pop	a6
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
		; set new filename to string and image (triggers image to free current image)

		move.l	image(pc),a0
		move.l	a7,d1
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	img_name_str(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		; send update to frame above image (invokes redraw self,
		; send new drawinfos to image and draw it)

		move.l	img_frame(pc),a0
		jsr	_LVOoxDoMethod(a6)

		; exchange name in oxbase

		move.l	curr_env(pc),a2
		move.w	oxE_offset(a2),d1
		move.l	(a6,d1.w),d0
		beq.b	.alloc_new

		cmp.l	oxE_default(a2),d0
		beq.b	.alloc_new

		move.l	d0,a0
		bsr	free_rem

.alloc_new	move.l	a7,a0
		moveq	#-1,d0
.len_lp		addq.l	#1,d0
		tst.b	(a0)+
		bne.b	.len_lp
		tst.l	d0
		beq.b	.clr
		addq.l	#2,d0
		bsr	alloc_rem
.clr		move.l	d0,(a6,d1.w)
		beq.b	.set_rtext
		move.l	d0,a0
		move.l	a7,a1
.copy_lp	move.b	(a1)+,(a0)+
		bne.b	.copy_lp

.set_rtext	; set new name into vars list

		move.l	d0,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0
		jsr	_LVOoxSetAttr(a6)

		; free the filename on stack

		lea	256(a7),a7

.rts		rts

.selhook	lea	.test_path(pc),a0
		bsr	cd_path
		bne.b	.get

		move.l	oxB_imagesdir(a6),-(a7)
		move.l	oxB_presetspath(a6),-(a7)
		lea	.images_template(pc),a0
		move.l	a7,a1
		bsr	string_format
		addq.l	#8,a7
		beq	.rts

		move.l	d0,-(a7)
		move.l	d0,a0
		bsr	cd_path
		move.l	(a7)+,a0
		bsr	free_rem

.get		move.l	d0,d7

		move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d1
		move.l	(a6,d1.w),a2
		move.l	a2,d1
		move.l	oxB_dosbase(a6),a6
		jsr	_LVOFilePart(a6)

		lea	-256(a7),a7
		move.l	a7,a1

.cpy_path	cmp.l	d0,a2
		beq.b	.terminate
		move.b	(a2)+,(a1)+
		bra.b	.cpy_path
.terminate	clr.b	(a1)		; term path (or empty if filepart = beg of string)

		move.l	a7,d1

		clr.l	-(a7)	; TAG_END
		move.l	d1,-(a7)
		move.l	#ASLFR_InitialDrawer,-(a7)
		move.l	d0,-(a7)
		move.l	#ASLFR_InitialFile,-(a7)
		move.l	#FALSE,-(a7)
		move.l	#ASLFR_DrawersOnly,-(a7)
		move.l	a7,a1
		move.l	g_asl_file_req(a4),a0
		move.l	g_aslbase(a4),a6
		jsr	_LVOAslRequest(a6)
		lea	8*3+4(a7),a7

		tst.l	d0
		beq.b	.free_stack

		move.l	g_asl_file_req(a4),a0
		move.l	a7,a2

		move.l	fr_Drawer(a0),a1

.cpy_path_lp	move.b	(a1)+,(a2)+
		bne.b	.cpy_path_lp
		subq	#1,a1
		subq	#1,a2
		cmp.l	fr_Drawer(a0),a1
		beq.b	.cpy_file
		cmp.b	#":",-1(a2)
		beq.b	.cpy_file
		cmp.b	#"/",-1(a2)
		beq.b	.cpy_file
		move.b	#"/",(a2)+
.cpy_file	move.l	fr_File(a0),a1
.lp		move.b	(a1)+,(a2)+
		bne.b	.lp

		; set new path into oxbase and gadgets and update dropbox image preview

		move.l	g_oxbase(a4),a6

		move.l	a7,a1
		bsr	exchange_string

		move.l	a7,d1

		move.l	image(pc),a0
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	img_name_str(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	img_frame(pc),a0
		jsr	_LVOoxDoMethod(a6)

.free_stack	move.l	d7,d1

		move.l	g_oxbase(a4),a6
		bsr	unlock_path

		lea	256(a7),a7

		rts

.test_path	dc.b	"progdir:presets/ox/images/default",0
.images_template dc.b	"%s/images/%s",0
		even

cd_path		; a0	*path
		;>d0	oldlock to pass to unlock_path
		
		pushm	d2/a6

		move.l	a0,d0
		beq.b	.pop

		move.l	d0,d1

		move.l	#ACCESS_READ,d2
		move.l	oxB_dosbase(a6),a6
		jsr	_LVOLock(a6)

		move.l	d0,d1
		beq.b	.pop

		jsr	_LVOCurrentDir(a6)

		tst.l	d0

.pop		popm	d2/a6
		rts

unlock_path	; d1	*oldlock
		push	a6
		move.l	oxB_dosbase(a6),a6
		jsr	_LVOCurrentDir(a6)
		move.l	d0,d1
		jsr	_LVOUnLock(a6)
		pop	a6
		rts


image_reset_hook
		move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d0
		move.l	(a6,d0.w),d1

		move.l	image(pc),a0
		move.l	#oxImA_filename,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	img_name_str(pc),a0
		move.l	#oxNSA_string,d0
		jsr	_LVOoxSetAttr(a6)

		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	img_frame(pc),a0
		jmp	_LVOoxDoMethod(a6)

imageed_ptr	dc.l	0
img_frame	dc.l	0
img_name_str	dc.l	0
image		dc.l	0


; COLOR editor

col_act_ptr	dc.l	0

color_value	dc.l	0

color_edit ;	dc.l	OX_HORIZGROUP,.checked
		dc.l	OX_HORIZGROUP,.labs_and_strs
		dc.l	OX_HORIZGROUP,color
		dc.l	OX_WHEELGRAD,.wheelgrad
		dc.l	oxGA_hprop,1
		dc.l	oxGA_vprop,1
		dc.l	oxGA_spaceprop,0
		dc.l	OX_PUTPTR,colored_ptr
		dc.l	TAG_END

.wheelgrad	dc.l	oxWGA_minsize,120
		dc.l	oxWGA_hook,color_hook_with_redraw
		dc.l	OX_PUTPTR,wg_ptr
		dc.l	TAG_END

.checked	dc.l	OX_CHECK,.check
		dc.l	OX_LABEL,.lab
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END
.check		dc.l	oxChkA_senschar,"a"
		dc.l	oxChkA_hook,color_act_hook
		dc.l	OX_PUTPTR,col_act_ptr
		dc.l	TAG_END
.lab		dc.l	oxLabA_text,.chlabt
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.chlabt		dc.b	"aktive (use pen if not)",0
		even

.labs_and_strs	dc.l	OX_VERTGROUP,.labs
		dc.l	OX_VERTGROUP,strs
		dc.l	oxGA_spaceprop,0
		dc.l	TAG_END

.labs		dc.l	OX_LABEL,.lhex
		dc.l	OX_LABEL,.lred
		dc.l	OX_LABEL,.lgreen
		dc.l	OX_LABEL,.lblue
		dc.l	TAG_END

.lhex		dc.l	oxLabA_text,.thex
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.lred		dc.l	oxLabA_text,.tred
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.lgreen		dc.l	oxLabA_text,.tgreen
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END
.lblue		dc.l	oxLabA_text,.tblue
		dc.l	oxLabA_linechar,1
		dc.l	TAG_END

.thex		dc.b	"web/hex",0
.tred		dc.b	"red",0
.tgreen		dc.b	"green",0
.tblue		dc.b	"blue",0
tchoose		dc.b	"?",0
		even

strs		dc.l	oxGA_spaceprop,0
		dc.l	oxGA_hprop,1
		dc.l	OX_HORIZGROUP,sghex
		dc.l	OX_HORIZGROUP,sgred
		dc.l	OX_HORIZGROUP,sggreen
		dc.l	OX_HORIZGROUP,sgblue
		dc.l	TAG_END

color		dc.l	oxGA_spaceprop,0
		dc.l	oxGA_hprop,1
		dc.l	oxGA_vprop,1
		dc.l	OX_FIELD,.col_preview
		dc.l	TAG_END

.col_preview 	dc.l	oxFdA_hprop,1
		dc.l	oxFdA_vprop,0
		dc.l	oxFdA_text,.text
		dc.l	oxFdA_minwidth,60
		dc.l	oxFdA_flags,oxFdF_CENTER
		dc.l	oxFdA_fillpen,oxPT_tabspen
		dc.l	OX_PUTPTR,colprev_ptr
		dc.l	TAG_END

.text		dc.b	"preview",0
		even

colprev_ptr	dc.l	0

wg_ptr		dc.l	0

sghex		dc.l	newstring,shex
		dc.l	OX_BUTTON,choose
		dc.l	oxGA_spaceprop,0
		dc.l	oxGA_minspace,4
		dc.l	TAG_END
sgred		dc.l	newstring,sred
		dc.l	TAG_END
sggreen		dc.l	newstring,sgreen
		dc.l	TAG_END
sgblue		dc.l	newstring,sblue
		dc.l	TAG_END

choose		dc.l	oxBA_text,tchoose
		dc.l	oxBA_linechar,1
		dc.l	TAG_END

shex		dc.l	oxNSA_maxlenght,6
		dc.l	oxA_minwidth,80
		dc.l	oxA_senschar,"w"
		dc.l	oxA_propw,FALSE
		dc.l	oxNSA_maxvalue,$FFFFFF
		dc.l	oxNSA_enterhook,color_hook_with_redraw_from_string
		dc.l	oxNSA_hex,TRUE
		dc.l	OX_PUTPTR,shex_ptr
		dc.l	TAG_END

color_act_hook	move.l	curr_env(pc),a3
		move.w	oxE_offset(a3),d2
		move.l	curr_base(pc),a5
		move.l	(a5,d2.w),d1
		bchg	#31,d1
		move.l	d1,(a5,d2.w)
		rts

color_hook_with_redraw_from_string
		move.l	oxNSSI_value(a1),d1

color_hook_with_redraw
		pushm	d1/a0
		bsr	color_hook
		popm	d1/a0

		move.l	a0,d3
	
		move.l	wg_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.prev
		move.l	#OXM_DRAW,d1
		jsr	_LVOoxDoMethod(a6)

.prev		move.l	colprev_ptr(pc),a0
		move.l	#OXM_DRAW,d1
		jmp	_LVOoxDoMethod(a6)

color_reset_hook
		move.l	curr_env(pc),a3
		move.l	curr_base(pc),a5
		move.w	oxE_offset(a3),d0
		move.l	(a5,d0.w),d0

		push	d0

		moveq	#0,d1
		btst	#31,d0
		bne.b	.set_act
		moveq	#1,d1
.set_act	move.l	#oxA_selected,d0
		move.l	col_act_ptr(pc),a0
	;	jsr	_LVOoxSetAttr(a6)

		pop	d1

		sub.l	a0,a0		; do all

		bsr	color_hook

		; must refresh wheel

		move.l	wg_ptr(pc),a0
		move.l	#OXM_DRAW,d1
		jmp	_LVOoxDoMethod(a6)

color_hook	; mask out self

		move.l	d1,color_value

		; write into base

		move.l	curr_env(pc),a1
		move.l	curr_base(pc),a5
		move.w	oxE_offset(a1),d0
		move.l	d1,(a5,d0.w)

		bclr	#31,d1	; mask out inactive bit

		move.l	a0,d3

		move.l	shex_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.wheel

		move.l	#oxNSA_value,d0
		jsr	_LVOoxSetAttr(a6)
		push	d1
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)
		pop	d1

.wheel		move.l	wg_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.prev

		move.l	#oxWGA_color,d0
		jsr	_LVOoxSetAttr(a6)

.prev		move.l	colprev_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.blue
		move.l	#oxFdA_color,d0
		jsr	_LVOoxSetAttr(a6)

.blue		move.l	d1,d2

		move.l	blue_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.green
		and.l	#$FF,d1
	 	move.l	#oxNSA_value,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.green		lsr.l	#8,d2
		move.l	green_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.red
		move.b	d2,d1
		and.l	#$FF,d1
		move.l	#oxNSA_value,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.red		lsr.l	#8,d2
		move.l	red_ptr(pc),a0
		cmp.l	a0,d3
		beq.b	.set_rtext
		move.b	d2,d1
		and.l	#$FF,d1
		move.l	#oxNSA_value,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

.set_rtext	move.l	curr_item(pc),a1
		move.l	vars_list_ptr(pc),a0

		move.l	#oxNLM_getitemtexts,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	d0,a0
		move.l	4(a0),d0
		beq.b	.rts

		move.l	d0,a0	; buffer for var is 50 bytes groß
		move.l	a0,a1
		move.l	color_value(pc),d0

		; write new var into base

		move.l	curr_env(pc),a2
		move.w	oxE_offset(a2),d1
		move.l	d0,(a5,d1.w)

		; calc hex string from value into buffer

		addq.l	#1,a0	; skip $

		moveq	#6,d1
		bsr	ValToHex

		move.l	a1,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0
		jsr	_LVOoxSetAttr(a6)

.rts		rts

flag_ptr	dc.l	0

flag_reset_hook	move.l	curr_env(pc),a1
		move.l	curr_base(pc),a5
		move.w	oxE_offset(a1),d4
		move.b	oxE_type(a1),d2
		and.b	#oxEt_SIZEMASK,d2

		cmp.b	#oxEt_byte,d2
		bne.b	.var_word
		move.b	(a5,d4.w),d1
		bra.b	.ok
.var_word	cmp.b	#oxEt_word,d2
		bne.b	.var_long
		move.w	(a5,d4.w),d1
		bra.b	.ok
.var_long	move.l	(a5,d4.w),d1
.ok
		move.b	oxE_flagbit(a1),d3		
		btst	d3,d1
		bne.b	.on
		lea	off(pc),a2
		moveq	#0,d1
		bra.b	.set
.on		lea	on(pc),a2
		moveq	#1,d1

.set		move.l	#oxA_selected,d0
		move.l	flag_ptr(pc),a0
		jsr	_LVOoxSetAttr(a6)

		move.l	a2,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0

		jmp	_LVOoxSetAttr(a6)


flag_hook	; gets d0 1 = on or 0 = off, state drawn from checkmark-class

		; read, set/clr bit, and write back into base, set ON/OFF text

		move.l	curr_env(pc),a1
		move.l	curr_base(pc),a5
		move.w	oxE_offset(a1),d4
		move.b	oxE_type(a1),d2
		and.b	#oxEt_SIZEMASK,d2

		cmp.b	#oxEt_byte,d2
		bne.b	.var_word
		move.b	(a5,d4.w),d1
		bra.b	.ok
.var_word	cmp.b	#oxEt_word,d2
		bne.b	.var_long
		move.w	(a5,d4.w),d1
		bra.b	.ok
.var_long	move.l	(a5,d4.w),d1
.ok
		lea	on(pc),a0
		move.b	oxE_flagbit(a1),d3		
		tst.b	d0
		bne.b	.on
		lea	off(pc),a0
		bclr	d3,d1
		bra.b	.write_back
.on		bset	d3,d1

.write_back	cmp.b	#oxEt_byte,d2
		bne.b	.varb_word
		move.b	d1,(a5,d4.w)
		bra.b	.ok_wrb
.varb_word	cmp.b	#oxEt_word,d2
		bne.b	.varb_long
		move.w	d1,(a5,d4.w)
		bra.b	.ok
.varb_long	move.l	d1,(a5,d4.w)
.ok_wrb
		move.l	a0,d1
		move.l	vars_list_ptr(pc),a0
		move.l	curr_item(pc),a1
		move.l	#oxNLA_itemtext2,d0

		jmp	_LVOoxSetAttr(a6)

shex_ptr	dc.l	0

red_hook	move.l	oxNSSI_value(a1),d1

		and.l	#$ff,d1
		lsl.l	#8,d1
		lsl.l	#8,d1
		move.l	color_value(pc),d0
		and.l	#$00FFFF,d0
		or.l	d1,d0
		move.l	d0,d1
		bra.b	color_hook_with_redraw

green_hook	move.l	oxNSSI_value(a1),d1
		and.l	#$ff,d1
		lsl.l	#8,d1
		move.l	color_value(pc),d0
		and.l	#$FF00FF,d0
		or.l	d1,d0
		move.l	d0,d1
		bra.b	color_hook_with_redraw

blue_hook	move.l	oxNSSI_value(a1),d1
		move.l	color_value(pc),d0
		and.l	#$FFFF00,d0
		or.b	d1,d0
		move.l	d0,d1
		bra.b	color_hook_with_redraw

sred		dc.l	oxA_senschar,"r"
		dc.l	oxNSA_enterhook,red_hook
		dc.l	OX_PUTPTR,red_ptr
		dc.l	TAG_MORE,s_all
red_ptr		dc.l	0

sgreen		dc.l	oxA_senschar,"g"
		dc.l	oxNSA_enterhook,green_hook
		dc.l	OX_PUTPTR,green_ptr
		dc.l	TAG_MORE,s_all
green_ptr	dc.l	0

sblue		dc.l	oxA_senschar,"b"
		dc.l	oxNSA_enterhook,blue_hook
		dc.l	OX_PUTPTR,blue_ptr
		dc.l	TAG_MORE,s_all
blue_ptr	dc.l	0

s_all		dc.l	oxA_minwidth,36
		dc.l	oxNSA_maxlenght,3
		dc.l	oxA_propw,FALSE
		dc.l	oxNSA_dez,TRUE
		dc.l	oxNSA_maxvalue,255
		dc.l	TAG_END

class_select	; hook gets: a0 and a3 *list, a1 *oxNLSelInfo, a4 *base from oxO_userbase(a3)

		move.l	oxNLSI_item_userdata(a1),d0
		beq.b	rts2

		move.l	d0,a3
		; 0(a3) *class
		; 4(a3) *currently visible object

		move.l	(a3),a4

		move.l	a4,currentclassptr

		; find verstring, if none found fall back to class name

		move.l	oxC_description(a4),d1
		bne	.get_desc
		move.l	oxC_name(a4),d1
		bra	.set_desc
.get_desc	move.l	d1,a0
		cmp.b	#"$",(a0)+		; skip "$VER: "
		bne.b	.set_desc
		cmp.b	#"V",(a0)+
		bne.b	.set_desc
		addq.l	#4,a0
		move.l	a0,d1
.set_desc	move.l	class_text_ptr(pc),a0
		move.l	#oxFdA_text,d0
		jsr	_LVOoxSetAttr(a6)
		move.l	#OXM_UPDATE,d1
		jsr	_LVOoxDoMethod(a6)

		move.l	pages_ptr(pc),a0
		move.l	4(a3),d1
		move.l	#oxPgA_current,d0
		jmp	_LVOoxSetAttr(a6)

		moveq	#OXM_DRAW,d1
		moveq	#OXBMODE_EVERYBODY+OXBMODE_SELF,d2
		jsr	_LVOoxBroadcast(a6)

rts2		rts

class_text	dc.l	OX_PUTPTR,class_text_ptr
		dc.l	oxFdA_inherit,TRUE
		dc.l	oxFdA_minlines,5
		dc.l	oxFdA_text,.welcome
		dc.l	oxFdA_flags,oxFdF_LAYOUT|oxFdF_FILL|oxFdF_UPDATEREDRAW
		dc.l	oxFdA_fillpen,oxPT_tabspen
		dc.l	TAG_END
.welcome	dc.b	"Welcome to Open Source XUI (OX)!",$a,$a
		dc.b	"Please select a class from the left to see what it can do.",0
		even

class_text_ptr	dc.l	0

; support routines

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

;d0	;value 0 to 99999 (?)
;a0	;*deststring
;>a0	;*behindnewchars

ValToDez:
	movem.l	d2-d4/a1,-(a7)
	push	a0
	moveq	#4,d1
	move.l	#10000,d3
	moveq	#0,d2
.lp1	moveq	#-1,d4
.2	addq.w	#1,d4
	sub.w	d3,d0
	bpl.s	.2
	add.w	d3,d0
	divu.w	#10,d3
	add.w	#$30,d4
	tst.w	d2
	bne.b	.4
	cmp.b	#"0",d4
	beq.b	.5
	st	d2
.4	move.b	d4,(a0)+
.5	dbf	d1,.lp1
	cmp.l	(a7)+,a0
	bne.b	.pop
	move.b	#"0",(a0)+
.pop	movem.l	(a7)+,d2-d4/a1
	rts

; ZAK FOR PRESIDENT

