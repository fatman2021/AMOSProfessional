#ifndef PROTO_COMMODITIES_H
#define PROTO_COMMODITIES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/commodities/commodities.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/commodities_protos.h>

#ifndef __COMMODITIES_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__COMMODITIES_NOLIBBASE__)
  #if !defined(CxBase)
   #ifdef __COMMODITIES_STDLIBBASE__
    extern struct Library *CxBase;
   #else
    extern struct Library *CxBase;
   #endif
  #endif
   #ifndef __aros_getbase_CxBase
    #define __aros_getbase_CxBase() (CxBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __COMMODITIES_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_CxBase;
 #define AROS_RELLIB_OFFSET_COMMODITIES __aros_rellib_offset_CxBase
 #define AROS_RELLIB_BASE_COMMODITIES __aros_rellib_base_CxBase
 #ifndef __aros_getbase_CxBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_CxBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_CxBase))
 #endif
#endif

#ifndef __aros_getbase_CxBase
extern struct Library *__aros_getbase_CxBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(COMMODITIES_NOLIBINLINE) && !defined(__COMMODITIES_RELLIBBASE__)
#   include <inline/commodities.h>
#elif !defined(NOLIBDEFINES) && !defined(COMMODITIES_NOLIBDEFINES)
#   include <defines/commodities.h>
#endif

#endif /* PROTO_COMMODITIES_H */
