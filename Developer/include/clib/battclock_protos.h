#ifndef CLIB_BATTCLOCK_PROTOS_H
#define CLIB_BATTCLOCK_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/battclock/battclock.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)
AROS_LP0(void, ResetBattClock,
         LIBBASETYPEPTR, BattClockBase, 1, Battclock
);

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)
AROS_LP0(ULONG, ReadBattClock,
         LIBBASETYPEPTR, BattClockBase, 2, Battclock
);

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

#if !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__)
AROS_LP1(void, WriteBattClock,
         AROS_LPA(ULONG, time, D0),
         LIBBASETYPEPTR, BattClockBase, 3, Battclock
);

#endif /* !defined(__BATTCLOCK_LIBAPI__) || (41 <= __BATTCLOCK_LIBAPI__) */

__END_DECLS

#endif /* CLIB_BATTCLOCK_PROTOS_H */
