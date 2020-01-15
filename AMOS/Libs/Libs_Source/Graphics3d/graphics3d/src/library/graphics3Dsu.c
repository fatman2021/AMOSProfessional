/*
**      $VER: StartUp.c 37.16 (23.8.97)
**
**      Library startup-code and function table definition
**
**      (C) Copyright 1996-97 Andreas R. Kleinert
**      All Rights Reserved.
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/libraries.h>
#include <exec/execbase.h>
#include <exec/resident.h>
#include <exec/initializers.h>

#include <proto/exec.h>    /* all other compilers */

#include "graphics3Dc.h"

#include "graphics3Dbase.h"
#include "graphics3D2D.h"
#include "graphics3Df.h"
#include "graphics3dl.h"

extern ULONG L_OpenLibs(void);
extern void  L_CloseLibs(void);

struct Graphics3DBase *InitLib( REG(a6) struct ExecBase *sysbase,
                    REG(a0) struct SegList *seglist,
                    REG(d0) struct Graphics3DBase *exb );

struct Graphics3DBase *OpenLib( REG(a6) struct Graphics3DBase *ExampleBase);

APTR CloseLib( REG(a6) struct Graphics3DBase *Graphics3DBase );

APTR ExpungeLib( REG(a6) struct Graphics3DBase *exb);

ULONG ExtFuncLib(void);


/* -------------------------------------------------------------------------
 ! LibStart:
 !
 ! If someone tries to start a library as an executable, it must return 
 ! (LONG) -1 as result. That's what we are doing here.
 ------------------------------------------------------------------------ */

LONG LibStart(void)
{
 return(-1);
}


/* -------------------------------------------------------------------------
 ! Function and Data Tables:
 !
 ! The function and data tables have been placed here for traditional 
 ! reasons.
 ! Placing the RomTag structure before (-> LibInit.c) would also be a good 
 ! idea, but it depends on whether you would like to keep the "version" 
 ! stuff separately.
 ------------------------------------------------------------------------ */

extern APTR FuncTab [];
extern struct MyDataInit DataTab; 
/* instead you may place ROMTag + Datatab directly, here */
/* (see LibInit.c). This may fix "Installer" version     */
/* checking problems, too.                               */

struct InitTable                       /* do not change */
{
 ULONG              LibBaseSize;
 APTR              *FunctionTable;
 struct MyDataInit *DataTable;
 APTR               InitLibTable;
} InitTab =
{
 sizeof(struct Graphics3DBase),
 &FuncTab[0],
 &DataTab,
 InitLib
};

APTR FuncTab [] =
{
 OpenLib,
 CloseLib,
 ExpungeLib,
 ExtFuncLib,

/* add your own functions here */

/* pubbliche */
/* for compatibility , don't change never the order of this functions */
/* add the new one after the last **/
 GD_switch_rp,
 GD_clipbox,
 GD_cls_b,
 GD_over,
 GD_display3d,
 GD_close_display3d,
 GD_changeviewmode,
 GD_changeviewmodeobj,
 GD_touchpalette,
 GD_moveforward,
 GD_viewangle,
 GD_frustum,
 GD_createlightsource,
 GD_ambientlight,
 GD_positioncamera,
 GD_aspectratio,
 GD_clipmode,
 GD_newobj,
 GD_deleteobject,
 GD_addobjvertex,
 GD_addobjpoly,
 GD_cattpoly,
 GD_setobj,
 GD_getobj,
 GD_translateobject,
 GD_positionobject,
 GD_scaleobject,
 GD_rotateobject,
 GD_pickobj,
 GD_rgb4,
 GD_paintframe,
 GD_newview,
 GD_recalcobj,
 GD_cascene,
 GD_int2fix,
 GD_fix2int,
 GD_sfl2fix,
 GD_fix2sfl,
 GD_dfl2fix,
 GD_fix2dfl,
 GD_loadobject,
 GD_genpalette,
 GD_modpoly,
 GD_newtmap,
 GD_rmtmap,
 GD_newtmapf,
 GD_colldetect,
 GD_modobj,

/* add the new one from here **/

/* private */

/* tappo */
 (APTR) ((LONG)-1)
};


extern struct Graphics3DBase *Graphics3DBase;

/* -------------------------------------------------------------------------
 ! InitLib:
 !
 ! This one is single-threaded by the Ramlib process. Theoretically you can 
 ! do, what you like here, since you have full exclusive control over all 
 ! the library code and data.
 ! But due to some bugs in Ramlib V37-40, you can easily cause a deadlock 
 ! when opening certain libraries here (which open other libraries, that 
 ! open other libraries, that...)
 ------------------------------------------------------------------------ */

struct Graphics3DBase *InitLib( REG(a6) struct ExecBase *sysbase,
                    REG(a0) struct SegList *seglist,
                    REG(d0) struct Graphics3DBase *exb)
{
 Graphics3DBase = exb;

 Graphics3DBase->exb_SysBase = sysbase;
 Graphics3DBase->exb_SegList = seglist;

 if(L_OpenLibs()) return(Graphics3DBase);

 L_CloseLibs();

  {
   ULONG negsize, possize, fullsize;
   UBYTE *negptr = (UBYTE *) Graphics3DBase;

   negsize  = Graphics3DBase->exb_LibNode.lib_NegSize;
   possize  = Graphics3DBase->exb_LibNode.lib_PosSize;
   fullsize = negsize + possize;
   negptr  -= negsize;

   FreeMem(negptr, fullsize);

  }

 return(NULL);
}

/* -------------------------------------------------------------------------
 ! OpenLib:
 !
 ! This one is enclosed within a Forbid/Permit pair by Exec V37-40. Since a 
 ! Wait() call would break this Forbid/Permit(), you are not allowed to 
 ! start any operations that may cause a Wait() during their processing. 
 ! It's possible, that future OS versions won't turn the multi-tasking off, 
 ! but instead use semaphore protection for this function.
 !
 ! Currently you only can bypass this restriction by supplying your own 
 ! semaphore mechanism.
 ------------------------------------------------------------------------ */

struct Graphics3DBase *OpenLib( REG(a6) struct Graphics3DBase *ExampleBase)
{

 Graphics3DBase->exb_LibNode.lib_OpenCnt++;

 Graphics3DBase->exb_LibNode.lib_Flags &= ~LIBF_DELEXP;

 return(Graphics3DBase);
}

/* -------------------------------------------------------------------------
 ! CloseLib:
 !
 ! This one is enclosed within a Forbid/Permit pair by Exec V37-40. Since a 
 ! Wait() call would break this Forbid/Permit(), you are not allowed to 
 ! start any operations that may cause a Wait() during their processing. 
 ! It's possible, that future OS versions won't turn the multi-tasking off, 
 ! but instead use semaphore protection for this function.
 !
 ! Currently you only can bypass this restriction by supplying your own 
 ! semaphore mechanism.
 ------------------------------------------------------------------------ */

APTR CloseLib( REG(a6) struct Graphics3DBase *Graphics3DBase )
{
 Graphics3DBase->exb_LibNode.lib_OpenCnt--;

 if(!Graphics3DBase->exb_LibNode.lib_OpenCnt)
  {
   if(Graphics3DBase->exb_LibNode.lib_Flags & LIBF_DELEXP)
    {
     return( ExpungeLib(Graphics3DBase) );
    }
  }

 return(NULL);
}

/* -------------------------------------------------------------------------
 ! ExpungeLib:
 !
 ! This one is enclosed within a Forbid/Permit pair by Exec V37-40. Since a 
 ! Wait() call would break this Forbid/Permit(), you are not allowed to 
 ! start any operations that may cause a Wait() during their processing. 
 ! It's possible, that future OS versions won't turn the multi-tasking off, 
 ! but instead use semaphore protection for this function.
 !
 ! Currently you only could bypass this restriction by supplying your own 
 ! semaphore mechanism - but since expunging can't be done twice, one 
 ! should avoid it here.
 ------------------------------------------------------------------------ */

APTR ExpungeLib( REG(a6) struct Graphics3DBase *exb )
{
 struct Graphics3DBase *Graphics3DBase = exb;
 struct SegList *seglist;

 if(!Graphics3DBase->exb_LibNode.lib_OpenCnt)
  {
   ULONG negsize, possize, fullsize;
   UBYTE *negptr = (UBYTE *) Graphics3DBase;

   seglist = Graphics3DBase->exb_SegList;

   Remove((struct Node *)Graphics3DBase);

   L_CloseLibs();

   negsize  = Graphics3DBase->exb_LibNode.lib_NegSize;
   possize  = Graphics3DBase->exb_LibNode.lib_PosSize;
   fullsize = negsize + possize;
   negptr  -= negsize;

   FreeMem(negptr, fullsize);

   return(seglist);
  }

 Graphics3DBase->exb_LibNode.lib_Flags |= LIBF_DELEXP;

 return(NULL);
}

/* -------------------------------------------------------------------------
 ! ExtFunct:
 !
 ! This one is enclosed within a Forbid/Permit pair by Exec V37-40. Since a 
 ! Wait() call would break this Forbid/Permit(), you are not allowed to 
 ! start any operations that may cause a Wait() during their processing. 
 ! It's possible, that future OS versions won't turn the multi-tasking off, 
 ! but instead use semaphore protection for this function.
 !
 ! Currently you only can bypass this restriction by supplying your own 
 ! semaphore mechanism - but since this function currently is unused, you 
 ! should not touch it, either.
 ------------------------------------------------------------------------ */

ULONG ExtFuncLib(void)
{
 return(NULL);
}

struct Graphics3DBase *Graphics3DBase = NULL;


