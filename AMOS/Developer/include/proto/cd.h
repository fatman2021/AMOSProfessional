#ifndef PROTO_CD_H
#define PROTO_CD_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/devs/cd/cd.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <exec/devices.h>
#include <aros/system.h>

#include <clib/cd_protos.h>

#ifndef __CD_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__CD_NOLIBBASE__)
  #if !defined(cdBase)
   #ifdef __CD_STDLIBBASE__
    extern struct Library *cdBase;
   #else
    extern struct Device *cdBase;
   #endif
  #endif
   #ifndef __aros_getbase_cdBase
    #define __aros_getbase_cdBase() (cdBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __CD_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_cdBase;
 #define AROS_RELLIB_OFFSET_CD __aros_rellib_offset_cdBase
 #define AROS_RELLIB_BASE_CD __aros_rellib_base_cdBase
 #ifndef __aros_getbase_cdBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_cdBase() (*(struct Device **)(__aros_getoffsettable()+__aros_rellib_offset_cdBase))
 #endif
#endif

#ifndef __aros_getbase_cdBase
extern struct Device *__aros_getbase_cdBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(CD_NOLIBINLINE) && !defined(__CD_RELLIBBASE__)
#   include <inline/cd.h>
#elif !defined(NOLIBDEFINES) && !defined(CD_NOLIBDEFINES)
#   include <defines/cd.h>
#endif

#endif /* PROTO_CD_H */
