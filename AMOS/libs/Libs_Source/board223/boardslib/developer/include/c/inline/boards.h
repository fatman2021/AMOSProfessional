/* Automatically generated header! Do not edit! */

#ifndef _INLINE_BOARDS_H
#define _INLINE_BOARDS_H

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef BOARDS_BASE_NAME
#define BOARDS_BASE_NAME BoardsBase
#endif /* !BOARDS_BASE_NAME */

#define AllocBoardInfo(BoardInfoFlags) \
	LP1(0x24, ULONG, AllocBoardInfo, ULONG, BoardInfoFlags, d0, \
	, BOARDS_BASE_NAME)

#define FreeBoardInfo(BoardInfo_) \
	LP1(0x30, ULONG, FreeBoardInfo, struct BoardInfo *, BoardInfo_, a0, \
	, BOARDS_BASE_NAME)

#define GetBoardName(ManuName, ProdName, Configdev, ManuID, ProdID) \
	LP5(0x1e, ULONG, GetBoardName, STRPTR, ManuName, a0, STRPTR, ProdName, a1, struct ConfigDev *, Configdev, a2, UWORD, ManuID, d0, UBYTE, ProdID, d1, \
	, BOARDS_BASE_NAME)

#define NextBoardInfo(BoardInfo_, Configdev) \
	LP2(0x2a, ULONG, NextBoardInfo, struct BoardInfo *, BoardInfo_, a0, struct ConfigDev *, Configdev, a1, \
	, BOARDS_BASE_NAME)

#endif /* !_INLINE_BOARDS_H */
