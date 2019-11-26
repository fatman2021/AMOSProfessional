/*
 * patch.c V1.0
 *
 * Patch routines
 *
 * (c) 1995 Stefan Becker
 */

#include "screennotify.h"

/* Local data */
static ULONG (*OldCloseScreen)(__A0 struct Screen *, __A6 struct Library *);
static LONG  (*OldCloseWB)(__A6 struct Library *);
static ULONG (*OldOpenWB)(__A6 struct Library *);
static ULONG (*OldPubScreenStatus)(__A0 struct Screen *, __D0 ULONG,
                                   __A6 struct Library *);

/* Local defines */
#define OFFSET_CloseScreen     -0x042
#define OFFSET_CloseWorkBench  -0x04E
#define OFFSET_OpenWorkBench   -0x0D2
#define OFFSET_PubScreenStatus -0x228

/* Patch for CloseScreen() */
__geta4 static ULONG PatchCloseScreen(__A0 struct Screen *s,
                                      __A6 struct Library *IntuitionBase)
{
 BYTE sigbit;

 DEBUGLOG(kprintf("PatchCloseScreen: Screen 0x%08lx\n", s);)

 /* Allocate signal bit */
 if ((sigbit = AllocSignal(-1)) != -1) {
  struct ClientListData         *cld  = &ScreenNotifyBase->snb_CloseScreenClients;
  struct MsgPort                *rp   = &cld->cld_MsgPort;
  struct ScreenNotifyMessage    *snm  = &cld->cld_Message;
  struct CloseScreenClientNode  *cscn;

  DEBUGLOG(kprintf("PatchCloseScreen: Signalbit %ld\n", sigbit);)

  /* Obtain semaphore for CloseScreen client list data */
  ObtainSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("PatchCloseScreen: Semaphore locked.\n");)

  /* Initialize message port */
  rp->mp_SigBit  = sigbit;
  rp->mp_SigTask = FindTask(NULL);

  /* Initialize message */
  snm->snm_Type  = SCREENNOTIFY_TYPE_CLOSESCREEN;
  snm->snm_Value = s;

  /* Get head of CloseScreen client list */
  cscn = (struct CloseScreenClientNode *) GetHead(&cld->cld_List);

  /* Traverse list */
  while (cscn) {

   /* Do the screen pointer values match? NULL matches any screen! */
   if ((cscn->cscn_Screen == NULL) || (cscn->cscn_Screen == s)) {
    struct MsgPort *mp = (struct MsgPort *) cscn->cscn_Node.ln_Name;

    /* Make sure that we don't send a message to our caller task! */
    if (rp->mp_SigTask != mp->mp_SigTask) {

     DEBUGLOG(kprintf("PatchCloseScreen: Sending to 0x%08lx\n", mp);)

     /* Send message to client */
     PutMsg(mp, (struct Message *) snm);

     /* Wait for reply */
     WaitPort(rp);

     DEBUGLOG(kprintf("PatchCloseScreen: Reply from 0x%08lx\n", mp);)

     /* Retrieve message */
     GetMsg(rp);
    }
   }

   /* Get next entry */
   cscn = (struct CloseScreenClientNode *) GetSucc((struct Node *) cscn);
  }

  DEBUGLOG(kprintf("PatchCloseScreen: Messages sent.\n");)

  /* Release semaphore */
  ReleaseSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("PatchCloseScreen: Semaphore released.\n");)

  /* Free signal bit */
  FreeSignal(sigbit);
 }

 DEBUGLOG(kprintf("PatchCloseScreen: Calling original function.\n");)

 /* Return value from original function */
 return(OldCloseScreen(s, IntuitionBase));
}

/* Inform clients */
static void InformClients(struct ClientListData *cld, ULONG type, APTR value)
{
 BYTE sigbit;

 DEBUGLOG(kprintf("InformClients(%ld): Value 0x%08lx\n", type, value);)

 /* Allocate signal bit */
 if ((sigbit = AllocSignal(-1)) != -1) {
  struct MsgPort             *rp  = &cld->cld_MsgPort;
  struct ScreenNotifyMessage *snm = &cld->cld_Message;
  struct Node                *n;

  DEBUGLOG(kprintf("InformClients(%ld): Signalbit %ld\n", type, sigbit);)

  /* Obtain semaphore for client list data */
  ObtainSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("InformClients(%ld): Semaphore locked.\n", type);)

  /* Initialize message port */
  rp->mp_SigBit  = sigbit;
  rp->mp_SigTask = FindTask(NULL);

  /* Initialize message */
  snm->snm_Type  = type;
  snm->snm_Value = value;

  /* Get head of client list */
  n = GetHead(&cld->cld_List);

  /* Traverse list */
  while (n) {
   struct MsgPort *mp = (struct MsgPort *) n->ln_Name;

   /* Make sure that we don't send a message to our caller task! */
   if (rp->mp_SigTask != mp->mp_SigTask) {

    DEBUGLOG(kprintf("InformClients(%ld): Sending to 0x%08lx\n", type, mp);)

    /* Send message to client */
    PutMsg(mp, (struct Message *) snm);

    /* Wait for reply */
    WaitPort(rp);

    DEBUGLOG(kprintf("InformClients(%ld): Reply from 0x%08lx\n", type, mp);)

    /* Retrieve message */
    GetMsg(rp);
   }

   /* Get next entry */
   n = GetSucc(n);
  }

  DEBUGLOG(kprintf("InformClients(%ld): Messages sent.\n", type);)

  /* Release semaphore */
  ReleaseSemaphore(&cld->cld_Semaphore);

  DEBUGLOG(kprintf("InformClients(%ld): Semaphore released.\n", type);)

  /* Free signal bit */
  FreeSignal(sigbit);
 }
}

/* Patch for PubScreenStatus() */
__geta4 static ULONG PatchPubScreenStatus(__A0 struct Screen *s, __D0 ULONG flags,
                                          __A6 struct Library *IntuitionBase)
{
 struct PubScreenNode *psn = NULL;
 ULONG rc;

 DEBUGLOG(kprintf("PatchPubScreenStatus: Screen 0x%08lx, Flags 0x%04lx\n", s, flags);)

 /* Find PubScreenNode for screen */
 {
  struct List *l;

  DEBUGLOG(kprintf("PatchPubScreenStatus: Locking PubScreenList.\n");)

  /* Lock public screen list */
  if (l = LockPubScreenList()) {

   /* Get head of list */
   psn = (struct PubScreenNode *) GetHead(l);

   /* Traverse list */
   while (psn && (psn->psn_Screen != s))
    psn = (struct PubScreenNode *) GetSucc((struct Node *) psn);

   DEBUGLOG(kprintf("PatchPubScreenStatus: Unlocking PubScreenList.\n");)

   /* Unlock list */
   UnlockPubScreenList();
  }
 }

 DEBUGLOG(kprintf("PatchPubScreenStatus: PubScreenNode 0x%08lx\n", psn);)

 /* PubScreenNode valid and "Private" event? */
 if (psn && ((flags & PSNF_PRIVATE) == PSNF_PRIVATE))

  /* Yes, send message to clients */
  InformClients(&ScreenNotifyBase->snb_PubScreenClients,
                SCREENNOTIFY_TYPE_PRIVATESCREEN, psn);

 DEBUGLOG(kprintf("PatchPubScreenStatus: Calling original function.\n");)

 /* Call original function */
 rc = OldPubScreenStatus(s, flags, IntuitionBase);

 DEBUGLOG(kprintf("PatchPubScreenStatus: Original function returned 0x%04lx\n", rc);)

 /* PubScreenNode valid & successful "Public" event or unsuccessful "Private" event? */
 if (psn &&
     ((((flags & PSNF_PRIVATE) == 0) &&            ((rc & 0x1) == 0x1)) ||
      (((flags & PSNF_PRIVATE) == PSNF_PRIVATE) && ((rc & 0x1) == 0x0))))

  /* Yes, inform clients */
  InformClients(&ScreenNotifyBase->snb_PubScreenClients,
                SCREENNOTIFY_TYPE_PUBLICSCREEN, psn);

 /* Return value from original function */
 return(rc);
}

/* Patch for CloseWorkBench() */
__geta4 static LONG PatchCloseWB(__A6 struct Library *IntuitionBase)
{
 ULONG rc;

 DEBUGLOG(kprintf("PatchCloseWB\n");)

 /* Inform WB clients that the Workbench will be closed */
 InformClients(&ScreenNotifyBase->snb_WorkbenchClients, SCREENNOTIFY_TYPE_WORKBENCH,
               (APTR) FALSE);

 DEBUGLOG(kprintf("PatchCloseWB: Calling original function.\n");)

 /* Call old function */
 if (!(rc = OldCloseWB(IntuitionBase)))

  /* Inform WB clients that the Workbench has NOT been closed! */
  InformClients(&ScreenNotifyBase->snb_WorkbenchClients, SCREENNOTIFY_TYPE_WORKBENCH,
                (APTR) TRUE);

 DEBUGLOG(kprintf("PatchCloseWB: Original function returned %ld\n", rc);)

 /* Return value from original function */
 return(rc);
}

/* Patch for OpenWorkBench() */
__geta4 static ULONG PatchOpenWB(__A6 struct Library *IntuitionBase)
{
 ULONG rc;

 DEBUGLOG(kprintf("PatchOpenWB: Calling original function.\n");)

 /* Call old function first */
 if (rc = OldOpenWB(IntuitionBase))

  /* Inform WB clients that the Workbench has been opened */
  InformClients(&ScreenNotifyBase->snb_WorkbenchClients, SCREENNOTIFY_TYPE_WORKBENCH,
                (APTR) TRUE);

 DEBUGLOG(kprintf("PatchOpenWB: Original function returned %ld\n", rc);)

 /* Return value from original function */
 return(rc);
}

/* Patch functions in intuition.library. Called in Forbid() state */
void PatchFunctions(struct Library *ib)
{
 /* Patch intuition.library */
 OldCloseScreen     = SetFunction(ib, OFFSET_CloseScreen,     (APTR) PatchCloseScreen);
 OldCloseWB         = SetFunction(ib, OFFSET_CloseWorkBench,  (APTR) PatchCloseWB);
 OldOpenWB          = SetFunction(ib, OFFSET_OpenWorkBench,   (APTR) PatchOpenWB);
 OldPubScreenStatus = SetFunction(ib, OFFSET_PubScreenStatus,
                                      (APTR) PatchPubScreenStatus);

 DEBUGLOG(kprintf("OldCloseScreen    : %08lx\n", OldCloseScreen);)
 DEBUGLOG(kprintf("OldCloseWB        : %08lx\n", OldCloseWB);)
 DEBUGLOG(kprintf("OldOpenWB         : %08lx\n", OldOpenWB);)
 DEBUGLOG(kprintf("OldPubScreenStatus: %08lx\n", OldPubScreenStatus);)
}

/* Remove function patches in intuition.library. Called in Forbid() state */
BOOL RemoveFunctionPatches(struct Library *ib)
{
 ULONG (*NewCloseScreen)(__A0 struct Screen *, __A6 struct Library *);
 LONG  (*NewCloseWB)(__A6 struct Library *);
 ULONG (*NewOpenWB)(__A6 struct Library *);
 ULONG (*NewPubScreenStatus)(__A0 struct Screen *, __D0 ULONG, __A6 struct Library *);
 BOOL rc;

 /* Remove patches */
 NewCloseScreen     = SetFunction(ib, OFFSET_CloseScreen,     (APTR) OldCloseScreen);
 NewCloseWB         = SetFunction(ib, OFFSET_CloseWorkBench,  (APTR) OldCloseWB);
 NewOpenWB          = SetFunction(ib, OFFSET_OpenWorkBench,   (APTR) OldOpenWB);
 NewPubScreenStatus = SetFunction(ib, OFFSET_PubScreenStatus,
                                      (APTR) OldPubScreenStatus);

 DEBUGLOG(kprintf("Remove/CloseScreen    : %08lx (old %08lx)\n", NewCloseScreen,
                                                                 PatchCloseScreen);)
 DEBUGLOG(kprintf("Remove/CloseWB        : %08lx (old %08lx)\n", NewCloseWB,
                                                                 PatchCloseWB);)
 DEBUGLOG(kprintf("Remove/OpenWB         : %08lx (old %08lx)\n", NewOpenWB,
                                                                 PatchOpenWB);)
 DEBUGLOG(kprintf("Remove/PubScreenStatus: %08lx (old %08lx)\n", NewPubScreenStatus,
                                                                 PatchPubScreenStatus);)

 /* Patches safely removed (that is nobody installed a patch after us)? */
 if (!(rc = (NewCloseScreen == PatchCloseScreen) && (NewCloseWB == PatchCloseWB) &&
            (NewOpenWB == PatchOpenWB) &&
            (NewPubScreenStatus == PatchPubScreenStatus))) {
  DEBUGLOG(kprintf("Can't remove patches, reinstalling...\n");)

  /* No, reinstall old patches */
  SetFunction(ib, OFFSET_CloseScreen,     (APTR) NewCloseScreen);
  SetFunction(ib, OFFSET_CloseWorkBench,  (APTR) NewCloseWB);
  SetFunction(ib, OFFSET_OpenWorkBench,   (APTR) NewOpenWB);
  SetFunction(ib, OFFSET_PubScreenStatus, (APTR) NewPubScreenStatus);
 }

 /* Return result of remove attempt */
 return(rc);
}
