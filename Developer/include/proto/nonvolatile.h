#ifndef PROTO_NONVOLATILE_H
#define PROTO_NONVOLATILE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/nonvolatile/nonvolatile.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/nonvolatile_protos.h>

#ifndef __NONVOLATILE_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__NONVOLATILE_NOLIBBASE__)
  #if !defined(NonvolatileBase)
   #ifdef __NONVOLATILE_STDLIBBASE__
    extern struct Library *NonvolatileBase;
   #else
    extern struct Library *NonvolatileBase;
   #endif
  #endif
   #ifndef __aros_getbase_NonvolatileBase
    #define __aros_getbase_NonvolatileBase() (NonvolatileBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __NONVOLATILE_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_NonvolatileBase;
 #define AROS_RELLIB_OFFSET_NONVOLATILE __aros_rellib_offset_NonvolatileBase
 #define AROS_RELLIB_BASE_NONVOLATILE __aros_rellib_base_NonvolatileBase
 #ifndef __aros_getbase_NonvolatileBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_NonvolatileBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_NonvolatileBase))
 #endif
#endif

#ifndef __aros_getbase_NonvolatileBase
extern struct Library *__aros_getbase_NonvolatileBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(NONVOLATILE_NOLIBINLINE) && !defined(__NONVOLATILE_RELLIBBASE__)
#   include <inline/nonvolatile.h>
#elif !defined(NOLIBDEFINES) && !defined(NONVOLATILE_NOLIBDEFINES)
#   include <defines/nonvolatile.h>
#endif

#endif /* PROTO_NONVOLATILE_H */
