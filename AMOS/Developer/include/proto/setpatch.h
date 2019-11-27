#ifndef PROTO_SETPATCH_H
#define PROTO_SETPATCH_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/setpatch/setpatch.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/setpatch_protos.h>

#ifndef __SETPATCH_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__SETPATCH_NOLIBBASE__)
  #if !defined(SetPatchBase)
   #ifdef __SETPATCH_STDLIBBASE__
    extern struct Library *SetPatchBase;
   #else
    extern struct Library *SetPatchBase;
   #endif
  #endif
   #ifndef __aros_getbase_SetPatchBase
    #define __aros_getbase_SetPatchBase() (SetPatchBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __SETPATCH_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_SetPatchBase;
 #define AROS_RELLIB_OFFSET_SETPATCH __aros_rellib_offset_SetPatchBase
 #define AROS_RELLIB_BASE_SETPATCH __aros_rellib_base_SetPatchBase
 #ifndef __aros_getbase_SetPatchBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_SetPatchBase() (*(struct Library **)(__aros_getoffsettable()+__aros_rellib_offset_SetPatchBase))
 #endif
#endif

#ifndef __aros_getbase_SetPatchBase
extern struct Library *__aros_getbase_SetPatchBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(SETPATCH_NOLIBINLINE) && !defined(__SETPATCH_RELLIBBASE__)
#   include <inline/setpatch.h>
#elif !defined(NOLIBDEFINES) && !defined(SETPATCH_NOLIBDEFINES)
#   include <defines/setpatch.h>
#endif

#endif /* PROTO_SETPATCH_H */
