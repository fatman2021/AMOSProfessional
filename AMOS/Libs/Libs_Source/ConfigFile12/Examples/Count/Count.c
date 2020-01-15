/*
**  $PROJECT: Count
**
**  $VER: Count.c 1.1 (20.2.97)
**
**  (C) Copyright 1997 Marcel Karas
**      All Rights Reserved.
**
**  This example reads a CF file and count the nodes.
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

UWORD	GrpNodeCnt	= 0,
		ArgNodeCnt	= 0,
		ItemNodeCnt	= 0,
		MaxArgNodeCnt	= 0,
		MaxItemNodeCnt	= 0;

enum { ARG_FILE ,ARG_MAX };

VOID PrintErr ( STRPTR );
VOID CountNodes ( CFHeader * );

ULONG main ( VOID )
{
	struct RDArgs *RDA;
	LONG ArgAry[ARG_MAX] = { 0 };

	ULONG Result = RETURN_ERROR, Error;

	CFHeader	* Header;

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

				Printf ("Count Nodes:\n\n");
				CountNodes (Header);

				Printf (	"This file has:\n\n"
							"GrpNodes  = %ld\n"
							"ArgNodes  = %ld\n"
							"ItemNodes = %ld\n\n"
							"Maximum ArgNodes in a GrpNode = %ld\n"
							"Maximum ItemNodes in an ArgNode = %ld\n",
							GrpNodeCnt, ArgNodeCnt, ItemNodeCnt,
							MaxArgNodeCnt, MaxItemNodeCnt);

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

VOID PrintErr ( STRPTR String ) { Printf ("Count: %ls\n", String); }

VOID CountNodes ( CFHeader * Header )
{
	CFGroup		*GrpNode;
	CFArgument	*ArgNode;
	CFItem 		*ItemNode;

	/* Before you use the grouplist you must call LockGrpList(). */
	if ( GrpNode = cf_LockGrpList (Header) )
	{
		while ( GrpNode = cf_NextGroup (GrpNode) )
		{
			GrpNodeCnt ++;

			/* Before you use the arglist of the
				groupnode you must call LockArgList(). */
			if ( ArgNode = cf_LockArgList (GrpNode) )
			{
				UWORD	TmpArgNodeCnt = 0;

				while ( ArgNode = cf_NextArgument (ArgNode) )
				{
					TmpArgNodeCnt ++, ArgNodeCnt ++;

					/* Before you use the itemlist of the
						argumentnode you must call LockItemList(). */
					if ( ItemNode = cf_LockItemList (ArgNode) )
					{
						UWORD	TmpItemNodeCnt = 0;

						while ( ItemNode = cf_NextItem (ItemNode) )
							TmpItemNodeCnt ++, ItemNodeCnt ++;

						cf_UnlockItemList (ArgNode);

						if ( TmpItemNodeCnt > MaxItemNodeCnt )
								MaxItemNodeCnt = TmpItemNodeCnt;
					}
				}

				if ( TmpArgNodeCnt > MaxArgNodeCnt )
						MaxArgNodeCnt = TmpArgNodeCnt;

				cf_UnlockArgList (GrpNode);
			}
		}
	}

	cf_UnlockGrpList (Header);
}
