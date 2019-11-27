#ifndef DEFINES_POSEIDON_H
#define DEFINES_POSEIDON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/usb/poseidon/poseidon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for poseidon
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__POSEIDON_LIBBASE)
#    define __POSEIDON_LIBBASE ps
#endif

__BEGIN_DECLS


#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAllocVec_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdAllocVec, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__ps), 5, psd);\
})

#define psdAllocVec(arg1) \
    __psdAllocVec_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFreeVec_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdFreeVec, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 6, psd);\
})

#define psdFreeVec(arg1) \
    __psdFreeVec_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdLockWritePBase_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdLockWritePBase, \
        struct Library *, (__ps), 7, psd);\
})

#define psdLockWritePBase() \
    __psdLockWritePBase_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdLockReadPBase_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdLockReadPBase, \
        struct Library *, (__ps), 8, psd);\
})

#define psdLockReadPBase() \
    __psdLockReadPBase_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdUnlockPBase_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdUnlockPBase, \
        struct Library *, (__ps), 9, psd);\
})

#define psdUnlockPBase() \
    __psdUnlockPBase_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdCopyStr_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(STRPTR, psdCopyStr, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
        struct Library *, (__ps), 10, psd);\
})

#define psdCopyStr(arg1) \
    __psdCopyStr_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdDelayMS_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdDelayMS, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__ps), 11, psd);\
})

#define psdDelayMS(arg1) \
    __psdDelayMS_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddHardware_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdAddHardware, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 12, psd);\
})

#define psdAddHardware(arg1, arg2) \
    __psdAddHardware_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemHardware_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdRemHardware, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 13, psd);\
})

#define psdRemHardware(arg1) \
    __psdRemHardware_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdEnumerateHardware_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdEnumerateHardware, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 14, psd);\
})

#define psdEnumerateHardware(arg1) \
    __psdEnumerateHardware_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAllocDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdAllocDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 15, psd);\
})

#define psdAllocDevice(arg1) \
    __psdAllocDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFreeDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdFreeDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 16, psd);\
})

#define psdFreeDevice(arg1) \
    __psdFreeDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdLockReadDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdLockReadDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 17, psd);\
})

#define psdLockReadDevice(arg1) \
    __psdLockReadDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdLockWriteDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdLockWriteDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 18, psd);\
})

#define psdLockWriteDevice(arg1) \
    __psdLockWriteDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdUnlockDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdUnlockDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 19, psd);\
})

#define psdUnlockDevice(arg1) \
    __psdUnlockDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdEnumerateDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdEnumerateDevice, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 20, psd);\
})

#define psdEnumerateDevice(arg1) \
    __psdEnumerateDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetNextDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdGetNextDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 21, psd);\
})

#define psdGetNextDevice(arg1) \
    __psdGetNextDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetAttrsA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(LONG, psdGetAttrsA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__ps), 22, psd);\
})

#define psdGetAttrsA(arg1, arg2, arg3) \
    __psdGetAttrsA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdGetAttrs(arg1, arg2, ...) \
({ \
    const IPTR psdGetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdGetAttrsA((arg1), (arg2), (struct TagItem *)(psdGetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetAttrsA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(LONG, psdSetAttrsA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__ps), 23, psd);\
})

#define psdSetAttrsA(arg1, arg2, arg3) \
    __psdSetAttrsA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdSetAttrs(arg1, arg2, ...) \
({ \
    const IPTR psdSetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdSetAttrsA((arg1), (arg2), (struct TagItem *)(psdSetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAllocPipe_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(APTR, psdAllocPipe, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct MsgPort *,(__arg2),A1), \
                  AROS_LCA(APTR,(__arg3),A2), \
        struct Library *, (__ps), 24, psd);\
})

#define psdAllocPipe(arg1, arg2, arg3) \
    __psdAllocPipe_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFreePipe_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdFreePipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 25, psd);\
})

#define psdFreePipe(arg1) \
    __psdFreePipe_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdPipeSetup_WB(__ps, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC5NR(VOID, psdPipeSetup, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(UWORD,(__arg5),D3), \
        struct Library *, (__ps), 26, psd);\
})

#define psdPipeSetup(arg1, arg2, arg3, arg4, arg5) \
    __psdPipeSetup_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdDoPipe_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(LONG, psdDoPipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct Library *, (__ps), 27, psd);\
})

#define psdDoPipe(arg1, arg2, arg3) \
    __psdDoPipe_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSendPipe_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3NR(VOID, psdSendPipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct Library *, (__ps), 28, psd);\
})

#define psdSendPipe(arg1, arg2, arg3) \
    __psdSendPipe_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAbortPipe_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdAbortPipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 29, psd);\
})

#define psdAbortPipe(arg1) \
    __psdAbortPipe_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdWaitPipe_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdWaitPipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 30, psd);\
})

#define psdWaitPipe(arg1) \
    __psdWaitPipe_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetPipeActual_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(ULONG, psdGetPipeActual, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 31, psd);\
})

#define psdGetPipeActual(arg1) \
    __psdGetPipeActual_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetPipeError_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdGetPipeError, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 32, psd);\
})

#define psdGetPipeError(arg1) \
    __psdGetPipeError_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetStringDescriptor_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(STRPTR, psdGetStringDescriptor, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
        struct Library *, (__ps), 33, psd);\
})

#define psdGetStringDescriptor(arg1, arg2) \
    __psdGetStringDescriptor_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetDeviceConfig_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdSetDeviceConfig, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(UWORD,(__arg2),D0), \
        struct Library *, (__ps), 34, psd);\
})

#define psdSetDeviceConfig(arg1, arg2) \
    __psdSetDeviceConfig_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddClass_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdAddClass, \
                  AROS_LCA(STRPTR,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 35, psd);\
})

#define psdAddClass(arg1, arg2) \
    __psdAddClass_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemClass_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdRemClass, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 36, psd);\
})

#define psdRemClass(arg1) \
    __psdRemClass_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdClassScan_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdClassScan, \
        struct Library *, (__ps), 37, psd);\
})

#define psdClassScan() \
    __psdClassScan_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdNumToStr_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(STRPTR, psdNumToStr, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
                  AROS_LCA(STRPTR,(__arg3),A0), \
        struct Library *, (__ps), 38, psd);\
})

#define psdNumToStr(arg1, arg2, arg3) \
    __psdNumToStr_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSpawnSubTask_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(struct Task *, psdSpawnSubTask, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(APTR,(__arg3),A2), \
        struct Library *, (__ps), 39, psd);\
})

#define psdSpawnSubTask(arg1, arg2, arg3) \
    __psdSpawnSubTask_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddErrorMsgA_WB(__ps, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC4(APTR, psdAddErrorMsgA, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(STRPTR,(__arg2),A0), \
                  AROS_LCA(STRPTR,(__arg3),A1), \
                  AROS_LCA(RAWARG,(__arg4),A2), \
        struct Library *, (__ps), 40, psd);\
})

#define psdAddErrorMsgA(arg1, arg2, arg3, arg4) \
    __psdAddErrorMsgA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline APTR __inline_psd_psdAddErrorMsg(struct Library * __ps, UWORD __arg1, STRPTR __arg2, STRPTR __arg3, ...)
{
    APTR retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg3);
    retval = __psdAddErrorMsgA_WB(__ps, __arg1, __arg2, __arg3, AROS_SLOWSTACKFORMAT_ARG(__arg3));
    AROS_SLOWSTACKFORMAT_POST(__arg3);
    return retval;
}

#define psdAddErrorMsg(arg1, arg2, ...) \
    __inline_psd_psdAddErrorMsg((struct Library *)__POSEIDON_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemErrorMsg_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdRemErrorMsg, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 41, psd);\
})

#define psdRemErrorMsg(arg1) \
    __psdRemErrorMsg_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSafeRawDoFmtA_WB(__ps, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC4NR(VOID, psdSafeRawDoFmtA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(CONST_STRPTR,(__arg3),A1), \
                  AROS_LCA(RAWARG,(__arg4),A2), \
        struct Library *, (__ps), 42, psd);\
})

#define psdSafeRawDoFmtA(arg1, arg2, arg3, arg4) \
    __psdSafeRawDoFmtA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline VOID __inline_psd_psdSafeRawDoFmt(struct Library * __ps, STRPTR __arg1, ULONG __arg2, CONST_STRPTR __arg3, ...)
{
    AROS_SLOWSTACKFORMAT_PRE(__arg3);
    __psdSafeRawDoFmtA_WB(__ps, __arg1, __arg2, __arg3, AROS_SLOWSTACKFORMAT_ARG(__arg3));
    AROS_SLOWSTACKFORMAT_POST(__arg3);
    return;
}

#define psdSafeRawDoFmt(arg1, arg2, ...) \
    __inline_psd_psdSafeRawDoFmt((struct Library *)__POSEIDON_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetAltInterface_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdSetAltInterface, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A0), \
        struct Library *, (__ps), 43, psd);\
})

#define psdSetAltInterface(arg1, arg2) \
    __psdSetAltInterface_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFindDeviceA_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdFindDeviceA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__ps), 44, psd);\
})

#define psdFindDeviceA(arg1, arg2) \
    __psdFindDeviceA_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindDevice(arg1, ...) \
({ \
    const IPTR psdFindDeviceA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindDeviceA((arg1), (struct TagItem *)(psdFindDeviceA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdClaimAppBindingA_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdClaimAppBindingA, \
                  AROS_LCA(struct TagItem *,(__arg1),A1), \
        struct Library *, (__ps), 45, psd);\
})

#define psdClaimAppBindingA(arg1) \
    __psdClaimAppBindingA_WB(__POSEIDON_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdClaimAppBinding(...) \
({ \
    const IPTR psdClaimAppBindingA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdClaimAppBindingA((struct TagItem *)(psdClaimAppBindingA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdReleaseAppBinding_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdReleaseAppBinding, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 46, psd);\
})

#define psdReleaseAppBinding(arg1) \
    __psdReleaseAppBinding_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddEventHandler_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdAddEventHandler, \
                  AROS_LCA(struct MsgPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 47, psd);\
})

#define psdAddEventHandler(arg1, arg2) \
    __psdAddEventHandler_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemEventHandler_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdRemEventHandler, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 48, psd);\
})

#define psdRemEventHandler(arg1) \
    __psdRemEventHandler_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSendEvent_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3NR(VOID, psdSendEvent, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(APTR,(__arg3),A1), \
        struct Library *, (__ps), 49, psd);\
})

#define psdSendEvent(arg1, arg2, arg3) \
    __psdSendEvent_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdReleaseDevBinding_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdReleaseDevBinding, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 50, psd);\
})

#define psdReleaseDevBinding(arg1) \
    __psdReleaseDevBinding_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdReleaseIfBinding_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdReleaseIfBinding, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 51, psd);\
})

#define psdReleaseIfBinding(arg1) \
    __psdReleaseIfBinding_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdReadCfg_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdReadCfg, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__ps), 52, psd);\
})

#define psdReadCfg(arg1, arg2) \
    __psdReadCfg_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdWriteCfg_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdWriteCfg, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 53, psd);\
})

#define psdWriteCfg(arg1) \
    __psdWriteCfg_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFindCfgForm_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdFindCfgForm, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 54, psd);\
})

#define psdFindCfgForm(arg1, arg2) \
    __psdFindCfgForm_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdNextCfgForm_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdNextCfgForm, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 55, psd);\
})

#define psdNextCfgForm(arg1) \
    __psdNextCfgForm_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemCfgForm_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdRemCfgForm, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 56, psd);\
})

#define psdRemCfgForm(arg1) \
    __psdRemCfgForm_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddCfgEntry_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdAddCfgEntry, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__ps), 57, psd);\
})

#define psdAddCfgEntry(arg1, arg2) \
    __psdAddCfgEntry_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdRemCfgChunk_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdRemCfgChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 58, psd);\
})

#define psdRemCfgChunk(arg1, arg2) \
    __psdRemCfgChunk_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetCfgChunk_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdGetCfgChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 59, psd);\
})

#define psdGetCfgChunk(arg1, arg2) \
    __psdGetCfgChunk_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdParseCfg_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdParseCfg, \
        struct Library *, (__ps), 60, psd);\
})

#define psdParseCfg() \
    __psdParseCfg_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdUnbindAll_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdUnbindAll, \
        struct Library *, (__ps), 61, psd);\
})

#define psdUnbindAll() \
    __psdUnbindAll_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetClsCfg_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdSetClsCfg, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Library *, (__ps), 62, psd);\
})

#define psdSetClsCfg(arg1, arg2) \
    __psdSetClsCfg_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetClsCfg_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdGetClsCfg, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
        struct Library *, (__ps), 63, psd);\
})

#define psdGetClsCfg(arg1) \
    __psdGetClsCfg_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetUsbDevCfg_WB(__ps, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC4(BOOL, psdSetUsbDevCfg, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A2), \
                  AROS_LCA(STRPTR,(__arg3),A3), \
                  AROS_LCA(APTR,(__arg4),A1), \
        struct Library *, (__ps), 64, psd);\
})

#define psdSetUsbDevCfg(arg1, arg2, arg3, arg4) \
    __psdSetUsbDevCfg_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetUsbDevCfg_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(APTR, psdGetUsbDevCfg, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A2), \
                  AROS_LCA(STRPTR,(__arg3),A3), \
        struct Library *, (__ps), 65, psd);\
})

#define psdGetUsbDevCfg(arg1, arg2, arg3) \
    __psdGetUsbDevCfg_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFindInterfaceA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(APTR, psdFindInterfaceA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__ps), 66, psd);\
})

#define psdFindInterfaceA(arg1, arg2, arg3) \
    __psdFindInterfaceA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindInterface(arg1, arg2, ...) \
({ \
    const IPTR psdFindInterfaceA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindInterfaceA((arg1), (arg2), (struct TagItem *)(psdFindInterfaceA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFindEndpointA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(APTR, psdFindEndpointA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__ps), 67, psd);\
})

#define psdFindEndpointA(arg1, arg2, arg3) \
    __psdFindEndpointA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindEndpoint(arg1, arg2, ...) \
({ \
    const IPTR psdFindEndpointA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindEndpointA((arg1), (arg2), (struct TagItem *)(psdFindEndpointA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdCopyStrFmtA_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(STRPTR, psdCopyStrFmtA, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(RAWARG,(__arg2),A1), \
        struct Library *, (__ps), 68, psd);\
})

#define psdCopyStrFmtA(arg1, arg2) \
    __psdCopyStrFmtA_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
static inline STRPTR __inline_psd_psdCopyStrFmt(struct Library * __ps, CONST_STRPTR __arg1, ...)
{
    STRPTR retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg1);
    retval = __psdCopyStrFmtA_WB(__ps, __arg1, AROS_SLOWSTACKFORMAT_ARG(__arg1));
    AROS_SLOWSTACKFORMAT_POST(__arg1);
    return retval;
}

#define psdCopyStrFmt(...) \
    __inline_psd_psdCopyStrFmt((struct Library *)__POSEIDON_LIBBASE, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSetForcedBinding_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(BOOL, psdSetForcedBinding, \
                  AROS_LCA(STRPTR,(__arg1),A2), \
                  AROS_LCA(STRPTR,(__arg2),A0), \
                  AROS_LCA(STRPTR,(__arg3),A1), \
        struct Library *, (__ps), 69, psd);\
})

#define psdSetForcedBinding(arg1, arg2, arg3) \
    __psdSetForcedBinding_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetForcedBinding_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(STRPTR, psdGetForcedBinding, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
        struct Library *, (__ps), 70, psd);\
})

#define psdGetForcedBinding(arg1, arg2) \
    __psdGetForcedBinding_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdCheckPipe_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdCheckPipe, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 71, psd);\
})

#define psdCheckPipe(arg1) \
    __psdCheckPipe_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdOpenStreamA_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdOpenStreamA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__ps), 72, psd);\
})

#define psdOpenStreamA(arg1, arg2) \
    __psdOpenStreamA_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdOpenStream(arg1, ...) \
({ \
    const IPTR psdOpenStreamA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdOpenStreamA((arg1), (struct TagItem *)(psdOpenStreamA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdCloseStream_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdCloseStream, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 73, psd);\
})

#define psdCloseStream(arg1) \
    __psdCloseStream_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdStreamRead_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(LONG, psdStreamRead, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__ps), 74, psd);\
})

#define psdStreamRead(arg1, arg2, arg3) \
    __psdStreamRead_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdStreamWrite_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(LONG, psdStreamWrite, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__ps), 75, psd);\
})

#define psdStreamWrite(arg1, arg2, arg3) \
    __psdStreamWrite_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdStreamFlush_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdStreamFlush, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 76, psd);\
})

#define psdStreamFlush(arg1) \
    __psdStreamFlush_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetStreamError_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdGetStreamError, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 77, psd);\
})

#define psdGetStreamError(arg1) \
    __psdGetStreamError_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdCalculatePower_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdCalculatePower, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 78, psd);\
})

#define psdCalculatePower(arg1) \
    __psdCalculatePower_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdLoadCfgFromDisk_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdLoadCfgFromDisk, \
                  AROS_LCA(STRPTR,(__arg1),A1), \
        struct Library *, (__ps), 79, psd);\
})

#define psdLoadCfgFromDisk(arg1) \
    __psdLoadCfgFromDisk_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSaveCfgToDisk_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(BOOL, psdSaveCfgToDisk, \
                  AROS_LCA(STRPTR,(__arg1),A1), \
                  AROS_LCA(BOOL,(__arg2),D0), \
        struct Library *, (__ps), 80, psd);\
})

#define psdSaveCfgToDisk(arg1, arg2) \
    __psdSaveCfgToDisk_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdDebugSemaphores_WB(__ps) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC0NR(VOID, psdDebugSemaphores, \
        struct Library *, (__ps), 81, psd);\
})

#define psdDebugSemaphores() \
    __psdDebugSemaphores_WB(__POSEIDON_LIBBASE)

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdHubClassScan_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdHubClassScan, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 82, psd);\
})

#define psdHubClassScan(arg1) \
    __psdHubClassScan_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdHubClaimAppBindingA_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdHubClaimAppBindingA, \
                  AROS_LCA(struct TagItem *,(__arg1),A1), \
        struct Library *, (__ps), 83, psd);\
})

#define psdHubClaimAppBindingA(arg1) \
    __psdHubClaimAppBindingA_WB(__POSEIDON_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdHubClaimAppBinding(...) \
({ \
    const IPTR psdHubClaimAppBindingA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdHubClaimAppBindingA((struct TagItem *)(psdHubClaimAppBindingA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdHubReleaseDevBinding_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdHubReleaseDevBinding, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 84, psd);\
})

#define psdHubReleaseDevBinding(arg1) \
    __psdHubReleaseDevBinding_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdHubReleaseIfBinding_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdHubReleaseIfBinding, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 85, psd);\
})

#define psdHubReleaseIfBinding(arg1) \
    __psdHubReleaseIfBinding_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAllocCfgForm_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(APTR, psdAllocCfgForm, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__ps), 86, psd);\
})

#define psdAllocCfgForm(arg1) \
    __psdAllocCfgForm_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAddStringChunk_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(BOOL, psdAddStringChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(CONST_STRPTR,(__arg3),A1), \
        struct Library *, (__ps), 87, psd);\
})

#define psdAddStringChunk(arg1, arg2, arg3) \
    __psdAddStringChunk_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdMatchStringChunk_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(BOOL, psdMatchStringChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(CONST_STRPTR,(__arg3),A1), \
        struct Library *, (__ps), 88, psd);\
})

#define psdMatchStringChunk(arg1, arg2, arg3) \
    __psdMatchStringChunk_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdGetStringChunk_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(STRPTR, psdGetStringChunk, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 89, psd);\
})

#define psdGetStringChunk(arg1, arg2) \
    __psdGetStringChunk_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFindDescriptorA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(APTR, psdFindDescriptorA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__ps), 91, psd);\
})

#define psdFindDescriptorA(arg1, arg2, arg3) \
    __psdFindDescriptorA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdFindDescriptor(arg1, arg2, ...) \
({ \
    const IPTR psdFindDescriptorA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdFindDescriptorA((arg1), (arg2), (struct TagItem *)(psdFindDescriptorA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdDoHubMethodA_WB(__ps, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC3(IPTR, psdDoHubMethodA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(IPTR *,(__arg3),A1), \
        struct Library *, (__ps), 92, psd);\
})

#define psdDoHubMethodA(arg1, arg2, arg3) \
    __psdDoHubMethodA_WB(__POSEIDON_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdDoHubMethod(arg1, arg2, ...) \
({ \
    const IPTR psdDoHubMethodA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdDoHubMethodA((arg1), (arg2), (IPTR *)(psdDoHubMethodA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdAllocRTIsoHandlerA_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(APTR, psdAllocRTIsoHandlerA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__ps), 93, psd);\
})

#define psdAllocRTIsoHandlerA(arg1, arg2) \
    __psdAllocRTIsoHandlerA_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(POSEIDON_NO_INLINE_STDARG)
#define psdAllocRTIsoHandler(arg1, ...) \
({ \
    const IPTR psdAllocRTIsoHandlerA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    psdAllocRTIsoHandlerA((arg1), (struct TagItem *)(psdAllocRTIsoHandlerA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdFreeRTIsoHandler_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1NR(VOID, psdFreeRTIsoHandler, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 94, psd);\
})

#define psdFreeRTIsoHandler(arg1) \
    __psdFreeRTIsoHandler_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdStartRTIso_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdStartRTIso, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 95, psd);\
})

#define psdStartRTIso(arg1) \
    __psdStartRTIso_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdStopRTIso_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(LONG, psdStopRTIso, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct Library *, (__ps), 96, psd);\
})

#define psdStopRTIso(arg1) \
    __psdStopRTIso_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdBorrowLocksWait_WB(__ps, __arg1, __arg2) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC2(ULONG, psdBorrowLocksWait, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__ps), 97, psd);\
})

#define psdBorrowLocksWait(arg1, arg2) \
    __psdBorrowLocksWait_WB(__POSEIDON_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSuspendDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdSuspendDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 98, psd);\
})

#define psdSuspendDevice(arg1) \
    __psdSuspendDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdResumeDevice_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdResumeDevice, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 99, psd);\
})

#define psdResumeDevice(arg1) \
    __psdResumeDevice_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdSuspendBindings_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdSuspendBindings, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 100, psd);\
})

#define psdSuspendBindings(arg1) \
    __psdSuspendBindings_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

#if !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__)

#define __psdResumeBindings_WB(__ps, __arg1) ({\
        AROS_LIBREQ(ps,4)\
        AROS_LC1(BOOL, psdResumeBindings, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__ps), 101, psd);\
})

#define psdResumeBindings(arg1) \
    __psdResumeBindings_WB(__POSEIDON_LIBBASE, (arg1))

#endif /* !defined(__POSEIDON_LIBAPI__) || (4 <= __POSEIDON_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_POSEIDON_H*/
