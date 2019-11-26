/*
 * handler.c  V2.2
 *
 * WBStart handler entry point
 *
 * (c) 1991-1996 Stefan Becker
 */

#include "wbstart.h"

/* Global data */
struct Library *DOSBase;
struct Library *IconBase;
struct Library *UtilityBase;

/* Handler entry point */
__geta4 void WBStartHandler(void)
{
 struct Message *msg;

 /* Wait for and retrieve startup message */
 {
  struct MsgPort *p = &((struct Process *) FindTask(NULL))->pr_MsgPort;

  /* Wait for startup message */
  WaitPort(p);

  /* Retrieve startup message */
  msg = GetMsg(p);
 }

 /* Set error reply code */
 msg->mn_Node.ln_Name = (char *) RETURN_FAIL;

 DEBUGLOG(kprintf("Handler startup.\n");)

 /* Open dos.library */
 if (DOSBase = OpenLibrary(DosName, 39)) {

  /* Open icon.library */
  if (IconBase = OpenLibrary("icon.library", 39)) {

   /* Open utility.library */
   if (UtilityBase = OpenLibrary("utility.library", 39)) {

    /* Initialize memory */
    if (InitMemory()) {
     BYTE sig;

     /* Allocate signal for message port */
     if ((sig = AllocSignal(-1)) >= 0) {
      struct MsgPort *p;

      /* Allocate memory for handler message port */
      if (p = AllocateMemory(sizeof(struct MsgPort))) {
       ULONG portmask, waitmask, active;

       DEBUGLOG(kprintf("Handler resources allocated.\n");)

       /* Initialize message port */
       p->mp_Flags   = PA_SIGNAL;
       p->mp_SigBit  = sig;
       p->mp_SigTask = FindTask(NULL);

       /* Initialize message list */
       NewList(&p->mp_MsgList);

       /* Set handler port in library base */
       WBStartBase->wbsb_Port = p;

       /* All resources allocated */
       msg->mn_Node.ln_Name = (char *) RETURN_OK;

       /* Reply startup message */
       ReplyMsg(msg);

       /* Install Workbench path */
       InstallWorkbenchPath();

       /* Generate signal masks */
       portmask = 1L << sig;
       waitmask = portmask | SIGBREAKF_CTRL_C;

       /* No active tasks */
       active = 0;

       /* Event loop */
       while (1) {
        ULONG signals;

        /* Wait for signal */
        signals = Wait(waitmask);

        /* New message arrived? */
        if (signals & portmask) {

         /* Retrieve message from port */
         while (msg = GetMsg(p)) {

          /* Reply message? */
          if (msg->mn_Node.ln_Type == NT_REPLYMSG) {

           DEBUGLOG(kprintf("WB process 0x%08lx left.\n", msg);)

           /* Yes, one Workbench process has been completed */
           active--;

           /* Free allocated resources for this process */
           FreeProcessData(msg, TRUE);

          } else {

           DEBUGLOG(kprintf("Please start program.\n");)

           /* No, IPC message. Start program and set return code */
           if ((msg->mn_Node.ln_Name =
                (char *) StartProgram((struct TagItem *) msg->mn_Node.ln_Name))
                == RETURN_OK)

            /* One process started */
            active++;

           /* Reply message */
           ReplyMsg(msg);
          }
         }
        }

        /* Stop signal, no active processes and can we lock the library base? */
        if ((signals & SIGBREAKF_CTRL_C) && (active == 0) &&
            AttemptSemaphore(&WBStartBase->wbsb_Semaphore)) {

         /* Remove handler port from library base */
         WBStartBase->wbsb_Port = NULL;

         /* Release semaphore */
         ReleaseSemaphore(&WBStartBase->wbsb_Semaphore);

         DEBUGLOG(kprintf("Handler leaving.\n");)

         /* Leave loop */
         break;
        }
       }

       /* Remove possible outstanding IPC message */
       if (msg = GetMsg(p)) {

        /* Set error reply code */
        msg->mn_Node.ln_Name = (char *) RETURN_FAIL;

        /* Reply message */
        ReplyMsg(msg);
       }

       /* Startup message already replied */
       msg = NULL;

       /* Remove Workbench path */
       RemoveWorkbenchPath();

       FreeMemory(p);
      }
      FreeSignal(sig);
     }
     DeleteMemory();
    }
    CloseLibrary(UtilityBase);
   }
   CloseLibrary(IconBase);
  }
  CloseLibrary(DOSBase);
 }

 /* Error in resource allocation? */
 if (msg)

  /* Yes, reply message with an error code */
  ReplyMsg(msg);

 else {

  /* No, switch to mono-tasking before leaving */
  Forbid();

  /* Handler is going inactive now */
  WBStartBase->wbsb_State = WBSTART_HANDLER_INACTIVE;
 }
}
