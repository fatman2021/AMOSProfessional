//
// chunky.library demo
// MODULE: shows an EasyRequest() requester on our DemoScreen
//
// (c) 1999 Rosande Limited, all rights reserved.
// PUBLIC DOMAIN
//

#include <exec/types.h>
#include <intuition/intuition.h>
#include <pragma/intuition_lib.h>
#include <stdarg.h>

#include "screen.h"

BOOL DEMO_Request(STRPTR Body, STRPTR Gadgets, ...)
{
  va_list myargs;
  struct EasyStruct myes =
  {
    sizeof(struct EasyStruct),
    0,
    "chunky.library Demo Request",
    Body,
    Gadgets,
  };
  BOOL Result;

  if(Gadgets == NULL) myes.es_GadgetFormat = "Okay";

  va_start(myargs, Gadgets);
  Result = EasyRequestArgs(DemoWindow, &myes, 0, (void *)myargs);
  va_end(myargs);

  return(Result);
}
