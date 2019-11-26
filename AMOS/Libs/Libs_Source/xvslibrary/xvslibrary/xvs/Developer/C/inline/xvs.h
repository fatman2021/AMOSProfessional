#ifndef _INLINE_XVS_H
#define _INLINE_XVS_H

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif

#ifndef XVS_BASE_NAME
#define XVS_BASE_NAME xvsBase
#endif

#define xvsSelfTest() \
	LP0(0x1e, BOOL, xvsSelfTest, \
	, XVS_BASE_NAME)

#define xvsCreateVirusList(listtype) \
	LP1(0x24, struct xvsVirusList *, xvsCreateVirusList, ULONG, listtype, d0, \
	, XVS_BASE_NAME)

#define xvsFreeVirusList(list) \
	LP1NR(0x2a, xvsFreeVirusList, struct xvsVirusList *, list, a1, \
	, XVS_BASE_NAME)

#define xvsAllocObject(objecttype) \
	LP1(0x30, APTR, xvsAllocObject, ULONG, objecttype, d0, \
	, XVS_BASE_NAME)

#define xvsFreeObject(object) \
	LP1NR(0x36, xvsFreeObject, APTR, object, a1, \
	, XVS_BASE_NAME)

#define xvsObjectType(object) \
	LP1(0x3c, ULONG, xvsObjectType, APTR, object, a1, \
	, XVS_BASE_NAME)

#define xvsCheckBootblock(bootinfo) \
	LP1(0x42, ULONG, xvsCheckBootblock, struct xvsBootInfo *, bootinfo, a0, \
	, XVS_BASE_NAME)

#define xvsInstallBootblock(bootblock, boottype, dostype) \
	LP3NR(0x48, xvsInstallBootblock, APTR, bootblock, a0, ULONG, boottype, d0, ULONG, dostype, d1, \
	, XVS_BASE_NAME)

#define xvsSumBootblock(bootblock, offset) \
	LP2NR(0x4e, xvsSumBootblock, APTR, bootblock, a0, ULONG, offset, d0, \
	, XVS_BASE_NAME)

#define xvsCheckSector(sectorinfo) \
	LP1(0x54, ULONG, xvsCheckSector, struct xvsSectorInfo *, sectorinfo, a0, \
	, XVS_BASE_NAME)

#define xvsRepairSector(sectorinfo) \
	LP1(0x5a, BOOL, xvsRepairSector, struct xvsSectorInfo *, sectorinfo, a0, \
	, XVS_BASE_NAME)

#define xvsCheckFile(fileinfo) \
	LP1(0x60, ULONG, xvsCheckFile, struct xvsFileInfo *, fileinfo, a0, \
	, XVS_BASE_NAME)

#define xvsRepairFile(fileinfo) \
	LP1(0x66, BOOL, xvsRepairFile, struct xvsFileInfo *, fileinfo, a0, \
	, XVS_BASE_NAME)

#define xvsSurveyMemory(memoryinfo) \
	LP1(0x6c, ULONG, xvsSurveyMemory, struct xvsMemoryInfo *, memoryinfo, a0, \
	, XVS_BASE_NAME)

#endif /*  _INLINE_XVS_H  */
