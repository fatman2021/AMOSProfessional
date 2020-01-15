/*
** mb_utils.h
** © 1998-1999 Matthias Bethke
**
** Link library with general purpose functions 
*/
#ifndef _COMMSIZE_H
#include <sys/commsize.h>
#endif

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif


char *mb_stristr(const char*, const char*);		// string_to_search, string_to_look_for
char *mb_strlimcpy(char*, const char*, size_t);	// destination, source, destsize
char *mb_strtok(char**, char*);						// string_to_search, break_characters
LONG mb_VNSPrintf(STRPTR,STRPTR,LONG,LONG*);		// destination, formatstring, length, argarray
LONG mb_VSPrintf(STRPTR, STRPTR, LONG*);			// destination, formatstring, argarray
LONG mb_SPrintf(STRPTR,STRPTR,...);					// destination, formatstring, arg, ...
void __asm *AllocVecPooled(register __a0 APTR, register __d0 ULONG);	// pool, size
void __asm FreeVecPooled(register __a0 APTR,register __a1 void*);		// pool, memblock
STRPTR mb_GetCurrentDirName(APTR);					// optional pool
STRPTR mb_GetProgramName(APTR);						// optional pool
STRPTR mb_NameFromLock(APTR,BPTR);					// optional pool, lock
ULONG DoSuperNew(struct IClass*, Object*, ULONG, ...);
STRPTR CloneString(APTR, STRPTR);					// optional pool, stringpointer
void FreeString(APTR, STRPTR);						// optional pool, stringpointer
STRPTR ConcatStrings(APTR, STRPTR, ...);			// optional pool, stringpointer, ...
struct DiskObject *ReadProgramIcon(APTR);			// optional pool
APTR AllocAligned(ULONG,ULONG,ULONG);				// size, alignment, memtype
