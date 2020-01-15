/*
** $Id: startup.c 1.11 1999/05/09 19:36:21 Krashan Exp Krashan $
*/

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>

struct Library *SysBase, *DOSBase;

__saveds long _main (void)
 {
  long ret_value, wb;
  struct Process *process;
  struct Message *wbmessage = NULL;
  
  SysBase = *(struct Library**)4;
  if (DOSBase = (struct Library*)OpenLibrary ("dos.library", 37))
   {
    process = (struct Process*)FindTask (NULL);
    if (process->pr_CLI) wb = FALSE;
    else
     {
        WaitPort (&process->pr_MsgPort);
        wbmessage = GetMsg (&process->pr_MsgPort);
        wb = TRUE;
     }
    ret_value = Main (wb);
    CloseLibrary (DOSBase);
    if (wbmessage)
     {
      Forbid ();
      ReplyMsg (wbmessage);
     }
    return (ret_value);
   }
  return (10);
 }
