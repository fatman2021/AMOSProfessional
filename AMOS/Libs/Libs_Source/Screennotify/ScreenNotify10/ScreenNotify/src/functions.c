/*
 * functions.c V1.0
 *
 * Add & Remove SceenNotify clients
 *
 * (c) 1995 Stefan Becker
 */

#include "screennotify.h"

/* Add a client to client list */
static struct Node *AddClient(struct ClientListData *cld, ULONG size,
                              struct MsgPort *port, BYTE pri)
{
 struct Node *n;

 DEBUGLOG(kprintf("AddClient: CLD 0x%08lx, Size %ld, Port 0x%08lx, Pri %ld\n",
                  cld, size, port, pri);)

 /* Allocate memory for node */
 if (n = AllocMem(size, MEMF_PUBLIC)) {

  DEBUGLOG(kprintf("AddClient: CLD 0x%08lx, Node 0x%08lx\n", cld, n);)

  /* Initialize node */
  n->ln_Name = (char *) port;
  n->ln_Pri  = pri;

  /* Obtain semaphore for client list data */
  ObtainSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("AddClient: CLD 0x%08lx, Semaphore locked.\n", cld);)

  /* Insert node into client list */
  Enqueue(&cld->cld_List, n);

  /* Release semaphore */
  ReleaseSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("AddClient: CLD 0x%08lx, Semaphore released.\n", cld);)
 }

 /* Return pointer to node as handle */
 return(n);
}

/* Remove a client from client list */
static BOOL RemoveClient(struct SignalSemaphore *ss, struct Node *n, ULONG size)
{
 BOOL rc = FALSE;

 DEBUGLOG(kprintf("RemoveClient: SS 0x%08lx, Node 0x%08lx, Size %ld\n", ss, n, size);)

 /* Try to obtain semaphore for client list data */
 if (AttemptSemaphore(ss)) {

  DEBUGLOG(kprintf("RemoveClient: SS 0x%08lx, Semaphore locked.\n", ss);)

  /* List locked, remove node from list */
  Remove(n);

  /* Release semaphore */
  ReleaseSemaphore(ss);

  DEBUGLOG(kprintf("RemoveClient: SS 0x%08lx, Semaphore released.\n", ss);)

  /* Free node */
  FreeMem(n, size);

  /* All OK. */
  rc = TRUE;

 } else {
  struct Message *m;

  DEBUGLOG(kprintf("RemoveClient: SS 0x%08lx, Semaphore NOT locked!\n", ss);)

  /* List is busy, check port if a message arrived and reply it! */
  if (m = GetMsg((struct MsgPort *) n->ln_Name)) ReplyMsg(m);
 }

 DEBUGLOG(kprintf("RemoveClient: SS 0x%08lx, %s.\n", ss, rc ? "OK" : "Failed");)

 return(rc);
}

/* Add a CloseScreen client */
__geta4 APTR _AddCloseScreenClient(__A0 struct Screen *s, __A1 struct MsgPort *port,
                                   __D0 BYTE pri)
{
 struct CloseScreenClientNode *cscn;

 /* Allocate memory for node */
 if (cscn = (struct CloseScreenClientNode *)
             AddClient(&ScreenNotifyBase->snb_CloseScreenClients,
                       sizeof(struct CloseScreenClientNode), port, pri))

  /* Initialize node */
  cscn->cscn_Screen = s;

 /* Return pointer to node as handle */
 return(cscn);
}

/* Remove a CloseScreen client */
__geta4 BOOL _RemCloseScreenClient(__A0 struct Node *n)
{
 return(RemoveClient(&ScreenNotifyBase->snb_CloseScreenClients.cld_Semaphore,
                     n, sizeof(struct CloseScreenClientNode)));
}

/* Add a PubScreenStatus client */
__geta4 APTR _AddPubScreenClient(__A0 struct MsgPort *port, __D0 BYTE pri)
{
 return(AddClient(&ScreenNotifyBase->snb_PubScreenClients, sizeof(struct Node), port,
                  pri));
}

/* Remove a PubScreenStatus client */
__geta4 BOOL _RemPubScreenClient(__A0 struct Node *n)
{
 return(RemoveClient(&ScreenNotifyBase->snb_PubScreenClients.cld_Semaphore,
                     n, sizeof(struct Node)));
}

/* Add a Workbench client */
__geta4 APTR _AddWorkbenchClient(__A0 struct MsgPort *port, __D0 BYTE pri)
{
 return(AddClient(&ScreenNotifyBase->snb_WorkbenchClients, sizeof(struct Node), port,
                  pri));
}

/* Remove a Workbench client */
__geta4 BOOL _RemWorkbenchClient(__A0 struct Node *n)
{
 return(RemoveClient(&ScreenNotifyBase->snb_WorkbenchClients.cld_Semaphore,
                     n, sizeof(struct Node)));
}
