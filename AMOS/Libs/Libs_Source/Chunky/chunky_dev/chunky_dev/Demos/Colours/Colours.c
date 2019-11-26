//
// chunky.library demo
//
// This example demonstrates all the colour functions provided by
// chunky.library version 4+.
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
#include "bartcolours.h"

struct Library *ChunkyBase;
struct ChunkyPort *cp = NULL;
struct ColoursCP *Cols = NULL;

void DoColourDemo(void);
void DisplayColours(void);
void DemoSetRGB4(void);
void DemoGetRGB4(void);

main()
{
  if(ChunkyBase = OpenLibrary("chunky.library", 4))
  {
    if(DEMO_OpenScreen(640, 480, NULL, NULL))
    {
      if(cp = CHK_InitChunky(32, 32))
      {
        CHK_ChooseHardwareMode(GetVPModeID(&DemoScreen->ViewPort));
        DoColourDemo();
      }
    }
  }
  if(cp) CHK_FreeChunky(cp);
  if(DemoScreen) DEMO_CloseScreen();
  if(ChunkyBase) CloseLibrary(ChunkyBase);
}

void DoColourDemo(void)
{
  DEMO_Request("Oh my, hello!\nThis is an example of using all the\n"
               "colour table functions supplied by chunky.library.\n\n"
               "CHK_InitColours(), CHK_PutChunkyColours(),\n"
               "CHK_ConvertCMAP(), CHK_SetRGB32(), CHK_SetRGB4(),\n"
               "CHK_GetRGB32(), CHK_GetRGB4() and CHK_LoadRGB32().",
               NULL, NULL);

  // Give our chunkyport  a colour table
  if(Cols = CHK_InitColours(cp))
  {
    // Insert our LoadRGB32() colour table into the cp's table
    CHK_LoadRGB32(cp, (void *)&BartRGB32);

    DEMO_Request("We have colours initialised in the colour table.\n"
                 "Let me display them all to you...", "Neat", NULL);

    DisplayColours();

    DEMO_Request("Woah!  Look at all the colours, man!\n\n"
                 "So far, we've demonstated CHK_InitColours(), CHK_LoadRGB32(),\n"
                 "and CHK_PutChunkyColours().  Now, let's set all the colours\n"
                 "from colour 4 to 255 as white using CHK_SetRGB4().",
                 "What a boring colour", NULL);

    DemoSetRGB4();
    DemoGetRGB4();
  }
  else
  {
    printf("No mem for colourtable\n");
  }
}

#define YOFF 20
#define XOFF 12
#define BOXWIDTH  16
#define BOXHEIGHT 16
void DisplayColours(void)
{
  int i, x, y, x2, y2;
  struct RastPort *rp = DemoWindow->RPort;
  char t[8];

  CHK_PutChunkyColours(cp, &DemoScreen->ViewPort);
  SetRast(DemoWindow->RPort, 0);

  y = YOFF + 16; x = XOFF;
  for(i = 0; i < 256; i++)
  {
    SetAPen(rp, 1); sprintf(t, "%ld", i);
    Move(rp, x, y+8); Text(rp, t, strlen(t));
    x += (3*8)+2; x2 = (x+BOXWIDTH)-1; y2 = (y+BOXHEIGHT)-1;
    SetAPen(rp, i); RectFill(rp, x, y, x2, y2);
    SetAPen(rp, 1);
    Move(rp, x, y);
    Draw(rp, x2, y); Draw(rp, x2, y2); Draw(rp, x, y2); Draw(rp, x, y);
    x += BOXWIDTH+2;
    if(x > (DemoWindow->Width - (BOXWIDTH + (8*3)+2)))
    {
      x = XOFF; y += YOFF+2;
    }
  }
}

int randmax(int n) { int i; for(;;) { i = rand(); if(!(i>n)) return(i); } }

void DemoSetRGB4(void)
{
  int i;

  for(i = 4; i < 256; i++)
    CHK_SetRGB4(cp, i, 255, 255, 255);

  DEMO_Request("Done.. hit them with the lights!", NULL, NULL);
  DisplayColours();

  DEMO_Request("Now for some random 0-255 colours...", NULL, NULL);
  for(i = 4; i < 256; i++)
    CHK_SetRGB4(cp, i, randmax(255), randmax(255), randmax(255));
  DisplayColours();

  DEMO_Request("CHK_SetRGB32() works just like CHK_SetRGB4() except that\n"
               "it takes 32-bit left-justifed values like\n"
               "graphics.library/SetRGB32().", "I see", NULL);
}

void DemoGetRGB4(void)
{
  int i, x, y;
  char s[80], label1[] = "Click the close gadget to use CHK_GetRGB32()!\0",
              label2[] = "Click the close gadget to quit!\0",
              label3[] = "Click the close gadget for more...\0";
  struct RastPort *rp = DemoWindow->RPort;
  struct cp_Colour4 col;
  struct cp_Colour32 *col32;

  DEMO_Request("Now then... what are the RGB values of all these colours?\n"
               "Let's use CHK_GetRGB4() to find out...", "Wicked", NULL);

  SetRast(DemoWindow->RPort, 0);

  x = 4; y = 12;
  for(i = 0; i < 256; i++)
  {
    CHK_GetRGB4(cp, i, &col);
    Move(rp, x, y);
    sprintf(s, "Col %3d - R: %3d G: %3d B: %3d  ", i, col.R, col.G, col.B);
    Text(rp, s, strlen(s));
    x += TextLength(rp, s, strlen(s)); if(x > 400) { x = 4; y += 10; }

    if(y > 460)
    {
      Move(rp, 4, 465);
      Text(rp, label3, strlen(label3));
      DEMO_WaitForCloseGadget();
      x = 4; y = 12;
      SetRast(DemoWindow->RPort, 0);
    }
  }

  Move(rp, 4, y + 12); Text(rp, label1, strlen(label1));
  DEMO_WaitForCloseGadget();

  // GetRGB32() demo

  SetRast(DemoWindow->RPort, 0);

  x = 4; y = 12;
  for(i = 0; i < 256; i++)
  {
    col32 = CHK_GetRGB32(cp, i);
    Move(rp, x, y);
    sprintf(s, "Col %3d - R: 0x%08X G: 0x%08X B: 0x%08X  ", i, col32->R, col32->G, col32->B);
    Text(rp, s, strlen(s));
    x += TextLength(rp, s, strlen(s)); if(x > 400) { x = 4; y += 10; }

    if(y > 460)
    {
      Move(rp, 4, 465);
      Text(rp, label3, strlen(label3));
      DEMO_WaitForCloseGadget();
      x = 4; y = 12;
      SetRast(DemoWindow->RPort, 0);
    }
  }

  Move(rp, 4, y + 12); Text(rp, label2, strlen(label2));
  DEMO_WaitForCloseGadget();
}
