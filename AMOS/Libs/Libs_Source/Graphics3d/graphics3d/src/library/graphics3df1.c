/*
**      $VER: graphics3Df1.c 11.00 (31.12.98)
**
**      Main functions for graphics3D.library
**	PARTE #2
**
**      (C) Copyright 97,98 Patrizio Biancalani
**      All Rights Reserved.
**      
**	Note: this code is a partially traslate from the blitzbasic 3d graphics engine 
**	      V 0.9 of Maciej R. Gorny.
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

/**********************************************************/

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

/*** prototipi solo locali ***/
long int read_iff(long int f,const unsigned char *campo);
long int read_r(long int f,long int comp,short int ll,unsigned char *bf);
/*****************************/

/********************************************
 ** cambia il modo di visualizzazione      **
 ** dell'oggetto attualmente selezionato.  **
 ********************************************
 *** INPUT :				    *
 * in  -> valore >0 restituito da display3d.*
 * modo-> modalita' di visualizzazione      *
 *        oggetti.			    *
 *        WIREF= wire frame                 *
 *        SOLID= solid shade   		    *
 *        FLAT = flat shading		    *
 *	  GORAUD = goraud shading	    *
 *** OUTPUT:			 	    *
 * >0 tutto ok.				    *
 * =0 valore non valido.		    *
 ********************************************/
long int GD_changeviewmodeobj(in,modo)
REG(a0)struct ambient3d *in;
REG(d0)long int modo;
{
struct objectnode *obj;
char md;

md=0x0F & modo;

if (md!=WIREF AND md!=SOLID AND md!=FLAT AND md!=GORAUD) return(0);


obj=pobj(in);

obj->shade=modo;
obj->trasf|=0x01;

return(1);
}

/************************************************
 ** Trova le eventuali collisioni degli oggetti**
 ** con quello attuale.			       **
 ************************************************
 **** INPUT :				        *
 * in -> valore > 0 restituito da display3d.	*
 * n  -> n# massimo oggetti da rilevare.	*
 * buf-> puntatore ad array di long int di n    *
 *	 elementi, dove mettere id degli oggetti*
 *	 in collisione.				*
 **** OUTPUT:					*
 * n# oggetti effettivamente rilevati.		*
 * =0 nessuno.					*
 **** NOTA:					*
 * il valore ritornato puo' essere anche > di n *
 ************************************************/
long int GD_colldetect(in,n,buf)
REG(a0)struct ambient3d *in;
REG(d0)long int n;
REG(a1)long int *buf;
{
long int minx,miny,minz,maxx,maxy,maxz;
long int xmn,ymn,zmn,xmx,ymx,zmx;
struct objectnode *obj,*ob;
long int i,ct,obja;

ct=0;
if (in->total_objects==NULL) return(0);

obj=pobj(in);
obja=in->attuale;

minx=obj->xmin+obj->worldposx;
miny=obj->ymin+obj->worldposy;
minz=obj->zmin+obj->worldposz;
maxx=obj->xmax+obj->worldposx;
maxy=obj->ymax+obj->worldposy;
maxz=obj->zmax+obj->worldposz;

ob=resetobj(in);

do
	{
	if (ob->id==obj->id OR ob->state==NULL) continue;
	xmn=ob->xmin+ob->worldposx;
	ymn=ob->ymin+ob->worldposy;
	zmn=ob->zmin+ob->worldposz;
	xmx=ob->xmax+ob->worldposx;
	ymx=ob->ymax+ob->worldposy;
	zmx=ob->zmax+ob->worldposz;
	/* test se i due oggetti non collidono */
	if (minx>=xmx OR maxx<=xmn OR miny>=ymx OR maxy<=ymn 
	    OR minz>=zmx OR maxz<=zmn) continue;
	if (ct<n) buf[ct]=ob->id;
	ct++;
	}while((ob=nextobj(in))!=NULL);

in->attuale=obja;
return(ct);

}

/************************************************
 ** trova l'oggetto e il poligono al cui       **
 ** interno risiede il punto dato.	       **
 ** ignora i poligoni con meno di 3 lati.      **
 ************************************************
 *** INPUT :				        *
 * in -> valore > 0 restituito da display3d.	*
 * np -> puntatore a long, dove mettere n# pol. *
 *       al cui interno risiede il punto.	*
 * xp -> coordinata x punto dato nella finestra * 
 *	 in cui e' visualizzata la scena.	*
 *	 (valore intero).			*  
 * yp -> coordinata y punto dato nella finestra * 
 *	 in cui e' visualizzata la scena.	*
 *	 (valore intero).			*  
 *** OUTPUT:					*
 * = 0 nessun oggetto trovato.			*
 *     (in questo caso valore in np senza sign.)*
 * > 0 valore identificativo oggetto trovato.   *
 *** NOTA:					*
 * L'algoritmo che ho usato sembra funzioni ma  *
 * e' stato trovato in modo del tutto empirico  *
 * se qualcuno mi sa spiegare perche' funzioni  *
 * e' il benvenuto.				*
 ************************************************/
long int GD_pickobj(in,np,xp,yp)
REG(a0)struct ambient3d *in;
REG(a1)long int *np;
REG(d0)long int xp;
REG(d1)long int yp;
{
struct polytemp *plt;
long int *ip,id,i,ris;
long int zz,x,y,xm,ym,x1,x2,x3,y1,y2,y3;

ip=in->iwpolys;
if (ip==NULL) return(0);
ris=0;
i=in->total_polys-1;

x=xp-in->minx;
y=yp-in->miny;
zz=0x7FFFFFFF;

for (i=0 ; i<in->total_polys; i++)
	{
	plt=(struct polytemp *)ip[i];
	if (plt->numpoints<3) goto prossimo;
/* traslo origini poligono su punto dato */
	x1=plt->x1-x;
	y1=plt->y1-y; 
	x2=plt->x2-x;
	y2=plt->y2-y; 
	x3=plt->x3-x;
	y3=plt->y3-y; 
/* calcolo massimo x e y del triangolo (in valore assoluto)*/ 
	xm=abs(x1);
	if (abs(x2)>xm) xm=abs(x2);
	if (abs(x3)>xm) xm=abs(x3);
	ym=abs(y1);
	if (abs(y2)>ym) ym=abs(y2);
	if (abs(y3)>ym) ym=abs(y3);
/* sommo gli assi dei tre vertici tra loro */
	x1=abs(x1+x2+x3);
	y1=abs(y1+y2+y3);
/* test se risultato in valore assoluto maggiore dei val. massimi per x e y*/
/* se no, punto interno altrimenti esterno */		
	if (x1<=xm AND y1<=ym AND zz>plt->svalue) 
		{
		ris=plt->obj;
		np[0]=plt->npol;
		zz=plt->svalue;
		}
/* se poligono composto di 4 lati ripeto il test per l'altro triangolo */
	if (plt->numpoints=4)
		{
	/* traslo origini poligono su punto dato */
		x1=plt->x3-x;
		y1=plt->y3-y; 
		x2=plt->x4-x;
		y2=plt->y4-y; 
		x3=plt->x1-x;
		y3=plt->y1-y; 
		xm=abs(x1);
		if (abs(x2)>xm) xm=abs(x2);
		if (abs(x3)>xm) xm=abs(x3);
		ym=abs(y1);
		if (abs(y2)>ym) ym=abs(y2);
		if (abs(y3)>ym) ym=abs(y3);
		x1=abs(x1+x2+x3);
		y1=abs(y1+y2+y3);
		if (x1<=xm AND y1<=ym AND zz>plt->svalue) 
			{
			ris=plt->obj;
			np[0]=plt->npol;
			zz=plt->svalue;
			}
		}
	prossimo:
	}

return(ris);

}

/************************************************
 ** aggiunge una nuova texture map all'elenco  **
 ************************************************
 *** INPUT :					*
 * in -> valore >0 restituito da display3d.	*
 * dx -> larghezza texture map in pixel.	*
 * dy -> altezza texture map in pixel.		*
 * buf -> puntatore ad area con chunky buffer   *
 *        della texturemap (si usera' dx e dy)  *
 *** OUTPUT:					*
 * = 0 aggiunta fallita.			*
 * > 0 indirizzo descrittore nuova texture.     *
 ************************************************/
long int GD_newtmap(in,dx,dy,buf)
REG(a0)struct ambient3d *in;
REG(d0)short int dx;
REG(d1)short int dy;
REG(a1)unsigned char *buf;
{
long int i,ct,ln,ris,nc;
struct buftmap *btm;
unsigned char *buf1;
#ifdef DEBUG
char dbg[100];
#endif

btm=in->graf->a_tmap;
nc=in->graf->n_color;

/* se la tabella per le texture non e' presente esco subito con 0 */
if (btm==NULL) return(NULL);

i=0;
while(i<TTMAP AND btm[i].chunky!=NULL) i++;

#ifdef DEBUG
sprintf(dbg,"indice=%ld chunky=%ld\n",i,btm[i].chunky);
write_dbg(dbg);
#endif

if (i<TTMAP)
	{
	ln=dx*dy+100;
	buf1=(unsigned char *)AllocMem(ln,NULL);
	if (buf1==NULL) return (0L);
	btm[i].chunky=buf1;
	btm[i].lung=ln;
	btm[i].larg=dx;
	btm[i].alt=dy;
	for(ct=0 ; ct<dx*dy ;ct++) 
		{
		if (buf[ct]<nc)
			{
			buf1[ct]=buf[ct];	
			}
		else
			{
			buf1[ct]=nc-1;
			}
		}
#ifdef DEBUG
sprintf(dbg,"id=%ld lung=%ld larg=%ld chunky=%ld\n",&(btm[i]),btm[i].lung,btm[i].larg,
	btm[i].chunky);
write_dbg(dbg);
#endif
	ris=(long int)&btm[i];
#ifdef DEBUG
sprintf(dbg,"ris=%ld\n",ris);
write_dbg(dbg);
#endif
	return(ris);
	}

return(0L);
}

/************************************************
 ** aggiunge una nuova texture map all'elenco  **
 ** leggendola da un file IFF_ILBM.	       **
 ************************************************
 *** INPUT :					*
 * in -> valore >0 restituito da display3d.	*
 * name -> a stringa con nome file da leggere.  *
 *	   (indicare il path completo).		*
 *** OUTPUT:					*
 * = 0 aggiunta fallita.			*
 * > 0 indirizzo descrittore nuova texture.     *
 ************************************************/
long int GD_newtmapf(in,name)
REG(a0)struct ambient3d *in;
REG(a1)unsigned char *name;
{
long int depth,lb,comp,ris,y,yy,dx,dy,fin,i,len;
short int *ps,id,sc;
unsigned char mk,val,*tb1,*tb,*buf;
#ifdef DEBUG
unsigned char dbg[100];
#endif

tb=in->temp;
ps=(short int *)tb;
ris=0L;
fin=Open(name,MODE_OLDFILE);
if (fin==NULL) return(0L);

/* leggo Header IFF */
Read(fin,tb,12);
if (tb[0]!='F' OR tb[1]!='O' OR tb[2]!='R' OR tb[3]!='M') goto abort_err;
if (tb[8]!='I' OR tb[9]!='L' OR tb[10]!='B' OR tb[11]!='M') goto abort_err;

/* leggo primo campo con dati immagine */
i=read_iff(fin,"BMHD");
if (i==0) goto abort_err;
/* leggo i dati dell'immagine */
len=Read(fin,tb,i);
if (len!=i) goto abort_err;
dx=ps[0];
dy=ps[1];
depth=tb[8];
comp=tb[10];
lb=(dx+7)/8;
if (depth>8) goto abort_err;
if (dx>9000) goto abort_err;

#ifdef DEBUG
sprintf(dbg,"IMG=%s - ",name);
write_dbg(dbg);
sprintf(dbg,"dx=%ld dy=%ld depth=%ld comp=%ld\n",dx,dy,depth,comp);
write_dbg(dbg);
#endif

/* apro un buffer delle dimensioni dell'immagine */
buf=AllocMem(dx*dy+100,NULL);
if (buf==NULL) goto abort_err;

/* leggo il campo col corpo dell'immagine */
i=read_iff(fin,"BODY");
if (i==0) goto abort_err1;
#ifdef DEBUG
sprintf(dbg,"len=%ld\n",i);
write_dbg(dbg);
#endif

/* leggo il corpo dell'immagine */
len=0;
for(y=0 ; y<dy ;y++)
	{
	tb1=tb;
	for(yy=0 ; yy<depth ; yy++)
		{
	/* leggo una linea con o senza compressione */	
		if (read_r(fin,comp,lb,tb1)==NULL) goto abort_err1;
		tb1+=lb;
		}
	mk=0x80;	/* maschera per bit */
	sc=7;		/* n# di shift da effettuare */
	/* conversione riga da planar a chunky */
	for(i=0; i<dx; i++)
		{
		val=0;
		tb1=tb;
		id=i/8;
		for(yy=0; yy<depth ;yy++)
			{
			val+=((mk & tb1[id])>>sc)<<yy;
			tb1+=lb;
			}
		mk=mk>>1;
		sc--;
		if (sc<0)
			{
			mk=0x80;
			sc=7;
			}
		buf[len++]=val;
/*
#ifdef DEBUG
sprintf(dbg,"%ld,",val);
write_dbg(dbg);
#endif
*/
		}
/*
#ifdef DEBUG
sprintf(dbg,"\n");
write_dbg(dbg);
#endif
*/
	}

/* aggiungo chunky display map ottenuta alla lista delle texture map */
ris=GD_newtmap(in,dx,dy,buf);

abort_err1:
FreeMem(buf,dx*dy+100);

abort_err:
Close(fin);
return(ris);
}

/************************************************
 ** Si posiziona all'inizio dei dati di un     **
 ** campo iff.				       **
 ************************************************
 *** INPUT :					*
 * f -> id. file da leggere .			*
 * campo -> puntatore a stringa con nome campo  *
 *	    (usa solo i primi 4 bytes)		*
 *** OUTPUT:					*
 * ==0 -> errore o campo vuoto.			*
 * !=0 -> lunghezza dati nel campo.		*
 ************************************************/
long int read_iff(long int f,const unsigned char *campo)
{
long int len,*ii;
unsigned char buf[10];

len=0;

/* mi sposto sicuramente all'inizio utile del file */
Seek(f,12,OFFSET_BEGINNING);

/* leggo testata + lunghezza campo fino ad un errore o al momento in cui 
   non trovo quella cercata*/
while(len==0)
	{
	if (Read(f,buf,8)!=8) break;
	ii=(long int *)&buf[4];
	/* test se campo cercato */
	if (buf[0]==campo[0] AND buf[1]==campo[1] AND buf[2]==campo[2] AND buf[3]==campo[3])
		{
		len=ii[0];
		}
	else
		{
	/* altrimenti salto a successivo */
		Seek(f,ii[0],OFFSET_CURRENT);
		}
	}

return(len);
}
/************************************************
 ** leggo una riga con eventuale comp. byterun **
 ** e la scrivo nel buffer.		       **
 ************************************************/
long int read_r(long int f,long int comp,short int ll,unsigned char *bf)
{
char flag[2];
long int i,l;

#ifdef DEBUG
char dbg[100];
#endif

if (comp==0)
	{
	if (Read(f,bf,ll)!=ll) return(0);
	}
else
	{
	l=0;
	while(l<ll)
		{
		if (Read(f,flag,2)!=2) return(0);
		bf[l++]=flag[1];
		if (flag[0]<0)
			{
			for(i=0 ; i<-flag[0] ; i++) bf[l++]=flag[1];
			}	
		else
			{
			i=flag[0];
			if (i>0) if (Read(f,bf+l,i)!=i) return(0);
			l+=i;
			}
#ifdef DEBUG
sprintf(dbg,"ll=%ld l=%ld flag0=%ld flag1=%lx\n",ll,l,flag[0],flag[1]);
write_dbg(dbg);
#endif
		}
	}
return(1);
} 

/************************************************
 ** elimina una texture map dall'elenco        **
 ************************************************
 *** INPUT :					*
 * in -> valore >0 restituito da display3d.	*
 * id -> valore >0 restituito da newtmap.	*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_rmtmap(in,id)
REG(a0)struct ambient3d *in;
REG(a1)struct buftmap *id;
{


if (id==NULL OR in->graf->a_tmap==NULL) return((void)0);
if (id->chunky!=NULL)
	{
	FreeMem(id->chunky,id->lung);
	id->chunky=0L;
	}
}
 

/************************************************
 ** crea e inizializza una nuova struttura     **
 ** oggetto e tutte le sue sottostrutture.     **
 ** Lo fa diventare l'attuale.		       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * name -> puntatore a stringa con nome oggetto.*
 * pol  -> n# totale poligoni nell'oggetto.     *
 * vert -> n# totale vertici nell'oggetto.      *
 *** OUTPUT:					*
 * > 0 tutto ok, rende n# identificatore oggetto*
 * =0 errore, operazione fallita.		* 
 ************************************************/
long int GD_newobj(in,name,pol,vert)
REG(a0)struct ambient3d *in;
REG(a1)char *name;
REG(d0)long int pol;
REG(d1)long int vert;
{
long int i,id,lv,lv1;
struct objectnode *ob;
struct vert1 *vc;
struct polygon *pl;
char *n;

id=in->total_objects;
if (id>MAXOBJECT) return(0);
if (vert>MAXVERT) return(0);

in->total_objects+=1;

in->attuale=id;
ob=pobj(in);

n=ob->name;

i=0;
while(i<21 OR name[i]!=0x00) n[i]=name[i++];
n[i]=0x00;

/** inizializzo valori di default */
ob->numpolys=pol;
ob->numverts=vert;
ob->vorig=0;
ob->vlocal=0;
ob->vcamera=0;
ob->polys=0;
ob->state=1;
ob->shade=in->view_mode;
ob->trasf=1;

/* definisco origine oggetto alle coordinate 0,0,0 */
ob->worldposx=0;
ob->worldposy=0;
ob->worldposz=0;

lv=vert*sizeof(Svertex);
lv1=vert*sizeof(Svert1);

n=(char *)AllocMem(lv,NULL);
if (n<=(char *)NULL)
	{
	GD_deleteobject(in);
	return(0);
	}
ob->vorig=(struct vertex *)n;

n=(char *)AllocMem(lv,NULL);
if (n<=(char *)NULL)
	{
	GD_deleteobject(in);
	return(0);
	}
ob->vlocal=(struct vertex *)n;

n=(char *)AllocMem(lv1,NULL);
if (n<=(char *)NULL)
	{
	GD_deleteobject(in);
	return(0);
	}
ob->vcamera=(struct vert1 *)n;

vc=ob->vcamera;
for(i=0 ; i<vert ; i++) vc[i].npol=0;

n=(char *)AllocMem(pol*sizeof(Spolygon),NULL);
if (n<=(char *)NULL)
	{
	GD_deleteobject(in);
	return(0);
	}
ob->polys=(struct polygon *)n;

pl=ob->polys;
for(i=0 ; i<pol ; i++)
	{
	pl[i].vertexlist0=-1;
	pl[i].vertexlist1=-1;
	pl[i].vertexlist2=-1;
	pl[i].vertexlist3=-1;
	}

ob->id=in->numero;
in->numero+=1;
in->max_polys+=ob->numpolys;

return(ob->id);

}

/************************************************
 ** elimina oggetto attuale e libera la memoria**
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
void GD_deleteobject(in)
REG(a0)struct ambient3d *in;
{
struct objectnode *ob;
char *s,*d;
long int sob,i,i1;

if (in->total_objects<=NULL) return(0);

sob=sizeof(Sobjectnode);
ob=pobj(in);

in->max_polys-=ob->numpolys;

i=sizeof(Svertex)*ob->numverts;
i1=sizeof(Svert1)*ob->numverts;

if (ob->vorig!=NULL) FreeMem(ob->vorig,i);
if (ob->vlocal!=NULL) FreeMem(ob->vlocal,i);
if (ob->vcamera!=NULL) FreeMem(ob->vcamera,i1);
if (ob->polys!=NULL) FreeMem(ob->polys,sizeof(Spolygon)*ob->numpolys);

in->total_objects-=1;
if (in->attuale>=in->total_objects)
	{
	in->attuale=in->total_objects-1;
	if (in->attuale<NULL) in->attuale=0;
	return(0);
	}

/* elimino i dati dell'oggetto */
/*cmem(ob+sob,ob,mul(in.total_objects-in.attuale-1,sob))*/
/** !!!attenzione!!! questa routin in questo caso e' ok ***/
/** ma se si devono spostare aree sovrapposte non va piu' bene **/ 
d=(char *)ob;
s=(char *)ob+sob;
for(i=0 ; i<(in->total_objects-in->attuale)*sob ; i++) d[i]=s[i];

}

/************************************************
 ** inserisce un vertice nell'oggetto corrente.**
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * num -> numero indice del vertice da inserire *
 *        (#1 = 0, #2 = 1, ...). 		*
 * x   -> valore coordinata x vertice           *
 *        (in FIXPOINT)				*
 * y   -> valore coordinata y vertice           *
 *        (in FIXPOINT)				*
 * z   -> valore coordinata z vertice           *
 *        (in FIXPOINT)				*
 *** OUTPUT:					*
 * > 0 tutto ok, vertice inserito.		*
 * = 0 operazione fallita.			*
 *** NOTA  :					*
 * Se si cerca di inserire un vertice con indice*
 * maggiore del numero di vertici definiti per  *
 * l'oggetto l'operazione fallira'.		*
 ************************************************/
long int GD_addobjvertex(in,num,x,y,z)
REG(a0)struct ambient3d *in;
REG(d0)long int num;
REG(d1)long int x;
REG(d2)long int y;
REG(d3)long int z;
{
struct objectnode *obj;
struct vertex *vl,*vo;

obj=pobj(in);

vl=obj->vlocal;
vo=obj->vorig;

if (num+1>obj->numverts) return(0);
if (num<NULL) return(0);

vl[num].x=x;
vo[num].x=x;
vl[num].y=y;
vo[num].y=y;
vl[num].z=z;
vo[num].z=z;

return(1);
}

/************************************************
 ** inserisce un poligono all'oggetto corrente **
 ** se p4=-1 allora poligono a 3 vertici.      **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * num -> numero indice del poligono da inserire*
 *        (#1 = 0, #2 = 1, ...).		*
 * p1  -> numero indice primo punto pol. su     *
 *        elenco vertico oggetto.		*
 * p2  -> numero indice secondo punto pol. su   *
 *        elenco vertico oggetto.		*
 *        (=-1 allora poligono a un vertice).   *
 * p3  -> numero indice terzo punto pol. su     *
 *        elenco vertico oggetto.		*
 *        (=-1 allora poligono a due vertici).  *
 * p4  -> numero indice quarto punto pol. su    *
 *        elenco vertico oggetto .		*
 *        (=-1 allora poligono a tre vertici).  *
 *** OUTPUT:					*
 * > 0 tutto ok, poligono inserito.		*
 * = 0 operazione fallita.			*
 *** NOTA  :					*
 * Se si cerca di inserire un poligono con      *
 * indice maggiore del numero di poligoni       *
 * definiti per l'oggetto l'operazione fallira'.*
 ************************************************/
long int GD_addobjpoly(in,num,p1,p2,p3,p4)
REG(a0)struct ambient3d *in;
REG(d0)long int num;
REG(d1)long int p1;
REG(d2)long int p2;
REG(d3)long int p3;
REG(d4)long int p4;
{
struct objectnode *obj;
struct polygon *poly;
struct vertex *vert;
long int t;

obj=pobj(in);
poly=obj->polys;
vert=obj->vorig;

if (num+1>obj->numpolys) return(0);
if (num<NULL) return(0);

t=1;
if (p1<NULL) return(0);
if (p2>=NULL) t++;
if (p3>=NULL) t++;
if (p4>=NULL) t++;

poly[num].numpoints=t;
poly[num].twosided=1;  	/* default poligono a due facce */
poly[num].visible=1;
poly[num].clipped=0;
poly[num].active=1;
poly[num].vertexlist0=p1;
poly[num].ptmap.dtmap=0;
if (t>1) poly[num].vertexlist1=p2;
if (t>2) poly[num].vertexlist2=p3;
if (t>3) poly[num].vertexlist3=p4;

return(1);
}

/************************************************
 ** modifica i parametri dell'oggetto attuale  **
 ************************************************
 *** INPUT :					*
 * in -> valore > 0 restituito da display3d.	*
 * new -> puntatore a array di strutture tag3d  *
 *        con nuovi parametri per oggetto 	*
 *** OUTPUT:					*
 * = 0 nessuna variazione.			*
 * > 0 numero di variazioni effettuate.		*
 ************************************************/
long int GD_modobj(in,new)
REG(a0)struct ambient3d *in;
REG(a1)struct tag3d *new;
{
long int ft,ris,i,md,ct;
struct objectnode *obj;

ris=0;
ct=0;
if (in->total_objects==NULL) return(0);
obj=pobj(in);

while(new[ct].tipo!=END_T AND ct<100)
	{
	ft=new[ct].tipo;
	i=new[ct].val;
	switch(ft)
		{
		case(MO_STATE):
		/* attiva(1) o disattiva(0) l'oggetto attuale */
			obj->state=i;
			ris++;
			break;

		case(MO_VMODE):
		/* cambia il modo di visualizzazione */
			md=0x0F & i;
			if (md==WIREF OR md==SOLID OR md==FLAT OR md==GORAUD) obj->shade=i;
			ris++;	
			break;	

		}
	ct++;
	}

return(ris);
}
 
/************************************************
 ** modifica i parametri di un poligono        **
 ** dell'oggetto attuale.		       **
 ************************************************
 *** INPUT :					*
 * in -> valore > 0 restituito da display3d.	*
 * new -> puntatore a array di strutture tag3d  *
 *        con nuovi parametri per poligono.     *
 *** OUTPUT:					*
 * = 0 nessuna variazione.			*
 * > 0 numero di variazioni effettuate.		*
 ************************************************/
long int GD_modpoly(in,new)
REG(a0)struct ambient3d *in;
REG(a1)struct tag3d *new;
{
long int ris,i,ct,ft,n_pol;
struct grafica *graf;
struct objectnode *obj;
struct polygon *a_poly,*poly;
struct buftmap *btm;
struct vtmap *vt;

graf=(struct grafica *)in->graf;
obj=pobj(in);
a_poly=obj->polys;
poly=&a_poly[0];

ct=0;
ris=0;
n_pol=0;
while(new[ct].tipo!=END_T AND ct<1000)
	{
	ft=new[ct].tipo;
	i=new[ct].val;
	switch(ft)
		{
		case(MP_POLY):
		/* seleziona il poligono di cui modificare le caratteristiche (def. 0) */
		if (i<obj->numpolys)
			{
			n_pol=i;
			poly=&a_poly[n_pol];
			ris++;
			}
		break;

		case(MP_ACTIV):
		/* attiva(1) o disattiva(0) il poligono selezionato */
		poly->active=i;
		ris++;
		break;
		
		case(MP_COLOR):
		/* nuovo colore per poligono selezionato */
		if (i<graf->n_color)
			{
			poly->color=i;
			ris++;
			}
		break;

		case(MP_2SIDE):
		/* setta a 2(1) o 1(0) faccia il poligono selezionato */		
		if (poly->numpoints>2)
			{
			poly->twosided=i;
			ris++;
			}		
		break;

		case(MP_TMAP):
		/* aggiunge una texture map al poligono ,.val deve puntare alla */
		/* struttura buftmap che la descrive */
		if (i!=NULL AND poly->numpoints>2)
			{
			poly->ptmap.dtmap=(struct buftmap *)i;
			ris++;
			}
		break;

		case(MP_VTMAP):
		/* setta vertici su texture map, .val deve puntare a struttura vtmap */
		/* tale struttura deve avere definiti almeno lo stesso n# di vertici del */
		/* poligono alla quale verra' assegnata */
		if (poly->numpoints>2)			
			{
			vt=(struct vtmap *)i;
			poly->ptmap.u1=vt->x1;
			poly->ptmap.v1=vt->y1;
			poly->ptmap.u2=vt->x2;
			poly->ptmap.v2=vt->y2;
			poly->ptmap.u3=vt->x3;
			poly->ptmap.v3=vt->y3;
			poly->ptmap.u4=vt->x4;
			poly->ptmap.v4=vt->y4;
			ris++;
			}
		break;
		
		case(MP_VTAUTO):
		/* setta i vertici su texture map in modo automatico, riempie tutto il */
		/* poligono con tutta la texture.*/
		if (poly->numpoints>2 AND poly->ptmap.dtmap!=NULL)
			{
			btm=poly->ptmap.dtmap;
			poly->ptmap.u1=0;
			poly->ptmap.v1=0;
			poly->ptmap.u2=btm->larg;
			poly->ptmap.v2=0;
			poly->ptmap.u3=btm->larg;
			poly->ptmap.v3=btm->alt;
			poly->ptmap.u4=0;
			poly->ptmap.v4=btm->alt;
			ris++;
			}
		break;
		}
	ct++;
	}

return(ris);
}

/************************************************
 ** cambia le caratteristiche di un poligono.  **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * num -> numero indice del poligono da variare *
 *        (#1 = 0, #2 = 1, ...).		*
 * color -> colore base per oggetto, in caso di *
 *          visualizzazione flat usera i colori *
 *          successivi a questo per sfumare.    *
 * twoside -> indica se poligono a 2 facce (1) o*
 *            a una faccia (0).			*
 *            Se a due facce sara' visibile solo*
 *	      la faccia frontale.		*
 *** OUTPUT:					*
 * > 0 tutto ok, poligono modificato.		*
 * = 0 operazione fallita.			*
 *** NOTA  :					*
 * Se si cerca di modificare un poligono con    *
 * indice maggiore del numero di poligoni       *
 * definiti per l'oggetto l'operazione fallira'.*
 ************************************************/
long int GD_cattpoly(in,num,color,twoside)
REG(a0)struct ambient3d *in;
REG(d0)long int num;
REG(d1)long int color;
REG(d2)long int twoside;
{
struct objectnode *obj;
struct polygon *poly;
long int c;

obj=pobj(in);
poly=obj->polys;

if (num+1>obj->numpolys) return(0);
if (num<NULL) return(0);

if (poly[num].numpoints>2) poly[num].twosided=twoside;

c=color;
if (c>in->graf->n_color) c=in->graf->n_color-1;
poly[num].color=c;

return(1);
}

/************************************************
 ** Setta come attuale l'oggetto di cui e'dato **
 ** l'identificativo.			       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * num -> identificativo oggetto da settare.    * 
 *** OUTPUT:					*
 * > 0 tutto ok, 				* 
 * = 0 operazione fallita.			*
 ************************************************/
long int GD_setobj(in,num)
REG(a0)struct ambient3d *in;
REG(d0)long int num;
{
long int ris,buf;
struct objectnode *obj;

ris=0;
if (num==0) return(0);
buf=in->attuale;
obj=resetobj(in);
while ((obj!=0 AND ris==0))
	{
	if (num==obj->id) 
		{
		ris=1;	
		}
	else	
		{
		obj=nextobj(in);
		}
	}

if (ris==NULL) in->attuale=buf;
return(ris);

}

/************************************************
 ** Ritorna l'identificativo dell'oggetto      **
 ** attuale.				       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 *** OUTPUT:					*
 * >0 tutto ok, valore identificativo.		*
 * = 0 operazione fallita.			*
 ************************************************/
long int GD_getobj(in)
REG(a0)struct ambient3d *in;
{
struct objectnode *obj;

obj=pobj(in);

return(obj->id);

}

/************************************************
 ** aggiorna tutti i dati precalcolati dello   **
 ** oggetto attuale.			       **
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 *** OUTPUT:					*
 * nessuno.					*
 *** NOTA :					*
 * Il ricalcolo si effettua solo se l'oggetto e'*
 * stato effettivamente modificato.		*
 ************************************************/
void GD_recalcobj(in)
REG (a0)struct ambient3d *in;
{
struct objectnode *obj;

obj=pobj(in);

if (in->total_objects>NULL AND obj->trasf!=NULL OR in->agg_all!=NULL)  
	{
	if (obj->trasf & 0x01!=NULL) aggobj(in);
	}

}

/***************** FINE ROUTIN USABILI ESTERNAMENTE ********************/

