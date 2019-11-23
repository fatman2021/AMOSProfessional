#ifndef INLINE_LAYERS_H
#define INLINE_LAYERS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/hyperlayers/layers.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for layers
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__LAYERS_LIBBASE)
#    define __LAYERS_LIBBASE LayersBase
#endif


#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_InitLayers(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, InitLayers,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 5, Layers    );
}

#define InitLayers(arg1) \
    __inline_Layers_InitLayers((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateUpfrontLayer(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct BitMap * __arg8, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC8(struct Layer *, CreateUpfrontLayer,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct BitMap *,(__arg8),A2),
        struct Library *, (__LayersBase), 6, Layers    );
}

#define CreateUpfrontLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Layers_CreateUpfrontLayer((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateBehindLayer(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct BitMap * __arg8, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC8(struct Layer *, CreateBehindLayer,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct BitMap *,(__arg8),A2),
        struct Library *, (__LayersBase), 7, Layers    );
}

#define CreateBehindLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Layers_CreateBehindLayer((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_UpfrontLayer(LONG __arg1, struct Layer * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(LONG, UpfrontLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        struct Library *, (__LayersBase), 8, Layers    );
}

#define UpfrontLayer(arg1, arg2) \
    __inline_Layers_UpfrontLayer((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_BehindLayer(LONG __arg1, struct Layer * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(LONG, BehindLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        struct Library *, (__LayersBase), 9, Layers    );
}

#define BehindLayer(arg1, arg2) \
    __inline_Layers_BehindLayer((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_MoveLayer(LONG __arg1, struct Layer * __arg2, LONG __arg3, LONG __arg4, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC4(LONG, MoveLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct Library *, (__LayersBase), 10, Layers    );
}

#define MoveLayer(arg1, arg2, arg3, arg4) \
    __inline_Layers_MoveLayer((arg1), (arg2), (arg3), (arg4), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_SizeLayer(LONG __arg1, struct Layer * __arg2, LONG __arg3, LONG __arg4, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC4(LONG, SizeLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct Library *, (__LayersBase), 11, Layers    );
}

#define SizeLayer(arg1, arg2, arg3, arg4) \
    __inline_Layers_SizeLayer((arg1), (arg2), (arg3), (arg4), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_ScrollLayer(LONG __arg1, struct Layer * __arg2, LONG __arg3, LONG __arg4, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC4NR(void, ScrollLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct Library *, (__LayersBase), 12, Layers    );
}

#define ScrollLayer(arg1, arg2, arg3, arg4) \
    __inline_Layers_ScrollLayer((arg1), (arg2), (arg3), (arg4), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_BeginUpdate(struct Layer * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC1(LONG, BeginUpdate,
        AROS_LCA(struct Layer *,(__arg1),A0),
        struct Library *, (__LayersBase), 13, Layers    );
}

#define BeginUpdate(arg1) \
    __inline_Layers_BeginUpdate((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_EndUpdate(struct Layer * __arg1, UWORD __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC2NR(void, EndUpdate,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        struct Library *, (__LayersBase), 14, Layers    );
}

#define EndUpdate(arg1, arg2) \
    __inline_Layers_EndUpdate((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_DeleteLayer(LONG __arg1, struct Layer * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(LONG, DeleteLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        struct Library *, (__LayersBase), 15, Layers    );
}

#define DeleteLayer(arg1, arg2) \
    __inline_Layers_DeleteLayer((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_LockLayer(LONG __arg1, struct Layer * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC2NR(void, LockLayer,
        AROS_LCA(LONG,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        struct Library *, (__LayersBase), 16, Layers    );
}

#define LockLayer(arg1, arg2) \
    __inline_Layers_LockLayer((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_UnlockLayer(struct Layer * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, UnlockLayer,
        AROS_LCA(struct Layer *,(__arg1),A0),
        struct Library *, (__LayersBase), 17, Layers    );
}

#define UnlockLayer(arg1) \
    __inline_Layers_UnlockLayer((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_LockLayers(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, LockLayers,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 18, Layers    );
}

#define LockLayers(arg1) \
    __inline_Layers_LockLayers((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_UnlockLayers(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, UnlockLayers,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 19, Layers    );
}

#define UnlockLayers(arg1) \
    __inline_Layers_UnlockLayers((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_LockLayerInfo(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, LockLayerInfo,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 20, Layers    );
}

#define LockLayerInfo(arg1) \
    __inline_Layers_LockLayerInfo((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_SwapBitsRastPortClipRect(struct RastPort * __arg1, struct ClipRect * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC2NR(void, SwapBitsRastPortClipRect,
        AROS_LCA(struct RastPort *,(__arg1),A0),
        AROS_LCA(struct ClipRect *,(__arg2),A1),
        struct Library *, (__LayersBase), 21, Layers    );
}

#define SwapBitsRastPortClipRect(arg1, arg2) \
    __inline_Layers_SwapBitsRastPortClipRect((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_WhichLayer(struct Layer_Info * __arg1, LONG __arg2, LONG __arg3, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC3(struct Layer *, WhichLayer,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__LayersBase), 22, Layers    );
}

#define WhichLayer(arg1, arg2, arg3) \
    __inline_Layers_WhichLayer((arg1), (arg2), (arg3), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_UnlockLayerInfo(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, UnlockLayerInfo,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 23, Layers    );
}

#define UnlockLayerInfo(arg1) \
    __inline_Layers_UnlockLayerInfo((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer_Info * __inline_Layers_NewLayerInfo(APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC0(struct Layer_Info *, NewLayerInfo,
        struct Library *, (__LayersBase), 24, Layers    );
}

#define NewLayerInfo() \
    __inline_Layers_NewLayerInfo(__LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_DisposeLayerInfo(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, DisposeLayerInfo,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 25, Layers    );
}

#define DisposeLayerInfo(arg1) \
    __inline_Layers_DisposeLayerInfo((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_FattenLayerInfo(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC1(LONG, FattenLayerInfo,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 26, Layers    );
}

#define FattenLayerInfo(arg1) \
    __inline_Layers_FattenLayerInfo((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_ThinLayerInfo(struct Layer_Info * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    AROS_LC1NR(void, ThinLayerInfo,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        struct Library *, (__LayersBase), 27, Layers    );
}

#define ThinLayerInfo(arg1) \
    __inline_Layers_ThinLayerInfo((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_MoveLayerInFrontOf(struct Layer * __arg1, struct Layer * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(LONG, MoveLayerInFrontOf,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct Layer *,(__arg2),A1),
        struct Library *, (__LayersBase), 28, Layers    );
}

#define MoveLayerInFrontOf(arg1, arg2) \
    __inline_Layers_MoveLayerInFrontOf((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Region * __inline_Layers_InstallClipRegion(struct Layer * __arg1, struct Region * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(struct Region *, InstallClipRegion,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        struct Library *, (__LayersBase), 29, Layers    );
}

#define InstallClipRegion(arg1, arg2) \
    __inline_Layers_InstallClipRegion((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_MoveSizeLayer(struct Layer * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, LONG __arg5, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC5(LONG, MoveSizeLayer,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(LONG,(__arg5),D3),
        struct Library *, (__LayersBase), 30, Layers    );
}

#define MoveSizeLayer(arg1, arg2, arg3, arg4, arg5) \
    __inline_Layers_MoveSizeLayer((arg1), (arg2), (arg3), (arg4), (arg5), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateUpfrontHookLayer(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct Hook * __arg8, struct BitMap * __arg9, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC9(struct Layer *, CreateUpfrontHookLayer,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct Hook *,(__arg8),A3),
        AROS_LCA(struct BitMap *,(__arg9),A2),
        struct Library *, (__LayersBase), 31, Layers    );
}

#define CreateUpfrontHookLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Layers_CreateUpfrontHookLayer((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateBehindHookLayer(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct Hook * __arg8, struct BitMap * __arg9, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC9(struct Layer *, CreateBehindHookLayer,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct Hook *,(__arg8),A3),
        AROS_LCA(struct BitMap *,(__arg9),A2),
        struct Library *, (__LayersBase), 32, Layers    );
}

#define CreateBehindHookLayer(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
    __inline_Layers_CreateBehindHookLayer((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), (arg9), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__)

static inline struct Hook * __inline_Layers_InstallLayerHook(struct Layer * __arg1, struct Hook * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 0)
    return AROS_LC2(struct Hook *, InstallLayerHook,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct Hook *,(__arg2),A1),
        struct Library *, (__LayersBase), 33, Layers    );
}

#define InstallLayerHook(arg1, arg2) \
    __inline_Layers_InstallLayerHook((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (0 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

static inline struct Hook * __inline_Layers_InstallLayerInfoHook(struct Layer_Info * __arg1, struct Hook * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 39)
    return AROS_LC2(struct Hook *, InstallLayerInfoHook,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct Hook *,(__arg2),A1),
        struct Library *, (__LayersBase), 34, Layers    );
}

#define InstallLayerInfoHook(arg1, arg2) \
    __inline_Layers_InstallLayerInfoHook((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_SortLayerCR(struct Layer * __arg1, LONG __arg2, LONG __arg3, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 39)
    AROS_LC3NR(void, SortLayerCR,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__LayersBase), 35, Layers    );
}

#define SortLayerCR(arg1, arg2, arg3) \
    __inline_Layers_SortLayerCR((arg1), (arg2), (arg3), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_DoHookClipRects(struct Hook * __arg1, struct RastPort * __arg2, struct Rectangle * __arg3, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 39)
    AROS_LC3NR(void, DoHookClipRects,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(struct RastPort *,(__arg2),A1),
        AROS_LCA(struct Rectangle *,(__arg3),A2),
        struct Library *, (__LayersBase), 36, Layers    );
}

#define DoHookClipRects(arg1, arg2, arg3) \
    __inline_Layers_DoHookClipRects((arg1), (arg2), (arg3), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (39 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__)

static inline struct Region * __inline_Layers_ChangeLayerShape(struct Layer * __arg1, struct Region * __arg2, struct Hook * __arg3, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 45)
    return AROS_LC3(struct Region *, ChangeLayerShape,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        AROS_LCA(struct Hook *,(__arg3),A2),
        struct Library *, (__LayersBase), 37, Layers    );
}

#define ChangeLayerShape(arg1, arg2, arg3) \
    __inline_Layers_ChangeLayerShape((arg1), (arg2), (arg3), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__)

static inline ULONG __inline_Layers_ScaleLayer(struct Layer * __arg1, struct TagItem * __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 45)
    return AROS_LC2(ULONG, ScaleLayer,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__LayersBase), 38, Layers    );
}

#define ScaleLayer(arg1, arg2) \
    __inline_Layers_ScaleLayer((arg1), (arg2), __LAYERS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define ScaleLayerTags(arg1, ...) \
({ \
    const IPTR ScaleLayer_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ScaleLayer((arg1), (struct TagItem *)(ScaleLayer_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (45 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateUpfrontLayerTagList(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct TagItem * __arg8, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    return AROS_LC8(struct Layer *, CreateUpfrontLayerTagList,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct TagItem *,(__arg8),A2),
        struct Library *, (__LayersBase), 39, Layers    );
}

#define CreateUpfrontLayerTagList(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Layers_CreateUpfrontLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __LAYERS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define CreateUpfrontLayerTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR CreateUpfrontLayerTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateUpfrontLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(CreateUpfrontLayerTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline struct Layer * __inline_Layers_CreateBehindLayerTagList(struct Layer_Info * __arg1, struct BitMap * __arg2, LONG __arg3, LONG __arg4, LONG __arg5, LONG __arg6, LONG __arg7, struct TagItem * __arg8, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    return AROS_LC8(struct Layer *, CreateBehindLayerTagList,
        AROS_LCA(struct Layer_Info *,(__arg1),A0),
        AROS_LCA(struct BitMap *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(LONG,(__arg5),D2),
        AROS_LCA(LONG,(__arg6),D3),
        AROS_LCA(LONG,(__arg7),D4),
        AROS_LCA(struct TagItem *,(__arg8),A2),
        struct Library *, (__LayersBase), 40, Layers    );
}

#define CreateBehindLayerTagList(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __inline_Layers_CreateBehindLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8), __LAYERS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(LAYERS_NO_INLINE_STDARG)
#define CreateBehindLayerTags(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) \
({ \
    const IPTR CreateBehindLayerTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateBehindLayerTagList((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (struct TagItem *)(CreateBehindLayerTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_ChangeLayerVisibility(struct Layer * __arg1, int __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    return AROS_LC2(LONG, ChangeLayerVisibility,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(int,(__arg2),D0),
        struct Library *, (__LayersBase), 41, Layers    );
}

#define ChangeLayerVisibility(arg1, arg2) \
    __inline_Layers_ChangeLayerVisibility((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline LONG __inline_Layers_IsLayerVisible(struct Layer * __arg1, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    return AROS_LC1(LONG, IsLayerVisible,
        AROS_LCA(struct Layer *,(__arg1),A0),
        struct Library *, (__LayersBase), 43, Layers    );
}

#define IsLayerVisible(arg1) \
    __inline_Layers_IsLayerVisible((arg1), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline BOOL __inline_Layers_IsLayerHiddenBySibling(struct Layer * __arg1, BOOL __arg2, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    return AROS_LC2(BOOL, IsLayerHiddenBySibling,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(BOOL,(__arg2),D0),
        struct Library *, (__LayersBase), 44, Layers    );
}

#define IsLayerHiddenBySibling(arg1, arg2) \
    __inline_Layers_IsLayerHiddenBySibling((arg1), (arg2), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#if !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__)

static inline void __inline_Layers_CollectPixelsLayer(struct Layer * __arg1, struct Region * __arg2, struct Hook * __arg3, APTR __LayersBase)
{
    AROS_LIBREQ(LayersBase, 50)
    AROS_LC3NR(void, CollectPixelsLayer,
        AROS_LCA(struct Layer *,(__arg1),A0),
        AROS_LCA(struct Region *,(__arg2),A1),
        AROS_LCA(struct Hook *,(__arg3),A2),
        struct Library *, (__LayersBase), 45, Layers    );
}

#define CollectPixelsLayer(arg1, arg2, arg3) \
    __inline_Layers_CollectPixelsLayer((arg1), (arg2), (arg3), __LAYERS_LIBBASE)

#endif /* !defined(__LAYERS_LIBAPI__) || (50 <= __LAYERS_LIBAPI__) */

#endif /* INLINE_LAYERS_H*/
