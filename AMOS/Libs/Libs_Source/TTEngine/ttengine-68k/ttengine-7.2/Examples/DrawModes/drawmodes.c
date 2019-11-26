/* test ttrender */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/layers.h>
#include <proto/ttengine.h>
#include <proto/asl.h>

#include <libraries/ttengine.h>


extern struct Library *SysBase, *DOSBase;
struct Library *GfxBase, *TTEngineBase, *LayersBase, *IntuitionBase, *AslBase;

ULONG BPen1, BPen2, FPen, MPen;
WORD WinWidth, WinHeight;

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

VOID drawbg(struct Window *win)
  {
    WORD x, y;
    BOOL dark;
    struct RastPort *rp = win->RPort;
    struct Region *rg, *org;

    if (rg = NewRegion())
      {
        struct Rectangle rc;

        rc.MinX = win->BorderLeft;
        rc.MinY = win->BorderTop;
        rc.MaxX = win->Width - win->BorderRight - 1;
        rc.MaxY = win->Height - win->BorderBottom - 1;
        if (OrRectRegion(rg, &rc))
          {
            org = InstallClipRegion(win->RPort->Layer, rg);

            for (x = 0; x < WinWidth; x += 10)
              {
                dark = (x % 20) ? TRUE : FALSE;
                for (y = 0; y < WinHeight; y += 10)
                  {
                    if (dark) SetAPen(win->RPort, BPen1);
                    else SetAPen(win->RPort, BPen2);

                    RectFill(win->RPort, x + win->BorderLeft, y + win->BorderTop,
                     x + win->BorderLeft + 9, y + win->BorderTop + 9);
                    dark = !dark;
                  }
              }
          }
        InstallClipRegion(win->RPort->Layer, org);
        DisposeRegion(rg);
      }
  }

/*----------------------------------------------------------------------------------------------------*/

VOID drawtexts(struct Window *w)
  {
    LONG ascend, deltax, x;
    struct RastPort *rp = w->RPort;

    deltax = (WinWidth - 30 >> 2) + 6;
    x = w->BorderLeft + 6;

    TT_GetAttrs(rp, TT_FontAscender, (ULONG)&ascend, TAG_END);
//    SetAPen(rp, FPen);
//    SetBPen(rp, MPen);
    TT_SetAttrs(rp, TT_Window, (ULONG)w, TAG_END);

    SetDrMd(rp, JAM1);
    Move(rp, x, w->BorderTop + 6 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | INVERSVID);
    Move(rp, x, w->BorderTop + 6 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | COMPLEMENT);
    Move(rp, x, w->BorderTop + 6 + ascend);
    TT_Text(rp, "Sample", 6);
    Move(rp, x, w->BorderTop + 6 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | INVERSVID | COMPLEMENT);
    Move(rp, x, w->BorderTop + 6 + ascend);
    TT_Text(rp, "Sample", 6);
    x = w->BorderLeft + 6;

    SetDrMd(rp, JAM2);
    Move(rp, x, w->BorderTop + 60 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | INVERSVID);
    Move(rp, x, w->BorderTop + 60 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | COMPLEMENT);
    Move(rp, x, w->BorderTop + 60 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | INVERSVID | COMPLEMENT);
    Move(rp, x, w->BorderTop + 60 + ascend);
    TT_Text(rp, "Sample", 6);
    x = w->BorderLeft + 6;

    TT_SetAttrs(rp, TT_Transparency, 128, TAG_END);

    SetDrMd(rp, JAM1);
    Move(rp, x, w->BorderTop + 114 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | INVERSVID);
    Move(rp, x, w->BorderTop + 114 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | COMPLEMENT);
    Move(rp, x, w->BorderTop + 114 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM1 | INVERSVID | COMPLEMENT);
    Move(rp, x, w->BorderTop + 114 + ascend);
    TT_Text(rp, "Sample", 6);
    x = w->BorderLeft + 6;

    SetDrMd(rp, JAM2);
    Move(rp, x, w->BorderTop + 168 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | INVERSVID);
    Move(rp, x, w->BorderTop + 168 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | COMPLEMENT);
    Move(rp, x, w->BorderTop + 168 + ascend);
    TT_Text(rp, "Sample", 6);
    x += deltax;

    SetDrMd(rp, JAM2 | INVERSVID | COMPLEMENT);
    Move(rp, x, w->BorderTop + 168 + ascend);
    TT_Text(rp, "Sample", 6);
  }

/*----------------------------------------------------------------------------------------------------*/

VOID get_window_size(struct Screen *s, APTR font)
  {
    LONG w;

    WinWidth = 0;
    WinHeight = 222;

    if (TT_SetFont(&s->RastPort, font))
      {
        w = TT_TextLength(&s->RastPort, "Sample", 6);
        WinWidth = (w << 2) + 30;
      }
    return;
  }


/*----------------------------------------------------------------------------------------------------*/

VOID loop(struct Window *w)
  {
    ULONG sigmask, signals;
    BOOL running = TRUE;
    struct IntuiMessage *imsg;

    sigmask = SIGBREAKF_CTRL_C | (1 << w->UserPort->mp_SigBit);
    while (running)
      {
        signals = Wait(sigmask);
        if (signals & SIGBREAKF_CTRL_C) running = FALSE;
        if (signals & (1 << w->UserPort->mp_SigBit))
          {
            struct IntuiMessage *imsg;

            while (imsg = (struct IntuiMessage*)GetMsg(w->UserPort))
              {
                if (imsg->Class == IDCMP_CLOSEWINDOW) running = FALSE;
                ReplyMsg((struct Message*)imsg);
              }
          }
      }
  }


BOOL init(VOID)
  {
    if (!(GfxBase = OpenLibrary("graphics.library", 39))) return FALSE;
    if (!(IntuitionBase = OpenLibrary("intuition.library", 39))) return FALSE;
    if (!(AslBase = OpenLibrary("asl.library", 38))) return FALSE;
    if (!(TTEngineBase = OpenLibrary("ttengine.library", 4))) return FALSE;
    if (!(LayersBase = OpenLibrary("layers.library", 39))) return FALSE;
    return TRUE;
  }

VOID cleanup(VOID)
  {
    if (GfxBase) CloseLibrary(GfxBase);
    if (IntuitionBase) CloseLibrary(IntuitionBase);
    if (AslBase) CloseLibrary(AslBase);
    if (TTEngineBase) CloseLibrary(TTEngineBase);
    if (LayersBase) CloseLibrary(LayersBase);
  }

int main (void)
  {
    struct Window *win;
    STRPTR fontname;
    APTR font;
    struct Screen *s;

    if (init())
      {
        if (fontname = get_font_name(AslBase))
          {
            if (s = LockPubScreen(NULL))
              {
                if (font = TT_OpenFont(
                  TT_FontFile, (ULONG)fontname,
                  TT_FontSize, 48,
                TAG_END))
                  {
                    free_font_name(fontname);
                    get_window_size(s, font);

                    if (win = OpenWindowTags(NULL,
                      WA_Top, 25,
                      WA_Left, 0,
                      WA_InnerWidth, WinWidth,
                      WA_InnerHeight, WinHeight,
                      WA_CloseGadget, TRUE,
                      WA_DragBar, TRUE,
                      WA_DepthGadget, TRUE,
                      WA_Activate, TRUE,
                      WA_IDCMP, IDCMP_CLOSEWINDOW,
                      WA_Title, (ULONG)"TTEngine drawmodes",
                      WA_ScreenTitle, (ULONG)"TTEngine demo",
                    TAG_END))
                      {
                        struct RastPort *rp = win->RPort;

                        BPen1 = ObtainBestPen(win->WScreen->ViewPort.ColorMap,
                         0xD0D0D0D0, 0xB5B5B5B5, 0xB5B5B5B5, TAG_END);
                        drawbg(win);

                        BPen2 = ObtainBestPen(win->WScreen->ViewPort.ColorMap,
                         0x61616161, 0x91919191, 0x61616161, TAG_END);
                        drawbg(win);

//                        FPen = ObtainBestPen(win->WScreen->ViewPort.ColorMap,
//                         0xFFFFFFFF, 0xD0D0D0D0, 0x00000000, TAG_END);

//                        MPen = ObtainBestPen(win->WScreen->ViewPort.ColorMap,
//                         0x00000000, 0x4C4C4C4C, 0x80808080, TAG_END);

                        drawbg(win);

                        if (TT_SetFont(win->RPort, font))
                          {
                            TT_SetAttrs(rp,
                              TT_Window, (ULONG)win,
                              TT_Encoding, TT_Encoding_Default,
                              TT_Antialias, TT_Antialias_On,
                              TT_Foreground, 0x00FFD000,
                              TT_Background, 0x00004C80,
                            TAG_END);

                            drawtexts(win);
                            loop(win);
                          }
                        else PutStr("TT_SetFont() failed.\n");
                        ReleasePen(win->WScreen->ViewPort.ColorMap, BPen1);
                        ReleasePen(win->WScreen->ViewPort.ColorMap, BPen2);
//                        ReleasePen(win->WScreen->ViewPort.ColorMap, MPen);
//                        ReleasePen(win->WScreen->ViewPort.ColorMap, FPen);
                        TT_DoneRastPort(rp);
                        CloseWindow(win);
                      }
                    TT_CloseFont(font);
                  }
                else PutStr("Font open failed.\n");

                UnlockPubScreen(NULL, s);
              }
          }
      }
    cleanup();
    return 0;
  }
