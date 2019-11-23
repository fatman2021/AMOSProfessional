#ifndef INLINE_KERNEL_H
#define INLINE_KERNEL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/kernel/kernel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for kernel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__KERNEL_LIBBASE)
#    define __KERNEL_LIBBASE KernelBase
#endif


#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline KRN_SchedType __inline_Kernel_KrnGetScheduler(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(KRN_SchedType, KrnGetScheduler,
        APTR , (__KernelBase), 1, Kernel    );
}

#define KrnGetScheduler() \
    __inline_Kernel_KrnGetScheduler(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSetScheduler(KRN_SchedType __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnSetScheduler,
        AROS_LCA(KRN_SchedType,(__arg1),D0),
        APTR , (__KernelBase), 2, Kernel    );
}

#define KrnSetScheduler(arg1) \
    __inline_Kernel_KrnSetScheduler((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnCause(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnCause,
        APTR , (__KernelBase), 3, Kernel    );
}

#define KrnCause() \
    __inline_Kernel_KrnCause(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnDispatch(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnDispatch,
        APTR , (__KernelBase), 4, Kernel    );
}

#define KrnDispatch() \
    __inline_Kernel_KrnDispatch(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSwitch(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnSwitch,
        APTR , (__KernelBase), 5, Kernel    );
}

#define KrnSwitch() \
    __inline_Kernel_KrnSwitch(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSchedule(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnSchedule,
        APTR , (__KernelBase), 6, Kernel    );
}

#define KrnSchedule() \
    __inline_Kernel_KrnSchedule(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnAddIRQHandler(uint32_t __arg1, void * __arg2, void * __arg3, void * __arg4, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC4(void *, KrnAddIRQHandler,
        AROS_LCA(uint32_t,(__arg1),D0),
        AROS_LCA(void *,(__arg2),A0),
        AROS_LCA(void *,(__arg3),A1),
        AROS_LCA(void *,(__arg4),A2),
        APTR , (__KernelBase), 7, Kernel    );
}

#define KrnAddIRQHandler(arg1, arg2, arg3, arg4) \
    __inline_Kernel_KrnAddIRQHandler((arg1), (arg2), (arg3), (arg4), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnRemIRQHandler(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnRemIRQHandler,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 8, Kernel    );
}

#define KrnRemIRQHandler(arg1) \
    __inline_Kernel_KrnRemIRQHandler((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnCli(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnCli,
        APTR , (__KernelBase), 9, Kernel    );
}

#define KrnCli() \
    __inline_Kernel_KrnCli(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSti(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnSti,
        APTR , (__KernelBase), 10, Kernel    );
}

#define KrnSti() \
    __inline_Kernel_KrnSti(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline struct TagItem * __inline_Kernel_KrnGetBootInfo(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(struct TagItem *, KrnGetBootInfo,
        APTR , (__KernelBase), 11, Kernel    );
}

#define KrnGetBootInfo() \
    __inline_Kernel_KrnGetBootInfo(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnBug(const char * __arg1, va_list __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(int, KrnBug,
        AROS_LCA(const char *,(__arg1),A0),
        AROS_LCA(va_list,(__arg2),A1),
        APTR , (__KernelBase), 12, Kernel    );
}

#define KrnBug(arg1, arg2) \
    __inline_Kernel_KrnBug((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnIsSuper(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(int, KrnIsSuper,
        APTR , (__KernelBase), 13, Kernel    );
}

#define KrnIsSuper() \
    __inline_Kernel_KrnIsSuper(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnAddExceptionHandler(uint8_t __arg1, void * __arg2, void * __arg3, void * __arg4, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC4(void *, KrnAddExceptionHandler,
        AROS_LCA(uint8_t,(__arg1),D0),
        AROS_LCA(void *,(__arg2),A0),
        AROS_LCA(void *,(__arg3),A1),
        AROS_LCA(void *,(__arg4),A2),
        APTR , (__KernelBase), 14, Kernel    );
}

#define KrnAddExceptionHandler(arg1, arg2, arg3, arg4) \
    __inline_Kernel_KrnAddExceptionHandler((arg1), (arg2), (arg3), (arg4), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnRemExceptionHandler(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnRemExceptionHandler,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 15, Kernel    );
}

#define KrnRemExceptionHandler(arg1) \
    __inline_Kernel_KrnRemExceptionHandler((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnMapGlobal(void * __arg1, void * __arg2, uint32_t __arg3, KRN_MapAttr __arg4, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC4(int, KrnMapGlobal,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        AROS_LCA(uint32_t,(__arg3),D0),
        AROS_LCA(KRN_MapAttr,(__arg4),D1),
        APTR , (__KernelBase), 16, Kernel    );
}

#define KrnMapGlobal(arg1, arg2, arg3, arg4) \
    __inline_Kernel_KrnMapGlobal((arg1), (arg2), (arg3), (arg4), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnUnmapGlobal(void * __arg1, uint32_t __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(int, KrnUnmapGlobal,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(uint32_t,(__arg2),D0),
        APTR , (__KernelBase), 17, Kernel    );
}

#define KrnUnmapGlobal(arg1, arg2) \
    __inline_Kernel_KrnUnmapGlobal((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnCreateContext(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(void *, KrnCreateContext,
        APTR , (__KernelBase), 18, Kernel    );
}

#define KrnCreateContext() \
    __inline_Kernel_KrnCreateContext(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnDeleteContext(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnDeleteContext,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 19, Kernel    );
}

#define KrnDeleteContext(arg1) \
    __inline_Kernel_KrnDeleteContext((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnVirtualToPhysical(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC1(void *, KrnVirtualToPhysical,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 20, Kernel    );
}

#define KrnVirtualToPhysical(arg1) \
    __inline_Kernel_KrnVirtualToPhysical((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSetProtection(void * __arg1, uint32_t __arg2, KRN_MapAttr __arg3, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC3NR(void, KrnSetProtection,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(uint32_t,(__arg2),D0),
        AROS_LCA(KRN_MapAttr,(__arg3),D1),
        APTR , (__KernelBase), 21, Kernel    );
}

#define KrnSetProtection(arg1, arg2, arg3) \
    __inline_Kernel_KrnSetProtection((arg1), (arg2), (arg3), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnPutChar(char __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnPutChar,
        AROS_LCA(char,(__arg1),D0),
        APTR , (__KernelBase), 25, Kernel    );
}

#define KrnPutChar(arg1) \
    __inline_Kernel_KrnPutChar((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnMayGetChar(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(int, KrnMayGetChar,
        APTR , (__KernelBase), 26, Kernel    );
}

#define KrnMayGetChar() \
    __inline_Kernel_KrnMayGetChar(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnAllocPages(void * __arg1, uintptr_t __arg2, uint32_t __arg3, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC3(void *, KrnAllocPages,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(uintptr_t,(__arg2),D0),
        AROS_LCA(uint32_t,(__arg3),D1),
        APTR , (__KernelBase), 27, Kernel    );
}

#define KrnAllocPages(arg1, arg2, arg3) \
    __inline_Kernel_KrnAllocPages((arg1), (arg2), (arg3), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnFreePages(void * __arg1, uintptr_t __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC2NR(void, KrnFreePages,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(uintptr_t,(__arg2),D0),
        APTR , (__KernelBase), 28, Kernel    );
}

#define KrnFreePages(arg1, arg2) \
    __inline_Kernel_KrnFreePages((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline intptr_t __inline_Kernel_KrnGetSystemAttr(uint32_t __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC1(intptr_t, KrnGetSystemAttr,
        AROS_LCA(uint32_t,(__arg1),D0),
        APTR , (__KernelBase), 29, Kernel    );
}

#define KrnGetSystemAttr(arg1) \
    __inline_Kernel_KrnGetSystemAttr((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnFormatStr(void * __arg1, const char * __arg2, va_list __arg3, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC3(int, KrnFormatStr,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(const char *,(__arg2),A1),
        AROS_LCA(va_list,(__arg3),A2),
        APTR , (__KernelBase), 30, Kernel    );
}

#define KrnFormatStr(arg1, arg2, arg3) \
    __inline_Kernel_KrnFormatStr((arg1), (arg2), (arg3), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnInitMemory(struct MemHeader * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnInitMemory,
        AROS_LCA(struct MemHeader *,(__arg1),A0),
        APTR , (__KernelBase), 31, Kernel    );
}

#define KrnInitMemory(arg1) \
    __inline_Kernel_KrnInitMemory((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline ULONG __inline_Kernel_KrnStatMemoryA(uint32_t __arg1, struct TagItem * __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(ULONG, KrnStatMemoryA,
        AROS_LCA(uint32_t,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        APTR , (__KernelBase), 32, Kernel    );
}

#define KrnStatMemoryA(arg1, arg2) \
    __inline_Kernel_KrnStatMemoryA((arg1), (arg2), __KERNEL_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(KERNEL_NO_INLINE_STDARG)
#define KrnStatMemory(arg1, ...) \
({ \
    const IPTR KrnStatMemoryA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    KrnStatMemoryA((arg1), (struct TagItem *)(KrnStatMemoryA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnObtainInput(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(int, KrnObtainInput,
        APTR , (__KernelBase), 33, Kernel    );
}

#define KrnObtainInput() \
    __inline_Kernel_KrnObtainInput(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnReleaseInput(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC0NR(void, KrnReleaseInput,
        APTR , (__KernelBase), 34, Kernel    );
}

#define KrnReleaseInput() \
    __inline_Kernel_KrnReleaseInput(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnDisplayAlert(uint32_t __arg1, const char * __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC2NR(void, KrnDisplayAlert,
        AROS_LCA(uint32_t,(__arg1),D0),
        AROS_LCA(const char *,(__arg2),A0),
        APTR , (__KernelBase), 35, Kernel    );
}

#define KrnDisplayAlert(arg1, arg2) \
    __inline_Kernel_KrnDisplayAlert((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnModifyIRQHandler(void * __arg1, void * __arg2, void * __arg3, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC3NR(void, KrnModifyIRQHandler,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        AROS_LCA(void *,(__arg3),A2),
        APTR , (__KernelBase), 37, Kernel    );
}

#define KrnModifyIRQHandler(arg1, arg2, arg3) \
    __inline_Kernel_KrnModifyIRQHandler((arg1), (arg2), (arg3), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline ULONG __inline_Kernel_KrnAllocIRQ(ULONG __arg1, ULONG __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(ULONG, KrnAllocIRQ,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        APTR , (__KernelBase), 38, Kernel    );
}

#define KrnAllocIRQ(arg1, arg2) \
    __inline_Kernel_KrnAllocIRQ((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline ULONG __inline_Kernel_KrnModifyIRQA(ULONG __arg1, struct TagItem * __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(ULONG, KrnModifyIRQA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        APTR , (__KernelBase), 39, Kernel    );
}

#define KrnModifyIRQA(arg1, arg2) \
    __inline_Kernel_KrnModifyIRQA((arg1), (arg2), __KERNEL_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(KERNEL_NO_INLINE_STDARG)
#define KrnModifyIRQ(arg1, ...) \
({ \
    const IPTR KrnModifyIRQA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    KrnModifyIRQA((arg1), (struct TagItem *)(KrnModifyIRQA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline unsigned int __inline_Kernel_KrnGetCPUCount(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(unsigned int, KrnGetCPUCount,
        APTR , (__KernelBase), 40, Kernel    );
}

#define KrnGetCPUCount() \
    __inline_Kernel_KrnGetCPUCount(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline uint32_t __inline_Kernel_KrnGetCPUNumber(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(uint32_t, KrnGetCPUNumber,
        APTR , (__KernelBase), 41, Kernel    );
}

#define KrnGetCPUNumber() \
    __inline_Kernel_KrnGetCPUNumber(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnAllocCPUMask(APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC0(void *, KrnAllocCPUMask,
        APTR , (__KernelBase), 42, Kernel    );
}

#define KrnAllocCPUMask() \
    __inline_Kernel_KrnAllocCPUMask(__KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void * __inline_Kernel_KrnFreeCPUMask(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC1(void *, KrnFreeCPUMask,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 43, Kernel    );
}

#define KrnFreeCPUMask(arg1) \
    __inline_Kernel_KrnFreeCPUMask((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnClearCPUMask(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnClearCPUMask,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 44, Kernel    );
}

#define KrnClearCPUMask(arg1) \
    __inline_Kernel_KrnClearCPUMask((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnGetCPUMask(uint32_t __arg1, void * __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC2NR(void, KrnGetCPUMask,
        AROS_LCA(uint32_t,(__arg1),D0),
        AROS_LCA(void *,(__arg2),A0),
        APTR , (__KernelBase), 45, Kernel    );
}

#define KrnGetCPUMask(arg1, arg2) \
    __inline_Kernel_KrnGetCPUMask((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline BOOL __inline_Kernel_KrnCPUInMask(uint32_t __arg1, void * __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(BOOL, KrnCPUInMask,
        AROS_LCA(uint32_t,(__arg1),D0),
        AROS_LCA(void *,(__arg2),A0),
        APTR , (__KernelBase), 46, Kernel    );
}

#define KrnCPUInMask(arg1, arg2) \
    __inline_Kernel_KrnCPUInMask((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnScheduleCPU(void * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnScheduleCPU,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__KernelBase), 47, Kernel    );
}

#define KrnScheduleCPU(arg1) \
    __inline_Kernel_KrnScheduleCPU((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSpinInit(spinlock_t * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnSpinInit,
        AROS_LCA(spinlock_t *,(__arg1),A0),
        APTR , (__KernelBase), 49, Kernel    );
}

#define KrnSpinInit(arg1) \
    __inline_Kernel_KrnSpinInit((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline int __inline_Kernel_KrnSpinIsLocked(spinlock_t * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC1(int, KrnSpinIsLocked,
        AROS_LCA(spinlock_t *,(__arg1),A0),
        APTR , (__KernelBase), 50, Kernel    );
}

#define KrnSpinIsLocked(arg1) \
    __inline_Kernel_KrnSpinIsLocked((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline spinlock_t * __inline_Kernel_KrnSpinTryLock(spinlock_t * __arg1, ULONG __arg2, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC2(spinlock_t *, KrnSpinTryLock,
        AROS_LCA(spinlock_t *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        APTR , (__KernelBase), 51, Kernel    );
}

#define KrnSpinTryLock(arg1, arg2) \
    __inline_Kernel_KrnSpinTryLock((arg1), (arg2), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline spinlock_t * __inline_Kernel_KrnSpinLock(spinlock_t * __arg1, struct Hook * __arg2, ULONG __arg3, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    return AROS_LC3(spinlock_t *, KrnSpinLock,
        AROS_LCA(spinlock_t *,(__arg1),A1),
        AROS_LCA(struct Hook *,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        APTR , (__KernelBase), 52, Kernel    );
}

#define KrnSpinLock(arg1, arg2, arg3) \
    __inline_Kernel_KrnSpinLock((arg1), (arg2), (arg3), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#if !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__)

static inline void __inline_Kernel_KrnSpinUnLock(spinlock_t * __arg1, APTR __KernelBase)
{
    AROS_LIBREQ(KernelBase, 3)
    AROS_LC1NR(void, KrnSpinUnLock,
        AROS_LCA(spinlock_t *,(__arg1),A0),
        APTR , (__KernelBase), 53, Kernel    );
}

#define KrnSpinUnLock(arg1) \
    __inline_Kernel_KrnSpinUnLock((arg1), __KERNEL_LIBBASE)

#endif /* !defined(__KERNEL_LIBAPI__) || (3 <= __KERNEL_LIBAPI__) */

#endif /* INLINE_KERNEL_H*/
