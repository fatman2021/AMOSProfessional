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

#include <graphics/gfxmacros.h>
#include <exec/memory.h>

#include <clib/layers_protos.h>
#include <clib/alib_protos.h>	/* For Coerce/Do/DoSuperMethod */

#include <pragmas/layers_pragmas.h>

/******************************************************************************/

#define VISIBLE (0)

/******************************************************************************/

#define GRANULARITY 100

/******************************************************************************/

struct TextEditContext
{
	STRPTR				tec_String;
	LONG				tec_StringTotalSize;
	LONG				tec_StringUsedSize;

	STRPTR				tec_BackupString;
	LONG				tec_BackupStringSize;

	struct RastPort *	tec_RastPort;

	UWORD				tec_TextPen;
	UWORD				tec_BackPen;
	UWORD				tec_ShadowPen;

	UWORD				tec_ActiveTextPen;
	UWORD				tec_ActiveBackPen;
	UWORD				tec_InactiveTextPen;
	UWORD				tec_InactiveBackPen;

	BOOL				tec_IsActive;
	BOOL				tec_IsDrawable;

	BOOL				tec_BufferChanged;
	BOOL				tec_MustRedraw;
	LONG				tec_RedrawStartLine;
	LONG				tec_RedrawStopLine;
	ULONG				tec_CursorVisible;

	STRPTR				tec_LinePointer;
	LONG				tec_LineIndex;

	LONG				tec_MaxPixels;
	LONG				tec_MaxColumns;
	LONG				tec_MaxLines;

	LONG				tec_FirstLine;
	LONG				tec_FirstPixel;

	WORD				tec_Left;
	WORD				tec_Top;
	WORD				tec_Width;
	WORD				tec_Height;

	LONG				tec_NumLines;

	WORD				tec_CharWidth;
	WORD				tec_CharHeight;

	LONG				tec_CursorX;
	LONG				tec_CursorY;

	struct DrawInfo *	tec_DrawInfo;
	struct TextFont *	tec_Font;

	LONG				tec_PreviousFirstLine;
	BOOL				tec_PreviousDataValid;

	BOOL				tec_MustCountColumnsAndLines;

	struct TextExtent	tec_TextExtent;
	struct RastPort		tec_MeasureRastPort;
	BOOL				tec_MeasureRastPortReady;

	APTR				tec_MemoryPoolHeader;
};

/******************************************************************************/

extern APTR __asm AsmCreatePool(register __d0 ULONG MemFlags,
                                register __d1 ULONG PuddleSize,
                                register __d2 ULONG ThreshSize,
                                register __a6 struct Library * SysBase);

extern VOID __asm AsmDeletePool(register __a0 APTR PoolHeader,
                                register __a6 struct Library * SysBase);

extern APTR __asm AsmAllocPooled(register __a0 APTR PoolHeader,
                                 register __d0 ULONG Size,
                                 register __a6 struct Library * SysBase);

extern VOID __asm AsmFreePooled(register __a0 APTR PoolHeader,
                                register __a1 APTR Memory,
                                register __d0 ULONG MemSize,
                                register __a6 struct Library * SysBase);

/******************************************************************************/

STATIC VOID TE_FreeVec(struct TextEditContext * tec,APTR address);
STATIC APTR TE_AllocVec(struct TextEditContext * tec,ULONG size,ULONG attributes);
STATIC VOID TE_SetWriteMask(struct TextEditContext *tec, UBYTE mask);
STATIC VOID TE_SetABPenDrMd(struct TextEditContext *tec, LONG fgPen, LONG bgPen, LONG drawMode);
STATIC ULONG TE_TextLength(struct TextEditContext *tec, STRPTR string, LONG len);
STATIC ULONG TE_TextFit(struct TextEditContext *tec, STRPTR string, LONG len, LONG width);
STATIC ULONG TE_RoundedTextFit(struct TextEditContext *tec, STRPTR string, LONG len, LONG width, LONG *deltaPtr);
STATIC VOID TE_ScrollComplete(struct TextEditContext *tec, LONG deltaX, LONG deltaY);
STATIC LONG TE_StrLen(STRPTR string);
STATIC STRPTR TE_FindLine(struct TextEditContext *tec, LONG whichLine);
STATIC VOID TE_DrawComplete(struct TextEditContext *tec, LONG startLine, LONG stopLine);
STATIC VOID TE_FillArea(struct TextEditContext *tec, LONG left, LONG top, LONG width, LONG height);
STATIC VOID TE_PrintText(struct TextEditContext *tec, LONG skipPixels, LONG left, LONG top, LONG width, STRPTR string, LONG len);
STATIC VOID TE_CursorPositionToOffset(struct TextEditContext *tec, LONG *offsetPtr);
STATIC VOID TE_OffsetToCursorPosition(struct TextEditContext *tec, LONG offset);
STATIC BOOL TE_DetermineLinesAffectedByChanges(struct TextEditContext *tec, LONG firstByteChanged, LONG numBytesChanged, LONG *firstLinePtr, LONG *lastLinePtr);
STATIC VOID TE_MakeBackup(struct TextEditContext *tec);
STATIC VOID TE_CountColumnsAndLines(struct TextEditContext *tec);
STATIC VOID TE_DrawCursor(struct TextEditContext *tec, LONG mode);
STATIC VOID TE_ShowCursor(struct TextEditContext *tec);
STATIC VOID TE_HideCursor(struct TextEditContext *tec);
STATIC VOID TE_EraseCursor(struct TextEditContext *tec);
STATIC BOOL TE_ChooseVisibleOffsetForCursor(struct TextEditContext *tec);
STATIC VOID TE_MakeCursorVisible(struct TextEditContext *tec);
STATIC VOID TE_ValidateCursorX(struct TextEditContext *tec);
STATIC VOID TE_MarkForRedraw(struct TextEditContext *tec, LONG startLine, LONG stopLine);

/******************************************************************************/

STATIC VOID
TE_FreeVec(
	struct TextEditContext *	tec,
	APTR						address)
{
	if(address != NULL)
	{
		ULONG * mem = address;

		AsmFreePooled(tec->tec_MemoryPoolHeader,&mem[-1],mem[-1],SysBase);
	}
}

STATIC APTR
TE_AllocVec(
	struct TextEditContext *	tec,
	ULONG						size,
	ULONG						attributes)
{
	APTR result = NULL;

	if(size > 0)
	{
		APTR poolHeader;
		ULONG * mem;

		if(attributes & MEMF_LOCAL)
			poolHeader = (APTR)tec;
		else
			poolHeader = tec->tec_MemoryPoolHeader;

		mem = AsmAllocPooled(poolHeader,sizeof(*mem) + size,SysBase);
		if(mem != NULL)
		{
			(*mem++) = sizeof(*mem) + size;

			if(attributes & MEMF_CLEAR)
				memset(mem,0,size);

			result = mem;
		}
	}

	return(result);
}

/******************************************************************************/

#define STARTLINE_First	(-1)
#define STOPLINE_Last	(-1)

STATIC VOID
TE_DrawComplete(
	struct TextEditContext *	tec,
	LONG						startLine,
	LONG						stopLine)
{
	if(tec->tec_IsDrawable && tec->tec_Height >= tec->tec_CharHeight)
	{
		LONG whichLine,top,lineHeight,numLines,from,to,linesShown,i;
		STRPTR string;

		TE_HideCursor(tec);

		whichLine = tec->tec_FirstLine;

		lineHeight = tec->tec_CharHeight;
		numLines = tec->tec_NumLines;

		if(startLine == STARTLINE_First)
			from = 0;
		else
			from = startLine;

		whichLine += from;
		top = from * lineHeight;

		if(stopLine == STOPLINE_Last)
			to = numLines-1;
		else
			to = stopLine;

		TE_SetABPenDrMd(tec,tec->tec_TextPen,tec->tec_BackPen,JAM2);
		TE_SetWriteMask(tec,tec->tec_TextPen | tec->tec_BackPen);

		if(NOT tec->tec_BufferChanged && tec->tec_PreviousDataValid)
		{
			LONG numLinesToScroll;

			numLinesToScroll = abs(tec->tec_PreviousFirstLine - tec->tec_FirstLine);

			if(numLinesToScroll > 0 && numLinesToScroll < tec->tec_NumLines)
			{
				if(tec->tec_FirstLine < tec->tec_PreviousFirstLine)
				{
					TE_ScrollComplete(tec,0,-(numLinesToScroll * lineHeight));

					to = numLinesToScroll-1;
				}
				else /* if(tec->tec_FirstLine > tec->tec_PreviousFirstLine) */
				{
					TE_ScrollComplete(tec,0,numLinesToScroll * lineHeight);

					from = tec->tec_NumLines-numLinesToScroll;
					whichLine += from;
					top += from * lineHeight;
				}
			}
		}

		for(i = from ; i <= to ; i++)
		{
			string = TE_FindLine(tec,whichLine++);
			if(string != NULL)
			{
				TE_PrintText(tec,tec->tec_FirstPixel,tec->tec_Left,tec->tec_Top + top,tec->tec_Width,string,TE_StrLen(string));
			}
			else
			{
				SetAPen(tec->tec_RastPort,tec->tec_BackPen);
				TE_FillArea(tec,tec->tec_Left,tec->tec_Top + top,tec->tec_Width,lineHeight);
				SetAPen(tec->tec_RastPort,tec->tec_TextPen);
			}

			top += lineHeight;
		}

		linesShown = tec->tec_MaxLines - tec->tec_FirstLine;
		if(linesShown < numLines)
		{
			SetAPen(tec->tec_RastPort,tec->tec_BackPen);
			TE_FillArea(tec,tec->tec_Left,tec->tec_Top + linesShown * lineHeight,tec->tec_Width,(numLines - linesShown) * lineHeight);
			SetAPen(tec->tec_RastPort,tec->tec_TextPen);
		}

		TE_ShowCursor(tec);
	}

	tec->tec_MustRedraw		= FALSE;
	tec->tec_BufferChanged	= FALSE;

	tec->tec_RedrawStartLine	= tec->tec_NumLines-1;
	tec->tec_RedrawStopLine		= 0;

	tec->tec_PreviousFirstLine	= tec->tec_FirstLine;
	tec->tec_PreviousDataValid	= TRUE;
}

STATIC VOID
TE_FillArea(
	struct TextEditContext *	tec,
	LONG						left,
	LONG						top,
	LONG						width,
	LONG						height)
{
	if(width > 0 && height > 0)
	{
		RectFill(tec->tec_RastPort,
			left,top,
			left + width - 1,top + height - 1);
	}
}

STATIC VOID
TE_PrintText(
	struct TextEditContext *	tec,
	LONG						skipPixels,
	LONG						left,
	LONG						top,
	LONG						width,
	STRPTR						string,
	LONG						len)
{
	LONG totalChars,delta;

	if(skipPixels > 0)
	{
		totalChars = TE_RoundedTextFit(tec,(STRPTR)string,len,skipPixels,&delta);
		if(totalChars > 0)
		{
			string += totalChars;
			len -= totalChars;
		}
	}
	else
	{
		delta = 0;
	}

	if(len > 0)
	{
		totalChars = TE_TextFit(tec,(STRPTR)string,len,width - delta);
		if(totalChars > 0)
		{
			Move(tec->tec_RastPort,left + delta - tec->tec_TextExtent.te_Extent.MinX,top+tec->tec_RastPort->TxBaseline);
			Text(tec->tec_RastPort,(STRPTR)string,totalChars);
		}

		if(delta > 0)
		{
			SetAPen(tec->tec_RastPort,tec->tec_BackPen);
			TE_FillArea(tec,left,top,delta,tec->tec_CharHeight);
			SetAPen(tec->tec_RastPort,tec->tec_TextPen);

			left += delta;
			width -= delta;
		}
	}
	else
	{
		tec->tec_TextExtent.te_Width = 0;
	}

	if(width > tec->tec_TextExtent.te_Width)
	{
		SetAPen(tec->tec_RastPort,tec->tec_BackPen);
		TE_FillArea(tec,left + tec->tec_TextExtent.te_Width,top,width - tec->tec_TextExtent.te_Width,tec->tec_CharHeight);
		SetAPen(tec->tec_RastPort,tec->tec_TextPen);
	}
}

/******************************************************************************/

STATIC VOID
TE_SetWriteMask(
	struct TextEditContext *	tec,
	UBYTE						mask)
{
	if(GfxBase->lib_Version < 39)
		tec->tec_RastPort->Mask = mask;
	else
		SetWriteMask(tec->tec_RastPort,mask);
}

/******************************************************************************/

#define OLD_FgPen		(-1)
#define OLD_BgPen		(-1)
#define OLD_DrawMode	(-1)

STATIC VOID
TE_SetABPenDrMd(
	struct TextEditContext *	tec,
	LONG						fgPen,
	LONG						bgPen,
	LONG						drawMode)
{
	if(GfxBase->lib_Version < 39)
	{
		if(fgPen != OLD_FgPen)
			SetAPen(tec->tec_RastPort,fgPen);

		if(bgPen != OLD_BgPen)
			SetBPen(tec->tec_RastPort,bgPen);

		if(drawMode != OLD_DrawMode)
			SetDrMd(tec->tec_RastPort,drawMode);
	}
	else
	{
		if(fgPen == OLD_FgPen)
			fgPen = GetAPen(tec->tec_RastPort);

		if(bgPen == OLD_BgPen)
			bgPen = GetBPen(tec->tec_RastPort);

		if(drawMode == OLD_DrawMode)
			drawMode = GetDrMd(tec->tec_RastPort);

		SetABPenDrMd(tec->tec_RastPort,fgPen,bgPen,drawMode);
	}
}

/******************************************************************************/

STATIC ULONG
TE_TextLength(
	struct TextEditContext *	tec,
	STRPTR						string,
	LONG						len)
{
	ULONG result;

	TextFit(&tec->tec_MeasureRastPort,string,len,&tec->tec_TextExtent,NULL,1,32767,32767);

	result = tec->tec_TextExtent.te_Width + (-tec->tec_TextExtent.te_Extent.MinX);

	return(result);
}

STATIC ULONG
TE_TextFit(
	struct TextEditContext *	tec,
	STRPTR						string,
	LONG						len,
	LONG						width)
{
	ULONG result;

	result = TextFit(&tec->tec_MeasureRastPort,string,len,&tec->tec_TextExtent,NULL,1,width,32767);

	return(result);
}

STATIC ULONG
TE_RoundedTextFit(
	struct TextEditContext *	tec,
	STRPTR						string,
	LONG						len,
	LONG						width,
	LONG *						deltaPtr)
{
	ULONG chars;
	LONG delta = 0;

	chars = TE_TextFit(tec,string,len,width);
	if(chars < len)
	{
		if(chars == 0 || TE_TextLength(tec,string,chars) != width)
		{
			chars++;

			delta = TE_TextLength(tec,string,chars) - width;
		}
	}

	(*deltaPtr) = delta;

	return(chars);
}

/******************************************************************************/

STATIC VOID
TE_ScrollComplete(
	struct TextEditContext *	tec,
	LONG						deltaX,
	LONG						deltaY)
{
	if(GfxBase->lib_Version < 39)
	{
		ScrollRaster(tec->tec_RastPort,deltaX,deltaY,
			tec->tec_Left,tec->tec_Top,
			tec->tec_Left + tec->tec_Width-1,tec->tec_Top + tec->tec_NumLines*tec->tec_CharHeight - 1);
	}
	else
	{
		struct Hook * oldHook;

		LockLayerInfo(tec->tec_RastPort->Layer->LayerInfo);
		oldHook = InstallLayerHook(tec->tec_RastPort->Layer,LAYERS_NOBACKFILL);

		ScrollRasterBF(tec->tec_RastPort,deltaX,deltaY,
			tec->tec_Left,tec->tec_Top,
			tec->tec_Left + tec->tec_Width-1,tec->tec_Top + tec->tec_NumLines*tec->tec_CharHeight - 1);

		InstallLayerHook(tec->tec_RastPort->Layer,oldHook);
		UnlockLayerInfo(tec->tec_RastPort->Layer->LayerInfo);
	}
}

/******************************************************************************/

VOID
TE_GetTextEditString(
	struct TextEditContext *	tec,
	STRPTR *					stringPtr)
{
	(*stringPtr) = tec->tec_String;
}

BOOL
TE_SetTextEditString(
	struct TextEditContext *	tec,
	STRPTR						string)
{
	BOOL hasNewBuffer = FALSE;
	STRPTR newString;
	LONG len;

	if(string == NULL)
		string = "";

	len = strlen(string)+1;

	newString = TE_AllocVec(tec,len + GRANULARITY,MEMF_ANY|MEMF_PUBLIC);
	if(newString != NULL)
	{
		hasNewBuffer = TRUE;

		strcpy(newString,string);

		if(tec->tec_String != NULL)
			TE_FreeVec(tec,tec->tec_String);

		tec->tec_String				= newString;
		tec->tec_StringUsedSize		= len;
		tec->tec_StringTotalSize	= len + GRANULARITY;

		tec->tec_LinePointer		= tec->tec_String;
		tec->tec_LineIndex			= 0;

		if(tec->tec_MeasureRastPortReady)
			TE_CountColumnsAndLines(tec);
		else
			tec->tec_MustCountColumnsAndLines = TRUE;

		TE_MakeBackup(tec);
	}

	return(hasNewBuffer);
}

/******************************************************************************/

VOID
TE_GetTextEditStringPosition(
	struct TextEditContext *	tec,
	LONG *						positionPtr)
{
	TE_CursorPositionToOffset(tec,positionPtr);
}

VOID
TE_SetTextEditStringPosition(
	struct TextEditContext *	tec,
	LONG						position)
{
	if(position < 0 || position > tec->tec_StringUsedSize)
		position = tec->tec_StringUsedSize;

	TE_HideCursor(tec);

	TE_OffsetToCursorPosition(tec,position);
	TE_ChooseVisibleOffsetForCursor(tec);

	TE_MarkForRedraw(tec,STARTLINE_First,STOPLINE_Last);

	TE_ShowCursor(tec);
}

/******************************************************************************/

VOID
TE_DeleteTextEditContext(struct TextEditContext * tec)
{
	if(tec != NULL)
		AsmDeletePool(tec->tec_MemoryPoolHeader,SysBase);
}

struct TextEditContext *
TE_CreateTextEditContext(
	struct DrawInfo *	dri,
	struct TextFont *	font)
{
	struct TextEditContext * tec = NULL;
	APTR memoryPoolHeader;

	memoryPoolHeader = AsmCreatePool(MEMF_ANY|MEMF_PUBLIC,2048,2048,SysBase);
	if(memoryPoolHeader != NULL)
	{
		tec = TE_AllocVec((struct TextEditContext *)memoryPoolHeader,sizeof(*tec),MEMF_ANY|MEMF_CLEAR|MEMF_LOCAL);
		if(tec != NULL)
		{
			tec->tec_DrawInfo = dri;

			tec->tec_ShadowPen			= dri->dri_Pens[SHADOWPEN];
			tec->tec_ActiveTextPen		= dri->dri_Pens[TEXTPEN];
			tec->tec_ActiveBackPen		= dri->dri_Pens[BACKGROUNDPEN];
			tec->tec_InactiveTextPen	= dri->dri_Pens[TEXTPEN];
			tec->tec_InactiveBackPen	= dri->dri_Pens[BACKGROUNDPEN];

			tec->tec_TextPen = tec->tec_InactiveTextPen;
			tec->tec_BackPen = tec->tec_InactiveBackPen;

			if(font == NULL)
				font = dri->dri_Font;

			tec->tec_Font = font;

			tec->tec_CharWidth	= tec->tec_Font->tf_XSize;
			tec->tec_CharHeight	= tec->tec_Font->tf_YSize;

			tec->tec_CursorVisible = VISIBLE+1;

			tec->tec_MemoryPoolHeader = memoryPoolHeader;
		}
		else
		{
			AsmDeletePool(memoryPoolHeader,SysBase);
		}
	}

	return(tec);
}

/******************************************************************************/

VOID
TE_SetTextEditBox(
	struct TextEditContext *	tec,
	struct IBox *				box)
{
	if(tec->tec_DrawInfo != NULL)
	{
		tec->tec_Left		= box->Left;
		tec->tec_Top		= box->Top;
		tec->tec_Width		= box->Width;
		tec->tec_Height		= box->Height;
		tec->tec_NumLines	= box->Height / tec->tec_CharHeight;

		tec->tec_RedrawStartLine	= tec->tec_NumLines-1;
		tec->tec_RedrawStopLine		= 0;
	}
}

VOID
TE_SetTextEditRastPort(
	struct TextEditContext *	tec,
	struct RastPort *			rastPort)
{
	if(rastPort != NULL)
	{
		tec->tec_RastPort = rastPort;
		SetFont(tec->tec_RastPort,tec->tec_Font);

		if(NOT tec->tec_MeasureRastPortReady)
		{
			tec->tec_MeasureRastPort		= (*rastPort);
			tec->tec_MeasureRastPortReady	= TRUE;
		}

		if(tec->tec_MustCountColumnsAndLines)
			TE_CountColumnsAndLines(tec);

		tec->tec_IsDrawable = TRUE;
	}
	else
	{
		tec->tec_IsDrawable = FALSE;
	}
}

/******************************************************************************/

STATIC LONG
TE_StrLen(STRPTR string)
{
	LONG len = 0;

	if(string != NULL)
	{
		while((*string) != '\n' && (*string) != '\0')
		{
			string++;

			len++;
		}
	}

	return(len);
}

STATIC STRPTR
TE_FindLine(
	struct TextEditContext *	tec,
	LONG						whichLine)
{
	STRPTR result = NULL;

	if(tec->tec_LineIndex == whichLine)
	{
		result = tec->tec_LinePointer;
	}
	else
	{
		if(whichLine < tec->tec_LineIndex)
		{
			if(whichLine >= 0)
			{
				STRPTR lastLineFeed;
				STRPTR lastChar;
				LONG line;
				STRPTR s;

				line	= tec->tec_LineIndex;
				s		= tec->tec_LinePointer;

				lastLineFeed	= tec->tec_LinePointer-1;
				lastChar		= tec->tec_String-1;

				while((line > whichLine) && (s != lastChar))
				{
					s--;

					if(((*s) == '\n' && s != lastLineFeed) || (s == lastChar))
						line--; /* found another line */
				}

				if(line == whichLine)
				{
					tec->tec_LineIndex		= line;
					tec->tec_LinePointer	= s+1;

					result = tec->tec_LinePointer;
				}
			}
		}
		else /* if(whichLine > tec->tec_LineIndex) */
		{
			LONG line;
			STRPTR s;

			line	= tec->tec_LineIndex;
			s		= tec->tec_LinePointer;

			while((line < whichLine) && ((*s) != '\0'))
			{
				if((*s++) == '\n')
					line++;		/* found another line */
			}

			if(line == whichLine)
			{
				tec->tec_LineIndex		= line;
				tec->tec_LinePointer	= s;

				result = tec->tec_LinePointer;
			}
		}
	}

	return(result);
}

/******************************************************************************/

STATIC VOID
TE_CursorPositionToOffset(
	struct TextEditContext *	tec,
	LONG *						offsetPtr)
{
	STRPTR string;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
		(*offsetPtr) = ((LONG)string - (LONG)tec->tec_String) + tec->tec_CursorX;
}

STATIC VOID
TE_OffsetToCursorPosition(
	struct TextEditContext *	tec,
	LONG						offset)
{
	if(offset >= 0)
	{
		STRPTR stringOffset;
		STRPTR string;
		LONG whichLine;

		stringOffset = tec->tec_String + offset;

		for(whichLine = 0 ; (string = TE_FindLine(tec,whichLine)) != NULL ; whichLine++)
		{
			if(string <= stringOffset && stringOffset <= string + TE_StrLen(string))
			{
				TE_HideCursor(tec);

				tec->tec_CursorX = (LONG)stringOffset - (LONG)string;
				tec->tec_CursorY = whichLine;

				TE_ShowCursor(tec);

				break;
			}
		}
	}
}

/******************************************************************************/

STATIC BOOL
TE_DetermineLinesAffectedByChanges(
	struct TextEditContext *	tec,
	LONG						firstByteChanged,
	LONG						numBytesChanged,
	LONG *						firstLinePtr,
	LONG *						lastLinePtr)
{
	STRPTR firstCharDisplayed;
	STRPTR lastCharDisplayed;
	LONG lastLineDisplayed;
	BOOL changesAreVisible;

	changesAreVisible = FALSE;

	lastLineDisplayed = tec->tec_FirstLine + tec->tec_NumLines-1;
	if(lastLineDisplayed >= tec->tec_MaxLines)
	{
		lastLineDisplayed = tec->tec_MaxLines-1;
		if(lastLineDisplayed < 0)
			lastLineDisplayed = 0;
	}

	firstCharDisplayed	= TE_FindLine(tec,tec->tec_FirstLine);
	lastCharDisplayed	= TE_FindLine(tec,lastLineDisplayed);

	if(firstCharDisplayed != NULL && lastCharDisplayed != NULL)
	{
		STRPTR firstCharChanged;
		STRPTR lastCharChanged;

		lastCharDisplayed += TE_StrLen(lastCharDisplayed)-1;

		firstCharChanged	= tec->tec_String + firstByteChanged;
		lastCharChanged		= tec->tec_String + firstByteChanged + numBytesChanged - 1;

		if(firstCharDisplayed <= lastCharChanged && firstCharChanged <= lastCharDisplayed)
		{
			STRPTR string;
			LONG firstLine;
			LONG lastLine;
			LONG len;
			LONG i;

			if(firstCharChanged < firstCharDisplayed)
				firstCharChanged = firstCharDisplayed;

			if(lastCharChanged > lastCharDisplayed)
				lastCharChanged = lastCharDisplayed;

			firstLine = lastLine = -1;

			for(i = 0 ; i < tec->tec_NumLines ; i++)
			{
				string = TE_FindLine(tec,tec->tec_FirstLine + i);
				if(string != NULL)
				{
					len = TE_StrLen(string);

					if(string <= firstCharChanged && firstCharChanged <= string + len)
					{
						if(firstLine == -1)
							firstLine = i;
					}

					if(string <= lastCharChanged && lastCharChanged <= string + len)
					{
						lastLine = i;

						changesAreVisible = TRUE;
					}
					else if (lastLine != -1)
					{
						break;
					}
				}
			}

			if(changesAreVisible)
			{
				(*firstLinePtr)	= firstLine;
				(*lastLinePtr)	= lastLine;
			}
		}
	}

	return(changesAreVisible);
}

/******************************************************************************/

BOOL
TE_AddString(
	struct TextEditContext *	tec,
	UBYTE *						string,
	LONG						len)
{
	LONG bytesBefore,bytesAfter;
	STRPTR destBuffer;
	LONG offset;
	LONG firstLine,lastLine;
	BOOL successful = FALSE;

	TE_CursorPositionToOffset(tec,&offset);

	bytesBefore	= offset;
	bytesAfter	= tec->tec_StringUsedSize - bytesBefore;

	TE_HideCursor(tec);

	if(tec->tec_StringUsedSize + len < tec->tec_StringTotalSize)
	{
		destBuffer = tec->tec_String;

		if(bytesAfter > 0)
			memmove(destBuffer + offset + len,destBuffer + offset,bytesAfter);
	}
	else
	{
		LONG destBufferSize;

		destBufferSize = tec->tec_StringUsedSize + len + GRANULARITY;

		destBuffer = TE_AllocVec(tec,destBufferSize,MEMF_ANY|MEMF_PUBLIC);
		if(destBuffer != NULL)
		{
			if(bytesBefore > 0)
				memcpy(destBuffer,tec->tec_String,bytesBefore);

			if(bytesAfter > 0)
				memcpy(destBuffer + offset + len,tec->tec_String + bytesBefore,bytesAfter);

			if(tec->tec_String != NULL)
				TE_FreeVec(tec,tec->tec_String);

			tec->tec_String				= destBuffer;
			tec->tec_StringTotalSize	= destBufferSize;
		}
	}

	if(destBuffer != NULL)
	{
		LONG numBytesChanged,i;

		memcpy(destBuffer + offset,string,len);
		tec->tec_StringUsedSize += len;

		tec->tec_BufferChanged = TRUE;

		tec->tec_LinePointer	= tec->tec_String;
		tec->tec_LineIndex		= 0;

		TE_CountColumnsAndLines(tec);
		TE_OffsetToCursorPosition(tec,offset + len);
		TE_ChooseVisibleOffsetForCursor(tec);

		numBytesChanged = len;

		for(i = 0 ; i < len ; i++)
		{
			if(string[i] == '\n')
			{
				numBytesChanged = tec->tec_StringUsedSize - offset;
				break;
			}
		}

		firstLine	= STARTLINE_First;
		lastLine	= STOPLINE_Last;

		TE_DetermineLinesAffectedByChanges(tec,
			offset,numBytesChanged,
			&firstLine,&lastLine);

		TE_MarkForRedraw(tec,firstLine,lastLine);

		successful = TRUE;
	}

	TE_ShowCursor(tec);

	return(successful);
}

VOID
TE_RemoveChars(
	struct TextEditContext *	tec,
	LONG						numChars)
{
	if(numChars > 0)
	{
		LONG offset;

		TE_CursorPositionToOffset(tec,&offset);

		if(numChars > offset)
			numChars = offset;

		if(numChars > 0)
		{
			LONG firstLine,lastLine,numBytesChanged,i;
			BOOL anyLinesRemoved;

			anyLinesRemoved = FALSE;
			for(i = 0 ; i < numChars ; i++)
			{
				if(tec->tec_String[offset - numChars + i] == '\n')
				{
					anyLinesRemoved = TRUE;
					break;
				}
			}

			TE_HideCursor(tec);

			firstLine	= STARTLINE_First;
			lastLine	= STOPLINE_Last;

			if(anyLinesRemoved)
			{
				/* This doesn't work since the display may have moved
				 * horizontally after deleting the first characters of
				 * a line.
				 */
				/*numBytesChanged = tec->tec_StringUsedSize - offset;

				TE_DetermineLinesAffectedByChanges(tec,
					offset,numBytesChanged,
					&firstLine,&lastLine);*/
			}
			else
			{
				numBytesChanged = TE_StrLen(tec->tec_String + offset - numChars);

				/* Account for the terminating '\0'. */
				if(numBytesChanged == 0)
					numBytesChanged = 1;

				TE_DetermineLinesAffectedByChanges(tec,
					offset,numBytesChanged,
					&firstLine,&lastLine);
			}

			memmove(tec->tec_String + offset - numChars,tec->tec_String + offset,tec->tec_StringUsedSize - offset);

			tec->tec_BufferChanged = TRUE;

			tec->tec_LinePointer	= tec->tec_String;
			tec->tec_LineIndex		= 0;

			tec->tec_StringUsedSize -= numChars;

			TE_CountColumnsAndLines(tec);
			TE_OffsetToCursorPosition(tec,offset - numChars);
			TE_ChooseVisibleOffsetForCursor(tec);

			TE_MarkForRedraw(tec,firstLine,lastLine);

			TE_ShowCursor(tec);
		}
	}
}

VOID
TE_DeleteChars(
	struct TextEditContext *	tec,
	LONG						numChars)
{
	if(numChars > 0)
	{
		LONG offset;

		TE_CursorPositionToOffset(tec,&offset);

		if(offset + numChars > tec->tec_StringUsedSize)
			numChars = tec->tec_StringUsedSize - offset;

		if(numChars > 0)
		{
			LONG firstLine,lastLine,numBytesChanged,i;
			BOOL anyLinesRemoved;

			anyLinesRemoved = FALSE;
			for(i = 0 ; i < numChars ; i++)
			{
				if(tec->tec_String[offset + i] == '\n')
				{
					anyLinesRemoved = TRUE;
					break;
				}
			}

			TE_HideCursor(tec);

			if(anyLinesRemoved)
			{
				numBytesChanged = tec->tec_StringUsedSize - offset;
			}
			else
			{
				numBytesChanged = TE_StrLen(tec->tec_String + offset);

				/* Account for the terminating '\0'. */
				if(numBytesChanged == 0)
					numBytesChanged = 1;
			}

			firstLine	= STARTLINE_First;
			lastLine	= STOPLINE_Last;

			TE_DetermineLinesAffectedByChanges(tec,
				offset,numBytesChanged,
				&firstLine,&lastLine);

			memmove(tec->tec_String + offset,tec->tec_String + offset + numChars,tec->tec_StringUsedSize - offset - numChars);

			tec->tec_BufferChanged = TRUE;

			tec->tec_LinePointer	= tec->tec_String;
			tec->tec_LineIndex		= 0;

			tec->tec_StringUsedSize -= numChars;

			TE_CountColumnsAndLines(tec);

			TE_MarkForRedraw(tec,firstLine,lastLine);

			TE_ShowCursor(tec);
		}
	}
}

VOID
TE_DeleteToStartOfLine(struct TextEditContext * tec)
{
	if(tec->tec_CursorX > 0)
		TE_RemoveChars(tec,tec->tec_CursorX);
}

VOID
TE_DeleteToEndOfLine(struct TextEditContext * tec)
{
	STRPTR string;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
	{
		LONG charsFollowingCursor;

		charsFollowingCursor = TE_StrLen(string) - tec->tec_CursorX;
		if(charsFollowingCursor > 0)
			TE_DeleteChars(tec,charsFollowingCursor);
	}
}

VOID
TE_DeleteAll(struct TextEditContext * tec)
{
	if(tec->tec_StringUsedSize > 1) /* one byte reserved for terminator '\0' */
	{
		TE_HideCursor(tec);

		TE_CursorFirstLine(tec);
		TE_CursorStartOfLine(tec);

		TE_DeleteChars(tec,tec->tec_StringUsedSize-1);
		TE_ChooseVisibleOffsetForCursor(tec);

		TE_ShowCursor(tec);
	}
}

VOID
TE_RemoveWord(struct TextEditContext * tec)
{
	STRPTR string;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
	{
		LONG firstChar,lastChar;
		LONG i;

		firstChar = -1;
		lastChar = -1;

		for(i = tec->tec_CursorX-1 ; i >= 0 ; i--)
		{
			if(i == 0 && lastChar != -1)
			{
				firstChar = 0;
				break;
			}
			else
			{
				if(string[i] != ' ')
				{
					if(lastChar == -1)
						lastChar = i;
				}
				else
				{
					if(lastChar != -1)
					{
						firstChar = i+1;
						break;
					}
				}
			}
		}

		if(firstChar != -1 && lastChar != -1)
		{
			TE_HideCursor(tec);

			if(firstChar < tec->tec_CursorX)
				TE_CursorLeft(tec,tec->tec_CursorX - firstChar);

			TE_DeleteChars(tec,lastChar - firstChar + 1);

			TE_ShowCursor(tec);
		}
	}
}

/******************************************************************************/

VOID
TE_RestoreBackup(struct TextEditContext * tec)
{
	if(tec->tec_BackupString != NULL)
	{
		LONG x,y,firstLine;

		firstLine	= tec->tec_FirstLine;
		x			= tec->tec_CursorX;
		y			= tec->tec_CursorY;

		TE_DeleteAll(tec);
		TE_AddString(tec,tec->tec_BackupString,strlen(tec->tec_BackupString));

		if(y > tec->tec_MaxLines)
			y = tec->tec_MaxLines;

		if(firstLine > tec->tec_MaxLines - tec->tec_NumLines)
		{
			firstLine = tec->tec_MaxLines - tec->tec_NumLines;
			if(firstLine < 0)
				firstLine = 0;
		}

		TE_HideCursor(tec);

		tec->tec_FirstLine	= firstLine;
		tec->tec_CursorX	= x;
		tec->tec_CursorY	= y;

		TE_ValidateCursorX(tec);
		TE_ChooseVisibleOffsetForCursor(tec);
		TE_MarkForRedraw(tec,STARTLINE_First,STOPLINE_Last);

		TE_ShowCursor(tec);
	}
	else
	{
		if(tec->tec_IsDrawable)
			DisplayBeep(NULL);
	}
}

STATIC VOID
TE_MakeBackup(struct TextEditContext * tec)
{
	LONG len;

	len = strlen(tec->tec_String)+1;

	if(tec->tec_BackupString != NULL && tec->tec_BackupStringSize >= len)
	{
		strcpy(tec->tec_BackupString,tec->tec_String);
	}
	else
	{
		STRPTR string;

		if(tec->tec_BackupString != NULL)
		{
			TE_FreeVec(tec,tec->tec_BackupString);
			tec->tec_BackupString = NULL;
		}

		string = TE_AllocVec(tec,len,MEMF_ANY|MEMF_PUBLIC);
		if(string != NULL)
		{
			tec->tec_BackupString		= string;
			tec->tec_BackupStringSize	= len;

			strcpy(tec->tec_BackupString,tec->tec_String);
		}
	}
}

/******************************************************************************/

STATIC VOID
TE_CountColumnsAndLines(struct TextEditContext * tec)
{
	STRPTR string;
	LONG whichLine = 0;
	LONG numLines = 0;
	LONG width,maxWidth = 0;
	LONG len,maxLen = 0;

	while((string = TE_FindLine(tec,whichLine++)) != NULL)
	{
		numLines++;

		len = TE_StrLen(string);
		if(maxLen < len)
			maxLen = len;

		width = TE_TextLength(tec,string,len);
		if(maxWidth < width)
			maxWidth = width;
	}

	tec->tec_MaxPixels					= maxWidth;
	tec->tec_MaxColumns					= maxLen;
	tec->tec_MaxLines					= numLines;
	tec->tec_MustCountColumnsAndLines	= TRUE;
}

/******************************************************************************/

enum
{
	DRAWCURSOR_Toggle,
	DRAWCURSOR_Erase
};

STATIC VOID
TE_DrawCursor(
	struct TextEditContext *	tec,
	LONG						mode)
{
	if(tec->tec_IsDrawable)
	{
		if(tec->tec_CursorY >= tec->tec_FirstLine &&
		   tec->tec_CursorY  < tec->tec_FirstLine + tec->tec_NumLines)
		{
			STRPTR string;

			string = TE_FindLine(tec,tec->tec_CursorY);
			if(string != NULL)
			{
				LONG cursorX;
				LONG totalChars;
				LONG len;
				LONG delta;

				cursorX = tec->tec_CursorX;
				len = TE_StrLen(string);
				if(tec->tec_FirstPixel > 0)
				{
					totalChars = TE_RoundedTextFit(tec,(STRPTR)string,len,tec->tec_FirstPixel,&delta);
					if(totalChars > 0)
					{
						string += totalChars;
						len -= totalChars;
						cursorX -= totalChars;
					}
				}
				else
				{
					delta = 0;
				}

				if(cursorX >= 0)
				{
					LONG cursorWidth;
					LONG cursorLeft;

					cursorLeft = TE_TextLength(tec,string,cursorX) + delta;

					if(cursorX < len)
						cursorWidth = TE_TextLength(tec,&string[cursorX],1);
					else
						cursorWidth = tec->tec_CharWidth;

					if(cursorLeft + cursorWidth > tec->tec_Width)
						cursorWidth = tec->tec_Width - cursorLeft;

					if(cursorWidth > 0)
					{
						LONG cursorTop;

						cursorTop = (tec->tec_CursorY - tec->tec_FirstLine) * tec->tec_CharHeight;

						if(mode == DRAWCURSOR_Toggle)
							TE_SetABPenDrMd(tec,0xFF,OLD_BgPen,COMPLEMENT | JAM1);
						else
							TE_SetABPenDrMd(tec,0x00,OLD_BgPen,JAM2);

						TE_SetWriteMask(tec,0xFF);

						TE_FillArea(tec,tec->tec_Left + cursorLeft,tec->tec_Top + cursorTop,cursorWidth,tec->tec_CharHeight);

						TE_SetABPenDrMd(tec,tec->tec_TextPen,OLD_BgPen,JAM2);
						TE_SetWriteMask(tec,tec->tec_TextPen | tec->tec_BackPen);
					}
				}
			}
		}
	}
}

STATIC VOID
TE_ShowCursor(struct TextEditContext * tec)
{
	if(tec->tec_CursorVisible > 0)
	{
		tec->tec_CursorVisible--;

		if(tec->tec_CursorVisible == VISIBLE)
			TE_DrawCursor(tec,DRAWCURSOR_Toggle);
	}
}

STATIC VOID
TE_HideCursor(struct TextEditContext * tec)
{
	if(tec->tec_CursorVisible == VISIBLE)
		TE_DrawCursor(tec,DRAWCURSOR_Toggle);

	tec->tec_CursorVisible++;
}

STATIC VOID
TE_EraseCursor(struct TextEditContext * tec)
{
	TE_DrawCursor(tec,DRAWCURSOR_Erase);

	tec->tec_CursorVisible++;
}

STATIC BOOL
TE_ChooseVisibleOffsetForCursor(struct TextEditContext * tec)
{
	LONG firstPixel = tec->tec_FirstPixel;
	LONG firstLine = tec->tec_FirstLine;
	STRPTR string;
	BOOL modified;

	if(tec->tec_CursorY < firstLine)
		firstLine = tec->tec_CursorY;
	else if (tec->tec_CursorY+1 >= firstLine + tec->tec_NumLines)
		firstLine = tec->tec_CursorY+1 - tec->tec_NumLines;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
	{
		LONG cursorLeft;

		cursorLeft = TE_TextLength(tec,string,tec->tec_CursorX);
		if(cursorLeft < firstPixel)
			firstPixel = cursorLeft;
		else if (cursorLeft + tec->tec_CharWidth >= firstPixel + tec->tec_Width)
			firstPixel = cursorLeft + tec->tec_CharWidth - tec->tec_Width;
	}

	if(firstPixel != tec->tec_FirstPixel || firstLine != tec->tec_FirstLine)
	{
		tec->tec_FirstPixel	= firstPixel;
		tec->tec_FirstLine	= firstLine;

		modified = TRUE;
	}
	else
	{
		modified = FALSE;
	}

	return(modified);
}

STATIC VOID
TE_MakeCursorVisible(struct TextEditContext * tec)
{
	BOOL mustRedraw;

	TE_HideCursor(tec);

	mustRedraw = TE_ChooseVisibleOffsetForCursor(tec);
	if(mustRedraw)
		TE_MarkForRedraw(tec,STARTLINE_First,STOPLINE_Last);

	TE_ShowCursor(tec);
}

/******************************************************************************/

STATIC VOID
TE_ValidateCursorX(struct TextEditContext * tec)
{
	STRPTR string;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
	{
		LONG cursorX = 0;

		while(cursorX < tec->tec_CursorX && (*string) != '\0' && (*string) != '\n')
		{
			cursorX++;
			string++;
		}

		TE_HideCursor(tec);

		tec->tec_CursorX = cursorX;

		TE_ShowCursor(tec);
	}
}

/******************************************************************************/

VOID
TE_CursorFirstLine(struct TextEditContext * tec)
{
	if(tec->tec_CursorY != 0)
	{
		TE_HideCursor(tec);

		tec->tec_CursorY = 0;
		TE_ValidateCursorX(tec);
		TE_MakeCursorVisible(tec);

		TE_ShowCursor(tec);
	}
}

VOID
TE_CursorLastLine(struct TextEditContext * tec)
{
	LONG cursorY;

	cursorY = tec->tec_MaxLines-1;
	if(cursorY < 0)
		cursorY = 0;

	if(tec->tec_CursorY != cursorY)
	{
		TE_HideCursor(tec);

		tec->tec_CursorY = cursorY;
		TE_ValidateCursorX(tec);
		TE_MakeCursorVisible(tec);

		TE_ShowCursor(tec);
	}
}

/******************************************************************************/

VOID
TE_CursorStartOfLine(struct TextEditContext * tec)
{
	if(tec->tec_CursorX != 0)
	{
		TE_HideCursor(tec);

		tec->tec_CursorX = 0;
		TE_MakeCursorVisible(tec);

		TE_ShowCursor(tec);
	}
}

VOID
TE_CursorEndOfLine(struct TextEditContext * tec)
{
	STRPTR string;

	string = TE_FindLine(tec,tec->tec_CursorY);
	if(string != NULL)
	{
		LONG cursorX = 0;

		while((*string) != '\0' && (*string) != '\n')
		{
			cursorX++;
			string++;
		}

		if(tec->tec_CursorX != cursorX)
		{
			TE_HideCursor(tec);

			tec->tec_CursorX = cursorX;
			TE_MakeCursorVisible(tec);

			TE_ShowCursor(tec);
		}
	}
}

/******************************************************************************/

VOID
TE_CursorPageUp(struct TextEditContext * tec)
{
	LONG numLines;

	if((tec->tec_CursorY - tec->tec_FirstLine) == 0)
		numLines = tec->tec_NumLines-1;
	else
		numLines = (tec->tec_CursorY - tec->tec_FirstLine);

	TE_CursorUp(tec,max(1,numLines));
}

VOID
TE_CursorPageDown(struct TextEditContext * tec)
{
	LONG numLines;

	if(tec->tec_CursorY == tec->tec_FirstLine + tec->tec_NumLines-1)
		numLines = tec->tec_NumLines-1;
	else
		numLines = tec->tec_NumLines-1 - (tec->tec_CursorY - tec->tec_FirstLine);

	TE_CursorDown(tec,max(1,numLines));
}

/******************************************************************************/

VOID
TE_CursorUp(
	struct TextEditContext *	tec,
	LONG						numLines)
{
	if(numLines > 0)
	{
		if(numLines < tec->tec_CursorY)
		{
			TE_HideCursor(tec);

			tec->tec_CursorY = tec->tec_CursorY - numLines;
			TE_ValidateCursorX(tec);
			TE_MakeCursorVisible(tec);

			TE_ShowCursor(tec);
		}
		else
		{
			TE_CursorFirstLine(tec);
		}
	}
}

VOID
TE_CursorDown(
	struct TextEditContext *	tec,
	LONG						numLines)
{
	if(numLines > 0)
	{
		if(tec->tec_CursorY + numLines < tec->tec_MaxLines)
		{
			TE_HideCursor(tec);

			tec->tec_CursorY = tec->tec_CursorY + numLines;
			TE_ValidateCursorX(tec);
			TE_MakeCursorVisible(tec);

			TE_ShowCursor(tec);
		}
		else
		{
			TE_CursorLastLine(tec);
		}
	}
}

VOID
TE_CursorLeft(
	struct TextEditContext *	tec,
	LONG						numColumns)
{
	if(numColumns > 0)
	{
		STRPTR string;

		if(numColumns == 1 && tec->tec_CursorX == 0)
		{
			if(tec->tec_CursorY > 0)
			{
				string = TE_FindLine(tec,tec->tec_CursorY - 1);
				if(string != NULL)
				{
					TE_HideCursor(tec);

					tec->tec_CursorX = TE_StrLen(string);
					tec->tec_CursorY = tec->tec_CursorY - 1;
					TE_MakeCursorVisible(tec);

					TE_ShowCursor(tec);
				}
			}
		}
		else
		{
			string = TE_FindLine(tec,tec->tec_CursorY);
			if(string != NULL)
			{
				LONG cursorX = 0;

				while(cursorX < tec->tec_CursorX && (*string) != '\0' && (*string) != '\n')
				{
					cursorX++;
					string++;
				}

				while(numColumns > 0 && cursorX > 0)
				{
					numColumns--;
					cursorX--;
				}

				if(tec->tec_CursorX != cursorX)
				{
					TE_HideCursor(tec);

					tec->tec_CursorX = cursorX;
					TE_MakeCursorVisible(tec);

					TE_ShowCursor(tec);
				}
			}
		}
	}
}

VOID
TE_CursorRight(
	struct TextEditContext *	tec,
	LONG						numColumns)
{
	if(numColumns > 0)
	{
		STRPTR string;

		string = TE_FindLine(tec,tec->tec_CursorY);
		if(string != NULL)
		{
			if(numColumns == 1 && tec->tec_CursorX == TE_StrLen(string))
			{
				if(tec->tec_CursorY + 1 < tec->tec_MaxLines)
				{
					TE_HideCursor(tec);

					tec->tec_CursorX = 0;
					tec->tec_CursorY = tec->tec_CursorY + 1;
					TE_MakeCursorVisible(tec);

					TE_ShowCursor(tec);
				}
			}
			else
			{
				LONG cursorX = 0;

				while(cursorX < tec->tec_CursorX && (*string) != '\0' && (*string) != '\n')
				{
					cursorX++;
					string++;
				}

				while(numColumns > 0 && (*string) != '\0' && (*string) != '\n')
				{
					numColumns--;
					cursorX++;
					string++;
				}

				if(tec->tec_CursorX != cursorX)
				{
					TE_HideCursor(tec);

					tec->tec_CursorX = cursorX;
					TE_MakeCursorVisible(tec);

					TE_ShowCursor(tec);
				}
			}
		}
	}
}

/******************************************************************************/

VOID
TE_CursorToMouse(
	struct TextEditContext *	tec,
	LONG						left,
	LONG						top)
{
	STRPTR string;
	LONG y;

	if(left < 0)
		left = 0;
	else if (left >= tec->tec_Width)
		left = tec->tec_Width-1;

	if(top < 0)
		top = 0;
	else if ((top / tec->tec_CharHeight) >= tec->tec_NumLines)
		top = (tec->tec_NumLines * tec->tec_CharHeight)-1;

	y = tec->tec_FirstLine + (top / tec->tec_CharHeight);
	if(y >= tec->tec_MaxLines)
	{
		y = tec->tec_MaxLines-1;
		if(y < 0)
			y = 0;
	}

	string = TE_FindLine(tec,y);
	if(string != NULL)
	{
		LONG x;

		x = TE_TextFit(tec,string,TE_StrLen(string),tec->tec_FirstPixel + left);

		if(tec->tec_CursorX != x || tec->tec_CursorY != y)
		{
			TE_HideCursor(tec);

			tec->tec_CursorX = x;
			tec->tec_CursorY = y;

			TE_ShowCursor(tec);
		}
	}
}

VOID
TE_MoveCursorWithMouse(
	struct TextEditContext *	tec,
	LONG						left,
	LONG						top)
{
	LONG firstPixel = tec->tec_FirstPixel;
	LONG firstLine = tec->tec_FirstLine;
	BOOL cursorHidden;

	if(left < 0 && firstPixel > 0)
	{
		if(firstPixel < tec->tec_CharWidth)
			firstPixel = 0;
		else
			firstPixel -= tec->tec_CharWidth;
	}
	else if (left >= tec->tec_Width && firstPixel + tec->tec_Width < (tec->tec_MaxPixels + tec->tec_CharWidth))
	{
		if(firstPixel + tec->tec_CharWidth + tec->tec_Width > (tec->tec_MaxPixels + tec->tec_CharWidth))
		{
			firstPixel = (tec->tec_MaxPixels + tec->tec_CharWidth) - (tec->tec_CharWidth + tec->tec_Width);
			if(firstPixel < 0)
				firstPixel = 0;
		}
		else
		{
			firstPixel += tec->tec_CharWidth;
		}
	}

	if(top < 0 && firstLine > 0)
	{
		firstLine--;
	}
	else if ((top / tec->tec_CharHeight) >= tec->tec_NumLines && firstLine + 1 + tec->tec_NumLines < (tec->tec_MaxLines + 1))
	{
		if(firstLine + 1 + tec->tec_NumLines > (tec->tec_MaxLines + 1))
		{
			firstLine = (tec->tec_MaxLines + 1) - (1 + tec->tec_NumLines);
			if(firstLine < 0)
				firstLine = 0;
		}
		else
		{
			firstLine++;
		}
	}

	if(tec->tec_FirstPixel != firstPixel || tec->tec_FirstLine != firstLine)
	{
		TE_HideCursor(tec);

		tec->tec_FirstPixel	= firstPixel;
		tec->tec_FirstLine	= firstLine;

		TE_DrawComplete(tec,STARTLINE_First,STOPLINE_Last);

		cursorHidden = TRUE;
	}
	else
	{
		cursorHidden = FALSE;
	}

	TE_CursorToMouse(tec,left,top);

	if(cursorHidden)
		TE_ShowCursor(tec);
}

/******************************************************************************/

BOOL
TE_MouseInArea(
	struct TextEditContext *	tec,
	LONG						left,
	LONG						top)
{
	BOOL inArea;

	inArea = (BOOL)(left >= 0 && left < tec->tec_Width &&
	                top  >= 0 && top  < tec->tec_Height);

	return(inArea);
}

VOID
TE_AdjustLeftTop(
	struct TextEditContext *	tec,
	LONG *						leftPtr,
	LONG *						topPtr)
{
	(*leftPtr)	-= tec->tec_Left;
	(*topPtr)	-= tec->tec_Top;
}

/******************************************************************************/

BOOL
TE_IsRedrawNecessary(struct TextEditContext * tec)
{
	BOOL result;

	result = tec->tec_MustRedraw;

	return(result);
}

VOID
TE_RedrawIfNecessary(struct TextEditContext * tec)
{
	if(tec->tec_MustRedraw)
		TE_DrawComplete(tec,tec->tec_RedrawStartLine,tec->tec_RedrawStopLine);
}

STATIC VOID
TE_MarkForRedraw(
	struct TextEditContext *	tec,
	LONG						startLine,
	LONG						stopLine)
{
	tec->tec_MustRedraw = TRUE;

	if(startLine == STARTLINE_First)
		startLine = 0;

	if(stopLine == STOPLINE_Last)
		stopLine = tec->tec_NumLines-1;

	if(tec->tec_RedrawStartLine > startLine)
		tec->tec_RedrawStartLine = startLine;

	if(tec->tec_RedrawStopLine < stopLine)
		tec->tec_RedrawStopLine = stopLine;
}

VOID
TE_Refresh(struct TextEditContext * tec)
{
	TE_EraseCursor(tec); /* == TE_HideCursor(tec) */

	TE_DrawComplete(tec,STARTLINE_First,STOPLINE_Last);

	TE_ShowCursor(tec);
}

/******************************************************************************/

VOID
TE_Activate(struct TextEditContext * tec)
{
	if(NOT tec->tec_IsActive)
	{
		tec->tec_IsActive = TRUE;

		tec->tec_TextPen = tec->tec_ActiveTextPen;
		tec->tec_BackPen = tec->tec_ActiveBackPen;

		TE_ShowCursor(tec);

		TE_Refresh(tec);

		TE_MakeBackup(tec);
	}
}

VOID
TE_Deactivate(struct TextEditContext * tec)
{
	if(tec->tec_IsActive)
	{
		TE_HideCursor(tec);

		tec->tec_IsActive = FALSE;

		tec->tec_TextPen = tec->tec_InactiveTextPen;
		tec->tec_BackPen = tec->tec_InactiveBackPen;

		TE_Refresh(tec);
	}
}

VOID
TE_InitialRefresh(struct TextEditContext * tec)
{
	if(tec->tec_IsActive)
	{
		tec->tec_TextPen = tec->tec_ActiveTextPen;
		tec->tec_BackPen = tec->tec_ActiveBackPen;
	}
	else
	{
		tec->tec_TextPen = tec->tec_InactiveTextPen;
		tec->tec_BackPen = tec->tec_InactiveBackPen;
	}

	TE_Refresh(tec);
}

/******************************************************************************/

VOID
TE_DrawDisabled(struct TextEditContext * tec)
{
	if(tec->tec_IsDrawable)
	{
		STATIC UWORD Ghosting[2] = { 0x4444,0x1111 };

		TE_SetABPenDrMd(tec,tec->tec_ShadowPen,OLD_BgPen,JAM1);

		SetAfPt(tec->tec_RastPort,Ghosting,1);
		TE_FillArea(tec,tec->tec_Left,tec->tec_Top,tec->tec_Width,tec->tec_Height);
		SetAfPt(tec->tec_RastPort,NULL,0);

		TE_SetABPenDrMd(tec,tec->tec_TextPen,OLD_BgPen,JAM2);
	}
}

/******************************************************************************/

#endif /* DO_TEXTEDIT_KIND */
