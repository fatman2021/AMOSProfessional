#ifndef INLINE_MATHIEEESINGTRANS_H
#define INLINE_MATHIEEESINGTRANS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeesingtrans/mathieeesingtrans.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathieeesingtrans
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEESINGTRANS_LIBBASE)
#    define __MATHIEEESINGTRANS_LIBBASE MathIeeeSingTransBase
#endif


#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPAtan(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPAtan,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 5, MathIeeeSingTrans    );
}

#define IEEESPAtan(arg1) \
    __inline_MathIeeeSingTrans_IEEESPAtan((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPSin(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPSin,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 6, MathIeeeSingTrans    );
}

#define IEEESPSin(arg1) \
    __inline_MathIeeeSingTrans_IEEESPSin((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPCos(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPCos,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 7, MathIeeeSingTrans    );
}

#define IEEESPCos(arg1) \
    __inline_MathIeeeSingTrans_IEEESPCos((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPTan(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPTan,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 8, MathIeeeSingTrans    );
}

#define IEEESPTan(arg1) \
    __inline_MathIeeeSingTrans_IEEESPTan((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPSincos(LONG * __arg1, LONG __arg2, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC2(LONG, IEEESPSincos,
        AROS_LCA(LONG *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathIeeeSingTransBase), 9, MathIeeeSingTrans    );
}

#define IEEESPSincos(arg1, arg2) \
    __inline_MathIeeeSingTrans_IEEESPSincos((arg1), (arg2), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPSinh(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPSinh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 10, MathIeeeSingTrans    );
}

#define IEEESPSinh(arg1) \
    __inline_MathIeeeSingTrans_IEEESPSinh((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPCosh(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPCosh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 11, MathIeeeSingTrans    );
}

#define IEEESPCosh(arg1) \
    __inline_MathIeeeSingTrans_IEEESPCosh((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPTanh(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPTanh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 12, MathIeeeSingTrans    );
}

#define IEEESPTanh(arg1) \
    __inline_MathIeeeSingTrans_IEEESPTanh((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPExp(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPExp,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 13, MathIeeeSingTrans    );
}

#define IEEESPExp(arg1) \
    __inline_MathIeeeSingTrans_IEEESPExp((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPLog(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPLog,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 14, MathIeeeSingTrans    );
}

#define IEEESPLog(arg1) \
    __inline_MathIeeeSingTrans_IEEESPLog((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPPow(LONG __arg1, LONG __arg2, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC2(LONG, IEEESPPow,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathIeeeSingTransBase), 15, MathIeeeSingTrans    );
}

#define IEEESPPow(arg1, arg2) \
    __inline_MathIeeeSingTrans_IEEESPPow((arg1), (arg2), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPSqrt(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPSqrt,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 16, MathIeeeSingTrans    );
}

#define IEEESPSqrt(arg1) \
    __inline_MathIeeeSingTrans_IEEESPSqrt((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPTieee(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPTieee,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 17, MathIeeeSingTrans    );
}

#define IEEESPTieee(arg1) \
    __inline_MathIeeeSingTrans_IEEESPTieee((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPFieee(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPFieee,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 18, MathIeeeSingTrans    );
}

#define IEEESPFieee(arg1) \
    __inline_MathIeeeSingTrans_IEEESPFieee((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPAsin(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPAsin,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 19, MathIeeeSingTrans    );
}

#define IEEESPAsin(arg1) \
    __inline_MathIeeeSingTrans_IEEESPAsin((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPAcos(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPAcos,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 20, MathIeeeSingTrans    );
}

#define IEEESPAcos(arg1) \
    __inline_MathIeeeSingTrans_IEEESPAcos((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#if !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__)

static inline LONG __inline_MathIeeeSingTrans_IEEESPLog10(LONG __arg1, APTR __MathIeeeSingTransBase)
{
    AROS_LIBREQ(MathIeeeSingTransBase, 41)
    return AROS_LC1(LONG, IEEESPLog10,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathIeeeSingTransBase), 21, MathIeeeSingTrans    );
}

#define IEEESPLog10(arg1) \
    __inline_MathIeeeSingTrans_IEEESPLog10((arg1), __MATHIEEESINGTRANS_LIBBASE)

#endif /* !defined(__MATHIEEESINGTRANS_LIBAPI__) || (41 <= __MATHIEEESINGTRANS_LIBAPI__) */

#endif /* INLINE_MATHIEEESINGTRANS_H*/
