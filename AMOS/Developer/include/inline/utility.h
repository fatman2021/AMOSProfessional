#ifndef INLINE_UTILITY_H
#define INLINE_UTILITY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/utility/utility.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for utility
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__UTILITY_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__UTILITY_NOLIBBASE__)
#    define __UTILITY_LIBBASE __aros_getbase_UtilityBase()
#  else
#    define __UTILITY_LIBBASE UtilityBase
#  endif
#endif


#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline struct TagItem * __inline_Utility_FindTagItem(Tag __arg1, const struct TagItem * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(struct TagItem *, FindTagItem,
        AROS_LCA(Tag,(__arg1),D0),
        AROS_LCA(const struct TagItem *,(__arg2),A0),
        struct UtilityBase *, (__UtilityBase), 5, Utility    );
}

#define FindTagItem(arg1, arg2) \
    __inline_Utility_FindTagItem((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline IPTR __inline_Utility_GetTagData(Tag __arg1, IPTR __arg2, const struct TagItem * __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC3(IPTR, GetTagData,
        AROS_LCA(Tag,(__arg1),D0),
        AROS_LCA(IPTR,(__arg2),D1),
        AROS_LCA(const struct TagItem *,(__arg3),A0),
        struct UtilityBase *, (__UtilityBase), 6, Utility    );
}

#define GetTagData(arg1, arg2, arg3) \
    __inline_Utility_GetTagData((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_PackBoolTags(ULONG __arg1, struct TagItem * __arg2, struct TagItem * __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC3(ULONG, PackBoolTags,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct TagItem *,(__arg2),A0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct UtilityBase *, (__UtilityBase), 7, Utility    );
}

#define PackBoolTags(arg1, arg2, arg3) \
    __inline_Utility_PackBoolTags((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline struct TagItem * __inline_Utility_NextTagItem(struct TagItem ** __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC1(struct TagItem *, NextTagItem,
        AROS_LCA(struct TagItem **,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 8, Utility    );
}

#define NextTagItem(arg1) \
    __inline_Utility_NextTagItem((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_FilterTagChanges(struct TagItem * __arg1, const struct TagItem * __arg2, BOOL __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    AROS_LC3NR(void, FilterTagChanges,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        AROS_LCA(const struct TagItem *,(__arg2),A1),
        AROS_LCA(BOOL,(__arg3),D0),
        struct UtilityBase *, (__UtilityBase), 9, Utility    );
}

#define FilterTagChanges(arg1, arg2, arg3) \
    __inline_Utility_FilterTagChanges((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_MapTags(struct TagItem * __arg1, struct TagItem * __arg2, ULONG __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    AROS_LC3NR(void, MapTags,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct UtilityBase *, (__UtilityBase), 10, Utility    );
}

#define MapTags(arg1, arg2, arg3) \
    __inline_Utility_MapTags((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline struct TagItem * __inline_Utility_AllocateTagItems(ULONG __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC1(struct TagItem *, AllocateTagItems,
        AROS_LCA(ULONG,(__arg1),D0),
        struct UtilityBase *, (__UtilityBase), 11, Utility    );
}

#define AllocateTagItems(arg1) \
    __inline_Utility_AllocateTagItems((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline struct TagItem * __inline_Utility_CloneTagItems(const struct TagItem * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC1(struct TagItem *, CloneTagItems,
        AROS_LCA(const struct TagItem *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 12, Utility    );
}

#define CloneTagItems(arg1) \
    __inline_Utility_CloneTagItems((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_FreeTagItems(struct TagItem * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    AROS_LC1NR(void, FreeTagItems,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 13, Utility    );
}

#define FreeTagItems(arg1) \
    __inline_Utility_FreeTagItems((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_RefreshTagItemClones(struct TagItem * __arg1, const struct TagItem * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    AROS_LC2NR(void, RefreshTagItemClones,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        AROS_LCA(const struct TagItem *,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 14, Utility    );
}

#define RefreshTagItemClones(arg1, arg2) \
    __inline_Utility_RefreshTagItemClones((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline BOOL __inline_Utility_TagInArray(Tag __arg1, Tag * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(BOOL, TagInArray,
        AROS_LCA(Tag,(__arg1),D0),
        AROS_LCA(Tag *,(__arg2),A0),
        struct UtilityBase *, (__UtilityBase), 15, Utility    );
}

#define TagInArray(arg1, arg2) \
    __inline_Utility_TagInArray((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_FilterTagItems(struct TagItem * __arg1, Tag * __arg2, ULONG __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC3(ULONG, FilterTagItems,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        AROS_LCA(Tag *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct UtilityBase *, (__UtilityBase), 16, Utility    );
}

#define FilterTagItems(arg1, arg2, arg3) \
    __inline_Utility_FilterTagItems((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline IPTR __inline_Utility_CallHookPkt(struct Hook * __arg1, APTR __arg2, APTR __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC3(IPTR, CallHookPkt,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(APTR,(__arg3),A1),
        struct UtilityBase *, (__UtilityBase), 17, Utility    );
}

#define CallHookPkt(arg1, arg2, arg3) \
    __inline_Utility_CallHookPkt((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_Amiga2Date(ULONG __arg1, struct ClockData * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    AROS_LC2NR(void, Amiga2Date,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct ClockData *,(__arg2),A0),
        struct UtilityBase *, (__UtilityBase), 20, Utility    );
}

#define Amiga2Date(arg1, arg2) \
    __inline_Utility_Amiga2Date((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_Date2Amiga(struct ClockData * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC1(ULONG, Date2Amiga,
        AROS_LCA(struct ClockData *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 21, Utility    );
}

#define Date2Amiga(arg1) \
    __inline_Utility_Date2Amiga((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_CheckDate(struct ClockData * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC1(ULONG, CheckDate,
        AROS_LCA(struct ClockData *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 22, Utility    );
}

#define CheckDate(arg1) \
    __inline_Utility_CheckDate((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline LONG __inline_Utility_SMult32(LONG __arg1, LONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(LONG, SMult32,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 23, Utility    );
}

#define SMult32(arg1, arg2) \
    __inline_Utility_SMult32((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_UMult32(ULONG __arg1, ULONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(ULONG, UMult32,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 24, Utility    );
}

#define UMult32(arg1, arg2) \
    __inline_Utility_UMult32((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline QUAD __inline_Utility_SDivMod32(LONG __arg1, LONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(QUAD, SDivMod32,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 25, Utility    );
}

#define SDivMod32(arg1, arg2) \
    __inline_Utility_SDivMod32((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_UDivMod32(ULONG __arg1, ULONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 36)
    return AROS_LC2(ULONG, UDivMod32,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 26, Utility    );
}

#define UDivMod32(arg1, arg2) \
    __inline_Utility_UDivMod32((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (36 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__)

static inline LONG __inline_Utility_Stricmp(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 37)
    return AROS_LC2(LONG, Stricmp,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 27, Utility    );
}

#define Stricmp(arg1, arg2) \
    __inline_Utility_Stricmp((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__)

static inline LONG __inline_Utility_Strnicmp(CONST_STRPTR __arg1, CONST_STRPTR __arg2, LONG __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 37)
    return AROS_LC3(LONG, Strnicmp,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct UtilityBase *, (__UtilityBase), 28, Utility    );
}

#define Strnicmp(arg1, arg2, arg3) \
    __inline_Utility_Strnicmp((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__)

static inline UBYTE __inline_Utility_ToUpper(ULONG __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 37)
    return AROS_LC1(UBYTE, ToUpper,
        AROS_LCA(ULONG,(__arg1),D0),
        struct UtilityBase *, (__UtilityBase), 29, Utility    );
}

#define ToUpper(arg1) \
    __inline_Utility_ToUpper((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__)

static inline UBYTE __inline_Utility_ToLower(ULONG __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 37)
    return AROS_LC1(UBYTE, ToLower,
        AROS_LCA(ULONG,(__arg1),D0),
        struct UtilityBase *, (__UtilityBase), 30, Utility    );
}

#define ToLower(arg1) \
    __inline_Utility_ToLower((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (37 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_ApplyTagChanges(struct TagItem * __arg1, struct TagItem * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    AROS_LC2NR(void, ApplyTagChanges,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 31, Utility    );
}

#define ApplyTagChanges(arg1, arg2) \
    __inline_Utility_ApplyTagChanges((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline QUAD __inline_Utility_SMult64(LONG __arg1, LONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC2(QUAD, SMult64,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(LONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 33, Utility    );
}

#define SMult64(arg1, arg2) \
    __inline_Utility_SMult64((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline UQUAD __inline_Utility_UMult64(ULONG __arg1, ULONG __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC2(UQUAD, UMult64,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct UtilityBase *, (__UtilityBase), 34, Utility    );
}

#define UMult64(arg1, arg2) \
    __inline_Utility_UMult64((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_PackStructureTags(APTR __arg1, ULONG * __arg2, struct TagItem * __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC3(ULONG, PackStructureTags,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct UtilityBase *, (__UtilityBase), 35, Utility    );
}

#define PackStructureTags(arg1, arg2, arg3) \
    __inline_Utility_PackStructureTags((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_UnpackStructureTags(APTR __arg1, ULONG * __arg2, struct TagItem * __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC3(ULONG, UnpackStructureTags,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(struct TagItem *,(__arg3),A2),
        struct UtilityBase *, (__UtilityBase), 36, Utility    );
}

#define UnpackStructureTags(arg1, arg2, arg3) \
    __inline_Utility_UnpackStructureTags((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline BOOL __inline_Utility_AddNamedObject(struct NamedObject * __arg1, struct NamedObject * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC2(BOOL, AddNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        AROS_LCA(struct NamedObject *,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 37, Utility    );
}

#define AddNamedObject(arg1, arg2) \
    __inline_Utility_AddNamedObject((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline struct NamedObject * __inline_Utility_AllocNamedObjectA(CONST_STRPTR __arg1, struct TagItem * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC2(struct NamedObject *, AllocNamedObjectA,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 38, Utility    );
}

#define AllocNamedObjectA(arg1, arg2) \
    __inline_Utility_AllocNamedObjectA((arg1), (arg2), __UTILITY_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(UTILITY_NO_INLINE_STDARG)
#define AllocNamedObject(arg1, ...) \
({ \
    const IPTR AllocNamedObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocNamedObjectA((arg1), (struct TagItem *)(AllocNamedObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline LONG __inline_Utility_AttemptRemNamedObject(struct NamedObject * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC1(LONG, AttemptRemNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 39, Utility    );
}

#define AttemptRemNamedObject(arg1) \
    __inline_Utility_AttemptRemNamedObject((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline struct NamedObject * __inline_Utility_FindNamedObject(struct NamedObject * __arg1, CONST_STRPTR __arg2, struct NamedObject * __arg3, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC3(struct NamedObject *, FindNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        AROS_LCA(struct NamedObject *,(__arg3),A2),
        struct UtilityBase *, (__UtilityBase), 40, Utility    );
}

#define FindNamedObject(arg1, arg2, arg3) \
    __inline_Utility_FindNamedObject((arg1), (arg2), (arg3), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_FreeNamedObject(struct NamedObject * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    AROS_LC1NR(void, FreeNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 41, Utility    );
}

#define FreeNamedObject(arg1) \
    __inline_Utility_FreeNamedObject((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline STRPTR __inline_Utility_NamedObjectName(struct NamedObject * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC1(STRPTR, NamedObjectName,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 42, Utility    );
}

#define NamedObjectName(arg1) \
    __inline_Utility_NamedObjectName((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_ReleaseNamedObject(struct NamedObject * __arg1, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    AROS_LC1NR(void, ReleaseNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        struct UtilityBase *, (__UtilityBase), 43, Utility    );
}

#define ReleaseNamedObject(arg1) \
    __inline_Utility_ReleaseNamedObject((arg1), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline void __inline_Utility_RemNamedObject(struct NamedObject * __arg1, struct Message * __arg2, APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    AROS_LC2NR(void, RemNamedObject,
        AROS_LCA(struct NamedObject *,(__arg1),A0),
        AROS_LCA(struct Message *,(__arg2),A1),
        struct UtilityBase *, (__UtilityBase), 44, Utility    );
}

#define RemNamedObject(arg1, arg2) \
    __inline_Utility_RemNamedObject((arg1), (arg2), __UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#if !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__)

static inline ULONG __inline_Utility_GetUniqueID(APTR __UtilityBase)
{
    AROS_LIBREQ(UtilityBase, 39)
    return AROS_LC0(ULONG, GetUniqueID,
        struct UtilityBase *, (__UtilityBase), 45, Utility    );
}

#define GetUniqueID() \
    __inline_Utility_GetUniqueID(__UTILITY_LIBBASE)

#endif /* !defined(__UTILITY_LIBAPI__) || (39 <= __UTILITY_LIBAPI__) */

#endif /* INLINE_UTILITY_H*/
