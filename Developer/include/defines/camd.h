#ifndef DEFINES_CAMD_H
#define DEFINES_CAMD_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/camd/camd.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for camd
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__CAMD_LIBBASE)
#    define __CAMD_LIBBASE CamdBase
#endif

__BEGIN_DECLS


#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __LockCAMD_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(APTR, LockCAMD, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__CamdBase), 5, Camd);\
})

#define LockCAMD(arg1) \
    __LockCAMD_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __UnlockCAMD_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, UnlockCAMD, \
                  AROS_LCA(APTR,(__arg1),A0), \
        struct Library *, (__CamdBase), 6, Camd);\
})

#define UnlockCAMD(arg1) \
    __UnlockCAMD_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __CreateMidiA_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiNode *, CreateMidiA, \
                  AROS_LCA(struct TagItem *,(__arg1),A0), \
        struct Library *, (__CamdBase), 7, Camd);\
})

#define CreateMidiA(arg1) \
    __CreateMidiA_WB(__CAMD_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define CreateMidi(...) \
({ \
    const IPTR CreateMidiA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateMidiA((struct TagItem *)(CreateMidiA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __DeleteMidi_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, DeleteMidi, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 8, Camd);\
})

#define DeleteMidi(arg1) \
    __DeleteMidi_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __SetMidiAttrsA_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(BOOL, SetMidiAttrsA, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CamdBase), 9, Camd);\
})

#define SetMidiAttrsA(arg1, arg2) \
    __SetMidiAttrsA_WB(__CAMD_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define SetMidiAttrs(arg1, ...) \
({ \
    const IPTR SetMidiAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetMidiAttrsA((arg1), (struct TagItem *)(SetMidiAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GetMidiAttrsA_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(ULONG, GetMidiAttrsA, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CamdBase), 10, Camd);\
})

#define GetMidiAttrsA(arg1, arg2) \
    __GetMidiAttrsA_WB(__CAMD_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define GetMidiAttrs(arg1, ...) \
({ \
    const IPTR GetMidiAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetMidiAttrsA((arg1), (struct TagItem *)(GetMidiAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __NextMidi_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiNode *, NextMidi, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 11, Camd);\
})

#define NextMidi(arg1) \
    __NextMidi_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __FindMidi_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiNode *, FindMidi, \
                  AROS_LCA(STRPTR,(__arg1),A1), \
        struct Library *, (__CamdBase), 12, Camd);\
})

#define FindMidi(arg1) \
    __FindMidi_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __FlushMidi_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, FlushMidi, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 13, Camd);\
})

#define FlushMidi(arg1) \
    __FlushMidi_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __AddMidiLinkA_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(struct MidiLink *, AddMidiLinkA, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(LONG,(__arg2),D0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__CamdBase), 14, Camd);\
})

#define AddMidiLinkA(arg1, arg2, arg3) \
    __AddMidiLinkA_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define AddMidiLink(arg1, arg2, ...) \
({ \
    const IPTR AddMidiLinkA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AddMidiLinkA((arg1), (arg2), (struct TagItem *)(AddMidiLinkA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __RemoveMidiLink_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, RemoveMidiLink, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
        struct Library *, (__CamdBase), 15, Camd);\
})

#define RemoveMidiLink(arg1) \
    __RemoveMidiLink_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __SetMidiLinkAttrsA_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(BOOL, SetMidiLinkAttrsA, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CamdBase), 16, Camd);\
})

#define SetMidiLinkAttrsA(arg1, arg2) \
    __SetMidiLinkAttrsA_WB(__CAMD_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define SetMidiLinkAttrs(arg1, ...) \
({ \
    const IPTR SetMidiLinkAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SetMidiLinkAttrsA((arg1), (struct TagItem *)(SetMidiLinkAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GetMidiLinkAttrsA_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(ULONG, GetMidiLinkAttrsA, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(struct TagItem *,(__arg2),A1), \
        struct Library *, (__CamdBase), 17, Camd);\
})

#define GetMidiLinkAttrsA(arg1, arg2) \
    __GetMidiLinkAttrsA_WB(__CAMD_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(CAMD_NO_INLINE_STDARG)
#define GetMidiLinkAttrs(arg1, ...) \
({ \
    const IPTR GetMidiLinkAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    GetMidiLinkAttrsA((arg1), (struct TagItem *)(GetMidiLinkAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __NextClusterLink_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(struct MidiLink *, NextClusterLink, \
                  AROS_LCA(struct MidiCluster *,(__arg1),A0), \
                  AROS_LCA(struct MidiLink *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__CamdBase), 18, Camd);\
})

#define NextClusterLink(arg1, arg2, arg3) \
    __NextClusterLink_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __NextMidiLink_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(struct MidiLink *, NextMidiLink, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(struct MidiLink *,(__arg2),A1), \
                  AROS_LCA(LONG,(__arg3),D0), \
        struct Library *, (__CamdBase), 19, Camd);\
})

#define NextMidiLink(arg1, arg2, arg3) \
    __NextMidiLink_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __MidiLinkConnected_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(BOOL, MidiLinkConnected, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
        struct Library *, (__CamdBase), 20, Camd);\
})

#define MidiLinkConnected(arg1) \
    __MidiLinkConnected_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __NextCluster_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiCluster *, NextCluster, \
                  AROS_LCA(struct MidiCluster *,(__arg1),A0), \
        struct Library *, (__CamdBase), 21, Camd);\
})

#define NextCluster(arg1) \
    __NextCluster_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __FindCluster_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiCluster *, FindCluster, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
        struct Library *, (__CamdBase), 22, Camd);\
})

#define FindCluster(arg1) \
    __FindCluster_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __PutMidi_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2NR(void, PutMidi, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
        struct Library *, (__CamdBase), 23, Camd);\
})

#define PutMidi(arg1, arg2) \
    __PutMidi_WB(__CAMD_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GetMidi_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(BOOL, GetMidi, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(MidiMsg *,(__arg2),A1), \
        struct Library *, (__CamdBase), 24, Camd);\
})

#define GetMidi(arg1, arg2) \
    __GetMidi_WB(__CAMD_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __WaitMidi_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2(BOOL, WaitMidi, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(MidiMsg *,(__arg2),A1), \
        struct Library *, (__CamdBase), 25, Camd);\
})

#define WaitMidi(arg1, arg2) \
    __WaitMidi_WB(__CAMD_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __PutSysEx_WB(__CamdBase, __arg1, __arg2) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC2NR(void, PutSysEx, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
        struct Library *, (__CamdBase), 26, Camd);\
})

#define PutSysEx(arg1, arg2) \
    __PutSysEx_WB(__CAMD_LIBBASE, (arg1), (arg2))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GetSysEx_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(ULONG, GetSysEx, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct Library *, (__CamdBase), 27, Camd);\
})

#define GetSysEx(arg1, arg2, arg3) \
    __GetSysEx_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __QuerySysEx_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(ULONG, QuerySysEx, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 28, Camd);\
})

#define QuerySysEx(arg1) \
    __QuerySysEx_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __SkipSysEx_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, SkipSysEx, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 29, Camd);\
})

#define SkipSysEx(arg1) \
    __SkipSysEx_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GetMidiErr_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(UBYTE, GetMidiErr, \
                  AROS_LCA(struct MidiNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 30, Camd);\
})

#define GetMidiErr(arg1) \
    __GetMidiErr_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __MidiMsgType_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(WORD, MidiMsgType, \
                  AROS_LCA(MidiMsg *,(__arg1),A0), \
        struct Library *, (__CamdBase), 31, Camd);\
})

#define MidiMsgType(arg1) \
    __MidiMsgType_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __MidiMsgLen_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(WORD, MidiMsgLen, \
                  AROS_LCA(ULONG,(__arg1),D0), \
        struct Library *, (__CamdBase), 32, Camd);\
})

#define MidiMsgLen(arg1) \
    __MidiMsgLen_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __ParseMidi_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3NR(void, ParseMidi, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(UBYTE *,(__arg2),A1), \
                  AROS_LCA(ULONG,(__arg3),D0), \
        struct Library *, (__CamdBase), 33, Camd);\
})

#define ParseMidi(arg1, arg2, arg3) \
    __ParseMidi_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __OpenMidiDevice_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1(struct MidiDeviceData *, OpenMidiDevice, \
                  AROS_LCA(UBYTE *,(__arg1),A0), \
        struct Library *, (__CamdBase), 34, Camd);\
})

#define OpenMidiDevice(arg1) \
    __OpenMidiDevice_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __CloseMidiDevice_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, CloseMidiDevice, \
                  AROS_LCA(struct MidiDeviceData *,(__arg1),A0), \
        struct Library *, (__CamdBase), 35, Camd);\
})

#define CloseMidiDevice(arg1) \
    __CloseMidiDevice_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __RethinkCAMD_WB(__CamdBase) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC0(LONG, RethinkCAMD, \
        struct Library *, (__CamdBase), 36, Camd);\
})

#define RethinkCAMD() \
    __RethinkCAMD_WB(__CAMD_LIBBASE)

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __StartClusterNotify_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, StartClusterNotify, \
                  AROS_LCA(struct ClusterNotifyNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 37, Camd);\
})

#define StartClusterNotify(arg1) \
    __StartClusterNotify_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __EndClusterNotify_WB(__CamdBase, __arg1) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC1NR(void, EndClusterNotify, \
                  AROS_LCA(struct ClusterNotifyNode *,(__arg1),A0), \
        struct Library *, (__CamdBase), 38, Camd);\
})

#define EndClusterNotify(arg1) \
    __EndClusterNotify_WB(__CAMD_LIBBASE, (arg1))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __GoodPutMidi_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(APTR, GoodPutMidi, \
                  AROS_LCA(struct MidiLink *,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct Library *, (__CamdBase), 39, Camd);\
})

#define GoodPutMidi(arg1, arg2, arg3) \
    __GoodPutMidi_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

#if !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__)

#define __Midi2Driver_WB(__CamdBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(CamdBase,41)\
        AROS_LC3(BOOL, Midi2Driver, \
                  AROS_LCA(APTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(ULONG,(__arg3),D1), \
        struct Library *, (__CamdBase), 40, Camd);\
})

#define Midi2Driver(arg1, arg2, arg3) \
    __Midi2Driver_WB(__CAMD_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__CAMD_LIBAPI__) || (41 <= __CAMD_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_CAMD_H*/
