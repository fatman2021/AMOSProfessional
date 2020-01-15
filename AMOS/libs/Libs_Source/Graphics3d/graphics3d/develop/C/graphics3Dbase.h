/*
**      $VER: graphics3Dbase.h 10.01 (01.11.97)
**
**      definition of Graphics3DBase
**
**      (C) Copyright 1996 Andreas R. Kleinert
**      (C) Copyright 1997 Patrizio Biancalani
**      All Rights Reserved.
*/

#ifndef GRAPHICS3D_GRAPHICS3DBASE_H
#define GRAPHICS3D_GRAPHICS3DBASE_H

#ifndef  EXEC_LIBRARIES
#include <exec/libraries.h>
#endif /* EXEC_LIBRARIES_H */

struct Graphics3DBase
{
 struct Library         exb_LibNode;
 APTR                   exb_SegList;
 struct ExecBase       *exb_SysBase;
 struct IntuitionBase  *exb_IntuitionBase;
 struct GfxBase        *exb_GfxBase;
 struct LayersBase     *exb_LayersBase;
 struct MathIEEEBase   *exb_MathIeeeDoubBasBase;
 struct MathIEEEBase   *exb_MathIeeeSingBasBase;
 struct DOSBase        *exb_DOSBase;
};

#endif /* GRAPHICS3D_GRAPHICS3DBASE_H */
