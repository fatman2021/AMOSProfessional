	IFND LIBRARIES_MODIFYLE_I
LIBRARIES_MODIFYLE_I	SET	1

; $VER: modiflye.library
;
; -----------------------------------------------------
; m68k assembler includefile and developer informations
; -----------------------------------------------------
;
; 2012 by PseudoDOS/silva@psi5.com


	include exec/types.i
	include	exec/libraries.i


MFVERSION	= 1	; current modifyle version

MFNAME		MACRO
		dc.b	"modifyle.library",0
		ENDM


; ------------------------------------------------------
; FUNCTIONS - see ASL docs for parameters and structures
; ------------------------------------------------------

	LIBINIT



	; ASL compatible functions

	LIBDEF	_LVOAllocMFRequest	; d0: requester type
					; (only filerequester)
					; a0: ASL FR tags
					;>d0: requester struct

	LIBDEF	_LVOFreeMFRequest	; a0: requester struct
					; a1: ASL FR tags

	LIBDEF	_LVOMFRequest		; a0: requester structure
					;>d0: TRUE = something selected




	; NEW functions, not in ASL

	LIBDEF	_LVOMFManager		; a0: requester structure
					;>d0: FALSE = failed, otherwise the pointer
					;     to the requester is returned.

					; With MFManager() you can open the requester
					; as a file browser and manager, which has no
					; select/cancel buttons, but supports all
					; filemanagement functions (as also every
					; plain filerequester does).
					; You may open any number of Managers.

	LIBDEF	_LVOQuitMFRequest	; a0: Close the file manager (if not closed by user).
					;     Nota bene: not yet a FileRequester, only a Manager.


; the next two are yet only for INTERNAL use, do not call!

	LIBDEF	_LVOMFJob		; d0: command		Yet not implemented, DON'T call!
					; a0: tags
					;>d0: jobhandle

	LIBDEF	_LVOQuitMFJob		; a0: jobhandle		Yet not implemented, DON'T call!


; ------------------------------------------------------
; yet FUNCTIONAL ASL Tags - see ASL docs for description
; ------------------------------------------------------

;		ASLFR_TitleText
;		ASLFR_PositiveText
;		ASLFR_NegativeText
;		ASLFR_InitialLeftEdge
;		ASLFR_InitialTopEdge
;		ASLFR_InitialWidth
;		ASLFR_InitialHeight
;		ASLFR_InitialFile
;		ASLFR_InitialDrawer
;		ASLFR_InitialPattern
;		ASLFR_Flags1
;		ASLFR_Flags2
;		ASLFR_DrawersOnly
;		ASLFR_FilterDrawers
;		ASLFR_RejectIcons
;		ASLFR_DoSaveMode
;		ASLFR_DoPatterns
;		ASLFR_AcceptPattern
;		ASLFR_RejectPattern
;		ASLFR_UserData
;		ASLFR_DoMultiSelect
;		ASLFR_Window
;		ASLFR_SleepWindow

; ------------------------------------------------------
; extended Modifyle tags
; ------------------------------------------------------

		ENUM	TAG_USER+256

	; Modifyle Manager tags

	; If you use this optional signaling for when the user closes the MANAGER
	; you MUST provide a quitsigbit AND a sigtask. Before this happens, you may
	; quit the browser with _LVOMFQuitRequest,
	; too (and then not wait for your signal anymore).

	EITEM	MF_QuitSigBit		; send this signal when the manager or job is ready
	EITEM	MF_SigTask		; then signal this task


	; Modifyle Job Tags (INTERNAL USE ONLY)

		ENUM	TAG_USER+512

	EITEM	MFJ_ToDoArray		; read filenames pointer from this array (0 term.)
	EITEM	MFJ_FreePool		; free this mempool at end
	EITEM	MFJ_Dest
	EITEM	MFJ_Source
	EITEM	MFJ_NumToDo

; ------------------------------------------------------
; commands that can be passed to MFJob()
; ------------------------------------------------------

MFCMD_ABORT		= -1	; internal use
MFCMD_COPY		= 0
MFCMD_MOVE		= 1
MFCMD_DELETE		= 2
MFCMD_CLONE		= 3
MFCMD_MAKEDIR		= 4
MFCMD_RENAME		= 5

; This qualifier that means MFJ_ToDoArray is not a plain names pointers array
; but a WBArgs array (each element has two longs: lock, name).
; Directories appear not in the name part but appended in the lock. In this
; case argname points to an empty string.

MFCMDQUAL_FROMARGS	= $80000000

; end of includefile here  --- Zak McKracken 4 president! ---

	ENDC

