//
// chunky.library demo
//
// This example fiddles  around with CHK_Rotate(), CHK_Scale() and
// CHK_Scroll().
//
// (c) 1999 Rosande Limited, all rights reserved.
// PUBLIC DOMAIN
//
// http://www.irrelevant.org/~oondy/chunky/

#include <exec/types.h>
#include <exec/libraries.h>
#include <clib/chunky_protos.h>
#include <libraries/chunky.h>
#include <pragma/chunky_lib.h>
#include <intuition/intuition.h>
#include <pragma/intuition_lib.h>
#include <pragma/graphics_lib.h>
#include <pragma/exec_lib.h>
#include <pragma/dos_lib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "/_shared/loadcp.h"
#include "/_shared/screen.h"
#include "/_shared/waitbutton.h"
#include "/_shared/requester.h"
#include "/_shared/text.h"

struct Library *ChunkyBase;
void *Colours = NULL;
UBYTE *Bart = NULL;
struct ChunkyPort *BartCP = NULL;

#define BART_WIDTH  139
#define BART_HEIGHT 232

void DoDemo(void);

main()
{
  if(ChunkyBase = OpenLibrary("chunky.library", 4))
  {
    // Open the screen
    if(Colours = DEMO_LoadRGB32("/_shared/bart.col"))
    {
      if(DEMO_OpenScreen(640, 480, NULL, Colours))
      {
        CHK_ChooseHardwareMode(GetVPModeID(&DemoScreen->ViewPort));
        if(Bart = DEMO_LoadChunky("/_shared/bart.chk", BART_WIDTH,
         BART_HEIGHT))
        {
          if(BartCP = CHK_InitChunky(BART_WIDTH, BART_HEIGHT))
          {
            CopyMem(Bart, BartCP->cp_Chunky, BART_WIDTH*BART_HEIGHT);
            DoDemo();
          }
          else printf("no bartcp mem\n");
        }
        else printf("No bart.chk\n");
      }
      else printf("No memory for screen\n");
    }
    else printf("No bart.col\n");
    CloseLibrary(ChunkyBase);
  }
  else printf("No chunky.library v4\n");

  if(BartCP) CHK_FreeChunky(BartCP);
  if(Bart) DEMO_FreeChunky(Bart);
  if(DemoScreen) DEMO_CloseScreen();
  if(Colours) DEMO_FreeRGB32(Colours);
}

BOOL DoFlipDemo(void)
{
  struct ChunkyPort *cp;
  char s[] = "Click close button to continue...\0";
  BOOL ok = FALSE;
  // Clone the ChunkyPort

  if(cp = CHK_CloneChunkyPort(BartCP))
  {
    // Right, show the normal image
    DEMO_WriteText("Normal Image", 16, 16);
    CHK_DrawChunky(cp, DemoWindow->RPort, 8, 26);

    // Flip it horizontally
    CHK_FlipChunkyPort(cp, CHKFLIP_HORIZ);
    DEMO_WriteText("CHKFLIP_HORIZ", 300, 16);
    CHK_DrawChunky(cp, DemoWindow->RPort, 300, 26);
    DEMO_WriteText(s, 16, 300);
    DEMO_WaitForCloseGadget();

    // Flip it vertically
    CHK_SetDrMd(cp, JAM2);
    CHK_DrawChunkyChunky(cp, BartCP, 0, 0);
    CHK_FlipChunkyPort(cp, CHKFLIP_VERT);
    DEMO_WriteText("CHKFLIP_VERT  ", 300, 16);
    CHK_DrawChunky(cp, DemoWindow->RPort, 300, 26);
    DEMO_WriteText(s, 16, 300);
    DEMO_WaitForCloseGadget();

    // Flip it both ways
    CHK_DrawChunkyChunky(cp, BartCP, 0, 0);
    CHK_FlipChunkyPort(cp, CHKFLIP_BOTH);
    DEMO_WriteText("CHKFLIP_BOTH", 300, 16);
    CHK_DrawChunky(cp, DemoWindow->RPort, 300, 26);
    DEMO_WriteText(s, 16, 300);
    DEMO_WaitForCloseGadget();

    CHK_FreeChunky(cp); ok  = TRUE;
  }
  else
  {
    printf("No mem for CHK_CloneChunkyPort()\n");
  }
  return(ok);
}

BOOL DoScrollDemo(void)
{
  struct ChunkyPort *cp = NULL;
  int i, w, h;
  BOOL ok = FALSE;

  if(cp = CHK_CloneChunkyPort(BartCP))
  {
    w = cp->cp_Width-1; h = cp->cp_Height-1;
    if(CHK_BeginScroll(cp, 0, 0, w, h))
    {
      //  Cool, scroll!
//      CHK_SetDrMd(cp, JAM2);
      CHK_DrawChunky(cp, DemoWindow->RPort, 200, 100);

      for(i = 0; i < 25; i++)
      {
        if(!CHK_Scroll(cp, 1, 0, 0, 0, w, h))
        {
          printf("CHK_Scroll() failed\n"); return(FALSE)
        }
        CHK_DrawChunky(cp, DemoWindow->RPort, 200, 100);
      }

      // Easy :)
      ok = TRUE;
      CHK_EndScroll(cp);
    }
    else printf("No mem for scroll buffer\n");
  }
  else printf("No mem  for cloning\n");
  if(cp) CHK_FreeChunky(cp);
  return(ok);
}

BOOL DoScaleDemo(void)
{
  struct  ChunkyPort *cp = NULL, *cp2 = NULL;
  char with[] = "Scaling with smoothing...\0";
  char without[] = "Scaling with no smoothing...\0";
  BOOL ok =  FALSE;

  DEMO_StatusText(NULL);
  DEMO_Request("Doubling the size of Bart...", NULL, NULL);

/*
  DEMO_StatusText(with);
  if(cp2 = CHK_CloneChunkyPort(BartCP))
  {
    if(cp = CHK_Scale(cp2, BART_WIDTH*2, BART_HEIGHT*2))
    {
      // Cool
      DEMO_StatusText(NULL);
      CHK_DrawChunky(cp, DemoWindow->RPort, 20, 10);
      DEMO_Request("Argh!  Giant Bart!", "Argh!", NULL);

      CHK_FreeChunky(cp); cp = NULL; cp2 = NULL;
    }
    else printf("No mem for doublescale\n");
    if(cp2) CHK_FreeChunky(cp2);
    cp2 = NULL;
  }
  else printf("No mem for clone\n");
*/

  DEMO_StatusText(without);
  if(cp = CHK_CloneChunkyPort(BartCP))
  {
    if(CHK_SimpleScale(cp, BART_WIDTH*2, BART_HEIGHT*2))
    {
      // Cool
      DEMO_StatusText(NULL);
      CHK_DrawChunky(cp, DemoWindow->RPort, 20, 10);
      DEMO_Request("Argh!  Giant Bart with no smoothing!!", "Argh!", NULL);
      ok = TRUE;
    }
    else printf("No mem for doublescale\n");
    CHK_FreeChunky(cp);
  }
  else printf("No mem for clone\n");
  return(ok);
}

void DoDemo(void)
{
  DEMO_Request("Flip that Bart!", "Wow!", NULL);

  if(!DoFlipDemo()) return;

  DEMO_Request("Scroll that Bart!", "Yeh!", NULL);

  if(!DoScrollDemo()) return;

  DEMO_Request("Scale that Bart!", "Bet that's painful!", NULL);

  if(!DoScaleDemo())  return;

  DEMO_Request("Neat library isn't it :)", "Fantastic!", NULL);
}
