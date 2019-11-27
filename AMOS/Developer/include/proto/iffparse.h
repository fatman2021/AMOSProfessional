#ifndef PROTO_IFFPARSE_H
#define PROTO_IFFPARSE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/iffparse/iffparse.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/iffparse_protos.h>

#ifndef __IFFPARSE_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__IFFPARSE_NOLIBBASE__)
  #if !defined(IFFParseBase)
   #ifdef __IFFPARSE_STDLIBBASE__
    extern struct Library *IFFParseBase;
   #else
    extern struct Library *IFFParseBase;
   #endif
  #endif
   #ifndef __aros_getbase_IFFParseBase
    #define __aros_getbase_IFFParseBase() (IFFParseBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __IFFPARSE_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_IFFParseBase;
 #define AROS_RELLIB_OFFSET_IFFPARSE __aros_rellib_offset_IFFParseBase
 #define AROS_RELLIB_BASE_IFFPARSE __aros_rellib_base_IFFParseBase
 #ifndef __aros_getbase_IFFParseBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_IFFParseBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_IFFParseBase))
 #endif
#endif

#ifndef __aros_getbase_IFFParseBase
extern struct Library *__aros_getbase_IFFParseBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(IFFPARSE_NOLIBINLINE) && !defined(__IFFPARSE_RELLIBBASE__)
#   include <inline/iffparse.h>
#elif !defined(NOLIBDEFINES) && !defined(IFFPARSE_NOLIBDEFINES)
#   include <defines/iffparse.h>
#endif

#endif /* PROTO_IFFPARSE_H */
