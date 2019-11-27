#ifndef INLINE_PARTITION_H
#define INLINE_PARTITION_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/partition/partition.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for partition
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PARTITION_LIBBASE)
#    define __PARTITION_LIBBASE PartitionBase
#endif


#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline struct PartitionHandle * __inline_Partition_OpenRootPartition(CONST_STRPTR __arg1, LONG __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(struct PartitionHandle *, OpenRootPartition,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        AROS_LCA(LONG,(__arg2),D1),
        struct PartitionBase *, (__PartitionBase), 5, Partition    );
}

#define OpenRootPartition(arg1, arg2) \
    __inline_Partition_OpenRootPartition((arg1), (arg2), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline void __inline_Partition_CloseRootPartition(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    AROS_LC1NR(void, CloseRootPartition,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 6, Partition    );
}

#define CloseRootPartition(arg1) \
    __inline_Partition_CloseRootPartition((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_OpenPartitionTable(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(LONG, OpenPartitionTable,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 7, Partition    );
}

#define OpenPartitionTable(arg1) \
    __inline_Partition_OpenPartitionTable((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline void __inline_Partition_ClosePartitionTable(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    AROS_LC1NR(void, ClosePartitionTable,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 8, Partition    );
}

#define ClosePartitionTable(arg1) \
    __inline_Partition_ClosePartitionTable((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_WritePartitionTable(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(LONG, WritePartitionTable,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 9, Partition    );
}

#define WritePartitionTable(arg1) \
    __inline_Partition_WritePartitionTable((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_CreatePartitionTable(struct PartitionHandle * __arg1, ULONG __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(LONG, CreatePartitionTable,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D1),
        struct PartitionBase *, (__PartitionBase), 10, Partition    );
}

#define CreatePartitionTable(arg1, arg2) \
    __inline_Partition_CreatePartitionTable((arg1), (arg2), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline struct PartitionHandle * __inline_Partition_AddPartition(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(struct PartitionHandle *, AddPartition,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 11, Partition    );
}

#define AddPartition(arg1, arg2) \
    __inline_Partition_AddPartition((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define AddPartitionTags(arg1, ...) \
({ \
    const IPTR AddPartition_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddPartition((arg1), (const struct TagItem *)(AddPartition_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline void __inline_Partition_DeletePartition(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    AROS_LC1NR(void, DeletePartition,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 12, Partition    );
}

#define DeletePartition(arg1) \
    __inline_Partition_DeletePartition((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_GetPartitionTableAttrs(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(LONG, GetPartitionTableAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 13, Partition    );
}

#define GetPartitionTableAttrs(arg1, arg2) \
    __inline_Partition_GetPartitionTableAttrs((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetPartitionTableAttrsTags(arg1, ...) \
({ \
    const IPTR GetPartitionTableAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetPartitionTableAttrs((arg1), (const struct TagItem *)(GetPartitionTableAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_SetPartitionTableAttrs(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(LONG, SetPartitionTableAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 14, Partition    );
}

#define SetPartitionTableAttrs(arg1, arg2) \
    __inline_Partition_SetPartitionTableAttrs((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define SetPartitionTableAttrsTags(arg1, ...) \
({ \
    const IPTR SetPartitionTableAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPartitionTableAttrs((arg1), (const struct TagItem *)(SetPartitionTableAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_GetPartitionAttrs(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(LONG, GetPartitionAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 15, Partition    );
}

#define GetPartitionAttrs(arg1, arg2) \
    __inline_Partition_GetPartitionAttrs((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetPartitionAttrsTags(arg1, ...) \
({ \
    const IPTR GetPartitionAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetPartitionAttrs((arg1), (const struct TagItem *)(GetPartitionAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_SetPartitionAttrs(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(LONG, SetPartitionAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 16, Partition    );
}

#define SetPartitionAttrs(arg1, arg2) \
    __inline_Partition_SetPartitionAttrs((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define SetPartitionAttrsTags(arg1, ...) \
({ \
    const IPTR SetPartitionAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPartitionAttrs((arg1), (const struct TagItem *)(SetPartitionAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline const struct PartitionAttribute * __inline_Partition_QueryPartitionTableAttrs(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(const struct PartitionAttribute *, QueryPartitionTableAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 17, Partition    );
}

#define QueryPartitionTableAttrs(arg1) \
    __inline_Partition_QueryPartitionTableAttrs((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline const struct PartitionAttribute * __inline_Partition_QueryPartitionAttrs(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(const struct PartitionAttribute *, QueryPartitionAttrs,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 18, Partition    );
}

#define QueryPartitionAttrs(arg1) \
    __inline_Partition_QueryPartitionAttrs((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_DestroyPartitionTable(struct PartitionHandle * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(LONG, DestroyPartitionTable,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 19, Partition    );
}

#define DestroyPartitionTable(arg1) \
    __inline_Partition_DestroyPartitionTable((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline struct Node * __inline_Partition_FindFileSystemA(struct PartitionHandle * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC2(struct Node *, FindFileSystemA,
        AROS_LCA(struct PartitionHandle *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 20, Partition    );
}

#define FindFileSystemA(arg1, arg2) \
    __inline_Partition_FindFileSystemA((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define FindFileSystem(arg1, ...) \
({ \
    const IPTR FindFileSystemA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    FindFileSystemA((arg1), (const struct TagItem *)(FindFileSystemA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline BPTR __inline_Partition_LoadFileSystem(struct Node * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(BPTR, LoadFileSystem,
        AROS_LCA(struct Node *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 21, Partition    );
}

#define LoadFileSystem(arg1) \
    __inline_Partition_LoadFileSystem((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline void __inline_Partition_GetFileSystemAttrsA(struct Node * __arg1, const struct TagItem * __arg2, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    AROS_LC2NR(void, GetFileSystemAttrsA,
        AROS_LCA(struct Node *,(__arg1),A1),
        AROS_LCA(const struct TagItem *,(__arg2),A2),
        struct PartitionBase *, (__PartitionBase), 22, Partition    );
}

#define GetFileSystemAttrsA(arg1, arg2) \
    __inline_Partition_GetFileSystemAttrsA((arg1), (arg2), __PARTITION_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetFileSystemAttrs(arg1, ...) \
({ \
    const IPTR GetFileSystemAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetFileSystemAttrsA((arg1), (const struct TagItem *)(GetFileSystemAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_AddBootFileSystem(struct Node * __arg1, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC1(LONG, AddBootFileSystem,
        AROS_LCA(struct Node *,(__arg1),A1),
        struct PartitionBase *, (__PartitionBase), 23, Partition    );
}

#define AddBootFileSystem(arg1) \
    __inline_Partition_AddBootFileSystem((arg1), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_LoadBootFileSystems(APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC0(LONG, LoadBootFileSystems,
        struct PartitionBase *, (__PartitionBase), 24, Partition    );
}

#define LoadBootFileSystems() \
    __inline_Partition_LoadBootFileSystems(__PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_ReadPartitionDataQ(struct PartitionHandle * __arg1, APTR __arg2, ULONG __arg3, UQUAD __arg4, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC3QUAD1(LONG, ReadPartitionDataQ,
         AROS_LCA(struct PartitionHandle *, (__arg1), A0), 
         AROS_LCA(APTR, (__arg2), A1), 
         AROS_LCA(ULONG, (__arg3), D0), 
         AROS_LCAQUAD(UQUAD, (__arg4), D1, D2), 
        struct PartitionBase *, (__PartitionBase), 25, Partition    );
}

#define ReadPartitionDataQ(arg1, arg2, arg3, arg4) \
    __inline_Partition_ReadPartitionDataQ((arg1), (arg2), (arg3), (arg4), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

static inline LONG __inline_Partition_WritePartitionDataQ(struct PartitionHandle * __arg1, APTR __arg2, ULONG __arg3, UQUAD __arg4, APTR __PartitionBase)
{
    AROS_LIBREQ(PartitionBase, 3)
    return AROS_LC3QUAD1(LONG, WritePartitionDataQ,
         AROS_LCA(struct PartitionHandle *, (__arg1), A0), 
         AROS_LCA(APTR, (__arg2), A1), 
         AROS_LCA(ULONG, (__arg3), D0), 
         AROS_LCAQUAD(UQUAD, (__arg4), D1, D2), 
        struct PartitionBase *, (__PartitionBase), 26, Partition    );
}

#define WritePartitionDataQ(arg1, arg2, arg3, arg4) \
    __inline_Partition_WritePartitionDataQ((arg1), (arg2), (arg3), (arg4), __PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#endif /* INLINE_PARTITION_H*/
