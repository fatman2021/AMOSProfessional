#ifndef PROTO_DUMMY_H
#define PROTO_DUMMY_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/dummy.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/dummy_protos.h>

#ifndef __DUMMY_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__DUMMY_NOLIBBASE__)
  #if !defined(DummyBase)
   #ifdef __DUMMY_STDLIBBASE__
    extern struct Library *DummyBase;
   #else
    extern struct Library *DummyBase;
   #endif
  #endif
   #ifndef __aros_getbase_DummyBase
    #define __aros_getbase_DummyBase() (DummyBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __DUMMY_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_DummyBase;
 #define AROS_RELLIB_OFFSET_DUMMY __aros_rellib_offset_DummyBase
 #define AROS_RELLIB_BASE_DUMMY __aros_rellib_base_DummyBase
 #ifndef __aros_getbase_DummyBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_DummyBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_DummyBase))
 #endif
#endif

#ifndef __aros_getbase_DummyBase
extern struct Library *__aros_getbase_DummyBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(DUMMY_NOLIBINLINE) && !defined(__DUMMY_RELLIBBASE__)
#   include <inline/dummy.h>
#elif !defined(NOLIBDEFINES) && !defined(DUMMY_NOLIBDEFINES)
#   include <defines/dummy.h>
#endif

#endif /* PROTO_DUMMY_H */
