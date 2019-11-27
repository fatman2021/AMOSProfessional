#ifndef DEFINES_PCCARD_H
#define DEFINES_PCCARD_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/pccard/pccard.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for pccard
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PCCARD_LIBBASE)
#    define __PCCARD_LIBBASE PCCardBase
#endif

__BEGIN_DECLS


#if !defined(__PCCARD_LIBAPI__) || (1 <= __PCCARD_LIBAPI__)

#define __PCCard_GetTupleInfo_WB(__PCCardBase, __arg1) ({\
        AROS_LIBREQ(PCCardBase,1)\
        AROS_LC1(const struct TagItem *, PCCard_GetTupleInfo, \
                  AROS_LCA(const UBYTE *,(__arg1),A0), \
        struct Library *, (__PCCardBase), 5, PCCard);\
})

#define PCCard_GetTupleInfo(arg1) \
    __PCCard_GetTupleInfo_WB(__PCCARD_LIBBASE, (arg1))

#endif /* !defined(__PCCARD_LIBAPI__) || (1 <= __PCCARD_LIBAPI__) */

#if !defined(__PCCARD_LIBAPI__) || (1 <= __PCCARD_LIBAPI__)

#define __PCCard_FreeTupleInfo_WB(__PCCardBase, __arg1) ({\
        AROS_LIBREQ(PCCardBase,1)\
        AROS_LC1NR(VOID, PCCard_FreeTupleInfo, \
                  AROS_LCA(const struct TagItem *,(__arg1),A0), \
        struct Library *, (__PCCardBase), 6, PCCard);\
})

#define PCCard_FreeTupleInfo(arg1) \
    __PCCard_FreeTupleInfo_WB(__PCCARD_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(PCCARD_NO_INLINE_STDARG)
#define PCCard_FreeTupleInfoTags(...) \
({ \
    const IPTR PCCard_FreeTupleInfo_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    PCCard_FreeTupleInfo((const struct TagItem *)(PCCard_FreeTupleInfo_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PCCARD_LIBAPI__) || (1 <= __PCCARD_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PCCARD_H*/
