#ifndef DEFINES_GALLIUM_H
#define DEFINES_GALLIUM_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/gallium/gallium.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for gallium
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__GALLIUM_LIBBASE)
#    define __GALLIUM_LIBBASE GalliumBase
#endif

__BEGIN_DECLS


#if !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__)

#define __CreatePipe_WB(__GalliumBase, __arg1) ({\
        AROS_LIBREQ(GalliumBase,4)\
        AROS_LC1(PipeHandle_t, CreatePipe, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct Library *, (__GalliumBase), 5, Gallium);\
})

#define CreatePipe(arg1) \
    __CreatePipe_WB(__GALLIUM_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(GALLIUM_NO_INLINE_STDARG)
#define CreatePipeTags(...) \
({ \
    const IPTR CreatePipe_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreatePipe((struct TagItem *)(CreatePipe_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__) */

#if !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__)

#define __DestroyPipe_WB(__GalliumBase, __arg1) ({\
        AROS_LIBREQ(GalliumBase,4)\
        AROS_LC1NR(void, DestroyPipe, \
                  AROS_LCA(PipeHandle_t,(__arg1),A0), \
        struct Library *, (__GalliumBase), 6, Gallium);\
})

#define DestroyPipe(arg1) \
    __DestroyPipe_WB(__GALLIUM_LIBBASE, (arg1))

#endif /* !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__) */

#if !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__)

#define __CreatePipeScreen_WB(__GalliumBase, __arg1) ({\
        AROS_LIBREQ(GalliumBase,4)\
        AROS_LC1(PipeScreen_t, CreatePipeScreen, \
                  AROS_LCA(PipeHandle_t,(__arg1),A0), \
        struct Library *, (__GalliumBase), 7, Gallium);\
})

#define CreatePipeScreen(arg1) \
    __CreatePipeScreen_WB(__GALLIUM_LIBBASE, (arg1))

#endif /* !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__) */

#if !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__)

#define __DestroyPipeScreen_WB(__GalliumBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GalliumBase,4)\
        AROS_LC2NR(void, DestroyPipeScreen, \
                  AROS_LCA(PipeHandle_t,(__arg1),A0), \
                  AROS_LCA(PipeScreen_t,(__arg2),A1), \
        struct Library *, (__GalliumBase), 8, Gallium);\
})

#define DestroyPipeScreen(arg1, arg2) \
    __DestroyPipeScreen_WB(__GALLIUM_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__) */

#if !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__)

#define __BltPipeResourceRastPort_WB(__GalliumBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(GalliumBase,4)\
        AROS_LC9NR(void, BltPipeResourceRastPort, \
                  AROS_LCA(PipeHandle_t,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(struct RastPort *,(__arg5),A2), \
                  AROS_LCA(LONG,(__arg6),D2), \
                  AROS_LCA(LONG,(__arg7),D3), \
                  AROS_LCA(LONG,(__arg8),D4), \
                  AROS_LCA(LONG,(__arg9),D5), \
        struct Library *, (__GalliumBase), 9, Gallium);\
})

#define BltPipeResourceRastPort(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __BltPipeResourceRastPort_WB(__GALLIUM_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__GALLIUM_LIBAPI__) || (4 <= __GALLIUM_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_GALLIUM_H*/
