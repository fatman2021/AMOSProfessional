/* gfxfiles.c
** Guigfx/datatypes handling, gfx file stuff
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/*
** $Id: gfxfiles.c 1.2 2000/01/25 17:31:21 msbethke Exp msbethke $
**
** $Log: gfxfiles.c $
** Revision 1.2  2000/01/25 17:31:21  msbethke
** Adapted to new header names
**
** Revision 1.1  2000/01/25 17:21:27  msbethke
** Initial revision
**
*/


#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/locale.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/datatypes.h>
#include <proto/guigfx.h>
#include <exec/memory.h>
#include <dos/dosextens.h>
#include <guigfx/guigfx.h>
#include <lib/mb_utils.h>
#include <string.h>
#include <stdlib.h>
#include "mrq.h"
#include "config.h"
#include "gfxfiles.h"

/* local protos */
static void LoadImageButton(struct MRQImageButton*, STRPTR);


/* GetFileType()
** Checks a file's type and returns a mask of MIF_xxx flags
** currently only MIF_ANIMATION for ReqAttack anims implemented
*/
/*
ULONG GetFileType(STRPTR name)
{
ULONG flags=0;
BPTR fh;

	if(fh = Open(name,MODE_OLDFILE))
	{
		UBYTE filebuf[6];

		if(Read(fh,filebuf,sizeof(filebuf)) == sizeof(filebuf))
		{
			if(strncmp(filebuf,"RAIM",4) == 0) flags |= MIF_ANIMATION;
		}
		Close(fh);
	}
	return flags;
}
*/

BOOL PreloadImage(STRPTR file, struct MRQImage *img)
{
	return (BOOL)(img->mi_Object = LoadPicture(file,GGFX_UseMask,TRUE,TAG_DONE));
}

void FreePreloaded(struct MRQConfig *cfg)
{
struct MRQEventClass *mec;
APTR o;

	if(o = cfg->mc_DefClass.mec_Image.mi_Object) DeletePicture(o);

	for(	mec = (struct MRQEventClass*)(cfg->mc_ClassList.mlh_Head);
			mec->mec_Node.mln_Succ;
			mec=(struct MRQEventClass*)(mec->mec_Node.mln_Succ))	
	{
		if((o = mec->mec_Image.mi_Object) &&
			(!(((struct MRQImage*)o)->mi_Flags & MIF_FILENAME)))
		{
			prdebug("Freeing preloaded image @$%08lx\n",o);
			DeletePicture(o);
		}
	}
}

static void LoadImageButton(struct MRQImageButton *ib, STRPTR filename)
{
char *err;

	if(filename)
	{
		if(ib->mib_Picture = LoadPicture(filename,GGFX_UseMask,TRUE,TAG_DONE))
			prdebug("Imagebutton loaded: %s\n",filename);
		else
			err = "file not found or corrupt:";
	} else err ="missing filename";

	if(ib->mib_Picture == NULL)
		prdebug("Imagebutton loading failed: %s %s\n",err,filename?(char*)filename:"");
}

void ReadImageButtons(struct MRQConfig *cfg)
{
	LoadImageButton(&cfg->mc_IButton_Yes,ttVars.IB_Yes);
	LoadImageButton(&cfg->mc_IButton_No,ttVars.IB_No);
	LoadImageButton(&cfg->mc_IButton_Cancel,ttVars.IB_Cancel);
}

void FreeImageButtons(struct MRQConfig *cfg)
{
	/* color tables will be released when the pool is deleted */
	if(cfg->mc_IButton_Yes.mib_Picture) DeletePicture(cfg->mc_IButton_Yes.mib_Picture);
	if(cfg->mc_IButton_No.mib_Picture) DeletePicture(cfg->mc_IButton_No.mib_Picture);
	if(cfg->mc_IButton_Cancel.mib_Picture) DeletePicture(cfg->mc_IButton_Cancel.mib_Picture);
}
