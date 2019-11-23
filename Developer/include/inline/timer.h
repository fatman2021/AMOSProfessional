#ifndef INLINE_TIMER_H
#define INLINE_TIMER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/timer/timer.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for timer
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__TIMER_LIBBASE)
#    define __TIMER_LIBBASE TimerBase
#endif


#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline void __inline_Timer_AddTime(struct timeval * __arg1, struct timeval * __arg2, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    AROS_LC2NR(void, AddTime,
        AROS_LCA(struct timeval *,(__arg1),A0),
        AROS_LCA(struct timeval *,(__arg2),A1),
        struct Device *, (__TimerBase), 7, Timer    );
}

#define AddTime(arg1, arg2) \
    __inline_Timer_AddTime((arg1), (arg2), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline void __inline_Timer_SubTime(struct timeval * __arg1, struct timeval * __arg2, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    AROS_LC2NR(void, SubTime,
        AROS_LCA(struct timeval *,(__arg1),A0),
        AROS_LCA(struct timeval *,(__arg2),A1),
        struct Device *, (__TimerBase), 8, Timer    );
}

#define SubTime(arg1, arg2) \
    __inline_Timer_SubTime((arg1), (arg2), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline LONG __inline_Timer_CmpTime(struct timeval * __arg1, struct timeval * __arg2, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    return AROS_LC2(LONG, CmpTime,
        AROS_LCA(struct timeval *,(__arg1),A0),
        AROS_LCA(struct timeval *,(__arg2),A1),
        struct Device *, (__TimerBase), 9, Timer    );
}

#define CmpTime(arg1, arg2) \
    __inline_Timer_CmpTime((arg1), (arg2), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline ULONG __inline_Timer_ReadEClock(struct EClockVal * __arg1, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    return AROS_LC1(ULONG, ReadEClock,
        AROS_LCA(struct EClockVal *,(__arg1),A0),
        struct Device *, (__TimerBase), 10, Timer    );
}

#define ReadEClock(arg1) \
    __inline_Timer_ReadEClock((arg1), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline void __inline_Timer_GetSysTime(struct timeval * __arg1, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    AROS_LC1NR(void, GetSysTime,
        AROS_LCA(struct timeval *,(__arg1),A0),
        struct Device *, (__TimerBase), 11, Timer    );
}

#define GetSysTime(arg1) \
    __inline_Timer_GetSysTime((arg1), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

static inline void __inline_Timer_GetUpTime(struct timeval * __arg1, APTR __TimerBase)
{
    AROS_LIBREQ(TimerBase, 0)
    AROS_LC1NR(void, GetUpTime,
        AROS_LCA(struct timeval *,(__arg1),A0),
        struct Device *, (__TimerBase), 12, Timer    );
}

#define GetUpTime(arg1) \
    __inline_Timer_GetUpTime((arg1), __TIMER_LIBBASE)

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#endif /* INLINE_TIMER_H*/
