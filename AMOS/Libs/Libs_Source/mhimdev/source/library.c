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


#include <proto/exec.h>
#include <exec/resident.h>
#include <exec/initializers.h>
#include "mhimdev.h"


/*** don't try to run this! ***/
LONG
returnError(void)
{
    return(-1);
}


static const ULONG libInitTable[4]; /* prototype */

const struct Resident romTag = 
{
    RTC_MATCHWORD,
    (struct Resident *)&romTag,
    (struct Resident *)libInitTable,
    RTF_AUTOINIT,
    VERSION,
    NT_LIBRARY,
    0,
    LIBNAME,
    IDSTRING,
    (APTR)libInitTable
};



struct LibInitData
{
    UBYTE i_Type;     UBYTE o_Type;     UBYTE  d_Type;     UBYTE p_Type;
    UBYTE i_Name;     UBYTE o_Name;     STRPTR d_Name;
    UBYTE i_Flags;    UBYTE o_Flags;    UBYTE  d_Flags;    UBYTE p_Flags;
    UBYTE i_Version;  UBYTE o_Version;  UWORD  d_Version;
    UBYTE i_Revision; UBYTE o_Revision; UWORD  d_Revision;
    UBYTE i_IdString; UBYTE o_IdString; STRPTR d_IdString;
    ULONG endmark;
};



/*** mandatory reserved library function ***/
static ULONG
i_libReserved(void)
{
    return(0);
}



/*** called by OpenLibrary() ***/
static struct Library* REGFUNC
i_libOpen(REG( a6, struct mhimdevBaseP *mybase))
{
    mybase->libNode.lib_Flags &= ~LIBF_DELEXP;
    mybase->libNode.lib_OpenCnt++;
    return(&mybase->libNode);
}



/*** remove lib from memory ***/
static BPTR REGFUNC
i_libExpunge(REG( a6, struct mhimdevBaseP *mybase))
{
    if(mybase->libNode.lib_OpenCnt==0)
    {
        struct ExecBase *SysBase = mybase->SysBase ;
        BPTR seglist = mybase->segList;
        Remove((struct Node *) mybase);
        FreeMem((STRPTR)mybase-mybase->libNode.lib_NegSize, (ULONG)(mybase->libNode.lib_NegSize+mybase->libNode.lib_PosSize));
        return(seglist);
    }
    mybase->libNode.lib_Flags |= LIBF_DELEXP;
    return(NULL);
}



/*** called by CloseLibrary() ***/
static BPTR REGFUNC
i_libClose(REG( a6, struct mhimdevBaseP *mybase))
{
    if(!(--mybase->libNode.lib_OpenCnt))
    {
#ifndef DEBUG
        if(mybase->libNode.lib_Flags & LIBF_DELEXP)
#endif
            return(i_libExpunge(mybase));
    }
    return(0);
}



/*** initialize library ***/
static struct Library* REGFUNC
i_libInit(REG( a0, BPTR seglist), REG( d0, struct mhimdevBaseP *mybase), REG( a6, struct ExecBase *SysBase))
{
    mybase->segList = seglist;
    mybase->SysBase = SysBase ;
    return(&mybase->libNode);   /* ok */
}



static const APTR libVectors[] =
{
    (APTR) i_libOpen,
    (APTR) i_libClose,
    (APTR) i_libExpunge,
    (APTR) i_libReserved,
    (APTR) i_MHIAllocDecoder,
    (APTR) i_MHIFreeDecoder,
    (APTR) i_MHIQueueBuffer,
    (APTR) i_MHIGetEmpty,
    (APTR) i_MHIGetStatus,
    (APTR) i_MHIPlay,
    (APTR) i_MHIStop,
    (APTR) i_MHIPause,
    (APTR) i_MHIQuery,
    (APTR) i_MHISetParam,
    (APTR) -1
};



static const struct LibInitData libInitData =
{
    0xA0, (UBYTE) OFFSET(Node,    ln_Type),      NT_LIBRARY,                   0,
    0x80, (UBYTE) OFFSET(Node,    ln_Name),      LIBNAME,
    0xA0, (UBYTE) OFFSET(Library, lib_Flags),    LIBF_SUMUSED|LIBF_CHANGED,    0,
    0x90, (UBYTE) OFFSET(Library, lib_Version),  VERSION,
    0x90, (UBYTE) OFFSET(Library, lib_Revision), REVISION,
    0x80, (UBYTE) OFFSET(Library, lib_IdString), IDSTRING,
    0
};



static const ULONG libInitTable[4] =
{
    (ULONG)sizeof(struct mhimdevBaseP),
    (ULONG)libVectors,
    (ULONG)&libInitData,
    (ULONG)i_libInit
};

