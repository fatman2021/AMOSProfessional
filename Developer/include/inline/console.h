#ifndef INLINE_CONSOLE_H
#define INLINE_CONSOLE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/console/console.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for console
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CONSOLE_LIBBASE)
#    define __CONSOLE_LIBBASE ConsoleDevice
#endif


#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline struct InputEvent* __inline_Console_CDInputHandler(struct InputEvent* __arg1, APTR __arg2, APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    return AROS_LC2(struct InputEvent*, CDInputHandler,
        AROS_LCA(struct InputEvent*,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Device *, (__ConsoleDevice), 7, Console    );
}

#define CDInputHandler(arg1, arg2) \
    __inline_Console_CDInputHandler((arg1), (arg2), __CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline LONG __inline_Console_RawKeyConvert(struct InputEvent* __arg1, STRPTR __arg2, LONG __arg3, struct KeyMap* __arg4, APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    return AROS_LC4(LONG, RawKeyConvert,
        AROS_LCA(struct InputEvent*,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(struct KeyMap*,(__arg4),A2),
        struct Device *, (__ConsoleDevice), 8, Console    );
}

#define RawKeyConvert(arg1, arg2, arg3, arg4) \
    __inline_Console_RawKeyConvert((arg1), (arg2), (arg3), (arg4), __CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline APTR __inline_Console_GetConSnip(APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    return AROS_LC0(APTR, GetConSnip,
        struct Device *, (__ConsoleDevice), 9, Console    );
}

#define GetConSnip() \
    __inline_Console_GetConSnip(__CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline LONG __inline_Console_SetConSnip(APTR __arg1, APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    return AROS_LC1(LONG, SetConSnip,
        AROS_LCA(APTR,(__arg1),A0),
        struct Device *, (__ConsoleDevice), 10, Console    );
}

#define SetConSnip(arg1) \
    __inline_Console_SetConSnip((arg1), __CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline void __inline_Console_AddConSnipHook(struct Hook* __arg1, APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    AROS_LC1NR(void, AddConSnipHook,
        AROS_LCA(struct Hook*,(__arg1),A0),
        struct Device *, (__ConsoleDevice), 11, Console    );
}

#define AddConSnipHook(arg1) \
    __inline_Console_AddConSnipHook((arg1), __CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#if !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__)

static inline void __inline_Console_RemConSnipHook(struct Hook* __arg1, APTR __ConsoleDevice)
{
    AROS_LIBREQ(ConsoleDevice, 0)
    AROS_LC1NR(void, RemConSnipHook,
        AROS_LCA(struct Hook*,(__arg1),A0),
        struct Device *, (__ConsoleDevice), 12, Console    );
}

#define RemConSnipHook(arg1) \
    __inline_Console_RemConSnipHook((arg1), __CONSOLE_LIBBASE)

#endif /* !defined(__CONSOLE_LIBAPI__) || (0 <= __CONSOLE_LIBAPI__) */

#endif /* INLINE_CONSOLE_H*/
