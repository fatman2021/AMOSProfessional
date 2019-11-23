#ifndef INLINE_EXPANSION_H
#define INLINE_EXPANSION_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/expansion/expansion.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for expansion
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EXPANSION_LIBBASE)
#    define __EXPANSION_LIBBASE ExpansionBase
#endif


#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_AddConfigDev(struct ConfigDev * __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC1NR(void, AddConfigDev,
        AROS_LCA(struct ConfigDev *,(__arg1),A0),
        struct Library *, (__ExpansionBase), 5, Expansion    );
}

#define AddConfigDev(arg1) \
    __inline_Expansion_AddConfigDev((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (36 <= __EXPANSION_LIBAPI__)

static inline BOOL __inline_Expansion_AddBootNode(LONG __arg1, ULONG __arg2, struct DeviceNode * __arg3, struct ConfigDev * __arg4, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 36)
    return AROS_LC4(BOOL, AddBootNode,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(struct DeviceNode *,(__arg3),A0),
        AROS_LCA(struct ConfigDev *,(__arg4),A1),
        struct Library *, (__ExpansionBase), 6, Expansion    );
}

#define AddBootNode(arg1, arg2, arg3, arg4) \
    __inline_Expansion_AddBootNode((arg1), (arg2), (arg3), (arg4), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (36 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_AllocBoardMem(ULONG __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC1NR(void, AllocBoardMem,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__ExpansionBase), 7, Expansion    );
}

#define AllocBoardMem(arg1) \
    __inline_Expansion_AllocBoardMem((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline struct ConfigDev * __inline_Expansion_AllocConfigDev(APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC0(struct ConfigDev *, AllocConfigDev,
        struct Library *, (__ExpansionBase), 8, Expansion    );
}

#define AllocConfigDev() \
    __inline_Expansion_AllocConfigDev(__EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline APTR __inline_Expansion_AllocExpansionMem(ULONG __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC2(APTR, AllocExpansionMem,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__ExpansionBase), 9, Expansion    );
}

#define AllocExpansionMem(arg1, arg2) \
    __inline_Expansion_AllocExpansionMem((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline BOOL __inline_Expansion_ConfigBoard(APTR __arg1, struct ConfigDev * __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC2(BOOL, ConfigBoard,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct ConfigDev *,(__arg2),A1),
        struct Library *, (__ExpansionBase), 10, Expansion    );
}

#define ConfigBoard(arg1, arg2) \
    __inline_Expansion_ConfigBoard((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_ConfigChain(APTR __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC1NR(void, ConfigChain,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ExpansionBase), 11, Expansion    );
}

#define ConfigChain(arg1) \
    __inline_Expansion_ConfigChain((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline struct ConfigDev * __inline_Expansion_FindConfigDev(struct ConfigDev * __arg1, LONG __arg2, LONG __arg3, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC3(struct ConfigDev *, FindConfigDev,
        AROS_LCA(struct ConfigDev *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        struct Library *, (__ExpansionBase), 12, Expansion    );
}

#define FindConfigDev(arg1, arg2, arg3) \
    __inline_Expansion_FindConfigDev((arg1), (arg2), (arg3), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_FreeBoardMem(ULONG __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC2NR(void, FreeBoardMem,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__ExpansionBase), 13, Expansion    );
}

#define FreeBoardMem(arg1, arg2) \
    __inline_Expansion_FreeBoardMem((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_FreeConfigDev(struct ConfigDev * __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC1NR(void, FreeConfigDev,
        AROS_LCA(struct ConfigDev *,(__arg1),A0),
        struct Library *, (__ExpansionBase), 14, Expansion    );
}

#define FreeConfigDev(arg1) \
    __inline_Expansion_FreeConfigDev((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_FreeExpansionMem(ULONG __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC2NR(void, FreeExpansionMem,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct Library *, (__ExpansionBase), 15, Expansion    );
}

#define FreeExpansionMem(arg1, arg2) \
    __inline_Expansion_FreeExpansionMem((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline UBYTE __inline_Expansion_ReadExpansionByte(APTR __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC2(UBYTE, ReadExpansionByte,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ExpansionBase), 16, Expansion    );
}

#define ReadExpansionByte(arg1, arg2) \
    __inline_Expansion_ReadExpansionByte((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline BOOL __inline_Expansion_ReadExpansionRom(APTR __arg1, struct ConfigDev * __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC2(BOOL, ReadExpansionRom,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct ConfigDev *,(__arg2),A1),
        struct Library *, (__ExpansionBase), 17, Expansion    );
}

#define ReadExpansionRom(arg1, arg2) \
    __inline_Expansion_ReadExpansionRom((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_RemConfigDev(struct ConfigDev * __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC1NR(void, RemConfigDev,
        AROS_LCA(struct ConfigDev *,(__arg1),A0),
        struct Library *, (__ExpansionBase), 18, Expansion    );
}

#define RemConfigDev(arg1) \
    __inline_Expansion_RemConfigDev((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_WriteExpansionByte(APTR __arg1, ULONG __arg2, ULONG __arg3, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC3NR(void, WriteExpansionByte,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct Library *, (__ExpansionBase), 19, Expansion    );
}

#define WriteExpansionByte(arg1, arg2, arg3) \
    __inline_Expansion_WriteExpansionByte((arg1), (arg2), (arg3), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_ObtainConfigBinding(APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC0NR(void, ObtainConfigBinding,
        struct Library *, (__ExpansionBase), 20, Expansion    );
}

#define ObtainConfigBinding() \
    __inline_Expansion_ObtainConfigBinding(__EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_ReleaseConfigBinding(APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC0NR(void, ReleaseConfigBinding,
        struct Library *, (__ExpansionBase), 21, Expansion    );
}

#define ReleaseConfigBinding() \
    __inline_Expansion_ReleaseConfigBinding(__EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_SetCurrentBinding(struct CurrentBinding * __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    AROS_LC2NR(void, SetCurrentBinding,
        AROS_LCA(struct CurrentBinding *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ExpansionBase), 22, Expansion    );
}

#define SetCurrentBinding(arg1, arg2) \
    __inline_Expansion_SetCurrentBinding((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline ULONG __inline_Expansion_GetCurrentBinding(struct CurrentBinding * __arg1, ULONG __arg2, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC2(ULONG, GetCurrentBinding,
        AROS_LCA(struct CurrentBinding *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__ExpansionBase), 23, Expansion    );
}

#define GetCurrentBinding(arg1, arg2) \
    __inline_Expansion_GetCurrentBinding((arg1), (arg2), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline struct DeviceNode * __inline_Expansion_MakeDosNode(APTR __arg1, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC1(struct DeviceNode *, MakeDosNode,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__ExpansionBase), 24, Expansion    );
}

#define MakeDosNode(arg1) \
    __inline_Expansion_MakeDosNode((arg1), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__)

static inline BOOL __inline_Expansion_AddDosNode(LONG __arg1, ULONG __arg2, struct DeviceNode * __arg3, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 33)
    return AROS_LC3(BOOL, AddDosNode,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(struct DeviceNode *,(__arg3),A0),
        struct Library *, (__ExpansionBase), 25, Expansion    );
}

#define AddDosNode(arg1, arg2, arg3) \
    __inline_Expansion_AddDosNode((arg1), (arg2), (arg3), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (33 <= __EXPANSION_LIBAPI__) */

#if !defined(__EXPANSION_LIBAPI__) || (36 <= __EXPANSION_LIBAPI__)

static inline void __inline_Expansion_WriteExpansionWord(APTR __arg1, ULONG __arg2, ULONG __arg3, APTR __ExpansionBase)
{
    AROS_LIBREQ(ExpansionBase, 36)
    AROS_LC3NR(void, WriteExpansionWord,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct Library *, (__ExpansionBase), 27, Expansion    );
}

#define WriteExpansionWord(arg1, arg2, arg3) \
    __inline_Expansion_WriteExpansionWord((arg1), (arg2), (arg3), __EXPANSION_LIBBASE)

#endif /* !defined(__EXPANSION_LIBAPI__) || (36 <= __EXPANSION_LIBAPI__) */

#endif /* INLINE_EXPANSION_H*/
