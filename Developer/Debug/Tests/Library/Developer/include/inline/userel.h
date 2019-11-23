#ifndef INLINE_USEREL_H
#define INLINE_USEREL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/userel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for userel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__USEREL_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__USEREL_NOLIBBASE__)
#    define __USEREL_LIBBASE __aros_getbase_UserelBase()
#  else
#    define __USEREL_LIBBASE UserelBase
#  endif
#endif


#if !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__)

static inline ULONG __inline_Userel_DummyAdd(ULONG __arg1, ULONG __arg2, APTR __UserelBase)
{
    AROS_LIBREQ(UserelBase, 1)
    return AROS_LC2(ULONG, DummyAdd,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__UserelBase), 5, Userel    );
}

#define DummyAdd(arg1, arg2) \
    __inline_Userel_DummyAdd((arg1), (arg2), __USEREL_LIBBASE)

#endif /* !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__) */

#endif /* INLINE_USEREL_H*/
