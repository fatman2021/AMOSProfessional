#ifndef INLINE_POTGO_H
#define INLINE_POTGO_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/potgo/potgo.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for potgo
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__POTGO_LIBBASE)
#    define __POTGO_LIBBASE PotgoBase
#endif


#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

static inline UWORD __inline_Potgo_AllocPotBits(UWORD __arg1, APTR __PotgoBase)
{
    AROS_LIBREQ(PotgoBase, 41)
    return AROS_LC1(UWORD, AllocPotBits,
        AROS_LCA(UWORD,(__arg1),D0),
        struct Library *, (__PotgoBase), 1, Potgo    );
}

#define AllocPotBits(arg1) \
    __inline_Potgo_AllocPotBits((arg1), __POTGO_LIBBASE)

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

static inline void __inline_Potgo_FreePotBits(UWORD __arg1, APTR __PotgoBase)
{
    AROS_LIBREQ(PotgoBase, 41)
    AROS_LC1NR(void, FreePotBits,
        AROS_LCA(UWORD,(__arg1),D0),
        struct Library *, (__PotgoBase), 2, Potgo    );
}

#define FreePotBits(arg1) \
    __inline_Potgo_FreePotBits((arg1), __POTGO_LIBBASE)

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#if !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__)

static inline void __inline_Potgo_WritePotgo(UWORD __arg1, UWORD __arg2, APTR __PotgoBase)
{
    AROS_LIBREQ(PotgoBase, 41)
    AROS_LC2NR(void, WritePotgo,
        AROS_LCA(UWORD,(__arg1),D0),
        AROS_LCA(UWORD,(__arg2),D1),
        struct Library *, (__PotgoBase), 3, Potgo    );
}

#define WritePotgo(arg1, arg2) \
    __inline_Potgo_WritePotgo((arg1), (arg2), __POTGO_LIBBASE)

#endif /* !defined(__POTGO_LIBAPI__) || (41 <= __POTGO_LIBAPI__) */

#endif /* INLINE_POTGO_H*/
