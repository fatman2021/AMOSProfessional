#ifndef INLINE_FREETYPE2_H
#define INLINE_FREETYPE2_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/freetype2/freetype2.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for freetype2
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__FREETYPE2_LIBBASE)
#    define __FREETYPE2_LIBBASE FreeType2Base
#endif


#if !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__)

static inline struct GlyphEngine * __inline_FreeType2_OpenEngine(APTR __FreeType2Base)
{
    AROS_LIBREQ(FreeType2Base, 6)
    return AROS_LC0(struct GlyphEngine *, OpenEngine,
        struct Library *, (__FreeType2Base), 5, FreeType2    );
}

#define OpenEngine() \
    __inline_FreeType2_OpenEngine(__FREETYPE2_LIBBASE)

#endif /* !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__) */

#if !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__)

static inline void __inline_FreeType2_CloseEngine(struct GlyphEngine * __arg1, APTR __FreeType2Base)
{
    AROS_LIBREQ(FreeType2Base, 6)
    AROS_LC1NR(void, CloseEngine,
        AROS_LCA(struct GlyphEngine *,(__arg1),A0),
        struct Library *, (__FreeType2Base), 6, FreeType2    );
}

#define CloseEngine(arg1) \
    __inline_FreeType2_CloseEngine((arg1), __FREETYPE2_LIBBASE)

#endif /* !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__) */

#if !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__)

static inline ULONG __inline_FreeType2_SetInfoA(struct GlyphEngine * __arg1, struct TagItem * __arg2, APTR __FreeType2Base)
{
    AROS_LIBREQ(FreeType2Base, 6)
    return AROS_LC2(ULONG, SetInfoA,
        AROS_LCA(struct GlyphEngine *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__FreeType2Base), 7, FreeType2    );
}

#define SetInfoA(arg1, arg2) \
    __inline_FreeType2_SetInfoA((arg1), (arg2), __FREETYPE2_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(FREETYPE2_NO_INLINE_STDARG)
#define SetInfo(arg1, ...) \
({ \
    const IPTR SetInfoA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetInfoA((arg1), (struct TagItem *)(SetInfoA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__) */

#if !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__)

static inline ULONG __inline_FreeType2_ObtainInfoA(struct GlyphEngine * __arg1, struct TagItem * __arg2, APTR __FreeType2Base)
{
    AROS_LIBREQ(FreeType2Base, 6)
    return AROS_LC2(ULONG, ObtainInfoA,
        AROS_LCA(struct GlyphEngine *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__FreeType2Base), 8, FreeType2    );
}

#define ObtainInfoA(arg1, arg2) \
    __inline_FreeType2_ObtainInfoA((arg1), (arg2), __FREETYPE2_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(FREETYPE2_NO_INLINE_STDARG)
#define ObtainInfo(arg1, ...) \
({ \
    const IPTR ObtainInfoA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ObtainInfoA((arg1), (struct TagItem *)(ObtainInfoA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__) */

#if !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__)

static inline ULONG __inline_FreeType2_ReleaseInfoA(struct GlyphEngine * __arg1, struct TagItem * __arg2, APTR __FreeType2Base)
{
    AROS_LIBREQ(FreeType2Base, 6)
    return AROS_LC2(ULONG, ReleaseInfoA,
        AROS_LCA(struct GlyphEngine *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__FreeType2Base), 9, FreeType2    );
}

#define ReleaseInfoA(arg1, arg2) \
    __inline_FreeType2_ReleaseInfoA((arg1), (arg2), __FREETYPE2_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(FREETYPE2_NO_INLINE_STDARG)
#define ReleaseInfo(arg1, ...) \
({ \
    const IPTR ReleaseInfoA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ReleaseInfoA((arg1), (struct TagItem *)(ReleaseInfoA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__FREETYPE2_LIBAPI__) || (6 <= __FREETYPE2_LIBAPI__) */

#endif /* INLINE_FREETYPE2_H*/
