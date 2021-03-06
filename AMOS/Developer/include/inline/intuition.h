#ifndef INLINE_INTUITION_H
#define INLINE_INTUITION_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/intuition/intuition.conf'. Edits will be lost. ***
    Copyright � 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for intuition
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__INTUITION_LIBBASE)
#    define __INTUITION_LIBBASE IntuitionBase
#endif


#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_AddGadget(struct Window * __arg1, struct Gadget * __arg2, ULONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC3(UWORD, AddGadget,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Gadget *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct IntuitionBase *, (__IntuitionBase), 7, Intuition    );
}

#define AddGadget(arg1, arg2, arg3) \
    __inline_Intuition_AddGadget((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_ClearDMRequest(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(BOOL, ClearDMRequest,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 8, Intuition    );
}

#define ClearDMRequest(arg1) \
    __inline_Intuition_ClearDMRequest((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ClearMenuStrip(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, ClearMenuStrip,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 9, Intuition    );
}

#define ClearMenuStrip(arg1) \
    __inline_Intuition_ClearMenuStrip((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ClearPointer(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, ClearPointer,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 10, Intuition    );
}

#define ClearPointer(arg1) \
    __inline_Intuition_ClearPointer((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_CloseScreen(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(BOOL, CloseScreen,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 11, Intuition    );
}

#define CloseScreen(arg1) \
    __inline_Intuition_CloseScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_CloseWindow(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, CloseWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 12, Intuition    );
}

#define CloseWindow(arg1) \
    __inline_Intuition_CloseWindow((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_CloseWorkBench(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(LONG, CloseWorkBench,
        struct IntuitionBase *, (__IntuitionBase), 13, Intuition    );
}

#define CloseWorkBench() \
    __inline_Intuition_CloseWorkBench(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_CurrentTime(ULONG * __arg1, ULONG * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, CurrentTime,
        AROS_LCA(ULONG *,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 14, Intuition    );
}

#define CurrentTime(arg1, arg2) \
    __inline_Intuition_CurrentTime((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_DisplayAlert(ULONG __arg1, UBYTE * __arg2, UWORD __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC3(BOOL, DisplayAlert,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(UBYTE *,(__arg2),A0),
        AROS_LCA(UWORD,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 15, Intuition    );
}

#define DisplayAlert(arg1, arg2, arg3) \
    __inline_Intuition_DisplayAlert((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_DisplayBeep(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, DisplayBeep,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 16, Intuition    );
}

#define DisplayBeep(arg1) \
    __inline_Intuition_DisplayBeep((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_DoubleClick(ULONG __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC4(BOOL, DoubleClick,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(ULONG,(__arg3),D2),
        AROS_LCA(ULONG,(__arg4),D3),
        struct IntuitionBase *, (__IntuitionBase), 17, Intuition    );
}

#define DoubleClick(arg1, arg2, arg3, arg4) \
    __inline_Intuition_DoubleClick((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_DrawBorder(struct RastPort * __arg1, struct Border * __arg2, LONG __arg3, LONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC4NR(void, DrawBorder,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct Border *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct IntuitionBase *, (__IntuitionBase), 18, Intuition    );
}

#define DrawBorder(arg1, arg2, arg3, arg4) \
    __inline_Intuition_DrawBorder((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_DrawImage(struct RastPort * __arg1, struct Image * __arg2, LONG __arg3, LONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC4NR(void, DrawImage,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct Image *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct IntuitionBase *, (__IntuitionBase), 19, Intuition    );
}

#define DrawImage(arg1, arg2, arg3, arg4) \
    __inline_Intuition_DrawImage((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_EndRequest(struct Requester * __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, EndRequest,
        AROS_LCA(struct Requester *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 20, Intuition    );
}

#define EndRequest(arg1, arg2) \
    __inline_Intuition_EndRequest((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Preferences * __inline_Intuition_GetDefPrefs(struct Preferences * __arg1, WORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(struct Preferences *, GetDefPrefs,
        AROS_LCA(struct Preferences *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 21, Intuition    );
}

#define GetDefPrefs(arg1, arg2) \
    __inline_Intuition_GetDefPrefs((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Preferences * __inline_Intuition_GetPrefs(struct Preferences * __arg1, WORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(struct Preferences *, GetPrefs,
        AROS_LCA(struct Preferences *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 22, Intuition    );
}

#define GetPrefs(arg1, arg2) \
    __inline_Intuition_GetPrefs((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_InitRequester(struct Requester * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, InitRequester,
        AROS_LCA(struct Requester *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 23, Intuition    );
}

#define InitRequester(arg1) \
    __inline_Intuition_InitRequester((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct MenuItem * __inline_Intuition_ItemAddress(struct Menu * __arg1, UWORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(struct MenuItem *, ItemAddress,
        AROS_LCA(struct Menu *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 24, Intuition    );
}

#define ItemAddress(arg1, arg2) \
    __inline_Intuition_ItemAddress((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_ModifyIDCMP(struct Window * __arg1, ULONG __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(BOOL, ModifyIDCMP,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 25, Intuition    );
}

#define ModifyIDCMP(arg1, arg2) \
    __inline_Intuition_ModifyIDCMP((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ModifyProp(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, ULONG __arg7, ULONG __arg8, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC8NR(void, ModifyProp,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(ULONG,(__arg5),D1),
        AROS_LCA(ULONG,(__arg6),D2),
        AROS_LCA(ULONG,(__arg7),D3),
        AROS_LCA(ULONG,(__arg8),D4),
        struct IntuitionBase *, (__IntuitionBase), 26, Intuition    );
}

#define ModifyProp(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Intuition_ModifyProp((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_MoveScreen(struct Screen * __arg1, LONG __arg2, LONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, MoveScreen,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 27, Intuition    );
}

#define MoveScreen(arg1, arg2, arg3) \
    __inline_Intuition_MoveScreen((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_MoveWindow(struct Window * __arg1, LONG __arg2, LONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, MoveWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 28, Intuition    );
}

#define MoveWindow(arg1, arg2, arg3) \
    __inline_Intuition_MoveWindow((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_OffGadget(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, OffGadget,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 29, Intuition    );
}

#define OffGadget(arg1, arg2, arg3) \
    __inline_Intuition_OffGadget((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_OffMenu(struct Window * __arg1, UWORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, OffMenu,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 30, Intuition    );
}

#define OffMenu(arg1, arg2) \
    __inline_Intuition_OffMenu((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_OnGadget(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, OnGadget,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 31, Intuition    );
}

#define OnGadget(arg1, arg2, arg3) \
    __inline_Intuition_OnGadget((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_OnMenu(struct Window * __arg1, UWORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, OnMenu,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 32, Intuition    );
}

#define OnMenu(arg1, arg2) \
    __inline_Intuition_OnMenu((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Screen * __inline_Intuition_OpenScreen(struct NewScreen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(struct Screen *, OpenScreen,
        AROS_LCA(struct NewScreen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 33, Intuition    );
}

#define OpenScreen(arg1) \
    __inline_Intuition_OpenScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Window * __inline_Intuition_OpenWindow(struct NewWindow * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(struct Window *, OpenWindow,
        AROS_LCA(struct NewWindow *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 34, Intuition    );
}

#define OpenWindow(arg1) \
    __inline_Intuition_OpenWindow((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_OpenWorkBench(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(IPTR, OpenWorkBench,
        struct IntuitionBase *, (__IntuitionBase), 35, Intuition    );
}

#define OpenWorkBench() \
    __inline_Intuition_OpenWorkBench(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_PrintIText(struct RastPort * __arg1, struct IntuiText * __arg2, LONG __arg3, LONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC4NR(void, PrintIText,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct IntuiText *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct IntuitionBase *, (__IntuitionBase), 36, Intuition    );
}

#define PrintIText(arg1, arg2, arg3, arg4) \
    __inline_Intuition_PrintIText((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_RefreshGadgets(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, RefreshGadgets,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 37, Intuition    );
}

#define RefreshGadgets(arg1, arg2, arg3) \
    __inline_Intuition_RefreshGadgets((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_RemoveGadget(struct Window * __arg1, struct Gadget * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(UWORD, RemoveGadget,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Gadget *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 38, Intuition    );
}

#define RemoveGadget(arg1, arg2) \
    __inline_Intuition_RemoveGadget((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ReportMouse(LONG __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, ReportMouse,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(struct Window *,(__arg2),A0),
        struct IntuitionBase *, (__IntuitionBase), 39, Intuition    );
}

#define ReportMouse(arg1, arg2) \
    __inline_Intuition_ReportMouse((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_Request(struct Requester * __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(BOOL, Request,
        AROS_LCA(struct Requester *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 40, Intuition    );
}

#define Request(arg1, arg2) \
    __inline_Intuition_Request((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScreenToBack(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, ScreenToBack,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 41, Intuition    );
}

#define ScreenToBack(arg1) \
    __inline_Intuition_ScreenToBack((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScreenToFront(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, ScreenToFront,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 42, Intuition    );
}

#define ScreenToFront(arg1) \
    __inline_Intuition_ScreenToFront((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_SetDMRequest(struct Window * __arg1, struct Requester * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(BOOL, SetDMRequest,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Requester *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 43, Intuition    );
}

#define SetDMRequest(arg1, arg2) \
    __inline_Intuition_SetDMRequest((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_SetMenuStrip(struct Window * __arg1, struct Menu * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC2(BOOL, SetMenuStrip,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Menu *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 44, Intuition    );
}

#define SetMenuStrip(arg1, arg2) \
    __inline_Intuition_SetMenuStrip((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SetPointer(struct Window * __arg1, const UWORD * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC6NR(void, SetPointer,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(const UWORD *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        struct IntuitionBase *, (__IntuitionBase), 45, Intuition    );
}

#define SetPointer(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Intuition_SetPointer((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SetWindowTitles(struct Window * __arg1, CONST_STRPTR __arg2, CONST_STRPTR __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, SetWindowTitles,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(CONST_STRPTR,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 46, Intuition    );
}

#define SetWindowTitles(arg1, arg2, arg3) \
    __inline_Intuition_SetWindowTitles((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ShowTitle(struct Screen * __arg1, BOOL __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, ShowTitle,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 47, Intuition    );
}

#define ShowTitle(arg1, arg2) \
    __inline_Intuition_ShowTitle((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SizeWindow(struct Window * __arg1, LONG __arg2, LONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC3NR(void, SizeWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 48, Intuition    );
}

#define SizeWindow(arg1, arg2, arg3) \
    __inline_Intuition_SizeWindow((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct View * __inline_Intuition_ViewAddress(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(struct View *, ViewAddress,
        struct IntuitionBase *, (__IntuitionBase), 49, Intuition    );
}

#define ViewAddress() \
    __inline_Intuition_ViewAddress(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct ViewPort * __inline_Intuition_ViewPortAddress(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(struct ViewPort *, ViewPortAddress,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 50, Intuition    );
}

#define ViewPortAddress(arg1) \
    __inline_Intuition_ViewPortAddress((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_WindowToBack(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, WindowToBack,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 51, Intuition    );
}

#define WindowToBack(arg1) \
    __inline_Intuition_WindowToBack((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_WindowToFront(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, WindowToFront,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 52, Intuition    );
}

#define WindowToFront(arg1) \
    __inline_Intuition_WindowToFront((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_WindowLimits(struct Window * __arg1, WORD __arg2, WORD __arg3, UWORD __arg4, UWORD __arg5, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC5(BOOL, WindowLimits,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        struct IntuitionBase *, (__IntuitionBase), 53, Intuition    );
}

#define WindowLimits(arg1, arg2, arg3, arg4, arg5) \
    __inline_Intuition_WindowLimits((arg1), (arg2), (arg3), (arg4), (arg5), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Preferences * __inline_Intuition_SetPrefs(struct Preferences * __arg1, LONG __arg2, BOOL __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC3(struct Preferences *, SetPrefs,
        AROS_LCA(struct Preferences *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(BOOL,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 54, Intuition    );
}

#define SetPrefs(arg1, arg2, arg3) \
    __inline_Intuition_SetPrefs((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_IntuiTextLength(struct IntuiText * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(LONG, IntuiTextLength,
        AROS_LCA(struct IntuiText *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 55, Intuition    );
}

#define IntuiTextLength(arg1) \
    __inline_Intuition_IntuiTextLength((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_WBenchToBack(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(BOOL, WBenchToBack,
        struct IntuitionBase *, (__IntuitionBase), 56, Intuition    );
}

#define WBenchToBack() \
    __inline_Intuition_WBenchToBack(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_WBenchToFront(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(BOOL, WBenchToFront,
        struct IntuitionBase *, (__IntuitionBase), 57, Intuition    );
}

#define WBenchToFront() \
    __inline_Intuition_WBenchToFront(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_AutoRequest(struct Window * __arg1, struct IntuiText * __arg2, struct IntuiText * __arg3, struct IntuiText * __arg4, ULONG __arg5, ULONG __arg6, ULONG __arg7, ULONG __arg8, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC8(BOOL, AutoRequest,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct IntuiText *,(__arg2),A1),
        AROS_LCA(struct IntuiText *,(__arg3),A2),
        AROS_LCA(struct IntuiText *,(__arg4),A3),
        AROS_LCA(ULONG,(__arg5),D0),
        AROS_LCA(ULONG,(__arg6),D1),
        AROS_LCA(ULONG,(__arg7),D2),
        AROS_LCA(ULONG,(__arg8),D3),
        struct IntuitionBase *, (__IntuitionBase), 58, Intuition    );
}

#define AutoRequest(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Intuition_AutoRequest((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_BeginRefresh(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, BeginRefresh,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 59, Intuition    );
}

#define BeginRefresh(arg1) \
    __inline_Intuition_BeginRefresh((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline struct Window * __inline_Intuition_BuildSysRequest(struct Window * __arg1, struct IntuiText * __arg2, struct IntuiText * __arg3, struct IntuiText * __arg4, ULONG __arg5, WORD __arg6, WORD __arg7, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC7(struct Window *, BuildSysRequest,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct IntuiText *,(__arg2),A1),
        AROS_LCA(struct IntuiText *,(__arg3),A2),
        AROS_LCA(struct IntuiText *,(__arg4),A3),
        AROS_LCA(ULONG,(__arg5),D0),
        AROS_LCA(WORD,(__arg6),D2),
        AROS_LCA(WORD,(__arg7),D3),
        struct IntuitionBase *, (__IntuitionBase), 60, Intuition    );
}

#define BuildSysRequest(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Intuition_BuildSysRequest((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_EndRefresh(struct Window * __arg1, BOOL __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, EndRefresh,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 61, Intuition    );
}

#define EndRefresh(arg1, arg2) \
    __inline_Intuition_EndRefresh((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeSysRequest(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, FreeSysRequest,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 62, Intuition    );
}

#define FreeSysRequest(arg1) \
    __inline_Intuition_FreeSysRequest((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_MakeScreen(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(LONG, MakeScreen,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 63, Intuition    );
}

#define MakeScreen(arg1) \
    __inline_Intuition_MakeScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_RemakeDisplay(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(LONG, RemakeDisplay,
        struct IntuitionBase *, (__IntuitionBase), 64, Intuition    );
}

#define RemakeDisplay() \
    __inline_Intuition_RemakeDisplay(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_RethinkDisplay(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC0(LONG, RethinkDisplay,
        struct IntuitionBase *, (__IntuitionBase), 65, Intuition    );
}

#define RethinkDisplay() \
    __inline_Intuition_RethinkDisplay(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline APTR __inline_Intuition_AllocRemember(struct Remember ** __arg1, ULONG __arg2, ULONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC3(APTR, AllocRemember,
        AROS_LCA(struct Remember **,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 66, Intuition    );
}

#define AllocRemember(arg1, arg2, arg3) \
    __inline_Intuition_AllocRemember((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_AlohaWorkbench(struct MsgPort * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, AlohaWorkbench,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 67, Intuition    );
}

#define AlohaWorkbench(arg1) \
    __inline_Intuition_AlohaWorkbench((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeRemember(struct Remember ** __arg1, LONG __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC2NR(void, FreeRemember,
        AROS_LCA(struct Remember **,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 68, Intuition    );
}

#define FreeRemember(arg1, arg2) \
    __inline_Intuition_FreeRemember((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline ULONG __inline_Intuition_LockIBase(ULONG __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    return AROS_LC1(ULONG, LockIBase,
        AROS_LCA(ULONG,(__arg1),D0),
        struct IntuitionBase *, (__IntuitionBase), 69, Intuition    );
}

#define LockIBase(arg1) \
    __inline_Intuition_LockIBase((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_UnlockIBase(ULONG __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 0)
    AROS_LC1NR(void, UnlockIBase,
        AROS_LCA(ULONG,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 70, Intuition    );
}

#define UnlockIBase(arg1) \
    __inline_Intuition_UnlockIBase((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (0 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_GetScreenData(APTR __arg1, ULONG __arg2, ULONG __arg3, struct Screen * __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    return AROS_LC4(LONG, GetScreenData,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(struct Screen *,(__arg4),A1),
        struct IntuitionBase *, (__IntuitionBase), 71, Intuition    );
}

#define GetScreenData(arg1, arg2, arg3, arg4) \
    __inline_Intuition_GetScreenData((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_RefreshGList(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, LONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    AROS_LC4NR(void, RefreshGList,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(LONG,(__arg4),D0),
        struct IntuitionBase *, (__IntuitionBase), 72, Intuition    );
}

#define RefreshGList(arg1, arg2, arg3, arg4) \
    __inline_Intuition_RefreshGList((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_AddGList(struct Window * __arg1, struct Gadget * __arg2, ULONG __arg3, LONG __arg4, struct Requester * __arg5, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    return AROS_LC5(UWORD, AddGList,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Gadget *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(struct Requester *,(__arg5),A2),
        struct IntuitionBase *, (__IntuitionBase), 73, Intuition    );
}

#define AddGList(arg1, arg2, arg3, arg4, arg5) \
    __inline_Intuition_AddGList((arg1), (arg2), (arg3), (arg4), (arg5), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_RemoveGList(struct Window * __arg1, struct Gadget * __arg2, LONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    return AROS_LC3(UWORD, RemoveGList,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Gadget *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct IntuitionBase *, (__IntuitionBase), 74, Intuition    );
}

#define RemoveGList(arg1, arg2, arg3) \
    __inline_Intuition_RemoveGList((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ActivateWindow(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    AROS_LC1NR(void, ActivateWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 75, Intuition    );
}

#define ActivateWindow(arg1) \
    __inline_Intuition_ActivateWindow((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_RefreshWindowFrame(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    AROS_LC1NR(void, RefreshWindowFrame,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 76, Intuition    );
}

#define RefreshWindowFrame(arg1) \
    __inline_Intuition_RefreshWindowFrame((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_ActivateGadget(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    return AROS_LC3(BOOL, ActivateGadget,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 77, Intuition    );
}

#define ActivateGadget(arg1, arg2, arg3) \
    __inline_Intuition_ActivateGadget((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_NewModifyProp(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, ULONG __arg7, ULONG __arg8, LONG __arg9, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 33)
    AROS_LC9NR(void, NewModifyProp,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(ULONG,(__arg5),D1),
        AROS_LCA(ULONG,(__arg6),D2),
        AROS_LCA(ULONG,(__arg7),D3),
        AROS_LCA(ULONG,(__arg8),D4),
        AROS_LCA(LONG,(__arg9),D5),
        struct IntuitionBase *, (__IntuitionBase), 78, Intuition    );
}

#define NewModifyProp(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Intuition_NewModifyProp((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (33 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_QueryOverscan(ULONG __arg1, struct Rectangle * __arg2, WORD __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC3(LONG, QueryOverscan,
        AROS_LCA(ULONG,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        AROS_LCA(WORD,(__arg3),D0),
        struct IntuitionBase *, (__IntuitionBase), 79, Intuition    );
}

#define QueryOverscan(arg1, arg2, arg3) \
    __inline_Intuition_QueryOverscan((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_MoveWindowInFrontOf(struct Window * __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC2NR(void, MoveWindowInFrontOf,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 80, Intuition    );
}

#define MoveWindowInFrontOf(arg1, arg2) \
    __inline_Intuition_MoveWindowInFrontOf((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ChangeWindowBox(struct Window * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, LONG __arg5, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC5NR(void, ChangeWindowBox,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(LONG,(__arg5),D3),
        struct IntuitionBase *, (__IntuitionBase), 81, Intuition    );
}

#define ChangeWindowBox(arg1, arg2, arg3, arg4, arg5) \
    __inline_Intuition_ChangeWindowBox((arg1), (arg2), (arg3), (arg4), (arg5), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Hook * __inline_Intuition_SetEditHook(struct Hook * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct Hook *, SetEditHook,
        AROS_LCA(struct Hook *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 82, Intuition    );
}

#define SetEditHook(arg1) \
    __inline_Intuition_SetEditHook((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_SetMouseQueue(struct Window * __arg1, UWORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(LONG, SetMouseQueue,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 83, Intuition    );
}

#define SetMouseQueue(arg1, arg2) \
    __inline_Intuition_SetMouseQueue((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ZipWindow(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, ZipWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 84, Intuition    );
}

#define ZipWindow(arg1) \
    __inline_Intuition_ZipWindow((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Screen * __inline_Intuition_LockPubScreen(CONST_STRPTR __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct Screen *, LockPubScreen,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 85, Intuition    );
}

#define LockPubScreen(arg1) \
    __inline_Intuition_LockPubScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_UnlockPubScreen(UBYTE * __arg1, struct Screen * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC2NR(void, UnlockPubScreen,
        AROS_LCA(UBYTE *,(__arg1),A0),
        AROS_LCA(struct Screen *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 86, Intuition    );
}

#define UnlockPubScreen(arg1, arg2) \
    __inline_Intuition_UnlockPubScreen((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct List * __inline_Intuition_LockPubScreenList(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC0(struct List *, LockPubScreenList,
        struct IntuitionBase *, (__IntuitionBase), 87, Intuition    );
}

#define LockPubScreenList() \
    __inline_Intuition_LockPubScreenList(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_UnlockPubScreenList(APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC0NR(void, UnlockPubScreenList,
        struct IntuitionBase *, (__IntuitionBase), 88, Intuition    );
}

#define UnlockPubScreenList() \
    __inline_Intuition_UnlockPubScreenList(__INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline UBYTE * __inline_Intuition_NextPubScreen(struct Screen * __arg1, UBYTE * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(UBYTE *, NextPubScreen,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 89, Intuition    );
}

#define NextPubScreen(arg1, arg2) \
    __inline_Intuition_NextPubScreen((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SetDefaultPubScreen(UBYTE * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, SetDefaultPubScreen,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 90, Intuition    );
}

#define SetDefaultPubScreen(arg1) \
    __inline_Intuition_SetDefaultPubScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_SetPubScreenModes(UWORD __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(UWORD, SetPubScreenModes,
        AROS_LCA(UWORD,(__arg1),D0),
        struct IntuitionBase *, (__IntuitionBase), 91, Intuition    );
}

#define SetPubScreenModes(arg1) \
    __inline_Intuition_SetPubScreenModes((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline UWORD __inline_Intuition_PubScreenStatus(struct Screen * __arg1, UWORD __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(UWORD, PubScreenStatus,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 92, Intuition    );
}

#define PubScreenStatus(arg1, arg2) \
    __inline_Intuition_PubScreenStatus((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct RastPort * __inline_Intuition_ObtainGIRPort(struct GadgetInfo * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct RastPort *, ObtainGIRPort,
        AROS_LCA(struct GadgetInfo *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 93, Intuition    );
}

#define ObtainGIRPort(arg1) \
    __inline_Intuition_ObtainGIRPort((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ReleaseGIRPort(struct RastPort * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, ReleaseGIRPort,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 94, Intuition    );
}

#define ReleaseGIRPort(arg1) \
    __inline_Intuition_ReleaseGIRPort((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_GadgetMouse(struct Gadget * __arg1, struct GadgetInfo * __arg2, WORD * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC3NR(void, GadgetMouse,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct GadgetInfo *,(__arg2),A1),
        AROS_LCA(WORD *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 95, Intuition    );
}

#define GadgetMouse(arg1, arg2, arg3) \
    __inline_Intuition_GadgetMouse((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline ULONG __inline_Intuition_SetIPrefs(APTR __arg1, ULONG __arg2, ULONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC3(ULONG, SetIPrefs,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct IntuitionBase *, (__IntuitionBase), 96, Intuition    );
}

#define SetIPrefs(arg1, arg2, arg3) \
    __inline_Intuition_SetIPrefs((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Screen * __inline_Intuition_GetDefaultPubScreen(UBYTE * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct Screen *, GetDefaultPubScreen,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 97, Intuition    );
}

#define GetDefaultPubScreen(arg1) \
    __inline_Intuition_GetDefaultPubScreen((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_EasyRequestArgs(struct Window * __arg1, struct EasyStruct * __arg2, ULONG * __arg3, RAWARG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC4(LONG, EasyRequestArgs,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct EasyStruct *,(__arg2),A1),
        AROS_LCA(ULONG *,(__arg3),A2),
        AROS_LCA(RAWARG,(__arg4),A3),
        struct IntuitionBase *, (__IntuitionBase), 98, Intuition    );
}

#define EasyRequestArgs(arg1, arg2, arg3, arg4) \
    __inline_Intuition_EasyRequestArgs((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Window * __inline_Intuition_BuildEasyRequestArgs(struct Window * __arg1, struct EasyStruct * __arg2, ULONG __arg3, RAWARG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC4(struct Window *, BuildEasyRequestArgs,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct EasyStruct *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(RAWARG,(__arg4),A3),
        struct IntuitionBase *, (__IntuitionBase), 99, Intuition    );
}

#define BuildEasyRequestArgs(arg1, arg2, arg3, arg4) \
    __inline_Intuition_BuildEasyRequestArgs((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_SysReqHandler(struct Window * __arg1, ULONG * __arg2, BOOL __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC3(LONG, SysReqHandler,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D0),
        struct IntuitionBase *, (__IntuitionBase), 100, Intuition    );
}

#define SysReqHandler(arg1, arg2, arg3) \
    __inline_Intuition_SysReqHandler((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Window * __inline_Intuition_OpenWindowTagList(struct NewWindow * __arg1, struct TagItem * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(struct Window *, OpenWindowTagList,
        AROS_LCA(struct NewWindow *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 101, Intuition    );
}

#define OpenWindowTagList(arg1, arg2) \
    __inline_Intuition_OpenWindowTagList((arg1), (arg2), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define OpenWindowTags(arg1, ...) \
({ \
    const IPTR OpenWindowTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    OpenWindowTagList((arg1), (struct TagItem *)(OpenWindowTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct Screen * __inline_Intuition_OpenScreenTagList(struct NewScreen * __arg1, struct TagItem * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(struct Screen *, OpenScreenTagList,
        AROS_LCA(struct NewScreen *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 102, Intuition    );
}

#define OpenScreenTagList(arg1, arg2) \
    __inline_Intuition_OpenScreenTagList((arg1), (arg2), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define OpenScreenTags(arg1, ...) \
({ \
    const IPTR OpenScreenTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    OpenScreenTagList((arg1), (struct TagItem *)(OpenScreenTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_DrawImageState(struct RastPort * __arg1, struct Image * __arg2, LONG __arg3, LONG __arg4, ULONG __arg5, struct DrawInfo * __arg6, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC6NR(void, DrawImageState,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct Image *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(ULONG,(__arg5),D2),
        AROS_LCA(struct DrawInfo *,(__arg6),A2),
        struct IntuitionBase *, (__IntuitionBase), 103, Intuition    );
}

#define DrawImageState(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Intuition_DrawImageState((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_PointInImage(ULONG __arg1, struct Image * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(BOOL, PointInImage,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct Image *,(__arg2),A0),
        struct IntuitionBase *, (__IntuitionBase), 104, Intuition    );
}

#define PointInImage(arg1, arg2) \
    __inline_Intuition_PointInImage((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_EraseImage(struct RastPort * __arg1, struct Image * __arg2, LONG __arg3, LONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC4NR(void, EraseImage,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct Image *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct IntuitionBase *, (__IntuitionBase), 105, Intuition    );
}

#define EraseImage(arg1, arg2, arg3, arg4) \
    __inline_Intuition_EraseImage((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline APTR __inline_Intuition_NewObjectA(struct IClass * __arg1, UBYTE * __arg2, struct TagItem * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC3(APTR, NewObjectA,
        AROS_LCA(struct IClass *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 106, Intuition    );
}

#define NewObjectA(arg1, arg2, arg3) \
    __inline_Intuition_NewObjectA((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define NewObject(arg1, arg2, ...) \
({ \
    const IPTR NewObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewObjectA((arg1), (arg2), (struct TagItem *)(NewObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_DisposeObject(APTR __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, DisposeObject,
        AROS_LCA(APTR,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 107, Intuition    );
}

#define DisposeObject(arg1) \
    __inline_Intuition_DisposeObject((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_SetAttrsA(APTR __arg1, struct TagItem * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(IPTR, SetAttrsA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 108, Intuition    );
}

#define SetAttrsA(arg1, arg2) \
    __inline_Intuition_SetAttrsA((arg1), (arg2), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define SetAttrs(arg1, ...) \
({ \
    const IPTR SetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetAttrsA((arg1), (struct TagItem *)(SetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline ULONG __inline_Intuition_GetAttr(ULONG __arg1, Object * __arg2, IPTR * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC3(ULONG, GetAttr,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(Object *,(__arg2),A0),
        AROS_LCA(IPTR *,(__arg3),A1),
        struct IntuitionBase *, (__IntuitionBase), 109, Intuition    );
}

#define GetAttr(arg1, arg2, arg3) \
    __inline_Intuition_GetAttr((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_SetGadgetAttrsA(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, struct TagItem * __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC4(IPTR, SetGadgetAttrsA,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(struct TagItem *,(__arg4),A3),
        struct IntuitionBase *, (__IntuitionBase), 110, Intuition    );
}

#define SetGadgetAttrsA(arg1, arg2, arg3, arg4) \
    __inline_Intuition_SetGadgetAttrsA((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define SetGadgetAttrs(arg1, arg2, arg3, ...) \
({ \
    const IPTR SetGadgetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetGadgetAttrsA((arg1), (arg2), (arg3), (struct TagItem *)(SetGadgetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline APTR __inline_Intuition_NextObject(APTR __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(APTR, NextObject,
        AROS_LCA(APTR,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 111, Intuition    );
}

#define NextObject(arg1) \
    __inline_Intuition_NextObject((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct IClass * __inline_Intuition_FindClass(ClassID __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct IClass *, FindClass,
        AROS_LCA(ClassID,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 112, Intuition    );
}

#define FindClass(arg1) \
    __inline_Intuition_FindClass((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct IClass * __inline_Intuition_MakeClass(ClassID __arg1, ClassID __arg2, struct IClass * __arg3, ULONG __arg4, ULONG __arg5, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC5(struct IClass *, MakeClass,
        AROS_LCA(ClassID,(__arg1),A0),
        AROS_LCA(ClassID,(__arg2),A1),
        AROS_LCA(struct IClass *,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(ULONG,(__arg5),D1),
        struct IntuitionBase *, (__IntuitionBase), 113, Intuition    );
}

#define MakeClass(arg1, arg2, arg3, arg4, arg5) \
    __inline_Intuition_MakeClass((arg1), (arg2), (arg3), (arg4), (arg5), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_AddClass(struct IClass * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, AddClass,
        AROS_LCA(struct IClass *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 114, Intuition    );
}

#define AddClass(arg1) \
    __inline_Intuition_AddClass((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline struct DrawInfo * __inline_Intuition_GetScreenDrawInfo(struct Screen * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(struct DrawInfo *, GetScreenDrawInfo,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 115, Intuition    );
}

#define GetScreenDrawInfo(arg1) \
    __inline_Intuition_GetScreenDrawInfo((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeScreenDrawInfo(struct Screen * __arg1, struct DrawInfo * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC2NR(void, FreeScreenDrawInfo,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct DrawInfo *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 116, Intuition    );
}

#define FreeScreenDrawInfo(arg1, arg2) \
    __inline_Intuition_FreeScreenDrawInfo((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_ResetMenuStrip(struct Window * __arg1, struct Menu * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC2(BOOL, ResetMenuStrip,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Menu *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 117, Intuition    );
}

#define ResetMenuStrip(arg1, arg2) \
    __inline_Intuition_ResetMenuStrip((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_RemoveClass(struct IClass * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    AROS_LC1NR(void, RemoveClass,
        AROS_LCA(struct IClass *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 118, Intuition    );
}

#define RemoveClass(arg1) \
    __inline_Intuition_RemoveClass((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_FreeClass(struct IClass * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 36)
    return AROS_LC1(BOOL, FreeClass,
        AROS_LCA(struct IClass *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 119, Intuition    );
}

#define FreeClass(arg1) \
    __inline_Intuition_FreeClass((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (36 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline struct ScreenBuffer * __inline_Intuition_AllocScreenBuffer(struct Screen * __arg1, struct BitMap * __arg2, ULONG __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    return AROS_LC3(struct ScreenBuffer *, AllocScreenBuffer,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct IntuitionBase *, (__IntuitionBase), 128, Intuition    );
}

#define AllocScreenBuffer(arg1, arg2, arg3) \
    __inline_Intuition_AllocScreenBuffer((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeScreenBuffer(struct Screen * __arg1, struct ScreenBuffer * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC2NR(void, FreeScreenBuffer,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct ScreenBuffer *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 129, Intuition    );
}

#define FreeScreenBuffer(arg1, arg2) \
    __inline_Intuition_FreeScreenBuffer((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline ULONG __inline_Intuition_ChangeScreenBuffer(struct Screen * __arg1, struct ScreenBuffer * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    return AROS_LC2(ULONG, ChangeScreenBuffer,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct ScreenBuffer *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 130, Intuition    );
}

#define ChangeScreenBuffer(arg1, arg2) \
    __inline_Intuition_ChangeScreenBuffer((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScreenDepth(struct Screen * __arg1, ULONG __arg2, APTR __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC3NR(void, ScreenDepth,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(APTR,(__arg3),A1),
        struct IntuitionBase *, (__IntuitionBase), 131, Intuition    );
}

#define ScreenDepth(arg1, arg2, arg3) \
    __inline_Intuition_ScreenDepth((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScreenPosition(struct Screen * __arg1, ULONG __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC6NR(void, ScreenPosition,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(LONG,(__arg5),D3),
        AROS_LCA(LONG,(__arg6),D4),
        struct IntuitionBase *, (__IntuitionBase), 132, Intuition    );
}

#define ScreenPosition(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Intuition_ScreenPosition((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScrollWindowRaster(struct Window * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, WORD __arg6, WORD __arg7, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC7NR(void, ScrollWindowRaster,
        AROS_LCA(struct Window *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(WORD,(__arg6),D4),
        AROS_LCA(WORD,(__arg7),D5),
        struct IntuitionBase *, (__IntuitionBase), 133, Intuition    );
}

#define ScrollWindowRaster(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Intuition_ScrollWindowRaster((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_LendMenus(struct Window * __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC2NR(void, LendMenus,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 134, Intuition    );
}

#define LendMenus(arg1, arg2) \
    __inline_Intuition_LendMenus((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_DoGadgetMethodA(struct Gadget * __arg1, struct Window * __arg2, struct Requester * __arg3, Msg __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    return AROS_LC4(IPTR, DoGadgetMethodA,
        AROS_LCA(struct Gadget *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        AROS_LCA(struct Requester *,(__arg3),A2),
        AROS_LCA(Msg,(__arg4),A3),
        struct IntuitionBase *, (__IntuitionBase), 135, Intuition    );
}

#define DoGadgetMethodA(arg1, arg2, arg3, arg4) \
    __inline_Intuition_DoGadgetMethodA((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define DoGadgetMethod(arg1, arg2, arg3, ...) \
({ \
    const IPTR DoGadgetMethodA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    DoGadgetMethodA((arg1), (arg2), (arg3), (Msg)(DoGadgetMethodA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SetWindowPointerA(struct Window * __arg1, struct TagItem * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC2NR(void, SetWindowPointerA,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 136, Intuition    );
}

#define SetWindowPointerA(arg1, arg2) \
    __inline_Intuition_SetWindowPointerA((arg1), (arg2), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define SetWindowPointer(arg1, ...) \
({ \
    const IPTR SetWindowPointerA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetWindowPointerA((arg1), (struct TagItem *)(SetWindowPointerA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_TimedDisplayAlert(ULONG __arg1, UBYTE * __arg2, UWORD __arg3, ULONG __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    return AROS_LC4(BOOL, TimedDisplayAlert,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(UBYTE *,(__arg2),A0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),A1),
        struct IntuitionBase *, (__IntuitionBase), 137, Intuition    );
}

#define TimedDisplayAlert(arg1, arg2, arg3, arg4) \
    __inline_Intuition_TimedDisplayAlert((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_HelpControl(struct Window * __arg1, ULONG __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 39)
    AROS_LC2NR(void, HelpControl,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct IntuitionBase *, (__IntuitionBase), 138, Intuition    );
}

#define HelpControl(arg1, arg2) \
    __inline_Intuition_HelpControl((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (39 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline LONG __inline_Intuition_IsWindowVisible(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(LONG, IsWindowVisible,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 139, Intuition    );
}

#define IsWindowVisible(arg1) \
    __inline_Intuition_IsWindowVisible((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_ShowWindow(struct Window * __arg1, struct Window * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC2(BOOL, ShowWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Window *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 140, Intuition    );
}

#define ShowWindow(arg1, arg2) \
    __inline_Intuition_ShowWindow((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_HideWindow(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(BOOL, HideWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 141, Intuition    );
}

#define HideWindow(arg1) \
    __inline_Intuition_HideWindow((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline struct Region * __inline_Intuition_ChangeWindowShape(struct Window * __arg1, struct Region * __arg2, struct Hook * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC3(struct Region *, ChangeWindowShape,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        AROS_LCA(struct Hook *,(__arg3),A2),
        struct IntuitionBase *, (__IntuitionBase), 143, Intuition    );
}

#define ChangeWindowShape(arg1, arg2, arg3) \
    __inline_Intuition_ChangeWindowShape((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SetDefaultScreenFont(struct TextFont * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC1NR(void, SetDefaultScreenFont,
        AROS_LCA(struct TextFont *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 144, Intuition    );
}

#define SetDefaultScreenFont(arg1) \
    __inline_Intuition_SetDefaultScreenFont((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_DoNotify(Class * __arg1, Object * __arg2, struct ICData * __arg3, struct opUpdate * __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC4(IPTR, DoNotify,
        AROS_LCA(Class *,(__arg1),A0),
        AROS_LCA(Object *,(__arg2),A1),
        AROS_LCA(struct ICData *,(__arg3),A2),
        AROS_LCA(struct opUpdate *,(__arg4),A3),
        struct IntuitionBase *, (__IntuitionBase), 145, Intuition    );
}

#define DoNotify(arg1, arg2, arg3, arg4) \
    __inline_Intuition_DoNotify((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeICData(struct ICData * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC1NR(void, FreeICData,
        AROS_LCA(struct ICData *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 146, Intuition    );
}

#define FreeICData(arg1) \
    __inline_Intuition_FreeICData((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline struct IntuiMessage * __inline_Intuition_AllocIntuiMessage(struct Window * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(struct IntuiMessage *, AllocIntuiMessage,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 148, Intuition    );
}

#define AllocIntuiMessage(arg1) \
    __inline_Intuition_AllocIntuiMessage((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeIntuiMessage(struct IntuiMessage * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC1NR(void, FreeIntuiMessage,
        AROS_LCA(struct IntuiMessage *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 149, Intuition    );
}

#define FreeIntuiMessage(arg1) \
    __inline_Intuition_FreeIntuiMessage((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_SendIntuiMessage(struct Window * __arg1, struct IntuiMessage * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC2NR(void, SendIntuiMessage,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(struct IntuiMessage *,(__arg2),A1),
        struct IntuitionBase *, (__IntuitionBase), 151, Intuition    );
}

#define SendIntuiMessage(arg1, arg2) \
    __inline_Intuition_SendIntuiMessage((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ChangeDecoration(ULONG __arg1, struct NewDecorator * __arg2, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC2NR(void, ChangeDecoration,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct NewDecorator *,(__arg2),A0),
        struct IntuitionBase *, (__IntuitionBase), 152, Intuition    );
}

#define ChangeDecoration(arg1, arg2) \
    __inline_Intuition_ChangeDecoration((arg1), (arg2), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline APTR __inline_Intuition_StartScreenNotifyTagList(struct TagItem * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(APTR, StartScreenNotifyTagList,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 154, Intuition    );
}

#define StartScreenNotifyTagList(arg1) \
    __inline_Intuition_StartScreenNotifyTagList((arg1), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define StartScreenNotifyTags(...) \
({ \
    const IPTR StartScreenNotifyTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    StartScreenNotifyTagList((struct TagItem *)(StartScreenNotifyTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline BOOL __inline_Intuition_EndScreenNotify(APTR __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(BOOL, EndScreenNotify,
        AROS_LCA(APTR,(__arg1),A0),
        struct IntuitionBase *, (__IntuitionBase), 155, Intuition    );
}

#define EndScreenNotify(arg1) \
    __inline_Intuition_EndScreenNotify((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline IPTR __inline_Intuition_GetDrawInfoAttr(struct DrawInfo * __arg1, ULONG __arg2, IPTR * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC3(IPTR, GetDrawInfoAttr,
        AROS_LCA(struct DrawInfo *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(IPTR *,(__arg3),A1),
        struct IntuitionBase *, (__IntuitionBase), 156, Intuition    );
}

#define GetDrawInfoAttr(arg1, arg2, arg3) \
    __inline_Intuition_GetDrawInfoAttr((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_WindowAction(struct Window * __arg1, ULONG __arg2, struct TagItem * __arg3, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC3NR(void, WindowAction,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct IntuitionBase *, (__IntuitionBase), 157, Intuition    );
}

#define WindowAction(arg1, arg2, arg3) \
    __inline_Intuition_WindowAction((arg1), (arg2), (arg3), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define WindowActionTags(arg1, arg2, ...) \
({ \
    const IPTR WindowAction_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    WindowAction((arg1), (arg2), (struct TagItem *)(WindowAction_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_ScrollWindowRasterNoFill(struct Window * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, WORD __arg6, WORD __arg7, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC7NR(void, ScrollWindowRasterNoFill,
        AROS_LCA(struct Window *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(WORD,(__arg6),D4),
        AROS_LCA(WORD,(__arg7),D5),
        struct IntuitionBase *, (__IntuitionBase), 159, Intuition    );
}

#define ScrollWindowRasterNoFill(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Intuition_ScrollWindowRasterNoFill((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline ULONG __inline_Intuition_SetPointerBounds(struct Screen * __arg1, struct Rectangle * __arg2, ULONG __arg3, struct TagItem * __arg4, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC4(ULONG, SetPointerBounds,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(struct TagItem *,(__arg4),A2),
        struct IntuitionBase *, (__IntuitionBase), 160, Intuition    );
}

#define SetPointerBounds(arg1, arg2, arg3, arg4) \
    __inline_Intuition_SetPointerBounds((arg1), (arg2), (arg3), (arg4), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define SetPointerBoundsTags(arg1, arg2, arg3, ...) \
({ \
    const IPTR SetPointerBounds_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPointerBounds((arg1), (arg2), (arg3), (struct TagItem *)(SetPointerBounds_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline Object ** __inline_Intuition_GetMonitorList(struct TagItem * __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    return AROS_LC1(Object **, GetMonitorList,
        AROS_LCA(struct TagItem *,(__arg1),A1),
        struct IntuitionBase *, (__IntuitionBase), 161, Intuition    );
}

#define GetMonitorList(arg1) \
    __inline_Intuition_GetMonitorList((arg1), __INTUITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(INTUITION_NO_INLINE_STDARG)
#define GetMonitorListTags(...) \
({ \
    const IPTR GetMonitorList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetMonitorList((struct TagItem *)(GetMonitorList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#if !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__)

static inline void __inline_Intuition_FreeMonitorList(Object ** __arg1, APTR __IntuitionBase)
{
    AROS_LIBREQ(IntuitionBase, 50)
    AROS_LC1NR(void, FreeMonitorList,
        AROS_LCA(Object **,(__arg1),A1),
        struct IntuitionBase *, (__IntuitionBase), 162, Intuition    );
}

#define FreeMonitorList(arg1) \
    __inline_Intuition_FreeMonitorList((arg1), __INTUITION_LIBBASE)

#endif /* !defined(__INTUITION_LIBAPI__) || (50 <= __INTUITION_LIBAPI__) */

#endif /* INLINE_INTUITION_H*/
