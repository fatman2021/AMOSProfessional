#ifndef _VBCCINLINE_XVS_H
#define _VBCCINLINE_XVS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

BOOL __xvsSelfTest(__reg("a6") struct Library *)="\tjsr\t-30(a6)";
#define xvsSelfTest() __xvsSelfTest(xvsBase)

struct xvsVirusList * __xvsCreateVirusList(__reg("a6") struct Library *, __reg("d0") ULONG listtype)="\tjsr\t-36(a6)";
#define xvsCreateVirusList(listtype) __xvsCreateVirusList(xvsBase, (listtype))

void __xvsFreeVirusList(__reg("a6") struct Library *, __reg("a1") struct xvsVirusList * list)="\tjsr\t-42(a6)";
#define xvsFreeVirusList(list) __xvsFreeVirusList(xvsBase, (list))

APTR __xvsAllocObject(__reg("a6") struct Library *, __reg("d0") ULONG objecttype)="\tjsr\t-48(a6)";
#define xvsAllocObject(objecttype) __xvsAllocObject(xvsBase, (objecttype))

void __xvsFreeObject(__reg("a6") struct Library *, __reg("a1") APTR object)="\tjsr\t-54(a6)";
#define xvsFreeObject(object) __xvsFreeObject(xvsBase, (object))

ULONG __xvsObjectType(__reg("a6") struct Library *, __reg("a1") APTR object)="\tjsr\t-60(a6)";
#define xvsObjectType(object) __xvsObjectType(xvsBase, (object))

ULONG __xvsCheckBootblock(__reg("a6") struct Library *, __reg("a0") struct xvsBootInfo * bootinfo)="\tjsr\t-66(a6)";
#define xvsCheckBootblock(bootinfo) __xvsCheckBootblock(xvsBase, (bootinfo))

void __xvsInstallBootblock(__reg("a6") struct Library *, __reg("a0") APTR bootblock, __reg("d0") ULONG boottype, __reg("d1") ULONG dostype)="\tjsr\t-72(a6)";
#define xvsInstallBootblock(bootblock, boottype, dostype) __xvsInstallBootblock(xvsBase, (bootblock), (boottype), (dostype))

void __xvsSumBootblock(__reg("a6") struct Library *, __reg("a0") APTR bootblock, __reg("d0") ULONG offset)="\tjsr\t-78(a6)";
#define xvsSumBootblock(bootblock, offset) __xvsSumBootblock(xvsBase, (bootblock), (offset))

ULONG __xvsCheckSector(__reg("a6") struct Library *, __reg("a0") struct xvsSectorInfo * sectorinfo)="\tjsr\t-84(a6)";
#define xvsCheckSector(sectorinfo) __xvsCheckSector(xvsBase, (sectorinfo))

BOOL __xvsRepairSector(__reg("a6") struct Library *, __reg("a0") struct xvsSectorInfo * sectorinfo)="\tjsr\t-90(a6)";
#define xvsRepairSector(sectorinfo) __xvsRepairSector(xvsBase, (sectorinfo))

ULONG __xvsCheckFile(__reg("a6") struct Library *, __reg("a0") struct xvsFileInfo * fileinfo)="\tjsr\t-96(a6)";
#define xvsCheckFile(fileinfo) __xvsCheckFile(xvsBase, (fileinfo))

BOOL __xvsRepairFile(__reg("a6") struct Library *, __reg("a0") struct xvsFileInfo * fileinfo)="\tjsr\t-102(a6)";
#define xvsRepairFile(fileinfo) __xvsRepairFile(xvsBase, (fileinfo))

ULONG __xvsSurveyMemory(__reg("a6") struct Library *, __reg("a0") struct xvsMemoryInfo * memoryinfo)="\tjsr\t-108(a6)";
#define xvsSurveyMemory(memoryinfo) __xvsSurveyMemory(xvsBase, (memoryinfo))

#endif /*  _VBCCINLINE_XVS_H  */
