#ifndef INLINE_DUMMY_H
#define INLINE_DUMMY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/dummy.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for dummy
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DUMMY_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__DUMMY_NOLIBBASE__)
#    define __DUMMY_LIBBASE __aros_getbase_DummyBase()
#  else
#    define __DUMMY_LIBBASE DummyBase
#  endif
#endif


#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)

static inline ULONG __inline_Dummy_add(ULONG __arg1, ULONG __arg2, APTR __DummyBase)
{
    AROS_LIBREQ(DummyBase, 1)
    return AROS_LC2(ULONG, add,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__DummyBase), 5, Dummy    );
}

#define add(arg1, arg2) \
    __inline_Dummy_add((arg1), (arg2), __DUMMY_LIBBASE)

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)

static inline ULONG __inline_Dummy_asl(ULONG __arg1, ULONG __arg2, APTR __DummyBase)
{
    AROS_LIBREQ(DummyBase, 1)
    return AROS_LC2(ULONG, asl,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__DummyBase), 6, Dummy    );
}

#define asl(arg1, arg2) \
    __inline_Dummy_asl((arg1), (arg2), __DUMMY_LIBBASE)

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

#endif /* INLINE_DUMMY_H*/
