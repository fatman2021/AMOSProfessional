#ifndef DEFINES_PEROPENER_H
#define DEFINES_PEROPENER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/peropener.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for peropener
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PEROPENER_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__PEROPENER_NOLIBBASE__)
#    define __PEROPENER_LIBBASE __aros_getbase_PeropenerBase()
#  else
#    define __PEROPENER_LIBBASE PeropenerBase
#  endif
#endif

__BEGIN_DECLS


#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)

#define __PeropenerSetValueReg_WB(__PeropenerBase, __arg1) ({\
        AROS_LIBREQ(PeropenerBase,2)\
        AROS_LC1NR(void, PeropenerSetValueReg, \
                  AROS_LCA(int,(__arg1),D0), \
        struct Library *, (__PeropenerBase), 7, Peropener);\
})

#define PeropenerSetValueReg(arg1) \
    __PeropenerSetValueReg_WB(__PEROPENER_LIBBASE, (arg1))

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)

#define __PeropenerGetValueReg_WB(__PeropenerBase) ({\
        AROS_LIBREQ(PeropenerBase,2)\
        AROS_LC0(int, PeropenerGetValueReg, \
        struct Library *, (__PeropenerBase), 8, Peropener);\
})

#define PeropenerGetValueReg() \
    __PeropenerGetValueReg_WB(__PEROPENER_LIBBASE)

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PEROPENER_H*/
