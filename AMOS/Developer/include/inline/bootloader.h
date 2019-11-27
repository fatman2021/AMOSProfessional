#ifndef INLINE_BOOTLOADER_H
#define INLINE_BOOTLOADER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/bootloader/bootloader.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for bootloader
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__BOOTLOADER_LIBBASE)
#    define __BOOTLOADER_LIBBASE BootLoaderBase
#endif


#if !defined(__BOOTLOADER_LIBAPI__) || (41 <= __BOOTLOADER_LIBAPI__)

static inline APTR __inline_Bootloader_GetBootInfo(ULONG __arg1, APTR __BootLoaderBase)
{
    AROS_LIBREQ(BootLoaderBase, 41)
    return AROS_LC1(APTR, GetBootInfo,
        AROS_LCA(ULONG,(__arg1),D0),
        APTR , (__BootLoaderBase), 1, Bootloader    );
}

#define GetBootInfo(arg1) \
    __inline_Bootloader_GetBootInfo((arg1), __BOOTLOADER_LIBBASE)

#endif /* !defined(__BOOTLOADER_LIBAPI__) || (41 <= __BOOTLOADER_LIBAPI__) */

#endif /* INLINE_BOOTLOADER_H*/
