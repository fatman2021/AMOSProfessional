/* TTEngine test */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/ttengine.h>
#include <proto/utility.h>

#include <libraries/ttengine.h>


extern struct Library *SysBase, *DOSBase;


struct TMatrix
{
  ULONG xx, xy, yx, yy;
};

/*----------------------------------------------------------------------------------------------------*/

UWORD tx[] = {'T', 'e', 's', 't', ' ', '1', '6', '-', 'b', 'i', 't', ' ', 'U', 'n', 'i',
 'c', 'o', 'd', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '.', 0x0000};

int main (void)
  {
    struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase, *UtilityBase;
    struct Window *win;
    STRPTR fontname;
    APTR font;

    if (GfxBase = OpenLibrary("graphics.library", 39))
      {
        if (UtilityBase = OpenLibrary("utility.library", 39))
          {
            if (IntuitionBase = OpenLibrary("intuition.library", 39))
              {
                if (TTEngineBase = OpenLibrary("ttengine.library", 6))
                  {
                    struct TagItem *fontattrs;
                    APTR requester;

                    requester = TT_AllocRequest();
                    Printf("requester = $%08lx\n", requester);

                    if (fontattrs = TT_Request(requester,
										 TTRQ_DoSizes, FALSE,
										 TTRQ_DoWeight, TRUE,
										 TTRQ_DoStyle, TRUE,
										 TTRQ_DoPreview, TRUE,
                     TAG_END))
                      {
                        if (win = OpenWindowTags(NULL,
                          WA_Top, 25,
                          WA_Left, 0,
                          WA_Width, 640,
                          WA_Height, 350,
                          WA_CloseGadget, TRUE,
                          WA_DragBar, TRUE,
                          WA_DepthGadget, TRUE,
                          WA_IDCMP, IDCMP_CLOSEWINDOW,
                          WA_Title, (ULONG)"ttengine.library test",
                          TAG_END))
                          {
                            ULONG sigmask, signals;
                            BOOL running = TRUE;
                            struct RastPort *rp = win->RPort;
                            struct TMatrix tmt = { 0x00010000, 0x00000000, 0x00000000, 0x00008000 };

                            if (font = TT_OpenFont(
                             TT_FamilyTable, GetTagData(TT_FamilyTable, NULL, fontattrs),
                             TT_FontStyle, GetTagData(TT_FontStyle, 0, fontattrs),
                             TT_FontWeight, GetTagData(TT_FontWeight, TT_FontWeight_Normal, fontattrs),
                             TT_FontSize, 24,
                         //    TT_FontTransform, (ULONG)&tmt,
                             TAG_END))
                              {
                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Window, (ULONG)win,
                                     TAG_END);

                                    SetAPen(rp, 2);
                                    SetDrMd(rp, JAM1);
                                    Move(rp, 10, 50);
                                    TT_Text(rp, "This is a text printed with TT_Text().", 38);

                                    TT_SetAttrs(rp,
                                      TT_Antialias, TT_Antialias_Off,
                                      TT_Encoding, TT_Encoding_UTF16_BE,
                                    TAG_END);

                                    SetDrMd(rp, JAM2);
                                    SetBPen(rp, 3);
                                    Move(rp, 10, 74);
                                    TT_Text(rp, tx, 27);
                                  }
                                else PutStr("TT_SetFont() failed.\n");
                                TT_CloseFont(font);
                              }
                            else PutStr("Font open failed.\n");

                            if (font = TT_OpenFont(
                             TT_FamilyTable, GetTagData(TT_FamilyTable, NULL, fontattrs),
                             TT_FontStyle, GetTagData(TT_FontStyle, 0, fontattrs),
                             TT_FontWeight, GetTagData(TT_FontWeight, TT_FontWeight_Normal, fontattrs),
                             TT_FontSize, 36,
                            TAG_END))
                              {
                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Encoding, TT_Encoding_Default,
                                      TT_Antialias, TT_Antialias_On,
                                      TT_Window, (ULONG)win,
                                    TAG_END);

                                    SetAPen(rp, 1);
                                    SetBPen(rp, 2);
                                    SetDrMd(rp, JAM2);
                                    Move(rp, 10, 120);
                                    TT_Text(rp, "Antialias with 36 points size.", 30);
                                  }
                                else PutStr("TT_SetFont() failed.\n");
                                TT_CloseFont(font);
                              }
                            else PutStr("Font open failed.\n");

                            if (font = TT_OpenFont(
                             TT_FamilyTable, GetTagData(TT_FamilyTable, NULL, fontattrs),
                             TT_FontStyle, GetTagData(TT_FontStyle, 0, fontattrs),
                             TT_FontWeight, GetTagData(TT_FontWeight, TT_FontWeight_Normal, fontattrs),
                             TT_FontSize, 16,
                            TAG_END))
                              {
                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Encoding, TT_Encoding_Default,
                                      TT_Antialias, TT_Antialias_On,
                                      TT_Window, (ULONG)win,
                                    TAG_END);

                                    SetAPen(rp, 1);
                                    SetDrMd(rp, JAM1);
                                    Move(rp, 10, 140);
                                    TT_Text(rp, "Antialias with 16 points size.", 30);
                                    SetAPen(rp, 2);
                                    Move(rp, 10, 156);
                                    TT_Text(rp, "Antialias with 16 points size.", 30);
                                    SetAPen(rp, 3);
                                    Move(rp, 10, 172);
                                    TT_Text(rp, "Antialias with 16 points size.", 30);
                                  }
                                else PutStr("TT_SetFont() failed.\n");
                                TT_CloseFont(font);
                              }
                            else PutStr("Font open failed.\n");

                            /* antialias on different backgrounds */

                            if (font = TT_OpenFont(
                             TT_FamilyTable, GetTagData(TT_FamilyTable, NULL, fontattrs),
                             TT_FontStyle, GetTagData(TT_FontStyle, 0, fontattrs),
                             TT_FontWeight, GetTagData(TT_FontWeight, TT_FontWeight_Normal, fontattrs),
                             TT_FontSize, 24,
                            TAG_END))
                              {
                                ULONG red, grn, blu;

                                red = ObtainBestPen(win->WScreen->ViewPort.ColorMap, 0xFFFFFFFF, 0, 0, TAG_END);
                                grn = ObtainBestPen(win->WScreen->ViewPort.ColorMap, 0, 0xFFFFFFFF, 0, TAG_END);
                                blu = ObtainBestPen(win->WScreen->ViewPort.ColorMap, 0, 0, 0xFFFFFFFF, TAG_END);

                                    if (TT_SetFont(rp, font))
                                      {
                                    TT_SetAttrs(rp,
                                      TT_Encoding, TT_Encoding_Default,
                                      TT_Antialias, TT_Antialias_On,
                                      TT_Window, (ULONG)win,
                                    TAG_END);

                                    SetDrMd(rp, JAM2);

                                    TT_SetAttrs(rp, TT_Background, 0x0000FF00, TT_Foreground, 0x00FF0000, TAG_END);
                                    Move(rp, 10, 200);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x000000FF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00000000, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00FFFFFF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);

                                    TT_SetAttrs(rp, TT_Background, 0x00FF0000, TT_Foreground, 0x0000FF00, TAG_END);
                                    Move(rp, 10, 224);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x000000FF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00000000, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00FFFFFF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);

                                    TT_SetAttrs(rp, TT_Background, 0x000000FF, TT_Foreground, 0x00FF0000, TAG_END);
                                    Move(rp, 10, 248);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x0000FF00, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00000000, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00FFFFFF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);

                                    TT_SetAttrs(rp, TT_Background, 0x0000000, TT_Foreground, 0x00FF0000, TAG_END);
                                    Move(rp, 10, 272);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00000FF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x0000FF00, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00FFFFFF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);

                                    TT_SetAttrs(rp, TT_Background, 0x00FFFFFF, TT_Foreground, 0x00FF0000, TAG_END);
                                    Move(rp, 10, 296);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x000000FF, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x00000000, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                    TT_SetAttrs(rp, TT_Foreground, 0x0000FF00, TAG_END);
                                    TT_Text(rp, "Smooth47", 8);
                                  }
                                else PutStr("TT_SetFont() failed.\n");

                                ReleasePen(win->WScreen->ViewPort.ColorMap, red);
                                ReleasePen(win->WScreen->ViewPort.ColorMap, grn);
                                ReleasePen(win->WScreen->ViewPort.ColorMap, blu);

                                TT_CloseFont(font);
                              }
                            else PutStr("Font open failed.\n");

                            sigmask = SIGBREAKF_CTRL_C | (1 << win->UserPort->mp_SigBit);
                            while (running)
                              {
                                signals = Wait(sigmask);
                                if (signals & SIGBREAKF_CTRL_C) running = FALSE;
                                if (signals & (1 << win->UserPort->mp_SigBit))
                                  {
                                    struct IntuiMessage *imsg;

                                    while (imsg = (struct IntuiMessage*)GetMsg(win->UserPort))
                                      {
                                        if (imsg->Class == IDCMP_CLOSEWINDOW) running = FALSE;
                                        ReplyMsg((struct Message*)imsg);
                                      }
                                  }
                              }
                             TT_DoneRastPort(rp);
                            CloseWindow(win);
                          }
                      }
                    TT_FreeRequest(requester);
                    CloseLibrary(TTEngineBase);
                  }
                CloseLibrary(IntuitionBase);
              }
            CloseLibrary(UtilityBase);
          }
        CloseLibrary(GfxBase);
      }
    return 0;
  }
