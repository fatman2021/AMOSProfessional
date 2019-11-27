#ifndef PROTO_SHELLCOMMANDS_H
#define PROTO_SHELLCOMMANDS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/c/shellcommands/shellcommands.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/shellcommands_protos.h>

#ifndef __SHELLCOMMANDS_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__SHELLCOMMANDS_NOLIBBASE__)
  #if !defined(ShellCommandsBase)
   #ifdef __SHELLCOMMANDS_STDLIBBASE__
    extern struct Library *ShellCommandsBase;
   #else
    extern APTR ShellCommandsBase;
   #endif
  #endif
   #ifndef __aros_getbase_ShellCommandsBase
    #define __aros_getbase_ShellCommandsBase() (ShellCommandsBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __SHELLCOMMANDS_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_ShellCommandsBase;
 #define AROS_RELLIB_OFFSET_SHELLCOMMANDS __aros_rellib_offset_ShellCommandsBase
 #define AROS_RELLIB_BASE_SHELLCOMMANDS __aros_rellib_base_ShellCommandsBase
 #ifndef __aros_getbase_ShellCommandsBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_ShellCommandsBase() (*(APTR *)(__aros_getoffsettable()+__aros_rellib_offset_ShellCommandsBase))
 #endif
#endif

#ifndef __aros_getbase_ShellCommandsBase
extern APTR __aros_getbase_ShellCommandsBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(SHELLCOMMANDS_NOLIBINLINE) && !defined(__SHELLCOMMANDS_RELLIBBASE__)
#   include <inline/shellcommands.h>
#elif !defined(NOLIBDEFINES) && !defined(SHELLCOMMANDS_NOLIBDEFINES)
#   include <defines/shellcommands.h>
#endif

#endif /* PROTO_SHELLCOMMANDS_H */
