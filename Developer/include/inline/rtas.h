#ifndef INLINE_RTAS_H
#define INLINE_RTAS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/ppc-chrp/rtas/rtas.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for rtas
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__RTAS_LIBBASE)
#    define __RTAS_LIBBASE RTASBase
#endif


#if !defined(__RTAS_LIBAPI__) || (0 <= __RTAS_LIBAPI__)

static inline int32_t __inline_Rtas_RTASCall(char * __arg1, uint32_t __arg2, uint32_t __arg3, uint32_t * __arg4, va_list __arg5, APTR __RTASBase)
{
    AROS_LIBREQ(RTASBase, 0)
    return AROS_LC5(int32_t, RTASCall,
        AROS_LCA(char *,(__arg1),A0),
        AROS_LCA(uint32_t,(__arg2),D0),
        AROS_LCA(uint32_t,(__arg3),D1),
        AROS_LCA(uint32_t *,(__arg4),A1),
        AROS_LCA(va_list,(__arg5),A2),
        APTR , (__RTASBase), 1, Rtas    );
}

#define RTASCall(arg1, arg2, arg3, arg4, arg5) \
    __inline_Rtas_RTASCall((arg1), (arg2), (arg3), (arg4), (arg5), __RTAS_LIBBASE)

#endif /* !defined(__RTAS_LIBAPI__) || (0 <= __RTAS_LIBAPI__) */

#endif /* INLINE_RTAS_H*/
