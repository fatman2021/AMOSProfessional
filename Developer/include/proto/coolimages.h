#ifndef PROTO_COOLIMAGES_H
#define PROTO_COOLIMAGES_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/coolimages/coolimages.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/coolimages_protos.h>

#ifndef __COOLIMAGES_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__COOLIMAGES_NOLIBBASE__)
  #if !defined(CoolImagesBase)
   #ifdef __COOLIMAGES_STDLIBBASE__
    extern struct Library *CoolImagesBase;
   #else
    extern struct Library *CoolImagesBase;
   #endif
  #endif
   #ifndef __aros_getbase_CoolImagesBase
    #define __aros_getbase_CoolImagesBase() (CoolImagesBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __COOLIMAGES_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_CoolImagesBase;
 #define AROS_RELLIB_OFFSET_COOLIMAGES __aros_rellib_offset_CoolImagesBase
 #define AROS_RELLIB_BASE_COOLIMAGES __aros_rellib_base_CoolImagesBase
 #ifndef __aros_getbase_CoolImagesBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_CoolImagesBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_CoolImagesBase))
 #endif
#endif

#ifndef __aros_getbase_CoolImagesBase
extern struct Library *__aros_getbase_CoolImagesBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(COOLIMAGES_NOLIBINLINE) && !defined(__COOLIMAGES_RELLIBBASE__)
#   include <inline/coolimages.h>
#elif !defined(NOLIBDEFINES) && !defined(COOLIMAGES_NOLIBDEFINES)
#   include <defines/coolimages.h>
#endif

#endif /* PROTO_COOLIMAGES_H */
