#ifndef PROTO_STDCIO_H
#define PROTO_STDCIO_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/compiler/stdc/stdcio.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/stdcio_protos.h>

struct StdCIOBase *__aros_getbase_StdCIOBase(void);
 extern const IPTR __aros_rellib_offset_StdCIOBase;
 #define AROS_RELLIB_OFFSET_STDCIO __aros_rellib_offset_StdCIOBase
 #define AROS_RELLIB_BASE_STDCIO __aros_rellib_base_StdCIOBase

#if !defined(NOLIBINLINE) && !defined(STDCIO_NOLIBINLINE) && !defined(__STDCIO_RELLIBBASE__)
#   include <inline/stdcio.h>
#elif !defined(NOLIBDEFINES) && !defined(STDCIO_NOLIBDEFINES)
#   include <defines/stdcio.h>
#endif

#endif /* PROTO_STDCIO_H */
