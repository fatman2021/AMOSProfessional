head	1.4;
access;
symbols;
locks
	msbethke:1.4; strict;
comment	@ * @;


1.4
date	2000.10.15.18.06.08;	author msbethke;	state Exp;
branches;
next	1.3;

1.3
date	2000.03.30.23.18.43;	author msbethke;	state Exp;
branches;
next	1.2;

1.2
date	2000.01.25.17.30.22;	author msbethke;	state Exp;
branches;
next	1.1;

1.1
date	2000.01.25.16.57.49;	author msbethke;	state Exp;
branches;
next	;


desc
@The Real Work(tm) is done here!
@


1.4
log
@Structured the button generation part a little better
(actually this should have long gone into a MUI class of its own :-( )
Now uses my own reentrant strtok()-function, not yet everywhere though.
@
text
@/* Requesters.c
** This is where the real work is done!
** - Functions patched into intuition and reqtools.library
** - Functions to build a MUI requester according to an
**   MRQReqMessage structure
** - Message handling
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: Requesters.c 1.3 2000/03/30 23:18:43 msbethke Exp msbethke $
**
** $Log: Requesters.c $
** Revision 1.3  2000/03/30 23:18:43  msbethke
** Changed NewImage.mcc -> Guigfx.mcc
**
** Revision 1.2  2000/01/25 17:30:22  msbethke
** Adapted to new header names
** Fixed obsolete NewImage.mcc tag names/structures
**
** Revision 1.1  2000/01/25 16:57:49  msbethke
** Initial revision
**
*/


#include <proto/utility.h>
#include <exec/memory.h>
#include <exec/alerts.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <libraries/reqtools.h>
#include <lib/mb_utils.h>
#include <MUI/Guigfx_mcc.h>
#include <MUI/TransferAnim_mcc.h>
#include <math.h>
#include <ctype.h>

#include "muistuff.h"
#include "mrq.h"
#include "config.h"
#include "gfxfiles.h"
#include "MRQasm.h"
#include "mui_macros.h"

/************************************************************************/
/* local protos                                                         */
/************************************************************************/
static struct MRQReqMessage *CreateMsgAndPort(ULONG);
static STRPTR GetCallingProgram(APTR);
static void FreeMsgAndPort(struct MRQReqMessage*);
static BOOL CheckAvoidTask(struct Task*);
static STRPTR FormatButtonText(STRPTR, APTR);
static struct MRQEventClass *AnalyzeReqText(STRPTR,STRPTR);
static APTR CreateMRQButton(STRPTR, BOOL, BOOL, struct Screen*, UBYTE, BOOL);
static APTR CreateImageButton(STRPTR,struct MRQImageButton*, struct Screen*, UBYTE, BOOL);
static APTR CreateTextButton(STRPTR, UBYTE, BOOL);
static WORD PreParseButtonText(STRPTR, UBYTE, BOOL, STRPTR*, STRPTR*);

/*****************************************************************************/

#define GADBUFSIZE (256)

/*****************************************************************************/

LONG __asm __saveds EasyRequestArgsPatch(
	register __a0 struct Window *ParentWindow,
	register __a1 struct EasyStruct *es,
	register __a2 ULONG *IDCMPptr,
	register __a3 APTR ArgList)
{
static const struct EasyStruct easy = {sizeof(struct EasyStruct),0,"System error",
"EasyRequestArgs() called by %s\nwith %s == NULL!","I see"};
struct MRQReqMessage *msg;
struct Window *pwindow;		// temp parent window
struct Task *MyTask;
STRPTR TaskName;
LONG RCode = -1;

	MyTask = FindTask(NULL);
	TaskName = MyTask->tc_Node.ln_Name ? MyTask->tc_Node.ln_Name : "<UNKNOWN>";

	pwindow = ParentWindow;

//	if((MyTask->tc_Node.ln_Type == NT_PROCESS) && (!pwindow))
//		pwindow = ((struct Process*)MyTask)->pr_WindowPtr;

	if(pwindow == (struct Window*)-1) pwindow = NULL;

	prdebug("EasyRequestArgs patch entered by '%s'\n",TaskName);

	if(CheckAvoidTask(MyTask) || (!AppActive))
	{
		return CallOldERA(ParentWindow,es,IDCMPptr,ArgList,IntuitionBase); // use standard intuition
	}

	if(!es->es_GadgetFormat)
	{
		EasyRequest(ParentWindow,(struct EasyStruct*)&easy,NULL,TaskName,"es_GadgetFormat");
		return -1L;
	}
	if(!es->es_TextFormat)
	{
		EasyRequest(ParentWindow,(struct EasyStruct*)&easy,NULL,TaskName,"es_TextFormat");
		return -1L;
	}

	if(msg = CreateMsgAndPort(IDCMPptr?*IDCMPptr:0L))
	{
		/* fill message structure */
		msg->mrm_Easy			= es;
		msg->mrm_ParentWin	= pwindow;
		msg->mrm_ArgList		= ArgList;
		msg->mrm_CalledFrom	= CALLER_EASYREQUESTARGS;
		msg->mrm_DefaultAnswer = 1;

		PutMsg(MainPort,(struct Message*)msg);
		prdebug("Message sent\n");
		WaitPort(msg->mrm_Message.mn_ReplyPort);
		GetMsg(msg->mrm_Message.mn_ReplyPort);
		prdebug("Received reply\n");

		RCode = msg->mrm_RCode;
		if(msg->mrm_FatalError)
		{
			prdebug("Fatal error in MUI requester code - using original function!\n");
			RCode = CallOldERA(ParentWindow,es,IDCMPptr,ArgList,IntuitionBase);
		}
		FreeMsgAndPort(msg);
	}
	prdebug("EasyRequestArgsPatch() result: %ld\n",RCode);
	return RCode;
}


/*****************************************************************************/

ULONG __asm __saveds rtEZRequestAPatch(
	register __a1 char *bodyfmt,
	register __a2 char *gadfmt,
	register __a3 struct rtReqInfo *reqinfo,
	register __a5 APTR argarray,					// usually a4 - requires asm stub!!!
	register __a0 struct TagItem *taglist)
{
struct MRQReqMessage *msg;
struct Window *pwindow=NULL;
struct Task *MyTask;
STRPTR TaskName;
ULONG RCode = -1;
ULONG IDCMPflags=0, IDCMPsaved=0, ReqFlags=0;
BOOL WaitPointer=FALSE, LockWindow=FALSE;
struct TagItem *tlist, *tag;
STRPTR ReqTitle=NULL;
UBYTE rtUnderscore=0, DefaultAnswer=1;

	MyTask = FindTask(NULL);
	TaskName = MyTask->tc_Node.ln_Name ? MyTask->tc_Node.ln_Name : "<UNKNOWN>";

	if(taglist)	pwindow = (struct Window*)GetTagData(RT_Window,0,taglist);

//	if((MyTask->tc_Node.ln_Type == NT_PROCESS) && (!pwindow))
//		pwindow = ((struct Process*)MyTask)->pr_WindowPtr;

	if(pwindow == (struct Window*)-1) pwindow=NULL;

	prdebug("rtEZRequestA patch entered by '%s'\n",TaskName);

	/* avoid certain tasks, buttonless/asynchronous requesters, and honor AppActive */
	if(CheckAvoidTask(MyTask) ||
		!(AppActive && gadfmt) ||
		FindTagItem(RT_ReqHandler,taglist))
	{
		prdebug("Requester not MUIfiable - calling original function!\n");
		return CallOldrtEZRA(bodyfmt,gadfmt,reqinfo,argarray,taglist,ReqToolsBase);
	}

	if(!bodyfmt)
	{
	struct EasyStruct easy = {sizeof(struct EasyStruct),0,"MRQ error","rtEZRequestA() called by %s\nwith bodyfmt == NULL!","I see"};

		EasyRequest(NULL,&easy,NULL,TaskName);
		return -1L;
	}

	if(reqinfo)
	{
		ReqTitle = reqinfo->ReqTitle;
		WaitPointer = reqinfo->WaitPointer;
		LockWindow = reqinfo->LockWindow;
		ReqFlags = reqinfo->Flags;
	}

	tlist = taglist;
	while(tag = NextTagItem(&tlist))
	{
		switch(tag->ti_Tag)
		{
			case  RT_IDCMPFlags	: IDCMPflags = tag->ti_Data;
				prdebug("IDCMPflags wanted: %08.lx\n",IDCMPflags);
				break;
			case  RT_WaitPointer	: WaitPointer = tag->ti_Data;
				break;
			case  RT_LockWindow	: LockWindow = tag->ti_Data;
				break;
			case RT_Underscore	: rtUnderscore = (UBYTE)tag->ti_Data;
				break;
			case RTEZ_ReqTitle	: ReqTitle = (STRPTR)tag->ti_Data;
				break;
			case RTEZ_Flags		:
				if(tag->ti_Data & EZREQF_CENTERTEXT)  ReqFlags |= MRQMF_CENTERTEXT;
				if(tag->ti_Data & EZREQF_NORETURNKEY) ReqFlags |= MRQMF_NORETURNKEY;
				break;
			case RTEZ_DefaultResponse : DefaultAnswer = tag->ti_Data;
				break;
		}
	}

	if(pwindow)
	{
		if(WaitPointer || LockWindow)
		{
			SetWindowPointer(pwindow,WA_BusyPointer,TRUE,TAG_DONE);
		}
		if(LockWindow)
		{
			IDCMPsaved = pwindow->IDCMPFlags;
			ModifyIDCMP(pwindow,0);				// turn off all IDCMP messages
		}
	}

	if(msg = CreateMsgAndPort(IDCMPflags))
	{
	struct EasyStruct es = {0};

		/* fake an EasyStruct :) */
		es.es_TextFormat = bodyfmt;
		es.es_GadgetFormat = gadfmt ? gadfmt : "OK";		// gadfmt may be NULL!
		es.es_Title = ReqTitle;

		/* fill message structure */
		msg->mrm_Easy				= &es;
		msg->mrm_ArgList			= argarray;
		msg->mrm_CalledFrom		= CALLER_RTEZREQUESTA;
		msg->mrm_ParentWin		= pwindow;
		msg->mrm_Flags				= ReqFlags;
		msg->mrm_Underscore		= rtUnderscore;
		msg->mrm_DefaultAnswer	= DefaultAnswer;

		PutMsg(MainPort,(struct Message*)msg);
		prdebug("Message sent\n");
		WaitPort(msg->mrm_Message.mn_ReplyPort);
		GetMsg(msg->mrm_Message.mn_ReplyPort);
		prdebug("Received reply\n");

		RCode = msg->mrm_RCode;
		if(msg->mrm_FatalError)
		{
			prdebug("Fatal error in MUI requester code - using original function!\n");
			RCode = CallOldrtEZRA(bodyfmt,gadfmt,reqinfo,argarray,taglist,ReqToolsBase);
		}
		FreeMsgAndPort(msg);
	} else prdebug("Can't create message/port!\n");
	if(pwindow)
	{
		if(WaitPointer || LockWindow) ClearPointer(pwindow);		// reqtools compatible
		if(LockWindow) ModifyIDCMP(pwindow,IDCMPsaved);
	}
	prdebug("rtEZRequestAPatch() result: %ld\n",RCode);
	return RCode;


}

/*****************************************************************************
** GetCallingProgram()                                                       *
** Returns a pointer to the calling program's name (including directory),    *
** in a newly allocted buffer. Deallocate with FreeString() (mb_utils.lib)   *
** Parameters: pool : optional mempool to allocate buffer from               *
******************************************************************************/
static STRPTR GetCallingProgram(APTR pool)
{
STRPTR ProgName, ProgDir, Path=NULL;
BPTR DirLock;

	if(DirLock = GetProgramDir())
	{
	ULONG len;

		ProgDir	= mb_NameFromLock(pool,DirLock);
		ProgName	= mb_GetProgramName(pool);
		if(Path=AllocVecPooled(pool,len=strlen(ProgDir)+1+strlen(ProgName)+1))
		{
			strcpy(Path,ProgDir);
			if(!(AddPart(Path,ProgName,len)))
			{
				FreeVecPooled(pool,Path);
				Path = NULL;
			}
		}
		FreeString(pool,ProgDir);
		FreeString(pool,ProgName);
	}
	return Path;
}

/*****************************************************************************
** CreateMsgAndPort()                                                        *
** Allocates a struct MRQReqMessage already filled with info common to all   *
** patches.                                                                  *
** Parameters: IDCMPFlags : IDCMP flags to terminate the requester           *
******************************************************************************/

static struct MRQReqMessage *CreateMsgAndPort(ULONG IDCMPflags)
{
struct MRQReqMessage *msg;

	/* allocate a message structure */
	if(msg = AllocVec(sizeof(struct MRQReqMessage),MEMF_PUBLIC|MEMF_CLEAR)) // important for VMem systems!
	{
	struct MsgPort *RPort;

		/* create a reply port */
		if(RPort = CreateMsgPort())
		{
			msg->mrm_Message.mn_ReplyPort = RPort;

			/* common to all patches, so let's do it here! */
			msg->mrm_CallingProgram = GetCallingProgram(Config->mc_MemPool);

			if(IDCMPflags)
			{
			struct MUI_EventHandlerNode *meh;

				/* allocate an EventHandlerNode if any IDCMP bits were requested */
				if(meh = AllocVec(sizeof(struct MUI_EventHandlerNode),MEMF_PUBLIC|MEMF_CLEAR))
				{
					meh->ehn_Priority	= 0;
					meh->ehn_Flags		= 0;
					meh->ehn_Events	= IDCMPflags;
					meh->ehn_Class		= NULL;
					msg->mrm_EventHandler = meh;
					prdebug("IDCMP flags requested (0x%08.lx), eventhandler initialized\n",IDCMPflags);
				} else Alert(AG_NoMemory);
			}
			return msg;
		} else prdebug("Error creating reply port!\n");
		FreeVec(msg);
	} else Alert(AG_NoMemory);
	return NULL;
}



/*****************************************************************************
** FreeMsgAndPort()                                                          *
** Frees a struct MRQReqMessage allocated by CreateMsgAndPort()              *
******************************************************************************/
static void FreeMsgAndPort(struct MRQReqMessage *msg)
{
	DeleteMsgPort(msg->mrm_Message.mn_ReplyPort);
	if(msg->mrm_EventHandler) FreeVec(msg->mrm_EventHandler);
	if(msg->mrm_CallingProgram) FreeString(Config->mc_MemPool,msg->mrm_CallingProgram);
	FreeVec(msg);
}


/*****************************************************************************
** CheckAvoidTask()                                                          *
** Checks if the passed-in task matches the preconfigured AVOIDTASKS pattern *
** Parameters: task : task to check                                          *
** Returns TRUE if task matches pattern                                      *
******************************************************************************/
static BOOL CheckAvoidTask(struct Task *task)
{
	if(ttVars.AvoidTasks)
	{
	UBYTE buf[256], *name;

		name = task->tc_Node.ln_Name;

		if(task->tc_Node.ln_Type == NT_PROCESS)
		{
			if(GetProgramName(buf,sizeof(buf)) && strlen(buf))
			{
				name = buf;
			}
		}

		if(name)
		{
			if(MatchPattern(ttVars.AvoidTasks,name))
			{
				prdebug("Task name \"%s\" matches AVOIDTASKS list!\n",name);
				return TRUE;
			}
		}
	}
	return FALSE;
}

/*****************************************************************************/

/************************************************************************
**
** MUI_EasyRequestArgs()
** Since MRQ V1.5 this is no longer a replacement function for
** EasyRequestArgs() but must be called by the MRQ process!
**	Generalized for a couple of other requester functions, thus
** supporting features not present in EasyRequestArgs(), as of V1.7
*************************************************************************/
BOOL MUI_EasyRequestArgs(struct MRQReqMessage *msg)
{
STRPTR Title, TextFormat, GadgetFormat;
UBYTE tbuf[1024];
struct MRQEventClass *EventClass, DynEventClass;
struct MRQImage *ReqImage;
struct MUIP_Guigfx_ImageInfo IconImageInfo;
struct Screen *scr;
struct DiskObject *ProgramIcon=NULL;
APTR ButtonArgs;
BOOL IconShown=FALSE;
struct StuffCharParams StuffCharParams;
APTR Win, BtGrp, ReqImgObj;

	Title			= msg->mrm_Easy->es_Title;
	TextFormat	= msg->mrm_Easy->es_TextFormat;
	GadgetFormat= msg->mrm_Easy->es_GadgetFormat;

	if(ttVars.FrontmostScreen)
	{
	ULONG lock;

		lock = LockIBase(0);
		scr = ((struct IntuitionBase*)(IntuitionBase))->FirstScreen;
		UnlockIBase(lock);
	} else
	{
		if(msg->mrm_ParentWin)
		{
			scr = msg->mrm_ParentWin->WScreen;
		} else
		{
			msg->mrm_ReqScreen = scr = LockPubScreen(NULL);
		}
	}

	StuffCharParams.Position= 0;
	StuffCharParams.Dest		= tbuf;
	StuffCharParams.DestLen	= sizeof(tbuf);
	ButtonArgs = RawDoFmt(TextFormat,msg->mrm_ArgList,&RDF_StuffChar,&StuffCharParams);

	EventClass = AnalyzeReqText(TextFormat,tbuf);

	if((EventClass == &Config->mc_DefClass) && msg->mrm_CallingProgram)
	{
		prdebug("default class - trying icon\n",msg->mrm_CallingProgram);
		if(ProgramIcon = GetDiskObject(msg->mrm_CallingProgram))
		{
			prdebug("icon read\n");
			if(ProgramIcon->do_Gadget.Flags & GFLG_GADGIMAGE)
			{
				prdebug("image gadget found\n");
				memset(&DynEventClass,0,sizeof(struct MRQEventClass));			// clear
				IconImageInfo.Version = GUIGFX_IMAGEINFO_VERSION;
				IconImageInfo.Image = ProgramIcon->do_Gadget.GadgetRender;		// enter image pointer
				IconImageInfo.ColorTable = (ULONG*)MUIV_Guigfx_WBPalette;		// we want a new WB-like palette
				DynEventClass.mec_Image.mi_Object = &IconImageInfo;
				EventClass = &DynEventClass;
				IconShown = TRUE;
			} else
			{
				prdebug("Not an image gadget!\n");
				FreeDiskObject(ProgramIcon);
			}
		} else prdebug("Can't read icon for %s!\n",msg->mrm_CallingProgram);
	}

	ReqImage = msg->mrm_ReqImage = &EventClass->mec_Image;

	prdebug("Final requester text: \"%s\"\nMatched for image: %s\n",
		tbuf,(ReqImage->mi_Flags & MIF_FILENAME) ? ReqImage->mi_Object : (STRPTR)"<preloaded>");

	if(!Title) Title = (UBYTE*)((strchr(GadgetFormat,'|'))?"Request":"Information");

	if(ReqImage->mi_Flags & MIF_ANIMATION)
	{
		ReqImgObj = TransferAnimObject,
							MUIA_TransferAnim_File, ReqImage->mi_Object,
							MUIA_TransferAnim_FPS, 10,
						End;
	} else
	{
		ReqImgObj = GuigfxObject,
							(ReqImage->mi_Flags & MIF_FILENAME) ?
								MUIA_Guigfx_FileName :
								IconShown ?
									MUIA_Guigfx_ImageInfo :
									MUIA_Guigfx_Picture,
							ReqImage->mi_Object,
							MUIA_Guigfx_ScaleMode, GGSMF_NONE,
							MUIA_Guigfx_Quality, ttVars.Quality,
							MUIA_Guigfx_Transparency, ttVars.Transparency ? GGTRF_MASK : 0,
						End;
	}

	Win = MRQWindowObject,
		MUIA_Window_Title, Title,
		MUIA_Window_ScreenTitle, Title,
		MUIA_Window_Screen, scr,
		MUIA_Window_TopEdge, ttVars.MousedReq ? MUIV_Window_TopEdge_Moused : MUIV_Window_TopEdge_Centered,
		MUIA_Window_LeftEdge, ttVars.MousedReq? MUIV_Window_LeftEdge_Moused: MUIV_Window_LeftEdge_Centered,
		MUIA_Window_CloseGadget, FALSE,
		MUIA_Window_SizeGadget, ttVars.Sizeable,
		WindowContents, VGroup,
			Child, HGroup,
				MUIA_Frame, ttVars.SingleFrame ? MUIV_Frame_Text : MUIV_Frame_None,
				Child, VGroup,
					GroupSpacing(0),
					MUIA_Frame, ttVars.SingleFrame ? MUIV_Frame_None : MUIV_Frame_Text,
					Child, RectangleObject,	End,
					Child, ReqImgObj,
					Child, RectangleObject, End,
				End,
				Child, VGroup,
					GroupSpacing(0),
					MUIA_Frame, ttVars.SingleFrame ? MUIV_Frame_None : MUIV_Frame_Text,
					MUIA_Background, MUII_TextBack,
					Child, VSpace(0),
					Child, TextObject,
						MUIA_Text_Contents, tbuf,
						MUIA_Text_PreParse, ((!strchr(tbuf,'\n'))	||
													ttVars.Centered		||
													(msg->mrm_Flags & MRQMF_CENTERTEXT)) ? "\33c" : "\33l",
					End,
					Child, VSpace(0),
				End,
			End,
			Child, MUI_MakeObject(MUIO_HBar,5),
			Child, BtGrp = HGroup,
				MUIA_Group_SameWidth, ttVars.SameWidthButtons,
				MUIA_Group_SameHeight, TRUE,
			End,
		End,
	End;
	
	if(IconShown)
	{
		FreeDiskObject(ProgramIcon);
		prdebug("Freed icon\n");
	}

	if(Win)
	{
	STRPTR GadgetsText;

		prdebug("Created window object @@$%08lx\n",Win);

		msg->mrm_WindowObject = Win;

		set(Win,MRQWINDOWTAG_REQMESSAGE,msg);	/* keep this *before* the AddEventHandler call! */
		if(msg->mrm_EventHandler)
		{
			msg->mrm_EventHandler->ehn_Object = Win;
			DoMethod(Win,MUIM_Window_AddEventHandler,msg->mrm_EventHandler);
			prdebug("IDCMP bits requested by caller: %08lx\n",msg->mrm_EventHandler->ehn_Events);
		}

		if(GadgetsText = FormatButtonText(GadgetFormat, ButtonArgs))
		{
		char *ThisButton, *NextButton=GadgetsText;
		APTR TButtonP;
		BOOL defaultbutton, ButtonOK=TRUE;
		int i;

			ThisButton = mb_strtok(&NextButton,"|");
			for(	i=0;
					(ThisButton != NULL) && (i < MAXBUTTONS);
					ThisButton = mb_strtok(&NextButton,"|"),i++)
			{
				/* try to create a new MUI button */
				defaultbutton = (msg->mrm_DefaultAnswer==i+1) || ((NextButton==NULL) && (msg->mrm_DefaultAnswer==0));
				TButtonP = CreateMRQButton(ThisButton,(i==0),(NextButton==NULL),scr,msg->mrm_Underscore,defaultbutton);

				if(TButtonP)
				{
					DoMethod(BtGrp,OM_ADDMEMBER,TButtonP);

					DoMethod(TButtonP,MUIM_Notify,MUIA_Pressed,FALSE,TButtonP,3,
								MUIM_WriteLong,(NextButton||!i) ? i+1 : 0,&msg->mrm_RCode);

					DoMethod(TButtonP,MUIM_Notify,MUIA_Pressed,FALSE,Application,2,
								MUIM_Application_ReturnID,msg);

					if(i<10)
					{
					ULONG fstring=MAKE_ID('f',0,0,0);
					
						if(i==9) fstring |= MAKE_ID(0,'1','0',0);
						else fstring |= (i+1+'0')<<16;

						DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,&fstring,
									Win,3,MUIM_WriteLong,(NextButton||!i) ? i+1 : 0,&msg->mrm_RCode);

						DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,&fstring,
									Application,2,MUIM_Application_ReturnID,msg);
					}

					if(defaultbutton && (!(msg->mrm_Flags & MRQMF_NORETURNKEY)))
						set(Win,MUIA_Window_ActiveObject,TButtonP);
				} else
				{
					ButtonOK = FALSE;
					break;
				}
			}

			if(ButtonOK)
			{
				if(EventClass->mec_RxCmdString)
				{
					msg->mrm_ARexxPort= EventClass->mec_RxPortName ? EventClass->mec_RxPortName : (STRPTR)"PLAY";
					msg->mrm_ARexxCmd	= EventClass->mec_RxCmdString;
				}

				DoMethod(Application,OM_ADDMEMBER,Win);

				prdebug("Added window to application object\n");

				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"esc",
							Win,3,MUIM_WriteLong,0,&msg->mrm_RCode);
				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"esc",
							Application,2,MUIM_Application_ReturnID,msg);

				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand v",
							Win,3,MUIM_WriteLong,1,&msg->mrm_RCode);
				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand v",
							Application,2,MUIM_Application_ReturnID,msg);

				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand b",
							Win,3,MUIM_WriteLong,0,&msg->mrm_RCode);
				DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand b",
							Application,2,MUIM_Application_ReturnID,msg);


				set(Win,MUIA_Window_Open,TRUE);
			} else
			{
				prdebug("Error creating button objects!\n");
				msg->mrm_FatalError = TRUE;
			}
			FreeVec(GadgetsText);
		} else 
		{
			prdebug("Can't format gadget text!\n");
			msg->mrm_FatalError = TRUE;
		}
	} else
	{
		prdebug("Can't create window object!\n");
		msg->mrm_FatalError = TRUE;
	}

	if(!(ttVars.FrontmostScreen || msg->mrm_ParentWin)) UnlockPubScreen(NULL,scr);
	return (BOOL)(!msg->mrm_FatalError);
}

static STRPTR FormatButtonText(STRPTR GadgetFormat, APTR BtArgs)
{
STRPTR tbuf;
struct StuffCharParams scp;

	if(tbuf = AllocVec(GADBUFSIZE,MEMF_ANY))
	{
		scp.Position= 0;
		scp.Dest		= tbuf;
		scp.DestLen = GADBUFSIZE;
		RawDoFmt(GadgetFormat,BtArgs,&RDF_StuffChar,&scp);
	}
	return tbuf;
}

/************************************************************************
** AnalyzeReqText()
** This short piece of code is MRQ's "core", the text analyzer. It
** matches all strings in all MRQ event class structures against the
** supplied requester texts and returns a pointer to the first class that
** matches.
*************************************************************************/
static struct MRQEventClass *AnalyzeReqText(STRPTR Text, STRPTR FormattedText)
{
struct MRQEventClass *class;
struct MRQString *str;
BOOL match;
STRPTR tx;

	for(class=(struct MRQEventClass*)(Config->mc_ClassList.mlh_Head);
		class->mec_Node.mln_Succ;
		class = (struct MRQEventClass*)(class->mec_Node.mln_Succ))
	{
		for(str = (struct MRQString*)(class->mec_StringList.mlh_Head);
			str->ms_Node.mln_Succ;
			str = (struct MRQString*)(str->ms_Node.mln_Succ))
		{
			tx = (str->ms_Flags & MSF_FORMATTED) ? FormattedText : Text;

			if(str->ms_Flags & MSF_SUBSTRING)
			{
				if(str->ms_Flags & MSF_NOCASE)
					match = (BOOL)mb_stristr(tx,str->ms_String);
				else
					match = (BOOL)strstr(tx,str->ms_String);
			}
			else if(str->ms_Flags & MSF_PATTERN)
			{
				if(str->ms_Flags & MSF_NOCASE) match = MatchPatternNoCase(str->ms_String,tx);
				else match = MatchPattern(str->ms_String,tx);
			}
			else
			{
				if(str->ms_Flags & MSF_NOCASE) match = (stricmp(str->ms_String,tx) == 0);
				else match = (strcmp(str->ms_String,tx) == 0);
			}

			if(match) return class;
		}
	}
	return &Config->mc_DefClass;
}


/************************************************************************
** CreateMRQButton()
** The one and only button creation function, delegates work to 
** CreateImageButton() and CreateTextButton().
** Parameters:
** first/last: indicate if button to make is the first or last in a
**             requester
** scr       : screen to remap image stuff to, if any
** uscore    : character to be used as "underscore", this precedes any
**             character that is to be underlined and used as a keyboard
**             shortcut
** defbutton : indicates that this button is the default response button
**             and its text should be printed in boldface
** 
*************************************************************************/
static APTR CreateMRQButton(STRPTR text, BOOL first, BOOL last, struct Screen *scr, UBYTE uscore, BOOL defbutton)
{
STRPTR PMatchText, PParseText;
APTR ret=NULL;
UWORD cchar=0;	// MUI button controlchar


	if(uscore)
	{
		if((cchar = PreParseButtonText(text,uscore,defbutton,&PMatchText,&PParseText)) == -1) return NULL;
	} else
	{
		PMatchText = PParseText = text;
	}

	/* analyze text if requested, unless button is the first one and should be marked "OK" */
	if(ttVars.IButtonsByText && (!(first && ttVars.SingleIsOK)))
	{
	int i;
	STRPTR s;
	struct MRQImageButton *ibuttons[3];
	UBYTE stringbuf[256];
	static BOOL ButtonUsed[3];

		ibuttons[0] = &Config->mc_IButton_Yes;
		ibuttons[1] = &Config->mc_IButton_No;
		ibuttons[2] = &Config->mc_IButton_Cancel;

		if(first) ButtonUsed[0] = ButtonUsed[1] = ButtonUsed[2] = FALSE;

		for(i=0; i<3; i++)		
		{
			if(ButtonUsed[i]) continue;		// don't use same button twice
			mb_strlimcpy(stringbuf,ibuttons[i]->mib_Text,256);
			s = strtok(stringbuf,"|");
			while(s)
			{
				if(mb_stristr(PMatchText,s))
				{
					prdebug("CreateMRQButton(): matched '%s' -> button #%ld\n",s,i);
					ButtonUsed[i] = TRUE;
					ret = CreateImageButton(PParseText,ibuttons[i],scr,cchar,defbutton);
				}
				s = strtok(NULL,"|");
			}
		}
	} else
	{
		if(first && Config->mc_IButton_Yes.mib_Picture)
		{
			ret = CreateImageButton(PParseText,&Config->mc_IButton_Yes,scr,cchar,defbutton);
		} else if(last && Config->mc_IButton_No.mib_Picture)
		{
			ret = CreateImageButton(PParseText,&Config->mc_IButton_No,scr,cchar,defbutton);
		}
	}
	if(!ret) ret = CreateTextButton(PParseText,cchar,defbutton);
	prdebug("CreateMRQButton: button created @@$%08.lx\n",ret);

	if(uscore)
	{
		FreeVecPooled(Config->mc_MemPool,PMatchText);
		FreeVecPooled(Config->mc_MemPool,PParseText);
	}
	set(ret,MUIA_CycleChain,1);
	return ret;
}



/************************************************************************
** CreateImageButton()
** Creates a button with text an an image on the left
**
** ctlchar and defbutton: see CreateTextButton()
*************************************************************************/
static APTR CreateImageButton(STRPTR text, struct MRQImageButton *img, struct Screen *scr, UBYTE ctlchar, BOOL defbutton)
{
APTR button;

	button = 
	VGroup,
		ButtonFrame,
		MUIA_InputMode, MUIV_InputMode_RelVerify,
		MUIA_Background, MUII_ButtonBack,
		Child, VSpace(0),
		Child, HGroup,
			Child, GuigfxObject,
				MUIA_Guigfx_Picture, img->mib_Picture,
				MUIA_Guigfx_ScaleMode, GGSMF_NONE,
				MUIA_Guigfx_Quality, ttVars.Quality,
				MUIA_Guigfx_Transparency, GGTRF_MASK,
			End,
			Child, TextObject,
				MUIA_Font, MUIV_Font_Button,
				MUIA_Text_Contents, text,
				MUIA_Text_PreParse, (defbutton ? "\33c\33b" : "\33c"),
			End,
		End,
		Child, VSpace(0),
	End;

	if(button && ctlchar)
	{
		set(button,MUIA_ControlChar,(LONG)ctlchar);
	}

	return button;
}

/************************************************************************
** CreateTextButton()
** Creates a button with only text in it.
** Optional: text rendering in boldface if defbutton is set; keyboard
** shortcut if ctlchar is set
*************************************************************************/
static APTR CreateTextButton(STRPTR text, UBYTE ctlchar, BOOL defbutton)
{
APTR button;

	if(Config->mc_IButton_Yes.mib_Picture ||
		Config->mc_IButton_No.mib_Picture  ||
		Config->mc_IButton_Cancel.mib_Picture)
	{
	/* use a height adaptive layout if imagebuttons are used */
		button =
		VGroup,
			ButtonFrame,
			MUIA_InputMode, MUIV_InputMode_RelVerify,
			MUIA_Background, MUII_ButtonBack,
			Child, VSpace(0),
			Child, TextObject,
				MUIA_Font, MUIV_Font_Button,
				MUIA_Text_Contents, text,
				MUIA_Text_PreParse, (defbutton ? "\33c\33b" : "\33c"),
			End,
			Child, VSpace(0),
		End;
	} else
	{
		button =
		TextObject,
		ButtonFrame,
		MUIA_InputMode, MUIV_InputMode_RelVerify,
		MUIA_Background, MUII_ButtonBack,
			MUIA_Font, MUIV_Font_Button,
			MUIA_Text_Contents, text,
			MUIA_Text_PreParse, (defbutton ? "\33c\33b" : "\33c"),
		End;
	}

	if(button && ctlchar)
	{
		set(button,MUIA_ControlChar,(LONG)ctlchar);
	}

	return button;
}


/************************************************************************
** PreParseButtonText()
** Using a certain "underscore" character, this function scans the input
** text and generates two variants: one for pattern matching, without
** the underscore character(s), one for MUI, including formatting codes
** to set the font style to "underlined" for the one character following
** the first "underscore" and "boldface" for the default button.
** Returns the character to use for the button's MUIA_ControlChar or -1
** on failure
*************************************************************************/
static WORD PreParseButtonText(STRPTR text, UBYTE uscore, BOOL defbutton, STRPTR *PMatchText, STRPTR *PParseText)
{
ULONG slen;
WORD hichar=0;

	slen = strlen(text)+1;

	if((*PMatchText = AllocVecPooled(Config->mc_MemPool,slen)) &&
		(*PParseText = AllocVecPooled(Config->mc_MemPool,slen+6)))
	{
	STRPTR s,t;
	UBYTE c;

		s = *PMatchText;
		t = text;
		do
		{
			c = *t++;
			if(c != uscore) *s++ = c;	// omit <underscore> characters
		} while(c);

		s = *PParseText;
		t = text;
		do
		{
			c = *t++;
			if(c == uscore)
			{
				*s++ = 0x1b;				// ESC
				*s++ = 'u';					// underline
				*s++ = hichar = *t++;	// save underlined character
				*s++ = 0x1b;				// ESC
				*s++ = 'n';					// normal
				if(defbutton)
				{
					*s++ = 0x1b;			// ESC
					*s++ = 'b';				// boldface
				}
					
				do
				{
					c = *t++;
					if(c != uscore) *s++ = c;	// just omit further <underscore> characters
				} while(c);
			} else
			{
				*s++ = c;
			}
		} while(c);

		hichar = tolower(hichar);

		return hichar;
	} else
	{
		if(PMatchText) FreeVecPooled(Config->mc_MemPool,PMatchText);
		return -1;
	}
}
@


1.3
log
@Changed NewImage.mcc -> Guigfx.mcc
@
text
@d13 1
a13 1
/* $Id: Requesters.c 1.2 2000/01/25 17:30:22 msbethke Exp msbethke $
d16 3
d55 1
d64 4
d86 4
a89 4
	if((MyTask->tc_Node.ln_Type == NT_PROCESS) && (!pwindow))
	{
		pwindow = ((struct Process*)MyTask)->pr_WindowPtr;
	}
d163 3
a165 2
	if((MyTask->tc_Node.ln_Type == NT_PROCESS) && (!pwindow))
		pwindow = ((struct Process*)MyTask)->pr_WindowPtr;
d416 1
a416 1
UBYTE tbuf[1024], gadbuf[128];
a420 1
struct Window *ParentWindow;
d422 2
a423 3
STRPTR s,ts;
APTR BtArgs;
BOOL MoreButtons, GoodButtons, IconShown=FALSE;
a424 1

a429 1
	ParentWindow= msg->mrm_ParentWin;
d440 1
a440 1
		if(ParentWindow)
d442 1
a442 1
			scr = ParentWindow->WScreen;
d452 1
a452 1
	BtArgs = RawDoFmt(TextFormat,msg->mrm_ArgList,&RDF_StuffChar,&StuffCharParams);
d466 1
a466 1
				IconImageInfo.Version = NEWIMAGE_IMAGEINFO_VERSION;
d502 1
a502 1
							MUIA_Guigfx_ScaleMode, NISMF_NONE,
d504 1
a504 1
							MUIA_Guigfx_Transparency, ttVars.Transparency ? NITRF_MASK : 0,
d556 1
a556 3
	APTR TButtonP;
	BOOL defaultbutton;
	int i;
d562 1
a562 2
		set(Win,MRQWINDOWTAG_REQMESSAGE,msg);	// keep this *before*
															// the AddEventHandler call!
d570 1
a570 9
		StuffCharParams.Position= 0;
		StuffCharParams.Dest		= tbuf;
		StuffCharParams.DestLen = sizeof(tbuf);
		
		RawDoFmt(GadgetFormat,BtArgs,&RDF_StuffChar,&StuffCharParams);

		ts = s = tbuf;

		for(i=0,MoreButtons=GoodButtons=TRUE; MoreButtons&&GoodButtons;)
d572 13
a584 2
			/* advance to next gadget marker */
			while(*s && (*s != '|')) s++;
d586 3
a588 3
			/* if neither current nor next-to-current char is 0 and i has not reached
				MAXBUTTONS yet, then there will be more gadgets */
			MoreButtons = ((s[0] != '\0') && (s[1] != '\0') && (i<MAXBUTTONS));
d590 2
a591 3
			/* copy substring and terminate it */
			memcpy(gadbuf,ts,(size_t)(max(s-ts,sizeof(gadbuf)-1)));
			gadbuf[s-ts] = '\0';
d593 2
a594 2
			/* set ts to start of next gadgetformat string */
			ts = ++s;
d596 22
a617 4
			/* try to create a new MUI button */
			TButtonP = CreateMRQButton(gadbuf,!i,!MoreButtons,scr,msg->mrm_Underscore,
												defaultbutton= (msg->mrm_DefaultAnswer==i+1) ||
																	(!MoreButtons&&(msg->mrm_DefaultAnswer==0)));
d619 1
a619 1
			if(TButtonP)
d621 5
a625 1
				DoMethod(BtGrp,OM_ADDMEMBER,TButtonP);
d627 1
a627 2
				DoMethod(TButtonP,MUIM_Notify,MUIA_Pressed,FALSE,TButtonP,3,
							MUIM_WriteLong,(MoreButtons||!i)?i+1:0,&msg->mrm_RCode);
d629 1
a629 2
				DoMethod(TButtonP,MUIM_Notify,MUIA_Pressed,FALSE,Application,2,
							MUIM_Application_ReturnID,msg);
d631 4
a634 6
				if(i<10)
				{
				ULONG fstring=MAKE_ID('f',0,0,0);
				
					if(i==9) fstring |= MAKE_ID(0,'1','0',0);
					else fstring |= (i+1+'0')<<16;
d636 4
a639 2
					DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,&fstring,
								Win,3,MUIM_WriteLong,(MoreButtons||!i)?i+1:0,&msg->mrm_RCode);
d641 4
a644 3
					DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,&fstring,
								Application,2,MUIM_Application_ReturnID,msg);
				}
a645 2
				if(defaultbutton && (!(msg->mrm_Flags & MRQMF_NORETURNKEY)))
					set(Win,MUIA_Window_ActiveObject,TButtonP);
d647 1
a647 1
				i++;
d650 2
a651 11
				GoodButtons = FALSE;
				break;
			}
		}

		if(GoodButtons)
		{
			if(EventClass->mec_RxCmdString)
			{
				msg->mrm_ARexxPort= EventClass->mec_RxPortName ? EventClass->mec_RxPortName : (STRPTR)"PLAY";
				msg->mrm_ARexxCmd	= EventClass->mec_RxCmdString;
d653 2
a654 23

			DoMethod(Application,OM_ADDMEMBER,Win);

			prdebug("Added window to application object\n");

			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"esc",
						Win,3,MUIM_WriteLong,0,&msg->mrm_RCode);
			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"esc",
						Application,2,MUIM_Application_ReturnID,msg);

			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand v",
						Win,3,MUIM_WriteLong,1,&msg->mrm_RCode);
			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand v",
						Application,2,MUIM_Application_ReturnID,msg);

			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand b",
						Win,3,MUIM_WriteLong,0,&msg->mrm_RCode);
			DoMethod(Win,MUIM_Notify,MUIA_Window_InputEvent,"lcommand b",
						Application,2,MUIM_Application_ReturnID,msg);


			set(Win,MUIA_Window_Open,TRUE);
		} else
d656 1
a656 1
			prdebug("Error creating button objects!\n");
d665 1
a665 1
	if(!(ttVars.FrontmostScreen || ParentWindow)) UnlockPubScreen(NULL,scr);
d669 14
d763 2
a764 1
	if(ttVars.IButtonsByText)
d787 1
d799 1
a799 2
		} 
		if(last && Config->mc_IButton_No.mib_Picture)
d837 1
a837 1
				MUIA_Guigfx_ScaleMode, NISMF_NONE,
d839 1
a839 1
				MUIA_Guigfx_Transparency, NITRF_MASK,
@


1.2
log
@Adapted to new header names
Fixed obsolete NewImage.mcc tag names/structures
@
text
@d13 1
a13 1
/* $Id: Requesters.c 1.1 2000/01/25 16:57:49 msbethke Exp msbethke $
d16 4
d33 2
a43 1
#include "MUI/NewImage_mcc.h"
d410 1
a410 1
struct MUIP_NewImage_ImageInfo IconImageInfo;
d453 1
a453 1
		prdebug("default class - trying icon\n");
d463 1
a463 1
				IconImageInfo.ColorTable = (ULONG*)MUIV_NewImage_WBPalette;		// we want a new WB-like palette
d482 21
d518 1
a518 8
					Child, ReqImgObj = NewImageObject,
							(ReqImage->mi_Flags & MIF_FILENAME) ? MUIA_NewImage_FileName :
							IconShown ? MUIA_NewImage_ImageInfo : MUIA_NewImage_Picture,
						ReqImage->mi_Object,
						MUIA_NewImage_ScaleMode, NISMF_NONE,
						MUIA_NewImage_Quality, ttVars.Quality,
						MUIA_NewImage_Transparency, ttVars.Transparency ? NITRF_MASK : 0,
					End,
d827 5
a831 5
			Child, NewImageObject,
				MUIA_NewImage_Picture, img->mib_Picture,
				MUIA_NewImage_ScaleMode, NISMF_NONE,
				MUIA_NewImage_Quality, ttVars.Quality,
				MUIA_NewImage_Transparency, NITRF_MASK,
@


1.1
log
@Initial revision
@
text
@d13 5
a17 1
/* $Id:$
a18 1
** $Log:$
d34 2
a35 2
#include "mrq_config.h"
#include "mrq_dtypes.h"
d405 1
a405 1
struct NewImage_ImageInfo IconImageInfo;
d494 1
a494 1
							IconShown ? MUIA_NewImage_Image : MUIA_NewImage_Picture,
@
