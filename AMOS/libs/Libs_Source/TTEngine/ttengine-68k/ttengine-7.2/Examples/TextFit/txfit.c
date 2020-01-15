/* test ttrender */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/ttengine.h>
#include <proto/asl.h>

#include <libraries/ttengine.h>

extern struct Library *SysBase, *DOSBase;

struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase;
ULONG Red;

/*----------------------------------------------------------------------------------------------------*/

static STRPTR get_font_name(struct Library *AslBase)
  {
    struct FileRequester *freq;
    STRPTR name = NULL;

    if (freq = AllocAslRequestTags(ASL_FileRequest, TAG_END))
      {
        if (AslRequestTags(freq,
          ASLFR_TitleText, (ULONG)"Select TrueType font",
          ASLFR_InitialDrawer, (ULONG)"FONTS:",
          ASLFR_DoPatterns, TRUE,
          ASLFR_InitialPattern, (ULONG)"#?.ttf",
          ASLFR_RejectIcons, TRUE,
          TAG_END))
          {
            ULONG namelen = strlen(freq->fr_File) + strlen(freq->fr_Drawer) + 4;

            if (name = AllocVec(namelen + 1, MEMF_ANY | MEMF_CLEAR))
              {
                strncpy(name, freq->fr_Drawer, namelen);
                AddPart(name, freq->fr_File, namelen);
              }
          }
        FreeAslRequest(freq);
      }
    return name;
  }

/*----------------------------------------------------------------------------------------------------*/

static VOID free_font_name(STRPTR name)
  {
    if (name) FreeVec(name);
  }

/*----------------------------------------------------------------------------------------------------*/

void fitted_text(STRPTR text, UWORD y, struct RastPort *rp, struct TextExtent *cte)
  {
    struct TextExtent te;
    UWORD len;
    ULONG pixlen, to_draw;

    /* draw constraint frame */

    SetAPen(rp, Red);
    Move(rp, 20 + cte->te_Extent.MinX, y + cte->te_Extent.MinY);
    Draw(rp, 20 + cte->te_Extent.MaxX, y + cte->te_Extent.MinY);
    Draw(rp, 20 + cte->te_Extent.MaxX, y + cte->te_Extent.MaxY);
    Draw(rp, 20 + cte->te_Extent.MinX, y + cte->te_Extent.MaxY);
    Draw(rp, 20 + cte->te_Extent.MinX, y + cte->te_Extent.MinY);

    /* draw text bounding box */

    len = strlen(text);
    to_draw = TT_TextFit(rp, text, len, &te, cte, 1, 0, 0);

    SetAPen(rp, 2);
    Move(rp, 20 + te.te_Extent.MinX, y + te.te_Extent.MinY);
    Draw(rp, 20 + te.te_Extent.MaxX, y + te.te_Extent.MinY);
    Draw(rp, 20 + te.te_Extent.MaxX, y + te.te_Extent.MaxY);
    Draw(rp, 20 + te.te_Extent.MinX, y + te.te_Extent.MaxY);
    Draw(rp, 20 + te.te_Extent.MinX, y + te.te_Extent.MinY);

    /* draw the text itself */

    SetAPen(rp, 1);
    Move(rp, 20, y);
    TT_Text(rp, text, to_draw);
  }


int Main (void)
  {
    struct Window *win;
    STRPTR fontname;

    if (GfxBase = OpenLibrary("graphics.library", 39))
      {
        if (IntuitionBase = OpenLibrary("intuition.library", 39))
          {
            if (AslBase = OpenLibrary("asl.library", 38))
              {
                if (fontname = get_font_name(AslBase))
                  {
                    if (TTEngineBase = OpenLibrary("ttengine.library", 0))
                      {
                        if (win = OpenWindowTags(NULL,
                          WA_Top, 25,
                          WA_Left, 0,
                          WA_Width, 640,
                          WA_Height, 210,
                          WA_CloseGadget, TRUE,
                          WA_DragBar, TRUE,
                          WA_DepthGadget, TRUE,
                          WA_IDCMP, IDCMP_CLOSEWINDOW,
                          WA_Title, (ULONG)"TT_TextFit() test",
                          TAG_END))
                          {
                            ULONG sigmask, signals;
                            BOOL running = TRUE;
                            struct RastPort *rp = win->RPort;
                            APTR font;

                            Red = ObtainBestPen(win->WScreen->ViewPort.ColorMap,
                              201, 0, 0, OBP_Precision, PRECISION_IMAGE, TAG_END);

                            if (font = TT_OpenFont(
                              TT_FontFile, (ULONG)fontname,
                              TT_FontSize, 16,
                            TAG_END))
                              {
                                struct TextExtent cte;
                                WORD i;

                                cte.te_Width = 32767;
                                cte.te_Height = 32767;
                                cte.te_Extent.MinX = -10;
                                cte.te_Extent.MinY = -20;
                                cte.te_Extent.MaxX = 600;
                                cte.te_Extent.MaxY = 20;

                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Window, (ULONG)win,
                                      TT_Antialias, TT_Antialias_On,
                                    TAG_END);

                                    SetDrMd(rp, JAM1);

                                    for (i = 0; i < 100; i++)
                                      {
                                        fitted_text("TT_TextFit() example shows how the text is fitted into constraining rectangle.", 45, rp, &cte);
                                        cte.te_Extent.MaxX -= 5;
                                        Delay(10);
                                        EraseRect(rp, win->BorderLeft, win->BorderTop,
                                          win->Width - win->BorderRight, win->Height - win->BorderBottom);
                                      }
                                  }
                                else PutStr("TT_SetFont() failed.\n");
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
                            ReleasePen(win->WScreen->ViewPort.ColorMap, Red);
                            TT_DoneRastPort(win->RPort);
                            CloseWindow(win);
                          }
                        CloseLibrary(TTEngineBase);
                      }
                    free_font_name(fontname);
                  }
                CloseLibrary(AslBase);
              }
            CloseLibrary(IntuitionBase);
          }
        CloseLibrary(GfxBase);
      }
    return 0;
  }
