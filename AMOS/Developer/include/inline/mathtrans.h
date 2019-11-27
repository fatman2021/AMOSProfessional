#ifndef INLINE_MATHTRANS_H
#define INLINE_MATHTRANS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/mathtrans/mathtrans.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for mathtrans
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MATHTRANS_LIBBASE)
#    define __MATHTRANS_LIBBASE MathTransBase
#endif


#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPAtan(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPAtan,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 5, MathTrans    );
}

#define SPAtan(arg1) \
    __inline_MathTrans_SPAtan((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPSin(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPSin,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 6, MathTrans    );
}

#define SPSin(arg1) \
    __inline_MathTrans_SPSin((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPCos(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPCos,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 7, MathTrans    );
}

#define SPCos(arg1) \
    __inline_MathTrans_SPCos((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPTan(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPTan,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 8, MathTrans    );
}

#define SPTan(arg1) \
    __inline_MathTrans_SPTan((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPSincos(IPTR * __arg1, LONG __arg2, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC2(LONG, SPSincos,
        AROS_LCA(IPTR *,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathTransBase), 9, MathTrans    );
}

#define SPSincos(arg1, arg2) \
    __inline_MathTrans_SPSincos((arg1), (arg2), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPSinh(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPSinh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 10, MathTrans    );
}

#define SPSinh(arg1) \
    __inline_MathTrans_SPSinh((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPCosh(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPCosh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 11, MathTrans    );
}

#define SPCosh(arg1) \
    __inline_MathTrans_SPCosh((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPTanh(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPTanh,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 12, MathTrans    );
}

#define SPTanh(arg1) \
    __inline_MathTrans_SPTanh((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPExp(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPExp,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 13, MathTrans    );
}

#define SPExp(arg1) \
    __inline_MathTrans_SPExp((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPLog(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPLog,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 14, MathTrans    );
}

#define SPLog(arg1) \
    __inline_MathTrans_SPLog((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPPow(LONG __arg1, LONG __arg2, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC2(LONG, SPPow,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MathTransBase), 15, MathTrans    );
}

#define SPPow(arg1, arg2) \
    __inline_MathTrans_SPPow((arg1), (arg2), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPSqrt(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPSqrt,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 16, MathTrans    );
}

#define SPSqrt(arg1) \
    __inline_MathTrans_SPSqrt((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPTieee(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPTieee,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 17, MathTrans    );
}

#define SPTieee(arg1) \
    __inline_MathTrans_SPTieee((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPFieee(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 0)
    return AROS_LC1(LONG, SPFieee,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 18, MathTrans    );
}

#define SPFieee(arg1) \
    __inline_MathTrans_SPFieee((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (0 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPAsin(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 31)
    return AROS_LC1(LONG, SPAsin,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 19, MathTrans    );
}

#define SPAsin(arg1) \
    __inline_MathTrans_SPAsin((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPAcos(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 31)
    return AROS_LC1(LONG, SPAcos,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 20, MathTrans    );
}

#define SPAcos(arg1) \
    __inline_MathTrans_SPAcos((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

#if !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__)

static inline LONG __inline_MathTrans_SPLog10(LONG __arg1, APTR __MathTransBase)
{
    AROS_LIBREQ(MathTransBase, 31)
    return AROS_LC1(LONG, SPLog10,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MathTransBase), 21, MathTrans    );
}

#define SPLog10(arg1) \
    __inline_MathTrans_SPLog10((arg1), __MATHTRANS_LIBBASE)

#endif /* !defined(__MATHTRANS_LIBAPI__) || (31 <= __MATHTRANS_LIBAPI__) */

#endif /* INLINE_MATHTRANS_H*/
