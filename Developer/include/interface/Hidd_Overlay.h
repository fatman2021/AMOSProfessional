#ifndef INTERFACE_Hidd_Overlay_H
#define INTERFACE_Hidd_Overlay_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/hidds/gfx/gfx.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: interface inlines for Hidd_Overlay
*/

#include <exec/types.h>
#include <proto/oop.h>

#define IID_Hidd_Overlay                     "hidd.gfx.overlay"

#if !defined(Hidd_OverlayBase) && !defined(__OOP_NOMETHODBASES__) && !defined(__Hidd_Overlay_NOMETHODBASE__)
#define Hidd_OverlayBase Hidd_Overlay_GetMethodBase(__obj)

static inline OOP_MethodID Hidd_Overlay_GetMethodBase(OOP_Object *obj)
{
    static OOP_MethodID Hidd_Overlay_mid;
    if (!Hidd_Overlay_mid) {
        struct Library *OOPBase = (struct Library *)OOP_OCLASS(obj)->OOPBasePtr;
        Hidd_Overlay_mid = OOP_GetMethodID(IID_Hidd_Overlay, 0);
    }
    return Hidd_Overlay_mid;
}
#endif

#define Hidd_OverlayAttrBase             __IHidd_Overlay

#if !defined(__OOP_NOATTRBASES__) && !defined(__Hidd_Overlay_NOATTRBASE__)
extern OOP_AttrBase Hidd_OverlayAttrBase;
#endif

enum
{
    aoHidd_Overlay_SrcWidth = 0,  /*  [I..] Source width in pixels  */
    aoHidd_Overlay_SrcHeight = 1,  /*  [I..] Source height in pixels */
    aoHidd_Overlay_SrcFormat = 2,  /*  [I..] Source pixel format */
    aoHidd_Overlay_Error = 3,  /*  [I..] Points to location where error code will be placed */
    num_Hidd_Overlay_Attrs = 4,
};

#define aHidd_Overlay_SrcWidth                         (Hidd_OverlayAttrBase + aoHidd_Overlay_SrcWidth)
#define aHidd_Overlay_SrcHeight                        (Hidd_OverlayAttrBase + aoHidd_Overlay_SrcHeight)
#define aHidd_Overlay_SrcFormat                        (Hidd_OverlayAttrBase + aoHidd_Overlay_SrcFormat)
#define aHidd_Overlay_Error                            (Hidd_OverlayAttrBase + aoHidd_Overlay_Error)

#define Hidd_Overlay_Switch(attr, idx) \
if (((idx) = (attr) - Hidd_OverlayAttrBase) < num_Hidd_Overlay_Attrs) \
switch (idx)

#endif /* INTERFACE_Hidd_Overlay_H */
