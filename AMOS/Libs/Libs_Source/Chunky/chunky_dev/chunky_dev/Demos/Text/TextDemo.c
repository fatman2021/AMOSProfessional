//
// chunky.library demo
//
// This example shows how to use the funky text commands...
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
#include <pragma/diskfont_lib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "/_shared/screen.h"
#include "/_shared/waitbutton.h"
#include "/_shared/requester.h"
#include "/_shared/text.h"

struct Library *ChunkyBase;

void DoDemo(void);
BOOL DoTopazDemo(void);
void DoTextDemo(struct ChunkyPort *cp, int Height);
BOOL DoMultiDemo(void);

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
  DEMO_Request("A juicy example!\n\nHow to draw text with chunky.library.\n\n"
               "chunky.library has extensive support for fonts and even has\n"
               "some unique styles which even the graphics.library can't do.\n\n"
               "This example uses your default system font, and also a couple\n"
               "of the standard Workbench fonts.  Onwards...", "Cool", NULL);

  if(!DoTopazDemo()) return;
  if(!DoMultiDemo()) return;
}

int randmax(int n) { int i; if(n < 1) return(0); for(;;) { i = rand(); if(!(i>n)) return(i); } }

BOOL DoTopazDemo(void)
{
  struct TextFont *Topaz80 = NULL;
  struct ChunkyPort *cp = NULL;
  struct TextAttr topaz80attr = {"topaz.font", 8, FS_NORMAL, FPB_ROMFONT };
  int c, x, y, i, len;
  char s[80];
  BOOL ok = FALSE;

  // allocate buffer
  if(cp = CHK_InitChunky(320, 200))
  {
    // open topaz font
    if(Topaz80 = OpenFont(&topaz80attr))
    {
      // right then
      // install the font on the ChunkyPort
      // you MUST do this before you can  use any of the text routines
      CHK_SetFont(cp, Topaz80);

      DEMO_Request("Okay, topaz.font/8 is open (duh :).  Now draw the text\n"
                   "in JAM2, random colour, and anywhere in ChunkyPort...", NULL, NULL);

      sprintf(s, "topaz.font/8!");

      // Use CHK_TextLength() to figure out the width of the text
      len = CHK_TextLength(cp, s, strlen(s));

      for(i = 0; i < 50; i++)
      {
        c = randmax(255)+1;
        x = randmax(320-len-1);
        // *** NOTE THE VALUE FOR THE Y-COORD!  Add the height of the
        // font to your y-coord!  Very important!
        y = 8+randmax(200-(8*2)-1);

        CHK_SetAPen(cp, c);
        CHK_Move(cp, x, y);
        CHK_Text(cp, s);
      }

      CHK_DrawChunky(cp, DemoWindow->RPort, 160, 140);

      DEMO_Request("Nice!\n\nLet's demonstrate all the text styles...", "Yeh, baby!", NULL);
      DoTextDemo(cp, 8);
      DEMO_Request("..and you can combine other styles too!", "Amazing", NULL);

      ok = TRUE;
    }
    else
     printf("can't open topaz.font 8 (are you nuts?)\n");
  }
  else
   printf("no mem in DoTopazDemo()\n");

  if(cp) CHK_FreeChunky(cp);
  if(Topaz80) CloseFont(Topaz80);
  return(ok);
}

void DoTextDemo(struct ChunkyPort *cp, int Height)
{
  char s[40];
  int y = 8;

  CHK_ClearChunky(cp);

  // Set some pens with some of the styles use
  CHK_SetABOPen(cp, 1, 3, 2);
  CHK_SetDrMd(cp, JAM2);

  // Normal
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FS_NORMAL);  // just for completeness :)
  sprintf(s, "FS_NORMAL text"); CHK_Text(cp, s);
  y += Height + 8;
  // Bold
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_BOLD);
  sprintf(s, "FSF_BOLD text"); CHK_Text(cp, s);
  y += Height + 8;
  // 3D
  CHK_SetDrMd(cp, JAM1);
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_3D);  // chunky.lib specific
  sprintf(s, "FSF_3D text"); CHK_Text(cp, s);
  y += Height + 8;
  // Wide3D
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_WIDE3D);
  sprintf(s, "FSF_WIDE3D text"); CHK_Text(cp, s);
  y += Height + 8;
  // Outline
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_OUTLINE);
  sprintf(s, "FSF_OUTLINE text"); CHK_Text(cp, s);
  y += Height + 8;
  // Embossed
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_EMBOSSED);
  sprintf(s, "FSF_EMBOSSED text"); CHK_Text(cp, s);
  y += Height + 8;
  // Outline and Bold
  CHK_SetDrMd(cp, JAM2);
  CHK_SetAPen(cp, randmax(255)+1);
  CHK_Move(cp, 8, y);
  CHK_SetSoftStyle(cp, FSF_BOLD | FSF_OUTLINE);
  sprintf(s, "FSF_BOLD and FSF_OUTLINE text"); CHK_Text(cp, s);
  CHK_DrawChunky(cp, DemoWindow->RPort, 160, 140);
}

struct TextFont *DEMO_OpenDiskFont(STRPTR Name, int YSize)
{
  struct TextAttr ta;

  ta.ta_Name = Name;
  ta.ta_YSize = YSize;
  ta.ta_Style = FS_NORMAL;
  ta.ta_Flags = FPF_DISKFONT;

  return((struct TextFont *)OpenDiskFont(&ta));
}

BOOL DoMultiDemo(void)
{
  // Use multiple fonts
  struct ChunkyPort *cp = NULL;
  struct TextFont *tf =  NULL;

  if(cp = CHK_InitChunky(480, 360))
  {
    DEMO_Request("Okay.. let's try some different fonts.\n\nGimme a courier.font...", NULL, NULL);

    if(!(tf = DEMO_OpenDiskFont("courier.font", 13))) return(FALSE);
    CHK_SetFont(cp, tf);
    DoTextDemo(cp, 13);
    DEMO_Request("Nice.", "Yes", NULL);
    CloseFont(tf);

    if(!(tf = DEMO_OpenDiskFont("diamond.font", 20))) return(FALSE);
    CHK_SetFont(cp, tf);
    DoTextDemo(cp, 20);
    DEMO_Request("Groovy.", "Aye", NULL);
    CloseFont(tf);

    if(!(tf = DEMO_OpenDiskFont("opal.font", 12))) return(FALSE);
    CHK_SetFont(cp, tf);
    DoTextDemo(cp, 12);
    DEMO_Request("Right, that's enough.", NULL, NULL);
    CloseFont(tf);

    CHK_FreeChunky(cp);
    return(TRUE);
  }
  printf("no mem\n");
  return(FALSE);
}
