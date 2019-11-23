#ifndef CLIB_POTGO_PROTOS_H
#define CLIB_POTGO_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/potgo/potgo.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)
AROS_LP1(UWORD, AllocPotBits,
         AROS_LPA(UWORD, bits, D0),
         LIBBASETYPEPTR, PotgoBase, 1, Potgo
);

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)
AROS_LP1(void, FreePotBits,
         AROS_LPA(UWORD, allocated, D0),
         LIBBASETYPEPTR, PotgoBase, 2, Potgo
);

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)
AROS_LP2(void, WritePotgo,
         AROS_LPA(UWORD, word, D0),
         AROS_LPA(UWORD, mask, D1),
         LIBBASETYPEPTR, PotgoBase, 3, Potgo
);

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

__END_DECLS

#endif /* CLIB_POTGO_PROTOS_H */
