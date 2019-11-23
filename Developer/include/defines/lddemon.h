#ifndef DEFINES_LDDEMON_H
#define DEFINES_LDDEMON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/lddemon/lddemon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for lddemon
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__LDDEMON_LIBBASE)
#    define __LDDEMON_LIBBASE ldBase
#endif

__BEGIN_DECLS


#if !defined(__LDDEMON_LIBAPI__) || (41 <= __LDDEMON_LIBAPI__)

#define __LDLoadSeg_WB(__ldBase, __arg1) ({\
        AROS_LIBREQ(ldBase,41)\
        AROS_LC1(BPTR, LDLoadSeg, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct LDDemonBase *, (__ldBase), 1, Lddemon);\
})

#define LDLoadSeg(arg1) \
    __LDLoadSeg_WB(__LDDEMON_LIBBASE, (arg1))

#endif /* !defined(__LDDEMON_LIBAPI__) || (41 <= __LDDEMON_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_LDDEMON_H*/
