/* test ttrender */

#define __NOLIBBASE__

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/ttengine.h>
#include <proto/asl.h>
#include <proto/timer.h>

#include <libraries/ttengine.h>

extern struct Library *SysBase, *DOSBase;

struct Library *TTEngineBase, *IntuitionBase, *GfxBase, *AslBase, *TimerBase,
               *MathIeeeSingBasBase;

LONG EClock;

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


void test_loop(struct RastPort *rp)
  {
    WORD a, b;
    struct EClockVal start, stop;
    LONG speed;

    Forbid();
    ReadEClock(&start);
    for (a = 10; a < 410; a += 10)
      {
        SetAPen(rp, a >> 3);
        SetBPen(rp, ~(a >> 3));
        for (b = 40; b < 440; b += 16)
          {
            Move(rp, a, b);
            TT_Text(rp, "speed test", 10);
          }
      }
    ReadEClock(&stop);
    Permit();
    if (stop.ev_lo < start.ev_lo) stop.ev_lo = !(start.ev_lo - stop.ev_lo);
    else stop.ev_lo -= start.ev_lo;
    speed = IEEESPFix(IEEESPDiv(IEEESPMul(IEEESPFlt(10000), IEEESPFlt(EClock)), IEEESPFlt(stop.ev_lo)));
    Printf("%ld glyphs per second.\n", speed);
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
                    if (TTEngineBase = OpenLibrary("ttengine.library", 0))
                      {
                        if (win = OpenWindowTags(NULL,
                          WA_Top, 25,
                          WA_Left, 0,
                          WA_Width, 640,
                          WA_Height, 480,
                          WA_CloseGadget, TRUE,
                          WA_DragBar, TRUE,
                          WA_DepthGadget, TRUE,
                          WA_IDCMP, IDCMP_CLOSEWINDOW,
                          WA_Title, (ULONG)"ttengine library speed test",
                          TAG_END))
                          {
                            ULONG sigmask, signals;
                            BOOL running = TRUE;
                            struct RastPort *rp = win->RPort;

                            if (font = TT_OpenFont(
                              TT_FontFile, (ULONG)fontname,
                              TT_FontSize, 16,
                            TAG_END))
                              {
                                struct timerequest req;
                                struct EClockVal ev;

                                if (MathIeeeSingBasBase = OpenLibrary("mathieeesingbas.library", 37))
                                  {
                                    if (OpenDevice ("timer.device", UNIT_ECLOCK, (struct IORequest*)&req, 0) == 0)
                                      {
                                        TimerBase = (struct Library*)req.tr_node.io_Device;
                                        EClock = ReadEClock(&ev);

                                        Printf("E clock will be used for measurements, frequency is %ld Hz.\n", EClock);

                                        if (TT_SetFont(rp, font))
                                          {
                                            TT_SetAttrs(rp,
                                              TT_Window, (ULONG)win,
                                              TT_Antialias, TT_Antialias_Off,
                                            TAG_END);

                                            SetDrMd(rp, JAM1);
                                            Printf("Antialias: OFF, mode: JAM1\n");
                                            test_loop(rp);
                                            EraseRect(rp, win->BorderLeft, win->BorderTop, win->Width - win->BorderRight - 1, win->Height - win->BorderBottom - 1);

                                            TT_SetAttrs(rp, TT_Antialias, TT_Antialias_On, TAG_END);
                                            Printf("Antialias: ON, mode: JAM1\n");
                                            test_loop(rp);
                                            EraseRect(rp, win->BorderLeft, win->BorderTop, win->Width - win->BorderRight - 1, win->Height - win->BorderBottom - 1);

                                            SetDrMd(rp, JAM2);
                                            Printf("Antialias: ON, mode: JAM2\n");
                                            test_loop(rp);
                                            EraseRect(rp, win->BorderLeft, win->BorderTop, win->Width - win->BorderRight - 1, win->Height - win->BorderBottom - 1);

                                            TT_SetAttrs(rp, TT_Antialias, TT_Antialias_Off, TAG_END);
                                            Printf("Antialias: OFF, mode: JAM2\n");
                                            test_loop(rp);
                                            EraseRect(rp, win->BorderLeft, win->BorderTop, win->Width - win->BorderRight - 1, win->Height - win->BorderBottom - 1);
                                          }
                                        else PutStr("TT_SetFont() failed.\n");
                                        CloseDevice((struct IORequest*)&req);
                                      }
                                    CloseLibrary(MathIeeeSingBasBase);
                                  }
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
