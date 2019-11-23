#ifndef DEFINES_REXXSYSLIB_H
#define DEFINES_REXXSYSLIB_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/rexxsyslib/rexxsyslib.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for rexxsyslib
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REXXSYSLIB_LIBBASE)
#    define __REXXSYSLIB_LIBBASE RexxSysBase
#endif

__BEGIN_DECLS


#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __CreateArgstring_WB(__RexxSysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC2(UBYTE *, CreateArgstring, \
                  AROS_LCA(CONST UBYTE *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct RxsLib *, (__RexxSysBase), 21, RexxSys);\
})

#define CreateArgstring(arg1, arg2) \
    __CreateArgstring_WB(__REXXSYSLIB_LIBBASE, (arg1), (arg2))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __DeleteArgstring_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1NR(void, DeleteArgstring, \
                  AROS_LCA(UBYTE *,(__arg1),A0), \
        struct RxsLib *, (__RexxSysBase), 22, RexxSys);\
})

#define DeleteArgstring(arg1) \
    __DeleteArgstring_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __LengthArgstring_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1(ULONG, LengthArgstring, \
                  AROS_LCA(UBYTE *,(__arg1),A0), \
        struct RxsLib *, (__RexxSysBase), 23, RexxSys);\
})

#define LengthArgstring(arg1) \
    __LengthArgstring_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __CreateRexxMsg_WB(__RexxSysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC3(struct RexxMsg *, CreateRexxMsg, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
                  AROS_LCA(UBYTE *,(__arg3),D0), \
        struct RxsLib *, (__RexxSysBase), 24, RexxSys);\
})

#define CreateRexxMsg(arg1, arg2, arg3) \
    __CreateRexxMsg_WB(__REXXSYSLIB_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __DeleteRexxMsg_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1NR(void, DeleteRexxMsg, \
                  AROS_LCA(struct RexxMsg *,(__arg1),A0), \
        struct RxsLib *, (__RexxSysBase), 25, RexxSys);\
})

#define DeleteRexxMsg(arg1) \
    __DeleteRexxMsg_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __ClearRexxMsg_WB(__RexxSysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC2NR(void, ClearRexxMsg, \
                  AROS_LCA(struct RexxMsg *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct RxsLib *, (__RexxSysBase), 26, RexxSys);\
})

#define ClearRexxMsg(arg1, arg2) \
    __ClearRexxMsg_WB(__REXXSYSLIB_LIBBASE, (arg1), (arg2))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __FillRexxMsg_WB(__RexxSysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC3(BOOL, FillRexxMsg, \
                  AROS_LCA(struct RexxMsg *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct RxsLib *, (__RexxSysBase), 27, RexxSys);\
})

#define FillRexxMsg(arg1, arg2, arg3) \
    __FillRexxMsg_WB(__REXXSYSLIB_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __IsRexxMsg_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1(BOOL, IsRexxMsg, \
                  AROS_LCA(struct RexxMsg *,(__arg1),A0), \
        struct RxsLib *, (__RexxSysBase), 28, RexxSys);\
})

#define IsRexxMsg(arg1) \
    __IsRexxMsg_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __LockRexxBase_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1NR(void, LockRexxBase, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct RxsLib *, (__RexxSysBase), 75, RexxSys);\
})

#define LockRexxBase(arg1) \
    __LockRexxBase_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

#if !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__)

#define __UnlockRexxBase_WB(__RexxSysBase, __arg1) ({\
        AROS_LIBREQ(RexxSysBase,33)\
        AROS_LC1NR(void, UnlockRexxBase, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct RxsLib *, (__RexxSysBase), 76, RexxSys);\
})

#define UnlockRexxBase(arg1) \
    __UnlockRexxBase_WB(__REXXSYSLIB_LIBBASE, (arg1))

#endif /* !defined(__REXXSYSLIB_LIBAPI__) || (33 <= __REXXSYSLIB_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_REXXSYSLIB_H*/
