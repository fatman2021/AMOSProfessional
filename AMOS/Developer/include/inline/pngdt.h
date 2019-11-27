#ifndef INLINE_PNGDT_H
#define INLINE_PNGDT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/classes/datatypes/png/png.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for png
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PNGDT_LIBBASE)
#    define __PNGDT_LIBBASE PNGBase
#endif


#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline LONG __inline_PNG_PNG_CheckSig(CONST_STRPTR __arg1, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    return AROS_LC1(LONG, PNG_CheckSig,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct Library *, (__PNGBase), 6, PNG    );
}

#define PNG_CheckSig(arg1) \
    __inline_PNG_PNG_CheckSig((arg1), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline APTR __inline_PNG_PNG_LoadImageFH(BPTR __arg1, CONST_STRPTR const * __arg2, APTR* __arg3, BOOL __arg4, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    return AROS_LC4(APTR, PNG_LoadImageFH,
        AROS_LCA(BPTR,(__arg1),A0),
        AROS_LCA(CONST_STRPTR const *,(__arg2),A1),
        AROS_LCA(APTR*,(__arg3),A2),
        AROS_LCA(BOOL,(__arg4),D0),
        struct Library *, (__PNGBase), 7, PNG    );
}

#define PNG_LoadImageFH(arg1, arg2, arg3, arg4) \
    __inline_PNG_PNG_LoadImageFH((arg1), (arg2), (arg3), (arg4), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline APTR __inline_PNG_PNG_LoadImage(CONST_STRPTR __arg1, CONST_STRPTR const * __arg2, APTR* __arg3, BOOL __arg4, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    return AROS_LC4(APTR, PNG_LoadImage,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(CONST_STRPTR const *,(__arg2),A1),
        AROS_LCA(APTR*,(__arg3),A2),
        AROS_LCA(BOOL,(__arg4),D0),
        struct Library *, (__PNGBase), 8, PNG    );
}

#define PNG_LoadImage(arg1, arg2, arg3, arg4) \
    __inline_PNG_PNG_LoadImage((arg1), (arg2), (arg3), (arg4), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline APTR __inline_PNG_PNG_LoadImageMEM(APTR __arg1, ULONG __arg2, CONST_STRPTR const * __arg3, APTR* __arg4, BOOL __arg5, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    return AROS_LC5(APTR, PNG_LoadImageMEM,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(CONST_STRPTR const *,(__arg3),A1),
        AROS_LCA(APTR*,(__arg4),A2),
        AROS_LCA(BOOL,(__arg5),D1),
        struct Library *, (__PNGBase), 9, PNG    );
}

#define PNG_LoadImageMEM(arg1, arg2, arg3, arg4, arg5) \
    __inline_PNG_PNG_LoadImageMEM((arg1), (arg2), (arg3), (arg4), (arg5), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline void __inline_PNG_PNG_GetImageInfo(APTR __arg1, LONG* __arg2, LONG* __arg3, LONG* __arg4, LONG* __arg5, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    AROS_LC5NR(void, PNG_GetImageInfo,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(LONG*,(__arg2),A1),
        AROS_LCA(LONG*,(__arg3),A2),
        AROS_LCA(LONG*,(__arg4),A3),
        AROS_LCA(LONG*,(__arg5),A4),
        struct Library *, (__PNGBase), 10, PNG    );
}

#define PNG_GetImageInfo(arg1, arg2, arg3, arg4, arg5) \
    __inline_PNG_PNG_GetImageInfo((arg1), (arg2), (arg3), (arg4), (arg5), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline void __inline_PNG_PNG_GetImageData(APTR __arg1, APTR* __arg2, APTR* __arg3, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    AROS_LC3NR(void, PNG_GetImageData,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR*,(__arg2),A1),
        AROS_LCA(APTR*,(__arg3),A2),
        struct Library *, (__PNGBase), 11, PNG    );
}

#define PNG_GetImageData(arg1, arg2, arg3) \
    __inline_PNG_PNG_GetImageData((arg1), (arg2), (arg3), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline void __inline_PNG_PNG_FreeImage(APTR __arg1, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    AROS_LC1NR(void, PNG_FreeImage,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__PNGBase), 12, PNG    );
}

#define PNG_FreeImage(arg1) \
    __inline_PNG_PNG_FreeImage((arg1), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline void __inline_PNG_PNG_FreeChunk(APTR __arg1, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    AROS_LC1NR(void, PNG_FreeChunk,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__PNGBase), 13, PNG    );
}

#define PNG_FreeChunk(arg1) \
    __inline_PNG_PNG_FreeChunk((arg1), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

static inline void __inline_PNG_PNG_GetChunkInfo(APTR __arg1, APTR* __arg2, ULONG* __arg3, APTR __PNGBase)
{
    AROS_LIBREQ(PNGBase, 42)
    AROS_LC3NR(void, PNG_GetChunkInfo,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR*,(__arg2),A1),
        AROS_LCA(ULONG*,(__arg3),A2),
        struct Library *, (__PNGBase), 14, PNG    );
}

#define PNG_GetChunkInfo(arg1, arg2, arg3) \
    __inline_PNG_PNG_GetChunkInfo((arg1), (arg2), (arg3), __PNGDT_LIBBASE)

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#endif /* INLINE_PNGDT_H*/
