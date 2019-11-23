#ifndef CLIB_HPET_PROTOS_H
#define CLIB_HPET_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/all-pc/hpet/hpet.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)
AROS_LP0(ULONG, GetHPETCount,
         LIBBASETYPEPTR, HPETBase, 1, Hpet
);

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)
AROS_LP1(ULONG, AllocHPETUnit,
         AROS_LPA(const char *, user, A0),
         LIBBASETYPEPTR, HPETBase, 2, Hpet
);

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)
AROS_LP1(void, FreeHPETUnit,
         AROS_LPA(ULONG, unit, D0),
         LIBBASETYPEPTR, HPETBase, 3, Hpet
);

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)
AROS_LP2(BOOL, GetUnitAttrsA,
         AROS_LPA(ULONG, unit, D0),
         AROS_LPA(const struct TagItem *, tags, A0),
         LIBBASETYPEPTR, HPETBase, 4, Hpet
);

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

__END_DECLS

#endif /* CLIB_HPET_PROTOS_H */
