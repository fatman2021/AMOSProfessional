#ifndef CLIB_TASK_PROTOS_H
#define CLIB_TASK_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/task/task.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


#include <utility/tagitem.h>


__BEGIN_DECLS


#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP1(struct TaskList *, LockTaskList,
         AROS_LPA(ULONG, flags, D0),
         LIBBASETYPEPTR, TaskResBase, 1, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP2(VOID, UnLockTaskList,
         AROS_LPA(struct TaskList *, tlist, A0),
         AROS_LPA(ULONG, flags, D0),
         LIBBASETYPEPTR, TaskResBase, 2, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP2(struct Task *, NextTaskEntry,
         AROS_LPA(struct TaskList *, tlist, A0),
         AROS_LPA(ULONG, flags, D0),
         LIBBASETYPEPTR, TaskResBase, 3, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP2(VOID, QueryTaskTagList,
         AROS_LPA(struct Task *, task, A0),
         AROS_LPA(struct TagItem *, tagList, A1),
         LIBBASETYPEPTR, TaskResBase, 6, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP3(BOOL, InitTaskHooks,
         AROS_LPA(APTR, thDispatcher, A0),
         AROS_LPA(ULONG, thType, D0),
         AROS_LPA(ULONG, thFlags, D1),
         LIBBASETYPEPTR, TaskResBase, 9, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP2(BOOL, AddTaskHook,
         AROS_LPA(struct Hook *, tHook, A0),
         AROS_LPA(ULONG, thType, D0),
         LIBBASETYPEPTR, TaskResBase, 10, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

#if !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__)
AROS_LP2(BOOL, RunTaskHooks,
         AROS_LPA(APTR, thDispatcher, A0),
         AROS_LPA(ULONG, thType, D0),
         LIBBASETYPEPTR, TaskResBase, 11, Task
);

#endif /* !defined(__TASK_LIBAPI__) || (1 <= __TASK_LIBAPI__) */

__END_DECLS

#endif /* CLIB_TASK_PROTOS_H */
