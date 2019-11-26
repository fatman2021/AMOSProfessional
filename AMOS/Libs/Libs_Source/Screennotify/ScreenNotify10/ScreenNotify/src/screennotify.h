/*
 * screennotify.h V1.0
 *
 * Main include file
 *
 * (c) 1995 Stefan Becker
 */

/* OS include files */
#include <dos/dos.h>
#include <exec/libraries.h>
#include <exec/memory.h>
#include <exec/nodes.h>
#include <exec/resident.h>
#include <exec/semaphores.h>
#include <intuition/screens.h>

/* OS function prototypes */
#include <clib/alib_protos.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>

/* OS function inline calls */
#include <pragmas/exec_pragmas.h>
#include <pragmas/intuition_pragmas.h>

/* Compiler specific include files */
#include <lists.h>

/* Library include files */
#include "/include/libraries/screennotify.h"

/* Client list data */
struct ClientListData {
 struct List                cld_List;
 struct SignalSemaphore     cld_Semaphore;
 struct ScreenNotifyMessage cld_Message;
 struct MsgPort             cld_MsgPort;
};

/* Library base */
struct ScreenNotifyBase {
 struct Library         snb_Library;
 UWORD                  snb_Pad;
 BPTR                   snb_Segment;
 struct Library        *snb_IntuitionBase;
 struct ClientListData  snb_CloseScreenClients;
 struct ClientListData  snb_PubScreenClients;
 struct ClientListData  snb_WorkbenchClients;
};

/* CloseScreen client node */
struct CloseScreenClientNode {
 struct Node    cscn_Node;
 struct Screen *cscn_Screen;
};

/* Library version & revision */
#define INTTOSTR(a) #a
#define SCREENNOTIFY_REVISION 0

/* Global data */
extern struct Library *SysBase;
extern struct ScreenNotifyBase *ScreenNotifyBase;

/* Function prototypes */
        void PatchFunctions(struct Library *);
        BOOL RemoveFunctionPatches(struct Library *);
__geta4 APTR _AddCloseScreenClient(__A0 struct Screen *, __A1 struct MsgPort *,
                                   __D0 BYTE);
__geta4 BOOL _RemCloseScreenClient(__A0 struct Node *);
__geta4 APTR _AddPubScreenClient(__A0 struct MsgPort *, __D0 BYTE);
__geta4 BOOL _RemPubScreenClient(__A0 struct Node *);
__geta4 APTR _AddWorkbenchClient(__A0 struct MsgPort *, __D0 BYTE);
__geta4 BOOL _RemWorkbenchClient(__A0 struct Node *);

/* Debugging */
#ifdef DEBUG
void kprintf(char *, ...);
#define DEBUGLOG(x) x
#else
#define DEBUGLOG(X)
#endif
