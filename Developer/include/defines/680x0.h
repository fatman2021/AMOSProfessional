#ifndef DEFINES_680X0_H
#define DEFINES_680X0_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-all/m680x0/680x0.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for 680x0
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__680X0_LIBBASE)
#    define __680X0_LIBBASE M680x0Base
#endif

__BEGIN_DECLS


#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

#define __Dummy1_WB(__M680x0Base) ({\
        AROS_LIBREQ(M680x0Base,41)\
        AROS_LC0(ULONG, Dummy1, \
        struct Library *, (__M680x0Base), 5, m680x0);\
})

#define Dummy1() \
    __Dummy1_WB(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

#define __Dummy2_WB(__M680x0Base) ({\
        AROS_LIBREQ(M680x0Base,41)\
        AROS_LC0(ULONG, Dummy2, \
        struct Library *, (__M680x0Base), 6, m680x0);\
})

#define Dummy2() \
    __Dummy2_WB(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

#define __Dummy3_WB(__M680x0Base) ({\
        AROS_LIBREQ(M680x0Base,41)\
        AROS_LC0(ULONG, Dummy3, \
        struct Library *, (__M680x0Base), 7, m680x0);\
})

#define Dummy3() \
    __Dummy3_WB(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

#if !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__)

#define __Dummy4_WB(__M680x0Base) ({\
        AROS_LIBREQ(M680x0Base,41)\
        AROS_LC0(ULONG, Dummy4, \
        struct Library *, (__M680x0Base), 8, m680x0);\
})

#define Dummy4() \
    __Dummy4_WB(__680X0_LIBBASE)

#endif /* !defined(__680X0_LIBAPI__) || (41 <= __680X0_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_680X0_H*/
