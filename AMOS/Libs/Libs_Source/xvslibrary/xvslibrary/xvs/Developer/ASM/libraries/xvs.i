	IFND	LIBRARIES_XVS_I
LIBRARIES_XVS_I	SET	1

**
**	$VER: xvs.i 33.37 (01.11.2001)
**
**	Copyright © 1997-2001 by Georg Hörmann
**	All Rights Reserved
**

	IFND EXEC_LIBRARIES_I
	include "exec/libraries.i"
	include "exec/lists.i"
	ENDC

;======================================================================
; Library Base
;======================================================================

; xvsBase structure has become completely private with version 33.37 !!
; For compatibility reasons, the fields that were not marked PRIVATE in
; the original structure are guaranteed to be there in all the future
; versions too. But please don't use this stuff in new code any longer!
xvs_DosBase	equ	40
xvs_ExecBase	equ	44

XVS_VERSION	equ	33	;for OpenLibrary()

XVS_NAME	MACRO
		dc.b	"xvs.library",0
		ENDM

;======================================================================
; Virus List
;======================================================================

    STRUCTURE	xvsVirusList,LH_SIZE
	UWORD	xvsvl_Count		; amount of entries
	LABEL	xvsVirusList_SIZE

; values for xvsVirusList->LH_TYPE and xvsCreateVirusList()

XVSLIST_BOOTVIRUSES	equ	$42
XVSLIST_DATAVIRUSES	equ	$44	; (V33.34)
XVSLIST_FILEVIRUSES	equ	$46
XVSLIST_LINKVIRUSES	equ	$4c

;======================================================================
; Object Types
;======================================================================

XVSOBJ_BOOTINFO		equ	1	; xvsBootInfo structure
XVSOBJ_SECTORINFO	equ	2	; xvsSectorInfo structure
XVSOBJ_FILEINFO		equ	3	; xvsFileInfo structure
XVSOBJ_MEMORYINFO	equ	4	; xvsMemoryInfo structure
XVSOBJ_MAX		equ	4	; PRIVATE

;======================================================================
; Bootblock Info
;======================================================================

    STRUCTURE	xvsBootInfo,0
	APTR	xvsbi_Bootblock		; buffer holding bootblock
	APTR	xvsbi_Name		; description of bootblock
	UBYTE	xvsbi_BootType		; type of bootblock
	UBYTE	xvsbi_DosType		; dos type (eg. DOS0 -> 0)
	UBYTE	xvsbi_ChkSumFlag	; TRUE if checksum correct
	UBYTE	xvsbi_Reserved0		; PRIVATE
	LABEL	xvsBootInfo_SIZE

; values for xvsBootInfo->xvsbi_BootType and xvsInstallBootblock()

XVSBT_UNKNOWN		equ	0	; Unknown bootblock
XVSBT_NOTDOS		equ	1	; Not a DOS bootblock
XVSBT_STANDARD13	equ	2	; Standard bootblock (1.3)
XVSBT_STANDARD20	equ	3	; Standard bootblock (2.0)
XVSBT_VIRUS		equ	4	; xvsbi_Name = virus name
XVSBT_UNINSTALLED	equ	5	; ONLY xvsInstallBootblock()

;======================================================================
; Sector Info
;======================================================================

    STRUCTURE	xvsSectorInfo,0
	APTR	xvssi_Sector		; buffer holding sector
	ULONG	xvssi_Key		; sector number
	APTR	xvssi_Name		; description of sector
	UBYTE	xvssi_SectorType	; type of sector
	UBYTE	xvssi_InternalType	; PRIVATE
	LABEL	xvsSectorInfo_SIZE

; values for xvsSectorInfo->xvssi_SectorType

XVSST_UNKNOWN		equ	0	; Unknown sector
XVSST_DESTROYED		equ	1	; xvssi_Name = virus name
XVSST_INFECTED		equ	2	; xvssi_Name = virus name

;======================================================================
; File Info
;======================================================================

    STRUCTURE	xvsFileInfo,0
	APTR	xvsfi_File		; buffer holding whole file
	ULONG	xvsfi_FileLen		; length of file
	APTR	xvsfi_Name		; description of file
	UBYTE	xvsfi_FileType		; type of file
	UBYTE	xvsfi_ModifiedFlag	; TRUE if file was modified
	UBYTE	xvsfi_ErrorCode		; only for xvsRepairFile()
	UBYTE	xvsfi_InternalType	; PRIVATE
	APTR	xvsfi_Fixed		; start of fixed file
	ULONG	xvsfi_FixedLen		; length of fixed file
	LABEL	xvsFileInfo_SIZE

; values for xvsFileInfo->xvsfi_FileType

XVSFT_EMPTYFILE		equ	1	; Empty file
XVSFT_DATAFILE		equ	2	; Data file
XVSFT_EXEFILE		equ	3	; Executable file
XVSFT_DATAVIRUS		equ	4	; xvsfi_Name = virus name
XVSFT_FILEVIRUS		equ	5	; xvsfi_Name = virus name
XVSFT_LINKVIRUS		equ	6	; xvsfi_Name = virus name

; values for xvsFileInfo->xvsfi_ErrorCode

XVSERR_WRONGFILETYPE	equ	1	; Wrong type of file
XVSERR_FILETRUNCATED	equ	2	; File truncated
XVSERR_UNSUPPORTEDHUNK	equ	3	; Unsupported hunk
XVSERR_UNEXPECTEDDATA	equ	4	; Unexpected data
XVSERR_OUTOFMEMORY	equ	5	; Out of memory
XVSERR_NOTIMPLEMENTED	equ	6	; (V33.15) Not implemented yet

;======================================================================
; Memory Info
;======================================================================

    STRUCTURE	xvsMemoryInfo,0
	UWORD	xvsmi_Count		; amount of detected viruses
	UWORD	xvsmi_Reserved0		; PRIVATE
	STRUCT	xvsmi_NameArray,5*4	; names of viruses
	LABEL	xvsMemoryInfo_SIZE


	ENDC	; LIBRARIES_XVS_I
