#ifndef INTERFACE_Hidd_H
#define INTERFACE_Hidd_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/hidds/hidd/hiddclass.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: interface inlines for Hidd
*/

#include <exec/types.h>
#include <proto/oop.h>

#define IID_Hidd                             "I_Hidd"

#if !defined(HiddBase) && !defined(__OOP_NOMETHODBASES__) && !defined(__Hidd_NOMETHODBASE__)
#define HiddBase Hidd_GetMethodBase(__obj)

static inline OOP_MethodID Hidd_GetMethodBase(OOP_Object *obj)
{
    static OOP_MethodID Hidd_mid;
    if (!Hidd_mid) {
        struct Library *OOPBase = (struct Library *)OOP_OCLASS(obj)->OOPBasePtr;
        Hidd_mid = OOP_GetMethodID(IID_Hidd, 0);
    }
    return Hidd_mid;
}
#endif

#define HiddAttrBase                     __IHidd

#if !defined(__OOP_NOATTRBASES__) && !defined(__Hidd_NOATTRBASE__)
extern OOP_AttrBase HiddAttrBase;
#endif

enum
{
    aoHidd_Type = 0,  /*  [..G] Major type of HIDD */
    aoHidd_SubType = 1,  /*  [..G] Sub-type of HIDD */
    aoHidd_Producer = 2,  /*  [I.G] Hardware manufacturer ID */
    aoHidd_Name = 3,  /*  [I.G] Name of HIDD */
    aoHidd_HardwareName = 4,  /*  [I.G] Hardware description */
    aoHidd_Active = 5,  /*  [ISG] Current active status */
    aoHidd_Status = 6,  /*  [..G] Status change */
    aoHidd_ErrorCode = 7,  /*  [..G] Error code */
    aoHidd_Locking = 8,  /*  [..G] Type of locking supported */
    aoHidd_Product = 9,  /*  [I.G] Hardware product ID */
    aoHidd_ProducerName = 10,  /*  [I.G] Hardware manufacturer name */
    aoHidd_DriverData = 11,  /*  [I..] Driver-specific data */
    num_Hidd_Attrs = 12,
};

#define aHidd_Type                             (HiddAttrBase + aoHidd_Type)
#define aHidd_SubType                          (HiddAttrBase + aoHidd_SubType)
#define aHidd_Producer                         (HiddAttrBase + aoHidd_Producer)
#define aHidd_Name                             (HiddAttrBase + aoHidd_Name)
#define aHidd_HardwareName                     (HiddAttrBase + aoHidd_HardwareName)
#define aHidd_Active                           (HiddAttrBase + aoHidd_Active)
#define aHidd_Status                           (HiddAttrBase + aoHidd_Status)
#define aHidd_ErrorCode                        (HiddAttrBase + aoHidd_ErrorCode)
#define aHidd_Locking                          (HiddAttrBase + aoHidd_Locking)
#define aHidd_Product                          (HiddAttrBase + aoHidd_Product)
#define aHidd_ProducerName                     (HiddAttrBase + aoHidd_ProducerName)
#define aHidd_DriverData                       (HiddAttrBase + aoHidd_DriverData)

#define Hidd_Switch(attr, idx) \
if (((idx) = (attr) - HiddAttrBase) < num_Hidd_Attrs) \
switch (idx)

#endif /* INTERFACE_Hidd_H */
