
#include <exec/types.h>
#include <intuition/intuition.h>
#include <pragma/graphics_lib.h>

#include "screen.h"
#include <string.h>
#include <stdio.h>

void DEMO_StatusText(STRPTR t)
{
  Move(DemoWindow->RPort, 20, 20);
  if(t)
   Text(DemoWindow->RPort, t, strlen(t))
  else
   SetRast(DemoWindow->RPort, 0);
}

void DEMO_WriteText(STRPTR t, UWORD x, UWORD y)
{
  SetAPen(DemoWindow->RPort, 1);
  Move(DemoWindow->RPort, x, y); Text(DemoWindow->RPort, t, strlen(t));
}

