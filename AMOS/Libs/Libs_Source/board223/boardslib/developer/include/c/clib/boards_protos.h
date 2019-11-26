#ifndef CLIB_BOARDS_PROTOS_H
#define CLIB_BOARDS_PROTOS_H

/*
**      $VER: boards_protos.h 2.0 (17.12.1997)
**	fixed by SDI
**
**      boards.library proto types
**
**      (C)1997 by Torsten Bach
**      All Rights Reserved.
*/

#include <libraries/boards.h>

/* boards protos */

ULONG GetBoardName(STRPTR, STRPTR, struct ConfigDev *, UWORD, UBYTE);
ULONG AllocBoardInfo(ULONG);
ULONG NextBoardInfo(struct BoardInfo *, struct ConfigDev *);
ULONG FreeBoardInfo(struct BoardInfo *);

#endif	/* CLIB_BOARDS_PROTOS_H */
