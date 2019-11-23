#ifndef INLINE_COOLIMAGES_H
#define INLINE_COOLIMAGES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/coolimages/coolimages.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for coolimages
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COOLIMAGES_LIBBASE)
#    define __COOLIMAGES_LIBBASE CoolImagesBase
#endif


#if !defined(__COOLIMAGES_LIBAPI__) || (1 <= __COOLIMAGES_LIBAPI__)

static inline const struct CoolImage * __inline_CoolImages_COOL_ObtainImageA(ULONG __arg1, struct TagItem * __arg2, APTR __CoolImagesBase)
{
    AROS_LIBREQ(CoolImagesBase, 1)
    return AROS_LC2(const struct CoolImage *, COOL_ObtainImageA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Library *, (__CoolImagesBase), 5, CoolImages    );
}

#define COOL_ObtainImageA(arg1, arg2) \
    __inline_CoolImages_COOL_ObtainImageA((arg1), (arg2), __COOLIMAGES_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(COOLIMAGES_NO_INLINE_STDARG)
#define COOL_ObtainImage(arg1, ...) \
({ \
    const IPTR COOL_ObtainImageA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    COOL_ObtainImageA((arg1), (struct TagItem *)(COOL_ObtainImageA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__COOLIMAGES_LIBAPI__) || (1 <= __COOLIMAGES_LIBAPI__) */

#endif /* INLINE_COOLIMAGES_H*/
