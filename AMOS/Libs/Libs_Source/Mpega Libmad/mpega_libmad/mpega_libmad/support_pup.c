// =======================================================================
// 68k side library startup and communications dispatcher
// (c)1998 by Jacek Cybularczyk (NOE/VenusArt)
// slightly modified for specific use by Sigbjørn (CISC) Skjæret
// =======================================================================

#include "library_base.h"

#include <exec/execbase.h>
#include <exec/memory.h>
#include <dos/dostags.h>
#include <utility/tagitem.h>

#include <powerup/ppclib/object.h>
#include <powerup/ppclib/interface.h>
#include <powerup/ppclib/message.h>
#include <powerup/ppclib/tasks.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/ppc.h>

struct Library *PPCLibBase = NULL;
extern UBYTE _ElfObject;

ULONG InitDispatch(struct PrivateBase *PrivateBase, ULONG MsgType)
{
	struct TagItem tmpTagList[20];

	tmpTagList[0].ti_Tag = TAG_DONE;
	if ((PrivateBase->pv_ReplyPort = PPCCreatePort(tmpTagList)))
	{
		if ((PrivateBase->pv_StartupMsg = PPCCreateMessage(PrivateBase->pv_ReplyPort, sizeof(struct StartupData))))
		{
			if ((PrivateBase->pv_StartupData = PPCAllocVec(sizeof(struct StartupData), MEMF_PUBLIC)))
			{
				PrivateBase->pv_StartupData->ElfObject = PrivateBase->pv_ElfObject;

				tmpTagList[0].ti_Tag = PPCTASKTAG_STARTUP_MSG;
				tmpTagList[0].ti_Data = (ULONG)PrivateBase->pv_StartupMsg;

				tmpTagList[1].ti_Tag = PPCTASKTAG_STARTUP_MSGDATA;
				tmpTagList[1].ti_Data = (ULONG)PrivateBase->pv_StartupData;

				tmpTagList[2].ti_Tag = PPCTASKTAG_STARTUP_MSGLENGTH;
//				tmpTagList[2].ti_Data = sizeof(struct StartupData);
				tmpTagList[2].ti_Data = 0;

				tmpTagList[3].ti_Tag = PPCTASKTAG_STARTUP_MSGID;
				tmpTagList[3].ti_Data = 0;

				tmpTagList[4].ti_Tag = PPCTASKTAG_MSGPORT;
				tmpTagList[4].ti_Data = TRUE;

				tmpTagList[5].ti_Tag = PPCTASKTAG_NAME;
				tmpTagList[5].ti_Data = (ULONG)PrivateBase->pv_Lib.lib_Node.ln_Name;

				tmpTagList[6].ti_Tag = PPCTASKTAG_STACKSIZE;
				tmpTagList[6].ti_Data = 16384;

				tmpTagList[7].ti_Tag = PPCTASKTAG_INPUTHANDLE;
//				tmpTagList[7].ti_Data = (ULONG)Input();
				tmpTagList[7].ti_Data = NULL;
            
				tmpTagList[8].ti_Tag = PPCTASKTAG_OUTPUTHANDLE;
//				tmpTagList[8].ti_Data = (ULONG)Output();
				tmpTagList[8].ti_Data = NULL;

				tmpTagList[9].ti_Tag = PPCTASKTAG_ERRORHANDLE;
//				tmpTagList[9].ti_Data = (ULONG)Open("*", MODE_NEWFILE);
				tmpTagList[9].ti_Data = NULL;

				tmpTagList[10].ti_Tag = NP_CloseInput;
				tmpTagList[10].ti_Data = FALSE;

				tmpTagList[11].ti_Tag = NP_CloseOutput;
				tmpTagList[11].ti_Data = FALSE;

				tmpTagList[12].ti_Tag = NP_CloseError;
				tmpTagList[12].ti_Data = FALSE;

				tmpTagList[13].ti_Tag = TAG_DONE;

				if ((PrivateBase->pv_Task = PPCCreateTask(PrivateBase->pv_ElfObject, tmpTagList)))
				{
					if ((PrivateBase->pv_PPCPort = (APTR)PPCGetTaskAttrsTags(PrivateBase->pv_Task, PPCTASKINFOTAG_MSGPORT, 0, TAG_END)))
					{
						if ((PrivateBase->pv_CallPPCMsg = PPCCreateMessage(PrivateBase->pv_ReplyPort, sizeof(struct CallPPCData))))
						{
							if ((PrivateBase->pv_CallPPCData = PPCAllocVec(sizeof(struct CallPPCData), MEMF_PUBLIC)))
							{
								PrivateBase->pv_CallPPCData->Type = MsgType;
								PrivateBase->pv_CallPPCData->Return = 0;

								PPCSendMessage(PrivateBase->pv_PPCPort, PrivateBase->pv_CallPPCMsg, PrivateBase->pv_CallPPCData, sizeof(struct CallPPCData), 0x12345678);
								PPCWaitPort(PrivateBase->pv_ReplyPort);
								PPCGetMessage(PrivateBase->pv_ReplyPort);

								return PrivateBase->pv_CallPPCData->Return;
							}

							PPCDeleteMessage(PrivateBase->pv_CallPPCMsg);
						}
					}

					/* TODO: Kill still active task */
				}

				PPCFreeVec(PrivateBase->pv_StartupData);
			}

			PPCDeleteMessage(PrivateBase->pv_StartupMsg);
		}

		PPCDeletePort(PrivateBase->pv_ReplyPort);
	}

	return 0;
}

void RemoveDispatch(struct PrivateBase *PrivateBase, ULONG MsgType)
{
	if (PrivateBase->pv_CallPPCData)
	{
		PrivateBase->pv_CallPPCData->Type = MsgType;
		PPCSendMessage(PrivateBase->pv_PPCPort, PrivateBase->pv_CallPPCMsg, PrivateBase->pv_CallPPCData, sizeof(struct CallPPCData), 0x12345678);

		while (PPCGetMessage(PrivateBase->pv_ReplyPort) != PrivateBase->pv_StartupMsg)
		{
			PPCWaitPort(PrivateBase->pv_ReplyPort);
		}

		PPCFreeVec(PrivateBase->pv_CallPPCData);
	}

	if (PrivateBase->pv_CallPPCMsg)
		PPCDeleteMessage(PrivateBase->pv_CallPPCMsg);

	if (PrivateBase->pv_StartupMsg)
		PPCDeleteMessage(PrivateBase->pv_StartupMsg);

	if (PrivateBase->pv_StartupData)
		PPCFreeVec(PrivateBase->pv_StartupData);

	if (PrivateBase->pv_ReplyPort)
		PPCDeletePort(PrivateBase->pv_ReplyPort);
}

ULONG InitSupport(struct PrivateBase *PrivateBase)
{
	struct PPCObjectInfo PPCObjectInfo;

	if ((PPCLibBase = OpenLibrary("ppc.library", 0)))
	{
		PrivateBase->pv_PPCLibBase = PPCLibBase;

		if ((PrivateBase->pv_ElfObject = PPCLoadObjectTags(PPCELFLOADTAG_ELFADDRESS, (ULONG)&_ElfObject, PPCELFLOADTAG_ELFNAME, (ULONG)PrivateBase->pv_Lib.lib_Node.ln_Name, TAG_DONE)))
		{
			PPCObjectInfo.Address = 0L;
			PPCObjectInfo.Name = "__LibFuncTable";

			PPCGetObjectAttrs(PrivateBase->pv_ElfObject, &PPCObjectInfo, NULL);
			PrivateBase->pv_LibFuncTable = (APTR)PPCObjectInfo.Address;

			if (InitDispatch(PrivateBase, MSGTYPE_INIT))
			{
				/* We can't re-use the ReplyPort because we are on ramlib's context, so clean up */
				while (PPCGetMessage(PrivateBase->pv_ReplyPort) != PrivateBase->pv_StartupMsg)
				{
					PPCWaitPort(PrivateBase->pv_ReplyPort);
				}

				PrivateBase->pv_Task = NULL;
				PrivateBase->pv_PPCPort = NULL;

				PPCDeleteMessage(PrivateBase->pv_CallPPCMsg);
				PrivateBase->pv_CallPPCMsg = NULL;

				PPCDeleteMessage(PrivateBase->pv_StartupMsg);
				PrivateBase->pv_StartupMsg = NULL;

				PPCDeletePort(PrivateBase->pv_ReplyPort);
				PrivateBase->pv_ReplyPort = NULL;

				PPCFreeVec(PrivateBase->pv_StartupData);
				PrivateBase->pv_StartupData = NULL;

				return 1;
			}

			PPCUnLoadObject(PrivateBase->pv_ElfObject);
		}

		CloseLibrary(PPCLibBase);
		PrivateBase->pv_PPCLibBase = PPCLibBase = NULL;
	}

	return 0;
}

void RemoveSupport(struct PrivateBase *PrivateBase)
{
	if (PPCLibBase)
	{
		InitDispatch(PrivateBase, MSGTYPE_HELLO);
		RemoveDispatch(PrivateBase, MSGTYPE_REMOVE);

		if (PrivateBase->pv_ElfObject)
			PPCUnLoadObject(PrivateBase->pv_ElfObject);

		if (PrivateBase->pv_PPCLibBase)
			CloseLibrary(PrivateBase->pv_PPCLibBase);

		PrivateBase->pv_PPCLibBase = PPCLibBase = NULL;
	}
}
