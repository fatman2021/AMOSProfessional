#ifndef INLINE_ATA_H
#define INLINE_ATA_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/ata/ata.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for ata
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__ATA_LIBBASE)
#    define __ATA_LIBBASE ataBase
#endif


#if !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__)

static inline ULONG __inline_ata_GetRdskLba(struct IORequest * __arg1, APTR __ataBase)
{
    AROS_LIBREQ(ataBase, 0)
    return AROS_LC1(ULONG, GetRdskLba,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct Device *, (__ataBase), 7, ata    );
}

#define GetRdskLba(arg1) \
    __inline_ata_GetRdskLba((arg1), __ATA_LIBBASE)

#endif /* !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__) */

#if !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__)

static inline ULONG __inline_ata_GetBlkSize(struct IORequest * __arg1, APTR __ataBase)
{
    AROS_LIBREQ(ataBase, 0)
    return AROS_LC1(ULONG, GetBlkSize,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct Device *, (__ataBase), 8, ata    );
}

#define GetBlkSize(arg1) \
    __inline_ata_GetBlkSize((arg1), __ATA_LIBBASE)

#endif /* !defined(__ATA_LIBAPI__) || (0 <= __ATA_LIBAPI__) */

#endif /* INLINE_ATA_H*/
