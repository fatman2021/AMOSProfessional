#ifndef PROTO_FREEANIM_H
#define PROTO_FREEANIM_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/freeanim/freeanim.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/freeanim_protos.h>

#ifndef __FREEANIM_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__FREEANIM_NOLIBBASE__)
  #if !defined(FreeAnimBase)
   #ifdef __FREEANIM_STDLIBBASE__
    extern struct Library *FreeAnimBase;
   #else
    extern struct Library *FreeAnimBase;
   #endif
  #endif
   #ifndef __aros_getbase_FreeAnimBase
    #define __aros_getbase_FreeAnimBase() (FreeAnimBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __FREEANIM_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_FreeAnimBase;
 #define AROS_RELLIB_OFFSET_FREEANIM __aros_rellib_offset_FreeAnimBase
 #define AROS_RELLIB_BASE_FREEANIM __aros_rellib_base_FreeAnimBase
 #ifndef __aros_getbase_FreeAnimBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_FreeAnimBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_FreeAnimBase))
 #endif
#endif

#ifndef __aros_getbase_FreeAnimBase
extern struct Library *__aros_getbase_FreeAnimBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(FREEANIM_NOLIBINLINE) && !defined(__FREEANIM_RELLIBBASE__)
#   include <inline/freeanim.h>
#elif !defined(NOLIBDEFINES) && !defined(FREEANIM_NOLIBDEFINES)
#   include <defines/freeanim.h>
#endif

#endif /* PROTO_FREEANIM_H */
