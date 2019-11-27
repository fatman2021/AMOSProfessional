#ifndef INLINE_RAMDRIVE_H
#define INLINE_RAMDRIVE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/devs/ramdrive.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for ramdrive
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__RAMDRIVE_LIBBASE)
#    define __RAMDRIVE_LIBBASE RamdriveBase
#endif


#if !defined(__RAMDRIVE_LIBAPI__) || (0 <= __RAMDRIVE_LIBAPI__)

static inline STRPTR __inline_Ramdrive_killrad0(APTR __RamdriveBase)
{
    AROS_LIBREQ(RamdriveBase, 0)
    return AROS_LC0(STRPTR, killrad0,
        struct Device *, (__RamdriveBase), 7, Ramdrive    );
}

#define killrad0() \
    __inline_Ramdrive_killrad0(__RAMDRIVE_LIBBASE)

#endif /* !defined(__RAMDRIVE_LIBAPI__) || (0 <= __RAMDRIVE_LIBAPI__) */

#if !defined(__RAMDRIVE_LIBAPI__) || (0 <= __RAMDRIVE_LIBAPI__)

static inline STRPTR __inline_Ramdrive_killrad(ULONG __arg1, APTR __RamdriveBase)
{
    AROS_LIBREQ(RamdriveBase, 0)
    return AROS_LC1(STRPTR, killrad,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Device *, (__RamdriveBase), 8, Ramdrive    );
}

#define killrad(arg1) \
    __inline_Ramdrive_killrad((arg1), __RAMDRIVE_LIBBASE)

#endif /* !defined(__RAMDRIVE_LIBAPI__) || (0 <= __RAMDRIVE_LIBAPI__) */

#endif /* INLINE_RAMDRIVE_H*/
