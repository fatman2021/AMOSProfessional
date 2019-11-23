#ifndef INLINE_REALTIME_H
#define INLINE_REALTIME_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/realtime/realtime.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for realtime
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REALTIME_LIBBASE)
#    define __REALTIME_LIBBASE RealTimeBase
#endif


#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline APTR __inline_RealTime_LockRealTime(ULONG __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC1(APTR, LockRealTime,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__RealTimeBase), 5, RealTime    );
}

#define LockRealTime(arg1) \
    __inline_RealTime_LockRealTime((arg1), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline void __inline_RealTime_UnlockRealTime(APTR __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    AROS_LC1NR(void, UnlockRealTime,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__RealTimeBase), 6, RealTime    );
}

#define UnlockRealTime(arg1) \
    __inline_RealTime_UnlockRealTime((arg1), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline struct Player * __inline_RealTime_CreatePlayerA(struct TagItem * __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC1(struct Player *, CreatePlayerA,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct Library *, (__RealTimeBase), 7, RealTime    );
}

#define CreatePlayerA(arg1) \
    __inline_RealTime_CreatePlayerA((arg1), __REALTIME_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REALTIME_NO_INLINE_STDARG)
#define CreatePlayer(...) \
({ \
    const IPTR CreatePlayerA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreatePlayerA((struct TagItem *)(CreatePlayerA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline void __inline_RealTime_DeletePlayer(struct Player * __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    AROS_LC1NR(void, DeletePlayer,
        AROS_LCA(struct Player *,(__arg1),A0),
        struct Library *, (__RealTimeBase), 8, RealTime    );
}

#define DeletePlayer(arg1) \
    __inline_RealTime_DeletePlayer((arg1), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline BOOL __inline_RealTime_SetPlayerAttrsA(struct Player * __arg1, struct TagItem * __arg2, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC2(BOOL, SetPlayerAttrsA,
        AROS_LCA(struct Player *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__RealTimeBase), 9, RealTime    );
}

#define SetPlayerAttrsA(arg1, arg2) \
    __inline_RealTime_SetPlayerAttrsA((arg1), (arg2), __REALTIME_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REALTIME_NO_INLINE_STDARG)
#define SetPlayerAttrs(arg1, ...) \
({ \
    const IPTR SetPlayerAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPlayerAttrsA((arg1), (struct TagItem *)(SetPlayerAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline LONG __inline_RealTime_SetConductorState(struct Player * __arg1, ULONG __arg2, LONG __arg3, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC3(LONG, SetConductorState,
        AROS_LCA(struct Player *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__RealTimeBase), 10, RealTime    );
}

#define SetConductorState(arg1, arg2, arg3) \
    __inline_RealTime_SetConductorState((arg1), (arg2), (arg3), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline BOOL __inline_RealTime_ExternalSync(struct Player * __arg1, LONG __arg2, LONG __arg3, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC3(BOOL, ExternalSync,
        AROS_LCA(struct Player *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__RealTimeBase), 11, RealTime    );
}

#define ExternalSync(arg1, arg2, arg3) \
    __inline_RealTime_ExternalSync((arg1), (arg2), (arg3), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline struct Conductor * __inline_RealTime_NextConductor(struct Conductor * __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC1(struct Conductor *, NextConductor,
        AROS_LCA(struct Conductor *,(__arg1),A0),
        struct Library *, (__RealTimeBase), 12, RealTime    );
}

#define NextConductor(arg1) \
    __inline_RealTime_NextConductor((arg1), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline struct Conductor * __inline_RealTime_FindConductor(STRPTR __arg1, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC1(struct Conductor *, FindConductor,
        AROS_LCA(STRPTR,(__arg1),A0),
        struct Library *, (__RealTimeBase), 13, RealTime    );
}

#define FindConductor(arg1) \
    __inline_RealTime_FindConductor((arg1), __REALTIME_LIBBASE)

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#if !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__)

static inline BOOL __inline_RealTime_GetPlayerAttrsA(struct Player * __arg1, struct TagItem * __arg2, APTR __RealTimeBase)
{
    AROS_LIBREQ(RealTimeBase, 37)
    return AROS_LC2(BOOL, GetPlayerAttrsA,
        AROS_LCA(struct Player *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__RealTimeBase), 14, RealTime    );
}

#define GetPlayerAttrsA(arg1, arg2) \
    __inline_RealTime_GetPlayerAttrsA((arg1), (arg2), __REALTIME_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REALTIME_NO_INLINE_STDARG)
#define GetPlayerAttrs(arg1, ...) \
({ \
    const IPTR GetPlayerAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetPlayerAttrsA((arg1), (struct TagItem *)(GetPlayerAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REALTIME_LIBAPI__) || (37 <= __REALTIME_LIBAPI__) */

#endif /* INLINE_REALTIME_H*/
