#ifndef DEFINES_KERNEL_H
#define DEFINES_KERNEL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/kernel/kernel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for kernel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__KERNEL_LIBBASE)
#    define __KERNEL_LIBBASE KernelBase
#endif

__BEGIN_DECLS


#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetScheduler_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(KRN_SchedType, KrnGetScheduler, \
        APTR , (__KernelBase), 1, Kernel);\
})

#define KrnGetScheduler() \
    __KrnGetScheduler_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSetScheduler_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnSetScheduler, \
                  AROS_LCA(KRN_SchedType,(__arg1),D0), \
        APTR , (__KernelBase), 2, Kernel);\
})

#define KrnSetScheduler(arg1) \
    __KrnSetScheduler_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnCause_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnCause, \
        APTR , (__KernelBase), 3, Kernel);\
})

#define KrnCause() \
    __KrnCause_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnDispatch_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnDispatch, \
        APTR , (__KernelBase), 4, Kernel);\
})

#define KrnDispatch() \
    __KrnDispatch_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSwitch_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnSwitch, \
        APTR , (__KernelBase), 5, Kernel);\
})

#define KrnSwitch() \
    __KrnSwitch_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSchedule_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnSchedule, \
        APTR , (__KernelBase), 6, Kernel);\
})

#define KrnSchedule() \
    __KrnSchedule_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnAddIRQHandler_WB(__KernelBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC4(void *, KrnAddIRQHandler, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
                  AROS_LCA(void *,(__arg2),A0), \
                  AROS_LCA(void *,(__arg3),A1), \
                  AROS_LCA(void *,(__arg4),A2), \
        APTR , (__KernelBase), 7, Kernel);\
})

#define KrnAddIRQHandler(arg1, arg2, arg3, arg4) \
    __KrnAddIRQHandler_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnRemIRQHandler_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnRemIRQHandler, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 8, Kernel);\
})

#define KrnRemIRQHandler(arg1) \
    __KrnRemIRQHandler_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnCli_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnCli, \
        APTR , (__KernelBase), 9, Kernel);\
})

#define KrnCli() \
    __KrnCli_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSti_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnSti, \
        APTR , (__KernelBase), 10, Kernel);\
})

#define KrnSti() \
    __KrnSti_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetBootInfo_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(struct TagItem *, KrnGetBootInfo, \
        APTR , (__KernelBase), 11, Kernel);\
})

#define KrnGetBootInfo() \
    __KrnGetBootInfo_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnBug_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(int, KrnBug, \
                  AROS_LCA(const char *,(__arg1),A0), \
                  AROS_LCA(va_list,(__arg2),A1), \
        APTR , (__KernelBase), 12, Kernel);\
})

#define KrnBug(arg1, arg2) \
    __KrnBug_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnIsSuper_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(int, KrnIsSuper, \
        APTR , (__KernelBase), 13, Kernel);\
})

#define KrnIsSuper() \
    __KrnIsSuper_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnAddExceptionHandler_WB(__KernelBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC4(void *, KrnAddExceptionHandler, \
                  AROS_LCA(uint8_t,(__arg1),D0), \
                  AROS_LCA(void *,(__arg2),A0), \
                  AROS_LCA(void *,(__arg3),A1), \
                  AROS_LCA(void *,(__arg4),A2), \
        APTR , (__KernelBase), 14, Kernel);\
})

#define KrnAddExceptionHandler(arg1, arg2, arg3, arg4) \
    __KrnAddExceptionHandler_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnRemExceptionHandler_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnRemExceptionHandler, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 15, Kernel);\
})

#define KrnRemExceptionHandler(arg1) \
    __KrnRemExceptionHandler_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnMapGlobal_WB(__KernelBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC4(int, KrnMapGlobal, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
                  AROS_LCA(uint32_t,(__arg3),D0), \
                  AROS_LCA(KRN_MapAttr,(__arg4),D1), \
        APTR , (__KernelBase), 16, Kernel);\
})

#define KrnMapGlobal(arg1, arg2, arg3, arg4) \
    __KrnMapGlobal_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnUnmapGlobal_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(int, KrnUnmapGlobal, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(uint32_t,(__arg2),D0), \
        APTR , (__KernelBase), 17, Kernel);\
})

#define KrnUnmapGlobal(arg1, arg2) \
    __KrnUnmapGlobal_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnCreateContext_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(void *, KrnCreateContext, \
        APTR , (__KernelBase), 18, Kernel);\
})

#define KrnCreateContext() \
    __KrnCreateContext_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnDeleteContext_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnDeleteContext, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 19, Kernel);\
})

#define KrnDeleteContext(arg1) \
    __KrnDeleteContext_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnVirtualToPhysical_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1(void *, KrnVirtualToPhysical, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 20, Kernel);\
})

#define KrnVirtualToPhysical(arg1) \
    __KrnVirtualToPhysical_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSetProtection_WB(__KernelBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC3NR(void, KrnSetProtection, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(uint32_t,(__arg2),D0), \
                  AROS_LCA(KRN_MapAttr,(__arg3),D1), \
        APTR , (__KernelBase), 21, Kernel);\
})

#define KrnSetProtection(arg1, arg2, arg3) \
    __KrnSetProtection_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnPutChar_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnPutChar, \
                  AROS_LCA(char,(__arg1),D0), \
        APTR , (__KernelBase), 25, Kernel);\
})

#define KrnPutChar(arg1) \
    __KrnPutChar_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnMayGetChar_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(int, KrnMayGetChar, \
        APTR , (__KernelBase), 26, Kernel);\
})

#define KrnMayGetChar() \
    __KrnMayGetChar_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnAllocPages_WB(__KernelBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC3(void *, KrnAllocPages, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(uintptr_t,(__arg2),D0), \
                  AROS_LCA(uint32_t,(__arg3),D1), \
        APTR , (__KernelBase), 27, Kernel);\
})

#define KrnAllocPages(arg1, arg2, arg3) \
    __KrnAllocPages_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnFreePages_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2NR(void, KrnFreePages, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(uintptr_t,(__arg2),D0), \
        APTR , (__KernelBase), 28, Kernel);\
})

#define KrnFreePages(arg1, arg2) \
    __KrnFreePages_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetSystemAttr_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1(intptr_t, KrnGetSystemAttr, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
        APTR , (__KernelBase), 29, Kernel);\
})

#define KrnGetSystemAttr(arg1) \
    __KrnGetSystemAttr_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnFormatStr_WB(__KernelBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC3(int, KrnFormatStr, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(const char *,(__arg2),A1), \
                  AROS_LCA(va_list,(__arg3),A2), \
        APTR , (__KernelBase), 30, Kernel);\
})

#define KrnFormatStr(arg1, arg2, arg3) \
    __KrnFormatStr_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnInitMemory_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnInitMemory, \
                  AROS_LCA(struct MemHeader *,(__arg1),A0), \
        APTR , (__KernelBase), 31, Kernel);\
})

#define KrnInitMemory(arg1) \
    __KrnInitMemory_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnStatMemoryA_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(ULONG, KrnStatMemoryA, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        APTR , (__KernelBase), 32, Kernel);\
})

#define KrnStatMemoryA(arg1, arg2) \
    __KrnStatMemoryA_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(KERNEL_NO_INLINE_STDARG)
#define KrnStatMemory(arg1, ...) \
({ \
    const IPTR KrnStatMemoryA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    KrnStatMemoryA((arg1), (struct TagItem *)(KrnStatMemoryA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnObtainInput_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(int, KrnObtainInput, \
        APTR , (__KernelBase), 33, Kernel);\
})

#define KrnObtainInput() \
    __KrnObtainInput_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnReleaseInput_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0NR(void, KrnReleaseInput, \
        APTR , (__KernelBase), 34, Kernel);\
})

#define KrnReleaseInput() \
    __KrnReleaseInput_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnDisplayAlert_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2NR(void, KrnDisplayAlert, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
                  AROS_LCA(const char *,(__arg2),A0), \
        APTR , (__KernelBase), 35, Kernel);\
})

#define KrnDisplayAlert(arg1, arg2) \
    __KrnDisplayAlert_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnModifyIRQHandler_WB(__KernelBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC3NR(void, KrnModifyIRQHandler, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
                  AROS_LCA(void *,(__arg3),A2), \
        APTR , (__KernelBase), 37, Kernel);\
})

#define KrnModifyIRQHandler(arg1, arg2, arg3) \
    __KrnModifyIRQHandler_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnAllocIRQ_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(ULONG, KrnAllocIRQ, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        APTR , (__KernelBase), 38, Kernel);\
})

#define KrnAllocIRQ(arg1, arg2) \
    __KrnAllocIRQ_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnModifyIRQA_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(ULONG, KrnModifyIRQA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        APTR , (__KernelBase), 39, Kernel);\
})

#define KrnModifyIRQA(arg1, arg2) \
    __KrnModifyIRQA_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(KERNEL_NO_INLINE_STDARG)
#define KrnModifyIRQ(arg1, ...) \
({ \
    const IPTR KrnModifyIRQA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    KrnModifyIRQA((arg1), (struct TagItem *)(KrnModifyIRQA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetCPUCount_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(unsigned int, KrnGetCPUCount, \
        APTR , (__KernelBase), 40, Kernel);\
})

#define KrnGetCPUCount() \
    __KrnGetCPUCount_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetCPUNumber_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(uint32_t, KrnGetCPUNumber, \
        APTR , (__KernelBase), 41, Kernel);\
})

#define KrnGetCPUNumber() \
    __KrnGetCPUNumber_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnAllocCPUMask_WB(__KernelBase) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC0(void *, KrnAllocCPUMask, \
        APTR , (__KernelBase), 42, Kernel);\
})

#define KrnAllocCPUMask() \
    __KrnAllocCPUMask_WB(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnFreeCPUMask_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1(void *, KrnFreeCPUMask, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 43, Kernel);\
})

#define KrnFreeCPUMask(arg1) \
    __KrnFreeCPUMask_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnClearCPUMask_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnClearCPUMask, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 44, Kernel);\
})

#define KrnClearCPUMask(arg1) \
    __KrnClearCPUMask_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnGetCPUMask_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2NR(void, KrnGetCPUMask, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
                  AROS_LCA(void *,(__arg2),A0), \
        APTR , (__KernelBase), 45, Kernel);\
})

#define KrnGetCPUMask(arg1, arg2) \
    __KrnGetCPUMask_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnCPUInMask_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(BOOL, KrnCPUInMask, \
                  AROS_LCA(uint32_t,(__arg1),D0), \
                  AROS_LCA(void *,(__arg2),A0), \
        APTR , (__KernelBase), 46, Kernel);\
})

#define KrnCPUInMask(arg1, arg2) \
    __KrnCPUInMask_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnScheduleCPU_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnScheduleCPU, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__KernelBase), 47, Kernel);\
})

#define KrnScheduleCPU(arg1) \
    __KrnScheduleCPU_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSpinInit_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnSpinInit, \
                  AROS_LCA(spinlock_t *,(__arg1),A0), \
        APTR , (__KernelBase), 49, Kernel);\
})

#define KrnSpinInit(arg1) \
    __KrnSpinInit_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSpinIsLocked_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1(int, KrnSpinIsLocked, \
                  AROS_LCA(spinlock_t *,(__arg1),A0), \
        APTR , (__KernelBase), 50, Kernel);\
})

#define KrnSpinIsLocked(arg1) \
    __KrnSpinIsLocked_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSpinTryLock_WB(__KernelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC2(spinlock_t *, KrnSpinTryLock, \
                  AROS_LCA(spinlock_t *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        APTR , (__KernelBase), 51, Kernel);\
})

#define KrnSpinTryLock(arg1, arg2) \
    __KrnSpinTryLock_WB(__KERNEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSpinLock_WB(__KernelBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC3(spinlock_t *, KrnSpinLock, \
                  AROS_LCA(spinlock_t *,(__arg1),A1), \
                  AROS_LCA(struct Hook *,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        APTR , (__KernelBase), 52, Kernel);\
})

#define KrnSpinLock(arg1, arg2, arg3) \
    __KrnSpinLock_WB(__KERNEL_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

#define __KrnSpinUnLock_WB(__KernelBase, __arg1) ({\
        AROS_LIBREQ(KernelBase,3)\
        AROS_LC1NR(void, KrnSpinUnLock, \
                  AROS_LCA(spinlock_t *,(__arg1),A0), \
        APTR , (__KernelBase), 53, Kernel);\
})

#define KrnSpinUnLock(arg1) \
    __KrnSpinUnLock_WB(__KERNEL_LIBBASE, (arg1))

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_KERNEL_H*/
