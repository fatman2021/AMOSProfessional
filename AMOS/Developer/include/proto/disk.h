#ifndef PROTO_DISK_H
#define PROTO_DISK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/disk/disk.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/disk_protos.h>

#ifndef __DISK_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__DISK_NOLIBBASE__)
  #if !defined(DiskBase)
   #ifdef __DISK_STDLIBBASE__
    extern struct Library *DiskBase;
   #else
    extern struct Library *DiskBase;
   #endif
  #endif
   #ifndef __aros_getbase_DiskBase
    #define __aros_getbase_DiskBase() (DiskBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __DISK_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_DiskBase;
 #define AROS_RELLIB_OFFSET_DISK __aros_rellib_offset_DiskBase
 #define AROS_RELLIB_BASE_DISK __aros_rellib_base_DiskBase
 #ifndef __aros_getbase_DiskBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_DiskBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_DiskBase))
 #endif
#endif

#ifndef __aros_getbase_DiskBase
extern struct Library *__aros_getbase_DiskBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(DISK_NOLIBINLINE) && !defined(__DISK_RELLIBBASE__)
#   include <inline/disk.h>
#elif !defined(NOLIBDEFINES) && !defined(DISK_NOLIBDEFINES)
#   include <defines/disk.h>
#endif

#endif /* PROTO_DISK_H */
