#ifndef DEFINES_PNGDT_H
#define DEFINES_PNGDT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/classes/datatypes/png/png.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for png
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PNGDT_LIBBASE)
#    define __PNGDT_LIBBASE PNGBase
#endif

__BEGIN_DECLS


#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_CheckSig_WB(__PNGBase, __arg1) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC1(LONG, PNG_CheckSig, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
        struct Library *, (__PNGBase), 6, PNG);\
})

#define PNG_CheckSig(arg1) \
    __PNG_CheckSig_WB(__PNGDT_LIBBASE, (arg1))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_LoadImageFH_WB(__PNGBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC4(APTR, PNG_LoadImageFH, \
                  AROS_LCA(BPTR,(__arg1),A0), \
                  AROS_LCA(CONST_STRPTR const *,(__arg2),A1), \
                  AROS_LCA(APTR*,(__arg3),A2), \
                  AROS_LCA(BOOL,(__arg4),D0), \
        struct Library *, (__PNGBase), 7, PNG);\
})

#define PNG_LoadImageFH(arg1, arg2, arg3, arg4) \
    __PNG_LoadImageFH_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_LoadImage_WB(__PNGBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC4(APTR, PNG_LoadImage, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(CONST_STRPTR const *,(__arg2),A1), \
                  AROS_LCA(APTR*,(__arg3),A2), \
                  AROS_LCA(BOOL,(__arg4),D0), \
        struct Library *, (__PNGBase), 8, PNG);\
})

#define PNG_LoadImage(arg1, arg2, arg3, arg4) \
    __PNG_LoadImage_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_LoadImageMEM_WB(__PNGBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC5(APTR, PNG_LoadImageMEM, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(CONST_STRPTR const *,(__arg3),A1), \
                  AROS_LCA(APTR*,(__arg4),A2), \
                  AROS_LCA(BOOL,(__arg5),D1), \
        struct Library *, (__PNGBase), 9, PNG);\
})

#define PNG_LoadImageMEM(arg1, arg2, arg3, arg4, arg5) \
    __PNG_LoadImageMEM_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_GetImageInfo_WB(__PNGBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC5NR(void, PNG_GetImageInfo, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(LONG*,(__arg2),A1), \
                  AROS_LCA(LONG*,(__arg3),A2), \
                  AROS_LCA(LONG*,(__arg4),A3), \
                  AROS_LCA(LONG*,(__arg5),A4), \
        struct Library *, (__PNGBase), 10, PNG);\
})

#define PNG_GetImageInfo(arg1, arg2, arg3, arg4, arg5) \
    __PNG_GetImageInfo_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_GetImageData_WB(__PNGBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC3NR(void, PNG_GetImageData, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR*,(__arg2),A1), \
                  AROS_LCA(APTR*,(__arg3),A2), \
        struct Library *, (__PNGBase), 11, PNG);\
})

#define PNG_GetImageData(arg1, arg2, arg3) \
    __PNG_GetImageData_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_FreeImage_WB(__PNGBase, __arg1) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC1NR(void, PNG_FreeImage, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__PNGBase), 12, PNG);\
})

#define PNG_FreeImage(arg1) \
    __PNG_FreeImage_WB(__PNGDT_LIBBASE, (arg1))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_FreeChunk_WB(__PNGBase, __arg1) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC1NR(void, PNG_FreeChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__PNGBase), 13, PNG);\
})

#define PNG_FreeChunk(arg1) \
    __PNG_FreeChunk_WB(__PNGDT_LIBBASE, (arg1))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

#if !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__)

#define __PNG_GetChunkInfo_WB(__PNGBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(PNGBase,42)\
        AROS_LC3NR(void, PNG_GetChunkInfo, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR*,(__arg2),A1), \
                  AROS_LCA(ULONG*,(__arg3),A2), \
        struct Library *, (__PNGBase), 14, PNG);\
})

#define PNG_GetChunkInfo(arg1, arg2, arg3) \
    __PNG_GetChunkInfo_WB(__PNGDT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__PNGDT_LIBAPI__) || (42 <= __PNGDT_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PNGDT_H*/
