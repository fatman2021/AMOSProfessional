#ifndef INTERFACE_Hidd_P96Gfx_H
#define INTERFACE_Hidd_P96Gfx_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/hidd/p96gfx/p96gfx.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: interface inlines for Hidd_P96Gfx
*/

#include <exec/types.h>
#include <proto/oop.h>

#define IID_Hidd_P96Gfx                      "hidd.gfx.p96gfx"

#if !defined(HiddP96GfxBase) && !defined(__OOP_NOMETHODBASES__) && !defined(__Hidd_P96Gfx_NOMETHODBASE__)
#define HiddP96GfxBase Hidd_P96Gfx_GetMethodBase(__obj)

static inline OOP_MethodID Hidd_P96Gfx_GetMethodBase(OOP_Object *obj)
{
    static OOP_MethodID Hidd_P96Gfx_mid;
    if (!Hidd_P96Gfx_mid) {
        struct Library *OOPBase = (struct Library *)OOP_OCLASS(obj)->OOPBasePtr;
        Hidd_P96Gfx_mid = OOP_GetMethodID(IID_Hidd_P96Gfx, 0);
    }
    return Hidd_P96Gfx_mid;
}
#endif

#define HiddP96GfxAttrBase               __IHidd_P96Gfx

#if !defined(__OOP_NOATTRBASES__) && !defined(__Hidd_P96Gfx_NOATTRBASE__)
extern OOP_AttrBase HiddP96GfxAttrBase;
#endif

enum
{
    aoHidd_P96Gfx_CardData = 0,  /*  [..G] Private card data */
    num_Hidd_P96Gfx_Attrs = 1,
};

#define aHidd_P96Gfx_CardData                         (HiddP96GfxAttrBase + aoHidd_P96Gfx_CardData)

#define Hidd_P96Gfx_Switch(attr, idx) \
if (((idx) = (attr) - HiddP96GfxAttrBase) < num_Hidd_P96Gfx_Attrs) \
switch (idx)


enum {
    moHidd_P96Gfx_SetCursorPen = 0,
    num_Hidd_P96Gfx_Methods = 1
};

struct pHidd_P96Gfx_SetCursorPen
{
    OOP_MethodID mID;
    UWORD pen;
    HIDDT_Color color;
};

#define HIDD_P96GFX_SetCursorPen(obj, args...) \
    ({OOP_Object *__obj = obj;\
      HIDD_P96GFX_SetCursorPen_(HiddP96GfxBase, __obj ,##args); })

static inline VOID HIDD_P96GFX_SetCursorPen_(OOP_MethodID __HiddP96GfxBase, OOP_Object *__obj, UWORD pen, HIDDT_Color color)
{
    struct pHidd_P96Gfx_SetCursorPen p;
    p.mID = __HiddP96GfxBase + moHidd_P96Gfx_SetCursorPen;
    p.pen = pen;
    p.color = color;
    (VOID)OOP_DoMethod(__obj, &p.mID);
}

#endif /* INTERFACE_Hidd_P96Gfx_H */
