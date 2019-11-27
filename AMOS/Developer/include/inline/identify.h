#ifndef INLINE_IDENTIFY_H
#define INLINE_IDENTIFY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/identify/identify.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for identify
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__IDENTIFY_LIBBASE)
#    define __IDENTIFY_LIBBASE IdentifyBase
#endif


#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline LONG __inline_Identify_IdExpansion(struct TagItem * __arg1, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC1(LONG, IdExpansion,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct Library *, (__IdentifyBase), 5, Identify    );
}

#define IdExpansion(arg1) \
    __inline_Identify_IdExpansion((arg1), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdExpansionTags(...) \
({ \
    const IPTR IdExpansion_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdExpansion((struct TagItem *)(IdExpansion_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline CONST_STRPTR __inline_Identify_IdHardware(ULONG __arg1, struct TagItem * __arg2, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC2(CONST_STRPTR, IdHardware,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Library *, (__IdentifyBase), 6, Identify    );
}

#define IdHardware(arg1, arg2) \
    __inline_Identify_IdHardware((arg1), (arg2), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdHardwareTags(arg1, ...) \
({ \
    const IPTR IdHardware_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdHardware((arg1), (struct TagItem *)(IdHardware_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline LONG __inline_Identify_IdAlert(ULONG __arg1, struct TagItem * __arg2, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC2(LONG, IdAlert,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Library *, (__IdentifyBase), 7, Identify    );
}

#define IdAlert(arg1, arg2) \
    __inline_Identify_IdAlert((arg1), (arg2), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdAlertTags(arg1, ...) \
({ \
    const IPTR IdAlert_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdAlert((arg1), (struct TagItem *)(IdAlert_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline LONG __inline_Identify_IdFunction(STRPTR __arg1, LONG __arg2, struct TagItem * __arg3, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC3(LONG, IdFunction,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__IdentifyBase), 8, Identify    );
}

#define IdFunction(arg1, arg2, arg3) \
    __inline_Identify_IdFunction((arg1), (arg2), (arg3), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdFunctionTags(arg1, arg2, ...) \
({ \
    const IPTR IdFunction_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdFunction((arg1), (arg2), (struct TagItem *)(IdFunction_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline ULONG __inline_Identify_IdHardwareNum(ULONG __arg1, struct TagItem * __arg2, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC2(ULONG, IdHardwareNum,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct Library *, (__IdentifyBase), 9, Identify    );
}

#define IdHardwareNum(arg1, arg2) \
    __inline_Identify_IdHardwareNum((arg1), (arg2), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdHardwareNumTags(arg1, ...) \
({ \
    const IPTR IdHardwareNum_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdHardwareNum((arg1), (struct TagItem *)(IdHardwareNum_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline void __inline_Identify_IdHardwareUpdate(APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    AROS_LC0NR(void, IdHardwareUpdate,
        struct Library *, (__IdentifyBase), 10, Identify    );
}

#define IdHardwareUpdate() \
    __inline_Identify_IdHardwareUpdate(__IDENTIFY_LIBBASE)

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline ULONG __inline_Identify_IdFormatString(STRPTR __arg1, STRPTR __arg2, ULONG __arg3, struct TagItem * __arg4, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC4(ULONG, IdFormatString,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(struct TagItem *,(__arg4),A2),
        struct Library *, (__IdentifyBase), 11, Identify    );
}

#define IdFormatString(arg1, arg2, arg3, arg4) \
    __inline_Identify_IdFormatString((arg1), (arg2), (arg3), (arg4), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdFormatStringTags(arg1, arg2, arg3, ...) \
({ \
    const IPTR IdFormatString_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdFormatString((arg1), (arg2), (arg3), (struct TagItem *)(IdFormatString_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#if !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__)

static inline ULONG __inline_Identify_IdEstimateFormatSize(STRPTR __arg1, struct TagItem * __arg2, APTR __IdentifyBase)
{
    AROS_LIBREQ(IdentifyBase, 37)
    return AROS_LC2(ULONG, IdEstimateFormatSize,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__IdentifyBase), 12, Identify    );
}

#define IdEstimateFormatSize(arg1, arg2) \
    __inline_Identify_IdEstimateFormatSize((arg1), (arg2), __IDENTIFY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(IDENTIFY_NO_INLINE_STDARG)
#define IdEstimateFormatSizeTags(arg1, ...) \
({ \
    const IPTR IdEstimateFormatSize_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    IdEstimateFormatSize((arg1), (struct TagItem *)(IdEstimateFormatSize_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__IDENTIFY_LIBAPI__) || (37 <= __IDENTIFY_LIBAPI__) */

#endif /* INLINE_IDENTIFY_H*/
