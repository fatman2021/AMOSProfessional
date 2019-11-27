#ifndef DEFINES_POTGO_H
#define DEFINES_POTGO_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/potgo/potgo.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for potgo
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__POTGO_LIBBASE)
#    define __POTGO_LIBBASE PotgoBase
#endif

__BEGIN_DECLS


#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

#define __AllocPotBits_WB(__PotgoBase, __arg1) ({\
        AROS_LIBREQ(PotgoBase,41)\
        AROS_LC1(UWORD, AllocPotBits, \
                  AROS_LCA(UWORD,(__arg1),D0), \
        struct Library *, (__PotgoBase), 1, Potgo);\
})

#define AllocPotBits(arg1) \
    __AllocPotBits_WB(__POTGO_LIBBASE, (arg1))

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

#define __FreePotBits_WB(__PotgoBase, __arg1) ({\
        AROS_LIBREQ(PotgoBase,41)\
        AROS_LC1NR(void, FreePotBits, \
                  AROS_LCA(UWORD,(__arg1),D0), \
        struct Library *, (__PotgoBase), 2, Potgo);\
})

#define FreePotBits(arg1) \
    __FreePotBits_WB(__POTGO_LIBBASE, (arg1))

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

#define __WritePotgo_WB(__PotgoBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PotgoBase,41)\
        AROS_LC2NR(void, WritePotgo, \
                  AROS_LCA(UWORD,(__arg1),D0), \
                  AROS_LCA(UWORD,(__arg2),D1), \
        struct Library *, (__PotgoBase), 3, Potgo);\
})

#define WritePotgo(arg1, arg2) \
    __WritePotgo_WB(__POTGO_LIBBASE, (arg1), (arg2))

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_POTGO_H*/
