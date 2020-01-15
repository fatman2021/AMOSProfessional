/* test ttrender */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/ttengine.h>
#include <proto/asl.h>
#include <proto/datatypes.h>
#include <datatypes/pictureclass.h>

#include <libraries/ttengine.h>

extern struct Library *SysBase, *DOSBase;

struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase, *DataTypesBase;
struct BitMap *PicBitMap;
Object *Picture;

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

VOID ctext (struct Window *w, STRPTR text, ULONG y)
  {
    UWORD tl, bl;
    struct RastPort *rp = w->RPort;

    tl = strlen(text);
    bl = TT_TextLength(rp, text, tl);
    Move(rp, ((448 - bl) >> 1) + w->BorderLeft, y);
    TT_Text(rp, text, tl);
  }

/*----------------------------------------------------------------------------------------------------*/

BOOL init(VOID)
  {
    if (!(GfxBase = OpenLibrary("graphics.library", 39))) return FALSE;
    if (!(IntuitionBase = OpenLibrary("intuition.library", 39))) return FALSE;
    if (!(AslBase = OpenLibrary("asl.library", 38))) return FALSE;
    if (!(TTEngineBase = OpenLibrary("ttengine.library", 4))) return FALSE;
    if (!(DataTypesBase = OpenLibrary("datatypes.library", 39))) return FALSE;
    return TRUE;
  }

/*----------------------------------------------------------------------------------------------------*/

VOID cleanup(VOID)
  {
    if (DataTypesBase) CloseLibrary(DataTypesBase);
    if (TTEngineBase) CloseLibrary(TTEngineBase);
    if (AslBase) CloseLibrary(AslBase);
    if (IntuitionBase) CloseLibrary(IntuitionBase);
    if (GfxBase) CloseLibrary(GfxBase);
    return;
  }

/*----------------------------------------------------------------------------------------------------*/

VOID load_picture(struct Window *w)
  {
    if (Picture = NewDTObject("PROGDIR:picture",
      DTA_GroupID,    GID_PICTURE,
      PDTA_Remap,     TRUE,
      PDTA_DestMode,  PMODE_V43,
      PDTA_Screen,    (ULONG)w->WScreen,
      TAG_END))
      {
        DoDTMethod(Picture, NULL, NULL, DTM_PROCLAYOUT, NULL, DTSIF_NEWSIZE);
        GetDTAttrs(Picture, PDTA_DestBitMap, (ULONG)&PicBitMap, TAG_END);
      }
    return;
  }

/*----------------------------------------------------------------------------------------------------*/

int Main (void)
  {
    struct Window *win;
    STRPTR fontname;
    APTR font;

    if (init())
      {
        if (fontname = get_font_name(AslBase))
          {
            if (win = OpenWindowTags(NULL,
              WA_Top, 25,
              WA_Left, 0,
              WA_InnerWidth, 448,
              WA_InnerHeight, 262,
              WA_CloseGadget, TRUE,
              WA_DragBar, TRUE,
              WA_DepthGadget, TRUE,
              WA_Activate, TRUE,
              WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_INTUITICKS,
              WA_Title, (ULONG)"TTEngine font picture demo",
              WA_ScreenTitle, (ULONG)"TTEngine demo",
              TAG_END))
              {
                ULONG sigmask, signals, pen;
                BOOL running = TRUE;
                struct RastPort *rp = win->RPort;
                WORD cnt = 0;
                ULONG r = 0, g = 0x7FFFFFFF, b = 0xFFFFFFFF, icl;

                load_picture(win);

                if (font = TT_OpenFont(
                  TT_FontFile, (ULONG)fontname,
                  TT_FontSize, 26,
                TAG_END))
                  {
                    SetDrMd(rp, JAM1);
                    if (TT_SetFont(rp, font))
                      {
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
                                    icl = imsg->Class;
                                    ReplyMsg((struct Message*)imsg);
                                    if (icl == IDCMP_CLOSEWINDOW) running = FALSE;
                                    if (icl == IDCMP_INTUITICKS)
                                      {
                                        if (++cnt > 9)
                                          {
                                            ULONG pen;

                                            if (PicBitMap)
                                              BltBitMapRastPort(PicBitMap, 0, 0, rp, win->BorderLeft, win->BorderTop, 448, 262, 0xC0);

                                            cnt = 0;
                                            r += 0x0817736F;
                                            g += 0x0A27E836;
                                            b += 0x0C3A47D4;

                                            pen = ObtainBestPen(win->WScreen->ViewPort.ColorMap, r, g, b, TAG_END);
                                            SetAPen(rp, pen);

                                            TT_SetAttrs(rp,
                                              TT_Window, (ULONG)win,
                                              TT_Antialias, TT_Antialias_On,
                                              TT_Transparency, 0,
                                            TAG_END);

                                            ctext(win, "You can see here how the text is", 40);
                                            ctext(win, "smoothed on background picture.", 66);

                                            TT_SetAttrs(rp,
                                              TT_Antialias, TT_Antialias_Off,
                                            TAG_END);

                                            ctext(win, "This text is not smoothed", 102);
                                            ctext(win, "The difference is clearly", 128);
                                            ctext(win, "visible.", 154);

                                            TT_SetAttrs(rp,
                                              TT_Antialias, TT_Antialias_On,
                                              TT_Transparency, 64,
                                            TAG_END);

                                            ctext(win, "transparent text (75%)", 190);

                                            TT_SetAttrs(rp,
                                              TT_Transparency, 128,
                                            TAG_END);

                                            ctext(win, "transparent text (50%)", 216);

                                            TT_SetAttrs(rp,
                                              TT_Transparency, 192,
                                            TAG_END);

                                            ctext(win, "transparent text (25%)", 242);

                                            ReleasePen(win->WScreen->ViewPort.ColorMap, pen);
                                          }
                                      }
                                  }
                              }
                          }
                      }
                    else PutStr("TT_SetFont() failed.\n");
                    TT_CloseFont(font);
                  }
                else PutStr("Font open failed.\n");

                TT_DoneRastPort(rp);
                CloseWindow(win);
              }
            free_font_name(fontname);
          }
      }
    cleanup();
    return 0;
  }
