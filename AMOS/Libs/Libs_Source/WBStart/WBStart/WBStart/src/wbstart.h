/*
 * wbstart.h  V2.2
 *
 * Main include file
 *
 * (c) 1991-1996 Stefan Becker
 */

/* OS include files */
#include <dos/dos.h>
#include <dos/dostags.h>
#include <exec/libraries.h>
#include <exec/memory.h>
#include <exec/resident.h>
#include <exec/semaphores.h>
#include <libraries/dospath.h>
#include <libraries/wbstart.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>

/* OS function prototypes */
#include <clib/alib_protos.h>
#include <clib/dos_protos.h>
#include <clib/dospath_protos.h>
#include <clib/exec_protos.h>
#include <clib/icon_protos.h>
#include <clib/utility_protos.h>

/* OS function inline calls */
#include <pragmas/dos_pragmas.h>
#include <pragmas/dospath_pragmas.h>
#include <pragmas/exec_pragmas.h>
#include <pragmas/icon_pragmas.h>
#include <pragmas/utility_pragmas.h>

/* ANSI C include files */
#include <string.h>

/* Revision number */
#define WBSTART_REVISION 2

/* Handler states */
#define WBSTART_HANDLER_INACTIVE 0
#define WBSTART_HANDLER_RUNNING  1

/* Library base */
struct WBStartBase {
 struct Library          wbsb_Library;     /* Library node                   */
 UWORD                   wbsb_State;       /* Handler state                  */
 BPTR                    wbsb_Segment;     /* Library segment list           */
 struct Process         *wbsb_Process;     /* Pointer to handler process     */
 struct MsgPort         *wbsb_Port;        /* Pointer to handler msg port    */
 struct SignalSemaphore  wbsb_Semaphore;   /* Semaphore to lock Library Base */
 UWORD                   wbsb_Pad1;        /* Long word alignment            */
 struct MsgPort          wbsb_ReplyPort;   /* Common reply port              */
 UWORD                   wbsb_Pad2;        /* Long word alignment            */
 struct Message          wbsb_Message;     /* Common message                 */
};

/* Global data */
extern struct Library     *DOSBase;
extern struct Library     *IconBase;
extern struct Library     *SysBase;
extern struct Library     *UtilityBase;
extern struct WBStartBase *WBStartBase;
extern const char          DosName[];

/* Function prototypes */
void  WBStartHandler(void);
BOOL  InitMemory(void);
void  DeleteMemory(void);
void *AllocateMemory(ULONG);
void  FreeMemory(void *);
void  InstallWorkbenchPath(void);
void  RemoveWorkbenchPath(void);
BPTR  ScanLoadPath(char *, BPTR);
LONG  StartProgram(struct TagItem *);
void  FreeProcessData(struct Message *, BOOL);

/* Debugging */
#ifdef DEBUG
void kprintf(char *, ...);
#define DEBUGLOG(x) x
#else
#define DEBUGLOG(X)
#endif
