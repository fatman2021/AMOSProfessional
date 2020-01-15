//
// chunky.library demo
//
// This example shows how to do primitive drawing with chunky.library.
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
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "/_shared/screen.h"
#include "/_shared/waitbutton.h"
#include "/_shared/requester.h"
#include "/_shared/text.h"

struct Library *ChunkyBase;

void DoDemo(void);
BOOL DoDrawDemo(void);

main()
{
  if(ChunkyBase = OpenLibrary("chunky.library", 4))
  {
    if(DEMO_OpenScreen(640, 480, NULL, NULL))
    {
      CHK_ChooseHardwareMode(GetVPModeID(&DemoScreen->ViewPort));

      DoDemo();
    }
  }
  else
    printf("need chunky.library v4\n");

  if(DemoScreen) DEMO_CloseScreen();
  if(ChunkyBase) CloseLibrary(ChunkyBase);
}

void DoDemo(void)
{
  DEMO_Request("Right then.  Drawing, eh?\n\n"
               "Here's a few lines, drawn on a 320x200 chunkyport.\n"
               "This uses random colours and positions, but shows using\n"
               "CHK_Move() and CHK_Draw() - like gfx.library's commands.",
               "This library kicks ass", NULL);
  if(!DoDrawDemo()) return;

  DEMO_Request("That concludes the drawing demo... how unexciting...", "Agreed", NULL);
}

int randmax(int n) { int i; if(n < 1) return(0); for(;;) { i = rand(); if(!(i>n)) return(i); } }

BOOL DoDrawDemo(void)
{
  BOOL ok = FALSE;
  struct ChunkyPort *cp = NULL;
  int i, x, y, c, xx, yy;

  if(cp = CHK_InitChunky(320, 200))
  {
    DEMO_StatusText("Rendering 250 lines with CHK_Draw()...");

    for(i = 0; i < 250; i++)
    {
      c = randmax(256);
      CHK_SetAPen(cp, c);

      x = randmax(320); y = randmax(200);
      // Move to x,y
      CHK_Move(cp, x, y);

      x = randmax(320-x); y = randmax(200-y);
      // Draw to x,y
      CHK_Draw(cp, x, y);
    }

    DEMO_StatusText(NULL);
    CHK_DrawChunky(cp, DemoWindow->RPort, (640-320)/2, (480-200)/2);

    DEMO_Request("Cool.. multi-coloured lines.\n\n"
                 "Now for CHK_DrawRect()...", "Nice", NULL);

    CHK_ClearChunky(cp);

    DEMO_StatusText("Drawing 25 hollow and filled rectangles...");
    for(i = 0; i < 25; i++)
    {
      // Draw a rectangle
      c = randmax(256); CHK_SetAPen(cp, c);
      x = randmax(320); y = randmax(200);
      xx = x + randmax(320-x-1); yy = y + randmax(200-y-1);
      CHK_DrawRect(cp, x, y, xx, yy);

      // Draw a filled rectangle
      c = randmax(256); CHK_SetAPen(cp, c);
      x = randmax(320); y = randmax(200);
      xx = x + randmax(320-x-1); yy = y + randmax(200-y-1);
      CHK_RectFill(cp, x, y, xx, yy);

      // Draw a "transparent" rectangle...
      c = randmax(256); CHK_SetAPen(cp, c);
      x = randmax(320); y = randmax(200);
      xx = randmax(320-x-1); yy = randmax(200-y-1);
      CHK_DrawTransparentRectangle(cp, x, y, xx, yy); //xx,yy = w,h
    }

    DEMO_StatusText(NULL);
    CHK_DrawChunky(cp, DemoWindow->RPort, (640-320)/2, (480-200)/2);

    DEMO_Request("Spunky boxes!\n\nCHK_DrawEllipse() time...", "Yeh!", NULL);

    CHK_ClearChunky(cp);

    DEMO_StatusText("Drawing 50 ellipses with CHK_DrawEllipse()...");
#define MAX_RADX 25
#define MAX_RADY 25
    for(i = 0; i < 50; i++)
    {
      c = randmax(256); CHK_SetAPen(cp, c);
      x = randmax(320-(MAX_RADX*2)); y = randmax(200-(MAX_RADY*2));
      xx = randmax(MAX_RADX); yy = randmax(MAX_RADY);
      // Draw an ellipse (xx,yy are radii not positions)
      CHK_DrawEllipse(cp, x, y, xx, yy);
    }

    DEMO_StatusText(NULL);
    CHK_DrawChunky(cp, DemoWindow->RPort, (640-320)/2, (480-200)/2);

    DEMO_Request("Woo.. elliptical ellipses!", "Super", NULL);

    CHK_FreeChunky(cp); ok  = TRUE;
  }
  else
   printf("no mem in DoDrawDemo()\n");

  return(ok);
}
