//
// chunky.library Demo
//
// MODULE: reading of raw chunky data from disk
//
// Public Domain.  (c) 1999 Rosande Limited, all rights reserved.

#ifndef DEMO_LOADCP_H
#define DEMO_LOADCP_H

#include <exec/types.h>

void DEMO_FreeChunky(UBYTE *buf);
void DEMO_FreeRGB32(void *buf);
UBYTE *DEMO_LoadChunky(STRPTR FileName, ULONG Width, ULONG Height);
void *DEMO_LoadRGB32(STRPTR FileName);

#endif
