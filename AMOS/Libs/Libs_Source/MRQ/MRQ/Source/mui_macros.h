/*
** mui-macros.h
** Some macros used in MRQ, adapted from MUI's standard macros
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: mui_macros.h 1.1 2000/01/25 16:53:35 msbethke Exp msbethke $
**
** $Log: mui_macros.h $
** Revision 1.1  2000/01/25 16:53:35  msbethke
** Initial revision
**
*/

#define Button(name,key)\
        TextObject,\
				ButtonFrame,\
				MUIA_Text_Contents, name,\
				MUIA_Text_PreParse, "\33c",\
				MUIA_Text_HiChar  , key,\
				MUIA_ControlChar  , key,\
	 			MUIA_InputMode    , MUIV_InputMode_RelVerify,\
				MUIA_Background   , MUII_ButtonBack,\
				MUIA_CycleChain,1,\
				End

#define MyStringGadget(maxlen,controlchar)\
        StringObject,\
				StringFrame,\
				MUIA_ControlChar, controlchar,\
				MUIA_String_MaxLen, maxlen,\
				MUIA_CycleChain, 1,\
				End

#define MyIntGadget(maxlen,controlchar)\
        StringObject,\
				StringFrame,\
				MUIA_ControlChar, controlchar,\
				MUIA_String_MaxLen, maxlen,\
				MUIA_CycleChain, 1,\
				MUIA_String_Accept, "0123456789",\
				End

#define MRQWindowObject NewObject(MRQWindowClass,NULL
