#ifndef INLINE_DOS_H
#define INLINE_DOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/dos/dos.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for dos
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DOS_LIBBASE)
#    define __DOS_LIBBASE DOSBase
#endif


#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_Open(CONST_STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(BPTR, Open,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 5, Dos    );
}

#define Open(arg1, arg2) \
    __inline_Dos_Open((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_Close(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BOOL, Close,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 6, Dos    );
}

#define Close(arg1) \
    __inline_Dos_Close((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Read(BPTR __arg1, APTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC3(LONG, Read,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(APTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 7, Dos    );
}

#define Read(arg1, arg2, arg3) \
    __inline_Dos_Read((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Write(BPTR __arg1, CONST_APTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC3(LONG, Write,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(CONST_APTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 8, Dos    );
}

#define Write(arg1, arg2, arg3) \
    __inline_Dos_Write((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_Input(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC0(BPTR, Input,
        struct DosLibrary *, (__DOSBase), 9, Dos    );
}

#define Input() \
    __inline_Dos_Input(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_Output(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC0(BPTR, Output,
        struct DosLibrary *, (__DOSBase), 10, Dos    );
}

#define Output() \
    __inline_Dos_Output(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Seek(BPTR __arg1, LONG __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC3(LONG, Seek,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 11, Dos    );
}

#define Seek(arg1, arg2, arg3) \
    __inline_Dos_Seek((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_DeleteFile(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BOOL, DeleteFile,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 12, Dos    );
}

#define DeleteFile(arg1) \
    __inline_Dos_DeleteFile((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Rename(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, Rename,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 13, Dos    );
}

#define Rename(arg1, arg2) \
    __inline_Dos_Rename((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_Lock(CONST_STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(BPTR, Lock,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 14, Dos    );
}

#define Lock(arg1, arg2) \
    __inline_Dos_Lock((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_UnLock(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BOOL, UnLock,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 15, Dos    );
}

#define UnLock(arg1) \
    __inline_Dos_UnLock((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_DupLock(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BPTR, DupLock,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 16, Dos    );
}

#define DupLock(arg1) \
    __inline_Dos_DupLock((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Examine(BPTR __arg1, struct FileInfoBlock* __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, Examine,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct FileInfoBlock*,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 17, Dos    );
}

#define Examine(arg1, arg2) \
    __inline_Dos_Examine((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ExNext(BPTR __arg1, struct FileInfoBlock* __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, ExNext,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct FileInfoBlock*,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 18, Dos    );
}

#define ExNext(arg1, arg2) \
    __inline_Dos_ExNext((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Info(BPTR __arg1, struct InfoData* __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, Info,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct InfoData*,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 19, Dos    );
}

#define Info(arg1, arg2) \
    __inline_Dos_Info((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_CreateDir(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BPTR, CreateDir,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 20, Dos    );
}

#define CreateDir(arg1) \
    __inline_Dos_CreateDir((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_CurrentDir(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BPTR, CurrentDir,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 21, Dos    );
}

#define CurrentDir(arg1) \
    __inline_Dos_CurrentDir((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline SIPTR __inline_Dos_IoErr(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC0(SIPTR, IoErr,
        struct DosLibrary *, (__DOSBase), 22, Dos    );
}

#define IoErr() \
    __inline_Dos_IoErr(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline struct MsgPort* __inline_Dos_CreateProc(CONST_STRPTR __arg1, LONG __arg2, BPTR __arg3, LONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC4(struct MsgPort*, CreateProc,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(BPTR,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 23, Dos    );
}

#define CreateProc(arg1, arg2, arg3, arg4) \
    __inline_Dos_CreateProc((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline void __inline_Dos_Exit(LONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    AROS_LC1NR(void, Exit,
        AROS_LCA(LONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 24, Dos    );
}

#define Exit(arg1) \
    __inline_Dos_Exit((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_LoadSeg(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BPTR, LoadSeg,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 25, Dos    );
}

#define LoadSeg(arg1) \
    __inline_Dos_LoadSeg((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_UnLoadSeg(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BOOL, UnLoadSeg,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 26, Dos    );
}

#define UnLoadSeg(arg1) \
    __inline_Dos_UnLoadSeg((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline struct MsgPort * __inline_Dos_DeviceProc(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(struct MsgPort *, DeviceProc,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 29, Dos    );
}

#define DeviceProc(arg1) \
    __inline_Dos_DeviceProc((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SetComment(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, SetComment,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 30, Dos    );
}

#define SetComment(arg1, arg2) \
    __inline_Dos_SetComment((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SetProtection(CONST_STRPTR __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, SetProtection,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 31, Dos    );
}

#define SetProtection(arg1, arg2) \
    __inline_Dos_SetProtection((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline struct DateStamp * __inline_Dos_DateStamp(struct DateStamp * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(struct DateStamp *, DateStamp,
        AROS_LCA(struct DateStamp *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 32, Dos    );
}

#define DateStamp(arg1) \
    __inline_Dos_DateStamp((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline void __inline_Dos_Delay(ULONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    AROS_LC1NR(void, Delay,
        AROS_LCA(ULONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 33, Dos    );
}

#define Delay(arg1) \
    __inline_Dos_Delay((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_WaitForChar(BPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC2(LONG, WaitForChar,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 34, Dos    );
}

#define WaitForChar(arg1, arg2) \
    __inline_Dos_WaitForChar((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_ParentDir(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(BPTR, ParentDir,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 35, Dos    );
}

#define ParentDir(arg1) \
    __inline_Dos_ParentDir((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_IsInteractive(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC1(LONG, IsInteractive,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 36, Dos    );
}

#define IsInteractive(arg1) \
    __inline_Dos_IsInteractive((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_Execute(CONST_STRPTR __arg1, BPTR __arg2, BPTR __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 0)
    return AROS_LC3(BOOL, Execute,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        AROS_LCA(BPTR,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 37, Dos    );
}

#define Execute(arg1, arg2, arg3) \
    __inline_Dos_Execute((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline APTR __inline_Dos_AllocDosObject(ULONG __arg1, struct TagItem * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(APTR, AllocDosObject,
        AROS_LCA(ULONG,(__arg1),D1),
        AROS_LCA(struct TagItem *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 38, Dos    );
}

#define AllocDosObject(arg1, arg2) \
    __inline_Dos_AllocDosObject((arg1), (arg2), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define AllocDosObjectTags(arg1, ...) \
({ \
    const IPTR AllocDosObject_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocDosObject((arg1), (struct TagItem *)(AllocDosObject_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_FreeDosObject(ULONG __arg1, APTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC2NR(void, FreeDosObject,
        AROS_LCA(ULONG,(__arg1),D1),
        AROS_LCA(APTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 39, Dos    );
}

#define FreeDosObject(arg1, arg2) \
    __inline_Dos_FreeDosObject((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline SIPTR __inline_Dos_DoPkt(struct MsgPort* __arg1, LONG __arg2, SIPTR __arg3, SIPTR __arg4, SIPTR __arg5, SIPTR __arg6, SIPTR __arg7, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC7(SIPTR, DoPkt,
        AROS_LCA(struct MsgPort*,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(SIPTR,(__arg3),D3),
        AROS_LCA(SIPTR,(__arg4),D4),
        AROS_LCA(SIPTR,(__arg5),D5),
        AROS_LCA(SIPTR,(__arg6),D6),
        AROS_LCA(SIPTR,(__arg7),D7),
        struct DosLibrary *, (__DOSBase), 40, Dos    );
}

#define DoPkt(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_Dos_DoPkt((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_SendPkt(struct DosPacket * __arg1, struct MsgPort * __arg2, struct MsgPort * __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC3NR(void, SendPkt,
        AROS_LCA(struct DosPacket *,(__arg1),D1),
        AROS_LCA(struct MsgPort *,(__arg2),D2),
        AROS_LCA(struct MsgPort *,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 41, Dos    );
}

#define SendPkt(arg1, arg2, arg3) \
    __inline_Dos_SendPkt((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosPacket * __inline_Dos_WaitPkt(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(struct DosPacket *, WaitPkt,
        struct DosLibrary *, (__DOSBase), 42, Dos    );
}

#define WaitPkt() \
    __inline_Dos_WaitPkt(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_ReplyPkt(struct DosPacket * __arg1, SIPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC3NR(void, ReplyPkt,
        AROS_LCA(struct DosPacket *,(__arg1),D1),
        AROS_LCA(SIPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 43, Dos    );
}

#define ReplyPkt(arg1, arg2, arg3) \
    __inline_Dos_ReplyPkt((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_AbortPkt(struct MsgPort * __arg1, struct DosPacket * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC2NR(void, AbortPkt,
        AROS_LCA(struct MsgPort *,(__arg1),D1),
        AROS_LCA(struct DosPacket *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 44, Dos    );
}

#define AbortPkt(arg1, arg2) \
    __inline_Dos_AbortPkt((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_LockRecord(BPTR __arg1, ULONG __arg2, ULONG __arg3, ULONG __arg4, ULONG __arg5, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC5(BOOL, LockRecord,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        AROS_LCA(ULONG,(__arg4),D4),
        AROS_LCA(ULONG,(__arg5),D5),
        struct DosLibrary *, (__DOSBase), 45, Dos    );
}

#define LockRecord(arg1, arg2, arg3, arg4, arg5) \
    __inline_Dos_LockRecord((arg1), (arg2), (arg3), (arg4), (arg5), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_LockRecords(struct RecordLock * __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, LockRecords,
        AROS_LCA(struct RecordLock *,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 46, Dos    );
}

#define LockRecords(arg1, arg2) \
    __inline_Dos_LockRecords((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_UnLockRecord(BPTR __arg1, ULONG __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, UnLockRecord,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 47, Dos    );
}

#define UnLockRecord(arg1, arg2, arg3) \
    __inline_Dos_UnLockRecord((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_UnLockRecords(struct RecordLock * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, UnLockRecords,
        AROS_LCA(struct RecordLock *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 48, Dos    );
}

#define UnLockRecords(arg1) \
    __inline_Dos_UnLockRecords((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_SelectInput(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, SelectInput,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 49, Dos    );
}

#define SelectInput(arg1) \
    __inline_Dos_SelectInput((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_SelectOutput(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, SelectOutput,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 50, Dos    );
}

#define SelectOutput(arg1) \
    __inline_Dos_SelectOutput((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FGetC(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, FGetC,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 51, Dos    );
}

#define FGetC(arg1) \
    __inline_Dos_FGetC((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FPutC(BPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, FPutC,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 52, Dos    );
}

#define FPutC(arg1, arg2) \
    __inline_Dos_FPutC((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_UnGetC(BPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, UnGetC,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 53, Dos    );
}

#define UnGetC(arg1, arg2) \
    __inline_Dos_UnGetC((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FRead(BPTR __arg1, APTR __arg2, ULONG __arg3, ULONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(LONG, FRead,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(APTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        AROS_LCA(ULONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 54, Dos    );
}

#define FRead(arg1, arg2, arg3, arg4) \
    __inline_Dos_FRead((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FWrite(BPTR __arg1, CONST_APTR __arg2, ULONG __arg3, ULONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(LONG, FWrite,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(CONST_APTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        AROS_LCA(ULONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 55, Dos    );
}

#define FWrite(arg1, arg2, arg3, arg4) \
    __inline_Dos_FWrite((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_FGets(BPTR __arg1, STRPTR __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(STRPTR, FGets,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 56, Dos    );
}

#define FGets(arg1, arg2, arg3) \
    __inline_Dos_FGets((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FPuts(BPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, FPuts,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 57, Dos    );
}

#define FPuts(arg1, arg2) \
    __inline_Dos_FPuts((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_VFWritef(BPTR __arg1, CONST_STRPTR __arg2, RAWARG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, VFWritef,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(RAWARG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 58, Dos    );
}

#define VFWritef(arg1, arg2, arg3) \
    __inline_Dos_VFWritef((arg1), (arg2), (arg3), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_FWritef(struct DosLibrary * __DOSBase, BPTR __arg1, CONST_STRPTR __arg2, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg2);
    retval = __inline_Dos_VFWritef(__arg1, __arg2, AROS_SLOWSTACKFORMAT_ARG(__arg2), __DOSBase);
    AROS_SLOWSTACKFORMAT_POST(__arg2);
    return retval;
}

#define FWritef(arg1, ...) \
    __inline_Dos_FWritef((struct DosLibrary *)__DOS_LIBBASE, (arg1), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_VFPrintf(BPTR __arg1, CONST_STRPTR __arg2, RAWARG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, VFPrintf,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(RAWARG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 59, Dos    );
}

#define VFPrintf(arg1, arg2, arg3) \
    __inline_Dos_VFPrintf((arg1), (arg2), (arg3), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_FPrintf(struct DosLibrary * __DOSBase, BPTR __arg1, CONST_STRPTR __arg2, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg2);
    retval = __inline_Dos_VFPrintf(__arg1, __arg2, AROS_SLOWSTACKFORMAT_ARG(__arg2), __DOSBase);
    AROS_SLOWSTACKFORMAT_POST(__arg2);
    return retval;
}

#define FPrintf(arg1, ...) \
    __inline_Dos_FPrintf((struct DosLibrary *)__DOS_LIBBASE, (arg1), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Flush(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, Flush,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 60, Dos    );
}

#define Flush(arg1) \
    __inline_Dos_Flush((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SetVBuf(BPTR __arg1, STRPTR __arg2, LONG __arg3, LONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(LONG, SetVBuf,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 61, Dos    );
}

#define SetVBuf(arg1, arg2, arg3, arg4) \
    __inline_Dos_SetVBuf((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_DupLockFromFH(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, DupLockFromFH,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 62, Dos    );
}

#define DupLockFromFH(arg1) \
    __inline_Dos_DupLockFromFH((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_OpenFromLock(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, OpenFromLock,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 63, Dos    );
}

#define OpenFromLock(arg1) \
    __inline_Dos_OpenFromLock((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_ParentOfFH(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, ParentOfFH,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 64, Dos    );
}

#define ParentOfFH(arg1) \
    __inline_Dos_ParentOfFH((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_ExamineFH(BPTR __arg1, struct FileInfoBlock* __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, ExamineFH,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct FileInfoBlock*,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 65, Dos    );
}

#define ExamineFH(arg1, arg2) \
    __inline_Dos_ExamineFH((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetFileDate(CONST_STRPTR __arg1, const struct DateStamp * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, SetFileDate,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(const struct DateStamp *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 66, Dos    );
}

#define SetFileDate(arg1, arg2) \
    __inline_Dos_SetFileDate((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_NameFromLock(BPTR __arg1, STRPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, NameFromLock,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 67, Dos    );
}

#define NameFromLock(arg1, arg2, arg3) \
    __inline_Dos_NameFromLock((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_NameFromFH(BPTR __arg1, STRPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, NameFromFH,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 68, Dos    );
}

#define NameFromFH(arg1, arg2, arg3) \
    __inline_Dos_NameFromFH((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SplitName(CONST_STRPTR __arg1, ULONG __arg2, STRPTR __arg3, LONG __arg4, LONG __arg5, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC5(LONG, SplitName,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(STRPTR,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        AROS_LCA(LONG,(__arg5),D5),
        struct DosLibrary *, (__DOSBase), 69, Dos    );
}

#define SplitName(arg1, arg2, arg3, arg4, arg5) \
    __inline_Dos_SplitName((arg1), (arg2), (arg3), (arg4), (arg5), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SameLock(BPTR __arg1, BPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, SameLock,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 70, Dos    );
}

#define SameLock(arg1, arg2) \
    __inline_Dos_SameLock((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SetMode(BPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, SetMode,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 71, Dos    );
}

#define SetMode(arg1, arg2) \
    __inline_Dos_SetMode((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_ExAll(BPTR __arg1, struct ExAllData * __arg2, LONG __arg3, LONG __arg4, struct ExAllControl * __arg5, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC5(BOOL, ExAll,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct ExAllData *,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        AROS_LCA(struct ExAllControl *,(__arg5),D5),
        struct DosLibrary *, (__DOSBase), 72, Dos    );
}

#define ExAll(arg1, arg2, arg3, arg4, arg5) \
    __inline_Dos_ExAll((arg1), (arg2), (arg3), (arg4), (arg5), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ReadLink(struct MsgPort * __arg1, BPTR __arg2, CONST_STRPTR __arg3, STRPTR __arg4, ULONG __arg5, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC5(LONG, ReadLink,
        AROS_LCA(struct MsgPort *,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        AROS_LCA(CONST_STRPTR,(__arg3),D3),
        AROS_LCA(STRPTR,(__arg4),D4),
        AROS_LCA(ULONG,(__arg5),D5),
        struct DosLibrary *, (__DOSBase), 73, Dos    );
}

#define ReadLink(arg1, arg2, arg3, arg4, arg5) \
    __inline_Dos_ReadLink((arg1), (arg2), (arg3), (arg4), (arg5), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_MakeLink(CONST_STRPTR __arg1, SIPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, MakeLink,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(SIPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 74, Dos    );
}

#define MakeLink(arg1, arg2, arg3) \
    __inline_Dos_MakeLink((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_ChangeMode(ULONG __arg1, BPTR __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, ChangeMode,
        AROS_LCA(ULONG,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 75, Dos    );
}

#define ChangeMode(arg1, arg2, arg3) \
    __inline_Dos_ChangeMode((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SetFileSize(BPTR __arg1, LONG __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, SetFileSize,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 76, Dos    );
}

#define SetFileSize(arg1, arg2, arg3) \
    __inline_Dos_SetFileSize((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline SIPTR __inline_Dos_SetIoErr(SIPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(SIPTR, SetIoErr,
        AROS_LCA(SIPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 77, Dos    );
}

#define SetIoErr(arg1) \
    __inline_Dos_SetIoErr((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_Fault(LONG __arg1, CONST_STRPTR __arg2, STRPTR __arg3, LONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(BOOL, Fault,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(STRPTR,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 78, Dos    );
}

#define Fault(arg1, arg2, arg3, arg4) \
    __inline_Dos_Fault((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_PrintFault(LONG __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, PrintFault,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 79, Dos    );
}

#define PrintFault(arg1, arg2) \
    __inline_Dos_PrintFault((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_ErrorReport(LONG __arg1, LONG __arg2, IPTR __arg3, struct MsgPort * __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(BOOL, ErrorReport,
        AROS_LCA(LONG,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(IPTR,(__arg3),D3),
        AROS_LCA(struct MsgPort *,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 80, Dos    );
}

#define ErrorReport(arg1, arg2, arg3, arg4) \
    __inline_Dos_ErrorReport((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_DisplayError(CONST_STRPTR __arg1, ULONG __arg2, APTR __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, DisplayError,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        AROS_LCA(APTR,(__arg3),A1),
        struct DosLibrary *, (__DOSBase), 81, Dos    );
}

#define DisplayError(arg1, arg2, arg3) \
    __inline_Dos_DisplayError((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct CommandLineInterface * __inline_Dos_Cli(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(struct CommandLineInterface *, Cli,
        struct DosLibrary *, (__DOSBase), 82, Dos    );
}

#define Cli() \
    __inline_Dos_Cli(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct Process * __inline_Dos_CreateNewProc(const struct TagItem * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct Process *, CreateNewProc,
        AROS_LCA(const struct TagItem *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 83, Dos    );
}

#define CreateNewProc(arg1) \
    __inline_Dos_CreateNewProc((arg1), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define CreateNewProcTags(...) \
({ \
    const IPTR CreateNewProc_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateNewProc((const struct TagItem *)(CreateNewProc_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_RunCommand(BPTR __arg1, ULONG __arg2, STRPTR __arg3, ULONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(LONG, RunCommand,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(STRPTR,(__arg3),D3),
        AROS_LCA(ULONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 84, Dos    );
}

#define RunCommand(arg1, arg2, arg3, arg4) \
    __inline_Dos_RunCommand((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct MsgPort * __inline_Dos_GetConsoleTask(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(struct MsgPort *, GetConsoleTask,
        struct DosLibrary *, (__DOSBase), 85, Dos    );
}

#define GetConsoleTask() \
    __inline_Dos_GetConsoleTask(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct MsgPort * __inline_Dos_SetConsoleTask(struct MsgPort * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct MsgPort *, SetConsoleTask,
        AROS_LCA(struct MsgPort *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 86, Dos    );
}

#define SetConsoleTask(arg1) \
    __inline_Dos_SetConsoleTask((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct MsgPort * __inline_Dos_GetFileSysTask(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(struct MsgPort *, GetFileSysTask,
        struct DosLibrary *, (__DOSBase), 87, Dos    );
}

#define GetFileSysTask() \
    __inline_Dos_GetFileSysTask(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct MsgPort * __inline_Dos_SetFileSysTask(struct MsgPort * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct MsgPort *, SetFileSysTask,
        AROS_LCA(struct MsgPort *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 88, Dos    );
}

#define SetFileSysTask(arg1) \
    __inline_Dos_SetFileSysTask((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_GetArgStr(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(STRPTR, GetArgStr,
        struct DosLibrary *, (__DOSBase), 89, Dos    );
}

#define GetArgStr() \
    __inline_Dos_GetArgStr(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_SetArgStr(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(STRPTR, SetArgStr,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 90, Dos    );
}

#define SetArgStr(arg1) \
    __inline_Dos_SetArgStr((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct Process * __inline_Dos_FindCliProc(ULONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct Process *, FindCliProc,
        AROS_LCA(ULONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 91, Dos    );
}

#define FindCliProc(arg1) \
    __inline_Dos_FindCliProc((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline ULONG __inline_Dos_MaxCli(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(ULONG, MaxCli,
        struct DosLibrary *, (__DOSBase), 92, Dos    );
}

#define MaxCli() \
    __inline_Dos_MaxCli(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetCurrentDirName(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, SetCurrentDirName,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 93, Dos    );
}

#define SetCurrentDirName(arg1) \
    __inline_Dos_SetCurrentDirName((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_GetCurrentDirName(STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, GetCurrentDirName,
        AROS_LCA(STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 94, Dos    );
}

#define GetCurrentDirName(arg1, arg2) \
    __inline_Dos_GetCurrentDirName((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetProgramName(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, SetProgramName,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 95, Dos    );
}

#define SetProgramName(arg1) \
    __inline_Dos_SetProgramName((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_GetProgramName(STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, GetProgramName,
        AROS_LCA(STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 96, Dos    );
}

#define GetProgramName(arg1, arg2) \
    __inline_Dos_GetProgramName((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetPrompt(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, SetPrompt,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 97, Dos    );
}

#define SetPrompt(arg1) \
    __inline_Dos_SetPrompt((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_GetPrompt(STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, GetPrompt,
        AROS_LCA(STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 98, Dos    );
}

#define GetPrompt(arg1, arg2) \
    __inline_Dos_GetPrompt((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_SetProgramDir(BPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BPTR, SetProgramDir,
        AROS_LCA(BPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 99, Dos    );
}

#define SetProgramDir(arg1) \
    __inline_Dos_SetProgramDir((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_GetProgramDir(APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC0(BPTR, GetProgramDir,
        struct DosLibrary *, (__DOSBase), 100, Dos    );
}

#define GetProgramDir() \
    __inline_Dos_GetProgramDir(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_SystemTagList(CONST_STRPTR __arg1, const struct TagItem * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, SystemTagList,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(const struct TagItem *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 101, Dos    );
}

#define SystemTagList(arg1, arg2) \
    __inline_Dos_SystemTagList((arg1), (arg2), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define SystemTags(arg1, ...) \
({ \
    const IPTR SystemTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SystemTagList((arg1), (const struct TagItem *)(SystemTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_AssignLock(CONST_STRPTR __arg1, BPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, AssignLock,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 102, Dos    );
}

#define AssignLock(arg1, arg2) \
    __inline_Dos_AssignLock((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AssignLate(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, AssignLate,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 103, Dos    );
}

#define AssignLate(arg1, arg2) \
    __inline_Dos_AssignLate((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AssignPath(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, AssignPath,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 104, Dos    );
}

#define AssignPath(arg1, arg2) \
    __inline_Dos_AssignPath((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AssignAdd(CONST_STRPTR __arg1, BPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, AssignAdd,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 105, Dos    );
}

#define AssignAdd(arg1, arg2) \
    __inline_Dos_AssignAdd((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_RemAssignList(CONST_STRPTR __arg1, BPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, RemAssignList,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 106, Dos    );
}

#define RemAssignList(arg1, arg2) \
    __inline_Dos_RemAssignList((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DevProc * __inline_Dos_GetDeviceProc(CONST_STRPTR __arg1, struct DevProc * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(struct DevProc *, GetDeviceProc,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(struct DevProc *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 107, Dos    );
}

#define GetDeviceProc(arg1, arg2) \
    __inline_Dos_GetDeviceProc((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_FreeDeviceProc(struct DevProc * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, FreeDeviceProc,
        AROS_LCA(struct DevProc *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 108, Dos    );
}

#define FreeDeviceProc(arg1) \
    __inline_Dos_FreeDeviceProc((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosList * __inline_Dos_LockDosList(ULONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct DosList *, LockDosList,
        AROS_LCA(ULONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 109, Dos    );
}

#define LockDosList(arg1) \
    __inline_Dos_LockDosList((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_UnLockDosList(ULONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, UnLockDosList,
        AROS_LCA(ULONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 110, Dos    );
}

#define UnLockDosList(arg1) \
    __inline_Dos_UnLockDosList((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosList * __inline_Dos_AttemptLockDosList(ULONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(struct DosList *, AttemptLockDosList,
        AROS_LCA(ULONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 111, Dos    );
}

#define AttemptLockDosList(arg1) \
    __inline_Dos_AttemptLockDosList((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_RemDosEntry(struct DosList * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, RemDosEntry,
        AROS_LCA(struct DosList *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 112, Dos    );
}

#define RemDosEntry(arg1) \
    __inline_Dos_RemDosEntry((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_AddDosEntry(struct DosList * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, AddDosEntry,
        AROS_LCA(struct DosList *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 113, Dos    );
}

#define AddDosEntry(arg1) \
    __inline_Dos_AddDosEntry((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosList * __inline_Dos_FindDosEntry(struct DosList * __arg1, CONST_STRPTR __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(struct DosList *, FindDosEntry,
        AROS_LCA(struct DosList *,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 114, Dos    );
}

#define FindDosEntry(arg1, arg2, arg3) \
    __inline_Dos_FindDosEntry((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosList * __inline_Dos_NextDosEntry(struct DosList * __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(struct DosList *, NextDosEntry,
        AROS_LCA(struct DosList *,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 115, Dos    );
}

#define NextDosEntry(arg1, arg2) \
    __inline_Dos_NextDosEntry((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct DosList * __inline_Dos_MakeDosEntry(CONST_STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(struct DosList *, MakeDosEntry,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 116, Dos    );
}

#define MakeDosEntry(arg1, arg2) \
    __inline_Dos_MakeDosEntry((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_FreeDosEntry(struct DosList * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, FreeDosEntry,
        AROS_LCA(struct DosList *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 117, Dos    );
}

#define FreeDosEntry(arg1) \
    __inline_Dos_FreeDosEntry((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_IsFileSystem(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, IsFileSystem,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 118, Dos    );
}

#define IsFileSystem(arg1) \
    __inline_Dos_IsFileSystem((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_Format(CONST_STRPTR __arg1, CONST_STRPTR __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, Format,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 119, Dos    );
}

#define Format(arg1, arg2, arg3) \
    __inline_Dos_Format((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Relabel(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, Relabel,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 120, Dos    );
}

#define Relabel(arg1, arg2) \
    __inline_Dos_Relabel((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_Inhibit(CONST_STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, Inhibit,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 121, Dos    );
}

#define Inhibit(arg1, arg2) \
    __inline_Dos_Inhibit((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AddBuffers(CONST_STRPTR __arg1, LONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, AddBuffers,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 122, Dos    );
}

#define AddBuffers(arg1, arg2) \
    __inline_Dos_AddBuffers((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_CompareDates(const struct DateStamp * __arg1, const struct DateStamp * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, CompareDates,
        AROS_LCA(const struct DateStamp *,(__arg1),D1),
        AROS_LCA(const struct DateStamp *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 123, Dos    );
}

#define CompareDates(arg1, arg2) \
    __inline_Dos_CompareDates((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_DateToStr(struct DateTime * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, DateToStr,
        AROS_LCA(struct DateTime *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 124, Dos    );
}

#define DateToStr(arg1) \
    __inline_Dos_DateToStr((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_StrToDate(struct DateTime * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, StrToDate,
        AROS_LCA(struct DateTime *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 125, Dos    );
}

#define StrToDate(arg1) \
    __inline_Dos_StrToDate((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_InternalLoadSeg(BPTR __arg1, BPTR __arg2, LONG_FUNC * __arg3, LONG * __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(BPTR, InternalLoadSeg,
        AROS_LCA(BPTR,(__arg1),D0),
        AROS_LCA(BPTR,(__arg2),A0),
        AROS_LCA(LONG_FUNC *,(__arg3),A1),
        AROS_LCA(LONG *,(__arg4),A2),
        struct DosLibrary *, (__DOSBase), 126, Dos    );
}

#define InternalLoadSeg(arg1, arg2, arg3, arg4) \
    __inline_Dos_InternalLoadSeg((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_InternalUnLoadSeg(BPTR __arg1, VOID_FUNC __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, InternalUnLoadSeg,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(VOID_FUNC,(__arg2),A1),
        struct DosLibrary *, (__DOSBase), 127, Dos    );
}

#define InternalUnLoadSeg(arg1, arg2) \
    __inline_Dos_InternalUnLoadSeg((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BPTR __inline_Dos_NewLoadSeg(CONST_STRPTR __arg1, const struct TagItem * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BPTR, NewLoadSeg,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(const struct TagItem *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 128, Dos    );
}

#define NewLoadSeg(arg1, arg2) \
    __inline_Dos_NewLoadSeg((arg1), (arg2), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define NewLoadSegTags(arg1, ...) \
({ \
    const IPTR NewLoadSeg_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewLoadSeg((arg1), (const struct TagItem *)(NewLoadSeg_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AddSegment(CONST_STRPTR __arg1, BPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, AddSegment,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 129, Dos    );
}

#define AddSegment(arg1, arg2, arg3) \
    __inline_Dos_AddSegment((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct Segment * __inline_Dos_FindSegment(CONST_STRPTR __arg1, struct Segment * __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(struct Segment *, FindSegment,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(struct Segment *,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 130, Dos    );
}

#define FindSegment(arg1, arg2, arg3) \
    __inline_Dos_FindSegment((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_RemSegment(struct Segment * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, RemSegment,
        AROS_LCA(struct Segment *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 131, Dos    );
}

#define RemSegment(arg1) \
    __inline_Dos_RemSegment((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_CheckSignal(LONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, CheckSignal,
        AROS_LCA(LONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 132, Dos    );
}

#define CheckSignal(arg1) \
    __inline_Dos_CheckSignal((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct RDArgs * __inline_Dos_ReadArgs(CONST_STRPTR __arg1, SIPTR * __arg2, struct RDArgs * __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(struct RDArgs *, ReadArgs,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(SIPTR *,(__arg2),D2),
        AROS_LCA(struct RDArgs *,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 133, Dos    );
}

#define ReadArgs(arg1, arg2, arg3) \
    __inline_Dos_ReadArgs((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_FindArg(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, FindArg,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 134, Dos    );
}

#define FindArg(arg1, arg2) \
    __inline_Dos_FindArg((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ReadItem(STRPTR __arg1, LONG __arg2, struct CSource * __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, ReadItem,
        AROS_LCA(STRPTR,(__arg1),D1),
        AROS_LCA(LONG,(__arg2),D2),
        AROS_LCA(struct CSource *,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 135, Dos    );
}

#define ReadItem(arg1, arg2, arg3) \
    __inline_Dos_ReadItem((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_StrToLong(CONST_STRPTR __arg1, LONG * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, StrToLong,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(LONG *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 136, Dos    );
}

#define StrToLong(arg1, arg2) \
    __inline_Dos_StrToLong((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_MatchFirst(CONST_STRPTR __arg1, struct AnchorPath * __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, MatchFirst,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(struct AnchorPath *,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 137, Dos    );
}

#define MatchFirst(arg1, arg2) \
    __inline_Dos_MatchFirst((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_MatchNext(struct AnchorPath * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, MatchNext,
        AROS_LCA(struct AnchorPath *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 138, Dos    );
}

#define MatchNext(arg1) \
    __inline_Dos_MatchNext((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_MatchEnd(struct AnchorPath * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, MatchEnd,
        AROS_LCA(struct AnchorPath *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 139, Dos    );
}

#define MatchEnd(arg1) \
    __inline_Dos_MatchEnd((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ParsePattern(CONST_STRPTR __arg1, STRPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(LONG, ParsePattern,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 140, Dos    );
}

#define ParsePattern(arg1, arg2, arg3) \
    __inline_Dos_ParsePattern((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_MatchPattern(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(BOOL, MatchPattern,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 141, Dos    );
}

#define MatchPattern(arg1, arg2) \
    __inline_Dos_MatchPattern((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_FreeArgs(struct RDArgs * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, FreeArgs,
        AROS_LCA(struct RDArgs *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 143, Dos    );
}

#define FreeArgs(arg1) \
    __inline_Dos_FreeArgs((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_FilePart(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(STRPTR, FilePart,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 145, Dos    );
}

#define FilePart(arg1) \
    __inline_Dos_FilePart((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_PathPart(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(STRPTR, PathPart,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 146, Dos    );
}

#define PathPart(arg1) \
    __inline_Dos_PathPart((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_AddPart(STRPTR __arg1, CONST_STRPTR __arg2, ULONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC3(BOOL, AddPart,
        AROS_LCA(STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(ULONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 147, Dos    );
}

#define AddPart(arg1, arg2, arg3) \
    __inline_Dos_AddPart((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_StartNotify(struct NotifyRequest * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(BOOL, StartNotify,
        AROS_LCA(struct NotifyRequest *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 148, Dos    );
}

#define StartNotify(arg1) \
    __inline_Dos_StartNotify((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline void __inline_Dos_EndNotify(struct NotifyRequest * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    AROS_LC1NR(void, EndNotify,
        AROS_LCA(struct NotifyRequest *,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 149, Dos    );
}

#define EndNotify(arg1) \
    __inline_Dos_EndNotify((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetVar(CONST_STRPTR __arg1, CONST_STRPTR __arg2, LONG __arg3, LONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(BOOL, SetVar,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 150, Dos    );
}

#define SetVar(arg1, arg2, arg3, arg4) \
    __inline_Dos_SetVar((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_GetVar(CONST_STRPTR __arg1, STRPTR __arg2, LONG __arg3, LONG __arg4, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC4(LONG, GetVar,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        struct DosLibrary *, (__DOSBase), 151, Dos    );
}

#define GetVar(arg1, arg2, arg3, arg4) \
    __inline_Dos_GetVar((arg1), (arg2), (arg3), (arg4), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_DeleteVar(CONST_STRPTR __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, DeleteVar,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 152, Dos    );
}

#define DeleteVar(arg1, arg2) \
    __inline_Dos_DeleteVar((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline struct LocalVar * __inline_Dos_FindVar(CONST_STRPTR __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(struct LocalVar *, FindVar,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 153, Dos    );
}

#define FindVar(arg1, arg2) \
    __inline_Dos_FindVar((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline IPTR __inline_Dos_CliInit(struct DosPacket * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(IPTR, CliInit,
        AROS_LCA(struct DosPacket *,(__arg1),A0),
        struct DosLibrary *, (__DOSBase), 154, Dos    );
}

#define CliInit(arg1) \
    __inline_Dos_CliInit((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline IPTR __inline_Dos_CliInitNewcli(struct DosPacket * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(IPTR, CliInitNewcli,
        AROS_LCA(struct DosPacket *,(__arg1),A0),
        struct DosLibrary *, (__DOSBase), 155, Dos    );
}

#define CliInitNewcli(arg1) \
    __inline_Dos_CliInitNewcli((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline IPTR __inline_Dos_CliInitRun(struct DosPacket * __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(IPTR, CliInitRun,
        AROS_LCA(struct DosPacket *,(__arg1),A0),
        struct DosLibrary *, (__DOSBase), 156, Dos    );
}

#define CliInitRun(arg1) \
    __inline_Dos_CliInitRun((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_WriteChars(CONST_STRPTR __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, WriteChars,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 157, Dos    );
}

#define WriteChars(arg1, arg2) \
    __inline_Dos_WriteChars((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_PutStr(CONST_STRPTR __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC1(LONG, PutStr,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 158, Dos    );
}

#define PutStr(arg1) \
    __inline_Dos_PutStr((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_VPrintf(CONST_STRPTR __arg1, RAWARG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 36)
    return AROS_LC2(LONG, VPrintf,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(RAWARG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 159, Dos    );
}

#define VPrintf(arg1, arg2) \
    __inline_Dos_VPrintf((arg1), (arg2), __DOS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_Printf(struct DosLibrary * __DOSBase, CONST_STRPTR __arg1, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg1);
    retval = __inline_Dos_VPrintf(__arg1, AROS_SLOWSTACKFORMAT_ARG(__arg1), __DOSBase);
    AROS_SLOWSTACKFORMAT_POST(__arg1);
    return retval;
}

#define Printf(...) \
    __inline_Dos_Printf((struct DosLibrary *)__DOS_LIBBASE, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ParsePatternNoCase(CONST_STRPTR __arg1, STRPTR __arg2, LONG __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 37)
    return AROS_LC3(LONG, ParsePatternNoCase,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(STRPTR,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 161, Dos    );
}

#define ParsePatternNoCase(arg1, arg2, arg3) \
    __inline_Dos_ParsePatternNoCase((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_MatchPatternNoCase(CONST_STRPTR __arg1, CONST_STRPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 37)
    return AROS_LC2(BOOL, MatchPatternNoCase,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(CONST_STRPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 162, Dos    );
}

#define MatchPatternNoCase(arg1, arg2) \
    __inline_Dos_MatchPatternNoCase((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

static inline STRPTR __inline_Dos_DosGetString(LONG __arg1, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 37)
    return AROS_LC1(STRPTR, DosGetString,
        AROS_LCA(LONG,(__arg1),D1),
        struct DosLibrary *, (__DOSBase), 163, Dos    );
}

#define DosGetString(arg1) \
    __inline_Dos_DosGetString((arg1), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SameDevice(BPTR __arg1, BPTR __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 37)
    return AROS_LC2(BOOL, SameDevice,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(BPTR,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 164, Dos    );
}

#define SameDevice(arg1, arg2) \
    __inline_Dos_SameDevice((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__)

static inline void __inline_Dos_ExAllEnd(BPTR __arg1, struct ExAllData * __arg2, LONG __arg3, LONG __arg4, struct ExAllControl * __arg5, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 39)
    AROS_LC5NR(void, ExAllEnd,
        AROS_LCA(BPTR,(__arg1),D1),
        AROS_LCA(struct ExAllData *,(__arg2),D2),
        AROS_LCA(LONG,(__arg3),D3),
        AROS_LCA(LONG,(__arg4),D4),
        AROS_LCA(struct ExAllControl *,(__arg5),D5),
        struct DosLibrary *, (__DOSBase), 165, Dos    );
}

#define ExAllEnd(arg1, arg2, arg3, arg4, arg5) \
    __inline_Dos_ExAllEnd((arg1), (arg2), (arg3), (arg4), (arg5), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__)

static inline BOOL __inline_Dos_SetOwner(CONST_STRPTR __arg1, ULONG __arg2, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 39)
    return AROS_LC2(BOOL, SetOwner,
        AROS_LCA(CONST_STRPTR,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        struct DosLibrary *, (__DOSBase), 166, Dos    );
}

#define SetOwner(arg1, arg2) \
    __inline_Dos_SetOwner((arg1), (arg2), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (50 <= __DOS_LIBAPI__)

static inline LONG __inline_Dos_ScanVars(struct Hook * __arg1, ULONG __arg2, APTR __arg3, APTR __DOSBase)
{
    AROS_LIBREQ(DOSBase, 50)
    return AROS_LC3(LONG, ScanVars,
        AROS_LCA(struct Hook *,(__arg1),D1),
        AROS_LCA(ULONG,(__arg2),D2),
        AROS_LCA(APTR,(__arg3),D3),
        struct DosLibrary *, (__DOSBase), 169, Dos    );
}

#define ScanVars(arg1, arg2, arg3) \
    __inline_Dos_ScanVars((arg1), (arg2), (arg3), __DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (50 <= __DOS_LIBAPI__) */

#endif /* INLINE_DOS_H*/
