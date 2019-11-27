#ifndef INLINE_LDDEMON_H
#define INLINE_LDDEMON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/lddemon/lddemon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for lddemon
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__LDDEMON_LIBBASE)
#    define __LDDEMON_LIBBASE ldBase
#endif


#if !defined(__LDDEMON_LIBAPI__) || (41 <= __LDDEMON_LIBAPI__)

static inline BPTR __inline_Lddemon_LDLoadSeg(CONST_STRPTR __arg1, APTR __ldBase)
{
    AROS_LIBREQ(ldBase, 41)
    return AROS_LC1(BPTR, LDLoadSeg,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct LDDemonBase *, (__ldBase), 1, Lddemon    );
}

#define LDLoadSeg(arg1) \
    __inline_Lddemon_LDLoadSeg((arg1), __LDDEMON_LIBBASE)

#endif /* !defined(__LDDEMON_LIBAPI__) || (41 <= __LDDEMON_LIBAPI__) */

#endif /* INLINE_LDDEMON_H*/
