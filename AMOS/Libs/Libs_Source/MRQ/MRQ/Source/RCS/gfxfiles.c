head	1.2;
access;
symbols;
locks
	msbethke:1.2; strict;
comment	@ * @;


1.2
date	2000.01.25.17.31.21;	author msbethke;	state Exp;
branches;
next	1.1;

1.1
date	2000.01.25.17.21.27;	author msbethke;	state Exp;
branches;
next	;


desc
@Guigfx/datatypes handling, gfx file stuff
@


1.2
log
@Adapted to new header names
@
text
@/* gfxfiles.c
** Guigfx/datatypes handling, gfx file stuff
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/*
** $Id: gfxfiles.c 1.1 2000/01/25 17:21:27 msbethke Exp msbethke $
**
** $Log: gfxfiles.c $
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
static void FillImgButtonStruct(struct MRQImageButton*, STRPTR);



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
			prdebug("Freeing preloaded image @@$%08lx\n",o);
			DeletePicture(o);
		}
	}
}

static void FillImgButtonStruct(struct MRQImageButton *ib, STRPTR filename)
{
	if(filename)
	{
		ib->mib_Picture = LoadPicture(filename,GGFX_UseMask,TRUE,TAG_DONE);
	}
}

void ReadImageButtons(struct MRQConfig *cfg)
{
	FillImgButtonStruct(&cfg->mc_IButton_Yes,ttVars.IB_Yes);
	FillImgButtonStruct(&cfg->mc_IButton_No,ttVars.IB_No);
	FillImgButtonStruct(&cfg->mc_IButton_Cancel,ttVars.IB_Cancel);
}

void FreeImageButtons(struct MRQConfig *cfg)
{
	/* color tables will be released when the pool is deleted */
	if(cfg->mc_IButton_Yes.mib_Picture) DeletePicture(cfg->mc_IButton_Yes.mib_Picture);
	if(cfg->mc_IButton_No.mib_Picture) DeletePicture(cfg->mc_IButton_No.mib_Picture);
	if(cfg->mc_IButton_Cancel.mib_Picture) DeletePicture(cfg->mc_IButton_Cancel.mib_Picture);
}
@


1.1
log
@Initial revision
@
text
@d10 5
a14 1
** $Id:$
a15 1
** $Log:$
d33 2
a34 2
#include "mrq_config.h"
#include "mrq_dtypes.h"
@
