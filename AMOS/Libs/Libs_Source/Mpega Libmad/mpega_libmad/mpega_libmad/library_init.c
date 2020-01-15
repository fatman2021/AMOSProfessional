#include "library_init.h"

#include <exec/memory.h>
#include <exec/resident.h>
#include <exec/initializers.h>

#include "wrap_mpega.h"

#ifdef BUILD_POWERUP
#include <proto/ppc.h>
#include "support_pup.h"
#elif defined(BUILD_WARPUP)
#include <powerpc/powerpc.h>
#include <proto/powerpc.h>
#include "support.h"
#else
#include "support.h"
#endif

#ifdef BUILD_WARPUP
#define CallPPCFunc(func, p1, p2, p3) \
({struct PPCArgs args; \
	args.PP_Flags = PPF_LINEAR; \
	args.PP_Stack = NULL; \
	args.PP_StackSize = 0; \
	args.PP_Code = (APTR)func; \
	args.PP_Offset = 0; \
	args.PP_Regs[0] = (ULONG)p1; \
	args.PP_Regs[1] = (ULONG)p2; \
	args.PP_Regs[2] = (ULONG)p3; \
	RunPPC(&args); \
	args.PP_Regs[0]; \
})

struct MPEGABase
{
	struct Library lib;
};

#pragma libbase MPEGABase

const char LibVersionString[] = "$VER: " LIB_ID;
const char LibNameString[] = LIB_NAME;

void INIT_3_InitLibraries(__REGA6(struct Library *base))
{
	/* At least v15.0 is needed for PPF_LINEAR */
	if (PowerPCBase->lib_Version >= 15) {
		if (CallPPCFunc(InitSupport, 0, 0, 0))
			return;
	}
	abortLibInit();
}

void EXIT_3_InitLibraries(__REGA6(struct Library *base))
{
	if (PowerPCBase->lib_Version >= 15)
		CallPPCFunc(RemoveSupport, 0, 0, 0);
}

#else	/* BUILD_WARPUP */

/* Reserved library-function and dummy entrypoint */
LONG LIB_Reserved(void)
{
#ifdef BUILD_OS4
	return 30;
#else
	return 0;
#endif
}

struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

#ifdef BUILD_OS4
struct UtilityBase	*UtilityBase;
struct ExecIFace	*IExec;
struct DOSIFace		*IDOS;
struct UtilityIFace	*IUtility;


///
ULONG Obtain(struct Interface *Self)
{
	return Self->Data.RefCount++;
}

ULONG Release(struct Interface *Self)
{
	return Self->Data.RefCount--;
}
///
///

STATIC CONST APTR manager_vectors[] = {
	(void *)Obtain,
	(void *)Release,
	(void *)0,
	(void *)0,
	(void *)LIB_Open,
	(void *)LIB_Close,
	(void *)LIB_Expunge,
	(void *)0,
	(void *)-1
};

static struct TagItem libmanagerTags[] =
{
	{MIT_Name,             (ULONG)"__library"},
	{MIT_VectorTable,      (ULONG)manager_vectors},
	{MIT_Version,          1},
	{TAG_DONE,             0}
};

static void *main_vectors[]=
{
  (void *)Obtain,
  (void *)Release,
  (void *)NULL,
  (void *)NULL,
  LIB_MPEGA_open,
  LIB_MPEGA_close,
  LIB_MPEGA_decode_frame,
  LIB_MPEGA_seek,
  LIB_MPEGA_time,
  LIB_MPEGA_find_sync,
  LIB_MPEGA_scale,
  (void *)-1
};

struct TagItem mainTags[] =
{
        {MIT_Name,     			(ULONG)"main"},
        {MIT_VectorTable,		(ULONG)main_vectors},
        {MIT_Version,       1},
        {TAG_DONE,          0}
};

// MLT_INTERFACES array
static ULONG libInterfaces[] =
{
	(ULONG)libmanagerTags,
	(ULONG)mainTags,
	0
};

extern ULONG VecTable68K[];

STATIC struct TagItem initTab[] = {
	{CLT_DataSize,         (ULONG)(sizeof(struct PrivateBase))},
	{CLT_Interfaces,       (ULONG)libInterfaces},
	{CLT_InitFunc,         (ULONG)LibInit},
	{CLT_Vector68K,		   (ULONG)VecTable68K},
	{TAG_DONE,             0}
};

static const char LibVersion[] = "$VER: " LIB_ID;

struct Resident	ROMTag = {
	RTC_MATCHWORD,
	&ROMTag,
	(&ROMTag)+1,
	RTF_AUTOINIT|RTF_NATIVE,
	LIB_VERSION,
	NT_LIBRARY,
	0,
	LIB_NAME,
	&LibVersion[6],
	initTab
};

#else	/* BUILD_OS4 */

ULONG LibVectors[] = {
#ifdef __MORPHOS__
	FUNCARRAY_32BIT_NATIVE,
#endif
	(ULONG) &LIB_Open,
	(ULONG) &LIB_Close,
	(ULONG) &LIB_Expunge,
	(ULONG) &LIB_Reserved,

	(ULONG) &LIB_MPEGA_open,
	(ULONG) &LIB_MPEGA_close,
	(ULONG) &LIB_MPEGA_decode_frame,
	(ULONG) &LIB_MPEGA_seek,
	(ULONG) &LIB_MPEGA_time,
	(ULONG) &LIB_MPEGA_find_sync,
	(ULONG) &LIB_MPEGA_scale,
	0xFFFFFFFF
};

struct LibInitStruct
{
	ULONG	LibSize;
	void	*FuncTable;
	void	*DataTable;
	void	(*InitFunc)(void);
};

struct LibInitStruct LibInitStruct = {
	sizeof(struct PrivateBase),
	LibVectors,
	NULL,
	(void (*)(void)) &LibInit
};

static const char LibVersion[] = "$VER: " LIB_ID;

static const struct Resident RomTag __attribute__((__aligned__(2))) = {
	RTC_MATCHWORD,
	&RomTag,
	&RomTag + 1,
#ifdef __MORPHOS__
	RTF_PPC | RTF_AUTOINIT,
#else
	RTF_AUTOINIT,
#endif
	LIB_VERSION,
	NT_LIBRARY,
	0,
	LIB_NAME,
	&LibVersion[6],
	&LibInitStruct
};


#ifdef __MORPHOS__
ULONG __amigappc__ = 1;
#endif

#endif	/* !BUILD_WARPUP */

static void LibCleanup(struct PrivateBase *PrivateBase)
{
#ifdef BUILD_POWERUP
	RemoveSupport(PrivateBase);
#else
	RemoveSupport();
#endif

	if (DOSBase)
	{
#ifdef BUILD_OS4
		DropInterface((struct Interface *)IDOS);
		IDOS = NULL;

		DropInterface((struct Interface *)IUtility);
		IUtility = NULL;

		CloseLibrary((struct Library *)UtilityBase);
		UtilityBase = NULL;
#endif

		CloseLibrary((struct Library *)DOSBase);
		PrivateBase->pv_DOSBase = DOSBase = NULL;
	}
}

BPTR LibExpunge(struct PrivateBase *PrivateBase)
{
#ifdef BUILD_POWERUP
	if (PrivateBase->ParentBase)
	{
		struct PrivateBase *OldBase = PrivateBase;

		PrivateBase = PrivateBase->ParentBase;

		FreeMem((APTR)((ULONG)(OldBase) - (ULONG)(OldBase->pv_Lib.lib_NegSize)),
				OldBase->pv_Lib.lib_NegSize + OldBase->pv_Lib.lib_PosSize);
	}
#endif

	if ((PrivateBase->pv_Lib.lib_OpenCnt == 0))
	{
		BPTR seglist;

		seglist = PrivateBase->pv_SegList;
		Remove(&PrivateBase->pv_Lib.lib_Node);
		LibCleanup(PrivateBase);

#ifdef BUILD_OS4
		DeleteLibrary((struct Library *)PrivateBase);
#else
		FreeMem((APTR)((ULONG)(PrivateBase) - (ULONG)(PrivateBase->pv_Lib.lib_NegSize)),
				PrivateBase->pv_Lib.lib_NegSize + PrivateBase->pv_Lib.lib_PosSize);
#endif

		return seglist;
	} else PrivateBase->pv_Lib.lib_Flags |= LIBF_DELEXP;

	return 0L;
}

#ifdef __MORPHOS__
struct Library *LibInit(struct PrivateBase *PrivateBase, BPTR SegList, struct ExecBase *sysbase)
#elif defined(BUILD_OS4)
struct Library * ASM LibInit(REG(d0, struct PrivateBase *PrivateBase), REG(a0, BPTR SegList), REG(a6, struct ExecIFace *pIExec))
#else
struct Library * ASM LibInit(REG(d0, struct PrivateBase *PrivateBase), REG(a0, BPTR SegList), REG(a6, struct ExecBase *sysbase))
#endif
{
#ifdef BUILD_OS4
	struct ExecBase	*sysbase = (struct ExecBase *) pIExec->Data.LibBase;
	IExec = pIExec;
#endif
	SysBase = sysbase;

	if ((DOSBase = (struct DosLibrary *)OpenLibrary("dos.library", 36)))
	{
#ifdef BUILD_POWERUP
		if (InitSupport(PrivateBase))
#elif BUILD_OS4
		if((IDOS = (struct DOSIFace *) GetInterface((struct Library *) DOSBase, "main", 1L, NULL)) &&
		   (UtilityBase = OpenLibrary("utility.library", 0L)) &&
		   (IUtility = (struct UtilityIFace *) GetInterface((struct Library *) UtilityBase, "main", 1L, NULL)) &&
		   InitSupport())
#else
		if (InitSupport())
#endif
		{
			PrivateBase->pv_Lib.lib_Revision     = LIB_REVISION;
			PrivateBase->pv_SegList              = SegList;
			PrivateBase->pv_SysBase              = SysBase;
			PrivateBase->pv_DOSBase              = DOSBase;
#ifdef BUILD_POWERUP
			PrivateBase->ParentBase              = NULL;
#endif

			return &PrivateBase->pv_Lib;
		}
	}

	LibCleanup(PrivateBase);
	return NULL;
}

#ifdef __MORPHOS__
struct Library *LIB_Open(void)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
#elif defined(BUILD_OS4)
struct Library * ASM LIB_Open(struct Interface *Self)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *) Self->Data.LibBase;
#else
struct Library * ASM LIB_Open(REG(a6, struct PrivateBase *PrivateBase))
{
#endif
#ifdef BUILD_POWERUP
	if (PrivateBase->pv_Lib.lib_OpenCnt > 0)
	{
		struct PrivateBase *NewBase;
		ULONG BaseSize = PrivateBase->pv_Lib.lib_NegSize + PrivateBase->pv_Lib.lib_PosSize;

		if ((NewBase = AllocMem(BaseSize, MEMF_PUBLIC)))
		{
			CopyMem((APTR)((ULONG)PrivateBase - (ULONG)PrivateBase->pv_Lib.lib_NegSize), NewBase, BaseSize);
			NewBase = (APTR)((ULONG)NewBase + (ULONG)PrivateBase->pv_Lib.lib_NegSize);

			NewBase->ParentBase = PrivateBase;
			NewBase->pv_CallPPCData = NULL;
			NewBase->pv_CallPPCMsg = NULL;
			NewBase->pv_StartupData = NULL;
			NewBase->pv_StartupMsg = NULL;
			NewBase->pv_ReplyPort = NULL;
			NewBase->pv_PPCPort = NULL;
			NewBase->pv_Task = NULL;

			if (!InitDispatch(NewBase, MSGTYPE_HELLO))
			{
				LibExpunge(NewBase);
				return NULL;
			}

			PrivateBase->pv_Lib.lib_Flags &= ~LIBF_DELEXP;
			PrivateBase->pv_Lib.lib_OpenCnt++;
		}

		return &NewBase->pv_Lib;
	} else {
		if (!InitDispatch(PrivateBase, MSGTYPE_HELLO))
		{
			LibExpunge(PrivateBase);
			return NULL;
		}
#endif
	PrivateBase->pv_Lib.lib_Flags &= ~LIBF_DELEXP;
	PrivateBase->pv_Lib.lib_OpenCnt++;

	return &PrivateBase->pv_Lib;
#ifdef BUILD_POWERUP
	}
#endif
}

#ifdef __MORPHOS__
BPTR LIB_Close(void)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
#elif defined(BUILD_OS4)
BPTR ASM LIB_Close(struct Interface *Self)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *) Self->Data.LibBase;
#else
BPTR ASM LIB_Close(REG(a6, struct PrivateBase *PrivateBase))
{
#endif
#ifdef BUILD_POWERUP
	RemoveDispatch(PrivateBase, MSGTYPE_GOODBYE);

	if (PrivateBase->ParentBase)
	{
		struct PrivateBase *OldBase = PrivateBase;

		PrivateBase = PrivateBase->ParentBase;

		FreeMem((APTR)((ULONG)(OldBase) - (ULONG)(OldBase->pv_Lib.lib_NegSize)),
				OldBase->pv_Lib.lib_NegSize + OldBase->pv_Lib.lib_PosSize);
	}
#endif

	if (PrivateBase->pv_Lib.lib_OpenCnt > 0) PrivateBase->pv_Lib.lib_OpenCnt--;

	if ((PrivateBase->pv_Lib.lib_OpenCnt == 0) && (PrivateBase->pv_Lib.lib_Flags & LIBF_DELEXP))
		return LibExpunge(PrivateBase);

	return 0L;
}

#ifdef __MORPHOS__
BPTR LIB_Expunge(void)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
#elif defined(BUILD_OS4)
BPTR ASM LIB_Expunge(struct Interface *Self)
{
	struct PrivateBase *PrivateBase = (struct PrivateBase *) Self->Data.LibBase;
#else
BPTR ASM LIB_Expunge(REG(a6, struct PrivateBase *PrivateBase))
{
#endif

	return LibExpunge(PrivateBase);
}
#endif /* BUILD_WARPUP */

#ifdef __MORPHOS__
MPEGA_STREAM *LIB_MPEGA_open(void)
{
	char *stream_name = (char *)REG_A0;
	MPEGA_CTRL *ctrl = (MPEGA_CTRL *)REG_A1;
	APTR a4base = (APTR)REG_A4;
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
	struct Task *task = FindTask(NULL);
	ULONG stacksize, stackused, stackreq = REQ_STACKSIZE;

	NewGetTaskAttrsA(task, &stacksize, sizeof(stacksize), TASKINFOTYPE_STACKSIZE, NULL);
	NewGetTaskAttrsA(task, &stackused, sizeof(stackused), TASKINFOTYPE_USEDSTACKSIZE, NULL);

	if ((stacksize - stackused) < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return NULL;

		PrivateBase->stackswap.stack.stk_Lower = newstack;
		PrivateBase->stackswap.stack.stk_Upper = (ULONG)newstack + stackreq;

		PrivateBase->stackswap.Args[0] = (ULONG)stream_name;
		PrivateBase->stackswap.Args[1] = (ULONG)ctrl;
		PrivateBase->stackswap.Args[2] = (ULONG)a4base;

		PrivateBase->stackswap.Return = NewPPCStackSwap(&PrivateBase->stackswap.stack, WRAP_MPEGA_open, &PrivateBase->stackswap.Args);
		FreeVec(newstack);
	} else {
		PrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_open(stream_name, ctrl, a4base);
	}

	return (MPEGA_STREAM *)PrivateBase->stackswap.Return;
}
#else
MPEGA_STREAM * LIB LIB_MPEGA_open(REG(a6, __IFACE_OR_BASE), REG(a0, char *stream_name), REG(a1, MPEGA_CTRL *ctrl), REG(a4, APTR a4base))
{
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_open;
	CallPPCData->Args[0] = (ULONG)stream_name;
	CallPPCData->Args[1] = (ULONG)ctrl;
	CallPPCData->Args[2] = (ULONG)a4base;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (MPEGA_STREAM *)Return;
#elif defined(BUILD_WARPUP)
	return (MPEGA_STREAM *)CallPPCFunc(WRAP_MPEGA_open, stream_name, ctrl, a4base);
#elif defined(BUILD_OS4)
	return WRAP_MPEGA_open(stream_name, ctrl, a4base);
#else
	register struct PrivateBase *MyPrivateBase __asm("a3") = PrivateBase;
	register char *stackptr __asm("sp");
	struct Task *task;
	long stackleft, stackreq = REQ_STACKSIZE;

	__asm("":"=r"(stackptr));	/* force gcc to acknowledge usage of the sp register */

	MyPrivateBase->stackswap.Args[0] = (ULONG)stream_name;
	MyPrivateBase->stackswap.Args[1] = (ULONG)ctrl;
	MyPrivateBase->stackswap.Args[2] = (ULONG)a4base;

	task = FindTask(NULL);
	stackleft = stackptr - (char *)task->tc_SPLower;

	if (stackleft < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return NULL;

		MyPrivateBase->stackswap.stack.stk_Lower = newstack;
		MyPrivateBase->stackswap.stack.stk_Pointer = newstack + stackreq;
		MyPrivateBase->stackswap.stack.stk_Upper = (ULONG)MyPrivateBase->stackswap.stack.stk_Pointer;

		StackSwap(&MyPrivateBase->stackswap.stack);

		MyPrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_open((char *)MyPrivateBase->stackswap.Args[0], (MPEGA_CTRL *)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);

		StackSwap(&MyPrivateBase->stackswap.stack);

		FreeVec(newstack);
		return (MPEGA_STREAM *)MyPrivateBase->stackswap.Return;
	} else {
		return WRAP_MPEGA_open((char *)MyPrivateBase->stackswap.Args[0], (MPEGA_CTRL *)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);
	}
#endif
}
#endif

#ifdef __MORPHOS__
void LIB_MPEGA_close(void)
{
	MPEGA_STREAM *mpega_stream = (MPEGA_STREAM *)REG_A0;
	APTR a4base = (APTR)REG_A4;
#else
void LIB LIB_MPEGA_close(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a4, APTR a4base))
{
#endif
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_close;
	CallPPCData->Args[0] = (ULONG)mpega_stream;
	CallPPCData->Args[1] = (ULONG)a4base;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}
#elif defined(BUILD_WARPUP)
	CallPPCFunc(WRAP_MPEGA_close, mpega_stream, a4base, 0);
#else
	WRAP_MPEGA_close(mpega_stream, a4base);
#endif
}

#ifdef __MORPHOS__
LONG LIB_MPEGA_decode_frame(void)
{
	MPEGA_STREAM *mpega_stream = (MPEGA_STREAM *)REG_A0;
	WORD **pcm = (WORD **)REG_A1;
	APTR a4base = (APTR)a4base;
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
	struct Task *task = FindTask(NULL);
	ULONG stacksize, stackused, stackreq = REQ_STACKSIZE;

	NewGetTaskAttrsA(task, &stacksize, sizeof(stacksize), TASKINFOTYPE_STACKSIZE, NULL);
	NewGetTaskAttrsA(task, &stackused, sizeof(stackused), TASKINFOTYPE_USEDSTACKSIZE, NULL);

	if ((stacksize - stackused) < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return MPEGA_ERR_MEM;

		PrivateBase->stackswap.stack.stk_Lower = newstack;
		PrivateBase->stackswap.stack.stk_Upper = (ULONG)newstack + stackreq;

		PrivateBase->stackswap.Args[0] = (ULONG)mpega_stream;
		PrivateBase->stackswap.Args[1] = (ULONG)pcm;
		PrivateBase->stackswap.Args[2] = (ULONG)a4base;

		PrivateBase->stackswap.Return = NewPPCStackSwap(&PrivateBase->stackswap.stack, WRAP_MPEGA_decode_frame, &PrivateBase->stackswap.Args);
		FreeVec(newstack);
	} else {
		PrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_decode_frame(mpega_stream, pcm, a4base);
	}

	return (LONG)PrivateBase->stackswap.Return;
}
#else
LONG LIB LIB_MPEGA_decode_frame(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a1, WORD *pcm[MPEGA_MAX_CHANNELS]), REG(a4, APTR a4base))
{
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_decode_frame;
	CallPPCData->Args[0] = (ULONG)mpega_stream;
	CallPPCData->Args[1] = (ULONG)pcm;
	CallPPCData->Args[2] = (ULONG)a4base;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (LONG)Return;
#elif defined(BUILD_WARPUP)
	return (LONG)CallPPCFunc(WRAP_MPEGA_decode_frame, mpega_stream, pcm, a4base);
#elif defined(BUILD_OS4)
	return WRAP_MPEGA_decode_frame(mpega_stream, pcm, a4base);
#else
	register struct PrivateBase *MyPrivateBase __asm("a3") = PrivateBase;
	register char *stackptr __asm("sp");
	struct Task *task;
	long stackleft, stackreq = REQ_STACKSIZE;

	__asm("":"=r"(stackptr));	/* force gcc to acknowledge usage of the sp register */

	MyPrivateBase->stackswap.Args[0] = (ULONG)mpega_stream;
	MyPrivateBase->stackswap.Args[1] = (ULONG)pcm;
	MyPrivateBase->stackswap.Args[2] = (ULONG)a4base;

	task = FindTask(NULL);
	stackleft = stackptr - (char *)task->tc_SPLower;

	if (stackleft < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return MPEGA_ERR_MEM;

		MyPrivateBase->stackswap.stack.stk_Lower = newstack;
		MyPrivateBase->stackswap.stack.stk_Pointer = newstack + stackreq;
		MyPrivateBase->stackswap.stack.stk_Upper = (ULONG)MyPrivateBase->stackswap.stack.stk_Pointer;

		StackSwap(&MyPrivateBase->stackswap.stack);

		MyPrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_decode_frame((MPEGA_STREAM *)MyPrivateBase->stackswap.Args[0], (WORD **)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);

		StackSwap(&MyPrivateBase->stackswap.stack);

		FreeVec(newstack);
		return (LONG)MyPrivateBase->stackswap.Return;
	} else {
		return WRAP_MPEGA_decode_frame((MPEGA_STREAM *)MyPrivateBase->stackswap.Args[0], (WORD **)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);
	}
#endif
}
#endif

#ifdef __MORPHOS__
LONG LIB_MPEGA_seek(void)
{
	MPEGA_STREAM *mpega_stream = (MPEGA_STREAM *)REG_A0;
	ULONG ms_time_position = (ULONG)REG_D0;
	APTR a4base = (APTR)REG_A4;
	struct PrivateBase *PrivateBase = (struct PrivateBase *)REG_A6;
	struct Task *task = FindTask(NULL);
	ULONG stacksize, stackused, stackreq = REQ_STACKSIZE;

	NewGetTaskAttrsA(task, &stacksize, sizeof(stacksize), TASKINFOTYPE_STACKSIZE, NULL);
	NewGetTaskAttrsA(task, &stackused, sizeof(stackused), TASKINFOTYPE_USEDSTACKSIZE, NULL);

	if ((stacksize - stackused) < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return MPEGA_ERR_MEM;

		PrivateBase->stackswap.stack.stk_Lower = newstack;
		PrivateBase->stackswap.stack.stk_Upper = (ULONG)newstack + stackreq;

		PrivateBase->stackswap.Args[0] = (ULONG)mpega_stream;
		PrivateBase->stackswap.Args[1] = (ULONG)ms_time_position;
		PrivateBase->stackswap.Args[2] = (ULONG)a4base;

		PrivateBase->stackswap.Return = NewPPCStackSwap(&PrivateBase->stackswap.stack, WRAP_MPEGA_seek, &PrivateBase->stackswap.Args);
		FreeVec(newstack);
	} else {
		PrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_seek(mpega_stream, ms_time_position, a4base);
	}

	return (LONG)PrivateBase->stackswap.Return;
}
#else
LONG LIB LIB_MPEGA_seek(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(d0, ULONG ms_time_position), REG(a4, APTR a4base))
{
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_seek;
	CallPPCData->Args[0] = (ULONG)mpega_stream;
	CallPPCData->Args[1] = (ULONG)ms_time_position;
	CallPPCData->Args[2] = (ULONG)a4base;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (LONG)Return;
#elif defined(BUILD_WARPUP)
	return (LONG)CallPPCFunc(WRAP_MPEGA_seek, mpega_stream, ms_time_position, a4base);
#elif defined(BUILD_OS4)
	return WRAP_MPEGA_seek(mpega_stream, ms_time_position, a4base);
#else
	register struct PrivateBase *MyPrivateBase __asm("a3") = PrivateBase;
	register char *stackptr __asm("sp");
	struct Task *task;
	long stackleft, stackreq = REQ_STACKSIZE;

	__asm("":"=r"(stackptr));	/* force gcc to acknowledge usage of the sp register */

	MyPrivateBase->stackswap.Args[0] = (ULONG)mpega_stream;
	MyPrivateBase->stackswap.Args[1] = (ULONG)ms_time_position;
	MyPrivateBase->stackswap.Args[2] = (ULONG)a4base;

	task = FindTask(NULL);
	stackleft = stackptr - (char *)task->tc_SPLower;

	if (stackleft < stackreq)
	{
		char *newstack;

		if (!(newstack = AllocVec(stackreq, MEMF_PUBLIC))) return MPEGA_ERR_MEM;

		MyPrivateBase->stackswap.stack.stk_Lower = newstack;
		MyPrivateBase->stackswap.stack.stk_Pointer = newstack + stackreq;
		MyPrivateBase->stackswap.stack.stk_Upper = (ULONG)MyPrivateBase->stackswap.stack.stk_Pointer;

		StackSwap(&MyPrivateBase->stackswap.stack);

		MyPrivateBase->stackswap.Return = (ULONG)WRAP_MPEGA_seek((MPEGA_STREAM *)MyPrivateBase->stackswap.Args[0], (ULONG)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);

		StackSwap(&MyPrivateBase->stackswap.stack);

		FreeVec(newstack);
		return (LONG)MyPrivateBase->stackswap.Return;
	} else {
		return WRAP_MPEGA_seek((MPEGA_STREAM *)MyPrivateBase->stackswap.Args[0], (ULONG)MyPrivateBase->stackswap.Args[1], (APTR)MyPrivateBase->stackswap.Args[2]);
	}
#endif
}
#endif

#ifdef __MORPHOS__
LONG LIB_MPEGA_time(void)
{
	MPEGA_STREAM *mpega_stream = (MPEGA_STREAM *)REG_A0;
	ULONG *ms_time_position = (ULONG *)REG_A1;
#else
LONG LIB LIB_MPEGA_time(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a1, ULONG *ms_time_position))
{
#endif
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_time;
	CallPPCData->Args[0] = (ULONG)mpega_stream;
	CallPPCData->Args[1] = (ULONG)ms_time_position;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (LONG)Return;
#elif defined(BUILD_WARPUP)
	return (LONG)CallPPCFunc(WRAP_MPEGA_time, mpega_stream, ms_time_position, 0);
#else
	return WRAP_MPEGA_time(mpega_stream, ms_time_position);
#endif
}

#ifdef __MORPHOS__
LONG LIB_MPEGA_find_sync(void)
{
	UBYTE *buffer = (UBYTE *)REG_A0;
	LONG buffer_size = (LONG)REG_D0;
#else
LONG LIB LIB_MPEGA_find_sync(REG(a6, __IFACE_OR_BASE), REG(a0, UBYTE *buffer), REG(d0, LONG buffer_size))
{
#endif
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_find_sync;
	CallPPCData->Args[0] = (ULONG)buffer;
	CallPPCData->Args[1] = (ULONG)buffer_size;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (LONG)Return;
#elif defined(BUILD_WARPUP)
	return (LONG)CallPPCFunc(WRAP_MPEGA_find_sync, buffer, buffer_size, 0);
#else
	return WRAP_MPEGA_find_sync(buffer, buffer_size);
#endif
}

#ifdef __MORPHOS__
LONG LIB_MPEGA_scale(void)
{
	MPEGA_STREAM *mpega_stream = (MPEGA_STREAM *)REG_A0;
	LONG scale_percent = (LONG)REG_D0;
#else
LONG LIB LIB_MPEGA_scale(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(d0, LONG scale_percent))
{
#endif
#ifdef BUILD_POWERUP
	struct CallPPCData *CallPPCData;
	APTR ReplyPort;
	APTR CallPPCMsg;
	ULONG Return;
	APTR ThisTask = FindTask(NULL);
	APTR SigTask = ((struct MsgPort *)PrivateBase->pv_ReplyPort)->mp_SigTask;	/* !!!HACK!!! */

	/* Workaround for bad tasks that pass around the library base */
	if (SigTask != ThisTask)
	{
		struct TagItem tmpTagList[1];

		tmpTagList[0].ti_Tag = TAG_DONE;
		ReplyPort = PPCCreatePort(tmpTagList);
		CallPPCMsg = PPCCreateMessage(ReplyPort, sizeof(struct CallPPCData));
		CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC);
	} else {
		CallPPCData = PrivateBase->pv_CallPPCData;
		CallPPCMsg = PrivateBase->pv_CallPPCMsg;
		ReplyPort = PrivateBase->pv_ReplyPort;
	}

	CallPPCData->Type = MSGTYPE_CALL;
	CallPPCData->PPCLVO = PPCLVO_MPEGA_scale;
	CallPPCData->Args[0] = (ULONG)mpega_stream;
	CallPPCData->Args[1] = (ULONG)scale_percent;

	PPCCacheClearE(NULL, 0xffffffff, CACRF_ClearD);

	PPCSendMessage(PrivateBase->pv_PPCPort, CallPPCMsg, CallPPCData, sizeof(struct CallPPCData), 0x12345678);

	PPCWaitPort(ReplyPort);
	PPCGetMessage(ReplyPort);
	Return = CallPPCData->Return;

	if (SigTask != ThisTask)
	{
		PPCDeleteMessage(CallPPCMsg);
		PPCDeletePort(ReplyPort);
		PPCFreeVec(CallPPCData);
	}

	return (LONG)Return;
#elif defined(BUILD_WARPUP)
	return (LONG)CallPPCFunc(WRAP_MPEGA_scale, mpega_stream, scale_percent, 0);
#else
	return WRAP_MPEGA_scale(mpega_stream, scale_percent);
#endif
}
