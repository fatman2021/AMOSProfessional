#ifndef INLINE_TASK_H
#define INLINE_TASK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/task/task.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for task
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__TASK_LIBBASE)
#    define __TASK_LIBBASE TaskResBase
#endif


#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline struct TaskList * __inline_Task_LockTaskList(ULONG __arg1, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    return AROS_LC1(struct TaskList *, LockTaskList,
        AROS_LCA(ULONG,(__arg1),D0),
        APTR , (__TaskResBase), 1, Task    );
}

#define LockTaskList(arg1) \
    __inline_Task_LockTaskList((arg1), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline VOID __inline_Task_UnLockTaskList(struct TaskList * __arg1, ULONG __arg2, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    AROS_LC2NR(VOID, UnLockTaskList,
        AROS_LCA(struct TaskList *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        APTR , (__TaskResBase), 2, Task    );
}

#define UnLockTaskList(arg1, arg2) \
    __inline_Task_UnLockTaskList((arg1), (arg2), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline struct Task * __inline_Task_NextTaskEntry(struct TaskList * __arg1, ULONG __arg2, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    return AROS_LC2(struct Task *, NextTaskEntry,
        AROS_LCA(struct TaskList *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        APTR , (__TaskResBase), 3, Task    );
}

#define NextTaskEntry(arg1, arg2) \
    __inline_Task_NextTaskEntry((arg1), (arg2), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline VOID __inline_Task_QueryTaskTagList(struct Task * __arg1, struct TagItem * __arg2, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    AROS_LC2NR(VOID, QueryTaskTagList,
        AROS_LCA(struct Task *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        APTR , (__TaskResBase), 6, Task    );
}

#define QueryTaskTagList(arg1, arg2) \
    __inline_Task_QueryTaskTagList((arg1), (arg2), __TASK_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(TASK_NO_INLINE_STDARG)
#define QueryTaskTags(arg1, ...) \
({ \
    const IPTR QueryTaskTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    QueryTaskTagList((arg1), (struct TagItem *)(QueryTaskTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline BOOL __inline_Task_InitTaskHooks(APTR __arg1, ULONG __arg2, ULONG __arg3, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    return AROS_LC3(BOOL, InitTaskHooks,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        APTR , (__TaskResBase), 9, Task    );
}

#define InitTaskHooks(arg1, arg2, arg3) \
    __inline_Task_InitTaskHooks((arg1), (arg2), (arg3), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline BOOL __inline_Task_AddTaskHook(struct Hook * __arg1, ULONG __arg2, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    return AROS_LC2(BOOL, AddTaskHook,
        AROS_LCA(struct Hook *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        APTR , (__TaskResBase), 10, Task    );
}

#define AddTaskHook(arg1, arg2) \
    __inline_Task_AddTaskHook((arg1), (arg2), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)

static inline BOOL __inline_Task_RunTaskHooks(APTR __arg1, ULONG __arg2, APTR __TaskResBase)
{
    AROS_LIBREQ(TaskResBase, 1)
    return AROS_LC2(BOOL, RunTaskHooks,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        APTR , (__TaskResBase), 11, Task    );
}

#define RunTaskHooks(arg1, arg2) \
    __inline_Task_RunTaskHooks((arg1), (arg2), __TASK_LIBBASE)

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#endif /* INLINE_TASK_H*/
