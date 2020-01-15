#ifndef CLIB_XVS_PROTOS_H
#define CLIB_XVS_PROTOS_H


/*
**	$VER: xvs_protos.h 33.37 (13.12.2001)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Georg Hörmann and Dirk Stöcker
**	All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_XVS_H
#include <libraries/xvs.h>
#endif

BOOL xvsSelfTest(void);
struct xvsVirusList * xvsCreateVirusList(ULONG listtype);
void xvsFreeVirusList(struct xvsVirusList * list);
APTR xvsAllocObject(ULONG objecttype);
void xvsFreeObject(APTR object);
ULONG xvsObjectType(APTR object);
ULONG xvsCheckBootblock(struct xvsBootInfo * bootinfo);
void xvsInstallBootblock(APTR bootblock, ULONG boottype, ULONG dostype);
void xvsSumBootblock(APTR bootblock, ULONG offset);
ULONG xvsCheckSector(struct xvsSectorInfo * sectorinfo);
BOOL xvsRepairSector(struct xvsSectorInfo * sectorinfo);
ULONG xvsCheckFile(struct xvsFileInfo * fileinfo);
BOOL xvsRepairFile(struct xvsFileInfo * fileinfo);
ULONG xvsSurveyMemory(struct xvsMemoryInfo * memoryinfo);

#endif	/*  CLIB_XVS_PROTOS_H  */
