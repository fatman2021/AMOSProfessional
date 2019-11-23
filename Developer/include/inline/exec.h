#ifndef INLINE_EXEC_H
#define INLINE_EXEC_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/exec/exec.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for exec
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EXEC_LIBBASE)
#    define __EXEC_LIBBASE SysBase
#endif


#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_Supervisor(void * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(IPTR, Supervisor,
        AROS_LCA(void *,(__arg1),A5),
        struct ExecBase *, (__SysBase), 5, Exec    );
}

#define Supervisor(arg1) \
    __inline_Exec_Supervisor((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Reschedule(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Reschedule,
        struct ExecBase *, (__SysBase), 8, Exec    );
}

#define Reschedule() \
    __inline_Exec_Reschedule(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Exception(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Exception,
        struct ExecBase *, (__SysBase), 11, Exec    );
}

#define Exception() \
    __inline_Exec_Exception(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_InitCode(ULONG __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, InitCode,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 12, Exec    );
}

#define InitCode(arg1, arg2) \
    __inline_Exec_InitCode((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_InitStruct(CONST_APTR __arg1, APTR __arg2, ULONG __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC3NR(void, InitStruct,
        AROS_LCA(CONST_APTR,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(ULONG,(__arg3),D0),
        struct ExecBase *, (__SysBase), 13, Exec    );
}

#define InitStruct(arg1, arg2, arg3) \
    __inline_Exec_InitStruct((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Library * __inline_Exec_MakeLibrary(CONST_APTR __arg1, CONST_APTR __arg2, ULONG_FUNC __arg3, ULONG __arg4, BPTR __arg5, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC5(struct Library *, MakeLibrary,
        AROS_LCA(CONST_APTR,(__arg1),A0),
        AROS_LCA(CONST_APTR,(__arg2),A1),
        AROS_LCA(ULONG_FUNC,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(BPTR,(__arg5),D1),
        struct ExecBase *, (__SysBase), 14, Exec    );
}

#define MakeLibrary(arg1, arg2, arg3, arg4, arg5) \
    __inline_Exec_MakeLibrary((arg1), (arg2), (arg3), (arg4), (arg5), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_MakeFunctions(APTR __arg1, CONST_APTR __arg2, CONST_APTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC3(ULONG, MakeFunctions,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(CONST_APTR,(__arg2),A1),
        AROS_LCA(CONST_APTR,(__arg3),A2),
        struct ExecBase *, (__SysBase), 15, Exec    );
}

#define MakeFunctions(arg1, arg2, arg3) \
    __inline_Exec_MakeFunctions((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Resident * __inline_Exec_FindResident(const UBYTE * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Resident *, FindResident,
        AROS_LCA(const UBYTE *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 16, Exec    );
}

#define FindResident(arg1) \
    __inline_Exec_FindResident((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_InitResident(struct Resident * __arg1, BPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(APTR, InitResident,
        AROS_LCA(struct Resident *,(__arg1),A1),
        AROS_LCA(BPTR,(__arg2),D1),
        struct ExecBase *, (__SysBase), 17, Exec    );
}

#define InitResident(arg1, arg2) \
    __inline_Exec_InitResident((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Alert(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, Alert,
        AROS_LCA(ULONG,(__arg1),D7),
        struct ExecBase *, (__SysBase), 18, Exec    );
}

#define Alert(arg1) \
    __inline_Exec_Alert((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Debug(unsigned long __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, Debug,
        AROS_LCA(unsigned long,(__arg1),D0),
        struct ExecBase *, (__SysBase), 19, Exec    );
}

#define Debug(arg1) \
    __inline_Exec_Debug((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Disable(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Disable,
        struct ExecBase *, (__SysBase), 20, Exec    );
}

#define Disable() \
    __inline_Exec_Disable(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Enable(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Enable,
        struct ExecBase *, (__SysBase), 21, Exec    );
}

#define Enable() \
    __inline_Exec_Enable(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Forbid(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Forbid,
        struct ExecBase *, (__SysBase), 22, Exec    );
}

#define Forbid() \
    __inline_Exec_Forbid(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Permit(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, Permit,
        struct ExecBase *, (__SysBase), 23, Exec    );
}

#define Permit() \
    __inline_Exec_Permit(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_SetSR(ULONG __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(ULONG, SetSR,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 24, Exec    );
}

#define SetSR(arg1, arg2) \
    __inline_Exec_SetSR((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_SuperState(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC0(APTR, SuperState,
        struct ExecBase *, (__SysBase), 25, Exec    );
}

#define SuperState() \
    __inline_Exec_SuperState(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_UserState(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, UserState,
        AROS_LCA(APTR,(__arg1),D0),
        struct ExecBase *, (__SysBase), 26, Exec    );
}

#define UserState(arg1) \
    __inline_Exec_UserState((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Interrupt * __inline_Exec_SetIntVector(ULONG __arg1, struct Interrupt * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(struct Interrupt *, SetIntVector,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct Interrupt *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 27, Exec    );
}

#define SetIntVector(arg1, arg2) \
    __inline_Exec_SetIntVector((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddIntServer(ULONG __arg1, struct Interrupt * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, AddIntServer,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct Interrupt *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 28, Exec    );
}

#define AddIntServer(arg1, arg2) \
    __inline_Exec_AddIntServer((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemIntServer(ULONG __arg1, struct Interrupt * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, RemIntServer,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(struct Interrupt *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 29, Exec    );
}

#define RemIntServer(arg1, arg2) \
    __inline_Exec_RemIntServer((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Cause(struct Interrupt * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, Cause,
        AROS_LCA(struct Interrupt *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 30, Exec    );
}

#define Cause(arg1) \
    __inline_Exec_Cause((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_Allocate(struct MemHeader * __arg1, IPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(APTR, Allocate,
        AROS_LCA(struct MemHeader *,(__arg1),A0),
        AROS_LCA(IPTR,(__arg2),D0),
        struct ExecBase *, (__SysBase), 31, Exec    );
}

#define Allocate(arg1, arg2) \
    __inline_Exec_Allocate((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Deallocate(struct MemHeader * __arg1, APTR __arg2, IPTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC3NR(void, Deallocate,
        AROS_LCA(struct MemHeader *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(IPTR,(__arg3),D0),
        struct ExecBase *, (__SysBase), 32, Exec    );
}

#define Deallocate(arg1, arg2, arg3) \
    __inline_Exec_Deallocate((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AllocMem(IPTR __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(APTR, AllocMem,
        AROS_LCA(IPTR,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 33, Exec    );
}

#define AllocMem(arg1, arg2) \
    __inline_Exec_AllocMem((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AllocAbs(IPTR __arg1, APTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(APTR, AllocAbs,
        AROS_LCA(IPTR,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A1),
        struct ExecBase *, (__SysBase), 34, Exec    );
}

#define AllocAbs(arg1, arg2) \
    __inline_Exec_AllocAbs((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeMem(APTR __arg1, IPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, FreeMem,
        AROS_LCA(APTR,(__arg1),A1),
        AROS_LCA(IPTR,(__arg2),D0),
        struct ExecBase *, (__SysBase), 35, Exec    );
}

#define FreeMem(arg1, arg2) \
    __inline_Exec_FreeMem((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_AvailMem(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(IPTR, AvailMem,
        AROS_LCA(ULONG,(__arg1),D1),
        struct ExecBase *, (__SysBase), 36, Exec    );
}

#define AvailMem(arg1) \
    __inline_Exec_AvailMem((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct MemList * __inline_Exec_AllocEntry(struct MemList * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct MemList *, AllocEntry,
        AROS_LCA(struct MemList *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 37, Exec    );
}

#define AllocEntry(arg1) \
    __inline_Exec_AllocEntry((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeEntry(struct MemList * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, FreeEntry,
        AROS_LCA(struct MemList *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 38, Exec    );
}

#define FreeEntry(arg1) \
    __inline_Exec_FreeEntry((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Insert(struct List * __arg1, struct Node * __arg2, struct Node * __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC3NR(void, Insert,
        AROS_LCA(struct List *,(__arg1),A0),
        AROS_LCA(struct Node *,(__arg2),A1),
        AROS_LCA(struct Node *,(__arg3),A2),
        struct ExecBase *, (__SysBase), 39, Exec    );
}

#define Insert(arg1, arg2, arg3) \
    __inline_Exec_Insert((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddHead(struct List * __arg1, struct Node * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, AddHead,
        AROS_LCA(struct List *,(__arg1),A0),
        AROS_LCA(struct Node *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 40, Exec    );
}

#define AddHead(arg1, arg2) \
    __inline_Exec_AddHead((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddTail(struct List * __arg1, struct Node * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, AddTail,
        AROS_LCA(struct List *,(__arg1),A0),
        AROS_LCA(struct Node *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 41, Exec    );
}

#define AddTail(arg1, arg2) \
    __inline_Exec_AddTail((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Remove(struct Node * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, Remove,
        AROS_LCA(struct Node *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 42, Exec    );
}

#define Remove(arg1) \
    __inline_Exec_Remove((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Node * __inline_Exec_RemHead(struct List * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Node *, RemHead,
        AROS_LCA(struct List *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 43, Exec    );
}

#define RemHead(arg1) \
    __inline_Exec_RemHead((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Node * __inline_Exec_RemTail(struct List * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Node *, RemTail,
        AROS_LCA(struct List *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 44, Exec    );
}

#define RemTail(arg1) \
    __inline_Exec_RemTail((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Enqueue(struct List * __arg1, struct Node * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, Enqueue,
        AROS_LCA(struct List *,(__arg1),A0),
        AROS_LCA(struct Node *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 45, Exec    );
}

#define Enqueue(arg1, arg2) \
    __inline_Exec_Enqueue((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Node * __inline_Exec_FindName(struct List * __arg1, CONST_STRPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(struct Node *, FindName,
        AROS_LCA(struct List *,(__arg1),A0),
        AROS_LCA(CONST_STRPTR,(__arg2),A1),
        struct ExecBase *, (__SysBase), 46, Exec    );
}

#define FindName(arg1, arg2) \
    __inline_Exec_FindName((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AddTask(struct Task * __arg1, APTR __arg2, APTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC3(APTR, AddTask,
        AROS_LCA(struct Task *,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(APTR,(__arg3),A3),
        struct ExecBase *, (__SysBase), 47, Exec    );
}

#define AddTask(arg1, arg2, arg3) \
    __inline_Exec_AddTask((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemTask(struct Task * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RemTask,
        AROS_LCA(struct Task *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 48, Exec    );
}

#define RemTask(arg1) \
    __inline_Exec_RemTask((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Task * __inline_Exec_FindTask(CONST_STRPTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Task *, FindTask,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 49, Exec    );
}

#define FindTask(arg1) \
    __inline_Exec_FindTask((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline BYTE __inline_Exec_SetTaskPri(struct Task * __arg1, LONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(BYTE, SetTaskPri,
        AROS_LCA(struct Task *,(__arg1),A1),
        AROS_LCA(LONG,(__arg2),D0),
        struct ExecBase *, (__SysBase), 50, Exec    );
}

#define SetTaskPri(arg1, arg2) \
    __inline_Exec_SetTaskPri((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_SetSignal(ULONG __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(ULONG, SetSignal,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 51, Exec    );
}

#define SetSignal(arg1, arg2) \
    __inline_Exec_SetSignal((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_SetExcept(ULONG __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(ULONG, SetExcept,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 52, Exec    );
}

#define SetExcept(arg1, arg2) \
    __inline_Exec_SetExcept((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_Wait(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(ULONG, Wait,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 53, Exec    );
}

#define Wait(arg1) \
    __inline_Exec_Wait((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Signal(struct Task * __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, Signal,
        AROS_LCA(struct Task *,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct ExecBase *, (__SysBase), 54, Exec    );
}

#define Signal(arg1, arg2) \
    __inline_Exec_Signal((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline BYTE __inline_Exec_AllocSignal(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(BYTE, AllocSignal,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 55, Exec    );
}

#define AllocSignal(arg1) \
    __inline_Exec_AllocSignal((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeSignal(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, FreeSignal,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 56, Exec    );
}

#define FreeSignal(arg1) \
    __inline_Exec_FreeSignal((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_AllocTrap(long __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(LONG, AllocTrap,
        AROS_LCA(long,(__arg1),D0),
        struct ExecBase *, (__SysBase), 57, Exec    );
}

#define AllocTrap(arg1) \
    __inline_Exec_AllocTrap((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeTrap(long __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, FreeTrap,
        AROS_LCA(long,(__arg1),D0),
        struct ExecBase *, (__SysBase), 58, Exec    );
}

#define FreeTrap(arg1) \
    __inline_Exec_FreeTrap((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddPort(struct MsgPort * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, AddPort,
        AROS_LCA(struct MsgPort *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 59, Exec    );
}

#define AddPort(arg1) \
    __inline_Exec_AddPort((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemPort(struct MsgPort * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RemPort,
        AROS_LCA(struct MsgPort *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 60, Exec    );
}

#define RemPort(arg1) \
    __inline_Exec_RemPort((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_PutMsg(struct MsgPort * __arg1, struct Message * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, PutMsg,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        AROS_LCA(struct Message *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 61, Exec    );
}

#define PutMsg(arg1, arg2) \
    __inline_Exec_PutMsg((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Message * __inline_Exec_GetMsg(struct MsgPort * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Message *, GetMsg,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 62, Exec    );
}

#define GetMsg(arg1) \
    __inline_Exec_GetMsg((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ReplyMsg(struct Message * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, ReplyMsg,
        AROS_LCA(struct Message *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 63, Exec    );
}

#define ReplyMsg(arg1) \
    __inline_Exec_ReplyMsg((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Message * __inline_Exec_WaitPort(struct MsgPort * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Message *, WaitPort,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 64, Exec    );
}

#define WaitPort(arg1) \
    __inline_Exec_WaitPort((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct MsgPort * __inline_Exec_FindPort(CONST_STRPTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct MsgPort *, FindPort,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 65, Exec    );
}

#define FindPort(arg1) \
    __inline_Exec_FindPort((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddLibrary(struct Library * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, AddLibrary,
        AROS_LCA(struct Library *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 66, Exec    );
}

#define AddLibrary(arg1) \
    __inline_Exec_AddLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemLibrary(struct Library * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RemLibrary,
        AROS_LCA(struct Library *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 67, Exec    );
}

#define RemLibrary(arg1) \
    __inline_Exec_RemLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Library * __inline_Exec_OldOpenLibrary(UBYTE * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct Library *, OldOpenLibrary,
        AROS_LCA(UBYTE *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 68, Exec    );
}

#define OldOpenLibrary(arg1) \
    __inline_Exec_OldOpenLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CloseLibrary(struct Library * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, CloseLibrary,
        AROS_LCA(struct Library *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 69, Exec    );
}

#define CloseLibrary(arg1) \
    __inline_Exec_CloseLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_SetFunction(struct Library * __arg1, LONG __arg2, APTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC3(APTR, SetFunction,
        AROS_LCA(struct Library *,(__arg1),A1),
        AROS_LCA(LONG,(__arg2),A0),
        AROS_LCA(APTR,(__arg3),D0),
        struct ExecBase *, (__SysBase), 70, Exec    );
}

#define SetFunction(arg1, arg2, arg3) \
    __inline_Exec_SetFunction((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_SumLibrary(struct Library * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, SumLibrary,
        AROS_LCA(struct Library *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 71, Exec    );
}

#define SumLibrary(arg1) \
    __inline_Exec_SumLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddDevice(struct Device * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, AddDevice,
        AROS_LCA(struct Device *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 72, Exec    );
}

#define AddDevice(arg1) \
    __inline_Exec_AddDevice((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemDevice(struct Device * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RemDevice,
        AROS_LCA(struct Device *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 73, Exec    );
}

#define RemDevice(arg1) \
    __inline_Exec_RemDevice((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_OpenDevice(CONST_STRPTR __arg1, IPTR __arg2, struct IORequest * __arg3, ULONG __arg4, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC4(LONG, OpenDevice,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(IPTR,(__arg2),D0),
        AROS_LCA(struct IORequest *,(__arg3),A1),
        AROS_LCA(ULONG,(__arg4),D1),
        struct ExecBase *, (__SysBase), 74, Exec    );
}

#define OpenDevice(arg1, arg2, arg3, arg4) \
    __inline_Exec_OpenDevice((arg1), (arg2), (arg3), (arg4), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CloseDevice(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, CloseDevice,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 75, Exec    );
}

#define CloseDevice(arg1) \
    __inline_Exec_CloseDevice((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_DoIO(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(LONG, DoIO,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 76, Exec    );
}

#define DoIO(arg1) \
    __inline_Exec_DoIO((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_SendIO(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, SendIO,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 77, Exec    );
}

#define SendIO(arg1) \
    __inline_Exec_SendIO((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct IORequest * __inline_Exec_CheckIO(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(struct IORequest *, CheckIO,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 78, Exec    );
}

#define CheckIO(arg1) \
    __inline_Exec_CheckIO((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_WaitIO(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(LONG, WaitIO,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 79, Exec    );
}

#define WaitIO(arg1) \
    __inline_Exec_WaitIO((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_AbortIO(struct IORequest * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(LONG, AbortIO,
        AROS_LCA(struct IORequest *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 80, Exec    );
}

#define AbortIO(arg1) \
    __inline_Exec_AbortIO((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddResource(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, AddResource,
        AROS_LCA(APTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 81, Exec    );
}

#define AddResource(arg1) \
    __inline_Exec_AddResource((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemResource(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RemResource,
        AROS_LCA(APTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 82, Exec    );
}

#define RemResource(arg1) \
    __inline_Exec_RemResource((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_OpenResource(CONST_STRPTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(APTR, OpenResource,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 83, Exec    );
}

#define OpenResource(arg1) \
    __inline_Exec_OpenResource((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RawIOInit(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC0NR(void, RawIOInit,
        struct ExecBase *, (__SysBase), 84, Exec    );
}

#define RawIOInit() \
    __inline_Exec_RawIOInit(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_RawMayGetChar(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC0(LONG, RawMayGetChar,
        struct ExecBase *, (__SysBase), 85, Exec    );
}

#define RawMayGetChar() \
    __inline_Exec_RawMayGetChar(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RawPutChar(UBYTE __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC1NR(void, RawPutChar,
        AROS_LCA(UBYTE,(__arg1),D0),
        struct ExecBase *, (__SysBase), 86, Exec    );
}

#define RawPutChar(arg1) \
    __inline_Exec_RawPutChar((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline RAWARG __inline_Exec_RawDoFmt(CONST_STRPTR __arg1, RAWARG __arg2, VOID_FUNC __arg3, APTR __arg4, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC4(RAWARG, RawDoFmt,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(RAWARG,(__arg2),A1),
        AROS_LCA(VOID_FUNC,(__arg3),A2),
        AROS_LCA(APTR,(__arg4),A3),
        struct ExecBase *, (__SysBase), 87, Exec    );
}

#define RawDoFmt(arg1, arg2, arg3, arg4) \
    __inline_Exec_RawDoFmt((arg1), (arg2), (arg3), (arg4), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline UWORD __inline_Exec_GetCC(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC0(UWORD, GetCC,
        struct ExecBase *, (__SysBase), 88, Exec    );
}

#define GetCC() \
    __inline_Exec_GetCC(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_TypeOfMem(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC1(ULONG, TypeOfMem,
        AROS_LCA(APTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 89, Exec    );
}

#define TypeOfMem(arg1) \
    __inline_Exec_TypeOfMem((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_Procure(struct SignalSemaphore * __arg1, struct SemaphoreMessage * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(ULONG, Procure,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        AROS_LCA(struct SemaphoreMessage *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 90, Exec    );
}

#define Procure(arg1, arg2) \
    __inline_Exec_Procure((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_Vacate(struct SignalSemaphore * __arg1, struct SemaphoreMessage * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    AROS_LC2NR(void, Vacate,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        AROS_LCA(struct SemaphoreMessage *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 91, Exec    );
}

#define Vacate(arg1, arg2) \
    __inline_Exec_Vacate((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

static inline struct Library * __inline_Exec_OpenLibrary(CONST_STRPTR __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 0)
    return AROS_LC2(struct Library *, OpenLibrary,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        AROS_LCA(ULONG,(__arg2),D0),
        struct ExecBase *, (__SysBase), 92, Exec    );
}

#define OpenLibrary(arg1, arg2) \
    __inline_Exec_OpenLibrary((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_InitSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, InitSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 93, Exec    );
}

#define InitSemaphore(arg1) \
    __inline_Exec_InitSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ObtainSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, ObtainSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 94, Exec    );
}

#define ObtainSemaphore(arg1) \
    __inline_Exec_ObtainSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ReleaseSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, ReleaseSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 95, Exec    );
}

#define ReleaseSemaphore(arg1) \
    __inline_Exec_ReleaseSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_AttemptSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    return AROS_LC1(ULONG, AttemptSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 96, Exec    );
}

#define AttemptSemaphore(arg1) \
    __inline_Exec_AttemptSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ObtainSemaphoreList(struct List * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, ObtainSemaphoreList,
        AROS_LCA(struct List *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 97, Exec    );
}

#define ObtainSemaphoreList(arg1) \
    __inline_Exec_ObtainSemaphoreList((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ReleaseSemaphoreList(struct List * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, ReleaseSemaphoreList,
        AROS_LCA(struct List *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 98, Exec    );
}

#define ReleaseSemaphoreList(arg1) \
    __inline_Exec_ReleaseSemaphoreList((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline struct SignalSemaphore * __inline_Exec_FindSemaphore(CONST_STRPTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    return AROS_LC1(struct SignalSemaphore *, FindSemaphore,
        AROS_LCA(CONST_STRPTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 99, Exec    );
}

#define FindSemaphore(arg1) \
    __inline_Exec_FindSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, AddSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 100, Exec    );
}

#define AddSemaphore(arg1) \
    __inline_Exec_AddSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemSemaphore(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC1NR(void, RemSemaphore,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 101, Exec    );
}

#define RemSemaphore(arg1) \
    __inline_Exec_RemSemaphore((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_SumKickData(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    return AROS_LC0(ULONG, SumKickData,
        struct ExecBase *, (__SysBase), 102, Exec    );
}

#define SumKickData() \
    __inline_Exec_SumKickData(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddMemList(IPTR __arg1, ULONG __arg2, LONG __arg3, APTR __arg4, STRPTR __arg5, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC5NR(void, AddMemList,
        AROS_LCA(IPTR,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        AROS_LCA(LONG,(__arg3),D2),
        AROS_LCA(APTR,(__arg4),A0),
        AROS_LCA(STRPTR,(__arg5),A1),
        struct ExecBase *, (__SysBase), 103, Exec    );
}

#define AddMemList(arg1, arg2, arg3, arg4, arg5) \
    __inline_Exec_AddMemList((arg1), (arg2), (arg3), (arg4), (arg5), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CopyMem(CONST_APTR __arg1, APTR __arg2, IPTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC3NR(void, CopyMem,
        AROS_LCA(CONST_APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(IPTR,(__arg3),D0),
        struct ExecBase *, (__SysBase), 104, Exec    );
}

#define CopyMem(arg1, arg2, arg3) \
    __inline_Exec_CopyMem((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CopyMemQuick(CONST_APTR __arg1, APTR __arg2, IPTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 33)
    AROS_LC3NR(void, CopyMemQuick,
        AROS_LCA(CONST_APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(IPTR,(__arg3),D0),
        struct ExecBase *, (__SysBase), 105, Exec    );
}

#define CopyMemQuick(arg1, arg2, arg3) \
    __inline_Exec_CopyMemQuick((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CacheClearU(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC0NR(void, CacheClearU,
        struct ExecBase *, (__SysBase), 106, Exec    );
}

#define CacheClearU() \
    __inline_Exec_CacheClearU(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CacheClearE(APTR __arg1, IPTR __arg2, ULONG __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC3NR(void, CacheClearE,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(IPTR,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct ExecBase *, (__SysBase), 107, Exec    );
}

#define CacheClearE(arg1, arg2, arg3) \
    __inline_Exec_CacheClearE((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_CacheControl(ULONG __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC2(ULONG, CacheControl,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 108, Exec    );
}

#define CacheControl(arg1, arg2) \
    __inline_Exec_CacheControl((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_CreateIORequest(struct MsgPort * __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC2(APTR, CreateIORequest,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct ExecBase *, (__SysBase), 109, Exec    );
}

#define CreateIORequest(arg1, arg2) \
    __inline_Exec_CreateIORequest((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_DeleteIORequest(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, DeleteIORequest,
        AROS_LCA(APTR,(__arg1),A0),
        struct ExecBase *, (__SysBase), 110, Exec    );
}

#define DeleteIORequest(arg1) \
    __inline_Exec_DeleteIORequest((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline struct MsgPort * __inline_Exec_CreateMsgPort(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC0(struct MsgPort *, CreateMsgPort,
        struct ExecBase *, (__SysBase), 111, Exec    );
}

#define CreateMsgPort() \
    __inline_Exec_CreateMsgPort(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_DeleteMsgPort(struct MsgPort * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, DeleteMsgPort,
        AROS_LCA(struct MsgPort *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 112, Exec    );
}

#define DeleteMsgPort(arg1) \
    __inline_Exec_DeleteMsgPort((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ObtainSemaphoreShared(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, ObtainSemaphoreShared,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 113, Exec    );
}

#define ObtainSemaphoreShared(arg1) \
    __inline_Exec_ObtainSemaphoreShared((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AllocVec(IPTR __arg1, ULONG __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC2(APTR, AllocVec,
        AROS_LCA(IPTR,(__arg1),D0),
        AROS_LCA(ULONG,(__arg2),D1),
        struct ExecBase *, (__SysBase), 114, Exec    );
}

#define AllocVec(arg1, arg2) \
    __inline_Exec_AllocVec((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeVec(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, FreeVec,
        AROS_LCA(APTR,(__arg1),A1),
        struct ExecBase *, (__SysBase), 115, Exec    );
}

#define FreeVec(arg1) \
    __inline_Exec_FreeVec((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_CreatePool(ULONG __arg1, IPTR __arg2, IPTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC3(APTR, CreatePool,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(IPTR,(__arg2),D1),
        AROS_LCA(IPTR,(__arg3),D2),
        struct ExecBase *, (__SysBase), 116, Exec    );
}

#define CreatePool(arg1, arg2, arg3) \
    __inline_Exec_CreatePool((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_DeletePool(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, DeletePool,
        AROS_LCA(APTR,(__arg1),A0),
        struct ExecBase *, (__SysBase), 117, Exec    );
}

#define DeletePool(arg1) \
    __inline_Exec_DeletePool((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AllocPooled(APTR __arg1, IPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC2(APTR, AllocPooled,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(IPTR,(__arg2),D0),
        struct ExecBase *, (__SysBase), 118, Exec    );
}

#define AllocPooled(arg1, arg2) \
    __inline_Exec_AllocPooled((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreePooled(APTR __arg1, APTR __arg2, IPTR __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC3NR(void, FreePooled,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(IPTR,(__arg3),D0),
        struct ExecBase *, (__SysBase), 119, Exec    );
}

#define FreePooled(arg1, arg2, arg3) \
    __inline_Exec_FreePooled((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_AttemptSemaphoreShared(struct SignalSemaphore * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC1(ULONG, AttemptSemaphoreShared,
        AROS_LCA(struct SignalSemaphore *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 120, Exec    );
}

#define AttemptSemaphoreShared(arg1) \
    __inline_Exec_AttemptSemaphoreShared((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ColdReboot(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC0NR(void, ColdReboot,
        struct ExecBase *, (__SysBase), 121, Exec    );
}

#define ColdReboot() \
    __inline_Exec_ColdReboot(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_ChildFree(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC1NR(void, ChildFree,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 123, Exec    );
}

#define ChildFree(arg1) \
    __inline_Exec_ChildFree((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_ChildOrphan(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC1(ULONG, ChildOrphan,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 124, Exec    );
}

#define ChildOrphan(arg1) \
    __inline_Exec_ChildOrphan((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_ChildStatus(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC1(ULONG, ChildStatus,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 125, Exec    );
}

#define ChildStatus(arg1) \
    __inline_Exec_ChildStatus((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_ChildWait(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC1(IPTR, ChildWait,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 126, Exec    );
}

#define ChildWait(arg1) \
    __inline_Exec_ChildWait((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_CachePreDMA(APTR __arg1, ULONG * __arg2, ULONG __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    return AROS_LC3(APTR, CachePreDMA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct ExecBase *, (__SysBase), 127, Exec    );
}

#define CachePreDMA(arg1, arg2, arg3) \
    __inline_Exec_CachePreDMA((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_CachePostDMA(APTR __arg1, ULONG * __arg2, ULONG __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 36)
    AROS_LC3NR(void, CachePostDMA,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct ExecBase *, (__SysBase), 128, Exec    );
}

#define CachePostDMA(arg1, arg2, arg3) \
    __inline_Exec_CachePostDMA((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_AddMemHandler(struct Interrupt * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    AROS_LC1NR(void, AddMemHandler,
        AROS_LCA(struct Interrupt *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 129, Exec    );
}

#define AddMemHandler(arg1) \
    __inline_Exec_AddMemHandler((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemMemHandler(struct Interrupt * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    AROS_LC1NR(void, RemMemHandler,
        AROS_LCA(struct Interrupt *,(__arg1),A1),
        struct ExecBase *, (__SysBase), 130, Exec    );
}

#define RemMemHandler(arg1) \
    __inline_Exec_RemMemHandler((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_ObtainQuickVector(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    return AROS_LC1(ULONG, ObtainQuickVector,
        AROS_LCA(APTR,(__arg1),A0),
        struct ExecBase *, (__SysBase), 131, Exec    );
}

#define ObtainQuickVector(arg1) \
    __inline_Exec_ObtainQuickVector((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_NewStackSwap(struct StackSwapStruct * __arg1, APTR __arg2, struct StackSwapArgs * __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    return AROS_LC3(IPTR, NewStackSwap,
        AROS_LCA(struct StackSwapStruct *,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        AROS_LCA(struct StackSwapArgs *,(__arg3),A2),
        struct ExecBase *, (__SysBase), 134, Exec    );
}

#define NewStackSwap(arg1, arg2, arg3) \
    __inline_Exec_NewStackSwap((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_TaggedOpenLibrary(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    return AROS_LC1(APTR, TaggedOpenLibrary,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 135, Exec    );
}

#define TaggedOpenLibrary(arg1) \
    __inline_Exec_TaggedOpenLibrary((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_ReadGayle(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 39)
    return AROS_LC0(ULONG, ReadGayle,
        struct ExecBase *, (__SysBase), 136, Exec    );
}

#define ReadGayle() \
    __inline_Exec_ReadGayle(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline STRPTR __inline_Exec_VNewRawDoFmt(CONST_STRPTR __arg1, VOID_FUNC __arg2, APTR __arg3, va_list __arg4, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC4(STRPTR, VNewRawDoFmt,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(VOID_FUNC,(__arg2),A2),
        AROS_LCA(APTR,(__arg3),A3),
        AROS_LCA(va_list,(__arg4),A1),
        struct ExecBase *, (__SysBase), 137, Exec    );
}

#define VNewRawDoFmt(arg1, arg2, arg3, arg4) \
    __inline_Exec_VNewRawDoFmt((arg1), (arg2), (arg3), (arg4), __EXEC_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
static inline STRPTR __inline_Exec_NewRawDoFmt(struct ExecBase * __SysBase, CONST_STRPTR __arg1, VOID_FUNC __arg2, APTR __arg3, ...)
{
    STRPTR retval;
    va_list __args;

    va_start(__args, __arg3);
    retval = __inline_Exec_VNewRawDoFmt(__arg1, __arg2, __arg3, __args, __SysBase);
    va_end(__args);
    return retval;
}

#define NewRawDoFmt(arg1, arg2, ...) \
    __inline_Exec_NewRawDoFmt((struct ExecBase *)__EXEC_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_NewMinList(struct MinList * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    AROS_LC1NR(void, NewMinList,
        AROS_LCA(struct MinList *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 138, Exec    );
}

#define NewMinList(arg1) \
    __inline_Exec_NewMinList((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_AddNode(struct AVLNode ** __arg1, struct AVLNode * __arg2, AVLNODECOMP __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC3(struct AVLNode *, AVL_AddNode,
        AROS_LCA(struct AVLNode **,(__arg1),A0),
        AROS_LCA(struct AVLNode *,(__arg2),A1),
        AROS_LCA(AVLNODECOMP,(__arg3),A2),
        struct ExecBase *, (__SysBase), 142, Exec    );
}

#define AVL_AddNode(arg1, arg2, arg3) \
    __inline_Exec_AVL_AddNode((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_RemNodeByAddress(struct AVLNode ** __arg1, struct AVLNode * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC2(struct AVLNode *, AVL_RemNodeByAddress,
        AROS_LCA(struct AVLNode **,(__arg1),A0),
        AROS_LCA(struct AVLNode *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 143, Exec    );
}

#define AVL_RemNodeByAddress(arg1, arg2) \
    __inline_Exec_AVL_RemNodeByAddress((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_RemNodeByKey(struct AVLNode ** __arg1, AVLKey __arg2, AVLKEYCOMP __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC3(struct AVLNode *, AVL_RemNodeByKey,
        AROS_LCA(struct AVLNode **,(__arg1),A0),
        AROS_LCA(AVLKey,(__arg2),A1),
        AROS_LCA(AVLKEYCOMP,(__arg3),A2),
        struct ExecBase *, (__SysBase), 144, Exec    );
}

#define AVL_RemNodeByKey(arg1, arg2, arg3) \
    __inline_Exec_AVL_RemNodeByKey((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindNode(const struct AVLNode * __arg1, AVLKey __arg2, AVLKEYCOMP __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC3(struct AVLNode *, AVL_FindNode,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        AROS_LCA(AVLKey,(__arg2),A1),
        AROS_LCA(AVLKEYCOMP,(__arg3),A2),
        struct ExecBase *, (__SysBase), 145, Exec    );
}

#define AVL_FindNode(arg1, arg2, arg3) \
    __inline_Exec_AVL_FindNode((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindPrevNodeByAddress(const struct AVLNode * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC1(struct AVLNode *, AVL_FindPrevNodeByAddress,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 146, Exec    );
}

#define AVL_FindPrevNodeByAddress(arg1) \
    __inline_Exec_AVL_FindPrevNodeByAddress((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindPrevNodeByKey(const struct AVLNode * __arg1, AVLKey __arg2, AVLKEYCOMP __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC3(struct AVLNode *, AVL_FindPrevNodeByKey,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        AROS_LCA(AVLKey,(__arg2),A1),
        AROS_LCA(AVLKEYCOMP,(__arg3),A2),
        struct ExecBase *, (__SysBase), 147, Exec    );
}

#define AVL_FindPrevNodeByKey(arg1, arg2, arg3) \
    __inline_Exec_AVL_FindPrevNodeByKey((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindNextNodeByAddress(const struct AVLNode * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC1(struct AVLNode *, AVL_FindNextNodeByAddress,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 148, Exec    );
}

#define AVL_FindNextNodeByAddress(arg1) \
    __inline_Exec_AVL_FindNextNodeByAddress((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindNextNodeByKey(const struct AVLNode * __arg1, AVLKey __arg2, AVLKEYCOMP __arg3, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC3(struct AVLNode *, AVL_FindNextNodeByKey,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        AROS_LCA(AVLKey,(__arg2),A1),
        AROS_LCA(AVLKEYCOMP,(__arg3),A2),
        struct ExecBase *, (__SysBase), 149, Exec    );
}

#define AVL_FindNextNodeByKey(arg1, arg2, arg3) \
    __inline_Exec_AVL_FindNextNodeByKey((arg1), (arg2), (arg3), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindFirstNode(const struct AVLNode * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC1(struct AVLNode *, AVL_FindFirstNode,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 150, Exec    );
}

#define AVL_FindFirstNode(arg1) \
    __inline_Exec_AVL_FindFirstNode((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

static inline struct AVLNode * __inline_Exec_AVL_FindLastNode(const struct AVLNode * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 45)
    return AROS_LC1(struct AVLNode *, AVL_FindLastNode,
        AROS_LCA(const struct AVLNode *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 151, Exec    );
}

#define AVL_FindLastNode(arg1) \
    __inline_Exec_AVL_FindLastNode((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline struct Task * __inline_Exec_NewCreateTaskA(struct TagItem * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC1(struct Task *, NewCreateTaskA,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 153, Exec    );
}

#define NewCreateTaskA(arg1) \
    __inline_Exec_NewCreateTaskA((arg1), __EXEC_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
#define NewCreateTask(...) \
({ \
    const IPTR NewCreateTaskA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewCreateTaskA((struct TagItem *)(NewCreateTaskA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline struct Task * __inline_Exec_FindTaskByPID(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC1(struct Task *, FindTaskByPID,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 166, Exec    );
}

#define FindTaskByPID(arg1) \
    __inline_Exec_FindTaskByPID((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline BOOL __inline_Exec_AddResetCallback(struct Interrupt * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC1(BOOL, AddResetCallback,
        AROS_LCA(struct Interrupt *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 167, Exec    );
}

#define AddResetCallback(arg1) \
    __inline_Exec_AddResetCallback((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RemResetCallback(struct Interrupt * __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    AROS_LC1NR(void, RemResetCallback,
        AROS_LCA(struct Interrupt *,(__arg1),A0),
        struct ExecBase *, (__SysBase), 168, Exec    );
}

#define RemResetCallback(arg1) \
    __inline_Exec_RemResetCallback((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_AllocVecPooled(APTR __arg1, IPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC2(APTR, AllocVecPooled,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(IPTR,(__arg2),D0),
        struct ExecBase *, (__SysBase), 169, Exec    );
}

#define AllocVecPooled(arg1, arg2) \
    __inline_Exec_AllocVecPooled((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_FreeVecPooled(APTR __arg1, APTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    AROS_LC2NR(void, FreeVecPooled,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct ExecBase *, (__SysBase), 170, Exec    );
}

#define FreeVecPooled(arg1, arg2) \
    __inline_Exec_FreeVecPooled((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline ULONG __inline_Exec_ShutdownA(ULONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC1(ULONG, ShutdownA,
        AROS_LCA(ULONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 173, Exec    );
}

#define ShutdownA(arg1) \
    __inline_Exec_ShutdownA((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline struct MemList * __inline_Exec_NewAllocEntry(struct MemList * __arg1, ULONG * __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC2(struct MemList *, NewAllocEntry,
        AROS_LCA(struct MemList *,(__arg1),A0),
        AROS_LCA(ULONG *,(__arg2),A1),
        struct ExecBase *, (__SysBase), 174, Exec    );
}

#define NewAllocEntry(arg1, arg2) \
    __inline_Exec_NewAllocEntry((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_NewAddTask(struct Task * __arg1, APTR __arg2, APTR __arg3, struct TagItem * __arg4, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 50)
    return AROS_LC4(APTR, NewAddTask,
        AROS_LCA(struct Task *,(__arg1),A1),
        AROS_LCA(APTR,(__arg2),A2),
        AROS_LCA(APTR,(__arg3),A3),
        AROS_LCA(struct TagItem *,(__arg4),A4),
        struct ExecBase *, (__SysBase), 176, Exec    );
}

#define NewAddTask(arg1, arg2, arg3, arg4) \
    __inline_Exec_NewAddTask((arg1), (arg2), (arg3), (arg4), __EXEC_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
#define NewAddTaskTags(arg1, arg2, arg3, ...) \
({ \
    const IPTR NewAddTask_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewAddTask((arg1), (arg2), (arg3), (struct TagItem *)(NewAddTask_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline LONG __inline_Exec_AllocTaskStorageSlot(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    return AROS_LC0(LONG, AllocTaskStorageSlot,
        struct ExecBase *, (__SysBase), 180, Exec    );
}

#define AllocTaskStorageSlot() \
    __inline_Exec_AllocTaskStorageSlot(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline VOID __inline_Exec_FreeTaskStorageSlot(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    AROS_LC1NR(VOID, FreeTaskStorageSlot,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 181, Exec    );
}

#define FreeTaskStorageSlot(arg1) \
    __inline_Exec_FreeTaskStorageSlot((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline APTR __inline_Exec_SaveTaskStorage(APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    return AROS_LC0(APTR, SaveTaskStorage,
        struct ExecBase *, (__SysBase), 182, Exec    );
}

#define SaveTaskStorage() \
    __inline_Exec_SaveTaskStorage(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline void __inline_Exec_RestoreTaskStorage(APTR __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    AROS_LC1NR(void, RestoreTaskStorage,
        AROS_LCA(APTR,(__arg1),A0),
        struct ExecBase *, (__SysBase), 183, Exec    );
}

#define RestoreTaskStorage(arg1) \
    __inline_Exec_RestoreTaskStorage((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline BOOL __inline_Exec_SetTaskStorageSlot(LONG __arg1, IPTR __arg2, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    return AROS_LC2(BOOL, SetTaskStorageSlot,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(IPTR,(__arg2),D1),
        struct ExecBase *, (__SysBase), 184, Exec    );
}

#define SetTaskStorageSlot(arg1, arg2) \
    __inline_Exec_SetTaskStorageSlot((arg1), (arg2), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_GetTaskStorageSlot(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    return AROS_LC1(IPTR, GetTaskStorageSlot,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 185, Exec    );
}

#define GetTaskStorageSlot(arg1) \
    __inline_Exec_GetTaskStorageSlot((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

static inline IPTR __inline_Exec_GetParentTaskStorageSlot(LONG __arg1, APTR __SysBase)
{
    AROS_LIBREQ(SysBase, 51)
    return AROS_LC1(IPTR, GetParentTaskStorageSlot,
        AROS_LCA(LONG,(__arg1),D0),
        struct ExecBase *, (__SysBase), 186, Exec    );
}

#define GetParentTaskStorageSlot(arg1) \
    __inline_Exec_GetParentTaskStorageSlot((arg1), __EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#endif /* INLINE_EXEC_H*/
