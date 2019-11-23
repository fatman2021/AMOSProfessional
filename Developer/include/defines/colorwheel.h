#ifndef DEFINES_COLORWHEEL_H
#define DEFINES_COLORWHEEL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/classes/gadgets/colorwheel/colorwheel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for colorwheel
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__COLORWHEEL_LIBBASE)
#    define __COLORWHEEL_LIBBASE ColorWheelBase
#endif

__BEGIN_DECLS


#if !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__)

#define __ConvertHSBToRGB_WB(__ColorWheelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ColorWheelBase,44)\
        AROS_LC2NR(void, ConvertHSBToRGB, \
                  AROS_LCA(struct ColorWheelHSB*,(__arg1),A0), \
                  AROS_LCA(struct ColorWheelRGB*,(__arg2),A1), \
        struct Library *, (__ColorWheelBase), 5, ColorWheel);\
})

#define ConvertHSBToRGB(arg1, arg2) \
    __ConvertHSBToRGB_WB(__COLORWHEEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__) */

#if !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__)

#define __ConvertRGBToHSB_WB(__ColorWheelBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ColorWheelBase,44)\
        AROS_LC2NR(void, ConvertRGBToHSB, \
                  AROS_LCA(struct ColorWheelRGB*,(__arg1),A0), \
                  AROS_LCA(struct ColorWheelHSB*,(__arg2),A1), \
        struct Library *, (__ColorWheelBase), 6, ColorWheel);\
})

#define ConvertRGBToHSB(arg1, arg2) \
    __ConvertRGBToHSB_WB(__COLORWHEEL_LIBBASE, (arg1), (arg2))

#endif /* !defined(__COLORWHEEL_LIBAPI__) || (44 <= __COLORWHEEL_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_COLORWHEEL_H*/
