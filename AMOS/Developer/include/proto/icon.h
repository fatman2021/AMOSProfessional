#ifndef PROTO_ICON_H
#define PROTO_ICON_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/icon/icon.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/icon_protos.h>

#ifndef __ICON_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__ICON_NOLIBBASE__)
  #if !defined(IconBase)
   #ifdef __ICON_STDLIBBASE__
    extern struct Library *IconBase;
   #else
    extern struct Library *IconBase;
   #endif
  #endif
   #ifndef __aros_getbase_IconBase
    #define __aros_getbase_IconBase() (IconBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __ICON_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_IconBase;
 #define AROS_RELLIB_OFFSET_ICON __aros_rellib_offset_IconBase
 #define AROS_RELLIB_BASE_ICON __aros_rellib_base_IconBase
 #ifndef __aros_getbase_IconBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_IconBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_IconBase))
 #endif
#endif

#ifndef __aros_getbase_IconBase
extern struct Library *__aros_getbase_IconBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(ICON_NOLIBINLINE) && !defined(__ICON_RELLIBBASE__)
#   include <inline/icon.h>
#elif !defined(NOLIBDEFINES) && !defined(ICON_NOLIBDEFINES)
#   include <defines/icon.h>
#endif

#endif /* PROTO_ICON_H */
