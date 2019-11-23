#ifndef INLINE_MATHFFP_H
#define INLINE_MATHFFP_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathffp/mathffp.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathffp
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHFFP_LIBBASE)
#    define __MATHFFP_LIBBASE MathBase
#endif


#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPFix(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC1(LONG, SPFix,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 5, Mathffp    );
}

#define SPFix(arg1) \
    __inline_Mathffp_SPFix((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPFlt(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC1(LONG, SPFlt,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 6, Mathffp    );
}

#define SPFlt(arg1) \
    __inline_Mathffp_SPFlt((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPCmp(LONG __arg1, LONG __arg2, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC2(LONG, SPCmp,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathBase), 7, Mathffp    );
}

#define SPCmp(arg1, arg2) \
    __inline_Mathffp_SPCmp((arg1), (arg2), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPTst(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC1(LONG, SPTst,
        AROS_LCA(LONG,(__arg1),D1),
        struct Library *, (__MathBase), 8, Mathffp    );
}

#define SPTst(arg1) \
    __inline_Mathffp_SPTst((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPAbs(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC1(LONG, SPAbs,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 9, Mathffp    );
}

#define SPAbs(arg1) \
    __inline_Mathffp_SPAbs((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPNeg(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC1(LONG, SPNeg,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 10, Mathffp    );
}

#define SPNeg(arg1) \
    __inline_Mathffp_SPNeg((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPAdd(LONG __arg1, LONG __arg2, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC2(LONG, SPAdd,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathBase), 11, Mathffp    );
}

#define SPAdd(arg1, arg2) \
    __inline_Mathffp_SPAdd((arg1), (arg2), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPSub(LONG __arg1, LONG __arg2, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC2(LONG, SPSub,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathBase), 12, Mathffp    );
}

#define SPSub(arg1, arg2) \
    __inline_Mathffp_SPSub((arg1), (arg2), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPMul(LONG __arg1, LONG __arg2, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC2(LONG, SPMul,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathBase), 13, Mathffp    );
}

#define SPMul(arg1, arg2) \
    __inline_Mathffp_SPMul((arg1), (arg2), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPDiv(LONG __arg1, LONG __arg2, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 0)
    return AROS_LC2(LONG, SPDiv,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathBase), 14, Mathffp    );
}

#define SPDiv(arg1, arg2) \
    __inline_Mathffp_SPDiv((arg1), (arg2), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPFloor(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 33)
    return AROS_LC1(LONG, SPFloor,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 15, Mathffp    );
}

#define SPFloor(arg1) \
    __inline_Mathffp_SPFloor((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__)

static inline LONG __inline_Mathffp_SPCeil(LONG __arg1, APTR __MathBase)
{
    AROS_LIBREQ(MathBase, 33)
    return AROS_LC1(LONG, SPCeil,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathBase), 16, Mathffp    );
}

#define SPCeil(arg1) \
    __inline_Mathffp_SPCeil((arg1), __MATHFFP_LIBBASE)

#endif /* !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__) */

#endif /* INLINE_MATHFFP_H*/
