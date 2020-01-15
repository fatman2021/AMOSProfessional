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

/** prototipi locali **/
struct objectnode *resetobj(struct ambient3d *in);
struct objectnode *nextobj(struct ambient3d *in);
struct objectnode *pobj(struct ambient3d *in);

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

/************************************/
/* costruzione tavole seno e coseno */
/************************************/
void buildlookuptables(in)
struct ambient3d *in;
{
long int *sn,*cn,i,ii;
long int t[]=
{    
/** val. seno angolo (0,90) e moltiplicato per 256 **/
    0,4,9,13,17,22,26,30,35,39,43,47,52,
    56,60,65,69,73,77,81,85,89,93,98,101,105,
    109,113,117,121,125,129,132,136,140,143,
    147,151,154,157,161,164,167,171,174,177,
    180,183,186,189,192,195,198,200,203,206,
    208,211,213,216,218,220,222,225,227,229,
    230,232,234,236,238,239,241,242,243,245,
    246,247,248,249,250,251,252,253,253,254,
    254,255,255,255,256
};

/*
#ifdef DEBUG
char dbg[80];
#endif
*/

sn=in->sintable;
cn=in->costable;
/** val. seno angolo (0,90) e moltiplicato per 1024 **/
/*
t:=[0,17,35,53,71,89,
    106,124,142,160,177,195,212,230,247,264,282,299,
    316,333,350,366,383,399,416,432,448,464,480,496,
    511,527,542,557,572,587,601,615,630,644,657,671,
    684,698,711,723,736,748,760,772,784,795,806,817,
    828,838,848,858,868,877,886,895,903,912,920,927,
    935,942,949,955,962,968,973,979,984,988,993,997,
    1001,1005,1008,1011,1013,1016,1018,1020,1021,1022,
    1023,1023,1024]:LONG
*/
ii=0;
for(i=0; i<361; i++)
	{
	if (i<91)
		{
		sn[i]=t[ii];
		cn[i]=t[90-ii];
		}
	else if (i<181) 
		{
		sn[i]=t[90-ii];
		cn[i]=-t[ii];
		}
	else if (i<271)
		{
		sn[i]=-t[ii];
		cn[i]=-t[90-ii];
		}
	else
		{
		sn[i]=-t[90-ii];
		cn[i]=t[ii];
		}
/*
#ifdef DEBUG
sprintf(dbg,"t[%ld]=%ld sn[%ld]=%ld cn[%ld]=%ld\n",ii,t[ii],i,sn[i],i,cn[i]);
write_dbg(dbg);
#endif
*/
	ii++;
	if (ii>90) ii=1;
	}
}

/*******************************************************/
/** crea la matrice di trasformazione inversa globale **/
/** usata per passare da coordinate del mondo in      **/
/** coordinate della camera			      **/
/** Crea matrice in.global_view per capirci.	      **/
/*******************************************************/
void createworldtocamera(in)
struct ambient3d *in;
{
long int temp,active_axes;
struct matrix4x4 translate,rotate_x,rotate_y,rotate_z;
struct matrix4x4 result_1,result_2,*g_v;
struct vector *v_p;
struct dir3d *v_a;
long int *cos,*sin;

cos=in->costable;
sin=in->sintable;
v_a=&in->view_angle;
v_p=&in->view_point;
g_v=&in->global_view;

active_axes=0;

matidentity4x4(&translate);
translate.r3c0=-v_p->x;
translate.r3c1=-v_p->y;
translate.r3c2=-v_p->z;

if (v_a->angx!=NULL AND v_a->angx!=360)
	{
	matidentity4x4(&rotate_x);
	rotate_x.r1c1=cos[v_a->angx];
	rotate_x.r1c2=sin[v_a->angx];
	rotate_x.r2c1=-sin[v_a->angx];
	rotate_x.r2c2=cos[v_a->angx];
	active_axes=active_axes+1;
	}

if (v_a->angy!=NULL AND v_a->angy!=360)
	{
	matidentity4x4(&rotate_y);
	rotate_y.r0c0=cos[v_a->angy];
	rotate_y.r0c2=sin[v_a->angy];
	rotate_y.r2c0=-sin[v_a->angy];
	rotate_y.r2c2=cos[v_a->angy];
	active_axes=active_axes+2;
	}

if (v_a->angz!=NULL AND v_a->angz!=360)
	{
	matidentity4x4(&rotate_z);
	rotate_z.r0c0=cos[v_a->angz];
	rotate_z.r0c1=sin[v_a->angz];
	rotate_z.r1c0=-sin[v_a->angz];
	rotate_z.r1c1=cos[v_a->angz];
	active_axes=active_axes+4;
	}

switch (active_axes)
	{
	case (0):
		matcopy4x4(&translate,g_v);
		break;

	case (1):
		matmult4x4s(&translate,&rotate_x,g_v);
/*
		matcopy4x4(&rotate_x,g_v);
		g_v->r3c0=-v_p->x;
		temp=-v_p->y*cos[v_a->angx] + v_p->z*sin[v_a->angx];
		g_v->r3c1=temp >> SFIXV;
		temp=v_p->y*sin[v_a->angx] - v_p->z*cos[v_a->angx];
		g_v->r3c2=temp >> SFIXV;
*/
		break;

	case (2):
		matmult4x4s(&translate,&rotate_y,g_v);
/*
		matcopy4x4(&rotate_y,g_v);
		temp=-v_p->x*cos[v_a->angy]+v_p->z*sin[v_a->angy];
		g_v->r3c0=temp >> SFIXV;
		g_v->r3c1=-v_p->y;
		temp=-v_p->x*sin[v_a->angy]-v_p->z*cos[v_a->angy];
		g_v->r3c2=temp >> SFIXV;
*/
		break;

	case (3):
		matmult4x4s(&translate,&rotate_x,&result_1);
		matmult4x4s(&result_1,&rotate_y,g_v);
		break;

	case (4):
		matmult4x4s(&translate,&rotate_z,g_v);
/*
		matcopy4x4(&rotate_z,g_v);
		temp=v_p->x*cos[v_a->angz]-v_p->y*sin[v_a->angz];
		g_v->r3c0=temp >> SFIXV;
		temp=-v_p->x*sin[v_a->angz]-v_p->y*cos[v_a->angz];
		g_v->r3c1=temp >> SFIXV;
		g_v->r3c3=-v_p->z;
*/
		break;

	case (5):
		matmult4x4s(&translate,&rotate_x,&result_1);
		matmult4x4s(&result_1,&rotate_z,g_v);
		break;

	case (6):
		matmult4x4s(&translate,&rotate_y,&result_1);
		matmult4x4s(&result_1,&rotate_z,g_v);
		break;

	case (7):
		matmult4x4s(&translate,&rotate_x,&result_1);
		matmult4x4s(&result_1,&rotate_y,&result_2);
		matmult4x4s(&result_2,&rotate_z,g_v);
		
	}
}

/*******************************************************
 ** trasla le coordinate locali dell'oggetto corrente **
 ** nelle coordinate del mondo 			      **
 *******************************************************
 *** INPUT :					       * 
 * in -> valore > 0 restituito da display3d.	       *
 *** OUTPUT:					       *
 * nessuno.					       *
 *******************************************************/
void localtoworld(in)
struct ambient3d *in;
{
struct objectnode *obj;
long int index;
struct vertex *vl;
struct vert1 *vg;
struct polygon *pl;
long int wx,wy,wz;

obj=pobj(in);
vg=obj->vcamera;
vl=obj->vlocal;
pl=obj->polys;
wx=obj->worldposx;
wy=obj->worldposy;
wz=obj->worldposz;
for (index=0; index<obj->numverts; index++)
	{
	vg[index].x=vl[index].x+wx;
	vg[index].y=vl[index].y+wy;
	vg[index].z=vl[index].z+wz;
	}
/* resetta flag di invisibilita' */
for (index=0; index<obj->numpolys; index++)
	{
	pl[index].visible=1;
	pl[index].clipped=0;
	}
}

/***************************************************
 ** converte le coordinate nel mondo dell'oggetto **
 ** corrente nelle coordinate della camera        **
 ***************************************************
 *** INPUT :				 	   * 
 * in -> valore > 0 restituito da display3d.	   *
 *** OUTPUT:					   *
 * nessuno.					   *
 ***************************************************/
void worldtocamera(in)
struct ambient3d *in;
{
struct objectnode *obj;
long int index,temp,tempx,tempy,tempz,active_axes;
struct vert1 *vc;
struct matrix4x4 gv,*g_v;
struct dir3d *vang;

obj=pobj(in);
vc=obj->vcamera;
vang=&in->view_angle;
g_v=&in->global_view;

active_axes=0;

if (vang->angx!=NULL) active_axes=active_axes+1; 
if (vang->angy!=NULL) active_axes=active_axes+2;
if (vang->angz!=NULL) active_axes=active_axes+4;

switch (active_axes)
	{
	case (0):
		for (index=0; index<obj->numverts; index++)
			{	
			vc[index].x=vc[index].x+g_v->r3c0;
			vc[index].y=vc[index].y+g_v->r3c1;
			vc[index].z=vc[index].z+g_v->r3c2;
			}
		break;
	case (1):
		for (index=0; index<obj->numverts; index++)
			{	
			vc[index].x=vc[index].x+g_v->r3c0;
			tempy=vc[index].y*g_v->r1c1+vc[index].z*g_v->r2c1;
			tempz=vc[index].y*g_v->r1c2+vc[index].z*g_v->r2c2;
			vc[index].z=(tempz >> SFIXV)+g_v->r3c2;
			vc[index].y=(tempy >> SFIXV)+g_v->r3c1;
			}
		break;

	case (2):
		for (index=0; index<obj->numverts; index++)
			{	
			tempx=vc[index].x*g_v->r0c0+vc[index].z*g_v->r2c0;
			tempz=vc[index].x*g_v->r0c2+vc[index].z*g_v->r2c2;
			vc[index].y=vc[index].y+g_v->r3c1;
			vc[index].z=(tempz >> SFIXV)+g_v->r3c2;
			vc[index].x=(tempx >> SFIXV)+g_v->r3c0;
			}
		break;

	case (4):
		for (index=0; index<obj->numverts; index++)
			{	
			tempx=vc[index].x*g_v->r0c0+vc[index].y*g_v->r1c0;
			tempy=vc[index].x*g_v->r0c1+vc[index].y*g_v->r1c1;
			vc[index].y=(tempy >> SFIXV)+g_v->r3c1;
			vc[index].x=(tempx >> SFIXV)+g_v->r3c0;
			vc[index].z=vc[index].z+g_v->r3c2;
			}
		break;

	default :
		for (index=0; index<obj->numverts; index++)
			{	
			tempx=vc[index].x*g_v->r0c0+vc[index].y*g_v->r1c0+
				vc[index].z*g_v->r2c0;
			tempy=vc[index].x*g_v->r0c1+vc[index].y*g_v->r1c1+
				vc[index].z*g_v->r2c1;		
			tempz=vc[index].x*g_v->r0c2+vc[index].y*g_v->r1c2+
				vc[index].z*g_v->r2c2;		
			vc[index].x=(tempx >> SFIXV)+g_v->r3c0;
			vc[index].y=(tempy >> SFIXV)+g_v->r3c1;
			vc[index].z=(tempz >> SFIXV)+g_v->r3c2;
			}
	}	
}

/**********************************************
 ** riporto oggetto attuale sul primo e      **
 ** resituisco puntatore a oggetto.          **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 *** OUTPUT:				      *
 * puntatore a struttura 1# oggetto.	      *
 **********************************************/
struct objectnode *resetobj(in)
struct ambient3d *in;
{

in->attuale=0;

return (pobj(in));
}

/**********************************************
 ** sposto oggetto attuale su prossimo se    **
 ** finiti restituisco 0 altrimenti puntore  **
 ** a oggetto.				     **
 **********************************************
 *** INPUT :				      * 
 * in -> valore > 0 restituito da display3d.  *
 *** OUTPUT:				      *
 * >0 - puntatore a oggetto successivo.       *
 * =0 - oggetti finiti.			      *
 **********************************************/
struct objectnode *nextobj(in)
struct ambient3d *in;
{

if (in->total_objects==NULL) return(0);
if (in->attuale>=in->total_objects-1) return(0); 

in->attuale=in->attuale+1;

return (pobj(in));
} 

/*******************************************
 ** restituisce indirizzo oggetto attuale **
 ** o 0 se nessun oggetto presente.       **
 *******************************************/

struct objectnode *pobj(in)
struct ambient3d *in;
{

if (in->total_objects==NULL) return(0);

return(&in->objects[in->attuale]);

}

/************************************************
 ** aggiorna tutti i valori precalcolati sul   **
 ** oggetto corrente.	  		       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void aggobj(in)
struct ambient3d *in;
{

computeobjectbox(in);

}

/**********************************************/
/** calcola il bounding box dell'oggetto at- **/
/** tuale per il controllo delle collisioni  **/
/**********************************************/
void computeobjectbox(in)
struct ambient3d *in;
{
struct objectnode *ob;
struct vertex *vt;
long int xmax,ymax,zmax,xmin,ymin,zmin;
long int x,y,z,i;

ob=pobj(in);

vt=ob->vlocal;

xmax=-2147483645;
ymax=-2147483645;
zmax=-2147483645;
xmin=2147483645;
ymin=2147483645;
zmin=2147483645;

for(i=0 ;i<ob->numverts ; i++)
	{
	x=vt[i].x;
	y=vt[i].y;
	z=vt[i].z;
	if (x>xmax) xmax=x;
	if (x<xmin) xmin=x;
	if (y>ymax) ymax=y;
	if (y<ymin) ymin=y;
	if (z>zmax) zmax=z;
	if (z<zmin) zmin=z;
	}

ob->xmax=xmax;
ob->ymax=ymax;
ob->zmax=zmax;
ob->xmin=xmin;
ob->ymin=ymin;
ob->zmin=zmin;

}

/*****************************************************/
/** determina se l'intero oggetto corrente e' fuori **/
/** dal volume compreso nella visuale o inattivo.   **/
/** Se si rimosso ,ritorna un valore <>0	    **/
/*****************************************************/
long int t_removeobject(in)
struct ambient3d *in;
{
long int n_z,f_z;
long int zvd,temp,x_bsphere,y_bsphere,z_bsphere;
long int xmax,ymax,zmax,xmin,ymin,zmin,x_compare,y_compare;
struct objectnode *obj;
struct matrix4x4 *g_v;

#ifdef DEBUG
char dbg[100];
#endif

/* trasformo da interi a fixpoint */
f_z=in->far_z * FIXV;
n_z=in->near_z * FIXV;

zvd=(in->viewing_distance*in->zoom)>>SFIXV;

obj=pobj(in);
g_v=&in->global_view;

/* test se oggetto disattivato ,quindi invisibile */
if (!obj->state) return(1);
	
/* segnalo oggetto non clippato per default */
obj->clipped=0;

xmax=obj->xmax;
ymax=obj->ymax;
zmax=obj->zmin;
xmin=obj->xmin;
ymin=obj->ymin;
zmin=obj->zmax;

temp=obj->worldposx*g_v->r0c0 + obj->worldposy*g_v->r1c0 +
	obj->worldposz*g_v->r2c0;
x_bsphere=(temp>>SFIXV) + g_v->r3c0;
temp=obj->worldposx*g_v->r0c1 + obj->worldposy*g_v->r1c1 +
      obj->worldposz*g_v->r2c1;
y_bsphere=(temp>>SFIXV) + g_v->r3c1;
temp=obj->worldposx*g_v->r0c2 + obj->worldposy*g_v->r1c2 +
      obj->worldposz*g_v->r2c2;
z_bsphere=(temp>>SFIXV) + g_v->r3c2;

/* clip con bounding box */
if (in->clip_mode==ZPLANE)
	{
	if (z_bsphere+zmax>f_z OR z_bsphere+zmin<n_z) 
		{
		obj->clipped=1;
		return(2);
		}
	else
		{
		return(0);
		}	
	}
else   
	{
	/* esegue un completo test su XYZ */
	if ((z_bsphere+zmax)>f_z OR (z_bsphere+zmin)<n_z)
		{
		obj->clipped=1;
		return(3);
		}
	temp=in->half_screen_width*z_bsphere;
	x_compare=temp/zvd;
	if ((x_bsphere+xmin)>x_compare OR (x_bsphere+xmax)<-x_compare)
		{
		obj->clipped=1;
		return(4);
		}
	temp=(in->half_screen_height*z_bsphere)/zvd;
	y_compare=(temp*in->inv_aspect_ratio) >> SFIXV;
	if ((y_bsphere+ymin)>y_compare OR (y_bsphere+ymax)<-y_compare)
		{
		obj->clipped=1;
		return(5);
		}
	}

return(0);
}

/****************************************************/
/** clippa le coordinate della camera dell'oggetto **/
/** corrente rispetto al volume della visuale      **/
/****************************************************/
void clipobject3d(in)
struct ambient3d *in;
{
long int n_z, f_z, curr_poly;
long int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
long int x1_cmp, y1_cmp, x2_cmp, y2_cmp, x3_cmp, y3_cmp, x4_cmp, y4_cmp;
long int vert0, vert1, vert2, vert3, fov_width, fov_height;
struct objectnode *obj;
struct vert1 *vc;
struct polygon *pol;

obj=pobj(in);

vc=obj->vcamera;
pol=obj->polys;

/* converto in fixpoint */
n_z=in->near_z*FIXV;
f_z=in->far_z*FIXV;

/*zvd=(in->viewing_distance*in->zoom)>>SFIXV;*/

if (in->clip_mode==ZPLANE)
	{
/* cerca di clippare ogni poligono con il volume della visuale */
	for (curr_poly=0 ;curr_poly<obj->numpolys ;curr_poly++)
		{
	/* test di quanti lati */ 
		switch(pol[curr_poly].numpoints)
			{
			case(1):
				z1=vc[pol[curr_poly].vertexlist0].z;
				z2=z1;
				z3=z1;
				z4=z4;
				break;

			case(2):
				z1=vc[pol[curr_poly].vertexlist0].z;
				z2=vc[pol[curr_poly].vertexlist1].z;
				z3=z2;
				z4=z2;
				break;

			case(3):
				z1=vc[pol[curr_poly].vertexlist0].z;
				z2=vc[pol[curr_poly].vertexlist1].z;
				z3=vc[pol[curr_poly].vertexlist2].z;
				z4=z3;
				break;

			case(4):
				z1=vc[pol[curr_poly].vertexlist0].z;
				z2=vc[pol[curr_poly].vertexlist1].z;
				z3=vc[pol[curr_poly].vertexlist2].z;
				z4=vc[pol[curr_poly].vertexlist3].z;
				break;
			}

		if ((z1<n_z AND z2<n_z AND z3<n_z AND z4<n_z) OR
		   (z1>f_z AND z2>f_z AND z3>f_z AND z4>f_z))
			pol[curr_poly].clipped=1;
		}
	}
else
	{
/* FRUSTUM MODE CLIP */
	/* calcolo i campi visivi in fixpoint */
/*
	fov_width=((in->half_screen_width)>>SFIXV)/zvd;
	fov_height=(((in->half_screen_height)*in->inv_aspect_ratio) / zvd);
*/
fov_width=in->fov_w;
fov_height=in->fov_h;
	for (curr_poly=0 ;curr_poly<obj->numpolys ;curr_poly++)		
		{
	/* test di quanti lati */
		switch(pol[curr_poly].numpoints)
			{
			case(1):
				vert0=pol[curr_poly].vertexlist0;
				x1=vc[vert0].x;
				y1=vc[vert0].y;
				z1=vc[vert0].z;
				x2=x1;
				y2=y1;
				z2=z1;
				x3=x1;
				y3=y1;
				z3=z1;
				x4=x1;
				y4=y1;
				z4=z1;
				break;
			case(2):
				vert0=pol[curr_poly].vertexlist0;
				vert1=pol[curr_poly].vertexlist1;
				x1=vc[vert0].x;
				y1=vc[vert0].y;
				z1=vc[vert0].z;
				x2=vc[vert1].x;
				y2=vc[vert1].y;
				z2=vc[vert1].z;
				x3=x2;
				y3=y2;
				z3=z2;
				x4=x2;
				y4=y2;
				z4=z2;
				break;
			case(3):
				vert0=pol[curr_poly].vertexlist0;
				vert1=pol[curr_poly].vertexlist1;
				vert2=pol[curr_poly].vertexlist2;	
				x1=vc[vert0].x;
				y1=vc[vert0].y;
				z1=vc[vert0].z;
				x2=vc[vert1].x;
				y2=vc[vert1].y;
				z2=vc[vert1].z;
				x3=vc[vert2].x;
				y3=vc[vert2].y;
				z3=vc[vert2].z;
				x4=x3;
				y4=y3;
				z4=z3;
				break;
			case(4):
				vert0=pol[curr_poly].vertexlist0;
				vert1=pol[curr_poly].vertexlist1;
				vert2=pol[curr_poly].vertexlist2;	
				vert3=pol[curr_poly].vertexlist3;
				x1=vc[vert0].x;
				y1=vc[vert0].y;
				z1=vc[vert0].z;
				x2=vc[vert1].x;
				y2=vc[vert1].y;
				z2=vc[vert1].z;
				x3=vc[vert2].x;
				y3=vc[vert2].y;
				z3=vc[vert2].z;
				x4=vc[vert3].x;
				y4=vc[vert3].y;
				z4=vc[vert3].z;
				break;
			}
		if (z1<n_z AND z2<n_z AND z3<n_z AND z4<n_z) 
			{
			pol[curr_poly].clipped=1;
			continue;
			}
		if (z1>f_z AND z2>f_z AND z3>f_z AND z4>f_z)
			{
			pol[curr_poly].clipped=1;
			continue;
			}

		x1_cmp=(fov_width*z1) >> SFIXV;
		x2_cmp=(fov_width*z2) >> SFIXV;
		x3_cmp=(fov_width*z3) >> SFIXV;
		x4_cmp=(fov_width*z4) >> SFIXV;

		if ((x1<-x1_cmp AND x2<-x2_cmp AND x3<-x3_cmp AND x4<-x4_cmp)
		   OR (x1>x1_cmp AND x2>x2_cmp AND x3>x3_cmp AND x4>x4_cmp))
			{
			pol[curr_poly].clipped=1;
			continue;
			}
		y1_cmp=(fov_height*z1) >> SFIXV;
		y2_cmp=(fov_height*z2) >> SFIXV;
		y3_cmp=(fov_height*z3) >> SFIXV;
		y4_cmp=(fov_height*z4) >> SFIXV;

		if ((y1<-y1_cmp AND y2<-y2_cmp AND y3<-y3_cmp AND y4<-y4_cmp)
		   OR (y1>y1_cmp AND y2>y2_cmp AND y3>y3_cmp AND y4>y4_cmp))
			{
			pol[curr_poly].clipped=1;
			continue;
			}
		}
	}
}	

/*******************************************************************/
