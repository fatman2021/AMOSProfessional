#ifndef INLINE_PERTASK_H
#define INLINE_PERTASK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/pertask.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for pertask
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


#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)

static inline struct Library * __inline_Pertask_GetParentBase(APTR __PertaskBase)
{
    AROS_LIBREQ(PertaskBase, 1)
    return AROS_LC0(struct Library *, GetParentBase,
        struct Library *, (__PertaskBase), 5, Pertask    );
}

#define GetParentBase() \
    __inline_Pertask_GetParentBase(__PERTASK_LIBBASE)

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

#endif /* INLINE_PERTASK_H*/
