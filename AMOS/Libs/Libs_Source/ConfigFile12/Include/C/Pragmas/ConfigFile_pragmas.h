/*
**  $VER: ConfigFile_pragmas.h 2.1 (11.2.97)
**
**  ConfigFile.library pragmas for SAS/C
**
**  (C) Copyright 1996-1997 min'MAX Developer's Group
**      All Rights Reserved.
**
**  (C) Copyright 1996-1997 Marcel Karas
**      All Rights Reserved.
*/

#ifndef PRAGMAS_CONFIGFILE_H
#define PRAGMAS_CONFIGFILE_H

#pragma libcall CFBase cf_Open 1e 90803
#pragma libcall CFBase cf_Close 24 801
#pragma libcall CFBase cf_Read 2a 9802
#pragma libcall CFBase cf_Write 30 90803
#pragma libcall CFBase cf_AddGroup 36 9802
#pragma libcall CFBase cf_AddArgument 3c 9802
#pragma libcall CFBase cf_AddItem 42 9802
#pragma libcall CFBase cf_NewGroup 48 9802
#pragma libcall CFBase cf_NewArgument 4e 9802
#pragma libcall CFBase cf_NewItem 54 210804
#pragma libcall CFBase cf_NewArgItem 5a 2109805
#pragma libcall CFBase cf_DisposeGroup 60 801
#pragma libcall CFBase cf_DisposeArgument 66 801
#pragma libcall CFBase cf_DisposeItem 6c 801
#pragma libcall CFBase cf_CloneGroup 72 801
#pragma libcall CFBase cf_CloneArgument 78 801
#pragma libcall CFBase cf_CloneItem 7e 801
#pragma libcall CFBase cf_RemoveGroup 84 801
#pragma libcall CFBase cf_RemoveArgument 8a 801
#pragma libcall CFBase cf_RemoveItem 90 801
#pragma libcall CFBase cf_ClearGrpList 96 801
#pragma libcall CFBase cf_ClearArgList 9c 801
#pragma libcall CFBase cf_ClearItemList a2 801
#pragma libcall CFBase cf_ChangeGroup a8 9802
#pragma libcall CFBase cf_ChangeArgument ae 9802
#pragma libcall CFBase cf_ChangeItem b4 210804
#pragma libcall CFBase cf_FindGroup ba 9802
#pragma libcall CFBase cf_FindArgument c0 9802
#pragma libcall CFBase cf_FindItem c6 10803
#pragma libcall CFBase cf_GetItem cc 10803
#pragma libcall CFBase cf_GetItemNum d2 210804
#pragma libcall CFBase cf_LockGrpList d8 801
#pragma libcall CFBase cf_LockArgList de 801
#pragma libcall CFBase cf_LockItemList e4 801
#pragma libcall CFBase cf_UnlockGrpList ea 801
#pragma libcall CFBase cf_UnlockArgList f0 801
#pragma libcall CFBase cf_UnlockItemList f6 801
#pragma libcall CFBase cf_NextGroup fc 801
#pragma libcall CFBase cf_NextArgument 102 801
#pragma libcall CFBase cf_NextItem 108 801
#pragma libcall CFBase cf_LastGroup 10e 801
#pragma libcall CFBase cf_LastArgument 114 801
#pragma libcall CFBase cf_LastItem 11a 801
/*
**  Functions in V2 or higher (Release 1.1)
*/
#pragma libcall CFBase cf_OpenPS 120 190804
#pragma libcall CFBase cf_GetItemType 126 801
#pragma libcall CFBase cf_GetItemSType 12c 801
#pragma libcall CFBase cf_GetGrpName 132 801
#pragma libcall CFBase cf_GetArgName 138 801
#pragma libcall CFBase cf_GetHdrOfGrp 13e 801
#pragma libcall CFBase cf_GetGrpOfArg 144 801
#pragma libcall CFBase cf_GetArgOfItem 14a 801
#pragma libcall CFBase cf_GetItemOnly 150 801

#endif /* PRAGMAS_CONFIGFILE_H */
