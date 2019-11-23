#ifndef PROTO_PEROPENER_H
#define PROTO_PEROPENER_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/peropener.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/peropener_protos.h>

struct Library *__aros_getbase_PeropenerBase(void);
 extern const IPTR __aros_rellib_offset_PeropenerBase;
 #define AROS_RELLIB_OFFSET_PEROPENER __aros_rellib_offset_PeropenerBase
 #define AROS_RELLIB_BASE_PEROPENER __aros_rellib_base_PeropenerBase

#if !defined(NOLIBINLINE) && !defined(PEROPENER_NOLIBINLINE) && !defined(__PEROPENER_RELLIBBASE__)
#   include <inline/peropener.h>
#elif !defined(NOLIBDEFINES) && !defined(PEROPENER_NOLIBDEFINES)
#   include <defines/peropener.h>
#endif

#endif /* PROTO_PEROPENER_H */
