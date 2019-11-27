#ifndef INLINE_REQTOOLS_H
#define INLINE_REQTOOLS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/reqtools/reqtools.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for reqtools
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__REQTOOLS_LIBBASE)
#    define __REQTOOLS_LIBBASE ReqToolsBase
#endif


#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline APTR __inline_ReqTools_rtAllocRequestA(ULONG __arg1, struct TagItem * __arg2, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC2(APTR, rtAllocRequestA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 5, ReqTools    );
}

#define rtAllocRequestA(arg1, arg2) \
    __inline_ReqTools_rtAllocRequestA((arg1), (arg2), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtAllocRequest(arg1, ...) \
({ \
    const IPTR rtAllocRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtAllocRequestA((arg1), (struct TagItem *)(rtAllocRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtFreeRequest(APTR __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtFreeRequest,
        AROS_LCA(APTR,(__arg1),A1),
        struct ReqToolsBase *, (__ReqToolsBase), 6, ReqTools    );
}

#define rtFreeRequest(arg1) \
    __inline_ReqTools_rtFreeRequest((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtFreeReqBuffer(APTR __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtFreeReqBuffer,
        AROS_LCA(APTR,(__arg1),A1),
        struct ReqToolsBase *, (__ReqToolsBase), 7, ReqTools    );
}

#define rtFreeReqBuffer(arg1) \
    __inline_ReqTools_rtFreeReqBuffer((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline LONG __inline_ReqTools_rtChangeReqAttrA(APTR __arg1, struct TagItem * __arg2, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC2(LONG, rtChangeReqAttrA,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 8, ReqTools    );
}

#define rtChangeReqAttrA(arg1, arg2) \
    __inline_ReqTools_rtChangeReqAttrA((arg1), (arg2), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtChangeReqAttr(arg1, ...) \
({ \
    const IPTR rtChangeReqAttrA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtChangeReqAttrA((arg1), (struct TagItem *)(rtChangeReqAttrA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline APTR __inline_ReqTools_rtFileRequestA(struct rtFileRequester * __arg1, char * __arg2, const char * __arg3, struct TagItem * __arg4, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC4(APTR, rtFileRequestA,
        AROS_LCA(struct rtFileRequester *,(__arg1),A1),
        AROS_LCA(char *,(__arg2),A2),
        AROS_LCA(const char *,(__arg3),A3),
        AROS_LCA(struct TagItem *,(__arg4),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 9, ReqTools    );
}

#define rtFileRequestA(arg1, arg2, arg3, arg4) \
    __inline_ReqTools_rtFileRequestA((arg1), (arg2), (arg3), (arg4), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtFileRequest(arg1, arg2, arg3, ...) \
({ \
    const IPTR rtFileRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtFileRequestA((arg1), (arg2), (arg3), (struct TagItem *)(rtFileRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtFreeFileList(struct rtFileList * __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtFreeFileList,
        AROS_LCA(struct rtFileList *,(__arg1),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 10, ReqTools    );
}

#define rtFreeFileList(arg1) \
    __inline_ReqTools_rtFreeFileList((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtEZRequestA(const char * __arg1, const char * __arg2, struct rtReqInfo * __arg3, APTR __arg4, struct TagItem * __arg5, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC5(ULONG, rtEZRequestA,
        AROS_LCA(const char *,(__arg1),A1),
        AROS_LCA(const char *,(__arg2),A2),
        AROS_LCA(struct rtReqInfo *,(__arg3),A3),
        AROS_LCA(APTR,(__arg4),A4),
        AROS_LCA(struct TagItem *,(__arg5),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 11, ReqTools    );
}

#define rtEZRequestA(arg1, arg2, arg3, arg4, arg5) \
    __inline_ReqTools_rtEZRequestA((arg1), (arg2), (arg3), (arg4), (arg5), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtEZRequest(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR rtEZRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtEZRequestA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(rtEZRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtGetStringA(UBYTE * __arg1, ULONG __arg2, const char * __arg3, struct rtReqInfo * __arg4, struct TagItem * __arg5, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC5(ULONG, rtGetStringA,
        AROS_LCA(UBYTE *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(const char *,(__arg3),A2),
        AROS_LCA(struct rtReqInfo *,(__arg4),A3),
        AROS_LCA(struct TagItem *,(__arg5),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 12, ReqTools    );
}

#define rtGetStringA(arg1, arg2, arg3, arg4, arg5) \
    __inline_ReqTools_rtGetStringA((arg1), (arg2), (arg3), (arg4), (arg5), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtGetString(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR rtGetStringA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtGetStringA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(rtGetStringA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtGetLongA(ULONG * __arg1, const char * __arg2, struct rtReqInfo * __arg3, struct TagItem * __arg4, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC4(ULONG, rtGetLongA,
        AROS_LCA(ULONG *,(__arg1),A1),
        AROS_LCA(const char *,(__arg2),A2),
        AROS_LCA(struct rtReqInfo *,(__arg3),A3),
        AROS_LCA(struct TagItem *,(__arg4),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 13, ReqTools    );
}

#define rtGetLongA(arg1, arg2, arg3, arg4) \
    __inline_ReqTools_rtGetLongA((arg1), (arg2), (arg3), (arg4), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtGetLong(arg1, arg2, arg3, ...) \
({ \
    const IPTR rtGetLongA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtGetLongA((arg1), (arg2), (arg3), (struct TagItem *)(rtGetLongA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline BOOL __inline_ReqTools_rtInternalGetPasswordA(UBYTE * __arg1, ULONG __arg2, PWCALLBACKFUNPTR __arg3, struct rtReqInfo * __arg4, struct TagItem * __arg5, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC5(BOOL, rtInternalGetPasswordA,
        AROS_LCA(UBYTE *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(PWCALLBACKFUNPTR,(__arg3),D2),
        AROS_LCA(struct rtReqInfo *,(__arg4),A3),
        AROS_LCA(struct TagItem *,(__arg5),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 14, ReqTools    );
}

#define rtInternalGetPasswordA(arg1, arg2, arg3, arg4, arg5) \
    __inline_ReqTools_rtInternalGetPasswordA((arg1), (arg2), (arg3), (arg4), (arg5), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtInternalGetPassword(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR rtInternalGetPasswordA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtInternalGetPasswordA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(rtInternalGetPasswordA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline BOOL __inline_ReqTools_rtInternalEnterPasswordA(UBYTE * __arg1, PWCALLBACKFUNPTR __arg2, struct rtReqInfo * __arg3, struct TagItem * __arg4, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC4(BOOL, rtInternalEnterPasswordA,
        AROS_LCA(UBYTE *,(__arg1),A1),
        AROS_LCA(PWCALLBACKFUNPTR,(__arg2),D2),
        AROS_LCA(struct rtReqInfo *,(__arg3),A3),
        AROS_LCA(struct TagItem *,(__arg4),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 15, ReqTools    );
}

#define rtInternalEnterPasswordA(arg1, arg2, arg3, arg4) \
    __inline_ReqTools_rtInternalEnterPasswordA((arg1), (arg2), (arg3), (arg4), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtInternalEnterPassword(arg1, arg2, arg3, ...) \
({ \
    const IPTR rtInternalEnterPasswordA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtInternalEnterPasswordA((arg1), (arg2), (arg3), (struct TagItem *)(rtInternalEnterPasswordA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtFontRequestA(struct rtFontRequester * __arg1, const char * __arg2, struct TagItem * __arg3, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC3(ULONG, rtFontRequestA,
        AROS_LCA(struct rtFontRequester *,(__arg1),A1),
        AROS_LCA(const char *,(__arg2),A3),
        AROS_LCA(struct TagItem *,(__arg3),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 16, ReqTools    );
}

#define rtFontRequestA(arg1, arg2, arg3) \
    __inline_ReqTools_rtFontRequestA((arg1), (arg2), (arg3), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtFontRequest(arg1, arg2, ...) \
({ \
    const IPTR rtFontRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtFontRequestA((arg1), (arg2), (struct TagItem *)(rtFontRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline LONG __inline_ReqTools_rtPaletteRequestA(const char * __arg1, struct rtReqInfo * __arg2, struct TagItem * __arg3, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC3(LONG, rtPaletteRequestA,
        AROS_LCA(const char *,(__arg1),A2),
        AROS_LCA(struct rtReqInfo *,(__arg2),A3),
        AROS_LCA(struct TagItem *,(__arg3),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 17, ReqTools    );
}

#define rtPaletteRequestA(arg1, arg2, arg3) \
    __inline_ReqTools_rtPaletteRequestA((arg1), (arg2), (arg3), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtPaletteRequest(arg1, arg2, ...) \
({ \
    const IPTR rtPaletteRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtPaletteRequestA((arg1), (arg2), (struct TagItem *)(rtPaletteRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline IPTR __inline_ReqTools_rtReqHandlerA(struct rtHandlerInfo * __arg1, ULONG __arg2, struct TagItem * __arg3, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC3(IPTR, rtReqHandlerA,
        AROS_LCA(struct rtHandlerInfo *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(struct TagItem *,(__arg3),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 18, ReqTools    );
}

#define rtReqHandlerA(arg1, arg2, arg3) \
    __inline_ReqTools_rtReqHandlerA((arg1), (arg2), (arg3), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtReqHandler(arg1, arg2, ...) \
({ \
    const IPTR rtReqHandlerA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtReqHandlerA((arg1), (arg2), (struct TagItem *)(rtReqHandlerA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtSetWaitPointer(struct Window * __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtSetWaitPointer,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 19, ReqTools    );
}

#define rtSetWaitPointer(arg1) \
    __inline_ReqTools_rtSetWaitPointer((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtGetVScreenSize(struct Screen * __arg1, ULONG * __arg2, ULONG * __arg3, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC3(ULONG, rtGetVScreenSize,
        AROS_LCA(struct Screen *,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(ULONG *,(__arg3),A2),
        struct ReqToolsBase *, (__ReqToolsBase), 20, ReqTools    );
}

#define rtGetVScreenSize(arg1, arg2, arg3) \
    __inline_ReqTools_rtGetVScreenSize((arg1), (arg2), (arg3), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtSetReqPosition(ULONG __arg1, struct NewWindow * __arg2, struct Screen * __arg3, struct Window * __arg4, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC4NR(void, rtSetReqPosition,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct NewWindow *,(__arg2),A0),
        AROS_LCA(struct Screen *,(__arg3),A1),
        AROS_LCA(struct Window *,(__arg4),A2),
        struct ReqToolsBase *, (__ReqToolsBase), 21, ReqTools    );
}

#define rtSetReqPosition(arg1, arg2, arg3, arg4) \
    __inline_ReqTools_rtSetReqPosition((arg1), (arg2), (arg3), (arg4), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtSpread(ULONG * __arg1, ULONG * __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, ULONG __arg6, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC6NR(void, rtSpread,
        AROS_LCA(ULONG *,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        AROS_LCA(ULONG,(__arg4),D1),
        AROS_LCA(ULONG,(__arg5),D2),
        AROS_LCA(ULONG,(__arg6),D3),
        struct ReqToolsBase *, (__ReqToolsBase), 22, ReqTools    );
}

#define rtSpread(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_ReqTools_rtSpread((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtScreenToFrontSafely(struct Screen * __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtScreenToFrontSafely,
        AROS_LCA(struct Screen *,(__arg1),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 23, ReqTools    );
}

#define rtScreenToFrontSafely(arg1) \
    __inline_ReqTools_rtScreenToFrontSafely((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline ULONG __inline_ReqTools_rtScreenModeRequestA(struct rtScreenModeRequester * __arg1, char * __arg2, struct TagItem * __arg3, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC3(ULONG, rtScreenModeRequestA,
        AROS_LCA(struct rtScreenModeRequester *,(__arg1),A1),
        AROS_LCA(char *,(__arg2),A3),
        AROS_LCA(struct TagItem *,(__arg3),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 24, ReqTools    );
}

#define rtScreenModeRequestA(arg1, arg2, arg3) \
    __inline_ReqTools_rtScreenModeRequestA((arg1), (arg2), (arg3), __REQTOOLS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(REQTOOLS_NO_INLINE_STDARG)
#define rtScreenModeRequest(arg1, arg2, ...) \
({ \
    const IPTR rtScreenModeRequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    rtScreenModeRequestA((arg1), (arg2), (struct TagItem *)(rtScreenModeRequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtCloseWindowSafely(struct Window * __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC1NR(void, rtCloseWindowSafely,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 25, ReqTools    );
}

#define rtCloseWindowSafely(arg1) \
    __inline_ReqTools_rtCloseWindowSafely((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline APTR __inline_ReqTools_rtLockWindow(struct Window * __arg1, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC1(APTR, rtLockWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        struct ReqToolsBase *, (__ReqToolsBase), 26, ReqTools    );
}

#define rtLockWindow(arg1) \
    __inline_ReqTools_rtLockWindow((arg1), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtUnlockWindow(struct Window * __arg1, APTR __arg2, APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC2NR(void, rtUnlockWindow,
        AROS_LCA(struct Window *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct ReqToolsBase *, (__ReqToolsBase), 27, ReqTools    );
}

#define rtUnlockWindow(arg1, arg2) \
    __inline_ReqTools_rtUnlockWindow((arg1), (arg2), __REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline struct ReqToolsPrefs * __inline_ReqTools_rtLockPrefs(APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    return AROS_LC0(struct ReqToolsPrefs *, rtLockPrefs,
        struct ReqToolsBase *, (__ReqToolsBase), 28, ReqTools    );
}

#define rtLockPrefs() \
    __inline_ReqTools_rtLockPrefs(__REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#if !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__)

static inline void __inline_ReqTools_rtUnlockPrefs(APTR __ReqToolsBase)
{
    AROS_LIBREQ(ReqToolsBase, 39)
    AROS_LC0NR(void, rtUnlockPrefs,
        struct ReqToolsBase *, (__ReqToolsBase), 29, ReqTools    );
}

#define rtUnlockPrefs() \
    __inline_ReqTools_rtUnlockPrefs(__REQTOOLS_LIBBASE)

#endif /* !defined(__REQTOOLS_LIBAPI__) || (39 <= __REQTOOLS_LIBAPI__) */

#endif /* INLINE_REQTOOLS_H*/
