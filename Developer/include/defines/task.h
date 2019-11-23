#ifndef DEFINES_TASK_H
#define DEFINES_TASK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/task/task.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for task
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__TASK_LIBBASE)
#    define __TASK_LIBBASE TaskResBase
#endif

__BEGIN_DECLS


#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __LockTaskList_WB(__TaskResBase, __arg1) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC1(struct TaskList *, LockTaskList, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        APTR , (__TaskResBase), 1, Task);\
})

#define LockTaskList(arg1) \
    __LockTaskList_WB(__TASK_LIBBASE, (arg1))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __UnLockTaskList_WB(__TaskResBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC2NR(VOID, UnLockTaskList, \
                  AROS_LCA(struct TaskList *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        APTR , (__TaskResBase), 2, Task);\
})

#define UnLockTaskList(arg1, arg2) \
    __UnLockTaskList_WB(__TASK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __NextTaskEntry_WB(__TaskResBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC2(struct Task *, NextTaskEntry, \
                  AROS_LCA(struct TaskList *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        APTR , (__TaskResBase), 3, Task);\
})

#define NextTaskEntry(arg1, arg2) \
    __NextTaskEntry_WB(__TASK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __QueryTaskTagList_WB(__TaskResBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC2NR(VOID, QueryTaskTagList, \
                  AROS_LCA(struct Task *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        APTR , (__TaskResBase), 6, Task);\
})

#define QueryTaskTagList(arg1, arg2) \
    __QueryTaskTagList_WB(__TASK_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(TASK_NO_INLINE_STDARG)
#define QueryTaskTags(arg1, ...) \
({ \
    const IPTR QueryTaskTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    QueryTaskTagList((arg1), (struct TagItem *)(QueryTaskTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __InitTaskHooks_WB(__TaskResBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC3(BOOL, InitTaskHooks, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        APTR , (__TaskResBase), 9, Task);\
})

#define InitTaskHooks(arg1, arg2, arg3) \
    __InitTaskHooks_WB(__TASK_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __AddTaskHook_WB(__TaskResBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC2(BOOL, AddTaskHook, \
                  AROS_LCA(struct Hook *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        APTR , (__TaskResBase), 10, Task);\
})

#define AddTaskHook(arg1, arg2) \
    __AddTaskHook_WB(__TASK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

#define __RunTaskHooks_WB(__TaskResBase, __arg1, __arg2) ({\
        AROS_LIBREQ(TaskResBase,1)\
        AROS_LC2(BOOL, RunTaskHooks, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        APTR , (__TaskResBase), 11, Task);\
})

#define RunTaskHooks(arg1, arg2) \
    __RunTaskHooks_WB(__TASK_LIBBASE, (arg1), (arg2))

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_TASK_H*/
