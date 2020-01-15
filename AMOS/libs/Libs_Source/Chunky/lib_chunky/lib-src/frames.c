/*
** frames.c V1.0
** -------------
**
** Functions to draw some of those pretty XEN-Frames
**
*/
#define   __CONSTLIBBASEDECL__  const
#include  <graphics/gfx.h>
#include  <intuition/screens.h>
#include  <proto/graphics.h>
#include  <math.h>
#include  "chunky.h"

///"void DrawBevelBoxChk( struct ChunkyPort *, UWORD, UWORD, UWORD, UWORD, ULONG )"
void DrawBevelBoxChk( struct ChunkyPort *cp, UWORD x1, UWORD y1, UWORD x2, UWORD y2, ULONG type )
{
	char  bpen = cp->cp_BPen,   // background
				apen = cp->cp_APen,   // text- and shadowpen
				ipen = cp->cp_IPen,   // hshadowpen
				open = cp->cp_OPen;   // shinepen

	cp->cp_OPen = 0;

	SetAPenChk( cp, bpen );
	RectFillChk( cp, x1, y1, x2, y2 );

	SetAPenChk( cp, apen );
	RectChk( cp, x1, y1, x2, y2 );

	SetAPenChk( cp, ipen );


}
///
