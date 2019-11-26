//
// chunky.library examples
// MODULE: screen opening and closing commands
//
// http://www.irrelevant.org/~oondy/chunky/
// Public domain.  (c) 1999 Rosande Limited, all rights reserved.

#ifndef DEMO_SCREEN_H
#define DEMO_SCREEN_H

#include <exec/types.h>
#include <intuition/intuition.h>

extern struct Screen *DemoScreen;
extern struct Window *DemoWindow;

BOOL DEMO_OpenScreen(ULONG Width, ULONG Height, ULONG Flags,
 void *ColourTable32);
void DEMO_CloseScreen(void);

#endif
