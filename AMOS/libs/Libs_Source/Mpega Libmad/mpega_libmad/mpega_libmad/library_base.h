#ifndef LIBRARY_BASE_H
#define LIBRARY_BASE_H

#define __USE_SYSBASE
#include <proto/exec.h>
#include <exec/execbase.h>
#include <proto/dos.h>

#ifdef BUILD_POWERUP
struct StartupData
{
	APTR ElfObject;
};

struct CallPPCData
{
	ULONG Type;
	ULONG PPCLVO;
	ULONG Args[3];
	ULONG Return;
};

#define MSGTYPE_INIT 1
#define MSGTYPE_REMOVE 2
#define MSGTYPE_CALL 3
#define MSGTYPE_HELLO 4
#define MSGTYPE_GOODBYE 5
#else
struct MyStackSwapStruct
{
	struct StackSwapStruct stack;
	ULONG Return;
	ULONG Args[8];
};

#define REQ_STACKSIZE 8192	/* Must be 4-byte aligned! */
#endif

struct PrivateBase {
	struct Library pv_Lib;
	UWORD pv_Pad;

	struct ExecBase *pv_SysBase;
	struct DosLibrary *pv_DOSBase;
	BPTR pv_SegList;

#ifdef BUILD_POWERUP
	struct Library *pv_PPCLibBase;
	APTR pv_ElfObject;
	APTR pv_LibFuncTable;
	APTR pv_ReplyPort;
	APTR pv_StartupMsg;
	struct StartupData *pv_StartupData;
	APTR pv_Task;
	APTR pv_PPCPort;
	APTR pv_CallPPCMsg;
	struct CallPPCData *pv_CallPPCData;
	struct PrivateBase *ParentBase;
#else
	struct MyStackSwapStruct stackswap;
#endif
};

#endif
