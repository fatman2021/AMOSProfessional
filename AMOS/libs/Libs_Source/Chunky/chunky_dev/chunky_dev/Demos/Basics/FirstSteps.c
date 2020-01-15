//
// FirstSteps.c
//
// This example shows how to do the basic stuff with chunky.library.
// Such basic stuff includes allocating buffers, display chunky data
// on a screen, and freeing buffers.
//
// (c) 1999 Rosande Limited, all rights reserved.
// PUBLIC DOMAIN
//
// http://www.irrelevant.org/~oondy/chunky/

#include <exec/types.h>
#include <clib/chunky_protos.h>
#include <pragma/chunky_lib.h>
#include <exec/libraries.h>
#include <pragma/exec_lib.h>
#include <intuition/intuition.h>
#include <pragma/intuition_lib.h>
#include <pragma/graphics_lib.h>
#include <stdio.h>

#include "/_shared/loadcp.h"
#include "/_shared/screen.h"
#include "/_shared/waitbutton.h"

// The chunky buffer structure - a ChunkyPort, so called because
// RastPort's and ChunkyPort's - see? :)
struct ChunkyPort *cp = NULL;

struct Library *ChunkyBase;
// dos.library etc are all opened by StormC - isn't that nice :)

UBYTE *ImageBuffer = NULL;
void *ColourPalette = NULL;

void TheMainDemo(void);

main()
{
  // Open the chunky.library
  printf("\nSimple chunky.library Demo\n"
         "Displays a chunky image on a screen, waiting for you to click\n"
         "the close button of the window.\n(c) 1999 Rosande Limited.  PD.\n\n");

  if(ChunkyBase = OpenLibrary("chunky.library", 4))
  {
    // Open a screen
    printf("Load the colour table...\n");
    if(ColourPalette = DEMO_LoadRGB32("/_shared/320x200.col"))
    {
      printf("Open the screen...\n");
      if(DEMO_OpenScreen(320, 200, NULL, ColourPalette))
      {
        // Load in the example image
        printf("Load the example 320x200 image...\n");
        if(ImageBuffer = DEMO_LoadChunky("/_shared/320x200.chk", 320, 200))
        {
          // Go!
          TheMainDemo();
        }
      }
    }
    printf("Freeing buffers...\n");
    if(ImageBuffer) DEMO_FreeChunky(ImageBuffer);
    if(DemoScreen) DEMO_CloseScreen();
    if(ColourPalette) DEMO_FreeRGB32(ColourPalette);
    if(ChunkyBase) CloseLibrary(ChunkyBase);
  }
  else
  {
    printf("\n ! Can't open chunky.library V4! \n");
  }
  printf("Done!\n");
}

void TheMainDemo(void)
{
  // Allocate the ChunkyPort
  printf("Allocating ChunkyPort...\n");
  if(cp = CHK_InitChunky(320, 200))
  {
    // Now, copy the chunky data we loaded off disk into the ChunkyPort
    CopyMem(ImageBuffer, cp->cp_Chunky, (320*200));
    //
    // We have a ChunkyPort which we can display on screen.
    // Now that the screen is open, we need to tell chunky.library
    // what type of screen we have opened so it knows whether or not
    // to use custom C2P for AGA or the drawing functions of the
    // graphics card.
    //
    // We tell chunky.library what to do via the CHK_ChooseHardwareMode()
    // command.  It requires a ModeID - the same ID used passed to
    // OpenScreenTagList() and SA_ModeID.
    //
    // IT IS IMPORTANT TO CALL CHK_CHOOSEHARDWAREMODE()!  If this call
    // isn't called in your program,  chunky.library defaults to using
    // custom C2P for AGA - meaning your program WILL FAIL ON GRAPHICS
    // BOARDS!
    //
    // If you don't know the ModeID of the screen, use the graphics.library
    // call GetVPModeID() as shown below.  Otherwise,  use the result you
    // got from your asl.library ScreenModeRequest struct or whatever.
    //
    CHK_ChooseHardwareMode(GetVPModeID(&DemoScreen->ViewPort));
    //
    // Now we can draw the image on  the screen...
    printf("Drawing ChunkyPort...\n");
    CHK_DrawChunky(cp, DemoWindow->RPort, 0, 0);
    //
    // Tada! :)  Now just wait for the close gadget to be pressed.
    printf("Hit that close gadget!\n");
    DEMO_WaitForCloseGadget();
    //
    // Free the chunky...
    printf("Freeing ChunkyPort...\n");
    CHK_FreeChunky(cp);
  }
  else
  {
    printf("No memory!\n");
  }
}
