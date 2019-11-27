#ifndef DEFINES_PROCESSOR_H
#define DEFINES_PROCESSOR_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/processor/processor.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for processor
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PROCESSOR_LIBBASE)
#    define __PROCESSOR_LIBBASE ProcessorBase
#endif

__BEGIN_DECLS


#if !defined(__PROCESSOR_LIBAPI__) || (2 <= __PROCESSOR_LIBAPI__)

#define __GetCPUInfo_WB(__ProcessorBase, __arg1) ({\
        AROS_LIBREQ(ProcessorBase,2)\
        AROS_LC1NR(VOID, GetCPUInfo, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        APTR , (__ProcessorBase), 1, Processor);\
})

#define GetCPUInfo(arg1) \
    __GetCPUInfo_WB(__PROCESSOR_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(PROCESSOR_NO_INLINE_STDARG)
#define GetCPUInfoTags(...) \
({ \
    const IPTR GetCPUInfo_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetCPUInfo((struct TagItem *)(GetCPUInfo_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PROCESSOR_LIBAPI__) || (2 <= __PROCESSOR_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PROCESSOR_H*/
