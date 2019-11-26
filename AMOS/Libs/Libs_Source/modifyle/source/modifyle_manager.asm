


; MODIFYLE BROWSER 2/2012
; Andreas G. Szabo
; info@torakosmos.de

; Search in aminet for "modifyle" if you are
; missing something. Assembles with phxass.


 		include exec/types.i
        	include exec/funcdef.i
		include exec/exec_lib.i
		include	exec/tasks.i

		include	easy.i
		include	utility/tagitem.i

		include	modifyle.i
		include	libraries/asl.i

		include	dos/dos.i
		include	dos/dosextens.i


		move.l	4.w,a6

		; look for start from wb

		sub.l   a1,a1
		jsr	_LVOFindTask(a6)

		move.l	d0,a2
		tst.l	pr_CLI(a2)
		bne	.from_cli

		lea	pr_MsgPort(a2),a0
		jsr	_LVOWaitPort(a6)

		lea	pr_MsgPort(a2),a0
		jsr	_LVOGetMsg(a6)

		move.l	d0,.wbmessitsch

.from_cli	; open modifyle library

		lea	.mfname(pc),a1
		moveq	#MFVERSION,d0
		jsr	_LVOOpenLibrary(a6)

		move.l	d0,.mfbase
		beq	.maybe_reply

		; get the ASL compatible filerequester structure

		move.l	d0,a6

		sub.l	a0,a0	; no tags now
		move.l	#ASL_FileRequest,d0
		jsr	_LVOAllocMFRequest(a6)

		tst.l	d0
		beq	.bye

		push	d0

		; Launch the filerequester as a file browser:
		; this creates it's own process and RETURNS!

		; It returns FALSE if the browser failed to
		; start (then must NOT wait for quit signal).

		move.l	d0,a0
		pea	.ASLtags(pc)
		move.l	#TAG_MORE,-(a7)

		move.l	#SIGB_SINGLE,-(a7)
		move.l	#MF_QuitSigBit,-(a7)

		move.l	4.w,a6
		sub.l	a1,a1
		jsr	_LVOFindTask(a6)

		move.l	d0,-(a7)
		move.l	#MF_SigTask,-(a7)

		move.l	a7,a1

		move.l	.mfbase(pc),a6
		jsr	_LVOMFManager(a6)

		lea	8+2*8(a7),a7

		tst.l	d0
		beq	.fail

		; wait for quit signal from requester or break signal from shell/system

		move.l	4.w,a6

		moveq	#0,d0
		moveq	#SIGF_SINGLE,d1
		jsr	_LVOSetSignal(a6)

		move.l	#SIGF_SINGLE|SIGBREAKF_CTRL_C,d0
		jsr	_LVOWait(a6)

		move.b	#SIGBREAKB_CTRL_C,d1
		btst	d1,d0
		beq	.free_req

		move.l	(a7),a0

		move.l	.mfbase(pc),a6
		jsr	_LVOQuitMFRequest(a6)

		bra	.free_req

.fail		lea	.failed(pc),a0
		bsr	printf

.free_req	; free the filerequester

 		pop	a0

		move.l	.mfbase(pc),a6
		jsr	_LVOFreeMFRequest(a6)

.bye		jsr	-18(a6)		; Expunge

		; close modifyle library

		move.l	4.w,a6

		move.l	.mfbase(pc),a1
		jsr	_LVOCloseLibrary(a6)

.maybe_reply	tst.l	.wbmessitsch
		beq	.return

		move.l	4.w,a6

		jsr	_LVOForbid(a6)

		move.l	.wbmessitsch(pc),a1
		jsr	_LVOReplyMsg(a6)

.return		moveq	#0,d0
		rts

.mfbase		dc.l	0
.wbmessitsch	dc.l	0

.mfname		MFNAME
		even

.failed		dc.b	"Failed launching the Modifyle Manager.",$a,0
		even

TRUE	= 1
FALSE	= 0

.ASLtags	dc.l	ASLFR_TitleText,.titletext
	;	dc.l	ASLFR_InitialPattern,.pattern
	;	dc.l	ASLFR_InitialDrawer,.drawer
	;	dc.l	ASLFR_InitialFile,.file
		dc.l	ASLFR_InitialLeftEdge,100
		dc.l	ASLFR_InitialTopEdge,100
		dc.l	ASLFR_InitialWidth,544

	;	dc.l	ASLFR_AcceptPattern,.accept
	;	dc.l	ASLFR_RejectPattern,.reject

	;	dc.l	ASLFR_DrawersOnly,TRUE
	;	dc.l	ASLFR_FilterDrawers,TRUE
	;	dc.l	ASLFR_Flags1,FRF_DOPATTERNS	;|FRF_DOMULTISELECT|FRF_DOSAVEMODE
	;	dc.l	ASLFR_Flags2,FRF_FILTERDRAWERS	;|FRF_REJECTICONS
	;	dc.l	ASLFR_RejectIcons,TRUE
		dc.l	ASLFR_DoPatterns,TRUE
		dc.l	TAG_END

.file		dc.b	"modifyle.lha",0
.drawer		dc.b	"work:",0
.pattern	dc.b	"a#?",0
.accept		dc.b	"o#?",0
.reject		dc.b	"ox#?",0
.titletext	dc.b 	"Modifyle Manager",0
		even


; --------------------------------------------------------------------------
; some support functions that are not part of what is neccesary for ModiFyle
; --------------------------------------------------------------------------

printf		; print a formated string to the CLI

		; a0 string
		; a1 data

		include	dos/dos_lib.i


		pushm	d2/d3/a6

		bsr	string_format

		tst.l	d0
		beq	.pop

		push	d0

		move.l	4.w,a6

		lea	.dosname(pc),a1
		moveq	#0,d0
		jsr	_LVOOpenLibrary(a6)

		tst.l	d0
		beq	.fail_lib

		move.l	d0,a6

		jsr	_LVOOutput(a6)

		move.l	d0,d1	; filehandle
		beq	.free

		move.l	(a7),d2	; string pointer

		move.l	d2,a0

		moveq	#0,d3
.lenght		addq.w	#1,d3
		tst.b	(a0)+
		bne	.lenght
		subq.l	#1,d3	; string lenght

		jsr	_LVOWrite(a6)

.free		pop	a1
		push	a6

		move.l	4.w,a6
		jsr	_LVOFreeVec(a6)

		pop	a1

		jsr	_LVOCloseLibrary(a6)

.pop		popm	d2/d3/a6
		rts

.fail_lib	pop	a1
		move.l	4.w,a6
		jsr	_LVOFreeVec(a6)
		bra	.pop
	
.dosname	dc.b	"dos.library",0
		even

string_format	; return pointer to formated string in d0,
		; string must be freed with exec FreeVec()

		; a0 string
		; a1 data

		include	exec/memory.i

		pushm	d1/a0-a3/a6

		move.l	4.w,a6

		clr.l	-(a7)
		move.l	a7,a3
		lea	.str_len_hook(pc),a2
		jsr	_LVORawDoFmt(a6)

		move.l	(a7)+,d0
		move.l	#MEMF_PUBLIC,d1
		jsr	_LVOAllocVec(a6)
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

