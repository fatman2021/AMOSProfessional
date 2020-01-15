/* test ttrender */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/ttengine.h>
#include <proto/asl.h>
#include <proto/cybergraphics.h>

#include <libraries/ttengine.h>

extern struct Library *SysBase, *DOSBase;

struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase, *CyberGfxBase;

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

int Main (void)
  {
    struct Window *win;
    STRPTR fontname;
    APTR font;

    if (GfxBase = OpenLibrary("graphics.library", 39))
      {
        if (IntuitionBase = OpenLibrary("intuition.library", 39))
          {
            if (AslBase = OpenLibrary("asl.library", 38))
              {
                if (fontname = get_font_name(AslBase))
                  {
                    if (TTEngineBase = OpenLibrary("ttengine.library", 4))
                      {
                        if (font = TT_OpenFont(
                          TT_FontFile, (ULONG)fontname,
                          TT_FontSize, 20,
                        TAG_END))
                          {
                            struct TT_Pixmap *px;

                            if (px = TT_GetPixmap(font, "Postprocessed pixmap", 20,
                              TT_Antialias, TT_Antialias_On,
                            TAG_END))
                              {
                                Printf("Pixmap $%08lx, %ld x %ld\n", (ULONG)px, px->ttp_Width, px->ttp_Height);
                                if (win = OpenWindowTags(NULL,
                                  WA_Top, 25,
                                  WA_Left, 0,
                                  WA_InnerWidth, px->ttp_Width * 3,
                                  WA_InnerHeight, px->ttp_Height * 3,
                                  WA_CloseGadget, TRUE,
                                  WA_DragBar, TRUE,
                                  WA_DepthGadget, TRUE,
                                  WA_IDCMP, IDCMP_CLOSEWINDOW,
                                  WA_Title, (ULONG)"Postprocessing demo",
                                TAG_END))
                                  {
                                    ULONG signals, sigmask;
                                    BOOL running = TRUE;
                                    WORD xi, yi;

                                    /* rendering processed pixelmap, it will be magnified */
                                    /* with factor 3 */

                                    if (CyberGfxBase = OpenLibrary("cybergraphics.library", 41))
                                      {
                                        for (xi = 0; xi < px->ttp_Width; xi++)
                                          {
                                            for (yi = 0; yi < px->ttp_Height; yi++)
                                              FillPixelArray(win->RPort, win->BorderLeft + xi * 3, win->BorderTop + yi * 3, 3, 3,
                                               px->ttp_Data[xi + yi * px->ttp_Width] * 0x00010101);
                                          }
                                        CloseLibrary(CyberGfxBase);
                                      }
                                    else PutStr("Program requires CyberGraphX or Picasso96\n");

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
                                    CloseWindow(win);
                                  }
                                TT_FreePixmap(px);
                              }
                          }
                        else PutStr("Font open failed.\n");
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
