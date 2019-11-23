#ifndef PROTO_USEREL_H
#define PROTO_USEREL_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/userel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/userel_protos.h>

struct Library *__aros_getbase_UserelBase(void);
 extern const IPTR __aros_rellib_offset_UserelBase;
 #define AROS_RELLIB_OFFSET_USEREL __aros_rellib_offset_UserelBase
 #define AROS_RELLIB_BASE_USEREL __aros_rellib_base_UserelBase

#if !defined(NOLIBINLINE) && !defined(USEREL_NOLIBINLINE) && !defined(__USEREL_RELLIBBASE__)
#   include <inline/userel.h>
#elif !defined(NOLIBDEFINES) && !defined(USEREL_NOLIBDEFINES)
#   include <defines/userel.h>
#endif

#endif /* PROTO_USEREL_H */
