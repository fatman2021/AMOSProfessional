#ifndef INLINE_GRAPHICS_H
#define INLINE_GRAPHICS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/graphics/graphics.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for graphics
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__GRAPHICS_LIBBASE)
#    define __GRAPHICS_LIBBASE GfxBase
#endif


#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_BltBitMap(struct BitMap * __arg1, WORD __arg2, WORD __arg3, struct BitMap * __arg4, WORD __arg5, WORD __arg6, WORD __arg7, WORD __arg8, ULONG __arg9, ULONG __arg10, PLANEPTR __arg11, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC11(LONG, BltBitMap,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(struct BitMap *,(__arg4),A1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(WORD,(__arg8),D5),
        AROS_LCA(ULONG,(__arg9),D6),
        AROS_LCA(ULONG,(__arg10),D7),
        AROS_LCA(PLANEPTR,(__arg11),A2),
        struct GfxBase *, (__GfxBase), 5, Graphics    );
}

#define BltBitMap(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) \
    __inline_Graphics_BltBitMap((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), (arg11), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BltTemplate(PLANEPTR __arg1, WORD __arg2, WORD __arg3, struct RastPort * __arg4, WORD __arg5, WORD __arg6, WORD __arg7, WORD __arg8, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC8NR(void, BltTemplate,
        AROS_LCA(PLANEPTR,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(struct RastPort *,(__arg4),A1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(WORD,(__arg8),D5),
        struct GfxBase *, (__GfxBase), 6, Graphics    );
}

#define BltTemplate(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Graphics_BltTemplate((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ClearEOL(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, ClearEOL,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 7, Graphics    );
}

#define ClearEOL(arg1) \
    __inline_Graphics_ClearEOL((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ClearScreen(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, ClearScreen,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 8, Graphics    );
}

#define ClearScreen(arg1) \
    __inline_Graphics_ClearScreen((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline WORD __inline_Graphics_TextLength(struct RastPort * __arg1, CONST_STRPTR __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(WORD, TextLength,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(CONST_STRPTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 9, Graphics    );
}

#define TextLength(arg1, arg2, arg3) \
    __inline_Graphics_TextLength((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_Text(struct RastPort * __arg1, CONST_STRPTR __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, Text,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(CONST_STRPTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 10, Graphics    );
}

#define Text(arg1, arg2, arg3) \
    __inline_Graphics_Text((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetFont(struct RastPort * __arg1, struct TextFont * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetFont,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(struct TextFont *,(__arg2),A0),
        struct GfxBase *, (__GfxBase), 11, Graphics    );
}

#define SetFont(arg1, arg2) \
    __inline_Graphics_SetFont((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline struct TextFont * __inline_Graphics_OpenFont(const struct TextAttr * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(struct TextFont *, OpenFont,
        AROS_LCA(const struct TextAttr *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 12, Graphics    );
}

#define OpenFont(arg1) \
    __inline_Graphics_OpenFont((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_CloseFont(struct TextFont * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, CloseFont,
        AROS_LCA(struct TextFont *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 13, Graphics    );
}

#define CloseFont(arg1) \
    __inline_Graphics_CloseFont((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_AskSoftStyle(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(ULONG, AskSoftStyle,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 14, Graphics    );
}

#define AskSoftStyle(arg1) \
    __inline_Graphics_AskSoftStyle((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_SetSoftStyle(struct RastPort * __arg1, ULONG __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(ULONG, SetSoftStyle,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 15, Graphics    );
}

#define SetSoftStyle(arg1, arg2, arg3) \
    __inline_Graphics_SetSoftStyle((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AddBob(struct Bob * __arg1, struct RastPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, AddBob,
        AROS_LCA(struct Bob *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 16, Graphics    );
}

#define AddBob(arg1, arg2) \
    __inline_Graphics_AddBob((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AddVSprite(struct VSprite * __arg1, struct RastPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, AddVSprite,
        AROS_LCA(struct VSprite *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 17, Graphics    );
}

#define AddVSprite(arg1, arg2) \
    __inline_Graphics_AddVSprite((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_DoCollision(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, DoCollision,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 18, Graphics    );
}

#define DoCollision(arg1) \
    __inline_Graphics_DoCollision((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_DrawGList(struct RastPort * __arg1, struct ViewPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, DrawGList,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(struct ViewPort *,(__arg2),A0),
        struct GfxBase *, (__GfxBase), 19, Graphics    );
}

#define DrawGList(arg1, arg2) \
    __inline_Graphics_DrawGList((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitGels(struct VSprite * __arg1, struct VSprite * __arg2, struct GelsInfo * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, InitGels,
        AROS_LCA(struct VSprite *,(__arg1),A0),
        AROS_LCA(struct VSprite *,(__arg2),A1),
        AROS_LCA(struct GelsInfo *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 20, Graphics    );
}

#define InitGels(arg1, arg2, arg3) \
    __inline_Graphics_InitGels((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitMasks(struct VSprite * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, InitMasks,
        AROS_LCA(struct VSprite *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 21, Graphics    );
}

#define InitMasks(arg1) \
    __inline_Graphics_InitMasks((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_RemIBob(struct Bob * __arg1, struct RastPort * __arg2, struct ViewPort * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, RemIBob,
        AROS_LCA(struct Bob *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        AROS_LCA(struct ViewPort *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 22, Graphics    );
}

#define RemIBob(arg1, arg2, arg3) \
    __inline_Graphics_RemIBob((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_RemVSprite(struct VSprite * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, RemVSprite,
        AROS_LCA(struct VSprite *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 23, Graphics    );
}

#define RemVSprite(arg1) \
    __inline_Graphics_RemVSprite((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetCollision(ULONG __arg1, VOID_FUNC __arg2, struct GelsInfo * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, SetCollision,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(VOID_FUNC,(__arg2),A0),
        AROS_LCA(struct GelsInfo *,(__arg3),A1),
        struct GfxBase *, (__GfxBase), 24, Graphics    );
}

#define SetCollision(arg1, arg2, arg3) \
    __inline_Graphics_SetCollision((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SortGList(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, SortGList,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 25, Graphics    );
}

#define SortGList(arg1) \
    __inline_Graphics_SortGList((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AddAnimOb(struct AnimOb * __arg1, struct AnimOb ** __arg2, struct RastPort * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, AddAnimOb,
        AROS_LCA(struct AnimOb *,(__arg1),A0),
        AROS_LCA(struct AnimOb **,(__arg2),A1),
        AROS_LCA(struct RastPort *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 26, Graphics    );
}

#define AddAnimOb(arg1, arg2, arg3) \
    __inline_Graphics_AddAnimOb((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_Animate(struct AnimOb ** __arg1, struct RastPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, Animate,
        AROS_LCA(struct AnimOb **,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 27, Graphics    );
}

#define Animate(arg1, arg2) \
    __inline_Graphics_Animate((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_GetGBuffers(struct AnimOb * __arg1, struct RastPort * __arg2, BOOL __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(BOOL, GetGBuffers,
        AROS_LCA(struct AnimOb *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 28, Graphics    );
}

#define GetGBuffers(arg1, arg2, arg3) \
    __inline_Graphics_GetGBuffers((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitGMasks(struct AnimOb * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, InitGMasks,
        AROS_LCA(struct AnimOb *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 29, Graphics    );
}

#define InitGMasks(arg1) \
    __inline_Graphics_InitGMasks((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_DrawEllipse(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC5NR(void, DrawEllipse,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 30, Graphics    );
}

#define DrawEllipse(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_DrawEllipse((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_AreaEllipse(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC5(ULONG, AreaEllipse,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 31, Graphics    );
}

#define AreaEllipse(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_AreaEllipse((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_LoadRGB4(struct ViewPort * __arg1, UWORD * __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, LoadRGB4,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(UWORD *,(__arg2),A1),
        AROS_LCA(WORD,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 32, Graphics    );
}

#define LoadRGB4(arg1, arg2, arg3) \
    __inline_Graphics_LoadRGB4((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitRastPort(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, InitRastPort,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 33, Graphics    );
}

#define InitRastPort(arg1) \
    __inline_Graphics_InitRastPort((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitVPort(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, InitVPort,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 34, Graphics    );
}

#define InitVPort(arg1) \
    __inline_Graphics_InitVPort((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_MrgCop(struct View * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(ULONG, MrgCop,
        AROS_LCA(struct View *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 35, Graphics    );
}

#define MrgCop(arg1) \
    __inline_Graphics_MrgCop((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_MakeVPort(struct View * __arg1, struct ViewPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(ULONG, MakeVPort,
        AROS_LCA(struct View *,(__arg1),A0),
        AROS_LCA(struct ViewPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 36, Graphics    );
}

#define MakeVPort(arg1, arg2) \
    __inline_Graphics_MakeVPort((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_LoadView(struct View * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, LoadView,
        AROS_LCA(struct View *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 37, Graphics    );
}

#define LoadView(arg1) \
    __inline_Graphics_LoadView((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_WaitBlit(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC0NR(void, WaitBlit,
        struct GfxBase *, (__GfxBase), 38, Graphics    );
}

#define WaitBlit() \
    __inline_Graphics_WaitBlit(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRast(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetRast,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 39, Graphics    );
}

#define SetRast(arg1, arg2) \
    __inline_Graphics_SetRast((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_Move(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, Move,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 40, Graphics    );
}

#define Move(arg1, arg2, arg3) \
    __inline_Graphics_Move((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_Draw(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, Draw,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 41, Graphics    );
}

#define Draw(arg1, arg2, arg3) \
    __inline_Graphics_Draw((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_AreaMove(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(ULONG, AreaMove,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 42, Graphics    );
}

#define AreaMove(arg1, arg2, arg3) \
    __inline_Graphics_AreaMove((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_AreaDraw(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(ULONG, AreaDraw,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 43, Graphics    );
}

#define AreaDraw(arg1, arg2, arg3) \
    __inline_Graphics_AreaDraw((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_AreaEnd(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(LONG, AreaEnd,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 44, Graphics    );
}

#define AreaEnd(arg1) \
    __inline_Graphics_AreaEnd((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_WaitTOF(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC0NR(void, WaitTOF,
        struct GfxBase *, (__GfxBase), 45, Graphics    );
}

#define WaitTOF() \
    __inline_Graphics_WaitTOF(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_QBlit(struct bltnode * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, QBlit,
        AROS_LCA(struct bltnode *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 46, Graphics    );
}

#define QBlit(arg1) \
    __inline_Graphics_QBlit((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitArea(struct AreaInfo * __arg1, void * __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, InitArea,
        AROS_LCA(struct AreaInfo *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        AROS_LCA(WORD,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 47, Graphics    );
}

#define InitArea(arg1, arg2, arg3) \
    __inline_Graphics_InitArea((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRGB4(struct ViewPort * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC5NR(void, SetRGB4,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        AROS_LCA(ULONG,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 48, Graphics    );
}

#define SetRGB4(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_SetRGB4((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_QBSBlit(struct bltnode * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, QBSBlit,
        AROS_LCA(struct bltnode *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 49, Graphics    );
}

#define QBSBlit(arg1) \
    __inline_Graphics_QBSBlit((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BltClear(void * __arg1, ULONG __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, BltClear,
        AROS_LCA(void *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 50, Graphics    );
}

#define BltClear(arg1, arg2, arg3) \
    __inline_Graphics_BltClear((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_RectFill(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC5NR(void, RectFill,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 51, Graphics    );
}

#define RectFill(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_RectFill((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BltPattern(struct RastPort * __arg1, PLANEPTR __arg2, WORD __arg3, WORD __arg4, WORD __arg5, WORD __arg6, ULONG __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC7NR(void, BltPattern,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(PLANEPTR,(__arg2),A0),
        AROS_LCA(WORD,(__arg3),D0),
        AROS_LCA(WORD,(__arg4),D1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(ULONG,(__arg7),D4),
        struct GfxBase *, (__GfxBase), 52, Graphics    );
}

#define BltPattern(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_BltPattern((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_ReadPixel(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(LONG, ReadPixel,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 53, Graphics    );
}

#define ReadPixel(arg1, arg2, arg3) \
    __inline_Graphics_ReadPixel((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_WritePixel(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(LONG, WritePixel,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 54, Graphics    );
}

#define WritePixel(arg1, arg2, arg3) \
    __inline_Graphics_WritePixel((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_Flood(struct RastPort * __arg1, ULONG __arg2, WORD __arg3, WORD __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC4(BOOL, Flood,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(WORD,(__arg3),D0),
        AROS_LCA(WORD,(__arg4),D1),
        struct GfxBase *, (__GfxBase), 55, Graphics    );
}

#define Flood(arg1, arg2, arg3, arg4) \
    __inline_Graphics_Flood((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_PolyDraw(struct RastPort * __arg1, LONG __arg2, WORD * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, PolyDraw,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(WORD *,(__arg3),A0),
        struct GfxBase *, (__GfxBase), 56, Graphics    );
}

#define PolyDraw(arg1, arg2, arg3) \
    __inline_Graphics_PolyDraw((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetAPen(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetAPen,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 57, Graphics    );
}

#define SetAPen(arg1, arg2) \
    __inline_Graphics_SetAPen((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetBPen(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetBPen,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 58, Graphics    );
}

#define SetBPen(arg1, arg2) \
    __inline_Graphics_SetBPen((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetDrMd(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetDrMd,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 59, Graphics    );
}

#define SetDrMd(arg1, arg2) \
    __inline_Graphics_SetDrMd((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitView(struct View * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, InitView,
        AROS_LCA(struct View *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 60, Graphics    );
}

#define InitView(arg1) \
    __inline_Graphics_InitView((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_CBump(struct UCopList * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, CBump,
        AROS_LCA(struct UCopList *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 61, Graphics    );
}

#define CBump(arg1) \
    __inline_Graphics_CBump((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_CMove(struct UCopList * __arg1, void * __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, CMove,
        AROS_LCA(struct UCopList *,(__arg1),A1),
        AROS_LCA(void *,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 62, Graphics    );
}

#define CMove(arg1, arg2, arg3) \
    __inline_Graphics_CMove((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_CWait(struct UCopList * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, CWait,
        AROS_LCA(struct UCopList *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 63, Graphics    );
}

#define CWait(arg1, arg2, arg3) \
    __inline_Graphics_CWait((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_VBeamPos(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC0(LONG, VBeamPos,
        struct GfxBase *, (__GfxBase), 64, Graphics    );
}

#define VBeamPos() \
    __inline_Graphics_VBeamPos(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_InitBitMap(struct BitMap * __arg1, BYTE __arg2, UWORD __arg3, UWORD __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC4NR(void, InitBitMap,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(BYTE,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        struct GfxBase *, (__GfxBase), 65, Graphics    );
}

#define InitBitMap(arg1, arg2, arg3, arg4) \
    __inline_Graphics_InitBitMap((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ScrollRaster(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, WORD __arg6, WORD __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC7NR(void, ScrollRaster,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(WORD,(__arg6),D4),
        AROS_LCA(WORD,(__arg7),D5),
        struct GfxBase *, (__GfxBase), 66, Graphics    );
}

#define ScrollRaster(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_ScrollRaster((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_WaitBOVP(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, WaitBOVP,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 67, Graphics    );
}

#define WaitBOVP(arg1) \
    __inline_Graphics_WaitBOVP((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline WORD __inline_Graphics_GetSprite(struct SimpleSprite * __arg1, WORD __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(WORD, GetSprite,
        AROS_LCA(struct SimpleSprite *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 68, Graphics    );
}

#define GetSprite(arg1, arg2) \
    __inline_Graphics_GetSprite((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeSprite(WORD __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, FreeSprite,
        AROS_LCA(WORD,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 69, Graphics    );
}

#define FreeSprite(arg1) \
    __inline_Graphics_FreeSprite((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ChangeSprite(struct ViewPort * __arg1, struct SimpleSprite * __arg2, void * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, ChangeSprite,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(struct SimpleSprite *,(__arg2),A1),
        AROS_LCA(void *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 70, Graphics    );
}

#define ChangeSprite(arg1, arg2, arg3) \
    __inline_Graphics_ChangeSprite((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_MoveSprite(struct ViewPort * __arg1, struct SimpleSprite * __arg2, WORD __arg3, WORD __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC4NR(void, MoveSprite,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(struct SimpleSprite *,(__arg2),A1),
        AROS_LCA(WORD,(__arg3),D0),
        AROS_LCA(WORD,(__arg4),D1),
        struct GfxBase *, (__GfxBase), 71, Graphics    );
}

#define MoveSprite(arg1, arg2, arg3, arg4) \
    __inline_Graphics_MoveSprite((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_LockLayerRom(struct Layer * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, LockLayerRom,
        AROS_LCA(struct Layer *,(__arg1),A5),
        struct GfxBase *, (__GfxBase), 72, Graphics    );
}

#define LockLayerRom(arg1) \
    __inline_Graphics_LockLayerRom((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_UnlockLayerRom(struct Layer * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, UnlockLayerRom,
        AROS_LCA(struct Layer *,(__arg1),A5),
        struct GfxBase *, (__GfxBase), 73, Graphics    );
}

#define UnlockLayerRom(arg1) \
    __inline_Graphics_UnlockLayerRom((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SyncSBitMap(struct Layer * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, SyncSBitMap,
        AROS_LCA(struct Layer *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 74, Graphics    );
}

#define SyncSBitMap(arg1) \
    __inline_Graphics_SyncSBitMap((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_CopySBitMap(struct Layer * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, CopySBitMap,
        AROS_LCA(struct Layer *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 75, Graphics    );
}

#define CopySBitMap(arg1) \
    __inline_Graphics_CopySBitMap((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_OwnBlitter(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC0NR(void, OwnBlitter,
        struct GfxBase *, (__GfxBase), 76, Graphics    );
}

#define OwnBlitter() \
    __inline_Graphics_OwnBlitter(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_DisownBlitter(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC0NR(void, DisownBlitter,
        struct GfxBase *, (__GfxBase), 77, Graphics    );
}

#define DisownBlitter() \
    __inline_Graphics_DisownBlitter(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline struct TmpRas * __inline_Graphics_InitTmpRas(struct TmpRas * __arg1, void * __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(struct TmpRas *, InitTmpRas,
        AROS_LCA(struct TmpRas *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 78, Graphics    );
}

#define InitTmpRas(arg1, arg2, arg3) \
    __inline_Graphics_InitTmpRas((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AskFont(struct RastPort * __arg1, struct TextAttr * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, AskFont,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(struct TextAttr *,(__arg2),A0),
        struct GfxBase *, (__GfxBase), 79, Graphics    );
}

#define AskFont(arg1, arg2) \
    __inline_Graphics_AskFont((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AddFont(struct TextFont * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, AddFont,
        AROS_LCA(struct TextFont *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 80, Graphics    );
}

#define AddFont(arg1) \
    __inline_Graphics_AddFont((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_RemFont(struct TextFont * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, RemFont,
        AROS_LCA(struct TextFont *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 81, Graphics    );
}

#define RemFont(arg1) \
    __inline_Graphics_RemFont((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline PLANEPTR __inline_Graphics_AllocRaster(UWORD __arg1, UWORD __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(PLANEPTR, AllocRaster,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(UWORD,(__arg2),D1),
        struct GfxBase *, (__GfxBase), 82, Graphics    );
}

#define AllocRaster(arg1, arg2) \
    __inline_Graphics_AllocRaster((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeRaster(PLANEPTR __arg1, UWORD __arg2, UWORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, FreeRaster,
        AROS_LCA(PLANEPTR,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 83, Graphics    );
}

#define FreeRaster(arg1, arg2, arg3) \
    __inline_Graphics_FreeRaster((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_AndRectRegion(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, AndRectRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 84, Graphics    );
}

#define AndRectRegion(arg1, arg2) \
    __inline_Graphics_AndRectRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_OrRectRegion(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, OrRectRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 85, Graphics    );
}

#define OrRectRegion(arg1, arg2) \
    __inline_Graphics_OrRectRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_NewRegion(APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC0(struct Region *, NewRegion,
        struct GfxBase *, (__GfxBase), 86, Graphics    );
}

#define NewRegion() \
    __inline_Graphics_NewRegion(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_ClearRectRegion(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, ClearRectRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 87, Graphics    );
}

#define ClearRectRegion(arg1, arg2) \
    __inline_Graphics_ClearRectRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ClearRegion(struct Region * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, ClearRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 88, Graphics    );
}

#define ClearRegion(arg1) \
    __inline_Graphics_ClearRegion((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_DisposeRegion(struct Region * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, DisposeRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 89, Graphics    );
}

#define DisposeRegion(arg1) \
    __inline_Graphics_DisposeRegion((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeVPortCopLists(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, FreeVPortCopLists,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 90, Graphics    );
}

#define FreeVPortCopLists(arg1) \
    __inline_Graphics_FreeVPortCopLists((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeCopList(struct CopList * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, FreeCopList,
        AROS_LCA(struct CopList *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 91, Graphics    );
}

#define FreeCopList(arg1) \
    __inline_Graphics_FreeCopList((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ClipBlit(struct RastPort * __arg1, WORD __arg2, WORD __arg3, struct RastPort * __arg4, WORD __arg5, WORD __arg6, WORD __arg7, WORD __arg8, UBYTE __arg9, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC9NR(void, ClipBlit,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(struct RastPort *,(__arg4),A1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(WORD,(__arg8),D5),
        AROS_LCA(UBYTE,(__arg9),D6),
        struct GfxBase *, (__GfxBase), 92, Graphics    );
}

#define ClipBlit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Graphics_ClipBlit((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_XorRectRegion(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, XorRectRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 93, Graphics    );
}

#define XorRectRegion(arg1, arg2) \
    __inline_Graphics_XorRectRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeCprList(struct cprlist * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, FreeCprList,
        AROS_LCA(struct cprlist *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 94, Graphics    );
}

#define FreeCprList(arg1) \
    __inline_Graphics_FreeCprList((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline struct ColorMap * __inline_Graphics_GetColorMap(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(struct ColorMap *, GetColorMap,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 95, Graphics    );
}

#define GetColorMap(arg1) \
    __inline_Graphics_GetColorMap((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeColorMap(struct ColorMap * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, FreeColorMap,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 96, Graphics    );
}

#define FreeColorMap(arg1) \
    __inline_Graphics_FreeColorMap((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetRGB4(struct ColorMap * __arg1, LONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(ULONG, GetRGB4,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 97, Graphics    );
}

#define GetRGB4(arg1, arg2) \
    __inline_Graphics_GetRGB4((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ScrollVPort(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC1NR(void, ScrollVPort,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 98, Graphics    );
}

#define ScrollVPort(arg1) \
    __inline_Graphics_ScrollVPort((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline struct CopList * __inline_Graphics_UCopperListInit(struct UCopList * __arg1, WORD __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(struct CopList *, UCopperListInit,
        AROS_LCA(struct UCopList *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 99, Graphics    );
}

#define UCopperListInit(arg1, arg2) \
    __inline_Graphics_UCopperListInit((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeGBuffers(struct AnimOb * __arg1, struct RastPort * __arg2, BOOL __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC3NR(void, FreeGBuffers,
        AROS_LCA(struct AnimOb *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D0),
        struct GfxBase *, (__GfxBase), 100, Graphics    );
}

#define FreeGBuffers(arg1, arg2, arg3) \
    __inline_Graphics_FreeGBuffers((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BltBitMapRastPort(struct BitMap * __arg1, WORD __arg2, WORD __arg3, struct RastPort * __arg4, WORD __arg5, WORD __arg6, WORD __arg7, WORD __arg8, ULONG __arg9, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC9NR(void, BltBitMapRastPort,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(struct RastPort *,(__arg4),A1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(WORD,(__arg8),D5),
        AROS_LCA(ULONG,(__arg9),D6),
        struct GfxBase *, (__GfxBase), 101, Graphics    );
}

#define BltBitMapRastPort(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Graphics_BltBitMapRastPort((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_OrRegionRegion(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, OrRegionRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 102, Graphics    );
}

#define OrRegionRegion(arg1, arg2) \
    __inline_Graphics_OrRegionRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_XorRegionRegion(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, XorRegionRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 103, Graphics    );
}

#define XorRegionRegion(arg1, arg2) \
    __inline_Graphics_XorRegionRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_AndRegionRegion(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC2(BOOL, AndRegionRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 104, Graphics    );
}

#define AndRegionRegion(arg1, arg2) \
    __inline_Graphics_AndRegionRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRGB4CM(struct ColorMap * __arg1, WORD __arg2, UBYTE __arg3, UBYTE __arg4, UBYTE __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC5NR(void, SetRGB4CM,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(UBYTE,(__arg3),D1),
        AROS_LCA(UBYTE,(__arg4),D2),
        AROS_LCA(UBYTE,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 105, Graphics    );
}

#define SetRGB4CM(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_SetRGB4CM((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BltMaskBitMapRastPort(struct BitMap * __arg1, WORD __arg2, WORD __arg3, struct RastPort * __arg4, WORD __arg5, WORD __arg6, WORD __arg7, WORD __arg8, ULONG __arg9, PLANEPTR __arg10, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC10NR(void, BltMaskBitMapRastPort,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(struct RastPort *,(__arg4),A1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(WORD,(__arg8),D5),
        AROS_LCA(ULONG,(__arg9),D6),
        AROS_LCA(PLANEPTR,(__arg10),A2),
        struct GfxBase *, (__GfxBase), 106, Graphics    );
}

#define BltMaskBitMapRastPort(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __inline_Graphics_BltMaskBitMapRastPort((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_AddDisplayDriverA(APTR __arg1, const struct TagItem * __arg2, const struct TagItem * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC3(LONG, AddDisplayDriverA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(const struct TagItem *,(__arg2),A1),
        AROS_LCA(const struct TagItem *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 107, Graphics    );
}

#define AddDisplayDriverA(arg1, arg2, arg3) \
    __inline_Graphics_AddDisplayDriverA((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define AddDisplayDriver(arg1, arg2, ...) \
({ \
    const IPTR AddDisplayDriverA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddDisplayDriverA((arg1), (arg2), (const struct TagItem *)(AddDisplayDriverA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetDisplayDriverCallback(APTR __arg1, APTR __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    AROS_LC2NR(void, SetDisplayDriverCallback,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 108, Graphics    );
}

#define SetDisplayDriverCallback(arg1, arg2) \
    __inline_Graphics_SetDisplayDriverCallback((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_AttemptLockLayerRom(struct Layer * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 0)
    return AROS_LC1(BOOL, AttemptLockLayerRom,
        AROS_LCA(struct Layer *,(__arg1),A5),
        struct GfxBase *, (__GfxBase), 109, Graphics    );
}

#define AttemptLockLayerRom(arg1) \
    __inline_Graphics_AttemptLockLayerRom((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline struct ExtendedNode * __inline_Graphics_GfxNew(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(struct ExtendedNode *, GfxNew,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 110, Graphics    );
}

#define GfxNew(arg1) \
    __inline_Graphics_GfxNew((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_GfxFree(struct ExtendedNode * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC1NR(void, GfxFree,
        AROS_LCA(struct ExtendedNode *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 111, Graphics    );
}

#define GfxFree(arg1) \
    __inline_Graphics_GfxFree((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_GfxAssociate(void * __arg1, struct ExtendedNode * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC2NR(void, GfxAssociate,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(struct ExtendedNode *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 112, Graphics    );
}

#define GfxAssociate(arg1, arg2) \
    __inline_Graphics_GfxAssociate((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_BitMapScale(struct BitScaleArgs * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC1NR(void, BitMapScale,
        AROS_LCA(struct BitScaleArgs *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 113, Graphics    );
}

#define BitMapScale(arg1) \
    __inline_Graphics_BitMapScale((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline UWORD __inline_Graphics_ScalerDiv(UWORD __arg1, UWORD __arg2, UWORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC3(UWORD, ScalerDiv,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(UWORD,(__arg2),D1),
        AROS_LCA(UWORD,(__arg3),D2),
        struct GfxBase *, (__GfxBase), 114, Graphics    );
}

#define ScalerDiv(arg1, arg2, arg3) \
    __inline_Graphics_ScalerDiv((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_TextExtent(struct RastPort * __arg1, CONST_STRPTR __arg2, ULONG __arg3, struct TextExtent * __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC4NR(void, TextExtent,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(CONST_STRPTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(struct TextExtent *,(__arg4),A2),
        struct GfxBase *, (__GfxBase), 115, Graphics    );
}

#define TextExtent(arg1, arg2, arg3, arg4) \
    __inline_Graphics_TextExtent((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_TextFit(struct RastPort * __arg1, CONST_STRPTR __arg2, ULONG __arg3, struct TextExtent * __arg4, struct TextExtent * __arg5, LONG __arg6, ULONG __arg7, ULONG __arg8, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC8(ULONG, TextFit,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(CONST_STRPTR,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(struct TextExtent *,(__arg4),A2),
        AROS_LCA(struct TextExtent *,(__arg5),A3),
        AROS_LCA(LONG,(__arg6),D1),
        AROS_LCA(ULONG,(__arg7),D2),
        AROS_LCA(ULONG,(__arg8),D3),
        struct GfxBase *, (__GfxBase), 116, Graphics    );
}

#define TextFit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Graphics_TextFit((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline struct ExtendedNode * __inline_Graphics_GfxLookUp(void * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(struct ExtendedNode *, GfxLookUp,
        AROS_LCA(void *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 117, Graphics    );
}

#define GfxLookUp(arg1) \
    __inline_Graphics_GfxLookUp((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_VideoControl(struct ColorMap * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC2(ULONG, VideoControl,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 118, Graphics    );
}

#define VideoControl(arg1, arg2) \
    __inline_Graphics_VideoControl((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define VideoControlTags(arg1, ...) \
({ \
    const IPTR VideoControl_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    VideoControl((arg1), (struct TagItem *)(VideoControl_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline struct MonitorSpec * __inline_Graphics_OpenMonitor(STRPTR __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC2(struct MonitorSpec *, OpenMonitor,
        AROS_LCA(STRPTR,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 119, Graphics    );
}

#define OpenMonitor(arg1, arg2) \
    __inline_Graphics_OpenMonitor((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_CloseMonitor(struct MonitorSpec * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(LONG, CloseMonitor,
        AROS_LCA(struct MonitorSpec *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 120, Graphics    );
}

#define CloseMonitor(arg1) \
    __inline_Graphics_CloseMonitor((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline DisplayInfoHandle __inline_Graphics_FindDisplayInfo(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(DisplayInfoHandle, FindDisplayInfo,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 121, Graphics    );
}

#define FindDisplayInfo(arg1) \
    __inline_Graphics_FindDisplayInfo((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_NextDisplayInfo(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(ULONG, NextDisplayInfo,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 122, Graphics    );
}

#define NextDisplayInfo(arg1) \
    __inline_Graphics_NextDisplayInfo((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetDisplayInfoData(DisplayInfoHandle __arg1, UBYTE * __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC5(ULONG, GetDisplayInfoData,
        AROS_LCA(DisplayInfoHandle,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(ULONG,(__arg4),D1),
        AROS_LCA(ULONG,(__arg5),D2),
        struct GfxBase *, (__GfxBase), 126, Graphics    );
}

#define GetDisplayInfoData(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_GetDisplayInfoData((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FontExtent(struct TextFont * __arg1, struct TextExtent * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC2NR(void, FontExtent,
        AROS_LCA(struct TextFont *,(__arg1),A0),
        AROS_LCA(struct TextExtent *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 127, Graphics    );
}

#define FontExtent(arg1, arg2) \
    __inline_Graphics_FontExtent((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_ReadPixelLine8(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, UBYTE * __arg5, struct RastPort * __arg6, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC6(LONG, ReadPixelLine8,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(UBYTE *,(__arg5),A2),
        AROS_LCA(struct RastPort *,(__arg6),A1),
        struct GfxBase *, (__GfxBase), 128, Graphics    );
}

#define ReadPixelLine8(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Graphics_ReadPixelLine8((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_WritePixelLine8(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, UBYTE * __arg5, struct RastPort * __arg6, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC6(LONG, WritePixelLine8,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(UBYTE *,(__arg5),A2),
        AROS_LCA(struct RastPort *,(__arg6),A1),
        struct GfxBase *, (__GfxBase), 129, Graphics    );
}

#define WritePixelLine8(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Graphics_WritePixelLine8((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline WORD __inline_Graphics_ReadPixelArray8(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, UBYTE * __arg6, struct RastPort * __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC7(WORD, ReadPixelArray8,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(UBYTE *,(__arg6),A2),
        AROS_LCA(struct RastPort *,(__arg7),A1),
        struct GfxBase *, (__GfxBase), 130, Graphics    );
}

#define ReadPixelArray8(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_ReadPixelArray8((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_WritePixelArray8(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, UBYTE * __arg6, struct RastPort * __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC7(LONG, WritePixelArray8,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(UBYTE *,(__arg6),A2),
        AROS_LCA(struct RastPort *,(__arg7),A1),
        struct GfxBase *, (__GfxBase), 131, Graphics    );
}

#define WritePixelArray8(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_WritePixelArray8((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetVPModeID(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(ULONG, GetVPModeID,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 132, Graphics    );
}

#define GetVPModeID(arg1) \
    __inline_Graphics_GetVPModeID((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_ModeNotAvailable(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC1(ULONG, ModeNotAvailable,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 133, Graphics    );
}

#define ModeNotAvailable(arg1) \
    __inline_Graphics_ModeNotAvailable((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline WORD __inline_Graphics_WeighTAMatch(const struct TextAttr * __arg1, const struct TextAttr * __arg2, struct TagItem * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC3(WORD, WeighTAMatch,
        AROS_LCA(const struct TextAttr *,(__arg1),A0),
        AROS_LCA(const struct TextAttr *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 134, Graphics    );
}

#define WeighTAMatch(arg1, arg2, arg3) \
    __inline_Graphics_WeighTAMatch((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define WeighTAMatchTags(arg1, arg2, ...) \
({ \
    const IPTR WeighTAMatch_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    WeighTAMatch((arg1), (arg2), (struct TagItem *)(WeighTAMatch_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_EraseRect(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC5NR(void, EraseRect,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 135, Graphics    );
}

#define EraseRect(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_EraseRect((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_ExtendFont(struct TextFont * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    return AROS_LC2(ULONG, ExtendFont,
        AROS_LCA(struct TextFont *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 136, Graphics    );
}

#define ExtendFont(arg1, arg2) \
    __inline_Graphics_ExtendFont((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ExtendFontTags(arg1, ...) \
({ \
    const IPTR ExtendFont_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ExtendFont((arg1), (struct TagItem *)(ExtendFont_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_StripFont(struct TextFont * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 36)
    AROS_LC1NR(void, StripFont,
        AROS_LCA(struct TextFont *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 137, Graphics    );
}

#define StripFont(arg1) \
    __inline_Graphics_StripFont((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline UWORD __inline_Graphics_CalcIVG(struct View * __arg1, struct ViewPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(UWORD, CalcIVG,
        AROS_LCA(struct View *,(__arg1),A0),
        AROS_LCA(struct ViewPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 138, Graphics    );
}

#define CalcIVG(arg1, arg2) \
    __inline_Graphics_CalcIVG((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_AttachPalExtra(struct ColorMap * __arg1, struct ViewPort * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(LONG, AttachPalExtra,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(struct ViewPort *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 139, Graphics    );
}

#define AttachPalExtra(arg1, arg2) \
    __inline_Graphics_AttachPalExtra((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_ObtainBestPenA(struct ColorMap * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, struct TagItem * __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC5(LONG, ObtainBestPenA,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(ULONG,(__arg3),D2),
        AROS_LCA(ULONG,(__arg4),D3),
        AROS_LCA(struct TagItem *,(__arg5),A1),
        struct GfxBase *, (__GfxBase), 140, Graphics    );
}

#define ObtainBestPenA(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_ObtainBestPenA((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ObtainBestPen(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR ObtainBestPenA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ObtainBestPenA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(ObtainBestPenA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRGB32(struct ViewPort * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC5NR(void, SetRGB32,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        AROS_LCA(ULONG,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 142, Graphics    );
}

#define SetRGB32(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_SetRGB32((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetAPen(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, GetAPen,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 143, Graphics    );
}

#define GetAPen(arg1) \
    __inline_Graphics_GetAPen((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetBPen(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, GetBPen,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 144, Graphics    );
}

#define GetBPen(arg1) \
    __inline_Graphics_GetBPen((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetDrMd(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, GetDrMd,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 145, Graphics    );
}

#define GetDrMd(arg1) \
    __inline_Graphics_GetDrMd((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_GetOutlinePen(struct RastPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, GetOutlinePen,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 146, Graphics    );
}

#define GetOutlinePen(arg1) \
    __inline_Graphics_GetOutlinePen((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_LoadRGB32(struct ViewPort * __arg1, const ULONG * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC2NR(void, LoadRGB32,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(const ULONG *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 147, Graphics    );
}

#define LoadRGB32(arg1, arg2) \
    __inline_Graphics_LoadRGB32((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_SetChipRev(ULONG __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, SetChipRev,
        AROS_LCA(ULONG,(__arg1),D0),
        struct GfxBase *, (__GfxBase), 148, Graphics    );
}

#define SetChipRev(arg1) \
    __inline_Graphics_SetChipRev((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetABPenDrMd(struct RastPort * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC4NR(void, SetABPenDrMd,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        struct GfxBase *, (__GfxBase), 149, Graphics    );
}

#define SetABPenDrMd(arg1, arg2, arg3, arg4) \
    __inline_Graphics_SetABPenDrMd((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_GetRGB32(struct ColorMap * __arg1, ULONG __arg2, ULONG __arg3, ULONG * __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC4NR(void, GetRGB32,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG *,(__arg4),A1),
        struct GfxBase *, (__GfxBase), 150, Graphics    );
}

#define GetRGB32(arg1, arg2, arg3, arg4) \
    __inline_Graphics_GetRGB32((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline struct BitMap * __inline_Graphics_AllocBitMap(UWORD __arg1, UWORD __arg2, ULONG __arg3, ULONG __arg4, struct BitMap * __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC5(struct BitMap *, AllocBitMap,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(UWORD,(__arg2),D1),
        AROS_LCA(ULONG,(__arg3),D2),
        AROS_LCA(ULONG,(__arg4),D3),
        AROS_LCA(struct BitMap *,(__arg5),A0),
        struct GfxBase *, (__GfxBase), 153, Graphics    );
}

#define AllocBitMap(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_AllocBitMap((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeBitMap(struct BitMap * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC1NR(void, FreeBitMap,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 154, Graphics    );
}

#define FreeBitMap(arg1) \
    __inline_Graphics_FreeBitMap((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_GetExtSpriteA(struct ExtSprite * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(LONG, GetExtSpriteA,
        AROS_LCA(struct ExtSprite *,(__arg1),A2),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 155, Graphics    );
}

#define GetExtSpriteA(arg1, arg2) \
    __inline_Graphics_GetExtSpriteA((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define GetExtSprite(arg1, ...) \
({ \
    const IPTR GetExtSpriteA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetExtSpriteA((arg1), (struct TagItem *)(GetExtSpriteA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_CoerceMode(struct ViewPort * __arg1, ULONG __arg2, ULONG __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC3(ULONG, CoerceMode,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 156, Graphics    );
}

#define CoerceMode(arg1, arg2, arg3) \
    __inline_Graphics_CoerceMode((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ChangeVPBitMap(struct ViewPort * __arg1, struct BitMap * __arg2, struct DBufInfo * __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC3NR(void, ChangeVPBitMap,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(struct DBufInfo *,(__arg3),A2),
        struct GfxBase *, (__GfxBase), 157, Graphics    );
}

#define ChangeVPBitMap(arg1, arg2, arg3) \
    __inline_Graphics_ChangeVPBitMap((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ReleasePen(struct ColorMap * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC2NR(void, ReleasePen,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 158, Graphics    );
}

#define ReleasePen(arg1, arg2) \
    __inline_Graphics_ReleasePen((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_ObtainPen(struct ColorMap * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC6(LONG, ObtainPen,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        AROS_LCA(ULONG,(__arg5),D3),
        AROS_LCA(ULONG,(__arg6),D4),
        struct GfxBase *, (__GfxBase), 159, Graphics    );
}

#define ObtainPen(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Graphics_ObtainPen((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline IPTR __inline_Graphics_GetBitMapAttr(struct BitMap * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(IPTR, GetBitMapAttr,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct GfxBase *, (__GfxBase), 160, Graphics    );
}

#define GetBitMapAttr(arg1, arg2) \
    __inline_Graphics_GetBitMapAttr((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline struct DBufInfo * __inline_Graphics_AllocDBufInfo(struct ViewPort * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(struct DBufInfo *, AllocDBufInfo,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 161, Graphics    );
}

#define AllocDBufInfo(arg1) \
    __inline_Graphics_AllocDBufInfo((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeDBufInfo(struct DBufInfo * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC1NR(void, FreeDBufInfo,
        AROS_LCA(struct DBufInfo *,(__arg1),A1),
        struct GfxBase *, (__GfxBase), 162, Graphics    );
}

#define FreeDBufInfo(arg1) \
    __inline_Graphics_FreeDBufInfo((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_SetOutlinePen(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(ULONG, SetOutlinePen,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 163, Graphics    );
}

#define SetOutlinePen(arg1, arg2) \
    __inline_Graphics_SetOutlinePen((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_SetWriteMask(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(ULONG, SetWriteMask,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 164, Graphics    );
}

#define SetWriteMask(arg1, arg2) \
    __inline_Graphics_SetWriteMask((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetMaxPen(struct RastPort * __arg1, ULONG __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC2NR(void, SetMaxPen,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct GfxBase *, (__GfxBase), 165, Graphics    );
}

#define SetMaxPen(arg1, arg2) \
    __inline_Graphics_SetMaxPen((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRGB32CM(struct ColorMap * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC5NR(void, SetRGB32CM,
        AROS_LCA(struct ColorMap *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D2),
        AROS_LCA(ULONG,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 166, Graphics    );
}

#define SetRGB32CM(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_SetRGB32CM((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_ScrollRasterBF(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, WORD __arg6, WORD __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC7NR(void, ScrollRasterBF,
        AROS_LCA(struct RastPort *,(__arg1),A1),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(WORD,(__arg6),D4),
        AROS_LCA(WORD,(__arg7),D5),
        struct GfxBase *, (__GfxBase), 167, Graphics    );
}

#define ScrollRasterBF(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_ScrollRasterBF((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_FindColor(struct ColorMap * __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC5(ULONG, FindColor,
        AROS_LCA(struct ColorMap *,(__arg1),A3),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(ULONG,(__arg3),D2),
        AROS_LCA(ULONG,(__arg4),D3),
        AROS_LCA(ULONG,(__arg5),D4),
        struct GfxBase *, (__GfxBase), 168, Graphics    );
}

#define FindColor(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_FindColor((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline struct ExtSprite * __inline_Graphics_AllocSpriteDataA(struct BitMap * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC2(struct ExtSprite *, AllocSpriteDataA,
        AROS_LCA(struct BitMap *,(__arg1),A2),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 170, Graphics    );
}

#define AllocSpriteDataA(arg1, arg2) \
    __inline_Graphics_AllocSpriteDataA((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define AllocSpriteData(arg1, ...) \
({ \
    const IPTR AllocSpriteDataA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocSpriteDataA((arg1), (struct TagItem *)(AllocSpriteDataA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_ChangeExtSpriteA(struct ViewPort * __arg1, struct ExtSprite * __arg2, struct ExtSprite * __arg3, struct TagItem * __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC4(LONG, ChangeExtSpriteA,
        AROS_LCA(struct ViewPort *,(__arg1),A0),
        AROS_LCA(struct ExtSprite *,(__arg2),A1),
        AROS_LCA(struct ExtSprite *,(__arg3),A2),
        AROS_LCA(struct TagItem *,(__arg4),A3),
        struct GfxBase *, (__GfxBase), 171, Graphics    );
}

#define ChangeExtSpriteA(arg1, arg2, arg3, arg4) \
    __inline_Graphics_ChangeExtSpriteA((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ChangeExtSprite(arg1, arg2, arg3, ...) \
({ \
    const IPTR ChangeExtSpriteA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ChangeExtSpriteA((arg1), (arg2), (arg3), (struct TagItem *)(ChangeExtSpriteA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_FreeSpriteData(struct ExtSprite * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC1NR(void, FreeSpriteData,
        AROS_LCA(struct ExtSprite *,(__arg1),A2),
        struct GfxBase *, (__GfxBase), 172, Graphics    );
}

#define FreeSpriteData(arg1) \
    __inline_Graphics_FreeSpriteData((arg1), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_SetRPAttrsA(struct RastPort * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC2NR(void, SetRPAttrsA,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 173, Graphics    );
}

#define SetRPAttrsA(arg1, arg2) \
    __inline_Graphics_SetRPAttrsA((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define SetRPAttrs(arg1, ...) \
({ \
    const IPTR SetRPAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetRPAttrsA((arg1), (struct TagItem *)(SetRPAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_GetRPAttrsA(struct RastPort * __arg1, struct TagItem * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    AROS_LC2NR(void, GetRPAttrsA,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 174, Graphics    );
}

#define GetRPAttrsA(arg1, arg2) \
    __inline_Graphics_GetRPAttrsA((arg1), (arg2), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define GetRPAttrs(arg1, ...) \
({ \
    const IPTR GetRPAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetRPAttrsA((arg1), (struct TagItem *)(GetRPAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

static inline ULONG __inline_Graphics_BestModeIDA(struct TagItem * __arg1, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 39)
    return AROS_LC1(ULONG, BestModeIDA,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct GfxBase *, (__GfxBase), 175, Graphics    );
}

#define BestModeIDA(arg1) \
    __inline_Graphics_BestModeIDA((arg1), __GRAPHICS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define BestModeID(...) \
({ \
    const IPTR BestModeIDA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    BestModeIDA((struct TagItem *)(BestModeIDA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_WriteChunkyPixels(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, UBYTE * __arg6, LONG __arg7, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    AROS_LC7NR(void, WriteChunkyPixels,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(UBYTE *,(__arg6),A2),
        AROS_LCA(LONG,(__arg7),D4),
        struct GfxBase *, (__GfxBase), 176, Graphics    );
}

#define WriteChunkyPixels(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Graphics_WriteChunkyPixels((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_SetRegion(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(BOOL, SetRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 181, Graphics    );
}

#define SetRegion(arg1, arg2) \
    __inline_Graphics_SetRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_ClearRegionRegion(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(BOOL, ClearRegionRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 182, Graphics    );
}

#define ClearRegionRegion(arg1, arg2) \
    __inline_Graphics_ClearRegionRegion((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_AreRegionsEqual(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(BOOL, AreRegionsEqual,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 183, Graphics    );
}

#define AreRegionsEqual(arg1, arg2) \
    __inline_Graphics_AreRegionsEqual((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_IsPointInRegion(struct Region * __arg1, WORD __arg2, WORD __arg3, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC3(BOOL, IsPointInRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        struct GfxBase *, (__GfxBase), 184, Graphics    );
}

#define IsPointInRegion(arg1, arg2, arg3) \
    __inline_Graphics_IsPointInRegion((arg1), (arg2), (arg3), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline BOOL __inline_Graphics_ScrollRegion(struct Region * __arg1, struct Rectangle * __arg2, WORD __arg3, WORD __arg4, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC4(BOOL, ScrollRegion,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        AROS_LCA(WORD,(__arg3),D0),
        AROS_LCA(WORD,(__arg4),D1),
        struct GfxBase *, (__GfxBase), 185, Graphics    );
}

#define ScrollRegion(arg1, arg2, arg3, arg4) \
    __inline_Graphics_ScrollRegion((arg1), (arg2), (arg3), (arg4), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_AndRectRegionND(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, AndRectRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 186, Graphics    );
}

#define AndRectRegionND(arg1, arg2) \
    __inline_Graphics_AndRectRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_AndRegionRegionND(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, AndRegionRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 187, Graphics    );
}

#define AndRegionRegionND(arg1, arg2) \
    __inline_Graphics_AndRegionRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_OrRectRegionND(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, OrRectRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 188, Graphics    );
}

#define OrRectRegionND(arg1, arg2) \
    __inline_Graphics_OrRectRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_OrRegionRegionND(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, OrRegionRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 189, Graphics    );
}

#define OrRegionRegionND(arg1, arg2) \
    __inline_Graphics_OrRegionRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_XorRectRegionND(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, XorRectRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 190, Graphics    );
}

#define XorRectRegionND(arg1, arg2) \
    __inline_Graphics_XorRectRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_XorRegionRegionND(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, XorRegionRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 191, Graphics    );
}

#define XorRegionRegionND(arg1, arg2) \
    __inline_Graphics_XorRegionRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_ClearRectRegionND(struct Region * __arg1, struct Rectangle * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, ClearRectRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Rectangle *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 192, Graphics    );
}

#define ClearRectRegionND(arg1, arg2) \
    __inline_Graphics_ClearRectRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline struct Region * __inline_Graphics_ClearRegionRegionND(struct Region * __arg1, struct Region * __arg2, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC2(struct Region *, ClearRegionRegionND,
        AROS_LCA(struct Region *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct GfxBase *, (__GfxBase), 193, Graphics    );
}

#define ClearRegionRegionND(arg1, arg2) \
    __inline_Graphics_ClearRegionRegionND((arg1), (arg2), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_WritePixels8(struct RastPort * __arg1, UBYTE * __arg2, ULONG __arg3, WORD __arg4, WORD __arg5, WORD __arg6, WORD __arg7, APTR __arg8, BOOL __arg9, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC9(LONG, WritePixels8,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(WORD,(__arg4),D1),
        AROS_LCA(WORD,(__arg5),D2),
        AROS_LCA(WORD,(__arg6),D3),
        AROS_LCA(WORD,(__arg7),D4),
        AROS_LCA(APTR,(__arg8),A2),
        AROS_LCA(BOOL,(__arg9),D5),
        struct GfxBase *, (__GfxBase), 197, Graphics    );
}

#define WritePixels8(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Graphics_WritePixels8((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_FillRectPenDrMd(struct RastPort * __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, ULONG __arg6, IPTR __arg7, BOOL __arg8, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC8(LONG, FillRectPenDrMd,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        AROS_LCA(ULONG,(__arg6),D4),
        AROS_LCA(IPTR,(__arg7),D5),
        AROS_LCA(BOOL,(__arg8),D6),
        struct GfxBase *, (__GfxBase), 198, Graphics    );
}

#define FillRectPenDrMd(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Graphics_FillRectPenDrMd((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_DoRenderFunc(struct RastPort * __arg1, Point * __arg2, struct Rectangle * __arg3, APTR __arg4, APTR __arg5, BOOL __arg6, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC6(LONG, DoRenderFunc,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(Point *,(__arg2),A1),
        AROS_LCA(struct Rectangle *,(__arg3),A2),
        AROS_LCA(APTR,(__arg4),A3),
        AROS_LCA(APTR,(__arg5),A4),
        AROS_LCA(BOOL,(__arg6),D0),
        struct GfxBase *, (__GfxBase), 199, Graphics    );
}

#define DoRenderFunc(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Graphics_DoRenderFunc((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline LONG __inline_Graphics_DoPixelFunc(struct RastPort * __arg1, WORD __arg2, WORD __arg3, APTR __arg4, APTR __arg5, BOOL __arg6, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    return AROS_LC6(LONG, DoPixelFunc,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(APTR,(__arg4),A1),
        AROS_LCA(APTR,(__arg5),A2),
        AROS_LCA(BOOL,(__arg6),D2),
        struct GfxBase *, (__GfxBase), 200, Graphics    );
}

#define DoPixelFunc(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_Graphics_DoPixelFunc((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

static inline void __inline_Graphics_UpdateBitMap(struct BitMap * __arg1, UWORD __arg2, UWORD __arg3, UWORD __arg4, UWORD __arg5, APTR __GfxBase)
{
    AROS_LIBREQ(GfxBase, 40)
    AROS_LC5NR(void, UpdateBitMap,
        AROS_LCA(struct BitMap *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UWORD,(__arg3),D1),
        AROS_LCA(UWORD,(__arg4),D2),
        AROS_LCA(UWORD,(__arg5),D3),
        struct GfxBase *, (__GfxBase), 201, Graphics    );
}

#define UpdateBitMap(arg1, arg2, arg3, arg4, arg5) \
    __inline_Graphics_UpdateBitMap((arg1), (arg2), (arg3), (arg4), (arg5), __GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#endif /* INLINE_GRAPHICS_H*/
