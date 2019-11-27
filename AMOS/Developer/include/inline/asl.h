#ifndef INLINE_ASL_H
#define INLINE_ASL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/asl/asl.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for asl
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__ASL_LIBBASE)
#    define __ASL_LIBBASE AslBase
#endif


#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline struct FileRequester * __inline_Asl_AllocFileRequest(APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    return AROS_LC0(struct FileRequester *, AllocFileRequest,
        struct Library *, (__AslBase), 5, Asl    );
}

#define AllocFileRequest() \
    __inline_Asl_AllocFileRequest(__ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline void __inline_Asl_FreeFileRequest(struct FileRequester * __arg1, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    AROS_LC1NR(void, FreeFileRequest,
        AROS_LCA(struct FileRequester *,(__arg1),A0),
        struct Library *, (__AslBase), 6, Asl    );
}

#define FreeFileRequest(arg1) \
    __inline_Asl_FreeFileRequest((arg1), __ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline BOOL __inline_Asl_RequestFile(struct FileRequester * __arg1, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    return AROS_LC1(BOOL, RequestFile,
        AROS_LCA(struct FileRequester *,(__arg1),A0),
        struct Library *, (__AslBase), 7, Asl    );
}

#define RequestFile(arg1) \
    __inline_Asl_RequestFile((arg1), __ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline APTR __inline_Asl_AllocAslRequest(ULONG __arg1, struct TagItem * __arg2, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    return AROS_LC2(APTR, AllocAslRequest,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Library *, (__AslBase), 8, Asl    );
}

#define AllocAslRequest(arg1, arg2) \
    __inline_Asl_AllocAslRequest((arg1), (arg2), __ASL_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ASL_NO_INLINE_STDARG)
#define AllocAslRequestTags(arg1, ...) \
({ \
    const IPTR AllocAslRequest_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocAslRequest((arg1), (struct TagItem *)(AllocAslRequest_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline void __inline_Asl_FreeAslRequest(APTR __arg1, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    AROS_LC1NR(void, FreeAslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__AslBase), 9, Asl    );
}

#define FreeAslRequest(arg1) \
    __inline_Asl_FreeAslRequest((arg1), __ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__)

static inline BOOL __inline_Asl_AslRequest(APTR __arg1, struct TagItem * __arg2, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 36)
    return AROS_LC2(BOOL, AslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__AslBase), 10, Asl    );
}

#define AslRequest(arg1, arg2) \
    __inline_Asl_AslRequest((arg1), (arg2), __ASL_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ASL_NO_INLINE_STDARG)
#define AslRequestTags(arg1, ...) \
({ \
    const IPTR AslRequest_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AslRequest((arg1), (struct TagItem *)(AslRequest_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ASL_LIBAPI__) || (36 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (50 <= __ASL_LIBAPI__)

static inline void __inline_Asl_AbortAslRequest(APTR __arg1, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 50)
    AROS_LC1NR(void, AbortAslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__AslBase), 13, Asl    );
}

#define AbortAslRequest(arg1) \
    __inline_Asl_AbortAslRequest((arg1), __ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (50 <= __ASL_LIBAPI__) */

#if !defined(__ASL_LIBAPI__) || (50 <= __ASL_LIBAPI__)

static inline void __inline_Asl_ActivateAslRequest(APTR __arg1, APTR __AslBase)
{
    AROS_LIBREQ(AslBase, 50)
    AROS_LC1NR(void, ActivateAslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__AslBase), 14, Asl    );
}

#define ActivateAslRequest(arg1) \
    __inline_Asl_ActivateAslRequest((arg1), __ASL_LIBBASE)

#endif /* !defined(__ASL_LIBAPI__) || (50 <= __ASL_LIBAPI__) */

#endif /* INLINE_ASL_H*/
