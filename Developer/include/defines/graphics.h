#ifndef DEFINES_GRAPHICS_H
#define DEFINES_GRAPHICS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/graphics/graphics.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for graphics
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__GRAPHICS_LIBBASE)
#    define __GRAPHICS_LIBBASE GfxBase
#endif

__BEGIN_DECLS


#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltBitMap_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10, __arg11) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC11(LONG, BltBitMap, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(struct BitMap *,(__arg4),A1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(WORD,(__arg8),D5), \
                  AROS_LCA(ULONG,(__arg9),D6), \
                  AROS_LCA(ULONG,(__arg10),D7), \
                  AROS_LCA(PLANEPTR,(__arg11),A2), \
        struct GfxBase *, (__GfxBase), 5, Graphics);\
})

#define BltBitMap(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) \
    __BltBitMap_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10), (arg11))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltTemplate_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC8NR(void, BltTemplate, \
                  AROS_LCA(PLANEPTR,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(struct RastPort *,(__arg4),A1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(WORD,(__arg8),D5), \
        struct GfxBase *, (__GfxBase), 6, Graphics);\
})

#define BltTemplate(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __BltTemplate_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ClearEOL_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, ClearEOL, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 7, Graphics);\
})

#define ClearEOL(arg1) \
    __ClearEOL_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ClearScreen_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, ClearScreen, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 8, Graphics);\
})

#define ClearScreen(arg1) \
    __ClearScreen_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __TextLength_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(WORD, TextLength, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 9, Graphics);\
})

#define TextLength(arg1, arg2, arg3) \
    __TextLength_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __Text_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, Text, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 10, Graphics);\
})

#define Text(arg1, arg2, arg3) \
    __Text_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetFont_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetFont, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(struct TextFont *,(__arg2),A0), \
        struct GfxBase *, (__GfxBase), 11, Graphics);\
})

#define SetFont(arg1, arg2) \
    __SetFont_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __OpenFont_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(struct TextFont *, OpenFont, \
                  AROS_LCA(const struct TextAttr *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 12, Graphics);\
})

#define OpenFont(arg1) \
    __OpenFont_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __CloseFont_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, CloseFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 13, Graphics);\
})

#define CloseFont(arg1) \
    __CloseFont_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AskSoftStyle_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(ULONG, AskSoftStyle, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 14, Graphics);\
})

#define AskSoftStyle(arg1) \
    __AskSoftStyle_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetSoftStyle_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(ULONG, SetSoftStyle, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 15, Graphics);\
})

#define SetSoftStyle(arg1, arg2, arg3) \
    __SetSoftStyle_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AddBob_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, AddBob, \
                  AROS_LCA(struct Bob *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 16, Graphics);\
})

#define AddBob(arg1, arg2) \
    __AddBob_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AddVSprite_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, AddVSprite, \
                  AROS_LCA(struct VSprite *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 17, Graphics);\
})

#define AddVSprite(arg1, arg2) \
    __AddVSprite_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __DoCollision_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, DoCollision, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 18, Graphics);\
})

#define DoCollision(arg1) \
    __DoCollision_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __DrawGList_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, DrawGList, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(struct ViewPort *,(__arg2),A0), \
        struct GfxBase *, (__GfxBase), 19, Graphics);\
})

#define DrawGList(arg1, arg2) \
    __DrawGList_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitGels_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, InitGels, \
                  AROS_LCA(struct VSprite *,(__arg1),A0), \
                  AROS_LCA(struct VSprite *,(__arg2),A1), \
                  AROS_LCA(struct GelsInfo *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 20, Graphics);\
})

#define InitGels(arg1, arg2, arg3) \
    __InitGels_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitMasks_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, InitMasks, \
                  AROS_LCA(struct VSprite *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 21, Graphics);\
})

#define InitMasks(arg1) \
    __InitMasks_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __RemIBob_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, RemIBob, \
                  AROS_LCA(struct Bob *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
                  AROS_LCA(struct ViewPort *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 22, Graphics);\
})

#define RemIBob(arg1, arg2, arg3) \
    __RemIBob_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __RemVSprite_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, RemVSprite, \
                  AROS_LCA(struct VSprite *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 23, Graphics);\
})

#define RemVSprite(arg1) \
    __RemVSprite_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetCollision_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, SetCollision, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(VOID_FUNC,(__arg2),A0), \
                  AROS_LCA(struct GelsInfo *,(__arg3),A1), \
        struct GfxBase *, (__GfxBase), 24, Graphics);\
})

#define SetCollision(arg1, arg2, arg3) \
    __SetCollision_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SortGList_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, SortGList, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 25, Graphics);\
})

#define SortGList(arg1) \
    __SortGList_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AddAnimOb_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, AddAnimOb, \
                  AROS_LCA(struct AnimOb *,(__arg1),A0), \
                  AROS_LCA(struct AnimOb **,(__arg2),A1), \
                  AROS_LCA(struct RastPort *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 26, Graphics);\
})

#define AddAnimOb(arg1, arg2, arg3) \
    __AddAnimOb_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __Animate_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, Animate, \
                  AROS_LCA(struct AnimOb **,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 27, Graphics);\
})

#define Animate(arg1, arg2) \
    __Animate_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __GetGBuffers_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(BOOL, GetGBuffers, \
                  AROS_LCA(struct AnimOb *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
                  AROS_LCA(BOOL,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 28, Graphics);\
})

#define GetGBuffers(arg1, arg2, arg3) \
    __GetGBuffers_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitGMasks_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, InitGMasks, \
                  AROS_LCA(struct AnimOb *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 29, Graphics);\
})

#define InitGMasks(arg1) \
    __InitGMasks_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __DrawEllipse_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC5NR(void, DrawEllipse, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 30, Graphics);\
})

#define DrawEllipse(arg1, arg2, arg3, arg4, arg5) \
    __DrawEllipse_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AreaEllipse_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC5(ULONG, AreaEllipse, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 31, Graphics);\
})

#define AreaEllipse(arg1, arg2, arg3, arg4, arg5) \
    __AreaEllipse_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __LoadRGB4_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, LoadRGB4, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(UWORD *,(__arg2),A1), \
                  AROS_LCA(WORD,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 32, Graphics);\
})

#define LoadRGB4(arg1, arg2, arg3) \
    __LoadRGB4_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitRastPort_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, InitRastPort, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 33, Graphics);\
})

#define InitRastPort(arg1) \
    __InitRastPort_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitVPort_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, InitVPort, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 34, Graphics);\
})

#define InitVPort(arg1) \
    __InitVPort_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __MrgCop_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(ULONG, MrgCop, \
                  AROS_LCA(struct View *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 35, Graphics);\
})

#define MrgCop(arg1) \
    __MrgCop_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __MakeVPort_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(ULONG, MakeVPort, \
                  AROS_LCA(struct View *,(__arg1),A0), \
                  AROS_LCA(struct ViewPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 36, Graphics);\
})

#define MakeVPort(arg1, arg2) \
    __MakeVPort_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __LoadView_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, LoadView, \
                  AROS_LCA(struct View *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 37, Graphics);\
})

#define LoadView(arg1) \
    __LoadView_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __WaitBlit_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0NR(void, WaitBlit, \
        struct GfxBase *, (__GfxBase), 38, Graphics);\
})

#define WaitBlit() \
    __WaitBlit_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetRast_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetRast, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 39, Graphics);\
})

#define SetRast(arg1, arg2) \
    __SetRast_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __Move_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, Move, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 40, Graphics);\
})

#define Move(arg1, arg2, arg3) \
    __Move_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __Draw_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, Draw, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 41, Graphics);\
})

#define Draw(arg1, arg2, arg3) \
    __Draw_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AreaMove_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(ULONG, AreaMove, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 42, Graphics);\
})

#define AreaMove(arg1, arg2, arg3) \
    __AreaMove_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AreaDraw_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(ULONG, AreaDraw, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 43, Graphics);\
})

#define AreaDraw(arg1, arg2, arg3) \
    __AreaDraw_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AreaEnd_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(LONG, AreaEnd, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 44, Graphics);\
})

#define AreaEnd(arg1) \
    __AreaEnd_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __WaitTOF_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0NR(void, WaitTOF, \
        struct GfxBase *, (__GfxBase), 45, Graphics);\
})

#define WaitTOF() \
    __WaitTOF_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __QBlit_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, QBlit, \
                  AROS_LCA(struct bltnode *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 46, Graphics);\
})

#define QBlit(arg1) \
    __QBlit_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitArea_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, InitArea, \
                  AROS_LCA(struct AreaInfo *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
                  AROS_LCA(WORD,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 47, Graphics);\
})

#define InitArea(arg1, arg2, arg3) \
    __InitArea_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetRGB4_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC5NR(void, SetRGB4, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
                  AROS_LCA(ULONG,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 48, Graphics);\
})

#define SetRGB4(arg1, arg2, arg3, arg4, arg5) \
    __SetRGB4_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __QBSBlit_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, QBSBlit, \
                  AROS_LCA(struct bltnode *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 49, Graphics);\
})

#define QBSBlit(arg1) \
    __QBSBlit_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltClear_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, BltClear, \
                  AROS_LCA(void *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 50, Graphics);\
})

#define BltClear(arg1, arg2, arg3) \
    __BltClear_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __RectFill_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC5NR(void, RectFill, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 51, Graphics);\
})

#define RectFill(arg1, arg2, arg3, arg4, arg5) \
    __RectFill_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltPattern_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC7NR(void, BltPattern, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(PLANEPTR,(__arg2),A0), \
                  AROS_LCA(WORD,(__arg3),D0), \
                  AROS_LCA(WORD,(__arg4),D1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(ULONG,(__arg7),D4), \
        struct GfxBase *, (__GfxBase), 52, Graphics);\
})

#define BltPattern(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __BltPattern_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ReadPixel_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(LONG, ReadPixel, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 53, Graphics);\
})

#define ReadPixel(arg1, arg2, arg3) \
    __ReadPixel_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __WritePixel_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(LONG, WritePixel, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 54, Graphics);\
})

#define WritePixel(arg1, arg2, arg3) \
    __WritePixel_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __Flood_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC4(BOOL, Flood, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(WORD,(__arg3),D0), \
                  AROS_LCA(WORD,(__arg4),D1), \
        struct GfxBase *, (__GfxBase), 55, Graphics);\
})

#define Flood(arg1, arg2, arg3, arg4) \
    __Flood_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __PolyDraw_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, PolyDraw, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(WORD *,(__arg3),A0), \
        struct GfxBase *, (__GfxBase), 56, Graphics);\
})

#define PolyDraw(arg1, arg2, arg3) \
    __PolyDraw_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetAPen_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetAPen, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 57, Graphics);\
})

#define SetAPen(arg1, arg2) \
    __SetAPen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetBPen_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetBPen, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 58, Graphics);\
})

#define SetBPen(arg1, arg2) \
    __SetBPen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetDrMd_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetDrMd, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 59, Graphics);\
})

#define SetDrMd(arg1, arg2) \
    __SetDrMd_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitView_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, InitView, \
                  AROS_LCA(struct View *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 60, Graphics);\
})

#define InitView(arg1) \
    __InitView_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __CBump_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, CBump, \
                  AROS_LCA(struct UCopList *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 61, Graphics);\
})

#define CBump(arg1) \
    __CBump_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __CMove_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, CMove, \
                  AROS_LCA(struct UCopList *,(__arg1),A1), \
                  AROS_LCA(void *,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 62, Graphics);\
})

#define CMove(arg1, arg2, arg3) \
    __CMove_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __CWait_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, CWait, \
                  AROS_LCA(struct UCopList *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 63, Graphics);\
})

#define CWait(arg1, arg2, arg3) \
    __CWait_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __VBeamPos_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0(LONG, VBeamPos, \
        struct GfxBase *, (__GfxBase), 64, Graphics);\
})

#define VBeamPos() \
    __VBeamPos_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitBitMap_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC4NR(void, InitBitMap, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(BYTE,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
        struct GfxBase *, (__GfxBase), 65, Graphics);\
})

#define InitBitMap(arg1, arg2, arg3, arg4) \
    __InitBitMap_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ScrollRaster_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC7NR(void, ScrollRaster, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(WORD,(__arg6),D4), \
                  AROS_LCA(WORD,(__arg7),D5), \
        struct GfxBase *, (__GfxBase), 66, Graphics);\
})

#define ScrollRaster(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __ScrollRaster_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __WaitBOVP_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, WaitBOVP, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 67, Graphics);\
})

#define WaitBOVP(arg1) \
    __WaitBOVP_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __GetSprite_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(WORD, GetSprite, \
                  AROS_LCA(struct SimpleSprite *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 68, Graphics);\
})

#define GetSprite(arg1, arg2) \
    __GetSprite_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeSprite_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, FreeSprite, \
                  AROS_LCA(WORD,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 69, Graphics);\
})

#define FreeSprite(arg1) \
    __FreeSprite_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ChangeSprite_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, ChangeSprite, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(struct SimpleSprite *,(__arg2),A1), \
                  AROS_LCA(void *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 70, Graphics);\
})

#define ChangeSprite(arg1, arg2, arg3) \
    __ChangeSprite_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __MoveSprite_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC4NR(void, MoveSprite, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(struct SimpleSprite *,(__arg2),A1), \
                  AROS_LCA(WORD,(__arg3),D0), \
                  AROS_LCA(WORD,(__arg4),D1), \
        struct GfxBase *, (__GfxBase), 71, Graphics);\
})

#define MoveSprite(arg1, arg2, arg3, arg4) \
    __MoveSprite_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __LockLayerRom_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, LockLayerRom, \
                  AROS_LCA(struct Layer *,(__arg1),A5), \
        struct GfxBase *, (__GfxBase), 72, Graphics);\
})

#define LockLayerRom(arg1) \
    __LockLayerRom_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __UnlockLayerRom_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, UnlockLayerRom, \
                  AROS_LCA(struct Layer *,(__arg1),A5), \
        struct GfxBase *, (__GfxBase), 73, Graphics);\
})

#define UnlockLayerRom(arg1) \
    __UnlockLayerRom_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SyncSBitMap_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, SyncSBitMap, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 74, Graphics);\
})

#define SyncSBitMap(arg1) \
    __SyncSBitMap_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __CopySBitMap_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, CopySBitMap, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 75, Graphics);\
})

#define CopySBitMap(arg1) \
    __CopySBitMap_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __OwnBlitter_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0NR(void, OwnBlitter, \
        struct GfxBase *, (__GfxBase), 76, Graphics);\
})

#define OwnBlitter() \
    __OwnBlitter_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __DisownBlitter_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0NR(void, DisownBlitter, \
        struct GfxBase *, (__GfxBase), 77, Graphics);\
})

#define DisownBlitter() \
    __DisownBlitter_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __InitTmpRas_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(struct TmpRas *, InitTmpRas, \
                  AROS_LCA(struct TmpRas *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 78, Graphics);\
})

#define InitTmpRas(arg1, arg2, arg3) \
    __InitTmpRas_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AskFont_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, AskFont, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(struct TextAttr *,(__arg2),A0), \
        struct GfxBase *, (__GfxBase), 79, Graphics);\
})

#define AskFont(arg1, arg2) \
    __AskFont_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AddFont_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, AddFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 80, Graphics);\
})

#define AddFont(arg1) \
    __AddFont_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __RemFont_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, RemFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 81, Graphics);\
})

#define RemFont(arg1) \
    __RemFont_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AllocRaster_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(PLANEPTR, AllocRaster, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(UWORD,(__arg2),D1), \
        struct GfxBase *, (__GfxBase), 82, Graphics);\
})

#define AllocRaster(arg1, arg2) \
    __AllocRaster_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeRaster_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, FreeRaster, \
                  AROS_LCA(PLANEPTR,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 83, Graphics);\
})

#define FreeRaster(arg1, arg2, arg3) \
    __FreeRaster_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AndRectRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, AndRectRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 84, Graphics);\
})

#define AndRectRegion(arg1, arg2) \
    __AndRectRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __OrRectRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, OrRectRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 85, Graphics);\
})

#define OrRectRegion(arg1, arg2) \
    __OrRectRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __NewRegion_WB(__GfxBase) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC0(struct Region *, NewRegion, \
        struct GfxBase *, (__GfxBase), 86, Graphics);\
})

#define NewRegion() \
    __NewRegion_WB(__GRAPHICS_LIBBASE)

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ClearRectRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, ClearRectRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 87, Graphics);\
})

#define ClearRectRegion(arg1, arg2) \
    __ClearRectRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ClearRegion_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, ClearRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 88, Graphics);\
})

#define ClearRegion(arg1) \
    __ClearRegion_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __DisposeRegion_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, DisposeRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 89, Graphics);\
})

#define DisposeRegion(arg1) \
    __DisposeRegion_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeVPortCopLists_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, FreeVPortCopLists, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 90, Graphics);\
})

#define FreeVPortCopLists(arg1) \
    __FreeVPortCopLists_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeCopList_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, FreeCopList, \
                  AROS_LCA(struct CopList *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 91, Graphics);\
})

#define FreeCopList(arg1) \
    __FreeCopList_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ClipBlit_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC9NR(void, ClipBlit, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(struct RastPort *,(__arg4),A1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(WORD,(__arg8),D5), \
                  AROS_LCA(UBYTE,(__arg9),D6), \
        struct GfxBase *, (__GfxBase), 92, Graphics);\
})

#define ClipBlit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __ClipBlit_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __XorRectRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, XorRectRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 93, Graphics);\
})

#define XorRectRegion(arg1, arg2) \
    __XorRectRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeCprList_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, FreeCprList, \
                  AROS_LCA(struct cprlist *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 94, Graphics);\
})

#define FreeCprList(arg1) \
    __FreeCprList_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __GetColorMap_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(struct ColorMap *, GetColorMap, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 95, Graphics);\
})

#define GetColorMap(arg1) \
    __GetColorMap_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeColorMap_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, FreeColorMap, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 96, Graphics);\
})

#define FreeColorMap(arg1) \
    __FreeColorMap_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __GetRGB4_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(ULONG, GetRGB4, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 97, Graphics);\
})

#define GetRGB4(arg1, arg2) \
    __GetRGB4_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __ScrollVPort_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1NR(void, ScrollVPort, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 98, Graphics);\
})

#define ScrollVPort(arg1) \
    __ScrollVPort_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __UCopperListInit_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(struct CopList *, UCopperListInit, \
                  AROS_LCA(struct UCopList *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 99, Graphics);\
})

#define UCopperListInit(arg1, arg2) \
    __UCopperListInit_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __FreeGBuffers_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3NR(void, FreeGBuffers, \
                  AROS_LCA(struct AnimOb *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
                  AROS_LCA(BOOL,(__arg3),D0), \
        struct GfxBase *, (__GfxBase), 100, Graphics);\
})

#define FreeGBuffers(arg1, arg2, arg3) \
    __FreeGBuffers_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltBitMapRastPort_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC9NR(void, BltBitMapRastPort, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(struct RastPort *,(__arg4),A1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(WORD,(__arg8),D5), \
                  AROS_LCA(ULONG,(__arg9),D6), \
        struct GfxBase *, (__GfxBase), 101, Graphics);\
})

#define BltBitMapRastPort(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __BltBitMapRastPort_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __OrRegionRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, OrRegionRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 102, Graphics);\
})

#define OrRegionRegion(arg1, arg2) \
    __OrRegionRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __XorRegionRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, XorRegionRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 103, Graphics);\
})

#define XorRegionRegion(arg1, arg2) \
    __XorRegionRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AndRegionRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2(BOOL, AndRegionRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 104, Graphics);\
})

#define AndRegionRegion(arg1, arg2) \
    __AndRegionRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetRGB4CM_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC5NR(void, SetRGB4CM, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(UBYTE,(__arg3),D1), \
                  AROS_LCA(UBYTE,(__arg4),D2), \
                  AROS_LCA(UBYTE,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 105, Graphics);\
})

#define SetRGB4CM(arg1, arg2, arg3, arg4, arg5) \
    __SetRGB4CM_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __BltMaskBitMapRastPort_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9, __arg10) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC10NR(void, BltMaskBitMapRastPort, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(struct RastPort *,(__arg4),A1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(WORD,(__arg8),D5), \
                  AROS_LCA(ULONG,(__arg9),D6), \
                  AROS_LCA(PLANEPTR,(__arg10),A2), \
        struct GfxBase *, (__GfxBase), 106, Graphics);\
})

#define BltMaskBitMapRastPort(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    __BltMaskBitMapRastPort_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), (arg10))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AddDisplayDriverA_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC3(LONG, AddDisplayDriverA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(const struct TagItem *,(__arg2),A1), \
                  AROS_LCA(const struct TagItem *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 107, Graphics);\
})

#define AddDisplayDriverA(arg1, arg2, arg3) \
    __AddDisplayDriverA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define AddDisplayDriver(arg1, arg2, ...) \
({ \
    const IPTR AddDisplayDriverA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddDisplayDriverA((arg1), (arg2), (const struct TagItem *)(AddDisplayDriverA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __SetDisplayDriverCallback_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC2NR(void, SetDisplayDriverCallback, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 108, Graphics);\
})

#define SetDisplayDriverCallback(arg1, arg2) \
    __SetDisplayDriverCallback_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__)

#define __AttemptLockLayerRom_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,0)\
        AROS_LC1(BOOL, AttemptLockLayerRom, \
                  AROS_LCA(struct Layer *,(__arg1),A5), \
        struct GfxBase *, (__GfxBase), 109, Graphics);\
})

#define AttemptLockLayerRom(arg1) \
    __AttemptLockLayerRom_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (0 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GfxNew_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(struct ExtendedNode *, GfxNew, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 110, Graphics);\
})

#define GfxNew(arg1) \
    __GfxNew_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GfxFree_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1NR(void, GfxFree, \
                  AROS_LCA(struct ExtendedNode *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 111, Graphics);\
})

#define GfxFree(arg1) \
    __GfxFree_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GfxAssociate_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC2NR(void, GfxAssociate, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(struct ExtendedNode *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 112, Graphics);\
})

#define GfxAssociate(arg1, arg2) \
    __GfxAssociate_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __BitMapScale_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1NR(void, BitMapScale, \
                  AROS_LCA(struct BitScaleArgs *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 113, Graphics);\
})

#define BitMapScale(arg1) \
    __BitMapScale_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __ScalerDiv_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC3(UWORD, ScalerDiv, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(UWORD,(__arg2),D1), \
                  AROS_LCA(UWORD,(__arg3),D2), \
        struct GfxBase *, (__GfxBase), 114, Graphics);\
})

#define ScalerDiv(arg1, arg2, arg3) \
    __ScalerDiv_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __TextExtent_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC4NR(void, TextExtent, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(struct TextExtent *,(__arg4),A2), \
        struct GfxBase *, (__GfxBase), 115, Graphics);\
})

#define TextExtent(arg1, arg2, arg3, arg4) \
    __TextExtent_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __TextFit_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC8(ULONG, TextFit, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(struct TextExtent *,(__arg4),A2), \
                  AROS_LCA(struct TextExtent *,(__arg5),A3), \
                  AROS_LCA(LONG,(__arg6),D1), \
                  AROS_LCA(ULONG,(__arg7),D2), \
                  AROS_LCA(ULONG,(__arg8),D3), \
        struct GfxBase *, (__GfxBase), 116, Graphics);\
})

#define TextFit(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __TextFit_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GfxLookUp_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(struct ExtendedNode *, GfxLookUp, \
                  AROS_LCA(void *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 117, Graphics);\
})

#define GfxLookUp(arg1) \
    __GfxLookUp_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __VideoControl_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC2(ULONG, VideoControl, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 118, Graphics);\
})

#define VideoControl(arg1, arg2) \
    __VideoControl_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define VideoControlTags(arg1, ...) \
({ \
    const IPTR VideoControl_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    VideoControl((arg1), (struct TagItem *)(VideoControl_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __OpenMonitor_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC2(struct MonitorSpec *, OpenMonitor, \
                  AROS_LCA(STRPTR,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 119, Graphics);\
})

#define OpenMonitor(arg1, arg2) \
    __OpenMonitor_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __CloseMonitor_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(LONG, CloseMonitor, \
                  AROS_LCA(struct MonitorSpec *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 120, Graphics);\
})

#define CloseMonitor(arg1) \
    __CloseMonitor_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __FindDisplayInfo_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(DisplayInfoHandle, FindDisplayInfo, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 121, Graphics);\
})

#define FindDisplayInfo(arg1) \
    __FindDisplayInfo_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __NextDisplayInfo_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(ULONG, NextDisplayInfo, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 122, Graphics);\
})

#define NextDisplayInfo(arg1) \
    __NextDisplayInfo_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GetDisplayInfoData_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC5(ULONG, GetDisplayInfoData, \
                  AROS_LCA(DisplayInfoHandle,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(ULONG,(__arg4),D1), \
                  AROS_LCA(ULONG,(__arg5),D2), \
        struct GfxBase *, (__GfxBase), 126, Graphics);\
})

#define GetDisplayInfoData(arg1, arg2, arg3, arg4, arg5) \
    __GetDisplayInfoData_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __FontExtent_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC2NR(void, FontExtent, \
                  AROS_LCA(struct TextFont *,(__arg1),A0), \
                  AROS_LCA(struct TextExtent *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 127, Graphics);\
})

#define FontExtent(arg1, arg2) \
    __FontExtent_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __ReadPixelLine8_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC6(LONG, ReadPixelLine8, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(UBYTE *,(__arg5),A2), \
                  AROS_LCA(struct RastPort *,(__arg6),A1), \
        struct GfxBase *, (__GfxBase), 128, Graphics);\
})

#define ReadPixelLine8(arg1, arg2, arg3, arg4, arg5, arg6) \
    __ReadPixelLine8_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __WritePixelLine8_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC6(LONG, WritePixelLine8, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(UBYTE *,(__arg5),A2), \
                  AROS_LCA(struct RastPort *,(__arg6),A1), \
        struct GfxBase *, (__GfxBase), 129, Graphics);\
})

#define WritePixelLine8(arg1, arg2, arg3, arg4, arg5, arg6) \
    __WritePixelLine8_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __ReadPixelArray8_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC7(WORD, ReadPixelArray8, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(UBYTE *,(__arg6),A2), \
                  AROS_LCA(struct RastPort *,(__arg7),A1), \
        struct GfxBase *, (__GfxBase), 130, Graphics);\
})

#define ReadPixelArray8(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __ReadPixelArray8_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __WritePixelArray8_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC7(LONG, WritePixelArray8, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(UBYTE *,(__arg6),A2), \
                  AROS_LCA(struct RastPort *,(__arg7),A1), \
        struct GfxBase *, (__GfxBase), 131, Graphics);\
})

#define WritePixelArray8(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __WritePixelArray8_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __GetVPModeID_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(ULONG, GetVPModeID, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 132, Graphics);\
})

#define GetVPModeID(arg1) \
    __GetVPModeID_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __ModeNotAvailable_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1(ULONG, ModeNotAvailable, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 133, Graphics);\
})

#define ModeNotAvailable(arg1) \
    __ModeNotAvailable_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __WeighTAMatch_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC3(WORD, WeighTAMatch, \
                  AROS_LCA(const struct TextAttr *,(__arg1),A0), \
                  AROS_LCA(const struct TextAttr *,(__arg2),A1), \
                  AROS_LCA(struct TagItem *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 134, Graphics);\
})

#define WeighTAMatch(arg1, arg2, arg3) \
    __WeighTAMatch_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define WeighTAMatchTags(arg1, arg2, ...) \
({ \
    const IPTR WeighTAMatch_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    WeighTAMatch((arg1), (arg2), (struct TagItem *)(WeighTAMatch_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __EraseRect_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC5NR(void, EraseRect, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 135, Graphics);\
})

#define EraseRect(arg1, arg2, arg3, arg4, arg5) \
    __EraseRect_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __ExtendFont_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC2(ULONG, ExtendFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 136, Graphics);\
})

#define ExtendFont(arg1, arg2) \
    __ExtendFont_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ExtendFontTags(arg1, ...) \
({ \
    const IPTR ExtendFont_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ExtendFont((arg1), (struct TagItem *)(ExtendFont_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__)

#define __StripFont_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,36)\
        AROS_LC1NR(void, StripFont, \
                  AROS_LCA(struct TextFont *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 137, Graphics);\
})

#define StripFont(arg1) \
    __StripFont_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (36 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __CalcIVG_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(UWORD, CalcIVG, \
                  AROS_LCA(struct View *,(__arg1),A0), \
                  AROS_LCA(struct ViewPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 138, Graphics);\
})

#define CalcIVG(arg1, arg2) \
    __CalcIVG_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __AttachPalExtra_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(LONG, AttachPalExtra, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(struct ViewPort *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 139, Graphics);\
})

#define AttachPalExtra(arg1, arg2) \
    __AttachPalExtra_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ObtainBestPenA_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC5(LONG, ObtainBestPenA, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
                  AROS_LCA(ULONG,(__arg3),D2), \
                  AROS_LCA(ULONG,(__arg4),D3), \
                  AROS_LCA(struct TagItem *,(__arg5),A1), \
        struct GfxBase *, (__GfxBase), 140, Graphics);\
})

#define ObtainBestPenA(arg1, arg2, arg3, arg4, arg5) \
    __ObtainBestPenA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ObtainBestPen(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR ObtainBestPenA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ObtainBestPenA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(ObtainBestPenA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetRGB32_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC5NR(void, SetRGB32, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
                  AROS_LCA(ULONG,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 142, Graphics);\
})

#define SetRGB32(arg1, arg2, arg3, arg4, arg5) \
    __SetRGB32_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetAPen_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, GetAPen, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 143, Graphics);\
})

#define GetAPen(arg1) \
    __GetAPen_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetBPen_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, GetBPen, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 144, Graphics);\
})

#define GetBPen(arg1) \
    __GetBPen_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetDrMd_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, GetDrMd, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 145, Graphics);\
})

#define GetDrMd(arg1) \
    __GetDrMd_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetOutlinePen_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, GetOutlinePen, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 146, Graphics);\
})

#define GetOutlinePen(arg1) \
    __GetOutlinePen_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __LoadRGB32_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2NR(void, LoadRGB32, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(const ULONG *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 147, Graphics);\
})

#define LoadRGB32(arg1, arg2) \
    __LoadRGB32_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetChipRev_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, SetChipRev, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct GfxBase *, (__GfxBase), 148, Graphics);\
})

#define SetChipRev(arg1) \
    __SetChipRev_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetABPenDrMd_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC4NR(void, SetABPenDrMd, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
        struct GfxBase *, (__GfxBase), 149, Graphics);\
})

#define SetABPenDrMd(arg1, arg2, arg3, arg4) \
    __SetABPenDrMd_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetRGB32_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC4NR(void, GetRGB32, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG *,(__arg4),A1), \
        struct GfxBase *, (__GfxBase), 150, Graphics);\
})

#define GetRGB32(arg1, arg2, arg3, arg4) \
    __GetRGB32_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __AllocBitMap_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC5(struct BitMap *, AllocBitMap, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(UWORD,(__arg2),D1), \
                  AROS_LCA(ULONG,(__arg3),D2), \
                  AROS_LCA(ULONG,(__arg4),D3), \
                  AROS_LCA(struct BitMap *,(__arg5),A0), \
        struct GfxBase *, (__GfxBase), 153, Graphics);\
})

#define AllocBitMap(arg1, arg2, arg3, arg4, arg5) \
    __AllocBitMap_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __FreeBitMap_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1NR(void, FreeBitMap, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 154, Graphics);\
})

#define FreeBitMap(arg1) \
    __FreeBitMap_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetExtSpriteA_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(LONG, GetExtSpriteA, \
                  AROS_LCA(struct ExtSprite *,(__arg1),A2), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 155, Graphics);\
})

#define GetExtSpriteA(arg1, arg2) \
    __GetExtSpriteA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define GetExtSprite(arg1, ...) \
({ \
    const IPTR GetExtSpriteA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetExtSpriteA((arg1), (struct TagItem *)(GetExtSpriteA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __CoerceMode_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC3(ULONG, CoerceMode, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 156, Graphics);\
})

#define CoerceMode(arg1, arg2, arg3) \
    __CoerceMode_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ChangeVPBitMap_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC3NR(void, ChangeVPBitMap, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(struct DBufInfo *,(__arg3),A2), \
        struct GfxBase *, (__GfxBase), 157, Graphics);\
})

#define ChangeVPBitMap(arg1, arg2, arg3) \
    __ChangeVPBitMap_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ReleasePen_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2NR(void, ReleasePen, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 158, Graphics);\
})

#define ReleasePen(arg1, arg2) \
    __ReleasePen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ObtainPen_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC6(LONG, ObtainPen, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
                  AROS_LCA(ULONG,(__arg5),D3), \
                  AROS_LCA(ULONG,(__arg6),D4), \
        struct GfxBase *, (__GfxBase), 159, Graphics);\
})

#define ObtainPen(arg1, arg2, arg3, arg4, arg5, arg6) \
    __ObtainPen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetBitMapAttr_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(IPTR, GetBitMapAttr, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct GfxBase *, (__GfxBase), 160, Graphics);\
})

#define GetBitMapAttr(arg1, arg2) \
    __GetBitMapAttr_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __AllocDBufInfo_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(struct DBufInfo *, AllocDBufInfo, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 161, Graphics);\
})

#define AllocDBufInfo(arg1) \
    __AllocDBufInfo_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __FreeDBufInfo_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1NR(void, FreeDBufInfo, \
                  AROS_LCA(struct DBufInfo *,(__arg1),A1), \
        struct GfxBase *, (__GfxBase), 162, Graphics);\
})

#define FreeDBufInfo(arg1) \
    __FreeDBufInfo_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetOutlinePen_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(ULONG, SetOutlinePen, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 163, Graphics);\
})

#define SetOutlinePen(arg1, arg2) \
    __SetOutlinePen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetWriteMask_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(ULONG, SetWriteMask, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 164, Graphics);\
})

#define SetWriteMask(arg1, arg2) \
    __SetWriteMask_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetMaxPen_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2NR(void, SetMaxPen, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct GfxBase *, (__GfxBase), 165, Graphics);\
})

#define SetMaxPen(arg1, arg2) \
    __SetMaxPen_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetRGB32CM_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC5NR(void, SetRGB32CM, \
                  AROS_LCA(struct ColorMap *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D2), \
                  AROS_LCA(ULONG,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 166, Graphics);\
})

#define SetRGB32CM(arg1, arg2, arg3, arg4, arg5) \
    __SetRGB32CM_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ScrollRasterBF_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC7NR(void, ScrollRasterBF, \
                  AROS_LCA(struct RastPort *,(__arg1),A1), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(WORD,(__arg6),D4), \
                  AROS_LCA(WORD,(__arg7),D5), \
        struct GfxBase *, (__GfxBase), 167, Graphics);\
})

#define ScrollRasterBF(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __ScrollRasterBF_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __FindColor_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC5(ULONG, FindColor, \
                  AROS_LCA(struct ColorMap *,(__arg1),A3), \
                  AROS_LCA(ULONG,(__arg2),D1), \
                  AROS_LCA(ULONG,(__arg3),D2), \
                  AROS_LCA(ULONG,(__arg4),D3), \
                  AROS_LCA(ULONG,(__arg5),D4), \
        struct GfxBase *, (__GfxBase), 168, Graphics);\
})

#define FindColor(arg1, arg2, arg3, arg4, arg5) \
    __FindColor_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __AllocSpriteDataA_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2(struct ExtSprite *, AllocSpriteDataA, \
                  AROS_LCA(struct BitMap *,(__arg1),A2), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 170, Graphics);\
})

#define AllocSpriteDataA(arg1, arg2) \
    __AllocSpriteDataA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define AllocSpriteData(arg1, ...) \
({ \
    const IPTR AllocSpriteDataA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocSpriteDataA((arg1), (struct TagItem *)(AllocSpriteDataA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __ChangeExtSpriteA_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC4(LONG, ChangeExtSpriteA, \
                  AROS_LCA(struct ViewPort *,(__arg1),A0), \
                  AROS_LCA(struct ExtSprite *,(__arg2),A1), \
                  AROS_LCA(struct ExtSprite *,(__arg3),A2), \
                  AROS_LCA(struct TagItem *,(__arg4),A3), \
        struct GfxBase *, (__GfxBase), 171, Graphics);\
})

#define ChangeExtSpriteA(arg1, arg2, arg3, arg4) \
    __ChangeExtSpriteA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define ChangeExtSprite(arg1, arg2, arg3, ...) \
({ \
    const IPTR ChangeExtSpriteA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ChangeExtSpriteA((arg1), (arg2), (arg3), (struct TagItem *)(ChangeExtSpriteA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __FreeSpriteData_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1NR(void, FreeSpriteData, \
                  AROS_LCA(struct ExtSprite *,(__arg1),A2), \
        struct GfxBase *, (__GfxBase), 172, Graphics);\
})

#define FreeSpriteData(arg1) \
    __FreeSpriteData_WB(__GRAPHICS_LIBBASE, (arg1))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __SetRPAttrsA_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2NR(void, SetRPAttrsA, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 173, Graphics);\
})

#define SetRPAttrsA(arg1, arg2) \
    __SetRPAttrsA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define SetRPAttrs(arg1, ...) \
({ \
    const IPTR SetRPAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetRPAttrsA((arg1), (struct TagItem *)(SetRPAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __GetRPAttrsA_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC2NR(void, GetRPAttrsA, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 174, Graphics);\
})

#define GetRPAttrsA(arg1, arg2) \
    __GetRPAttrsA_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define GetRPAttrs(arg1, ...) \
({ \
    const IPTR GetRPAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetRPAttrsA((arg1), (struct TagItem *)(GetRPAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__)

#define __BestModeIDA_WB(__GfxBase, __arg1) ({\
        AROS_LIBREQ(GfxBase,39)\
        AROS_LC1(ULONG, BestModeIDA, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct GfxBase *, (__GfxBase), 175, Graphics);\
})

#define BestModeIDA(arg1) \
    __BestModeIDA_WB(__GRAPHICS_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(GRAPHICS_NO_INLINE_STDARG)
#define BestModeID(...) \
({ \
    const IPTR BestModeIDA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    BestModeIDA((struct TagItem *)(BestModeIDA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__GRAPHICS_LIBAPI__) || (39 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __WriteChunkyPixels_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC7NR(void, WriteChunkyPixels, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(UBYTE *,(__arg6),A2), \
                  AROS_LCA(LONG,(__arg7),D4), \
        struct GfxBase *, (__GfxBase), 176, Graphics);\
})

#define WriteChunkyPixels(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __WriteChunkyPixels_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __SetRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(BOOL, SetRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 181, Graphics);\
})

#define SetRegion(arg1, arg2) \
    __SetRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __ClearRegionRegion_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(BOOL, ClearRegionRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 182, Graphics);\
})

#define ClearRegionRegion(arg1, arg2) \
    __ClearRegionRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __AreRegionsEqual_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(BOOL, AreRegionsEqual, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 183, Graphics);\
})

#define AreRegionsEqual(arg1, arg2) \
    __AreRegionsEqual_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __IsPointInRegion_WB(__GfxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC3(BOOL, IsPointInRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
        struct GfxBase *, (__GfxBase), 184, Graphics);\
})

#define IsPointInRegion(arg1, arg2, arg3) \
    __IsPointInRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __ScrollRegion_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC4(BOOL, ScrollRegion, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
                  AROS_LCA(WORD,(__arg3),D0), \
                  AROS_LCA(WORD,(__arg4),D1), \
        struct GfxBase *, (__GfxBase), 185, Graphics);\
})

#define ScrollRegion(arg1, arg2, arg3, arg4) \
    __ScrollRegion_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __AndRectRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, AndRectRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 186, Graphics);\
})

#define AndRectRegionND(arg1, arg2) \
    __AndRectRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __AndRegionRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, AndRegionRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 187, Graphics);\
})

#define AndRegionRegionND(arg1, arg2) \
    __AndRegionRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __OrRectRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, OrRectRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 188, Graphics);\
})

#define OrRectRegionND(arg1, arg2) \
    __OrRectRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __OrRegionRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, OrRegionRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 189, Graphics);\
})

#define OrRegionRegionND(arg1, arg2) \
    __OrRegionRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __XorRectRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, XorRectRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 190, Graphics);\
})

#define XorRectRegionND(arg1, arg2) \
    __XorRectRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __XorRegionRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, XorRegionRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 191, Graphics);\
})

#define XorRegionRegionND(arg1, arg2) \
    __XorRegionRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __ClearRectRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, ClearRectRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Rectangle *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 192, Graphics);\
})

#define ClearRectRegionND(arg1, arg2) \
    __ClearRectRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __ClearRegionRegionND_WB(__GfxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC2(struct Region *, ClearRegionRegionND, \
                  AROS_LCA(struct Region *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct GfxBase *, (__GfxBase), 193, Graphics);\
})

#define ClearRegionRegionND(arg1, arg2) \
    __ClearRegionRegionND_WB(__GRAPHICS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __WritePixels8_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC9(LONG, WritePixels8, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(WORD,(__arg4),D1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(WORD,(__arg7),D4), \
                  AROS_LCA(APTR,(__arg8),A2), \
                  AROS_LCA(BOOL,(__arg9),D5), \
        struct GfxBase *, (__GfxBase), 197, Graphics);\
})

#define WritePixels8(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __WritePixels8_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __FillRectPenDrMd_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC8(LONG, FillRectPenDrMd, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(WORD,(__arg4),D2), \
                  AROS_LCA(WORD,(__arg5),D3), \
                  AROS_LCA(ULONG,(__arg6),D4), \
                  AROS_LCA(IPTR,(__arg7),D5), \
                  AROS_LCA(BOOL,(__arg8),D6), \
        struct GfxBase *, (__GfxBase), 198, Graphics);\
})

#define FillRectPenDrMd(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __FillRectPenDrMd_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __DoRenderFunc_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC6(LONG, DoRenderFunc, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(Point *,(__arg2),A1), \
                  AROS_LCA(struct Rectangle *,(__arg3),A2), \
                  AROS_LCA(APTR,(__arg4),A3), \
                  AROS_LCA(APTR,(__arg5),A4), \
                  AROS_LCA(BOOL,(__arg6),D0), \
        struct GfxBase *, (__GfxBase), 199, Graphics);\
})

#define DoRenderFunc(arg1, arg2, arg3, arg4, arg5, arg6) \
    __DoRenderFunc_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __DoPixelFunc_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC6(LONG, DoPixelFunc, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(WORD,(__arg2),D0), \
                  AROS_LCA(WORD,(__arg3),D1), \
                  AROS_LCA(APTR,(__arg4),A1), \
                  AROS_LCA(APTR,(__arg5),A2), \
                  AROS_LCA(BOOL,(__arg6),D2), \
        struct GfxBase *, (__GfxBase), 200, Graphics);\
})

#define DoPixelFunc(arg1, arg2, arg3, arg4, arg5, arg6) \
    __DoPixelFunc_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

#if !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__)

#define __UpdateBitMap_WB(__GfxBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(GfxBase,40)\
        AROS_LC5NR(void, UpdateBitMap, \
                  AROS_LCA(struct BitMap *,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
                  AROS_LCA(UWORD,(__arg3),D1), \
                  AROS_LCA(UWORD,(__arg4),D2), \
                  AROS_LCA(UWORD,(__arg5),D3), \
        struct GfxBase *, (__GfxBase), 201, Graphics);\
})

#define UpdateBitMap(arg1, arg2, arg3, arg4, arg5) \
    __UpdateBitMap_WB(__GRAPHICS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__GRAPHICS_LIBAPI__) || (40 <= __GRAPHICS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_GRAPHICS_H*/
