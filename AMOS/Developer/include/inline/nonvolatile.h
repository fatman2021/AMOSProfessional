#ifndef INLINE_NONVOLATILE_H
#define INLINE_NONVOLATILE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/nonvolatile/nonvolatile.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for nonvolatile
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__NONVOLATILE_LIBBASE)
#    define __NONVOLATILE_LIBBASE NonvolatileBase
#endif


#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline APTR __inline_Nonvolatile_GetCopyNV(STRPTR __arg1, STRPTR __arg2, BOOL __arg3, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC3(APTR, GetCopyNV,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D1),
        struct Library *, (__NonvolatileBase), 5, Nonvolatile    );
}

#define GetCopyNV(arg1, arg2, arg3) \
    __inline_Nonvolatile_GetCopyNV((arg1), (arg2), (arg3), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline void __inline_Nonvolatile_FreeNVData(APTR __arg1, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    AROS_LC1NR(void, FreeNVData,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__NonvolatileBase), 6, Nonvolatile    );
}

#define FreeNVData(arg1) \
    __inline_Nonvolatile_FreeNVData((arg1), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline LONG __inline_Nonvolatile_StoreNV(STRPTR __arg1, STRPTR __arg2, APTR __arg3, ULONG __arg4, BOOL __arg5, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC5(LONG, StoreNV,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(APTR,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(BOOL,(__arg5),D1),
        struct Library *, (__NonvolatileBase), 7, Nonvolatile    );
}

#define StoreNV(arg1, arg2, arg3, arg4, arg5) \
    __inline_Nonvolatile_StoreNV((arg1), (arg2), (arg3), (arg4), (arg5), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline BOOL __inline_Nonvolatile_DeleteNV(STRPTR __arg1, STRPTR __arg2, BOOL __arg3, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC3(BOOL, DeleteNV,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D1),
        struct Library *, (__NonvolatileBase), 8, Nonvolatile    );
}

#define DeleteNV(arg1, arg2, arg3) \
    __inline_Nonvolatile_DeleteNV((arg1), (arg2), (arg3), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline struct NVInfo * __inline_Nonvolatile_GetNVInfo(BOOL __arg1, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC1(struct NVInfo *, GetNVInfo,
        AROS_LCA(BOOL,(__arg1),D1),
        struct Library *, (__NonvolatileBase), 9, Nonvolatile    );
}

#define GetNVInfo(arg1) \
    __inline_Nonvolatile_GetNVInfo((arg1), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline struct MinList * __inline_Nonvolatile_GetNVList(STRPTR __arg1, BOOL __arg2, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC2(struct MinList *, GetNVList,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D1),
        struct Library *, (__NonvolatileBase), 10, Nonvolatile    );
}

#define GetNVList(arg1, arg2) \
    __inline_Nonvolatile_GetNVList((arg1), (arg2), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#if !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__)

static inline BOOL __inline_Nonvolatile_SetNVProtection(STRPTR __arg1, STRPTR __arg2, LONG __arg3, BOOL __arg4, APTR __NonvolatileBase)
{
    AROS_LIBREQ(NonvolatileBase, 40)
    return AROS_LC4(BOOL, SetNVProtection,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D2),
        AROS_LCA(BOOL,(__arg4),D1),
        struct Library *, (__NonvolatileBase), 11, Nonvolatile    );
}

#define SetNVProtection(arg1, arg2, arg3, arg4) \
    __inline_Nonvolatile_SetNVProtection((arg1), (arg2), (arg3), (arg4), __NONVOLATILE_LIBBASE)

#endif /* !defined(__NONVOLATILE_LIBAPI__) || (40 <= __NONVOLATILE_LIBAPI__) */

#endif /* INLINE_NONVOLATILE_H*/
