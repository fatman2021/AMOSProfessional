#ifndef INLINE_MATHIEEESINGBAS_H
#define INLINE_MATHIEEESINGBAS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeesingbas/mathieeesingbas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathieeesingbas
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEESINGBAS_LIBBASE)
#    define __MATHIEEESINGBAS_LIBBASE MathIeeeSingBasBase
#endif


#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPFix(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPFix,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 5, Mathieeesingbas    );
}

#define IEEESPFix(arg1) \
    __inline_Mathieeesingbas_IEEESPFix((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPFlt(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPFlt,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 6, Mathieeesingbas    );
}

#define IEEESPFlt(arg1) \
    __inline_Mathieeesingbas_IEEESPFlt((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPCmp(LONG __arg1, LONG __arg2, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC2(LONG, IEEESPCmp,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct Library *, (__MathIeeeSingBasBase), 7, Mathieeesingbas    );
}

#define IEEESPCmp(arg1, arg2) \
    __inline_Mathieeesingbas_IEEESPCmp((arg1), (arg2), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPTst(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPTst,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 8, Mathieeesingbas    );
}

#define IEEESPTst(arg1) \
    __inline_Mathieeesingbas_IEEESPTst((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPAbs(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPAbs,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 9, Mathieeesingbas    );
}

#define IEEESPAbs(arg1) \
    __inline_Mathieeesingbas_IEEESPAbs((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPNeg(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPNeg,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 10, Mathieeesingbas    );
}

#define IEEESPNeg(arg1) \
    __inline_Mathieeesingbas_IEEESPNeg((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPAdd(LONG __arg1, LONG __arg2, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC2(LONG, IEEESPAdd,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct Library *, (__MathIeeeSingBasBase), 11, Mathieeesingbas    );
}

#define IEEESPAdd(arg1, arg2) \
    __inline_Mathieeesingbas_IEEESPAdd((arg1), (arg2), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPSub(LONG __arg1, LONG __arg2, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC2(LONG, IEEESPSub,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct Library *, (__MathIeeeSingBasBase), 12, Mathieeesingbas    );
}

#define IEEESPSub(arg1, arg2) \
    __inline_Mathieeesingbas_IEEESPSub((arg1), (arg2), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPMul(LONG __arg1, LONG __arg2, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC2(LONG, IEEESPMul,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct Library *, (__MathIeeeSingBasBase), 13, Mathieeesingbas    );
}

#define IEEESPMul(arg1, arg2) \
    __inline_Mathieeesingbas_IEEESPMul((arg1), (arg2), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPDiv(LONG __arg1, LONG __arg2, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC2(LONG, IEEESPDiv,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct Library *, (__MathIeeeSingBasBase), 14, Mathieeesingbas    );
}

#define IEEESPDiv(arg1, arg2) \
    __inline_Mathieeesingbas_IEEESPDiv((arg1), (arg2), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPFloor(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPFloor,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 15, Mathieeesingbas    );
}

#define IEEESPFloor(arg1) \
    __inline_Mathieeesingbas_IEEESPFloor((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

static inline LONG __inline_Mathieeesingbas_IEEESPCeil(LONG __arg1, APTR __MathIeeeSingBasBase)
{
    AROS_LIBREQ(MathIeeeSingBasBase, 40)
    return AROS_LC1(LONG, IEEESPCeil,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingBasBase), 16, Mathieeesingbas    );
}

#define IEEESPCeil(arg1) \
    __inline_Mathieeesingbas_IEEESPCeil((arg1), __MATHIEEESINGBAS_LIBBASE)

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#endif /* INLINE_MATHIEEESINGBAS_H*/
