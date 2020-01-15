//
// chunky.library demo
// MODULE: waits for the close gadget of the window to be pressed
//
// http://www.irrelevant.org/~oondy/chunky/
// Public Domain.  (c) 1999 Rosande Limited, all rights reserved.
//

#include <exec/types.h>
#include <intuition/intuition.h>
#include <pragma/intuition_lib.h>
#include <pragma/exec_lib.h>

#include "screen.h"

void DEMO_WaitForCloseGadget(void)
{
  BOOL terminated = FALSE;
  struct IntuiMessage *imsg;
  while(!terminated)
  {
    Wait(1<<DemoWindow->UserPort->mp_SigBit);
    while(imsg = (struct IntuiMessage *)GetMsg(DemoWindow->UserPort))
    {
      if(imsg->Class == IDCMP_CLOSEWINDOW) terminated = TRUE;
      ReplyMsg((struct Message *)imsg);
    }
  }
}
