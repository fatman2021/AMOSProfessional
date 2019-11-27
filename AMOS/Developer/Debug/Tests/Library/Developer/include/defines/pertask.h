#ifndef DEFINES_PERTASK_H
#define DEFINES_PERTASK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/pertask.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for pertask
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PERTASK_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__PERTASK_NOLIBBASE__)
#    define __PERTASK_LIBBASE __aros_getbase_PertaskBase()
#  else
#    define __PERTASK_LIBBASE PertaskBase
#  endif
#endif

__BEGIN_DECLS


#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)

#define __GetParentBase_WB(__PertaskBase) ({\
        AROS_LIBREQ(PertaskBase,1)\
        AROS_LC0(struct Library *, GetParentBase, \
        struct Library *, (__PertaskBase), 5, Pertask);\
})

#define GetParentBase() \
    __GetParentBase_WB(__PERTASK_LIBBASE)

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PERTASK_H*/
