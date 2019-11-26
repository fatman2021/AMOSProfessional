/*
** test2.c
**
** Tests the various insert functions and prints the execution time
**
** compile me with
** gcc -noixemul -s -m68020 -O2 -o test2 test2.c -lchunky -lm
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
#define CX  320
#define CY  240

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
///"Test functions "
void chk_draw( struct ChunkyPort *cp )
{
	// Draw some outline boxes into the cp
	int i;
	int sx = 16;
	int sy = 16;
	int x, y;

	srand( (unsigned )time(NULL));

	for( i= 0; i<255; i++ ){
		SetAPenChk( cp, i%255);
		sx = rand() % CX;
		sy = rand() % CY;
		x = rand() % (CX-sx);
		y = rand() % (CY-sy);
		RectChk( cp, x, y, x+sx, y+sy );
	}
}

void rpt_draw( void )
{
	SetRast( rp, 1 );
	WaitBlit();
}

void chk_test( void )
{
	// This routine uses the InsertChunkyPort() function to
	// plot the ChunkyPort into the RastPort
	chk_draw( cp );
	rpt_draw();
	PTimeStart(0);
	InsertChunkyPort( cp, rp, (SX-CX)/2, (SY-CY)/2 );
	PPrintTime( "InsertChunkyPort()", PTimeStop());
}

void chk_test2( void )
{
	// This routine uses the CreateChunkyFromRastPort() function to
	// get a 'squizzy paper' as background for our rendering functions
	// This might be usefull if you want to chunky-draw into a picture

	struct ChunkyPort *c2;
	int    x = (SX-CX)/2, y = (SY-CY)/2;

	if( c2 = CreateChunkyFromRastPort( rp, x, y, CX-1, CY-1 ) ){
		rpt_draw();
		chk_draw(c2);

		PTimeStart(0);
		DrawChunkyPort( c2, rp, (SX-CX)/2, (SY-CY)/2 );
		PPrintTime( "CreateChunkyFromRastPort()", PTimeStop());

		FreeChunkyPort( c2 );
	}
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
			chk_test2();
			FreeChunkyPort( cp );
		}
		Delay( 250 );
		CloseScreen( scr );
	}
}
///

