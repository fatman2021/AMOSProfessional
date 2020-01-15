#include  <intuition/intuition.h>
#include  <dos/dos.h>
#include  <proto/intuition.h>
#include  <proto/graphics.h>
#include  "../lib-src/chunky.h"

int main( void )
{
	struct ChunkyPort *cp;
	struct RastPort   *rp;
	struct Window     *win;
	struct TextFont   *tf;
	struct TextAttr   ta = {"topaz.font", 8, 0, 0};

	if(win = OpenWindowTags( NULL, WA_InnerWidth, 320,
																 WA_InnerHeight, 200,
																 WA_AutoAdjust, TRUE,
																 TAG_DONE ) )
	{
		rp = win->RPort;
		if( cp = InitChunkyPort(  win->Width-win->BorderLeft-win->BorderRight,
															win->Height-win->BorderTop-win->BorderBottom ) )
		{
			if( tf = OpenFont( &ta ) )
			{
				char  *txt1 = "This is a fixed-width-font test chk";
				char  *txt2 = "This is a fixed-width-font test rpt";
				SetFont( rp, tf );
				SetAPen( rp, 1 );
				SetFontChk( cp, tf );
				SetSoftStyleChk( cp, FSF_EMBOSSED );
				SetABOPenChk( cp, 1, 4, 5 );
				MoveChk( cp, 4, 40 );
				TextChk( cp, txt1 );
				DrawChunkyPort( cp, rp, win->LeftEdge+win->BorderLeft, win->TopEdge+win->BorderTop );
				Move(rp, win->BorderLeft+4, 60 );
				Text( rp, txt2, strlen(txt2));
				printf("TextLength()   : %ld\n"
							 "TextLengthChk(): %ld\n",
							 TextLength(rp, txt2, strlen(txt2 ) ),
							 TextLengthChk( cp, txt1, strlen(txt1 ) ) );
				Wait( SIGBREAKF_CTRL_C );
				CloseFont( tf );
			}
			FreeChunkyPort( cp );
		}
		CloseWindow( win );
	}
}
