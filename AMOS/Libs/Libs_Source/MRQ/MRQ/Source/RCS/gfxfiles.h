head	1.1;
access;
symbols;
locks
	msbethke:1.1; strict;
comment	@ * @;


1.1
date	2000.01.25.17.22.31;	author msbethke;	state Exp;
branches;
next	;


desc
@C header for MRQ's datatypes/guigfx routines
@


1.1
log
@Initial revision
@
text
@/* gfxfiles.h
** C header for MRQ's datatypes/guigfx routines
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id:$
**
** $Log:$
*/

BOOL PreloadImage(STRPTR,struct MRQImage*);
void FreePreloaded(struct MRQConfig*);
void ReadImageButtons(struct MRQConfig*);
void FreeImageButtons(struct MRQConfig*);
@
