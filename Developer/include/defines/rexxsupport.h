#ifndef DEFINES_REXXSUPPORT_H
#define DEFINES_REXXSUPPORT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/rexxsupport/rexxsupport.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for rexxsupport
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REXXSUPPORT_LIBBASE)
#    define __REXXSUPPORT_LIBBASE RexxSupportBase
#endif

__BEGIN_DECLS


#if !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__)

#define __ArexxDispatch_WB(__RexxSupportBase, __arg1, __arg2) ({\
        AROS_LIBREQ(RexxSupportBase,34)\
        AROS_LC2(ULONG, ArexxDispatch, \
                  AROS_LCA(struct RexxMsg *,(__arg1),A0), \
                  AROS_LCA(STRPTR *,(__arg2),A1), \
        struct Library *, (__RexxSupportBase), 5, RexxSupport);\
})

#define ArexxDispatch(arg1, arg2) \
    __ArexxDispatch_WB(__REXXSUPPORT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__) */

#if !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__)

#define __ClosePortRsrc_WB(__RexxSupportBase, __arg1) ({\
        AROS_LIBREQ(RexxSupportBase,34)\
        AROS_LC1NR(void, ClosePortRsrc, \
                  AROS_LCA(struct RexxRsrc *,(__arg1),A0), \
        struct Library *, (__RexxSupportBase), 6, RexxSupport);\
})

#define ClosePortRsrc(arg1) \
    __ClosePortRsrc_WB(__REXXSUPPORT_LIBBASE, (arg1))

#endif /* !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_REXXSUPPORT_H*/
