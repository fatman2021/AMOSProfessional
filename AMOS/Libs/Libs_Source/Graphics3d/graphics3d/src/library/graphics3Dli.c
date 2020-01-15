/*
**      $VER: LibInit.c 37.16 (23.8.97)
**
**      Library initializers and functions to be called by StartUp.c
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

#include <proto/exec.h>

#include "graphics3Dbase.h"

ULONG L_OpenLibs(void);
void  L_CloseLibs(void);

extern struct Graphics3DBase *Graphics3DBase;


struct ExecBase      *SysBase       	   = NULL;
struct IntuitionBase *IntuitionBase 	   = NULL;
struct GfxBase       *GfxBase        	   = NULL;
struct LayersBase    *LayersBase           = NULL;
struct MathIEEEBase  *MathIeeeDoubBasBase  = NULL;
struct MathIEEEBase  *MathIeeeSingBasBase  = NULL;
struct DOSBase	     *DOSBase       	   = NULL;

#define VERSION  15
#define REVISION 10 

char ExLibName [] = "graphics3D.library";
char ExLibID   [] = "graphics3D 15.10 (10.05.99)";
char Copyright [] = "(C)opyright 1996-99 by Patrizio Biancalani & Andreas R. Kleinert . All rights reserved.";


/* -------------------------------------------------------------------------
 ! ROMTag and Library inilitalization structure:
 !
 ! Below you find the ROMTag, which is the most important "magic" part 
 ! of a library (as for any other resident module). You should not need 
 ! to modify any of the structures directly, since all the data is 
 ! referenced from constants from somewhere else.
 !
 ! You may place the ROMTag directly after the LibStart (-> StartUp.c) 
 ! function as well.
 !
 ! Note, that the data initialization structure may be somewhat redundantit's
 ! for demonstration purposes.
 !
 ! EndResident can be placed somewhere else - but it must follow the ROMTag 
 ! and it must not be placed in a different SECTION.
 ------------------------------------------------------------------------ */

extern ULONG InitTab[];
extern APTR EndResident; /* below */

struct Resident ROMTag =     /* do not change */
{
 RTC_MATCHWORD,
 &ROMTag,
 &EndResident,
 RTF_AUTOINIT,
 VERSION,
 NT_LIBRARY,
 0,
 &ExLibName[0],
 &ExLibID[0],
 &InitTab[0]
};

APTR EndResident;

struct MyDataInit                      /* do not change */
{
 UWORD ln_Type_Init;      UWORD ln_Type_Offset;      UWORD ln_Type_Content;
 UBYTE ln_Name_Init;      UBYTE ln_Name_Offset;      ULONG ln_Name_Content;
 UWORD lib_Flags_Init;    UWORD lib_Flags_Offset;    UWORD lib_Flags_Content;
 UWORD lib_Version_Init;  UWORD lib_Version_Offset;  UWORD lib_Version_Content;
 UWORD lib_Revision_Init; UWORD lib_Revision_Offset; UWORD lib_Revision_Content;
 UBYTE lib_IdString_Init; UBYTE lib_IdString_Offset; ULONG lib_IdString_Content;
 ULONG ENDMARK;
} DataTab =
#ifdef VBCC
{
	0xe000,8,NT_LIBRARY, 
	0x0080,10,(ULONG) &ExLibName[0], 
	0xe000,LIBF_SUMUSED|LIBF_CHANGED, 
	0xd000,20,VERSION, 
	0xd000,22,REVISION, 
	0x80,24,(ULONG) &ExLibID[0], 
	(ULONG) 0
};
#else
{
 INITBYTE(OFFSET1(Node,         ln_Type),      NT_LIBRARY),
 0x80, (UBYTE) OFFSET1(Node,    ln_Name),      (ULONG) &ExLibName[0],
 INITBYTE(OFFSET1(Library,      lib_Flags),    LIBF_SUMUSED|LIBF_CHANGED),
 INITWORD(OFFSET1(Library,      lib_Version),  VERSION),
 INITWORD(OFFSET1(Library,      lib_Revision), REVISION),
 0x80, (UBYTE) OFFSET1(Library, lib_IdString), (ULONG) &ExLibID[0],
 (ULONG) 0
};
#endif

/*--------------------------------------------------------------------------
 ! L_OpenLibs:
 !
 ! Since this one is called by InitLib, libraries not shareable between 
 ! Processes or libraries messing with RamLib (deadlock and crash) may not 
 ! be opened here.
 !
 ! You may bypass this by calling this function fromout LibOpen, but then 
 ! you will have to a) protect it by a semaphore and b) make sure, that 
 ! libraries are only opened once (when using globa library bases).
 ------------------------------------------------------------------------ */

ULONG L_OpenLibs(void)
{
 SysBase = (*((struct ExecBase **) 4));

 IntuitionBase =
	(struct IntuitionBase *) OpenLibrary("intuition.library", 37);
 if(!IntuitionBase) return(FALSE);

 GfxBase = (struct GfxBase *) OpenLibrary("graphics.library", 37);
 if(!GfxBase) 
	{
	CloseLibrary(IntuitionBase);
	return(FALSE);
	}

 LayersBase = (struct LayersBase *) OpenLibrary("layers.library", 37);
 if(!LayersBase) 
	{
	CloseLibrary(IntuitionBase);
	CloseLibrary(GfxBase);
	return(FALSE);
	}

 MathIeeeSingBasBase=
	(struct MathIeeeSingBasBase *)
	OpenLibrary("mathieeesingbas.library",37);
 if(!MathIeeeSingBasBase) 
	{
	CloseLibrary(IntuitionBase);
	CloseLibrary(GfxBase);
	CloseLibrary(LayersBase);
	return(FALSE);
	}

 MathIeeeDoubBasBase=
	(struct MathIeeeDoubBasBase *)
	OpenLibrary("mathieeedoubbas.library",37);
 if(!MathIeeeDoubBasBase) 
	{
	CloseLibrary(IntuitionBase);
	CloseLibrary(GfxBase);
	CloseLibrary(LayersBase);
	CloseLibrary(MathIeeeSingBasBase);
	return(FALSE);
	}
 DOSBase = (struct DOSBase *) OpenLibrary("dos.library", 37);
 if(!DOSBase) 
	{
	CloseLibrary(IntuitionBase);
	CloseLibrary(GfxBase);
	CloseLibrary(LayersBase);
	CloseLibrary(MathIeeeSingBasBase);
	CloseLibrary(MathIeeeDoubBasBase);
	return(FALSE);
	}

 Graphics3DBase->exb_SysBase       = SysBase;

 Graphics3DBase->exb_IntuitionBase        = IntuitionBase;
 Graphics3DBase->exb_GfxBase              = GfxBase;
 Graphics3DBase->exb_LayersBase           = LayersBase;
 Graphics3DBase->exb_MathIeeeDoubBasBase  = MathIeeeDoubBasBase;
 Graphics3DBase->exb_MathIeeeSingBasBase  = MathIeeeSingBasBase;
 Graphics3DBase->exb_DOSBase       = DOSBase;

 return(TRUE);
}

/* -------------------------------------------------------------------------
 ! L_CloseLibs:
 !
 ! This one by default is called by ExpungeLib, which only can take place 
 ! once and thus per definition is single-threaded.
 !
 ! When calling this fromout LibClose instead, you will have to protect it 
 ! by a semaphore, since you don't know whether a given CloseLibrary(foobase)
 ! may cause a Wait().
 ! Additionally, there should be protection, that a library won't be closed 
 ! twice.
 ------------------------------------------------------------------------ */

void L_CloseLibs(void)
{
 if(DOSBase) CloseLibrary((struct Library *) DOSBase);
 if(MathIeeeDoubBasBase) CloseLibrary((struct Library *)MathIeeeDoubBasBase);
 if(MathIeeeSingBasBase) CloseLibrary((struct Library *)MathIeeeSingBasBase);
 if(LayersBase) CloseLibrary((struct Library *) LayersBase);
 if(GfxBase)       CloseLibrary((struct Library *) GfxBase);
 if(IntuitionBase) CloseLibrary((struct Library *) IntuitionBase);
}
