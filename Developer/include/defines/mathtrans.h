#ifndef DEFINES_MATHTRANS_H
#define DEFINES_MATHTRANS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathtrans/mathtrans.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for mathtrans
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHTRANS_LIBBASE)
#    define __MATHTRANS_LIBBASE MathTransBase
#endif

__BEGIN_DECLS


#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPAtan_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPAtan, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 5, MathTrans);\
})

#define SPAtan(arg1) \
    __SPAtan_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPSin_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPSin, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 6, MathTrans);\
})

#define SPSin(arg1) \
    __SPSin_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPCos_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPCos, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 7, MathTrans);\
})

#define SPCos(arg1) \
    __SPCos_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPTan_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPTan, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 8, MathTrans);\
})

#define SPTan(arg1) \
    __SPTan_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPSincos_WB(__MathTransBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC2(LONG, SPSincos, \
                  AROS_LCA(IPTR *,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathTransBase), 9, MathTrans);\
})

#define SPSincos(arg1, arg2) \
    __SPSincos_WB(__MATHTRANS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPSinh_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPSinh, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 10, MathTrans);\
})

#define SPSinh(arg1) \
    __SPSinh_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPCosh_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPCosh, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 11, MathTrans);\
})

#define SPCosh(arg1) \
    __SPCosh_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPTanh_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPTanh, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 12, MathTrans);\
})

#define SPTanh(arg1) \
    __SPTanh_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPExp_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPExp, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 13, MathTrans);\
})

#define SPExp(arg1) \
    __SPExp_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPLog_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPLog, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 14, MathTrans);\
})

#define SPLog(arg1) \
    __SPLog_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPPow_WB(__MathTransBase, __arg1, __arg2) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC2(LONG, SPPow, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct Library *, (__MathTransBase), 15, MathTrans);\
})

#define SPPow(arg1, arg2) \
    __SPPow_WB(__MATHTRANS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPSqrt_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPSqrt, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 16, MathTrans);\
})

#define SPSqrt(arg1) \
    __SPSqrt_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPTieee_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPTieee, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 17, MathTrans);\
})

#define SPTieee(arg1) \
    __SPTieee_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

#define __SPFieee_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,0)\
        AROS_LC1(LONG, SPFieee, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 18, MathTrans);\
})

#define SPFieee(arg1) \
    __SPFieee_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

#define __SPAsin_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,31)\
        AROS_LC1(LONG, SPAsin, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 19, MathTrans);\
})

#define SPAsin(arg1) \
    __SPAsin_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

#define __SPAcos_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,31)\
        AROS_LC1(LONG, SPAcos, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 20, MathTrans);\
})

#define SPAcos(arg1) \
    __SPAcos_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

#define __SPLog10_WB(__MathTransBase, __arg1) ({\
        AROS_LIBREQ(MathTransBase,31)\
        AROS_LC1(LONG, SPLog10, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct Library *, (__MathTransBase), 21, MathTrans);\
})

#define SPLog10(arg1) \
    __SPLog10_WB(__MATHTRANS_LIBBASE, (arg1))

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_MATHTRANS_H*/
