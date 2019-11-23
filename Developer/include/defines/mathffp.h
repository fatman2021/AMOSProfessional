#ifndef DEFINES_MATHFFP_H
#define DEFINES_MATHFFP_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathffp/mathffp.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for mathffp
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHFFP_LIBBASE)
#    define __MATHFFP_LIBBASE MathBase
#endif

__BEGIN_DECLS


#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPFix_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC1(LONG, SPFix, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 5, Mathffp);\
})

#define SPFix(arg1) \
    __SPFix_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPFlt_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC1(LONG, SPFlt, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 6, Mathffp);\
})

#define SPFlt(arg1) \
    __SPFlt_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPCmp_WB(__MathBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC2(LONG, SPCmp, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathBase), 7, Mathffp);\
})

#define SPCmp(arg1, arg2) \
    __SPCmp_WB(__MATHFFP_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPTst_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC1(LONG, SPTst, \
                  AROS_LCA(LONG,(__arg1),D1), \
        struct Library *, (__MathBase), 8, Mathffp);\
})

#define SPTst(arg1) \
    __SPTst_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPAbs_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC1(LONG, SPAbs, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 9, Mathffp);\
})

#define SPAbs(arg1) \
    __SPAbs_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPNeg_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC1(LONG, SPNeg, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 10, Mathffp);\
})

#define SPNeg(arg1) \
    __SPNeg_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPAdd_WB(__MathBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC2(LONG, SPAdd, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathBase), 11, Mathffp);\
})

#define SPAdd(arg1, arg2) \
    __SPAdd_WB(__MATHFFP_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPSub_WB(__MathBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC2(LONG, SPSub, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathBase), 12, Mathffp);\
})

#define SPSub(arg1, arg2) \
    __SPSub_WB(__MATHFFP_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPMul_WB(__MathBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC2(LONG, SPMul, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathBase), 13, Mathffp);\
})

#define SPMul(arg1, arg2) \
    __SPMul_WB(__MATHFFP_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__)

#define __SPDiv_WB(__MathBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathBase,0)\
        AROS_LC2(LONG, SPDiv, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathBase), 14, Mathffp);\
})

#define SPDiv(arg1, arg2) \
    __SPDiv_WB(__MATHFFP_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHFFP_LIBAPI__) || (0 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__)

#define __SPFloor_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,33)\
        AROS_LC1(LONG, SPFloor, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 15, Mathffp);\
})

#define SPFloor(arg1) \
    __SPFloor_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__) */

#if !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__)

#define __SPCeil_WB(__MathBase, __arg1) ({\
        AROS_LIBREQ(MathBase,33)\
        AROS_LC1(LONG, SPCeil, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathBase), 16, Mathffp);\
})

#define SPCeil(arg1) \
    __SPCeil_WB(__MATHFFP_LIBBASE, (arg1))

#endif /* !defined(__MATHFFP_LIBAPI__) || (33 <= __MATHFFP_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MATHFFP_H*/
