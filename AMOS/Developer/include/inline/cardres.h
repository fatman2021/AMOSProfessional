#ifndef INLINE_CARDRES_H
#define INLINE_CARDRES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/card/card.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for card
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CARDRES_LIBBASE)
#    define __CARDRES_LIBBASE CardResource
#endif


#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline struct CardHandle * __inline_Card_OwnCard(struct CardHandle * __arg1, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC1(struct CardHandle *, OwnCard,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        struct Library *, (__CardResource), 1, Card    );
}

#define OwnCard(arg1) \
    __inline_Card_OwnCard((arg1), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline void __inline_Card_ReleaseCard(struct CardHandle * __arg1, ULONG __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    AROS_LC2NR(void, ReleaseCard,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CardResource), 2, Card    );
}

#define ReleaseCard(arg1, arg2) \
    __inline_Card_ReleaseCard((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline struct CardMemoryMap * __inline_Card_GetCardMap(APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC0(struct CardMemoryMap *, GetCardMap,
        struct Library *, (__CardResource), 3, Card    );
}

#define GetCardMap() \
    __inline_Card_GetCardMap(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_BeginCardAccess(struct CardHandle * __arg1, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC1(BOOL, BeginCardAccess,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        struct Library *, (__CardResource), 4, Card    );
}

#define BeginCardAccess(arg1) \
    __inline_Card_BeginCardAccess((arg1), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_EndCardAccess(struct CardHandle * __arg1, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC1(BOOL, EndCardAccess,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        struct Library *, (__CardResource), 5, Card    );
}

#define EndCardAccess(arg1) \
    __inline_Card_EndCardAccess((arg1), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline UBYTE __inline_Card_ReadCardStatus(APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC0(UBYTE, ReadCardStatus,
        struct Library *, (__CardResource), 6, Card    );
}

#define ReadCardStatus() \
    __inline_Card_ReadCardStatus(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_CardResetRemove(struct CardHandle * __arg1, ULONG __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC2(BOOL, CardResetRemove,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CardResource), 7, Card    );
}

#define CardResetRemove(arg1, arg2) \
    __inline_Card_CardResetRemove((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline UBYTE __inline_Card_CardMiscControl(struct CardHandle * __arg1, UBYTE __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC2(UBYTE, CardMiscControl,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(UBYTE,(__arg2),D1),
        struct Library *, (__CardResource), 8, Card    );
}

#define CardMiscControl(arg1, arg2) \
    __inline_Card_CardMiscControl((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline ULONG __inline_Card_CardAccessSpeed(struct CardHandle * __arg1, ULONG __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC2(ULONG, CardAccessSpeed,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CardResource), 9, Card    );
}

#define CardAccessSpeed(arg1, arg2) \
    __inline_Card_CardAccessSpeed((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline LONG __inline_Card_CardProgramVoltage(struct CardHandle * __arg1, ULONG __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC2(LONG, CardProgramVoltage,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CardResource), 10, Card    );
}

#define CardProgramVoltage(arg1, arg2) \
    __inline_Card_CardProgramVoltage((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_CardResetCard(struct CardHandle * __arg1, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC1(BOOL, CardResetCard,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        struct Library *, (__CardResource), 11, Card    );
}

#define CardResetCard(arg1) \
    __inline_Card_CardResetCard((arg1), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_CopyTuple(struct CardHandle * __arg1, UBYTE * __arg2, ULONG __arg3, ULONG __arg4, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC4(BOOL, CopyTuple,
        AROS_LCA(struct CardHandle *,(__arg1),A1),
        AROS_LCA(UBYTE *,(__arg2),A0),
        AROS_LCA(ULONG,(__arg3),D1),
        AROS_LCA(ULONG,(__arg4),D0),
        struct Library *, (__CardResource), 12, Card    );
}

#define CopyTuple(arg1, arg2, arg3, arg4) \
    __inline_Card_CopyTuple((arg1), (arg2), (arg3), (arg4), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline ULONG __inline_Card_DeviceTuple(UBYTE * __arg1, struct DeviceTData * __arg2, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC2(ULONG, DeviceTuple,
        AROS_LCA(UBYTE *,(__arg1),A0),
        AROS_LCA(struct DeviceTData *,(__arg2),A1),
        struct Library *, (__CardResource), 13, Card    );
}

#define DeviceTuple(arg1, arg2) \
    __inline_Card_DeviceTuple((arg1), (arg2), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline struct Resident * __inline_Card_IfAmigaXIP(struct CardHandle * __arg1, APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC1(struct Resident *, IfAmigaXIP,
        AROS_LCA(struct CardHandle *,(__arg1),A2),
        struct Library *, (__CardResource), 14, Card    );
}

#define IfAmigaXIP(arg1) \
    __inline_Card_IfAmigaXIP((arg1), __CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline BOOL __inline_Card_CardForceChange(APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC0(BOOL, CardForceChange,
        struct Library *, (__CardResource), 15, Card    );
}

#define CardForceChange() \
    __inline_Card_CardForceChange(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline ULONG __inline_Card_CardChangeCount(APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC0(ULONG, CardChangeCount,
        struct Library *, (__CardResource), 16, Card    );
}

#define CardChangeCount() \
    __inline_Card_CardChangeCount(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#if !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__)

static inline ULONG __inline_Card_CardInterface(APTR __CardResource)
{
    AROS_LIBREQ(CardResource, 41)
    return AROS_LC0(ULONG, CardInterface,
        struct Library *, (__CardResource), 17, Card    );
}

#define CardInterface() \
    __inline_Card_CardInterface(__CARDRES_LIBBASE)

#endif /* !defined(__CARDRES_LIBAPI__) || (41 <= __CARDRES_LIBAPI__) */

#endif /* INLINE_CARDRES_H*/
