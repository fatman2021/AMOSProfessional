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
STRPTR fontname;

/*----------------------------------------------------------------------------------------------------*/

static STRPTR get_font_name(struct Library *AslBase, ULONG num)
  {
    struct FileRequester *freq;
    STRPTR name = NULL;
    UBYTE title[28];

    sprintf(title, "Select %ld TrueType font", num);

    if (freq = AllocAslRequestTags(ASL_FileRequest, TAG_END))
      {
        if (AslRequestTags(freq,
          ASLFR_TitleText, (ULONG)"haha",
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

#define NFN 4

int Main (void)
  {
    struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase;
    struct Window *win;
    APTR fonts[NFN];
    WORD i;
    ULONG sigmask, signals;
    BOOL running = TRUE;

    if (GfxBase = OpenLibrary("graphics.library", 39))
      {
        if (IntuitionBase = OpenLibrary("intuition.library", 39))
          {
            if (AslBase = OpenLibrary("asl.library", 38))
              {
                if (TTEngineBase = OpenLibrary("ttengine.library", 4))
                  {
                    if (win = OpenWindowTags(NULL,
                      WA_Top, 25,
                      WA_Left, 0,
                      WA_Width, 550,
                      WA_Height, 150,
                      WA_CloseGadget, TRUE,
                      WA_DragBar, TRUE,
                      WA_DepthGadget, TRUE,
                      WA_IDCMP, IDCMP_CLOSEWINDOW,
                      WA_Title, (ULONG)"TTEngine test - 4 fonts at once",
                      TAG_END))
                      {
                        struct RastPort *rp = win->RPort;

                        for (i = 1; i <= NFN; i++)
                          {
                            if (!(fonts[i - 1] = TT_OpenFont(
                              TT_FontFile, (ULONG)fontname = get_font_name(AslBase, i),
                              TT_FontSize, 18,
                            TAG_END)))
                              {
                                PutStr("TT_OpenFont failed!\n");
                              }
                            else Printf("Font %ld @ $%08lx\n", i, (ULONG)fonts[i - 1]);
                            free_font_name(fontname);
                          }

                        SetDrMd(rp, JAM1);
                        SetAPen(rp, 2);
                        TT_SetAttrs(rp, TT_Window, (ULONG)win);

                        for (i = 1; i <= NFN; i++)
                          {
                            Printf("Font %ld at $%08lx\n", i, (ULONG)fonts[i - 1]);

                            if (TT_SetFont(rp, fonts[i - 1]))
                              {
                                Move(rp, 10, 20 + i * 18);
                                TT_Text(rp, "Text rendered with one of four TrueType fonts.", 46);
                              }
                          }

                        for (i = 1; i <= NFN; i++) if (fonts[i]) TT_CloseFont(fonts[i - 1]);

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
                CloseLibrary(AslBase);
              }
            CloseLibrary(IntuitionBase);
          }
        CloseLibrary(GfxBase);
      }
    return 0;
  }
