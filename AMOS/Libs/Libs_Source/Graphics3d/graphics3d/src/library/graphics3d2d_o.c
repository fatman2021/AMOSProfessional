/*
**      $VER: graphics3D2d_o.c 10.00 (06.05.98)
**
**      Internal functions for graphics3D.library
** 	Optimezed 2D functions
**	
**      (C) Copyright 98 Patrizio Biancalani
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
void line2(struct ambient3d *amb3d, long int x, long int y, long int z, long int x1,
	long int y1, long int z1, long int col);

void FreeNBuff(struct grafica *graf);

/**********************************************************/

/************ macro solo locali ******/
#define DIPIU 500 
#define PREC 8
#define DISP (6*FIXV)
#define D_TMAP sizeof(Sbuftmap)*TTMAP+DIPIU
/*************************************/

/****************************************************
 ** Routin per la gestione della grafica, in stile **
 ** 2.0 Ottimizzate                                ** 
 ** (c) 1994 BIANCA HARD&SOFT Vers:1.00            **
 ****************************************************/

/********* FUNZIONI DI INIZIALIZAZIONE PER IL 2D ********************************/

/***********************************
 ** INIZIALIZZO STRUTTURE PER USO **
 ** CON ROUTIN  OTTIMIZZATE.      **
 ***********************************
 **** INPUT :			  **
 ** win -> puntatore a finestra   **
 **        su cui lavorare.       **
 ** mxv -> n# massimo vertici da  **
 **        usare.		  **
 ** dx -> larghezza box di visual.**
 ** dy -> altezza box di visual.  **
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
struct buftmap *btm;
long int i,x,y;

ris=(struct grafica *)AllocMem(sizeof(Sgrafica),NULL);
if (ris==NULL) return (0);

ris->vpor=0;
ris->rast=0;
ris->rast1=0;
ris->rast2=0;
ris->zbuf=0;
ris->fdouble=1;
ris->b_af=0;
ris->pras=0;
ris->t_color=0;
ris->a_tmap=0;

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
ris->dbuf=0;
ris->ldbuf=0;
ris->tmp_rp.BitMap=0;

rw=win->RPort;
scr=win->WScreen;
ris->vpor=&(scr->ViewPort);
ris->wind=win;

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

i=(long int)AllocMem(D_TMAP,NULL);	/* alloco memoria per tabella texture map */
if (i==NULL)
	{
	close_g(ris);
	return(0);
	}
ris->a_tmap=(struct buftmap *)i;
btm=(struct buftmap *)i;
/* setto tutti gli elementi come vuoti */
for(i=0 ;i<TTMAP ;i++) btm[i].chunky=0;

r=InitNBuff(ris);
if ((long int)r==NULL) {
	close_g(ris);
	return(0);
	}
ris->rast1=rw;
ris->rast2=r;
ris->rast=r;

return(ris);
}

/***********************************
 ** Apro un area per lo Z-buffer  **
 ** se non gia' esistente.	  **
 ***********************************
 *** INPUT :			   *
 * in -> valore >0 restituito da   *
 * 	 display3d.                *
 *** OUTPUT:		           *	
 * 0 - operazione fallita.	   *
 * 1 - operazione riuscita.	   * 
 ***********************************/
long int c_zbuf(struct ambient3d *in)
{
struct grafica *graf;

graf=in->graf;

if (graf->zbuf!=NULL) return(1);	/* area per zbuffering gia' esistente */

graf->lzbuf=in->maxx*in->maxy*(sizeof(long int))+DIPIU;

graf->zbuf=(long int *)AllocMem(graf->lzbuf,NULL);
if (graf->zbuf==NULL) return(0);

return(1);
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
struct buftmap *btm;
long int i;

if ((long int)graf != NULL)
	{
	if (graf->t_color!=NULL) FreeMem(graf->t_color,LEN_TABC);
	if (graf->a_tmap!=NULL) 
		{
		btm=graf->a_tmap;
		for(i=0; i<TTMAP; i++)
			{
			if (btm[i].chunky!=NULL)
				{
				FreeMem(btm[i].chunky,btm[i].lung);
				btm[i].chunky=0;
				}	
			}
		FreeMem(graf->a_tmap,D_TMAP);
		}
	if (graf->zbuf!=NULL) FreeMem(graf->zbuf,graf->lzbuf);
	if (graf->dbuf!=NULL) FreeNBuff(graf);
	FreeMem(graf,sizeof(Sgrafica));
	}
}

/************************************
 ** FUNZIONE PER VISUALIZZARE IL   **
 ** DISPLAY BUFFER CHUNKY NELLA    **
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
long int x,y;

x=graf->clipx;
y=graf->clipy;

if (graf) WritePixelArray8(graf->rast,x,y,x+graf->clipdx-1,y+graf->clipdy-1,
		graf->dbuf,&graf->tmp_rp);

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
 ** dy max =2999.		   **
 ** dx max =2999.		   **
 ** Se dx o dy =0 allora ritorna   **
 ** valore effettivo di dx.        **
 ************************************/
long int clipbox(struct grafica *graf,long int minx,
           long int miny,long int dx,long int dy)
{
struct Layer *la;
struct Region *clipr;
struct Rectangle rect;
struct ClipRect *clrt;
long int esi,x,y;
long int i;

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

/* se uso libreria ottimizzata */
if (graf->clipdx!=i OR graf->clipdy!=y)
	{
	graf->clipdx=i;
	graf->clipdy=y;
/*
	FreeNBuff(graf);
	InitNBuff(graf);
*/
	}

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
/*
void cls_b(struct grafica *graf,long int x0,
	long int y0,long int x1,long int y1)
{
long int i;
char c,*db;
if (((long int)graf<=NULL) OR ((long int)(graf->rast)<=NULL)) return(0); 
EraseRect(graf->rast,x0,y0,x1,y1);
}
*/

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
 ** INIZIALIZZO UN DISPLAY BUFFER DI TIPO   **
 ** CHUNKY PER USARE POI WritePixelArray8().** 
 *********************************************
 **** INPUT :				    **
 **** OUTPUT:				    **
 ** se > 0 allora puntatore a nuova rastport**
 *********************************************
 ** nota: la larghezza del box di visualiz. ** 
 **    deve essere un multiplo di 16.       **
 *********************************************/
struct RastPort *InitNBuff(struct grafica *graf)
{
struct RastPort *rport = NULL;  
struct Window *win;
short int err = NULL;
char *c;
long int i;

win=graf->wind;

graf->tmp_rp.BitMap=NULL;
graf->dbuf=NULL;

InitRastPort(&graf->tmp_rp);

/** 
   Uso le routin ottimizzate definisco un display buffer tipo chunky e una rastport temp.
   per WritePixelArray8().
   Nota :la larghezza del display buffer deve essere multipla di 16 (una word)).
**/ 
rport=win->RPort;

graf->ldbuf=graf->clipdx * graf->clipdy + DIPIU;
graf->dbuf=(char *)AllocMem(graf->ldbuf,NULL);
if (graf->dbuf==NULL) {
	err=1;
	goto NBInit_done ;
	}
graf->tmp_rp.Layer=NULL;
graf->tmp_rp.BitMap=(struct BitMap *)AllocBitMap(graf->clipdx,1,8,						BMF_CLEAR|BMF_DISPLAYABLE,rport->BitMap);

if (graf->tmp_rp.BitMap==NULL) {
	err=2;
	goto NBInit_done ;
	}

/* inizializzo il display buffer con tutti 0 */
c=graf->dbuf;
for(i=0 ;i<graf->ldbuf; i++) c[i]=0;

NBInit_done:
if (err) FreeNBuff(graf);
return (rport);
}

/***************************************************
 ** CHIUDO TUTTE LE AREE APERTE DALLA InitNBuff() **
 ***************************************************/
void FreeNBuff(struct grafica *graf)
{

if (graf->dbuf) FreeMem(graf->dbuf,graf->ldbuf);
if (graf->tmp_rp.BitMap) 
	{
	WaitBlit();
	FreeBitMap(graf->tmp_rp.BitMap);  
	}

}

/********* FUNZIONI GRAFICHE 2D OTTIMIZZATE ********************************/

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
char col,*c;
long int i,*z,zz;

/* inizializzo il display buffer con gcolor */
c=amb3d->graf->dbuf;
col=amb3d->gcolor;
for(i=0 ;i<amb3d->graf->ldbuf; i++) c[i]=col;

/* se definito uno zbuffer lo riempio con z=0x7FFFFFFF */
if (amb3d->graf->zbuf!=NULL)
	{
	z=amb3d->graf->zbuf;
	zz=amb3d->maxx*amb3d->maxy;
	for(i=0 ;i<=zz; i++) z[i]=0x7FFFFFFFL; 
	}

}

/***********************************
 ** DISEGNO UN PIXEL NEL DISPLAY  **
 ** BUFFER CHUNKY.		  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf  -> puntatore ad array di **
 **	    short int con coordi- **
 **         nate vertici.	  **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void pixel(amb3d,buf)
struct ambient3d *amb3d;
struct polytemp *buf;
{
struct grafica *gf;
short int dx;
short int x;
short int y;
long int c,*tcol,ii,*zz;
char *db;

gf=amb3d->graf;
db=gf->dbuf;
tcol=gf->t_color;
zz=gf->zbuf;
dx=gf->clipdx;
x=buf->x1;
y=buf->y1;
ii=dx*y+x;
c=tcol[buf->color];
if (c==TRASP) return((void)0);

if (amb3d->fzbuf==NULL)
	{
	if (x>=NULL AND x<dx AND y>=NULL AND y<gf->clipdy) db[ii]=c+buf->shade;
	}
else
	{
	if (buf->z1<zz[ii] AND x>=NULL AND x<dx AND y>=NULL AND y<gf->clipdy) 
		{
		db[ii]=c+buf->shade;
		zz[ii]=buf->z1;
		}
	}
}
/***********************************
 ** DISEGNO IL BORDO DI UN POLIGO-**
 ** NO.				  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf  -> puntatore ad array di **
 **	    short int con coordi- **
 **         nate vertici.	  **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void line(amb3d,buf)
struct ambient3d *amb3d;
struct polytemp *buf;
{
long int col,*bcol;

bcol=amb3d->graf->t_color;
col=bcol[buf->color]+buf->shade;
if (col==TRASP) return((void)0);

switch (buf->numpoints)
	{
	case (2):
		line2(amb3d,buf->x1,buf->y1,buf->z1,buf->x2,buf->y2,buf->z2,col);
		break;
	case (3):
		line2(amb3d,buf->x1,buf->y1,buf->z1,buf->x2,buf->y2,buf->z2,col);
		line2(amb3d,buf->x2,buf->y2,buf->z2,buf->x3,buf->y3,buf->z3,col);
		line2(amb3d,buf->x3,buf->y3,buf->z3,buf->x1,buf->y1,buf->z1,col);
		break;
	case (4):
		line2(amb3d,buf->x1,buf->y1,buf->z1,buf->x2,buf->y2,buf->z2,col);
		line2(amb3d,buf->x2,buf->y2,buf->z2,buf->x3,buf->y3,buf->z3,col);
		line2(amb3d,buf->x3,buf->y3,buf->z3,buf->x4,buf->y4,buf->z4,col);
		line2(amb3d,buf->x4,buf->y4,buf->z4,buf->x1,buf->y1,buf->z1,col);
		break;
	}
}

/***********************************
 ** DISEGNO UNA RIGA NEL DISPLAY  **
 ** BUFFER CHUNKY.		  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** x  -> coordinata x partenza.  **
 ** y  -> coordinata y partenza.  **
 ** z  -> valore z iniziale.	  **
 ** x1 -> coordinata x arrivo.	  **
 ** y1 -> coordinata y arrivo.	  **
 ** z1 -> valore z finale.	  **
 ** col-> colore riga.		  **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void line2(amb3d,x,y,z,x1,y1,z1,col)
struct ambient3d *amb3d;
long int x;
long int y;
long int z;
long int x1;
long int y1;
long int z1;
long int col;
{
struct grafica *gf;
char *db;
short int xm,ym,xx;
long int dx,dy,dz;
long int to,from,za,*zz,fz;
long int ii,i,a,b;

#ifdef DEBUG
char dbg[100];
#endif

gf=amb3d->graf;
db=gf->dbuf;
zz=gf->zbuf;
fz=amb3d->fzbuf;
xm=(short int)gf->clipdx;
ym=(short int)gf->clipdy;
xx=xm;

dy=(y1-y)<<PREC;
dx=(x1-x)<<PREC;
dz=z1-z;
if (dy<NULL) dy=-dy;
if (dx<NULL) dx=-dx;
if (dy<dx)
	{
	if (y>y1) dy=-dy;
	dx=dx>>PREC;
	if (dx==NULL) dx=1; 
	dy/=dx;
	if (fz) dz/=dx;
	a=y<<PREC;
	za=z;
	from=x;
	to=x1;
	if (x>x1)
		{
		ii=from;
		from=to;
		to=ii;
		a=y1<<PREC;
		za=z1;
		dy=-dy;
		dz=-dz;
		}
	if (to>=xm) to=xm;
	if (fz==NULL)
		{
		for(b=from ;b<to ;b++) 
			{
			i=a>>PREC;
			if (b>=0 AND i>=0 AND i<ym) db[i*xx+b]=(char)col;
			a+=dy;
			}
		}
	else
		{
		for(b=from ;b<to ;b++) 
			{
			i=a>>PREC;
			ii=i*xx+b;
			if (za<=zz[ii] AND b>=0 AND i>=0 AND i<ym)
				{
				db[ii]=(char)col;
				zz[ii]=za;
				}
			a+=dy;
			za+=dz;
			}
		}
	}
else
	{
	if (x>x1) dx=-dx;
	dy=dy>>PREC;
	if (dy==NULL) dy=1;
	dx/=dy;
	if (fz) dz/=dy;
	a=x<<PREC;
	za=z;
	from=y;
	to=y1;
	if (y>y1) 
		{
		ii=from;
		from=to;
		to=ii;
		a=x1<<PREC;
		za=z1;
		dx=-dx;
		dz=-dz;
		}
	if (to>=ym) to=ym;
	if (fz==NULL)
		{
		for(b=from ;b<to ;b++) 
			{
			i=a>>PREC;
			if (b>=0 AND i>=0 AND i<xm) db[b*xx+i]=(char)col;
			a+=dx;
			}
		}
	else
		{
		for(b=from ;b<to ;b++) 
			{
			i=a>>PREC;
			ii=b*xx+i;
			if (za<=zz[ii] AND b>=0 AND i>=0 AND i<xm)
				{
				db[ii]=(char)col;
				zz[ii]=za;
				}
			a+=dx;
			za+=dz;
			}
		}
	}
}

/***********************************
 ** DISEGNO UN TRIANGOLO CON LO   **
 ** SHADING RICHIESTO CON O SENZA **
 ** BORDO NEL DISPLAY BUFFER      **
 ** CHUNKY.			  **
 ***********************************
 **** INPUT :			  **
 ** amb3d -> valore >0 ritornato  **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf  -> puntatore a struttura **
 **         polytemp con descri-  **
 **	    zione poligono.	  ** 
 ** bordo-> =-1 senza bordo       **
 **         >=0 colore bordo.     **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void drw_tg(amb3d,buf,bordo)
struct ambient3d *amb3d;
struct polytemp *buf;
long int bordo;
{
struct pixl *vert;
register long int d,i,ii,x1,xs,xe;
long int clb,xm,ym,x,y,c,z,u,v,ys,ye;
long int lmap,*tcol,*pzb,dy,mx,mc,mz,mu,mv,start;
struct grafica *gf;
unsigned char *tmp,*btmap;
struct edge *ledge,*redge;
char zbuf,goraud,texmap;
#ifdef DEBUG 
char dbg[100];
#endif

goraud=0;
texmap=0;
zbuf=0;
btmap=0;
lmap=0;
gf=amb3d->graf;
tcol=gf->t_color;
pzb=gf->zbuf;
if (buf->tmap->dtmap!=NULL)
	{
	btmap=buf->tmap->dtmap->chunky;
	lmap=buf->tmap->dtmap->larg;
	}
i=buf->vmode & 0x0F;
if (i==GORAUD) goraud=1;
if (( buf->vmode & TMAP)!=NULL AND btmap!=NULL) texmap=1;
if (pzb!=NULL) zbuf=amb3d->fzbuf;
xm=gf->clipdx-1;
ym=gf->clipdy;
vert=(struct pixl *)amb3d->temp;
ledge=(struct edge *)&vert[5];
redge=(struct edge *)&ledge[MAXDY+2];
tmp=(unsigned char *)gf->dbuf;

#ifdef DEBUG
sprintf(dbg,"vert=%ld ledge=%ld redge=%ld tmp=%ld tcol=%ld pzb=%ld \n",vert,ledge,redge,tmp,tcol,pzb,);
write_dbg(dbg);
#endif

vert[0].x=buf->x1<<PREC;
vert[0].y=buf->y1;
vert[0].color=buf->clp1<<PREC;
vert[0].z=buf->z1;
vert[0].u=buf->tmap->u1<<PREC;
vert[0].v=buf->tmap->v1<<PREC;
vert[1].x=buf->x2<<PREC;
vert[1].y=buf->y2;
vert[1].color=buf->clp2<<PREC;
vert[1].z=buf->z2;
vert[1].u=buf->tmap->u2<<PREC;
vert[1].v=buf->tmap->v2<<PREC;
vert[2].x=buf->x3<<PREC;
vert[2].y=buf->y3;
vert[2].color=buf->clp3<<PREC;
vert[2].z=buf->z3;
vert[2].u=buf->tmap->u3<<PREC;
vert[2].v=buf->tmap->v3<<PREC;

/* riordino i vertici in base alla Y minore con bubble sort */
if (vert[0].y > vert[1].y)
	{
	x=vert[0].x;
	y=vert[0].y;
	z=vert[0].z;
	c=vert[0].color;
	u=vert[0].u;
	v=vert[0].v;
	vert[0].x=vert[1].x;
	vert[0].y=vert[1].y;
	vert[0].z=vert[1].z;
	vert[0].color=vert[1].color;
	vert[0].u=vert[1].u;
	vert[0].v=vert[1].v;
	vert[1].x=x;
	vert[1].y=y;
	vert[1].z=z;
	vert[1].color=c;
	vert[1].u=u;
	vert[1].v=v;
	}	

if (vert[1].y > vert[2].y)
	{
	x=vert[1].x;
	y=vert[1].y;
	z=vert[1].z;
	c=vert[1].color;
	u=vert[1].u;
	v=vert[1].v;
	vert[1].x=vert[2].x;
	vert[1].y=vert[2].y;
	vert[1].z=vert[2].z;
	vert[1].color=vert[2].color;
	vert[1].u=vert[2].u;
	vert[1].v=vert[2].v;
	vert[2].x=x;
	vert[2].y=y;
	vert[2].z=z;
	vert[2].color=c;
	vert[2].u=u;
	vert[2].v=v;
	}	

if (vert[0].y > vert[1].y)
	{
	x=vert[0].x;
	y=vert[0].y;
	z=vert[0].z;
	c=vert[0].color;
	u=vert[0].u;
	v=vert[0].v;
	vert[0].x=vert[1].x;
	vert[0].y=vert[1].y;
	vert[0].z=vert[1].z;
	vert[0].color=vert[1].color;
	vert[0].u=vert[1].u;
	vert[0].v=vert[1].v;
	vert[1].x=x;
	vert[1].y=y;
	vert[1].z=z;
	vert[1].color=c;
	vert[1].u=u;
	vert[1].v=v;
	}	

/* scarto triangoli tutti fuori */
if (vert[0].y<NULL AND vert[2].y<NULL) return(0);
if (vert[0].y>=ym AND vert[2].y>=ym) return(0);

/** scan left edges **/
mx=vert[2].x-vert[0].x;
mc=vert[2].color-vert[0].color;
mz=vert[2].z-vert[0].z;
if (texmap)
	{
	mu=vert[2].u-vert[0].u;
	mv=vert[2].v-vert[0].v;
	}
dy=vert[2].y-vert[0].y;
if (dy!=NULL)
	{
	mx/=dy;
	if (texmap)
		{
		mu/=dy;
		mv/=dy;
		}
	if (goraud) mc/=dy;
	if (zbuf) mz/=dy;
	}
x=vert[0].x;
c=vert[0].color;
z=vert[0].z;
u=vert[0].u;
v=vert[0].v;
for (i=vert[0].y ;i<=vert[2].y; i++)
	{
	x1=x>>PREC;
	if (i>=NULL AND i<ym)
		{
		ledge[i].x=x1;
		if (texmap)
			{
			ledge[i].u=u;
			ledge[i].v=v;
			}
		if (goraud) ledge[i].color=c;
		if (zbuf) ledge[i].z=z;	
		}
	c+=mc;
	x+=mx;
	z+=mz;
	if (texmap)
		{
		u+=mu;
		v+=mv;
		}
	}

/** scan rigth edges **/
mx=vert[1].x-vert[0].x;
mc=vert[1].color-vert[0].color;
mz=vert[1].z-vert[0].z;
if (texmap)
	{
	mu=vert[1].u-vert[0].u;
	mv=vert[1].v-vert[0].v;
	}
dy=vert[1].y-vert[0].y;
if (dy!=NULL)
	{
	mx/=dy;
	if (texmap)
		{
		mu/=dy;
		mv/=dy;
		}
	if (goraud) mc/=dy;
	if (zbuf) mz/=dy;
	}
x=vert[0].x;
c=vert[0].color;
z=vert[0].z;
u=vert[0].u;
v=vert[0].v;
for (i=vert[0].y ;i<=vert[1].y; i++)
	{
	x1=x>>PREC;
	if (i>=NULL AND i<ym)
		{
		redge[i].x=x1;
		if (texmap)
			{
			redge[i].u=u;
			redge[i].v=v;
			}
		if (goraud) redge[i].color=c;
		if (zbuf) redge[i].z=z;
		}
	c+=mc;
	x+=mx;
	z+=mz;
	if (texmap)
		{
		u+=mu;
		v+=mv;
		}
	}

mx=vert[2].x-vert[1].x;
mc=vert[2].color-vert[1].color;
mz=vert[2].z-vert[1].z;
if (texmap)
	{
	mu=vert[2].u-vert[1].u;
	mv=vert[2].v-vert[1].v;
	}
dy=vert[2].y-vert[1].y;
if (dy!=NULL)
	{
	mx/=dy;
	if (texmap)
		{
		mu/=dy;
		mv/=dy;
		}
	if (goraud) mc/=dy;
	if (zbuf) mz/=dy;
	}
x=vert[1].x;
c=vert[1].color;
z=vert[1].z;
u=vert[1].u;
v=vert[1].v;
for (i=vert[1].y ;i<=vert[2].y; i++)
	{
	x1=x>>PREC;
	if (i>=NULL AND i<ym)
		{
		redge[i].x=x1;
		if (texmap)
			{
			redge[i].u=u;
			redge[i].v=v;
			}
		if (goraud) redge[i].color=c;
		if (zbuf) redge[i].z=z;
		}
	c+=mc;
	x+=mx;
	z+=mz;
	if (texmap)
		{
		u+=mu;
		v+=mv;
		}
	}

/** draw scan lines **/
ys=vert[0].y;
if (ys<NULL) ys=0;
if (ys>ym-1) ys=ym-1;
ye=vert[2].y;
if (ye<NULL) ye=0;
if (ye>ym-1) ye=ym-1;

start=(ys-1)*(xm+1);

for (i=ys ;i<=ye ;i++)
	{
	start+=xm+1;
	xs=ledge[i].x;
	xe=redge[i].x;
	if (xe>xm AND xs>xm) continue;
	if (xe<NULL AND xs<NULL) continue;
	clb=tcol[buf->color];
	c=buf->shade;
	if (xs<xe)
		{
		mx=(xe-xs);
		if (mx!=NULL)
			{
			if (texmap) 
				{
				mu=(redge[i].u-ledge[i].u)/mx;
				mv=(redge[i].v-ledge[i].v)/mx;
				}
			if (goraud) mc=(redge[i].color-ledge[i].color)/mx;
			if (zbuf) mz=(redge[i].z-ledge[i].z)/mx;
			}
		if (zbuf) z=ledge[i].z+FIXVM;
		if (goraud) c=ledge[i].color+FIXVM;
		if (texmap)
			{
			u=ledge[i].u+FIXVM;
			v=ledge[i].v+FIXVM;
			}
		}
	else 
		{
		mx=(xs-xe);
		if (mx!=NULL)
			{
			if (texmap)
				{
				mu=(ledge[i].u-redge[i].u)/mx;
				mv=(ledge[i].v-redge[i].v)/mx;
				}
			if (goraud) mc=(ledge[i].color-redge[i].color)/mx;
			if (zbuf) mz=(ledge[i].z-redge[i].z)/mx;
			}
		if (zbuf) z=redge[i].z+FIXVM;
		if (goraud) c=redge[i].color+FIXVM;
		if (texmap)
			{
			u=redge[i].u+FIXVM;
			v=redge[i].v+FIXVM;
			}
		x=xs;
		xs=xe;
		xe=x;
		}
	if (xe>xm) xe=xm;
	if (goraud)
		{
		if (zbuf)
			{
			for (ii=xs ;ii<=xe ;ii++)
				{
				d=start+ii;
				if (z<pzb[d] AND ii>=NULL )
					{
					if (texmap) clb=tcol[btmap[(v>>PREC)*lmap + 										  (u>>PREC)]];
					if (clb!=TRASP)
						{
						pzb[d]=z; 
						tmp[d]=clb+(c>>PREC);
						}
					}
				c+=mc;
				z+=mz;
				if (texmap)
					{
					u+=mu;
					v+=mv;
					}
				}
			}
		else
			{	
			for (ii=xs ;ii<=xe ;ii++)
				{
				if (ii>=NULL)
					{
					if (texmap) clb=tcol[btmap[(v>>PREC)*lmap + 
								   (u>>PREC)]];
					if (clb!=TRASP) tmp[start+ii]=clb+(c>>PREC);
					}
				c+=mc;
				if (texmap)
					{
					u+=mu;
					v+=mv;
					}
				}
			}
		}
	else	
		{
		if (zbuf)
			{
			for (ii=xs ;ii<=xe ;ii++)
				{
				d=start+ii;
				if (z<pzb[d] AND ii>=NULL)
					{
					if (texmap) clb=tcol[btmap[(v>>PREC)*lmap + 
								   (u>>PREC)]];
					if (clb!=TRASP)
						{
						pzb[d]=z; 
						tmp[d]=clb+c;
						}
					}
				z+=mz;
				if (texmap)
					{
					u+=mu;
					v+=mv;
					}
				}
			}		
		else
			{
			for (ii=xs ;ii<=xe ;ii++) 
				{
				if (ii>=NULL)
					{
					if (texmap) clb=tcol[btmap[(v>>PREC)*lmap + 
								   (u>>PREC)]];
					if (clb!=TRASP) tmp[start+ii]=clb+c;
					}
				if (texmap)
					{
					u+=mu;
					v+=mv;
					}
				}
			}		
		}
	}
/* traccio eventuale bordo */

if (bordo>=NULL)
	{
	line2(amb3d,buf->x1,buf->y1,buf->z1-DISP,buf->x2,buf->y2,buf->z2-DISP,bordo);
	line2(amb3d,buf->x2,buf->y2,buf->z2-DISP,buf->x3,buf->y3,buf->z3-DISP,bordo);
	line2(amb3d,buf->x3,buf->y3,buf->z3-DISP,buf->x1,buf->y1,buf->z1-DISP,bordo);
	}

}

/***********************************
 ** DISEGNO UN QUADRILATERO CON O **
 ** SENZA BORDO NEL CHUNKY BUFFER **
 ** CON LO SHADING RICHIESTO      **
 ***********************************
 **** INPUT :			  **
 ** amb3d-> valore >0 ritornato   **
 **         dalla funzione d'ini- **
 **         zializzazione.        **
 ** buf  -> puntatore a struttura **
 **         polytemp con descri-  **
 **	    zione poligono.	  ** 
 ** bordo-> =-1 senza bordo       **
 **         >=0 colore bordo.     **
 **** OUTPUT:			  **
 ** nessuno .			  **
 ***********************************/
void drw_qg(amb3d,buf,bordo)
struct ambient3d *amb3d;
struct polytemp *buf;
long int bordo;
{
struct grafica *gf;
struct polytemp pt;
struct poltmap ptm,*ptmo; 
short int buf1[6];

gf=amb3d->graf;
ptmo=buf->tmap;
pt.x1=buf->x3;
pt.y1=buf->y3;
pt.x2=buf->x4;
pt.y2=buf->y4;
pt.x3=buf->x1;
pt.y3=buf->y1;
pt.numpoints=buf->numpoints;
pt.obj=buf->obj;
pt.npol=buf->npol;
pt.color=buf->color;
pt.shade=buf->shade;
pt.vmode=buf->vmode;
pt.clp1=buf->clp3;
pt.clp2=buf->clp4;
pt.clp3=buf->clp1;
pt.z1=buf->z3;
pt.z2=buf->z4;
pt.z3=buf->z1;
pt.tmap=&ptm;

ptm.dtmap=ptmo->dtmap;
ptm.u1=ptmo->u3;
ptm.v1=ptmo->v3;
ptm.u2=ptmo->u4;
ptm.v2=ptmo->v4;
ptm.u3=ptmo->u1;
ptm.v3=ptmo->v1;

drw_tg(amb3d,buf,-1);
drw_tg(amb3d,&pt,-1);
/* traccio eventuale bordo */

if (bordo>=NULL)
	{
	line2(amb3d,buf->x1,buf->y1,buf->z1-DISP,buf->x2,buf->y2,buf->z2-DISP,bordo);
	line2(amb3d,buf->x2,buf->y2,buf->z2-DISP,buf->x3,buf->y3,buf->z3-DISP,bordo);
	line2(amb3d,buf->x3,buf->y3,buf->z3-DISP,buf->x4,buf->y4,buf->z4-DISP,bordo);
	line2(amb3d,buf->x4,buf->y4,buf->z4-DISP,buf->x1,buf->y1,buf->z1-DISP,bordo);
	}

}

