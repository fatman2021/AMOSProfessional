/*
** test3.c
**
** Tests the various text functions and prints the execution time
**
** compile me with
** gcc -noixemul -s -m68020 -O2 -o test3 test3.c -lchunky -lm
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
///"Test functions "
void chk_draw( struct ChunkyPort *cp )
{
	// Draw some text into the cp
	int i;
	int sx, sy = cp->cp_TxHeight;
	int x, y;
	char  *text = "This is a test...";

	rpt_clear();
	srand( (unsigned )time(NULL));

	sx = TextLength( rp, text, strlen( text ) );

	for( i= 0; i<512; i++ ){
		SetAPenChk( cp, i%255);

		x = rand() % (CX-sx);
		y = cp->cp_TxBaseline + ( rand() % (CY-sy-cp->cp_TxBaseline) );

		MoveChk( cp, x, y );
		TextChk( cp, text );
	}
}

void rpt_clear( void )
{
	SetRast( rp, 0 );
	SetChunky( cp, 0 );
	WaitBlit();
}

void rpt_test( void )
{
	// Draw some text into the rp
	int i;
	int sx, sy = rp->TxHeight;
	int x, y;
	char  *text = "This is a test...";

	rpt_clear();
	SetDrMd( rp, JAM1 );

	PTimeStart(0);
	srand( (unsigned )time(NULL));

	sx = TextLength( rp, text, strlen( text ) );

	for( i= 0; i<512; i++ ){
		SetAPen( rp, i%255);

		x = rand() % (CX-sx);
		y = rp->TxBaseline + ( rand() % (CY-sy-rp->TxBaseline) );

		Move( rp, x, y );
		Text( rp, text, strlen( text ) );
	}

	PPrintTime("rpt_test", PTimeStop());
}
void chk_test( void )
{
	int    x = (SX-CX)/2, y = (SY-CY)/2;

	PTimeStart(0);
	chk_draw(cp);
	PPrintTime("chk_test", PTimeStop());

	DrawChunkyPort( cp, rp, (SX-CX)/2, (SY-CY)/2 );

}

void chk_test2( void )
{
	int hshadow = 4, hshine = 5, shadow = 1, shine = 2;
	int y = 18, sy = 18;
	int i;
	// clear rastport and chunkyPort
	rpt_clear();

	srand( (unsigned )time(NULL));

	PTimeStart(0);

	SetSoftStyleChk( cp, FS_NORMAL );
	SetABOPenChk( cp, shadow, shine, 0 );
	TextCenterChk( cp, "This is a FS_NORMAL test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_BOLD );
	SetABOPenChk( cp, shadow, shine, 0 );
	TextCenterChk( cp, "This is a FSF_BOLD test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_OUTLINE );
	SetABOPenChk( cp, shine, 0, shadow );
	TextCenterChk( cp, "This is a FSF_OUTLINE test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_3D );
	SetABOPenChk( cp, shine, shadow, 0 );
	TextCenterChk( cp, "This is a FSF_3D test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_WIDE3D );
	SetABOPenChk( cp, shine, shadow, 0 );
	TextCenterChk( cp, "This is a FSF_WIDE3D test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_EMBOSSED );
	SetABOPenChk( cp, shadow, hshadow, hshine );
	TextCenterChk( cp, "This is a FSF_EMBOSSED test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_BOLD|FSF_OUTLINE );
	SetABOPenChk( cp, shine, 0, shadow );
	TextCenterChk( cp, "This is a FSF_BOLD|FSF_OUTLINE test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_BOLD|FSF_3D );
	SetABOPenChk( cp, shine, shadow, 0 );
	TextCenterChk( cp, "This is a FSF_BOLD|FSF_3D test", y );
	y+=20;
	SetSoftStyleChk( cp, FSF_BOLD|FSF_EMBOSSED );
	SetABOPenChk( cp, shadow, hshadow, hshine );
	TextCenterChk( cp, "This is a FSF_BOLD|FSF_EMBOSSED test", y );

	PPrintTime( "chk_test2", PTimeStop());
	DrawChunkyPort( cp, rp, (SX-CX)/2, (SY-CY)/2 );
	Delay( 100 );
}
///
///"main function"
int main( void )
{
	ULONG cols[ 8*3+1 ] =  {  0x00060000,
														0x95959595, 0x95959595, 0x95959595,
														0x00000000, 0x00000000, 0x00000000,
														0xffffffff, 0xffffffff, 0xffffffff,
														0x34343434, 0x3e3e3e3e, 0xa7a7a7a7,
														0x7b7b7b7b, 0x7b7b7b7b, 0x7b7b7b7b,
														0xafafafaf, 0xafafafaf, 0xafafafaf };


	if( scr = OpenScreenTags( NULL, SA_DisplayID, 0x39024,    // VGA: Productivity
																	SA_Width,     SX,
																	SA_Height,    SY,
																	SA_Depth,     8,
																	SA_FullPalette, TRUE,
																	SA_Interleaved, TRUE,
																	SA_Colors32,  (ULONG )&cols,
																	SA_Title,     (ULONG )"Chunky Text Functions Test",
																	TAG_DONE ) )
	{
		rp = &scr->RastPort;

		if( cp = InitChunkyPort( CX, CY ) )
		{

			/* Draw something */
			SetFontChk( cp, rp->Font );

			chk_test();
			rpt_test();

			// Test new SoftStyleFlags
			chk_test2();
			FreeChunkyPort( cp );
		}
		Delay( 300 );
		CloseScreen( scr );
	}
}
///

