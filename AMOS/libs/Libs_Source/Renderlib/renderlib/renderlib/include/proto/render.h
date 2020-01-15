#ifndef _PROTO_RENDER_H
#define _PROTO_RENDER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_RENDER_PROTOS_H
#include <clib/render_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *RenderBase;
#endif

#ifdef __GNUC__
#include <inline/render.h>
#elif defined(__SASC)
#include <pragmas/render_pragmas.h>
#elif !defined(__VBCC__)
#include <pragma/render_lib.h>
#endif

#endif	/*  _PROTO_RENDER_H  */
