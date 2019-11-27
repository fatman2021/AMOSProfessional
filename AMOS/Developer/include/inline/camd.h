#ifndef INLINE_CAMD_H
#define INLINE_CAMD_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/camd/camd.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for camd
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CAMD_LIBBASE)
#    define __CAMD_LIBBASE CamdBase
#endif


#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline APTR __inline_Camd_LockCAMD(ULONG __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(APTR, LockCAMD,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__CamdBase), 5, Camd    );
}

#define LockCAMD(arg1) \
    __inline_Camd_LockCAMD((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_UnlockCAMD(APTR __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, UnlockCAMD,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__CamdBase), 6, Camd    );
}

#define UnlockCAMD(arg1) \
    __inline_Camd_UnlockCAMD((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiNode * __inline_Camd_CreateMidiA(struct TagItem * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiNode *, CreateMidiA,
        AROS_LCA(struct TagItem *,(__arg1),A0),
        struct Library *, (__CamdBase), 7, Camd    );
}

#define CreateMidiA(arg1) \
    __inline_Camd_CreateMidiA((arg1), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define CreateMidi(...) \
({ \
    const IPTR CreateMidiA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateMidiA((struct TagItem *)(CreateMidiA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_DeleteMidi(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, DeleteMidi,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 8, Camd    );
}

#define DeleteMidi(arg1) \
    __inline_Camd_DeleteMidi((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_SetMidiAttrsA(struct MidiNode * __arg1, struct TagItem * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(BOOL, SetMidiAttrsA,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CamdBase), 9, Camd    );
}

#define SetMidiAttrsA(arg1, arg2) \
    __inline_Camd_SetMidiAttrsA((arg1), (arg2), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define SetMidiAttrs(arg1, ...) \
({ \
    const IPTR SetMidiAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetMidiAttrsA((arg1), (struct TagItem *)(SetMidiAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline ULONG __inline_Camd_GetMidiAttrsA(struct MidiNode * __arg1, struct TagItem * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(ULONG, GetMidiAttrsA,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CamdBase), 10, Camd    );
}

#define GetMidiAttrsA(arg1, arg2) \
    __inline_Camd_GetMidiAttrsA((arg1), (arg2), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define GetMidiAttrs(arg1, ...) \
({ \
    const IPTR GetMidiAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetMidiAttrsA((arg1), (struct TagItem *)(GetMidiAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiNode * __inline_Camd_NextMidi(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiNode *, NextMidi,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 11, Camd    );
}

#define NextMidi(arg1) \
    __inline_Camd_NextMidi((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiNode * __inline_Camd_FindMidi(STRPTR __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiNode *, FindMidi,
        AROS_LCA(STRPTR,(__arg1),A1),
        struct Library *, (__CamdBase), 12, Camd    );
}

#define FindMidi(arg1) \
    __inline_Camd_FindMidi((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_FlushMidi(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, FlushMidi,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 13, Camd    );
}

#define FlushMidi(arg1) \
    __inline_Camd_FlushMidi((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiLink * __inline_Camd_AddMidiLinkA(struct MidiNode * __arg1, LONG __arg2, struct TagItem * __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(struct MidiLink *, AddMidiLinkA,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__CamdBase), 14, Camd    );
}

#define AddMidiLinkA(arg1, arg2, arg3) \
    __inline_Camd_AddMidiLinkA((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define AddMidiLink(arg1, arg2, ...) \
({ \
    const IPTR AddMidiLinkA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddMidiLinkA((arg1), (arg2), (struct TagItem *)(AddMidiLinkA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_RemoveMidiLink(struct MidiLink * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, RemoveMidiLink,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        struct Library *, (__CamdBase), 15, Camd    );
}

#define RemoveMidiLink(arg1) \
    __inline_Camd_RemoveMidiLink((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_SetMidiLinkAttrsA(struct MidiLink * __arg1, struct TagItem * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(BOOL, SetMidiLinkAttrsA,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CamdBase), 16, Camd    );
}

#define SetMidiLinkAttrsA(arg1, arg2) \
    __inline_Camd_SetMidiLinkAttrsA((arg1), (arg2), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define SetMidiLinkAttrs(arg1, ...) \
({ \
    const IPTR SetMidiLinkAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetMidiLinkAttrsA((arg1), (struct TagItem *)(SetMidiLinkAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline ULONG __inline_Camd_GetMidiLinkAttrsA(struct MidiLink * __arg1, struct TagItem * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(ULONG, GetMidiLinkAttrsA,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(struct TagItem *,(__arg2),A1),
        struct Library *, (__CamdBase), 17, Camd    );
}

#define GetMidiLinkAttrsA(arg1, arg2) \
    __inline_Camd_GetMidiLinkAttrsA((arg1), (arg2), __CAMD_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define GetMidiLinkAttrs(arg1, ...) \
({ \
    const IPTR GetMidiLinkAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetMidiLinkAttrsA((arg1), (struct TagItem *)(GetMidiLinkAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiLink * __inline_Camd_NextClusterLink(struct MidiCluster * __arg1, struct MidiLink * __arg2, LONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(struct MidiLink *, NextClusterLink,
        AROS_LCA(struct MidiCluster *,(__arg1),A0),
        AROS_LCA(struct MidiLink *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__CamdBase), 18, Camd    );
}

#define NextClusterLink(arg1, arg2, arg3) \
    __inline_Camd_NextClusterLink((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiLink * __inline_Camd_NextMidiLink(struct MidiNode * __arg1, struct MidiLink * __arg2, LONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(struct MidiLink *, NextMidiLink,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(struct MidiLink *,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D0),
        struct Library *, (__CamdBase), 19, Camd    );
}

#define NextMidiLink(arg1, arg2, arg3) \
    __inline_Camd_NextMidiLink((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_MidiLinkConnected(struct MidiLink * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(BOOL, MidiLinkConnected,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        struct Library *, (__CamdBase), 20, Camd    );
}

#define MidiLinkConnected(arg1) \
    __inline_Camd_MidiLinkConnected((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiCluster * __inline_Camd_NextCluster(struct MidiCluster * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiCluster *, NextCluster,
        AROS_LCA(struct MidiCluster *,(__arg1),A0),
        struct Library *, (__CamdBase), 21, Camd    );
}

#define NextCluster(arg1) \
    __inline_Camd_NextCluster((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiCluster * __inline_Camd_FindCluster(STRPTR __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiCluster *, FindCluster,
        AROS_LCA(STRPTR,(__arg1),A0),
        struct Library *, (__CamdBase), 22, Camd    );
}

#define FindCluster(arg1) \
    __inline_Camd_FindCluster((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_PutMidi(struct MidiLink * __arg1, ULONG __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC2NR(void, PutMidi,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__CamdBase), 23, Camd    );
}

#define PutMidi(arg1, arg2) \
    __inline_Camd_PutMidi((arg1), (arg2), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_GetMidi(struct MidiNode * __arg1, MidiMsg * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(BOOL, GetMidi,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(MidiMsg *,(__arg2),A1),
        struct Library *, (__CamdBase), 24, Camd    );
}

#define GetMidi(arg1, arg2) \
    __inline_Camd_GetMidi((arg1), (arg2), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_WaitMidi(struct MidiNode * __arg1, MidiMsg * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC2(BOOL, WaitMidi,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(MidiMsg *,(__arg2),A1),
        struct Library *, (__CamdBase), 25, Camd    );
}

#define WaitMidi(arg1, arg2) \
    __inline_Camd_WaitMidi((arg1), (arg2), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_PutSysEx(struct MidiLink * __arg1, UBYTE * __arg2, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC2NR(void, PutSysEx,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        struct Library *, (__CamdBase), 26, Camd    );
}

#define PutSysEx(arg1, arg2) \
    __inline_Camd_PutSysEx((arg1), (arg2), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline ULONG __inline_Camd_GetSysEx(struct MidiNode * __arg1, UBYTE * __arg2, ULONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(ULONG, GetSysEx,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct Library *, (__CamdBase), 27, Camd    );
}

#define GetSysEx(arg1, arg2, arg3) \
    __inline_Camd_GetSysEx((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline ULONG __inline_Camd_QuerySysEx(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(ULONG, QuerySysEx,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 28, Camd    );
}

#define QuerySysEx(arg1) \
    __inline_Camd_QuerySysEx((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_SkipSysEx(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, SkipSysEx,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 29, Camd    );
}

#define SkipSysEx(arg1) \
    __inline_Camd_SkipSysEx((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline UBYTE __inline_Camd_GetMidiErr(struct MidiNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(UBYTE, GetMidiErr,
        AROS_LCA(struct MidiNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 30, Camd    );
}

#define GetMidiErr(arg1) \
    __inline_Camd_GetMidiErr((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline WORD __inline_Camd_MidiMsgType(MidiMsg * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(WORD, MidiMsgType,
        AROS_LCA(MidiMsg *,(__arg1),A0),
        struct Library *, (__CamdBase), 31, Camd    );
}

#define MidiMsgType(arg1) \
    __inline_Camd_MidiMsgType((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline WORD __inline_Camd_MidiMsgLen(ULONG __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(WORD, MidiMsgLen,
        AROS_LCA(ULONG,(__arg1),D0),
        struct Library *, (__CamdBase), 32, Camd    );
}

#define MidiMsgLen(arg1) \
    __inline_Camd_MidiMsgLen((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_ParseMidi(struct MidiLink * __arg1, UBYTE * __arg2, ULONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC3NR(void, ParseMidi,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(UBYTE *,(__arg2),A1),
        AROS_LCA(ULONG,(__arg3),D0),
        struct Library *, (__CamdBase), 33, Camd    );
}

#define ParseMidi(arg1, arg2, arg3) \
    __inline_Camd_ParseMidi((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline struct MidiDeviceData * __inline_Camd_OpenMidiDevice(UBYTE * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC1(struct MidiDeviceData *, OpenMidiDevice,
        AROS_LCA(UBYTE *,(__arg1),A0),
        struct Library *, (__CamdBase), 34, Camd    );
}

#define OpenMidiDevice(arg1) \
    __inline_Camd_OpenMidiDevice((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_CloseMidiDevice(struct MidiDeviceData * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, CloseMidiDevice,
        AROS_LCA(struct MidiDeviceData *,(__arg1),A0),
        struct Library *, (__CamdBase), 35, Camd    );
}

#define CloseMidiDevice(arg1) \
    __inline_Camd_CloseMidiDevice((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline LONG __inline_Camd_RethinkCAMD(APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC0(LONG, RethinkCAMD,
        struct Library *, (__CamdBase), 36, Camd    );
}

#define RethinkCAMD() \
    __inline_Camd_RethinkCAMD(__CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_StartClusterNotify(struct ClusterNotifyNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, StartClusterNotify,
        AROS_LCA(struct ClusterNotifyNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 37, Camd    );
}

#define StartClusterNotify(arg1) \
    __inline_Camd_StartClusterNotify((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline void __inline_Camd_EndClusterNotify(struct ClusterNotifyNode * __arg1, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    AROS_LC1NR(void, EndClusterNotify,
        AROS_LCA(struct ClusterNotifyNode *,(__arg1),A0),
        struct Library *, (__CamdBase), 38, Camd    );
}

#define EndClusterNotify(arg1) \
    __inline_Camd_EndClusterNotify((arg1), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline APTR __inline_Camd_GoodPutMidi(struct MidiLink * __arg1, ULONG __arg2, ULONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(APTR, GoodPutMidi,
        AROS_LCA(struct MidiLink *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct Library *, (__CamdBase), 39, Camd    );
}

#define GoodPutMidi(arg1, arg2, arg3) \
    __inline_Camd_GoodPutMidi((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

static inline BOOL __inline_Camd_Midi2Driver(APTR __arg1, ULONG __arg2, ULONG __arg3, APTR __CamdBase)
{
    AROS_LIBREQ(CamdBase, 41)
    return AROS_LC3(BOOL, Midi2Driver,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(ULONG,(__arg3),D1),
        struct Library *, (__CamdBase), 40, Camd    );
}

#define Midi2Driver(arg1, arg2, arg3) \
    __inline_Camd_Midi2Driver((arg1), (arg2), (arg3), __CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#endif /* INLINE_CAMD_H*/
