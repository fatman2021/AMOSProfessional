
#ifndef _RND_DIVERSITY_H
#define _RND_DIVERSITY_H

#include <utility/tagitem.h>
#include <exec/memory.h>
#include "rnd_palette.h"

LIBAPI LONG RGBArrayDiversityA(const ULONG *rgb, UWORD w, UWORD h, struct TagItem *tags);
LIBAPI LONG ChunkyArrayDiversityA(const UBYTE *chunky, RNDPAL *palette, UWORD w, UWORD h, struct TagItem *tags);

#endif
