#ifndef INLINE_SCSI_H
#define INLINE_SCSI_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/scsi/scsi.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for scsi
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__SCSI_LIBBASE)
#    define __SCSI_LIBBASE SCSIBase
#endif


#if !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__)

static inline ULONG __inline_scsi_GetRdskLba(struct IORequest * __arg1, APTR __SCSIBase)
{
    AROS_LIBREQ(SCSIBase, 0)
    return AROS_LC1(ULONG, GetRdskLba,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct Device *, (__SCSIBase), 7, scsi    );
}

#define GetRdskLba(arg1) \
    __inline_scsi_GetRdskLba((arg1), __SCSI_LIBBASE)

#endif /* !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__) */

#if !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__)

static inline ULONG __inline_scsi_GetBlkSize(struct IORequest * __arg1, APTR __SCSIBase)
{
    AROS_LIBREQ(SCSIBase, 0)
    return AROS_LC1(ULONG, GetBlkSize,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct Device *, (__SCSIBase), 8, scsi    );
}

#define GetBlkSize(arg1) \
    __inline_scsi_GetBlkSize((arg1), __SCSI_LIBBASE)

#endif /* !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__) */

#endif /* INLINE_SCSI_H*/
