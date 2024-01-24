#define __CONSTLIBBASEDECL__  const
#include  <proto/graphics.h>
#include  <proto/exec.h>
#include  <dos/dos.h>
#include  "chunky.h"

///"some static prototypes"
static void text_softstyle( struct ChunkyPort *, char *, int );
static void text_chk( struct ChunkyPort *, char *, int );
static void text_w3d( struct ChunkyPort *, char *, int );
static void text_3d ( struct ChunkyPort *, char *, int );
static void text_ol ( struct ChunkyPort *, char *, int );
static void text_emb( struct ChunkyPort *, char *, int );
static void text_bld( struct ChunkyPort *, char *, int );
///
///"static inline void text_chk( struct ChunkyPort *, char *, int )"
static inline char get_pen( const char *cb, long bpr, long x, long y )
{
	return( *((UBYTE *)((ULONG )cb ) + ( ( bpr * y ) + x ) ) );
}

static void text_chk( struct ChunkyPort *cp, char *text, int length )
{
	// Better Text(rp, txt, txtlen) - replacement
	// Init all those static variables

	struct TextFont *tf = cp->cp_Font;
	char  dpen = cp->cp_APen;
	int   sx, sy, dx, dy, x, y;
	UBYTE *src = cp->cp_TxtChunky;
	WORD  *cloc = tf->tf_CharLoc;
	UWORD *cspa = tf->tf_CharSpace;
	UWORD *ckern= tf->tf_CharKern;
	int   cwidth, cx, spa, kern;
	int   bpr  = tf->tf_Modulo * 8;
	char  c, p;

	if( tf == NULL )          return;
	if( strlen( text ) == 0 ) return;

	while( length-- )
	{
		c = *text++;
		// Is the character in the CharLocation ?
		// If not, set it to this 'unknown' amiga character
		if( ( c < tf->tf_LoChar || c > tf->tf_HiChar ) )
			c = tf->tf_HiChar + 1;

		// Get real character offset
		// Ie.: if loChar == 'A' then it's the first Character
		// in each offset-table
		c -= tf->tf_LoChar;
		cx     = cloc[ c*2 ];
		cwidth = cloc[ c*2+1];

		// NOTE: CharSpace[] and CharKern[] do not exist on some fixed-width-fonts
		spa    = cspa ? cspa[c] : tf->tf_XSize;
		kern   = ckern ? ckern[c] : 0;

		// Now we have the following vars set:
		// cx     = #byte-offset of first character-pixel
		// cwidth = real width of character
		// spa    = spacing ( rect of printed character )
		// kern   = kerning ( start of printed char. into those spacing )

		sx = cp->cp_cx + kern;
		cp->cp_cx += spa;

		sy = cp->cp_cy - cp->cp_TxBaseline;

		// Test the various font behavior
		if( cp->cp_Flags == JAM1 ){

			for( y = 0; y < tf->tf_YSize; y++ )
			{
				dx = sx;
				for( x = cx; x < cx + cwidth; x++ )
				{
					p = get_pen( src, bpr, x, y );
					// only set dest if p != 0
					if( p ) SET_BYTE( cp, dpen, dx, sy+y );
					dx++;
				}
			}
		}
		else if( cp->cp_Flags == JAM2 ){
			for( y = 0; y < tf->tf_YSize; y++ )
			{
				dx = sx;
				for( x = cx; x < cx + cwidth; x++ )
				{
					p = get_pen( src, bpr, x, y );
					// if 0x00 -> bpen
					// if 0x01 -> apen
					SET_BYTE( cp, p?dpen:cp->cp_BPen, dx++, sy+y );
				}
			}
		}
		else if( cp->cp_Flags == INVERSVID ){
			for( y = 0; y < tf->tf_YSize; y++ )
			{
				dx = sx;
				for( x = cx; x < cx + cwidth; x++ )
				{
					p = get_pen( src, bpr, x, y );
					// if 0x00 -> apen
					// if 0x01 -> bpen
					SET_BYTE( cp, p?cp->cp_BPen:dpen, dx++, sy+y );
				}
			}
		}
	}
}
///
///"static inline text_bld( struct ChunkyPort *, char *, int )"
static void text_bld( struct ChunkyPort *cp, char *t, int l)
{
	// draw text bold - twice w/ shifted and or'ed
	int o_f = cp->cp_Flags;
	int x = cp->cp_cx, y = cp->cp_cy;

	// needed!
	cp->cp_Flags = JAM1;
	text_chk( cp, t, l );
	MoveChk( cp, x+1, y );
	text_chk( cp, t, l );
	cp->cp_Flags = o_f;
}
///
///"text_w3d"
static void text_w3d( struct ChunkyPort *cp, char *t, int l )
{
	// Use bpen as shadow and apen as textpen
	int  x = cp->cp_cx;
	int  y = cp->cp_cy;
	char bpen = cp->cp_BPen;
	char apen = cp->cp_APen;

	SetAPenChk( cp, bpen );

	// Draw dark shadow of 3d
	text_bld( cp, t, l );
	MoveChk( cp, x-2, y-2 );

	// draw light pen of 3d
	SetAPenChk( cp, apen );
	text_chk( cp, t, l );
}
///
///"text_3d"
static void text_3d ( struct ChunkyPort *cp, char *t, int l )
{
	// Use bpen as shadow and apen as textpen
	int  x = cp->cp_cx;
	int  y = cp->cp_cy;
	char bpen = cp->cp_BPen;
	char apen = cp->cp_APen;

	SetAPenChk( cp, bpen );

	if( cp->cp_TxStyle & FSF_BOLD ){
		// Draw dark shadow of 3d
		text_bld( cp, t, l );
		MoveChk( cp, x-2, y-2 );

		// draw light pen of 3d
		SetAPenChk( cp, apen );
		text_bld( cp, t, l );

	} else {
		// Draw dark shadow of 3d
		text_chk( cp, t, l );
		MoveChk( cp, x-1, y-1 );

		// draw light pen of 3d
		SetAPenChk( cp, apen );
		text_chk( cp, t, l );
	}
}
///
///"text_ol"
static void text_ol ( struct ChunkyPort *cp, char *t, int l)
{
	UWORD xpos, ypos;
	int   x = cp->cp_cx;
	int   y = cp->cp_cy;
	char  open = cp->cp_OPen;
	char  apen = cp->cp_APen;
	int   o_f = cp->cp_Flags;

	cp->cp_Flags = JAM1;

	if( cp->cp_TxStyle & FSF_BOLD ){
		SetAPenChk( cp, open );
		for( ypos = y; ypos < y+3; ypos++ ){
			for( xpos = x; xpos < x+3; xpos++){
				MoveChk( cp, xpos, ypos );
				text_bld( cp, t, l );
			}
		}
		SetAPenChk( cp, apen );
		MoveChk( cp, x+1, y+1 );
		text_bld( cp, t, l );
	}
	else{
		SetAPenChk( cp, open );
		for( ypos = y; ypos < y+3; ypos++ ){
			for( xpos = x; xpos < x+3; xpos++){
				MoveChk( cp, xpos, ypos );
				text_chk( cp, t, l );
			}
		}
		SetAPenChk( cp, apen );
		MoveChk( cp, x+1, y+1 );
		text_chk( cp, t, l );
	}
	cp->cp_Flags = o_f;
}
///
///"text_emb"
static void text_emb( struct ChunkyPort *cp, char *t, int l )
{
	// use: - apen as textpen 0/0
	//      - bpen as hshadowpen -1/-1
	//      - open as shinepen +1/+1
	int   x = cp->cp_cx;
	int   y = cp->cp_cy;
	char  open = cp->cp_OPen;
	char  apen = cp->cp_APen;
	char  bpen = cp->cp_BPen;
	int   o_f = cp->cp_Flags;

	cp->cp_Flags = JAM1;

	if( cp->cp_TxStyle & FSF_BOLD ){
		SetAPenChk( cp, bpen );
		MoveChk( cp, x-1, y-1 );
		text_bld( cp, t, l );

		SetAPenChk( cp, open );
		MoveChk( cp, x+1, y+1 );
		text_bld( cp, t, l );

		SetAPenChk( cp, apen );
		MoveChk( cp, x, y );
		text_bld( cp, t, l );
	}
	else{
		SetAPenChk( cp, bpen );
		MoveChk( cp, x-1, y-1 );
		text_chk( cp, t, l );

		SetAPenChk( cp, open );
		MoveChk( cp, x+1, y+1 );
		text_chk( cp, t, l );

		SetAPenChk( cp, apen );
		MoveChk( cp, x, y );
		text_chk( cp, t, l );
	}
	cp->cp_Flags = o_f;
}
///
///"static inline void text_softstyle( struct ChunkyPort *, char *, int )"
static inline void text_softstyle( struct ChunkyPort *cp, char *text, int len )
{
	// draw the text with the softstyle set
	// possible combinations of the softstyle:
	//    FSF_BOLD|FSF_3D
	//    FSF_BOLD|FSF_OUTLINE
	//    FSF_BOLD|FSF_EMBOSSED

	// First test the normal possibilities
	if( cp->cp_TxStyle == FS_NORMAL ){
		text_chk( cp, text, len );
	} else if( cp->cp_TxStyle == FSF_BOLD ){
		text_bld( cp, text, len );

	// Test the possible combinations
	} else if( cp->cp_TxStyle & FSF_3D ){
		text_3d(cp, text, len );
	} else if( cp->cp_TxStyle & FSF_WIDE3D ){
		text_w3d( cp, text, len );
	} else if( cp->cp_TxStyle & FSF_OUTLINE ){
		text_ol ( cp, text, len );
	} else if( cp->cp_TxStyle & FSF_EMBOSSED ){
		text_emb( cp, text, len );
	} else {
		text_chk( cp, text, len );
	}
}
///
///"void SetFontChk( struct ChunkyPort *, struct TextFont *)"
void SetFontChk( struct ChunkyPort  *cp, struct TextFont *tf )
{
	// SetFont(rp, font ) - replacement

	// Same font? -> return
	if( cp->cp_Font == tf ) return;
	if( tf == NULL )        return;

	// Init ChunkyPort structure
	cp->cp_Font       = tf;
	cp->cp_TxHeight   = tf->tf_YSize;
	cp->cp_TxBaseline = tf->tf_Baseline;

	// Set soft style back to normal
	SetSoftStyleChk( cp, FS_NORMAL );

	// Free old TxtChunky
	if(cp->cp_TxtChunky )   FreeVec( cp->cp_TxtChunky );
	cp->cp_TxtChunky = NULL;

	// Install new TxtChunky
	if( cp->cp_TxtChunky = AllocVec( 8*tf->tf_YSize * tf->tf_Modulo, MEMF_CLEAR|MEMF_ANY ) )
	{
		// Convert tf->tf_CharLoc to an array of ChunkyBytes
		struct  BitMap    *bm;
		struct  p2cStruct p2c;
		BPTR    fh;

		if( bm = AllocBitMap( tf->tf_Modulo * 8, tf->tf_YSize, 1, BMF_CLEAR, NULL ) )
		{
			CopyMem( tf->tf_CharData, bm->Planes[0], tf->tf_YSize * tf->tf_Modulo );
			p2c.ChunkyBuffer = cp->cp_TxtChunky;
			p2c.startx       = 0;
			p2c.starty       = 0;
			p2c.bmap         = bm;
			p2c.width        = ( tf->tf_Modulo * 8 );
			p2c.height       = tf->tf_YSize;
			PlanarToChunky( &p2c );

			FreeBitMap( bm );
		}
	}
}
///
///"ULONG SetSoftStyleChk( struct ChunkyPort *, ULONG, ULONG )"
ULONG SetSoftStyleChk( struct ChunkyPort *cp, ULONG newStyle )
{
	// Since we currently do not support some of the system
	// default soft styles, we must return real soft style set
	// List of currently unsupported flags:
	//    FSF_ITALIC
	//    FSF_UNDERLINED
	ULONG realStyle = newStyle;

	if( newStyle & FSF_ITALIC )     realStyle = realStyle & ~FSF_ITALIC;
	if( newStyle & FSF_UNDERLINED ) realStyle = realStyle & ~FSF_UNDERLINED;

	cp->cp_TxStyle = realStyle;
	return( realStyle );
}
///
///"long TextLengthChk( struct ChunkyPort *, char *, int )"
long TextLengthChk( struct ChunkyPort *cp, char *text, int length )
{
	// TextLength( rport, text, tlen )  -  replacement
	// returns expected pixelwidth of the given text
	// NEW: It takes the several SoftStyles into account
	struct TextFont *tf = cp->cp_Font;
	long  plen = 0;
	UWORD *cspa = tf->tf_CharSpace;
	int   lst = cspa ? 1 : 0;
	char  c;

	// simple safety check
	if( tf == NULL )          return;
	if( strlen( text ) == 0 ) return;

	while( length-- )
	{
		c = *text++;
		// Is the character in the CharLocation ?
		// If not, set it to this 'unknown' amiga character
		if( ( c < tf->tf_LoChar || c > tf->tf_HiChar ) )
			c = tf->tf_HiChar + 1;

		// Get real character offset
		// Ie.: if loChar == 'A' then it's the first Character
		// in each offset-table
		c -= tf->tf_LoChar;
		plen  += cspa ? cspa[c] : tf->tf_XSize;
	}
	plen += lst;

	// This is the expected length of the string for FS_NORMAL
	// Look into the StyleFlags set to get the REAL width
	if( cp->cp_TxStyle == FSF_BOLD )    return(plen+1);
	if( cp->cp_TxStyle & FSF_BOLD  )    plen+=1;
	if( cp->cp_TxStyle & FSF_OUTLINE )  plen+=3;
	if( cp->cp_TxStyle & FSF_EMBOSSED)  plen+=2;
	return(plen);
}
///
///"void TextChk( struct ChunkyPort *, char * )"
void TextChk( struct ChunkyPort *cp, char *text )
{
	// simple Text( ... ) replacement
	text_softstyle( cp, text, strlen( text ) );
}
///
///"void TextLChk( struct ChunkyPort *, char *, int )"
void TextLChk( struct ChunkyPort *cp, char *text, int length )
{
	// simple Text( rport, text, len ) - replacement
	text_softstyle( cp, text, length );
}
///
///"void TextCenterChk( struct ChunkyPort *, char *, UWORD )"
void TextCenterChk( struct ChunkyPort *cp, char *text, UWORD y )
{
	// Center text horizontally
	// NOTE:  This clips the text horizontally if it does not fit
	int  l = strlen( text );
	long sx,x;

	sx = TextLengthChk( cp, text, l );
	x  = ( cp->cp_Width - sx ) / 2;
	if( x > 0 ){
		MoveChk( cp, x, y );
		text_softstyle( cp, text, l );
	}
	else {
		// The given string does not fit the entire ChunkyPort
		// Loop until the Text fits
		while( sx > cp->cp_Width ){
			sx = TextLengthChk( cp, text, --l );
		}
		x = ( cp->cp_Width - sx ) / 2;
		MoveChk( cp, x, y );
		text_softstyle( cp, text, l );
	}
}
///
///"void TextFChk( struct ChunkyPort *, char *, ... )"
#define RAWDOFMT_COPY (void (*))"\x16\xc0\x4e\x75"

void TextFChk( struct ChunkyPort *cp, char *format, ... )
{
	// Replacement for:
	// sprintf(buffer, "bla %s", "hi" );
	// Text( rport, buffer, strlen( buffer ) );
	char  buffer[256];

	RawDoFmt( format, &format+1, RAWDOFMT_COPY, buffer );
	text_softstyle( cp, buffer, strlen( buffer));
}
///

