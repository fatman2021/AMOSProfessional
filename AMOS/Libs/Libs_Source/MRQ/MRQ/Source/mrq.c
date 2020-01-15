/* mrq.c
** Main program source for MRQ, the MUI Requester Improver
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: mrq.c 1.4 2000/03/30 23:17:52 msbethke Exp $
**
** $Log: mrq.c $
** Revision 1.4  2000/03/30 23:17:52  msbethke
** Changed NewImage.mcc -> Guigfx.mcc
**
** Revision 1.3  2000/02/16 18:25:42  msbethke
** Disabled DOS requesters for MRQ's main process to avoid deadlocks
**
** Revision 1.2  2000/01/25 17:28:05  msbethke
** Adapted to new header names
**
** Revision 1.1  2000/01/25 16:43:18  msbethke
** Initial revision
**
*/

#include <proto/icon.h>
#include <proto/intuition.h>
#include <proto/rexxsyslib.h>
#include <proto/commodities.h>
#include <proto/datatypes.h>
#include <proto/wbstart.h>
#include <clib/debug_protos.h>
#include <libraries/reqtools.h>
#include <guigfx/guigfx.h>
#include <exec/memory.h>
#include <dos/dostags.h>
#include <lib/mb_utils.h>
#include <MUI/Guigfx_mcc.h>
#include <dos.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mrq.h"
#include "config.h"
#include "mui_macros.h"
#include "muistuff.h"
#include "Requesters.h"
#include "MRQasm.h"
#include "mrqwindowclass.h"

#define RTEZREQUESTA_OFFSET (-66)
#define EASYREQUESTARGS_OFFSET (-588)

#define GUIGFXLIB_NAME "guigfx.library"
#define GUIGFXLIB_VMIN 15
#define REQTOOLSLIB_NAME "reqtools.library"
#define REQTOOLSLIB_VMIN 0
#define CGFXLIB_NAME "cybergraphics.library"
#define CGFXLIB_VMIN 0

/*************************************************************************/
/* local protos & dummy functions                                        */
/*************************************************************************/
static BOOL OpenLibs(void);
static void CloseLibs(void);
static BOOL BuildApp(void);
static void DisposeApp(APTR app);
static APTR ReadToolTypes(struct WBStartup*);
static APTR ReadShellParams(void);
static STRPTR FindConfigFile(void);
static BOOL CheckDir(STRPTR);
static BOOL AskQuit(void);
static BOOL CheckPatchManager(void);
static LONG DecodeQuality(STRPTR);
static void StartExternalProgram(STRPTR);
static BOOL ExistsIcon(STRPTR);
static BOOL CreateCustomClasses(void);
static void DeleteCustomClasses(void);
/* dummies */
void __regargs _CXBRK(void) {}
void chkabort(void) {}


/*************************************************************************/
/* global identifiers                                                    */
/*************************************************************************/
APTR OldEasyRequestArgs, OldrtEZRequestA, Application;
struct MUI_CustomClass *MUIMRQWindowClass;
struct IClass *MRQWindowClass;
UBYTE ProgName[80]={0};
struct TTVars ttVars = {0};
struct MRQConfig *Config;
const UBYTE VersionString[]="$VER: MRQ 2.1 by M.Bethke "__AMIGADATE__;
struct Library *MUIMasterBase, *GuiGFXBase, *CyberGfxBase;
struct ReqToolsBase *ReqToolsBase;
struct MsgPort *MainPort;
LONG AppActive=TRUE;
LONG __stack = 12288;
BPTR _debugfh=NULL;
STRPTR true_s="TRUE", false_s="FALSE",
		 none_s="<none>", unset_s="<unset>";	// take some work off the stringmerger
/*************************************************************************/
/* hooks                                                                 */
/*************************************************************************/
static void __saveds __asm __interrupt BrokerHookFunc(register __a1 CxMsg*, register __a2 APTR);
struct Hook BrokerHook = {{NULL,NULL},(void*)(&BrokerHookFunc),NULL,NULL};



/*************************************************************************/

LONG main(int argc, char *argv[])
{
LONG rcode = RETURN_OK;
APTR Args;
STRPTR ConfigName;
static const UBYTE MRQRendezvousPort[] = "MRQ.Rendezvous";
struct Process *MyProc;
APTR MyWindowPtr;

	if(!GetProgramName(ProgName,sizeof(ProgName))) strcpy(ProgName,"MRQ");

	MyProc = (struct Process*)FindTask(NULL);
	MyWindowPtr = MyProc->pr_WindowPtr;
	MyProc->pr_WindowPtr = (APTR)-1;

	if(FindPort((STRPTR)MRQRendezvousPort))
	{
		if(argc)
		{
			Printf("%s: already running!\n",*argv);
		} else
		{
		struct EasyStruct es={sizeof(struct EasyStruct),0,"MRQ Error","Please don't start me twice!","I won't!"};

			EasyRequestArgs(NULL,&es,NULL,NULL);
		}
		return RETURN_WARN;
	}

	if(argc)	Args = ReadShellParams();
	else Args = ReadToolTypes((struct WBStartup*)argv);

	if(!Args) return RETURN_FAIL;

	if(!(ConfigName = FindConfigFile()))
	{
	struct EasyStruct es={sizeof(struct EasyStruct),0,"MRQ Error","Can't find config file!","I see"};

		EasyRequestArgs(NULL,&es,NULL,NULL);
		if(argc) FreeArgs((struct RDArgs*)Args);
		else FreeDiskObject((struct DiskObject*)Args);
		return RETURN_ERROR;
	}

	if(ttVars.DefImageDir == NULL || (!CheckDir(ttVars.DefImageDir)))
	{
		if(!CheckDir(ttVars.DefImageDir="PROGDIR:MRQ-images"))
		{
			if(!CheckDir(ttVars.DefImageDir="s:MRQ-images"))
			{
			struct EasyStruct es={sizeof(struct EasyStruct),0,"MRQ Error","Can't find image directory!","I see"};

				EasyRequestArgs(NULL,&es,NULL,NULL);
				if(argc) FreeArgs((struct RDArgs*)Args);
				else FreeDiskObject((struct DiskObject*)Args);
				return RETURN_ERROR;
			}
		}
	}

	if(ttVars.Debug)									// debug info wanted
	{
		if(!argc || strlen(ttVars.Debug))		// WB-start or file specified
		{
			_debugfh=Open(strlen(ttVars.Debug) ?
								ttVars.Debug :				// file specified
								(STRPTR)"CON:40/80/640/180/MRQ_CONSOLE",MODE_NEWFILE);	// default
		} else
		{
			_debugfh = Output();						// use stdout
		}
	}

	prdebug(	"Started %s\n\n"
				"Parameters read:\n\tCONFIGFILE    : %s\n\tMOUSEREQ      : %s\n\t"
				"SAMEWIDTH     : %s\n\tFRONTSCREEN   : %s\n\tTRANSPARENCY  : %s\n\t"
				"SINGLEFRAME   : %s\n\tSIZEABLE      : %s\n\tCENTERTEXT    : %s\n\t"
				"NORTPATCH     : %s\n\tIMAGES        : %s\n\t"
				"QUALITY       : %s\n\tIMG_YES       : %s\n\tIMG_NO        : %s\n\t"
				"IMG_CANCEL    : %s\n\tIBUTTONSBYTEXT: %s\n\tSINGLE_IS_OK  : %s\n\t"
				"AFTERPATCH    : %s\n\tAVOIDTASKS    : %s\n\n",
		VersionString+6,
		ConfigName,
		ttVars.MousedReq			? true_s : false_s,
		ttVars.SameWidthButtons	? true_s : false_s,
		ttVars.FrontmostScreen	? true_s : false_s,
		ttVars.Transparency		? true_s : false_s,
		ttVars.SingleFrame		? true_s : false_s,
		ttVars.Sizeable			? true_s : false_s,
		ttVars.Centered			? true_s : false_s,
		ttVars.NoRTPatch			? true_s : false_s,
		ttVars.DefImageDir,
		(ttVars.Quality==MUIV_Guigfx_Quality_Best) ? "Best" : 
		(ttVars.Quality==MUIV_Guigfx_Quality_Medium) ? "Medium" : 
		(ttVars.Quality==MUIV_Guigfx_Quality_High) ? "High" : "Low",
		ttVars.IB_Yes		? ttVars.IB_Yes	: none_s,
		ttVars.IB_No		? ttVars.IB_No		: none_s,
		ttVars.IB_Cancel	? ttVars.IB_Cancel: none_s,
		ttVars.IButtonsByText	? ttVars.IButtonsByText	: unset_s,
		ttVars.SingleIsOK			? true_s : false_s,
		ttVars.AfterPatch			? ttVars.AfterPatch		: unset_s,
		ttVars.AvoidTasks			? ttVars.AvoidTasks		: unset_s
		);

	if(OpenLibs())
	{
		if(Config = ReadMRQConfig(ConfigName))
		{
			if(MainPort = CreateMsgPort())
			{
				MainPort->mp_Node.ln_Name = (STRPTR)MRQRendezvousPort;
				MainPort->mp_Node.ln_Pri = -128;
				AddPort(MainPort);

				if(BuildApp())
				{
				ULONG sigs, result;
				BOOL running=TRUE;
				struct MsgPort *RexxRPort;
		
					if(CreateCustomClasses())
					{
						if(RexxRPort = CreateMsgPort())
						{
						LONG RexxMPending=0,	RexxPortSignal, MainPortSignal;
			
							RexxPortSignal = 1<<(RexxRPort->mp_SigBit);
							MainPortSignal = 1<<(MainPort->mp_SigBit);

							OldEasyRequestArgs = SetFunction((struct Library*)IntuitionBase,EASYREQUESTARGS_OFFSET,(APTR)(&EasyRequestArgsPatch));
							prdebug("SetFunction() called on %s\n","intuition.library/EasyRequestArgs()");
							if(ReqToolsBase)				// obviously, only patch if RT found
							{
								if(ttVars.NoRTPatch)		// if no reqtools patching desired
								{
									CloseLibrary((struct Library*)ReqToolsBase);	// close early
									ReqToolsBase = NULL;
								} else
								{
									OldrtEZRequestA = SetFunction((struct Library*)ReqToolsBase,RTEZREQUESTA_OFFSET,(APTR)(&rtEZRequestA_Wedge));
									prdebug("SetFunction() called on %s\n","reqtools.library/rtEZRequestA()");
								}
							}

							if(ttVars.AfterPatch) StartExternalProgram(ttVars.AfterPatch);
							
							prdebug("Entering main loop\n\n");
							while(running)
							{
								result = DoMethod(Application,MUIM_Application_NewInput,&sigs);
			
								switch(result)
								{
									case MUIV_Application_ReturnID_Quit :
										running = !AskQuit();
										break;
			
									default :
										if(result && (!(result & 0x01)))
										{
										struct MRQReqMessage *msg;

											msg = (struct MRQReqMessage*)result;

											if(msg->mrm_EventHandler)
											{
												DoMethod(msg->mrm_WindowObject,
															MUIM_Window_RemEventHandler,
															msg->mrm_EventHandler);
											}
											DoMethod(Application,OM_REMMEMBER,msg->mrm_WindowObject);
											DisposeObject(msg->mrm_WindowObject);
											ReplyMsg((struct Message*)msg);
										}
								}
								if(sigs)
								{
									sigs = Wait(sigs | RexxPortSignal | MainPortSignal | SIGBREAKF_CTRL_C);

									if(sigs & SIGBREAKF_CTRL_C)	// got break signal
									{
										prdebug("Ctrl-C received\n");
										running = FALSE;
										continue;
									}

									if(sigs & MainPortSignal)		// have to set up a new requester
									{
									struct MRQReqMessage *msg;

										if(!(msg = (struct MRQReqMessage*)GetMsg(MainPort)))
										{
											DisplayBeep(NULL);
											continue;
										}

										MUI_EasyRequestArgs(msg);		// setup the entire requester

										if(msg->mrm_FatalError)			// handle errors
										{
											ReplyMsg((struct Message*)msg);
											continue;
										}

										if(msg->mrm_ARexxCmd)			// have to dispatch an ARexx command
										{
										struct RexxMsg *rmsg;

											prdebug("Sending ARexx message:\n\tPORT: '%s'\n\tCMND: '%s'...",msg->mrm_ARexxPort,msg->mrm_ARexxCmd);
		
											if(rmsg = CreateRexxMsg(RexxRPort,NULL,msg->mrm_ARexxPort))
											{
												rmsg->rm_Action	= RXCOMM;
												rmsg->rm_Args[0]	= msg->mrm_ARexxCmd;
												if(FillRexxMsg(rmsg,1,0))
												{
												struct MsgPort *RxDestPort;

													Forbid();
													if(RxDestPort = FindPort(msg->mrm_ARexxPort))
													{
														PutMsg(RxDestPort,(struct Message*)rmsg);
														RexxMPending++;
														Permit();
														prdebug("OK!\n");
													} else
													{
														Permit();
														prdebug("port not found!\n");
													}
												} else prdebug("FillRexxMsg() failed!\n");
											} else prdebug("can't create rexx message!\n");
										}
									}

									if(sigs & RexxPortSignal)		// got ARexx demon reply
									{
									struct RexxMsg *rmsg;
			
										while(rmsg = (struct RexxMsg*)GetMsg(RexxRPort))
										{
											ClearRexxMsg(rmsg,1);
											DeleteRexxMsg(rmsg);
											RexxMPending--;
											prdebug("Rexxhost reply received\n");
										}
									}
								}
							}

							if(ReqToolsBase)
							{
								SetFunction((struct Library*)ReqToolsBase,RTEZREQUESTA_OFFSET,OldrtEZRequestA);
								prdebug("rtEZRequestA()-patch removed\n");
							}
							SetFunction((struct Library*)IntuitionBase,EASYREQUESTARGS_OFFSET,OldEasyRequestArgs);
							prdebug("EasyRequestArgs()-patch removed\n");
							while(RexxMPending)
							{
								WaitPort(RexxRPort);
								GetMsg(RexxRPort);
							}
							DeleteMsgPort(RexxRPort);
						} else
						{
							prdebug("Can't create ARexx communication port!\n");
							rcode=RETURN_FAIL;
						}
						DeleteCustomClasses();
					} else
					{
						prdebug("Can't create custom classes!\n");
						rcode=RETURN_FAIL;
					}
					DisposeApp(Application);		
					prdebug("Disposed of MUI app\n");
				} else
				{
					prdebug("Can't build MUI application object!\n");
					rcode=RETURN_FAIL;
				}
				RemPort(MainPort);
				DeleteMsgPort(MainPort);
			}
			FreeMRQConfig(Config);
		} else rcode=RETURN_FAIL;
		CloseLibs();
	} else rcode=RETURN_FAIL;

	if(_debugfh)										// debug output being printed
	{
		if(strlen(ttVars.Debug) || !argc)		// file specified or WB-start
			Close(_debugfh);
	}

	if(argc) FreeArgs((struct RDArgs*)Args);
	else FreeDiskObject((struct DiskObject*)Args);

	MyProc->pr_WindowPtr = MyWindowPtr;

	return rcode;
}

/*************************************************************************/

static BOOL OpenLibs(void)
{
struct EasyStruct es={sizeof(struct EasyStruct),0,"MRQ Error","Can't open %s V%ld+!","Dammit!"};

	ReqToolsBase = (struct ReqToolsBase*)OpenLibrary(REQTOOLSLIB_NAME, REQTOOLSLIB_VMIN);	// optional
	CyberGfxBase = OpenLibrary(CGFXLIB_NAME,CGFXLIB_VMIN); 			// optional
	if(MUIMasterBase = OpenLibrary(MUIMASTER_NAME,MUIMASTER_VMIN))
	{
		if(GuiGFXBase = OpenLibrary(GUIGFXLIB_NAME,GUIGFXLIB_VMIN))
		{
			return TRUE;
		} else
		{
			EasyRequest(NULL,&es,NULL,GUIGFXLIB_NAME,GUIGFXLIB_VMIN);
			CloseLibs();
		}
	} else
	{
		EasyRequest(NULL,&es,NULL,MUIMASTER_NAME,MUIMASTER_VMIN);
	}
	return FALSE;	
}

static void CloseLibs(void)
{
	if(MUIMasterBase) CloseLibrary(MUIMasterBase);
	if(ReqToolsBase) CloseLibrary((struct Library*)ReqToolsBase);
}

/*************************************************************************/

static BOOL BuildApp(void)
{
	Application = ApplicationObject,
		MUIA_Application_Title      , "MRQ",
		MUIA_Application_Version    , VersionString,
		MUIA_Application_Copyright  , "Matthias Bethke",
		MUIA_Application_Author     , "Matthias Bethke",
		MUIA_Application_Description, "A requester replacement using MUI",
		MUIA_Application_Base       , "MRQ",
		MUIA_Application_SingleTask , TRUE,
		MUIA_Application_BrokerHook , &BrokerHook,
		End;

	if(Application)
	{
		DoMethod(Application,MUIM_Notify,MUIA_Application_Active,MUIV_EveryTime,
					MUIV_Notify_Self,3,MUIM_WriteLong,MUIV_TriggerValue,&AppActive);
	}
	return (BOOL)Application;
}


static void DisposeApp(APTR app)
{
	if(app) MUI_DisposeObject(app);
}

/*************************************************************************/

static APTR ReadToolTypes(struct WBStartup *msg)
{
struct DiskObject *dob;
BPTR olddir=0, homedir;

	if(!(msg->sm_NumArgs)) return NULL;
	homedir = msg->sm_ArgList[0].wa_Lock;
	if(homedir) olddir = CurrentDir(homedir);

	if(dob = GetDiskObject(msg->sm_ArgList[0].wa_Name))
	{
		ttVars.ConfigName			= FindToolType(dob->do_ToolTypes,"CONFIGFILE");
		ttVars.Debug				= FindToolType(dob->do_ToolTypes,"DEBUG");
		ttVars.MousedReq			= (LONG)FindToolType(dob->do_ToolTypes,"MOUSEREQ");
		ttVars.SameWidthButtons	= (LONG)FindToolType(dob->do_ToolTypes,"SAMEWIDTH");
		ttVars.FrontmostScreen	= (LONG)FindToolType(dob->do_ToolTypes,"FRONTSCREEN");
		ttVars.SingleFrame		= (LONG)FindToolType(dob->do_ToolTypes,"SINGLEFRAME");
		ttVars.Transparency		= (LONG)FindToolType(dob->do_ToolTypes,"TRANSPARENCY");
		ttVars.Sizeable			= (LONG)FindToolType(dob->do_ToolTypes,"SIZEABLE");
		ttVars.Centered			= (LONG)FindToolType(dob->do_ToolTypes,"CENTERTEXT");
		ttVars.NoRTPatch			= (LONG)FindToolType(dob->do_ToolTypes,"NORTPATCH");
		ttVars.DefaultIcon		= (LONG)FindToolType(dob->do_ToolTypes,"DEFAULTICON");
		ttVars.SingleIsOK			= (LONG)FindToolType(dob->do_ToolTypes,"SINGLE_IS_OK");
		ttVars.DefImageDir		= FindToolType(dob->do_ToolTypes,"IMAGES");
		ttVars.IButtonsByText	= FindToolType(dob->do_ToolTypes,"IBUTTONSBYTEXT");
		ttVars.IB_Yes				= FindToolType(dob->do_ToolTypes,"IMG_YES");
		ttVars.IB_No				= FindToolType(dob->do_ToolTypes,"IMG_NO");
		ttVars.IB_Cancel			= FindToolType(dob->do_ToolTypes,"IMG_CANCEL");
		ttVars.AfterPatch			= FindToolType(dob->do_ToolTypes,"AFTERPATCH");
		ttVars.AvoidTasks			= FindToolType(dob->do_ToolTypes,"AVOIDTASKS");

		ttVars.Quality				= DecodeQuality(FindToolType(dob->do_ToolTypes,"QUALITY"));
	} else PrintFault(IoErr(),ProgName);
	if(olddir) CurrentDir(olddir);
	return (APTR)dob;
}

static APTR ReadShellParams(void)
{
struct RDArgs *Args;
struct MRQShellArguments args={0};

	if(Args = ReadArgs(
		"Configfile,IMD=ImageDir/K,BY=Button_Yes/K,BN=Button_No/K,BC=Button_Cancel/K,"
		"IBBT=IButtonsByText/K,QU=Quality/K,AT=AvoidTasks/K,DI=DefaultIcon/S"
		"MR=MouseReq/S,SW=SameWidth/S,FS=FrontScreen/S,"
		"SF=SingleFrame/S,TR=Transparency/S,SI=Sizeable/S,CT=CenterText/S,NRTP=NoRTPatch/S,"
		"SIOK=SingleIsOK/S,AP=AfterPatch/K,Debug/K",(LONG*)&args,NULL))
	{
		ttVars.ConfigName		= args.ConfigName;	// may be NULL!

		ttVars.DefImageDir	= args.DefImageDir	? args.DefImageDir	: NULL;
		ttVars.IB_Yes			= args.IB_Yes			? args.IB_Yes			: NULL;
		ttVars.IB_No			= args.IB_No			? args.IB_No			: NULL;
		ttVars.IB_Cancel		= args.IB_Cancel		? args.IB_Cancel		: NULL;
		ttVars.IButtonsByText= args.IButtonsByText? args.IButtonsByText: NULL;
		ttVars.Quality			= DecodeQuality(args.Quality);
		ttVars.MousedReq			= args.MousedReq;
		ttVars.SameWidthButtons	= args.SameWidth;
		ttVars.FrontmostScreen	= args.FrontScreen;
		ttVars.SingleFrame		= args.SingleFrame;
		ttVars.Transparency		= args.Transparency;
		ttVars.Sizeable			= args.Sizeable;
		ttVars.Centered			= args.Centered;
		ttVars.NoRTPatch			= args.NoRTPatch;
		ttVars.AfterPatch			= args.AfterPatch;
		ttVars.Debug				= args.Debug;
		ttVars.AvoidTasks			= args.AvoidTasks;
		ttVars.DefaultIcon		= args.DefaultIcon;
		ttVars.SingleIsOK			= args.SingleIsOK;
	} else PrintFault(IoErr(),ProgName);
	return (APTR)Args;
}

/*************************************************************************/

static void __saveds __asm __interrupt BrokerHookFunc(register __a1 CxMsg *cxm, register __a2 APTR app)
{
	if(CxMsgType(cxm) == CXM_COMMAND)
	{
		if(CxMsgID(cxm) == CXCMD_APPEAR)
		{
			if(MUI_RequestA(Application,NULL,0,"MRQ Request","*_MUIprefs|_Configfile",
									"Edit MUI settings for MRQ\nor edit the configfile?",
									NULL))
			{
				DoMethod(app,MUIM_Application_OpenConfigWindow,0);
			} else prdebug("Configfile editing not yet implemented!\n");
		}
	}
}

/*************************************************************************/


static LONG DecodeQuality(STRPTR s)
{
	if(s)
	{
		if(!stricmp(s,"best")) return MUIV_Guigfx_Quality_Best;
		if(!stricmp(s,"high")) return MUIV_Guigfx_Quality_High;
		if(!stricmp(s,"low")) return MUIV_Guigfx_Quality_Low;
	}
	return MUIV_Guigfx_Quality_Medium;		// default
}


/*************************************************************************/

static void StartExternalProgram(STRPTR ttype)
{
BPTR FileLock;
BOOL WBStarted=FALSE;

	if(FileLock = Lock(ttype,ACCESS_READ))
	{
	BPTR DirLock;

		DirLock = ParentDir(FileLock);
		UnLock(FileLock);
		if(ExistsIcon(ttype))
		{
		struct Library *WBStartBase;

			if(WBStartBase = OpenLibrary("wbstart.library",0))
			{
				prdebug("Starting Workbench program '%s'\n",ttype);

				if(WBStartTags(WBStart_Name, ttype,
									WBStart_DirectoryLock, DirLock,
									TAG_DONE) == RETURN_OK)
				{
					WBStarted = TRUE;
				} else
				{
					prdebug("Error starting program!\n");
				}
				CloseLibrary(WBStartBase);
			} else prdebug("Starting Workbench programs requires %s\n","wbstart.library");
		}
	}

	if(!WBStarted)
	{
	STRPTR tt,prog,args;

		if(tt = AllocVecPooled(Config->mc_MemPool,strlen(ttype)+1))
		{
			strcpy(tt,ttype);

			prog = strtok(tt," ");
			args = strtok(NULL," ");

			prdebug("Starting shell program \"%s\" (parameters: \"%s\")\n",prog,args?args:(STRPTR)"<none>");

			if(SystemTags(prog,
								NP_Arguments,args,
								SYS_Asynch,TRUE,
								TAG_DONE) != RETURN_OK)
			{
				prdebug("Error starting program!\n");
			}
			FreeVecPooled(Config->mc_MemPool,tt);
		}
	}
}

static BOOL ExistsIcon(STRPTR prog)
{
STRPTR icon;
ULONG proglen;
BOOL ret = FALSE;

	proglen = strlen(prog);
	if(icon = AllocVecPooled(Config->mc_MemPool,proglen+6))
	{
	BPTR lock;

		strcpy(icon,prog);
		strcpy(icon+proglen,".info");
		if(lock = Lock(icon,ACCESS_READ))
		{
			UnLock(lock);
			ret = TRUE;
		}
		FreeVecPooled(Config->mc_MemPool,icon);
	}
	return ret;
}

/*************************************************************************/

static STRPTR FindConfigFile(void)
{
static STRPTR CfgAlts[3] = {NULL,"PROGDIR:MRQ.config","s:MRQ.config"};
BPTR lock;
int i;

	i = (CfgAlts[0] = ttVars.ConfigName) ? 0 : 1;
	for(; i<(sizeof(CfgAlts)/sizeof(STRPTR)); i++)
	{
		if(lock=Lock(CfgAlts[i],ACCESS_READ))
		{
			UnLock(lock);
			return CfgAlts[i];
		}
	}
	return NULL;
}

static BOOL CheckDir(STRPTR dir)
{
BPTR lock;
BOOL ret=FALSE;

	if(lock=Lock(dir,ACCESS_READ))
	{
	struct FileInfoBlock *fib;
		if(fib = AllocDosObjectTagList(DOS_FIB,NULL))
		{
			if(Examine(lock,fib))
			{
				if(fib->fib_DirEntryType > 0) ret=TRUE;	// entry is directory
			}
			FreeDosObject(DOS_FIB,fib);
		}
		UnLock(lock);
	}
	return ret;
}

static BOOL AskQuit(void)
{

	if(CheckPatchManager()) return TRUE;	// don't ask if it's safe to remove patches

	if(ttVars.AfterPatch)
	{
		MUI_RequestA(Application,NULL,0,"MRQ Error","*:-(",
			"MRQ has started another program after patching!\n"
			"Therefore it can't be unloaded without causing\n"
			"a certain crash on the next call to a patched function.",NULL);
		return FALSE;
	}
	return (BOOL)MUI_RequestA(Application,NULL,0,"MRQ Warning","_I am sure|*_Not really",
						"Are you sure you want to quit MRQ?\n"
						"This is not safe if other programs have\n"
						"patched the same functions!",NULL);
}

static BOOL CheckPatchManager(void)
{
BOOL ret;

	Forbid();
	ret = (BOOL)(FindPort("SetMan"));
	Permit();
	return ret;
}

static BOOL CreateCustomClasses(void)
{
	if(MUIMRQWindowClass = NewMRQWindowClass())
	{
		MRQWindowClass = MUIMRQWindowClass->mcc_Class;
		return TRUE;
	}
	DeleteCustomClasses();
	return FALSE;
}

static void DeleteCustomClasses(void)
{
	if(MUIMRQWindowClass)	MUI_DeleteCustomClass(MUIMRQWindowClass);
}



void prdebug(char *fmt, ...)
{
va_list arglist;
char tbuf[768];

	if(ttVars.Debug)
	{
		memset(tbuf,0,sizeof(tbuf));
		va_start(arglist,fmt);
		mb_VNSPrintf(tbuf,fmt,sizeof(tbuf),(LONG*)arglist);
		FPuts(_debugfh,tbuf);
		va_end(arglist);
	}
}
