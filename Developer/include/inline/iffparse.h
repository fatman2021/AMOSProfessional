#ifndef INLINE_IFFPARSE_H
#define INLINE_IFFPARSE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/iffparse/iffparse.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for iffparse
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__IFFPARSE_LIBBASE)
#    define __IFFPARSE_LIBBASE IFFParseBase
#endif


#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct IFFHandle * __inline_IFFParse_AllocIFF(APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC0(struct IFFHandle *, AllocIFF,
        struct Library *, (__IFFParseBase), 5, IFFParse    );
}

#define AllocIFF() \
    __inline_IFFParse_AllocIFF(__IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_OpenIFF(struct IFFHandle * __arg1, LONG __arg2, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC2(LONG, OpenIFF,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__IFFParseBase), 6, IFFParse    );
}

#define OpenIFF(arg1, arg2) \
    __inline_IFFParse_OpenIFF((arg1), (arg2), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_ParseIFF(struct IFFHandle * __arg1, LONG __arg2, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC2(LONG, ParseIFF,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__IFFParseBase), 7, IFFParse    );
}

#define ParseIFF(arg1, arg2) \
    __inline_IFFParse_ParseIFF((arg1), (arg2), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_CloseIFF(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, CloseIFF,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 8, IFFParse    );
}

#define CloseIFF(arg1) \
    __inline_IFFParse_CloseIFF((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_FreeIFF(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, FreeIFF,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 9, IFFParse    );
}

#define FreeIFF(arg1) \
    __inline_IFFParse_FreeIFF((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_ReadChunkBytes(struct IFFHandle * __arg1, APTR __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, ReadChunkBytes,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 10, IFFParse    );
}

#define ReadChunkBytes(arg1, arg2, arg3) \
    __inline_IFFParse_ReadChunkBytes((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_WriteChunkBytes(struct IFFHandle * __arg1, APTR __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, WriteChunkBytes,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 11, IFFParse    );
}

#define WriteChunkBytes(arg1, arg2, arg3) \
    __inline_IFFParse_WriteChunkBytes((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_ReadChunkRecords(struct IFFHandle * __arg1, APTR __arg2, LONG __arg3, LONG __arg4, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC4(LONG, ReadChunkRecords,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct Library *, (__IFFParseBase), 12, IFFParse    );
}

#define ReadChunkRecords(arg1, arg2, arg3, arg4) \
    __inline_IFFParse_ReadChunkRecords((arg1), (arg2), (arg3), (arg4), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_WriteChunkRecords(struct IFFHandle * __arg1, APTR __arg2, LONG __arg3, LONG __arg4, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC4(LONG, WriteChunkRecords,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        AROS_LCA(LONG,(__arg4),D1),
        struct Library *, (__IFFParseBase), 13, IFFParse    );
}

#define WriteChunkRecords(arg1, arg2, arg3, arg4) \
    __inline_IFFParse_WriteChunkRecords((arg1), (arg2), (arg3), (arg4), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_PushChunk(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC4(LONG, PushChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        struct Library *, (__IFFParseBase), 14, IFFParse    );
}

#define PushChunk(arg1, arg2, arg3, arg4) \
    __inline_IFFParse_PushChunk((arg1), (arg2), (arg3), (arg4), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_PopChunk(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(LONG, PopChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 15, IFFParse    );
}

#define PopChunk(arg1) \
    __inline_IFFParse_PopChunk((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_EntryHandler(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, struct Hook * __arg5, APTR __arg6, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC6(LONG, EntryHandler,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(struct Hook *,(__arg5),A1),
        AROS_LCA(APTR,(__arg6),A2),
        struct Library *, (__IFFParseBase), 17, IFFParse    );
}

#define EntryHandler(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_IFFParse_EntryHandler((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_ExitHandler(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, struct Hook * __arg5, APTR __arg6, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC6(LONG, ExitHandler,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(struct Hook *,(__arg5),A1),
        AROS_LCA(APTR,(__arg6),A2),
        struct Library *, (__IFFParseBase), 18, IFFParse    );
}

#define ExitHandler(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_IFFParse_ExitHandler((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_PropChunk(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, PropChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 19, IFFParse    );
}

#define PropChunk(arg1, arg2, arg3) \
    __inline_IFFParse_PropChunk((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_PropChunks(struct IFFHandle * __arg1, const LONG * __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, PropChunks,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(const LONG *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 20, IFFParse    );
}

#define PropChunks(arg1, arg2, arg3) \
    __inline_IFFParse_PropChunks((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_StopChunk(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, StopChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 21, IFFParse    );
}

#define StopChunk(arg1, arg2, arg3) \
    __inline_IFFParse_StopChunk((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_StopChunks(struct IFFHandle * __arg1, const LONG * __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, StopChunks,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(const LONG *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 22, IFFParse    );
}

#define StopChunks(arg1, arg2, arg3) \
    __inline_IFFParse_StopChunks((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_CollectionChunk(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, CollectionChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 23, IFFParse    );
}

#define CollectionChunk(arg1, arg2, arg3) \
    __inline_IFFParse_CollectionChunk((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_CollectionChunks(struct IFFHandle * __arg1, const LONG * __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, CollectionChunks,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(const LONG *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 24, IFFParse    );
}

#define CollectionChunks(arg1, arg2, arg3) \
    __inline_IFFParse_CollectionChunks((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_StopOnExit(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, StopOnExit,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 25, IFFParse    );
}

#define StopOnExit(arg1, arg2, arg3) \
    __inline_IFFParse_StopOnExit((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct StoredProperty * __inline_IFFParse_FindProp(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(struct StoredProperty *, FindProp,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 26, IFFParse    );
}

#define FindProp(arg1, arg2, arg3) \
    __inline_IFFParse_FindProp((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct CollectionItem * __inline_IFFParse_FindCollection(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(struct CollectionItem *, FindCollection,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__IFFParseBase), 27, IFFParse    );
}

#define FindCollection(arg1, arg2, arg3) \
    __inline_IFFParse_FindCollection((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct ContextNode * __inline_IFFParse_FindPropContext(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(struct ContextNode *, FindPropContext,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 28, IFFParse    );
}

#define FindPropContext(arg1) \
    __inline_IFFParse_FindPropContext((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct ContextNode * __inline_IFFParse_CurrentChunk(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(struct ContextNode *, CurrentChunk,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 29, IFFParse    );
}

#define CurrentChunk(arg1) \
    __inline_IFFParse_CurrentChunk((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct ContextNode * __inline_IFFParse_ParentChunk(struct ContextNode * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(struct ContextNode *, ParentChunk,
        AROS_LCA(struct ContextNode *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 30, IFFParse    );
}

#define ParentChunk(arg1) \
    __inline_IFFParse_ParentChunk((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct LocalContextItem * __inline_IFFParse_AllocLocalItem(LONG __arg1, LONG __arg2, LONG __arg3, ULONG __arg4, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC4(struct LocalContextItem *, AllocLocalItem,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        AROS_LCA(LONG,(__arg3),D2),
        AROS_LCA(ULONG,(__arg4),D3),
        struct Library *, (__IFFParseBase), 31, IFFParse    );
}

#define AllocLocalItem(arg1, arg2, arg3, arg4) \
    __inline_IFFParse_AllocLocalItem((arg1), (arg2), (arg3), (arg4), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline APTR __inline_IFFParse_LocalItemData(struct LocalContextItem * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(APTR, LocalItemData,
        AROS_LCA(struct LocalContextItem *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 32, IFFParse    );
}

#define LocalItemData(arg1) \
    __inline_IFFParse_LocalItemData((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_SetLocalItemPurge(struct LocalContextItem * __arg1, struct Hook * __arg2, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC2NR(void, SetLocalItemPurge,
        AROS_LCA(struct LocalContextItem *,(__arg1),A0),
        AROS_LCA(struct Hook *,(__arg2),A1),
        struct Library *, (__IFFParseBase), 33, IFFParse    );
}

#define SetLocalItemPurge(arg1, arg2) \
    __inline_IFFParse_SetLocalItemPurge((arg1), (arg2), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_FreeLocalItem(struct LocalContextItem * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, FreeLocalItem,
        AROS_LCA(struct LocalContextItem *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 34, IFFParse    );
}

#define FreeLocalItem(arg1) \
    __inline_IFFParse_FreeLocalItem((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct LocalContextItem * __inline_IFFParse_FindLocalItem(struct IFFHandle * __arg1, LONG __arg2, LONG __arg3, LONG __arg4, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC4(struct LocalContextItem *, FindLocalItem,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        struct Library *, (__IFFParseBase), 35, IFFParse    );
}

#define FindLocalItem(arg1, arg2, arg3, arg4) \
    __inline_IFFParse_FindLocalItem((arg1), (arg2), (arg3), (arg4), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_StoreLocalItem(struct IFFHandle * __arg1, struct LocalContextItem * __arg2, LONG __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC3(LONG, StoreLocalItem,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(struct LocalContextItem *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__IFFParseBase), 36, IFFParse    );
}

#define StoreLocalItem(arg1, arg2, arg3) \
    __inline_IFFParse_StoreLocalItem((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_StoreItemInContext(struct IFFHandle * __arg1, struct LocalContextItem * __arg2, struct ContextNode * __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC3NR(void, StoreItemInContext,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(struct LocalContextItem *,(__arg2),A1),
        AROS_LCA(struct ContextNode *,(__arg3),A2),
        struct Library *, (__IFFParseBase), 37, IFFParse    );
}

#define StoreItemInContext(arg1, arg2, arg3) \
    __inline_IFFParse_StoreItemInContext((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_InitIFF(struct IFFHandle * __arg1, LONG __arg2, struct Hook * __arg3, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC3NR(void, InitIFF,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(struct Hook *,(__arg3),A1),
        struct Library *, (__IFFParseBase), 38, IFFParse    );
}

#define InitIFF(arg1, arg2, arg3) \
    __inline_IFFParse_InitIFF((arg1), (arg2), (arg3), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_InitIFFasDOS(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, InitIFFasDOS,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 39, IFFParse    );
}

#define InitIFFasDOS(arg1) \
    __inline_IFFParse_InitIFFasDOS((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_InitIFFasClip(struct IFFHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, InitIFFasClip,
        AROS_LCA(struct IFFHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 40, IFFParse    );
}

#define InitIFFasClip(arg1) \
    __inline_IFFParse_InitIFFasClip((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline struct ClipboardHandle * __inline_IFFParse_OpenClipboard(LONG __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(struct ClipboardHandle *, OpenClipboard,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__IFFParseBase), 41, IFFParse    );
}

#define OpenClipboard(arg1) \
    __inline_IFFParse_OpenClipboard((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline void __inline_IFFParse_CloseClipboard(struct ClipboardHandle * __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    AROS_LC1NR(void, CloseClipboard,
        AROS_LCA(struct ClipboardHandle *,(__arg1),A0),
        struct Library *, (__IFFParseBase), 42, IFFParse    );
}

#define CloseClipboard(arg1) \
    __inline_IFFParse_CloseClipboard((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_GoodID(LONG __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(LONG, GoodID,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__IFFParseBase), 43, IFFParse    );
}

#define GoodID(arg1) \
    __inline_IFFParse_GoodID((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline LONG __inline_IFFParse_GoodType(LONG __arg1, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC1(LONG, GoodType,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__IFFParseBase), 44, IFFParse    );
}

#define GoodType(arg1) \
    __inline_IFFParse_GoodType((arg1), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#if !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__)

static inline STRPTR __inline_IFFParse_IDtoStr(LONG __arg1, STRPTR __arg2, APTR __IFFParseBase)
{
    AROS_LIBREQ(IFFParseBase, 33)
    return AROS_LC2(STRPTR, IDtoStr,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(STRPTR,(__arg2),A0),
        struct Library *, (__IFFParseBase), 45, IFFParse    );
}

#define IDtoStr(arg1, arg2) \
    __inline_IFFParse_IDtoStr((arg1), (arg2), __IFFPARSE_LIBBASE)

#endif /* !defined(__IFFPARSE_LIBAPI__) || (33 <= __IFFPARSE_LIBAPI__) */

#endif /* INLINE_IFFPARSE_H*/
