/*
** mrq.h
** Main data structure and definitions file for MRQ
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: mrq.h 1.2 2000/03/30 23:18:34 msbethke Exp msbethke $
**
** $Log: mrq.h $
** Revision 1.2  2000/03/30 23:18:34  msbethke
** Changed NewImage.mcc -> Guigfx.mcc
**
** Revision 1.1  2000/01/25 16:44:57  msbethke
** Initial revision
**
*/

#define MRQWINDOWTAG_REQMESSAGE (0x8000ffff)
#define MAXBUTTONS 25

/* set by different patches */
#define CALLER_EASYREQUESTARGS 1
#define CALLER_RTEZREQUESTA 2

#define MRQMF_NORETURNKEY (1<<0)
#define MRQMF_CENTERTEXT  (1<<1)

/* Message sent to main task when a requester should open */
struct MRQReqMessage
{
	struct Message mrm_Message;
	struct EasyStruct *mrm_Easy;
	struct Window *mrm_ParentWin;
	APTR mrm_ArgList;
	APTR mrm_WindowObject;
	struct MUI_EventHandlerNode *mrm_EventHandler;
	struct Screen *mrm_ReqScreen;
	STRPTR mrm_ARexxPort;
	STRPTR mrm_ARexxCmd;
	struct MRQImage *mrm_ReqImage;
	LONG mrm_RCode;
	ULONG mrm_Flags;
	STRPTR mrm_CallingProgram;
	UWORD	mrm_CalledFrom;
	BOOL	mrm_FatalError;
	UBYTE mrm_Underscore;
	UBYTE mrm_DefaultAnswer;
};

/* ToolType structure - config data */
struct TTVars
{
	LONG MousedReq;
	LONG SameWidthButtons;
	LONG FrontmostScreen;
	LONG Quality;
	LONG SingleFrame;
	LONG Transparency;
	LONG Sizeable;
	LONG Centered;
	LONG NoRTPatch;
	LONG DefaultIcon;
	LONG SingleIsOK;
	STRPTR Debug;
	STRPTR IB_Yes;
	STRPTR IB_No;
	STRPTR IB_Cancel;
	STRPTR IButtonsByText;
	STRPTR DefImageDir;
	STRPTR ConfigName;
	STRPTR AfterPatch;
	STRPTR AvoidTasks;
};

/* Used for ReadArgs() on shell invocation */
struct MRQShellArguments
{
	STRPTR ConfigName;
	STRPTR DefImageDir;
	STRPTR IB_Yes;
	STRPTR IB_No;
	STRPTR IB_Cancel;
	STRPTR IButtonsByText;
	STRPTR Quality;
	STRPTR AvoidTasks;
	LONG DefaultIcon;
	LONG MousedReq;
	LONG SameWidth;
	LONG FrontScreen;
	LONG SingleFrame;
	LONG Transparency;
	LONG Sizeable;
	LONG Centered;
	LONG NoRTPatch;
	LONG SingleIsOK;
	STRPTR AfterPatch;
	STRPTR Debug;
};

/* globals - initialized in mrq.c */
extern APTR OldEasyRequestArgs, OldrtEZRequestA, Application;
extern struct IClass *MRQWindowClass, *GuigfxClass;
extern UBYTE ProgName[];
extern struct MRQConfig *Config;
extern struct TTVars ttVars;
extern struct DosLibrary *DOSBase;
extern struct IntuitionBase *IntuitionBase;
extern struct GfxBase *GfxBase;
extern struct Library *MUIMasterBase, *IconBase, *RexxSysBase, *DataTypesBase, *UtilityBase;
extern struct ExecBase *SysBase;
extern struct ReqToolsBase *ReqToolsBase;
extern struct MsgPort *MainPort;
extern LONG AppActive;

/* some error messages for debug output */
#define MRQERROR_NOMEMORY       "out of memory"
#define MRQERROR_BADPATTERN     "pattern parse error"
#define MRQERROR_NOCONFIGFILE   "configfile not found"
#define MRQERROR_LOADIMAGE      "can't load an image"
#define MRQERROR_CONFIGFORMAT   "error in config file"

/* protos */
void prdebug(char*,...);
