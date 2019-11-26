/*
 * start.c  V2.2
 *
 * Start a Workbench program
 *
 * (c) 1991-1996 Stefan Becker
 */

#include "wbstart.h"

/* Local data structure */
struct ProcessData {
 struct WBStartup  pd_WBStartup;
 BPTR              pd_HomeDir;
 ULONG             pd_StackSize;
 struct WBArg     *pd_CurrentArg;
 /* Array of WBArgs follows */
};

/* Local data */
static const struct TagItem ProcTags[] = {
 NP_FreeSeglist, FALSE,
 NP_Input,       NULL,
 NP_CloseInput,  FALSE,
 NP_Output,      NULL,
 NP_CloseOutput, FALSE,
 NP_Error,       NULL,
 NP_CloseError,  FALSE,
 NP_CurrentDir,  NULL,  /* Makes sure that you don't see the guy from India */
 NP_ConsoleTask, NULL,
 NP_WindowPtr,   NULL,
 TAG_DONE
};

/* Duplicate a string */
static char *StrDup(char *orig)
{
 char *rc;

 /* Allocate memory for string and copy it */
 if (rc = AllocateMemory(strlen(orig) + 1)) strcpy(rc, orig);

 return(rc);
}

/* Copy argument list */
static BOOL CopyArguments(struct ProcessData *pd, struct WBArg *orig,
                          ULONG count)
{
 struct WBArg *dest = pd->pd_CurrentArg;
 BOOL rc            = TRUE;

 /* Scan original list */
 while (count--) {

  DEBUGLOG(kprintf("Copy in : Lock: 0x%08lx, Name: %s (0x%08lx)\n",
                   orig->wa_Lock, orig->wa_Name, orig->wa_Name);)

  /* Duplicate name and lock (NULL locks are only allowed for devices!) */
  if (((dest->wa_Name = StrDup(orig->wa_Name)) == NULL) ||
      (pd->pd_WBStartup.sm_NumArgs++,
       (((dest->wa_Lock = DupLock(orig->wa_Lock)) == NULL) &&
        (dest->wa_Name[strlen(dest->wa_Name) - 1] != ':')))) {

   /* Error */
   rc = FALSE;

   /* Leave loop */
   break;
  }

  DEBUGLOG(kprintf("Copy Out: Lock: 0x%08lx, Name: %s (0x%08lx)\n",
                   dest->wa_Lock, dest->wa_Name, dest->wa_Name);)

  /* Next entries */
  orig++;
  dest++;
 }

 return(rc);
}

/* Fill current WBArg */
static BOOL FillCurrentArg(struct ProcessData *pd, BPTR currentdir, char *name)
{
 struct WBArg *wa = pd->pd_CurrentArg++;
 BOOL rc          = FALSE;

 DEBUGLOG(kprintf("Fill in : Lock: 0x%08lx, Name: %s\n", currentdir, name);)

 /* Duplicate name */
 if (wa->wa_Name = StrDup(name)) {
  char *filepart;

  /* Increment argument count */
  pd->pd_WBStartup.sm_NumArgs++;

  /* Clear lock */
  wa->wa_Lock = NULL;

  /* Does name contain a path? */
  if ((filepart = FilePart(wa->wa_Name)) != wa->wa_Name) {

   DEBUGLOG(kprintf("Name contains path\n");)

   /* Get a lock from the path part */
   {
    char savechar = *filepart;

    /* Add string terminator to path */
    *filepart = '\0';

    /* Get lock */
    rc = (wa->wa_Lock = Lock(wa->wa_Name, SHARED_LOCK)) != NULL;

    /* Restore file name */
    *filepart = savechar;
   }

   /* All OK? */
   if (rc) {
    BPTR parentlock = NULL;

    DEBUGLOG(kprintf("Path lock: 0x%08lx\n", wa->wa_Lock);)

    /* Lock the file and get a lock of the parent directory */
    {
     BPTR filelock;

     /* Try to lock complete file name */
     if (filelock = Lock(wa->wa_Name, SHARED_LOCK)) {

      DEBUGLOG(kprintf("File lock: 0x%08lx\n", filelock);)

      /* Get lock of parent directory */
      rc = (parentlock = ParentDir(filelock)) != NULL;

      /* Release lock on file */
      UnLock(filelock);
     }
    }

    DEBUGLOG(kprintf("Parent Dir lock: 0x%08lx (rc %ld)\n", parentlock, rc);)

    /* All OK? */
    if (rc &&

    /* Does the Path have at least one directory? */
        ((*(filepart - 1) == '/') ||

    /* Path is a Device/Volume/Assign. Is the parent lock valid? */
         ((parentlock != NULL) &&

    /* ...and is the parent dir lock the same as the path lock? */
         (SameLock(parentlock, wa->wa_Lock) == LOCK_SAME)))) {

     DEBUGLOG(kprintf("Path contains directory or no Multi-Assign\n");)

     /* Path lock is valid. Delete path part in name buffer */
     strcpy(wa->wa_Name, filepart);
    }

    /* Release parent lock */
    UnLock(parentlock);
   }

  } else

   /* No, just duplicate current dir lock */
   rc = (wa->wa_Lock = DupLock(currentdir)) != NULL;
 }

 DEBUGLOG(kprintf("Fill out: Lock: 0x%08lx, Name: %s, RC %ld\n",
                  wa->wa_Lock, wa->wa_Name, rc);)

 return(rc);
}

/* Load program code */
static BOOL LoadProgram(struct ProcessData *pd, BPTR currentdir, char *name)
{
 BPTR oldlock;
 struct DiskObject *dobj;
 BOOL rc                 = FALSE;

 DEBUGLOG(kprintf("Current Dir: 0x%08lx\n", currentdir);)

 /* Go to current directory */
 oldlock = CurrentDir(currentdir);

 DEBUGLOG(kprintf("Load Icon: %s\n", name);)

 /* Get icon and check for projects */
 if (dobj = GetDiskObject(name)) {

  /* Get stack size */
  pd->pd_StackSize = dobj->do_StackSize;

  /* Check icon type */
  switch (dobj->do_Type) {

   case WBTOOL:      /* Program is a TOOL */

    DEBUGLOG(kprintf("Tool icon\n");)

    /* Fill first WBArg */
    rc = FillCurrentArg(pd, currentdir, name);

    /* Get home directory */
    pd->pd_HomeDir = pd->pd_WBStartup.sm_ArgList->wa_Lock;
    break;

   case WBPROJECT: { /* Program is a PROJECT */
     char *tool = dobj->do_DefaultTool;

     DEBUGLOG(kprintf("Project icon, Tool: %s\n", tool);)

     /* Does the default tool contain a relative/absolute path? */
     if (FilePart(tool) != tool) {

      /* Yes, fill first WBArg with default tool, second with project */
      if (rc = (FillCurrentArg(pd, currentdir, tool) &&
                FillCurrentArg(pd, currentdir, name)))

       /* Get home directory */
       pd->pd_HomeDir = pd->pd_WBStartup.sm_ArgList->wa_Lock;

     } else {
      struct WBArg *first = pd->pd_WBStartup.sm_ArgList;

      /* No, fill first WBArg with project, second with default tool, */
      /* but use the projects directory lock as current dir lock      */
      if (rc = (FillCurrentArg(pd, currentdir, name) &&
                FillCurrentArg(pd, first->wa_Lock, tool))) {
        struct WBArg temp;
        struct WBArg *second = first + 1;

        /* Now swap first and second WBArg */
        temp    = *first;
        *first  = *second;
        *second = temp;

        /* Scan load path for default tool */
        pd->pd_HomeDir = ScanLoadPath(tool, currentdir);
      }
     }
    }
    break;
  }

  /* Free icon */
  FreeDiskObject(dobj);

  /* No icon. This is a special case which can never happen with    */
  /* the Workbench. In this case the Workbench starts a CLI process */
 } else {

  DEBUGLOG(kprintf("No program icon found\n");)

  /* Program is a TOOL. Fill first WBArg */
  if (rc = FillCurrentArg(pd, currentdir, name))

   /* Does the program name contain a path? */
   if (FilePart(name) != name)

    /* Yes, get home directory from first WBArg */
    pd->pd_HomeDir = pd->pd_WBStartup.sm_ArgList->wa_Lock;

   else

    /* No, scan load path */
    pd->pd_HomeDir = ScanLoadPath(name, currentdir);
 }

 /* All OK? */
 if (rc) {
  char *tool = pd->pd_WBStartup.sm_ArgList->wa_Name;

  /* Yes, go to home directory */
  CurrentDir(pd->pd_HomeDir);

  DEBUGLOG(kprintf("Loading program\n");)

  /* Load program */
  if (rc = ((pd->pd_WBStartup.sm_Segment = NewLoadSeg(tool, NULL)) != NULL)) {

   DEBUGLOG(kprintf("Program loaded, retrieving icon\n");)

   /* Get tool icon */
   if (dobj = GetDiskObject(tool)) {

    /* Copy Toolwindow */
    if (dobj->do_ToolWindow)
     rc = ((pd->pd_WBStartup.sm_ToolWindow = StrDup(dobj->do_ToolWindow))
            != NULL);

    /* Free icon */
    FreeDiskObject(dobj);
   }
  }

  DEBUGLOG(kprintf("Tool: %s, Home: 0x%08lx, Stack %ld\n",
                   tool, pd->pd_HomeDir, pd->pd_StackSize);)
 }

 /* Go back to old directory */
 CurrentDir(oldlock);

 return(rc);
}

/* Start a Workbench program */
LONG StartProgram(struct TagItem *tags)
{
 LONG rc            = RETURN_FAIL;
 char *name         = NULL;
 BPTR dirlock       = NULL;
 LONG priority      = 0;
 ULONG stack        = 0;
 ULONG count        = 0;
 struct WBArg *args = NULL;

 /* Scan tag items */
 {
  struct TagItem *tstate = tags;
  struct TagItem *ti;

  /* Get next tag item */
  while (ti = NextTagItem(&tstate)) {

   DEBUGLOG(kprintf("Tag: 0x%08lx, Data: 0x%08lx\n", ti->ti_Tag, ti->ti_Data);)

   /* Which tag? */
   switch (ti->ti_Tag) {

    case WBStart_Name:
     name = (char *) ti->ti_Data;
     break;

    case WBStart_DirectoryName:
     if (ti->ti_Data) {
      BPTR newlock;

      /* Get new lock */
      if (newlock = Lock((STRPTR) ti->ti_Data, ACCESS_READ)) {

       DEBUGLOG(kprintf("Locked %s (0x%08lx), Unlocking 0x%08lx\n",
                        ti->ti_Data, newlock, dirlock);)

       /* Release old directory lock first */
       UnLock(dirlock);

       /* Set new lock */
       dirlock = newlock;
      }
     }
     break;

    case WBStart_DirectoryLock: {
      BPTR newlock;

      /* Duplicate lock */
      if (newlock = DupLock(ti->ti_Data)) {

       DEBUGLOG(kprintf("Duplicated 0x%08lx (0x%08lx), Unlocking 0x%08lx\n",
                        ti->ti_Data, newlock, dirlock);)

       /* Release old directory lock first */
       UnLock(dirlock);

       /* Set new lock */
       dirlock = newlock;
      }
     }
     break;

    case WBStart_Stack:
     stack = ti->ti_Data;
     break;

    case WBStart_Priority:
     priority = ti->ti_Data;
     break;

    case WBStart_ArgumentCount:
     count = ti->ti_Data;
     break;

    case WBStart_ArgumentList:
     args = (struct WBArg *) ti->ti_Data;
     break;
   }
  }

  DEBUGLOG(kprintf("Tags parsed.\n");)
 }

 /* Parameter check                                                       */
 /* a) Name must be specified                                             */
 /* b) If argument list is specified then arg count must be specified too */
 if (name && ((args == NULL) || (count != 0))) {
  struct ProcessData *pd;

  DEBUGLOG(kprintf(
  "Name: %s, Dir: 0x%08lx, Stack: %ld, Prio: %ld, Count: %ld, Args: 0x%08lx\n",
  name, dirlock, stack, priority, count, args);)

  /* Sanity check for argument count */
  if (args == NULL) count = 0;

  /* Sanity check for stack size */
  if (stack < 4096) stack = 4096;

  /* Allocate WBStartup structure and argument array     */
  /* Note that we reserve memory for two more arguments! */
  if (pd = AllocateMemory(sizeof(struct ProcessData) +
                          sizeof(struct WBArg) * (count + 2))) {

   DEBUGLOG(kprintf("Process data: 0x%08lx\n", pd);)

   /* Initialize ProcessData structure */
   pd->pd_WBStartup.sm_Message.mn_Node.ln_Pri = 0;
   pd->pd_WBStartup.sm_Message.mn_ReplyPort   = WBStartBase->wbsb_Port;
   pd->pd_WBStartup.sm_Message.mn_Length      = sizeof(struct WBStartup);
   pd->pd_WBStartup.sm_Segment                = NULL;
   pd->pd_WBStartup.sm_NumArgs                = 0;
   pd->pd_WBStartup.sm_ToolWindow             = NULL;
   pd->pd_WBStartup.sm_ArgList                = (struct WBArg *) (pd + 1);
   pd->pd_StackSize                           = stack;
   pd->pd_CurrentArg                          = pd->pd_WBStartup.sm_ArgList;

   /* Load program code */
   if (LoadProgram(pd, dirlock, name)) {

    DEBUGLOG(kprintf("Program loaded.\n");)

    /* Copy argument list */
    if (CopyArguments(pd, args, count)) {
     BPTR homelock;

     DEBUGLOG(kprintf("Arguments copied.\n");)

     /* Duplicate home directory lock */
     if (homelock = DupLock(pd->pd_HomeDir)) {
      struct Process *newproc;

      DEBUGLOG(kprintf("Home Dir Lock: 0x%08lx\n", homelock);)

      /* Create new process */
      if (newproc = CreateNewProcTags(
           NP_Seglist,   pd->pd_WBStartup.sm_Segment,
           NP_StackSize, (stack > pd->pd_StackSize) ? stack : pd->pd_StackSize,
           NP_Name,      pd->pd_WBStartup.sm_ArgList->wa_Name,
           NP_Priority,  priority,
           NP_HomeDir,   homelock,

           /* The rest is constant */
           TAG_MORE,      ProcTags)) {
       struct MsgPort *p = &newproc->pr_MsgPort;

       DEBUGLOG(kprintf("New process created: 0x%08lx\n", newproc);)

       /* Set WBStartup process pointer */
       pd->pd_WBStartup.sm_Process = p;

       /* Send startup message to new process */
       PutMsg(p, (struct Message *) pd);

       /* All OK */
       rc = RETURN_OK;

      } else
        /* Process not created,  free duplicate of home directory lock */
        UnLock(homelock);
     }
    }
   }

   /* Error? */
   if (rc != RETURN_OK) FreeProcessData((struct Message *) pd, FALSE);
  }
 }

 /* Free directory lock */
 UnLock(dirlock);

 return(rc);
}

/* Free process data */
void FreeProcessData(struct Message *msg, BOOL reply)
{
 struct ProcessData *pd = (struct ProcessData *) msg;
 struct WBArg *wa       = pd->pd_WBStartup.sm_ArgList;
 int i                  = pd->pd_WBStartup.sm_NumArgs;

 /* Scan array */
 while (i--) {

  DEBUGLOG(kprintf("Free WBArg %s (0x%08lx)\n", wa->wa_Name, wa->wa_Lock);)

  /* Free directory lock */
  UnLock(wa->wa_Lock);

  /* Free name buffer */
  if (wa->wa_Name) FreeMemory(wa->wa_Name);

  /* Next entry */
  wa++;
 }

 /* Free tool window specificaton */
 if (pd->pd_WBStartup.sm_ToolWindow)
  FreeMemory(pd->pd_WBStartup.sm_ToolWindow);

 /* Free program segments */
 if (pd->pd_WBStartup.sm_Segment) UnLoadSeg(pd->pd_WBStartup.sm_Segment);

 /* Free process data structure */
 FreeMemory(pd);
}
