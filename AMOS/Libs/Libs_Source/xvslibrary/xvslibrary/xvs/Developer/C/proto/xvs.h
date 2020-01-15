#ifndef _PROTO_XVS_H
#define _PROTO_XVS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_XVS_PROTOS_H
#include <clib/xvs_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *xvsBase;
#endif

#ifdef __GNUC__
#include <inline/xvs.h>
#elif defined(__VBCC__)
#ifndef __PPC__
#include <inline/xvs_protos.h>
#endif
#else
#include <pragma/xvs_lib.h>
#endif

#endif	/*  _PROTO_XVS_H  */
