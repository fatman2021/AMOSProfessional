#ifndef DEFINES_TIMER_H
#define DEFINES_TIMER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/timer/timer.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for timer
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__TIMER_LIBBASE)
#    define __TIMER_LIBBASE TimerBase
#endif

__BEGIN_DECLS


#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __AddTime_WB(__TimerBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC2NR(void, AddTime, \
                  AROS_LCA(struct timeval *,(__arg1),A0), \
                  AROS_LCA(struct timeval *,(__arg2),A1), \
        struct Device *, (__TimerBase), 7, Timer);\
})

#define AddTime(arg1, arg2) \
    __AddTime_WB(__TIMER_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __SubTime_WB(__TimerBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC2NR(void, SubTime, \
                  AROS_LCA(struct timeval *,(__arg1),A0), \
                  AROS_LCA(struct timeval *,(__arg2),A1), \
        struct Device *, (__TimerBase), 8, Timer);\
})

#define SubTime(arg1, arg2) \
    __SubTime_WB(__TIMER_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __CmpTime_WB(__TimerBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC2(LONG, CmpTime, \
                  AROS_LCA(struct timeval *,(__arg1),A0), \
                  AROS_LCA(struct timeval *,(__arg2),A1), \
        struct Device *, (__TimerBase), 9, Timer);\
})

#define CmpTime(arg1, arg2) \
    __CmpTime_WB(__TIMER_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __ReadEClock_WB(__TimerBase, __arg1) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC1(ULONG, ReadEClock, \
                  AROS_LCA(struct EClockVal *,(__arg1),A0), \
        struct Device *, (__TimerBase), 10, Timer);\
})

#define ReadEClock(arg1) \
    __ReadEClock_WB(__TIMER_LIBBASE, (arg1))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __GetSysTime_WB(__TimerBase, __arg1) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC1NR(void, GetSysTime, \
                  AROS_LCA(struct timeval *,(__arg1),A0), \
        struct Device *, (__TimerBase), 11, Timer);\
})

#define GetSysTime(arg1) \
    __GetSysTime_WB(__TIMER_LIBBASE, (arg1))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

#if !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__)

#define __GetUpTime_WB(__TimerBase, __arg1) ({\
        AROS_LIBREQ(TimerBase,0)\
        AROS_LC1NR(void, GetUpTime, \
                  AROS_LCA(struct timeval *,(__arg1),A0), \
        struct Device *, (__TimerBase), 12, Timer);\
})

#define GetUpTime(arg1) \
    __GetUpTime_WB(__TIMER_LIBBASE, (arg1))

#endif /* !defined(__TIMER_LIBAPI__) || (0 <= __TIMER_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_TIMER_H*/
