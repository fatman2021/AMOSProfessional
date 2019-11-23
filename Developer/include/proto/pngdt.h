#ifndef PROTO_PNGDT_H
#define PROTO_PNGDT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/classes/datatypes/png/png.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/pngdt_protos.h>

#ifndef __PNGDT_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__PNGDT_NOLIBBASE__)
  #if !defined(PNGBase)
   #ifdef __PNGDT_STDLIBBASE__
    extern struct Library *PNGBase;
   #else
    extern struct Library *PNGBase;
   #endif
  #endif
   #ifndef __aros_getbase_PNGBase
    #define __aros_getbase_PNGBase() (PNGBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __PNGDT_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_PNGBase;
 #define AROS_RELLIB_OFFSET_PNGDT __aros_rellib_offset_PNGBase
 #define AROS_RELLIB_BASE_PNGDT __aros_rellib_base_PNGBase
 #ifndef __aros_getbase_PNGBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_PNGBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_PNGBase))
 #endif
#endif

#ifndef __aros_getbase_PNGBase
extern struct Library *__aros_getbase_PNGBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(PNGDT_NOLIBINLINE) && !defined(__PNGDT_RELLIBBASE__)
#   include <inline/pngdt.h>
#elif !defined(NOLIBDEFINES) && !defined(PNGDT_NOLIBDEFINES)
#   include <defines/pngdt.h>
#endif

#endif /* PROTO_PNGDT_H */
