/*******************************************************
 ** Libreria di routin grafiche per la visualizzazione
 ** in 3d .
 ** Traslata in E V2.1b dalla libreria :
 ** 2B3D Blitz Basic II 3D Graphics Engine Version 0.9 Beta
 ** di Maciej R. Gorny
 **
 ** Autore del porting :
 ** 1997 Patrizio Biancalani
 ** NOTA: 
 ** Nel porting tutte le variabili float sono state mutate
 ** in variabili LONG intese pero' col formato 
 ** a virgola fissa :val.float*FIXV
 ** Questo per 2 motivi:
 ** - E' piu' veloce anche su macchine senza coprocessore
 ** - IL compilatore E V2.1B non tratta direttamente i numeri float
 ** RICORDARSI SEMPRE :
 ** in questa versione dell'E il simbolo
 ** * significa prodotto tra 16bit*16bit=32bit
 ** / significa divisione tra 32bit/16bit=16bit
 ** quindi prestare MOLTA attenzione ai valori che possono
 ** assumere in numeri in virgola fissa quando si usano 
 ** questi valori
 *******************************************************/
#define div(a,b) Div(a,b)
#define mul(a,b) Mul(a,b)

MODULE 'graphics','graphics/rastport','graphics/clip','layers'
MODULE 'graphics/regions','graphics/gfx','graphics/layers'
MODULE 'intuition/screens','dos/dos','Asl','libraries/Asl'

/** 
   moduli per poter usare la nuova libreria graphics3D.library al posto della
   gfx.h
**/
/**
   modules to use the new library graphics3d.library instead of gfx.h
**/
MODULE 'graphics3D','graphics3D_lib'

/*** INIZIO CODICI ESEGUIBILI ***/

/*** ROUTIN DI USO ANCHE ESTERNO ***/

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
 * =0 allora errore, operazione fallita.        * 
 ************************************************/
PROC display3d(win:PTR TO window,x0:LONG,y0:LONG,
		scrw:LONG,scrh:LONG,vdist:LONG)
DEF 	ris:LONG 

ris:=NIL
graphics3dbase:=NIL
IF ((graphics3dbase:=OpenLibrary('graphics3D.library',11))<=NIL) THEN RETURN 0

ris:=Gd_display3d(win,x0,y0,scrw,scrh,vdist)

WriteF('ris=\d\n',ris)

ENDPROC ris

/************************************************
 * chiusura ed eliminazione dell'ambiente 3D    * 
 ************************************************
 *** INPUT :					*
 * in -> valore >0 restituito da display3d.     *
 *** OUTPUT:					*
 * nessuno.					*
 ************************************************/
PROC close_display3d(in:LONG)
DEF i:LONG

IF in<>NIL THEN Gd_close_display3d(in)

IF graphics3dbase<>NIL 
	CloseLibrary(graphics3dbase)
	RETURN
ENDIF

ENDPROC

/************************************************
 ** legge i dati di un oggetto da un file .PLG **
 ** e li inserisce nel mondo 3d come un nuovo  **
 ** oggetto.				       ** 
 ************************************************
 *** INPUT :				        * 
 * in -> valore > 0 restituito da display3d.	*
 * fname -> puntatore a stringa con nome file.  *
 * scalar-> fattore di scala per oggetto.       *
 *          (valore in FIXPOINT).		*
 *** OUTPUT:					*
 * >0 tutto ok, oggetto letto.			*
 * =0 operazione fallita.			*
 ************************************************/
PROC plgloadobject(in:LONG,fname:PTR TO CHAR,scalar:LONG)
DEF total_vertices:LONG,
    total_polys:LONG,
    num_vertices:LONG,
    color_des:LONG,
    logical_color:LONG,
    shading:LONG,
    index:LONG,
    ln:LONG,
    tempword:LONG,
    p1:LONG,
    p2:LONG,
    p3:LONG,
    p4:LONG,	
    tempbyte:LONG,
    t:LONG,
    k:LONG,
    v:vertex,
    vl:PTR TO LONG,
    temp[500]:ARRAY,
    sbuffer[100]:ARRAY,
    name[50]:ARRAY,
    tempstr[50]:ARRAY,
    file:LONG,
    col:LONG,
    cl:LONG,
    cc:LONG,
    cs:LONG,
    i:LONG,
   esi:LONG

esi:=0
file:=Open(fname,OLDFILE)
IF file=NIL THEN RETURN 0
ln:=0
cs:=0
WHILE ((cl:=Read(file,temp,495))>NIL)
	cc:=0
	WHILE (cc<cl)
		sbuffer[cs++]:=temp[cc++]
		IF (sbuffer[cs-1]=$0D) OR (sbuffer[cs-1]=$0A) 
			sbuffer[cs]:=0
/** mettere qui codici di lettura dati da file **/
/** place here the code of reading datas from file **/
	plggetline(sbuffer)
#ifdef DEBUG
WriteF('Line read by plggetline :\s\n',sbuffer)
#endif
	IF StrLen(sbuffer)>3   /* test se linea non vuota *//* test if line not empty */
		INC ln
		IF ln=1		
			tempbyte:=lstr(sbuffer,name,0)		
			tempbyte:=lstr(sbuffer,tempstr,tempbyte)
			total_vertices:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Total_vertices:\d\n',total_vertices)
#endif
			lstr(sbuffer,tempstr,tempbyte)
			total_polys:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Total_polys:\d\n',total_polys)
#endif
			t:=Gd_newobj(in,name,total_polys,total_vertices)
#ifdef DEBUG
WriteF('Id. of new object:\d\n',t)
#endif
			IF t=NIL THEN JUMP abort
		/** valori fix point **/
		/** values in fix point **/
		ELSEIF (ln>=2) AND ((total_vertices+1)>=ln)
			tempbyte:=lstr(sbuffer,tempstr,0)
			v.x:=Val(tempstr,{i})
			tempbyte:=lstr(sbuffer,tempstr,tempbyte)
			v.y:=Val(tempstr,{i})
			lstr(sbuffer,tempstr,tempbyte)
			v.z:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Value of vertex n#\d in integer : x=\d y=\d y=\d\n',ln-2,v.x,v.y,v.z) 
#endif
			v.x:=mul(v.x,scalar)
			v.y:=mul(v.y,scalar)
			v.z:=mul(v.z,scalar)
#ifdef DEBUG
WriteF('Value of vertex n#\d in fixpoint : x=\d y=\d y=\d\n',ln-2,v.x,v.y,v.z) 
WriteF('Result of GD_addobjvertex :\d\n',
			Gd_addobjvertex(in,ln-2,v.x,v.y,v.z) )
#endif
#ifndef DEBUG
			Gd_addobjvertex(in,ln-2,v.x,v.y,v.z)
#endif
		ELSEIF (total_vertices+2<=ln) AND 
			(total_polys+total_vertices+1>=ln)
			tempbyte:=lstr(sbuffer,tempstr,0)
	/** implementati dec. hex($,0x) e binary(%) **/
	/** implemented decimal hex($,0x) and bynary(%) **/
			IF (tempstr[0]="0") AND (tempstr[1]="x") 
				tempstr[0]:=" "
				tempstr[1]:="$"
			ENDIF
			color_des:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Color descriptor (in hexadecimal):\h\n',color_des)
#endif
			tempbyte:=lstr(sbuffer,tempstr,tempbyte)
			tempword:=total_vertices+2
			num_vertices:=Val(tempstr,{i})
			index:=ln-tempword
#ifdef DEBUG
WriteF('Number of vertex in #\d polygons:\d\n',index,num_vertices)
#endif			
			p2:=-1
			p3:=-1
			p4:=-1	
			IF num_vertices>0
				tempbyte:=lstr(sbuffer,tempstr,tempbyte)
				p1:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('First vertex n#\d\n',p1)
#endif
			ENDIF
			IF num_vertices>1
				tempbyte:=lstr(sbuffer,tempstr,tempbyte)
				p2:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Second vertex n#\d\n',p2)
#endif
			ENDIF
			IF num_vertices>2
				tempbyte:=lstr(sbuffer,tempstr,tempbyte)
				p3:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Third vertex n#\d\n',p3)
#endif
			ENDIF
			IF num_vertices>3
				tempbyte:=lstr(sbuffer,tempstr,tempbyte)
				p4:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Fourth vertex n#\d\n',p4)
#endif
			ENDIF
#ifdef DEBUG
WriteF('Result of GD_addobjpoly :\d\n',
			Gd_addobjpoly(in,index,p1,p2,p3,p4) )
#endif
#ifndef DEBUG
			Gd_addobjpoly(in,index,p1,p2,p3,p4)
#endif
			col:=And($FF,color_des)
			IF col<16 THEN col:=1
			IF col>16 THEN col:=16
#ifdef DEBUG
WriteF('Color :\d\n',col)
#endif
			Gd_cattpoly(in,index,col,Shr(color_des,12))
		ENDIF
	ENDIF
/****************************************/
			cs:=0
		ENDIF
	ENDWHILE
ENDWHILE
/** 
	remeber that you must be use this function ever than the end of 
	definition of a new object
**/
Gd_recalcobj(in)
esi:=1

abort:
Close(file)

ENDPROC esi

/*** ROUTIN DI USO SOLO INTERNO ***/

/******************************************************/
/** elimina i commenti da una stringa di un file PLG **/
/** erase the comment from a string of a PLG file    **/
/******************************************************/
PROC plggetline(strl:PTR TO CHAR)
DEF i:LONG
DEF a:LONG
DEF f:LONG
DEF lens:LONG

f:=0
a:=0
lens:=StrLen(strl)
FOR i:=0 TO lens
	IF (strl[i]<>32) THEN f:=1
	IF f<>NIL
		IF (strl[i]="#") OR (strl[i]=";") 
			i:=lens
		ELSE
			strl[a]:=strl[i]
			INC a
		ENDIF
	ENDIF
ENDFOR

strl[a]:=0

ENDPROC

/*************************************************/
/** in str mette la prima sequenza di caratteri **/
/** diversi da spazio che trova in s a partire  **/
/** da start, str deve essere lunga a sufficenza**/
/** ritorno prima pos. dopo sequenza.		**/
/** in 'str' place the first sequence of caracters **/
/** other than space that are in 's' from 'start', **/
/** 'str' must be sufficent long , result is the   **/
/** first position after the sequence.             **/ 
/*************************************************/
PROC lstr(s:PTR TO CHAR,str:PTR TO CHAR,start:LONG)
DEF esi:LONG
DEF f:LONG
DEF ls:LONG
DEF esif:LONG
esi:=0
f:=start
ls:=StrLen(s)

/** elimino eventuali spazi precedenti **/
WHILE ((f<ls) AND ((s[f]=" ") OR (s[f]=$0A) OR (s[f]=$0D))) DO INC f
/** calcolo lunghezza sequenza caratteri <> " " **/
esif:=esi+f
WHILE (((esif)<ls) AND (s[esif]<>" ") AND
	(s[esif]<>$0A) AND (s[esif]<>$0D))
	str[esi]:=s[esif] 
	INC esi
	INC esif
ENDWHILE
str[esi]:=0

#ifdef DEBUG
WriteF('lstr : s=>\s< str=>\s< start=\d result=\d\n',s,str,start,esi+f)
#endif

ENDPROC esi+f

/**** FINE ROUTIN ***/

/*** ROUTIN DI USO SOLO PER TEST **/


/*************************************************/
/** stampa contenuto delle strutture polytemp   **/
/*************************************************/
/*
PROC printpolyt(in:LONG)
DEF i:LONG
DEF pt:PTR TO polytemp


pt:=in.worldpolys
FOR i:=0 TO in.total_polys
	WriteF('pol#\d\n',i)
	WriteF('seg#1 X=\d Y=\d\n',pt[i].x1,pt[i].y1)
	WriteF('seg#2 X=\d Y=\d\n',pt[i].x2,pt[i].y2)
	WriteF('seg#3 X=\d Y=\d\n',pt[i].x3,pt[i].y3)
	WriteF('seg#4 X=\d Y=\d\n',pt[i].x4,pt[i].y4)
	WriteF('seg#5 X=\d Y=\d\n',pt[i].x5,pt[i].y5)

	WriteF('n#segmenti=\d col=\d\n',pt[i].numpoints,pt[i].shade)

	WriteF('vmode=\d\n',pt[i].vmode)

ENDFOR

ENDPROC
*/

/*************************************************/
/** stampa contenuto delle strutture objectnode **/
/*************************************************/
/*
PROC objectprint(in:LONG)
DEF id:LONG
DEF io:PTR TO LONG
DEF i:LONG
DEF k:LONG
DEF vo:PTR TO vertex
DEF vl:PTR TO vertex
DEF vg:PTR TO vertex
DEF vc:PTR TO vertex
DEF obj:PTR TO objectnode
DEF pol:PTR TO polygon

WriteF('indici oggetti:\n')
io:=in.iobjects
FOR id:=0 TO in.total_objects-1
	WriteF('#\d oggetto id:\d\n',id,io[id])
ENDFOR
FOR id:=0 TO in.total_objects-1
	in.attuale:=id
	obj:=pobj(in)
	vo:=obj.vorig
	vl:=obj.vlocal
	vc:=obj.vcamera
	pol:=obj.polys
	WriteF('id:\d Name:\s\n',obj.id,obj.name)
	WriteF('num. of vert.:\d\n',obj.numverts)
	WriteF('num. of poly.:\d\n',obj.numpolys)
	WriteF('view_mode:\d\n',obj.shade)
	WriteF('state:\d\n',obj.state)
	WriteF('world pos.: X=\d Y=\d Z=\d\n',
		obj.worldposx/FIXV,obj.worldposy/FIXV,obj.worldposz/FIXV)
	WriteF('bounding box:\n max x:\d y:\d z:\d\n min x:\d y:\d z:\d\n',
		obj.xmax,obj.ymax,obj.zmax,obj.xmin,obj.ymin,obj.zmin)
	WriteF('original vertices:\n')
	FOR k:=0 TO obj.numverts-1
		WriteF('\d \d \d\n',vl[k].x/FIXV,
			vl[k].y/FIXV,vl[k].z/FIXV)
	ENDFOR
	WriteF('local vertices:\n')
	FOR k:=0 TO obj.numverts-1
		WriteF('\d \d \d\n',vl[k].x/FIXV,
			vl[k].y/FIXV,vl[k].z/FIXV)
	ENDFOR
	WriteF('camera vertices:\n')
	FOR k:=0 TO obj.numverts-1
		WriteF('\d \d \d\n',vc[k].x/FIXV,
			vc[k].y/FIXV,vc[k].z/FIXV)
	ENDFOR
	WriteF('poligon list:\n')
	FOR i:=0 TO obj.numpolys-1
		WriteF('poligon #\d\n',i)
		WriteF('\d,',pol[i].vertexlist0)
		WriteF('\d,',pol[i].vertexlist1)
		WriteF('\d,',pol[i].vertexlist2)
		WriteF('\d,',pol[i].vertexlist3)
		WriteF('color:\d shade:\d 2-sided:\d\n',
		    pol[i].color,pol[i].shade,pol[i].twosided)
		WriteF('visible:\d clipped:\d active:\d\n',
			pol[i].visible,pol[i].clipped,pol[i].active)
	ENDFOR	
ENDFOR

ENDPROC
*/

