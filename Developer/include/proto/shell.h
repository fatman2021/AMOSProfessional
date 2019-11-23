#ifndef PROTO_SHELL_H
#define PROTO_SHELL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/c/Shell/shell.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/shell_protos.h>

#ifndef __SHELL_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__SHELL_NOLIBBASE__)
  #if !defined(Shell)
   #ifdef __SHELL_STDLIBBASE__
    extern struct Library *Shell;
   #else
    extern APTR Shell;
   #endif
  #endif
   #ifndef __aros_getbase_Shell
    #define __aros_getbase_Shell() (Shell)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __SHELL_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_Shell;
 #define AROS_RELLIB_OFFSET_SHELL __aros_rellib_offset_Shell
 #define AROS_RELLIB_BASE_SHELL __aros_rellib_base_Shell
 #ifndef __aros_getbase_Shell
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_Shell() (*(APTR *)(__aros_getoffsettable()+__aros_rellib_offset_Shell))
 #endif
#endif

#ifndef __aros_getbase_Shell
extern APTR __aros_getbase_Shell(void);
#endif

#if !defined(NOLIBINLINE) && !defined(SHELL_NOLIBINLINE) && !defined(__SHELL_RELLIBBASE__)
#   include <inline/shell.h>
#elif !defined(NOLIBDEFINES) && !defined(SHELL_NOLIBDEFINES)
#   include <defines/shell.h>
#endif

#endif /* PROTO_SHELL_H */
