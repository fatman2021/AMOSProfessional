#ifndef INLINE_REXXSYSLIB_H
#define INLINE_REXXSYSLIB_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/rexxsyslib/rexxsyslib.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for rexxsyslib
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REXXSYSLIB_LIBBASE)
#    define __REXXSYSLIB_LIBBASE RexxSysBase
#endif


#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline UBYTE * __inline_RexxSys_CreateArgstring(CONST UBYTE * __arg1, ULONG __arg2, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    return AROS_LC2(UBYTE *, CreateArgstring,
        AROS_LCA(CONST UBYTE *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct RxsLib *, (__RexxSysBase), 21, RexxSys    );
}

#define CreateArgstring(arg1, arg2) \
    __inline_RexxSys_CreateArgstring((arg1), (arg2), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline void __inline_RexxSys_DeleteArgstring(UBYTE * __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    AROS_LC1NR(void, DeleteArgstring,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct RxsLib *, (__RexxSysBase), 22, RexxSys    );
}

#define DeleteArgstring(arg1) \
    __inline_RexxSys_DeleteArgstring((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline ULONG __inline_RexxSys_LengthArgstring(UBYTE * __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    return AROS_LC1(ULONG, LengthArgstring,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct RxsLib *, (__RexxSysBase), 23, RexxSys    );
}

#define LengthArgstring(arg1) \
    __inline_RexxSys_LengthArgstring((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline struct RexxMsg * __inline_RexxSys_CreateRexxMsg(struct MsgPort * __arg1, UBYTE * __arg2, UBYTE * __arg3, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    return AROS_LC3(struct RexxMsg *, CreateRexxMsg,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(UBYTE *,(__arg3),D0),
        struct RxsLib *, (__RexxSysBase), 24, RexxSys    );
}

#define CreateRexxMsg(arg1, arg2, arg3) \
    __inline_RexxSys_CreateRexxMsg((arg1), (arg2), (arg3), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline void __inline_RexxSys_DeleteRexxMsg(struct RexxMsg * __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    AROS_LC1NR(void, DeleteRexxMsg,
        AROS_LCA(struct RexxMsg *,(__arg1),A0),
        struct RxsLib *, (__RexxSysBase), 25, RexxSys    );
}

#define DeleteRexxMsg(arg1) \
    __inline_RexxSys_DeleteRexxMsg((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline void __inline_RexxSys_ClearRexxMsg(struct RexxMsg * __arg1, ULONG __arg2, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    AROS_LC2NR(void, ClearRexxMsg,
        AROS_LCA(struct RexxMsg *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct RxsLib *, (__RexxSysBase), 26, RexxSys    );
}

#define ClearRexxMsg(arg1, arg2) \
    __inline_RexxSys_ClearRexxMsg((arg1), (arg2), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline BOOL __inline_RexxSys_FillRexxMsg(struct RexxMsg * __arg1, ULONG __arg2, ULONG __arg3, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    return AROS_LC3(BOOL, FillRexxMsg,
        AROS_LCA(struct RexxMsg *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct RxsLib *, (__RexxSysBase), 27, RexxSys    );
}

#define FillRexxMsg(arg1, arg2, arg3) \
    __inline_RexxSys_FillRexxMsg((arg1), (arg2), (arg3), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline BOOL __inline_RexxSys_IsRexxMsg(struct RexxMsg * __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    return AROS_LC1(BOOL, IsRexxMsg,
        AROS_LCA(struct RexxMsg *,(__arg1),A0),
        struct RxsLib *, (__RexxSysBase), 28, RexxSys    );
}

#define IsRexxMsg(arg1) \
    __inline_RexxSys_IsRexxMsg((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline void __inline_RexxSys_LockRexxBase(ULONG __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    AROS_LC1NR(void, LockRexxBase,
        AROS_LCA(ULONG,(__arg1),D0),
        struct RxsLib *, (__RexxSysBase), 75, RexxSys    );
}

#define LockRexxBase(arg1) \
    __inline_RexxSys_LockRexxBase((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

static inline void __inline_RexxSys_UnlockRexxBase(ULONG __arg1, APTR __RexxSysBase)
{
    AROS_LIBREQ(RexxSysBase, 33)
    AROS_LC1NR(void, UnlockRexxBase,
        AROS_LCA(ULONG,(__arg1),D0),
        struct RxsLib *, (__RexxSysBase), 76, RexxSys    );
}

#define UnlockRexxBase(arg1) \
    __inline_RexxSys_UnlockRexxBase((arg1), __REXXSYSLIB_LIBBASE)

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#endif /* INLINE_REXXSYSLIB_H*/
