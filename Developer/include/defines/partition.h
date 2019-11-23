#ifndef DEFINES_PARTITION_H
#define DEFINES_PARTITION_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/partition/partition.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for partition
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__PARTITION_LIBBASE)
#    define __PARTITION_LIBBASE PartitionBase
#endif

__BEGIN_DECLS


#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __OpenRootPartition_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(struct PartitionHandle *, OpenRootPartition, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
                  AROS_LCA(LONG,(__arg2),D1), \
        struct PartitionBase *, (__PartitionBase), 5, Partition);\
})

#define OpenRootPartition(arg1, arg2) \
    __OpenRootPartition_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __CloseRootPartition_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1NR(void, CloseRootPartition, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 6, Partition);\
})

#define CloseRootPartition(arg1) \
    __CloseRootPartition_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __OpenPartitionTable_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(LONG, OpenPartitionTable, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 7, Partition);\
})

#define OpenPartitionTable(arg1) \
    __OpenPartitionTable_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __ClosePartitionTable_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1NR(void, ClosePartitionTable, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 8, Partition);\
})

#define ClosePartitionTable(arg1) \
    __ClosePartitionTable_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __WritePartitionTable_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(LONG, WritePartitionTable, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 9, Partition);\
})

#define WritePartitionTable(arg1) \
    __WritePartitionTable_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __CreatePartitionTable_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(LONG, CreatePartitionTable, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct PartitionBase *, (__PartitionBase), 10, Partition);\
})

#define CreatePartitionTable(arg1, arg2) \
    __CreatePartitionTable_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __AddPartition_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(struct PartitionHandle *, AddPartition, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 11, Partition);\
})

#define AddPartition(arg1, arg2) \
    __AddPartition_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define AddPartitionTags(arg1, ...) \
({ \
    const IPTR AddPartition_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddPartition((arg1), (const struct TagItem *)(AddPartition_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __DeletePartition_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1NR(void, DeletePartition, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 12, Partition);\
})

#define DeletePartition(arg1) \
    __DeletePartition_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __GetPartitionTableAttrs_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(LONG, GetPartitionTableAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 13, Partition);\
})

#define GetPartitionTableAttrs(arg1, arg2) \
    __GetPartitionTableAttrs_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetPartitionTableAttrsTags(arg1, ...) \
({ \
    const IPTR GetPartitionTableAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetPartitionTableAttrs((arg1), (const struct TagItem *)(GetPartitionTableAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __SetPartitionTableAttrs_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(LONG, SetPartitionTableAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 14, Partition);\
})

#define SetPartitionTableAttrs(arg1, arg2) \
    __SetPartitionTableAttrs_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define SetPartitionTableAttrsTags(arg1, ...) \
({ \
    const IPTR SetPartitionTableAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPartitionTableAttrs((arg1), (const struct TagItem *)(SetPartitionTableAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __GetPartitionAttrs_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(LONG, GetPartitionAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 15, Partition);\
})

#define GetPartitionAttrs(arg1, arg2) \
    __GetPartitionAttrs_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetPartitionAttrsTags(arg1, ...) \
({ \
    const IPTR GetPartitionAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetPartitionAttrs((arg1), (const struct TagItem *)(GetPartitionAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __SetPartitionAttrs_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(LONG, SetPartitionAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 16, Partition);\
})

#define SetPartitionAttrs(arg1, arg2) \
    __SetPartitionAttrs_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define SetPartitionAttrsTags(arg1, ...) \
({ \
    const IPTR SetPartitionAttrs_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetPartitionAttrs((arg1), (const struct TagItem *)(SetPartitionAttrs_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __QueryPartitionTableAttrs_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(const struct PartitionAttribute *, QueryPartitionTableAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 17, Partition);\
})

#define QueryPartitionTableAttrs(arg1) \
    __QueryPartitionTableAttrs_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __QueryPartitionAttrs_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(const struct PartitionAttribute *, QueryPartitionAttrs, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 18, Partition);\
})

#define QueryPartitionAttrs(arg1) \
    __QueryPartitionAttrs_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __DestroyPartitionTable_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(LONG, DestroyPartitionTable, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 19, Partition);\
})

#define DestroyPartitionTable(arg1) \
    __DestroyPartitionTable_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __FindFileSystemA_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2(struct Node *, FindFileSystemA, \
                  AROS_LCA(struct PartitionHandle *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 20, Partition);\
})

#define FindFileSystemA(arg1, arg2) \
    __FindFileSystemA_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define FindFileSystem(arg1, ...) \
({ \
    const IPTR FindFileSystemA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    FindFileSystemA((arg1), (const struct TagItem *)(FindFileSystemA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __LoadFileSystem_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(BPTR, LoadFileSystem, \
                  AROS_LCA(struct Node *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 21, Partition);\
})

#define LoadFileSystem(arg1) \
    __LoadFileSystem_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __GetFileSystemAttrsA_WB(__PartitionBase, __arg1, __arg2) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC2NR(void, GetFileSystemAttrsA, \
                  AROS_LCA(struct Node *,(__arg1),A1), \
                  AROS_LCA(const struct TagItem *,(__arg2),A2), \
        struct PartitionBase *, (__PartitionBase), 22, Partition);\
})

#define GetFileSystemAttrsA(arg1, arg2) \
    __GetFileSystemAttrsA_WB(__PARTITION_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(PARTITION_NO_INLINE_STDARG)
#define GetFileSystemAttrs(arg1, ...) \
({ \
    const IPTR GetFileSystemAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetFileSystemAttrsA((arg1), (const struct TagItem *)(GetFileSystemAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __AddBootFileSystem_WB(__PartitionBase, __arg1) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC1(LONG, AddBootFileSystem, \
                  AROS_LCA(struct Node *,(__arg1),A1), \
        struct PartitionBase *, (__PartitionBase), 23, Partition);\
})

#define AddBootFileSystem(arg1) \
    __AddBootFileSystem_WB(__PARTITION_LIBBASE, (arg1))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __LoadBootFileSystems_WB(__PartitionBase) ({\
        AROS_LIBREQ(PartitionBase,3)\
        AROS_LC0(LONG, LoadBootFileSystems, \
        struct PartitionBase *, (__PartitionBase), 24, Partition);\
})

#define LoadBootFileSystems() \
    __LoadBootFileSystems_WB(__PARTITION_LIBBASE)

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __ReadPartitionDataQ_WB(__PartitionBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(PartitionBase,3)\
    AROS_LC3QUAD1(LONG, ReadPartitionDataQ,\
         AROS_LCA(struct PartitionHandle *, (__arg1), A0), \
         AROS_LCA(APTR, (__arg2), A1), \
         AROS_LCA(ULONG, (__arg3), D0), \
         AROS_LCAQUAD(UQUAD, (__arg4), D1, D2), \
        struct PartitionBase *, (__PartitionBase), 25, Partition);\
})

#define ReadPartitionDataQ(arg1, arg2, arg3, arg4) \
    __ReadPartitionDataQ_WB(__PARTITION_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

#if !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__)

#define __WritePartitionDataQ_WB(__PartitionBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(PartitionBase,3)\
    AROS_LC3QUAD1(LONG, WritePartitionDataQ,\
         AROS_LCA(struct PartitionHandle *, (__arg1), A0), \
         AROS_LCA(APTR, (__arg2), A1), \
         AROS_LCA(ULONG, (__arg3), D0), \
         AROS_LCAQUAD(UQUAD, (__arg4), D1, D2), \
        struct PartitionBase *, (__PartitionBase), 26, Partition);\
})

#define WritePartitionDataQ(arg1, arg2, arg3, arg4) \
    __WritePartitionDataQ_WB(__PARTITION_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__PARTITION_LIBAPI__) || (3 <= __PARTITION_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_PARTITION_H*/
