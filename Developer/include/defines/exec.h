#ifndef DEFINES_EXEC_H
#define DEFINES_EXEC_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/exec/exec.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for exec
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EXEC_LIBBASE)
#    define __EXEC_LIBBASE SysBase
#endif

__BEGIN_DECLS


#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Supervisor_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(IPTR, Supervisor, \
                  AROS_LCA(void *,(__arg1),A5), \
        struct ExecBase *, (__SysBase), 5, Exec);\
})

#define Supervisor(arg1) \
    __Supervisor_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Reschedule_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Reschedule, \
        struct ExecBase *, (__SysBase), 8, Exec);\
})

#define Reschedule() \
    __Reschedule_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Exception_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Exception, \
        struct ExecBase *, (__SysBase), 11, Exec);\
})

#define Exception() \
    __Exception_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __InitCode_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, InitCode, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 12, Exec);\
})

#define InitCode(arg1, arg2) \
    __InitCode_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __InitStruct_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3NR(void, InitStruct, \
                  AROS_LCA(CONST_APTR,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 13, Exec);\
})

#define InitStruct(arg1, arg2, arg3) \
    __InitStruct_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __MakeLibrary_WB(__SysBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC5(struct Library *, MakeLibrary, \
                  AROS_LCA(CONST_APTR,(__arg1),A0), \
                  AROS_LCA(CONST_APTR,(__arg2),A1), \
                  AROS_LCA(ULONG_FUNC,(__arg3),A2), \
                  AROS_LCA(ULONG,(__arg4),D0), \
                  AROS_LCA(BPTR,(__arg5),D1), \
        struct ExecBase *, (__SysBase), 14, Exec);\
})

#define MakeLibrary(arg1, arg2, arg3, arg4, arg5) \
    __MakeLibrary_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __MakeFunctions_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3(ULONG, MakeFunctions, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(CONST_APTR,(__arg2),A1), \
                  AROS_LCA(CONST_APTR,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 15, Exec);\
})

#define MakeFunctions(arg1, arg2, arg3) \
    __MakeFunctions_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FindResident_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Resident *, FindResident, \
                  AROS_LCA(const UBYTE *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 16, Exec);\
})

#define FindResident(arg1) \
    __FindResident_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __InitResident_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(APTR, InitResident, \
                  AROS_LCA(struct Resident *,(__arg1),A1), \
                  AROS_LCA(BPTR,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 17, Exec);\
})

#define InitResident(arg1, arg2) \
    __InitResident_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Alert_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, Alert, \
                  AROS_LCA(ULONG,(__arg1),D7), \
        struct ExecBase *, (__SysBase), 18, Exec);\
})

#define Alert(arg1) \
    __Alert_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Debug_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, Debug, \
                  AROS_LCA(unsigned long,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 19, Exec);\
})

#define Debug(arg1) \
    __Debug_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Disable_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Disable, \
        struct ExecBase *, (__SysBase), 20, Exec);\
})

#define Disable() \
    __Disable_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Enable_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Enable, \
        struct ExecBase *, (__SysBase), 21, Exec);\
})

#define Enable() \
    __Enable_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Forbid_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Forbid, \
        struct ExecBase *, (__SysBase), 22, Exec);\
})

#define Forbid() \
    __Forbid_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Permit_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, Permit, \
        struct ExecBase *, (__SysBase), 23, Exec);\
})

#define Permit() \
    __Permit_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetSR_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(ULONG, SetSR, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 24, Exec);\
})

#define SetSR(arg1, arg2) \
    __SetSR_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SuperState_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0(APTR, SuperState, \
        struct ExecBase *, (__SysBase), 25, Exec);\
})

#define SuperState() \
    __SuperState_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __UserState_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, UserState, \
                  AROS_LCA(APTR,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 26, Exec);\
})

#define UserState(arg1) \
    __UserState_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetIntVector_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(struct Interrupt *, SetIntVector, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct Interrupt *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 27, Exec);\
})

#define SetIntVector(arg1, arg2) \
    __SetIntVector_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddIntServer_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, AddIntServer, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct Interrupt *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 28, Exec);\
})

#define AddIntServer(arg1, arg2) \
    __AddIntServer_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemIntServer_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, RemIntServer, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(struct Interrupt *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 29, Exec);\
})

#define RemIntServer(arg1, arg2) \
    __RemIntServer_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Cause_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, Cause, \
                  AROS_LCA(struct Interrupt *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 30, Exec);\
})

#define Cause(arg1) \
    __Cause_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Allocate_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(APTR, Allocate, \
                  AROS_LCA(struct MemHeader *,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 31, Exec);\
})

#define Allocate(arg1, arg2) \
    __Allocate_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Deallocate_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3NR(void, Deallocate, \
                  AROS_LCA(struct MemHeader *,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(IPTR,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 32, Exec);\
})

#define Deallocate(arg1, arg2, arg3) \
    __Deallocate_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AllocMem_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(APTR, AllocMem, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 33, Exec);\
})

#define AllocMem(arg1, arg2) \
    __AllocMem_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AllocAbs_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(APTR, AllocAbs, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 34, Exec);\
})

#define AllocAbs(arg1, arg2) \
    __AllocAbs_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FreeMem_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, FreeMem, \
                  AROS_LCA(APTR,(__arg1),A1), \
                  AROS_LCA(IPTR,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 35, Exec);\
})

#define FreeMem(arg1, arg2) \
    __FreeMem_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AvailMem_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(IPTR, AvailMem, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct ExecBase *, (__SysBase), 36, Exec);\
})

#define AvailMem(arg1) \
    __AvailMem_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AllocEntry_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct MemList *, AllocEntry, \
                  AROS_LCA(struct MemList *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 37, Exec);\
})

#define AllocEntry(arg1) \
    __AllocEntry_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FreeEntry_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, FreeEntry, \
                  AROS_LCA(struct MemList *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 38, Exec);\
})

#define FreeEntry(arg1) \
    __FreeEntry_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Insert_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3NR(void, Insert, \
                  AROS_LCA(struct List *,(__arg1),A0), \
                  AROS_LCA(struct Node *,(__arg2),A1), \
                  AROS_LCA(struct Node *,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 39, Exec);\
})

#define Insert(arg1, arg2, arg3) \
    __Insert_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddHead_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, AddHead, \
                  AROS_LCA(struct List *,(__arg1),A0), \
                  AROS_LCA(struct Node *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 40, Exec);\
})

#define AddHead(arg1, arg2) \
    __AddHead_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddTail_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, AddTail, \
                  AROS_LCA(struct List *,(__arg1),A0), \
                  AROS_LCA(struct Node *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 41, Exec);\
})

#define AddTail(arg1, arg2) \
    __AddTail_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Remove_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, Remove, \
                  AROS_LCA(struct Node *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 42, Exec);\
})

#define Remove(arg1) \
    __Remove_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemHead_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Node *, RemHead, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 43, Exec);\
})

#define RemHead(arg1) \
    __RemHead_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemTail_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Node *, RemTail, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 44, Exec);\
})

#define RemTail(arg1) \
    __RemTail_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Enqueue_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, Enqueue, \
                  AROS_LCA(struct List *,(__arg1),A0), \
                  AROS_LCA(struct Node *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 45, Exec);\
})

#define Enqueue(arg1, arg2) \
    __Enqueue_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FindName_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(struct Node *, FindName, \
                  AROS_LCA(struct List *,(__arg1),A0), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 46, Exec);\
})

#define FindName(arg1, arg2) \
    __FindName_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddTask_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3(APTR, AddTask, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(APTR,(__arg3),A3), \
        struct ExecBase *, (__SysBase), 47, Exec);\
})

#define AddTask(arg1, arg2, arg3) \
    __AddTask_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemTask_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RemTask, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 48, Exec);\
})

#define RemTask(arg1) \
    __RemTask_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FindTask_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Task *, FindTask, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 49, Exec);\
})

#define FindTask(arg1) \
    __FindTask_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetTaskPri_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(BYTE, SetTaskPri, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
                  AROS_LCA(LONG,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 50, Exec);\
})

#define SetTaskPri(arg1, arg2) \
    __SetTaskPri_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetSignal_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(ULONG, SetSignal, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 51, Exec);\
})

#define SetSignal(arg1, arg2) \
    __SetSignal_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetExcept_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(ULONG, SetExcept, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 52, Exec);\
})

#define SetExcept(arg1, arg2) \
    __SetExcept_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Wait_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(ULONG, Wait, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 53, Exec);\
})

#define Wait(arg1) \
    __Wait_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Signal_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, Signal, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 54, Exec);\
})

#define Signal(arg1, arg2) \
    __Signal_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AllocSignal_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(BYTE, AllocSignal, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 55, Exec);\
})

#define AllocSignal(arg1) \
    __AllocSignal_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FreeSignal_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, FreeSignal, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 56, Exec);\
})

#define FreeSignal(arg1) \
    __FreeSignal_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AllocTrap_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(LONG, AllocTrap, \
                  AROS_LCA(long,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 57, Exec);\
})

#define AllocTrap(arg1) \
    __AllocTrap_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FreeTrap_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, FreeTrap, \
                  AROS_LCA(long,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 58, Exec);\
})

#define FreeTrap(arg1) \
    __FreeTrap_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddPort_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, AddPort, \
                  AROS_LCA(struct MsgPort *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 59, Exec);\
})

#define AddPort(arg1) \
    __AddPort_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemPort_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RemPort, \
                  AROS_LCA(struct MsgPort *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 60, Exec);\
})

#define RemPort(arg1) \
    __RemPort_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __PutMsg_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, PutMsg, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
                  AROS_LCA(struct Message *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 61, Exec);\
})

#define PutMsg(arg1, arg2) \
    __PutMsg_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __GetMsg_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Message *, GetMsg, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 62, Exec);\
})

#define GetMsg(arg1) \
    __GetMsg_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __ReplyMsg_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, ReplyMsg, \
                  AROS_LCA(struct Message *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 63, Exec);\
})

#define ReplyMsg(arg1) \
    __ReplyMsg_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __WaitPort_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Message *, WaitPort, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 64, Exec);\
})

#define WaitPort(arg1) \
    __WaitPort_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __FindPort_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct MsgPort *, FindPort, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 65, Exec);\
})

#define FindPort(arg1) \
    __FindPort_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, AddLibrary, \
                  AROS_LCA(struct Library *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 66, Exec);\
})

#define AddLibrary(arg1) \
    __AddLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RemLibrary, \
                  AROS_LCA(struct Library *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 67, Exec);\
})

#define RemLibrary(arg1) \
    __RemLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __OldOpenLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct Library *, OldOpenLibrary, \
                  AROS_LCA(UBYTE *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 68, Exec);\
})

#define OldOpenLibrary(arg1) \
    __OldOpenLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __CloseLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, CloseLibrary, \
                  AROS_LCA(struct Library *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 69, Exec);\
})

#define CloseLibrary(arg1) \
    __CloseLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SetFunction_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC3(APTR, SetFunction, \
                  AROS_LCA(struct Library *,(__arg1),A1), \
                  AROS_LCA(LONG,(__arg2),A0), \
                  AROS_LCA(APTR,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 70, Exec);\
})

#define SetFunction(arg1, arg2, arg3) \
    __SetFunction_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SumLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, SumLibrary, \
                  AROS_LCA(struct Library *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 71, Exec);\
})

#define SumLibrary(arg1) \
    __SumLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddDevice_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, AddDevice, \
                  AROS_LCA(struct Device *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 72, Exec);\
})

#define AddDevice(arg1) \
    __AddDevice_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemDevice_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RemDevice, \
                  AROS_LCA(struct Device *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 73, Exec);\
})

#define RemDevice(arg1) \
    __RemDevice_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __OpenDevice_WB(__SysBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC4(LONG, OpenDevice, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
                  AROS_LCA(struct IORequest *,(__arg3),A1), \
                  AROS_LCA(ULONG,(__arg4),D1), \
        struct ExecBase *, (__SysBase), 74, Exec);\
})

#define OpenDevice(arg1, arg2, arg3, arg4) \
    __OpenDevice_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __CloseDevice_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, CloseDevice, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 75, Exec);\
})

#define CloseDevice(arg1) \
    __CloseDevice_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __DoIO_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(LONG, DoIO, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 76, Exec);\
})

#define DoIO(arg1) \
    __DoIO_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __SendIO_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, SendIO, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 77, Exec);\
})

#define SendIO(arg1) \
    __SendIO_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __CheckIO_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(struct IORequest *, CheckIO, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 78, Exec);\
})

#define CheckIO(arg1) \
    __CheckIO_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __WaitIO_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(LONG, WaitIO, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 79, Exec);\
})

#define WaitIO(arg1) \
    __WaitIO_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AbortIO_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(LONG, AbortIO, \
                  AROS_LCA(struct IORequest *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 80, Exec);\
})

#define AbortIO(arg1) \
    __AbortIO_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __AddResource_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, AddResource, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 81, Exec);\
})

#define AddResource(arg1) \
    __AddResource_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RemResource_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RemResource, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 82, Exec);\
})

#define RemResource(arg1) \
    __RemResource_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __OpenResource_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(APTR, OpenResource, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 83, Exec);\
})

#define OpenResource(arg1) \
    __OpenResource_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RawIOInit_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0NR(void, RawIOInit, \
        struct ExecBase *, (__SysBase), 84, Exec);\
})

#define RawIOInit() \
    __RawIOInit_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RawMayGetChar_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0(LONG, RawMayGetChar, \
        struct ExecBase *, (__SysBase), 85, Exec);\
})

#define RawMayGetChar() \
    __RawMayGetChar_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RawPutChar_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1NR(void, RawPutChar, \
                  AROS_LCA(UBYTE,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 86, Exec);\
})

#define RawPutChar(arg1) \
    __RawPutChar_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __RawDoFmt_WB(__SysBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC4(RAWARG, RawDoFmt, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(RAWARG,(__arg2),A1), \
                  AROS_LCA(VOID_FUNC,(__arg3),A2), \
                  AROS_LCA(APTR,(__arg4),A3), \
        struct ExecBase *, (__SysBase), 87, Exec);\
})

#define RawDoFmt(arg1, arg2, arg3, arg4) \
    __RawDoFmt_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __GetCC_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC0(UWORD, GetCC, \
        struct ExecBase *, (__SysBase), 88, Exec);\
})

#define GetCC() \
    __GetCC_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __TypeOfMem_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC1(ULONG, TypeOfMem, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 89, Exec);\
})

#define TypeOfMem(arg1) \
    __TypeOfMem_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Procure_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(ULONG, Procure, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
                  AROS_LCA(struct SemaphoreMessage *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 90, Exec);\
})

#define Procure(arg1, arg2) \
    __Procure_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __Vacate_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2NR(void, Vacate, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
                  AROS_LCA(struct SemaphoreMessage *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 91, Exec);\
})

#define Vacate(arg1, arg2) \
    __Vacate_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__)

#define __OpenLibrary_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,0)\
        AROS_LC2(struct Library *, OpenLibrary, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 92, Exec);\
})

#define OpenLibrary(arg1, arg2) \
    __OpenLibrary_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (0 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __InitSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, InitSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 93, Exec);\
})

#define InitSemaphore(arg1) \
    __InitSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __ObtainSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, ObtainSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 94, Exec);\
})

#define ObtainSemaphore(arg1) \
    __ObtainSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __ReleaseSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, ReleaseSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 95, Exec);\
})

#define ReleaseSemaphore(arg1) \
    __ReleaseSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __AttemptSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1(ULONG, AttemptSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 96, Exec);\
})

#define AttemptSemaphore(arg1) \
    __AttemptSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __ObtainSemaphoreList_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, ObtainSemaphoreList, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 97, Exec);\
})

#define ObtainSemaphoreList(arg1) \
    __ObtainSemaphoreList_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __ReleaseSemaphoreList_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, ReleaseSemaphoreList, \
                  AROS_LCA(struct List *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 98, Exec);\
})

#define ReleaseSemaphoreList(arg1) \
    __ReleaseSemaphoreList_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __FindSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1(struct SignalSemaphore *, FindSemaphore, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 99, Exec);\
})

#define FindSemaphore(arg1) \
    __FindSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __AddSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, AddSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 100, Exec);\
})

#define AddSemaphore(arg1) \
    __AddSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __RemSemaphore_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC1NR(void, RemSemaphore, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 101, Exec);\
})

#define RemSemaphore(arg1) \
    __RemSemaphore_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __SumKickData_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC0(ULONG, SumKickData, \
        struct ExecBase *, (__SysBase), 102, Exec);\
})

#define SumKickData() \
    __SumKickData_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __AddMemList_WB(__SysBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC5NR(void, AddMemList, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
                  AROS_LCA(LONG,(__arg3),D2), \
                  AROS_LCA(APTR,(__arg4),A0), \
                  AROS_LCA(STRPTR,(__arg5),A1), \
        struct ExecBase *, (__SysBase), 103, Exec);\
})

#define AddMemList(arg1, arg2, arg3, arg4, arg5) \
    __AddMemList_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __CopyMem_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC3NR(void, CopyMem, \
                  AROS_LCA(CONST_APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(IPTR,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 104, Exec);\
})

#define CopyMem(arg1, arg2, arg3) \
    __CopyMem_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__)

#define __CopyMemQuick_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,33)\
        AROS_LC3NR(void, CopyMemQuick, \
                  AROS_LCA(CONST_APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(IPTR,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 105, Exec);\
})

#define CopyMemQuick(arg1, arg2, arg3) \
    __CopyMemQuick_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (33 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CacheClearU_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC0NR(void, CacheClearU, \
        struct ExecBase *, (__SysBase), 106, Exec);\
})

#define CacheClearU() \
    __CacheClearU_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CacheClearE_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC3NR(void, CacheClearE, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct ExecBase *, (__SysBase), 107, Exec);\
})

#define CacheClearE(arg1, arg2, arg3) \
    __CacheClearE_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CacheControl_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC2(ULONG, CacheControl, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 108, Exec);\
})

#define CacheControl(arg1, arg2) \
    __CacheControl_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CreateIORequest_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC2(APTR, CreateIORequest, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 109, Exec);\
})

#define CreateIORequest(arg1, arg2) \
    __CreateIORequest_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __DeleteIORequest_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, DeleteIORequest, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 110, Exec);\
})

#define DeleteIORequest(arg1) \
    __DeleteIORequest_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CreateMsgPort_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC0(struct MsgPort *, CreateMsgPort, \
        struct ExecBase *, (__SysBase), 111, Exec);\
})

#define CreateMsgPort() \
    __CreateMsgPort_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __DeleteMsgPort_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, DeleteMsgPort, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 112, Exec);\
})

#define DeleteMsgPort(arg1) \
    __DeleteMsgPort_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ObtainSemaphoreShared_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, ObtainSemaphoreShared, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 113, Exec);\
})

#define ObtainSemaphoreShared(arg1) \
    __ObtainSemaphoreShared_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __AllocVec_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC2(APTR, AllocVec, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 114, Exec);\
})

#define AllocVec(arg1, arg2) \
    __AllocVec_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __FreeVec_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, FreeVec, \
                  AROS_LCA(APTR,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 115, Exec);\
})

#define FreeVec(arg1) \
    __FreeVec_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CreatePool_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC3(APTR, CreatePool, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),D1), \
                  AROS_LCA(IPTR,(__arg3),D2), \
        struct ExecBase *, (__SysBase), 116, Exec);\
})

#define CreatePool(arg1, arg2, arg3) \
    __CreatePool_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __DeletePool_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, DeletePool, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 117, Exec);\
})

#define DeletePool(arg1) \
    __DeletePool_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __AllocPooled_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC2(APTR, AllocPooled, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 118, Exec);\
})

#define AllocPooled(arg1, arg2) \
    __AllocPooled_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __FreePooled_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC3NR(void, FreePooled, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(IPTR,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 119, Exec);\
})

#define FreePooled(arg1, arg2, arg3) \
    __FreePooled_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __AttemptSemaphoreShared_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1(ULONG, AttemptSemaphoreShared, \
                  AROS_LCA(struct SignalSemaphore *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 120, Exec);\
})

#define AttemptSemaphoreShared(arg1) \
    __AttemptSemaphoreShared_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ColdReboot_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC0NR(void, ColdReboot, \
        struct ExecBase *, (__SysBase), 121, Exec);\
})

#define ColdReboot() \
    __ColdReboot_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ChildFree_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1NR(void, ChildFree, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 123, Exec);\
})

#define ChildFree(arg1) \
    __ChildFree_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ChildOrphan_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1(ULONG, ChildOrphan, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 124, Exec);\
})

#define ChildOrphan(arg1) \
    __ChildOrphan_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ChildStatus_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1(ULONG, ChildStatus, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 125, Exec);\
})

#define ChildStatus(arg1) \
    __ChildStatus_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __ChildWait_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC1(IPTR, ChildWait, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 126, Exec);\
})

#define ChildWait(arg1) \
    __ChildWait_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CachePreDMA_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC3(APTR, CachePreDMA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 127, Exec);\
})

#define CachePreDMA(arg1, arg2, arg3) \
    __CachePreDMA_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__)

#define __CachePostDMA_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,36)\
        AROS_LC3NR(void, CachePostDMA, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct ExecBase *, (__SysBase), 128, Exec);\
})

#define CachePostDMA(arg1, arg2, arg3) \
    __CachePostDMA_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (36 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __AddMemHandler_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC1NR(void, AddMemHandler, \
                  AROS_LCA(struct Interrupt *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 129, Exec);\
})

#define AddMemHandler(arg1) \
    __AddMemHandler_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __RemMemHandler_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC1NR(void, RemMemHandler, \
                  AROS_LCA(struct Interrupt *,(__arg1),A1), \
        struct ExecBase *, (__SysBase), 130, Exec);\
})

#define RemMemHandler(arg1) \
    __RemMemHandler_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __ObtainQuickVector_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC1(ULONG, ObtainQuickVector, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 131, Exec);\
})

#define ObtainQuickVector(arg1) \
    __ObtainQuickVector_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __NewStackSwap_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC3(IPTR, NewStackSwap, \
                  AROS_LCA(struct StackSwapStruct *,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
                  AROS_LCA(struct StackSwapArgs *,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 134, Exec);\
})

#define NewStackSwap(arg1, arg2, arg3) \
    __NewStackSwap_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __TaggedOpenLibrary_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC1(APTR, TaggedOpenLibrary, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 135, Exec);\
})

#define TaggedOpenLibrary(arg1) \
    __TaggedOpenLibrary_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__)

#define __ReadGayle_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,39)\
        AROS_LC0(ULONG, ReadGayle, \
        struct ExecBase *, (__SysBase), 136, Exec);\
})

#define ReadGayle() \
    __ReadGayle_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (39 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __VNewRawDoFmt_WB(__SysBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC4(STRPTR, VNewRawDoFmt, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(VOID_FUNC,(__arg2),A2), \
                  AROS_LCA(APTR,(__arg3),A3), \
                  AROS_LCA(va_list,(__arg4),A1), \
        struct ExecBase *, (__SysBase), 137, Exec);\
})

#define VNewRawDoFmt(arg1, arg2, arg3, arg4) \
    __VNewRawDoFmt_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
static inline STRPTR __NewRawDoFmt_WB(struct ExecBase * __SysBase, CONST_STRPTR FormatString, VOID_FUNC PutChProc, APTR PutChData, ...)
{
    STRPTR retval;
    va_list args;

    va_start(args, PutChData);
    retval = __VNewRawDoFmt_WB(__SysBase, FormatString, PutChProc, PutChData, args);
    va_end(args);
    return retval;
}
#define NewRawDoFmt(arg1, arg2, ...) __NewRawDoFmt_WB((struct ExecBase *)__EXEC_LIBBASE, (arg1), (arg2), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __NewMinList_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC1NR(void, NewMinList, \
                  AROS_LCA(struct MinList *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 138, Exec);\
})

#define NewMinList(arg1) \
    __NewMinList_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_AddNode_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC3(struct AVLNode *, AVL_AddNode, \
                  AROS_LCA(struct AVLNode **,(__arg1),A0), \
                  AROS_LCA(struct AVLNode *,(__arg2),A1), \
                  AROS_LCA(AVLNODECOMP,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 142, Exec);\
})

#define AVL_AddNode(arg1, arg2, arg3) \
    __AVL_AddNode_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_RemNodeByAddress_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC2(struct AVLNode *, AVL_RemNodeByAddress, \
                  AROS_LCA(struct AVLNode **,(__arg1),A0), \
                  AROS_LCA(struct AVLNode *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 143, Exec);\
})

#define AVL_RemNodeByAddress(arg1, arg2) \
    __AVL_RemNodeByAddress_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_RemNodeByKey_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC3(struct AVLNode *, AVL_RemNodeByKey, \
                  AROS_LCA(struct AVLNode **,(__arg1),A0), \
                  AROS_LCA(AVLKey,(__arg2),A1), \
                  AROS_LCA(AVLKEYCOMP,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 144, Exec);\
})

#define AVL_RemNodeByKey(arg1, arg2, arg3) \
    __AVL_RemNodeByKey_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindNode_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC3(struct AVLNode *, AVL_FindNode, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
                  AROS_LCA(AVLKey,(__arg2),A1), \
                  AROS_LCA(AVLKEYCOMP,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 145, Exec);\
})

#define AVL_FindNode(arg1, arg2, arg3) \
    __AVL_FindNode_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindPrevNodeByAddress_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC1(struct AVLNode *, AVL_FindPrevNodeByAddress, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 146, Exec);\
})

#define AVL_FindPrevNodeByAddress(arg1) \
    __AVL_FindPrevNodeByAddress_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindPrevNodeByKey_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC3(struct AVLNode *, AVL_FindPrevNodeByKey, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
                  AROS_LCA(AVLKey,(__arg2),A1), \
                  AROS_LCA(AVLKEYCOMP,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 147, Exec);\
})

#define AVL_FindPrevNodeByKey(arg1, arg2, arg3) \
    __AVL_FindPrevNodeByKey_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindNextNodeByAddress_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC1(struct AVLNode *, AVL_FindNextNodeByAddress, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 148, Exec);\
})

#define AVL_FindNextNodeByAddress(arg1) \
    __AVL_FindNextNodeByAddress_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindNextNodeByKey_WB(__SysBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC3(struct AVLNode *, AVL_FindNextNodeByKey, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
                  AROS_LCA(AVLKey,(__arg2),A1), \
                  AROS_LCA(AVLKEYCOMP,(__arg3),A2), \
        struct ExecBase *, (__SysBase), 149, Exec);\
})

#define AVL_FindNextNodeByKey(arg1, arg2, arg3) \
    __AVL_FindNextNodeByKey_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindFirstNode_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC1(struct AVLNode *, AVL_FindFirstNode, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 150, Exec);\
})

#define AVL_FindFirstNode(arg1) \
    __AVL_FindFirstNode_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__)

#define __AVL_FindLastNode_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,45)\
        AROS_LC1(struct AVLNode *, AVL_FindLastNode, \
                  AROS_LCA(const struct AVLNode *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 151, Exec);\
})

#define AVL_FindLastNode(arg1) \
    __AVL_FindLastNode_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (45 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __NewCreateTaskA_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC1(struct Task *, NewCreateTaskA, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 153, Exec);\
})

#define NewCreateTaskA(arg1) \
    __NewCreateTaskA_WB(__EXEC_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
#define NewCreateTask(...) \
({ \
    const IPTR NewCreateTaskA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewCreateTaskA((struct TagItem *)(NewCreateTaskA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __FindTaskByPID_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC1(struct Task *, FindTaskByPID, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 166, Exec);\
})

#define FindTaskByPID(arg1) \
    __FindTaskByPID_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __AddResetCallback_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC1(BOOL, AddResetCallback, \
                  AROS_LCA(struct Interrupt *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 167, Exec);\
})

#define AddResetCallback(arg1) \
    __AddResetCallback_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __RemResetCallback_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC1NR(void, RemResetCallback, \
                  AROS_LCA(struct Interrupt *,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 168, Exec);\
})

#define RemResetCallback(arg1) \
    __RemResetCallback_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __AllocVecPooled_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC2(APTR, AllocVecPooled, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
        struct ExecBase *, (__SysBase), 169, Exec);\
})

#define AllocVecPooled(arg1, arg2) \
    __AllocVecPooled_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __FreeVecPooled_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC2NR(void, FreeVecPooled, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(APTR,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 170, Exec);\
})

#define FreeVecPooled(arg1, arg2) \
    __FreeVecPooled_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __ShutdownA_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC1(ULONG, ShutdownA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 173, Exec);\
})

#define ShutdownA(arg1) \
    __ShutdownA_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __NewAllocEntry_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC2(struct MemList *, NewAllocEntry, \
                  AROS_LCA(struct MemList *,(__arg1),A0), \
                  AROS_LCA(ULONG *,(__arg2),A1), \
        struct ExecBase *, (__SysBase), 174, Exec);\
})

#define NewAllocEntry(arg1, arg2) \
    __NewAllocEntry_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__)

#define __NewAddTask_WB(__SysBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(SysBase,50)\
        AROS_LC4(APTR, NewAddTask, \
                  AROS_LCA(struct Task *,(__arg1),A1), \
                  AROS_LCA(APTR,(__arg2),A2), \
                  AROS_LCA(APTR,(__arg3),A3), \
                  AROS_LCA(struct TagItem *,(__arg4),A4), \
        struct ExecBase *, (__SysBase), 176, Exec);\
})

#define NewAddTask(arg1, arg2, arg3, arg4) \
    __NewAddTask_WB(__EXEC_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(EXEC_NO_INLINE_STDARG)
#define NewAddTaskTags(arg1, arg2, arg3, ...) \
({ \
    const IPTR NewAddTask_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewAddTask((arg1), (arg2), (arg3), (struct TagItem *)(NewAddTask_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__EXEC_LIBAPI__) || (50 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __AllocTaskStorageSlot_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC0(LONG, AllocTaskStorageSlot, \
        struct ExecBase *, (__SysBase), 180, Exec);\
})

#define AllocTaskStorageSlot() \
    __AllocTaskStorageSlot_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __FreeTaskStorageSlot_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC1NR(VOID, FreeTaskStorageSlot, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 181, Exec);\
})

#define FreeTaskStorageSlot(arg1) \
    __FreeTaskStorageSlot_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __SaveTaskStorage_WB(__SysBase) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC0(APTR, SaveTaskStorage, \
        struct ExecBase *, (__SysBase), 182, Exec);\
})

#define SaveTaskStorage() \
    __SaveTaskStorage_WB(__EXEC_LIBBASE)

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __RestoreTaskStorage_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC1NR(void, RestoreTaskStorage, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct ExecBase *, (__SysBase), 183, Exec);\
})

#define RestoreTaskStorage(arg1) \
    __RestoreTaskStorage_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __SetTaskStorageSlot_WB(__SysBase, __arg1, __arg2) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC2(BOOL, SetTaskStorageSlot, \
                  AROS_LCA(LONG,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),D1), \
        struct ExecBase *, (__SysBase), 184, Exec);\
})

#define SetTaskStorageSlot(arg1, arg2) \
    __SetTaskStorageSlot_WB(__EXEC_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __GetTaskStorageSlot_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC1(IPTR, GetTaskStorageSlot, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 185, Exec);\
})

#define GetTaskStorageSlot(arg1) \
    __GetTaskStorageSlot_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

#if !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__)

#define __GetParentTaskStorageSlot_WB(__SysBase, __arg1) ({\
        AROS_LIBREQ(SysBase,51)\
        AROS_LC1(IPTR, GetParentTaskStorageSlot, \
                  AROS_LCA(LONG,(__arg1),D0), \
        struct ExecBase *, (__SysBase), 186, Exec);\
})

#define GetParentTaskStorageSlot(arg1) \
    __GetParentTaskStorageSlot_WB(__EXEC_LIBBASE, (arg1))

#endif /* !defined(__EXEC_LIBAPI__) || (51 <= __EXEC_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_EXEC_H*/
