/*
** test.c
**
** Tests the various gfx functions and prints the execution time
**
** compile me with
** gcc -noixemul -s -m68020 -O2 -o test test.c -lchunky -lm
*/
#define __CONSTLIBBASEDECL__  const
#include  <exec/execbase.h>
#include  <intuition/screens.h>
#include  <graphics/gfx.h>
#include  <hardware/custom.h>
#include  <hardware/cia.h>
#include  <hardware/dmabits.h>

#include  <proto/exec.h>
#include  <proto/intuition.h>
#include  <proto/graphics.h>

#include  <stdlib.h>
#include  <time.h>

#include  "../lib-src/chunky.h"

#ifndef __GNUC__
extern  __far struct CIA    ciaa;
extern  __far struct CIA    ciab;
extern  __far struct Custom custom;
#else
extern struct CIA     ciaa;
extern struct CIA     ciab;
extern struct Custom  custom;
#endif

#define SX  640
#define SY  480
#define CX  640
#define CY  480

struct  Screen      *scr;
struct  RastPort    *rp;
struct  ChunkyPort  *cp;

/*///"Time functions"*/
void PTimeStart( BOOL dmaoff )
{
	WaitTOF();
	Forbid();
	Disable();

	if( dmaoff )  custom.dmacon = DMAF_MASTER;

	ciab.ciacra = 0;      /* Timer a und b stoppen */
	ciab.ciacrb = 0;

	ciab.ciatalo= 0xff;    /* TimerA = $ffff */
	ciab.ciatahi= 0xff;

	ciab.ciatblo= 0xff;    /* TimerB = $ffff */
	ciab.ciatbhi= 0xff;

	/* TimerB start mit INMODE1 set, da 32bit-Zähler */
	ciab.ciacrb = CIACRBF_START|CIACRBF_INMODE1;

	/* TimerA start normal */
	ciab.ciacra = CIACRAF_START;

}

ULONG PTimeStop( void )
{
	ULONG cycles;

	ciab.ciacra = 0;  /* Timer a und b stoppen */
	ciab.ciacrb = 0;

	cycles =  0xffffffff -
						( ( ciab.ciatalo ) + ( ciab.ciatahi * 0x100 ) +
							( ciab.ciatblo * 0x10000 ) + ( ciab.ciatbhi * 0x1000000 ) );

	custom.dmacon = DMAF_SETCLR | DMAF_MASTER;

	Enable();
	Permit();
	return( cycles );
}

void PPrintTime( char *head, ULONG val )
{
	struct ExecBase *sb = SysBase;
	ULONG correct;
	ULONG realtime;
	ULONG etime = sb->ex_EClockFrequency;

	/* Calculate real time needed */
	PTimeStart( 0 );
	correct = PTimeStop();

	realtime = val - correct;

	printf( "Elapsed time for function %s: %f sec. \n", (LONG )head,
	(float )((float )realtime/(float )etime ) );
}
/*///*/
///"Test functions"
void lines1_chk( void )
{
	int i;
	// vertical lines
	PTimeStart( 0 );

	for( i = 0; i<CX; i++ ){
		SetAPenChk( cp, i%255 );
		LineChk( cp, i, 0, i, CY-1 );
	}
	PPrintTime( "v_lines_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );

}
void lines2_chk( void )
{
	int i;
	// horizontal lines
	PTimeStart( 0 );

	for( i = 0; i<CY; i++ ){
		SetAPenChk( cp, i%255 );
		LineChk( cp, 0, i, CX-1, i );
	}
	PPrintTime( "h_lines_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );

}
void lines3_chk( void )
{
	int i;
	PTimeStart( 0 );
	// lines spread
	for( i = 0; i<CY; i++ ){
		SetAPenChk( cp, i%255 );
		LineChk( cp, 0, 0, CX-1, i );
	}
	PPrintTime( "s_lines_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );
}
void rect1_chk( void )
{
	// draw 256 filled boxes with random x/y-positions
	int i;
	int sx = 32;
	int sy = 32;
	int x, y;
	srand( (unsigned )time(NULL));
	PTimeStart(0);

	for( i= 0; i<256; i++ ){
		SetAPenChk( cp, i%255);
		sx= 4+ (rand() % 128);
		sy= 4+ (rand() % 128);
		x = rand() % (640-sx);
		y = rand() % (480-sy);
		RectFillChk( cp, x, y, x+sx, y+sy );
	}
	PPrintTime( "rect1_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );

}

void circle_chk( void )
{
	// draw 256 outlined circles with color fadeing
	int i;
	int sx = 64;
	int sy = 64;
	int x, y;

	srand( (unsigned )time(NULL));
	PTimeStart(0);

	for( i= 0; i<256; i++ ){
		SetAPenChk( cp, i%255);
		x = sx+rand() % (640-(2*sx));
		y = sy+rand() % (480-(2*sy));
		DrawEllipseChk( cp, x, y, sx, sy );
	}
	PPrintTime( "circle_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );
}

void setpix_chk( void )
{
	// draw 320*240 pixels
	int i;
	int sx = 64;
	int sy = 64;
	int x, y;

	srand( (unsigned )time(NULL));
	PTimeStart(0);

	for( i= 0; i<CX/2*CY/2; i++ ){
		x = rand() % 640;
		y = rand() % 480;
		SET_BYTE( cp, i%256, x, y );
	}
	PPrintTime( "writepixel_chk()", PTimeStop() );
	DrawChunkyPort( cp, rp, 0, 0 );
}

void lines1_rpt( void )
{
	int i;
	// vertical lines
	PTimeStart( 0 );
	for( i = 0; i<CX; i++ ){
		SetAPen( rp, i%255 );
		Move( rp, i, 0 );
		Draw( rp, i, CY-1 );
	}
	PPrintTime( "v_lines_rpt()", PTimeStop() );
}

void lines2_rpt( void )
{
	int i;
	// horizontal lines
	PTimeStart( 0 );
	for( i = 0; i<CY; i++ ){
		SetAPen( rp, i%255 );
		Move( rp, 0, i );
		Draw( rp, CX-1, i );
	}
	PPrintTime( "h_lines_rpt()", PTimeStop() );
}

void lines3_rpt( void )
{
	int i;
	// lines-spread
	PTimeStart( 0 );
	for( i = 0; i<CY; i++ ){
		SetAPen( rp, i%255 );
		Move( rp, 0, 0 );
		Draw( rp, CX-1, i );
	}
	PPrintTime( "s_lines_rpt()", PTimeStop() );
}

void rect1_rpt( void )
{
	// draw 256 filled boxes with random x/y-positions
	int i;
	int sx = 32;
	int sy = 32;
	int x, y;

	srand( (unsigned )time(NULL));

	PTimeStart(0);

	for( i= 0; i<256; i++ ){
		SetAPen( rp, i%255);
		sx= 4+ (rand() % 128);
		sy= 4+ (rand() % 128);
		x = rand() % (640-sx);
		y = rand() % (480-sy);
		RectFill( rp, x, y, x+sx, y+sy );
	}
	PPrintTime( "rect1_rpt()", PTimeStop() );
}

void circle_rpt( void )
{
	// draw 256 outlined circles with color fadeing
	int i;
	int sx = 64;
	int sy = 64;
	int x, y;
	srand( (unsigned )time(NULL));
	PTimeStart(0);

	for( i= 0; i<256; i++ ){
		SetAPen( rp, i%255);
		x = sx+rand() % (640-(2*sx));
		y = sy+rand() % (480-(2*sy));
		DrawEllipse( rp, x, y, sx, sy );
	}
	PPrintTime( "circle_rpt()", PTimeStop() );
}

void setpix_rpt( void )
{
	// draw 320*240 pixels
	int i;
	int sx = 64;
	int sy = 64;
	int x, y;
	srand( (unsigned )time(NULL));
	PTimeStart(0);

	for( i= 0; i<CX/2*CY/2; i++ ){
		SetAPen( rp, i%255);
		x = rand() % 640;
		y = rand() % 480;
		WritePixel( rp, x, y );
	}
	PPrintTime( "writepixel_rpt()", PTimeStop() );
}

void rpt_test( void )
{
	SetRast(rp, 0);
	setpix_rpt();
	SetRast(rp,0);
	lines1_rpt();
	SetRast(rp,0);
	lines2_rpt();
	SetRast(rp,0);
	lines3_rpt();
	SetRast(rp,0);
	rect1_rpt();
	SetRast(rp,0);
	circle_rpt();
}

void chk_test( void )
{
	setpix_chk();
	ClearChunky(cp);
	lines1_chk();
	ClearChunky(cp);

	lines2_chk();
	ClearChunky(cp);

	lines3_chk();
	ClearChunky(cp);

	rect1_chk();
	ClearChunky(cp);
	circle_chk();
	ClearChunky(cp);
	Delay(100);
	PTimeStart(0);
	DrawChunkyPort(cp, rp, 0, 0 );
	PPrintTime( "DrawChunkyPort()", PTimeStop() );
}
///
///"main function"
int main( void )
{
	if( scr = OpenScreenTags( NULL, SA_DisplayID, 0x39024,    // VGA: Productivity
																	SA_Width,     SX,
																	SA_Height,    SY,
																	SA_Depth,     8,
																	SA_Interleaved, TRUE,
																	TAG_DONE ) )
	{
		rp = &scr->RastPort;

		if( cp = InitChunkyPort( CX, CY ) )
		{
			/* Draw something */
			chk_test();
			rpt_test();
			FreeChunkyPort( cp );
		}
		//Delay( 250 );
		CloseScreen( scr );
	}
}
///
