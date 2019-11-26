/*
 * wbstart.c  V2.2
 *
 * Library routines
 *
 * (c) 1991-1996 Stefan Becker
 */

#include "wbstart.h"

/*
 * Object file dummy entry point
 */
static ULONG Dummy(void)
{
 return(0);
}

/* Library name, ID string and other constant strings */
#define INTTOSTR(a) #a
static const char LibraryName[] = WBSTART_NAME;
static const char LibraryID[]   = "$VER: " WBSTART_NAME " "
                                   INTTOSTR(WBSTART_VERSION) "."
                                   INTTOSTR(WBSTART_REVISION)
                                   " (" __COMMODORE_DATE__ ")\r\n";
static const char HandlerName[] = "WBStart Handler";
const char        DosName[]     = "dos.library";

/* Standard library function prototypes */
__geta4 static struct Library *LibraryInit(__A0 BPTR, __A6 struct Library *);
__geta4 static struct Library *LibraryOpen(__A6 struct WBStartBase *);
__geta4 static BPTR            LibraryClose(__A6 struct WBStartBase *);
__geta4 static BPTR            LibraryExpunge(__A6 struct WBStartBase *);
        static ULONG           LibraryReserved(void);

/* Library specific function prototypes */
__geta4 static LONG WBStartTagList(__A0 struct TagItem *,
                                   __A6 struct WBStartBase *);

/* ROMTag structure */
static const struct Resident ROMTag = { RTC_MATCHWORD, &ROMTag, &ROMTag + 1, 0,
 WBSTART_VERSION, NT_LIBRARY, 0, LibraryName, LibraryID, LibraryInit
};

/* Library functions table */
static const APTR LibraryVectors[] = {
 /* Standard functions */
 (APTR) LibraryOpen,
 (APTR) LibraryClose,
 (APTR) LibraryExpunge,
 (APTR) LibraryReserved,

 /* Library specific functions */
 (APTR) LibraryReserved, /* reserved for ARexx */
 (APTR) WBStartTagList,

 /* End of table */
 (APTR) -1
};

/* Handler process creation data */
static const struct TagItem WBStartHandlerTags[] = {
 NP_Entry,       (ULONG) WBStartHandler,
 NP_CurrentDir,  NULL,
 NP_Name,        (ULONG) HandlerName,
 NP_Priority,    0,
 NP_ConsoleTask, NULL,
 NP_WindowPtr,   NULL,
 NP_HomeDir,     NULL,
 NP_Cli,         TRUE,
 NP_CommandName, (ULONG) HandlerName,
 TAG_DONE
};

/* Global library bases */
struct Library     *SysBase;
struct WBStartBase *WBStartBase = NULL; /* dcc: DON'T REMOVE THE ASSIGNMENT! */

/* Initialize library */
__geta4 static struct Library *LibraryInit(__A0 BPTR Segment,
                                           __A6 struct Library *ExecBase)
{
 struct WBStartBase *wbsb = NULL;

 /* Check OS version, must be OS 3.x or better */
 if (ExecBase->lib_Version >= 39) {

  /* Initialize SysBase */
  SysBase = ExecBase;

  if (wbsb = (struct WBStartBase *) MakeLibrary(LibraryVectors, NULL, NULL,
                                                 sizeof(struct WBStartBase),
                                                 NULL)) {

   /* Initialize libray structure */
   wbsb->wbsb_Library.lib_Node.ln_Type = NT_LIBRARY;
   wbsb->wbsb_Library.lib_Node.ln_Name = LibraryName;
   wbsb->wbsb_Library.lib_Flags        = LIBF_CHANGED | LIBF_SUMUSED;
   wbsb->wbsb_Library.lib_Version      = WBSTART_VERSION;
   wbsb->wbsb_Library.lib_Revision     = WBSTART_REVISION;
   wbsb->wbsb_Library.lib_IdString     = (APTR) LibraryID;
   wbsb->wbsb_State                    = WBSTART_HANDLER_INACTIVE;
   wbsb->wbsb_Segment                  = Segment;
   wbsb->wbsb_Process                  = NULL;
   wbsb->wbsb_Port                     = NULL;
   wbsb->wbsb_ReplyPort.mp_Flags       = PA_SIGNAL;
   wbsb->wbsb_Message.mn_Length        = sizeof(struct Message);

   /* Initialize reply ports' message list */
   NewList(&wbsb->wbsb_ReplyPort.mp_MsgList);

   /* Initialize Semaphore */
   InitSemaphore(&wbsb->wbsb_Semaphore);

   /* Add the library to the system */
   AddLibrary((struct Library *) wbsb);

   /* Set global library base pointer */
   WBStartBase = wbsb;

   DEBUGLOG(kprintf("Init Lib: %08lx Seg; 0x%08lx\n", wbsb, Segment);)
  }
 }

 /* Return new library pointer */
 return((struct Library *) wbsb);
}

/* Standard library function: Open. Called in Forbid() state */
__geta4 static struct Library *LibraryOpen(__A6 struct WBStartBase *wbsb)
{
 /* Oh another user :-) */
 wbsb->wbsb_Library.lib_OpenCnt++;

 /* Reset delayed expunge flag */
 wbsb->wbsb_Library.lib_Flags &= ~LIBF_DELEXP;

 DEBUGLOG(kprintf("Open Lib: %ld\n", wbsb->wbsb_Library.lib_OpenCnt);)

 /* Return library pointer */
 return(&wbsb->wbsb_Library);
}

/* Standard library function: Close. Called in Forbid() state */
__geta4 static BPTR LibraryClose(__A6 struct WBStartBase *wbsb)
{
 BPTR rc = NULL;

 /* Open count greater zero, only one user and delayed expunge bit set? */
 if ((wbsb->wbsb_Library.lib_OpenCnt > 0) &&
     (--wbsb->wbsb_Library.lib_OpenCnt == 0) &&
     (wbsb->wbsb_Library.lib_Flags & LIBF_DELEXP))

  /* Yes, try to remove the library */
  rc = LibraryExpunge(wbsb);

 DEBUGLOG(kprintf("Close Lib: %ld (0x%08lx)\n", wbsb->wbsb_Library.lib_OpenCnt,
                  rc);)

 /* Return library segment if expunge was successful */
 return(rc);
}

/* Standard library function: Expunge. Called in Forbid() state */
__geta4 static BPTR LibraryExpunge(__A6 struct WBStartBase *wbsb)
{
 BPTR rc = NULL;

 DEBUGLOG(kprintf("Expunge Lib: %08lx Seg: 0x%08lx\n", wbsb,
                  wbsb->wbsb_Segment);)

 /* Does anybody use library now? */
 if (wbsb->wbsb_Library.lib_OpenCnt > 0)

  /* No, library still in use -> set delayed expunge flag */
  wbsb->wbsb_Library.lib_Flags |= LIBF_DELEXP;

 /* Is handler inactive? */
 else if (wbsb->wbsb_State == WBSTART_HANDLER_INACTIVE) {

  /* Yes, remove library */
  Remove(&wbsb->wbsb_Library.lib_Node);

  /* Return library segment */
  rc = wbsb->wbsb_Segment;

  /* Free memory for library base */
  FreeMem((void *) ((ULONG) wbsb - wbsb->wbsb_Library.lib_NegSize),
          wbsb->wbsb_Library.lib_NegSize + wbsb->wbsb_Library.lib_PosSize);

  DEBUGLOG(kprintf("Removing library...\n");)

 /* No, handler still active */
 } else {

  DEBUGLOG(kprintf("Sending exit signal to hander.\n");)

  /* Send exit signal to handler */
  Signal(&wbsb->wbsb_Process->pr_Task, SIGBREAKF_CTRL_C);

  /* Library still in use -> set delayed expunge flag */
  wbsb->wbsb_Library.lib_Flags |= LIBF_DELEXP;
 }

 /* Return library segment if expunge was successful */
 return(rc);
}

/* Reserved function, returns NULL */
static ULONG LibraryReserved(void)
{
 return(0);
}

/* Send message and wait for reply */
static LONG DoMessage(struct MsgPort *p, struct Message *msg,
                      struct MsgPort *rp)
{
 /* Initialize message */
 msg->mn_ReplyPort = rp;

 /* Send message to handler */
 PutMsg(p, msg);

 /* Wait for reply */
 WaitPort(rp);

 /* Retrieve reply */
 GetMsg(rp);

 /* Get return code */
 return((LONG) msg->mn_Node.ln_Name);
}

/* Library function: WBStartTagList */
__geta4 static LONG WBStartTagList(__A0 struct TagItem *tags,
                                   __A6 struct WBStartBase *wbsb)
{
 LONG rc  = RETURN_FAIL;
 BYTE sig;

 /* Allocate signal for message port */
 if ((sig = AllocSignal(-1)) >= 0) {

  DEBUGLOG(kprintf("Entering critical section.\n");)

  /*** ENTERING CRITICAL SECTION ***/
  ObtainSemaphore(&wbsb->wbsb_Semaphore);

  /* Initialize reply port */
  wbsb->wbsb_ReplyPort.mp_SigBit  = sig;
  wbsb->wbsb_ReplyPort.mp_SigTask = FindTask(NULL);

  /* Is handler running? */
  if (wbsb->wbsb_State == WBSTART_HANDLER_INACTIVE) {
   struct Library *DOSBase;

   DEBUGLOG(kprintf("Starting handler.\n");)

   /* No, start it. First open DOS library */
   if (DOSBase = OpenLibrary(DosName, 39)) {

    /* Create new process */
    if (wbsb->wbsb_Process = CreateNewProc(WBStartHandlerTags)) {

     DEBUGLOG(kprintf("WBStartTagList: Process created.\n");)

     /* Send startup message */
     if (DoMessage(&wbsb->wbsb_Process->pr_MsgPort, &wbsb->wbsb_Message,
                   &wbsb->wbsb_ReplyPort)
          == RETURN_OK) {

      DEBUGLOG(kprintf("WBStartTagList: Handler started.\n");)

      /* Handler is starting now */
      wbsb->wbsb_State = WBSTART_HANDLER_RUNNING;
     }
    }

    /* Close DOS library */
    CloseLibrary(DOSBase);
   }
  }

  /* Check that handler is really running */
  if (wbsb->wbsb_Port) {

   /* Initialize message */
   wbsb->wbsb_Message.mn_Node.ln_Name = (char *) tags;

   /* Send message to handler */
   rc = DoMessage(wbsb->wbsb_Port, &wbsb->wbsb_Message, &wbsb->wbsb_ReplyPort);
  }

  ReleaseSemaphore(&wbsb->wbsb_Semaphore);
  /*** LEFT CRITICAL SECTION ***/

  DEBUGLOG(kprintf("Left critical section.\n");)

  /* Free signal */
  FreeSignal(sig);
 }

 return(rc);
}
