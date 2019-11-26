#include <exec/types.h>
#include <exec/memory.h>
#include <intuition/intuition.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/graphics.h>
#include <proto/intuition.h>

#include <proto/RainbowSystem.h>

struct RainbowSystemBase *RainbowSystemBase;

void rs_DrawHSBSpace(APTR, UWORD, UWORD, UWORD, UWORD );

static void ErrorMessage(STRPTR text)
{
    struct EasyStruct easy;

    easy.es_StructSize=sizeof(struct EasyStruct);
    easy.es_Flags=0;
    easy.es_Title="Rainbow Demo";
    easy.es_TextFormat=text;
    easy.es_GadgetFormat="Ok";

    EasyRequestArgs(NULL,&easy,NULL,NULL);
}

int main(int argc, char **argv )
{
    LONG error_code;
    char scr[256];
    APTR rainbow;

    if (argc == 2)  strcpy(scr,argv[1]);
    else            strcpy(scr,"Workbench");

    if (RainbowSystemBase=(struct RainbowSystemBase *)OpenLibrary("rainbow.library",1L)) {

        if (rainbow=rs_ObtainScreen(scr,&error_code)) {

            ULONG width=256,height=256;
            struct Window *wnd;

            if (wnd=OpenWindowTags(NULL,WA_Left,    16,
                                        WA_Top,     rs_GetScreen(rainbow)->WBorTop+rs_GetScreen(rainbow)->RastPort.TxHeight+1+12,
                                        WA_InnerWidth,   width,
                                        WA_InnerHeight,  height,
                                        WA_Title,   "Demo",
                                        WA_IDCMP,   IDCMP_CLOSEWINDOW,
                                        WA_PubScreen,rs_GetScreen(rainbow),
                                        WA_Flags,   WFLG_CLOSEGADGET|WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_SMART_REFRESH,TAG_DONE))
            {
                const UWORD offx=wnd->BorderLeft,
                      offy=wnd->BorderTop;
                UWORD x,y;

                if (rs_BeginDraw(rainbow,wnd->RPort))
                {
                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_DrawLine()",NULL);

                    for (y=0;y<height;y+=16)
                    {
                        rs_DrawLine(rainbow,offx,offy+255-y,offx+y,offy,255,0,0);
                        rs_DrawLine(rainbow,offx+255,offy+y,offx+255-y,offy+255,0,255,0);
                    }

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_DrawCircle()",NULL);

                    for (y=0;y<4;y++)
                        for (x=0;x<4;x++)
                        {
                            rs_DrawCircle(rainbow,offx+31+64*x,offy+31+64*y,31,63+y*64,63+x*64,255);
                        }

                    Delay(100);

                    SetWindowTitles(wnd,"rs_FillCircle()",NULL);

                    for (y=0;y<4;y++)
                        for (x=0;x<4;x++)   rs_FillCircle(rainbow,offx+31+64*x,offy+31+64*y,31,RGB(63+y*64,63+x*64,255),RGB_RED);

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_DrawPolygon()",NULL);

                    for (y=0;y<4;y++)
                        for (x=0;x<4;x++)
                        {
                            WORD array[8];

                            array[0]=offx+x*64+8; array[1]=offy+y*64+10;
                            array[2]=offx+x*64+54; array[3]=offy+y*64+40;
                            array[4]=offx+x*64+15; array[5]=offy+y*64+60;
                            array[6]=array[0];     array[7]=array[1];

                            rs_DrawPolygon(rainbow,4,array,255,63+x*64,63+y*64);
                        }

                    Delay(100);

                    SetWindowTitles(wnd,"rs_FillPolygon()",NULL);

                    for (y=0;y<4;y++)
                        for (x=0;x<4;x++)
                        {
                            WORD array[6];

                            array[0]=offx+x*64+8;   array[1]=offy+y*64+10;
                            array[2]=offx+x*64+54;  array[3]=offy+y*64+40;
                            array[4]=offx+x*64+15;  array[5]=offy+y*64+60;

                            rs_FillPolygon(rainbow,3,array,RGB(255,63+x*64,63+y*64),RGB_NONE);
                        }

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_FillRectangle()",NULL);

                    for (y=0;y<256;y+=16)   rs_FillRectangle(rainbow,offx+y,offy+y,255-y,255-y,RGB(255,y,y),RGB_NONE);

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_FadeHorizontal()",NULL);

                    rs_FadeHorizontal(rainbow,offx,offy,     width,36,RGB_RED,     RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+36,  width,36,RGB_GREEN,   RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+2*36,width,36,RGB_BLUE,    RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+3*36,width,36,RGB_CYAN,    RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+4*36,width,36,RGB_MAGENTA, RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+5*36,width,36,RGB_YELLOW,  RGB_WHITE);
                    rs_FadeHorizontal(rainbow,offx,offy+6*36,width,40,RGB_BLACK,   RGB_WHITE);

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_FadeVertical()",NULL);

                    rs_FadeVertical(rainbow,offx+0*36,offy,36,height,RGB_RED,    RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+1*36,offy,36,height,RGB_GREEN,  RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+2*36,offy,36,height,RGB_BLUE,   RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+3*36,offy,36,height,RGB_CYAN,   RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+4*36,offy,36,height,RGB_MAGENTA,RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+5*36,offy,36,height,RGB_YELLOW, RGB_WHITE);
                    rs_FadeVertical(rainbow,offx+6*36,offy,40,height,RGB_BLACK,  RGB_WHITE);

                    Delay(100);

                    SetWindowTitles(wnd,"rs_DrawHSBSpace()",NULL);

                    rs_DrawHSBSpace(rainbow,offx,offy,width,height);

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"rs_Move() - rs_Draw()",NULL);

                    rs_Move(rainbow,offx+width/2-1+(width*5/12),offy+height/2-1);

                    for (y=70;y<=2520;y+=70)
                    {
                        float angle=y*PI/180.0;
                        UWORD x0,y0;

                        x0=offx+width/2-1+(width*5/12)*cos(angle);
                        y0=offy+height/2-1-(height*5/12)*sin(angle);

                        rs_Draw(rainbow,x0,y0,255,255*y/2520,0);
                    }

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    SetWindowTitles(wnd,"Various",NULL);

                    for (y=0;y<40;y++)
                    {
                         UWORD x0=rand()%width,
                               y0=rand()%height,
                               w=rand()%(width-x0),
                               h=rand()%(height-y0);

                        rs_FillRectangle(rainbow,offx+x0,offy+y0,w,h,RGB(rand()&0xFF,rand()&0xFF,rand()&0xFF),RGB_NONE);
                    }

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    for (y=0;y<40;y++)
                    {
                        UWORD x0=rand()%(width>>1),
                              y0=rand()%(height>>1),
                              r0=rand()%(width>>2);

                        rs_FillCircle(rainbow,offx+(width>>2)+x0,offy+(height>>2)+y0,r0,RGB(rand()&0xFF,rand()&0xFF,rand()&0xFF),RGB_NONE);
                    }

                    Delay(100);

                    rs_FillRectangle(rainbow,offx,offy,width,height,RGB_BLACK,RGB_NONE);

                    for (y=0;y<40;y++)
                    {
                        WORD array[6];

                        array[0]=offx+rand()%width;  array[1]=offy+rand()%height;
                        array[2]=offx+rand()%width;  array[3]=offy+rand()%height;
                        array[4]=offx+rand()%width;  array[5]=offy+rand()%height;

                        rs_FillPolygon(rainbow,3,array,RGB(rand()&0xFF,rand()&0xFF,rand()&0xFF),RGB_NONE);
                    }

                    rs_EndDraw(rainbow);
                }

                WaitPort(wnd->UserPort);

                CloseWindow(wnd);
            }

            rs_ReleaseScreen(rainbow);

        } else switch(error_code) {

            case RAINBOWMANAGER_ISNT_ACTIVE:    ErrorMessage("First, you must activate the RainbowManager"); break;
            case NOT_ENOUGH_MEMORY:             ErrorMessage("Not enough memeory"); break;

        }

        CloseLibrary((struct Library*)RainbowSystemBase);

    } else ErrorMessage("First, you must acivate the RainbowManager");

    return 0;
}

void rs_DrawHSBSpace(APTR rainbow, UWORD xstart, UWORD ystart, UWORD w, UWORD h )
{
    UBYTE *buffer;

    if (buffer=AllocVec(3*max(w,16)*h,MEMF_ANY)) {

        UWORD www=3*w,x,y;

        for (x=0;x<w;x++)
        {
            UWORD hue=(6*(x<<13))/w,f=hue&0x1FFF;
            ULONG xx;

            for (xx=3*x,y=0;y<h;y++,xx+=www)
            {
                UBYTE v=(y<<8)/h,s=255-((v*v)>>8);
                UBYTE r,g,b;

                #define p1 (v*(255-s))>>8
                #define p2 (v*(255*8192-s*f))>>21
                #define p3 (v*(((255-s)<<13)+s*f))>>21

                switch (hue>>13)
                {
                    case 0:     r=v;
                                g=p3;
                                b=p1;
                                break;
                    case 1:     r=p2;
                                g=v;
                                b=p1;
                                break;
                    case 2:     r=p1;
                                g=v;
                                b=p3;
                                break;
                    case 3:     r=p1;
                                g=p2;
                                b=v;
                                break;
                    case 4:     r=p3;
                                g=p1;
                                b=v;
                                break;
                    case 5:     r=v;
                                g=p1;
                                b=p2;
                                break;
                }

                buffer[xx]  =r;
                buffer[xx+1]=g;
                buffer[xx+2]=b;
            }
        }

        rs_WritePixelArray(rainbow,xstart,ystart,w,h,buffer);

        FreeVec(buffer);
    }
}
