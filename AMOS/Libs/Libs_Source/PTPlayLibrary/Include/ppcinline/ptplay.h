/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PTPLAY_H
#define _PPCINLINE_PTPLAY_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PTPLAY_BASE_NAME
#define PTPLAY_BASE_NAME PtPlayBase
#endif /* !PTPLAY_BASE_NAME */

#define PtInit(__p0, __p1, __p2, __p3) \
	LP4(30, struct PlayMod *, PtInit, \
		UBYTE *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		ULONG , __p3, d2, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PtRender(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(36, PtRender, \
		struct PlayMod *, __p0, a0, \
		BYTE *, __p1, a1, \
		BYTE *, __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		LONG , __p5, d2, \
		LONG , __p6, d3, \
		LONG , __p7, d4, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PtTest(__p0, __p1, __p2) \
	LP3(42, ULONG  VOID					PtCleanup	(struct PlayMod *mod), PtTest, \
		STRPTR , __p0, a0, \
		UBYTE *, __p1, a1, \
		LONG , __p2, d0, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PtSeek(__p0, __p1) \
	LP2(66, ULONG , PtSeek, \
		VOID *, __p0, a0, \
		ULONG , __p1, d0, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PtSetAttrs(__p0, __p1) \
	LP2NR(54, PtSetAttrs, \
		struct PlayMod *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PtGetAttr(__p0, __p1, __p2) \
	LP3(60, ULONG , PtGetAttr, \
		struct PlayMod *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		, PTPLAY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_PTPLAY_H */
