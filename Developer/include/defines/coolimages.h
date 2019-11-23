#ifndef DEFINES_COOLIMAGES_H
#define DEFINES_COOLIMAGES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/coolimages/coolimages.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for coolimages
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COOLIMAGES_LIBBASE)
#    define __COOLIMAGES_LIBBASE CoolImagesBase
#endif

__BEGIN_DECLS


#if !defined(__COOLIMAGES_LIBAPI__) || (1 <= __COOLIMAGES_LIBAPI__)

#define __COOL_ObtainImageA_WB(__CoolImagesBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CoolImagesBase,1)\
        AROS_LC2(const struct CoolImage *, COOL_ObtainImageA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Library *, (__CoolImagesBase), 5, CoolImages);\
})

#define COOL_ObtainImageA(arg1, arg2) \
    __COOL_ObtainImageA_WB(__COOLIMAGES_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(COOLIMAGES_NO_INLINE_STDARG)
#define COOL_ObtainImage(arg1, ...) \
({ \
    const IPTR COOL_ObtainImageA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    COOL_ObtainImageA((arg1), (struct TagItem *)(COOL_ObtainImageA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__COOLIMAGES_LIBAPI__) || (1 <= __COOLIMAGES_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_COOLIMAGES_H*/
