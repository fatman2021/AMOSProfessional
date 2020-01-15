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

VOID
LTP_GetStorage(ObjectNode *Node)
{
	if(Node->Storage)
	{
		LONG	Number = 0;
		STRPTR	String = NULL;

		switch(Node->StorageType)
		{
			case STORAGE_BYTE:

				Number = *(BYTE *)Node->Storage;
				break;

			case STORAGE_UBYTE:

				Number = *(UBYTE *)Node->Storage;
				break;

			case STORAGE_WORD:

				Number = *(WORD *)Node->Storage;
				break;

			case STORAGE_UWORD:

				Number = *(UWORD *)Node->Storage;
				break;

			case STORAGE_LONG:

				Number = *(LONG *)Node->Storage;
				break;

			case STORAGE_ULONG:

				Number = *(ULONG *)Node->Storage;
				break;

			case STORAGE_STRPTR:

				String = Node->Storage;
				break;
		}

		switch(Node->Type)
		{
			case POPUP_KIND:
			case TAB_KIND:
			case GAUGE_KIND:
			case TAPEDECK_KIND:
			case LEVEL_KIND:

			case CHECKBOX_KIND:
			case LISTVIEW_KIND:
			case MX_KIND:
			case CYCLE_KIND:
			case PALETTE_KIND:
			case SLIDER_KIND:
			case SCROLLER_KIND:

				Node->Current = Number;
				break;

			case PASSWORD_KIND:
			case STRING_KIND:
			case FRACTION_KIND:

				Node->Special.String.String = String;
				break;

			case INTEGER_KIND:

				Node->Special.Integer.Number = Number;
				break;

			#ifdef DO_TEXTEDIT_KIND
			{
				case TEXTEDIT_KIND:

					Node->Special.TextEdit.String = String;
					break;
			}
			#endif	/* DO_TEXTEDIT_KIND */
		}
	}
}


/*****************************************************************************/


VOID
LTP_PutStorage(ObjectNode *Node)
{
	if(Node->Storage)
	{
		LONG	Number = 0;
		STRPTR	String = NULL;

		switch(Node->Type)
		{
			case POPUP_KIND:
			case TAB_KIND:
			case GAUGE_KIND:
			case TAPEDECK_KIND:
			case LEVEL_KIND:

			case CHECKBOX_KIND:
			case LISTVIEW_KIND:
			case MX_KIND:
			case CYCLE_KIND:
			case PALETTE_KIND:
			case SLIDER_KIND:
			case SCROLLER_KIND:

				Number = Node->Current;
				break;

			#ifdef DO_PASSWORD_KIND
			{
				case PASSWORD_KIND:

					String = Node->Special.String.RealString;
					break;
			}
			#endif

			#ifdef DO_TEXTEDIT_KIND
			{
				case TEXTEDIT_KIND:

					if(Node->Host != NULL)
					{
						GetAttr(STRINGA_Buffer,Node->Host,(ULONG *)&String);
					}
					else
					{
						String = Node->Special.TextEdit.String;
					}

					break;
			}
			#endif /* DO_TEXTEDIT_KIND */

			case STRING_KIND:
			case FRACTION_KIND:

				if(Node->Host)
					String = ((struct StringInfo *)Node->Host->SpecialInfo)->Buffer;
				else
					String = Node->Special.String.String;

				if(Node->Type == FRACTION_KIND)
				{
					LTP_CopyFraction(Node->Special.String.RealString,String);
					String = Node->Special.String.RealString;
				}

				break;

			case INTEGER_KIND:

				if(Node->Host)
					Number = ((struct StringInfo *)Node->Host->SpecialInfo)->LongInt;
				else
					Number = Node->Special.Integer.Number;

				break;
		}

		switch(Node->StorageType)
		{
			case STORAGE_BYTE:

				if(!String)
					*(BYTE *)Node->Storage = (BYTE)Number;

				break;

			case STORAGE_UBYTE:

				if(!String)
					*(UBYTE *)Node->Storage = (UBYTE)Number;

				break;

			case STORAGE_WORD:

				if(!String)
					*(WORD *)Node->Storage = (WORD)Number;

				break;

			case STORAGE_UWORD:

				if(!String)
					*(UWORD *)Node->Storage = (UWORD)Number;

				break;

			case STORAGE_LONG:

				if(!String)
					*(LONG *)Node->Storage = (LONG)Number;

				break;

			case STORAGE_ULONG:

				if(!String)
					*(ULONG *)Node->Storage = (ULONG)Number;

				break;

			case STORAGE_STRPTR:

				if(String)
					strcpy(Node->Storage,String);

				break;
		}
	}
}


/*****************************************************************************/


VOID
LTP_CopyFraction(STRPTR To,STRPTR From)
{
	UBYTE DecimalPoint,c;
	BOOL GotPoint;
	STRPTR Orig;

		/* If there is nothing to copy from, pretend it's an empty string. */

	if(From == NULL)
		From = "";

	DecimalPoint = LTP_DecimalPoint[0];

		/* Skip leading junk. */

	while(*From != '.' && (*From < '0' || *From > '9') && *From != '\0' && *From != DecimalPoint)
		From++;

		/* Skip extraenous zeroes. */

	while(From[0] == '0')
		From++;

	Orig = To;

		/* If the first character is just a decimal point, add a zero
		 * in front of it.
		 */

	if(*From == '.' || *From == DecimalPoint)
		*To++ = '0';

	GotPoint = FALSE;

		/* Now copy and convert the number. */

	while(c = *From++)
	{
		if(c == DecimalPoint || c == '.')
		{
			if(!GotPoint)
			{
				*To++ = '.';

				GotPoint = TRUE;
			}
		}
		else
		{
			if(c >= '0' && c <= '9')
				*To++ = c;
		}
	}

		/* If the string would remain blank,
		 * use a zero.
		 */

	if(Orig == To)
		*To++ = '0';

		/* If we didn't get a decimal point, add one. */

	if(!GotPoint)
	{
		*To++ = '.';
		*To++ = '0';
	}

		/* Strip trailing zeroes if they follow the decimal point. */

	if(GotPoint)
	{
		while(To > Orig && To[-1] == '0' && To[-2] == '0')
			To--;
	}

		/* Terminate the string. */

	*To = '\0';
}
