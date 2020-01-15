****************************************************************************
* Listview Hooks  -  An example of MUI assembler hook functions            *
****************************************************************************
*
* This file provides 2 routines for use with the Poplist.mui class.
*
* One copies the selected list entry into the string gadget when the popup
* is closed. The other find the string in the listview, and selects it when
* the popup is opened.
*
*
* This file is assembled & Ploaded into bank 32 of the MUI-Support.AMOS
* program for use with the _MUIB_LISTSTRING procedure.
*

	include MUI-Hook-Functions.i

*
* Change this to your system include dir:
*
	incdir	dta:Sys/include
	
	include	intuition/intuition_lib.i
	include	libraries/mui.i



*
* Jump table
*


	bra	hook_List_To_String
	bra	hook_String_In_List


****************************************************************************
* This hook copies the active entry from a listview into a string gadget.
*

hook_List_To_String:


*PRE: A1=StringObj
*PRE: A2=ListViewObj

	movem.l	a1,-(sp)	
	move.l 	-4(a2),a0 	;A0=CLASS
	move.l 	8(a0),a3  	;A3=DISPATCHER
	lea 	tag_getactive(pc),a1
	move.l	a1,d0
	add.l	#16,d0
	move.l	d0,8(a1)	;Get active entry directly to other taglist!
	jsr	(a3)
	movem.l	(sp)+,a0
	lea	tag_setstring(pc),a1
	move.l	#MUIA_String_Contents,(a1) ;SetAttrsA damages taglist!
	jsr	_LVOSetAttrsA(a6)
	moveQ	#1,d0		;MUI_TRUE
	rts
	

*
*Taglists.
*

tag_getactive

		dc.l	MUIM_List_GetEntry
		dc.l	MUIV_List_GetEntry_Active	
		dc.l	0				;Pointer to active_entry	

tag_setstring	dc.l	MUIA_String_Contents
active_entry	dc.l	0				



****************************************************************************		
* This hook scans a listview gadget for the string in a string gadget, and
* activates it in the listview gadget if it is found.
*

hook_String_In_List:

*PRE: A1 = String Obj
*PRE: A2 = Listview Obj

		move.l	a2,-(sp)		;Stack Listview object
		move.l	a1,a0

		move.l	#MUIA_String_Contents,d0
		lea	search_string(pc),a1
		jsr	_LVOGetAttr(a6)		;get the string to search for.
						;into longword (A1)

		move.l	(sp),a2			;Prepare DoMethod & StrCmp
		move.l	-4(a2),a0
		move.l	8(a0),a3		;A3 = List_GetEntry Dispatcher
		lea	search_tags(pc),a1      ;A1 = GetEntry Taglist
		lea	test_string(pc),a4	;A3 = Listview Entry Pointer Address
		lea	search_string(pc),a5	;A5 = String Pointer Address
		moveQ	#0,d0
		tst.l	(a5)
		beq.s	.emptystring	;String gadget is empty
		move.l	(a5),a5		;A5 = Pointer to string gadget contents
		move.l	a4,8(a1)	;A4 = Address to store pointer to list entry
		movem.l	a0-5,-(sp)

.nextentry	movem.l	(sp),a0-5 ;Restore a0-5 as above
		move.l	d0,4(a1)  ;D0=List Entry No. To get (put in taglist)
		move.l	d0,-(sp)
		jsr	(a3)	  ;Get next entry
		move.l	(sp)+,d0
		movem.l	(sp),a0-5 ;Restore a0-5
		tst.l	(a4)      ;Is this the end of the list?
		beq.s	.notinlist ;Yes!
		move.l	(a4),a4	  ;A4=List entry string

	;Now a StrCmp between a4 & a5
	
	.next	tst.b	(a4)
		beq.s	.s1end
		tst.b	(a5)
		beq.s	.fail	
		cmp.b	(a4)+,(a5)+	
		bne.s	.fail	
		bra.s	.next
			
	.s1end	tst.b	(a5)
		beq.s	.succeed
	
	.fail	addQ	#1,d0		;Didn't match - Get next entry
		bra.s	.nextentry

.notinlist	move.l	#MUIV_List_ActiveOff,d0	;String is not in the list,
						;so see turn off the active entry.

.succeed	movem.l	(sp)+,a0-a5	       ;Restore a0-5
.emptystring	move.l	(sp)+,a0	       ;A0=Listview Object
		lea	set_list(pc),a1	       ; change the active entry
		move.l	#MUIA_List_Active,(a1) ; SetAttrs damages taglist!
		move.l	d0,4(a1)               ;Put new active entry in taglist
		jsr	_LVOSetAttrsA(a6)
		moveQ	#1,d0		       ;Return Successful Open to MUI
		rts

*
* Data Pointers
*

search_string	dc.l	0
test_string	dc.l	0

*
*Taglists
*

search_tags	dc.l	MUIM_List_GetEntry
		dc.l	0
		dc.l	0


set_list	dc.l	MUIA_List_Active
		dc.l	0
