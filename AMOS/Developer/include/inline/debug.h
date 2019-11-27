#ifndef INLINE_DEBUG_H
#define INLINE_DEBUG_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/debug/debug.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for debug
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DEBUG_LIBBASE)
#    define __DEBUG_LIBBASE DebugBase
#endif


#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)

static inline void __inline_Debug_RegisterModule(const char * __arg1, BPTR __arg2, ULONG __arg3, APTR __arg4, APTR __DebugBase)
{
    AROS_LIBREQ(DebugBase, 2)
    AROS_LC4NR(void, RegisterModule,
        AROS_LCA(const char *,(__arg1),A0),
        AROS_LCA(BPTR,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(APTR,(__arg4),A2),
        struct Library *, (__DebugBase), 5, Debug    );
}

#define RegisterModule(arg1, arg2, arg3, arg4) \
    __inline_Debug_RegisterModule((arg1), (arg2), (arg3), (arg4), __DEBUG_LIBBASE)

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)

static inline void __inline_Debug_UnregisterModule(BPTR __arg1, APTR __DebugBase)
{
    AROS_LIBREQ(DebugBase, 2)
    AROS_LC1NR(void, UnregisterModule,
        AROS_LCA(BPTR,(__arg1),A0),
        struct Library *, (__DebugBase), 6, Debug    );
}

#define UnregisterModule(arg1) \
    __inline_Debug_UnregisterModule((arg1), __DEBUG_LIBBASE)

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)

static inline int __inline_Debug_DecodeLocationA(void * __arg1, struct TagItem * __arg2, APTR __DebugBase)
{
    AROS_LIBREQ(DebugBase, 2)
    return AROS_LC2(int, DecodeLocationA,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__DebugBase), 7, Debug    );
}

#define DecodeLocationA(arg1, arg2) \
    __inline_Debug_DecodeLocationA((arg1), (arg2), __DEBUG_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DEBUG_NO_INLINE_STDARG)
#define DecodeLocation(arg1, ...) \
({ \
    const IPTR DecodeLocationA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DecodeLocationA((arg1), (struct TagItem *)(DecodeLocationA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#if !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__)

static inline void __inline_Debug_EnumerateSymbolsA(struct Hook * __arg1, struct TagItem * __arg2, APTR __DebugBase)
{
    AROS_LIBREQ(DebugBase, 2)
    AROS_LC2NR(void, EnumerateSymbolsA,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__DebugBase), 8, Debug    );
}

#define EnumerateSymbolsA(arg1, arg2) \
    __inline_Debug_EnumerateSymbolsA((arg1), (arg2), __DEBUG_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DEBUG_NO_INLINE_STDARG)
#define EnumerateSymbols(arg1, ...) \
({ \
    const IPTR EnumerateSymbolsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    EnumerateSymbolsA((arg1), (struct TagItem *)(EnumerateSymbolsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DEBUG_LIBAPI__) || (2 <= __DEBUG_LIBAPI__) */

#endif /* INLINE_DEBUG_H*/
