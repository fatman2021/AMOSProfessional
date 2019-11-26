// =======================================================================
// ppc side communication dispatcher
// (c)1998 by Jacek Cybularczyk (NOE/VenusArt)
// slightly modified for specific use by Sigbjørn (CISC) Skjæret
// =======================================================================

#include "library_base.h"

#include <exec/memory.h>
#include <utility/tagitem.h>

#include <powerup/ppclib/object.h>
#include <powerup/ppclib/interface.h>
#include <powerup/ppclib/message.h>
#include <powerup/ppclib/tasks.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <powerup/gcclib/powerup_protos.h>

#include "support.h"

extern APTR __LibFuncTable[];

void MainEntry(void)
{
	APTR ElfObject;
	APTR PPCPort;
	APTR CallPPCMsg;
	ULONG (*function)(ULONG, ULONG, ULONG);
	struct CallPPCData *CallPPCData;
	struct StartupData *StartupData;

	StartupData = (struct StartupData *)PPCGetTaskAttr(PPCTASKTAG_STARTUP_MSGDATA);
	ElfObject = StartupData->ElfObject;

	if ((PPCPort = (APTR)PPCGetTaskAttr(PPCTASKTAG_MSGPORT)))
	{
		BOOL Terminated = FALSE;

		do {
			PPCWaitPort(PPCPort);

			if ((CallPPCMsg = PPCGetMessage(PPCPort)))
			{
				CallPPCData = (struct CallPPCData *)PPCGetMessageAttr(CallPPCMsg, PPCMSGTAG_DATA);

				switch (CallPPCData->Type)
				{
					case MSGTYPE_CALL:
						function = (ULONG (*)(ULONG, ULONG))__LibFuncTable[CallPPCData->PPCLVO];
						CallPPCData->Return = function(CallPPCData->Args[0], CallPPCData->Args[1], CallPPCData->Args[2]);
						break;

					case MSGTYPE_INIT:
						CallPPCData->Return = InitSupport();
						Terminated = TRUE;
						break;

					case MSGTYPE_HELLO:
						CallPPCData->Return = 1;
						break;

					case MSGTYPE_REMOVE:
						RemoveSupport();

					/* Fall through */

					case MSGTYPE_GOODBYE:
						Terminated = TRUE;
						break;

					default:
						break;
				}

				PPCCacheFlushAll();
				PPCReplyMessage(CallPPCMsg);
			}
		} while (!Terminated);
	}
}
