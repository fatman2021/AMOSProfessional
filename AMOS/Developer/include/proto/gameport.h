#ifndef PROTO_GAMEPORT_H
#define PROTO_GAMEPORT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/devs/gameport/gameport.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <exec/devices.h>
#include <aros/system.h>

#include <clib/gameport_protos.h>

#ifndef __GAMEPORT_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__GAMEPORT_NOLIBBASE__)
  #if !defined(GPBase)
   #ifdef __GAMEPORT_STDLIBBASE__
    extern struct Library *GPBase;
   #else
    extern struct Device *GPBase;
   #endif
  #endif
   #ifndef __aros_getbase_GPBase
    #define __aros_getbase_GPBase() (GPBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __GAMEPORT_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_GPBase;
 #define AROS_RELLIB_OFFSET_GAMEPORT __aros_rellib_offset_GPBase
 #define AROS_RELLIB_BASE_GAMEPORT __aros_rellib_base_GPBase
 #ifndef __aros_getbase_GPBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_GPBase() (*(struct Device **)(__aros_getoffsettable()+__aros_rellib_offset_GPBase))
 #endif
#endif

#ifndef __aros_getbase_GPBase
extern struct Device *__aros_getbase_GPBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(GAMEPORT_NOLIBINLINE) && !defined(__GAMEPORT_RELLIBBASE__)
#   include <inline/gameport.h>
#elif !defined(NOLIBDEFINES) && !defined(GAMEPORT_NOLIBDEFINES)
#   include <defines/gameport.h>
#endif

#endif /* PROTO_GAMEPORT_H */
