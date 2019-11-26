#ifndef _INCLUDE_PRAGMA_BOARDS_LIB_H
#define _INCLUDE_PRAGMA_BOARDS_LIB_H

#ifndef CLIB_BOARDS_PROTOS_H
#include <clib/boards_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(BoardsBase,0x01E,GetBoardName(a0,a1,a2,d0,d1))
#pragma amicall(BoardsBase,0x024,AllocBoardInfo(d0))
#pragma amicall(BoardsBase,0x02A,NextBoardInfo(a0,a1))
#pragma amicall(BoardsBase,0x030,FreeBoardInfo(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma libcall BoardsBase GetBoardName         01E 10A9805
#pragma libcall BoardsBase AllocBoardInfo       024 001
#pragma libcall BoardsBase NextBoardInfo        02A 9802
#pragma libcall BoardsBase FreeBoardInfo        030 801
#endif

#endif	/*  _INCLUDE_PRAGMA_BOARDS_LIB_H  */