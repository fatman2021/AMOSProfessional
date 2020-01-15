#ifndef _CHK_DRAW_H
#define _CHK_DRAW_H
#ifndef _EXEC_MEMORY_H
#include  <exec/memory.h>
#endif
#ifndef _GRAPHICS_GFX_H
#include  <graphics/gfx.h>
#endif
#ifndef _GRAPHICS_TEXT_H
#include  <graphics/text.h>
#endif
#ifndef _GRAPHICS_RASTPORT_H
#include  <graphics/rastport.h>
#endif

struct  ChunkyPort
{
// Raw Chunky data
	UBYTE             *cp_Chunky; // Chunky buffer of this ChunkyPort
	UWORD             cp_Width,   // width/Height specification of this
										cp_Height;  // ChunkyPort
	UWORD             cp_cx,      // current position of the
										cp_cy;      // draw pen
	UBYTE             cp_APen;    // current pen
	UBYTE             cp_OPen;    // area outline pen
	UBYTE             cp_BPen;    // background pen for inversvid
	UBYTE             cp_IPen;    // image-pen: mostly used as half shine/shadow pen
	UWORD             cp_Flags;   // use those flags defined in graphics/rastport.h

// structure-entries for Text
	struct TextFont   *cp_Font;       // pointer to the system font
	UBYTE             *cp_TxtChunky;  // pointer to a bitmap used for text rendering
	UWORD             cp_TxHeight;    // Height of the text
	UWORD             cp_TxBaseline;  // Baseline of the text
	UWORD             cp_TxStyle;     // Those old Softstyle and the new ones see below
};

/* New Softstyles, for all fonts */
#define FSB_OUTLINE   8     // use bpen to draw dark outline and jam1 apen
#define FSF_OUTLINE   1<<8
#define FSB_3D        9     // use bpen as dark shadowed pen and
#define FSF_3D        1<<9  // apen as the light one
#define FSB_WIDE3D    10    // like FSB_3D but it's 4pix changed
#define FSF_WIDE3D    1<<10
#define FSB_EMBOSSED  11    // use bpen as dark upper left pen
#define FSF_EMBOSSED  1<<11 // then open +1/+1 and finally apen +1/+1

/*
** To use these functions, you have to assemble the sources (p2c.s|c2p.s) and
** then use hunk2gcc
*/
struct  p2cStruct
{
	struct  BitMap  *bmap;
	UWORD           startx,
									starty,
									width,
									height;
	UBYTE           *ChunkyBuffer;
};

struct  c2pStruct
{
	struct  BitMap  *bmap;
	UWORD           startx,
									starty,
									width,
									height;
	UBYTE           *ChunkyBuffer;
};

/*
** Here are the prototypes for the both asm-functions
*/
void ChunkyToPlanarAsm( struct c2pStruct * );
void PlanarToChunkyAsm( struct p2cStruct * );
#define ChunkyToPlanar( c2p )                       \
({                                                  \
	struct c2pStruct  *str = c2p;                           \
	{                                                 \
		register  struct c2pStruct  *str __asm("a0") = c2p;   \
		__asm volatile ("jbsr _ChunkyToPlanarAsm"       \
		: /* no output */                               \
		: "r"(str)                                       \
		: "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory");  \
	}                                                           \
})
#define PlanarToChunky( p2c )   \
({                                 \
	struct  p2cStruct *str = p2c;   \
	{                                             \
		register  struct p2cStruct  *str __asm("a0") = p2c; \
		__asm volatile ("jbsr _PlanarToChunkyAsm" \
		: /* no output */   \
		: "r"(str)          \
		: "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
	} \
})


#define MAX(a,b)  (((a)>(b)) ? (a) : (b) )
#define MIN(a,b)  (((a)<(b)) ? (a) : (b) )

#define SET_BYTE( cp, p, x, y ) \
	*((UBYTE *)((ULONG )cp->cp_Chunky ) + ((cp->cp_Width * (y) )+(x) )) = (p)

#define GET_BYTE( cp, x, y ) \
	*((UBYTE *)((ULONG )cp->cp_Chunky ) + ((cp->cp_Width * (y))+(x) ) )

// general purpose routines
extern struct ChunkyPort *InitChunkyPort( UWORD, UWORD );
extern void   FreeChunkyPort( struct ChunkyPort * );
extern void   DrawChunkyPort( struct ChunkyPort *, struct RastPort *, UWORD, UWORD );
extern void   DrawChunkyArea( struct ChunkyPort *, struct RastPort *, UWORD, UWORD, UWORD, UWORD );
extern void   InsertChunkyPort( struct ChunkyPort *, struct RastPort *, UWORD, UWORD );
extern struct ChunkyPort *CreateChunkyFromRastPort( struct RastPort *, UWORD, UWORD, UWORD, UWORD );
extern struct ChunkyPort *CreateChunkyFromBitMap( struct BitMap *, UWORD, UWORD, UWORD, UWORD );
extern void   SetAPenChk( struct ChunkyPort *, UBYTE );
extern void   SetOPenChk( struct ChunkyPort *, UBYTE );
extern void   SetBPenChk( struct ChunkyPort *, UBYTE );
extern void   SetABOPenChk( struct ChunkyPort *, UBYTE, UBYTE, UBYTE );
extern void   SetDrMdChk( struct ChunkyPort *, UWORD );
extern void   MoveChk( struct ChunkyPort *, UWORD, UWORD );
extern void   DrawChk( struct ChunkyPort *, UWORD, UWORD );
extern void   SetChkByte( struct ChunkyPort *, UBYTE, UWORD, UWORD );
extern UBYTE  GetChkByte( struct ChunkyPort *, UWORD, UWORD );
extern void   LineChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD );
extern void   RectChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD );
extern void   RectFillChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD );
extern void   SetChunky( struct ChunkyPort *, UBYTE );
extern void   ClearChunky( struct ChunkyPort * );

// general text routines
extern void  SetFontChk( struct ChunkyPort *, struct TextFont * );
extern long  TextLengthChk( struct ChunkyPort *, char *, int );
extern void  TextLChk( struct ChunkyPort *, char *, int );
extern void  TextChk( struct ChunkyPort *, char * );
extern void  TextCenterChk( struct ChunkyPort *, char *, UWORD );
extern void  TextFChk( struct ChunkyPort *, char *, ... );
extern ULONG SetSoftStyleChk( struct ChunkyPort *, ULONG );

#endif
