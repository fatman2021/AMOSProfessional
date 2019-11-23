#ifndef PROTO_OOP_H
#define PROTO_OOP_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/oop/oop.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/oop_protos.h>

#ifndef __OOP_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__OOP_NOLIBBASE__)
  #if !defined(OOPBase)
   #ifdef __OOP_STDLIBBASE__
    extern struct Library *OOPBase;
   #else
    extern struct Library *OOPBase;
   #endif
  #endif
   #ifndef __aros_getbase_OOPBase
    #define __aros_getbase_OOPBase() (OOPBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __OOP_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_OOPBase;
 #define AROS_RELLIB_OFFSET_OOP __aros_rellib_offset_OOPBase
 #define AROS_RELLIB_BASE_OOP __aros_rellib_base_OOPBase
 #ifndef __aros_getbase_OOPBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_OOPBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_OOPBase))
 #endif
#endif

#ifndef __aros_getbase_OOPBase
extern struct Library *__aros_getbase_OOPBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(OOP_NOLIBINLINE) && !defined(__OOP_RELLIBBASE__)
#   include <inline/oop.h>
#elif !defined(NOLIBDEFINES) && !defined(OOP_NOLIBDEFINES)
#   include <defines/oop.h>
#endif

#endif /* PROTO_OOP_H */
