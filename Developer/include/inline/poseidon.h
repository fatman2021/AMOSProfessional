#ifndef INLINE_POSEIDON_H
#define INLINE_POSEIDON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/usb/poseidon/poseidon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for poseidon
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__POSEIDON_LIBBASE)
#    define __POSEIDON_LIBBASE ps
#endif


#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAllocVec(ULONG __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdAllocVec,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__ps), 5, psd    );
}

#define psdAllocVec(arg1) \
    __inline_psd_psdAllocVec((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdFreeVec(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdFreeVec,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 6, psd    );
}

#define psdFreeVec(arg1) \
    __inline_psd_psdFreeVec((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdLockWritePBase(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdLockWritePBase,
        struct Library *, (__ps), 7, psd    );
}

#define psdLockWritePBase() \
    __inline_psd_psdLockWritePBase(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdLockReadPBase(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdLockReadPBase,
        struct Library *, (__ps), 8, psd    );
}

#define psdLockReadPBase() \
    __inline_psd_psdLockReadPBase(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdUnlockPBase(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdUnlockPBase,
        struct Library *, (__ps), 9, psd    );
}

#define psdUnlockPBase() \
    __inline_psd_psdUnlockPBase(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdCopyStr(CONST_STRPTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(STRPTR, psdCopyStr,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct Library *, (__ps), 10, psd    );
}

#define psdCopyStr(arg1) \
    __inline_psd_psdCopyStr((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdDelayMS(ULONG __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdDelayMS,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__ps), 11, psd    );
}

#define psdDelayMS(arg1) \
    __inline_psd_psdDelayMS((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAddHardware(STRPTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdAddHardware,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 12, psd    );
}

#define psdAddHardware(arg1, arg2) \
    __inline_psd_psdAddHardware((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdRemHardware(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdRemHardware,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 13, psd    );
}

#define psdRemHardware(arg1) \
    __inline_psd_psdRemHardware((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdEnumerateHardware(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdEnumerateHardware,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 14, psd    );
}

#define psdEnumerateHardware(arg1) \
    __inline_psd_psdEnumerateHardware((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAllocDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdAllocDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 15, psd    );
}

#define psdAllocDevice(arg1) \
    __inline_psd_psdAllocDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdFreeDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdFreeDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 16, psd    );
}

#define psdFreeDevice(arg1) \
    __inline_psd_psdFreeDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdLockReadDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdLockReadDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 17, psd    );
}

#define psdLockReadDevice(arg1) \
    __inline_psd_psdLockReadDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdLockWriteDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdLockWriteDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 18, psd    );
}

#define psdLockWriteDevice(arg1) \
    __inline_psd_psdLockWriteDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdUnlockDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdUnlockDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 19, psd    );
}

#define psdUnlockDevice(arg1) \
    __inline_psd_psdUnlockDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdEnumerateDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdEnumerateDevice,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 20, psd    );
}

#define psdEnumerateDevice(arg1) \
    __inline_psd_psdEnumerateDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdGetNextDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdGetNextDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 21, psd    );
}

#define psdGetNextDevice(arg1) \
    __inline_psd_psdGetNextDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdGetAttrsA(ULONG __arg1, APTR __arg2, struct TagItem * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(LONG, psdGetAttrsA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__ps), 22, psd    );
}

#define psdGetAttrsA(arg1, arg2, arg3) \
    __inline_psd_psdGetAttrsA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdGetAttrs(arg1, arg2, ...) \
({ \
    const IPTR psdGetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdGetAttrsA((arg1), (arg2), (struct TagItem *)(psdGetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdSetAttrsA(ULONG __arg1, APTR __arg2, struct TagItem * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(LONG, psdSetAttrsA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__ps), 23, psd    );
}

#define psdSetAttrsA(arg1, arg2, arg3) \
    __inline_psd_psdSetAttrsA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdSetAttrs(arg1, arg2, ...) \
({ \
    const IPTR psdSetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdSetAttrsA((arg1), (arg2), (struct TagItem *)(psdSetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAllocPipe(APTR __arg1, struct MsgPort * __arg2, APTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(APTR, psdAllocPipe,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct MsgPort *,(__arg2),A1),
        AROS_LCA(APTR,(__arg3),A2),
        struct Library *, (__ps), 24, psd    );
}

#define psdAllocPipe(arg1, arg2, arg3) \
    __inline_psd_psdAllocPipe((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFreePipe(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdFreePipe,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 25, psd    );
}

#define psdFreePipe(arg1) \
    __inline_psd_psdFreePipe((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdPipeSetup(APTR __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, UWORD __arg5, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC5NR(VOID, psdPipeSetup,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        struct Library *, (__ps), 26, psd    );
}

#define psdPipeSetup(arg1, arg2, arg3, arg4, arg5) \
    __inline_psd_psdPipeSetup((arg1), (arg2), (arg3), (arg4), (arg5), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdDoPipe(APTR __arg1, APTR __arg2, ULONG __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(LONG, psdDoPipe,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        struct Library *, (__ps), 27, psd    );
}

#define psdDoPipe(arg1, arg2, arg3) \
    __inline_psd_psdDoPipe((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdSendPipe(APTR __arg1, APTR __arg2, ULONG __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC3NR(VOID, psdSendPipe,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        struct Library *, (__ps), 28, psd    );
}

#define psdSendPipe(arg1, arg2, arg3) \
    __inline_psd_psdSendPipe((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdAbortPipe(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdAbortPipe,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 29, psd    );
}

#define psdAbortPipe(arg1) \
    __inline_psd_psdAbortPipe((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdWaitPipe(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdWaitPipe,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 30, psd    );
}

#define psdWaitPipe(arg1) \
    __inline_psd_psdWaitPipe((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline ULONG __inline_psd_psdGetPipeActual(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(ULONG, psdGetPipeActual,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 31, psd    );
}

#define psdGetPipeActual(arg1) \
    __inline_psd_psdGetPipeActual((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdGetPipeError(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdGetPipeError,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 32, psd    );
}

#define psdGetPipeError(arg1) \
    __inline_psd_psdGetPipeError((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdGetStringDescriptor(APTR __arg1, UWORD __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(STRPTR, psdGetStringDescriptor,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        struct Library *, (__ps), 33, psd    );
}

#define psdGetStringDescriptor(arg1, arg2) \
    __inline_psd_psdGetStringDescriptor((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSetDeviceConfig(APTR __arg1, UWORD __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdSetDeviceConfig,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(UWORD,(__arg2),D0),
        struct Library *, (__ps), 34, psd    );
}

#define psdSetDeviceConfig(arg1, arg2) \
    __inline_psd_psdSetDeviceConfig((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAddClass(STRPTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdAddClass,
        AROS_LCA(STRPTR,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 35, psd    );
}

#define psdAddClass(arg1, arg2) \
    __inline_psd_psdAddClass((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdRemClass(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdRemClass,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 36, psd    );
}

#define psdRemClass(arg1) \
    __inline_psd_psdRemClass((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdClassScan(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdClassScan,
        struct Library *, (__ps), 37, psd    );
}

#define psdClassScan() \
    __inline_psd_psdClassScan(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdNumToStr(UWORD __arg1, LONG __arg2, STRPTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(STRPTR, psdNumToStr,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        AROS_LCA(STRPTR,(__arg3),A0),
        struct Library *, (__ps), 38, psd    );
}

#define psdNumToStr(arg1, arg2, arg3) \
    __inline_psd_psdNumToStr((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline struct Task * __inline_psd_psdSpawnSubTask(STRPTR __arg1, APTR __arg2, APTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(struct Task *, psdSpawnSubTask,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(APTR,(__arg3),A2),
        struct Library *, (__ps), 39, psd    );
}

#define psdSpawnSubTask(arg1, arg2, arg3) \
    __inline_psd_psdSpawnSubTask((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAddErrorMsgA(UWORD __arg1, STRPTR __arg2, STRPTR __arg3, RAWARG __arg4, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC4(APTR, psdAddErrorMsgA,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(STRPTR,(__arg2),A0),
        AROS_LCA(STRPTR,(__arg3),A1),
        AROS_LCA(RAWARG,(__arg4),A2),
        struct Library *, (__ps), 40, psd    );
}

#define psdAddErrorMsgA(arg1, arg2, arg3, arg4) \
    __inline_psd_psdAddErrorMsgA((arg1), (arg2), (arg3), (arg4), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline APTR __inline_psd_psdAddErrorMsg(struct Library * __ps, UWORD __arg1, STRPTR __arg2, STRPTR __arg3, ...)
{
    APTR retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg3);
    retval = __inline_psd_psdAddErrorMsgA(__arg1, __arg2, __arg3, AROS_SLOWSTACKFORMAT_ARG(__arg3), __ps);
    AROS_SLOWSTACKFORMAT_POST(__arg3);
    return retval;
}

#define psdAddErrorMsg(arg1, arg2, ...) \
    __inline_psd_psdAddErrorMsg((struct Library *)__POSEIDON_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdRemErrorMsg(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdRemErrorMsg,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 41, psd    );
}

#define psdRemErrorMsg(arg1) \
    __inline_psd_psdRemErrorMsg((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdSafeRawDoFmtA(STRPTR __arg1, ULONG __arg2, CONST_STRPTR __arg3, RAWARG __arg4, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC4NR(VOID, psdSafeRawDoFmtA,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(CONST_STRPTR,(__arg3),A1),
        AROS_LCA(RAWARG,(__arg4),A2),
        struct Library *, (__ps), 42, psd    );
}

#define psdSafeRawDoFmtA(arg1, arg2, arg3, arg4) \
    __inline_psd_psdSafeRawDoFmtA((arg1), (arg2), (arg3), (arg4), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline VOID __inline_psd_psdSafeRawDoFmt(struct Library * __ps, STRPTR __arg1, ULONG __arg2, CONST_STRPTR __arg3, ...)
{

    AROS_SLOWSTACKFORMAT_PRE(__arg3);
    __inline_psd_psdSafeRawDoFmtA(__arg1, __arg2, __arg3, AROS_SLOWSTACKFORMAT_ARG(__arg3), __ps);
    AROS_SLOWSTACKFORMAT_POST(__arg3);
    return;
}

#define psdSafeRawDoFmt(arg1, arg2, ...) \
    __inline_psd_psdSafeRawDoFmt((struct Library *)__POSEIDON_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSetAltInterface(APTR __arg1, APTR __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdSetAltInterface,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A0),
        struct Library *, (__ps), 43, psd    );
}

#define psdSetAltInterface(arg1, arg2) \
    __inline_psd_psdSetAltInterface((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFindDeviceA(APTR __arg1, struct TagItem * __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdFindDeviceA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__ps), 44, psd    );
}

#define psdFindDeviceA(arg1, arg2) \
    __inline_psd_psdFindDeviceA((arg1), (arg2), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindDevice(arg1, ...) \
({ \
    const IPTR psdFindDeviceA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindDeviceA((arg1), (struct TagItem *)(psdFindDeviceA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdClaimAppBindingA(struct TagItem * __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdClaimAppBindingA,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct Library *, (__ps), 45, psd    );
}

#define psdClaimAppBindingA(arg1) \
    __inline_psd_psdClaimAppBindingA((arg1), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdClaimAppBinding(...) \
({ \
    const IPTR psdClaimAppBindingA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdClaimAppBindingA((struct TagItem *)(psdClaimAppBindingA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdReleaseAppBinding(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdReleaseAppBinding,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 46, psd    );
}

#define psdReleaseAppBinding(arg1) \
    __inline_psd_psdReleaseAppBinding((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAddEventHandler(struct MsgPort * __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdAddEventHandler,
        AROS_LCA(struct MsgPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 47, psd    );
}

#define psdAddEventHandler(arg1, arg2) \
    __inline_psd_psdAddEventHandler((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdRemEventHandler(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdRemEventHandler,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 48, psd    );
}

#define psdRemEventHandler(arg1) \
    __inline_psd_psdRemEventHandler((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdSendEvent(ULONG __arg1, APTR __arg2, APTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC3NR(VOID, psdSendEvent,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(APTR,(__arg3),A1),
        struct Library *, (__ps), 49, psd    );
}

#define psdSendEvent(arg1, arg2, arg3) \
    __inline_psd_psdSendEvent((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdReleaseDevBinding(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdReleaseDevBinding,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 50, psd    );
}

#define psdReleaseDevBinding(arg1) \
    __inline_psd_psdReleaseDevBinding((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdReleaseIfBinding(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdReleaseIfBinding,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 51, psd    );
}

#define psdReleaseIfBinding(arg1) \
    __inline_psd_psdReleaseIfBinding((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdReadCfg(APTR __arg1, APTR __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdReadCfg,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Library *, (__ps), 52, psd    );
}

#define psdReadCfg(arg1, arg2) \
    __inline_psd_psdReadCfg((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdWriteCfg(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdWriteCfg,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 53, psd    );
}

#define psdWriteCfg(arg1) \
    __inline_psd_psdWriteCfg((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFindCfgForm(APTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdFindCfgForm,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 54, psd    );
}

#define psdFindCfgForm(arg1, arg2) \
    __inline_psd_psdFindCfgForm((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdNextCfgForm(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdNextCfgForm,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 55, psd    );
}

#define psdNextCfgForm(arg1) \
    __inline_psd_psdNextCfgForm((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdRemCfgForm(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdRemCfgForm,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 56, psd    );
}

#define psdRemCfgForm(arg1) \
    __inline_psd_psdRemCfgForm((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAddCfgEntry(APTR __arg1, APTR __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdAddCfgEntry,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Library *, (__ps), 57, psd    );
}

#define psdAddCfgEntry(arg1, arg2) \
    __inline_psd_psdAddCfgEntry((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdRemCfgChunk(APTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdRemCfgChunk,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 58, psd    );
}

#define psdRemCfgChunk(arg1, arg2) \
    __inline_psd_psdRemCfgChunk((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdGetCfgChunk(APTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdGetCfgChunk,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 59, psd    );
}

#define psdGetCfgChunk(arg1, arg2) \
    __inline_psd_psdGetCfgChunk((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdParseCfg(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdParseCfg,
        struct Library *, (__ps), 60, psd    );
}

#define psdParseCfg() \
    __inline_psd_psdParseCfg(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdUnbindAll(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdUnbindAll,
        struct Library *, (__ps), 61, psd    );
}

#define psdUnbindAll() \
    __inline_psd_psdUnbindAll(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSetClsCfg(STRPTR __arg1, APTR __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdSetClsCfg,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Library *, (__ps), 62, psd    );
}

#define psdSetClsCfg(arg1, arg2) \
    __inline_psd_psdSetClsCfg((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdGetClsCfg(STRPTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdGetClsCfg,
        AROS_LCA(STRPTR,(__arg1),A0),
        struct Library *, (__ps), 63, psd    );
}

#define psdGetClsCfg(arg1) \
    __inline_psd_psdGetClsCfg((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSetUsbDevCfg(STRPTR __arg1, STRPTR __arg2, STRPTR __arg3, APTR __arg4, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC4(BOOL, psdSetUsbDevCfg,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A2),
        AROS_LCA(STRPTR,(__arg3),A3),
        AROS_LCA(APTR,(__arg4),A1),
        struct Library *, (__ps), 64, psd    );
}

#define psdSetUsbDevCfg(arg1, arg2, arg3, arg4) \
    __inline_psd_psdSetUsbDevCfg((arg1), (arg2), (arg3), (arg4), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdGetUsbDevCfg(STRPTR __arg1, STRPTR __arg2, STRPTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(APTR, psdGetUsbDevCfg,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A2),
        AROS_LCA(STRPTR,(__arg3),A3),
        struct Library *, (__ps), 65, psd    );
}

#define psdGetUsbDevCfg(arg1, arg2, arg3) \
    __inline_psd_psdGetUsbDevCfg((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFindInterfaceA(APTR __arg1, APTR __arg2, struct TagItem * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(APTR, psdFindInterfaceA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__ps), 66, psd    );
}

#define psdFindInterfaceA(arg1, arg2, arg3) \
    __inline_psd_psdFindInterfaceA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindInterface(arg1, arg2, ...) \
({ \
    const IPTR psdFindInterfaceA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindInterfaceA((arg1), (arg2), (struct TagItem *)(psdFindInterfaceA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFindEndpointA(APTR __arg1, APTR __arg2, struct TagItem * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(APTR, psdFindEndpointA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__ps), 67, psd    );
}

#define psdFindEndpointA(arg1, arg2, arg3) \
    __inline_psd_psdFindEndpointA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindEndpoint(arg1, arg2, ...) \
({ \
    const IPTR psdFindEndpointA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindEndpointA((arg1), (arg2), (struct TagItem *)(psdFindEndpointA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdCopyStrFmtA(CONST_STRPTR __arg1, RAWARG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(STRPTR, psdCopyStrFmtA,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(RAWARG,(__arg2),A1),
        struct Library *, (__ps), 68, psd    );
}

#define psdCopyStrFmtA(arg1, arg2) \
    __inline_psd_psdCopyStrFmtA((arg1), (arg2), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline STRPTR __inline_psd_psdCopyStrFmt(struct Library * __ps, CONST_STRPTR __arg1, ...)
{
    STRPTR retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg1);
    retval = __inline_psd_psdCopyStrFmtA(__arg1, AROS_SLOWSTACKFORMAT_ARG(__arg1), __ps);
    AROS_SLOWSTACKFORMAT_POST(__arg1);
    return retval;
}

#define psdCopyStrFmt(...) \
    __inline_psd_psdCopyStrFmt((struct Library *)__POSEIDON_LIBBASE, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSetForcedBinding(STRPTR __arg1, STRPTR __arg2, STRPTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(BOOL, psdSetForcedBinding,
        AROS_LCA(STRPTR,(__arg1),A2),
        AROS_LCA(STRPTR,(__arg2),A0),
        AROS_LCA(STRPTR,(__arg3),A1),
        struct Library *, (__ps), 69, psd    );
}

#define psdSetForcedBinding(arg1, arg2, arg3) \
    __inline_psd_psdSetForcedBinding((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdGetForcedBinding(STRPTR __arg1, STRPTR __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(STRPTR, psdGetForcedBinding,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        struct Library *, (__ps), 70, psd    );
}

#define psdGetForcedBinding(arg1, arg2) \
    __inline_psd_psdGetForcedBinding((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdCheckPipe(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdCheckPipe,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 71, psd    );
}

#define psdCheckPipe(arg1) \
    __inline_psd_psdCheckPipe((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdOpenStreamA(APTR __arg1, struct TagItem * __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdOpenStreamA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__ps), 72, psd    );
}

#define psdOpenStreamA(arg1, arg2) \
    __inline_psd_psdOpenStreamA((arg1), (arg2), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdOpenStream(arg1, ...) \
({ \
    const IPTR psdOpenStreamA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdOpenStreamA((arg1), (struct TagItem *)(psdOpenStreamA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdCloseStream(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdCloseStream,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 73, psd    );
}

#define psdCloseStream(arg1) \
    __inline_psd_psdCloseStream((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdStreamRead(APTR __arg1, APTR __arg2, LONG __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(LONG, psdStreamRead,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__ps), 74, psd    );
}

#define psdStreamRead(arg1, arg2, arg3) \
    __inline_psd_psdStreamRead((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdStreamWrite(APTR __arg1, APTR __arg2, LONG __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(LONG, psdStreamWrite,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__ps), 75, psd    );
}

#define psdStreamWrite(arg1, arg2, arg3) \
    __inline_psd_psdStreamWrite((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdStreamFlush(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdStreamFlush,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 76, psd    );
}

#define psdStreamFlush(arg1) \
    __inline_psd_psdStreamFlush((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdGetStreamError(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdGetStreamError,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 77, psd    );
}

#define psdGetStreamError(arg1) \
    __inline_psd_psdGetStreamError((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdCalculatePower(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdCalculatePower,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 78, psd    );
}

#define psdCalculatePower(arg1) \
    __inline_psd_psdCalculatePower((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdLoadCfgFromDisk(STRPTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdLoadCfgFromDisk,
        AROS_LCA(STRPTR,(__arg1),A1),
        struct Library *, (__ps), 79, psd    );
}

#define psdLoadCfgFromDisk(arg1) \
    __inline_psd_psdLoadCfgFromDisk((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSaveCfgToDisk(STRPTR __arg1, BOOL __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(BOOL, psdSaveCfgToDisk,
        AROS_LCA(STRPTR,(__arg1),A1),
        AROS_LCA(BOOL,(__arg2),D0),
        struct Library *, (__ps), 80, psd    );
}

#define psdSaveCfgToDisk(arg1, arg2) \
    __inline_psd_psdSaveCfgToDisk((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdDebugSemaphores(APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC0NR(VOID, psdDebugSemaphores,
        struct Library *, (__ps), 81, psd    );
}

#define psdDebugSemaphores() \
    __inline_psd_psdDebugSemaphores(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdHubClassScan(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdHubClassScan,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 82, psd    );
}

#define psdHubClassScan(arg1) \
    __inline_psd_psdHubClassScan((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdHubClaimAppBindingA(struct TagItem * __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdHubClaimAppBindingA,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct Library *, (__ps), 83, psd    );
}

#define psdHubClaimAppBindingA(arg1) \
    __inline_psd_psdHubClaimAppBindingA((arg1), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdHubClaimAppBinding(...) \
({ \
    const IPTR psdHubClaimAppBindingA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdHubClaimAppBindingA((struct TagItem *)(psdHubClaimAppBindingA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdHubReleaseDevBinding(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdHubReleaseDevBinding,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 84, psd    );
}

#define psdHubReleaseDevBinding(arg1) \
    __inline_psd_psdHubReleaseDevBinding((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdHubReleaseIfBinding(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdHubReleaseIfBinding,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 85, psd    );
}

#define psdHubReleaseIfBinding(arg1) \
    __inline_psd_psdHubReleaseIfBinding((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAllocCfgForm(ULONG __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(APTR, psdAllocCfgForm,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__ps), 86, psd    );
}

#define psdAllocCfgForm(arg1) \
    __inline_psd_psdAllocCfgForm((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdAddStringChunk(APTR __arg1, ULONG __arg2, CONST_STRPTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(BOOL, psdAddStringChunk,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(CONST_STRPTR,(__arg3),A1),
        struct Library *, (__ps), 87, psd    );
}

#define psdAddStringChunk(arg1, arg2, arg3) \
    __inline_psd_psdAddStringChunk((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdMatchStringChunk(APTR __arg1, ULONG __arg2, CONST_STRPTR __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(BOOL, psdMatchStringChunk,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(CONST_STRPTR,(__arg3),A1),
        struct Library *, (__ps), 88, psd    );
}

#define psdMatchStringChunk(arg1, arg2, arg3) \
    __inline_psd_psdMatchStringChunk((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline STRPTR __inline_psd_psdGetStringChunk(APTR __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(STRPTR, psdGetStringChunk,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 89, psd    );
}

#define psdGetStringChunk(arg1, arg2) \
    __inline_psd_psdGetStringChunk((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdFindDescriptorA(APTR __arg1, APTR __arg2, struct TagItem * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(APTR, psdFindDescriptorA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__ps), 91, psd    );
}

#define psdFindDescriptorA(arg1, arg2, arg3) \
    __inline_psd_psdFindDescriptorA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindDescriptor(arg1, arg2, ...) \
({ \
    const IPTR psdFindDescriptorA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindDescriptorA((arg1), (arg2), (struct TagItem *)(psdFindDescriptorA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline IPTR __inline_psd_psdDoHubMethodA(APTR __arg1, ULONG __arg2, IPTR * __arg3, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC3(IPTR, psdDoHubMethodA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(IPTR *,(__arg3),A1),
        struct Library *, (__ps), 92, psd    );
}

#define psdDoHubMethodA(arg1, arg2, arg3) \
    __inline_psd_psdDoHubMethodA((arg1), (arg2), (arg3), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdDoHubMethod(arg1, arg2, ...) \
({ \
    const IPTR psdDoHubMethodA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdDoHubMethodA((arg1), (arg2), (IPTR *)(psdDoHubMethodA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline APTR __inline_psd_psdAllocRTIsoHandlerA(APTR __arg1, struct TagItem * __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(APTR, psdAllocRTIsoHandlerA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__ps), 93, psd    );
}

#define psdAllocRTIsoHandlerA(arg1, arg2) \
    __inline_psd_psdAllocRTIsoHandlerA((arg1), (arg2), __POSEIDON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdAllocRTIsoHandler(arg1, ...) \
({ \
    const IPTR psdAllocRTIsoHandlerA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdAllocRTIsoHandlerA((arg1), (struct TagItem *)(psdAllocRTIsoHandlerA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline VOID __inline_psd_psdFreeRTIsoHandler(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    AROS_LC1NR(VOID, psdFreeRTIsoHandler,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 94, psd    );
}

#define psdFreeRTIsoHandler(arg1) \
    __inline_psd_psdFreeRTIsoHandler((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdStartRTIso(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdStartRTIso,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 95, psd    );
}

#define psdStartRTIso(arg1) \
    __inline_psd_psdStartRTIso((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline LONG __inline_psd_psdStopRTIso(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(LONG, psdStopRTIso,
        AROS_LCA(APTR,(__arg1),A1),
        struct Library *, (__ps), 96, psd    );
}

#define psdStopRTIso(arg1) \
    __inline_psd_psdStopRTIso((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline ULONG __inline_psd_psdBorrowLocksWait(struct Task * __arg1, ULONG __arg2, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC2(ULONG, psdBorrowLocksWait,
        AROS_LCA(struct Task *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ps), 97, psd    );
}

#define psdBorrowLocksWait(arg1, arg2) \
    __inline_psd_psdBorrowLocksWait((arg1), (arg2), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSuspendDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdSuspendDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 98, psd    );
}

#define psdSuspendDevice(arg1) \
    __inline_psd_psdSuspendDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdResumeDevice(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdResumeDevice,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 99, psd    );
}

#define psdResumeDevice(arg1) \
    __inline_psd_psdResumeDevice((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdSuspendBindings(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdSuspendBindings,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 100, psd    );
}

#define psdSuspendBindings(arg1) \
    __inline_psd_psdSuspendBindings((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

static inline BOOL __inline_psd_psdResumeBindings(APTR __arg1, APTR __ps)
{
    AROS_LIBREQ(ps, 4)
    return AROS_LC1(BOOL, psdResumeBindings,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ps), 101, psd    );
}

#define psdResumeBindings(arg1) \
    __inline_psd_psdResumeBindings((arg1), __POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#endif /* INLINE_POSEIDON_H*/
