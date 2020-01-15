/*
**  $PROJECT: Write
**
**  $VER: Write.c 1.4 (20.2.97)
**
**  (C) Copyright 1996-1997 Marcel Karas
**      All Rights Reserved.
**
**  This example open and writes a new CF file.
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

ULONG main( VOID )
{
	struct RDArgs *RDA;
	LONG ArgAry[ARG_MAX] = { 0 };

	ULONG Result = RETURN_ERROR, Error;

	CFGroup		*GrpNode;
	CFArgument	*ArgNode;
	CFItem		*ItemNode;

	CFHeader		*Header;

	if ( CFBase = OpenLibrary (CF_NAME, 1L) )
	{
		RDA = AllocDosObject (DOS_RDARGS, NULL);

		if ( ReadArgs ("ConfigFile/A", ArgAry, RDA) )
		{
			/* Open CF file */
			if ( Header = cf_Open ((STRPTR)ArgAry[ARG_FILE], CF_OMODE_NEWFILE, &Error) )
			{
				/* Open Modes:
				
					CF_OMODE_OLDFILE	 -- A old file will be open. Did the file
												 not exists the function failed.
				
					CF_OMODE_NEWFILE	 -- A new file will be create.

					CF_OMODE_READWRITE -- Open the file. Did the file not exists
												 a new file will be create.
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
					
				Printf ("\n");
/*
				This is without macros:

				GrpNode = cf_NewGroup (Header, "ExampleGroup");
				ArgNode = cf_NewArgument (GrpNode, "ExampleArgument");

				ItemNode = cf_NewItem (ArgNode, (LONG)"Example String",
										CF_ITYP_STRING,NULL);

				cf_NewItem (ArgNode,1234567890,CF_ITYP_NUMBER,CF_STYP_NUM_DEC);
				cf_NewItem (ArgNode,1234567890,CF_ITYP_NUMBER,CF_STYP_NUM_HEX);
				cf_NewItem (ArgNode,1234567890,CF_ITYP_NUMBER,CF_STYP_NUM_BIN);

				ArgNode = cf_NewArgument (GrpNode, "ExampleBools");

				cf_NewItem (ArgNode, TRUE , CF_ITYP_BOOL, CF_STYP_BOOL_TRUE);
				cf_NewItem (ArgNode, FALSE, CF_ITYP_BOOL, CF_STYP_BOOL_TRUE);
				cf_NewItem (ArgNode, TRUE , CF_ITYP_BOOL, CF_STYP_BOOL_YES);
				cf_NewItem (ArgNode, FALSE, CF_ITYP_BOOL, CF_STYP_BOOL_YES);
				cf_NewItem (ArgNode, TRUE , CF_ITYP_BOOL, CF_STYP_BOOL_ON);
				cf_NewItem (ArgNode, FALSE, CF_ITYP_BOOL, CF_STYP_BOOL_ON);

				GrpNode = cf_NewGroup (Header, "ExampleGroupII");
*/
/*
				And this with macros:
*/
				GrpNode = cf_NewGroup (Header, "ExampleGroup");
				ArgNode = cf_NewArgument (GrpNode, "ExampleArgument");

				ItemNode = cf_NewString (ArgNode, "Example String");

				cf_NewNumDec (ArgNode, 1234567890);
				cf_NewNumHex (ArgNode, 1234567890);
				cf_NewNumBin (ArgNode, 1234567890);

				ArgNode = cf_NewArgument (GrpNode, "ExampleBools");

				cf_NewBoolTrue (ArgNode, TRUE);
				cf_NewBoolTrue (ArgNode, FALSE);
				cf_NewBoolYes (ArgNode, TRUE);
				cf_NewBoolYes (ArgNode, FALSE);
				cf_NewBoolOn (ArgNode, TRUE);
				cf_NewBoolOn (ArgNode, FALSE);

				GrpNode = cf_NewGroup (Header, "ExampleGroupII");

				/* Write CF file */
				if ( cf_Write (Header, CF_WMODE_SHORT, &Error) )
				{
					/* Write Modes:

						CF_WMODE_ASCII -- Writes the file as ASCII

												For Example:

												[Group]

												Argument = "Item",34435,%1011,TRUE

						CF_WMODE_SHORT -- Writes the file in the SHORT format

												The SHORT format is a smaller than
												the ASCII format, but the files can
												be not changed with a text editor.

					*/

					Printf ("Ok\n");

					Result = RETURN_OK;
				}
				else
				{
					switch (Error)
					{
						case CF_WERR_ALLOC_WBUFFER:	PrintErr ("No memory for WriteBuffer"); break;
						default:								PrintErr ("Unkown write failure"); break;
					}
				}

				/* Close CF file */
				cf_Close (Header);
			}
			else
			{
				switch (Error)
				{
					case CF_OERR_OPEN_FILE:		PrintErr ("Couldn't open CF file"); break;
					case CF_OERR_READ_FILE:		PrintErr ("Couldn't read CF file"); break;
					case CF_OERR_NO_FORMAT:		PrintErr ("File isn't in CF format"); break;
					case CF_OERR_NO_SIZE:		PrintErr ("File hasn't a size"); break;
					case CF_OERR_HEADER_MEM:	PrintErr ("No memory for Header"); break;
					default:							PrintErr ("Unkown open failure"); break;
				}
			}

			FreeArgs (RDA);
		}
		else	PrintErr ("Wrong arguments");

		FreeDosObject (DOS_RDARGS, RDA);
		CloseLibrary (CFBase);
	}
	else	PrintErr ("Couldn't open ConfigFile.library V1+");

	return (Result);
}

VOID PrintErr( STRPTR String ) { Printf ("Write: %ls\n", String); }
