#ifndef INLINE_ICON_H
#define INLINE_ICON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/icon/icon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for icon
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__ICON_LIBBASE)
#    define __ICON_LIBBASE IconBase
#endif


#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline void __inline_Icon_FreeFreeList(struct FreeList * __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    AROS_LC1NR(void, FreeFreeList,
        AROS_LCA(struct FreeList *,(__arg1),A0),
        struct Library *, (__IconBase), 9, Icon    );
}

#define FreeFreeList(arg1) \
    __inline_Icon_FreeFreeList((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_AddFreeList(struct FreeList * __arg1, APTR __arg2, unsigned long __arg3, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC3(BOOL, AddFreeList,
        AROS_LCA(struct FreeList *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(unsigned long,(__arg3),A2),
        struct Library *, (__IconBase), 12, Icon    );
}

#define AddFreeList(arg1, arg2, arg3) \
    __inline_Icon_AddFreeList((arg1), (arg2), (arg3), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_GetDiskObject(CONST_STRPTR __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC1(struct DiskObject *, GetDiskObject,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct Library *, (__IconBase), 13, Icon    );
}

#define GetDiskObject(arg1) \
    __inline_Icon_GetDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_PutDiskObject(CONST_STRPTR __arg1, struct DiskObject * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC2(BOOL, PutDiskObject,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(struct DiskObject *,(__arg2),A1),
        struct Library *, (__IconBase), 14, Icon    );
}

#define PutDiskObject(arg1, arg2) \
    __inline_Icon_PutDiskObject((arg1), (arg2), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline void __inline_Icon_FreeDiskObject(struct DiskObject * __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    AROS_LC1NR(void, FreeDiskObject,
        AROS_LCA(struct DiskObject *,(__arg1),A0),
        struct Library *, (__IconBase), 15, Icon    );
}

#define FreeDiskObject(arg1) \
    __inline_Icon_FreeDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline UBYTE * __inline_Icon_FindToolType(const STRPTR * __arg1, const STRPTR __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC2(UBYTE *, FindToolType,
        AROS_LCA(const STRPTR *,(__arg1),A0),
        AROS_LCA(const STRPTR,(__arg2),A1),
        struct Library *, (__IconBase), 16, Icon    );
}

#define FindToolType(arg1, arg2) \
    __inline_Icon_FindToolType((arg1), (arg2), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_MatchToolValue(UBYTE * __arg1, UBYTE * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC2(BOOL, MatchToolValue,
        AROS_LCA(UBYTE *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        struct Library *, (__IconBase), 17, Icon    );
}

#define MatchToolValue(arg1, arg2) \
    __inline_Icon_MatchToolValue((arg1), (arg2), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline UBYTE * __inline_Icon_BumpRevision(UBYTE * __arg1, UBYTE * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC2(UBYTE *, BumpRevision,
        AROS_LCA(UBYTE *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        struct Library *, (__IconBase), 18, Icon    );
}

#define BumpRevision(arg1, arg2) \
    __inline_Icon_BumpRevision((arg1), (arg2), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_GetDefDiskObject(LONG __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC1(struct DiskObject *, GetDefDiskObject,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__IconBase), 20, Icon    );
}

#define GetDefDiskObject(arg1) \
    __inline_Icon_GetDefDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_PutDefDiskObject(struct DiskObject * __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC1(BOOL, PutDefDiskObject,
        AROS_LCA(struct DiskObject *,(__arg1),A0),
        struct Library *, (__IconBase), 21, Icon    );
}

#define PutDefDiskObject(arg1) \
    __inline_Icon_PutDefDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_GetDiskObjectNew(CONST_STRPTR __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 36)
    return AROS_LC1(struct DiskObject *, GetDiskObjectNew,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct Library *, (__IconBase), 22, Icon    );
}

#define GetDiskObjectNew(arg1) \
    __inline_Icon_GetDiskObjectNew((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (36 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (37 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_DeleteDiskObject(UBYTE * __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 37)
    return AROS_LC1(BOOL, DeleteDiskObject,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct Library *, (__IconBase), 23, Icon    );
}

#define DeleteDiskObject(arg1) \
    __inline_Icon_DeleteDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (37 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_DupDiskObjectA(struct DiskObject * __arg1, struct TagItem * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC2(struct DiskObject *, DupDiskObjectA,
        AROS_LCA(struct DiskObject *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__IconBase), 25, Icon    );
}

#define DupDiskObjectA(arg1, arg2) \
    __inline_Icon_DupDiskObjectA((arg1), (arg2), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define DupDiskObject(arg1, ...) \
({ \
    const IPTR DupDiskObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DupDiskObjectA((arg1), (struct TagItem *)(DupDiskObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline ULONG __inline_Icon_IconControlA(struct DiskObject * __arg1, struct TagItem * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC2(ULONG, IconControlA,
        AROS_LCA(struct DiskObject *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__IconBase), 26, Icon    );
}

#define IconControlA(arg1, arg2) \
    __inline_Icon_IconControlA((arg1), (arg2), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define IconControl(arg1, ...) \
({ \
    const IPTR IconControlA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IconControlA((arg1), (struct TagItem *)(IconControlA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline void __inline_Icon_DrawIconStateA(struct RastPort * __arg1, struct DiskObject * __arg2, STRPTR __arg3, LONG __arg4, LONG __arg5, ULONG __arg6, struct TagItem * __arg7, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    AROS_LC7NR(void, DrawIconStateA,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct DiskObject *,(__arg2),A1),
        AROS_LCA(STRPTR,(__arg3),A2),
        AROS_LCA(LONG,(__arg4),D0),
        AROS_LCA(LONG,(__arg5),D1),
        AROS_LCA(ULONG,(__arg6),D2),
        AROS_LCA(struct TagItem *,(__arg7),A3),
        struct Library *, (__IconBase), 27, Icon    );
}

#define DrawIconStateA(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Icon_DrawIconStateA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define DrawIconState(arg1, arg2, arg3, arg4, arg5, arg6, ...) \
({ \
    const IPTR DrawIconStateA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DrawIconStateA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (struct TagItem *)(DrawIconStateA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_GetIconRectangleA(struct RastPort * __arg1, struct DiskObject * __arg2, STRPTR __arg3, struct Rectangle * __arg4, struct TagItem * __arg5, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC5(BOOL, GetIconRectangleA,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct DiskObject *,(__arg2),A1),
        AROS_LCA(STRPTR,(__arg3),A2),
        AROS_LCA(struct Rectangle *,(__arg4),A3),
        AROS_LCA(struct TagItem *,(__arg5),A4),
        struct Library *, (__IconBase), 28, Icon    );
}

#define GetIconRectangleA(arg1, arg2, arg3, arg4, arg5) \
    __inline_Icon_GetIconRectangleA((arg1), (arg2), (arg3), (arg4), (arg5), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define GetIconRectangle(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR GetIconRectangleA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetIconRectangleA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(GetIconRectangleA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_NewDiskObject(ULONG __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC1(struct DiskObject *, NewDiskObject,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__IconBase), 29, Icon    );
}

#define NewDiskObject(arg1) \
    __inline_Icon_NewDiskObject((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline struct DiskObject * __inline_Icon_GetIconTagList(CONST_STRPTR __arg1, const struct TagItem * __arg2, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC2(struct DiskObject *, GetIconTagList,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(const struct TagItem *,(__arg2),A1),
        struct Library *, (__IconBase), 30, Icon    );
}

#define GetIconTagList(arg1, arg2) \
    __inline_Icon_GetIconTagList((arg1), (arg2), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define GetIconTags(arg1, ...) \
({ \
    const IPTR GetIconTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetIconTagList((arg1), (const struct TagItem *)(GetIconTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_PutIconTagList(CONST_STRPTR __arg1, struct DiskObject * __arg2, struct TagItem * __arg3, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC3(BOOL, PutIconTagList,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(struct DiskObject *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct Library *, (__IconBase), 31, Icon    );
}

#define PutIconTagList(arg1, arg2, arg3) \
    __inline_Icon_PutIconTagList((arg1), (arg2), (arg3), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define PutIconTags(arg1, arg2, ...) \
({ \
    const IPTR PutIconTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PutIconTagList((arg1), (arg2), (struct TagItem *)(PutIconTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline BOOL __inline_Icon_LayoutIconA(struct DiskObject * __arg1, struct Screen * __arg2, struct TagItem * __arg3, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    return AROS_LC3(BOOL, LayoutIconA,
        AROS_LCA(struct DiskObject *,(__arg1),A0),
        AROS_LCA(struct Screen *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct Library *, (__IconBase), 32, Icon    );
}

#define LayoutIconA(arg1, arg2, arg3) \
    __inline_Icon_LayoutIconA((arg1), (arg2), (arg3), __ICON_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(ICON_NO_INLINE_STDARG)
#define LayoutIcon(arg1, arg2, ...) \
({ \
    const IPTR LayoutIconA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    LayoutIconA((arg1), (arg2), (struct TagItem *)(LayoutIconA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#if !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__)

static inline void __inline_Icon_ChangeToSelectedIconColor(struct ColorRegister * __arg1, APTR __IconBase)
{
    AROS_LIBREQ(IconBase, 44)
    AROS_LC1NR(void, ChangeToSelectedIconColor,
        AROS_LCA(struct ColorRegister *,(__arg1),A0),
        struct Library *, (__IconBase), 33, Icon    );
}

#define ChangeToSelectedIconColor(arg1) \
    __inline_Icon_ChangeToSelectedIconColor((arg1), __ICON_LIBBASE)

#endif /* !defined(__ICON_LIBAPI__) || (44 <= __ICON_LIBAPI__) */

#endif /* INLINE_ICON_H*/
