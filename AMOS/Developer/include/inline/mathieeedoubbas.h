#ifndef INLINE_MATHIEEEDOUBBAS_H
#define INLINE_MATHIEEEDOUBBAS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeedoubbas/mathieeedoubbas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathieeedoubbas
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEEDOUBBAS_LIBBASE)
#    define __MATHIEEEDOUBBAS_LIBBASE MathIeeeDoubBasBase
#endif


#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline LONG __inline_MathIeeeDoubBas_IEEEDPFix(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD1(LONG, IEEEDPFix,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 5, MathIeeeDoubBas    );
}

#define IEEEDPFix(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPFix((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPFlt(LONG __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LC1(double, IEEEDPFlt,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeDoubBasBase), 6, MathIeeeDoubBas    );
}

#define IEEEDPFlt(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPFlt((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline LONG __inline_MathIeeeDoubBas_IEEEDPCmp(double __arg1, double __arg2, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD2(LONG, IEEEDPCmp,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubBasBase), 7, MathIeeeDoubBas    );
}

#define IEEEDPCmp(arg1, arg2) \
    __inline_MathIeeeDoubBas_IEEEDPCmp((arg1), (arg2), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline LONG __inline_MathIeeeDoubBas_IEEEDPTst(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD1(LONG, IEEEDPTst,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 8, MathIeeeDoubBas    );
}

#define IEEEDPTst(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPTst((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPAbs(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD1(double, IEEEDPAbs,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 9, MathIeeeDoubBas    );
}

#define IEEEDPAbs(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPAbs((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPNeg(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD1(double, IEEEDPNeg,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 10, MathIeeeDoubBas    );
}

#define IEEEDPNeg(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPNeg((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPAdd(double __arg1, double __arg2, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD2(double, IEEEDPAdd,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubBasBase), 11, MathIeeeDoubBas    );
}

#define IEEEDPAdd(arg1, arg2) \
    __inline_MathIeeeDoubBas_IEEEDPAdd((arg1), (arg2), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPSub(double __arg1, double __arg2, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD2(double, IEEEDPSub,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubBasBase), 12, MathIeeeDoubBas    );
}

#define IEEEDPSub(arg1, arg2) \
    __inline_MathIeeeDoubBas_IEEEDPSub((arg1), (arg2), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPMul(double __arg1, double __arg2, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD2(double, IEEEDPMul,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubBasBase), 13, MathIeeeDoubBas    );
}

#define IEEEDPMul(arg1, arg2) \
    __inline_MathIeeeDoubBas_IEEEDPMul((arg1), (arg2), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPDiv(double __arg1, double __arg2, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 0)
    return AROS_LCQUAD2(double, IEEEDPDiv,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubBasBase), 14, MathIeeeDoubBas    );
}

#define IEEEDPDiv(arg1, arg2) \
    __inline_MathIeeeDoubBas_IEEEDPDiv((arg1), (arg2), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPFloor(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 33)
    return AROS_LCQUAD1(double, IEEEDPFloor,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 15, MathIeeeDoubBas    );
}

#define IEEEDPFloor(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPFloor((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)

static inline double __inline_MathIeeeDoubBas_IEEEDPCeil(double __arg1, APTR __MathIeeeDoubBasBase)
{
    AROS_LIBREQ(MathIeeeDoubBasBase, 33)
    return AROS_LCQUAD1(double, IEEEDPCeil,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubBasBase), 16, MathIeeeDoubBas    );
}

#define IEEEDPCeil(arg1) \
    __inline_MathIeeeDoubBas_IEEEDPCeil((arg1), __MATHIEEEDOUBBAS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#endif /* INLINE_MATHIEEEDOUBBAS_H*/
