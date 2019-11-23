#ifndef INLINE_DISKFONT_H
#define INLINE_DISKFONT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/diskfont/diskfont.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for diskfont
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISKFONT_LIBBASE)
#    define __DISKFONT_LIBBASE DiskfontBase
#endif


#if !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__)

static inline struct TextFont * __inline_Diskfont_OpenDiskFont(struct TextAttr * __arg1, APTR __DiskfontBase)
{
    AROS_LIBREQ(DiskfontBase, 0)
    return AROS_LC1(struct TextFont *, OpenDiskFont,
        AROS_LCA(struct TextAttr *,(__arg1),A0),
        struct Library *, (__DiskfontBase), 5, Diskfont    );
}

#define OpenDiskFont(arg1) \
    __inline_Diskfont_OpenDiskFont((arg1), __DISKFONT_LIBBASE)

#endif /* !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__)

static inline LONG __inline_Diskfont_AvailFonts(STRPTR __arg1, LONG __arg2, LONG __arg3, APTR __DiskfontBase)
{
    AROS_LIBREQ(DiskfontBase, 0)
    return AROS_LC3(LONG, AvailFonts,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__DiskfontBase), 6, Diskfont    );
}

#define AvailFonts(arg1, arg2, arg3) \
    __inline_Diskfont_AvailFonts((arg1), (arg2), (arg3), __DISKFONT_LIBBASE)

#endif /* !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__)

static inline struct FontContentsHeader * __inline_Diskfont_NewFontContents(BPTR __arg1, STRPTR __arg2, APTR __DiskfontBase)
{
    AROS_LIBREQ(DiskfontBase, 34)
    return AROS_LC2(struct FontContentsHeader *, NewFontContents,
        AROS_LCA(BPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        struct Library *, (__DiskfontBase), 7, Diskfont    );
}

#define NewFontContents(arg1, arg2) \
    __inline_Diskfont_NewFontContents((arg1), (arg2), __DISKFONT_LIBBASE)

#endif /* !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__)

static inline void __inline_Diskfont_DisposeFontContents(struct FontContentsHeader * __arg1, APTR __DiskfontBase)
{
    AROS_LIBREQ(DiskfontBase, 34)
    AROS_LC1NR(void, DisposeFontContents,
        AROS_LCA(struct FontContentsHeader *,(__arg1),A1),
        struct Library *, (__DiskfontBase), 8, Diskfont    );
}

#define DisposeFontContents(arg1) \
    __inline_Diskfont_DisposeFontContents((arg1), __DISKFONT_LIBBASE)

#endif /* !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (36 <= __DISKFONT_LIBAPI__)

static inline struct DiskFont * __inline_Diskfont_NewScaledDiskFont(struct TextFont * __arg1, struct TextAttr * __arg2, APTR __DiskfontBase)
{
    AROS_LIBREQ(DiskfontBase, 36)
    return AROS_LC2(struct DiskFont *, NewScaledDiskFont,
        AROS_LCA(struct TextFont *,(__arg1),A0),
        AROS_LCA(struct TextAttr *,(__arg2),A1),
        struct Library *, (__DiskfontBase), 9, Diskfont    );
}

#define NewScaledDiskFont(arg1, arg2) \
    __inline_Diskfont_NewScaledDiskFont((arg1), (arg2), __DISKFONT_LIBBASE)

#endif /* !defined(__DISKFONT_LIBAPI__) || (36 <= __DISKFONT_LIBAPI__) */

#endif /* INLINE_DISKFONT_H*/
