#ifndef INLINE_BATTCLOCK_H
#define INLINE_BATTCLOCK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/battclock/battclock.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for battclock
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__BATTCLOCK_LIBBASE)
#    define __BATTCLOCK_LIBBASE BattClockBase
#endif


#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

static inline void __inline_Battclock_ResetBattClock(APTR __BattClockBase)
{
    AROS_LIBREQ(BattClockBase, 41)
    AROS_LC0NR(void, ResetBattClock,
        struct Library *, (__BattClockBase), 1, Battclock    );
}

#define ResetBattClock() \
    __inline_Battclock_ResetBattClock(__BATTCLOCK_LIBBASE)

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

static inline ULONG __inline_Battclock_ReadBattClock(APTR __BattClockBase)
{
    AROS_LIBREQ(BattClockBase, 41)
    return AROS_LC0(ULONG, ReadBattClock,
        struct Library *, (__BattClockBase), 2, Battclock    );
}

#define ReadBattClock() \
    __inline_Battclock_ReadBattClock(__BATTCLOCK_LIBBASE)

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)

static inline void __inline_Battclock_WriteBattClock(ULONG __arg1, APTR __BattClockBase)
{
    AROS_LIBREQ(BattClockBase, 41)
    AROS_LC1NR(void, WriteBattClock,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__BattClockBase), 3, Battclock    );
}

#define WriteBattClock(arg1) \
    __inline_Battclock_WriteBattClock((arg1), __BATTCLOCK_LIBBASE)

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#endif /* INLINE_BATTCLOCK_H*/
