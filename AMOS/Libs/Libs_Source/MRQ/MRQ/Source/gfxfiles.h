/* gfxfiles.h
** C header for MRQ's datatypes/guigfx routines
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: gfxfiles.h 1.1 2000/01/25 17:22:31 msbethke Exp msbethke $
**
** $Log: gfxfiles.h $
** Revision 1.1  2000/01/25 17:22:31  msbethke
** Initial revision
**
*/

BOOL PreloadImage(STRPTR,struct MRQImage*);
void FreePreloaded(struct MRQConfig*);
void ReadImageButtons(struct MRQConfig*);
void FreeImageButtons(struct MRQConfig*);
