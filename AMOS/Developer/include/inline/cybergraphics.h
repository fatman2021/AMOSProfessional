#ifndef INLINE_CYBERGRAPHICS_H
#define INLINE_CYBERGRAPHICS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/cgfx/cybergraphics.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for cybergraphics
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CYBERGRAPHICS_LIBBASE)
#    define __CYBERGRAPHICS_LIBBASE CyberGfxBase
#endif


#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline BOOL __inline_Cybergraphics_IsCyberModeID(ULONG __arg1, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC1(BOOL, IsCyberModeID,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__CyberGfxBase), 9, Cybergraphics    );
}

#define IsCyberModeID(arg1) \
    __inline_Cybergraphics_IsCyberModeID((arg1), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_BestCModeIDTagList(struct TagItem * __arg1, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC1(ULONG, BestCModeIDTagList,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct Library *, (__CyberGfxBase), 10, Cybergraphics    );
}

#define BestCModeIDTagList(arg1) \
    __inline_Cybergraphics_BestCModeIDTagList((arg1), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define BestCModeIDTags(...) \
({ \
    const IPTR BestCModeIDTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    BestCModeIDTagList((struct TagItem *)(BestCModeIDTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline struct List * __inline_Cybergraphics_AllocCModeListTagList(struct TagItem * __arg1, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC1(struct List *, AllocCModeListTagList,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct Library *, (__CyberGfxBase), 12, Cybergraphics    );
}

#define AllocCModeListTagList(arg1) \
    __inline_Cybergraphics_AllocCModeListTagList((arg1), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define AllocCModeListTags(...) \
({ \
    const IPTR AllocCModeListTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocCModeListTagList((struct TagItem *)(AllocCModeListTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_FreeCModeList(struct List * __arg1, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    AROS_LC1NR(void, FreeCModeList,
        AROS_LCA(struct List *,(__arg1),A0),
        struct Library *, (__CyberGfxBase), 13, Cybergraphics    );
}

#define FreeCModeList(arg1) \
    __inline_Cybergraphics_FreeCModeList((arg1), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline LONG __inline_Cybergraphics_ScalePixelArray(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, struct RastPort * __arg5, UWORD __arg6, UWORD __arg7, UWORD __arg8, UWORD __arg9, UBYTE __arg10, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC10(LONG, ScalePixelArray,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(struct RastPort *,(__arg5),A1),
        AROS_LCA(UWORD,(__arg6),D3),
        AROS_LCA(UWORD,(__arg7),D4),
        AROS_LCA(UWORD,(__arg8),D5),
        AROS_LCA(UWORD,(__arg9),D6),
        AROS_LCA(UBYTE,(__arg10),D7),
        struct Library *, (__CyberGfxBase), 15, Cybergraphics    );
}

#define ScalePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __inline_Cybergraphics_ScalePixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_GetCyberMapAttr(struct BitMap * __arg1, ULONG __arg2, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC2(ULONG, GetCyberMapAttr,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CyberGfxBase), 16, Cybergraphics    );
}

#define GetCyberMapAttr(arg1, arg2) \
    __inline_Cybergraphics_GetCyberMapAttr((arg1), (arg2), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_GetCyberIDAttr(ULONG __arg1, ULONG __arg2, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC2(ULONG, GetCyberIDAttr,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__CyberGfxBase), 17, Cybergraphics    );
}

#define GetCyberIDAttr(arg1, arg2) \
    __inline_Cybergraphics_GetCyberIDAttr((arg1), (arg2), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_ReadRGBPixel(struct RastPort * __arg1, UWORD __arg2, UWORD __arg3, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC3(ULONG, ReadRGBPixel,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        struct Library *, (__CyberGfxBase), 18, Cybergraphics    );
}

#define ReadRGBPixel(arg1, arg2, arg3) \
    __inline_Cybergraphics_ReadRGBPixel((arg1), (arg2), (arg3), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline LONG __inline_Cybergraphics_WriteRGBPixel(struct RastPort * __arg1, UWORD __arg2, UWORD __arg3, ULONG __arg4, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC4(LONG, WriteRGBPixel,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        struct Library *, (__CyberGfxBase), 19, Cybergraphics    );
}

#define WriteRGBPixel(arg1, arg2, arg3, arg4) \
    __inline_Cybergraphics_WriteRGBPixel((arg1), (arg2), (arg3), (arg4), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_ReadPixelArray(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, struct RastPort * __arg5, UWORD __arg6, UWORD __arg7, UWORD __arg8, UWORD __arg9, UBYTE __arg10, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC10(ULONG, ReadPixelArray,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(struct RastPort *,(__arg5),A1),
        AROS_LCA(UWORD,(__arg6),D3),
        AROS_LCA(UWORD,(__arg7),D4),
        AROS_LCA(UWORD,(__arg8),D5),
        AROS_LCA(UWORD,(__arg9),D6),
        AROS_LCA(UBYTE,(__arg10),D7),
        struct Library *, (__CyberGfxBase), 20, Cybergraphics    );
}

#define ReadPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __inline_Cybergraphics_ReadPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_WritePixelArray(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, struct RastPort * __arg5, UWORD __arg6, UWORD __arg7, UWORD __arg8, UWORD __arg9, UBYTE __arg10, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC10(ULONG, WritePixelArray,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(struct RastPort *,(__arg5),A1),
        AROS_LCA(UWORD,(__arg6),D3),
        AROS_LCA(UWORD,(__arg7),D4),
        AROS_LCA(UWORD,(__arg8),D5),
        AROS_LCA(UWORD,(__arg9),D6),
        AROS_LCA(UBYTE,(__arg10),D7),
        struct Library *, (__CyberGfxBase), 21, Cybergraphics    );
}

#define WritePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __inline_Cybergraphics_WritePixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_MovePixelArray(UWORD __arg1, UWORD __arg2, struct RastPort * __arg3, UWORD __arg4, UWORD __arg5, UWORD __arg6, UWORD __arg7, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC7(ULONG, MovePixelArray,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(UWORD,(__arg2),D1),
        AROS_LCA(struct RastPort *,(__arg3),A1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        AROS_LCA(UWORD,(__arg6),D4),
        AROS_LCA(UWORD,(__arg7),D5),
        struct Library *, (__CyberGfxBase), 22, Cybergraphics    );
}

#define MovePixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Cybergraphics_MovePixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_InvertPixelArray(struct RastPort * __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, UWORD __arg5, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC5(ULONG, InvertPixelArray,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        struct Library *, (__CyberGfxBase), 24, Cybergraphics    );
}

#define InvertPixelArray(arg1, arg2, arg3, arg4, arg5) \
    __inline_Cybergraphics_InvertPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_FillPixelArray(struct RastPort * __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, UWORD __arg5, ULONG __arg6, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC6(ULONG, FillPixelArray,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        AROS_LCA(ULONG,(__arg6),D4),
        struct Library *, (__CyberGfxBase), 25, Cybergraphics    );
}

#define FillPixelArray(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Cybergraphics_FillPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_DoCDrawMethodTagList(struct Hook * __arg1, struct RastPort * __arg2, struct TagItem * __arg3, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    AROS_LC3NR(void, DoCDrawMethodTagList,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct Library *, (__CyberGfxBase), 26, Cybergraphics    );
}

#define DoCDrawMethodTagList(arg1, arg2, arg3) \
    __inline_Cybergraphics_DoCDrawMethodTagList((arg1), (arg2), (arg3), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define DoCDrawMethodTags(arg1, arg2, ...) \
({ \
    const IPTR DoCDrawMethodTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DoCDrawMethodTagList((arg1), (arg2), (struct TagItem *)(DoCDrawMethodTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_CVideoCtrlTagList(struct ViewPort * __arg1, struct TagItem * __arg2, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    AROS_LC2NR(void, CVideoCtrlTagList,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CyberGfxBase), 27, Cybergraphics    );
}

#define CVideoCtrlTagList(arg1, arg2) \
    __inline_Cybergraphics_CVideoCtrlTagList((arg1), (arg2), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define CVideoCtrlTags(arg1, ...) \
({ \
    const IPTR CVideoCtrlTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CVideoCtrlTagList((arg1), (struct TagItem *)(CVideoCtrlTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline APTR __inline_Cybergraphics_LockBitMapTagList(APTR __arg1, struct TagItem * __arg2, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    return AROS_LC2(APTR, LockBitMapTagList,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CyberGfxBase), 28, Cybergraphics    );
}

#define LockBitMapTagList(arg1, arg2) \
    __inline_Cybergraphics_LockBitMapTagList((arg1), (arg2), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define LockBitMapTags(arg1, ...) \
({ \
    const IPTR LockBitMapTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    LockBitMapTagList((arg1), (struct TagItem *)(LockBitMapTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_UnLockBitMap(APTR __arg1, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    AROS_LC1NR(void, UnLockBitMap,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__CyberGfxBase), 29, Cybergraphics    );
}

#define UnLockBitMap(arg1) \
    __inline_Cybergraphics_UnLockBitMap((arg1), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_UnLockBitMapTagList(APTR __arg1, struct TagItem * __arg2, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 40)
    AROS_LC2NR(void, UnLockBitMapTagList,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CyberGfxBase), 30, Cybergraphics    );
}

#define UnLockBitMapTagList(arg1, arg2) \
    __inline_Cybergraphics_UnLockBitMapTagList((arg1), (arg2), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define UnLockBitMapTags(arg1, ...) \
({ \
    const IPTR UnLockBitMapTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    UnLockBitMapTagList((arg1), (struct TagItem *)(UnLockBitMapTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (40 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_ExtractColor(struct RastPort * __arg1, struct BitMap * __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, ULONG __arg7, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 41)
    return AROS_LC7(ULONG, ExtractColor,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(ULONG,(__arg4),D1),
        AROS_LCA(ULONG,(__arg5),D2),
        AROS_LCA(ULONG,(__arg6),D3),
        AROS_LCA(ULONG,(__arg7),D4),
        struct Library *, (__CyberGfxBase), 31, Cybergraphics    );
}

#define ExtractColor(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Cybergraphics_ExtractColor((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

static inline LONG __inline_Cybergraphics_WriteLUTPixelArray(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, struct RastPort * __arg5, APTR __arg6, UWORD __arg7, UWORD __arg8, UWORD __arg9, UWORD __arg10, UBYTE __arg11, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 41)
    return AROS_LC11(LONG, WriteLUTPixelArray,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(struct RastPort *,(__arg5),A1),
        AROS_LCA(APTR,(__arg6),A2),
        AROS_LCA(UWORD,(__arg7),D3),
        AROS_LCA(UWORD,(__arg8),D4),
        AROS_LCA(UWORD,(__arg9),D5),
        AROS_LCA(UWORD,(__arg10),D6),
        AROS_LCA(UBYTE,(__arg11),D7),
        struct Library *, (__CyberGfxBase), 33, Cybergraphics    );
}

#define WriteLUTPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) \
    __inline_Cybergraphics_WriteLUTPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), (arg11), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__)

static inline ULONG __inline_Cybergraphics_WritePixelArrayAlpha(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, struct RastPort * __arg5, UWORD __arg6, UWORD __arg7, UWORD __arg8, UWORD __arg9, ULONG __arg10, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 41)
    return AROS_LC10(ULONG, WritePixelArrayAlpha,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(struct RastPort *,(__arg5),A1),
        AROS_LCA(UWORD,(__arg6),D3),
        AROS_LCA(UWORD,(__arg7),D4),
        AROS_LCA(UWORD,(__arg8),D5),
        AROS_LCA(UWORD,(__arg9),D6),
        AROS_LCA(ULONG,(__arg10),D7),
        struct Library *, (__CyberGfxBase), 36, Cybergraphics    );
}

#define WritePixelArrayAlpha(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __inline_Cybergraphics_WritePixelArrayAlpha((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (41 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__)

static inline void __inline_Cybergraphics_BltTemplateAlpha(APTR __arg1, LONG __arg2, LONG __arg3, struct RastPort * __arg4, LONG __arg5, LONG __arg6, LONG __arg7, LONG __arg8, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 51)
    AROS_LC8NR(void, BltTemplateAlpha,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(struct RastPort *,(__arg4),A1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(LONG,(__arg8),D5),
        struct Library *, (__CyberGfxBase), 37, Cybergraphics    );
}

#define BltTemplateAlpha(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Cybergraphics_BltTemplateAlpha((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __CYBERGRAPHICS_LIBBASE)

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__) */

#if !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__)

static inline VOID __inline_Cybergraphics_ProcessPixelArray(struct RastPort * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, LONG __arg7, struct TagItem * __arg8, APTR __CyberGfxBase)
{
    AROS_LIBREQ(CyberGfxBase, 51)
    AROS_LC8NR(VOID, ProcessPixelArray,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        AROS_LCA(ULONG,(__arg5),D3),
        AROS_LCA(ULONG,(__arg6),D4),
        AROS_LCA(LONG,(__arg7),D5),
        AROS_LCA(struct TagItem *,(__arg8),A2),
        struct Library *, (__CyberGfxBase), 38, Cybergraphics    );
}

#define ProcessPixelArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Cybergraphics_ProcessPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __CYBERGRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CYBERGRAPHICS_NO_INLINE_STDARG)
#define ProcessPixelArrayTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR ProcessPixelArray_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ProcessPixelArray((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(ProcessPixelArray_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CYBERGRAPHICS_LIBAPI__) || (51 <= __CYBERGRAPHICS_LIBAPI__) */

#endif /* INLINE_CYBERGRAPHICS_H*/
