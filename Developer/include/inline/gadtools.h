#ifndef INLINE_GADTOOLS_H
#define INLINE_GADTOOLS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/gadtools/gadtools.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for gadtools
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__GADTOOLS_LIBBASE)
#    define __GADTOOLS_LIBBASE GadToolsBase
#endif


#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct Gadget * __inline_GadTools_CreateGadgetA(ULONG __arg1, struct Gadget * __arg2, struct NewGadget * __arg3, struct TagItem * __arg4, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC4(struct Gadget *, CreateGadgetA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct Gadget *,(__arg2),A0),
        AROS_LCA(struct NewGadget *,(__arg3),A1),
        AROS_LCA(struct TagItem *,(__arg4),A2),
        struct Library *, (__GadToolsBase), 5, GadTools    );
}

#define CreateGadgetA(arg1, arg2, arg3, arg4) \
    __inline_GadTools_CreateGadgetA((arg1), (arg2), (arg3), (arg4), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define CreateGadget(arg1, arg2, arg3, ...) \
({ \
    const IPTR CreateGadgetA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateGadgetA((arg1), (arg2), (arg3), (struct TagItem *)(CreateGadgetA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_FreeGadgets(struct Gadget * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC1NR(void, FreeGadgets,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        struct Library *, (__GadToolsBase), 6, GadTools    );
}

#define FreeGadgets(arg1) \
    __inline_GadTools_FreeGadgets((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_GT_SetGadgetAttrsA(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, struct TagItem * __arg4, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC4NR(void, GT_SetGadgetAttrsA,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(struct TagItem *,(__arg4),A3),
        struct Library *, (__GadToolsBase), 7, GadTools    );
}

#define GT_SetGadgetAttrsA(arg1, arg2, arg3, arg4) \
    __inline_GadTools_GT_SetGadgetAttrsA((arg1), (arg2), (arg3), (arg4), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define GT_SetGadgetAttrs(arg1, arg2, arg3, ...) \
({ \
    const IPTR GT_SetGadgetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GT_SetGadgetAttrsA((arg1), (arg2), (arg3), (struct TagItem *)(GT_SetGadgetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct Menu * __inline_GadTools_CreateMenusA(struct NewMenu * __arg1, struct TagItem * __arg2, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC2(struct Menu *, CreateMenusA,
        AROS_LCA(struct NewMenu *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__GadToolsBase), 8, GadTools    );
}

#define CreateMenusA(arg1, arg2) \
    __inline_GadTools_CreateMenusA((arg1), (arg2), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define CreateMenus(arg1, ...) \
({ \
    const IPTR CreateMenusA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateMenusA((arg1), (struct TagItem *)(CreateMenusA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_FreeMenus(struct Menu * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC1NR(void, FreeMenus,
        AROS_LCA(struct Menu *,(__arg1),A0),
        struct Library *, (__GadToolsBase), 9, GadTools    );
}

#define FreeMenus(arg1) \
    __inline_GadTools_FreeMenus((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline BOOL __inline_GadTools_LayoutMenuItemsA(struct MenuItem * __arg1, APTR __arg2, struct TagItem * __arg3, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC3(BOOL, LayoutMenuItemsA,
        AROS_LCA(struct MenuItem *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct Library *, (__GadToolsBase), 10, GadTools    );
}

#define LayoutMenuItemsA(arg1, arg2, arg3) \
    __inline_GadTools_LayoutMenuItemsA((arg1), (arg2), (arg3), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define LayoutMenuItems(arg1, arg2, ...) \
({ \
    const IPTR LayoutMenuItemsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    LayoutMenuItemsA((arg1), (arg2), (struct TagItem *)(LayoutMenuItemsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline BOOL __inline_GadTools_LayoutMenusA(struct Menu * __arg1, APTR __arg2, struct TagItem * __arg3, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC3(BOOL, LayoutMenusA,
        AROS_LCA(struct Menu *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct Library *, (__GadToolsBase), 11, GadTools    );
}

#define LayoutMenusA(arg1, arg2, arg3) \
    __inline_GadTools_LayoutMenusA((arg1), (arg2), (arg3), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define LayoutMenus(arg1, arg2, ...) \
({ \
    const IPTR LayoutMenusA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    LayoutMenusA((arg1), (arg2), (struct TagItem *)(LayoutMenusA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct IntuiMessage * __inline_GadTools_GT_GetIMsg(struct MsgPort * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC1(struct IntuiMessage *, GT_GetIMsg,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        struct Library *, (__GadToolsBase), 12, GadTools    );
}

#define GT_GetIMsg(arg1) \
    __inline_GadTools_GT_GetIMsg((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_GT_ReplyIMsg(struct IntuiMessage * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC1NR(void, GT_ReplyIMsg,
        AROS_LCA(struct IntuiMessage *,(__arg1),A1),
        struct Library *, (__GadToolsBase), 13, GadTools    );
}

#define GT_ReplyIMsg(arg1) \
    __inline_GadTools_GT_ReplyIMsg((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_GT_RefreshWindow(struct Window * __arg1, struct Requester * __arg2, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC2NR(void, GT_RefreshWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Requester *,(__arg2),A1),
        struct Library *, (__GadToolsBase), 14, GadTools    );
}

#define GT_RefreshWindow(arg1, arg2) \
    __inline_GadTools_GT_RefreshWindow((arg1), (arg2), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_GT_BeginRefresh(struct Window * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC1NR(void, GT_BeginRefresh,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct Library *, (__GadToolsBase), 15, GadTools    );
}

#define GT_BeginRefresh(arg1) \
    __inline_GadTools_GT_BeginRefresh((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_GT_EndRefresh(struct Window * __arg1, BOOL __arg2, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC2NR(void, GT_EndRefresh,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct Library *, (__GadToolsBase), 16, GadTools    );
}

#define GT_EndRefresh(arg1, arg2) \
    __inline_GadTools_GT_EndRefresh((arg1), (arg2), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct IntuiMessage * __inline_GadTools_GT_FilterIMsg(struct IntuiMessage * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC1(struct IntuiMessage *, GT_FilterIMsg,
        AROS_LCA(struct IntuiMessage *,(__arg1),A1),
        struct Library *, (__GadToolsBase), 17, GadTools    );
}

#define GT_FilterIMsg(arg1) \
    __inline_GadTools_GT_FilterIMsg((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct IntuiMessage * __inline_GadTools_GT_PostFilterIMsg(struct IntuiMessage * __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC1(struct IntuiMessage *, GT_PostFilterIMsg,
        AROS_LCA(struct IntuiMessage *,(__arg1),A1),
        struct Library *, (__GadToolsBase), 18, GadTools    );
}

#define GT_PostFilterIMsg(arg1) \
    __inline_GadTools_GT_PostFilterIMsg((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline struct Gadget * __inline_GadTools_CreateContext(struct Gadget ** __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC1(struct Gadget *, CreateContext,
        AROS_LCA(struct Gadget **,(__arg1),A0),
        struct Library *, (__GadToolsBase), 19, GadTools    );
}

#define CreateContext(arg1) \
    __inline_GadTools_CreateContext((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_DrawBevelBoxA(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, struct TagItem * __arg6, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC6NR(void, DrawBevelBoxA,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(struct TagItem *,(__arg6),A1),
        struct Library *, (__GadToolsBase), 20, GadTools    );
}

#define DrawBevelBoxA(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_GadTools_DrawBevelBoxA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define DrawBevelBox(arg1, arg2, arg3, arg4, arg5, ...) \
({ \
    const IPTR DrawBevelBoxA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DrawBevelBoxA((arg1), (arg2), (arg3), (arg4), (arg5), (struct TagItem *)(DrawBevelBoxA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline APTR __inline_GadTools_GetVisualInfoA(struct Screen * __arg1, struct TagItem * __arg2, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    return AROS_LC2(APTR, GetVisualInfoA,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__GadToolsBase), 21, GadTools    );
}

#define GetVisualInfoA(arg1, arg2) \
    __inline_GadTools_GetVisualInfoA((arg1), (arg2), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define GetVisualInfo(arg1, ...) \
({ \
    const IPTR GetVisualInfoA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetVisualInfoA((arg1), (struct TagItem *)(GetVisualInfoA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__)

static inline void __inline_GadTools_FreeVisualInfo(APTR __arg1, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 36)
    AROS_LC1NR(void, FreeVisualInfo,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__GadToolsBase), 22, GadTools    );
}

#define FreeVisualInfo(arg1) \
    __inline_GadTools_FreeVisualInfo((arg1), __GADTOOLS_LIBBASE)

#endif /* !defined(__GADTOOLS_LIBAPI__) || (36 <= __GADTOOLS_LIBAPI__) */

#if !defined(__GADTOOLS_LIBAPI__) || (39 <= __GADTOOLS_LIBAPI__)

static inline LONG __inline_GadTools_GT_GetGadgetAttrsA(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, struct TagItem * __arg4, APTR __GadToolsBase)
{
    AROS_LIBREQ(GadToolsBase, 39)
    return AROS_LC4(LONG, GT_GetGadgetAttrsA,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(struct TagItem *,(__arg4),A3),
        struct Library *, (__GadToolsBase), 29, GadTools    );
}

#define GT_GetGadgetAttrsA(arg1, arg2, arg3, arg4) \
    __inline_GadTools_GT_GetGadgetAttrsA((arg1), (arg2), (arg3), (arg4), __GADTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GADTOOLS_NO_INLINE_STDARG)
#define GT_GetGadgetAttrs(arg1, arg2, arg3, ...) \
({ \
    const IPTR GT_GetGadgetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GT_GetGadgetAttrsA((arg1), (arg2), (arg3), (struct TagItem *)(GT_GetGadgetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GADTOOLS_LIBAPI__) || (39 <= __GADTOOLS_LIBAPI__) */

#endif /* INLINE_GADTOOLS_H*/
