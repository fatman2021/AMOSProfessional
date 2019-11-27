#ifndef DEFINES_CARDRES_H
#define DEFINES_CARDRES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/card/card.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for card
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CARDRES_LIBBASE)
#    define __CARDRES_LIBBASE CardResource
#endif

__BEGIN_DECLS


#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __OwnCard_WB(__CardResource, __arg1) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC1(struct CardHandle *, OwnCard, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
        struct Library *, (__CardResource), 1, Card);\
})

#define OwnCard(arg1) \
    __OwnCard_WB(__CARDRES_LIBBASE, (arg1))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __ReleaseCard_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2NR(void, ReleaseCard, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CardResource), 2, Card);\
})

#define ReleaseCard(arg1, arg2) \
    __ReleaseCard_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __GetCardMap_WB(__CardResource) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC0(struct CardMemoryMap *, GetCardMap, \
        struct Library *, (__CardResource), 3, Card);\
})

#define GetCardMap() \
    __GetCardMap_WB(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __BeginCardAccess_WB(__CardResource, __arg1) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC1(BOOL, BeginCardAccess, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
        struct Library *, (__CardResource), 4, Card);\
})

#define BeginCardAccess(arg1) \
    __BeginCardAccess_WB(__CARDRES_LIBBASE, (arg1))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __EndCardAccess_WB(__CardResource, __arg1) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC1(BOOL, EndCardAccess, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
        struct Library *, (__CardResource), 5, Card);\
})

#define EndCardAccess(arg1) \
    __EndCardAccess_WB(__CARDRES_LIBBASE, (arg1))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __ReadCardStatus_WB(__CardResource) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC0(UBYTE, ReadCardStatus, \
        struct Library *, (__CardResource), 6, Card);\
})

#define ReadCardStatus() \
    __ReadCardStatus_WB(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardResetRemove_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2(BOOL, CardResetRemove, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CardResource), 7, Card);\
})

#define CardResetRemove(arg1, arg2) \
    __CardResetRemove_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardMiscControl_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2(UBYTE, CardMiscControl, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(UBYTE,(__arg2),D1), \
        struct Library *, (__CardResource), 8, Card);\
})

#define CardMiscControl(arg1, arg2) \
    __CardMiscControl_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardAccessSpeed_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2(ULONG, CardAccessSpeed, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CardResource), 9, Card);\
})

#define CardAccessSpeed(arg1, arg2) \
    __CardAccessSpeed_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardProgramVoltage_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2(LONG, CardProgramVoltage, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CardResource), 10, Card);\
})

#define CardProgramVoltage(arg1, arg2) \
    __CardProgramVoltage_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardResetCard_WB(__CardResource, __arg1) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC1(BOOL, CardResetCard, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
        struct Library *, (__CardResource), 11, Card);\
})

#define CardResetCard(arg1) \
    __CardResetCard_WB(__CARDRES_LIBBASE, (arg1))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CopyTuple_WB(__CardResource, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC4(BOOL, CopyTuple, \
                  AROS_LCA(struct CardHandle *,(__arg1),A1), \
                  AROS_LCA(UBYTE *,(__arg2),A0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
                  AROS_LCA(ULONG,(__arg4),D0), \
        struct Library *, (__CardResource), 12, Card);\
})

#define CopyTuple(arg1, arg2, arg3, arg4) \
    __CopyTuple_WB(__CARDRES_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __DeviceTuple_WB(__CardResource, __arg1, __arg2) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC2(ULONG, DeviceTuple, \
                  AROS_LCA(UBYTE *,(__arg1),A0), \
                  AROS_LCA(struct DeviceTData *,(__arg2),A1), \
        struct Library *, (__CardResource), 13, Card);\
})

#define DeviceTuple(arg1, arg2) \
    __DeviceTuple_WB(__CARDRES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __IfAmigaXIP_WB(__CardResource, __arg1) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC1(struct Resident *, IfAmigaXIP, \
                  AROS_LCA(struct CardHandle *,(__arg1),A2), \
        struct Library *, (__CardResource), 14, Card);\
})

#define IfAmigaXIP(arg1) \
    __IfAmigaXIP_WB(__CARDRES_LIBBASE, (arg1))

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardForceChange_WB(__CardResource) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC0(BOOL, CardForceChange, \
        struct Library *, (__CardResource), 15, Card);\
})

#define CardForceChange() \
    __CardForceChange_WB(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardChangeCount_WB(__CardResource) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC0(ULONG, CardChangeCount, \
        struct Library *, (__CardResource), 16, Card);\
})

#define CardChangeCount() \
    __CardChangeCount_WB(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

#define __CardInterface_WB(__CardResource) ({\
        AROS_LIBREQ(CardResource,41)\
        AROS_LC0(ULONG, CardInterface, \
        struct Library *, (__CardResource), 17, Card);\
})

#define CardInterface() \
    __CardInterface_WB(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_CARDRES_H*/
