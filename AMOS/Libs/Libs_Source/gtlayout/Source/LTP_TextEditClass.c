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

/******************************************************************************/

#ifdef DO_TEXTEDIT_KIND	/* Support code */

/******************************************************************************/

#include <clib/keymap_protos.h>
#include <clib/layers_protos.h>
#include <clib/alib_protos.h>	/* For Coerce/Do/DoSuperMethod */

#include <pragmas/keymap_pragmas.h>
#include <pragmas/layers_pragmas.h>

/******************************************************************************/

#define G(x) ((struct Gadget *)x)

/******************************************************************************/

#define CLEAR_FLAG(v,f)		((v) &= (~(f)))
#define SET_FLAG(v,f)		((v) |=   (f))
#define FLAG_IS_SET(v,f)	(((v) & (f)) != 0)
#define FLAG_IS_CLEAR(v,f)	(((v) & (f)) == 0)

/******************************************************************************/

#define RAWKEY_BACKSPACE	65
#define RAWKEY_TAB			66
#define RAWKEY_ENTER		67
#define RAWKEY_RETURN		68
#define RAWKEY_HELP			95

/******************************************************************************/

#define IS_CONTROL_CHARACTER(c) ((c & 0xE0) == 0)

/******************************************************************************/

#define IEQUALIFIER_SHIFT	(IEQUALIFIER_LSHIFT|IEQUALIFIER_RSHIFT)
#define IEQUALIFIER_ALT		(IEQUALIFIER_LALT|IEQUALIFIER_RALT)

/******************************************************************************/

STATIC VOID
DrawButtonBevel(
	struct RastPort *	rp,
	UWORD *				pens,
	BOOL				recessed,
	LONG				left,
	LONG				top,
	LONG				width,
	LONG				height)
{
	UWORD shinePen,shadowPen;

	if(recessed)
	{
		shinePen	= pens[SHADOWPEN];
		shadowPen	= pens[SHINEPEN];
	}
	else
	{
		shinePen	= pens[SHINEPEN];
		shadowPen	= pens[SHADOWPEN];
	}

	SetDrMd(rp,JAM1);

	SetAPen(rp,shinePen);
	Move(rp,left + width - 2,top);
	Draw(rp,left,top);
	Draw(rp,left,top + height - 1);
	Move(rp,left + 1,top + height - 2);
	Draw(rp,left + 1,top + 1);

	SetAPen(rp,shadowPen);
	Move(rp,left + 1,top + height - 1);
	Draw(rp,left + width - 1,top + height - 1);
	Draw(rp,left + width - 1,top);
	Move(rp,left + width - 2,top + 1);
	Draw(rp,left + width - 2,top + height - 2);
}

/******************************************************************************/

STATIC Object *
NewMethod(
	Class *			cl,
	Object *		o,
	struct opSet *	ops)
{
	Object * result;

	result = (Object *)DoSuperMethodA(cl,o,(Msg)ops);
	if(result != NULL)
	{
		struct TextEditInfo * tei = INST_DATA(cl,result);
		struct DrawInfo * dri;
		BOOL success = FALSE;

		dri = (struct DrawInfo *)GetTagData(GA_DrawInfo,(ULONG)NULL,ops->ops_AttrList);
		if(dri != NULL)
		{
			BOOL gotTheFrame;

			tei->tei_DrawInfo = dri;

			if(IntuitionBase->lib_Version < 39)
			{
				gotTheFrame = TRUE;
			}
			else
			{
				tei->tei_Frame = NewObject(NULL,FRAMEICLASS,
					IA_FrameType,	FRAME_RIDGE,
					IA_EdgesOnly,	TRUE,
				TAG_DONE);

				gotTheFrame = (BOOL)(tei->tei_Frame != NULL);
			}

			if(gotTheFrame)
			{
				struct TextFont * font;
				struct IBox outBox;

				if(tei->tei_Frame != NULL)
				{
					struct IBox inBox;
					struct impFrameBox frameBoxMsg;

					frameBoxMsg.MethodID		= IM_FRAMEBOX;
					frameBoxMsg.imp_ContentsBox	= &inBox;
					frameBoxMsg.imp_FrameBox	= &outBox;
					frameBoxMsg.imp_DrInfo		= dri;
					frameBoxMsg.imp_FrameFlags	= 0;

					memset(&inBox,0,sizeof(inBox));

					DoMethodA((Object *)tei->tei_Frame,&frameBoxMsg);
				}
				else
				{
					outBox.Left	= -6;
					outBox.Top	= -3;
				}

				tei->tei_FrameLeft	= (-outBox.Left);
				tei->tei_FrameTop	= (-outBox.Top);

				font = (struct TextFont *)GetTagData(STRINGA_Font,(ULONG)NULL,ops->ops_AttrList);

				tei->tei_Context = TE_CreateTextEditContext(dri,font);
				if(tei->tei_Context != NULL)
				{
					if(TE_SetTextEditString(tei->tei_Context,""))
					{
						tei->tei_Dragging		= FALSE;
						tei->tei_NoFilterMode	= TRUE;
						tei->tei_ExitHelp		= FALSE;

						DoMethod(result,OM_SET,ops->ops_AttrList,NULL);

						success = TRUE;
					}
				}
			}
		}

		if(NO success)
		{
			CoerceMethod(cl,result,OM_DISPOSE);
			result = NULL;
		}
	}

	return(result);
}

STATIC ULONG
SetMethod(
	Class *			cl,
	Object *		o,
	struct opSet *	ops)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;
	struct RastPort * rp;
	struct TagItem * tag;
	struct TagItem * list;
	BOOL mustRefresh;
	LONG redrawMode;
	BOOL isDisabled;
	ULONG result;

	isDisabled = (BOOL)FLAG_IS_SET(G(o)->Flags,GFLG_DISABLED);
	redrawMode = GREDRAW_UPDATE;

	result = DoSuperMethodA(cl,o,(Msg)ops);
	mustRefresh = result;

	list = ops->ops_AttrList;
	while((tag = NextTagItem(&list)) != NULL)
	{
		BOOL setBox = FALSE;

		switch(tag->ti_Tag)
		{
			case GA_Disabled:

				if(isDisabled != (BOOL)(tag->ti_Data != 0))
				{
					mustRefresh = TRUE;
					redrawMode = GREDRAW_REDRAW;
				}

				result = TRUE;

				break;

			case STRINGA_Buffer:

				TE_SetTextEditString(tec,(STRPTR)tag->ti_Data);

				mustRefresh = TRUE;
				redrawMode = GREDRAW_REDRAW;

				result = TRUE;

				break;

			case STRINGA_BufferPos:

				rp = ObtainGIRPort(ops->ops_GInfo);
				if(rp != NULL)
				{
					TE_SetTextEditRastPort(tec,rp);

					TE_SetTextEditStringPosition(tec,tag->ti_Data);

					ReleaseGIRPort(rp);
					TE_SetTextEditRastPort(tec,NULL);
				}

				result = TRUE;

				break;

			case STRINGA_NoFilterMode:

				tei->tei_NoFilterMode = tag->ti_Data;
				break;

			case STRINGA_ExitHelp:

				tei->tei_ExitHelp = tag->ti_Data;
				break;

			case STRINGA_AltKeyMap:

				tei->tei_AltKeyMap = (struct KeyMap *)tag->ti_Data;
				break;

			case GA_Left:
			case GA_Top:
			case GA_Width:
			case GA_Height:

				setBox = TRUE;
				break;
		}

		if(setBox)
		{
			struct impFrameBox frameBoxMsg;
			struct IBox box;

			box = (*((struct IBox *)&G(o)->LeftEdge));

			box.Left	+= tei->tei_FrameLeft;
			box.Top		+= tei->tei_FrameTop;
			box.Width	-= 2 * tei->tei_FrameLeft;
			box.Height	-= 2 * tei->tei_FrameTop;

			TE_SetTextEditBox(tec,&box);
			mustRefresh = TRUE;

			if(tei->tei_Frame != NULL)
			{
				box.Left	= tei->tei_FrameLeft;
				box.Top		= tei->tei_FrameTop;

				frameBoxMsg.MethodID		= IM_FRAMEBOX;
				frameBoxMsg.imp_ContentsBox	= &box;
				frameBoxMsg.imp_FrameBox	= (struct IBox *)tei->tei_Frame;
				frameBoxMsg.imp_DrInfo		= tei->tei_DrawInfo;
				frameBoxMsg.imp_FrameFlags	= 0;

				DoMethodA((Object *)tei->tei_Frame,&frameBoxMsg);
			}
		}
	}

	if(mustRefresh)
	{
		rp = ObtainGIRPort(ops->ops_GInfo);
		if(rp != NULL)
		{
			DoMethod(o,GM_RENDER,ops->ops_GInfo,rp,redrawMode);

			ReleaseGIRPort(rp);
		}
	}

	return(result);
}

STATIC ULONG
GetMethod(
	Class *			cl,
	Object *		o,
	struct opGet *	opg)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;
	STRPTR string;
	LONG value;
	ULONG result;

	switch(opg->opg_AttrID)
	{
		case STRINGA_Buffer:

			TE_GetTextEditString(tec,&string);
			(*opg->opg_Storage) = (ULONG)string;
			result = TRUE;
			break;

		case STRINGA_BufferPos:

			TE_GetTextEditStringPosition(tec,&value);
			(*opg->opg_Storage) = (ULONG)value;
			result = TRUE;
			break;

		case STRINGA_NoFilterMode:

			(*opg->opg_Storage) = (ULONG)tei->tei_NoFilterMode;
			result = TRUE;
			break;

		case STRINGA_ExitHelp:

			(*opg->opg_Storage) = (ULONG)tei->tei_ExitHelp;
			result = TRUE;
			break;

		case STRINGA_AltKeyMap:

			(*opg->opg_Storage) = (ULONG)tei->tei_AltKeyMap;
			result = TRUE;
			break;

		default:

			result = DoSuperMethodA(cl,o,(Msg)opg);
			break;
	}

	return(result);
}

STATIC ULONG
RenderMethod(
	Class *				cl,
	Object *			o,
	struct gpRender *	gpr)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;
	struct RastPort * rp = gpr->gpr_RPort;

	TE_SetTextEditRastPort(tec,rp);

	if(gpr->gpr_Redraw == GREDRAW_TOGGLE)
	{
		if(FLAG_IS_SET(G(o)->Flags,GFLG_SELECTED))
			TE_Activate(tec);
		else
			TE_Deactivate(tec);
	}
	else
	{
		if(tei->tei_Frame != NULL)
		{
			DrawImageState(rp,(struct Image *)tei->tei_Frame,G(o)->LeftEdge,G(o)->TopEdge,IDS_NORMAL,tei->tei_DrawInfo);
		}
		else
		{
			DrawButtonBevel(rp,tei->tei_DrawInfo->dri_Pens,FALSE,G(o)->LeftEdge,G(o)->TopEdge,G(o)->Width,G(o)->Height);
			DrawButtonBevel(rp,tei->tei_DrawInfo->dri_Pens,TRUE, G(o)->LeftEdge + 2,G(o)->TopEdge + 1,G(o)->Width - 4,G(o)->Height - 2);
		}

		if(gpr->gpr_Redraw == GREDRAW_UPDATE)
			TE_RedrawIfNecessary(tec);
		else
			TE_Refresh(tec);
	}

	if(FLAG_IS_SET(G(o)->Flags,GFLG_DISABLED))
		TE_DrawDisabled(tec);

	TE_SetTextEditRastPort(tec,NULL);

	return(TRUE);
}

STATIC ULONG
HitTestMethod(
	Class *				cl,
	Object *			o,
	struct gpHitTest *	gpht)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;
	ULONG result = 0;

	if(FLAG_IS_CLEAR(G(o)->Flags,GFLG_DISABLED))
	{
		if(TE_MouseInArea(tec,gpht->gpht_Mouse.X,gpht->gpht_Mouse.Y))
			result = GMR_GADGETHIT;
	}

	return(result);
}

STATIC ULONG
InactiveMethod(
	Class *					cl,
	Object *				o,
	struct gpGoInactive *	gpgi)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct RastPort * rp;

	rp = ObtainGIRPort(gpgi->gpgi_GInfo);
	if(rp != NULL)
	{
		CLEAR_FLAG(G(o)->Flags,GFLG_SELECTED);
		DoMethod(o,GM_RENDER,gpgi->gpgi_GInfo,rp,GREDRAW_TOGGLE);

		ReleaseGIRPort(rp);
	}

	tei->tei_Dragging = FALSE;

	return(0);
}

STATIC ULONG
ActiveMethod(
	Class *				cl,
	Object *			o,
	struct gpInput *	gpi)
{
	struct RastPort * rp;
	ULONG result;

	rp = ObtainGIRPort(gpi->gpi_GInfo);
	if(rp != NULL)
	{
		struct TextEditInfo * tei = INST_DATA(cl,o);
		struct TextEditContext * tec = tei->tei_Context;

		SET_FLAG(G(o)->Flags,GFLG_SELECTED);
		DoMethod(o,GM_RENDER,gpi->gpi_GInfo,rp,GREDRAW_TOGGLE);

		if(gpi->gpi_IEvent->ie_Class == IECLASS_RAWMOUSE)
		{
			LONG x,y;

			TE_SetTextEditRastPort(tec,rp);

			x = gpi->gpi_Mouse.X - tei->tei_FrameLeft;
			y = gpi->gpi_Mouse.Y - tei->tei_FrameTop;

			TE_CursorToMouse(tec,x,y);
			tei->tei_Dragging = TRUE;

			TE_SetTextEditRastPort(tec,NULL);
		}

		ReleaseGIRPort(rp);

		result = GMR_MEACTIVE;
	}
	else
	{
		result = GMR_NOREUSE;
	}

	return(result);
}

STATIC ULONG
InputMethod(
	Class *				cl,
	Object *			o,
	struct gpInput *	gpi)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;
	ULONG result = GMR_MEACTIVE;

	if(gpi->gpi_IEvent->ie_Class == IECLASS_TIMER)
	{
		if(tei->tei_Dragging)
		{
			struct RastPort * rp = ObtainGIRPort(gpi->gpi_GInfo);
			if(rp != NULL)
			{
				LONG x,y;

				TE_SetTextEditRastPort(tec,rp);

				x = gpi->gpi_Mouse.X - tei->tei_FrameLeft;
				y = gpi->gpi_Mouse.Y - tei->tei_FrameTop;

				TE_MoveCursorWithMouse(tec,x,y);

				TE_SetTextEditRastPort(tec,NULL);
				ReleaseGIRPort(rp);
			}
		}
	}
	else if (gpi->gpi_IEvent->ie_Class == IECLASS_RAWMOUSE)
	{
		switch(gpi->gpi_IEvent->ie_Code)
		{
			case MENUDOWN:

				result = GMR_REUSE;
				break;

			case SELECTDOWN:

				if(NOT TE_MouseInArea(tec,gpi->gpi_Mouse.X,gpi->gpi_Mouse.Y))
				{
					result = GMR_REUSE;
				}
				else
				{
					struct RastPort * rp = ObtainGIRPort(gpi->gpi_GInfo);
					if(rp != NULL)
					{
						LONG x,y;

						TE_SetTextEditRastPort(tec,rp);

						x = gpi->gpi_Mouse.X - tei->tei_FrameLeft;
						y = gpi->gpi_Mouse.Y - tei->tei_FrameTop;

						TE_CursorToMouse(tec,x,y);
						tei->tei_Dragging = TRUE;

						TE_SetTextEditRastPort(tec,NULL);
						ReleaseGIRPort(rp);
					}
				}

				break;

			case SELECTUP:

				tei->tei_Dragging = FALSE;
				break;
		}
	}
	else if (gpi->gpi_IEvent->ie_Class == IECLASS_RAWKEY)
	{
		if(FLAG_IS_CLEAR(gpi->gpi_IEvent->ie_Code,IECODE_UP_PREFIX))
		{
			struct RastPort * rp;

			rp = ObtainGIRPort(gpi->gpi_GInfo);
			if(rp != NULL)
			{
				ULONG qualifier = gpi->gpi_IEvent->ie_Qualifier;
				UWORD code = gpi->gpi_IEvent->ie_Code;
				UBYTE c;

				TE_SetTextEditRastPort(tec,rp);

				if(MapRawKey(gpi->gpi_IEvent,&c,1,tei->tei_AltKeyMap) == 1)
				{
					if(tei->tei_NoFilterMode ||
					   NOT IS_CONTROL_CHARACTER(c) ||
					   code == RAWKEY_BACKSPACE ||
					   code == RAWKEY_TAB ||
					   code == RAWKEY_ENTER ||
					   code == RAWKEY_RETURN)
					{
						switch(c)
						{
							case '\b':

								if(code == RAWKEY_BACKSPACE)
								{
									if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
										TE_DeleteToStartOfLine(tec);
									else
										TE_RemoveChars(tec,1);
								}
								else
								{
									TE_AddString(tec,&c,1);
								}

								break;

							case '\t':

								if(code == RAWKEY_TAB)
								{
									(*gpi->gpi_Termination) = '\t';
                
									result = GMR_VERIFY;
                
									if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
										result |= GMR_NEXTACTIVE;
									else
										result |= GMR_PREVACTIVE;
								}
								else
								{
									TE_AddString(tec,&c,1);
								}

								break;

							case '\177':	/* del */

								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_DeleteToEndOfLine(tec);
								else
									TE_DeleteChars(tec,1);

								break;

							case '\r':

								if(code == RAWKEY_ENTER || code == RAWKEY_RETURN)
								{
									if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									{
										result = 0;
										break;
									}
									else
									{
										c = '\n';
									}
								}

								/* FALLS THROUGH TO */

							default:

								if(ToUpper(c) == 'X' && FLAG_IS_SET(qualifier,IEQUALIFIER_RCOMMAND))
								{
									TE_DeleteAll(tec);
								}
								else if (ToUpper(c) == 'Q' && FLAG_IS_SET(qualifier,IEQUALIFIER_RCOMMAND))
								{
									TE_RestoreBackup(tec);
								}
								else
								{
									TE_AddString(tec,&c,1);
								}

								break;
						}
					}
					else if (IS_CONTROL_CHARACTER(c))
					{
						switch(c)
						{
							case '\001':	/* ^A */

								TE_CursorStartOfLine(tec);
								break;

							case '\b':

								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_DeleteToStartOfLine(tec);
								else
									TE_RemoveChars(tec,1);

								break;

							case '\013':	/* ^L */

								TE_DeleteToEndOfLine(tec);
								break;

							case '\025':	/* ^U */

								TE_DeleteToStartOfLine(tec);
								break;

							case '\027':	/* ^W */

								TE_RemoveWord(tec);
								break;

							case '\030':	/* ^X */

								TE_DeleteAll(tec);
								break;

							case '\032':	/* ^Z */

								TE_CursorEndOfLine(tec);
								break;

							case '\r':

								(*gpi->gpi_Termination) = 0;

								result = GMR_VERIFY;
								break;
						}
					}
				}
				else
				{
					if((code >= CURSORUP && code <= CURSORLEFT) || (code == RAWKEY_HELP))
					{
						switch(code)
						{
							case CURSORUP:
                
								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_CursorPageUp(tec);
								else if (FLAG_IS_SET(qualifier,IEQUALIFIER_ALT))
									TE_CursorFirstLine(tec);
								else
									TE_CursorUp(tec,1);
                
								break;
                
							case CURSORDOWN:
                
								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_CursorPageDown(tec);
								else if (FLAG_IS_SET(qualifier,IEQUALIFIER_ALT))
									TE_CursorLastLine(tec);
								else
									TE_CursorDown(tec,1);
                
								break;
                
							case CURSORLEFT:
                
								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_CursorStartOfLine(tec);
								else if (FLAG_IS_SET(qualifier,IEQUALIFIER_ALT))
									TE_CursorStartOfLine(tec);
								else
									TE_CursorLeft(tec,1);
                
								break;
                
							case CURSORRIGHT:
                
								if(FLAG_IS_SET(qualifier,IEQUALIFIER_SHIFT))
									TE_CursorEndOfLine(tec);
								else if (FLAG_IS_SET(qualifier,IEQUALIFIER_ALT))
									TE_CursorEndOfLine(tec);
								else
									TE_CursorRight(tec,1);
                
								break;

							case RAWKEY_HELP:

								if(tei->tei_ExitHelp)
								{
									(*gpi->gpi_Termination) = RAWKEY_HELP;

									result = GMR_VERIFY;
								}

								break;
						}
					}
				}

				ReleaseGIRPort(rp);

				TE_SetTextEditRastPort(tec,NULL);
			}
		}
	}

	if(TE_IsRedrawNecessary(tec))
	{
		struct RastPort * rp;

		rp = ObtainGIRPort(gpi->gpi_GInfo);
		if(rp != NULL)
		{
			DoMethod(o,GM_RENDER,gpi->gpi_GInfo,rp,GREDRAW_UPDATE);

			ReleaseGIRPort(rp);
		}
	}

	return(result);
}

STATIC VOID
DisposeMethod(
	Class *		cl,
	Object *	o)
{
	struct TextEditInfo * tei = INST_DATA(cl,o);
	struct TextEditContext * tec = tei->tei_Context;

	TE_DeleteTextEditContext(tec);
	DisposeObject(tei->tei_Frame);
}

/******************************************************************************/

ULONG SAVE_DS ASM
LTP_TextEditClassDispatcher(
	REG(a0) Class *		cl,
	REG(a2) Object *	o,
	REG(a1) Msg			msg)
{
	ULONG result;

	switch(msg->MethodID)
	{
		case OM_NEW:

			result = (ULONG)NewMethod(cl,o,(struct opSet *)msg);
			break;

		case OM_SET:

			result = SetMethod(cl,o,(struct opSet *)msg);
			break;

		case OM_GET:

			result = GetMethod(cl,o,(struct opGet *)msg);
			break;

		case GM_RENDER:

			result = RenderMethod(cl,o,(struct gpRender *)msg);
			break;

		case GM_HITTEST:

			result = HitTestMethod(cl,o,(struct gpHitTest *)msg);
			break;

		case GM_GOINACTIVE:

			result = InactiveMethod(cl,o,(struct gpGoInactive *)msg);
			break;

		case GM_GOACTIVE:

			result = ActiveMethod(cl,o,(struct gpInput *)msg);
			break;

		case GM_HANDLEINPUT:

			result = InputMethod(cl,o,(struct gpInput *)msg);
			break;

		case OM_DISPOSE:

			DisposeMethod(cl,o);

			/* FALLS THROUGH TO */

		default:

			result = DoSuperMethodA(cl,o,msg);
			break;
	}

	return(result);
}

/******************************************************************************/

#endif /* DO_TEXTEDIT_KIND */
