/*
** mrqwindowclass.c
** Implements MRQ's window subclass to handle MRQReqMessages from window
** to application and do the HandleEvent input stuff
**
** Attributes:
** 	MRQWINDOWTAG_REQMESSAGE [ S ] : message structure to fill
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: mrqwindowclass.c 1.1 2000/01/25 16:48:20 msbethke Exp msbethke $
**
** $Log: mrqwindowclass.c $
** Revision 1.1  2000/01/25 16:48:20  msbethke
** Initial revision
**
*/


#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <exec/memory.h>
#include <lib/mb_utils.h>
#include "mrq.h"
#include "muistuff.h"
#include "mrqwindowclass_private.h"

/******************************************************************************/


static ULONG __saveds __asm MyWindowDispatcher(
	register __a0 struct IClass *cl,
	register __a2 Object *obj,
	register __a1 Msg msg)
{
struct MRQReqMessage *rmsg;

	switch(msg->MethodID)
	{
		case OM_SET :
			if(rmsg = (struct MRQReqMessage*)(GetTagData(MRQWINDOWTAG_REQMESSAGE,0,((struct opSet *)msg)->ops_AttrList)))
			{
				((struct MRQWinData*)(INST_DATA(cl,obj)))->ReqMsg = rmsg;
			}
			return DoSuperMethodA(cl,obj,msg);

		case MUIM_HandleEvent :
			if(((struct MUIP_HandleInput*)msg)->imsg)
			{
				rmsg = ((struct MRQWinData*)(INST_DATA(cl,obj)))->ReqMsg;
				rmsg->mrm_RCode = -1;
				DoMethod(_app(obj),MUIM_Application_ReturnID,rmsg);
			}
			break;

		default :
			return DoSuperMethodA(cl,obj,msg);
	}
}

/*****************************************************************************/

struct MUI_CustomClass *NewMRQWindowClass(void)
{
	return MUI_CreateCustomClass(
		NULL,MUIC_Window,NULL,sizeof(struct MRQWinData),&MyWindowDispatcher);
}
