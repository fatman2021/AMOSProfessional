#ifndef INLINE_680X0_H
#define INLINE_680X0_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-all/m680x0/680x0.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for 680x0
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__680X0_LIBBASE)
#    define __680X0_LIBBASE M680x0Base
#endif


#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

static inline ULONG __inline_m680x0_Dummy1(APTR __M680x0Base)
{
    AROS_LIBREQ(M680x0Base, 41)
    return AROS_LC0(ULONG, Dummy1,
        struct Library *, (__M680x0Base), 5, m680x0    );
}

#define Dummy1() \
    __inline_m680x0_Dummy1(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

static inline ULONG __inline_m680x0_Dummy2(APTR __M680x0Base)
{
    AROS_LIBREQ(M680x0Base, 41)
    return AROS_LC0(ULONG, Dummy2,
        struct Library *, (__M680x0Base), 6, m680x0    );
}

#define Dummy2() \
    __inline_m680x0_Dummy2(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

static inline ULONG __inline_m680x0_Dummy3(APTR __M680x0Base)
{
    AROS_LIBREQ(M680x0Base, 41)
    return AROS_LC0(ULONG, Dummy3,
        struct Library *, (__M680x0Base), 7, m680x0    );
}

#define Dummy3() \
    __inline_m680x0_Dummy3(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

static inline ULONG __inline_m680x0_Dummy4(APTR __M680x0Base)
{
    AROS_LIBREQ(M680x0Base, 41)
    return AROS_LC0(ULONG, Dummy4,
        struct Library *, (__M680x0Base), 8, m680x0    );
}

#define Dummy4() \
    __inline_m680x0_Dummy4(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#endif /* INLINE_680X0_H*/
