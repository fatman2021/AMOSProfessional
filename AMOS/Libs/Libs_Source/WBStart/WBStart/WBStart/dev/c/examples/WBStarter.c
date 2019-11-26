/*
 * WBStarter.c  V2.2
 *
 * Start WB programs with wbstart.library
 *
 * (c) 1991-96 Stefan Becker
 *
 */

/* OS include files */
#include <dos/dos.h>
#include <libraries/wbstart.h>

/* OS function prototypes */
#include <clib/dos_protos.h>
#include <clib/wbstart_protos.h>

/* OS function inline calls */
#include <pragmas/dos_pragmas.h>
#include <pragmas/wbstart_pragmas.h>

/* ANSI C includes */
#include <stdlib.h>

/* Library bases */
extern struct Library *DOSBase, *SysBase, *WBStartBase;

/* Version string */
static const char Version[]="$VER: WBStarter 2.2 (" __COMMODORE_DATE__ ")";

int main(int argc, char **argv)
{
 BPTR oldlock;
 LONG rc      = RETURN_OK;

 /* Get current directory lock */
 oldlock = CurrentDir(NULL);

 /* Scan argument list */
 while (--argc)

  /* Start program */
  if ((rc = WBStartTags(WBStart_Name,          *++argv,
                        WBStart_DirectoryLock, oldlock,
                        TAG_DONE))
       != RETURN_OK)

   /* Error, leave loop */
   break;

 /* Go back to old directory */
 CurrentDir(oldlock);

 /* All OK! */
 return(0);
}
