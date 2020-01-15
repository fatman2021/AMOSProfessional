#ifndef PROTO_TTENGINE_H
#define PROTO_TTENGINE_H

/*
**	$Id$
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	(C) Copyright 2003-2004 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_TTENGINE_H
#include <libraries/ttengine.h>
#endif
#ifndef GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * TTEngineBase;
 #else
  extern struct Library * TTEngineBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/ttengine.h>
 #ifdef __USE_INLINE__
  #include <inline4/ttengine.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TTENGINE_PROTOS_H
  #define CLIB_TTENGINE_PROTOS_H 1
 #endif /* CLIB_TTENGINE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct TTEngineIFace *ITTEngine;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TTENGINE_PROTOS_H
  #include <clib/ttengine_protos.h>
 #endif /* CLIB_TTENGINE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/ttengine.h>
  #else
   #include <ppcinline/ttengine.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/ttengine_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/ttengine_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TTENGINE_H */
