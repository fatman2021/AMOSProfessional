#ifndef CLIB_MATHIEEEDOUBBAS_PROTOS_H
#define CLIB_MATHIEEEDOUBBAS_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathieeedoubbas/mathieeedoubbas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(LONG, IEEEDPFix,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 5, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LP1(double, IEEEDPFlt,
         AROS_LPA(LONG, y, D0),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 6, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD2(LONG, IEEEDPCmp,
         AROS_LPAQUAD(double, y, D0, D1),
         AROS_LPAQUAD(double, z, D2, D3),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 7, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(LONG, IEEEDPTst,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 8, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(double, IEEEDPAbs,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 9, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(double, IEEEDPNeg,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 10, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD2(double, IEEEDPAdd,
         AROS_LPAQUAD(double, y, D0, D1),
         AROS_LPAQUAD(double, z, D2, D3),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 11, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD2(double, IEEEDPSub,
         AROS_LPAQUAD(double, y, D0, D1),
         AROS_LPAQUAD(double, z, D2, D3),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 12, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD2(double, IEEEDPMul,
         AROS_LPAQUAD(double, y, D0, D1),
         AROS_LPAQUAD(double, z, D2, D3),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 13, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD2(double, IEEEDPDiv,
         AROS_LPAQUAD(double, y, D0, D1),
         AROS_LPAQUAD(double, z, D2, D3),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 14, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (0 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(double, IEEEDPFloor,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 15, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

#if !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__)
AROS_LPQUAD1(double, IEEEDPCeil,
         AROS_LPAQUAD(double, y, D0, D1),
         LIBBASETYPEPTR, MathIeeeDoubBasBase, 16, MathIeeeDoubBas
);

#endif /* !defined(__MATHIEEEDOUBBAS_LIBAPI__) || (33 <= __MATHIEEEDOUBBAS_LIBAPI__) */

__END_DECLS

#endif /* CLIB_MATHIEEEDOUBBAS_PROTOS_H */
