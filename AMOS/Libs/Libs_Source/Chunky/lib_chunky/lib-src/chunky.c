/*
** chunky.c V1.0
** -------------
**
** Functions to init, render in, convert and free a chunky port
**
** To have a bottleneck, compile with USE_AMIGA_OS defined ;)
**
** TODO:
** I want to implement those pretty BltBitMap() functions
** with and without a mask.
*/
#define   __CONSTLIBBASEDECL__  const
#include  <graphics/gfx.h>
#include  <graphics/GfxBase.h>
#include  <proto/graphics.h>
#include  <proto/exec.h>
#include  <math.h>
#include  "chunky.h"

// Set this to compile a 100% GfxCard compatible renderlib
// But if you only want to use Amiga-Features, DO NOT set this,
// because it's ten times as slow as if it's not set
//
// COMPARE: Be GfxCard compatible for 2.2769 seconds for a 640x480x8 display
// OR     : Be fast (0.23 seconds ) and use this only for native amigas.
//#define USE_AMIGA_OS

///"int sptst( ... )"
static inline int sptst( float x )
{
	int ret = 0;

	if( x < 0 )       ret = -1;
	else if( x > 0 )  ret = 1;
	else              ret = 0;
	return( ret );
}
///
///"struct ChunkyPort *InitChunkyPort( UWORD, UWORD )"
struct ChunkyPort *InitChunkyPort( UWORD sx, UWORD sy )
{
	// Allocate and initialize the ChunkyPort for rendering
	// operations

	struct  ChunkyPort  *cp;
	if( cp = AllocVec( sizeof( struct ChunkyPort ) + ( sx * sy ), MEMF_ANY|MEMF_CLEAR ) )
	{
		/* Init the pointers */
		cp->cp_Chunky = (UBYTE *)((ULONG )cp + sizeof( struct ChunkyPort ) );

		cp->cp_Width  = sx;
		cp->cp_Height = sy;
		SetDrMdChk( cp, JAM1 );
		SetABOPenChk( cp, 1, 0, 0 );

		return( cp );
	}
	return(NULL);
}
///
///"void FreeChunkyPort( struct ChunkyPort * )"
void FreeChunkyPort( struct ChunkyPort *cp )
{
	// Frees allocated ChunkyPort
	if( cp->cp_TxtChunky ) FreeVec( cp->cp_TxtChunky );
	if( cp )    FreeVec( cp );
}
///
///"void DrawChunkyPort( struct ChunkyPort *, struct RastPort *, UWORD, UWORD )"
void DrawChunkyPort( struct ChunkyPort *cp, struct RastPort *rp, UWORD x, UWORD y )
{
	// This routine blasts the chunky-buffer over the given rastport at
	// given x/y coordinates
	// Compile this lib with USE_AMIGA_OS defined and you'll get
	// a 100 percent GfxCard compatible lib

	#ifdef USE_AMIGA_OS
	struct  BitMap    *bm;
	struct  RastPort  rpt;
	struct  GfxBase *gb = GfxBase;

	// Test for V40
	if( gb->LibNode.lib_Version >= 40 ){
		WriteChunkyPixels( rp, x, y, x+cp->cp_Width-1, y+cp->cp_Height-1, cp->cp_Chunky, cp->cp_Width );

	} else {
		if( bm = AllocBitMap( cp->cp_Width, 1, 8, BMF_CLEAR, rp->BitMap ) ){
			CopyMem( rp, &rpt, sizeof( struct RastPort ) );
			rpt.Layer  = NULL;
			rpt.BitMap = bm;

			WritePixelArray8( rp, x, y, x+cp->cp_Width-1, y+cp->cp_Height-1, cp->cp_Chunky, &rpt );
			FreeBitMap( bm );
		}
	}
	#else
	struct  c2pStruct c2p;

	c2p.bmap    = rp->BitMap;
	c2p.startx  = x;
	c2p.starty  = y;
	c2p.width   = cp->cp_Width;
	c2p.height  = cp->cp_Height;
	c2p.ChunkyBuffer  = cp->cp_Chunky;

	ChunkyToPlanar( &c2p );
	#endif
}
///
///"void DrawChunkyArea( struct ChunkyPort *, struct RastPort *, UWORD, UWORD, UWORD, UWORD )"
void DrawChunkyArea( struct ChunkyPort *cp, struct RastPort *rp, UWORD x, UWORD y, UWORD sizex, UWORD sizey )
{
	// This routine blasts the chunky-buffer over the given rastport at
	// given x/y coordinates and given size
	// Compile this lib with USE_AMIGA_OS defined and you'll get
	// a 100 percent GfxCard compatible lib

	struct  c2pStruct c2p;
	struct  BitMap    *bm;
	struct  RastPort  rpt;

	#ifdef USE_AMIGA_OS
	if( bm = AllocBitMap( cp->cp_Width, 1, 8, BMF_CLEAR, rp->BitMap ) ){
		CopyMem( rp, &rpt, sizeof( struct RastPort ) );
		rpt.Layer  = NULL;
		rpt.BitMap = bm;

		WritePixelArray8( rp, x, y, x+sizex-1, y+sizey-1, cp->cp_Chunky, &rpt );
		FreeBitMap( bm );
	}
	#else
	c2p.bmap    = rp->BitMap;
	c2p.startx  = x;
	c2p.starty  = y;
	c2p.width   = sizex;
	c2p.height  = sizey;
	c2p.ChunkyBuffer  = cp->cp_Chunky;

	ChunkyToPlanar( &c2p );
	#endif
}
///
///"void InsertChunkyPort( struct ChunkyPort *, struct RastPort *, UWORD, UWORD )"
void InsertChunkyPort( struct ChunkyPort *cp, struct RastPort *rp, UWORD x, UWORD y )
{
	// This function inserts the ChunkyPort into the RastPort at the given
	// coordinates
	// This insertion is done that all bytes that are 0 (ie. Background ) are not
	// set in the destination rport

	struct  p2cStruct p2c;
	struct  ChunkyPort  *tmp;
	UBYTE   *src, *dst;
	ULONG   size = cp->cp_Height * cp->cp_Width;
	ULONG   i=0;
	UBYTE   p;

	// First allocate a temporary ChunkyPort
	if( tmp = InitChunkyPort( cp->cp_Width, cp->cp_Height ) ){

		// convert the destination into chunkyPixels
		p2c.bmap    = rp->BitMap;
		p2c.startx  = x;
		p2c.starty  = y;
		p2c.width   = cp->cp_Width;
		p2c.height  = cp->cp_Height;
		p2c.ChunkyBuffer  = tmp->cp_Chunky;

		PlanarToChunky( &p2c );

		// copy all pens from src which are not 0 to dst
		src = cp->cp_Chunky;
		dst = tmp->cp_Chunky;

		while( i<size )
		{
			p = *src++;
			if( p ) *dst++ = p;
			else    dst++;
			i++;
		}

		// finally re-convert the temporary chunkyBuffer
		ChunkyToPlanar( (struct c2pStruct *)&p2c );

		// and free temporary buffer
		FreeChunkyPort( tmp );
	}
}
///
///"struct ChunkyPort *CreateChunkyFromRastPort( struct RastPort *, UWORD, UWORD, UWORD, UWORD )"
struct ChunkyPort *CreateChunkyFromRastPort( struct RastPort *rp, UWORD x, UWORD y, UWORD sx, UWORD sy )
{
	struct  ChunkyPort  *cp = NULL;
	struct  p2cStruct p2c;

	// First create the ChunkyPort
	if( cp = InitChunkyPort( sx, sy ) ){

		// Then convert the given rectangle into a ChunkyBuffer
		p2c.bmap    = rp->BitMap;
		p2c.startx  = x;
		p2c.starty  = y;
		p2c.width   = sx;
		p2c.height  = sy;
		p2c.ChunkyBuffer  = cp->cp_Chunky;

		PlanarToChunky( &p2c );

		return( cp );
	}
	return(NULL);
}
///
///"struct ChunkyPort *CreateChunkyFromBitMap( struct BitMap *, UWORD, UWORD, UWORD, UWORD )"
struct ChunkyPort *CreateChunkyFromBitMap( struct BitMap *bm, UWORD x, UWORD y, UWORD sx, UWORD sy )
{
	struct  ChunkyPort  *cp = NULL;
	struct  p2cStruct p2c;

	// First create the ChunkyPort
	if( cp = InitChunkyPort( sx, sy ) ){

		// Then convert the given rectangle into a ChunkyBuffer
		p2c.bmap    = bm;
		p2c.startx  = x;
		p2c.starty  = y;
		p2c.width   = sx;
		p2c.height  = sy;
		p2c.ChunkyBuffer  = cp->cp_Chunky;

		PlanarToChunky( &p2c );

		return( cp );
	}
	return(NULL);
}
///
///"void SetDrMdChk( ... )"
void SetDrMdChk( struct ChunkyPort *cp, UWORD flags )
{
	cp->cp_Flags = flags;
}
///
///"void SetAPenChk( ... )"
inline void SetAPenChk(struct ChunkyPort *cp, UBYTE p )
{
	cp->cp_APen = p;
}
///
///"void SetOPenChk( ... )"
inline void SetOPenChk( struct ChunkyPort *cp, UBYTE p )
{
	cp->cp_OPen = p;
}
///
///"void SetABOPenChk( ... )"
inline void SetABOPenChk( struct ChunkyPort *cp, UBYTE a, UBYTE b, UBYTE o )
{
	cp->cp_APen = a;
	cp->cp_BPen = b;
	cp->cp_OPen = o;
}
///
///"void MoveChk( ... )"
inline void MoveChk( struct ChunkyPort *cp, UWORD x, UWORD y )
{
	// Move(rp,x,y) - replacement
	cp->cp_cx = x;
	cp->cp_cy = y;
}
///
///"void SetChkByte( ... )"
inline void SetChkByte( struct ChunkyPort *cp, UBYTE p, UWORD x, UWORD y )
{
	// WritePixel( rp, pen, x, y ) - replacement
	SET_BYTE( cp, p, x, y );
}
///
///"UBYTE GetChkByte( ... )"
inline UBYTE GetChkByte( struct ChunkyPort *cp, UWORD x, UWORD y )
{
	// ReadPixel(rp, x, y ) replacement
	return(GET_BYTE( cp, x, y ));
}
///
///"void DrawChk( struct ChunkyPort *, UWORD, UWORD )"
inline void DrawChk( struct ChunkyPort *cp, UWORD x2, UWORD y2 )
{
	// Draw(rp, x, y ) replacement with optimized check for
	// horizontal/vertical lines
	const char  p = cp->cp_APen;
	UBYTE   *chk = cp->cp_Chunky;

	UWORD   x1 = cp->cp_cx;
	UWORD   y1 = cp->cp_cy;
	int     i, change, s1, s2;
	LONG    x, y, dx, dy, e;

	x = x1;
	y = y1;

	/* first check, if we should draw a horizontal or vertical line */
	if( y1 == y2 ){
		// We should draw horizontalally
		// Calculate start address and then move the bytes into the buffer
		x = MIN(x1, x2 );
		y = MAX(x1, x2 );
		chk = ((UBYTE *)((ULONG )chk ) + ((cp->cp_Width * y1 ) + x ) );

		for( i = x; i < y; i++ ){
			*chk++ = p;
		}
	} else if( x1 == x2 ){
		// We should draw vertically
		// Calculate start address and then move the bytes into the buffer
		x = MIN(y1, y2 );
		y = MAX(y1, y2 );
		chk = ((UBYTE *)((ULONG )chk ) + ((cp->cp_Width * x ) + x1 ) );

		for( i = x; i < y; i++ ){
			*chk = p;
			chk += cp->cp_Width;
		}
	}
	else{
		/* It is a line which can't be drawn using this above */
		dx  = abs( (float )(x2-x1) );   // Number of x-moves
		dy  = abs( (float )(y2-y1) );   // Number of y-moves
		s1  = sptst( x2 - x1 );         // Sign for x-direction
		s2  = sptst( y2 - y1 );         // sign for y-direction

		/* draw in which direction ? */
		if( dy > dx )
		{
			dy = dx;
			dx = abs( (float )(y2 - y1 ) );
			change = 1;
		}
		else{
			change = 0;
		}

		e = 2 * dy - dx;

		/* Draw the line */
		for( i = 1; i<=dx; i++ )
		{
			SET_BYTE( cp, p, x, y );

			while( e>=0 )
			{
				if( change ){
					x = x+s1;
				}
				else{
					y = y+s2;
				}
				e = e - 2 * dx;
			}
			if( change ){
				y = y+s2;
			}
			else{
				x = x+s1;
			}
			e = e + 2*dy;
		}
	}
	/* Set the endposition to the new current position */
	MoveChk( cp, x2, y2 );
}
///
///"void LineChk( ... )"
inline void LineChk( struct ChunkyPort *cp, UWORD x1, UWORD y1, UWORD x2, UWORD y2 )
{
	// Draw a line into the chunky buffer
	MoveChk( cp, x1, y1 );
	DrawChk( cp, x2, y2 );
}
///
///"void RectChk( struct ChunkyPort *, UWORD, UWORD; UWORD, UWORD )"
void RectChk( struct ChunkyPort *cp, UWORD x1, UWORD y1, UWORD x2, UWORD y2 )
{
	// Draw a box into the chunky-buffer
	MoveChk( cp, x1, y1 );
	DrawChk( cp, x2, y1 );
	DrawChk( cp, x2, y2 );
	DrawChk( cp, x1, y2 );
	DrawChk( cp, x1, y1 );
}
///
///"void RectFillChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD )"
void RectFillChk( struct ChunkyPort *cp, UWORD x1, UWORD y1, UWORD x2, UWORD y2 )
{
	// Draw a filled box at the specified position
	// If the OPen is set draw a frame around it
	UWORD rx1=x1, ry1=y1, rx2=x2, ry2=y2;
	int   i,x,y;

	/* Do we have the outline pen set ? */
	if( cp->cp_OPen ){
		int oapen = cp->cp_APen;

		cp->cp_APen = cp->cp_OPen;
		RectChk( cp, x1, y1, x2, y2 );
		cp->cp_APen = oapen;
		rx1++;
		rx2--;
		ry1++;
		ry2--;
	}

	/* Draw the filled box */
	for( i = ry1; i < ry2; i++ ){
		LineChk( cp, rx1, i, rx2, i );
	}
}
///
///"void DrawEllipseChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD )"
void DrawEllipseChk( struct ChunkyPort *cp, UWORD mx, UWORD my, UWORD rx, UWORD ry )
{
	double x, y, i, step=0.02;
	int    x1, y1, x2, y2, x3, y3, x4, y4;
	const char   apen = cp->cp_APen;

	if( rx == 0 || ry == 0 )  return;

	for( i=PI/2; i>0; i-=step ){
		x = cos(i)*rx;
		y = sin(i)*ry;

		x2 = (int)x;
		y2 = (int)-y;
		x3 = (int)-x;
		y3 = (int)-y;
		x4 = (int)-x;
		y4 = (int)y;

		SET_BYTE( cp, apen, mx + (int)x, my + (int)y );
		SET_BYTE( cp, apen, mx + x2, my + y2 );
		SET_BYTE( cp, apen, mx + x3, my + y3 );
		SET_BYTE( cp, apen, mx + x4, my + y4 );
	}
}
///
///"void ClearChunky( struct ChunkyPort * )"
void ClearChunky( struct ChunkyPort *cp )
{
	// SetRast( rp, 0 ) replacement
	UBYTE *buf = cp->cp_Chunky;
	ULONG size = cp->cp_Width * cp->cp_Height;
	ULONG  i=0;

	while( i < size ){
		*buf++ = 0;
		i++;
	}
}
///
///"void SetChunky( struct ChunkyPort *, UBYTE )"
void SetChunky( struct ChunkyPort *cp, UBYTE p )
{
	// SetRast( rp, pen ) replacement
	UBYTE *buf = cp->cp_Chunky;
	ULONG size = cp->cp_Width * cp->cp_Height;
	ULONG  i=0;

	while( i < size ){
		*buf++ = p;
		i++;
	}
}
///

