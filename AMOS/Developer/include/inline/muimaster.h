#ifndef INLINE_MUIMASTER_H
#define INLINE_MUIMASTER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/muimaster/muimaster.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for muimaster
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MUIMASTER_LIBBASE)
#    define __MUIMASTER_LIBBASE MUIMasterBase
#endif


#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline Object* __inline_MUIMaster_MUI_NewObjectA(ClassID __arg1, struct TagItem* __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(Object*, MUI_NewObjectA,
        AROS_LCA(ClassID,(__arg1),A0),
        AROS_LCA(struct TagItem*,(__arg2),A1),
        struct Library *, (__MUIMasterBase), 5, MUIMaster    );
}

#define MUI_NewObjectA(arg1, arg2) \
    __inline_MUIMaster_MUI_NewObjectA((arg1), (arg2), __MUIMASTER_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(MUIMASTER_NO_INLINE_STDARG)
#define MUI_NewObject(arg1, ...) \
({ \
    const IPTR MUI_NewObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MUI_NewObjectA((arg1), (struct TagItem*)(MUI_NewObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_DisposeObject(Object* __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC1NR(void, MUI_DisposeObject,
        AROS_LCA(Object*,(__arg1),A0),
        struct Library *, (__MUIMasterBase), 6, MUIMaster    );
}

#define MUI_DisposeObject(arg1) \
    __inline_MUIMaster_MUI_DisposeObject((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline LONG __inline_MUIMaster_MUI_RequestA(APTR __arg1, APTR __arg2, LONGBITS __arg3, CONST_STRPTR __arg4, CONST_STRPTR __arg5, CONST_STRPTR __arg6, APTR __arg7, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC7(LONG, MUI_RequestA,
        AROS_LCA(APTR,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),D1),
        AROS_LCA(LONGBITS,(__arg3),D2),
        AROS_LCA(CONST_STRPTR,(__arg4),A0),
        AROS_LCA(CONST_STRPTR,(__arg5),A1),
        AROS_LCA(CONST_STRPTR,(__arg6),A2),
        AROS_LCA(APTR,(__arg7),A3),
        struct Library *, (__MUIMasterBase), 7, MUIMaster    );
}

#define MUI_RequestA(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_MUIMaster_MUI_RequestA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __MUIMASTER_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(MUIMASTER_NO_INLINE_STDARG)
#define MUI_Request(arg1, arg2, arg3, arg4, arg5, arg6, ...) \
({ \
    const IPTR MUI_RequestA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MUI_RequestA((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (APTR)(MUI_RequestA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline APTR __inline_MUIMaster_MUI_AllocAslRequest(unsigned long __arg1, struct TagItem* __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(APTR, MUI_AllocAslRequest,
        AROS_LCA(unsigned long,(__arg1),D0),
        AROS_LCA(struct TagItem*,(__arg2),A0),
        struct Library *, (__MUIMasterBase), 8, MUIMaster    );
}

#define MUI_AllocAslRequest(arg1, arg2) \
    __inline_MUIMaster_MUI_AllocAslRequest((arg1), (arg2), __MUIMASTER_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(MUIMASTER_NO_INLINE_STDARG)
#define MUI_AllocAslRequestTags(arg1, ...) \
({ \
    const IPTR MUI_AllocAslRequest_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MUI_AllocAslRequest((arg1), (struct TagItem*)(MUI_AllocAslRequest_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline BOOL __inline_MUIMaster_MUI_AslRequest(APTR __arg1, struct TagItem* __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(BOOL, MUI_AslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct TagItem*,(__arg2),A1),
        struct Library *, (__MUIMasterBase), 9, MUIMaster    );
}

#define MUI_AslRequest(arg1, arg2) \
    __inline_MUIMaster_MUI_AslRequest((arg1), (arg2), __MUIMASTER_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(MUIMASTER_NO_INLINE_STDARG)
#define MUI_AslRequestTags(arg1, ...) \
({ \
    const IPTR MUI_AslRequest_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MUI_AslRequest((arg1), (struct TagItem*)(MUI_AslRequest_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_FreeAslRequest(APTR __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC1NR(void, MUI_FreeAslRequest,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__MUIMasterBase), 10, MUIMaster    );
}

#define MUI_FreeAslRequest(arg1) \
    __inline_MUIMaster_MUI_FreeAslRequest((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline LONG __inline_MUIMaster_MUI_Error(APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC0(LONG, MUI_Error,
        struct Library *, (__MUIMasterBase), 11, MUIMaster    );
}

#define MUI_Error() \
    __inline_MUIMaster_MUI_Error(__MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline LONG __inline_MUIMaster_MUI_SetError(LONG __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC1(LONG, MUI_SetError,
        AROS_LCA(LONG,(__arg1),D0),
        struct Library *, (__MUIMasterBase), 12, MUIMaster    );
}

#define MUI_SetError(arg1) \
    __inline_MUIMaster_MUI_SetError((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline struct IClass* __inline_MUIMaster_MUI_GetClass(ClassID __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC1(struct IClass*, MUI_GetClass,
        AROS_LCA(ClassID,(__arg1),A0),
        struct Library *, (__MUIMasterBase), 13, MUIMaster    );
}

#define MUI_GetClass(arg1) \
    __inline_MUIMaster_MUI_GetClass((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_FreeClass(Class* __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC1NR(void, MUI_FreeClass,
        AROS_LCA(Class*,(__arg1),A0),
        struct Library *, (__MUIMasterBase), 14, MUIMaster    );
}

#define MUI_FreeClass(arg1) \
    __inline_MUIMaster_MUI_FreeClass((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_RequestIDCMP(Object* __arg1, ULONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_RequestIDCMP,
        AROS_LCA(Object*,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 15, MUIMaster    );
}

#define MUI_RequestIDCMP(arg1, arg2) \
    __inline_MUIMaster_MUI_RequestIDCMP((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_RejectIDCMP(Object* __arg1, ULONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_RejectIDCMP,
        AROS_LCA(Object*,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 16, MUIMaster    );
}

#define MUI_RejectIDCMP(arg1, arg2) \
    __inline_MUIMaster_MUI_RejectIDCMP((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_Redraw(Object* __arg1, ULONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_Redraw,
        AROS_LCA(Object*,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 17, MUIMaster    );
}

#define MUI_Redraw(arg1, arg2) \
    __inline_MUIMaster_MUI_Redraw((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline struct MUI_CustomClass* __inline_MUIMaster_MUI_CreateCustomClass(struct Library* __arg1, ClassID __arg2, struct MUI_CustomClass* __arg3, ULONG __arg4, APTR __arg5, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC5(struct MUI_CustomClass*, MUI_CreateCustomClass,
        AROS_LCA(struct Library*,(__arg1),A0),
        AROS_LCA(ClassID,(__arg2),A1),
        AROS_LCA(struct MUI_CustomClass*,(__arg3),A2),
        AROS_LCA(ULONG,(__arg4),D0),
        AROS_LCA(APTR,(__arg5),A3),
        struct Library *, (__MUIMasterBase), 18, MUIMaster    );
}

#define MUI_CreateCustomClass(arg1, arg2, arg3, arg4, arg5) \
    __inline_MUIMaster_MUI_CreateCustomClass((arg1), (arg2), (arg3), (arg4), (arg5), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline BOOL __inline_MUIMaster_MUI_DeleteCustomClass(struct MUI_CustomClass* __arg1, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC1(BOOL, MUI_DeleteCustomClass,
        AROS_LCA(struct MUI_CustomClass*,(__arg1),A0),
        struct Library *, (__MUIMasterBase), 19, MUIMaster    );
}

#define MUI_DeleteCustomClass(arg1) \
    __inline_MUIMaster_MUI_DeleteCustomClass((arg1), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline Object* __inline_MUIMaster_MUI_MakeObjectA(LONG __arg1, IPTR* __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(Object*, MUI_MakeObjectA,
        AROS_LCA(LONG,(__arg1),D0),
        AROS_LCA(IPTR*,(__arg2),A0),
        struct Library *, (__MUIMasterBase), 20, MUIMaster    );
}

#define MUI_MakeObjectA(arg1, arg2) \
    __inline_MUIMaster_MUI_MakeObjectA((arg1), (arg2), __MUIMASTER_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(MUIMASTER_NO_INLINE_STDARG)
#define MUI_MakeObject(arg1, ...) \
({ \
    const IPTR MUI_MakeObjectA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    MUI_MakeObjectA((arg1), (IPTR*)(MUI_MakeObjectA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline BOOL __inline_MUIMaster_MUI_Layout(Object* __arg1, LONG __arg2, LONG __arg3, LONG __arg4, LONG __arg5, ULONG __arg6, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC6(BOOL, MUI_Layout,
        AROS_LCA(Object*,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(LONG,(__arg4),D2),
        AROS_LCA(LONG,(__arg5),D3),
        AROS_LCA(ULONG,(__arg6),D4),
        struct Library *, (__MUIMasterBase), 21, MUIMaster    );
}

#define MUI_Layout(arg1, arg2, arg3, arg4, arg5, arg6) \
    __inline_MUIMaster_MUI_Layout((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline LONG __inline_MUIMaster_MUI_ObtainPen(struct MUI_RenderInfo* __arg1, struct MUI_PenSpec* __arg2, ULONG __arg3, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC3(LONG, MUI_ObtainPen,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(struct MUI_PenSpec*,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct Library *, (__MUIMasterBase), 26, MUIMaster    );
}

#define MUI_ObtainPen(arg1, arg2, arg3) \
    __inline_MUIMaster_MUI_ObtainPen((arg1), (arg2), (arg3), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_ReleasePen(struct MUI_RenderInfo* __arg1, LONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_ReleasePen,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 27, MUIMaster    );
}

#define MUI_ReleasePen(arg1, arg2) \
    __inline_MUIMaster_MUI_ReleasePen((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline APTR __inline_MUIMaster_MUI_AddClipping(struct MUI_RenderInfo* __arg1, WORD __arg2, WORD __arg3, WORD __arg4, WORD __arg5, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC5(APTR, MUI_AddClipping,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(WORD,(__arg2),D0),
        AROS_LCA(WORD,(__arg3),D1),
        AROS_LCA(WORD,(__arg4),D2),
        AROS_LCA(WORD,(__arg5),D3),
        struct Library *, (__MUIMasterBase), 28, MUIMaster    );
}

#define MUI_AddClipping(arg1, arg2, arg3, arg4, arg5) \
    __inline_MUIMaster_MUI_AddClipping((arg1), (arg2), (arg3), (arg4), (arg5), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_RemoveClipping(struct MUI_RenderInfo* __arg1, APTR __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_RemoveClipping,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Library *, (__MUIMasterBase), 29, MUIMaster    );
}

#define MUI_RemoveClipping(arg1, arg2) \
    __inline_MUIMaster_MUI_RemoveClipping((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline APTR __inline_MUIMaster_MUI_AddClipRegion(struct MUI_RenderInfo* __arg1, struct Region* __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(APTR, MUI_AddClipRegion,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(struct Region*,(__arg2),A1),
        struct Library *, (__MUIMasterBase), 30, MUIMaster    );
}

#define MUI_AddClipRegion(arg1, arg2) \
    __inline_MUIMaster_MUI_AddClipRegion((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_RemoveClipRegion(struct MUI_RenderInfo* __arg1, APTR __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_RemoveClipRegion,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(APTR,(__arg2),A1),
        struct Library *, (__MUIMasterBase), 31, MUIMaster    );
}

#define MUI_RemoveClipRegion(arg1, arg2) \
    __inline_MUIMaster_MUI_RemoveClipRegion((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline BOOL __inline_MUIMaster_MUI_BeginRefresh(struct MUI_RenderInfo* __arg1, ULONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    return AROS_LC2(BOOL, MUI_BeginRefresh,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 32, MUIMaster    );
}

#define MUI_BeginRefresh(arg1, arg2) \
    __inline_MUIMaster_MUI_BeginRefresh((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#if !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__)

static inline void __inline_MUIMaster_MUI_EndRefresh(struct MUI_RenderInfo* __arg1, ULONG __arg2, APTR __MUIMasterBase)
{
    AROS_LIBREQ(MUIMasterBase, 19)
    AROS_LC2NR(void, MUI_EndRefresh,
        AROS_LCA(struct MUI_RenderInfo*,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIMasterBase), 33, MUIMaster    );
}

#define MUI_EndRefresh(arg1, arg2) \
    __inline_MUIMaster_MUI_EndRefresh((arg1), (arg2), __MUIMASTER_LIBBASE)

#endif /* !defined(__MUIMASTER_LIBAPI__) || (19 <= __MUIMASTER_LIBAPI__) */

#endif /* INLINE_MUIMASTER_H*/
