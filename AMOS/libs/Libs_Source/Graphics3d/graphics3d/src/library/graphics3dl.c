/*
**      $VER: graphics3Dl.c 10.00 (14.11.98)
**
**      Objects loader functions for graphics3D.library
**
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
**
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <proto/exec.h>
#include <dos/dos.h>
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
#include "graphics3Df.h"
#include "graphics3df_proto.h"
/******************************************************************
 * Explanation of my custom 3d object format "3dgfo" :
 ** Header :
 * [3][D][G][F][X][V][x][.][x][x][00][object_name][00]
 * total vertex number (4 bytes :long int)
 * total polys number (4 bytes :long int)
 ** vertex coordinates :
 * X coordinates (8 bytes :double float Ieee format)
 * Y coordinates (8 bytes :double float Ieee format)
 * Z coordinates (8 bytes :double float Ieee format)
 * Note : One triplet for any vertex .
 ** poligon descriptor :
 * flag+colour of polygon (4 bytes)
 * vertex number of polygon (1 byte :permit value 1,2,3,4)
 * #1 vertex index (4 bytes :long int ,first =0 last=vertex_number-1)
 * #2 vertex index (4 bytes :long int ,first =0 last=vertex_number-1)
 * #3 vertex index (4 bytes :long int ,first =0 last=vertex_number-1)
 * #4 vertex index (4 bytes :long int ,first =0 last=vertex_number-1)
 * Note : vertex index #2,#3,#4 is present only if vertex number of polygon
 *	  is respectly 2,3 or 4.
 * Description of flag+colour :
 * flag (1 byte)
 * bit 0 = 0 
 *		colour[0] is Red component 	(1 byte: 0-255)
 *		colour[1] is Green component	(1 byte: 0-255)
 *		colour[3] is Blue component	(1 byte: 0-255)
 * bit 0 = 1
 *		colour[0] ignored
 *		colour[1] ignored
 *		colour[3] register colour on screen palette (1 byte: 0-255)
 *      Note : now only bit0=1 is supported
 * bit 1 = 1 two face polygon
 * bit 1 = 0 one face polygon
 * bit 2-7 = reserved for future use
 **********************************************************************/

/*** local define ***/
#define HEADER_LEN 11

/*** local prototipe ***/
void lo_end(struct ambient3d *in,long int id,long int f);


/************************************************
 ** Carica un oggetto nel formato custom .3dgfo**
 ** nella scena 3d.			       **
 ************************************************
 *** INPUT :				        * 
 * in    -> valore > 0 restituito da display3d.	*
 * foname-> puntatore a stringa con nome file.  *
 * scale -> fattore scala oggetto in fix point  * 
 *** OUTPUT:					*
 * > 0 tutto ok, rende n# identificatore oggetto*
 * =0 errore, operazione fallita.		* 
 ************************************************/
long int GD_loadobject(in,foname,scale)
REG(a0)struct ambient3d *in;
REG(a1)char *foname;
REG(d0)long int scale;
{
double x,y,z;
long int sc,i,f,cl,esi,e,id;
long int np,n_vert,n_pol;
long int x1,y1,z1;
long int fl,fc,p1,p2,p3,p4;
char name[80],c;

#ifdef DEBUG
char dbg[80];
#endif

sc=scale;
esi=0;
id=0;

f=Open(foname,MODE_OLDFILE);
if (f==NULL) return(esi);

/* read object identifier */
e=Read(f,name,HEADER_LEN);
if (e!=HEADER_LEN) goto abort;

if (name[0]!='3' OR name[1]!='D' OR name[2]!='G' OR name[3]!='F' OR
    name[4]!='X' OR name[5]!='V' ) goto abort;

/* read header */

#ifdef DEBUG
sprintf(dbg,"header=%s\n",name);
write_dbg(dbg);
#endif

i=0;
e=Read(f,&c,1);
while (e==1 AND c!=0x00)
	{
	if (i<78) name[i++]=c;
	e=Read(f,&c,1);
	}
if (e!=1) goto abort;
name[i]=0x00;

e=Read(f,&n_vert,4);
if (e!=4) goto abort;
e=Read(f,&n_pol,4);
if (e!=4) goto abort;

if (n_vert==NULL OR n_pol==NULL) goto abort;

e=GD_newobj(in,name,n_pol,n_vert);
if (e==0) goto abort;
id=e;

/* read all vertex */
for (i=0 ; i<n_vert ; i++)
	{
	x1=0;
	y1=0;
	z1=0;
	e=Read(f,&x,8);
	if (e!=8) goto abort;
	GD_dfl2fix(&x,&x1);
	x1=(x1*sc)>>SFIXV;
	e=Read(f,&y,8);
	if (e!=8) goto abort;
	GD_dfl2fix(&y,&y1);
	y1=(y1*sc)>>SFIXV;
	e=Read(f,&z,8);
	if (e!=8) goto abort;
	GD_dfl2fix(&z,&z1);
	z1=(z1*sc)>>SFIXV;
	GD_addobjvertex(in,i,x1,y1,z1);
	}

/* read all polygon descriptor */
for (i=0 ; i<n_pol ;i++)
	{
	e=Read(f,&fc,4);
	if (e!=4) goto abort;
	e=Read(f,&c,1);
	if (e!=1) goto abort;
	e=Read(f,&p1,4);
	if (e!=4) goto abort;
	p2=-1;
	p3=-1;
	p4=-1;
	np=(long int)c;
	switch(np)
		{
		case 2:
			e=Read(f,&p2,4);
			if (e!=4) goto abort;
			break;
		case 3:
			e=Read(f,&p2,4);
			if (e!=4) goto abort;
			e=Read(f,&p3,4);
			if (e!=4) goto abort;
			break;
		default:	
			e=Read(f,&p2,4);
			if (e!=4) goto abort;
			e=Read(f,&p3,4);
			if (e!=4) goto abort;
			e=Read(f,&p4,4);
			if (e!=4) goto abort;
		}	
	GD_addobjpoly(in,i,p1,p2,p3,p4);
	cl=0x000000FF & fc;
	fl=0x02000000 & fc;
	if (fl!=0) fl=1;
	GD_cattpoly(in,i,cl,fl);
	}

GD_recalcobj(in);
esi=id;
id=0;

abort:
lo_end(in,id,f);

return(esi);
}

void lo_end(in,id,f)
struct ambient3d *in;
long int id;
long int f;
{

if (id!=NULL) GD_deleteobject(in);
Close(f); 

}
