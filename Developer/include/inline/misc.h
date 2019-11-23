#ifndef INLINE_MISC_H
#define INLINE_MISC_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/misc/misc.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for misc
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MISC_LIBBASE)
#    define __MISC_LIBBASE MiscBase
#endif


#if !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__)

static inline char * __inline_Misc_AllocMiscResource(ULONG __arg1, char * __arg2, APTR __MiscBase)
{
    AROS_LIBREQ(MiscBase, 41)
    return AROS_LC2(char *, AllocMiscResource,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(char *,(__arg2),A0),
        APTR , (__MiscBase), 1, Misc    );
}

#define AllocMiscResource(arg1, arg2) \
    __inline_Misc_AllocMiscResource((arg1), (arg2), __MISC_LIBBASE)

#endif /* !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__) */

#if !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__)

static inline void __inline_Misc_FreeMiscResource(ULONG __arg1, APTR __MiscBase)
{
    AROS_LIBREQ(MiscBase, 41)
    AROS_LC1NR(void, FreeMiscResource,
        AROS_LCA(ULONG,(__arg1),D0),
        APTR , (__MiscBase), 2, Misc    );
}

#define FreeMiscResource(arg1) \
    __inline_Misc_FreeMiscResource((arg1), __MISC_LIBBASE)

#endif /* !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__) */

#endif /* INLINE_MISC_H*/
