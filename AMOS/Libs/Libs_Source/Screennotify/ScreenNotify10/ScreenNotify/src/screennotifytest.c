#include <libraries/screennotify.h>
#include <clib/dos_protos.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/screennotify_protos.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/exec_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/screennotify_pragmas.h>
#include <stdlib.h>

extern struct Library *SysBase, *DOSBase, *IntuitionBase;

/* Create a test window on the Workbench screen */
static struct Window *CreateWindow(void)
{
 return(OpenWindowTags(NULL, WA_Width,         200,
                             WA_Height,        100,
                             WA_Flags,         WFLG_CLOSEGADGET | WFLG_DRAGBAR,
                             WA_IDCMP,         IDCMP_CLOSEWINDOW,
                             WA_PubScreenName, "Workbench",
                             WA_Title,         "ScreenNotify Test",
                             TAG_DONE));
}

/* Main program */
int main(int argc, char **argv)
{
 struct Library *ScreenNotifyBase;

 /* Open screennotify.library */
 if (ScreenNotifyBase = OpenLibrary(SCREENNOTIFY_NAME, SCREENNOTIFY_VERSION)) {
  struct MsgPort *p;

  /* Create message port for ScreenNotify notifications */
  if (p = CreateMsgPort()) {
   APTR handle;

   /* Add our program as WB client */
   if (handle = AddWorkbenchClient(p, 0)) {
    struct Window *w;

    /* Open window */
    if (w = CreateWindow()) {
     ULONG portmask, winmask;
     BOOL active = TRUE;

     /* Calculate signal masks */
     portmask = 1L << p->mp_SigBit;
     winmask  = 1L << w->UserPort->mp_SigBit;

     /* Event loop */
     while (active) {
      ULONG sigs;

      /* Wait for signals */
      sigs = Wait(portmask | winmask);

      /* WBClose notification? */
      if (sigs & portmask) {
       struct ScreenNotifyMessage *snm;

       /* Get message */
       while (snm = (struct ScreenNotifyMessage *) GetMsg(p)) {

        /* Workbench notification? */
        if (snm->snm_Type == SCREENNOTIFY_TYPE_WORKBENCH)

         /* Yes, Open/Close event? */
         switch (snm->snm_Value) {

          case FALSE: /* WB Close -> close our window */
           if (w) {
            CloseWindow(w);
            w       = NULL;
            winmask = NULL;
           }
           break;

          case TRUE:  /* WB Open -> reopen our window */
           if ((w == NULL) && (w = CreateWindow()))
            winmask = 1L << w->UserPort->mp_SigBit;
           break;
         }

        /* Reply message */
        ReplyMsg((struct Message *) snm);
       }
      }

      /* Window event? */
      if (sigs & winmask) {
       struct IntuiMessage *msg;

       /* Handle window events */
       while (msg = (struct IntuiMessage *) GetMsg(w->UserPort)) {

        if (msg->Class == IDCMP_CLOSEWINDOW) active = FALSE;

        ReplyMsg((struct Message *) msg);
       }
      }
     }

     /* Close window */
     CloseWindow(w);
    }

    /* Unregister WB client */
    while (!RemWorkbenchClient(handle)) Delay(10);
   }

   /* Delete message port */
   DeleteMsgPort(p);
  }

  /* Close wbclose.library */
  CloseLibrary(ScreenNotifyBase);
 }
}
