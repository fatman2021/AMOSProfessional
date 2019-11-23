#ifndef DEFINES_WORKBENCH_H
#define DEFINES_WORKBENCH_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/workbench/workbench.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for workbench
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__WORKBENCH_LIBBASE)
#    define __WORKBENCH_LIBBASE WorkbenchBase
#endif

__BEGIN_DECLS


#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __UpdateWorkbench_WB(__WorkbenchBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC3(BOOL, UpdateWorkbench, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(BPTR,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__WorkbenchBase), 5, Workbench);\
})

#define UpdateWorkbench(arg1, arg2, arg3) \
    __UpdateWorkbench_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __QuoteWorkbench_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC1(BOOL, QuoteWorkbench, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__WorkbenchBase), 6, Workbench);\
})

#define QuoteWorkbench(arg1) \
    __QuoteWorkbench_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __StartWorkbench_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC2(BOOL, StartWorkbench, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),D1), \
        struct Library *, (__WorkbenchBase), 7, Workbench);\
})

#define StartWorkbench(arg1, arg2) \
    __StartWorkbench_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __AddAppWindowA_WB(__WorkbenchBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC5(struct AppWindow *, AddAppWindowA, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),D1), \
                  AROS_LCA(struct Window *,(__arg3),A0), \
                  AROS_LCA(struct MsgPort *,(__arg4),A1), \
                  AROS_LCA(struct TagItem *,(__arg5),A2), \
        struct Library *, (__WorkbenchBase), 8, Workbench);\
})

#define AddAppWindowA(arg1, arg2, arg3, arg4, arg5) \
    __AddAppWindowA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define AddAppWindow(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR AddAppWindowA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddAppWindowA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(AddAppWindowA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __RemoveAppWindow_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC1(BOOL, RemoveAppWindow, \
                  AROS_LCA(struct AppWindow *,(__arg1),A0), \
        struct Library *, (__WorkbenchBase), 9, Workbench);\
})

#define RemoveAppWindow(arg1) \
    __RemoveAppWindow_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __AddAppIconA_WB(__WorkbenchBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC7(struct AppIcon *, AddAppIconA, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),D1), \
                  AROS_LCA(const char *,(__arg3),A0), \
                  AROS_LCA(struct MsgPort *,(__arg4),A1), \
                  AROS_LCA(BPTR,(__arg5),A2), \
                  AROS_LCA(struct DiskObject *,(__arg6),A3), \
                  AROS_LCA(struct TagItem *,(__arg7),A4), \
        struct Library *, (__WorkbenchBase), 10, Workbench);\
})

#define AddAppIconA(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __AddAppIconA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define AddAppIcon(arg1, arg2, arg3, arg4, arg5, arg6, ...) \
({ \
    const IPTR AddAppIconA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddAppIconA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (struct TagItem *)(AddAppIconA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __RemoveAppIcon_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC1(BOOL, RemoveAppIcon, \
                  AROS_LCA(struct AppIcon *,(__arg1),A0), \
        struct Library *, (__WorkbenchBase), 11, Workbench);\
})

#define RemoveAppIcon(arg1) \
    __RemoveAppIcon_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __AddAppMenuItemA_WB(__WorkbenchBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC5(struct AppMenuItem *, AddAppMenuItemA, \
                  AROS_LCA(IPTR,(__arg1),D0), \
                  AROS_LCA(IPTR,(__arg2),D1), \
                  AROS_LCA(APTR,(__arg3),A0), \
                  AROS_LCA(struct MsgPort *,(__arg4),A1), \
                  AROS_LCA(struct TagItem *,(__arg5),A3), \
        struct Library *, (__WorkbenchBase), 12, Workbench);\
})

#define AddAppMenuItemA(arg1, arg2, arg3, arg4, arg5) \
    __AddAppMenuItemA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define AddAppMenuItem(arg1, arg2, arg3, arg4, ...) \
({ \
    const IPTR AddAppMenuItemA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddAppMenuItemA((arg1), (arg2), (arg3), (arg4), (struct TagItem *)(AddAppMenuItemA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__)

#define __RemoveAppMenuItem_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,36)\
        AROS_LC1(BOOL, RemoveAppMenuItem, \
                  AROS_LCA(struct AppMenuItem *,(__arg1),A0), \
        struct Library *, (__WorkbenchBase), 13, Workbench);\
})

#define RemoveAppMenuItem(arg1) \
    __RemoveAppMenuItem_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (36 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (39 <= __WORKBENCH_LIBAPI__)

#define __WBConfig_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,39)\
        AROS_LC2(BOOL, WBConfig, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(ULONG,(__arg2),D1), \
        struct Library *, (__WorkbenchBase), 14, Workbench);\
})

#define WBConfig(arg1, arg2) \
    __WBConfig_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (39 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (39 <= __WORKBENCH_LIBAPI__)

#define __WBInfo_WB(__WorkbenchBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(WorkbenchBase,39)\
        AROS_LC3(BOOL, WBInfo, \
                  AROS_LCA(BPTR,(__arg1),A0), \
                  AROS_LCA(CONST_STRPTR,(__arg2),A1), \
                  AROS_LCA(struct Screen *,(__arg3),A2), \
        struct Library *, (__WorkbenchBase), 15, Workbench);\
})

#define WBInfo(arg1, arg2, arg3) \
    __WBInfo_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (39 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __OpenWorkbenchObjectA_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC2(BOOL, OpenWorkbenchObjectA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 16, Workbench);\
})

#define OpenWorkbenchObjectA(arg1, arg2) \
    __OpenWorkbenchObjectA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define OpenWorkbenchObject(arg1, ...) \
({ \
    const IPTR OpenWorkbenchObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    OpenWorkbenchObjectA((arg1), (struct TagItem *)(OpenWorkbenchObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __CloseWorkbenchObjectA_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC2(BOOL, CloseWorkbenchObjectA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 17, Workbench);\
})

#define CloseWorkbenchObjectA(arg1, arg2) \
    __CloseWorkbenchObjectA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define CloseWorkbenchObject(arg1, ...) \
({ \
    const IPTR CloseWorkbenchObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CloseWorkbenchObjectA((arg1), (struct TagItem *)(CloseWorkbenchObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __WorkbenchControlA_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC2(BOOL, WorkbenchControlA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 18, Workbench);\
})

#define WorkbenchControlA(arg1, arg2) \
    __WorkbenchControlA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define WorkbenchControl(arg1, ...) \
({ \
    const IPTR WorkbenchControlA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    WorkbenchControlA((arg1), (struct TagItem *)(WorkbenchControlA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __AddAppWindowDropZoneA_WB(__WorkbenchBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC4(struct AppWindowDropZone *, AddAppWindowDropZoneA, \
                  AROS_LCA(struct AppWindow *,(__arg1),A0), \
                  AROS_LCA(IPTR,(__arg2),D0), \
                  AROS_LCA(IPTR,(__arg3),D1), \
                  AROS_LCA(struct TagItem *,(__arg4),A1), \
        struct Library *, (__WorkbenchBase), 19, Workbench);\
})

#define AddAppWindowDropZoneA(arg1, arg2, arg3, arg4) \
    __AddAppWindowDropZoneA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define AddAppWindowDropZone(arg1, arg2, arg3, ...) \
({ \
    const IPTR AddAppWindowDropZoneA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddAppWindowDropZoneA((arg1), (arg2), (arg3), (struct TagItem *)(AddAppWindowDropZoneA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __RemoveAppWindowDropZone_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC2(BOOL, RemoveAppWindowDropZone, \
                  AROS_LCA(struct AppWindow *,(__arg1),A0), \
                  AROS_LCA(struct AppWindowDropZone *,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 20, Workbench);\
})

#define RemoveAppWindowDropZone(arg1, arg2) \
    __RemoveAppWindowDropZone_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __ChangeWorkbenchSelectionA_WB(__WorkbenchBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC3(BOOL, ChangeWorkbenchSelectionA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct Hook *,(__arg2),A1), \
                  AROS_LCA(struct TagItem *,(__arg3),A2), \
        struct Library *, (__WorkbenchBase), 21, Workbench);\
})

#define ChangeWorkbenchSelectionA(arg1, arg2, arg3) \
    __ChangeWorkbenchSelectionA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define ChangeWorkbenchSelection(arg1, arg2, ...) \
({ \
    const IPTR ChangeWorkbenchSelectionA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    ChangeWorkbenchSelectionA((arg1), (arg2), (struct TagItem *)(ChangeWorkbenchSelectionA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__)

#define __MakeWorkbenchObjectVisibleA_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,44)\
        AROS_LC2(BOOL, MakeWorkbenchObjectVisibleA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 22, Workbench);\
})

#define MakeWorkbenchObjectVisibleA(arg1, arg2) \
    __MakeWorkbenchObjectVisibleA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define MakeWorkbenchObjectVisible(arg1, ...) \
({ \
    const IPTR MakeWorkbenchObjectVisibleA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MakeWorkbenchObjectVisibleA((arg1), (struct TagItem *)(MakeWorkbenchObjectVisibleA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (44 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__)

#define __RegisterWorkbench_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,45)\
        AROS_LC1(BOOL, RegisterWorkbench, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
        struct Library *, (__WorkbenchBase), 23, Workbench);\
})

#define RegisterWorkbench(arg1) \
    __RegisterWorkbench_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__)

#define __UnregisterWorkbench_WB(__WorkbenchBase, __arg1) ({\
        AROS_LIBREQ(WorkbenchBase,45)\
        AROS_LC1(BOOL, UnregisterWorkbench, \
                  AROS_LCA(struct MsgPort *,(__arg1),A0), \
        struct Library *, (__WorkbenchBase), 24, Workbench);\
})

#define UnregisterWorkbench(arg1) \
    __UnregisterWorkbench_WB(__WORKBENCH_LIBBASE, (arg1))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__)

#define __UpdateWorkbenchObjectA_WB(__WorkbenchBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(WorkbenchBase,45)\
        AROS_LC3(BOOL, UpdateWorkbenchObjectA, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D1), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__WorkbenchBase), 25, Workbench);\
})

#define UpdateWorkbenchObjectA(arg1, arg2, arg3) \
    __UpdateWorkbenchObjectA_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(WORKBENCH_NO_INLINE_STDARG)
#define UpdateWorkbenchObject(arg1, arg2, ...) \
({ \
    const IPTR UpdateWorkbenchObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    UpdateWorkbenchObjectA((arg1), (arg2), (struct TagItem *)(UpdateWorkbenchObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__)

#define __SendAppWindowMessage_WB(__WorkbenchBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7, __arg8) ({\
        AROS_LIBREQ(WorkbenchBase,45)\
        AROS_LC8(BOOL, SendAppWindowMessage, \
                  AROS_LCA(struct Window *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(char **,(__arg3),A1), \
                  AROS_LCA(UWORD,(__arg4),D1), \
                  AROS_LCA(WORD,(__arg5),D2), \
                  AROS_LCA(WORD,(__arg6),D3), \
                  AROS_LCA(ULONG,(__arg7),D4), \
                  AROS_LCA(ULONG,(__arg8),D5), \
        struct Library *, (__WorkbenchBase), 26, Workbench);\
})

#define SendAppWindowMessage(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
    __SendAppWindowMessage_WB(__WORKBENCH_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), (arg8))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__) */

#if !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__)

#define __GetNextAppIcon_WB(__WorkbenchBase, __arg1, __arg2) ({\
        AROS_LIBREQ(WorkbenchBase,45)\
        AROS_LC2(struct DiskObject *, GetNextAppIcon, \
                  AROS_LCA(struct DiskObject *,(__arg1),A0), \
                  AROS_LCA(char*,(__arg2),A1), \
        struct Library *, (__WorkbenchBase), 27, Workbench);\
})

#define GetNextAppIcon(arg1, arg2) \
    __GetNextAppIcon_WB(__WORKBENCH_LIBBASE, (arg1), (arg2))

#endif /* !defined(__WORKBENCH_LIBAPI__) || (45 <= __WORKBENCH_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_WORKBENCH_H*/
