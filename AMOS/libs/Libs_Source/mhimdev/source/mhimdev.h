/*****************************************************************************

    mhimdev.library - MHI driver for mpeg.device
    Copyright (C) 2001  Michael Henke

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/


#include <exec/libraries.h>
#include <dos/dos.h>
#include "RegVar.h"


/* #define DEBUG - enable auto-expunge and debug output to serial port */
/*#define DEBUG*/


#define VERSION     1
#define REVISION    3
#define DATETXT     "03.10.2011"
#define VERSTXT     "1.3"

#define LIBNAME     "mhimdev.library"
#define IDSTRING    LIBNAME " " VERSTXT " (" DATETXT ")"


struct mhimdevBaseP
{
    struct Library      libNode;
    BPTR                segList;
    struct ExecBase *   SysBase ;
};


extern const UBYTE idstring[];


#ifdef DEBUG
extern void KPutStr(STRPTR);
extern LONG KPutChar(LONG);
#pragma **note: DEBUG mode is enabled
/* force SAS/C to print a warning */
#endif


extern APTR REGFUNC   i_MHIAllocDecoder(REG( a0, struct Task *task), REG( d0, ULONG mhisignal), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern void REGFUNC   i_MHIFreeDecoder(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern BOOL REGFUNC   i_MHIQueueBuffer(REG( a3, APTR handle), REG( a0, APTR buffer), REG( d0, ULONG size), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern APTR REGFUNC   i_MHIGetEmpty(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern UBYTE REGFUNC  i_MHIGetStatus(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern void REGFUNC   i_MHIPlay(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern void REGFUNC   i_MHIStop(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern void REGFUNC   i_MHIPause(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern ULONG REGFUNC  i_MHIQuery(REG( d1, ULONG query), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );
extern void REGFUNC   i_MHISetParam(REG( a3, APTR handle), REG( d0, UWORD param), REG( d1, ULONG value), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) );

