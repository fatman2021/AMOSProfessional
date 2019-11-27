#ifndef DEFINES_ATA_H
#define DEFINES_ATA_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/ata/ata.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for ata
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__ATA_LIBBASE)
#    define __ATA_LIBBASE ataBase
#endif

__BEGIN_DECLS


#if !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__)

#define __GetRdskLba_WB(__ataBase, __arg1) ({\
        AROS_LIBREQ(ataBase,0)\
        AROS_LC1(ULONG, GetRdskLba, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct Device *, (__ataBase), 7, ata);\
})

#define GetRdskLba(arg1) \
    __GetRdskLba_WB(__ATA_LIBBASE, (arg1))

#endif /* !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__) */

#if !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__)

#define __GetBlkSize_WB(__ataBase, __arg1) ({\
        AROS_LIBREQ(ataBase,0)\
        AROS_LC1(ULONG, GetBlkSize, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct Device *, (__ataBase), 8, ata);\
})

#define GetBlkSize(arg1) \
    __GetBlkSize_WB(__ATA_LIBBASE, (arg1))

#endif /* !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_ATA_H*/
