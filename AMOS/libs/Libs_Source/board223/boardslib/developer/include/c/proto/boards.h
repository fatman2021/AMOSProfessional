#ifndef _PROTO_BOARDS_H
#define _PROTO_BOARDS_H

#ifndef __NOLIBBASE__
  extern struct Library *BoardsBase;
#endif

#include <exec/types.h>
#include <clib/boards_protos.h>

#ifdef __GNUC__
  #include <inline/boards.h>
#else
  #include <pragma/boards_lib.h>
#endif

#endif	/*  _PROTO_BOARDS_H  */
