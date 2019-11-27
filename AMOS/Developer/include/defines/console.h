#ifndef DEFINES_CONSOLE_H
#define DEFINES_CONSOLE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/console/console.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for console
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CONSOLE_LIBBASE)
#    define __CONSOLE_LIBBASE ConsoleDevice
#endif

__BEGIN_DECLS


#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __CDInputHandler_WB(__ConsoleDevice, __arg1, __arg2) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC2(struct InputEvent*, CDInputHandler, \
                  AROS_LCA(struct InputEvent*,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct Device *, (__ConsoleDevice), 7, Console);\
})

#define CDInputHandler(arg1, arg2) \
    __CDInputHandler_WB(__CONSOLE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __RawKeyConvert_WB(__ConsoleDevice, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC4(LONG, RawKeyConvert, \
                  AROS_LCA(struct InputEvent*,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D1), \
                  AROS_LCA(struct KeyMap*,(__arg4),A2), \
        struct Device *, (__ConsoleDevice), 8, Console);\
})

#define RawKeyConvert(arg1, arg2, arg3, arg4) \
    __RawKeyConvert_WB(__CONSOLE_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __GetConSnip_WB(__ConsoleDevice) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC0(APTR, GetConSnip, \
        struct Device *, (__ConsoleDevice), 9, Console);\
})

#define GetConSnip() \
    __GetConSnip_WB(__CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __SetConSnip_WB(__ConsoleDevice, __arg1) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC1(LONG, SetConSnip, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Device *, (__ConsoleDevice), 10, Console);\
})

#define SetConSnip(arg1) \
    __SetConSnip_WB(__CONSOLE_LIBBASE, (arg1))

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __AddConSnipHook_WB(__ConsoleDevice, __arg1) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC1NR(void, AddConSnipHook, \
                  AROS_LCA(struct Hook*,(__arg1),A0), \
        struct Device *, (__ConsoleDevice), 11, Console);\
})

#define AddConSnipHook(arg1) \
    __AddConSnipHook_WB(__CONSOLE_LIBBASE, (arg1))

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

#define __RemConSnipHook_WB(__ConsoleDevice, __arg1) ({\
        AROS_LIBREQ(ConsoleDevice,0)\
        AROS_LC1NR(void, RemConSnipHook, \
                  AROS_LCA(struct Hook*,(__arg1),A0), \
        struct Device *, (__ConsoleDevice), 12, Console);\
})

#define RemConSnipHook(arg1) \
    __RemConSnipHook_WB(__CONSOLE_LIBBASE, (arg1))

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_CONSOLE_H*/
