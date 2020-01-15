/* test ttengine - custom 8-bit encoding */

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

UWORD CustomEncodingTable[256];

/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/


static VOID free_font_name(STRPTR name)
  {
    if (name) FreeVec(name);
  }

/*----------------------------------------------------------------------------*/

VOID fill_table(UWORD *table)
  {
    WORD i;

    for (i = 0; i < 256; i++)
      {
        CustomEncodingTable[i] = i ^ 0x0015;
      }
    return;
  }

/*----------------------------------------------------------------------------*/

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
                    if (TTEngineBase = OpenLibrary("ttengine.library", 5))
                      {
                        fill_table(CustomEncodingTable);
                        if (win = OpenWindowTags(NULL,
                          WA_Top, 25,
                          WA_Left, 0,
                          WA_Width, 640,
                          WA_Height, 210,
                          WA_CloseGadget, TRUE,
                          WA_DragBar, TRUE,
                          WA_DepthGadget, TRUE,
                          WA_IDCMP, IDCMP_CLOSEWINDOW,
                          WA_Title, (ULONG)"Custom encoding test",
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
                                if (TT_SetFont(rp, font))
                                  {
                                    TT_SetAttrs(rp,
                                      TT_Window, (ULONG)win,
                                      TT_Antialias, TT_Antialias_On,
                                      TT_Encoding, TT_Encoding_ISO8859_1,
                                    TAG_END);

                                    SetDrMd(rp, JAM1);
                                    SetAPen(rp, 1);

                                    /* alphabet in ISO-8859-1 */

                                    Move (rp, 10, 40);
                                    TT_Text (rp, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz", 53);

                                    /* turn our weird encoding on, also set some Unicode encoding */
                                    /* just to check if custom overrides it as it should */

                                    TT_SetAttrs(rp,
                                      TT_CustomEncoding, (ULONG)CustomEncodingTable,
                                      TT_Encoding, TT_Encoding_UTF32_BE,              /* will be overriden */
                                    TAG_END);

                                    Move (rp, 10, 58);
                                    TT_Text (rp, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz", 54);
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
