#ifndef DEFINES_DISKFONT_H
#define DEFINES_DISKFONT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/diskfont/diskfont.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for diskfont
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DISKFONT_LIBBASE)
#    define __DISKFONT_LIBBASE DiskfontBase
#endif

__BEGIN_DECLS


#if !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__)

#define __OpenDiskFont_WB(__DiskfontBase, __arg1) ({\
        AROS_LIBREQ(DiskfontBase,0)\
        AROS_LC1(struct TextFont *, OpenDiskFont, \
                  AROS_LCA(struct TextAttr *,(__arg1),A0), \
        struct Library *, (__DiskfontBase), 5, Diskfont);\
})

#define OpenDiskFont(arg1) \
    __OpenDiskFont_WB(__DISKFONT_LIBBASE, (arg1))

#endif /* !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__)

#define __AvailFonts_WB(__DiskfontBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DiskfontBase,0)\
        AROS_LC3(LONG, AvailFonts, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(LONG,(__arg3),D1), \
        struct Library *, (__DiskfontBase), 6, Diskfont);\
})

#define AvailFonts(arg1, arg2, arg3) \
    __AvailFonts_WB(__DISKFONT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DISKFONT_LIBAPI__) || (0 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__)

#define __NewFontContents_WB(__DiskfontBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskfontBase,34)\
        AROS_LC2(struct FontContentsHeader *, NewFontContents, \
                  AROS_LCA(BPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
        struct Library *, (__DiskfontBase), 7, Diskfont);\
})

#define NewFontContents(arg1, arg2) \
    __NewFontContents_WB(__DISKFONT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__)

#define __DisposeFontContents_WB(__DiskfontBase, __arg1) ({\
        AROS_LIBREQ(DiskfontBase,34)\
        AROS_LC1NR(void, DisposeFontContents, \
                  AROS_LCA(struct FontContentsHeader *,(__arg1),A1), \
        struct Library *, (__DiskfontBase), 8, Diskfont);\
})

#define DisposeFontContents(arg1) \
    __DisposeFontContents_WB(__DISKFONT_LIBBASE, (arg1))

#endif /* !defined(__DISKFONT_LIBAPI__) || (34 <= __DISKFONT_LIBAPI__) */

#if !defined(__DISKFONT_LIBAPI__) || (36 <= __DISKFONT_LIBAPI__)

#define __NewScaledDiskFont_WB(__DiskfontBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DiskfontBase,36)\
        AROS_LC2(struct DiskFont *, NewScaledDiskFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A0), \
                  AROS_LCA(struct TextAttr *,(__arg2),A1), \
        struct Library *, (__DiskfontBase), 9, Diskfont);\
})

#define NewScaledDiskFont(arg1, arg2) \
    __NewScaledDiskFont_WB(__DISKFONT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DISKFONT_LIBAPI__) || (36 <= __DISKFONT_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DISKFONT_H*/
