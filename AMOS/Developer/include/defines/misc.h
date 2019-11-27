#ifndef DEFINES_MISC_H
#define DEFINES_MISC_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/misc/misc.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for misc
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MISC_LIBBASE)
#    define __MISC_LIBBASE MiscBase
#endif

__BEGIN_DECLS


#if !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__)

#define __AllocMiscResource_WB(__MiscBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MiscBase,41)\
        AROS_LC2(char *, AllocMiscResource, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(char *,(__arg2),A0), \
        APTR , (__MiscBase), 1, Misc);\
})

#define AllocMiscResource(arg1, arg2) \
    __AllocMiscResource_WB(__MISC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__) */

#if !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__)

#define __FreeMiscResource_WB(__MiscBase, __arg1) ({\
        AROS_LIBREQ(MiscBase,41)\
        AROS_LC1NR(void, FreeMiscResource, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        APTR , (__MiscBase), 2, Misc);\
})

#define FreeMiscResource(arg1) \
    __FreeMiscResource_WB(__MISC_LIBBASE, (arg1))

#endif /* !defined(__MISC_LIBAPI__) || (41 <= __MISC_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MISC_H*/
