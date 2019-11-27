#ifndef INLINE_POPUPMENU_H
#define INLINE_POPUPMENU_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/popupmenu/popupmenu.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for popupmenu
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__POPUPMENU_LIBBASE)
#    define __POPUPMENU_LIBBASE PopupMenuBase
#endif


#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PopupMenu * __inline_Popupmenu_PM_MakeMenuA(struct TagItem * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC1(struct PopupMenu *, PM_MakeMenuA,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 5, Popupmenu    );
}

#define PM_MakeMenuA(arg1) \
    __inline_Popupmenu_PM_MakeMenuA((arg1), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_MakeMenu(...) \
({ \
    const IPTR PM_MakeMenuA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_MakeMenuA((struct TagItem *)(PM_MakeMenuA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PopupMenu * __inline_Popupmenu_PM_MakeItemA(struct TagItem * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC1(struct PopupMenu *, PM_MakeItemA,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 6, Popupmenu    );
}

#define PM_MakeItemA(arg1) \
    __inline_Popupmenu_PM_MakeItemA((arg1), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_MakeItem(...) \
({ \
    const IPTR PM_MakeItemA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_MakeItemA((struct TagItem *)(PM_MakeItemA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline void __inline_Popupmenu_PM_FreePopupMenu(struct PopupMenu * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    AROS_LC1NR(void, PM_FreePopupMenu,
        AROS_LCA(struct PopupMenu *,(__arg1),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 7, Popupmenu    );
}

#define PM_FreePopupMenu(arg1) \
    __inline_Popupmenu_PM_FreePopupMenu((arg1), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline IPTR __inline_Popupmenu_PM_OpenPopupMenuA(struct Window * __arg1, struct TagItem * __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(IPTR, PM_OpenPopupMenuA,
        AROS_LCA(struct Window *,(__arg1),A1),
        AROS_LCA(struct TagItem *,(__arg2),A2),
        struct PopupMenuBase *, (__PopupMenuBase), 8, Popupmenu    );
}

#define PM_OpenPopupMenuA(arg1, arg2) \
    __inline_Popupmenu_PM_OpenPopupMenuA((arg1), (arg2), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_OpenPopupMenu(arg1, ...) \
({ \
    const IPTR PM_OpenPopupMenuA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_OpenPopupMenuA((arg1), (struct TagItem *)(PM_OpenPopupMenuA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PM_IDLst * __inline_Popupmenu_PM_MakeIDListA(struct TagItem * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC1(struct PM_IDLst *, PM_MakeIDListA,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 9, Popupmenu    );
}

#define PM_MakeIDListA(arg1) \
    __inline_Popupmenu_PM_MakeIDListA((arg1), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_MakeIDList(...) \
({ \
    const IPTR PM_MakeIDListA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_MakeIDListA((struct TagItem *)(PM_MakeIDListA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline BOOL __inline_Popupmenu_PM_ItemChecked(struct PopupMenu * __arg1, ULONG __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(BOOL, PM_ItemChecked,
        AROS_LCA(struct PopupMenu *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D1),
        struct PopupMenuBase *, (__PopupMenuBase), 10, Popupmenu    );
}

#define PM_ItemChecked(arg1, arg2) \
    __inline_Popupmenu_PM_ItemChecked((arg1), (arg2), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline LONG __inline_Popupmenu_PM_GetItemAttrsA(struct PopupMenu * __arg1, struct TagItem * __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(LONG, PM_GetItemAttrsA,
        AROS_LCA(struct PopupMenu *,(__arg1),A2),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 11, Popupmenu    );
}

#define PM_GetItemAttrsA(arg1, arg2) \
    __inline_Popupmenu_PM_GetItemAttrsA((arg1), (arg2), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_GetItemAttrs(arg1, ...) \
({ \
    const IPTR PM_GetItemAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_GetItemAttrsA((arg1), (struct TagItem *)(PM_GetItemAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline LONG __inline_Popupmenu_PM_SetItemAttrsA(struct PopupMenu * __arg1, struct TagItem * __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(LONG, PM_SetItemAttrsA,
        AROS_LCA(struct PopupMenu *,(__arg1),A2),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 12, Popupmenu    );
}

#define PM_SetItemAttrsA(arg1, arg2) \
    __inline_Popupmenu_PM_SetItemAttrsA((arg1), (arg2), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_SetItemAttrs(arg1, ...) \
({ \
    const IPTR PM_SetItemAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_SetItemAttrsA((arg1), (struct TagItem *)(PM_SetItemAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PopupMenu * __inline_Popupmenu_PM_FindItem(struct PopupMenu * __arg1, ULONG __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(struct PopupMenu *, PM_FindItem,
        AROS_LCA(struct PopupMenu *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D1),
        struct PopupMenuBase *, (__PopupMenuBase), 13, Popupmenu    );
}

#define PM_FindItem(arg1, arg2) \
    __inline_Popupmenu_PM_FindItem((arg1), (arg2), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline void __inline_Popupmenu_PM_AlterState(struct PopupMenu * __arg1, struct PM_IDLst * __arg2, UWORD __arg3, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    AROS_LC3NR(void, PM_AlterState,
        AROS_LCA(struct PopupMenu *,(__arg1),A1),
        AROS_LCA(struct PM_IDLst *,(__arg2),A2),
        AROS_LCA(UWORD,(__arg3),D1),
        struct PopupMenuBase *, (__PopupMenuBase), 14, Popupmenu    );
}

#define PM_AlterState(arg1, arg2, arg3) \
    __inline_Popupmenu_PM_AlterState((arg1), (arg2), (arg3), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline APTR __inline_Popupmenu_PM_OBSOLETEFilterIMsgA(struct Window * __arg1, struct PopupMenu * __arg2, struct IntuiMessage * __arg3, struct TagItem * __arg4, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC4(APTR, PM_OBSOLETEFilterIMsgA,
        AROS_LCA(struct Window *,(__arg1),A1),
        AROS_LCA(struct PopupMenu *,(__arg2),A2),
        AROS_LCA(struct IntuiMessage *,(__arg3),A3),
        AROS_LCA(struct TagItem *,(__arg4),A5),
        struct PopupMenuBase *, (__PopupMenuBase), 15, Popupmenu    );
}

#define PM_OBSOLETEFilterIMsgA(arg1, arg2, arg3, arg4) \
    __inline_Popupmenu_PM_OBSOLETEFilterIMsgA((arg1), (arg2), (arg3), (arg4), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_OBSOLETEFilterIMsg(arg1, arg2, arg3, ...) \
({ \
    const IPTR PM_OBSOLETEFilterIMsgA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_OBSOLETEFilterIMsgA((arg1), (arg2), (arg3), (struct TagItem *)(PM_OBSOLETEFilterIMsgA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PM_IDLst * __inline_Popupmenu_PM_ExLstA(ULONG * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC1(struct PM_IDLst *, PM_ExLstA,
        AROS_LCA(ULONG *,(__arg1),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 16, Popupmenu    );
}

#define PM_ExLstA(arg1) \
    __inline_Popupmenu_PM_ExLstA((arg1), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_ExLst(...) \
({ \
    const IPTR PM_ExLstA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_ExLstA((ULONG *)(PM_ExLstA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline APTR __inline_Popupmenu_PM_FilterIMsgA(struct Window * __arg1, struct PopupMenu * __arg2, struct IntuiMessage * __arg3, struct TagItem * __arg4, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC4(APTR, PM_FilterIMsgA,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct PopupMenu *,(__arg2),A1),
        AROS_LCA(struct IntuiMessage *,(__arg3),A2),
        AROS_LCA(struct TagItem *,(__arg4),A3),
        struct PopupMenuBase *, (__PopupMenuBase), 17, Popupmenu    );
}

#define PM_FilterIMsgA(arg1, arg2, arg3, arg4) \
    __inline_Popupmenu_PM_FilterIMsgA((arg1), (arg2), (arg3), (arg4), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_FilterIMsg(arg1, arg2, arg3, ...) \
({ \
    const IPTR PM_FilterIMsgA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_FilterIMsgA((arg1), (arg2), (arg3), (struct TagItem *)(PM_FilterIMsgA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline LONG __inline_Popupmenu_PM_InsertMenuItemA(struct PopupMenu * __arg1, struct TagItem * __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(LONG, PM_InsertMenuItemA,
        AROS_LCA(struct PopupMenu *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 18, Popupmenu    );
}

#define PM_InsertMenuItemA(arg1, arg2) \
    __inline_Popupmenu_PM_InsertMenuItemA((arg1), (arg2), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_InsertMenuItem(arg1, ...) \
({ \
    const IPTR PM_InsertMenuItemA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_InsertMenuItemA((arg1), (struct TagItem *)(PM_InsertMenuItemA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline struct PopupMenu * __inline_Popupmenu_PM_RemoveMenuItem(struct PopupMenu * __arg1, struct PopupMenu * __arg2, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC2(struct PopupMenu *, PM_RemoveMenuItem,
        AROS_LCA(struct PopupMenu *,(__arg1),A0),
        AROS_LCA(struct PopupMenu *,(__arg2),A1),
        struct PopupMenuBase *, (__PopupMenuBase), 19, Popupmenu    );
}

#define PM_RemoveMenuItem(arg1, arg2) \
    __inline_Popupmenu_PM_RemoveMenuItem((arg1), (arg2), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline BOOL __inline_Popupmenu_PM_AbortHook(APTR __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC1(BOOL, PM_AbortHook,
        AROS_LCA(APTR,(__arg1),A0),
        struct PopupMenuBase *, (__PopupMenuBase), 20, Popupmenu    );
}

#define PM_AbortHook(arg1) \
    __inline_Popupmenu_PM_AbortHook((arg1), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline STRPTR __inline_Popupmenu_PM_GetVersion(APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC0(STRPTR, PM_GetVersion,
        struct PopupMenuBase *, (__PopupMenuBase), 21, Popupmenu    );
}

#define PM_GetVersion() \
    __inline_Popupmenu_PM_GetVersion(__POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline void __inline_Popupmenu_PM_ReloadPrefs(APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    AROS_LC0NR(void, PM_ReloadPrefs,
        struct PopupMenuBase *, (__PopupMenuBase), 22, Popupmenu    );
}

#define PM_ReloadPrefs() \
    __inline_Popupmenu_PM_ReloadPrefs(__POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline LONG __inline_Popupmenu_PM_LayoutMenuA(struct Window * __arg1, struct PopupMenu * __arg2, struct TagItem * __arg3, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    return AROS_LC3(LONG, PM_LayoutMenuA,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct PopupMenu *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct PopupMenuBase *, (__PopupMenuBase), 23, Popupmenu    );
}

#define PM_LayoutMenuA(arg1, arg2, arg3) \
    __inline_Popupmenu_PM_LayoutMenuA((arg1), (arg2), (arg3), __POPUPMENU_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(POPUPMENU_NO_INLINE_STDARG)
#define PM_LayoutMenu(arg1, arg2, ...) \
({ \
    const IPTR PM_LayoutMenuA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PM_LayoutMenuA((arg1), (arg2), (struct TagItem *)(PM_LayoutMenuA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#if !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__)

static inline void __inline_Popupmenu_PM_FreeIDList(struct PM_IDLst * __arg1, APTR __PopupMenuBase)
{
    AROS_LIBREQ(PopupMenuBase, 10)
    AROS_LC1NR(void, PM_FreeIDList,
        AROS_LCA(struct PM_IDLst *,(__arg1),A0),
        struct PopupMenuBase *, (__PopupMenuBase), 25, Popupmenu    );
}

#define PM_FreeIDList(arg1) \
    __inline_Popupmenu_PM_FreeIDList((arg1), __POPUPMENU_LIBBASE)

#endif /* !defined(__POPUPMENU_LIBAPI__) || (10 <= __POPUPMENU_LIBAPI__) */

#endif /* INLINE_POPUPMENU_H*/
