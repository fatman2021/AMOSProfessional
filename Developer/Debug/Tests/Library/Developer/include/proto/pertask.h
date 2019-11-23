#ifndef PROTO_PERTASK_H
#define PROTO_PERTASK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/pertask.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/pertask_protos.h>

struct Library *__aros_getbase_PertaskBase(void);
 extern const IPTR __aros_rellib_offset_PertaskBase;
 #define AROS_RELLIB_OFFSET_PERTASK __aros_rellib_offset_PertaskBase
 #define AROS_RELLIB_BASE_PERTASK __aros_rellib_base_PertaskBase

#if !defined(NOLIBINLINE) && !defined(PERTASK_NOLIBINLINE) && !defined(__PERTASK_RELLIBBASE__)
#   include <inline/pertask.h>
#elif !defined(NOLIBDEFINES) && !defined(PERTASK_NOLIBDEFINES)
#   include <defines/pertask.h>
#endif

#endif /* PROTO_PERTASK_H */
