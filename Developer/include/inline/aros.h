#ifndef INLINE_AROS_H
#define INLINE_AROS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/aros/aros.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for aros
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__AROS_LIBBASE)
#    define __AROS_LIBBASE ArosBase
#endif


#if !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__)

static inline ULONG __inline_Aros_ArosInquireA(struct TagItem * __arg1, APTR __ArosBase)
{
    AROS_LIBREQ(ArosBase, 41)
    return AROS_LC1(ULONG, ArosInquireA,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct Library *, (__ArosBase), 5, Aros    );
}

#define ArosInquireA(arg1) \
    __inline_Aros_ArosInquireA((arg1), __AROS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(AROS_NO_INLINE_STDARG)
#define ArosInquire(...) \
({ \
    const IPTR ArosInquireA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ArosInquireA((struct TagItem *)(ArosInquireA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__) */

#endif /* INLINE_AROS_H*/
