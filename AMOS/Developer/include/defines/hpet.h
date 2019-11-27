#ifndef DEFINES_HPET_H
#define DEFINES_HPET_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/all-pc/hpet/hpet.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for hpet
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__HPET_LIBBASE)
#    define __HPET_LIBBASE HPETBase
#endif

__BEGIN_DECLS


#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

#define __GetHPETCount_WB(__HPETBase) ({\
        AROS_LIBREQ(HPETBase,1)\
        AROS_LC0(ULONG, GetHPETCount, \
        APTR , (__HPETBase), 1, Hpet);\
})

#define GetHPETCount() \
    __GetHPETCount_WB(__HPET_LIBBASE)

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

#define __AllocHPETUnit_WB(__HPETBase, __arg1) ({\
        AROS_LIBREQ(HPETBase,1)\
        AROS_LC1(ULONG, AllocHPETUnit, \
                  AROS_LCA(const char *,(__arg1),A0), \
        APTR , (__HPETBase), 2, Hpet);\
})

#define AllocHPETUnit(arg1) \
    __AllocHPETUnit_WB(__HPET_LIBBASE, (arg1))

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

#define __FreeHPETUnit_WB(__HPETBase, __arg1) ({\
        AROS_LIBREQ(HPETBase,1)\
        AROS_LC1NR(void, FreeHPETUnit, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        APTR , (__HPETBase), 3, Hpet);\
})

#define FreeHPETUnit(arg1) \
    __FreeHPETUnit_WB(__HPET_LIBBASE, (arg1))

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

#define __GetUnitAttrsA_WB(__HPETBase, __arg1, __arg2) ({\
        AROS_LIBREQ(HPETBase,1)\
        AROS_LC2(BOOL, GetUnitAttrsA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(const struct TagItem *,(__arg2),A0), \
        APTR , (__HPETBase), 4, Hpet);\
})

#define GetUnitAttrsA(arg1, arg2) \
    __GetUnitAttrsA_WB(__HPET_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(HPET_NO_INLINE_STDARG)
#define GetUnitAttrs(arg1, ...) \
({ \
    const IPTR GetUnitAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetUnitAttrsA((arg1), (const struct TagItem *)(GetUnitAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_HPET_H*/
