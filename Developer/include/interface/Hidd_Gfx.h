#ifndef INTERFACE_Hidd_Gfx_H
#define INTERFACE_Hidd_Gfx_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/hidds/gfx/gfx.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: interface inlines for Hidd_Gfx
*/

#include <exec/types.h>
#include <proto/oop.h>

#define IID_Hidd_Gfx                         "hidd.gfx.driver"

#if !defined(HiddGfxBase) && !defined(__OOP_NOMETHODBASES__) && !defined(__Hidd_Gfx_NOMETHODBASE__)
#define HiddGfxBase Hidd_Gfx_GetMethodBase(__obj)

static inline OOP_MethodID Hidd_Gfx_GetMethodBase(OOP_Object *obj)
{
    static OOP_MethodID Hidd_Gfx_mid;
    if (!Hidd_Gfx_mid) {
        struct Library *OOPBase = (struct Library *)OOP_OCLASS(obj)->OOPBasePtr;
        Hidd_Gfx_mid = OOP_GetMethodID(IID_Hidd_Gfx, 0);
    }
    return Hidd_Gfx_mid;
}
#endif

#define HiddGfxAttrBase                  __IHidd_Gfx

#if !defined(__OOP_NOATTRBASES__) && !defined(__Hidd_Gfx_NOATTRBASE__)
extern OOP_AttrBase HiddGfxAttrBase;
#endif

enum
{
    aoHidd_Gfx_MemoryAttribs = 0,  /* [..G] query information about the gfx devices memory. */
    aoHidd_Gfx_DisplayList = 1,  /*      [..G] Returns a list of Display objects (if supported) */
    aoHidd_Gfx_DisplayDefault = 2,  /*    [..G] Find the primary Display. If DisplayList == NULL, DisplayDefault = the only available display. */
    aoHidd_Gfx_IsWindowed = 3,  /*              [..G] Whether the HIDD is using host's window system */
    aoHidd_Gfx_DPMSLevel = 4,  /*              [ISG] DPMS level */
    aoHidd_Gfx_PixFmtTags = 5,  /*  [I..] */
    aoHidd_Gfx_SyncTags = 6,  /*    [I..] */
    aoHidd_Gfx_ModeTags = 7,  /*    [I..] Display modes description */
    aoHidd_Gfx_NumSyncs = 8,  /*               [..G] The number of different syncs the gfxcard can do */
    aoHidd_Gfx_SupportsHWCursor = 9,  /*        [..G] SupportsHWCursor (obsolete) */
    aoHidd_Gfx_NoFrameBuffer = 10,  /*           [..G] if the hidd does not need a framebuffer */
    aoHidd_Gfx_HWSpriteTypes = 11,  /*          [..G] Supported types of hardware sprites */
    aoHidd_Gfx_MemorySize = 12,  /*             [..G] Size of video card's memory in bytes */
    aoHidd_Gfx_MemoryClock = 13,  /*            [..G] A video card's memory clock in Hz */
    aoHidd_Gfx_DriverName = 14,  /*            [..G] A name of driver for CyberGraphX */
    aoHidd_Gfx_ActiveCallBack = 15,  /*          [.S.] Display activation callback function */
    aoHidd_Gfx_ActiveCallBackData = 16,  /*      [.S.] User data for activation callback */
    aoHidd_Gfx_DefaultGC = 17,  /*       [..G] Default GC for copy operations */
    aoHidd_Gfx_FrameBufferType = 18,  /*        [I.G] Framebuffer type */
    aoHidd_Gfx_SupportsGamma = 19,  /*           [..G] Supports gamma correction table */
    num_Hidd_Gfx_Attrs = 20,
};

#define aHidd_Gfx_MemoryAttribs                    (HiddGfxAttrBase + aoHidd_Gfx_MemoryAttribs)
#define aHidd_Gfx_DisplayList                      (HiddGfxAttrBase + aoHidd_Gfx_DisplayList)
#define aHidd_Gfx_DisplayDefault                   (HiddGfxAttrBase + aoHidd_Gfx_DisplayDefault)
#define aHidd_Gfx_IsWindowed                       (HiddGfxAttrBase + aoHidd_Gfx_IsWindowed)
#define aHidd_Gfx_DPMSLevel                        (HiddGfxAttrBase + aoHidd_Gfx_DPMSLevel)
#define aHidd_Gfx_PixFmtTags                       (HiddGfxAttrBase + aoHidd_Gfx_PixFmtTags)
#define aHidd_Gfx_SyncTags                         (HiddGfxAttrBase + aoHidd_Gfx_SyncTags)
#define aHidd_Gfx_ModeTags                         (HiddGfxAttrBase + aoHidd_Gfx_ModeTags)
#define aHidd_Gfx_NumSyncs                         (HiddGfxAttrBase + aoHidd_Gfx_NumSyncs)
#define aHidd_Gfx_SupportsHWCursor                 (HiddGfxAttrBase + aoHidd_Gfx_SupportsHWCursor)
#define aHidd_Gfx_NoFrameBuffer                    (HiddGfxAttrBase + aoHidd_Gfx_NoFrameBuffer)
#define aHidd_Gfx_HWSpriteTypes                    (HiddGfxAttrBase + aoHidd_Gfx_HWSpriteTypes)
#define aHidd_Gfx_MemorySize                       (HiddGfxAttrBase + aoHidd_Gfx_MemorySize)
#define aHidd_Gfx_MemoryClock                      (HiddGfxAttrBase + aoHidd_Gfx_MemoryClock)
#define aHidd_Gfx_DriverName                       (HiddGfxAttrBase + aoHidd_Gfx_DriverName)
#define aHidd_Gfx_ActiveCallBack                   (HiddGfxAttrBase + aoHidd_Gfx_ActiveCallBack)
#define aHidd_Gfx_ActiveCallBackData               (HiddGfxAttrBase + aoHidd_Gfx_ActiveCallBackData)
#define aHidd_Gfx_DefaultGC                        (HiddGfxAttrBase + aoHidd_Gfx_DefaultGC)
#define aHidd_Gfx_FrameBufferType                  (HiddGfxAttrBase + aoHidd_Gfx_FrameBufferType)
#define aHidd_Gfx_SupportsGamma                    (HiddGfxAttrBase + aoHidd_Gfx_SupportsGamma)

#define Hidd_Gfx_Switch(attr, idx) \
if (((idx) = (attr) - HiddGfxAttrBase) < num_Hidd_Gfx_Attrs) \
switch (idx)


enum {
    moHidd_Gfx_NominalDimensions = 0,
    moHidd_Gfx_CreateObject = 1,
    moHidd_Gfx_QueryModeIDs = 2,
    moHidd_Gfx_ReleaseModeIDs = 3,
    moHidd_Gfx_NextModeID = 4,
    moHidd_Gfx_GetMode = 5,
    moHidd_Gfx_CheckMode = 6,
    moHidd_Gfx_GetPixFmt = 7,
    moHidd_Gfx_SetCursorShape = 8,
    moHidd_Gfx_SetCursorPos = 9,
    moHidd_Gfx_SetCursorVisible = 10,
    moHidd_Gfx_SetMode = 11,
    moHidd_Gfx_Show = 12,
    moHidd_Gfx_CopyBox = 13,
    moHidd_Gfx_ShowImminentReset = 14,
    moHidd_Gfx_ModeProperties = 15,
    moHidd_Gfx_ShowViewPorts = 16,
    moHidd_Gfx_GetSync = 17,
    moHidd_Gfx_GetGamma = 18,
    moHidd_Gfx_SetGamma = 19,
    moHidd_Gfx_QueryHardware3D = 20,
    moHidd_Gfx_GetMaxSpriteSize = 21,
    moHidd_Gfx_NewOverlay = 22,
    moHidd_Gfx_DisposeOverlay = 23,
    moHidd_Gfx_MakeViewPort = 24,
    moHidd_Gfx_CleanViewPort = 25,
    moHidd_Gfx_PrepareViewPorts = 26,
    moHidd_Gfx_CopyBoxMasked = 27,
    num_Hidd_Gfx_Methods = 28
};

struct pHidd_Gfx_NominalDimensions
{
    OOP_MethodID mID;
    UWORD *width;
    UWORD *height;
    UBYTE *depth;
};

#define HIDD_Gfx_NominalDimensions(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_NominalDimensions_(HiddGfxBase, __obj ,##args); })

static inline VOID HIDD_Gfx_NominalDimensions_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, UWORD *width, UWORD *height, UBYTE *depth)
{
    struct pHidd_Gfx_NominalDimensions p;
    p.mID = __HiddGfxBase + moHidd_Gfx_NominalDimensions;
    p.width = width;
    p.height = height;
    p.depth = depth;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_CreateObject
{
    OOP_MethodID mID;
    OOP_Class *cl;
    struct TagItem *attrList;
};

#define HIDD_Gfx_CreateObject(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_CreateObject_(HiddGfxBase, __obj ,##args); })

static inline OOP_Object * HIDD_Gfx_CreateObject_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Class *cl, struct TagItem *attrList)
{
    struct pHidd_Gfx_CreateObject p;
    p.mID = __HiddGfxBase + moHidd_Gfx_CreateObject;
    p.cl = cl;
    p.attrList = attrList;
    return (OOP_Object *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_QueryModeIDs
{
    OOP_MethodID mID;
    struct TagItem *queryTags;
};

#define HIDD_Gfx_QueryModeIDs(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_QueryModeIDs_(HiddGfxBase, __obj ,##args); })

static inline HIDDT_ModeID * HIDD_Gfx_QueryModeIDs_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct TagItem *queryTags)
{
    struct pHidd_Gfx_QueryModeIDs p;
    p.mID = __HiddGfxBase + moHidd_Gfx_QueryModeIDs;
    p.queryTags = queryTags;
    return (HIDDT_ModeID *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_ReleaseModeIDs
{
    OOP_MethodID mID;
    HIDDT_ModeID *modeIDs;
};

#define HIDD_Gfx_ReleaseModeIDs(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_ReleaseModeIDs_(HiddGfxBase, __obj ,##args); })

static inline VOID HIDD_Gfx_ReleaseModeIDs_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_ModeID *modeIDs)
{
    struct pHidd_Gfx_ReleaseModeIDs p;
    p.mID = __HiddGfxBase + moHidd_Gfx_ReleaseModeIDs;
    p.modeIDs = modeIDs;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_NextModeID
{
    OOP_MethodID mID;
    HIDDT_ModeID modeID;
    OOP_Object **syncPtr;
    OOP_Object **pixFmtPtr;
};

#define HIDD_Gfx_NextModeID(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_NextModeID_(HiddGfxBase, __obj ,##args); })

static inline HIDDT_ModeID HIDD_Gfx_NextModeID_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_ModeID modeID, OOP_Object **syncPtr, OOP_Object **pixFmtPtr)
{
    struct pHidd_Gfx_NextModeID p;
    p.mID = __HiddGfxBase + moHidd_Gfx_NextModeID;
    p.modeID = modeID;
    p.syncPtr = syncPtr;
    p.pixFmtPtr = pixFmtPtr;
    return (HIDDT_ModeID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_GetMode
{
    OOP_MethodID mID;
    HIDDT_ModeID modeID;
    OOP_Object **syncPtr;
    OOP_Object **pixFmtPtr;
};

#define HIDD_Gfx_GetMode(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_GetMode_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_GetMode_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_ModeID modeID, OOP_Object **syncPtr, OOP_Object **pixFmtPtr)
{
    struct pHidd_Gfx_GetMode p;
    p.mID = __HiddGfxBase + moHidd_Gfx_GetMode;
    p.modeID = modeID;
    p.syncPtr = syncPtr;
    p.pixFmtPtr = pixFmtPtr;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_CheckMode
{
    OOP_MethodID mID;
    HIDDT_ModeID modeID;
    OOP_Object *sync;
    OOP_Object *pixFmt;
};

#define HIDD_Gfx_CheckMode(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_CheckMode_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_CheckMode_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_ModeID modeID, OOP_Object *sync, OOP_Object *pixFmt)
{
    struct pHidd_Gfx_CheckMode p;
    p.mID = __HiddGfxBase + moHidd_Gfx_CheckMode;
    p.modeID = modeID;
    p.sync = sync;
    p.pixFmt = pixFmt;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_GetPixFmt
{
    OOP_MethodID mID;
    HIDDT_StdPixFmt stdPixFmt;
};

#define HIDD_Gfx_GetPixFmt(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_GetPixFmt_(HiddGfxBase, __obj ,##args); })

static inline OOP_Object * HIDD_Gfx_GetPixFmt_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_StdPixFmt stdPixFmt)
{
    struct pHidd_Gfx_GetPixFmt p;
    p.mID = __HiddGfxBase + moHidd_Gfx_GetPixFmt;
    p.stdPixFmt = stdPixFmt;
    return (OOP_Object *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_SetCursorShape
{
    OOP_MethodID mID;
    OOP_Object *shape;
    WORD xoffset;
    WORD yoffset;
};

#define HIDD_Gfx_SetCursorShape(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_SetCursorShape_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_SetCursorShape_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *shape, WORD xoffset, WORD yoffset)
{
    struct pHidd_Gfx_SetCursorShape p;
    p.mID = __HiddGfxBase + moHidd_Gfx_SetCursorShape;
    p.shape = shape;
    p.xoffset = xoffset;
    p.yoffset = yoffset;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_SetCursorPos
{
    OOP_MethodID mID;
    WORD x;
    WORD y;
};

#define HIDD_Gfx_SetCursorPos(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_SetCursorPos_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_SetCursorPos_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, WORD x, WORD y)
{
    struct pHidd_Gfx_SetCursorPos p;
    p.mID = __HiddGfxBase + moHidd_Gfx_SetCursorPos;
    p.x = x;
    p.y = y;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_SetCursorVisible
{
    OOP_MethodID mID;
    BOOL visible;
};

#define HIDD_Gfx_SetCursorVisible(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_SetCursorVisible_(HiddGfxBase, __obj ,##args); })

static inline VOID HIDD_Gfx_SetCursorVisible_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, BOOL visible)
{
    struct pHidd_Gfx_SetCursorVisible p;
    p.mID = __HiddGfxBase + moHidd_Gfx_SetCursorVisible;
    p.visible = visible;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_SetMode
{
    OOP_MethodID mID;
    OOP_Object *sync;
};

#define HIDD_Gfx_SetMode(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_SetMode_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_SetMode_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *sync)
{
    struct pHidd_Gfx_SetMode p;
    p.mID = __HiddGfxBase + moHidd_Gfx_SetMode;
    p.sync = sync;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_Show
{
    OOP_MethodID mID;
    OOP_Object *bitMap;
    ULONG flags;
};

#define HIDD_Gfx_Show(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_Show_(HiddGfxBase, __obj ,##args); })

static inline OOP_Object * HIDD_Gfx_Show_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *bitMap, ULONG flags)
{
    struct pHidd_Gfx_Show p;
    p.mID = __HiddGfxBase + moHidd_Gfx_Show;
    p.bitMap = bitMap;
    p.flags = flags;
    return (OOP_Object *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_CopyBox
{
    OOP_MethodID mID;
    OOP_Object *src;
    WORD srcX;
    WORD srcY;
    OOP_Object *dest;
    WORD destX;
    WORD destY;
    UWORD width;
    UWORD height;
    OOP_Object *gc;
};

#define HIDD_Gfx_CopyBox(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_CopyBox_(HiddGfxBase, __obj ,##args); })

static inline VOID HIDD_Gfx_CopyBox_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *src, WORD srcX, WORD srcY, OOP_Object *dest, WORD destX, WORD destY, UWORD width, UWORD height, OOP_Object *gc)
{
    struct pHidd_Gfx_CopyBox p;
    p.mID = __HiddGfxBase + moHidd_Gfx_CopyBox;
    p.src = src;
    p.srcX = srcX;
    p.srcY = srcY;
    p.dest = dest;
    p.destX = destX;
    p.destY = destY;
    p.width = width;
    p.height = height;
    p.gc = gc;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_ShowImminentReset
{
    OOP_MethodID mID;
};

/*  Obsolete */
#define HIDD_Gfx_ShowImminentReset(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_ShowImminentReset_(HiddGfxBase, __obj ,##args); })

static inline VOID HIDD_Gfx_ShowImminentReset_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj)
{
    struct pHidd_Gfx_ShowImminentReset p;
    p.mID = __HiddGfxBase + moHidd_Gfx_ShowImminentReset;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_ModeProperties
{
    OOP_MethodID mID;
    HIDDT_ModeID modeID;
    struct HIDD_ModeProperties *props;
    ULONG propsLen;
};

#define HIDD_Gfx_ModeProperties(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_ModeProperties_(HiddGfxBase, __obj ,##args); })

static inline ULONG HIDD_Gfx_ModeProperties_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, HIDDT_ModeID modeID, struct HIDD_ModeProperties *props, ULONG propsLen)
{
    struct pHidd_Gfx_ModeProperties p;
    p.mID = __HiddGfxBase + moHidd_Gfx_ModeProperties;
    p.modeID = modeID;
    p.props = props;
    p.propsLen = propsLen;
    return (ULONG)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_ShowViewPorts
{
    OOP_MethodID mID;
    struct HIDD_ViewPortData *Data;
};

#define HIDD_Gfx_ShowViewPorts(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_ShowViewPorts_(HiddGfxBase, __obj ,##args); })

static inline ULONG HIDD_Gfx_ShowViewPorts_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct HIDD_ViewPortData *Data)
{
    struct pHidd_Gfx_ShowViewPorts p;
    p.mID = __HiddGfxBase + moHidd_Gfx_ShowViewPorts;
    p.Data = Data;
    return (ULONG)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_GetSync
{
    OOP_MethodID mID;
    ULONG num;
};

#define HIDD_Gfx_GetSync(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_GetSync_(HiddGfxBase, __obj ,##args); })

static inline OOP_Object * HIDD_Gfx_GetSync_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, ULONG num)
{
    struct pHidd_Gfx_GetSync p;
    p.mID = __HiddGfxBase + moHidd_Gfx_GetSync;
    p.num = num;
    return (OOP_Object *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_GetGamma
{
    OOP_MethodID mID;
    UBYTE *Red;
    UBYTE *Green;
    UBYTE *Blue;
};

#define HIDD_Gfx_GetGamma(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_GetGamma_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_GetGamma_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, UBYTE *Red, UBYTE *Green, UBYTE *Blue)
{
    struct pHidd_Gfx_GetGamma p;
    p.mID = __HiddGfxBase + moHidd_Gfx_GetGamma;
    p.Red = Red;
    p.Green = Green;
    p.Blue = Blue;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_SetGamma
{
    OOP_MethodID mID;
    UBYTE *Red;
    UBYTE *Green;
    UBYTE *Blue;
};

#define HIDD_Gfx_SetGamma(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_SetGamma_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_SetGamma_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, UBYTE *Red, UBYTE *Green, UBYTE *Blue)
{
    struct pHidd_Gfx_SetGamma p;
    p.mID = __HiddGfxBase + moHidd_Gfx_SetGamma;
    p.Red = Red;
    p.Green = Green;
    p.Blue = Blue;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_QueryHardware3D
{
    OOP_MethodID mID;
    OOP_Object *pixFmt;
};

#define HIDD_Gfx_QueryHardware3D(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_QueryHardware3D_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_QueryHardware3D_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *pixFmt)
{
    struct pHidd_Gfx_QueryHardware3D p;
    p.mID = __HiddGfxBase + moHidd_Gfx_QueryHardware3D;
    p.pixFmt = pixFmt;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_GetMaxSpriteSize
{
    OOP_MethodID mID;
    ULONG Type;
    ULONG *Width;
    ULONG *Height;
};

#define HIDD_Gfx_GetMaxSpriteSize(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_GetMaxSpriteSize_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_GetMaxSpriteSize_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, ULONG Type, ULONG *Width, ULONG *Height)
{
    struct pHidd_Gfx_GetMaxSpriteSize p;
    p.mID = __HiddGfxBase + moHidd_Gfx_GetMaxSpriteSize;
    p.Type = Type;
    p.Width = Width;
    p.Height = Height;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_NewOverlay
{
    OOP_MethodID mID;
    struct TagItem *attrList;
};

#define HIDD_Gfx_NewOverlay(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_NewOverlay_(HiddGfxBase, __obj ,##args); })

static inline OOP_Object * HIDD_Gfx_NewOverlay_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct TagItem *attrList)
{
    struct pHidd_Gfx_NewOverlay p;
    p.mID = __HiddGfxBase + moHidd_Gfx_NewOverlay;
    p.attrList = attrList;
    return (OOP_Object *)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_DisposeOverlay
{
    OOP_MethodID mID;
    OOP_Object *Overlay;
};

#define HIDD_Gfx_DisposeOverlay(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_DisposeOverlay_(HiddGfxBase, __obj ,##args); })

static inline void HIDD_Gfx_DisposeOverlay_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *Overlay)
{
    struct pHidd_Gfx_DisposeOverlay p;
    p.mID = __HiddGfxBase + moHidd_Gfx_DisposeOverlay;
    p.Overlay = Overlay;
    (void)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_MakeViewPort
{
    OOP_MethodID mID;
    struct HIDD_ViewPortData *Data;
};

#define HIDD_Gfx_MakeViewPort(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_MakeViewPort_(HiddGfxBase, __obj ,##args); })

static inline ULONG HIDD_Gfx_MakeViewPort_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct HIDD_ViewPortData *Data)
{
    struct pHidd_Gfx_MakeViewPort p;
    p.mID = __HiddGfxBase + moHidd_Gfx_MakeViewPort;
    p.Data = Data;
    return (ULONG)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_CleanViewPort
{
    OOP_MethodID mID;
    struct HIDD_ViewPortData *Data;
};

#define HIDD_Gfx_CleanViewPort(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_CleanViewPort_(HiddGfxBase, __obj ,##args); })

static inline void HIDD_Gfx_CleanViewPort_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct HIDD_ViewPortData *Data)
{
    struct pHidd_Gfx_CleanViewPort p;
    p.mID = __HiddGfxBase + moHidd_Gfx_CleanViewPort;
    p.Data = Data;
    (void)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_PrepareViewPorts
{
    OOP_MethodID mID;
    struct HIDD_ViewPortData *Data;
    struct View *view;
};

#define HIDD_Gfx_PrepareViewPorts(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_PrepareViewPorts_(HiddGfxBase, __obj ,##args); })

static inline ULONG HIDD_Gfx_PrepareViewPorts_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, struct HIDD_ViewPortData *Data, struct View *view)
{
    struct pHidd_Gfx_PrepareViewPorts p;
    p.mID = __HiddGfxBase + moHidd_Gfx_PrepareViewPorts;
    p.Data = Data;
    p.view = view;
    return (ULONG)OOP_DoMethod(__obj, &p.mID);
}

struct pHidd_Gfx_CopyBoxMasked
{
    OOP_MethodID mID;
    OOP_Object *src;
    WORD srcX;
    WORD srcY;
    OOP_Object *dest;
    WORD destX;
    WORD destY;
    UWORD width;
    UWORD height;
    PLANEPTR mask;
    OOP_Object *gc;
};

#define HIDD_Gfx_CopyBoxMasked(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_Gfx_CopyBoxMasked_(HiddGfxBase, __obj ,##args); })

static inline BOOL HIDD_Gfx_CopyBoxMasked_(OOP_MethodID __HiddGfxBase, OOP_Object *__obj, OOP_Object *src, WORD srcX, WORD srcY, OOP_Object *dest, WORD destX, WORD destY, UWORD width, UWORD height, PLANEPTR mask, OOP_Object *gc)
{
    struct pHidd_Gfx_CopyBoxMasked p;
    p.mID = __HiddGfxBase + moHidd_Gfx_CopyBoxMasked;
    p.src = src;
    p.srcX = srcX;
    p.srcY = srcY;
    p.dest = dest;
    p.destX = destX;
    p.destY = destY;
    p.width = width;
    p.height = height;
    p.mask = mask;
    p.gc = gc;
    return (BOOL)OOP_DoMethod(__obj, &p.mID);
}

#endif /* INTERFACE_Hidd_Gfx_H */
