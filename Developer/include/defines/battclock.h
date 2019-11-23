#ifndef DEFINES_BATTCLOCK_H
#define DEFINES_BATTCLOCK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/battclock/battclock.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for battclock
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__BATTCLOCK_LIBBASE)
#    define __BATTCLOCK_LIBBASE BattClockBase
#endif

__BEGIN_DECLS


#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

#define __ResetBattClock_WB(__BattClockBase) ({\
        AROS_LIBREQ(BattClockBase,41)\
        AROS_LC0NR(void, ResetBattClock, \
        struct Library *, (__BattClockBase), 1, Battclock);\
})

#define ResetBattClock() \
    __ResetBattClock_WB(__BATTCLOCK_LIBBASE)

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

#define __ReadBattClock_WB(__BattClockBase) ({\
        AROS_LIBREQ(BattClockBase,41)\
        AROS_LC0(ULONG, ReadBattClock, \
        struct Library *, (__BattClockBase), 2, Battclock);\
})

#define ReadBattClock() \
    __ReadBattClock_WB(__BATTCLOCK_LIBBASE)

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

#define __WriteBattClock_WB(__BattClockBase, __arg1) ({\
        AROS_LIBREQ(BattClockBase,41)\
        AROS_LC1NR(void, WriteBattClock, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__BattClockBase), 3, Battclock);\
})

#define WriteBattClock(arg1) \
    __WriteBattClock_WB(__BATTCLOCK_LIBBASE, (arg1))

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_BATTCLOCK_H*/
