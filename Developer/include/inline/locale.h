#ifndef INLINE_LOCALE_H
#define INLINE_LOCALE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/locale/locale.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for locale
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__LOCALE_LIBBASE)
#    define __LOCALE_LIBBASE LocaleBase
#endif


#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline void __inline_Locale_CloseCatalog(struct Catalog * __arg1, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    AROS_LC1NR(void, CloseCatalog,
        AROS_LCA(struct Catalog *,(__arg1),A0),
        struct LocaleBase *, (__LocaleBase), 6, Locale    );
}

#define CloseCatalog(arg1) \
    __inline_Locale_CloseCatalog((arg1), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline void __inline_Locale_CloseLocale(struct Locale * __arg1, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    AROS_LC1NR(void, CloseLocale,
        AROS_LCA(struct Locale *,(__arg1),A0),
        struct LocaleBase *, (__LocaleBase), 7, Locale    );
}

#define CloseLocale(arg1) \
    __inline_Locale_CloseLocale((arg1), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_ConvToLower(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, ConvToLower,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 8, Locale    );
}

#define ConvToLower(arg1, arg2) \
    __inline_Locale_ConvToLower((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_ConvToUpper(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, ConvToUpper,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 9, Locale    );
}

#define ConvToUpper(arg1, arg2) \
    __inline_Locale_ConvToUpper((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline void __inline_Locale_FormatDate(const struct Locale * __arg1, CONST_STRPTR __arg2, const struct DateStamp * __arg3, const struct Hook * __arg4, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    AROS_LC4NR(void, FormatDate,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(const struct DateStamp *,(__arg3),A2),
        AROS_LCA(const struct Hook *,(__arg4),A3),
        struct LocaleBase *, (__LocaleBase), 10, Locale    );
}

#define FormatDate(arg1, arg2, arg3, arg4) \
    __inline_Locale_FormatDate((arg1), (arg2), (arg3), (arg4), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline APTR __inline_Locale_FormatString(const struct Locale * __arg1, CONST_STRPTR __arg2, RAWARG __arg3, const struct Hook * __arg4, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC4(APTR, FormatString,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(RAWARG,(__arg3),A2),
        AROS_LCA(const struct Hook *,(__arg4),A3),
        struct LocaleBase *, (__LocaleBase), 11, Locale    );
}

#define FormatString(arg1, arg2, arg3, arg4) \
    __inline_Locale_FormatString((arg1), (arg2), (arg3), (arg4), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline CONST_STRPTR __inline_Locale_GetCatalogStr(const struct Catalog * __arg1, ULONG __arg2, CONST_STRPTR __arg3, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC3(CONST_STRPTR, GetCatalogStr,
        AROS_LCA(const struct Catalog *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(CONST_STRPTR,(__arg3),A1),
        struct LocaleBase *, (__LocaleBase), 12, Locale    );
}

#define GetCatalogStr(arg1, arg2, arg3) \
    __inline_Locale_GetCatalogStr((arg1), (arg2), (arg3), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline CONST_STRPTR __inline_Locale_GetLocaleStr(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(CONST_STRPTR, GetLocaleStr,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 13, Locale    );
}

#define GetLocaleStr(arg1, arg2) \
    __inline_Locale_GetLocaleStr((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsAlNum(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsAlNum,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 14, Locale    );
}

#define IsAlNum(arg1, arg2) \
    __inline_Locale_IsAlNum((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsAlpha(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsAlpha,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 15, Locale    );
}

#define IsAlpha(arg1, arg2) \
    __inline_Locale_IsAlpha((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsCntrl(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsCntrl,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 16, Locale    );
}

#define IsCntrl(arg1, arg2) \
    __inline_Locale_IsCntrl((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsDigit(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsDigit,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 17, Locale    );
}

#define IsDigit(arg1, arg2) \
    __inline_Locale_IsDigit((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsGraph(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsGraph,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 18, Locale    );
}

#define IsGraph(arg1, arg2) \
    __inline_Locale_IsGraph((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsLower(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsLower,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 19, Locale    );
}

#define IsLower(arg1, arg2) \
    __inline_Locale_IsLower((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsPrint(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsPrint,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 20, Locale    );
}

#define IsPrint(arg1, arg2) \
    __inline_Locale_IsPrint((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsPunct(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsPunct,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 21, Locale    );
}

#define IsPunct(arg1, arg2) \
    __inline_Locale_IsPunct((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsSpace(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsSpace,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 22, Locale    );
}

#define IsSpace(arg1, arg2) \
    __inline_Locale_IsSpace((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsUpper(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsUpper,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 23, Locale    );
}

#define IsUpper(arg1, arg2) \
    __inline_Locale_IsUpper((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_IsXDigit(const struct Locale * __arg1, ULONG __arg2, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC2(ULONG, IsXDigit,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct LocaleBase *, (__LocaleBase), 24, Locale    );
}

#define IsXDigit(arg1, arg2) \
    __inline_Locale_IsXDigit((arg1), (arg2), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline struct Catalog * __inline_Locale_OpenCatalogA(const struct Locale * __arg1, CONST_STRPTR __arg2, const struct TagItem * __arg3, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC3(struct Catalog *, OpenCatalogA,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(const struct TagItem *,(__arg3),A2),
        struct LocaleBase *, (__LocaleBase), 25, Locale    );
}

#define OpenCatalogA(arg1, arg2, arg3) \
    __inline_Locale_OpenCatalogA((arg1), (arg2), (arg3), __LOCALE_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(LOCALE_NO_INLINE_STDARG)
#define OpenCatalog(arg1, arg2, ...) \
({ \
    const IPTR OpenCatalogA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    OpenCatalogA((arg1), (arg2), (const struct TagItem *)(OpenCatalogA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline struct Locale * __inline_Locale_OpenLocale(CONST_STRPTR __arg1, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC1(struct Locale *, OpenLocale,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct LocaleBase *, (__LocaleBase), 26, Locale    );
}

#define OpenLocale(arg1) \
    __inline_Locale_OpenLocale((arg1), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline BOOL __inline_Locale_ParseDate(struct Locale * __arg1, struct DateStamp * __arg2, CONST_STRPTR __arg3, struct Hook * __arg4, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC4(BOOL, ParseDate,
        AROS_LCA(struct Locale *,(__arg1),A0),
        AROS_LCA(struct DateStamp *,(__arg2),A1),
        AROS_LCA(CONST_STRPTR,(__arg3),A2),
        AROS_LCA(struct Hook *,(__arg4),A3),
        struct LocaleBase *, (__LocaleBase), 27, Locale    );
}

#define ParseDate(arg1, arg2, arg3, arg4) \
    __inline_Locale_ParseDate((arg1), (arg2), (arg3), (arg4), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline struct Locale * __inline_Locale_LocalePrefsUpdate(struct Locale * __arg1, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC1(struct Locale *, LocalePrefsUpdate,
        AROS_LCA(struct Locale *,(__arg1),A0),
        struct LocaleBase *, (__LocaleBase), 28, Locale    );
}

#define LocalePrefsUpdate(arg1) \
    __inline_Locale_LocalePrefsUpdate((arg1), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline ULONG __inline_Locale_StrConvert(const struct Locale * __arg1, CONST_STRPTR __arg2, APTR __arg3, ULONG __arg4, ULONG __arg5, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC5(ULONG, StrConvert,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(APTR,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(ULONG,(__arg5),D1),
        struct LocaleBase *, (__LocaleBase), 29, Locale    );
}

#define StrConvert(arg1, arg2, arg3, arg4, arg5) \
    __inline_Locale_StrConvert((arg1), (arg2), (arg3), (arg4), (arg5), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#if !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__)

static inline LONG __inline_Locale_StrnCmp(const struct Locale * __arg1, CONST_STRPTR __arg2, CONST_STRPTR __arg3, LONG __arg4, ULONG __arg5, APTR __LocaleBase)
{
    AROS_LIBREQ(LocaleBase, 39)
    return AROS_LC5(LONG, StrnCmp,
        AROS_LCA(const struct Locale *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(CONST_STRPTR,(__arg3),A2),
        AROS_LCA(LONG,(__arg4),D0),
        AROS_LCA(ULONG,(__arg5),D1),
        struct LocaleBase *, (__LocaleBase), 30, Locale    );
}

#define StrnCmp(arg1, arg2, arg3, arg4, arg5) \
    __inline_Locale_StrnCmp((arg1), (arg2), (arg3), (arg4), (arg5), __LOCALE_LIBBASE)

#endif /* !defined(__LOCALE_LIBAPI__) || (39 <= __LOCALE_LIBAPI__) */

#endif /* INLINE_LOCALE_H*/
