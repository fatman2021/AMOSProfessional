#ifndef INLINE_HPET_H
#define INLINE_HPET_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/all-pc/hpet/hpet.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for hpet
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__HPET_LIBBASE)
#    define __HPET_LIBBASE HPETBase
#endif


#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

static inline ULONG __inline_Hpet_GetHPETCount(APTR __HPETBase)
{
    AROS_LIBREQ(HPETBase, 1)
    return AROS_LC0(ULONG, GetHPETCount,
        APTR , (__HPETBase), 1, Hpet    );
}

#define GetHPETCount() \
    __inline_Hpet_GetHPETCount(__HPET_LIBBASE)

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

static inline ULONG __inline_Hpet_AllocHPETUnit(const char * __arg1, APTR __HPETBase)
{
    AROS_LIBREQ(HPETBase, 1)
    return AROS_LC1(ULONG, AllocHPETUnit,
        AROS_LCA(const char *,(__arg1),A0),
        APTR , (__HPETBase), 2, Hpet    );
}

#define AllocHPETUnit(arg1) \
    __inline_Hpet_AllocHPETUnit((arg1), __HPET_LIBBASE)

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

static inline void __inline_Hpet_FreeHPETUnit(ULONG __arg1, APTR __HPETBase)
{
    AROS_LIBREQ(HPETBase, 1)
    AROS_LC1NR(void, FreeHPETUnit,
        AROS_LCA(ULONG,(__arg1),D0),
        APTR , (__HPETBase), 3, Hpet    );
}

#define FreeHPETUnit(arg1) \
    __inline_Hpet_FreeHPETUnit((arg1), __HPET_LIBBASE)

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#if !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__)

static inline BOOL __inline_Hpet_GetUnitAttrsA(ULONG __arg1, const struct TagItem * __arg2, APTR __HPETBase)
{
    AROS_LIBREQ(HPETBase, 1)
    return AROS_LC2(BOOL, GetUnitAttrsA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(const struct TagItem *,(__arg2),A0),
        APTR , (__HPETBase), 4, Hpet    );
}

#define GetUnitAttrsA(arg1, arg2) \
    __inline_Hpet_GetUnitAttrsA((arg1), (arg2), __HPET_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(HPET_NO_INLINE_STDARG)
#define GetUnitAttrs(arg1, ...) \
({ \
    const IPTR GetUnitAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetUnitAttrsA((arg1), (const struct TagItem *)(GetUnitAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__HPET_LIBAPI__) || (1 <= __HPET_LIBAPI__) */

#endif /* INLINE_HPET_H*/
