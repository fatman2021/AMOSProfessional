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
    struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase;
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
                        if (win = OpenWindowTags(NULL,
                          WA_Top, 25,
                          WA_Left, 0,
                          WA_Width, 400,
                          WA_Height, 100,
                          WA_CloseGadget, TRUE,
                          WA_DragBar, TRUE,
                          WA_DepthGadget, TRUE,
                          WA_IDCMP, IDCMP_CLOSEWINDOW,
                          WA_Title, (ULONG)"TTEngine font names",
                          TAG_END))
                          {
                            ULONG sigmask, signals;
                            BOOL running = TRUE;
                            struct RastPort *rp = win->RPort;

                            if (font = TT_OpenFont(
                              TT_FontFile, (ULONG)fontname,
                              TT_FontSize, 18,
                            TAG_END))
                              {
                                STRPTR family, subfamily, fullname;

                                free_font_name(fontname);

                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Window, (ULONG)win,
                                      TT_Encoding, TT_Encoding_Default,
                                      TT_Antialias, TT_Antialias_On,
                                    TAG_END);

                                    TT_GetAttrs(rp,
                                      TT_FamilyName, (ULONG)&family,
                                      TT_SubfamilyName, (ULONG)&subfamily,
                                      TT_FontName, (ULONG)&fullname,
                                    TAG_END);

                                    SetAPen(rp, 1);
                                    SetDrMd(rp, JAM1);

                                    Move(rp, 10, 36);
                                    TT_Text(rp, family, strlen(family));
                                    Move(rp, 10, 54);
                                    TT_Text(rp, subfamily, strlen(subfamily));
                                    Move(rp, 10, 72);
                                    TT_Text(rp, fullname, strlen(fullname));
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
                            TT_DoneRastPort(rp);
                            CloseWindow(win);
                          }
                        CloseLibrary(TTEngineBase);
                      }
//                    free_font_name(fontname);
                  }
                CloseLibrary(AslBase);
              }
            CloseLibrary(IntuitionBase);
          }
        CloseLibrary(GfxBase);
      }
    return 0;
  }
