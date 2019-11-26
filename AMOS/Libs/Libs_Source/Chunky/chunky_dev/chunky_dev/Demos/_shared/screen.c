//
// chunky.library examples
// MODULE: screen opening and closing commands
//
// http://www.irrelevant.org/~oondy/chunky/
// Public domain.  (c) 1999 Rosande Limited, all rights reserved.

#include <exec/types.h>
#include <intuition/intuition.h>
#include <pragma/intuition_lib.h>
#include <pragma/graphics_lib.h>

#include "screen.h"

struct Screen *DemoScreen = NULL;
struct Window *DemoWindow = NULL;

BOOL DEMO_OpenScreen(ULONG Width, ULONG Height, ULONG Flags,
 void *ColourTable32)
{
  struct Screen *WB = (struct Screen *)OpenWorkBench();
  if(!DemoScreen)
  {
    if(DemoScreen = OpenScreenTags(NULL,
       SA_Width, Width,
       SA_Height, Height,
       SA_Depth, 8,
       SA_Title, "chunky.library Demo Screen",
       SA_DisplayID, GetVPModeID(&WB->ViewPort),
       ColourTable32 ? SA_Colors32 : TAG_SKIP, ColourTable32,
       TAG_DONE))
    {
      if(DemoWindow = OpenWindowTags(NULL,
        WA_Width, Width,
        WA_Height, Height,
        WA_IDCMP, IDCMP_CLOSEWINDOW,
        WA_CloseGadget, TRUE,
        WA_Borderless,  TRUE,
        WA_Activate, TRUE,
        WA_CustomScreen, DemoScreen,
        TAG_DONE))
      {
        // Opened the demo screen and window
        return(TRUE);
      }
    }
  }
  return(FALSE);
}

void DEMO_CloseScreen(void)
{
  if(DemoWindow)
  {
    CloseWindow(DemoWindow); DemoWindow = NULL;
  }
  if(DemoScreen)
  {
    CloseScreen(DemoScreen); DemoScreen = NULL;
  }
}
