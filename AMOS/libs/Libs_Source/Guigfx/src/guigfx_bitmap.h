#ifndef _GUIGFX_BITMAP_H
#define _GUIGFX_BITMAP_H        1

#include "guigfx_internal.h"

int GetBitMapInfoA(struct BitMap *bm, UWORD displayID, TAGLIST tags);

#if defined(__MORPHOS__) || defined(__amigaos4__)
#define GetBitMapInfo(bm, displayID, tags...) \
        ({unsigned long _tags[] = { tags }; GetBitMapInfoA(bm, displayID, (TAGLIST)_tags);})
#else
int GetBitMapInfo(struct BitMap *bm, UWORD displayID, Tag tag1, ...);
#endif

APTR ReadBitMapA(struct BitMap *bm, UWORD displayID, PALETTE palette,
        int *pixelformat, int *width, int *height, TAGLIST tags);

#if defined(__MORPHOS__) || defined(__amigaos4__)
#define ReadBitMap(bm, displayID, palette, pixelformat, width, height, tags...) \
        ({unsigned long _tags[] = { tags }; ReadBitMapA(bm, displayID, palette, pixelformat, width, height, (TAGLIST)_tags);})
#else
APTR ReadBitMap(struct BitMap *bm, UWORD displayID, PALETTE palette, 
        int *pixelformat, int *width, int *height, Tag tag1, ...);
#endif

#endif
