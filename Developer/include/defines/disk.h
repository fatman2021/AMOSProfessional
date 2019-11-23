#ifndef DEFINES_DISK_H
#define DEFINES_DISK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/disk/disk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for disk
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISK_LIBBASE)
#    define __DISK_LIBBASE DiskBase
#endif

__BEGIN_DECLS


#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __AllocUnit_WB(__DiskBase, __arg1) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC1(BOOL, AllocUnit, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__DiskBase), 1, Disk);\
})

#define AllocUnit(arg1) \
    __AllocUnit_WB(__DISK_LIBBASE, (arg1))

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __FreeUnit_WB(__DiskBase, __arg1) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC1NR(void, FreeUnit, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__DiskBase), 2, Disk);\
})

#define FreeUnit(arg1) \
    __FreeUnit_WB(__DISK_LIBBASE, (arg1))

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __GetUnit_WB(__DiskBase, __arg1) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC1(struct DiscResourceUnit*, GetUnit, \
                  AROS_LCA(struct DiscResourceUnit *,(__arg1),A1), \
        struct Library *, (__DiskBase), 3, Disk);\
})

#define GetUnit(arg1) \
    __GetUnit_WB(__DISK_LIBBASE, (arg1))

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __GiveUnit_WB(__DiskBase) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC0NR(void, GiveUnit, \
        struct Library *, (__DiskBase), 4, Disk);\
})

#define GiveUnit() \
    __GiveUnit_WB(__DISK_LIBBASE)

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __GetUnitID_WB(__DiskBase, __arg1) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC1(ULONG, GetUnitID, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__DiskBase), 5, Disk);\
})

#define GetUnitID(arg1) \
    __GetUnitID_WB(__DISK_LIBBASE, (arg1))

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)

#define __ReadUnitID_WB(__DiskBase, __arg1) ({\
        AROS_LIBREQ(DiskBase,41)\
        AROS_LC1(ULONG, ReadUnitID, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__DiskBase), 6, Disk);\
})

#define ReadUnitID(arg1) \
    __ReadUnitID_WB(__DISK_LIBBASE, (arg1))

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DISK_H*/
