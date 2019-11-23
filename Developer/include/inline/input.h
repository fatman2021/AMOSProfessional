#ifndef INLINE_INPUT_H
#define INLINE_INPUT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/input/input.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for input
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__INPUT_LIBBASE)
#    define __INPUT_LIBBASE InputBase
#endif


#if !defined(__INPUT_LIBAPI__) || (0 <= __INPUT_LIBAPI__)

static inline UWORD __inline_Input_PeekQualifier(APTR __InputBase)
{
    AROS_LIBREQ(InputBase, 0)
    return AROS_LC0(UWORD, PeekQualifier,
        struct Device *, (__InputBase), 7, Input    );
}

#define PeekQualifier() \
    __inline_Input_PeekQualifier(__INPUT_LIBBASE)

#endif /* !defined(__INPUT_LIBAPI__) || (0 <= __INPUT_LIBAPI__) */

#endif /* INLINE_INPUT_H*/
