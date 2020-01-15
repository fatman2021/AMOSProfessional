head	1.1;
access;
symbols;
locks
	msbethke:1.1; strict;
comment	@ * @;


1.1
date	2000.01.25.16.49.02;	author msbethke;	state Exp;
branches;
next	;


desc
@C header for MRQ's window subclass
@


1.1
log
@Initial revision
@
text
@/* mrqwindowclass.h
** C header for MRQ's window subclass
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id:$
**
** $Log:$
*/

struct MUI_CustomClass *NewMRQWindowClass(void);
@
