//
// chunky.library Demo
//
// MODULE: reading of raw chunky data from disk
//
// Public Domain.  (c) 1999 Rosande Limited, all rights reserved.

#include <exec/types.h>
#include <dos/dos.h>
#include <pragma/dos_lib.h>
#include <stdlib.h>
#include <stdio.h>

#include "loadcp.h"

void DEMO_FreeChunky(UBYTE *buf)
{
  if(buf)
  {
    free(buf);
  }
}

void DEMO_FreeRGB32(void *buf)
{
  if(buf) free(buf);
}

UBYTE *DEMO_LoadChunky(STRPTR FileName, ULONG Width, ULONG Height)
{
  BPTR fh;
  ULONG size;
  UBYTE *buf = NULL; int ok = FALSE;

  if(fh = Open(FileName, MODE_OLDFILE))
  {
    size = Width * Height;
    if(buf = (UBYTE *)malloc(size))
    {
      if(Read(fh, buf, size) == size)
      {
        // Done
        ok = TRUE;
      }
    }
    Close(fh);
  }
  if(!ok)
  {
    DEMO_FreeChunky(buf); buf = NULL;
  }
  return(buf);
}

void *DEMO_LoadRGB32(STRPTR FileName)
{
  BPTR fh;
  ULONG size = 3080;
  void *buf = NULL; int ok = FALSE;

  if(fh =  Open(FileName, MODE_OLDFILE))
  {
    if(buf = malloc(size))
    {
      if(Read(fh, buf, size) == size)
      {
        ok = TRUE;
      }
    }
    Close(fh);
  }
  if(!ok)
  {
    DEMO_FreeRGB32(buf);
    buf = NULL;
  }
  return(buf);
}
