#ifndef DEFINES_LAYERS_H
#define DEFINES_LAYERS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/hyperlayers/layers.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for layers
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__LAYERS_LIBBASE)
#    define __LAYERS_LIBBASE LayersBase
#endif

__BEGIN_DECLS


#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __InitLayers_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, InitLayers, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 5, Layers);\
})

#define InitLayers(arg1) \
    __InitLayers_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __CreateUpfrontLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC8(struct Layer *, CreateUpfrontLayer, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct BitMap *,(__arg8),A2), \
        struct Library *, (__LayersBase), 6, Layers);\
})

#define CreateUpfrontLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __CreateUpfrontLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __CreateBehindLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC8(struct Layer *, CreateBehindLayer, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct BitMap *,(__arg8),A2), \
        struct Library *, (__LayersBase), 7, Layers);\
})

#define CreateBehindLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __CreateBehindLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __UpfrontLayer_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(LONG, UpfrontLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
        struct Library *, (__LayersBase), 8, Layers);\
})

#define UpfrontLayer(arg1, arg2) \
    __UpfrontLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __BehindLayer_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(LONG, BehindLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
        struct Library *, (__LayersBase), 9, Layers);\
})

#define BehindLayer(arg1, arg2) \
    __BehindLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __MoveLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC4(LONG, MoveLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
        struct Library *, (__LayersBase), 10, Layers);\
})

#define MoveLayer(arg1, arg2, arg3, arg4) \
    __MoveLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __SizeLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC4(LONG, SizeLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
        struct Library *, (__LayersBase), 11, Layers);\
})

#define SizeLayer(arg1, arg2, arg3, arg4) \
    __SizeLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __ScrollLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC4NR(void, ScrollLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
        struct Library *, (__LayersBase), 12, Layers);\
})

#define ScrollLayer(arg1, arg2, arg3, arg4) \
    __ScrollLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __BeginUpdate_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1(LONG, BeginUpdate, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
        struct Library *, (__LayersBase), 13, Layers);\
})

#define BeginUpdate(arg1) \
    __BeginUpdate_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __EndUpdate_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2NR(void, EndUpdate, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(UWORD,(__arg2),D0), \
        struct Library *, (__LayersBase), 14, Layers);\
})

#define EndUpdate(arg1, arg2) \
    __EndUpdate_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __DeleteLayer_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(LONG, DeleteLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
        struct Library *, (__LayersBase), 15, Layers);\
})

#define DeleteLayer(arg1, arg2) \
    __DeleteLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __LockLayer_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2NR(void, LockLayer, \
                  AROS_LCA(LONG,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
        struct Library *, (__LayersBase), 16, Layers);\
})

#define LockLayer(arg1, arg2) \
    __LockLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __UnlockLayer_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, UnlockLayer, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
        struct Library *, (__LayersBase), 17, Layers);\
})

#define UnlockLayer(arg1) \
    __UnlockLayer_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __LockLayers_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, LockLayers, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 18, Layers);\
})

#define LockLayers(arg1) \
    __LockLayers_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __UnlockLayers_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, UnlockLayers, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 19, Layers);\
})

#define UnlockLayers(arg1) \
    __UnlockLayers_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __LockLayerInfo_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, LockLayerInfo, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 20, Layers);\
})

#define LockLayerInfo(arg1) \
    __LockLayerInfo_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __SwapBitsRastPortClipRect_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2NR(void, SwapBitsRastPortClipRect, \
                  AROS_LCA(struct RastPort *,(__arg1),A0), \
                  AROS_LCA(struct ClipRect *,(__arg2),A1), \
        struct Library *, (__LayersBase), 21, Layers);\
})

#define SwapBitsRastPortClipRect(arg1, arg2) \
    __SwapBitsRastPortClipRect_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __WhichLayer_WB(__LayersBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC3(struct Layer *, WhichLayer, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(LONG,(__arg3),D1), \
        struct Library *, (__LayersBase), 22, Layers);\
})

#define WhichLayer(arg1, arg2, arg3) \
    __WhichLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __UnlockLayerInfo_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, UnlockLayerInfo, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 23, Layers);\
})

#define UnlockLayerInfo(arg1) \
    __UnlockLayerInfo_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __NewLayerInfo_WB(__LayersBase) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC0(struct Layer_Info *, NewLayerInfo, \
        struct Library *, (__LayersBase), 24, Layers);\
})

#define NewLayerInfo() \
    __NewLayerInfo_WB(__LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __DisposeLayerInfo_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, DisposeLayerInfo, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 25, Layers);\
})

#define DisposeLayerInfo(arg1) \
    __DisposeLayerInfo_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __FattenLayerInfo_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1(LONG, FattenLayerInfo, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 26, Layers);\
})

#define FattenLayerInfo(arg1) \
    __FattenLayerInfo_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __ThinLayerInfo_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC1NR(void, ThinLayerInfo, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
        struct Library *, (__LayersBase), 27, Layers);\
})

#define ThinLayerInfo(arg1) \
    __ThinLayerInfo_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __MoveLayerInFrontOf_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(LONG, MoveLayerInFrontOf, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct Layer *,(__arg2),A1), \
        struct Library *, (__LayersBase), 28, Layers);\
})

#define MoveLayerInFrontOf(arg1, arg2) \
    __MoveLayerInFrontOf_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __InstallClipRegion_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(struct Region *, InstallClipRegion, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
        struct Library *, (__LayersBase), 29, Layers);\
})

#define InstallClipRegion(arg1, arg2) \
    __InstallClipRegion_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __MoveSizeLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC5(LONG, MoveSizeLayer, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(LONG,(__arg3),D1), \
                  AROS_LCA(LONG,(__arg4),D2), \
                  AROS_LCA(LONG,(__arg5),D3), \
        struct Library *, (__LayersBase), 30, Layers);\
})

#define MoveSizeLayer(arg1, arg2, arg3, arg4, arg5) \
    __MoveSizeLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __CreateUpfrontHookLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC9(struct Layer *, CreateUpfrontHookLayer, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct Hook *,(__arg8),A3), \
                  AROS_LCA(struct BitMap *,(__arg9),A2), \
        struct Library *, (__LayersBase), 31, Layers);\
})

#define CreateUpfrontHookLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __CreateUpfrontHookLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __CreateBehindHookLayer_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8, __arg9) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC9(struct Layer *, CreateBehindHookLayer, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct Hook *,(__arg8),A3), \
                  AROS_LCA(struct BitMap *,(__arg9),A2), \
        struct Library *, (__LayersBase), 32, Layers);\
})

#define CreateBehindHookLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __CreateBehindHookLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

#define __InstallLayerHook_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,0)\
        AROS_LC2(struct Hook *, InstallLayerHook, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct Hook *,(__arg2),A1), \
        struct Library *, (__LayersBase), 33, Layers);\
})

#define InstallLayerHook(arg1, arg2) \
    __InstallLayerHook_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

#define __InstallLayerInfoHook_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,39)\
        AROS_LC2(struct Hook *, InstallLayerInfoHook, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct Hook *,(__arg2),A1), \
        struct Library *, (__LayersBase), 34, Layers);\
})

#define InstallLayerInfoHook(arg1, arg2) \
    __InstallLayerInfoHook_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

#define __SortLayerCR_WB(__LayersBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(LayersBase,39)\
        AROS_LC3NR(void, SortLayerCR, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(LONG,(__arg3),D1), \
        struct Library *, (__LayersBase), 35, Layers);\
})

#define SortLayerCR(arg1, arg2, arg3) \
    __SortLayerCR_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

#define __DoHookClipRects_WB(__LayersBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(LayersBase,39)\
        AROS_LC3NR(void, DoHookClipRects, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
                  AROS_LCA(struct RastPort *,(__arg2),A1), \
                  AROS_LCA(struct Rectangle *,(__arg3),A2), \
        struct Library *, (__LayersBase), 36, Layers);\
})

#define DoHookClipRects(arg1, arg2, arg3) \
    __DoHookClipRects_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__)

#define __ChangeLayerShape_WB(__LayersBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(LayersBase,45)\
        AROS_LC3(struct Region *, ChangeLayerShape, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
                  AROS_LCA(struct Hook *,(__arg3),A2), \
        struct Library *, (__LayersBase), 37, Layers);\
})

#define ChangeLayerShape(arg1, arg2, arg3) \
    __ChangeLayerShape_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__)

#define __ScaleLayer_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,45)\
        AROS_LC2(ULONG, ScaleLayer, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__LayersBase), 38, Layers);\
})

#define ScaleLayer(arg1, arg2) \
    __ScaleLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define ScaleLayerTags(arg1, ...) \
({ \
    const IPTR ScaleLayer_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ScaleLayer((arg1), (struct TagItem *)(ScaleLayer_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __CreateUpfrontLayerTagList_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC8(struct Layer *, CreateUpfrontLayerTagList, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct TagItem *,(__arg8),A2), \
        struct Library *, (__LayersBase), 39, Layers);\
})

#define CreateUpfrontLayerTagList(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __CreateUpfrontLayerTagList_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define CreateUpfrontLayerTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR CreateUpfrontLayerTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateUpfrontLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(CreateUpfrontLayerTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __CreateBehindLayerTagList_WB(__LayersBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC8(struct Layer *, CreateBehindLayerTagList, \
                  AROS_LCA(struct Layer_Info *,(__arg1),A0), \
                  AROS_LCA(struct BitMap *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
                  AROS_LCA(LONG,(__arg4),D1), \
                  AROS_LCA(LONG,(__arg5),D2), \
                  AROS_LCA(LONG,(__arg6),D3), \
                  AROS_LCA(LONG,(__arg7),D4), \
                  AROS_LCA(struct TagItem *,(__arg8),A2), \
        struct Library *, (__LayersBase), 40, Layers);\
})

#define CreateBehindLayerTagList(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __CreateBehindLayerTagList_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define CreateBehindLayerTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR CreateBehindLayerTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateBehindLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(CreateBehindLayerTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __ChangeLayerVisibility_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC2(LONG, ChangeLayerVisibility, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
        struct Library *, (__LayersBase), 41, Layers);\
})

#define ChangeLayerVisibility(arg1, arg2) \
    __ChangeLayerVisibility_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __IsLayerVisible_WB(__LayersBase, __arg1) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC1(LONG, IsLayerVisible, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
        struct Library *, (__LayersBase), 43, Layers);\
})

#define IsLayerVisible(arg1) \
    __IsLayerVisible_WB(__LAYERS_LIBBASE, (arg1))

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __IsLayerHiddenBySibling_WB(__LayersBase, __arg1, __arg2) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC2(BOOL, IsLayerHiddenBySibling, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(BOOL,(__arg2),D0), \
        struct Library *, (__LayersBase), 44, Layers);\
})

#define IsLayerHiddenBySibling(arg1, arg2) \
    __IsLayerHiddenBySibling_WB(__LAYERS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

#define __CollectPixelsLayer_WB(__LayersBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(LayersBase,50)\
        AROS_LC3NR(void, CollectPixelsLayer, \
                  AROS_LCA(struct Layer *,(__arg1),A0), \
                  AROS_LCA(struct Region *,(__arg2),A1), \
                  AROS_LCA(struct Hook *,(__arg3),A2), \
        struct Library *, (__LayersBase), 45, Layers);\
})

#define CollectPixelsLayer(arg1, arg2, arg3) \
    __CollectPixelsLayer_WB(__LAYERS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_LAYERS_H*/
