#ifndef INLINE_HOSTLIB_H
#define INLINE_HOSTLIB_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/all-hosted/hostlib/hostlib.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for hostlib
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__HOSTLIB_LIBBASE)
#    define __HOSTLIB_LIBBASE HostLibBase
#endif


#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void * __inline_HostLib_HostLib_Open(const char * __arg1, char ** __arg2, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    return AROS_LC2(void *, HostLib_Open,
        AROS_LCA(const char *,(__arg1),A0),
        AROS_LCA(char **,(__arg2),A1),
        APTR , (__HostLibBase), 1, HostLib    );
}

#define HostLib_Open(arg1, arg2) \
    __inline_HostLib_HostLib_Open((arg1), (arg2), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline int __inline_HostLib_HostLib_Close(void * __arg1, char ** __arg2, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    return AROS_LC2(int, HostLib_Close,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(char **,(__arg2),A1),
        APTR , (__HostLibBase), 2, HostLib    );
}

#define HostLib_Close(arg1, arg2) \
    __inline_HostLib_HostLib_Close((arg1), (arg2), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void * __inline_HostLib_HostLib_GetPointer(void * __arg1, const char * __arg2, char ** __arg3, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    return AROS_LC3(void *, HostLib_GetPointer,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(const char *,(__arg2),A1),
        AROS_LCA(char **,(__arg3),A2),
        APTR , (__HostLibBase), 3, HostLib    );
}

#define HostLib_GetPointer(arg1, arg2, arg3) \
    __inline_HostLib_HostLib_GetPointer((arg1), (arg2), (arg3), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void __inline_HostLib_HostLib_FreeErrorStr(char * __arg1, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    AROS_LC1NR(void, HostLib_FreeErrorStr,
        AROS_LCA(char *,(__arg1),A0),
        APTR , (__HostLibBase), 4, HostLib    );
}

#define HostLib_FreeErrorStr(arg1) \
    __inline_HostLib_HostLib_FreeErrorStr((arg1), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline APTR * __inline_HostLib_HostLib_GetInterface(void * __arg1, const char ** __arg2, ULONG * __arg3, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    return AROS_LC3(APTR *, HostLib_GetInterface,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(const char **,(__arg2),A1),
        AROS_LCA(ULONG *,(__arg3),A2),
        APTR , (__HostLibBase), 5, HostLib    );
}

#define HostLib_GetInterface(arg1, arg2, arg3) \
    __inline_HostLib_HostLib_GetInterface((arg1), (arg2), (arg3), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void __inline_HostLib_HostLib_DropInterface(APTR * __arg1, APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    AROS_LC1NR(void, HostLib_DropInterface,
        AROS_LCA(APTR *,(__arg1),A0),
        APTR , (__HostLibBase), 6, HostLib    );
}

#define HostLib_DropInterface(arg1) \
    __inline_HostLib_HostLib_DropInterface((arg1), __HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void __inline_HostLib_HostLib_Lock(APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    AROS_LC0NR(void, HostLib_Lock,
        APTR , (__HostLibBase), 7, HostLib    );
}

#define HostLib_Lock() \
    __inline_HostLib_HostLib_Lock(__HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

static inline void __inline_HostLib_HostLib_Unlock(APTR __HostLibBase)
{
    AROS_LIBREQ(HostLibBase, 3)
    AROS_LC0NR(void, HostLib_Unlock,
        APTR , (__HostLibBase), 8, HostLib    );
}

#define HostLib_Unlock() \
    __inline_HostLib_HostLib_Unlock(__HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#endif /* INLINE_HOSTLIB_H*/
