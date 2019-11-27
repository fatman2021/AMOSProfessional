#ifndef DEFINES_MATHIEEEDOUBBAS_H
#define DEFINES_MATHIEEEDOUBBAS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeedoubbas/mathieeedoubbas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for mathieeedoubbas
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHIEEEDOUBBAS_LIBBASE)
#    define __MATHIEEEDOUBBAS_LIBBASE MathIeeeDoubBasBase
#endif

__BEGIN_DECLS


#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPFix_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD1(LONG, IEEEDPFix,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 5, MathIeeeDoubBas);\
})

#define IEEEDPFix(arg1) \
    __IEEEDPFix_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPFlt_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
        AROS_LC1(double, IEEEDPFlt, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathIeeeDoubBasBase), 6, MathIeeeDoubBas);\
})

#define IEEEDPFlt(arg1) \
    __IEEEDPFlt_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPCmp_WB(__MathIeeeDoubBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD2(LONG, IEEEDPCmp,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubBasBase), 7, MathIeeeDoubBas);\
})

#define IEEEDPCmp(arg1, arg2) \
    __IEEEDPCmp_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPTst_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD1(LONG, IEEEDPTst,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 8, MathIeeeDoubBas);\
})

#define IEEEDPTst(arg1) \
    __IEEEDPTst_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPAbs_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD1(double, IEEEDPAbs,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 9, MathIeeeDoubBas);\
})

#define IEEEDPAbs(arg1) \
    __IEEEDPAbs_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPNeg_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD1(double, IEEEDPNeg,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 10, MathIeeeDoubBas);\
})

#define IEEEDPNeg(arg1) \
    __IEEEDPNeg_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPAdd_WB(__MathIeeeDoubBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD2(double, IEEEDPAdd,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubBasBase), 11, MathIeeeDoubBas);\
})

#define IEEEDPAdd(arg1, arg2) \
    __IEEEDPAdd_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPSub_WB(__MathIeeeDoubBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD2(double, IEEEDPSub,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubBasBase), 12, MathIeeeDoubBas);\
})

#define IEEEDPSub(arg1, arg2) \
    __IEEEDPSub_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPMul_WB(__MathIeeeDoubBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD2(double, IEEEDPMul,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubBasBase), 13, MathIeeeDoubBas);\
})

#define IEEEDPMul(arg1, arg2) \
    __IEEEDPMul_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPDiv_WB(__MathIeeeDoubBasBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,0)\
    AROS_LCQUAD2(double, IEEEDPDiv,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
         AROS_LCAQUAD(double, (__arg2), D2, D3), \
        struct Library *, (__MathIeeeDoubBasBase), 14, MathIeeeDoubBas);\
})

#define IEEEDPDiv(arg1, arg2) \
    __IEEEDPDiv_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPFloor_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,33)\
    AROS_LCQUAD1(double, IEEEDPFloor,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 15, MathIeeeDoubBas);\
})

#define IEEEDPFloor(arg1) \
    __IEEEDPFloor_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)

#define __IEEEDPCeil_WB(__MathIeeeDoubBasBase, __arg1) ({\
        AROS_LIBREQ(MathIeeeDoubBasBase,33)\
    AROS_LCQUAD1(double, IEEEDPCeil,\
         AROS_LCAQUAD(double, (__arg1), D0, D1), \
        struct Library *, (__MathIeeeDoubBasBase), 16, MathIeeeDoubBas);\
})

#define IEEEDPCeil(arg1) \
    __IEEEDPCeil_WB(__MATHIEEEDOUBBAS_LIBBASE, (arg1))

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MATHIEEEDOUBBAS_H*/
