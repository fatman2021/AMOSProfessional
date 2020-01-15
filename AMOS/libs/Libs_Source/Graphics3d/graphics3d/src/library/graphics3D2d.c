/*
**      $VER: graphics3D2d.c 11.00 (10.05.98)
**
**      External functions for graphics3D.library
**	In questa versione eventuali attivazioni di
**	Goraud shading o ZBuffering vengono semplicemente
**	ignorate.
**	
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>

#include <graphics/rastport.h>
#include <graphics/clip.h>
#include <graphics/regions.h>
#include <graphics/gfx.h>
#include <graphics/gfxmacros.h>
#include <graphics/layers.h>

#include "graphics3Dc.h"
#include "graphics3D.h"
#include "graphics3D2d_proto.h"

 /* Please note, that &Graphics3DBase always resides in register __a6 
    as well, but if we don't need it, we need not reference it here.

    Also note, that registers a0, a1, d0, d1 always are scratch registers,
    so you usually should only *pass* parameters there, but make a copy
    directly after entering the function. To avoid problems of kind
    "implementation defined behaviour", you should make a copy of A6 too,
    when it is actually used.

    In this example case, scratch register saving would not have been 
    necessary (since there are no other function calls inbetween), but we 
    did it nevertheless.
  */

/************ prototipi solo locali ******/
struct RastPort *InitNBuff(struct grafica *graf);

void FreeNBuff(struct grafica *graf);

/**********************************************************/

/************ macro solo locali ******/
#define DIPIU 500 
#define PREC 8
/*************************************/

/****************************************************
 ** Routin per la gestione della grafica, in stile **
 ** 2.0                                            ** 
 ** (c) 1994 BIANCA HARD&SOFT Vers:1.00            **
 ****************************************************/

/********* FUNZIONI 2D ********************************/

/***********************************
 ** INIZIALIZZO STRUTTURE PER USO **
 ** CON ROUTIN DI AREA FILL       **
 ***********************************
 **** INPUT :			  **
 ** win -> puntatore a finestra   **
 **        su cui lavorare.       **
 ** mxv -> n# massimo vertici da  **
 **        usare.		  **
 **** OUTPUT :                    **
 ** ris >0  - tutto ok.           **
 ** ris =<0 - errore, ini.fallita.**
 ***********************************/
struct grafica *ini_g(struct Window *win,long int mxv,long int dx,long int dy)
{
struct grafica *ris;
struct Screen *scr;
struct RastPort *rw;
struct RastPort *r;
struct Layer *la;
long int i,x,y;

ris=(struct grafica *)AllocMem(sizeof(Sgrafica),NULL);
if (ris==NULL) return (0);

ris->vpor=0;
ris->rast=0;
ris->rast1=0;
ris->rast2=0;
ris->fdouble=1;
ris->b_af=0;
ris->pras=0;
x=dx;
y=dy;
if (x>MAXDX) x=MAXDX;
if (y>MAXDY) y=MAXDY;

/** default si single buffer **/
ris->clipx=0;
ris->clipy=0;
i=((x+15)/16)*16;
ris->clipdx=i;
ris->clipdy=y;
ris->zbuf=0;
ris->dbuf=0;
ris->ldbuf=0;
ris->tmp_rp.BitMap=0;
ris->NB_rinfo=0;       
ris->NB_bmap=0;        
ris->NB_layerinfo=0;   
ris->NB_layer=0;       

rw=win->RPort;
scr=win->WScreen;
ris->vpor=&(scr->ViewPort);
la=win->WLayer;
ris->wind=win;
ris->larg=LTMP;
ris->alte=ATMP;

ris->depth=1<<(rw->BitMap->Depth);
ris->r_color=4;				/* n# colori da non usare nella gen. palette */
ris->n_level=ris->depth - ris->r_color;	/* n# livelli intensita' per ogni colore */
ris->n_color=1;				/* n# colori base nella palette */

i=(long int)AllocMem(LEN_TABC,NULL);	/* alloco memoria per tabella colori base */
if (i==NULL)
	{
	close_g(ris);
	return(0);
	}	
ris->t_color=(long int *)i;

/* non alloco la memoria per la tabella delle texture map */
ris->a_tmap=0;

r=InitNBuff(ris);
if ((long int)r==NULL) {
	close_g(ris);
	return(0);
	}
ris->rast1=rw;
ris->rast2=r;
ris->rast=r;
ris->o_ai=r->AreaInfo;
ris->o_tr=r->TmpRas;

/* se per buffer richiesto meno di 1 vertice e' meglio evitare */
if (mxv<=1) {
	close_g(ris);
	return(0);
	}
/* faccio in modo di allineare alle words la dimensione dell'area */
i=mxv;
if (((mxv>>1)<<1)!=mxv) i++;
ris->b_af=AllocMem(MAXVER(i),NULL);
if (ris->b_af==NULL) {
	close_g(ris);
	return(0);	
	}
ris->lb_af=i;

InitArea(&ris->n_ai,ris->b_af,mxv);
r->AreaInfo=&ris->n_ai;

ris->pras=(char *)AllocRaster(ris->larg,ris->alte);
if (ris->pras==NULL) {
	close_g(ris);
	return (0);
	}

InitTmpRas(&ris->n_tr,ris->pras,RASSIZE(ris->larg,ris->alte));

r->TmpRas=&ris->n_tr;

return(ris);
}

/***********************************
 ** NON FA NULLA SOLO PER POTER   **
 ** USARE GLI STESSI MODULI DELLA **
 ** VERSIONE OTTIMIZZATA.	  **
 ***********************************
 **** INPUT :			  **
 ** Ignorato			  **
 ***********************************/
long int c_zbuf(struct ambient3d *in)
{
return(0);
}

/***********************************
 ** CHIUDO TUTTE LE STRUTTURE     **
 ** APERTE CON LA FUNZIONE PRECE- **
 ** DENTE.                        **
 ***********************************
 **** INPUT :                     **
 ** graf -> valore >0 ritornato   **
 **         dalla funzione d'ini- **
 **         zializzazione         **
 ***********************************/
void close_g(struct grafica *graf)
{
struct RastPort *r;
struct Layer *la;
long int c;

if ((long int)graf != NULL)
	{
	la=graf->wind->WLayer;
	if (graf->fdouble!=NULL) la=graf->NB_layer;
	if (la->ClipRegion!=NULL)
		{
		c=InstallClipRegion(la,NULL);
		DisposeRegion(c);
		}
	r=graf->rast;
	if ((long int)r > NULL )
		{
		r->AreaInfo=graf->o_ai;
		r->TmpRas=graf->o_tr;
		}
	if (graf->b_af!=NULL) FreeMem(graf->b_af,MAXVER(graf->lb_af));
	if (graf->pras!=NULL) FreeRaster(graf->pras,graf->larg,graf->alte);
	if (graf->fdouble!=NULL) FreeNBuff(graf);
	FreeMem(graf,sizeof(Sgrafica));
	}
}

/************************************
 ** FUNZIONE PER VISUALIZZARE LA   **
 ** RASTPORT NASCOSTA SULLA        **
 ** FINESTRA.			   **
 ************************************
 **** INPUT :			   **
 ** graf -> valore >0 ritornato    **
 **         dalla funzione d'ini-  **
 **         zializzazione.         **
 **** OUTPUT:			   **
 ************************************/
void switch_rp(graf)
struct grafica *graf;
{

/** se libreria non ottimizzata **/
ClipBlit(graf->rast2,0,0,graf->rast1,graf->clipx,
	graf->clipy,graf->clipdx,graf->clipdy,0xc0);
WaitBlit();

}

/************************************
 ** FUNZIONE PER DEFINIRE UN BOX   **
 ** DI CLIP SULLA FINESTRA         **
 ************************************
 **** INPUT :			   **
 ** graf -> valore >0 ritornato    **
 **         dalla funzione d'ini-  **
 **         zializzazione.         **
 ** minx - valore minimo x box.    **
 ** miny - valore minimo y box.    **
 ** dx - larghezza box.		   **
 ** dy - altezza box.		   **
 **** OUTPUT:			   **
 ** > 0 tutto ok, valore effettivo **
 **     larghezza box in pixel.    ** 
 ** = 0 errore.			   **
 **** NOTA:			   **
 ** elimina eventuali clip region  **
 ** preesistenti.   		   **
 ** Se dx o dy =0 allora ritorna   **
 ** valore effettivo di dx.        **
 ** dy max =2999.		   **
 ** dx max =2999.		   **
 ************************************/
long int clipbox(struct grafica *graf,long int minx,
           long int miny,long int dx,long int dy)
{
struct Layer *la;
struct Region *clipr;
struct Rectangle rect;
struct ClipRect *clrt;
long int esi;
long int i,x,y;

#ifdef DEBUG
char dbg[80];
#endif

if (dx==0 OR dy==0) return(graf->clipdx);

x=dx;
y=dy;

if (y>MAXDY) y=MAXDY;
if (x>MAXDX) x=MAXDX;


i=((x+15)/16)*16;

graf->clipx=minx;
graf->clipy=miny;

#ifdef DEBUG
sprintf(dbg,"mx=%ld my=%ld dx=%ld dy=%ld \n",minx,miny,dx,dy);
write_dbg(dbg);
#endif

graf->clipdx=i;
graf->clipdy=y;

la=graf->wind->WLayer;
if (graf->fdouble) la=graf->NB_layer;

/*
if (minx==0 AND miny==0 AND dx==0 AND dy==0)
	{
	if (graf->fdouble)
		{
		}
	else
		{
		clipr=(struct Region *)InstallClipRegion(la,NULL);
		if (clipr) DisposeRegion(clipr);
		return (0);
		}
	}
if (graf->fdouble==NULL)
	{
	wn=graf->wind;
	la=wn->WLayer;
	}
*/

/** elimino eventuali clipregion preesistenti **/
clipr=(struct Region *)InstallClipRegion(la,NULL);
if (clipr) DisposeRegion(clipr);

/** inizializzo una nuova clip region vuota **/
clipr=(struct Region *)NewRegion();
if (clipr==NULL) return (0);

rect.MinX=0;
rect.MinY=0;
if(graf->fdouble==NULL) 
	{
	rect.MinX=graf->clipx;
	rect.MinY=graf->clipy;
	}
rect.MaxX=graf->clipdx;
rect.MaxY=graf->clipdy;

OrRectRegion(clipr,&rect);
InstallClipRegion(la,clipr);

return (graf->clipdx);
}

/*************************************
 ** FUNZIONE PER CANCELLARE UN BOX  **
 ** NELLA FINESTRA .		    **
 *************************************
 **** INPUT :                       **
 ** graf -> valore >0 ritornato da  **
 **         ini_g().                **
 ** x0   -> coord. x punto in alto  **
 **         a sinistra box.         **
 ** y0   -> coord. y punto in alto  **
 **         a sinistra box.         **
 ** x1   -> coord. x punto in basso **
 **         a destra box.	    **
 ** y1   -> coord. y punto in basso **
 **	    a destra box.	    **
 **** NOTA :			    **
 ** usa il colore dello sfondo, e   **
 ** non influenza le altre funzioni **
 *************************************/
void cls_b(struct grafica *graf,long int x0,
	long int y0,long int x1,long int y1)
{
long int i;
char c,*db;
if (((long int)graf<=NULL) OR ((long int)(graf->rast)<=NULL)) return(0); 

/* se uso libreria non ottimizzata */
EraseRect(graf->rast,x0,y0,x1,y1);
}

/*************************************
 ** FUNZIONE PER CAMBIARE IL MODO   **
 ** VIDEO DI TRACCIAMENTO.          **
 *************************************
 **** INPUT :                       **
 ** graf -> valore >0 ritornato da  **
 **         ini_g().                **
 ** mod  -> nuovo modo video.       **
 **** NOTA :			    **
 ** valori per mod :		    **
 ** 0 > JAM1 (over 2)		    **
 ** 1 > JAM2 (over 0) (def.)	    **
 ** 2 > COMPLEMENT (over 1) 	    **
 ** 4 > INVERSVID  (inverse 1)      **
 *************************************/
void over(struct grafica *graf,long int mod)
{
if (((long int)graf<=NULL) OR ((long int)(graf->rast)<=NULL)) return(0); 

SetDrMd(graf->rast,mod);
}

/********* ROUTIN INTERNE PER PSEUDO DOUBLE BUFFERING ***************/
/*********************************************
 ** INIZIALIZZO NUOVA RASTPORT PER USARLA   **
 ** COME AREA DI RENDERING NASCOSTA.	    **
 *********************************************
 **** INPUT :				    **
 **** OUTPUT:				    **
 ** se > 0 allora puntatore a nuova rastport**
 *********************************************
 ** nota: inizializzo una bitmap uguale     **
 ** alla finestra usata per visualizzare la **
 ** scena effettivamente.	            **
 *********************************************/
struct RastPort *InitNBuff(struct grafica *graf)
{
struct RastPort *rport = NULL;  
struct Window *win;
struct Screen *screen;
short int err = NULL;
unsigned char depth;
long int i;
#ifdef DEBUG
char dbg[100];
#endif

win=graf->wind;
screen=win->WScreen;
depth=screen->BitMap.Depth;

graf->tmp_rp.BitMap=NULL;
graf->dbuf=NULL;

/** 
   Uso routin non ottimizzate passo da una rastport con display buffer nascosto
   di tipo planar per usare il blitter
**/
if (!(graf->NB_layerinfo = (struct Layer_Info *)NewLayerInfo())) 
	return (NULL);

if (!(graf->NB_bmap =(struct BitMap *)AllocBitMap(win->Width+SMARG,
	win->Height+SMARG,depth,BMF_CLEAR|BMF_DISPLAYABLE,
	graf->rast1->BitMap))) {
   err = 3;
   goto NBInit_done;
   }

if (!(graf->NB_layer = (struct Layer *)CreateBehindLayer(graf->NB_layerinfo,
		graf->NB_bmap,SMARGM,SMARGM, win->Width-1, win->Height-1,
		LAYERSIMPLE|LAYERBACKDROP, NULL))) {
   err = 4;
   goto NBInit_done;
   }
rport = graf->NB_layer->rp;

SetRast(rport, 0);   

NBInit_done:
if (err) FreeNBuff(graf);
return (rport);
}

/***************************************************
 ** CHIUDO TUTTE LE AREE APERTE DALLA InitNBuff() **
 ***************************************************/
void FreeNBuff(struct grafica *graf)
{
unsigned char depth;
struct RastPort *rp;

rp=graf->rast2;
if (graf->NB_layer) DeleteLayer(0L, graf->NB_layer);
if (graf->NB_layerinfo) DisposeLayerInfo(graf->NB_layerinfo);

if (graf->NB_bmap) 
	{
	WaitBlit();
	FreeBitMap(graf->NB_bmap);  
	}
}

/********* FUNZIONI 2D NON OTTIMIZZATE ********************************/

/***********************************
 ** RIEMPIO IL DISPLAY FILE COL   **
 ** COLORE DELLO SFONDO.	  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void cls_f(amb3d)
struct ambient3d *amb3d;
{

SetRast(amb3d->graf->rast,amb3d->gcolor);

}

/***********************************
 ** DISEGNO UN PIXEL NEL DISPLAY  **
 ** BUFFER CHUNKY.		  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf -> puntatore a struttura  **
 **	   polytemp con dati 	  **
 **	   poligono.		  **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void pixel( struct ambient3d *amb3d, struct polytemp *buf)
{
struct RastPort *rast;
long int *tcol,c;

tcol=amb3d->graf->t_color;
c=tcol[buf->color]+buf->shade;
if (c==TRASP) return((void)0);

rast=amb3d->graf->rast;

SetAPen(rast,c);
WritePixel(rast,buf->x1,buf->y1);

}

/***********************************
 ** DISEGNO UNA RIGA NEL DISPLAY  **
 ** BUFFER CHUNKY.		  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf -> puntatore a struttura  **
 **	   polytemp con dati 	  **
 **	   poligono.		  **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void line( struct ambient3d *amb3d, struct polytemp *buf)
{
struct RastPort *rast;
long int *tcol,c;

tcol=amb3d->graf->t_color;
c=tcol[buf->color]+buf->shade;
if (c==TRASP) return((void)0);

rast=amb3d->graf->rast;

SetAPen(rast,c);
Move(rast,buf->x1,buf->y1);

switch (buf->numpoints)
	{
		case (2):
			Draw(rast,buf->x2,buf->y2);
			break;
		case (3):
		case (4):
			PolyDraw(rast,buf->numpoints+1,(short int *)buf);
			break;
	}

}
/***********************************
 ** DISEGNO UN TRIANGOLO CON O    **
 ** SENZA BORDO NEL DISPLAY       **
 ** BUFFER CHUNKY.		  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf -> puntatore a struttura  **
 **	   polytemp con dati 	  **
 **	   poligono.		  **
 ** bordo-> =-1 senza bordo       **
 **         >=0 colore bordo.     **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void drw_tg( struct ambient3d *amb3d, struct polytemp *buf, long int bordo)
{
struct RastPort *rast;
long int *tcol,c;

tcol=amb3d->graf->t_color;
c=tcol[buf->color]+buf->shade;
if (c==TRASP) return((void)0);

rast=amb3d->graf->rast;

SetAPen(rast,c);

BNDRYOFF(rast)
if (bordo>=NULL) SetOutlinePen(rast,bordo);

AreaMove(rast,buf->x1,buf->y1);
AreaDraw(rast,buf->x2,buf->y2);
AreaDraw(rast,buf->x3,buf->y3);
AreaEnd(rast);

}

/***********************************
 ** DISEGNO UN QUADRILATERO CON O **
 ** SENZA BORDO NELLA RASTPORT    **
 ** NASCOSTA.			  **
 ***********************************
 **** INPUT :			  **
 ** amb3d-> valore >0 ritornato   **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf -> puntatore a struttura  **
 **	   polytemp con dati 	  **
 **	   poligono.		  **
 ** bordo-> =-1 senza bordo       **
 **         >=0 colore bordo.     **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void drw_qg( struct ambient3d *amb3d, struct polytemp *buf, long int bordo)
{
struct RastPort *rast;
long int *tcol,c;

tcol=amb3d->graf->t_color;
c=tcol[buf->color]+buf->shade;
if (c==TRASP) return((void)0);

rast=amb3d->graf->rast;

SetAPen(rast,c);

BNDRYOFF(rast)
if (bordo>=NULL) SetOutlinePen(rast,bordo);

AreaMove(rast,buf->x1,buf->y1);
AreaDraw(rast,buf->x2,buf->y2);
AreaDraw(rast,buf->x3,buf->y3);
AreaDraw(rast,buf->x4,buf->y4);
AreaEnd(rast);

}

