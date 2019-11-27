#ifndef PROTO_DISKFONT_H
#define PROTO_DISKFONT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/diskfont/diskfont.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/diskfont_protos.h>

#ifndef __DISKFONT_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__DISKFONT_NOLIBBASE__)
  #if !defined(DiskfontBase)
   #ifdef __DISKFONT_STDLIBBASE__
    extern struct Library *DiskfontBase;
   #else
    extern struct Library *DiskfontBase;
   #endif
  #endif
   #ifndef __aros_getbase_DiskfontBase
    #define __aros_getbase_DiskfontBase() (DiskfontBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __DISKFONT_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_DiskfontBase;
 #define AROS_RELLIB_OFFSET_DISKFONT __aros_rellib_offset_DiskfontBase
 #define AROS_RELLIB_BASE_DISKFONT __aros_rellib_base_DiskfontBase
 #ifndef __aros_getbase_DiskfontBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_DiskfontBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_DiskfontBase))
 #endif
#endif

#ifndef __aros_getbase_DiskfontBase
extern struct Library *__aros_getbase_DiskfontBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(DISKFONT_NOLIBINLINE) && !defined(__DISKFONT_RELLIBBASE__)
#   include <inline/diskfont.h>
#elif !defined(NOLIBDEFINES) && !defined(DISKFONT_NOLIBDEFINES)
#   include <defines/diskfont.h>
#endif

#endif /* PROTO_DISKFONT_H */
