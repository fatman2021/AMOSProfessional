#ifndef INLINE_MATHIEEEDOUBTRANS_H
#define INLINE_MATHIEEEDOUBTRANS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeedoubtrans/mathieeedoubtrans.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathieeedoubtrans
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEEDOUBTRANS_LIBBASE)
#    define __MATHIEEEDOUBTRANS_LIBBASE MathIeeeDoubTransBase
#endif


#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPAtan(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPAtan,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 5, MathIeeeDoubTrans    );
}

#define IEEEDPAtan(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPAtan((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPSin(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPSin,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 6, MathIeeeDoubTrans    );
}

#define IEEEDPSin(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPSin((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPCos(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPCos,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 7, MathIeeeDoubTrans    );
}

#define IEEEDPCos(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPCos((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPTan(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPTan,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 8, MathIeeeDoubTrans    );
}

#define IEEEDPTan(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPTan((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPSincos(double * __arg1, double __arg2, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LC1QUAD1(double, IEEEDPSincos,
         AROS_LCA(double *, (__arg1), A0), 
         AROS_LCAQUAD(double, (__arg2), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 9, MathIeeeDoubTrans    );
}

#define IEEEDPSincos(arg1, arg2) \
    __inline_MathIeeeDoubTrans_IEEEDPSincos((arg1), (arg2), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPSinh(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPSinh,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 10, MathIeeeDoubTrans    );
}

#define IEEEDPSinh(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPSinh((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPCosh(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPCosh,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 11, MathIeeeDoubTrans    );
}

#define IEEEDPCosh(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPCosh((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPTanh(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPTanh,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 12, MathIeeeDoubTrans    );
}

#define IEEEDPTanh(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPTanh((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPExp(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPExp,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 13, MathIeeeDoubTrans    );
}

#define IEEEDPExp(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPExp((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPLog(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPLog,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 14, MathIeeeDoubTrans    );
}

#define IEEEDPLog(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPLog((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPPow(double __arg1, double __arg2, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD2(double, IEEEDPPow,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
         AROS_LCAQUAD(double, (__arg2), D2, D3), 
        struct Library *, (__MathIeeeDoubTransBase), 15, MathIeeeDoubTrans    );
}

#define IEEEDPPow(arg1, arg2) \
    __inline_MathIeeeDoubTrans_IEEEDPPow((arg1), (arg2), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPSqrt(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPSqrt,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 16, MathIeeeDoubTrans    );
}

#define IEEEDPSqrt(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPSqrt((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeDoubTrans_IEEEDPTieee(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(LONG, IEEEDPTieee,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 17, MathIeeeDoubTrans    );
}

#define IEEEDPTieee(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPTieee((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPFieee(LONG __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LC1(double, IEEEDPFieee,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeDoubTransBase), 18, MathIeeeDoubTrans    );
}

#define IEEEDPFieee(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPFieee((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPAsin(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPAsin,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 19, MathIeeeDoubTrans    );
}

#define IEEEDPAsin(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPAsin((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPAcos(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPAcos,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 20, MathIeeeDoubTrans    );
}

#define IEEEDPAcos(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPAcos((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

static inline double __inline_MathIeeeDoubTrans_IEEEDPLog10(double __arg1, APTR __MathIeeeDoubTransBase)
{
    AROS_LIBREQ(MathIeeeDoubTransBase, 41)
    return AROS_LCQUAD1(double, IEEEDPLog10,
         AROS_LCAQUAD(double, (__arg1), D0, D1), 
        struct Library *, (__MathIeeeDoubTransBase), 21, MathIeeeDoubTrans    );
}

#define IEEEDPLog10(arg1) \
    __inline_MathIeeeDoubTrans_IEEEDPLog10((arg1), __MATHIEEEDOUBTRANS_LIBBASE)

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#endif /* INLINE_MATHIEEEDOUBTRANS_H*/
