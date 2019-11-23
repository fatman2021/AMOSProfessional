#ifndef PROTO_ASL_H
#define PROTO_ASL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/asl/asl.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/asl_protos.h>

#ifndef __ASL_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__ASL_NOLIBBASE__)
  #if !defined(AslBase)
   #ifdef __ASL_STDLIBBASE__
    extern struct Library *AslBase;
   #else
    extern struct Library *AslBase;
   #endif
  #endif
   #ifndef __aros_getbase_AslBase
    #define __aros_getbase_AslBase() (AslBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __ASL_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_AslBase;
 #define AROS_RELLIB_OFFSET_ASL __aros_rellib_offset_AslBase
 #define AROS_RELLIB_BASE_ASL __aros_rellib_base_AslBase
 #ifndef __aros_getbase_AslBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_AslBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_AslBase))
 #endif
#endif

#ifndef __aros_getbase_AslBase
extern struct Library *__aros_getbase_AslBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(ASL_NOLIBINLINE) && !defined(__ASL_RELLIBBASE__)
#   include <inline/asl.h>
#elif !defined(NOLIBDEFINES) && !defined(ASL_NOLIBDEFINES)
#   include <defines/asl.h>
#endif

#endif /* PROTO_ASL_H */
