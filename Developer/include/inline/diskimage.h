#ifndef INLINE_DISKIMAGE_H
#define INLINE_DISKIMAGE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/devs/diskimage/device/diskimage.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for diskimage
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISKIMAGE_LIBBASE)
#    define __DISKIMAGE_LIBBASE DiskImageBase
#endif


#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline LONG __inline_DiskImage_MountImage(ULONG __arg1, CONST_STRPTR __arg2, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    return AROS_LC2(LONG, MountImage,
        AROS_LCA(ULONG,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),D0),
        struct Device *, (__DiskImageBase), 7, DiskImage    );
}

#define MountImage(arg1, arg2) \
    __inline_DiskImage_MountImage((arg1), (arg2), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline LONG __inline_DiskImage_UnitInfo(ULONG __arg1, STRPTR * __arg2, BOOL * __arg3, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    return AROS_LC3(LONG, UnitInfo,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(STRPTR *,(__arg2),A0),
        AROS_LCA(BOOL *,(__arg3),A1),
        struct Device *, (__DiskImageBase), 8, DiskImage    );
}

#define UnitInfo(arg1, arg2, arg3) \
    __inline_DiskImage_UnitInfo((arg1), (arg2), (arg3), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline LONG __inline_DiskImage_WriteProtect(ULONG __arg1, BOOL __arg2, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    return AROS_LC2(LONG, WriteProtect,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(BOOL,(__arg2),D1),
        struct Device *, (__DiskImageBase), 9, DiskImage    );
}

#define WriteProtect(arg1, arg2) \
    __inline_DiskImage_WriteProtect((arg1), (arg2), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline LONG __inline_DiskImage_UnitControlA(ULONG __arg1, struct TagItem * __arg2, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    return AROS_LC2(LONG, UnitControlA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Device *, (__DiskImageBase), 10, DiskImage    );
}

#define UnitControlA(arg1, arg2) \
    __inline_DiskImage_UnitControlA((arg1), (arg2), __DISKIMAGE_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DISKIMAGE_NO_INLINE_STDARG)
#define UnitControl(arg1, ...) \
({ \
    const IPTR UnitControlA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    UnitControlA((arg1), (struct TagItem *)(UnitControlA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline LONG __inline_DiskImage_ReloadPlugins(APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    return AROS_LC0(LONG, ReloadPlugins,
        struct Device *, (__DiskImageBase), 11, DiskImage    );
}

#define ReloadPlugins() \
    __inline_DiskImage_ReloadPlugins(__DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline void __inline_DiskImage_DoHookPlugins(struct Hook * __arg1, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    AROS_LC1NR(void, DoHookPlugins,
        AROS_LCA(struct Hook *,(__arg1),A0),
        struct Device *, (__DiskImageBase), 12, DiskImage    );
}

#define DoHookPlugins(arg1) \
    __inline_DiskImage_DoHookPlugins((arg1), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline void __inline_DiskImage_AddDiskChangeHook(struct Hook * __arg1, BOOL __arg2, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    AROS_LC2NR(void, AddDiskChangeHook,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct Device *, (__DiskImageBase), 13, DiskImage    );
}

#define AddDiskChangeHook(arg1, arg2) \
    __inline_DiskImage_AddDiskChangeHook((arg1), (arg2), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

static inline void __inline_DiskImage_AddReloadPluginsHook(struct Hook * __arg1, BOOL __arg2, APTR __DiskImageBase)
{
    AROS_LIBREQ(DiskImageBase, 0)
    AROS_LC2NR(void, AddReloadPluginsHook,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct Device *, (__DiskImageBase), 14, DiskImage    );
}

#define AddReloadPluginsHook(arg1, arg2) \
    __inline_DiskImage_AddReloadPluginsHook((arg1), (arg2), __DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#endif /* INLINE_DISKIMAGE_H*/
