#ifndef LIBRARIES_XVS_H
#define LIBRARIES_XVS_H

/*
**	$VER: xvs.h 33.37 (01.11.2001)
**
**	Copyright © 1998-2001 by Georg Hörmann and Dirk Stöcker
**	All Rights Reserved
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

/************************************************************************
* Library Base								*
************************************************************************/

/* xvsBase structure has become completely private with version 33.37 !!
   For compatibility reasons, the fields that were not marked PRIVATE in
   the original structure are guaranteed to be there in all the future
   versions too. But please don't use this stuff in new code any longer!
*/
#define xvs_DosBase	40
#define xvs_ExecBase	44

#define	XVS_VERSION	33	/* for OpenLibrary() */
#define	XVS_NAME	"xvs.library"

/************************************************************************
* Virus List								*
************************************************************************/

struct xvsVirusList {
  struct List	xvsvl_List;
  UWORD		xvsvl_Count;	/* amount of entries */
};

/* values for xvsVirusList->xvsl_List.lh_Type and xvsCreateVirusList() */

#define XVSLIST_BOOTVIRUSES	0x42
#define XVSLIST_DATAVIRUSES	0x44	/* V33.34 */
#define XVSLIST_FILEVIRUSES	0x46
#define XVSLIST_LINKVIRUSES	0x4C

/************************************************************************
* Object Types								*
************************************************************************/

#define XVSOBJ_BOOTINFO		1	/* xvsBootInfo structure */
#define XVSOBJ_SECTORINFO	2	/* xvsSectorInfo structure */
#define XVSOBJ_FILEINFO		3	/* xvsFileInfo structure */
#define XVSOBJ_MEMORYINFO	4	/* xvsMemoryInfo structure */
#define XVSOBJ_MAX		4	/* PRIVATE */

/************************************************************************
* Bootblock Info							*
************************************************************************/

struct xvsBootInfo {
  APTR		xvsbi_Bootblock;	/* buffer holding bootblock */
  STRPTR	xvsbi_Name;		/* description of bootblock */
  UBYTE		xvsbi_BootType;		/* type of bootblock */
  UBYTE		xvsbi_DosType;		/* dos type (eg. DOS0 -> 0) */
  UBYTE		xvsbi_ChkSumFlag;	/* TRUE if checksum correct */
  UBYTE		xvsbi_Reserved0;	/* PRIVATE */
};

/* values for xvsBootInfo->xvsbi_BootType and xvsInstallBootblock() */

#define XVSBT_UNKNOWN		0	/* Unknown bootblock */
#define XVSBT_NOTDOS		1	/* Not a DOS bootblock */
#define XVSBT_STANDARD13	2	/* Standard bootblock (1.3) */
#define XVSBT_STANDARD20	3	/* Standard bootblock (2.0) */
#define XVSBT_VIRUS		4	/* xvsbi_Name = virus name */
#define XVSBT_UNINSTALLED	5	/* ONLY xvsInstallBootblock() */

/************************************************************************
* Sector Info								*
************************************************************************/

struct xvsSectorInfo {
  APTR		xvssi_Sector;		/* buffer holding sector */
  ULONG		xvssi_Key;		/* sector number */
  STRPTR	xvssi_Name;		/* description of sector */
  UBYTE 	xvssi_SectorType;	/* type of sector */
  UBYTE 	xvssi_InternalType;	/* PRIVATE */
};

/* values for xvsSectorInfo->xvssi_SectorType */

#define XVSST_UNKNOWN		0	/* Unknown sector */
#define XVSST_DESTROYED		1	/* xvssi_Name = virus name */
#define XVSST_INFECTED		2	/* xvssi_Name = virus name */

/************************************************************************
* File Info								*
************************************************************************/

struct xvsFileInfo {
  APTR		xvsfi_File;		/* buffer holding whole file */
  ULONG		xvsfi_FileLen;		/* length of file */
  STRPTR	xvsfi_Name;		/* description of file */
  UBYTE		xvsfi_FileType;		/* type of file */
  UBYTE		xvsfi_ModifiedFlag;	/* TRUE if file was modified */
  UBYTE		xvsfi_ErrorCode;	/* only for xvsRepairFile() */
  UBYTE		xvsfi_InternalType;	/* PRIVATE */
  APTR		xvsfi_Fixed;		/* start of fixed file */
  ULONG		xvsfi_FixedLen;		/* length of fixed file */
};

/* values for xvsFileInfo->xvsfi_FileType */

#define XVSFT_EMPTYFILE		1	/* Empty file */
#define XVSFT_DATAFILE		2	/* Data file */
#define XVSFT_EXEFILE		3	/* Executable file */
#define XVSFT_DATAVIRUS		4	/* xvsfi_Name = virus name */
#define XVSFT_FILEVIRUS		5	/* xvsfi_Name = virus name */
#define XVSFT_LINKVIRUS		6	/* xvsfi_Name = virus name */

/* values for xvsFileInfo->xvsfi_ErrorCode */

#define XVSERR_WRONGFILETYPE	1	/* Wrong type of file */
#define XVSERR_FILETRUNCATED	2	/* File truncated */
#define XVSERR_UNSUPPORTEDHUNK	3	/* Unsupported hunk */
#define XVSERR_UNEXPECTEDDATA	4	/* Unexpected data */
#define XVSERR_OUTOFMEMORY	5	/* Out of memory */
#define XVSERR_NOTIMPLEMENTED	6	/* (V33.15) Not implemented yet */

/************************************************************************
* Memory Info								*
************************************************************************/

struct xvsMemoryInfo {
  UWORD		xvsmi_Count;		/* amount of detected viruses */
  UWORD		xvsmi_Reserved0;	/* PRIVATE */
  STRPTR	xvsmi_NameArray[5];	/* names of viruses */
};

#endif /* LIBRARIES_XVS_H */
