#ifndef DEFINES_NVDISK_H
#define DEFINES_NVDISK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/nonvolatile/nvdisk/nvdisk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for nvdisk
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__NVDISK_LIBBASE)
#    define __NVDISK_LIBBASE nvdBase
#endif

__BEGIN_DECLS


#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __ReadNVDData_WB(__nvdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC2(APTR, ReadNVDData, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
        struct Library *, (__nvdBase), 5, NVDisk);\
})

#define ReadNVDData(arg1, arg2) \
    __ReadNVDData_WB(__NVDISK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __WriteNVDData_WB(__nvdBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC4(LONG, WriteNVDData, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
                  AROS_LCA(APTR,(__arg3),A2), \
                  AROS_LCA(LONG,(__arg4),A3), \
        struct Library *, (__nvdBase), 6, NVDisk);\
})

#define WriteNVDData(arg1, arg2, arg3, arg4) \
    __WriteNVDData_WB(__NVDISK_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __DeleteNVDData_WB(__nvdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC2(BOOL, DeleteNVDData, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
        struct Library *, (__nvdBase), 7, NVDisk);\
})

#define DeleteNVDData(arg1, arg2) \
    __DeleteNVDData_WB(__NVDISK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __MemInfoNVD_WB(__nvdBase, __arg1) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC1(BOOL, MemInfoNVD, \
                  AROS_LCA(struct NVInfo *,(__arg1),A0), \
        struct Library *, (__nvdBase), 8, NVDisk);\
})

#define MemInfoNVD(arg1) \
    __MemInfoNVD_WB(__NVDISK_LIBBASE, (arg1))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __SetNVDProtection_WB(__nvdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC3(BOOL, SetNVDProtection, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__nvdBase), 9, NVDisk);\
})

#define SetNVDProtection(arg1, arg2, arg3) \
    __SetNVDProtection_WB(__NVDISK_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

#if !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__)

#define __GetNVDItemList_WB(__nvdBase, __arg1) ({\
        AROS_LIBREQ(nvdBase,42)\
        AROS_LC1(struct MinList *, GetNVDItemList, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
        struct Library *, (__nvdBase), 10, NVDisk);\
})

#define GetNVDItemList(arg1) \
    __GetNVDItemList_WB(__NVDISK_LIBBASE, (arg1))

#endif /* !defined(__NVDISK_LIBAPI__) || (42 <= __NVDISK_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_NVDISK_H*/
