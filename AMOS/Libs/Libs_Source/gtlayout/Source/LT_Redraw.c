/*
**	GadTools layout toolkit
**
**	Copyright © 1993-1999 by Olaf `Olsen' Barthel
**		Freely distributable.
**
**	:ts=4
*/

#ifndef _GTLAYOUT_GLOBAL_H
#include "gtlayout_global.h"
#endif

#include "Assert.h"

/****** gtlayout.library/LT_Redraw ******************************************
*
*   NAME
*	LT_Redraw -- Redraw a single object (V47).
*
*   SYNOPSIS
*	LT_Redraw(handle,id)
*	           A0    D0
*
*	VOID LT_Redraw(LayoutHandle * handle,LONG id);
*
*   FUNCTION
*	This function is for redrawing a single object, as contained in
*	a window. This is not always necessary as the library will handle
*	display updates automatically. Please note that if this routine cannot
*	find the object you specified, it will resort to redraw the contents
*	of the entire window and no just a single element.
*
*   INPUTS
*	handle -- Pointer to a LayoutHandle structure.
*	id -- Numeric identifier of the object to redraw.
*
*   RESULT
*	none
*
*   SEE ALSO
*	intuition.library/BeginRefresh
*	intuition.library/EndRefresh
*	gtlayout.library/LT_EndRefresh
*
******************************************************************************
*
*/

VOID LIBENT
LT_Redraw(REG(a0) LayoutHandle *handle,REG(d0) LONG id)
{
	if(handle != NULL)
	{
		BOOL found;

		found = LTP_DrawGroupMember(handle,handle->TopGroup,id);
		if(NOT found)
		{
			#ifdef DO_BOOPSI_KIND
			{
				if(handle->BOOPSIList != NULL)
					RefreshGList((struct Gadget *)handle->BOOPSIList,handle->Window,NULL,(UWORD)-1);
			}
			#endif	/* DO_BOOPSI_KIND */

			RefreshGList(handle->List,handle->Window,NULL,(UWORD)-1);

			GT_RefreshWindow(handle->Window,NULL);

			LTP_DrawGroup(handle,handle->TopGroup);
		}
	}
}
