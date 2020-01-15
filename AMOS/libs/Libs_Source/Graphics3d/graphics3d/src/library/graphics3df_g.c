/*
**      $VER: graphics3Df_i.c 10.10 (16.02.98)
**
**      Internal functions for graphics3D.library
**
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
**
**	Note: this code is traslate from the blitzbasic 3d graphics engine 
**	      V 0.9 of Maciej R. Gorny.
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
#include "graphics3d2d.h"
#include "graphics3d2d_proto.h"

/*** funzioni esterne solo matematiche ***/
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
extern struct objectnode *pobj(struct ambient3d *in);
extern struct objectnode *resetobj(struct ambient3d *in);
extern struct objectnode *nextobj(struct ambient3d *in);


/******************************************************/
/** rimuove le facce posteriori dell'oggetto corrente**/
/** e calcola il flat shading dell'oggetto           **/
/******************************************************/
void removebackfacesandshade(in)
struct ambient3d *in;
{
struct objectnode *obj;
struct vector *vp, *ls;
struct vert1 *v0,*v1,*v2,*v3;
struct polygon *pol;
long int ms1,ms,al,sha_org,shading,curr_poly,dp,intensity;
struct vector u,v;
struct vector normal,norm,sight;
long int norml;
char col;
#ifdef DEBUG
char dbg[80];
#endif

vp=&in->view_point;
ls=&in->light_source;
obj=pobj(in);
shading=0x0F & obj->shade;
sha_org=shading;

ms=in->maxintensity;
ms1=ms << SFIXV;
al=in->ambient_light >> SFIXV;
for (curr_poly=0; curr_poly<obj->numpolys; curr_poly++)
   {
#ifdef DEBUG
sprintf(dbg,"polig=%ld\n",curr_poly);
write_dbg(dbg);
#endif
   shading=sha_org;
   col=0;
   pol=&obj->polys[curr_poly];   	
   pol->visible=1;
   if (pol->active==NULL) pol->visible=0;
   v0=&obj->vcamera[pol->vertexlist0];
   v1=&obj->vcamera[pol->vertexlist1];
   v2=&obj->vcamera[pol->vertexlist2];
   v3=&obj->vcamera[pol->vertexlist3];
   if (pol->numpoints>2 AND pol->active)
	{
	if (shading==FLAT OR shading==GORAUD OR pol->twosided==NULL)
		{
	/* se poligono a 1 faccia o flat o goraud shading calcolo normale al poligono */
		normalpol(v0,v1,v2,&normal);	
		}
	if (pol->twosided==NULL)
		{
	/* test per poligoni ad una faccia se visibili o meno */
		sight.x=vp->x - v0->x;
		sight.y=vp->y - v0->y;
		sight.z=vp->z - v0->z;
	
		if (dotproduct(&normal,&sight)<NULL) pol->visible=0;
		}
	}
   if (pol->visible>NULL AND pol->numpoints>2)
	{
	switch(shading)
		{
		case(GORAUD):
		case(FLAT):
	/* calcolo lunghezza normale poligono */
			dp=dotproduct(&normal,ls);
/*			if (pol->twosided!=NULL AND dp<NULL) dp=-dp;*/
			if (dp>NULL)
				{
				norml=vectormag3d(&normal);
				if (norml==NULL) norml=1;
				intensity=al+(ms1*dp)/norml;
				if (intensity>ms) intensity=ms;
				if (intensity<0) intensity=0;
        /* intensity e' compreso ora tra 0 e ms ,si usera' questo valore */
        /* per trovare l'indice di sfumatura */
				col=intensity;
#ifdef DEBUG
sprintf(dbg,"pol.col=%ld inte=%ld\n",pol->color,intensity);
write_dbg(dbg);
#endif
				}
			else
				{
#ifdef DEBUG
sprintf(dbg,"pol.col=%ld luce=%ld\n",pol->color,al);
write_dbg(dbg);
#endif
				col=al;
				}
			if (shading==GORAUD)
				{
				v0->color+=col;
				v1->color+=col;
				if (v0->npol==NULL) v0->color=col;
				if (v1->npol==NULL) v1->color=col;		
				v0->npol+=1;
				v1->npol+=1;
				if (pol->numpoints>2)
					{
					v2->color+=col;
					if (v2->npol==NULL) v2->color=col;
					v2->npol+=1;
					}
				if (pol->numpoints>3)
					{
					v3->color+=col;
					if (v3->npol==NULL) v3->color=col;
					v3->npol+=1;
					}
				}
			break;

		case(SOLID):
			col=(ms>>1);
			break;
	
		default:
	/* se tipo di shading <> da goraud,flat e solid si assume cosi' */
			col=0;
		}
	}
   pol->shade=col;
   }

}

/******************************************************/
/** crea la lista di tutti i poligoni visibili nella **/
/** frame corrente e li memorizza gia' proiettati    **/
/** e' gia' stato ottimizzato il piu' possibile.     **/
/** Ora si calcola la distanza tra il punto medio del**/
/** poligono e l'osservatore per il succ. riordino.  **/
/******************************************************/
void generatepolylist(in)
struct ambient3d *in;
{
long int *iwp;
long int zx,zy,zxp,zyp,id,fix1,fix,curr_poly,i,ii,mx,my,mz,x,y,z;
struct pixel *pt;
struct objectnode *obj;
struct vert1 *vc;
struct polygon *pol;
struct polytemp *wpl;

#ifdef DEBUG
char dbg[100];
#endif

if (in->iwpolys==NULL) return(0);

iwp=in->iwpolys;
pt=(struct pixel *)in->temp;

#ifdef DEBUG
sprintf(dbg,"pt=%ld\n",pt);
write_dbg(dbg);
#endif

obj=resetobj(in);
id=0;
curr_poly=0;
fix=(in->aspect_ratio*in->viewing_distance) >> SFIXV;
fix1=in->aspect_ratio;
zy=(fix*in->zoom) >> SFIXV;
zx=(in->viewing_distance*in->zoom) >> SFIXV;
zxp=in->zoom;
zyp=(in->aspect_ratio*in->zoom) >> SFIXV;

#ifdef DEBUG
sprintf(dbg,"\n--- ciclo generatepolylist ---\n");
write_dbg(dbg);
sprintf(dbg,"view distance=%ld fix=%ld\n",in->viewing_distance,fix);
write_dbg(dbg);
#endif

do 
   {	
   if (obj->clipped==0 AND obj->state!=0) 
	{
	/* se goraud shading e se non gia fatto normalizzo intensita' colori vertici */
	if ((0x0F & obj->shade)==GORAUD)
		{
		for(i=0 ;i<obj->numverts ;i++)
			{
			vc=&obj->vcamera[i];
			if (vc->npol!=NULL)
				{
#ifdef DEBUG
sprintf(dbg,"vert#%ld col=%ld npol=%ld\n",i,vc->color,vc->npol);
write_dbg(dbg);
#endif
				vc->color=vc->color/vc->npol;
				vc->npol=0;
#ifdef DEBUG
sprintf(dbg,"col=%ld npol=%ld\n",vc->color,vc->npol);
write_dbg(dbg);
#endif
				}
			}
		}
	/** proietto tutti i punti dell'oggetto corrente **/
	switch(in->projection_type)
		{
		case(PROSP_P) :
	/* uso proiezione prospettica */
			for(i=0 ;i<obj->numverts ;i++ ) 
				{
				vc=&obj->vcamera[i];
				z=vc->z;
				if (z==NULL) z=1;
/*
#ifdef DEBUG
sprintf(dbg,"Vertex=%ld\n",i);
write_dbg(dbg);
sprintf(dbg,"x=%ld y=%ld z=%ld z=%ld\n",vc->x,vc->y,vc->z,z);
write_dbg(dbg);
sprintf(dbg,"half_screen_w=%ld half_screen_h=%ld zx=%ld zy=%ld\n",in->half_screen_width,
	in->half_screen_height,zx,zy);
write_dbg(dbg);
#endif
*/
				x=in->half_screen_width +
					 (vc->x*zx)/z;
				y=in->half_screen_height -
					 (vc->y*zy)/z;
				if (x>16355) x=16355;
				if (x<-16355) x=-16355;
				if (y>16355) y=16355;
				if (y<-16355) y=-16355;
				pt[i].x=x;
				pt[i].y=y;
/*
#ifdef DEBUG
sprintf(dbg,"xp=%ld yp=%ld \n",pt[i].x,pt[i].y);
write_dbg(dbg);
#endif
*/		
				}
				break;
		case(PARAL_P) :
	/* uso proiezione parallela */
			for(i=0 ;i<obj->numverts ;i++ ) 
				{
				vc=&obj->vcamera[i];
				pt[i].x=in->half_screen_width + 
					((vc->x*zxp) >> (2*SFIXV));
				pt[i].y=in->half_screen_height + 
					((vc->y*zyp) >> (2*SFIXV));
				if (x>16355) x=16355;
				if (x<-16355) x=-16355;
				if (y>16355) y=16355;
				if (y<-16355) y=-16355;
				pt[i].x=x;
				pt[i].y=y;
				}
				break;
		}
	/* genero lista di poligoni gia' proiettati */
	vc=obj->vcamera;
	for(curr_poly=0 ;curr_poly<obj->numpolys ;curr_poly++) 
		{
		pol=&obj->polys[curr_poly];
		if (pol->visible!=NULL AND pol->clipped==NULL)
			{
	/* reinizializzo puntatore a indice su lista poligoni */
	/* per velocizzare il successivo riordino	      */
			if (id < in->max_polys)
			   {
			   wpl=&in->worldpolys[id];
			   iwp[id]=(long int )wpl;
			   mz=0;
			   mx=0;
			   my=0;
			   wpl->numpoints=pol->numpoints;
			   wpl->color=pol->color;
			   wpl->shade=pol->shade;
			   wpl->vmode=obj->shade;		
			   wpl->obj=obj->id;	
			   wpl->npol=curr_poly;
			   wpl->tmap=&pol->ptmap;	
			   i=pol->vertexlist0;
			   wpl->x1=pt[i].x;
			   wpl->y1=pt[i].y;
			   wpl->clp1=vc[i].color;
			   wpl->z1=vc[i].z;
			   mz+=wpl->z1;
			   mx+=wpl->x1;
			   my+=wpl->y1;	

			   if (pol->numpoints>=2)			
				{
				i=pol->vertexlist1;
				wpl->x2=pt[i].x;
				wpl->y2=pt[i].y;
				wpl->clp2=vc[i].color;
				wpl->z2=vc[i].z;
				mz+=wpl->z2;
			   	mx+=wpl->x2;
			   	my+=wpl->y2;	
				}

			   if (pol->numpoints>=3)		
				{
				i=pol->vertexlist2;
				wpl->x3=pt[i].x;
				wpl->y3=pt[i].y;
				wpl->clp3=vc[i].color;
				wpl->z3=vc[i].z;
			   	mz+=wpl->z3;
			   	mx+=wpl->x3;
			   	my+=wpl->y3;	
			
				wpl->x4=wpl->x1;
				wpl->y4=wpl->y1;	
				}

			   if (pol->numpoints==4) 
				{
				i=pol->vertexlist3;
				wpl->x4=pt[i].x;
				wpl->y4=pt[i].y;
				wpl->clp4=vc[i].color;
				wpl->z4=vc[i].z;
			   	mz+=wpl->z4;
			   	mx+=wpl->x4;
			   	my+=wpl->y4;	

				wpl->x5=wpl->x1;
				wpl->y5=wpl->y1;
				}
	/* calcolo punto medio del poligono */
			   ii=pol->numpoints << SFIXV;
			   mx/=ii;
			   my/=ii;
			   mz/=ii;
	/* quindi calcolo distanza media poligono (evito la radice ,non serve)*/
			   wpl->svalue=mx*mx + my*my + mz*mz;
/*
#ifdef DEBUG
sprintf(dbg,"dist=%ld\n",wpl->svalue);
write_dbg(dbg);
#endif
*/
			   id+=1;
			   }
			}
		}
	}
   obj=nextobj(in);
   }while(obj!=NULL);

in->total_polys=id;

/********************/
}

/************************************
 ** routin richiamata da quicksort **
 ** occhio e' recursiva.	   **
 ** I parametri non possono percio'**
 ** essere passati tramite registri**
 ************************************/
void qsort(lo0,hi0,pol,count)
long int lo0;
long int hi0;
long int *pol;
long int *count;
{
long int it, lo, hi, mid, t;
struct polytemp *wpl;

lo=lo0;
hi=hi0;
it=count[0];

if (hi0>lo0)
/* stabilisco arbitrariamente il pivot point nel mezzo dell'array */
	{
	wpl=(struct polytemp *)pol[(lo0+hi0)>>1];
	mid=wpl->svalue;

/* eseguo il loop finche non incrocio indici */
	while(lo<=hi)
/* trovo il primo elemento minore o uguale a mid partendo da sinistra */
		{
		wpl=(struct polytemp *)pol[lo];
		while(lo<hi0 AND wpl->svalue>mid)
			{
			lo++;
			wpl=(struct polytemp *)pol[lo];
			it++;
			}
/* trovo il primo elemento maggiore o uguale a mid partendo da destra */
		wpl=(struct polytemp *)pol[hi];
		while(hi>lo0 AND wpl->svalue<mid)
			{	
			hi--;
			wpl=(struct polytemp *)pol[hi];
			it++;
			}
/* se gli indici non si sono incrociati scambio elementi */
		if (lo<=hi)
			{
			t=pol[hi];
			pol[hi]=pol[lo];
			pol[lo]=t;
			lo++;
			hi--;
			}
		}
	}		

count[0]=it;

if (lo0<hi) qsort(lo0,hi,pol,count);

if (lo<hi0) qsort(lo,hi0,pol,count);

}

/******************************************************
 ** visualizza un gruppo di poligoni nella rastport  **
 ** corrente(purche di 3 o 4 lati). 		     **	
 ** E' ottimizzata il piu' possibile.		     **
 ******************************************************
 **** INPUT :					     ** 
 **  amb ->valore non 0 ritornato da GD_display3d(). **
 **  iwp  ->puntatore ad array di puntatori a strut- **
 **         ture polytemp.			     ** 
 **  total_polys ->n# totale elementi nell'array iwp **
 **  colb ->se >=0 allora poligoni con bordo di quel **
 **         colore.				     **
 **** OUTPUT:					     **
 ** nessuno.					     **
 ******************************************************/
void paintpol(amb,iwp,total_polys,colb)
struct ambient3d *amb;
long int *iwp;
long int total_polys;
long int colb;
{
struct RastPort *rast;
struct polytemp *wpl;
long int i,f;

#ifdef DEBUG
char dbg[100];
#endif

if (amb->iwpolys==NULL) return(0);

rast=amb->graf->rast;
f=rast->FgPen;

#ifdef DEBUG
sprintf(dbg,"ambient3d=%ld rast=%ld\n",amb,rast);
write_dbg(dbg);
#endif

for (i=0;i<total_polys;i++)
	{
	wpl=(struct polytemp *)iwp[i];
	/* visualizzo il poligono */ 
/** visualizza un poligono proiettato **/
	switch(wpl->numpoints)
		{
		case (1) :
	/* 1 vertice -> disegno un punto */
			pixel(amb,wpl);
			break;
		case (2) :
	/* 2 vertici -> disegno una linea */
			line(amb,wpl);
			break;
		case (3) :
	/* 3 vertici -> poligono triangolare disegno in base a wpl->vmode */
			if ((wpl->vmode & 0x0F)!=WIREF)
				{
				drw_tg(amb,wpl,colb);
				}
			else
				{
				line(amb,wpl);
				}
			break;
		case (4) :
	/* 4 vertici -> poligono quadrangolare disegno in base a wpl->vmode*/
			if ((wpl->vmode & 0x0F)!=WIREF)
				{
				drw_qg(amb,wpl,colb);
				}
			else
				{
				line(amb,wpl);
				}
			break;
		}
	}

SetAPen(rast,f);
}

/**********************************************
 ** effettuo ordinamento poligoni proiettati **
 ** via quicksort			     **
 ** mediamente 4 volte piu' veloce dello     ** 
 ** shellsort.				     **
 **********************************************
 **** INPUT :				     **
 ** len -> numero di poligoni da riordinare  **
 ** pol -> array di puntatori alle strutture **
 **        polytemp, da riordinare.          **
 **** OUTPUT:				     **
 ** n# di passi effettuati per l'ordinamento.** 
 **********************************************/
long int quicksort(len,pol)
long int len;
long int *pol;
{
long int itera;

itera=0;

if (len>NULL) qsort(0,len-1,pol,&itera);

return(itera);
}
/*******************************************************************/
