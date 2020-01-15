//
// chunky.library include and header file
//
// by Andrew "Oondy" King
// (c) 1998 Rosande Limited, all rights reserved.

#ifndef CHUNKY_H
#define CHUNKY_H

#include <exec/memory.h>
#include <exec/libraries.h>
#include <graphics/gfx.h>
#include <graphics/text.h>
#include <graphics/rastport.h>
#include <graphics/view.h>

#define HEAD_CHKP 0x43484B50
#define HEAD_CPCL 0x4350434C

struct cp_Colour32
{
  unsigned long R, G, B;
};

// Filled in by CHK_GetRGB4() (V4)
struct cp_Colour4
{
  unsigned char R, G, B;  // 0-255
};

struct ColoursCP
{
  unsigned long      cpc_Identifier; // == CPCL
  short              cpc_ColourRecord;
  short              cpc_ColourFirst; //  = 0
  struct cp_Colour32 cpc_ColourTable32[256+1];
};

struct ChunkyPort
{
  unsigned long      cp_Identifier; // == CHKP
  unsigned char     *cp_Chunky; // Memory allocated for the chunky data
  unsigned short     cp_cx,      // Draw pen x position in buffer
                     cp_cy;      // Y pen
  unsigned char      cp_APen;    // Foreground pen
  unsigned char      cp_OPen;    // Outline pen
  unsigned char      cp_BPen;    // Background pen
  unsigned char      cp_IPen;    // Shine/shadow pen
  unsigned short     cp_Flags;   // Flags which are the same as graphics/rastport.h

  struct TextFont   *cp_Font;        // Font to use for text rendering
  unsigned char     *cp_TxtChunky;   // Chunky data buffer used for text rendering
  unsigned short     cp_TxHeight;    // Height of the text
  unsigned short     cp_TxBaseline;  // Baseline of the text
  unsigned short     cp_TxStyle;     // Softstyles in graphics/text.h plus these...
  unsigned short     cp_NoFree;      // TRUE if buffer was grabbed from a memory location
  unsigned long      cp_BufSize;     // Number of bytes used for cp_Chunky
  unsigned short     cp_Width,   // Pixel width of buffer
                     cp_Height;  // Pixel height of buffer
  struct ColoursCP  *cp_Colours; // Pointer to colour palete data or NULL if none
  struct ChunkyPort *cp_ScrollCP; // Used for scrolling (V4)
  unsigned long     cp_Reserved[6];
};

// New softstyles
#define FSB_OUTLINE   8
#define FSB_3D        9
#define FSB_WIDE3D    10
#define FSB_EMBOSSED  11
#define FSF_OUTLINE   (1<<FSB_OUTLINE)
#define FSF_3D        (1<<FSB_3D)
#define FSF_WIDE3D    (1<<FSB_WIDE3D)
#define FSF_EMBOSSED  (1<<FSB_EMBOSSED)

struct c2pStruct
{
  struct BitMap *bmap;
  unsigned short startX, startY, width, height;
  unsigned char *ChunkyBuffer;
};

struct p2cStruct
{
  struct BitMap *bmap;
  unsigned short startX, startY, width, height;
  unsigned char *ChunkyBuffer;
};

// Don't use these!  Use CHK_WritePixel()/ReadPixel() to be 100% safe!
#define CHK_SET_PIXEL(cp, p, x, y) \
  *((unsigned char *)((unsigned long )cp->cp_Chunky) + ((cp->cp_Width * (y) )+(x))) = (p)

#define CHK_GET_PIXEL(cp, x, y) \
  *((unsigned char *)((unsigned long )cp->cp_Chunky) + ((cp->cp_Width * (y))+(x)))

#define CHK_GET_PIXEL_POS(cp, x, y)\
  (void *)(((unsigned long)cp->cp_Chunky) + ((cp->cp_Width * (y))+(x)))

#ifdef MAX
#undef MAX
#endif
#define MAX(a,b)  (((a)>(b)) ? (a) : (b))
#ifdef MIN
#undef MIN
#endif
#define MIN(a,b)  (((a)<(b)) ? (a) : (b))
#ifdef ABS
#undef ABS
#endif
#define ABS(x) ((x<0)?(-(x)):(x))

// This structure is private!  Do not use!
struct ChunkyBase
{
  struct Library base;

  unsigned long cb_Reserved[16];
};

// NEW FLAGS FOR VERSION 4+
//
// CHK_FlipChunkyPort() flags
#define CHKFLIP_VERT  1
#define CHKFLIP_HORIZ 2
#define CHKFLIP_BOTH  (CHKFLIP_VERT | CHKFLIP_HORIZ)


#endif

