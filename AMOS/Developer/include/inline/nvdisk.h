#ifndef INLINE_NVDISK_H
#define INLINE_NVDISK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/nonvolatile/nvdisk/nvdisk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for nvdisk
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__NVDISK_LIBBASE)
#    define __NVDISK_LIBBASE nvdBase
#endif


#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline APTR __inline_NVDisk_ReadNVDData(STRPTR __arg1, STRPTR __arg2, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC2(APTR, ReadNVDData,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        struct Library *, (__nvdBase), 5, NVDisk    );
}

#define ReadNVDData(arg1, arg2) \
    __inline_NVDisk_ReadNVDData((arg1), (arg2), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline LONG __inline_NVDisk_WriteNVDData(STRPTR __arg1, STRPTR __arg2, APTR __arg3, LONG __arg4, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC4(LONG, WriteNVDData,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(APTR,(__arg3),A2),
        AROS_LCA(LONG,(__arg4),A3),
        struct Library *, (__nvdBase), 6, NVDisk    );
}

#define WriteNVDData(arg1, arg2, arg3, arg4) \
    __inline_NVDisk_WriteNVDData((arg1), (arg2), (arg3), (arg4), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline BOOL __inline_NVDisk_DeleteNVDData(STRPTR __arg1, STRPTR __arg2, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC2(BOOL, DeleteNVDData,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        struct Library *, (__nvdBase), 7, NVDisk    );
}

#define DeleteNVDData(arg1, arg2) \
    __inline_NVDisk_DeleteNVDData((arg1), (arg2), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline BOOL __inline_NVDisk_MemInfoNVD(struct NVInfo * __arg1, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC1(BOOL, MemInfoNVD,
        AROS_LCA(struct NVInfo *,(__arg1),A0),
        struct Library *, (__nvdBase), 8, NVDisk    );
}

#define MemInfoNVD(arg1) \
    __inline_NVDisk_MemInfoNVD((arg1), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline BOOL __inline_NVDisk_SetNVDProtection(STRPTR __arg1, STRPTR __arg2, LONG __arg3, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC3(BOOL, SetNVDProtection,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__nvdBase), 9, NVDisk    );
}

#define SetNVDProtection(arg1, arg2, arg3) \
    __inline_NVDisk_SetNVDProtection((arg1), (arg2), (arg3), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

static inline struct MinList * __inline_NVDisk_GetNVDItemList(STRPTR __arg1, APTR __nvdBase)
{
    AROS_LIBREQ(nvdBase, 42)
    return AROS_LC1(struct MinList *, GetNVDItemList,
        AROS_LCA(STRPTR,(__arg1),A0),
        struct Library *, (__nvdBase), 10, NVDisk    );
}

#define GetNVDItemList(arg1) \
    __inline_NVDisk_GetNVDItemList((arg1), __NVDISK_LIBBASE)

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#endif /* INLINE_NVDISK_H*/
