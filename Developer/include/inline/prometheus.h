#ifndef INLINE_PROMETHEUS_H
#define INLINE_PROMETHEUS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/prometheus/prometheus.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for prometheus
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PROMETHEUS_LIBBASE)
#    define __PROMETHEUS_LIBBASE PrometheusBase
#endif


#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline PCIBoard * __inline_Prometheus_Prm_FindBoardTagList(PCIBoard * __arg1, struct TagItem * __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(PCIBoard *, Prm_FindBoardTagList,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__PrometheusBase), 5, Prometheus    );
}

#define Prm_FindBoardTagList(arg1, arg2) \
    __inline_Prometheus_Prm_FindBoardTagList((arg1), (arg2), __PROMETHEUS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PROMETHEUS_NO_INLINE_STDARG)
#define Prm_FindBoardTags(arg1, ...) \
({ \
    const IPTR Prm_FindBoardTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    Prm_FindBoardTagList((arg1), (struct TagItem *)(Prm_FindBoardTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline ULONG __inline_Prometheus_Prm_GetBoardAttrsTagList(PCIBoard * __arg1, struct TagItem * __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(ULONG, Prm_GetBoardAttrsTagList,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__PrometheusBase), 6, Prometheus    );
}

#define Prm_GetBoardAttrsTagList(arg1, arg2) \
    __inline_Prometheus_Prm_GetBoardAttrsTagList((arg1), (arg2), __PROMETHEUS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PROMETHEUS_NO_INLINE_STDARG)
#define Prm_GetBoardAttrsTags(arg1, ...) \
({ \
    const IPTR Prm_GetBoardAttrsTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    Prm_GetBoardAttrsTagList((arg1), (struct TagItem *)(Prm_GetBoardAttrsTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline ULONG __inline_Prometheus_Prm_ReadConfigLong(PCIBoard * __arg1, UBYTE __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(ULONG, Prm_ReadConfigLong,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(UBYTE,(__arg2),D0),
        struct Library *, (__PrometheusBase), 7, Prometheus    );
}

#define Prm_ReadConfigLong(arg1, arg2) \
    __inline_Prometheus_Prm_ReadConfigLong((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline UWORD __inline_Prometheus_Prm_ReadConfigWord(PCIBoard * __arg1, UBYTE __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(UWORD, Prm_ReadConfigWord,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(UBYTE,(__arg2),D0),
        struct Library *, (__PrometheusBase), 8, Prometheus    );
}

#define Prm_ReadConfigWord(arg1, arg2) \
    __inline_Prometheus_Prm_ReadConfigWord((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline UBYTE __inline_Prometheus_Prm_ReadConfigByte(PCIBoard * __arg1, UBYTE __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(UBYTE, Prm_ReadConfigByte,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(UBYTE,(__arg2),D0),
        struct Library *, (__PrometheusBase), 9, Prometheus    );
}

#define Prm_ReadConfigByte(arg1, arg2) \
    __inline_Prometheus_Prm_ReadConfigByte((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline void __inline_Prometheus_Prm_WriteConfigLong(PCIBoard * __arg1, ULONG __arg2, UBYTE __arg3, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    AROS_LC3NR(void, Prm_WriteConfigLong,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(UBYTE,(__arg3),D1),
        struct Library *, (__PrometheusBase), 10, Prometheus    );
}

#define Prm_WriteConfigLong(arg1, arg2, arg3) \
    __inline_Prometheus_Prm_WriteConfigLong((arg1), (arg2), (arg3), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline void __inline_Prometheus_Prm_WriteConfigWord(PCIBoard * __arg1, UWORD __arg2, UBYTE __arg3, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    AROS_LC3NR(void, Prm_WriteConfigWord,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(UWORD,(__arg2),D0),
        AROS_LCA(UBYTE,(__arg3),D1),
        struct Library *, (__PrometheusBase), 11, Prometheus    );
}

#define Prm_WriteConfigWord(arg1, arg2, arg3) \
    __inline_Prometheus_Prm_WriteConfigWord((arg1), (arg2), (arg3), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline void __inline_Prometheus_Prm_WriteConfigByte(PCIBoard * __arg1, UBYTE __arg2, UBYTE __arg3, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    AROS_LC3NR(void, Prm_WriteConfigByte,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(UBYTE,(__arg2),D0),
        AROS_LCA(UBYTE,(__arg3),D1),
        struct Library *, (__PrometheusBase), 12, Prometheus    );
}

#define Prm_WriteConfigByte(arg1, arg2, arg3) \
    __inline_Prometheus_Prm_WriteConfigByte((arg1), (arg2), (arg3), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline ULONG __inline_Prometheus_Prm_SetBoardAttrsTagList(PCIBoard * __arg1, struct TagItem * __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(ULONG, Prm_SetBoardAttrsTagList,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__PrometheusBase), 13, Prometheus    );
}

#define Prm_SetBoardAttrsTagList(arg1, arg2) \
    __inline_Prometheus_Prm_SetBoardAttrsTagList((arg1), (arg2), __PROMETHEUS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PROMETHEUS_NO_INLINE_STDARG)
#define Prm_SetBoardAttrsTags(arg1, ...) \
({ \
    const IPTR Prm_SetBoardAttrsTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    Prm_SetBoardAttrsTagList((arg1), (struct TagItem *)(Prm_SetBoardAttrsTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline BOOL __inline_Prometheus_Prm_AddIntServer(PCIBoard * __arg1, struct Interrupt * __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC2(BOOL, Prm_AddIntServer,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(struct Interrupt *,(__arg2),A1),
        struct Library *, (__PrometheusBase), 14, Prometheus    );
}

#define Prm_AddIntServer(arg1, arg2) \
    __inline_Prometheus_Prm_AddIntServer((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline void __inline_Prometheus_Prm_RemIntServer(PCIBoard * __arg1, struct Interrupt * __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    AROS_LC2NR(void, Prm_RemIntServer,
        AROS_LCA(PCIBoard *,(__arg1),A0),
        AROS_LCA(struct Interrupt *,(__arg2),A1),
        struct Library *, (__PrometheusBase), 15, Prometheus    );
}

#define Prm_RemIntServer(arg1, arg2) \
    __inline_Prometheus_Prm_RemIntServer((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline APTR __inline_Prometheus_Prm_AllocDMABuffer(ULONG __arg1, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC1(APTR, Prm_AllocDMABuffer,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__PrometheusBase), 16, Prometheus    );
}

#define Prm_AllocDMABuffer(arg1) \
    __inline_Prometheus_Prm_AllocDMABuffer((arg1), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline void __inline_Prometheus_Prm_FreeDMABuffer(APTR __arg1, ULONG __arg2, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    AROS_LC2NR(void, Prm_FreeDMABuffer,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__PrometheusBase), 17, Prometheus    );
}

#define Prm_FreeDMABuffer(arg1, arg2) \
    __inline_Prometheus_Prm_FreeDMABuffer((arg1), (arg2), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#if !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__)

static inline APTR __inline_Prometheus_Prm_GetPhysicalAddr(APTR __arg1, APTR __PrometheusBase)
{
    AROS_LIBREQ(PrometheusBase, 2)
    return AROS_LC1(APTR, Prm_GetPhysicalAddr,
        AROS_LCA(APTR,(__arg1),D0),
        struct Library *, (__PrometheusBase), 18, Prometheus    );
}

#define Prm_GetPhysicalAddr(arg1) \
    __inline_Prometheus_Prm_GetPhysicalAddr((arg1), __PROMETHEUS_LIBBASE)

#endif /* !defined(__PROMETHEUS_LIBAPI__) || (2 <= __PROMETHEUS_LIBAPI__) */

#endif /* INLINE_PROMETHEUS_H*/
