/*
**  $PROJECT: Read
**
**  $VER: Read.c 1.7 (20.2.97)
**
**  (C) Copyright 1996-1997 Marcel Karas
**      All Rights Reserved.
**
**  This example reads a CF file and shows the contents.
*/

#include <exec/types.h>
#include <exec/libraries.h>
#include <dos/rdargs.h>
#include <dos/dos.h>

#include <proto/exec.h>
#include <proto/dos.h>

#include <Libraries/ConfigFile.h>
#include <CLib/ConfigFile_protos.h>
#include <Pragmas/ConfigFile_pragmas.h>

struct Library *CFBase;

enum { ARG_FILE ,ARG_MAX };

VOID PrintErr ( STRPTR );
VOID ShowFile ( CFHeader * );
VOID LongToBinStr ( ULONG, STRPTR );

ULONG main ( VOID )
{
	struct RDArgs *RDA;
	LONG ArgAry[ARG_MAX] = { 0 };

	ULONG Result = RETURN_ERROR, Error;

	CFHeader	*Header;

	if ( CFBase = OpenLibrary (CF_NAME, 2L) )
	{
		RDA = AllocDosObject (DOS_RDARGS, NULL);

		if ( ReadArgs ("ConfigFile/A", ArgAry, RDA) )
		{
			/* Open and read the CF file */
			if ( Header = cf_Open ((STRPTR)ArgAry[ARG_FILE],
				CF_OMODE_OLDFILE | CF_OFLG_READ_TOO, &Error) )
			{
				/* Open Modes:
				
					CF_OMODE_OLDFILE   -- An existing file is opened. Did the
												 file not exists the function failed.                      **

					CF_OMODE_NEWFILE   -- A new file will be create.                       **

					CF_OMODE_READWRITE -- Opens a file, but creates it if it
												 didn't exist.
					Extra open flags:

					CF_OFLG_READ_TOO   -- Reads the file directly after the is is
												 open. You didn't need use cf_Read().
				*/

				Printf (	"Header Information:\n\n"
							"Header->OpenMode   = ");

				if ( Header->OpenMode == CF_OMODE_OLDFILE )
					Printf ("CF_OMODE_OLDFILE\n");
				else if ( Header->OpenMode == CF_OMODE_NEWFILE )
					Printf ("CF_OMODE_NEWFILE\n");
				else if ( Header->OpenMode == CF_OMODE_READWRITE )
					Printf ("CF_OMODE_READWRITE\n");
				else
					Printf ("Unkown\n");

				Printf (	"Header->Length     = %ld\n"
							"Header->PuddleSize = %ld\n"
							"Header->WBufLength = %ld\n"
							"Header->Flags      =",

							Header->Length,
							Header->PuddleSize,
							Header->WBufLength);

				if ( Header->Flags & CF_HFLG_SHORT_FILE )
					Printf (" CF_HFLG_SHORT_FILE");
				if ( Header->Flags & CF_HFLG_ASCII_FILE )
					Printf (" CF_HFLG_ASCII_FILE");
				if ( Header->Flags & CF_HFLG_CHANGED )
					Printf (" CF_HFLG_CHANGED");
				if ( Header->Flags & CF_HFLG_WRITE_BY_CLOSE )
					Printf (" CF_HFLG_WRITE_BY_CLOSE");
					
				Printf ("\n\nShow file:\n");
				ShowFile(Header);

				Result = RETURN_OK;

				/* Close CF file */
				cf_Close (Header);
			}
			else
			{
				switch ( Error )
				{
					/* cf_Open() failures */
					case CF_OERR_OPEN_FILE:		PrintErr ("Couldn't open CF file"); break;
					case CF_OERR_READ_FILE:		PrintErr ("Couldn't read CF file"); break;
					case CF_OERR_NO_FORMAT:		PrintErr ("File isn't in CF format"); break;
					case CF_OERR_NO_SIZE:		PrintErr ("File hasn't a size"); break;
					case CF_OERR_HEADER_MEM:	PrintErr ("No memory for Header"); break;

					/* cf_Read() failures */
					case CF_RERR_FORMAT:			PrintErr ("File has an error in the format structure"); break;
					case CF_RERR_UNKOWN_ITYPE:	PrintErr ("An unkown item type was found"); break;

					default:							PrintErr ("Unkown open failure"); break;
				}
			}

			FreeArgs (RDA);
		}
		else	PrintErr ("Wrong arguments");

		FreeDosObject (DOS_RDARGS, RDA);
		CloseLibrary (CFBase);
	}
	else	PrintErr ("Couldn't open ConfigFile.library V2+");

	return (Result);
}

VOID PrintErr ( STRPTR String ) { Printf ("Read: %ls\n", String); }

VOID ShowFile ( CFHeader * Header )
{
	CFGroup		*GrpNode;
	CFArgument	*ArgNode;
	CFItem 		*ItemNode;

	BOOL Pnt=FALSE;
	UBYTE BinStr[32];

	/* Before you use the grouplist you must call LockGrpList(). */
	if ( GrpNode = cf_LockGrpList (Header) )
	{
		while ( GrpNode = cf_NextGroup (GrpNode) )
		{
			Printf ("\n[%s]\n\n", cf_GetGrpName (GrpNode));

			/* Before you use the arglist of the
				groupnode you must call LockArgList(). */
			if ( ArgNode = cf_LockArgList (GrpNode) )
			{
				while ( ArgNode = cf_NextArgument (ArgNode) )
				{
					Printf ("%s=", cf_GetArgName (ArgNode));

					/* Before you use the itemlist of the
						argumentnode you must call LockItemList(). */
					if ( ItemNode = cf_LockItemList (ArgNode) )
					{
						while ( ItemNode = cf_NextItem (ItemNode) )
						{
							UBYTE	Type		= cf_GetItemType  (ItemNode);
							UBYTE	SType		= cf_GetItemSType (ItemNode);
							ULONG	Contents	= cf_GetItemOnly  (ItemNode);

							if( Pnt ) Printf (",");

							if ( Type == CF_ITYP_STRING )
							{
								Printf ("\"%s\"", Contents);

								Pnt = TRUE;
							}
							else if ( Type == CF_ITYP_NUMBER )
							{
								if ( SType == CF_STYP_NUM_DEC )
									Printf ("%ld", Contents);
	
								else if ( SType == CF_STYP_NUM_HEX )
									Printf ("$%lx", Contents);

								else if ( SType == CF_STYP_NUM_BIN )
								{
									LongToBinStr (Contents, BinStr);
									Printf ("%%%s", BinStr);
								}

								Pnt = TRUE;	
							}
							else if ( Type == CF_ITYP_BOOL )
							{
								if ( SType == CF_STYP_BOOL_TRUE )
									Printf ("%s", Contents ? "TRUE" : "FALSE");
	
								else if ( SType == CF_STYP_BOOL_YES )
									Printf ("%s", Contents ? "YES" : "NO");
	
								else if ( SType == CF_STYP_BOOL_ON )
									Printf ("%s", Contents ? "ON" : "OFF");

								Pnt = TRUE;
							}
						}

						cf_UnlockItemList (ArgNode);
						Pnt = 0;					
					}

					Printf ("\n");
				}

				cf_UnlockArgList (GrpNode);
			}
		}
	}

	cf_UnlockGrpList (Header);
}

	/* LongToBinStr():
	 *
	 *	convert a long value to a binary string.
	 */

VOID LongToBinStr ( ULONG Bin, STRPTR Str )
{
	ULONG Cnt = 31;
	UBYTE	One = FALSE, *TmpStr = Str;

	do
	{
		if ( Bin & (1 << Cnt) )
		{
			*TmpStr++ = '1';
			One = TRUE;
		}
		else
		{
			if ( One ) *TmpStr++ = '0';
		}

		Cnt--;
	}
	while ( Cnt != -1 );

	*TmpStr = 0;
}
