#ifndef DEFINES_MATHIEEEDOUBTRANS_H
#define DEFINES_MATHIEEEDOUBTRANS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeedoubtrans/mathieeedoubtrans.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for mathieeedoubtrans
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEEDOUBTRANS_LIBBASE)
#    define __MATHIEEEDOUBTRANS_LIBBASE MathIeeeDoubTransBase
#endif

__BEGIN_DECLS


#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPAtan_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPAtan,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 5, MathIeeeDoubTrans);\
})

#define IEEEDPAtan(arg1) \
    __IEEEDPAtan_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPSin_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPSin,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 6, MathIeeeDoubTrans);\
})

#define IEEEDPSin(arg1) \
    __IEEEDPSin_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPCos_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPCos,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 7, MathIeeeDoubTrans);\
})

#define IEEEDPCos(arg1) \
    __IEEEDPCos_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPTan_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPTan,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 8, MathIeeeDoubTrans);\
})

#define IEEEDPTan(arg1) \
    __IEEEDPTan_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPSincos_WB(__MathIeeeDoubTransBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LC1QUAD1(double, IEEEDPSincos,\
         AROS_LCA(double *, (__arg1), A0), \
         AROS_LCAQUAD(double, (__arg2), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 9, MathIeeeDoubTrans);\
})

#define IEEEDPSincos(arg1, arg2) \
    __IEEEDPSincos_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPSinh_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPSinh,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 10, MathIeeeDoubTrans);\
})

#define IEEEDPSinh(arg1) \
    __IEEEDPSinh_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPCosh_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPCosh,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 11, MathIeeeDoubTrans);\
})

#define IEEEDPCosh(arg1) \
    __IEEEDPCosh_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPTanh_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPTanh,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 12, MathIeeeDoubTrans);\
})

#define IEEEDPTanh(arg1) \
    __IEEEDPTanh_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPExp_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPExp,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 13, MathIeeeDoubTrans);\
})

#define IEEEDPExp(arg1) \
    __IEEEDPExp_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPLog_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPLog,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 14, MathIeeeDoubTrans);\
})

#define IEEEDPLog(arg1) \
    __IEEEDPLog_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPPow_WB(__MathIeeeDoubTransBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD2(double, IEEEDPPow,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubTransBase), 15, MathIeeeDoubTrans);\
})

#define IEEEDPPow(arg1, arg2) \
    __IEEEDPPow_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPSqrt_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPSqrt,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 16, MathIeeeDoubTrans);\
})

#define IEEEDPSqrt(arg1) \
    __IEEEDPSqrt_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPTieee_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(LONG, IEEEDPTieee,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 17, MathIeeeDoubTrans);\
})

#define IEEEDPTieee(arg1) \
    __IEEEDPTieee_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPFieee_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
        AROS_LC1(double, IEEEDPFieee, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeDoubTransBase), 18, MathIeeeDoubTrans);\
})

#define IEEEDPFieee(arg1) \
    __IEEEDPFieee_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPAsin_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPAsin,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 19, MathIeeeDoubTrans);\
})

#define IEEEDPAsin(arg1) \
    __IEEEDPAsin_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPAcos_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPAcos,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 20, MathIeeeDoubTrans);\
})

#define IEEEDPAcos(arg1) \
    __IEEEDPAcos_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__)

#define __IEEEDPLog10_WB(__MathIeeeDoubTransBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubTransBase,41)\
    AROS_LCQUAD1(double, IEEEDPLog10,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubTransBase), 21, MathIeeeDoubTrans);\
})

#define IEEEDPLog10(arg1) \
    __IEEEDPLog10_WB(__MATHIEEEDOUBTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBTRANS_LIBAPI__) || (41 <= __MATHIEEEDOUBTRANS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MATHIEEEDOUBTRANS_H*/
