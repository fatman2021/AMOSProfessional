#ifndef DEFINES_HOSTLIB_H
#define DEFINES_HOSTLIB_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/all-hosted/hostlib/hostlib.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for hostlib
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__HOSTLIB_LIBBASE)
#    define __HOSTLIB_LIBBASE HostLibBase
#endif

__BEGIN_DECLS


#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_Open_WB(__HostLibBase, __arg1, __arg2) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC2(void *, HostLib_Open, \
                  AROS_LCA(const char *,(__arg1),A0), \
                  AROS_LCA(char **,(__arg2),A1), \
        APTR , (__HostLibBase), 1, HostLib);\
})

#define HostLib_Open(arg1, arg2) \
    __HostLib_Open_WB(__HOSTLIB_LIBBASE, (arg1), (arg2))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_Close_WB(__HostLibBase, __arg1, __arg2) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC2(int, HostLib_Close, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(char **,(__arg2),A1), \
        APTR , (__HostLibBase), 2, HostLib);\
})

#define HostLib_Close(arg1, arg2) \
    __HostLib_Close_WB(__HOSTLIB_LIBBASE, (arg1), (arg2))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_GetPointer_WB(__HostLibBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC3(void *, HostLib_GetPointer, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(const char *,(__arg2),A1), \
                  AROS_LCA(char **,(__arg3),A2), \
        APTR , (__HostLibBase), 3, HostLib);\
})

#define HostLib_GetPointer(arg1, arg2, arg3) \
    __HostLib_GetPointer_WB(__HOSTLIB_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_FreeErrorStr_WB(__HostLibBase, __arg1) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC1NR(void, HostLib_FreeErrorStr, \
                  AROS_LCA(char *,(__arg1),A0), \
        APTR , (__HostLibBase), 4, HostLib);\
})

#define HostLib_FreeErrorStr(arg1) \
    __HostLib_FreeErrorStr_WB(__HOSTLIB_LIBBASE, (arg1))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_GetInterface_WB(__HostLibBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC3(APTR *, HostLib_GetInterface, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(const char **,(__arg2),A1), \
                  AROS_LCA(ULONG *,(__arg3),A2), \
        APTR , (__HostLibBase), 5, HostLib);\
})

#define HostLib_GetInterface(arg1, arg2, arg3) \
    __HostLib_GetInterface_WB(__HOSTLIB_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_DropInterface_WB(__HostLibBase, __arg1) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC1NR(void, HostLib_DropInterface, \
                  AROS_LCA(APTR *,(__arg1),A0), \
        APTR , (__HostLibBase), 6, HostLib);\
})

#define HostLib_DropInterface(arg1) \
    __HostLib_DropInterface_WB(__HOSTLIB_LIBBASE, (arg1))

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_Lock_WB(__HostLibBase) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC0NR(void, HostLib_Lock, \
        APTR , (__HostLibBase), 7, HostLib);\
})

#define HostLib_Lock() \
    __HostLib_Lock_WB(__HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

#if !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__)

#define __HostLib_Unlock_WB(__HostLibBase) ({\
        AROS_LIBREQ(HostLibBase,3)\
        AROS_LC0NR(void, HostLib_Unlock, \
        APTR , (__HostLibBase), 8, HostLib);\
})

#define HostLib_Unlock() \
    __HostLib_Unlock_WB(__HOSTLIB_LIBBASE)

#endif /* !defined(__HOSTLIB_LIBAPI__) || (3 <= __HOSTLIB_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_HOSTLIB_H*/
