;---------------------------------------------------------------------
;    **   **   **  ***   ***   ****     **    ***  **  ****
;   ****  *** *** ** ** **     ** **   ****  **    ** **  **
;  **  ** ** * ** ** **  ***   *****  **  **  ***  ** **
;  ****** **   ** ** **    **  **  ** ******    ** ** **
;  **  ** **   ** ** ** *  **  **  ** **  ** *  ** ** **  **
;  **  ** **   **  ***   ***   *****  **  **  ***  **  ****
;---------------------------------------------------------------------
; Serial extension source code, V1.1
; By François Lionet
; AMOS and AMOS Compiler (c) Europress Software 1991
; To be used with AMOS1.3 and over
;--------------------------------------------------------------------- 
; This file is public domain
;---------------------------------------------------------------------
;
; Please refer to the _Music.s file for more informations...
;
;---------------------------------------------------------------------
*
Version		MACRO
		dc.b	"1.2"
		ENDM
*
		XREF		_LVOOpenDevice
		XREF		_LVOCloseDevice
		XREF		_LVOCheckIO
		XREF		_LVOWaitIO
		XREF		_LVOAbortIO
		XREF		_LVOSendIO
		XREF		_LVODoIO

* AMIGA's includes
		INCDIR		":Includes/I/"
		INCLUDE		"Exec/Types.I"
		INCLUDE		"Exec/Exec.I"
		INCLUDE 	"Devices/Serial.I"

*************** AMOS includes
ExtNb		equ	6-1

		INCDIR		":AMOS1.3/Comp/"
 		Include	"_Equ.s"
		RsSet	DataLong
		Include "_Pointe.s"
		Include	"_WEqu.s"
		Include "_CEqu.s"
		Include	"_LEqu.s"

Dlea		MACRO
		move.l	ExtAdr+ExtNb*16(a5),\2
		add.w	#\1-DT,\2
		ENDM
Dload		MACRO
		move.l	ExtAdr+ExtNb*16(a5),\1
		ENDM

* Number of serial channels allowed
NSerial		equ	4

******************************************************************
*	Header
Start	dc.l	C_Tk-C_Off
	dc.l	C_Lib-C_Tk
	dc.l	C_Title-C_Lib
	dc.l	C_End-C_Title
	dc.w	0	

******************************************************************
*	Offsets to library
C_Off   dc.w (L1-L0)/2,(L2-L1)/2,(L3-L2)/2,(L4-L3)/2
        dc.w (L5-L4)/2,(L6-L5)/2,(L7-L6)/2,(L8-L7)/2
        dc.w (L9-L8)/2,(L10-L9)/2,(L11-L10)/2,(L12-L11)/2
        dc.w (L13-L12)/2,(L14-L13)/2,(L15-L14)/2,(L16-L15)/2
        dc.w (L17-L16)/2,(L18-L17)/2,(L19-L18)/2,(L20-L19)/2
        dc.w (L21-L20)/2,(L22-L21)/2,(L23-L22)/2,(L24-L23)/2
        dc.w (L25-L24)/2,(L26-L25)/2,(L27-L26)/2,(L28-L27)/2
        dc.w (L29-L28)/2,(L30-L29)/2,(L31-L30)/2,(L32-L31)/2
        dc.w (L33-L32)/2,(L34-L33)/2,(L35-L34)/2

******************************************************************
*	TOKEN TABLE
C_Tk	dc.w 	1,0
	dc.b 	$80,-1
	dc.w	L_SerOp2,-1
	dc.b	"!serial ope","n"+$80,"I0,0",-2
	dc.w	L_SerOp5,-1
	dc.b	$80,"I0,0,0,0,0",-1
	dc.w	L_SerClo0,-1
	dc.b	"!serial clos","e"+$80,"I",-2
	dc.w	L_SerClo1,-1
	dc.b	$80,"I0",-1
	dc.w	L_SerSp,-1
	dc.b	"serial spee","d"+$80,"I0,0",-1
	dc.w	-1,L_SerChk
	dc.b	"serial chec","k"+$80,"00",-1
	dc.w 	L_SerSend,-1
	dc.b	"serial sen","d"+$80,"I0,2",-1
	dc.w 	L_SerSp,-1
	dc.b	"serial spee","d"+$80,"I0,0",-1
	dc.w 	L_SerBit,-1
	dc.b	"serial bit","s"+$80,"I0,0,0",-1
	dc.w 	L_SerX,-1
	dc.b	"serial ","x"+$80,"I0,0",-1
	dc.w 	L_SerBuf,-1
	dc.b	"serial bu","f"+$80,"I0,0",-1
	dc.w 	L_SerPar,-1
	dc.b	"serial parit","y"+$80,"I0,0",-1
	dc.w	-1,L_SerGet
	dc.b	"serial ge","t"+$80,"00",-1
	dc.w	-1,L_SerInp
	dc.b	"serial input","$"+$80,"20",-1
	dc.w	L_SerFast,-1
	dc.b	"serial fas","t"+$80,"I0",-1
	dc.w	L_SerSlow,-1
	dc.b	"serial slo","w"+$80,"I0",-1
	dc.w	-1,L_SerE
	dc.b	"serial erro","r"+$80,"00",-1
	dc.w	L_SerOut,-1
	dc.b	"serial ou","t"+$80,"I0,0,0",-1
	dc.w	0
C_Lib

******************************************************************
*		COLD START
L0	movem.l	a3-a6,-(sp)
	lea	DT(pc),a3
	move.l	a3,ExtAdr+ExtNb*16(a5)
	lea	SerDef(pc),a0
	move.l	a0,ExtAdr+ExtNb*16+4(a5)
	lea	SerEnd(pc),a0
	move.l	a0,ExtAdr+ExtNb*16+8(a5)
	movem.l	(sp)+,a3-a6
	moveq	#ExtNb,d0		* NO ERRORS
	rts

******* SCREEN RESET
SerDef	
******* QUIT
SerEnd	Rbra	L_SCloseA

*************** Data zone
DT
SerialIO	ds.l	NSerial*2
BufIn		dc.l	0
		dc.l	0
SerName		SERIALNAME
		even

L1
L2

***********************************************************
*	OPEN SERIAL DEVICE

******* Seropen logicnumber,physicnumber[,shared,xdisabled,7wires]	
L_SerOp2	equ	3
L3	clr.l	-(a3)
	clr.l	-(a3)
	clr.l	-(a3)
	Rbra	L_SerOp5
L_SerOp5	equ	4
L4	movem.l	a4-a6,-(sp)
	move.l	16(a3),d0
	Rbsr	L_GetSerial
	tst.l	(a2)
	Rbne	L_SerAOp
; Opens communication port
	clr.l	-(sp)
	clr.l	-(sp)
	moveq	#0,d0
	Rbsr	L_Amiga.Lib
	addq.l	#8,sp
	move.l	d0,4(a2)
	Rbeq	L_SerOpE
; Opens IO structure
	move.l	#IOEXTSER_SIZE,-(sp)
	move.l	d0,-(sp)
	moveq	#2,d0
	Rbsr	L_Amiga.Lib
	addq.l	#8,sp
	move.l	d0,(a2)
	Rbeq	L_SerOpE
; Opening parameters
	move.l	d0,a1
	tst.l	(a3)+
	beq.s	SerOpA
	bset	#SERB_7WIRE,IO_SERFLAGS(a1)
SerOpA	bset	#SERB_XDISABLED,IO_SERFLAGS(a1)
	tst.l	(a3)+
	beq.s	SerOpB
	bclr	#SERB_XDISABLED,IO_SERFLAGS(a1)
SerOpB  tst.l	(a3)+
	beq.s	SerOpC
	bset	#SERB_SHARED,IO_SERFLAGS(a1)
SerOpC	
	Dlea	SerName,a0
	move.l	(a3),d0
	moveq	#0,d1
	move.l	$4.w,a6
	jsr	_LVOOpenDevice(a6)
	tst.l	d0
	Rbne	L_SerOpE
	bset	#7,4(a2)
	move.l	(a3)+,d0
	addq.l	#4,a3
	beq.s	.PaSet
* If NOT user-serial (#0),
* default settings for French MINITEL: 1200/7/1 Stop/EVEN parity
	move.l	(a2),a1
	move.l	#1200,IO_BAUD(a1)
	move.b	#7,IO_READLEN(a1)
	move.b	#7,IO_WRITELEN(a1)
	move.b	#1,IO_STOPBITS(a1)
	bset	#SERB_XDISABLED,IO_SERFLAGS(a1)
	bset	#SERB_PARTY_ON,IO_SERFLAGS(a1)
	bclr	#SERB_PARTY_ODD,IO_SERFLAGS(a1)
	bclr	#SEXTB_MSPON,IO_EXTFLAGS+3(a1)
	bclr	#SEXTB_MARK,IO_EXTFLAGS+3(a1)
* Appelle le device au moins une fois! BUG!
.PaSet	move.l	(a2),a1
	Rbsr	L_Stpar
	movem.l	(sp)+,a4-a6
	rts

***********************************************************
*	Serclose [N]
L_SerClo1	equ	5
L5	move.l	(a3)+,d0
	Rbsr	L_GetSerial
	tst.l	(a2)
	Rbeq	L_SerNOp
	Rbne	L_SClose
;-----> Close ALL channels
L_SerClo0	equ	6	
L_SCloseA	equ	6
L6	Dlea	SerialIO,a2
	moveq	#NSerial-1,d2
SCloA1	Rbsr	L_SClose
	lea	8(a2),a2
	dbra	d2,SCloA1
	rts
;-----> Close channel A2
L_SClose	equ	7
L7	movem.l	a0-a6/d0-d7,-(sp)
	move.l	4.w,a6
; Close device
	bclr	#7,4(a2)
	beq.s	SClo1
	move.l	(a2),a1
	jsr	_LVOCheckIO(a6)
	tst.l	d0
	bne.s	.Skip
	move.l	(a2),a1
	jsr	_LVOAbortIO(a6)
.Skip	move.l	(a2),a1
	jsr	_LVOWaitIO(a6)
	move.l	(a2),a1
	jsr	_LVOCloseDevice(a6)
; Delete IO structure
SClo1	tst.l	(a2)
	beq.s	SClo2	
	move.l	(a2),-(sp)
	clr.l	(a2)	
	moveq	#3,d0
	Rbsr	L_Amiga.Lib
	addq.l	#4,sp
; Remove message port
SClo2	tst.l	4(a2)
	beq.s	SClo3
	move.l	4(a2),-(sp)
	clr.l	4(a2)
	moveq	#1,d0
	Rbsr	L_Amiga.Lib
	addq.l	#4,sp
SClo3	movem.l	(sp)+,d0-d7/a0-a6
	rts

***********************************************************
*	Serial Send ser,A$
L_SerSend	equ	8
L8	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.l	d1,a2
	moveq	#0,d0
	move.w	(a2)+,d0
	Rbeq	L_IFonc
	move.l	d0,IO_LENGTH(a1)
	move.l	a2,IO_DATA(a1)
	moveq	#CMD_WRITE,d0
	Rbra	L_DoSENDIO
***********************************************************
*	Serial Out ser,address,length
L_SerOut	equ	9
L9	move.l	(a3)+,d2
	Rbmi	L_IFonc
	Rbeq	L_IFonc
	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.l	d1,IO_DATA(a1)
	move.l	d2,IO_LENGTH(a1)
	moveq	#CMD_WRITE,d0
	Rbra	L_DoSENDIO
***********************************************************
*	=Serial Get(ser)
L_SerGet	equ	10
L10	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.w	#SDCMD_QUERY,d0
	Rbsr	L_DoDOIO
	moveq	#-1,d3
	move.l	IO_ACTUAL(a1),d0
	beq.s	SerINo
	Dlea	BufIn,a2
	move.l	a2,IO_DATA(a1)
	move.l	#1,IO_LENGTH(a1)
	moveq	#CMD_READ,d0
	Rbsr	L_DoDOIO
	moveq	#0,d3
	move.b	(a2),d3
SerINo	moveq	#0,d2
	rts
***********************************************************
*	=Serial Input$(Ser) 
L_SerInp	equ	11
L11	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	moveq	#SDCMD_QUERY,d0
	Rbsr	L_DoDOIO
	move.l	IO_ACTUAL(a1),d4
	beq.s	SInpNo
	cmp.l	#65530,d4
	Rbcc	L_IFonc
* Ask for string space...
	move.l	a1,-(sp)
	move.l	d4,d3
	and.w	#$FFFE,d3		* Only EVEN!
	addq.w	#2,d3
	Rjsr	L_Demande
	lea	2(a1,d3.w),a1
	move.l	a1,HiChaine(a5)
* Send to device...
	move.l	(sp)+,a1
	move.l	a0,d3
	move.w	d4,(a0)+
	move.l	a0,IO_DATA(a1)
	move.l	d4,IO_LENGTH(a1)
	moveq	#CMD_READ,d0
	Rbsr	L_DoDOIO
	moveq	#2,d2
	rts
* Nothing to return
SInpNo	move.l	ChVide(a5),d3		* Empty string
	moveq	#2,d2
	rts

***********************************************************
*	Serial Speed ser,baud
L_SerSp		equ	12
L12	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.l	d1,IO_BAUD(a1)
	Rbra	L_Stpar
L_Stpar		equ	13
L13	
	move.w	#SDCMD_SETPARAMS,d0
	Rbsr	L_DoDOIO
	Rbne	L_SerError
	rts
***********************************************************
*	Serial Bit ser,number,stop
L_SerBit	equ	14
L14	move.l	(a3)+,d2
	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.b	d1,IO_READLEN(a1)
	move.b	d1,IO_WRITELEN(a1)
	move.b	d2,IO_STOPBITS(a1)
	Rbra	L_Stpar
***********************************************************
*	Serial Parity ser,on/off/odd/even/mspon
L_SerPar	equ	15
L15	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	bclr	#SERB_PARTY_ON,IO_SERFLAGS(a1)
	bclr	#SERB_PARTY_ODD,IO_SERFLAGS(a1)
	bclr	#SEXTB_MSPON,IO_EXTFLAGS+3(a1)
	bclr	#SEXTB_MARK,IO_EXTFLAGS+3(a1)
; -1-> NO PARITY
	tst.w	d1
	bmi.s	.parX
; 0--> EVEN
	bne.s	.par1
	bset	#SERB_PARTY_ON,IO_SERFLAGS(a1)
	bra.s	.parX
; 1--> ODD
.par1	cmp.w	#1,d1
	bne.s	.par2
	bset	#SERB_PARTY_ON,IO_SERFLAGS(a1)
	bset	#SERB_PARTY_ODD,IO_SERFLAGS(a1)
	bra.s	.parX
; 2--> SPACE
.par2	cmp.w	#2,d1
	bne.s	.par3
	bset	#SEXTB_MSPON,IO_EXTFLAGS+3(a1)
	bra.s	.parX
; 3--> MARK
.par3	cmp.w	#3,d1
	bne.s	.parX
	bset	#SEXTB_MSPON,IO_EXTFLAGS+3(a1)
	bset	#SEXTB_MARK,IO_EXTFLAGS+3(a1)
; Envoie
.parX	Rbra	L_Stpar	
**********************************************************
*	Serial X ser,value
L_SerX		equ	16
L16	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	bset	#SERB_XDISABLED,IO_SERFLAGS(a1)
	cmp.l	#-1,d1
	Rbeq	L_Stpar
	bclr	#SERB_XDISABLED,IO_SERFLAGS(a1)
	move.l	d1,IO_CTLCHAR(a1)
	Rbra	L_Stpar
**********************************************************
*	Serial Buffer ser,length
L_SerBuf	equ	17
L17	move.l	(a3)+,d1
	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.l	d1,IO_RBUFLEN(a1)
	Rbra	L_Stpar
**********************************************************
*	Serial Fast ser
L_SerFast	equ	18
L18	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	bclr	#SERB_PARTY_ON,IO_SERFLAGS(a1)
	bclr	#SEXTB_MSPON,IO_EXTFLAGS+3(a1)
	bset	#SERB_XDISABLED,IO_SERFLAGS(a1)
	move.b	#8,IO_READLEN(a1)
	move.b	#8,IO_WRITELEN(a1)
	bset	#SERB_RAD_BOOGIE,IO_SERFLAGS(a1)
	Rbra	L_Stpar
**********************************************************
*	Serial Slow Ser
L_SerSlow	equ	19
L19	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	bclr	#SERB_RAD_BOOGIE,IO_SERFLAGS(a1)
	Rbra	L_Stpar
**********************************************************
*	=Serial Check(N)
L_SerChk	equ	20
L20	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	move.l	a6,-(sp)
	move.l	$4.w,a6
	jsr	_LVOCheckIO(a6)
	move.l	(sp)+,a6
	move.l	d0,d3
	beq.s	SerChk1
	moveq	#-1,d3
SerChk1	moveq	#0,d2	
	rts
**********************************************************
*	=Serial Error(n)
L_SerE		equ	21
L21	move.l	(a3)+,d0
	Rbsr	L_GetSerA1
	moveq	#0,d3
	move.b	IO_ERROR(a1),d3
	moveq	#0,d2
	rts

* DOIO function
L_DoDOIO	equ	22
L22	movem.l	a1/a2/a6,-(sp)
	move.w	d0,IO_COMMAND(a1)
	move.l	$4.w,a6
	jsr	_LVODoIO(a6)
	tst.l	d0
	movem.l	(sp)+,a1/a2/a6
	rts
* SENDIO function
L_DoSENDIO	equ	23
L23	movem.l	a1/a2/a6,-(sp)
	move.w	d0,IO_COMMAND(a1)
	move.l	$4.w,a6
	jsr	_LVOSendIO(a6)
	tst.l	d0
	movem.l	(sp)+,a1/a2/a6
	rts
	
;-----> IO #D0 to A1/a2
L_GetSerA1	equ	24
L24	move.l	d0,-(sp)
	Rbsr	L_GetSerial
	move.l	(a2),d0
	Rbeq	L_SerNOp
	move.l	d0,a1
	move.l	(sp)+,d0
	rts
;-----> Find IO address > D0
L_GetSerial	equ	25
L25	cmp.l	#NSerial,d0
	Rbcc	L_IFonc
	lsl.w	#3,d0
	Dlea	SerialIO,a2
	add.w	d0,a2
	rts

*********************************************************************
*	AMIGA.LIB linked code. 
*	In order to make it relocatable, I have been
*	obliged to disassemble the code and include it in this 
*	routine.
L_Amiga.Lib	equ	26
L26	lsl.w	#2,d0
	lea	JJJmp(pc),a0
	jmp	0(a0,d0.w)
JJJmp	bra	_CreatePort
	bra	_DeletePort
	bra	_CreateExtIO
	bra	_DeleteExtIO

_CreatePort
	MOVEM.L	D2-7/A2,-(A7)
	MOVE.L	$20(A7),D4
	MOVE.B	$27(A7),D3
	MOVE.L	#$FFFFFFFF,-(A7)
	BSR	L7C7DB14
	MOVE.L	D0,D5
	MOVE.L	D5,D6
	MOVEQ	#-1,D2
	CMP.L	D5,D2
	ADDQ.L	#4,A7
	BNE.S	L7C7D97A
	MOVEQ	#0,D0
	BRA	L7C7D9E6
L7C7D97A	MOVE.L	#$10001,-(A7)
	PEA	$22.W
	BSR	L7C7DAD0
	MOVEA.L	D0,A2
	EXG	D7,A2
	TST.L	D7
	EXG	D7,A2
	ADDQ.L	#8,A7
	BNE.S	L7C7D9A4
	MOVE.L	D6,-(A7)
	BSR	L7C7DB28
	MOVEQ	#0,D0
	ADDQ.L	#4,A7
	BRA.S	L7C7D9E6
L7C7D9A4	MOVE.L	D4,$A(A2)
	MOVE.B	D3,9(A2)
	MOVE.B	#4,8(A2)
	CLR.B	$E(A2)
	MOVE.B	D6,$F(A2)
	CLR.L	-(A7)
	BSR	L7C7DB00
	MOVE.L	D0,$10(A2)
	TST.L	D4
	ADDQ.L	#4,A7
	BEQ.S	L7C7D9D8
	MOVE.L	A2,-(A7)
	BSR	L7C7DB3C
	ADDQ.L	#4,A7
	BRA.S	L7C7D9E4
L7C7D9D8	PEA	$14(A2)
	BSR	_NewList
	ADDQ.L	#4,A7
L7C7D9E4	MOVE.L	A2,D0
L7C7D9E6	MOVEM.L	(A7)+,D2-7/A2
	RTS

_DeletePort
	MOVEM.L	D2/A2,-(A7)
	MOVEA.L	$C(A7),A2
	TST.L	$A(A2)
	BEQ.S	L7C7DA04
	MOVE.L	A2,-(A7)
	BSR	L7C7DB50
	ADDQ.L	#4,A7
L7C7DA04	MOVE.B	#$FF,8(A2)
	MOVEQ	#-1,D2
	MOVE.L	D2,$14(A2)
	MOVEQ	#0,D2
	MOVE.B	$F(A2),D2
	MOVE.L	D2,-(A7)
	BSR	L7C7DB28
	PEA	$22.W
	MOVE.L	A2,-(A7)
	BSR	L7C7DAE8
	LEA	$C(A7),A7
	MOVEM.L	(A7)+,D2/A2
	RTS
_CreateExtIO
	MOVEM.L	D2-4,-(A7)
	MOVE.L	$10(A7),D2
	MOVE.L	$14(A7),D3
	TST.L	D2
	BNE.S	L7C7DA54
	MOVEQ	#0,D0
	BRA.S	L7C7DA82
L7C7DA54	MOVE.L	#$10001,-(A7)
	MOVE.L	D3,-(A7)
	BSR	L7C7DAD0
	MOVEA.L	D0,A0
	EXG	D4,A0
	TST.L	D4
	EXG	D4,A0
	ADDQ.L	#8,A7
	BNE.S	L7C7DA72
	MOVEQ	#0,D0
	BRA.S	L7C7DA82
L7C7DA72	MOVE.B	#5,8(A0)
	MOVE.W	D3,$12(A0)
	MOVE.L	D2,$E(A0)
	MOVE.L	A0,D0
L7C7DA82	MOVEM.L	(A7)+,D2-4
	RTS

_DeleteExtIO
	MOVEM.L	D2-3,-(A7)
	MOVEA.L	$C(A7),A0
	EXG	D3,A0
	TST.L	D3
	EXG	D3,A0
	BEQ	L7C7DABE
	MOVE.B	#$FF,8(A0)
	MOVEQ	#-1,D2
	MOVE.L	D2,$14(A0)
	MOVEQ	#-1,D2
	MOVE.L	D2,$18(A0)
	MOVEQ	#0,D2
	MOVE.W	$12(A0),D2
	MOVE.L	D2,-(A7)
	MOVE.L	A0,-(A7)
	BSR	L7C7DAE8
	ADDQ.L	#8,A7
L7C7DABE	MOVEM.L	(A7)+,D2-3
	RTS
L7C7DAD0
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVEM.L	8(A7),D0-1
	JSR	-$C6(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DAE8
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVEA.L	8(A7),A1
	MOVE.L	$C(A7),D0
	JSR	-$D2(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DB00
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVEA.L	8(A7),A1
	JSR	-$126(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DB14
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVE.L	8(A7),D0
	JSR	-$14A(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DB28
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVE.L	8(A7),D0
	JSR	-$150(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DB3C
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVEA.L	8(A7),A1
	JSR	-$162(A6)
	MOVEA.L	(A7)+,A6
	RTS
L7C7DB50
	MOVE.L	A6,-(A7)
	MOVEA.L	$4.w,A6
	MOVEA.L	8(A7),A1
	JSR	-$168(A6)
	MOVEA.L	(A7)+,A6
	RTS
_NewList
	move.l	4(a7),a0
	move.l	a0,(a0)
	addq.l	#4,(a0)
	clr.l	4(a0)
	move.l	a0,8(a0)
	rts

L27
L28
*********************************************************************
*	ERRORS
L_SerOpE	equ	29
L_IFonc		equ	29
L29	moveq	#23,d0			* Illegal function call
	Rjmp	L_Error
******* Custom errors
L_SerNOp	equ	30	
L30	moveq	#16,d0
	Rbra	L_Custom
L_SerAOp	equ	31
L31	moveq	#17,d0
	Rbra	L_Custom
* General serial error
L_SerError	equ	32
L32	subq.l	#1,d0
	cmp.l	#16,d0
	Rbcs	L_Custom
	moveq	#18,d0
	Rbra	L_Custom

******* Main routine.
L_Custom	equ	33
L33	lea	ErrMess(pc),a0
	moveq	#0,d1			* Can be trapped
	moveq	#ExtNb,d2		* Number of extension
	moveq	#0,d3			* IMPORTANT!!!
	Rjmp	L_ErrorExt		* Jump to routine...
ErrMess
	dc.b	"Device already in use",0		* 0
	dc.b	0					* 1
	dc.b	"Invalid baud rate",0			* 2
	dc.b	"Out of memory (serial device)",0	* 3
	dc.b	"Bad parameter",0			* 4
	dc.b	"Hardware data overrun",0		* 5
	dc.b 	0					* 6
	dc.b	0					* 7
	dc.b	0					* 8
	dc.b	0					* 9
	dc.b	"Timer error",0				* 10
	dc.b	"Buffer overflow",0			* 11
	dc.b	"No data set ready",0			* 12
	dc.b	"No clear to send",0			* 13
	dc.b	0					* 14
	dc.b	0					* 15		
	dc.b	"Serial port not opened",0		* 16	
	dc.b	"Serial port already opened",0		* 17
	dc.b	"Serial error",0			* 18
	even

******* "No errors" routine
L34	moveq	#0,d1
	moveq	#ExtNb,d2
	moveq	#-1,d3
	Rjmp	L_ErrorExt
L35
*********************************************************************

******* TITLE MESSAGE
C_Title	dc.b	31,"Serial extension V "
	Version
	dc.b	0,"$VER: "
	Version
	dc.b	0
	Even

******* END OF THE EXTENSION
C_End	dc.w	0
	even
