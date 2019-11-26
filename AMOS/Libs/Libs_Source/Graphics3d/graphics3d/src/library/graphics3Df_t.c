/*
**      $VER: graphics3Df_t.c 10.01 (01.11.97)
**
**      External functions for graphics3D.library
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
#include "graphics3Df_proto.h"
#include "graphics3D2d_proto.h"

 /* Please note, that &PovedtBase always resides in register __a6 as well,
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

/**********************************************************/

/****************************************************
 ** Routin per la gestione della grafica, in stile **
 ** 2.0                                            ** 
 ** (c) 1994 BIANCA HARD&SOFT Vers:1.00            **
 ****************************************************/

/************ FUNZIONI 3D (trasformazioni oggetti) **********************/

/************************************************
 ** sposta origine oggetto attuale.	       **
 ** Lavora SEMPRE sulle coordinate iniziali,   **
 ** quindi occorre cumulare le eventuali varia-**
 ** zioni di posizione all'esterno di questa   **
 ** routin .				       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * dx -> valore spostamento su asse x (oggetto) *
 *       (valore in FIXPOINT).			*
 * dy -> valore spostamento su asse y (oggetto) *
 *       (valore in FIXPOINT).			*
 * dz -> valore spostamento su asse z (oggetto) *
 *       (valore in FIXPOINT).			*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_translateobject(in,dx,dy,dz)
REG(a0)struct ambient3d *in;
REG(d0)long int dx;
REG(d1)long int dy;
REG(d2)long int dz;
{
struct objectnode *obj;
struct vertex *vo,*vl;
long int curr_vertex;

obj=pobj(in);
if (obj==NULL) return(0);

vo=obj->vlocal;
vl=obj->vorig;

if (obj->trasf&0x01!=NULL) vl=obj->vlocal;

for(curr_vertex=0 ; curr_vertex<obj->numverts ; curr_vertex++)
	{
	vo[curr_vertex].x=vl[curr_vertex].x+dx;
	vo[curr_vertex].y=vl[curr_vertex].y+dy;
	vo[curr_vertex].z=vl[curr_vertex].z+dz;
	}

obj->trasf |= 0x01;

}

/************************************************
 ** posiziona origine oggetto attuale in modo  **
 ** assoluto.				       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * dx -> valore posizione su asse x             *
 *       (valore in FIXPOINT).			*
 * dy -> valore posizione su asse y             *
 *       (valore in FIXPOINT).			*
 * dz -> valore posizione su asse z             *
 *       (valore in FIXPOINT).			*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_positionobject(in,x,y,z)
REG(a0)struct ambient3d *in;
REG(d0)long int x;
REG(d1)long int y;
REG(d2)long int z;
{
struct objectnode *obj;

obj=pobj(in);
if (obj==NULL) return(0);

obj->worldposx=x;
obj->worldposy=y;
obj->worldposz=z;

obj->trasf |= 0x00;

}

/************************************************
 ** riscala oggetto attuale sui tre assi.      **
 ** Lavora SEMPRE sulle coordinate iniziali,   **
 ** quindi occorre cumulare le eventuali varia-**
 ** zioni di scala all'esterno di questa routin**
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * xscale_fact -> valore riscalatura su asse x  *
 *		  (valore in FIXPOINT).		*
 * yscale_fact -> valore riscalatura su asse y  *
 *		  (valore in FIXPOINT).		*
 * zscale_fact -> valore riscalatura su asse z  *
 *		  (valore in FIXPOINT).		*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_scaleobject(in,xscale_fact,yscale_fact,zscale_fact)
REG(a0)struct ambient3d *in;
REG(d0)long int xscale_fact;
REG(d1)long int yscale_fact;
REG(d2)long int zscale_fact;
{
struct objectnode *obj;
struct vertex *vl,*vo;
long int curr_vertex;

obj=pobj(in);
if (obj==NULL) return(0);
vo=obj->vlocal;
vl=obj->vorig;

if (xscale_fact==FIXV AND yscale_fact==FIXV AND zscale_fact==FIXV) return(0);
if (obj->trasf&0x01!=NULL) vl=obj->vlocal;

for(curr_vertex=0 ; curr_vertex<obj->numverts ; curr_vertex++)
	{
	vo[curr_vertex].x=(vl[curr_vertex].x*xscale_fact) >> SFIXV;
	vo[curr_vertex].y=(vl[curr_vertex].y*yscale_fact) >> SFIXV;
	vo[curr_vertex].z=(vl[curr_vertex].z*zscale_fact) >> SFIXV;
	}

obj->trasf |= 0x01;

}

/************************************************
 ** ruota oggetto attuale sui tre assi .       **
 ** Lavora SEMPRE sulle coordinate iniziali,   **
 ** quindi occorre cumulare le eventuali varia-**
 ** zioni di rot. all'esterno di questa routin **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * angle_x -> valore rotazione su asse x.       *
 * 	      (in gradi INTERO)			*
 * angle_y -> valore rotazione su asse y.       *
 * 	      (in gradi INTERO)			*
 * angle_z -> valore rotazione su asse z.       *
 * 	      (in gradi INTERO)			*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_rotateobject(in,angle_x,angle_y,angle_z)
REG(a0)struct ambient3d *in;
REG(d0)long int angle_x;
REG(d1)long int angle_y;
REG(d2)long int angle_z;
{
struct objectnode *obj;
struct vertex *vo,*vl;
long int *sin,*cos;
long int i,product;
struct matrix4x4 rotate_x;
struct matrix4x4 rotate_y;
struct matrix4x4 rotate_z;
struct matrix4x4 rot;
struct matrix4x4 temp;
#ifdef DEBUG
char dbg[100];
#endif

obj=pobj(in);
if (obj==NULL) return(0);
vo=obj->vlocal;
vl=obj->vorig;
if (obj->trasf&0x01 != NULL) vl=obj->vlocal;
sin=in->sintable;
cos=in->costable;

product=0;

matidentity4x4(&rot);

if (angle_x<0 OR angle_x>360)
	{
	angle_x-=(angle_x/360)*360;
	if (angle_x<0) angle_x+=360;
	}

if (angle_y<0 OR angle_y>360)
	{
	angle_y-=(angle_y/360)*360;
	if (angle_y<0) angle_y+=360;
	}

if (angle_z<0 OR angle_z>360)
	{
	angle_z-=(angle_z/360)*360;
	if (angle_z<0) angle_z+=360;
	}

#ifdef DEBUG
sprintf(dbg,"ax=%ld ay=%ld az=%ld\n",angle_x,angle_y,angle_z);
write_dbg(dbg);
#endif

if (angle_x!=0 AND angle_x!=360) product+=4;
if (angle_y!=0 AND angle_y!=360) product+=2;
if (angle_z!=0 AND angle_z!=360) product+=1;

switch (product)
	{
	case(1):
		rot.r0c0=cos[angle_z];
		rot.r0c1=sin[angle_z];
		rot.r1c0=-sin[angle_z];
		rot.r1c1=cos[angle_z];
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0+vl[i].y*rot.r1c0) >> SFIXV;
			vo[i].y=(vl[i].x*rot.r0c1+vl[i].y*rot.r1c1) >> SFIXV;
			vo[i].z=vl[i].z;
			}
		obj->trasf|=0x01;
		break;
	case(2):
		rot.r0c0=cos[angle_y];
		rot.r0c2=sin[angle_y];
		rot.r2c0=-sin[angle_y];
		rot.r2c2=cos[angle_y];
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0+vl[i].z*rot.r2c0) >> SFIXV;
			vo[i].z=(vl[i].x*rot.r0c2+vl[i].z*rot.r2c2) >> SFIXV;
			vo[i].y=vl[i].y;
			}
		obj->trasf|=0x01;
		break;
	case(3):
		rot.r0c0=(cos[angle_y]*cos[angle_z]) >> SFIXV;
		rot.r0c1=(cos[angle_y]*sin[angle_z]) >> SFIXV;
		rot.r0c2=sin[angle_y];
		rot.r1c0=-sin[angle_z];
		rot.r1c1=cos[angle_z];
		rot.r2c0=(-sin[angle_y]*cos[angle_z]) >> SFIXV;
		rot.r2c1=(-sin[angle_y]*sin[angle_z]) >> SFIXV;
		rot.r2c2=cos[angle_y];
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0 + vl[i].y*rot.r1c0 +
				vl[i].z*rot.r2c0) >> SFIXV;
			vo[i].y=(vl[i].x*rot.r0c1 + vl[i].y*rot.r1c1 +
				vl[i].z*rot.r2c1) >> SFIXV;
			vo[i].z=(vl[i].x*rot.r0c2+vl[i].z*rot.r2c2) >> SFIXV;
			}
		obj->trasf|=0x01;
		break;
	case(4):
		rot.r1c1=cos[angle_x];
		rot.r1c2=sin[angle_x];
		rot.r2c1=-sin[angle_x];
		rot.r2c2=cos[angle_x];
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].y=(vl[i].y*rot.r1c1+vl[i].z*rot.r2c1) >> SFIXV;
			vo[i].z=(vl[i].y*rot.r1c2+vl[i].z*rot.r2c2) >> SFIXV;
			vo[i].x=vl[i].x;
			}
		obj->trasf|=0x01;
		break;
	case(5):
		rot.r0c0=cos[angle_z];
		rot.r0c1=sin[angle_z];
		rot.r1c0=(-cos[angle_x]*sin[angle_z]) >> SFIXV;
		rot.r1c1=(cos[angle_x]*cos[angle_z]) >> SFIXV;
		rot.r1c2=sin[angle_x];
		rot.r2c0=(sin[angle_x]*sin[angle_z]) >> SFIXV;
		rot.r2c1=(-sin[angle_x]*cos[angle_z]) >> SFIXV;
		rot.r2c2=cos[angle_x];
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0 + vl[i].y*rot.r1c0 +
				vl[i].z*rot.r2c0) >> SFIXV;
			vo[i].y=(vl[i].x*rot.r0c1 + vl[i].y*rot.r1c1 +
				vl[i].z*rot.r2c1) >> SFIXV;
			vo[i].z=(vl[i].y*rot.r1c2+vl[i].z*rot.r2c2) >> SFIXV;
			}
		obj->trasf|=0x01;
		break;
	case(6):
		rot.r0c0=cos[angle_y];
		rot.r0c2=sin[angle_y];
		rot.r1c0=(-sin[angle_x]*sin[angle_y]) >> SFIXV;
		rot.r1c1=cos[angle_x];
		rot.r1c2=(sin[angle_x]*cos[angle_y]) >> SFIXV;
		rot.r2c0=(-cos[angle_x]*sin[angle_y]) >> SFIXV;
		rot.r2c1=-sin[angle_x];
		rot.r2c2=(cos[angle_x]*cos[angle_y]) >> SFIXV;
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0 + vl[i].y*rot.r1c0+
				vl[i].z*rot.r2c0) >> SFIXV;
			vo[i].y=(vl[i].y*rot.r1c1+vl[i].z*rot.r2c1) >> SFIXV;
			vo[i].z=(vl[i].x*rot.r0c2 + vl[i].y*rot.r1c2 +
				vl[i].z*rot.r2c2) >> SFIXV;
			}
		obj->trasf|=0x01;
		break;
	case(7):
		matidentity4x4(&rotate_x);
		rotate_x.r1c1=cos[angle_x];
		rotate_x.r1c2=sin[angle_x];
		rotate_x.r2c1=-sin[angle_x];
		rotate_x.r2c2=cos[angle_x];
		matidentity4x4(&rotate_y);
		rotate_y.r0c0=cos[angle_y];
		rotate_y.r0c2=sin[angle_y];
		rotate_y.r2c0=-sin[angle_y];
		rotate_y.r2c2=cos[angle_y];
		matidentity4x4(&rotate_z);
		rotate_z.r0c0=cos[angle_z];
		rotate_z.r0c1=sin[angle_z];
		rotate_z.r1c0=-sin[angle_z];
		rotate_z.r1c1=cos[angle_z];
		matmult4x4s(&rotate_x,&rotate_y,&temp);
		matmult4x4s(&temp,&rotate_z,&rot);
		for(i=0 ; i<obj->numverts ; i++)
			{
			vo[i].x=(vl[i].x*rot.r0c0 + vl[i].y*rot.r1c0 +
				vl[i].z*rot.r2c0) >> SFIXV;
			vo[i].y=(vl[i].x*rot.r0c1 + vl[i].y*rot.r1c1 +
				vl[i].z*rot.r2c1) >> SFIXV;
			vo[i].z=(vl[i].x*rot.r0c2+vl[i].y*rot.r1c2+
				vl[i].z*rot.r2c2) >> SFIXV;
			}
		obj->trasf|=0x01;
		break;
	}

}


/********************* fine *************************/
