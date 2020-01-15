//
// chunky.library demo
//
// This example demonstrates how to use BitMap's as ChunkyPort's,
// drawing parts of ChunkyPort's onto RastPort's and other ChunkyPort's.
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
#include <workbench/startup.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "/_shared/loadcp.h"
#include "/_shared/screen.h"
#include "/_shared/waitbutton.h"
#include "/_shared/requester.h"

struct Library *ChunkyBase;
void *Colours = NULL;
UBYTE *Bart = NULL;

#define BART_WIDTH  139
#define BART_HEIGHT 232

void DoDemo(void);
BOOL DemoAllocBitMap(void);
BOOL DemoDrawChunky(void);
BOOL DemoDrawChunkyChunky(void);
BOOL DemoDrawChunkyWindow(void);
void DemoDone(void);

void main2(void);
void StatusText(STRPTR Text);

void wbmain(struct WBStartup *wbmsg)
{
  main2();
}

main(int argc, char** argv)
{
  if(!argc) wbmain((struct WBStartup *)argv) else main2();
}

void main2(void)
{
  // Open the library
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
          DoDemo();
        }
        else printf("No bart.chk\n");
      }
      else printf("No memory for screen\n");
    }
    else printf("No bart.col\n");
    CloseLibrary(ChunkyBase);
  }
  else printf("No chunky.library v4\n");

  if(Bart) DEMO_FreeChunky(Bart);
  if(DemoScreen) DEMO_CloseScreen();
  if(Colours) DEMO_FreeRGB32(Colours);
}

void DoDemo(void)
{
  DEMO_Request("Welcome to the chunky.library Basic Demo!", "Woohoo!", NULL);
  DEMO_Request("First off, let's create a BitMap using AllocBitMap()\n"
               "and then convert it into a ChunkyPort.  I'll draw a\n"
               "few rectangles on the BitMap in a few colours.", NULL, NULL);
  if(!DemoAllocBitMap()) return;
  if(!DemoDrawChunky()) return;
  if(!DemoDrawChunkyChunky())  return;
  if(!DemoDrawChunkyWindow()) return;
  DemoDone();
}

int GetRandNumber(int max)
{
  int n, ok = 0;
  while(!ok)
  {
    n = rand();
    if(!(n > max)) ok = 1;
  }
  return(n);
}

void StatusText(STRPTR t)
{
  Move(DemoWindow->RPort, 20, 20);
  if(t)
   Text(DemoWindow->RPort, t, strlen(t))
  else
   SetRast(DemoWindow->RPort, 0);
}

BOOL DemoAllocBitMap(void)
{
  struct BitMap *BitMap = NULL;
  struct ChunkyPort *Converted = NULL;
  struct RastPort rp;
  BOOL ok = FALSE;

  // Allocate a bitmap
  if(BitMap = AllocBitMap(320, 200, 8, BMF_CLEAR, NULL))
  {
    int x1, y1, x2, y2, c, i;
    StatusText("Rendering boxes...");
    InitRastPort(&rp); rp.BitMap = BitMap;
    // Draw some rectangles on it
    for(i = 0; i < 50; i++)
    {
      x1 = GetRandNumber(319); y1 = GetRandNumber(199);
      x2 = x1 + GetRandNumber(319-x1); y2 = y1 + GetRandNumber(199-y1);
      c = GetRandNumber(254)+1;
      SetAPen(&rp, c);
      RectFill(&rp, x1, y1, x2, y2);
    }
    StatusText(NULL);

    DEMO_Request("Okay, drawn the boxes.  Now let's convert the BitMap\n"
                 "into a ChunkyPort...", NULL, NULL);

    if(Converted = CHK_CreateChunkyFromBitMap(BitMap, 0, 0, 320, 200))
    {
      DEMO_Request("... and now bring it to life by using CHK_DrawChunky()...", "Oh yes!", NULL);

      // Draw the converted BitMap onto the screen
      CHK_DrawChunky(Converted, DemoWindow->RPort, 160, 140);

      DEMO_Request("And volia!  Doesn't that look pretty? :)", "No!", NULL);
      ok = TRUE;
    }
    else
    {
      printf("Can't CHK_CreateChunkyFromBitMap() in DemoAllocBitMap()!\nNo memory?");
    }
  }
  if(Converted) CHK_FreeChunky(Converted);
  if(BitMap) FreeBitMap(BitMap);
  return(ok);
}

BOOL DemoDrawChunky(void)
{
  struct ChunkyPort *cp = NULL;
  int x, y, i, ok = FALSE;

  DEMO_Request("Now, boxes are very nice, but let's use some real graphics.\n"
               "Whilst you weren't looking, I loaded a chunky picture.  It is\n"
               "just a chunky image at the moment, and chunky.library doesn't\n"
               "know about it.  But, let's make it so it does.\n\n"
               "We do this allocating a buffer...", NULL, NULL);
  if(cp = CHK_InitChunky(BART_WIDTH, BART_HEIGHT))
  {
    DEMO_Request("...and then by CopyMem()'ing the chunky buffer into the\n"
                 "ChunkyPort I just made...", "Wooo...",  NULL);
    //
    // Okay this is a bit of a hack, but seems the most sensible way of
    // doing it.  Perhaps V5 will have a command to copy the data across..
    // :)
    //
    CopyMem(Bart, cp->cp_Chunky, (BART_WIDTH * BART_HEIGHT));

    DEMO_Request("I must stress that\m The Simpsons is (C) & (TM)\n"
                 "20th Century Fox Film Corporation, all rights reserved\n"
                 "This image is not used with permission.\n\n"
                 "Bah, it's for educational purposes damnit! :)", "Right on!", NULL);

    CHK_DrawChunky(cp, DemoWindow->RPort, (640-BART_WIDTH)/2, (480-BART_HEIGHT)/2);

    DEMO_Request("Don't have a cow, man!", "Eat my shorts!", NULL);
    DEMO_Request("Okay, let's have lots of Barts...", NULL, NULL);

    // There is a reason for this - demonstrating CHK_InsertChunky() in a mo :)
    for(i = 0; i < 5; i++)
    {
      x = GetRandNumber(640-BART_WIDTH); y = GetRandNumber(480-BART_HEIGHT);
      CHK_DrawChunky(cp, DemoWindow->RPort, x, y);
    }

    DEMO_Request("Hang on a minute.  CHK_DrawChunky() has also drawn colour zero\n"
                 "too, but I wanted it to be drawn transparent!\n\n"
                 "No problemo, CHK_InsertChunky() to the rescue!", "Hooray!", NULL);

    StatusText(NULL);
    for(i = 0; i < 5; i++)
    {
      x = GetRandNumber(640-BART_WIDTH); y = GetRandNumber(480-BART_HEIGHT);
      CHK_InsertChunky(cp, DemoWindow->RPort, x, y);
    }

    DEMO_Request("Cool!\n\nYou'll note that CHK_InsertChunky() can be\n"
                 "slow.  Blame ReadPixelArray8() for that.", "Dang", NULL);

    CHK_FreeChunky(cp);
    ok = TRUE;
  }
  else
  {
    printf("Can't alloc mem for Bart!\n");
  }
  return(ok);
}

void WriteLabel(STRPTR t, UWORD x, UWORD y)
{
  SetAPen(DemoWindow->RPort, 1);
  Move(DemoWindow->RPort, x, y); Text(DemoWindow->RPort, t, strlen(t));
}

BOOL DemoDrawChunkyChunky(void)
{
  struct ChunkyPort *cp = NULL, *cp2 = NULL;
  BOOL ok = FALSE;

  if((cp = CHK_InitChunky(128, 128)) && (cp2 = CHK_InitChunky(128, 128)))
  {
    DEMO_Request("Now, let's demonstrate drawing ChunkyPort's inside ChunkyPort's.\n\n"
                 "To do this, I've allocated two identical ChunkyPort's.\n"
                 "Let's draw a different coloured rectangle in each.", NULL, NULL);

    // Hell, I'm not supposed to demonstrate CHK_RectFill() here, but
    // never mind :)
    StatusText("CHK_RectFill()");
    CHK_SetAPen(cp, 2);  CHK_SetAPen(cp2, 3);
    CHK_RectFill(cp, 0, 0, 128, 128);
    CHK_RectFill(cp2, 32, 32, (32+64), (32+64));
    StatusText(NULL);
    CHK_DrawChunky(cp, DemoWindow->RPort, 20, 200);
    CHK_DrawChunky(cp2, DemoWindow->RPort, (20+cp->cp_Width)+16, 200);
    WriteLabel("ChunkyPort 1", 32, 188);
    WriteLabel("ChunkyPort 2", (32+cp->cp_Width), 188);

    DEMO_Request("Right, there's two ChunkyPort's drawn on the window using\n"
                 "CHK_DrawChunky().  Remember that both ChunkyPort's are the\n"
                 "same width,height - I've drawn the rectangle on ChunkyPort 2\n"
                 "to be half the size as the rectangle on ChunkyPort 1.\n\n"
                 "What I'll do now is CHK_DrawChunkyChunky() CP 2 onto CP 1...",
                 "Groovy", NULL);

    CHK_SetDrMd(cp2, JAM1); // new in v4
    CHK_DrawChunkyChunky(cp, cp2, 0, 0);
    // Draw the rectangle-on-rectangle onto  the window
    CHK_DrawChunky(cp, DemoWindow->RPort, 20, 200);
    // Just to iterate that cp2 is the same  as before. :)
    CHK_DrawChunky(cp2, DemoWindow->RPort, (20+cp->cp_Width)+16, 200);

    DEMO_Request("Tada!", NULL, NULL);
    StatusText(NULL);
    ok =  TRUE;
    CHK_FreeChunky(cp); CHK_FreeChunky(cp2);
  }
  else
  {
    printf("DemoDrawChunkyChunky() has no mem!\n");
  }
  return(ok);
}

BOOL DemoDrawChunkyWindow(void)
{
  struct Window *win = NULL;
  struct ChunkyPort *cp = NULL;
  BOOL ok = FALSE;

  DEMO_Request("Okay, new in V4 of chunky.library is a command called\n"
               "CHK_DrawChunkyWindow().  You'll know that all the drawing\n"
               "commands use RastPort's to display their data.  That's okay,\n"
               "but it's not very friendly if you're using a proper\n"
               "windowed environment.  CHK_DrawChunkyWindow() takes into\n"
               "account the Window's borders, and renders a ChunkyPort\n"
               "without overwriting the borders, etc.  So to demonstrate...",
               "Open a Window!", NULL);

  // First of all, we gonna reuse Bart for this...
  if(cp = CHK_InitChunky(BART_WIDTH, BART_HEIGHT))
  {
    CopyMem(Bart, cp->cp_Chunky, BART_WIDTH*BART_HEIGHT);

    if(win = OpenWindowTags(NULL,
       WA_Left, 128,
       WA_Top,  128,
       WA_Width, BART_WIDTH+60,
       WA_Height, BART_HEIGHT+20,
       WA_Flags, WFLG_DRAGBAR|WFLG_ACTIVATE,
       WA_CustomScreen, DemoScreen,
       WA_Title, "Will drop pants for food",
       TAG_DONE))
    {
      DEMO_Request("Drawing Bart using CHK_DrawChunky(cp, win->RPort, 0, 0)", "Right", NULL);

      CHK_DrawChunky(cp, win->RPort, 0, 0);

      DEMO_Request("See, went over the borders... let's refresh the window\n"
                   "and draw with CHK_DrawChunkyWindow(cp, win, 0, 0)...", "Oooh", NULL);

      SetRast(win->RPort, 0); RefreshWindowFrame(win);
      // Autodocs for this function were wrong prior to V4.1
      CHK_DrawChunkyWindow(cp, win, 0, 0);

      DEMO_Request("Wow, what a difference :)", "Heh", NULL);

      ok = TRUE;
    }
    else
    {
      printf("OpenWindowTags() failed in DemoDrawChunkyWindow()\n");
    }
    CHK_FreeChunky(cp);
  }
  else
  {
    printf("No mem in DemoDrawChunkyWindow()\n");
  }
  if(win) CloseWindow(win);
  return(ok);
}

void DemoDone(void)
{
  StatusText(NULL);
  WriteLabel("And that's it for this Basic demo!", 20, 20);
  WriteLabel("We hope you had a lot of fun, and will tune in next time", 20, 30);
  WriteLabel("for another thrilling installment of the Cosby Show.", 20, 40);
  WriteLabel("Same Bat-time, same Bat-channel!", 20, 60);
  WriteLabel("D'oh!", 20, 120);
  WriteLabel("Click the close button in the top-left to exit this madness.", 20, 140);
  DEMO_WaitForCloseGadget();
}
