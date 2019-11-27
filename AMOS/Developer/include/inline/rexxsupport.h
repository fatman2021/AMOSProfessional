#ifndef INLINE_REXXSUPPORT_H
#define INLINE_REXXSUPPORT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/rexxsupport/rexxsupport.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for rexxsupport
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REXXSUPPORT_LIBBASE)
#    define __REXXSUPPORT_LIBBASE RexxSupportBase
#endif


#if !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__)

static inline ULONG __inline_RexxSupport_ArexxDispatch(struct RexxMsg * __arg1, STRPTR * __arg2, APTR __RexxSupportBase)
{
    AROS_LIBREQ(RexxSupportBase, 34)
    return AROS_LC2(ULONG, ArexxDispatch,
        AROS_LCA(struct RexxMsg *,(__arg1),A0),
        AROS_LCA(STRPTR *,(__arg2),A1),
        struct Library *, (__RexxSupportBase), 5, RexxSupport    );
}

#define ArexxDispatch(arg1, arg2) \
    __inline_RexxSupport_ArexxDispatch((arg1), (arg2), __REXXSUPPORT_LIBBASE)

#endif /* !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__) */

#if !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__)

static inline void __inline_RexxSupport_ClosePortRsrc(struct RexxRsrc * __arg1, APTR __RexxSupportBase)
{
    AROS_LIBREQ(RexxSupportBase, 34)
    AROS_LC1NR(void, ClosePortRsrc,
        AROS_LCA(struct RexxRsrc *,(__arg1),A0),
        struct Library *, (__RexxSupportBase), 6, RexxSupport    );
}

#define ClosePortRsrc(arg1) \
    __inline_RexxSupport_ClosePortRsrc((arg1), __REXXSUPPORT_LIBBASE)

#endif /* !defined(__REXXSUPPORT_LIBAPI__) || (34 <= __REXXSUPPORT_LIBAPI__) */

#endif /* INLINE_REXXSUPPORT_H*/
