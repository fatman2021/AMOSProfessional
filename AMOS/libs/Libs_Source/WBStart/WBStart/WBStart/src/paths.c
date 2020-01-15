/*
 * paths.c  V2.2
 *
 * DOS Paths handling routines
 *
 * (c) 1991-96 Stefan Becker
 *
 */

/* Handler includes */
#include "wbstart.h"

/* Local data */
static struct Library       *DOSPathBase;
static struct PathListEntry *LoadPath;       /* Path for loading programs    */
static struct PathListEntry *WorkbenchPath;  /* Copy of Workbench path       */
static struct PathListEntry *OldProcessPath; /* Pointer to process' old path */

/* Scan load path for program and return directory lock */
BPTR ScanLoadPath(char *name, BPTR currentdir)
{
 BPTR rc;

 /* Check current directory first */
 if (rc = Lock(name, ACCESS_READ)) {

  DEBUGLOG(kprintf("Program found in current directory\n");)

  /* Program found, unlock it */
  UnLock(rc);

  /* Return current directory as home directory */
  rc = currentdir;

 } else {
  struct PathListEntry *path = LoadPath;

  /* Program not found, scan load path */
  rc = FindFileInPathList(&path, name);
 }

 /* Return home directory lock */
 return(rc);
}

/* Copy path from Workbench process and install it as our process' path */
void InstallWorkbenchPath(void)
{
 struct CommandLineInterface *cli = Cli();

 /* Get pointer to our old path */
 OldProcessPath = (struct PathListEntry *) BADDR(cli->cli_CommandDir);

 /* Set this path as default load path */
 LoadPath = OldProcessPath;

 /* Clear pointer to Workbench path */
 WorkbenchPath = NULL;

 /* Open dospath.library */
 if (DOSPathBase = OpenLibrary(DOSPATH_NAME, DOSPATH_VERSION)) {

  DEBUGLOG(kprintf("DOSPathBase 0x%08lx\n", DOSPathBase);)

  /* Copy workbench path */
  if (WorkbenchPath = CopyWorkbenchPathList(NULL, NULL)) {

   DEBUGLOG(kprintf("WorkbenchPath 0x%08lx\n", WorkbenchPath);)

   /* Path successfully copied, install it in our process */
   cli->cli_CommandDir = MKBADDR(WorkbenchPath);

   /* Use workbench path as load path */
   LoadPath = WorkbenchPath;
  }
 }
}

/* Remove Workbench path */
void RemoveWorkbenchPath(void)
{
 /* Copy of Workbench path valid? */
 if (WorkbenchPath) {

  /* Yes, reinstall our old path */
  Cli()->cli_CommandDir = MKBADDR(OldProcessPath);

  /* Free Workbench Path */
  FreePathList(WorkbenchPath);
 }

 /* Close DOSPath library */
 if (DOSPathBase) CloseLibrary(DOSPathBase);
}
