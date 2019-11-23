#ifndef PROTO_680X0_H
#define PROTO_680X0_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-all/m680x0/680x0.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/680x0_protos.h>

#ifndef __680X0_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__680X0_NOLIBBASE__)
  #if !defined(M680x0Base)
   #ifdef __680X0_STDLIBBASE__
    extern struct Library *M680x0Base;
   #else
    extern struct Library *M680x0Base;
   #endif
  #endif
   #ifndef __aros_getbase_M680x0Base
    #define __aros_getbase_M680x0Base() (M680x0Base)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __680X0_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_M680x0Base;
 #define AROS_RELLIB_OFFSET_680X0 __aros_rellib_offset_M680x0Base
 #define AROS_RELLIB_BASE_680X0 __aros_rellib_base_M680x0Base
 #ifndef __aros_getbase_M680x0Base
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_M680x0Base() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_M680x0Base))
 #endif
#endif

#ifndef __aros_getbase_M680x0Base
extern struct Library *__aros_getbase_M680x0Base(void);
#endif

#if !defined(NOLIBINLINE) && !defined(X680X0_NOLIBINLINE) && !defined(__680X0_RELLIBBASE__)
#   include <inline/680x0.h>
#elif !defined(NOLIBDEFINES) && !defined(X680X0_NOLIBDEFINES)
#   include <defines/680x0.h>
#endif

#endif /* PROTO_680X0_H */
