#ifndef PROTO_POTGO_H
#define PROTO_POTGO_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/potgo/potgo.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/potgo_protos.h>

#ifndef __POTGO_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__POTGO_NOLIBBASE__)
  #if !defined(PotgoBase)
   #ifdef __POTGO_STDLIBBASE__
    extern struct Library *PotgoBase;
   #else
    extern struct Library *PotgoBase;
   #endif
  #endif
   #ifndef __aros_getbase_PotgoBase
    #define __aros_getbase_PotgoBase() (PotgoBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __POTGO_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_PotgoBase;
 #define AROS_RELLIB_OFFSET_POTGO __aros_rellib_offset_PotgoBase
 #define AROS_RELLIB_BASE_POTGO __aros_rellib_base_PotgoBase
 #ifndef __aros_getbase_PotgoBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_PotgoBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_PotgoBase))
 #endif
#endif

#ifndef __aros_getbase_PotgoBase
extern struct Library *__aros_getbase_PotgoBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(POTGO_NOLIBINLINE) && !defined(__POTGO_RELLIBBASE__)
#   include <inline/potgo.h>
#elif !defined(NOLIBDEFINES) && !defined(POTGO_NOLIBDEFINES)
#   include <defines/potgo.h>
#endif

#endif /* PROTO_POTGO_H */
