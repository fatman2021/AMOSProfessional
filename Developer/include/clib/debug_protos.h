#ifndef CLIB_DEBUG_PROTOS_H
#define CLIB_DEBUG_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/debug/debug.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <dos/bptr.h>
#include <utility/tagitem.h>
#include <utility/hooks.h>

LONG KGetChar(VOID);
LONG KMayGetChar(VOID);
VOID KPutChar(LONG ch);
VOID KPutStr(CONST_STRPTR string);
VOID KDoFmt(CONST_STRPTR formatString, CONST APTR dataStream, CONST APTR putChProc, APTR putChData );
VOID KVPrintF( CONST_STRPTR formatString, CONST APTR values );
VOID KPrintF( CONST_STRPTR formatString, ... );

#define kgetc    KGetChar
#define kgetch   KGetChar
#define KGetCh   KGetChar
#define kgetchar KGetChar
#define kputc    KPutChar
#define kputch   KPutChar
#define KPutCh   KPutChar
#define kputchar KPutChar
#define kputs    KPutStr
#define KPutS    KPutStr
#define KPutFmt  KVPrintF

__BEGIN_DECLS


#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)
AROS_LP4(void, RegisterModule,
         AROS_LPA(const char *, name, A0),
         AROS_LPA(BPTR, segList, A1),
         AROS_LPA(ULONG, debugType, D0),
         AROS_LPA(APTR, debugInfo, A2),
         LIBBASETYPEPTR, DebugBase, 5, Debug
);

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)
AROS_LP1(void, UnregisterModule,
         AROS_LPA(BPTR, segList, A0),
         LIBBASETYPEPTR, DebugBase, 6, Debug
);

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)
AROS_LP2(int, DecodeLocationA,
         AROS_LPA(void *, addr, A0),
         AROS_LPA(struct TagItem *, tags, A1),
         LIBBASETYPEPTR, DebugBase, 7, Debug
);

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)
AROS_LP2(void, EnumerateSymbolsA,
         AROS_LPA(struct Hook *, handler, A0),
         AROS_LPA(struct TagItem *, tags, A1),
         LIBBASETYPEPTR, DebugBase, 8, Debug
);

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

__END_DECLS

#endif /* CLIB_DEBUG_PROTOS_H */
