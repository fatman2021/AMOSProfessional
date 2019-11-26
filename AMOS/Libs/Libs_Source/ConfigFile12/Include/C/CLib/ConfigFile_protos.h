/*
**  $VER: ConfigFile_protos.h 2.2 (11.2.97)
**
**  C prototypes for the ConfigFile.library
**
**  (C) Copyright 1996-1997 min'MAX Developer's Group
**      All Rights Reserved.
**
**  (C) Copyright 1996-1997 Marcel Karas
**      All Rights Reserved.
*/

#ifndef  CLIB_CONFIGFILE_PROTOS_H
#define  CLIB_CONFIGFILE_PROTOS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

#ifndef LIBRARIES_CONFIGFILE_H
#include <libraries/configfile.h>
#endif /* LIBRARIES_CONFIGFILE_H */

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/

CFHeader * cf_Open ( STRPTR, ULONG, ULONG * );
VOID cf_Close ( CFHeader * );

/**************************************************************************/

BOOL cf_Read ( CFHeader *, ULONG * );
BOOL cf_Write ( CFHeader *, ULONG, ULONG * );

/**************************************************************************/

VOID cf_AddArgument ( CFGroup *, CFArgument * );
VOID cf_AddGroup ( CFHeader *, CFGroup * );
VOID cf_AddItem ( CFArgument *, CFItem * );

/**************************************************************************/

CFArgument * cf_NewArgument ( CFGroup *, STRPTR );
CFGroup * cf_NewGroup ( CFHeader *, STRPTR );
CFItem * cf_NewItem ( CFArgument *, LONG, ULONG, ULONG );
CFArgument * cf_NewArgItem ( CFGroup *, STRPTR, LONG, ULONG, ULONG );

/**************************************************************************/

VOID cf_DisposeArgument ( CFArgument * );
VOID cf_DisposeGroup ( CFGroup * );
VOID cf_DisposeItem ( CFItem * );

/**************************************************************************/

CFArgument * cf_CloneArgument ( CFArgument * );
CFGroup * cf_CloneGroup ( CFGroup * );
CFItem * cf_CloneItem ( CFItem * );

/**************************************************************************/

VOID cf_RemoveArgument ( CFArgument * );
VOID cf_RemoveGroup ( CFGroup * );
VOID cf_RemoveItem ( CFItem * );

/**************************************************************************/

VOID cf_ClearArgList ( CFGroup * );
VOID cf_ClearGrpList ( CFHeader * );
VOID cf_ClearItemList ( CFArgument * );

/**************************************************************************/

VOID cf_ChangeArgument ( CFArgument *, STRPTR );
VOID cf_ChangeGroup ( CFGroup *, STRPTR );
VOID cf_ChangeItem ( CFItem *, LONG, ULONG, ULONG );

/**************************************************************************/

CFArgument * cf_FindArgument ( CFGroup *, STRPTR );
CFGroup * cf_FindGroup ( CFHeader *, STRPTR );
CFItem * cf_FindItem ( CFArgument *, LONG, ULONG );

/**************************************************************************/

LONG cf_GetItem ( CFItem *, ULONG, LONG );
LONG cf_GetItemNum ( CFArgument *, ULONG, ULONG, LONG );

/**************************************************************************/

CFArgument * cf_LockArgList ( CFGroup * );
CFGroup * cf_LockGrpList ( CFHeader * );
CFItem * cf_LockItemList ( CFArgument * );

/**************************************************************************/

VOID cf_UnlockArgList ( CFGroup * );
VOID cf_UnlockGrpList ( CFHeader * );
VOID cf_UnlockItemList ( CFArgument * );

/**************************************************************************/

CFArgument * cf_NextArgument ( CFArgument * );
CFGroup * cf_NextGroup ( CFGroup * );
CFItem * cf_NextItem ( CFItem * );

/**************************************************************************/

CFArgument * cf_LastArgument ( CFArgument * );
CFGroup * cf_LastGroup ( CFGroup * );
CFItem * cf_LastItem ( CFItem * );

/***************************************************************************
**               Functions in V2 or higher (Release 1.1)                  **
***************************************************************************/

CFHeader * cf_OpenPS ( STRPTR, ULONG, ULONG *, ULONG );

/**************************************************************************/

UBYTE cf_GetItemType ( CFItem * );
UBYTE cf_GetItemSType ( CFItem * );

/**************************************************************************/

STRPTR cf_GetGrpName ( CFGroup * );
STRPTR cf_GetArgName ( CFArgument * );

/**************************************************************************/

CFHeader * cf_GetHdrOfGrp ( CFGroup * );
CFGroup * cf_GetGrpOfArg ( CFArgument * );
CFArgument * cf_GetArgOfItem ( CFItem * );

/**************************************************************************/

LONG cf_GetItemOnly ( CFItem * );

/**************************************************************************/

#ifdef __cplusplus
}

#endif /* CLIB_CONFIGFILE_PROTOS_H */
