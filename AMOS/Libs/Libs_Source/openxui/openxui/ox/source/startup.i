;=====================================================
; intelligent Startup code - Andreas G. Szabo 11/2009
; handles start from shell and workbench(icon), has
; routines for memory allocation and error handling
;=====================================================

		incdir	include:
        	include exec/funcdef.i
        	include exec/types.i
		include	exec/libraries.i
		include	exec/exec_lib.i
		include	dos/dosextens.i
		include	dos/dostags.i
		include	dos/dos_lib.i
		include	workbench/startup.i
		include intuition/intuition_lib.i

		section program,code

		bra.b	.start

		dc.b	"ZABOX RUNBASE APP 1.0",0
		even

.start		movem.l	d0/a0,-(A7)

		move.l	4.w,a6

		; get wbmsg

		sub.l   a1,a1
		jsr	_LVOFindTask(a6)
		lea	task(pc),a0
		move.l	d0,(a0)
		move.l	d0,a4
		tst.l	pr_CLI(a4)
		bne.b	.fromcli
		lea	pr_MsgPort(a4),a0
		jsr	_LVOWaitPort(A6)
		lea	pr_MsgPort(a4),a0
		jsr	_LVOGetMsg(A6)
		lea	wbmsg(pc),a0
		move.l	d0,(a0)
		beq.b	.fromcli
		addq.l	#8,a7
	;	lea	defaultargs(pc),a2
	;	moveq	#2,d2
		bra.b	call

.fromcli	movem.l	(a7)+,d2/a2
		move.l	4.w,a6
		moveq	#39,d0
		lea	.dosname(pc),a1
		jsr	_LVOOpenLibrary(a6)
		move.l	d0,sudosbase
		beq.b	call

		move.l	d0,a6
		jsr	-492(a6)			; _LVOCli
		move.l	d0,a0
		move.l	cli_Module(a0),segment
		clr.l	cli_Module(a0)
		lea	.proctags(pc),a0
		move.l	a0,d1
		jsr	-498(a6)	; _LVOCreateNewProc

		tst.l	d0
		beq	clean_up	; no process made? -> exit
		bra	ende		; leave / the new process run

.proctags	dc.l	NP_Entry,call
		dc.l	NP_Name,procname
		dc.l	NP_StackSize,8000
		dc.l	TAG_END

.dosname	dc.b	"dos.library",0
		PROCNAME
		even

segment		dc.l	0
wbmsg		dc.l	0
task		dc.l	0
newtask		dc.l	0
sudosbase	dc.l	0
prevtrap	dc.l	0

call		move.l	a7,exitstack

		sub.l   a1,a1
		move.l	4.w,a6
		jsr	_LVOFindTask(a6)
		lea	newtask(pc),a0
		move.l	d0,(a0)
		move.l	d0,a0

		move.l	TC_TRAPCODE(a0),prevtrap
		lea	trapcode(pc),a1
	;	move.l	a1,TC_TRAPCODE(a0)

		bsr	program

clean_up	move.l	wbmsg(pc),d2
		beq.b   .close_dos
		move.l	4.w,a6
                move.l	d2,a1
		jsr	_LVOForbid(a6)
		jsr	_LVOReplyMsg(a6)
		jsr	_LVOPermit(a6)

.close_dos	move.l	4.w,a6
		move.l	sudosbase(pc),d1
		beq.b	.unloadseg
		move.l	d1,a1
		jsr	_LVOCloseLibrary(a6)

.unloadseg	move.l	segment(pc),d0 
		beq.b	ende
                move.l	4.w,a6
		jsr	_LVOForbid(a6)
		move.l	segment(pc),d1
		move.l	sudosbase(pc),a6
		jmp	_LVOUnLoadSeg(a6)

ende		move.l	returncode(pc),d0
		rts

returncode	dc.l	0
error_text	dc.l	0
error_data	dc.l	0
exitstack	dc.l	0
alertnumber	dc.l	0
returnaddr	dc.l	0
runbase_flags	dc.b	0
		even

	BITDEF RB,OUTOFMEM,0	; out of memory

trapcode	move.l	(SP)+,d0
		move.l	d0,alertnumber
		lea	.usermode(pc),a0
		cmp.w	#3,d0			; ist es eine ungerade addressierung?
		bne.b	.set_retr		; wenn ja
		move.l	10(sp),returnaddr	; hole alter pc von anderer position vom stack
		move.l	a0,10(sp)
		RTE
.set_retr	move.l	2(sp),returnaddr	; hole alten pc.l, überspringe statusregister.w
.set_ret	move.l	A0,2(sp)
		RTE

.traptext	dc.b	"Error %ld before %lx.",0
		even

.usermode	move.l	returnaddr(pc),-(a7)
		move.l	alertnumber(pc),-(A7)
		move.l	a7,a1
		lea	.traptext(pc),a0
		bsr	auto_request

error_exit	move.l	exitstack(pc),a7
		move.l	error_text(pc),d0
		move.l	d0,a0
		bne.b	.data
		btst	#RBB_OUTOFMEM,runbase_flags
		bne.b	.cleanup
		lea	.general(pc),a0
.data		move.l	error_data(pc),a1
		bsr	auto_request

.cleanup	bsr	user_cleanup
		bra	clean_up

.general	dc.b	"Something NOT so wonderful has happened!",$a
		dc.b	"Cannot continue.",0
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

free_mem	movem.l	d0-a6,-(a7)
		move.l	a0,a1		; aber in a1 wird gebraucht
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)
		movem.l	(a7)+,d0-a6
		rts

alloc_rem	tst.l	d0
		beq.b	.rts
		addq.l	#4,d0
		movem.l	d1/d2/a0/a1/a6,-(a7)
		move.l	d0,d2

		move.l	d2,d0
		move.l	#$10001,d1	; MEMF_PUBLIC | MEMF_CLEAR
		move.l	4.w,a6
		jsr	_LVOAllocMem(a6)
		tst.l	d0
		bne.b	.store_size

		cmp.l	#1024,d2		; if memory is less than 1 k terminate everything because
		blt.b	.ex			; maybe alert would show again and again

		lea	out_of_memory(pc),a0
		bsr	auto_request
		moveq	#0,d0
		bra.b	.pop

.ex		lea	very_very(pc),a0
		bsr	auto_request
		bset	#RBB_OUTOFMEM,runbase_flags
		bra.b	error_exit

.store_size	move.l	d0,a0
		move.l	d2,(a0)+
		move.l	a0,d0
.pop		movem.l	(a7)+,d1/d2/a0/a1/a6
.rts		rts

out_of_memory	dc.b	"Out of memory!",0
very_very	dc.b	"Very very out of memory. Cannot continue!",0
		even

out_of_mem	lea	out_of_memory(pc),a0
		bra	auto_request

out_of_mem_exit	lea	very_very(pc),a0
		bsr	auto_request
		bset	#RBB_OUTOFMEM,runbase_flags
		bra.b	error_exit

free_rem	movem.l	d0/d1/a0/a1/a6,-(a7)
		move.l -(a0),d0
		move.l	a0,a1
		move.l	4.w,a6
		jsr	_LVOFreeMem(a6)
		movem.l	(a7)+,d0/d1/a0/a1/a6
		rts

auto_request	; a0	*text
		; a1	data	

		bsr	string_format
		beq.b	.print		; if no memory for string try w/o format
					; (not really usefull though)
		move.l	d0,a0

		bsr	 .print

		bra	free_rem

.print		pushm	a0/a2/a3/a6

		move.l	#MEMF_PUBLIC|MEMF_LARGEST,d1
		move.l	4.w,a6
		jsr	_LVOAvailMem(a6)
		move.l	d0,d2

		lea	.intname(pc),a1
		moveq	#39,d0
		jsr	_LVOOpenLibrary(a6)

		tst.l	d0
		beq.b	.alert

		move.l	d0,a6

		cmp.l	#50000,d2
		blt	.displayalert

		move.l	(a7),a0

		lea	.it_body(pc),a1
		move.l	a0,it_IText(a1)	; insert *text into body intuitext
		sub.l	a0,a0		; no parent window
		sub.l	a2,a2		; no positive text
		lea	.it_ok(pc),a3	; negative text
		moveq	#0,d0
		moveq	#0,d1

		jsr	_LVOAutoRequest(a6)

.close_int	move.l	a6,a1
		move.l	4.w,a6
		jsr	_LVOCloseLibrary(a6)
		bra.b	.pop

.displayalert	move.l	(a7),a0

		lea	-256(a7),a7

		; make an AlertMessage string as described in intuition.doc

		move.l	a7,a1
		move.w	#100,(a1)+	; x
		move.b	#50,(a1)+	; y
		move.w	#250,d0	; buffer
.loop		move.b	(a0)+,(a1)+
		dbeq	d0,.loop
		clr.b	(a1)+	; stop

		move.l	a7,a0

		moveq	#100,d1
		moveq	#RECOVERY_ALERT,d0
		jsr	_LVODisplayAlert(a6)
		lea	256(a7),a7

		bra	.close_int

.alert		move.l	alertnumber(pc),d7
		jmp	_LVOAlert(a6)

.pop		popm	a0/a2/a3/a6
		rts

.intname	dc.b	"intuition.library",0
		even

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
		; gives	d0	*string new, must be freed with Mfree()
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

.template	dc.b	"Failed to load %s with at least version %ld.",0
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

program
