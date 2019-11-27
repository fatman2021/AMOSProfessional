#ifndef INLINE_COLORWHEEL_H
#define INLINE_COLORWHEEL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/classes/gadgets/colorwheel/colorwheel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for colorwheel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COLORWHEEL_LIBBASE)
#    define __COLORWHEEL_LIBBASE ColorWheelBase
#endif


#if !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__)

static inline void __inline_ColorWheel_ConvertHSBToRGB(struct ColorWheelHSB* __arg1, struct ColorWheelRGB* __arg2, APTR __ColorWheelBase)
{
    AROS_LIBREQ(ColorWheelBase, 44)
    AROS_LC2NR(void, ConvertHSBToRGB,
        AROS_LCA(struct ColorWheelHSB*,(__arg1),A0),
        AROS_LCA(struct ColorWheelRGB*,(__arg2),A1),
        struct Library *, (__ColorWheelBase), 5, ColorWheel    );
}

#define ConvertHSBToRGB(arg1, arg2) \
    __inline_ColorWheel_ConvertHSBToRGB((arg1), (arg2), __COLORWHEEL_LIBBASE)

#endif /* !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__) */

#if !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__)

static inline void __inline_ColorWheel_ConvertRGBToHSB(struct ColorWheelRGB* __arg1, struct ColorWheelHSB* __arg2, APTR __ColorWheelBase)
{
    AROS_LIBREQ(ColorWheelBase, 44)
    AROS_LC2NR(void, ConvertRGBToHSB,
        AROS_LCA(struct ColorWheelRGB*,(__arg1),A0),
        AROS_LCA(struct ColorWheelHSB*,(__arg2),A1),
        struct Library *, (__ColorWheelBase), 6, ColorWheel    );
}

#define ConvertRGBToHSB(arg1, arg2) \
    __inline_ColorWheel_ConvertRGBToHSB((arg1), (arg2), __COLORWHEEL_LIBBASE)

#endif /* !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__) */

#endif /* INLINE_COLORWHEEL_H*/
