#ifndef DEFINES_IDENTIFY_H
#define DEFINES_IDENTIFY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/identify/identify.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for identify
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__IDENTIFY_LIBBASE)
#    define __IDENTIFY_LIBBASE IdentifyBase
#endif

__BEGIN_DECLS


#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdExpansion_WB(__IdentifyBase, __arg1) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC1(LONG, IdExpansion, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct Library *, (__IdentifyBase), 5, Identify);\
})

#define IdExpansion(arg1) \
    __IdExpansion_WB(__IDENTIFY_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdExpansionTags(...) \
({ \
    const IPTR IdExpansion_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdExpansion((struct TagItem *)(IdExpansion_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdHardware_WB(__IdentifyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC2(CONST_STRPTR, IdHardware, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Library *, (__IdentifyBase), 6, Identify);\
})

#define IdHardware(arg1, arg2) \
    __IdHardware_WB(__IDENTIFY_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdHardwareTags(arg1, ...) \
({ \
    const IPTR IdHardware_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdHardware((arg1), (struct TagItem *)(IdHardware_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdAlert_WB(__IdentifyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC2(LONG, IdAlert, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Library *, (__IdentifyBase), 7, Identify);\
})

#define IdAlert(arg1, arg2) \
    __IdAlert_WB(__IDENTIFY_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdAlertTags(arg1, ...) \
({ \
    const IPTR IdAlert_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdAlert((arg1), (struct TagItem *)(IdAlert_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdFunction_WB(__IdentifyBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC3(LONG, IdFunction, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__IdentifyBase), 8, Identify);\
})

#define IdFunction(arg1, arg2, arg3) \
    __IdFunction_WB(__IDENTIFY_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdFunctionTags(arg1, arg2, ...) \
({ \
    const IPTR IdFunction_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdFunction((arg1), (arg2), (struct TagItem *)(IdFunction_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdHardwareNum_WB(__IdentifyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC2(ULONG, IdHardwareNum, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct TagItem *,(__arg2),A0), \
        struct Library *, (__IdentifyBase), 9, Identify);\
})

#define IdHardwareNum(arg1, arg2) \
    __IdHardwareNum_WB(__IDENTIFY_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdHardwareNumTags(arg1, ...) \
({ \
    const IPTR IdHardwareNum_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdHardwareNum((arg1), (struct TagItem *)(IdHardwareNum_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdHardwareUpdate_WB(__IdentifyBase) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC0NR(void, IdHardwareUpdate, \
        struct Library *, (__IdentifyBase), 10, Identify);\
})

#define IdHardwareUpdate() \
    __IdHardwareUpdate_WB(__IDENTIFY_LIBBASE)

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdFormatString_WB(__IdentifyBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC4(ULONG, IdFormatString, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(STRPTR,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
                  AROS_LCA(struct TagItem *,(__arg4),A2), \
        struct Library *, (__IdentifyBase), 11, Identify);\
})

#define IdFormatString(arg1, arg2, arg3, arg4) \
    __IdFormatString_WB(__IDENTIFY_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdFormatStringTags(arg1, arg2, arg3, ...) \
({ \
    const IPTR IdFormatString_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdFormatString((arg1), (arg2), (arg3), (struct TagItem *)(IdFormatString_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

#define __IdEstimateFormatSize_WB(__IdentifyBase, __arg1, __arg2) ({\
        AROS_LIBREQ(IdentifyBase,37)\
        AROS_LC2(ULONG, IdEstimateFormatSize, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__IdentifyBase), 12, Identify);\
})

#define IdEstimateFormatSize(arg1, arg2) \
    __IdEstimateFormatSize_WB(__IDENTIFY_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdEstimateFormatSizeTags(arg1, ...) \
({ \
    const IPTR IdEstimateFormatSize_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdEstimateFormatSize((arg1), (struct TagItem *)(IdEstimateFormatSize_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_IDENTIFY_H*/
