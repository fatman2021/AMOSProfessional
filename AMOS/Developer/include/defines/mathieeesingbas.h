#ifndef DEFINES_MATHIEEESINGBAS_H
#define DEFINES_MATHIEEESINGBAS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeesingbas/mathieeesingbas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for mathieeesingbas
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEESINGBAS_LIBBASE)
#    define __MATHIEEESINGBAS_LIBBASE MathIeeeSingBasBase
#endif

__BEGIN_DECLS


#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPFix_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPFix, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 5, Mathieeesingbas);\
})

#define IEEESPFix(arg1) \
    __IEEESPFix_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPFlt_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPFlt, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 6, Mathieeesingbas);\
})

#define IEEESPFlt(arg1) \
    __IEEESPFlt_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPCmp_WB(__MathIeeeSingBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC2(LONG, IEEESPCmp, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct Library *, (__MathIeeeSingBasBase), 7, Mathieeesingbas);\
})

#define IEEESPCmp(arg1, arg2) \
    __IEEESPCmp_WB(__MATHIEEESINGBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPTst_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPTst, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 8, Mathieeesingbas);\
})

#define IEEESPTst(arg1) \
    __IEEESPTst_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPAbs_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPAbs, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 9, Mathieeesingbas);\
})

#define IEEESPAbs(arg1) \
    __IEEESPAbs_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPNeg_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPNeg, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 10, Mathieeesingbas);\
})

#define IEEESPNeg(arg1) \
    __IEEESPNeg_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPAdd_WB(__MathIeeeSingBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC2(LONG, IEEESPAdd, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct Library *, (__MathIeeeSingBasBase), 11, Mathieeesingbas);\
})

#define IEEESPAdd(arg1, arg2) \
    __IEEESPAdd_WB(__MATHIEEESINGBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPSub_WB(__MathIeeeSingBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC2(LONG, IEEESPSub, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct Library *, (__MathIeeeSingBasBase), 12, Mathieeesingbas);\
})

#define IEEESPSub(arg1, arg2) \
    __IEEESPSub_WB(__MATHIEEESINGBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPMul_WB(__MathIeeeSingBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC2(LONG, IEEESPMul, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct Library *, (__MathIeeeSingBasBase), 13, Mathieeesingbas);\
})

#define IEEESPMul(arg1, arg2) \
    __IEEESPMul_WB(__MATHIEEESINGBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPDiv_WB(__MathIeeeSingBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC2(LONG, IEEESPDiv, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct Library *, (__MathIeeeSingBasBase), 14, Mathieeesingbas);\
})

#define IEEESPDiv(arg1, arg2) \
    __IEEESPDiv_WB(__MATHIEEESINGBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPFloor_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPFloor, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 15, Mathieeesingbas);\
})

#define IEEESPFloor(arg1) \
    __IEEESPFloor_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

#if !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__)

#define __IEEESPCeil_WB(__MathIeeeSingBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeSingBasBase,40)\
        AROS_LC1(LONG, IEEESPCeil, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeSingBasBase), 16, Mathieeesingbas);\
})

#define IEEESPCeil(arg1) \
    __IEEESPCeil_WB(__MATHIEEESINGBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEESINGBAS_LIBAPI__) || (40 <= __MATHIEEESINGBAS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MATHIEEESINGBAS_H*/
