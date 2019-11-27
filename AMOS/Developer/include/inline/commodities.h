#ifndef INLINE_COMMODITIES_H
#define INLINE_COMMODITIES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/commodities/commodities.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for commodities
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COMMODITIES_LIBBASE)
#    define __COMMODITIES_LIBBASE CxBase
#endif


#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline CxObj * __inline_Commodities_CreateCxObj(ULONG __arg1, IPTR __arg2, IPTR __arg3, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC3(CxObj *, CreateCxObj,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(IPTR,(__arg2),A0),
        AROS_LCA(IPTR,(__arg3),A1),
        struct Library *, (__CxBase), 5, Commodities    );
}

#define CreateCxObj(arg1, arg2, arg3) \
    __inline_Commodities_CreateCxObj((arg1), (arg2), (arg3), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline CxObj * __inline_Commodities_CxBroker(struct NewBroker * __arg1, LONG * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(CxObj *, CxBroker,
        AROS_LCA(struct NewBroker *,(__arg1),A0),
        AROS_LCA(LONG *,(__arg2),D0),
        struct Library *, (__CxBase), 6, Commodities    );
}

#define CxBroker(arg1, arg2) \
    __inline_Commodities_CxBroker((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_ActivateCxObj(CxObj * __arg1, LONG __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(LONG, ActivateCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__CxBase), 7, Commodities    );
}

#define ActivateCxObj(arg1, arg2) \
    __inline_Commodities_ActivateCxObj((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_DeleteCxObj(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, DeleteCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 8, Commodities    );
}

#define DeleteCxObj(arg1) \
    __inline_Commodities_DeleteCxObj((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_DeleteCxObjAll(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, DeleteCxObjAll,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 9, Commodities    );
}

#define DeleteCxObjAll(arg1) \
    __inline_Commodities_DeleteCxObjAll((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline ULONG __inline_Commodities_CxObjType(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(ULONG, CxObjType,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 10, Commodities    );
}

#define CxObjType(arg1) \
    __inline_Commodities_CxObjType((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_CxObjError(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(LONG, CxObjError,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 11, Commodities    );
}

#define CxObjError(arg1) \
    __inline_Commodities_CxObjError((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_ClearCxObjError(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, ClearCxObjError,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 12, Commodities    );
}

#define ClearCxObjError(arg1) \
    __inline_Commodities_ClearCxObjError((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_SetCxObjPri(CxObj * __arg1, LONG __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(LONG, SetCxObjPri,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__CxBase), 13, Commodities    );
}

#define SetCxObjPri(arg1, arg2) \
    __inline_Commodities_SetCxObjPri((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_AttachCxObj(CxObj * __arg1, CxObj * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, AttachCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(CxObj *,(__arg2),A1),
        struct Library *, (__CxBase), 14, Commodities    );
}

#define AttachCxObj(arg1, arg2) \
    __inline_Commodities_AttachCxObj((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_EnqueueCxObj(CxObj * __arg1, CxObj * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, EnqueueCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(CxObj *,(__arg2),A1),
        struct Library *, (__CxBase), 15, Commodities    );
}

#define EnqueueCxObj(arg1, arg2) \
    __inline_Commodities_EnqueueCxObj((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_InsertCxObj(CxObj * __arg1, CxObj * __arg2, CxObj * __arg3, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC3NR(void, InsertCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(CxObj *,(__arg2),A1),
        AROS_LCA(CxObj *,(__arg3),A2),
        struct Library *, (__CxBase), 16, Commodities    );
}

#define InsertCxObj(arg1, arg2, arg3) \
    __inline_Commodities_InsertCxObj((arg1), (arg2), (arg3), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_RemoveCxObj(CxObj * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, RemoveCxObj,
        AROS_LCA(CxObj *,(__arg1),A0),
        struct Library *, (__CxBase), 17, Commodities    );
}

#define RemoveCxObj(arg1) \
    __inline_Commodities_RemoveCxObj((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_SetTranslate(CxObj * __arg1, struct InputEvent * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, SetTranslate,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(struct InputEvent *,(__arg2),A1),
        struct Library *, (__CxBase), 19, Commodities    );
}

#define SetTranslate(arg1, arg2) \
    __inline_Commodities_SetTranslate((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_SetFilter(CxObj * __arg1, STRPTR __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, SetFilter,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        struct Library *, (__CxBase), 20, Commodities    );
}

#define SetFilter(arg1, arg2) \
    __inline_Commodities_SetFilter((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_SetFilterIX(CxObj * __arg1, IX * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, SetFilterIX,
        AROS_LCA(CxObj *,(__arg1),A0),
        AROS_LCA(IX *,(__arg2),A1),
        struct Library *, (__CxBase), 21, Commodities    );
}

#define SetFilterIX(arg1, arg2) \
    __inline_Commodities_SetFilterIX((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_ParseIX(CONST_STRPTR __arg1, IX * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(LONG, ParseIX,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(IX *,(__arg2),A1),
        struct Library *, (__CxBase), 22, Commodities    );
}

#define ParseIX(arg1, arg2) \
    __inline_Commodities_ParseIX((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline ULONG __inline_Commodities_CxMsgType(CxMsg * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(ULONG, CxMsgType,
        AROS_LCA(CxMsg *,(__arg1),A0),
        struct Library *, (__CxBase), 23, Commodities    );
}

#define CxMsgType(arg1) \
    __inline_Commodities_CxMsgType((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline APTR __inline_Commodities_CxMsgData(CxMsg * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(APTR, CxMsgData,
        AROS_LCA(CxMsg *,(__arg1),A0),
        struct Library *, (__CxBase), 24, Commodities    );
}

#define CxMsgData(arg1) \
    __inline_Commodities_CxMsgData((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_CxMsgID(CxMsg * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(LONG, CxMsgID,
        AROS_LCA(CxMsg *,(__arg1),A0),
        struct Library *, (__CxBase), 25, Commodities    );
}

#define CxMsgID(arg1) \
    __inline_Commodities_CxMsgID((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_DivertCxMsg(CxMsg * __arg1, CxObj * __arg2, CxObj * __arg3, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC3NR(void, DivertCxMsg,
        AROS_LCA(CxMsg *,(__arg1),A0),
        AROS_LCA(CxObj *,(__arg2),A1),
        AROS_LCA(CxObj *,(__arg3),A2),
        struct Library *, (__CxBase), 26, Commodities    );
}

#define DivertCxMsg(arg1, arg2, arg3) \
    __inline_Commodities_DivertCxMsg((arg1), (arg2), (arg3), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_RouteCxMsg(CxMsg * __arg1, CxObj * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC2NR(void, RouteCxMsg,
        AROS_LCA(CxMsg *,(__arg1),A0),
        AROS_LCA(CxObj *,(__arg2),A1),
        struct Library *, (__CxBase), 27, Commodities    );
}

#define RouteCxMsg(arg1, arg2) \
    __inline_Commodities_RouteCxMsg((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_DisposeCxMsg(CxMsg * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, DisposeCxMsg,
        AROS_LCA(CxMsg *,(__arg1),A0),
        struct Library *, (__CxBase), 28, Commodities    );
}

#define DisposeCxMsg(arg1) \
    __inline_Commodities_DisposeCxMsg((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline BOOL __inline_Commodities_InvertKeyMap(ULONG __arg1, struct InputEvent * __arg2, struct KeyMap * __arg3, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC3(BOOL, InvertKeyMap,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct InputEvent *,(__arg2),A0),
        AROS_LCA(struct KeyMap *,(__arg3),A1),
        struct Library *, (__CxBase), 29, Commodities    );
}

#define InvertKeyMap(arg1, arg2, arg3) \
    __inline_Commodities_InvertKeyMap((arg1), (arg2), (arg3), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_AddIEvents(struct InputEvent * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, AddIEvents,
        AROS_LCA(struct InputEvent *,(__arg1),A0),
        struct Library *, (__CxBase), 30, Commodities    );
}

#define AddIEvents(arg1) \
    __inline_Commodities_AddIEvents((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline LONG __inline_Commodities_CopyBrokerList(struct List * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC1(LONG, CopyBrokerList,
        AROS_LCA(struct List *,(__arg1),A0),
        struct Library *, (__CxBase), 31, Commodities    );
}

#define CopyBrokerList(arg1) \
    __inline_Commodities_CopyBrokerList((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline void __inline_Commodities_FreeBrokerList(struct List * __arg1, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    AROS_LC1NR(void, FreeBrokerList,
        AROS_LCA(struct List *,(__arg1),A0),
        struct Library *, (__CxBase), 32, Commodities    );
}

#define FreeBrokerList(arg1) \
    __inline_Commodities_FreeBrokerList((arg1), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline ULONG __inline_Commodities_BrokerCommand(STRPTR __arg1, ULONG __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(ULONG, BrokerCommand,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CxBase), 33, Commodities    );
}

#define BrokerCommand(arg1, arg2) \
    __inline_Commodities_BrokerCommand((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

static inline BOOL __inline_Commodities_MatchIX(struct InputEvent * __arg1, IX * __arg2, APTR __CxBase)
{
    AROS_LIBREQ(CxBase, 36)
    return AROS_LC2(BOOL, MatchIX,
        AROS_LCA(struct InputEvent *,(__arg1),A0),
        AROS_LCA(IX *,(__arg2),A1),
        struct Library *, (__CxBase), 34, Commodities    );
}

#define MatchIX(arg1, arg2) \
    __inline_Commodities_MatchIX((arg1), (arg2), __COMMODITIES_LIBBASE)

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#endif /* INLINE_COMMODITIES_H*/
