#ifndef DEFINES_DISKIMAGE_H
#define DEFINES_DISKIMAGE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/devs/diskimage/device/diskimage.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for diskimage
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISKIMAGE_LIBBASE)
#    define __DISKIMAGE_LIBBASE DiskImageBase
#endif

__BEGIN_DECLS


#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __MountImage_WB(__DiskImageBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC2(LONG, MountImage, \
                  AROS_LCA(ULONG,(__arg1),A0), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D0), \
        struct Device *, (__DiskImageBase), 7, DiskImage);\
})

#define MountImage(arg1, arg2) \
    __MountImage_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __UnitInfo_WB(__DiskImageBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC3(LONG, UnitInfo, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(STRPTR *,(__arg2),A0), \
                  AROS_LCA(BOOL *,(__arg3),A1), \
        struct Device *, (__DiskImageBase), 8, DiskImage);\
})

#define UnitInfo(arg1, arg2, arg3) \
    __UnitInfo_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __WriteProtect_WB(__DiskImageBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC2(LONG, WriteProtect, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(BOOL,(__arg2),D1), \
        struct Device *, (__DiskImageBase), 9, DiskImage);\
})

#define WriteProtect(arg1, arg2) \
    __WriteProtect_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __UnitControlA_WB(__DiskImageBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC2(LONG, UnitControlA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Device *, (__DiskImageBase), 10, DiskImage);\
})

#define UnitControlA(arg1, arg2) \
    __UnitControlA_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DISKIMAGE_NO_INLINE_STDARG)
#define UnitControl(arg1, ...) \
({ \
    const IPTR UnitControlA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    UnitControlA((arg1), (struct TagItem *)(UnitControlA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __ReloadPlugins_WB(__DiskImageBase) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC0(LONG, ReloadPlugins, \
        struct Device *, (__DiskImageBase), 11, DiskImage);\
})

#define ReloadPlugins() \
    __ReloadPlugins_WB(__DISKIMAGE_LIBBASE)

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __DoHookPlugins_WB(__DiskImageBase, __arg1) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC1NR(void, DoHookPlugins, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
        struct Device *, (__DiskImageBase), 12, DiskImage);\
})

#define DoHookPlugins(arg1) \
    __DoHookPlugins_WB(__DISKIMAGE_LIBBASE, (arg1))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __AddDiskChangeHook_WB(__DiskImageBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC2NR(void, AddDiskChangeHook, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
                  AROS_LCA(BOOL,(__arg2),D0), \
        struct Device *, (__DiskImageBase), 13, DiskImage);\
})

#define AddDiskChangeHook(arg1, arg2) \
    __AddDiskChangeHook_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

#if !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__)

#define __AddReloadPluginsHook_WB(__DiskImageBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskImageBase,0)\
        AROS_LC2NR(void, AddReloadPluginsHook, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
                  AROS_LCA(BOOL,(__arg2),D0), \
        struct Device *, (__DiskImageBase), 14, DiskImage);\
})

#define AddReloadPluginsHook(arg1, arg2) \
    __AddReloadPluginsHook_WB(__DISKIMAGE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKIMAGE_LIBAPI__) || (0 <= __DISKIMAGE_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DISKIMAGE_H*/
