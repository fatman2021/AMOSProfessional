#ifndef DEFINES_BOOTLOADER_H
#define DEFINES_BOOTLOADER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/bootloader/bootloader.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for bootloader
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__BOOTLOADER_LIBBASE)
#    define __BOOTLOADER_LIBBASE BootLoaderBase
#endif

__BEGIN_DECLS


#if !defined(__BOOTLOADER_LIBAPI__) || (41 <= __BOOTLOADER_LIBAPI__)

#define __GetBootInfo_WB(__BootLoaderBase, __arg1) ({\
        AROS_LIBREQ(BootLoaderBase,41)\
        AROS_LC1(APTR, GetBootInfo, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        APTR , (__BootLoaderBase), 1, Bootloader);\
})

#define GetBootInfo(arg1) \
    __GetBootInfo_WB(__BOOTLOADER_LIBBASE, (arg1))

#endif /* !defined(__BOOTLOADER_LIBAPI__) || (41 <= __BOOTLOADER_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_BOOTLOADER_H*/
