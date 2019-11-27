#ifndef DEFINES_COMMODITIES_H
#define DEFINES_COMMODITIES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/commodities/commodities.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for commodities
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COMMODITIES_LIBBASE)
#    define __COMMODITIES_LIBBASE CxBase
#endif

__BEGIN_DECLS


#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CreateCxObj_WB(__CxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC3(CxObj *, CreateCxObj, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),A0), \
                  AROS_LCA(IPTR,(__arg3),A1), \
        struct Library *, (__CxBase), 5, Commodities);\
})

#define CreateCxObj(arg1, arg2, arg3) \
    __CreateCxObj_WB(__COMMODITIES_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxBroker_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(CxObj *, CxBroker, \
                  AROS_LCA(struct NewBroker *,(__arg1),A0), \
                  AROS_LCA(LONG *,(__arg2),D0), \
        struct Library *, (__CxBase), 6, Commodities);\
})

#define CxBroker(arg1, arg2) \
    __CxBroker_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __ActivateCxObj_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(LONG, ActivateCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__CxBase), 7, Commodities);\
})

#define ActivateCxObj(arg1, arg2) \
    __ActivateCxObj_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __DeleteCxObj_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, DeleteCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 8, Commodities);\
})

#define DeleteCxObj(arg1) \
    __DeleteCxObj_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __DeleteCxObjAll_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, DeleteCxObjAll, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 9, Commodities);\
})

#define DeleteCxObjAll(arg1) \
    __DeleteCxObjAll_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxObjType_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(ULONG, CxObjType, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 10, Commodities);\
})

#define CxObjType(arg1) \
    __CxObjType_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxObjError_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(LONG, CxObjError, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 11, Commodities);\
})

#define CxObjError(arg1) \
    __CxObjError_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __ClearCxObjError_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, ClearCxObjError, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 12, Commodities);\
})

#define ClearCxObjError(arg1) \
    __ClearCxObjError_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __SetCxObjPri_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(LONG, SetCxObjPri, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__CxBase), 13, Commodities);\
})

#define SetCxObjPri(arg1, arg2) \
    __SetCxObjPri_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __AttachCxObj_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, AttachCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(CxObj *,(__arg2),A1), \
        struct Library *, (__CxBase), 14, Commodities);\
})

#define AttachCxObj(arg1, arg2) \
    __AttachCxObj_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __EnqueueCxObj_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, EnqueueCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(CxObj *,(__arg2),A1), \
        struct Library *, (__CxBase), 15, Commodities);\
})

#define EnqueueCxObj(arg1, arg2) \
    __EnqueueCxObj_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __InsertCxObj_WB(__CxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC3NR(void, InsertCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(CxObj *,(__arg2),A1), \
                  AROS_LCA(CxObj *,(__arg3),A2), \
        struct Library *, (__CxBase), 16, Commodities);\
})

#define InsertCxObj(arg1, arg2, arg3) \
    __InsertCxObj_WB(__COMMODITIES_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __RemoveCxObj_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, RemoveCxObj, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
        struct Library *, (__CxBase), 17, Commodities);\
})

#define RemoveCxObj(arg1) \
    __RemoveCxObj_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __SetTranslate_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, SetTranslate, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(struct InputEvent *,(__arg2),A1), \
        struct Library *, (__CxBase), 19, Commodities);\
})

#define SetTranslate(arg1, arg2) \
    __SetTranslate_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __SetFilter_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, SetFilter, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
        struct Library *, (__CxBase), 20, Commodities);\
})

#define SetFilter(arg1, arg2) \
    __SetFilter_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __SetFilterIX_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, SetFilterIX, \
                  AROS_LCA(CxObj *,(__arg1),A0), \
                  AROS_LCA(IX *,(__arg2),A1), \
        struct Library *, (__CxBase), 21, Commodities);\
})

#define SetFilterIX(arg1, arg2) \
    __SetFilterIX_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __ParseIX_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(LONG, ParseIX, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(IX *,(__arg2),A1), \
        struct Library *, (__CxBase), 22, Commodities);\
})

#define ParseIX(arg1, arg2) \
    __ParseIX_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxMsgType_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(ULONG, CxMsgType, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
        struct Library *, (__CxBase), 23, Commodities);\
})

#define CxMsgType(arg1) \
    __CxMsgType_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxMsgData_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(APTR, CxMsgData, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
        struct Library *, (__CxBase), 24, Commodities);\
})

#define CxMsgData(arg1) \
    __CxMsgData_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CxMsgID_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(LONG, CxMsgID, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
        struct Library *, (__CxBase), 25, Commodities);\
})

#define CxMsgID(arg1) \
    __CxMsgID_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __DivertCxMsg_WB(__CxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC3NR(void, DivertCxMsg, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
                  AROS_LCA(CxObj *,(__arg2),A1), \
                  AROS_LCA(CxObj *,(__arg3),A2), \
        struct Library *, (__CxBase), 26, Commodities);\
})

#define DivertCxMsg(arg1, arg2, arg3) \
    __DivertCxMsg_WB(__COMMODITIES_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __RouteCxMsg_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2NR(void, RouteCxMsg, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
                  AROS_LCA(CxObj *,(__arg2),A1), \
        struct Library *, (__CxBase), 27, Commodities);\
})

#define RouteCxMsg(arg1, arg2) \
    __RouteCxMsg_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __DisposeCxMsg_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, DisposeCxMsg, \
                  AROS_LCA(CxMsg *,(__arg1),A0), \
        struct Library *, (__CxBase), 28, Commodities);\
})

#define DisposeCxMsg(arg1) \
    __DisposeCxMsg_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __InvertKeyMap_WB(__CxBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC3(BOOL, InvertKeyMap, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct InputEvent *,(__arg2),A0), \
                  AROS_LCA(struct KeyMap *,(__arg3),A1), \
        struct Library *, (__CxBase), 29, Commodities);\
})

#define InvertKeyMap(arg1, arg2, arg3) \
    __InvertKeyMap_WB(__COMMODITIES_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __AddIEvents_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, AddIEvents, \
                  AROS_LCA(struct InputEvent *,(__arg1),A0), \
        struct Library *, (__CxBase), 30, Commodities);\
})

#define AddIEvents(arg1) \
    __AddIEvents_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __CopyBrokerList_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1(LONG, CopyBrokerList, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct Library *, (__CxBase), 31, Commodities);\
})

#define CopyBrokerList(arg1) \
    __CopyBrokerList_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __FreeBrokerList_WB(__CxBase, __arg1) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC1NR(void, FreeBrokerList, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct Library *, (__CxBase), 32, Commodities);\
})

#define FreeBrokerList(arg1) \
    __FreeBrokerList_WB(__COMMODITIES_LIBBASE, (arg1))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __BrokerCommand_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(ULONG, BrokerCommand, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CxBase), 33, Commodities);\
})

#define BrokerCommand(arg1, arg2) \
    __BrokerCommand_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

#if !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__)

#define __MatchIX_WB(__CxBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CxBase,36)\
        AROS_LC2(BOOL, MatchIX, \
                  AROS_LCA(struct InputEvent *,(__arg1),A0), \
                  AROS_LCA(IX *,(__arg2),A1), \
        struct Library *, (__CxBase), 34, Commodities);\
})

#define MatchIX(arg1, arg2) \
    __MatchIX_WB(__COMMODITIES_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COMMODITIES_LIBAPI__) || (36 <= __COMMODITIES_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_COMMODITIES_H*/
