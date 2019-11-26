/* MRQasm.h
** C header for MRQ's assembler functions
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: MRQasm.h 1.1 2000/01/25 16:47:14 msbethke Exp msbethke $
**
** $Log: MRQasm.h $
** Revision 1.1  2000/01/25 16:47:14  msbethke
** Initial revision
**
*/

void RDF_StuffChar();

struct StuffCharParams
{
	LONG	Position;
	LONG	DestLen;
	APTR	Dest;
};


ULONG __asm __saveds rtEZRequestA_Wedge(
	register __a1 char*,
	register __a2 char*,
	register __a3 struct rtReqInfo*,
	register __a4 APTR,
	register __a0 struct TagItem*);

ULONG __asm CallOldrtEZRA(
	register __a1 char*,
	register __a2 char*,
	register __a3 struct rtReqInfo*,
	register __a4 APTR,
	register __a0 struct TagItem*,
	register __a6 struct ReqToolsBase*);
	
LONG __asm CallOldERA(
	register __a0 struct Window*,
	register __a1 struct EasyStruct*,
	register __a2 ULONG*,
	register __a3 APTR,
	register __a6 struct IntuitionBase*);
