#ifndef DEFINES_CYBERGRAPHICS_H
#define DEFINES_CYBERGRAPHICS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/cgfx/cybergraphics.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for cybergraphics
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CYBERGRAPHICS_LIBBASE)
#    define __CYBERGRAPHICS_LIBBASE CyberGfxBase
#endif

__BEGIN_DECLS


#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __IsCyberModeID_WB(__CyberGfxBase, __arg1) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC1(BOOL, IsCyberModeID, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__CyberGfxBase), 9, Cybergraphics);\
})

#define IsCyberModeID(arg1) \
    __IsCyberModeID_WB(__CYBERGRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __BestCModeIDTagList_WB(__CyberGfxBase, __arg1) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC1(ULONG, BestCModeIDTagList, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct Library *, (__CyberGfxBase), 10, Cybergraphics);\
})

#define BestCModeIDTagList(arg1) \
    __BestCModeIDTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define BestCModeIDTags(...) \
({ \
    const IPTR BestCModeIDTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    BestCModeIDTagList((struct TagItem *)(BestCModeIDTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __AllocCModeListTagList_WB(__CyberGfxBase, __arg1) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC1(struct List *, AllocCModeListTagList, \
                  AROS_LCA(struct TagItem *,(__arg1),A1), \
        struct Library *, (__CyberGfxBase), 12, Cybergraphics);\
})

#define AllocCModeListTagList(arg1) \
    __AllocCModeListTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define AllocCModeListTags(...) \
({ \
    const IPTR AllocCModeListTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocCModeListTagList((struct TagItem *)(AllocCModeListTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __FreeCModeList_WB(__CyberGfxBase, __arg1) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC1NR(void, FreeCModeList, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct Library *, (__CyberGfxBase), 13, Cybergraphics);\
})

#define FreeCModeList(arg1) \
    __FreeCModeList_WB(__CYBERGRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __ScalePixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC10(LONG, ScalePixelArray, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(struct RastPort *,(__arg5),A1), \
                  AROS_LCA(UWORD,(__arg6),D3), \
                  AROS_LCA(UWORD,(__arg7),D4), \
                  AROS_LCA(UWORD,(__arg8),D5), \
                  AROS_LCA(UWORD,(__arg9),D6), \
                  AROS_LCA(UBYTE,(__arg10),D7), \
        struct Library *, (__CyberGfxBase), 15, Cybergraphics);\
})

#define ScalePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __ScalePixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __GetCyberMapAttr_WB(__CyberGfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC2(ULONG, GetCyberMapAttr, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CyberGfxBase), 16, Cybergraphics);\
})

#define GetCyberMapAttr(arg1, arg2) \
    __GetCyberMapAttr_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __GetCyberIDAttr_WB(__CyberGfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC2(ULONG, GetCyberIDAttr, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct Library *, (__CyberGfxBase), 17, Cybergraphics);\
})

#define GetCyberIDAttr(arg1, arg2) \
    __GetCyberIDAttr_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __ReadRGBPixel_WB(__CyberGfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC3(ULONG, ReadRGBPixel, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
        struct Library *, (__CyberGfxBase), 18, Cybergraphics);\
})

#define ReadRGBPixel(arg1, arg2, arg3) \
    __ReadRGBPixel_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __WriteRGBPixel_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC4(LONG, WriteRGBPixel, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
        struct Library *, (__CyberGfxBase), 19, Cybergraphics);\
})

#define WriteRGBPixel(arg1, arg2, arg3, arg4) \
    __WriteRGBPixel_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __ReadPixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC10(ULONG, ReadPixelArray, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(struct RastPort *,(__arg5),A1), \
                  AROS_LCA(UWORD,(__arg6),D3), \
                  AROS_LCA(UWORD,(__arg7),D4), \
                  AROS_LCA(UWORD,(__arg8),D5), \
                  AROS_LCA(UWORD,(__arg9),D6), \
                  AROS_LCA(UBYTE,(__arg10),D7), \
        struct Library *, (__CyberGfxBase), 20, Cybergraphics);\
})

#define ReadPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __ReadPixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __WritePixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC10(ULONG, WritePixelArray, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(struct RastPort *,(__arg5),A1), \
                  AROS_LCA(UWORD,(__arg6),D3), \
                  AROS_LCA(UWORD,(__arg7),D4), \
                  AROS_LCA(UWORD,(__arg8),D5), \
                  AROS_LCA(UWORD,(__arg9),D6), \
                  AROS_LCA(UBYTE,(__arg10),D7), \
        struct Library *, (__CyberGfxBase), 21, Cybergraphics);\
})

#define WritePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __WritePixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __MovePixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC7(ULONG, MovePixelArray, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(UWORD,(__arg2),D1), \
                  AROS_LCA(struct RastPort *,(__arg3),A1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(UWORD,(__arg5),D3), \
                  AROS_LCA(UWORD,(__arg6),D4), \
                  AROS_LCA(UWORD,(__arg7),D5), \
        struct Library *, (__CyberGfxBase), 22, Cybergraphics);\
})

#define MovePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __MovePixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __InvertPixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC5(ULONG, InvertPixelArray, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(UWORD,(__arg5),D3), \
        struct Library *, (__CyberGfxBase), 24, Cybergraphics);\
})

#define InvertPixelArray(arg1, arg2, arg3, arg4, arg5) \
    __InvertPixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __FillPixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC6(ULONG, FillPixelArray, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(UWORD,(__arg5),D3), \
                  AROS_LCA(ULONG,(__arg6),D4), \
        struct Library *, (__CyberGfxBase), 25, Cybergraphics);\
})

#define FillPixelArray(arg1, arg2, arg3, arg4, arg5, arg6) \
    __FillPixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __DoCDrawMethodTagList_WB(__CyberGfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC3NR(void, DoCDrawMethodTagList, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
                  AROS_LCA(struct TagItem *,(__arg3),A2), \
        struct Library *, (__CyberGfxBase), 26, Cybergraphics);\
})

#define DoCDrawMethodTagList(arg1, arg2, arg3) \
    __DoCDrawMethodTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define DoCDrawMethodTags(arg1, arg2, ...) \
({ \
    const IPTR DoCDrawMethodTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DoCDrawMethodTagList((arg1), (arg2), (struct TagItem *)(DoCDrawMethodTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __CVideoCtrlTagList_WB(__CyberGfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC2NR(void, CVideoCtrlTagList, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CyberGfxBase), 27, Cybergraphics);\
})

#define CVideoCtrlTagList(arg1, arg2) \
    __CVideoCtrlTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define CVideoCtrlTags(arg1, ...) \
({ \
    const IPTR CVideoCtrlTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CVideoCtrlTagList((arg1), (struct TagItem *)(CVideoCtrlTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __LockBitMapTagList_WB(__CyberGfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC2(APTR, LockBitMapTagList, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CyberGfxBase), 28, Cybergraphics);\
})

#define LockBitMapTagList(arg1, arg2) \
    __LockBitMapTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define LockBitMapTags(arg1, ...) \
({ \
    const IPTR LockBitMapTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    LockBitMapTagList((arg1), (struct TagItem *)(LockBitMapTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __UnLockBitMap_WB(__CyberGfxBase, __arg1) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC1NR(void, UnLockBitMap, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__CyberGfxBase), 29, Cybergraphics);\
})

#define UnLockBitMap(arg1) \
    __UnLockBitMap_WB(__CYBERGRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

#define __UnLockBitMapTagList_WB(__CyberGfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CyberGfxBase,40)\
        AROS_LC2NR(void, UnLockBitMapTagList, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CyberGfxBase), 30, Cybergraphics);\
})

#define UnLockBitMapTagList(arg1, arg2) \
    __UnLockBitMapTagList_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define UnLockBitMapTags(arg1, ...) \
({ \
    const IPTR UnLockBitMapTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    UnLockBitMapTagList((arg1), (struct TagItem *)(UnLockBitMapTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

#define __ExtractColor_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(CyberGfxBase,41)\
        AROS_LC7(ULONG, ExtractColor, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(ULONG,(__arg4),D1), \
                  AROS_LCA(ULONG,(__arg5),D2), \
                  AROS_LCA(ULONG,(__arg6),D3), \
                  AROS_LCA(ULONG,(__arg7),D4), \
        struct Library *, (__CyberGfxBase), 31, Cybergraphics);\
})

#define ExtractColor(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __ExtractColor_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

#define __WriteLUTPixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10, __arg11) ({\
        AROS_LIBREQ(CyberGfxBase,41)\
        AROS_LC11(LONG, WriteLUTPixelArray, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(struct RastPort *,(__arg5),A1), \
                  AROS_LCA(APTR,(__arg6),A2), \
                  AROS_LCA(UWORD,(__arg7),D3), \
                  AROS_LCA(UWORD,(__arg8),D4), \
                  AROS_LCA(UWORD,(__arg9),D5), \
                  AROS_LCA(UWORD,(__arg10),D6), \
                  AROS_LCA(UBYTE,(__arg11),D7), \
        struct Library *, (__CyberGfxBase), 33, Cybergraphics);\
})

#define WriteLUTPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) \
    __WriteLUTPixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), (arg11))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

#define __WritePixelArrayAlpha_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10) ({\
        AROS_LIBREQ(CyberGfxBase,41)\
        AROS_LC10(ULONG, WritePixelArrayAlpha, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(struct RastPort *,(__arg5),A1), \
                  AROS_LCA(UWORD,(__arg6),D3), \
                  AROS_LCA(UWORD,(__arg7),D4), \
                  AROS_LCA(UWORD,(__arg8),D5), \
                  AROS_LCA(UWORD,(__arg9),D6), \
                  AROS_LCA(ULONG,(__arg10),D7), \
        struct Library *, (__CyberGfxBase), 36, Cybergraphics);\
})

#define WritePixelArrayAlpha(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __WritePixelArrayAlpha_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__)

#define __BltTemplateAlpha_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(CyberGfxBase,51)\
        AROS_LC8NR(void, BltTemplateAlpha, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(LONG,(__arg3),D1), \
                  AROS_LCA(struct RastPort *,(__arg4),A1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(LONG,(__arg8),D5), \
        struct Library *, (__CyberGfxBase), 37, Cybergraphics);\
})

#define BltTemplateAlpha(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __BltTemplateAlpha_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__)

#define __ProcessPixelArray_WB(__CyberGfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(CyberGfxBase,51)\
        AROS_LC8NR(VOID, ProcessPixelArray, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
                  AROS_LCA(ULONG,(__arg5),D3), \
                  AROS_LCA(ULONG,(__arg6),D4), \
                  AROS_LCA(LONG,(__arg7),D5), \
                  AROS_LCA(struct TagItem *,(__arg8),A2), \
        struct Library *, (__CyberGfxBase), 38, Cybergraphics);\
})

#define ProcessPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __ProcessPixelArray_WB(__CYBERGRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define ProcessPixelArrayTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR ProcessPixelArray_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ProcessPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(ProcessPixelArray_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_CYBERGRAPHICS_H*/
