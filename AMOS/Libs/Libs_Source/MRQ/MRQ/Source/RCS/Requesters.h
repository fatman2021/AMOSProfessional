head	1.1;
access;
symbols;
locks
	msbethke:1.1; strict;
comment	@ * @;


1.1
date	2000.01.25.16.59.34;	author msbethke;	state Exp;
branches;
next	;


desc
@Stuff exported from Requesters.c
@


1.1
log
@Initial revision
@
text
@/* Requesters.h
** Stuff exported from Requesters.c
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id:$
**
** $Log:$
*/

LONG __asm __saveds EasyRequestArgsPatch(
	register __a0 struct Window*,
	register __a1 struct EasyStruct*,
	register __a2 ULONG*,
	register __a3 APTR);

ULONG __asm __saveds rtEZRequestAPatch(
	register __a1 char*,
	register __a2 char*,
	register __a3 struct rtReqInfo*,
	register __a5 APTR,
	register __a0 struct TagItem*);


BOOL MUI_EasyRequestArgs(struct MRQReqMessage*);
@
