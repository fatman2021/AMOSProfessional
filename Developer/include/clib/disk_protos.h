#ifndef CLIB_DISK_PROTOS_H
#define CLIB_DISK_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/disk/disk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP1(BOOL, AllocUnit,
         AROS_LPA(LONG, unitNum, D0),
         LIBBASETYPEPTR, DiskBase, 1, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP1(void, FreeUnit,
         AROS_LPA(LONG, unitNum, D0),
         LIBBASETYPEPTR, DiskBase, 2, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP1(struct DiscResourceUnit*, GetUnit,
         AROS_LPA(struct DiscResourceUnit *, dru, A1),
         LIBBASETYPEPTR, DiskBase, 3, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP0(void, GiveUnit,
         LIBBASETYPEPTR, DiskBase, 4, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP1(ULONG, GetUnitID,
         AROS_LPA(LONG, unitNum, D0),
         LIBBASETYPEPTR, DiskBase, 5, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

#if !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__)
AROS_LP1(ULONG, ReadUnitID,
         AROS_LPA(LONG, unitNum, D0),
         LIBBASETYPEPTR, DiskBase, 6, Disk
);

#endif /* !defined(__DISK_LIBAPI__) || (41 <= __DISK_LIBAPI__) */

__END_DECLS

#endif /* CLIB_DISK_PROTOS_H */
