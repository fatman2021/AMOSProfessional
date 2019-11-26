/*
**      $VER: graphics3Df_i2.c 10.01 (01.11.97)
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

/**** prototipi locali ****/
long int abs(val);

/************** routin interne solo matematiche *************/

/**************************************/
/** crea una matrice 4x4 d'identita' **/
/**************************************/
void matidentity4x4(imatrix)
struct matrix4x4 *imatrix;
{
imatrix->r0c0=FIXV; imatrix->r0c1=0; imatrix->r0c2=0; imatrix->r0c3=0;
imatrix->r1c0=0; imatrix->r1c1=FIXV; imatrix->r1c2=0; imatrix->r1c3=0;
imatrix->r2c0=0; imatrix->r2c1=0; imatrix->r2c2=FIXV; imatrix->r2c3=0;
imatrix->r3c0=0; imatrix->r3c1=0; imatrix->r3c2=0; imatrix->r3c3=FIXV;
}

/****************************/
/** azzera una matrice 4x4 **/
/****************************/
void matzero4x4(imatrix)
struct matrix4x4 *imatrix;
{
imatrix->r0c0=0; imatrix->r0c1=0; imatrix->r0c2=0; imatrix->r0c3=0;
imatrix->r1c0=0; imatrix->r1c1=0; imatrix->r1c2=0; imatrix->r1c3=0;
imatrix->r2c0=0; imatrix->r2c1=0; imatrix->r2c2=0; imatrix->r2c3=0;
imatrix->r3c0=0; imatrix->r3c1=0; imatrix->r3c2=0; imatrix->r3c3=0;
}

/***************************************/
/** copia una matrice 4x4 in un'altra **/
/***************************************/
void matcopy4x4(s_m,d_m)
struct matrix4x4 *s_m;
struct matrix4x4 *d_m;
{
d_m->r0c0=s_m->r0c0; d_m->r0c1=s_m->r0c1; d_m->r0c2=s_m->r0c2;
d_m->r0c3=s_m->r0c3;
d_m->r1c0=s_m->r1c0; d_m->r1c1=s_m->r1c1; d_m->r1c2=s_m->r1c2;
d_m->r1c3=s_m->r1c3;
d_m->r2c0=s_m->r2c0; d_m->r2c1=s_m->r2c1; d_m->r2c2=s_m->r2c2;
d_m->r2c3=s_m->r2c3;
d_m->r3c0=s_m->r3c0; d_m->r3c1=s_m->r3c1; d_m->r3c2=s_m->r3c2;
d_m->r3c3=s_m->r3c3;
}

/*********************************************/
/** calcola il prodotto tra due matrici 4x4 **/
/*********************************************/
void matmult4x4(a,b,r)
struct matrix4x4 *a;
struct matrix4x4 *b;
struct matrix4x4 *r;
{
r->r0c0=a->r0c0*b->r0c0+a->r0c1*b->r1c0+a->r0c2*b->r2c0+a->r0c3*b->r3c0;
r->r0c0=r->r0c0 >> SFIXV;
r->r0c1=a->r0c0*b->r0c1+a->r0c1*b->r1c1+a->r0c2*b->r2c1+a->r0c3*b->r3c1;
r->r0c1=r->r0c1 >> SFIXV;
r->r0c2=a->r0c0*b->r0c2+a->r0c1*b->r1c2+a->r0c2*b->r2c2+a->r0c3*b->r3c2;
r->r0c2=r->r0c2 >> SFIXV;
r->r0c3=a->r0c0*b->r0c3+a->r0c1*b->r1c3+a->r0c2*b->r2c3+a->r0c3*b->r3c3;
r->r0c3=r->r0c3 >> SFIXV;

r->r1c0=a->r1c0*b->r0c0+a->r1c1*b->r1c0+a->r1c2*b->r2c0+a->r1c3*b->r3c0;
r->r1c0=r->r1c0 >> SFIXV;
r->r1c1=a->r1c0*b->r0c1+a->r1c1*b->r1c1+a->r1c2*b->r2c1+a->r1c3*b->r3c1;
r->r1c1=r->r1c1 >> SFIXV;
r->r1c2=a->r1c0*b->r0c2+a->r1c1*b->r1c2+a->r1c2*b->r2c2+a->r1c3*b->r3c2;
r->r1c2=r->r1c2 >> SFIXV;
r->r1c3=a->r1c0*b->r0c3+a->r1c1*b->r1c3+a->r1c2*b->r2c3+a->r1c3*b->r3c3;
r->r1c3=r->r1c3 >> SFIXV;

r->r2c0=a->r2c0*b->r0c0+a->r2c1*b->r1c0+a->r2c2*b->r2c0+a->r2c3*b->r3c0;
r->r2c0=r->r2c0 >> SFIXV;
r->r2c1=a->r2c0*b->r0c1+a->r2c1*b->r1c1+a->r2c2*b->r2c1+a->r2c3*b->r3c1;
r->r2c1=r->r2c1 >> SFIXV;
r->r2c2=a->r2c0*b->r0c2+a->r2c1*b->r1c2+a->r2c2*b->r2c2+a->r2c3*b->r3c2;
r->r2c2=r->r2c2 >> SFIXV;
r->r2c3=a->r2c0*b->r0c3+a->r2c1*b->r1c3+a->r2c2*b->r2c3+a->r2c3*b->r3c3;
r->r2c3=r->r2c3 >> SFIXV;

r->r3c0=a->r3c0*b->r0c0+a->r3c1*b->r1c0+a->r3c2*b->r2c0+a->r3c3*b->r3c0;
r->r3c0=r->r3c0 >> SFIXV;
r->r3c1=a->r3c0*b->r0c1+a->r3c1*b->r1c1+a->r3c2*b->r2c1+a->r3c3*b->r3c1;
r->r3c1=r->r3c1 >> SFIXV;
r->r3c2=a->r3c0*b->r0c2+a->r3c1*b->r1c2+a->r3c2*b->r2c2+a->r3c3*b->r3c2;
r->r3c2=r->r3c2 >> SFIXV;
r->r3c3=a->r3c0*b->r0c3+a->r3c1*b->r1c3+a->r3c2*b->r2c3+a->r3c3*b->r3c3;
r->r3c3=r->r3c3 >> SFIXV;
}

/*********************************************/
/** calcola il prodotto tra due matrici 4x4 **/
/** ottimizzato per matrici di rotazione    **/
/*********************************************/
void matmult4x4s(a,b,r)
struct matrix4x4 *a;
struct matrix4x4 *b;
struct matrix4x4 *r;
{

r->r0c0=a->r0c0*b->r0c0+a->r0c1*b->r1c0+a->r0c2*b->r2c0;
r->r0c0=r->r0c0 >> SFIXV;
r->r0c1=a->r0c0*b->r0c1+a->r0c1*b->r1c1+a->r0c2*b->r2c1;
r->r0c1=r->r0c1 >> SFIXV;
r->r0c2=a->r0c0*b->r0c2+a->r0c1*b->r1c2+a->r0c2*b->r2c2;
r->r0c2=r->r0c2 >> SFIXV;
r->r0c3=0;

r->r1c0=a->r1c0*b->r0c0+a->r1c1*b->r1c0+a->r1c2*b->r2c0;
r->r1c0=r->r1c0 >> SFIXV;
r->r1c1=a->r1c0*b->r0c1+a->r1c1*b->r1c1+a->r1c2*b->r2c1;
r->r1c1=r->r1c1 >> SFIXV;
r->r1c2=a->r1c0*b->r0c2+a->r1c1*b->r1c2+a->r1c2*b->r2c2;
r->r1c2=r->r1c2 >> SFIXV;
r->r1c3=0;

r->r2c0=a->r2c0*b->r0c0+a->r2c1*b->r1c0+a->r2c2*b->r2c0;
r->r2c0=r->r2c0 >> SFIXV;
r->r2c1=a->r2c0*b->r0c1+a->r2c1*b->r1c1+a->r2c2*b->r2c1;
r->r2c1=r->r2c1 >> SFIXV;
r->r2c2=a->r2c0*b->r0c2+a->r2c1*b->r1c2+a->r2c2*b->r2c2;
r->r2c2=r->r2c2 >> SFIXV;
r->r2c3=0;

r->r3c0=a->r3c0*b->r0c0+a->r3c1*b->r1c0+a->r3c2*b->r2c0;
r->r3c0=r->r3c0 >> SFIXV;
r->r3c1=a->r3c0*b->r0c1+a->r3c1*b->r1c1+a->r3c2*b->r2c1;
r->r3c1=r->r3c1 >> SFIXV;
r->r3c2=a->r3c0*b->r0c2+a->r3c1*b->r1c2+a->r3c2*b->r2c2;
r->r3c2=r->r3c2 >> SFIXV;
r->r3c3=0;
}

/****************************************************/
/** calcola prodotto tra una matrice 1x4 e una 4x4 **/
/** risultato in una matrice 1x4		   **/
/****************************************************/
void matmult1x4s(a,b,r)
struct matrix1x4 *a;
struct matrix4x4 *b;
struct matrix1x4 *r;
{
r->r0c0=a->r0c0*b->r0c0+a->r0c1*b->r0c1+a->r0c2*b->r0c2+a->r0c3*b->r0c3;
r->r0c0=r->r0c0 >> SFIXV;
r->r0c1=a->r0c0*b->r1c0+a->r0c1*b->r1c1+a->r0c2*b->r1c2+a->r0c3*b->r1c3;
r->r0c1=r->r0c1 >> SFIXV;
r->r0c2=a->r0c0*b->r2c0+a->r0c1*b->r2c1+a->r0c2*b->r2c2+a->r0c3*b->r2c3;
r->r0c2=r->r0c2 >> SFIXV;
r->r0c3=a->r0c0*b->r3c0+a->r0c1*b->r3c0+a->r0c2*b->r3c2+a->r0c3*b->r3c3;
r->r0c3=r->r0c3 >> SFIXV;
}

/************************************************/
/** crea un vettore da 2 punti nello spazio 3d **/
/************************************************/
void makevector3d(a,b,result)
struct vertex *a;
struct vertex *b;
struct vector *result;
{

result->x=b->x - a->x;
result->y=b->y - a->y;
result->z=b->z - a->z;

}

/**************************************/
/** ritorna l'ampiezza di un vettore **/
/** nota:			     **/
/** siccome posso trattare al mass.  **/
/** numeri a 32bit elimino la        **/
/** parte frazionaria, tanto l'errore**/
/** introdotto e' minimo in tal caso.**/
/** Il  risultato e' in FIXPOINT.    **/
/**************************************/
long int vectormag3d(a)
struct vector *a;
{
long int p,x,y,z;

x=(a->x+FIXVM) >> SFIXV;
y=(a->y+FIXVM) >> SFIXV;
z=(a->z+FIXVM) >> SFIXV;
p=x*x+y*y+z*z;

if (p<x OR p<y OR p<z) p=0x7FFFFF;

p=sqri(p);

return (p);
}

/************************************/
/* calcolo vettore normale ad un    */
/* poligono.			    */
/* E' ottimizzato.		    */
/* le componenti del vettore sono   */
/* espresse come numeri in FIXPOINT.*/
/************************************/
void normalpol(v0,v1,v2,normal)
struct vector *normal;
struct vertex *v2,*v1,*v0;
{
long int x0,y0,z0;
long int x,y,z;
long int x1,y1,z1;

x0=v0->x + FIXVM;
y0=v0->y + FIXVM;
z0=v0->z + FIXVM;

x=(v1->x - x0) >> SFIXV;
y=(v1->y - y0) >> SFIXV;
z=(v1->z - z0) >> SFIXV;

x1=(v2->x - x0) >> SFIXV;
y1=(v2->y - y0) >> SFIXV;
z1=(v2->z - z0) >> SFIXV;

normal->x=(y*z1-z*y1) << SFIXV;
normal->y=(-x*z1+z*x1) << SFIXV;
normal->z=(x*y1-y*x1) << SFIXV;

}

/*****************************************/
/** ritorna il prodotto tra due vettori **/
/** risultato in fixpoint	        **/
/** nota:				**/
/** siccome posso trattare al mass.     **/
/** numeri a 32bit                      **/
/** risultato non in fix point ma int.  **/
/*****************************************/
long int dotproduct(u,v)
struct vector *v;
struct vector *u;
{
long int x,y,z;
long int x1,y1,z1;
long int r1,r2,r3;

x=(u->x + FIXVM) >> SFIXV ;
y=(u->y + FIXVM) >> SFIXV ;
z=(u->z + FIXVM) >> SFIXV ;

x1=(v->x + FIXVM) >> SFIXV ;
y1=(v->y + FIXVM) >> SFIXV ;
z1=(v->z + FIXVM) >> SFIXV ;

r1=x*x1;
r2=y*y1;
r3=z*z1;

/*
if (r1<x AND r1<x1) return(0x7FFFFF)
if (r2<y AND r2<y1) return(0x7FFFFF)
if (r3<z AND r3<z1) return(0x7FFFFF)
*/

return(r1+r2+r3);
}

/************************************/
/** calcolo radice quadrata di un  **/
/** numero intero.		   **/
/** risultato in fixpoint          **/
/************************************/
long int sqri(v)
long int v;
{
long int p,v1,d,r,f;

v1=v;

f=(v1>32000L)?1:0;

if (f==NULL) v1=v << (SFIXV+SFIXV);

/** uso metodo delle approssimazioni successive pero' a passo variabile **/
/* prima pero' calcolo una base il piu' vicina possibile alla radice */
d=v1>>1;
p=0;
if (d>45000L) d=20000L;
while (d>NULL)
	{
	r=p+d;
	if (r*r>v1) 
		{
		d=d>>1;
		}
		else
		{
		p=r;
		}
	}

if (f!=NULL) p=p << SFIXV;

return(p);
}

/************************************
 ** calcolo valore assoluto di un  **
 ** intero fixpoint o meno.	   **
 ************************************/
long int abs(val)
long int val;
{
if (val>=0) return(val);

return(-val);
}

/********************* fine *******************************/
