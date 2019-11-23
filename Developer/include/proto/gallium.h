#ifndef PROTO_GALLIUM_H
#define PROTO_GALLIUM_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/gallium/gallium.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/gallium_protos.h>

#ifndef __GALLIUM_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__GALLIUM_NOLIBBASE__)
  #if !defined(GalliumBase)
   #ifdef __GALLIUM_STDLIBBASE__
    extern struct Library *GalliumBase;
   #else
    extern struct Library *GalliumBase;
   #endif
  #endif
   #ifndef __aros_getbase_GalliumBase
    #define __aros_getbase_GalliumBase() (GalliumBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __GALLIUM_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_GalliumBase;
 #define AROS_RELLIB_OFFSET_GALLIUM __aros_rellib_offset_GalliumBase
 #define AROS_RELLIB_BASE_GALLIUM __aros_rellib_base_GalliumBase
 #ifndef __aros_getbase_GalliumBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_GalliumBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_GalliumBase))
 #endif
#endif

#ifndef __aros_getbase_GalliumBase
extern struct Library *__aros_getbase_GalliumBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(GALLIUM_NOLIBINLINE) && !defined(__GALLIUM_RELLIBBASE__)
#   include <inline/gallium.h>
#elif !defined(NOLIBDEFINES) && !defined(GALLIUM_NOLIBDEFINES)
#   include <defines/gallium.h>
#endif

#endif /* PROTO_GALLIUM_H */
