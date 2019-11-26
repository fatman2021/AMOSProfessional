/*
**      $VER: graphics3Df.c 10.11 (02.03.98)
**
**      Main functions for graphics3D.library
**	PARTE #1
**
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
**      
**	Note: this code is traslate from the blitzbasic 3d graphics engine 
**	      V 0.9 of Maciej R. Gorny.
**
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
#include "graphics3D2d.h"
#include "graphics3Df_proto.h"
#include "graphics3D2d_proto.h"

 /* Please note, that &Graphics3dBase always resides in register __a6 as well,
    but if we don't need it, we need not reference it here.

    Also note, that registers a0, a1, d0, d1 always are scratch registers,
    so you usually should only *pass* parameters there, but make a copy
    directly after entering the function. To avoid problems of kind
    "implementation defined behaviour", you should make a copy of A6 too,
    when it is actually used.

    In this example case, scratch register saving would not have been 
    necessary (since there are no other function calls inbetween), but we 
    did it nevertheless.
  */

extern void buildlookuptables(struct ambient3d *in);
extern void createworldtocamera(struct ambient3d *in);
extern void recalcobj(struct ambient3d *in);
extern long int t_removeobject(struct ambient3d *in);
extern void localtoworld(struct ambient3d *in);
extern void worldtocamera(struct ambient3d *in);
extern void removebackfacesandshade(struct ambient3d *in);
extern void clipobject3d(struct ambient3d *in);
extern void generatepolylist(struct ambient3d *in);
extern struct objectnode *resetobj(struct ambient3d *in);
extern struct objectnode *nextobj(struct ambient3d *in);
extern struct objectnode *pobj(struct ambient3d *in);
extern void aggobj(struct ambient3d *in);
extern void matidentity4x4(struct matrix4x4 *imatrix); 
extern void matzero4x4(struct matrix4x4 imatrix);
extern void matcopy4x4(struct matrix4x4 *s_m,struct matrix4x4 *d_m);
extern void matmult4x4(struct matrix4x4 *a,struct matrix4x4 *b,
		struct matrix4x4 *r);
extern void matmult4x4s(struct matrix4x4 *a,struct matrix4x4 *b,
		struct matrix4x4 *r);
extern void matmult1x4s(struct matrix1x4 *a,struct matrix4x4 *b,
		struct matrix1x4 *r);
extern void makevector3d(struct vertex *a,struct vertex *b,
		 struct vector *result);
extern long int vectormag3d(struct vector *a);
extern void normalpol(struct vertex *v0,struct vertex *v1,
	 struct vertex *v2,struct vector *normal);
extern long int dotproduct(struct vector *u,struct vector *v);
extern long int sqri(long int v);
extern long int abs(long int val);
extern void qsort(long int lo0,long int hi0,long int *pol,long int *count);
extern void paintpol(struct ambient3d *in,long int *iwp,
	long int total_polys,long int colb); 
extern long int quicksort(long int len,long int *pol);
extern void GD_deleteobject(REG(a0)struct ambient3d *in);

/**********************************************************/

long int v_worldp(struct ambient3d *in);

/****************************************************
 ** Routin per la gestione della grafica, in stile **
 ** 2.0                                            ** 
 ** (c) 1994 BIANCA HARD&SOFT Vers:1.00            **
 ****************************************************/

/************ FUNZIONI 3D ********************************/

/** macro ad uso interno e provvisorio **/
#define mver(val) (val*sizeof(Svertex)+10)
#define mobj(val) (val*sizeof(Sobjectnode)+5)
#define mplf(val) (val*sizeof(long int)+5)
#define mtmp(val) (val*sizeof(Spolytemp)+5)
#define tang (361*4+5)
/****************************************/

/************************************************
 * apertura e inizializzazione dell'ambiente 3D * 
 * restituisce puntatore ad area generale da    *
 * indicare sempre al richiamo delle altre      *
 * routin.					*
 ************************************************
 *** INPUT :					*
 * win  -> puntatore a finestra su cui si vuol  *
 *         operare.				*
 * x0   -> coord. X origine finestra di vis.    *
 * y0   -> coord. Y origine finestra di vis.    *
 * scrw -> larghezza finestra per mondo 3D.     *
 * scrh -> altezza finestra per mondo 3D.       *
 * vdist-> distanza tra osservatore e piano di  *
 *         proiezione.			        *
 *** OUTPUT:					*
 * puntatore a struttura ambient3d da usarsi in *
 * ingresso di quasi tutte le altre funzioni.   *
 * > 0 allora tutto ok.				*
 * <=0 allora errore, operazione fallita.       * 
 ************************************************/
struct ambient3d *GD_display3d(win,x0,y0,scrw,scrh,vdist)
REG(a0)struct Window *win;
REG(d0)long int x0;
REG(d1)long int y0;
REG(d2)long int scrw;
REG(d3)long int scrh;
REG(d4)long int vdist;
{
long int i;
char *p;
struct ambient3d *ris;
struct vector *vt;
struct dir3d *dan3;
struct Screen *sc;
struct Layer *la;
struct RastPort *rp;
struct tag3d *gpal;

#ifdef DEBUG
char dbg[80];
#endif

ris=NULL;

ris=(struct ambient3d *)AllocMem(sizeof(Sambient3d),NULL);
#ifdef DEBUG
sprintf(dbg,"ambient3d=%ld\n",ris);
write_dbg(dbg);
#endif
if ((long int)ris==NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}

/** inizializzo tutti i puntatori a 0 */
ris->graf=0;
ris->temp=0;
ris->iobjects=0;
ris->objects=0;
ris->iwpolys=0;
ris->worldpolys=0;
ris->sintable=0;
ris->costable=0;

p=(char *)ini_g(win,5,scrw,scrh);
#ifdef DEBUG
sprintf(dbg,"ini_g=%ld\n",p);
write_dbg(dbg);
#endif
if (p==(char *)NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}
ris->graf=(struct grafica *)p;

i=mver(MAXVERT);
if (i<(100+sizeof(Sedge)*2*MAXDY)) i=100+2*MAXDY*sizeof(Sedge);
p=(char *)AllocMem(i,NULL);
if (p==(char *)NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}
ris->temp=p;
#ifdef DEBUG
sprintf(dbg,"temp=%ld\n",p);
write_dbg(dbg);
#endif

ris->ltemp=i;

p=(char *)AllocMem(mobj(MAXOBJECT),NULL);
if (p==(char *)NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}
ris->objects=(struct objectnode *)p;

p=(char *)AllocMem(tang,NULL);
#ifdef DEBUG
sprintf(dbg,"sintable=%ld\n",p);
write_dbg(dbg);
#endif
if (p==(char *)NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}
ris->sintable=(long int *)p;

p=(char *)AllocMem(tang,NULL);
#ifdef DEBUG
sprintf(dbg,"costable=%ld\n",p);
write_dbg(dbg);
#endif
if (p==(char *)NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}
ris->costable=(long int *)p;

/** inizializzo tutte le variabili **/
ris->win=win;
ris->half_screen_width=(ris->graf->clipdx)/2;
ris->half_screen_height=(ris->graf->clipdy)/2;
ris->zoom=FIXV;
ris->aspect_ratio=1*FIXV;
ris->inv_aspect_ratio=1*FIXV;
ris->viewing_distance=vdist;
new_fov(ris);
ris->minx=x0;
ris->miny=y0;
ris->maxx=ris->graf->clipdx;
ris->maxy=ris->graf->clipdy;
ris->agg_all=1;
ris->gl_triangle_color=1;
ris->gcolor=0;
ris->ambient_light=1*FIXV;
ris->projection_type=PROSP_P;
vt=&ris->light_source;

vt->x=234;	 /* =INT(0.913913*FIXV) */
vt->y=100;	 /* =INT(0.389759*FIXV) */
vt->z=-29;	 /* =INT(-0.113369*FIXV)*/
vt->w=0;

/*
vt->x=1*FIXV;
vt->y=-2*FIXV;
vt->z=5*FIXV;
vt->w=0*FIXV;
*/
vt=&ris->view_point;
vt->x=1*FIXV;
vt->y=2*FIXV;
vt->z=3*FIXV;
vt->w=10*FIXV;
dan3=&ris->view_angle;
dan3->angx=0;
dan3->angy=0;
dan3->angz=0;
ris->near_z=ris->viewing_distance;
ris->far_z=4096;
ris->bord_col=1;
ris->fzbuf=0;
ris->clip_mode=ZPLANE;
ris->view_mode=WIREF;
ris->maxintensity=ris->graf->n_level-1;
ris->total_polys=0;
ris->max_polys=0;
ris->old_mpoly=0;
ris->total_objects=0;
ris->attuale=0;
ris->numero=1;

/* genero tutte sfumature di grigio di default */
gpal=(struct tag3d *)(ris->temp+15000);
gpal[0].tipo=GP_COL;
gpal[0].val=0L;
gpal[1].tipo=END_T;
GD_genpalette(ris,gpal);

/* installo una clipregion, per effettuare il clip automatico */
i=clipbox(ris->graf,ris->minx,ris->miny,ris->maxx,ris->maxy);
#ifdef DEBUG
sprintf(dbg,"clipbox esi=%ld\n",i);
write_dbg(dbg);
#endif
if (i==NULL)
	{
	GD_close_display3d(ris);
	return(0);
	}	

/** inizializzo tabelle seno e coseno **/
buildlookuptables(ris);

return(ris);

}

/************************************************
 * chiusura ed eliminazione dell'ambiente 3D    * 
 ************************************************
 *** INPUT :					*
 * in -> valore >0 restituito da display3d.     *
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_close_display3d(in)
REG(a0)struct ambient3d *in;
{
long int i,n;

if (in==NULL) return(0);

if (in->temp!=NULL) FreeMem(in->temp,in->ltemp);
if (in->sintable!=NULL) FreeMem(in->sintable,tang);
if (in->costable!=NULL) FreeMem(in->costable,tang);
if (in->iwpolys!=NULL) FreeMem(in->iwpolys,mplf(in->max_polys));
if (in->worldpolys!=NULL) FreeMem(in->worldpolys,mtmp(in->max_polys));
if (in->total_objects>NULL)
	{
	n=in->total_objects;
	for(i=0 ; i<n ; i++)
		{
		in->attuale=0;	
		GD_deleteobject(in);
		}
	}
if (in->iobjects!=NULL) FreeMem(in->iobjects,NULL);
if (in->objects!=NULL) FreeMem(in->objects,mobj(MAXOBJECT));
if (in->graf!=NULL) close_g(in->graf);
	
FreeMem(in,sizeof(Sambient3d));

}

/********************************************
 ** cambia il modo di visualizzazione      **
 ** globale.				   **
 ********************************************
 *** INPUT :				    *
 * in  -> valore >0 restituito da display3d.*
 * modo-> modalita' di visualizzazione      *
 *        oggetti.			    *
 *        WIREF  = wire frame               *
 *        SOLID  = solid shade   	    *
 *        FLAT   = flat shading		    *
 *	  GORAUD = goraud shading	    *
 * b_col-> colore bordo, se <0 allora nessun*
 *        bordo per i poligoni.		    *
 *** OUTPUT:			 	    *
 * >0 tutto ok.				    *
 * =0 valore non valido.		    *
 ********************************************/
long int GD_changeviewmode(in,modo,b_col)
REG(a0)struct ambient3d *in;
REG(d0)long int modo;
REG(d1)long int b_col;
{
struct objectnode *obj;
long int buf,md;

in->bord_col=b_col;
md=0x0F & modo;

if (md!=WIREF AND md!=SOLID AND md!=FLAT AND md!=GORAUD) return(0);

buf=in->attuale;
obj=resetobj(in);
while(obj!=NULL)
	{
	obj->shade=modo;
	obj->trasf|=0x01;
	obj=nextobj(in);
	}

in->view_mode=modo;
in->attuale=buf;

return(1);
}

/**********************************************
 ** genera tutta la palette dei colori in    **
 ** in modo indipendente dai valori impostati**
 ** DA USARSI AL POSTO DELLA TOUCHPALETTE .  **
 **********************************************
 *** INPUT :				     **
 * in -> valore > 0 restituito da display3d   *
 * new-> puntatore a array di strutture	      *
 *	  tag3d con nuovi valori.	      *
 **** OUTPUT:				     **
 * 0 == nessuna variazione .		      *
 * 0 >  n# di variazioni effettuate.	      *
 *** NOTE :				     **
 **********************************************/
long int GD_genpalette(in,new)
REG(a0)struct ambient3d *in;
REG(a1)struct tag3d *new;
{
long int *col,ris,i,ii,ct,ft,n_col,color;
long int d_red,d_green,d_blu;
long int red,green,blu;
long int *tcol;
struct rgbtype *crgb,*c;
struct grafica *graf;
#ifdef DEBUG
char dbg[200];
#endif

n_col=0;
ris=0;

col=(long int *)in->temp;
crgb=(struct rgbtype *)&col[260];
graf=(struct grafica *)in->graf;
tcol=graf->t_color;

for (i=0 ; i<256 ; i++)
	{
	col[i]=-1;
	ct=i<<1;
	crgb[ct].r=15;
	crgb[ct].g=15;
	crgb[ct].b=15;
	crgb[ct+1].r=0;
	crgb[ct+1].g=0;
	crgb[ct+1].b=0;
	}

ct=0;
while(new[ct].tipo!=END_T AND ct<300)
	{
	ft=new[ct].tipo;
	i=new[ct].val;
	switch(ft)
		{
		case (GP_RCOL):
		/* riservo un n# di colori non utilizzato */
		/* uso multiplo di 2 piu' vicino */
		if (((i+1)>>1)<<1 < graf->depth)
			{
			graf->r_color=((i+1)>>1)<<1;
			ris++;
			}
		break;

		case (GP_NCOL):
		/* definisco il n# di colori base da usare */
		if (i > 0)
			{
			ii=i;
			if (ii>graf->depth-graf->r_color) ii=graf->depth-graf->r_color;
			graf->n_color=ii;
			ris++;
			}
		break;

		case (GP_NLIV):
		/* definisco il n# di livelli di intensita' per ogni colore */		
		if (i > 0)
			{
		/* verifico se n# livelli troppo grande se si lo adeguo automaticamente*/
			ii=i;
			if (ii*graf->n_color > graf->depth-graf->r_color) 
				ii=(graf->depth-graf->r_color)/graf->n_color;
			graf->n_level=ii;
			ris++;
			}
		break;

		case (GP_COL):
		/* assegno il n# di colore virtuale a cui associare la prossima seq. rgb */
		if (i < graf->n_color)
			{
			n_col=i;
			col[n_col]=i;
			tcol[n_col]=graf->r_color+(n_col*graf->n_level);
			ris++;
			}
		break;

		case (GP_HRGB):
		/* livello RGB massimo da usare per definire il n# di colore richiesto */
		/* BIANCO SE NON DEFINITA */
		c=(struct rgbtype *)i;
		crgb[n_col<<1].r=c->r;
		crgb[n_col<<1].g=c->g;
		crgb[n_col<<1].b=c->b;
		ris++;
		break;

		case (GP_LRGB):
		/* livello RGB minimo da usare per definire il n# di colore richiesto */
		/* NERO SE NON DEFINITA */
		c=(struct rgbtype *)i;
		crgb[(n_col<<1)+1].r=c->r;
		crgb[(n_col<<1)+1].g=c->g;
		crgb[(n_col<<1)+1].b=c->b;
		ris++;
		break;

		case (GP_PALET):
		/* assegna al colore indicato in GP_COL il registro della palette indicato*/
		if (i <= graf->depth)
			{
			tcol[n_col]=i;
			col[n_col]=-1;	
			ris++;
			}		
		break;
		
		case (GP_TRASP) :
		/* assegna il colore trasparente all'ultimo colore e non verra' considerato per i
		   livelli di luminosita' */
		tcol[graf->n_color-1]=TRASP;
		col[graf->n_color-1]=-1;
		graf->n_level=(graf->depth-graf->r_color)/(graf->n_color-1);
		ris++;
		break;
	
		case (GP_INFO):
		/* ritorna in .val il n# di registro nella palette assegnato a quel colore */
		/* val deve essere puntatore ad intero */
		*(long int *)i=tcol[n_col];		
		ris++;
		break;
		
		}
	ct++;
	}

in->maxintensity=graf->n_level-1;

/* genero la palette dei livelli dei colori definiti */
for (i=0 ; i<256 ;i++)
	{
	if (col[i]>=NULL)
		{
		n_col=col[i]<<1;
		color=tcol[col[i]];
#ifdef DEBUG
sprintf(dbg,"color=%ld\n",color);
write_dbg(dbg);
#endif
		ft=0;
		if (crgb[n_col].r>15 OR crgb[n_col].g>15 OR crgb[n_col].b>15) ft=1;
		if (crgb[n_col+1].r>15 OR crgb[n_col+1].g>15 OR crgb[n_col+1].b>15) ft=1;
		red=crgb[n_col+1].r<<8;
		green=crgb[n_col+1].g<<8;
		blu=crgb[n_col+1].b<<8;			
		d_red=((crgb[n_col].r<<8)-red)/graf->n_level;
		d_green=((crgb[n_col].g<<8)-green)/graf->n_level;
		d_blu=((crgb[n_col].b<<8)-blu)/graf->n_level;
		for (ct=0 ;ct<graf->n_level; ct++)
			{
			if (ft)
				{
				if (color+ct<graf->depth)
					SetRGB32(graf->vpor,color+ct,(red>>8)<<24,
						(green>>8)<<24,(blu>>8)<<24);
				}
			else
				{
				if (color+ct<graf->depth)
					SetRGB4(graf->vpor,color+ct,red>>8,green>>8,blu>>8);
				}
			red+=d_red;
			green+=d_green;
			blu+=d_blu;
			}
		}
	}

return(ris);
}

/**********************************************
 ** crea una palette sfumata tra due colori  **
 ** nella palette dello schermo, in modo di  **
 ** poter poi usare il FLAT E il GORAUD      **
 ** SHADING.   			             **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 * fr -> n# primo registro colore da settare. *
 * lr -> n# ultimo reg. colore da settare.    *
 * init_color -> punt. a struttura rgbtype    *
 *               con valore rgb iniz. colore. *
 * last_color -> punt. a struttura rgbtype    *
 *		 con valore rgb fin. color.   *
 *** OUTPUT:				      *
 * nessuno.				      *
 *** NOTE :				      *
 * se si usa valori tra 0-15 per i colori si  *
 * puo' usare la graphics.library del S.O.2.0 *
 * altrimenti occorre il 3.0.		      *
 **********************************************/
void GD_touchpalette(in,fr,lr,init_color,last_color)
REG(a0)struct ambient3d *in;
REG(d0)long int fr;
REG(d1)long int lr;
REG(a1)struct rgbtype *init_color;
REG(a2)struct rgbtype *last_color;
{
long int i,c;
struct tag3d *gpal;

gpal=(struct tag3d *)(in->temp+15000);

c=fr/in->graf->n_level - in->graf->r_color;

if (c>in->graf->n_color-1) c=in->graf->n_color-1;

gpal[0].tipo=GP_COL;
gpal[0].val=c;
gpal[1].tipo=GP_HRGB;
gpal[1].val=(long int)last_color;
gpal[2].tipo=GP_LRGB;
gpal[2].val=(long int)init_color;
gpal[3].tipo=END_T;

GD_genpalette(in,gpal);

}

/**********************************************
 ** muove l'osservatore di dist unita'       **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 * dist -> numero di unita' di spostamento.   *
 *         (il valore deve essere FIXPOINT)   *
 *** OUTPUT:				      *
 * nessuno.				      *
 **********************************************/
void GD_moveforward(in,dist)
REG(a0)struct ambient3d *in;
REG(d0)long int dist;
{
long int *sin,*cos;
struct dir3d *vang;
struct vector *vp;
long int active_axes,dx,dy,dz;

sin=in->sintable;
cos=in->costable;
vang=&in->view_angle;
vp=&in->view_point;

active_axes=0;

if (vang->angx!=NULL) active_axes+=1;
if (vang->angy!=NULL) active_axes+=2;
if (vang->angz!=NULL) active_axes+=4;

switch (active_axes)
	{
	case (0):
		dx=0;
		dy=0;
		dz=dist;
		break;
	case (1):
		dx=0;
		dy=(dist*cos[vang->angx]) >> SFIXV;
		dz=(dist*sin[vang->angx]) >> SFIXV;
		break;
	case (2):
		dx=(dist*sin[vang->angy]) >> SFIXV;
		dy=0;
		dz=(dist*cos[vang->angy]) >> SFIXV;
		break;
	case (3):
		dx=(dist*sin[vang->angy]) >> SFIXV;
		dy=(dist*cos[vang->angx]) >> SFIXV;
		dz=(dist*cos[vang->angy]) >> SFIXV + 
			(dist*sin[vang->angx]) >> SFIXV;
		break;
	case (4):		
		dx=(dist*sin[vang->angz]) >> SFIXV;
		dy=(dist*cos[vang->angz]) >> SFIXV;
		dz=0;
		break;		
	case (5):
		dx=(dist*sin[vang->angz]) >> SFIXV;
		dy=(dist*cos[vang->angx]) >> SFIXV +
		    (dist*cos[vang->angz]) >> SFIXV;	
		dz=(dist*sin[vang->angx]) >> SFIXV;
		break;

	case (6):
		dx=(dist*sin[vang->angy]) >> SFIXV +
		    (dist*sin[vang->angz]) >> SFIXV;
		dy=(dist*cos[vang->angz]) >> SFIXV;
		dz=(dist*cos[vang->angy]) >> SFIXV;
		break;

	case (7):
		dx=(dist*sin[vang->angy]) >> SFIXV +
		    (dist*sin[vang->angz]) >> SFIXV;	
		dy=(dist*cos[vang->angx]) >> SFIXV +
		    (dist*cos[vang->angz]) >> SFIXV;	
		dz=(dist*sin[vang->angx]) >> SFIXV +
		    (dist*cos[vang->angy]) >> SFIXV;
		break;	

	}

vp->x+=dx;
vp->y+=dy;
vp->z+=dz;

/* forzo aggiornamento di TUTTA la scena */
in->agg_all=1;

}

/**********************************************
 ** cambio l'angolo della visuale            **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 * ax -> valore rotazione su asse x.          *
 *       (in gradi e intero)		      *
 * ay -> valore rotazione su asse y.          *
 *       (in gradi e intero)		      *
 * az -> valore rotazione su asse z.          *
 *       (in gradi e intero)		      *
 *** OUTPUT:				      *
 * nessuno.				      *
 **********************************************/
void GD_viewangle(in,ax,ay,az)
REG(a0)struct ambient3d *in;
REG(d0)long int ax;
REG(d1)long int ay;
REG(d2)long int az;
{
struct dir3d *va;

va=&in->view_angle;

if (ax<0 OR ax>360)
	{
	ax-=(ax/360)*360;
	if (ax<0) ax+=360;
	}

if (ay<0 OR ay>360)
	{
	ay-=(ay/360)*360;
	if (ay<0) ay+=360;
	}

if (az<0 OR az>360)
	{
	az-=(az/360)*360;
	if (az<0) az+=360;
	}

va->angx=ax;
va->angy=ay;
va->angz=az;

/* forzo aggiornamento di TUTTA la scena */
in->agg_all=1;

}

/******************************************************
 ** setta i piani near e far del volume visualizzato **
 ******************************************************
 *** INPUT :					      * 
 * in   -> valore > 0 restituito da display3d.	      *
 * near -> posizione piano vicino.(valore intero)     *
 * far  -> posizione piano lontano.(valore intero)    *
 *** OUTPUT:					      *
 * nessuno.					      *
 ******************************************************/
void GD_frustum(in,near,far)
REG(a0)struct ambient3d *in;
REG(d0)long int near;
REG(d1)long int far;
{
long int n,f;
/* i valori in input devono essere interi */
n=near;
f=far;
/*if (near<in->viewing_distance) n=in->viewing_distance;*/
if (far<near) f=2*n;

in->near_z=n;
in->far_z=f;

}

/******************************************************
 ** crea e posiziona una sorgente di luce .          **
 ******************************************************
 *** INPUT :					      * 
 * in -> valore > 0 restituito da display3d.	      *
 * x  -> valore coordinata X luce(valore FIXPOINT).   *
 * y  -> valore coordinata Y luce(valore FIXPOINT).   *
 * z  -> valore coordinata Z luce(valore FIXPOINT).   *
 *** OUTPUT:					      *
 * nessuno.					      *
 ******************************************************/
void GD_createlightsource(in,x,y,z)
REG(a0)struct ambient3d *in;
REG(d0)long int x;
REG(d1)long int y;
REG(d2)long int z;
{
struct vertex v1,v2;
long int dd;

/* i valori in ingresso devono gia' essere in fixpoint */
v2.x=x;
v2.y=y;
v2.z=z;
v1.x=0;
v1.y=0;
v1.z=0;

makevector3d(&v1,&v2,&in->light_source);

/* riduco l'ampiezza del vettore ma non la direzione che l'unica cosa che serve*/
dd=in->light_source.x;
if (dd<in->light_source.y) dd=in->light_source.y;
if (dd<in->light_source.z) dd=in->light_source.z;
dd=dd>>SFIXV;
if (dd==NULL) dd=1;
if (dd<NULL) dd=-dd;

in->light_source.x/=dd;
in->light_source.y/=dd;
in->light_source.z/=dd;

/* forzo aggiornamento scena */
in->agg_all=1;

}

/**********************************************
 ** setta l'intensita' di luce ambientale.   **
 **********************************************
 *** INPUT :				      * 
 * in  -> valore > 0 restituito da display3d. *
 * inte-> valore intensita' luce (positivo)   *
 *       (valore in FIXPOINT).		      *
 *** OUTPUT:				      *
 * nessuno.				      *
 **********************************************/
void GD_ambientlight(in,inte)
REG(a0)struct ambient3d *in;
REG(d0)long int inte;
{
long int i;
i=inte;

/* il valore di input deve essere in fixpoint */
if (i>>SFIXV > in->maxintensity) i=in->maxintensity<<SFIXV;
if (i<NULL) i=0;
in->ambient_light=i;

/* forzo aggiornamento scena */
in->agg_all=1;

}

/************************************************
 ** posiziona il punto di vista nel mondo 3d.  ** 
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * x  -> valore coordinata X camera		*
 *	 (valore FIXPOINT). 		        *
 * y  -> valore coordinata Y camera		*
 *       (valore FIXPOINT).   			*
 * z  -> valore coordinata Z camera		*
 *       (valore FIXPOINT).   			*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_positioncamera(in,x,y,z)
REG(a0)struct ambient3d *in;
REG(d0)long int x;
REG(d1)long int y;
REG(d2)long int z; 
{

/* i valori in input devono gia' essere in fixpoint */ 
in->view_point.x=x;
in->view_point.y=y;
in->view_point.z=z;

/* forzo aggiornamento scena */
in->agg_all=1;

}

/************************************************
 ** variazione aspect ratio scena. 	       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * ratio-> nuovo aspect ratio.(valore FIPOINT). *
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_aspectratio(in,ratio)
REG(a0)struct ambient3d *in;
REG(d0)long int ratio;
{

in->aspect_ratio=ratio;
in->inv_aspect_ratio=FIXV*FIXV/ratio;

new_fov(in);

}

/************************************************
 ** setta un particolare modo per il clipping. **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * mode -> nuovo modo di clipping.		*
 *         (ZPLANE ,FRUSTUM).			*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_clipmode(in,mode)
REG(a0)struct ambient3d *in;
REG(d0)long int mode;
{

in->clip_mode=mode;
if (mode!=FRUSTUM AND mode!=ZPLANE) in->clip_mode=ZPLANE;

}

/*************************************
 ** ROUTIN PER CABIARE IL COLORE    **
 ** DI UN REGISTRO DELLA PALETTE    **
 *************************************
 **** INPUT :			    **
 ** graf ->valore non 0 ritornato da**
 **        display3d.		    **
 ** nr   ->numero registro da       **
 **        variare.		    **
 ** red  ->livello rosso (0-15).    **
 ** green->livello verde (0-15).    **
 ** blue ->livello blu   (0-15).    **
 **** OUTPUT:			    **
 ** nessuno.			    **
 *************************************/
void GD_rgb4(REG(a0)struct ambient3d *in,REG(d0)long int n,
	REG(d1)long int red,REG(d2)long int green,REG(d3)long int blue) 
{

}

/******************************************************
 ** visualizza effettivamente i poligoni nella frame **
 ** corrente. Ordina i poligoni in base alla Z min.  **
 ** o se attivo usa lo Z buffering.		     **
 ******************************************************
 *** INPUT :					      * 
 * in -> valore > 0 restituito da display3d.	      *
 *** OUTPUT:					      *
 * puntatore a RastPort su cui si e' disegnato.	      *
 * In caso di libreria ottimizzato e' quello della    *
 * finestra di visualizzazione.			      *
 ******************************************************/
struct RastPort *GD_paintframe(in)
REG(a0)struct ambient3d *in;
{
long int it,buf;

it=0;

/* ripulisco la frame attuale */
cls_f(in);

if (in->total_objects==NULL OR in->iwpolys==NULL) return(in->graf->rast);

/** riordino tutti i poligoni in base alla loro distanza **/
/** dall'osservatore.					 **/
/** si effettua solo se lo ZBUFFERING e' OFF 		 **/
/** ho usato il quicksort				 **/
if (in->fzbuf==NULL) it=quicksort(in->total_polys,in->iwpolys);

buf=in->graf->rast->DrawMode;

over(in->graf,1);

/** inizio la visualizzazione vera e propia della frame attuale **/
paintpol(in,in->iwpolys,in->total_polys,in->bord_col);

over(in->graf,buf);

return (in->graf->rast);
}

/**********************************************
 ** ri-calcola la vista del mondo 3d.        **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 *** OUTPUT:				      *
 * nessuno.				      *
 **********************************************/
void GD_newview(in)
REG(a0)struct ambient3d *in;
{
struct objectnode *obj;
long int buf;

#ifdef DEBUG
char dbg[80];
#endif

createworldtocamera(in);

/* resetlist() */
buf=in->attuale;
obj=resetobj(in);

if (in->total_objects>NULL)
{

   if (in->old_mpoly<=in->max_polys)
	{
/* se e' aumentato il n# massimo di poligoni nello spazio allora vario le aree coinvolte */
	if (v_worldp(in)==NULL)
		{
		/* se fallisce riprovo con le dimensioni vecchie */
		in->max_polys=in->old_mpoly;
		if (v_worldp(in)==NULL)
			{
			/* se fallisce di nuovo termino */
			return(0);
			}
		}
	else
		{
		in->old_mpoly=in->max_polys;
		}
	}

#ifdef DEBUG
sprintf(dbg,"*** INIZIO RICALCOLO SCENA ***\n");
write_dbg(dbg);
#endif

   do
/** non cambiare l'ordine d'esecuzione delle routin in questo loop MAI! **/
	{
	GD_recalcobj(in);
	if (obj->trasf!=NULL OR in->agg_all!=NULL)	
		{
		if (t_removeobject(in)==NULL)
			{
			localtoworld(in);
			removebackfacesandshade(in);
			worldtocamera(in);
			clipobject3d(in);
			}
		}
/*  reset segnalazione di trasformazioni multiple */
	obj->trasf=0;
	obj=nextobj(in);
	}while(obj!=NULL);

#ifdef DEBUG
sprintf(dbg,"*** FINE RICALCOLO SCENA ***\n\n");
write_dbg(dbg);
#endif

   generatepolylist(in);
#ifdef DEBUG
sprintf(dbg,"Generatepolylist\n");
write_dbg(dbg);
#endif

}
/* resetto flag per forzare aggiornamento scena */
   in->agg_all=0;

/* ripristino oggetto attualmente selezionato */
   in->attuale=buf;

}

/********************************************************************************/
/* funzione locale per ridefinire le aree per i poligoni proiettati nella scena */ 
/********************************************************************************/
long int v_worldp(struct ambient3d *in)
{

if (in->max_polys==NULL) return(0);

if (in->iwpolys!=NULL) FreeMem(in->iwpolys,mplf(in->old_mpoly));
in->iwpolys=(long int *)AllocMem(mplf(in->max_polys),NULL);
if (in->iwpolys==NULL) 
	{
	if (in->worldpolys!=NULL) FreeMem(in->worldpolys,mtmp(in->old_mpoly));
	in->worldpolys=0;
	return(0);
	}
	
if (in->worldpolys!=NULL) FreeMem(in->worldpolys,mtmp(in->old_mpoly));
in->worldpolys=(struct polytemp *)AllocMem(mtmp(in->max_polys),NULL);
if (in->worldpolys==NULL) 
	{
	FreeMem(in->iwpolys,mplf(in->max_polys));
	in->iwpolys=0;
	return(0);
	}

return(1);
}

/********** FUNZIONI 2D *************************/
/************************************
 ** FUNZIONE PER DEFINIRE UN BOX   **
 ** DI CLIP SULLA FINESTRA         **
 ************************************
 **** INPUT :			   **
 ** in   -> valore >0 ritornato    **
 **         dalla funzione d'ini-  **
 **         zializzazione display3d**
 ** minx - valore minimo x box.    **
 ** miny - valore minimo y box.    **
 ** dx - larghezza box.		   **
 ** dy - altezza box.		   **
 **** OUTPUT:			   **
 ** > 0 tutto ok valore dx.	   ** 
 ** = 0 errore.			   **
 **** NOTA:			   **
 ** dx e dy non possono eccedere i **
 ** valori indicati in display3d() ** 
 ************************************/
long int GD_clipbox(REG(a0)struct ambient3d *in,REG(d0)long int minx,
           REG(d1)long int miny,REG(d2)long int dx,REG(d3)long int dy)
{
long int ris;
struct Window *win;

if (in->maxx<dx OR in->maxy<dy) return(0);

ris=clipbox(in->graf,minx,miny,dx,dy);
if (ris==NULL) return(ris);

win=in->win;

in->half_screen_width=ris/2;
in->half_screen_height=dy/2;
new_fov(in);
in->minx=minx;
in->miny=miny;

return(ris);

}

/************************************
 ** FUNZIONE PER VISUALIZZARE LA   **
 ** RASTPORT NASCOSTA SULLA        **
 ** FINESTRA.			   **
 ************************************
 **** INPUT :			   **
 ** in ->   valore >0 ritornato    **
 **         dalla funzione d'ini-  **
 **         zializzazione display3d**
 **** OUTPUT:			   **
 ************************************/
void GD_switch_rp(in)
REG(a0)struct ambient3d *in;
{

switch_rp(in->graf);

}

/*****************************************
 ** FUNZIONE PER VARIARE CARATTERISTCHE **
 ** SCENA 3D.				**
 *****************************************
 **** INPUT :				**
 ** in -> valore >0 ritornato dalla     **
 **       funzione d'inizializzazione   **
 **	  display3d().			**
 ** new-> puntatore a array di strutture**
 **	  tag3d con nuovi valori.	**
 **** OUTPUT:				**
 ** == 0  - nessuna variazione .        ** 
 **  > 0  - n# variazioni eseguite.     ** 
 *****************************************/
long int GD_cascene(in,new)
REG(a0)struct ambient3d *in;
REG(a1)struct tag3d *new;
{
long int ris,i,ct,ft;
struct vertex *vp;

ris=0;
ct=0;

while(new[ct].tipo!=END_T AND ct<1000)
	{
	ft=new[ct].tipo;
	i=new[ct].val;
	switch(ft)
		{
		case(CS_PROJET):
	/* cambio tipo di proiezione */
			if (i==PROSP_P OR i==PARAL_P)
				{
				in->projection_type=i;
				in->agg_all=1;	
				ris+=1;
				}
			break;

		case(CS_ZOOM):
	/* cambio valore zoom scena */
			if (i<256*FIXV)
				{
				in->zoom=i;			
				in->agg_all=1;
				ris+=1;
				}
			break;

		case(CS_VDIST):
	/* sposto distanza osservatore dal piano di proiezione */
				in->viewing_distance=i;
				in->agg_all=1;
				ris+=1;
			break;

		case(CS_VIEWP):
	/* inserisce nella struttura vertex puntata da .val la posizione attuale della camera */
		if (i!=NULL)
			{
			vp=(struct vertex *)i;
			vp->x=in->view_point.x;	
			vp->y=in->view_point.y;
			vp->z=in->view_point.z;
			ris+=1;
			}
		break;

		case(CS_NPX0):
	/* sposto X0 box scena 3d nella sua finestra */
			in->minx=i;
			clipbox(in->graf,in->minx,in->miny,
				in->graf->clipdx,in->graf->clipdy);
			in->agg_all=1;
			ris+=1;
			break;

		case(CS_NPY0):
	/* sposto Y0 box scena 3d nella sua finestra */
			in->miny=i;
			clipbox(in->graf,in->minx,in->miny,
				in->graf->clipdx,in->graf->clipdy);
			in->agg_all=1;
			ris+=1;
			break;
	
		case(CS_GCOLOR):
	/* cambio colore fondo a scena 3d */
			in->gcolor=i;
			in->agg_all=1;
			ris+=1;
			break;
			
		case(CS_ZBUF):
	/* setto flag per zbuffer come indicato */
		if (i!=NULL) i=c_zbuf(in);
		in->fzbuf=i;
		in->agg_all=1;
		ris+=1;
		break;

		}
	ct+=1;
	}

new_fov(in);

return(ris);
}

/*************************************
 ** FUNZIONE PER PASSARE DA INTERO  **
 ** A FIXPOINT.			    **
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a intero long   **
 **       con valore da convertire. **
 ** out-> puntatore a intero long   **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_int2fix(in,out)
REG(a0)long int *in;
REG(a1)long int *out;
{
long int bf,bf1;

bf=in[0];

/* calcolo massimo valore convertibile */
bf1=0x7fffffff >> SFIXV;

if (bf>bf1) return (1);
if (bf<-bf1) return (2);

out[0]=bf << SFIXV;

return(0);

} 

/*************************************
 ** FUNZIONE PER PASSARE DA SINGLE  **
 ** FLOAT A FIXPOINT.		    **
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a single float  **
 **       con valore da convertire. **
 ** out-> puntatore a intero long   **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_sfl2fix(in,out)
REG(a0)float *in;
REG(a1)long int *out;
{
long int max,it,frt;
float ifix;

it=in[0];
ifix=FIXV;

/* calcolo massimo valore convertibile */
max=0x7fffffff >> SFIXV;

if (it>=max) return (1);
if (it<=-max) return (2);

out[0]=in[0]*ifix;

return(0);


}

/*************************************
 ** FUNZIONE PER PASSARE DA DOUBLE  **
 ** FLOAT A FIXPOINT.		    **
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a double float  **
 **       con valore da convertire. **
 ** out-> puntatore a intero long   **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_dfl2fix(in,out)
REG(a0)double *in;
REG(a1)long int *out;
{
long int max,it,frt;
double ifix;

it=in[0];
ifix=FIXV;

/* calcolo massimo valore convertibile */
max=0x7fffffff >> SFIXV;

if (it>=max) return (1);
if (it<=-max) return (2);

out[0]=in[0]*ifix;

return(0);


}

/*************************************
 ** FUNZIONE PER PASSARE DA FIXPOINT**
 ** AD INTERO			    ** 
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a intero long   **
 **       con valore da convertire. **
 ** out-> puntatore a intero long   **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_fix2int(in,out)
REG(a0)long int *in;
REG(a1)long int *out;
{
long int i;

i=in[0];
if (i<~0L - FIXVM) i=i+FIXVM;

out[0]=i >> SFIXV;

return(0);

}

/*************************************
 ** FUNZIONE PER PASSARE DA FIXPOINT**
 ** AD SINGLE FLOAT		    ** 
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a intero long   **
 **       con valore da convertire. **
 ** out-> puntatore a single float  **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_fix2sfl(in,out)
REG(a0)long int *in;
REG(a1)float *out;
{
float fv,ifix;

ifix=FIXV;
fv=in[0];

out[0]=fv/ifix;

return(0);

}

/*************************************
 ** FUNZIONE PER PASSARE DA FIXPOINT**
 ** AD DOUBLE FLOAT		    ** 
 *************************************
 **** INPUT :			    **
 ** in -> puntatore a intero long   **
 **       con valore da convertire. **
 ** out-> puntatore a double float  **
 **       con valore convertito.    **
 **** OUTPUT:			    **
 ** ==0 -> tutto ok.		    **
 ** <>0 -> errore out non modificato**
 *************************************/
long int GD_fix2dfl(in,out)
REG(a0)long int *in;
REG(a1)double *out;
{
double fv,ifix;

ifix=FIXV;
fv=in[0];

out[0]=fv/ifix;

return(0);

}

/*************************************
 ** FUNZIONE PER CAMBIARE IL MODO   **
 ** VIDEO DI TRACCIAMENTO.          **
 *************************************
 **** INPUT :                       **
 ** in   -> valore >0 ritornato da  **
 **         display3d().            **
 ** mod  -> nuovo modo video.       **
 **** NOTA :			    **
 ** valori per mod :		    **
 ** 0 > JAM1 (over 2)		    **
 ** 1 > JAM2 (over 0) (def.)	    **
 ** 2 > COMPLEMENT (over 1) 	    **
 ** 4 > INVERSVID  (inverse 1)      **
 *************************************/
void GD_over(REG(a0)struct ambient3d *in,REG(d0)long int mod)
{

over(in->graf,mod);

}

/*************************************
 ** FUNZIONE PER CANCELLARE UN BOX  **
 ** NELLA FINESTRA .		    **
 *************************************
 **** INPUT :                       **
 ** in   -> valore >0 ritornato da  **
 **         display3d().            **
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
void GD_cls_b(REG(a0)struct ambient3d *in,REG(d0)long int x0,
	REG(d1)long int y0,REG(d2)long int x1,REG(d3)long int y1)
{
/*
cls_b(in->graf,x0,y0,x1,y1);
*/
}

/***************** FINE ROUTIN USABILI ESTERNAMENTE ********************/

/**************************************
 ** RICALCOLO VALORI FOV_WIDTH e     **
 ** FOV_HEIGHT.			     **
 **************************************/
void new_fov(struct ambient3d *in)
{

in->fov_w=((in->half_screen_width + FOV_M) << SFIXV)/
	((in->viewing_distance*in->zoom) >> SFIXV);
in->fov_h=((in->half_screen_height + FOV_M) * in->inv_aspect_ratio)/ 
	((in->viewing_distance*in->zoom) >> SFIXV);

}
