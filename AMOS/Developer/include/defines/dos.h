#ifndef DEFINES_DOS_H
#define DEFINES_DOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/dos/dos.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for dos
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DOS_LIBBASE)
#    define __DOS_LIBBASE DOSBase
#endif

__BEGIN_DECLS


#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Open_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(BPTR, Open, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 5, Dos);\
})

#define Open(arg1, arg2) \
    __Open_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Close_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BOOL, Close, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 6, Dos);\
})

#define Close(arg1) \
    __Close_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Read_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC3(LONG, Read, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(APTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 7, Dos);\
})

#define Read(arg1, arg2, arg3) \
    __Read_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Write_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC3(LONG, Write, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(CONST_APTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 8, Dos);\
})

#define Write(arg1, arg2, arg3) \
    __Write_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Input_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC0(BPTR, Input, \
        struct DosLibrary *, (__DOSBase), 9, Dos);\
})

#define Input() \
    __Input_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Output_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC0(BPTR, Output, \
        struct DosLibrary *, (__DOSBase), 10, Dos);\
})

#define Output() \
    __Output_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Seek_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC3(LONG, Seek, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 11, Dos);\
})

#define Seek(arg1, arg2, arg3) \
    __Seek_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __DeleteFile_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BOOL, DeleteFile, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 12, Dos);\
})

#define DeleteFile(arg1) \
    __DeleteFile_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Rename_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, Rename, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 13, Dos);\
})

#define Rename(arg1, arg2) \
    __Rename_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Lock_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(BPTR, Lock, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 14, Dos);\
})

#define Lock(arg1, arg2) \
    __Lock_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __UnLock_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BOOL, UnLock, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 15, Dos);\
})

#define UnLock(arg1) \
    __UnLock_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __DupLock_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BPTR, DupLock, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 16, Dos);\
})

#define DupLock(arg1) \
    __DupLock_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Examine_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, Examine, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct FileInfoBlock*,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 17, Dos);\
})

#define Examine(arg1, arg2) \
    __Examine_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __ExNext_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, ExNext, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct FileInfoBlock*,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 18, Dos);\
})

#define ExNext(arg1, arg2) \
    __ExNext_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Info_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, Info, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct InfoData*,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 19, Dos);\
})

#define Info(arg1, arg2) \
    __Info_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __CreateDir_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BPTR, CreateDir, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 20, Dos);\
})

#define CreateDir(arg1) \
    __CreateDir_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __CurrentDir_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BPTR, CurrentDir, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 21, Dos);\
})

#define CurrentDir(arg1) \
    __CurrentDir_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __IoErr_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC0(SIPTR, IoErr, \
        struct DosLibrary *, (__DOSBase), 22, Dos);\
})

#define IoErr() \
    __IoErr_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __CreateProc_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC4(struct MsgPort*, CreateProc, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(BPTR,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 23, Dos);\
})

#define CreateProc(arg1, arg2, arg3, arg4) \
    __CreateProc_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Exit_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1NR(void, Exit, \
                  AROS_LCA(LONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 24, Dos);\
})

#define Exit(arg1) \
    __Exit_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __LoadSeg_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BPTR, LoadSeg, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 25, Dos);\
})

#define LoadSeg(arg1) \
    __LoadSeg_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __UnLoadSeg_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BOOL, UnLoadSeg, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 26, Dos);\
})

#define UnLoadSeg(arg1) \
    __UnLoadSeg_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __DeviceProc_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(struct MsgPort *, DeviceProc, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 29, Dos);\
})

#define DeviceProc(arg1) \
    __DeviceProc_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __SetComment_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, SetComment, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 30, Dos);\
})

#define SetComment(arg1, arg2) \
    __SetComment_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __SetProtection_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, SetProtection, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 31, Dos);\
})

#define SetProtection(arg1, arg2) \
    __SetProtection_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __DateStamp_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(struct DateStamp *, DateStamp, \
                  AROS_LCA(struct DateStamp *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 32, Dos);\
})

#define DateStamp(arg1) \
    __DateStamp_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Delay_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1NR(void, Delay, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 33, Dos);\
})

#define Delay(arg1) \
    __Delay_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __WaitForChar_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC2(LONG, WaitForChar, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 34, Dos);\
})

#define WaitForChar(arg1, arg2) \
    __WaitForChar_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __ParentDir_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(BPTR, ParentDir, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 35, Dos);\
})

#define ParentDir(arg1) \
    __ParentDir_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __IsInteractive_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC1(LONG, IsInteractive, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 36, Dos);\
})

#define IsInteractive(arg1) \
    __IsInteractive_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__)

#define __Execute_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,0)\
        AROS_LC3(BOOL, Execute, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
                  AROS_LCA(BPTR,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 37, Dos);\
})

#define Execute(arg1, arg2, arg3) \
    __Execute_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (0 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AllocDosObject_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(APTR, AllocDosObject, \
                  AROS_LCA(ULONG,(__arg1),D1), \
                  AROS_LCA(struct TagItem *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 38, Dos);\
})

#define AllocDosObject(arg1, arg2) \
    __AllocDosObject_WB(__DOS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define AllocDosObjectTags(arg1, ...) \
({ \
    const IPTR AllocDosObject_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    AllocDosObject((arg1), (struct TagItem *)(AllocDosObject_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FreeDosObject_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2NR(void, FreeDosObject, \
                  AROS_LCA(ULONG,(__arg1),D1), \
                  AROS_LCA(APTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 39, Dos);\
})

#define FreeDosObject(arg1, arg2) \
    __FreeDosObject_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __DoPkt_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC7(SIPTR, DoPkt, \
                  AROS_LCA(struct MsgPort*,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(SIPTR,(__arg3),D3), \
                  AROS_LCA(SIPTR,(__arg4),D4), \
                  AROS_LCA(SIPTR,(__arg5),D5), \
                  AROS_LCA(SIPTR,(__arg6),D6), \
                  AROS_LCA(SIPTR,(__arg7),D7), \
        struct DosLibrary *, (__DOSBase), 40, Dos);\
})

#define DoPkt(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __DoPkt_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SendPkt_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3NR(void, SendPkt, \
                  AROS_LCA(struct DosPacket *,(__arg1),D1), \
                  AROS_LCA(struct MsgPort *,(__arg2),D2), \
                  AROS_LCA(struct MsgPort *,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 41, Dos);\
})

#define SendPkt(arg1, arg2, arg3) \
    __SendPkt_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __WaitPkt_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(struct DosPacket *, WaitPkt, \
        struct DosLibrary *, (__DOSBase), 42, Dos);\
})

#define WaitPkt() \
    __WaitPkt_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ReplyPkt_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3NR(void, ReplyPkt, \
                  AROS_LCA(struct DosPacket *,(__arg1),D1), \
                  AROS_LCA(SIPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 43, Dos);\
})

#define ReplyPkt(arg1, arg2, arg3) \
    __ReplyPkt_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AbortPkt_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2NR(void, AbortPkt, \
                  AROS_LCA(struct MsgPort *,(__arg1),D1), \
                  AROS_LCA(struct DosPacket *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 44, Dos);\
})

#define AbortPkt(arg1, arg2) \
    __AbortPkt_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __LockRecord_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC5(BOOL, LockRecord, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
                  AROS_LCA(ULONG,(__arg4),D4), \
                  AROS_LCA(ULONG,(__arg5),D5), \
        struct DosLibrary *, (__DOSBase), 45, Dos);\
})

#define LockRecord(arg1, arg2, arg3, arg4, arg5) \
    __LockRecord_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __LockRecords_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, LockRecords, \
                  AROS_LCA(struct RecordLock *,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 46, Dos);\
})

#define LockRecords(arg1, arg2) \
    __LockRecords_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __UnLockRecord_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, UnLockRecord, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 47, Dos);\
})

#define UnLockRecord(arg1, arg2, arg3) \
    __UnLockRecord_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __UnLockRecords_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, UnLockRecords, \
                  AROS_LCA(struct RecordLock *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 48, Dos);\
})

#define UnLockRecords(arg1) \
    __UnLockRecords_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SelectInput_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, SelectInput, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 49, Dos);\
})

#define SelectInput(arg1) \
    __SelectInput_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SelectOutput_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, SelectOutput, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 50, Dos);\
})

#define SelectOutput(arg1) \
    __SelectOutput_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FGetC_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, FGetC, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 51, Dos);\
})

#define FGetC(arg1) \
    __FGetC_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FPutC_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, FPutC, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 52, Dos);\
})

#define FPutC(arg1, arg2) \
    __FPutC_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __UnGetC_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, UnGetC, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 53, Dos);\
})

#define UnGetC(arg1, arg2) \
    __UnGetC_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FRead_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(LONG, FRead, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(APTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
                  AROS_LCA(ULONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 54, Dos);\
})

#define FRead(arg1, arg2, arg3, arg4) \
    __FRead_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FWrite_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(LONG, FWrite, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(CONST_APTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
                  AROS_LCA(ULONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 55, Dos);\
})

#define FWrite(arg1, arg2, arg3, arg4) \
    __FWrite_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FGets_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(STRPTR, FGets, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 56, Dos);\
})

#define FGets(arg1, arg2, arg3) \
    __FGets_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FPuts_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, FPuts, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 57, Dos);\
})

#define FPuts(arg1, arg2) \
    __FPuts_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __VFWritef_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, VFWritef, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(RAWARG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 58, Dos);\
})

#define VFWritef(arg1, arg2, arg3) \
    __VFWritef_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_FWritef(struct DosLibrary * __DOSBase, BPTR __arg1, CONST_STRPTR __arg2, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg2);
    retval = __VFWritef_WB(__DOSBase, __arg1, __arg2, AROS_SLOWSTACKFORMAT_ARG(__arg2));
    AROS_SLOWSTACKFORMAT_POST(__arg2);
    return retval;
}

#define FWritef(arg1, ...) \
    __inline_Dos_FWritef((struct DosLibrary *)__DOS_LIBBASE, (arg1), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __VFPrintf_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, VFPrintf, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(RAWARG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 59, Dos);\
})

#define VFPrintf(arg1, arg2, arg3) \
    __VFPrintf_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_FPrintf(struct DosLibrary * __DOSBase, BPTR __arg1, CONST_STRPTR __arg2, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg2);
    retval = __VFPrintf_WB(__DOSBase, __arg1, __arg2, AROS_SLOWSTACKFORMAT_ARG(__arg2));
    AROS_SLOWSTACKFORMAT_POST(__arg2);
    return retval;
}

#define FPrintf(arg1, ...) \
    __inline_Dos_FPrintf((struct DosLibrary *)__DOS_LIBBASE, (arg1), __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Flush_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, Flush, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 60, Dos);\
})

#define Flush(arg1) \
    __Flush_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetVBuf_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(LONG, SetVBuf, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 61, Dos);\
})

#define SetVBuf(arg1, arg2, arg3, arg4) \
    __SetVBuf_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __DupLockFromFH_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, DupLockFromFH, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 62, Dos);\
})

#define DupLockFromFH(arg1) \
    __DupLockFromFH_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __OpenFromLock_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, OpenFromLock, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 63, Dos);\
})

#define OpenFromLock(arg1) \
    __OpenFromLock_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ParentOfFH_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, ParentOfFH, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 64, Dos);\
})

#define ParentOfFH(arg1) \
    __ParentOfFH_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ExamineFH_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, ExamineFH, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct FileInfoBlock*,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 65, Dos);\
})

#define ExamineFH(arg1, arg2) \
    __ExamineFH_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetFileDate_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, SetFileDate, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(const struct DateStamp *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 66, Dos);\
})

#define SetFileDate(arg1, arg2) \
    __SetFileDate_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __NameFromLock_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, NameFromLock, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 67, Dos);\
})

#define NameFromLock(arg1, arg2, arg3) \
    __NameFromLock_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __NameFromFH_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, NameFromFH, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 68, Dos);\
})

#define NameFromFH(arg1, arg2, arg3) \
    __NameFromFH_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SplitName_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC5(LONG, SplitName, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(STRPTR,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
                  AROS_LCA(LONG,(__arg5),D5), \
        struct DosLibrary *, (__DOSBase), 69, Dos);\
})

#define SplitName(arg1, arg2, arg3, arg4, arg5) \
    __SplitName_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SameLock_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, SameLock, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 70, Dos);\
})

#define SameLock(arg1, arg2) \
    __SameLock_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetMode_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, SetMode, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 71, Dos);\
})

#define SetMode(arg1, arg2) \
    __SetMode_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ExAll_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC5(BOOL, ExAll, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct ExAllData *,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
                  AROS_LCA(struct ExAllControl *,(__arg5),D5), \
        struct DosLibrary *, (__DOSBase), 72, Dos);\
})

#define ExAll(arg1, arg2, arg3, arg4, arg5) \
    __ExAll_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ReadLink_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC5(LONG, ReadLink, \
                  AROS_LCA(struct MsgPort *,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
                  AROS_LCA(CONST_STRPTR,(__arg3),D3), \
                  AROS_LCA(STRPTR,(__arg4),D4), \
                  AROS_LCA(ULONG,(__arg5),D5), \
        struct DosLibrary *, (__DOSBase), 73, Dos);\
})

#define ReadLink(arg1, arg2, arg3, arg4, arg5) \
    __ReadLink_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MakeLink_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, MakeLink, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(SIPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 74, Dos);\
})

#define MakeLink(arg1, arg2, arg3) \
    __MakeLink_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ChangeMode_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, ChangeMode, \
                  AROS_LCA(ULONG,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 75, Dos);\
})

#define ChangeMode(arg1, arg2, arg3) \
    __ChangeMode_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetFileSize_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, SetFileSize, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 76, Dos);\
})

#define SetFileSize(arg1, arg2, arg3) \
    __SetFileSize_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetIoErr_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(SIPTR, SetIoErr, \
                  AROS_LCA(SIPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 77, Dos);\
})

#define SetIoErr(arg1) \
    __SetIoErr_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Fault_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(BOOL, Fault, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(STRPTR,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 78, Dos);\
})

#define Fault(arg1, arg2, arg3, arg4) \
    __Fault_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __PrintFault_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, PrintFault, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 79, Dos);\
})

#define PrintFault(arg1, arg2) \
    __PrintFault_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ErrorReport_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(BOOL, ErrorReport, \
                  AROS_LCA(LONG,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(IPTR,(__arg3),D3), \
                  AROS_LCA(struct MsgPort *,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 80, Dos);\
})

#define ErrorReport(arg1, arg2, arg3, arg4) \
    __ErrorReport_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __DisplayError_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, DisplayError, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
                  AROS_LCA(ULONG,(__arg2),D0), \
                  AROS_LCA(APTR,(__arg3),A1), \
        struct DosLibrary *, (__DOSBase), 81, Dos);\
})

#define DisplayError(arg1, arg2, arg3) \
    __DisplayError_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Cli_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(struct CommandLineInterface *, Cli, \
        struct DosLibrary *, (__DOSBase), 82, Dos);\
})

#define Cli() \
    __Cli_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CreateNewProc_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct Process *, CreateNewProc, \
                  AROS_LCA(const struct TagItem *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 83, Dos);\
})

#define CreateNewProc(arg1) \
    __CreateNewProc_WB(__DOS_LIBBASE, (arg1))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define CreateNewProcTags(...) \
({ \
    const IPTR CreateNewProc_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    CreateNewProc((const struct TagItem *)(CreateNewProc_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __RunCommand_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(LONG, RunCommand, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(STRPTR,(__arg3),D3), \
                  AROS_LCA(ULONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 84, Dos);\
})

#define RunCommand(arg1, arg2, arg3, arg4) \
    __RunCommand_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetConsoleTask_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(struct MsgPort *, GetConsoleTask, \
        struct DosLibrary *, (__DOSBase), 85, Dos);\
})

#define GetConsoleTask() \
    __GetConsoleTask_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetConsoleTask_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct MsgPort *, SetConsoleTask, \
                  AROS_LCA(struct MsgPort *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 86, Dos);\
})

#define SetConsoleTask(arg1) \
    __SetConsoleTask_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetFileSysTask_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(struct MsgPort *, GetFileSysTask, \
        struct DosLibrary *, (__DOSBase), 87, Dos);\
})

#define GetFileSysTask() \
    __GetFileSysTask_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetFileSysTask_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct MsgPort *, SetFileSysTask, \
                  AROS_LCA(struct MsgPort *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 88, Dos);\
})

#define SetFileSysTask(arg1) \
    __SetFileSysTask_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetArgStr_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(STRPTR, GetArgStr, \
        struct DosLibrary *, (__DOSBase), 89, Dos);\
})

#define GetArgStr() \
    __GetArgStr_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetArgStr_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(STRPTR, SetArgStr, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 90, Dos);\
})

#define SetArgStr(arg1) \
    __SetArgStr_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FindCliProc_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct Process *, FindCliProc, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 91, Dos);\
})

#define FindCliProc(arg1) \
    __FindCliProc_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MaxCli_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(ULONG, MaxCli, \
        struct DosLibrary *, (__DOSBase), 92, Dos);\
})

#define MaxCli() \
    __MaxCli_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetCurrentDirName_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, SetCurrentDirName, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 93, Dos);\
})

#define SetCurrentDirName(arg1) \
    __SetCurrentDirName_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetCurrentDirName_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, GetCurrentDirName, \
                  AROS_LCA(STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 94, Dos);\
})

#define GetCurrentDirName(arg1, arg2) \
    __GetCurrentDirName_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetProgramName_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, SetProgramName, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 95, Dos);\
})

#define SetProgramName(arg1) \
    __SetProgramName_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetProgramName_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, GetProgramName, \
                  AROS_LCA(STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 96, Dos);\
})

#define GetProgramName(arg1, arg2) \
    __GetProgramName_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetPrompt_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, SetPrompt, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 97, Dos);\
})

#define SetPrompt(arg1) \
    __SetPrompt_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetPrompt_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, GetPrompt, \
                  AROS_LCA(STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 98, Dos);\
})

#define GetPrompt(arg1, arg2) \
    __GetPrompt_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetProgramDir_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BPTR, SetProgramDir, \
                  AROS_LCA(BPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 99, Dos);\
})

#define SetProgramDir(arg1) \
    __SetProgramDir_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetProgramDir_WB(__DOSBase) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC0(BPTR, GetProgramDir, \
        struct DosLibrary *, (__DOSBase), 100, Dos);\
})

#define GetProgramDir() \
    __GetProgramDir_WB(__DOS_LIBBASE)

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SystemTagList_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, SystemTagList, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(const struct TagItem *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 101, Dos);\
})

#define SystemTagList(arg1, arg2) \
    __SystemTagList_WB(__DOS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define SystemTags(arg1, ...) \
({ \
    const IPTR SystemTagList_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    SystemTagList((arg1), (const struct TagItem *)(SystemTagList_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AssignLock_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, AssignLock, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 102, Dos);\
})

#define AssignLock(arg1, arg2) \
    __AssignLock_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AssignLate_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, AssignLate, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 103, Dos);\
})

#define AssignLate(arg1, arg2) \
    __AssignLate_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AssignPath_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, AssignPath, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 104, Dos);\
})

#define AssignPath(arg1, arg2) \
    __AssignPath_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AssignAdd_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, AssignAdd, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 105, Dos);\
})

#define AssignAdd(arg1, arg2) \
    __AssignAdd_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __RemAssignList_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, RemAssignList, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 106, Dos);\
})

#define RemAssignList(arg1, arg2) \
    __RemAssignList_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetDeviceProc_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(struct DevProc *, GetDeviceProc, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(struct DevProc *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 107, Dos);\
})

#define GetDeviceProc(arg1, arg2) \
    __GetDeviceProc_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FreeDeviceProc_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, FreeDeviceProc, \
                  AROS_LCA(struct DevProc *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 108, Dos);\
})

#define FreeDeviceProc(arg1) \
    __FreeDeviceProc_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __LockDosList_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct DosList *, LockDosList, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 109, Dos);\
})

#define LockDosList(arg1) \
    __LockDosList_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __UnLockDosList_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, UnLockDosList, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 110, Dos);\
})

#define UnLockDosList(arg1) \
    __UnLockDosList_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AttemptLockDosList_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(struct DosList *, AttemptLockDosList, \
                  AROS_LCA(ULONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 111, Dos);\
})

#define AttemptLockDosList(arg1) \
    __AttemptLockDosList_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __RemDosEntry_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, RemDosEntry, \
                  AROS_LCA(struct DosList *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 112, Dos);\
})

#define RemDosEntry(arg1) \
    __RemDosEntry_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AddDosEntry_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, AddDosEntry, \
                  AROS_LCA(struct DosList *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 113, Dos);\
})

#define AddDosEntry(arg1) \
    __AddDosEntry_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FindDosEntry_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(struct DosList *, FindDosEntry, \
                  AROS_LCA(struct DosList *,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 114, Dos);\
})

#define FindDosEntry(arg1, arg2, arg3) \
    __FindDosEntry_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __NextDosEntry_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(struct DosList *, NextDosEntry, \
                  AROS_LCA(struct DosList *,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 115, Dos);\
})

#define NextDosEntry(arg1, arg2) \
    __NextDosEntry_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MakeDosEntry_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(struct DosList *, MakeDosEntry, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 116, Dos);\
})

#define MakeDosEntry(arg1, arg2) \
    __MakeDosEntry_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FreeDosEntry_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, FreeDosEntry, \
                  AROS_LCA(struct DosList *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 117, Dos);\
})

#define FreeDosEntry(arg1) \
    __FreeDosEntry_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __IsFileSystem_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, IsFileSystem, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 118, Dos);\
})

#define IsFileSystem(arg1) \
    __IsFileSystem_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Format_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, Format, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 119, Dos);\
})

#define Format(arg1, arg2, arg3) \
    __Format_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Relabel_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, Relabel, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 120, Dos);\
})

#define Relabel(arg1, arg2) \
    __Relabel_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __Inhibit_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, Inhibit, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 121, Dos);\
})

#define Inhibit(arg1, arg2) \
    __Inhibit_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AddBuffers_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, AddBuffers, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 122, Dos);\
})

#define AddBuffers(arg1, arg2) \
    __AddBuffers_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CompareDates_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, CompareDates, \
                  AROS_LCA(const struct DateStamp *,(__arg1),D1), \
                  AROS_LCA(const struct DateStamp *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 123, Dos);\
})

#define CompareDates(arg1, arg2) \
    __CompareDates_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __DateToStr_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, DateToStr, \
                  AROS_LCA(struct DateTime *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 124, Dos);\
})

#define DateToStr(arg1) \
    __DateToStr_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __StrToDate_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, StrToDate, \
                  AROS_LCA(struct DateTime *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 125, Dos);\
})

#define StrToDate(arg1) \
    __StrToDate_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __InternalLoadSeg_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(BPTR, InternalLoadSeg, \
                  AROS_LCA(BPTR,(__arg1),D0), \
                  AROS_LCA(BPTR,(__arg2),A0), \
                  AROS_LCA(LONG_FUNC *,(__arg3),A1), \
                  AROS_LCA(LONG *,(__arg4),A2), \
        struct DosLibrary *, (__DOSBase), 126, Dos);\
})

#define InternalLoadSeg(arg1, arg2, arg3, arg4) \
    __InternalLoadSeg_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __InternalUnLoadSeg_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, InternalUnLoadSeg, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(VOID_FUNC,(__arg2),A1), \
        struct DosLibrary *, (__DOSBase), 127, Dos);\
})

#define InternalUnLoadSeg(arg1, arg2) \
    __InternalUnLoadSeg_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __NewLoadSeg_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BPTR, NewLoadSeg, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(const struct TagItem *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 128, Dos);\
})

#define NewLoadSeg(arg1, arg2) \
    __NewLoadSeg_WB(__DOS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
#define NewLoadSegTags(arg1, ...) \
({ \
    const IPTR NewLoadSeg_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    NewLoadSeg((arg1), (const struct TagItem *)(NewLoadSeg_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AddSegment_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, AddSegment, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 129, Dos);\
})

#define AddSegment(arg1, arg2, arg3) \
    __AddSegment_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FindSegment_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(struct Segment *, FindSegment, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(struct Segment *,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 130, Dos);\
})

#define FindSegment(arg1, arg2, arg3) \
    __FindSegment_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __RemSegment_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, RemSegment, \
                  AROS_LCA(struct Segment *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 131, Dos);\
})

#define RemSegment(arg1) \
    __RemSegment_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CheckSignal_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, CheckSignal, \
                  AROS_LCA(LONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 132, Dos);\
})

#define CheckSignal(arg1) \
    __CheckSignal_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ReadArgs_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(struct RDArgs *, ReadArgs, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(SIPTR *,(__arg2),D2), \
                  AROS_LCA(struct RDArgs *,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 133, Dos);\
})

#define ReadArgs(arg1, arg2, arg3) \
    __ReadArgs_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FindArg_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, FindArg, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 134, Dos);\
})

#define FindArg(arg1, arg2) \
    __FindArg_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ReadItem_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, ReadItem, \
                  AROS_LCA(STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG,(__arg2),D2), \
                  AROS_LCA(struct CSource *,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 135, Dos);\
})

#define ReadItem(arg1, arg2, arg3) \
    __ReadItem_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __StrToLong_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, StrToLong, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(LONG *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 136, Dos);\
})

#define StrToLong(arg1, arg2) \
    __StrToLong_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MatchFirst_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, MatchFirst, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(struct AnchorPath *,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 137, Dos);\
})

#define MatchFirst(arg1, arg2) \
    __MatchFirst_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MatchNext_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, MatchNext, \
                  AROS_LCA(struct AnchorPath *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 138, Dos);\
})

#define MatchNext(arg1) \
    __MatchNext_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MatchEnd_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, MatchEnd, \
                  AROS_LCA(struct AnchorPath *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 139, Dos);\
})

#define MatchEnd(arg1) \
    __MatchEnd_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __ParsePattern_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(LONG, ParsePattern, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 140, Dos);\
})

#define ParsePattern(arg1, arg2, arg3) \
    __ParsePattern_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __MatchPattern_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(BOOL, MatchPattern, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 141, Dos);\
})

#define MatchPattern(arg1, arg2) \
    __MatchPattern_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FreeArgs_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, FreeArgs, \
                  AROS_LCA(struct RDArgs *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 143, Dos);\
})

#define FreeArgs(arg1) \
    __FreeArgs_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FilePart_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(STRPTR, FilePart, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 145, Dos);\
})

#define FilePart(arg1) \
    __FilePart_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __PathPart_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(STRPTR, PathPart, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 146, Dos);\
})

#define PathPart(arg1) \
    __PathPart_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __AddPart_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC3(BOOL, AddPart, \
                  AROS_LCA(STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(ULONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 147, Dos);\
})

#define AddPart(arg1, arg2, arg3) \
    __AddPart_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __StartNotify_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(BOOL, StartNotify, \
                  AROS_LCA(struct NotifyRequest *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 148, Dos);\
})

#define StartNotify(arg1) \
    __StartNotify_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __EndNotify_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1NR(void, EndNotify, \
                  AROS_LCA(struct NotifyRequest *,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 149, Dos);\
})

#define EndNotify(arg1) \
    __EndNotify_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __SetVar_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(BOOL, SetVar, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 150, Dos);\
})

#define SetVar(arg1, arg2, arg3, arg4) \
    __SetVar_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __GetVar_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC4(LONG, GetVar, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
        struct DosLibrary *, (__DOSBase), 151, Dos);\
})

#define GetVar(arg1, arg2, arg3, arg4) \
    __GetVar_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __DeleteVar_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, DeleteVar, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 152, Dos);\
})

#define DeleteVar(arg1, arg2) \
    __DeleteVar_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __FindVar_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(struct LocalVar *, FindVar, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 153, Dos);\
})

#define FindVar(arg1, arg2) \
    __FindVar_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CliInit_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(IPTR, CliInit, \
                  AROS_LCA(struct DosPacket *,(__arg1),A0), \
        struct DosLibrary *, (__DOSBase), 154, Dos);\
})

#define CliInit(arg1) \
    __CliInit_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CliInitNewcli_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(IPTR, CliInitNewcli, \
                  AROS_LCA(struct DosPacket *,(__arg1),A0), \
        struct DosLibrary *, (__DOSBase), 155, Dos);\
})

#define CliInitNewcli(arg1) \
    __CliInitNewcli_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __CliInitRun_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(IPTR, CliInitRun, \
                  AROS_LCA(struct DosPacket *,(__arg1),A0), \
        struct DosLibrary *, (__DOSBase), 156, Dos);\
})

#define CliInitRun(arg1) \
    __CliInitRun_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __WriteChars_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, WriteChars, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 157, Dos);\
})

#define WriteChars(arg1, arg2) \
    __WriteChars_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __PutStr_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC1(LONG, PutStr, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 158, Dos);\
})

#define PutStr(arg1) \
    __PutStr_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__)

#define __VPrintf_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,36)\
        AROS_LC2(LONG, VPrintf, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(RAWARG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 159, Dos);\
})

#define VPrintf(arg1, arg2) \
    __VPrintf_WB(__DOS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(DOS_NO_INLINE_STDARG)
static inline LONG __inline_Dos_Printf(struct DosLibrary * __DOSBase, CONST_STRPTR __arg1, ...)
{
    LONG retval;

    AROS_SLOWSTACKFORMAT_PRE(__arg1);
    retval = __VPrintf_WB(__DOSBase, __arg1, AROS_SLOWSTACKFORMAT_ARG(__arg1));
    AROS_SLOWSTACKFORMAT_POST(__arg1);
    return retval;
}

#define Printf(...) \
    __inline_Dos_Printf((struct DosLibrary *)__DOS_LIBBASE, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__DOS_LIBAPI__) || (36 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

#define __ParsePatternNoCase_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,37)\
        AROS_LC3(LONG, ParsePatternNoCase, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(STRPTR,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 161, Dos);\
})

#define ParsePatternNoCase(arg1, arg2, arg3) \
    __ParsePatternNoCase_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

#define __MatchPatternNoCase_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,37)\
        AROS_LC2(BOOL, MatchPatternNoCase, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(CONST_STRPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 162, Dos);\
})

#define MatchPatternNoCase(arg1, arg2) \
    __MatchPatternNoCase_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

#define __DosGetString_WB(__DOSBase, __arg1) ({\
        AROS_LIBREQ(DOSBase,37)\
        AROS_LC1(STRPTR, DosGetString, \
                  AROS_LCA(LONG,(__arg1),D1), \
        struct DosLibrary *, (__DOSBase), 163, Dos);\
})

#define DosGetString(arg1) \
    __DosGetString_WB(__DOS_LIBBASE, (arg1))

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__)

#define __SameDevice_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,37)\
        AROS_LC2(BOOL, SameDevice, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(BPTR,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 164, Dos);\
})

#define SameDevice(arg1, arg2) \
    __SameDevice_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (37 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__)

#define __ExAllEnd_WB(__DOSBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DOSBase,39)\
        AROS_LC5NR(void, ExAllEnd, \
                  AROS_LCA(BPTR,(__arg1),D1), \
                  AROS_LCA(struct ExAllData *,(__arg2),D2), \
                  AROS_LCA(LONG,(__arg3),D3), \
                  AROS_LCA(LONG,(__arg4),D4), \
                  AROS_LCA(struct ExAllControl *,(__arg5),D5), \
        struct DosLibrary *, (__DOSBase), 165, Dos);\
})

#define ExAllEnd(arg1, arg2, arg3, arg4, arg5) \
    __ExAllEnd_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__)

#define __SetOwner_WB(__DOSBase, __arg1, __arg2) ({\
        AROS_LIBREQ(DOSBase,39)\
        AROS_LC2(BOOL, SetOwner, \
                  AROS_LCA(CONST_STRPTR,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
        struct DosLibrary *, (__DOSBase), 166, Dos);\
})

#define SetOwner(arg1, arg2) \
    __SetOwner_WB(__DOS_LIBBASE, (arg1), (arg2))

#endif /* !defined(__DOS_LIBAPI__) || (39 <= __DOS_LIBAPI__) */

#if !defined(__DOS_LIBAPI__) || (50 <= __DOS_LIBAPI__)

#define __ScanVars_WB(__DOSBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(DOSBase,50)\
        AROS_LC3(LONG, ScanVars, \
                  AROS_LCA(struct Hook *,(__arg1),D1), \
                  AROS_LCA(ULONG,(__arg2),D2), \
                  AROS_LCA(APTR,(__arg3),D3), \
        struct DosLibrary *, (__DOSBase), 169, Dos);\
})

#define ScanVars(arg1, arg2, arg3) \
    __ScanVars_WB(__DOS_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__DOS_LIBAPI__) || (50 <= __DOS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DOS_H*/
