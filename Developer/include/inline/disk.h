#ifndef INLINE_DISK_H
#define INLINE_DISK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/disk/disk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for disk
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISK_LIBBASE)
#    define __DISK_LIBBASE DiskBase
#endif


#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline BOOL __inline_Disk_AllocUnit(LONG __arg1, APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    return AROS_LC1(BOOL, AllocUnit,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__DiskBase), 1, Disk    );
}

#define AllocUnit(arg1) \
    __inline_Disk_AllocUnit((arg1), __DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline void __inline_Disk_FreeUnit(LONG __arg1, APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    AROS_LC1NR(void, FreeUnit,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__DiskBase), 2, Disk    );
}

#define FreeUnit(arg1) \
    __inline_Disk_FreeUnit((arg1), __DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline struct DiscResourceUnit* __inline_Disk_GetUnit(struct DiscResourceUnit * __arg1, APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    return AROS_LC1(struct DiscResourceUnit*, GetUnit,
        AROS_LCA(struct DiscResourceUnit *,(__arg1),A1),
        struct Library *, (__DiskBase), 3, Disk    );
}

#define GetUnit(arg1) \
    __inline_Disk_GetUnit((arg1), __DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline void __inline_Disk_GiveUnit(APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    AROS_LC0NR(void, GiveUnit,
        struct Library *, (__DiskBase), 4, Disk    );
}

#define GiveUnit() \
    __inline_Disk_GiveUnit(__DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline ULONG __inline_Disk_GetUnitID(LONG __arg1, APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    return AROS_LC1(ULONG, GetUnitID,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__DiskBase), 5, Disk    );
}

#define GetUnitID(arg1) \
    __inline_Disk_GetUnitID((arg1), __DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

static inline ULONG __inline_Disk_ReadUnitID(LONG __arg1, APTR __DiskBase)
{
    AROS_LIBREQ(DiskBase, 41)
    return AROS_LC1(ULONG, ReadUnitID,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__DiskBase), 6, Disk    );
}

#define ReadUnitID(arg1) \
    __inline_Disk_ReadUnitID((arg1), __DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#endif /* INLINE_DISK_H*/
