#ifndef DEFINES_SCSI_H
#define DEFINES_SCSI_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/scsi/scsi.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for scsi
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__SCSI_LIBBASE)
#    define __SCSI_LIBBASE SCSIBase
#endif

__BEGIN_DECLS


#if !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__)

#define __GetRdskLba_WB(__SCSIBase, __arg1) ({\
        AROS_LIBREQ(SCSIBase,0)\
        AROS_LC1(ULONG, GetRdskLba, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct Device *, (__SCSIBase), 7, scsi);\
})

#define GetRdskLba(arg1) \
    __GetRdskLba_WB(__SCSI_LIBBASE, (arg1))

#endif /* !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__) */

#if !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__)

#define __GetBlkSize_WB(__SCSIBase, __arg1) ({\
        AROS_LIBREQ(SCSIBase,0)\
        AROS_LC1(ULONG, GetBlkSize, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct Device *, (__SCSIBase), 8, scsi);\
})

#define GetBlkSize(arg1) \
    __GetBlkSize_WB(__SCSI_LIBBASE, (arg1))

#endif /* !defined(__SCSI_LIBAPI__) || (0 <= __SCSI_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_SCSI_H*/
