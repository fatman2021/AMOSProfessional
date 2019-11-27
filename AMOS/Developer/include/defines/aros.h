#ifndef DEFINES_AROS_H
#define DEFINES_AROS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/aros/aros.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for aros
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__AROS_LIBBASE)
#    define __AROS_LIBBASE ArosBase
#endif

__BEGIN_DECLS


#if !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__)

#define __ArosInquireA_WB(__ArosBase, __arg1) ({\
        AROS_LIBREQ(ArosBase,41)\
        AROS_LC1(ULONG, ArosInquireA, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct Library *, (__ArosBase), 5, Aros);\
})

#define ArosInquireA(arg1) \
    __ArosInquireA_WB(__AROS_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(AROS_NO_INLINE_STDARG)
#define ArosInquire(...) \
({ \
    const IPTR ArosInquireA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ArosInquireA((struct TagItem *)(ArosInquireA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_AROS_H*/
