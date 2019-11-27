#ifndef DEFINES_DUMMY_H
#define DEFINES_DUMMY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/dummy.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for dummy
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

__BEGIN_DECLS


#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)

#define __add_WB(__DummyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DummyBase,1)\
        AROS_LC2(ULONG, add, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct Library *, (__DummyBase), 5, Dummy);\
})

#define add(arg1, arg2) \
    __add_WB(__DUMMY_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)

#define __asl_WB(__DummyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DummyBase,1)\
        AROS_LC2(ULONG, asl, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct Library *, (__DummyBase), 6, Dummy);\
})

#define asl(arg1, arg2) \
    __asl_WB(__DUMMY_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DUMMY_H*/
