/*********************************************
 ** Convertitore oggetti da .PLG a formato  **
 ** .3DGFO (custom libreria graphics3d).    **
 *********************************************
 ** By Patrizio Biancalani (c)1998 V 1.00   **
 *********************************************/
	OPT	PREPROCESS

MODULE 'mathieeedoubbas','dos/dos'

OBJECT stringa
	s[84]:ARRAY
ENDOBJECT

OBJECT vertex
	x:LONG,
	y:LONG,
	z:LONG
ENDOBJECT

OBJECT double_f
	a:LONG
	b:LONG
ENDOBJECT

OBJECT vert
	x:double_f
	y:double_f
	z:double_f
ENDOBJECT

OBJECT edge
	a:LONG
	b:LONG
ENDOBJECT

DEF formato:LONG
DEF reord:LONG

PROC main()
DEF num:LONG
DEF parm[8]:ARRAY OF stringa
DEF nome_in[84]:STRING
DEF nome_out[84]:STRING
DEF temp[10]:ARRAY
DEF f_in:LONG
DEF f_out:LONG
DEF i:LONG
DEF c:LONG
DEF faces:LONG
DEF color:LONG
DEF tipo:LONG
DEF f:LONG

f_in:=0
f_out:=0
tipo:=-1	/* default nessun formato */
formato:=0	/* default output .3dgfo format */
reord:=0	/* default nessun ordinamento */ 

mathieeedoubbasbase:=NIL

IF ((mathieeedoubbasbase:=OpenLibrary('mathieeedoubbas.library',38))<=NIL)
	close(f_in,f_out)
	RETURN (-10)
ENDIF

copyr()

num:=com_parse(arg,8,parm)

IF num<1 
	usage_m()
	close(f_in,f_out)
	RETURN(-11)
ENDIF 

faces:=-1
color:=-1

IF StrCmp(parm[0].s,'-help',5)=TRUE
	p_help()
	close(f_in,f_out)
	RETURN(0)
ELSE
	i:=StrLen(parm[0].s)
	IF i>80 THEN i:=80
	StrCopy(nome_in,parm[0].s,i)
	SetStr(nome_in,StrLen(nome_in))
	i:=InStr(nome_in,'.',0)
	IF i<>-1
		IF (StrCmp(nome_in+i,'.plg')=TRUE) OR
		   (StrCmp(nome_in+i,'.PLG')=TRUE) THEN tipo:=0
		StrCopy(nome_out,nome_in,i)
		SetStr(nome_out,StrLen(nome_out))
	ELSE
		StrCopy(nome_out,nome_in,ALL)
		SetStr(nome_out,StrLen(nome_out))
	ENDIF
ENDIF

IF num > NIL 
   FOR i:=1 TO num-1
	f:=0
	IF StrCmp(parm[i].s,'-help',5)=TRUE
	/* PRINT HELP PAGE */
		p_help()
		close(f_in,f_out)
		RETURN(0)
	ENDIF 
	IF StrCmp(parm[i].s,'-o',ALL) 
		StrCopy(nome_out,parm[i+1].s,80)
		SetStr(nome_out,StrLen(nome_out))
		i:=i+1
		f:=1
	ENDIF
	IF StrCmp(parm[i].s,'-d',ALL) 
		faces:=0
		f:=1
	ENDIF
	IF StrCmp(parm[i].s,'-dd',ALL) 
		faces:=1
		f:=1
	ENDIF
	IF StrCmp(parm[i].s,'-p',ALL) 
		formato:=1
		f:=1
	ENDIF
	IF StrCmp(parm[i].s,'-c',ALL)
		c:=Val(parm[i+1],NIL)	
		i:=i+1
		IF (c<NIL) OR (c>255) 
			WriteF('Illegal color value in -c option\n')
		ELSE
			color:=c
		ENDIF
		f:=1
	ENDIF
	IF f=NIL
		WriteF('conv - illegal option, use -help to see available options\n')
		close(f_in,f_out)
		RETURN(-14)
	ENDIF
   ENDFOR
ENDIF

c:=InStr(nome_out,'.')
SELECT formato
	CASE 0
	/** formato output '.3dgfo' **/
		IF c=-1
			StrAdd(nome_out,'.3dgfo')
			SetStr(nome_out,StrLen(nome_out))
		ENDIF			
	CASE 1
	/** formato output '.plg' **/
		IF c=-1
			StrAdd(nome_out,'.plg')
			SetStr(nome_out,StrLen(nome_out))
		ENDIF
ENDSELECT

f_in:=Open(nome_in,MODE_OLDFILE)
IF f_in=NIL
	WriteF('I can not open file:\s\n',nome_in)
	close(f_in,f_out)
	RETURN(-12)
ENDIF
f_out:=Open(nome_out,MODE_NEWFILE)
IF f_out=NIL
	WriteF('I can not create file:\s\n',nome_out)
	close(f_in,f_out)
	RETURN(-13)
ENDIF

/* test se t3d format */
Read(f_in,temp,8)
temp[8]:=0
IF StrCmp(temp,'% T3DLIB',ALL) THEN tipo:=1
Seek(f_in,0,OFFSET_BEGINNING)

WriteF('\nSource object file :\s\n',nome_in)
WriteF('Destination object file :\s\n\n',nome_out)

SELECT tipo
	CASE 0
	/* .PLG format */
		WriteF('Source file in .PLG format\n')
		i:=plgloadobject(f_in,f_out,color,faces)
	CASE 1
	/* .TDDD format */
		IF color=-1 THEN color:=2
		IF faces=-1 THEN faces:=1
		WriteF('Source file in .TDDD format\n')
		i:=t3dloadobject(f_in,f_out,color,faces)
	CASE 2
	/* .POV format */

	DEFAULT
	/* formato ignoto */
		WriteF('Unrecognized object format\n')
		i:=1
ENDSELECT

IF i=NIL
	WriteF('Found an error in source file, conversion aborted!\n')
ENDIF

close(f_in,f_out)

ENDPROC 

PROC close(in:LONG,out:LONG)

IF mathieeedoubbasbase>NIL THEN CloseLibrary(mathieeedoubbasbase)

IF in<>NIL THEN Close(in)
IF out<>NIL THEN Close(out)

ENDPROC

/*** Print help page ***/
PROC p_help()

WriteF('**** HELP PAGE ****\n')
usage_m()
WriteF('	input : file name of .PLG or .TDDD object\n')
WriteF('   	-o    : set with "output" file name of object in\n')
WriteF('		.3dgfo format\n')
WriteF('	-d    : set all polygons as 1 faces (override source)\n')
WriteF('	-dd   : set all polygons as 2 faces (override source)\n')
WriteF('	-c    : set all poligons colour with n_col (override source)\n')
WriteF('	-p    : output file in .plg format instead of 3dgfo\n')
WriteF('        -help : this page\n')

ENDPROC

/*** Print usage messages ***/
PROC usage_m()

WriteF('Usage: conv input [[-help],[-o output],[-r],[-d],[-dd],[-p],[-c n_col]]\n') 

ENDPROC

/*** Print CopyRigth messages ***/
PROC copyr()

WriteF('conv - 3D object converter .PLG,TDDD -> .3dgfo V1.10\n')
WriteF('      by Patrizio Biancalani (c)1998 \n')

ENDPROC

/*****************************************
 ** parsing command string		**
 ** estrae gli argomenti separati da    **
 ** spazzi.				**
 *****************************************
 *** INPUT :				**
 ** argc = stringa comandi		**
 ** argv = numero parametri massimo	**
 ** argp = array di stringhe per i	**
 **	   parametri estratti ,deve     **
 **         essere di argv elementi.    **
 *** OUTPUT :				**
 ** elementi effettivamente estratti.   **
 *****************************************/
PROC com_parse(argc:PTR TO CHAR,argv:LONG,argp:PTR TO stringa)
DEF i :LONG
DEF n :LONG
DEF f :LONG
DEF c :LONG
DEF l :LONG
DEF l1:LONG

n:=0
f:=1
l:=StrLen(argc)
l1:=0
FOR i:=0 TO l-1
	c:=argc[i]
	IF c<>" "
		IF l1<80 
			argp[n].s[l1]:=c
			l1:=l1+1
		ENDIF
		f:=0
	ENDIF
	IF (c=" ") AND (f=NIL)
		f:=1
		argp[n].s[l1]:=0
		n:=n+1
		l1:=0
		IF n>argv THEN i:=l+1
	ENDIF
	
ENDFOR 

IF f=NIL
	argp[n].s[l1]:=0
	n:=n+1
ENDIF

ENDPROC n

/********************************************
 ** Scrive Header nel formato indicato in  **
 ** formato (0=.3dgfo,1=.plg)		   **
 **** INPUT :				   **
 ** out -> file handler su cui scrivere.   **
 ** nome-> nome oggetto.		   **
 ** n_vert -> numero vertici.		   **
 ** n_pol  -> numero poligoni.		   **
 **** OUTPUT:				   **
 ********************************************/ 
PROC w_header(out:LONG,nome:LONG,n_vert:LONG,n_pol:LONG)
DEF temp[100]:ARRAY

SELECT formato
	CASE 0
	/* output in .3dgfo */
		StrCopy(temp,'3DGFXV1.00',ALL)
		Write(out,temp,StrLen(temp)+1)
		Write(out,nome,StrLen(nome)+1)
		Write(out,{n_vert},4)
		Write(out,{n_pol},4)
	
	CASE 1
	/* output in .plg */
		StringF(temp,';\n; .PLG object file write with\n')
		StringF(temp,'\s; conv V1.00 (c) Patrizio Biancalani 1998\n;\n',temp)
		Write(out,temp,StrLen(temp))
		StringF(temp,' \s \d \d\n\n',nome,n_vert,n_pol)
		Write(out,temp,StrLen(temp))
	
ENDSELECT

WriteF('Found #\d vertex\nFound #\d polygons\n',n_vert,n_pol)

ENDPROC

/********************************************
 ** Scrive tripletta x,y,z nel formato dato** 
 ** in formato (0=.3dgfo,1=.plg)	   **
 **** INPUT :				   **
 ** out -> file handler su cui scrivere.   **
 ** x -> valore x in double_f		   **
 ** y -> valore y in double_f		   **
 ** z -> valore z in double_f		   **
 **** OUTPUT:				   **
 ********************************************/ 
PROC w_xyz(out:LONG,x:PTR TO double_f,y:PTR TO double_f,z:PTR TO double_f)
DEF temp[100]:ARRAY
DEF v:double_f
DEF v1:double_f
DEF x1:LONG
DEF y1:LONG
DEF z1:LONG
DEF a:LONG
DEF b:LONG
DEF d0:LONG
DEF d1:LONG

SELECT formato
	CASE 0
	/* output in .3dgfo */
		d0:=x.a
		d1:=x.b
		Write(out,{d0},4)
		Write(out,{d1},4)
		d0:=y.a
		d1:=y.b
		Write(out,{d0},4)
		Write(out,{d1},4)
		d0:=z.a
		d1:=z.b
		Write(out,{d0},4)
		Write(out,{d1},4)
	CASE 1
	/* output in .plg */
		d0,d1:=IeeeDPFlt(1)
		v1.a:=d0
		v1.a:=d1
		d0,d1:=IeeeDPFlt(2)
		v.a:=d0
		v.a:=d1
		d0,d1:=IeeeDPDiv(v1.a,v1.b,v.a,v.b)
		v1.a:=d0
		v1.a:=d1
		x1:=IeeeDPFix(x.a,x.b)
		y1:=IeeeDPFix(y.a,y.b)
		z1:=IeeeDPFix(z.a,z.b)

		StringF(temp,' \r\d[8] \r\d[8] \r\d[8] \n',x1,y1,z1)
		Write(out,temp,StrLen(temp))
ENDSELECT

ENDPROC

/********************************************
 ** Scrive flag+colore e desc. spigoli nel ** 
 ** formato in "formato" (0=.3dgfo,1=.plg) **
 **** INPUT :				   **
 ** out -> file handler su cui scrivere.   **
 ** flag -> flag+colore			   **
 ** n_v -> numero vertici.		   **
 ** p0 -> primo vertice			   **
 ** p1 -> secondo vertice		   **
 ** p2 -> terzo vertice			   **
 ** p4 -> quarto vertice		   **
 ********************************************
 **** OUTPUT:				   **
 ********************************************/ 
PROC w_fcp(out:LONG,flag:LONG,n_v:LONG,p0:LONG,p1:LONG,p2:LONG,p3:LONG)
DEF temp[100]:ARRAY
DEF flag1:LONG

SELECT formato
	CASE 0
	/* output in .3dgfo */
	Write(out,{flag},4)
	Write(out,{n_v}+3,1)
	Write(out,{p0},4)
	SELECT n_v
		CASE 2
			Write(out,{p1},4)
		CASE 3
			Write(out,{p1},4)
			Write(out,{p2},4)
		DEFAULT
			Write(out,{p1},4)
			Write(out,{p2},4)
			Write(out,{p3},4)
	ENDSELECT	
	CASE 1
	/* output in .plg */
	   flag1:=And(flag,$FF)
	   IF And(flag,$2000000)<>NIL THEN flag1:=flag1+$1000
	   SELECT n_v
		CASE 1
			StringF(temp,' 0x\z\h[4] 1 \d \n',flag1,p0)
		CASE 2
			StringF(temp,' 0x\z\h[4] 2 \d \d \n',flag1,p0,p1)
		CASE 3
			StringF(temp,' 0x\z\h[4] 3 \d \d \d \n',flag1,p0,p1,p2)
		CASE 4
			StringF(temp,' 0x\z\h[4] 4 \d \d \d \d \n',flag1,p0,p1,p2,p3)
	   ENDSELECT	
	   Write(out,temp,StrLen(temp))

ENDSELECT

ENDPROC

/************************************************
 ** legge i dati di un oggetto da un file .TDDD**
 ** e li traduce nel nuovo formato .3dgfo      ** 
 ************************************************
 *** INPUT :				        * 
 * in -> file handler oggetto .PLG		* 
 * out -> file handler oggetto .3dgfo		*
 *** OUTPUT:					*
 * >0 tutto ok, oggetto letto.			*
 * =0 operazione fallita.			*
 ************************************************/
PROC t3dloadobject(in:LONG,out:LONG,coll:LONG,double:LONG)
DEF esi
DEF tempstr[100]:ARRAY
DEF temp:PTR TO CHAR
DEF name[90]:STRING
DEF i:LONG
DEF st:LONG
DEF e:LONG
DEF b:LONG
DEF flag:LONG
DEF stato:LONG
DEF n_vert:LONG
DEF n_pol:LONG
DEF n_edge:LONG
DEF s_obj:LONG
DEF p_ct:LONG
DEF f_ct:LONG
DEF e_ct:LONG
DEF p_pos:LONG
DEF f_pos:LONG
DEF e_pos:LONG
DEF x:double_f
DEF y:double_f
DEF z:double_f
DEF d0:LONG
DEF d1:LONG
DEF p0:LONG
DEF p1:LONG
DEF p2:LONG
DEF pp:LONG
DEF e0:LONG
DEF e1:LONG
DEF e2:LONG
DEF ord:LONG
DEF pt_e:PTR TO edge
DEF pt_v:PTR TO vert

esi:=0
stato:=0
n_vert:=0
n_pol:=0
n_edge:=0
p_ct:=0
f_ct:=0
e_ct:=0
p_pos:=0
f_pos:=0
e_pos:=0
pt_e:=NIL
pt_v:=NIL

/* make flag byte + colors bytes*/
flag:=Shl(($01+(double*2)),24)+coll

REPEAT
	e:=Fgets(in,tempstr,90)
	temp:=TrimStr(tempstr)
	IF temp<tempstr+StrLen(tempstr)
	   SELECT stato
		CASE 0
		/** look for object start definition **/
			st:=InStr(temp,'OBJ ',NIL)
			IF st<>-1 
				s_obj:=Seek(in,0,OFFSET_CURRENT)
				stato:=1
			ENDIF
		CASE 1
		/** look for object name **/
			st:=InStr(temp,'NAME',NIL)
			IF st<>-1
				st:=InStr(temp,'"',st)+1
				i:=InStr(temp,'"',st)-st
				IF i>80 THEN i:=80	
				MidStr(name,temp,st,i)
				Seek(in,s_obj,OFFSET_BEGINNING)
				stato:=2
			ENDIF			
		CASE 2
		/** look for total number of vertex **/
			st:=InStr(temp,'PNTS',NIL)
			IF st<>-1
				i:=InStr(temp,'PCount',st+4)
				IF i<>-1
					i:=i+6
					n_vert:=Val(temp+i,NIL)
					p_pos:=Seek(in,s_obj,OFFSET_BEGINNING)
					pt_v:=New(n_vert*(SIZEOF vert)+100)
					IF pt_v=NIL THEN e:=NIL
					stato:=3
				ENDIF
			ENDIF
		CASE 3
		/** look for total number of polygons **/
			st:=InStr(temp,'FACE',NIL)
			IF st<>-1
				i:=InStr(temp,'TCount',st+4)
				IF i<>-1
					i:=i+6
					n_pol:=Val(temp+i,NIL)
					f_pos:=Seek(in,s_obj,OFFSET_BEGINNING)
					w_header(out,name,n_vert,n_pol)
					p_ct:=0
					f_ct:=0
					stato:=5
				ENDIF
			ENDIF
		CASE 5
		/** look for coordinates of all vertex **/
			st:=InStr(temp,'PNTS',NIL)
			IF st<>-1 
			   st:=InStr(temp,'Point[',st+4)
			   IF st<>-1
				st:=st+6
				i:=InStr(temp,']',st)
				temp[i]:=0
				b:=i	
				i:=Val(temp+st,NIL)
				st:=b+1
				IF i=p_ct
					d0,d1:=readX(temp+st)
					x.a:=d0
					x.b:=d1
					pt_v[i].x.a:=d0
					pt_v[i].x.b:=d1
					d0,d1:=readY(temp+st)
					y.a:=d0
					y.b:=d1
					pt_v[i].y.a:=d0
					pt_v[i].y.b:=d1
					d0,d1:=readZ(temp+st)
					z.a:=d0
					z.b:=d1
					pt_v[i].z.a:=d0
					pt_v[i].z.b:=d1
					w_xyz(out,x,y,z)
					p_ct:=p_ct+1
					IF p_ct>=n_vert 	
					    Seek(in,s_obj,OFFSET_BEGINNING)
					    stato:=6
					ELSE
/*
					    Seek(in,p_pos,OFFSET_BEGINNING)
*/
					ENDIF
				ENDIF
			    ENDIF
			ENDIF
		CASE 6
		/** look for total number of lines **/
			st:=InStr(temp,'EDGE',NIL)
			IF st<>-1
				i:=InStr(temp,'ECount',st+4)
				IF i<>-1
					i:=i+6
					n_edge:=Val(temp+i,NIL)
					e_pos:=Seek(in,s_obj,OFFSET_BEGINNING)
					e_ct:=0
					pt_e:=New(((SIZEOF edge)*n_edge)+100)
					IF pt_e=NIL THEN e:=NIL
					stato:=7
				ENDIF
			ENDIF
		CASE 7
		/** look for vertex of start and stop of all lines **/
			st:=InStr(temp,'EDGE',NIL)
			IF st<>-1 
			   st:=InStr(temp,'Edge[',st+4)
			   IF st<>-1
				st:=st+5
				i:=InStr(temp,']',st)
				temp[i]:=0
				b:=i	
				i:=Val(temp+st,NIL)
				st:=b+1
				IF i=e_ct
					temp:=TrimStr(temp+st)
					st:=InStr(temp,' ',0)
					temp[st]:=0
					pt_e[e_ct].a:=Val(temp,0)
					pt_e[e_ct].b:=Val(temp+st+1,0)
					e_ct:=e_ct+1
					IF e_ct>=n_edge
					    Seek(in,s_obj,OFFSET_BEGINNING)
					    stato:=10
					ELSE
/*
					    Seek(in,e_pos,OFFSET_BEGINNING)
*/
					ENDIF
				ENDIF
			    ENDIF
			ENDIF
		CASE 10
		/** look for vertex of all poligons **/
			st:=InStr(temp,'FACE',NIL)
			IF st<>-1 
			   st:=InStr(temp,'Connect[',st+4)
			   IF st<>-1
				st:=st+8
				i:=InStr(temp,']',st)
				temp[i]:=0
				b:=i	
				i:=Val(temp+st,NIL)
				st:=b+1
				IF i=f_ct
					temp:=TrimStr(temp+st)
					st:=InStr(temp,' ',0)
					temp[st]:=0
					e0:=Val(temp,0)
					temp:=TrimStr(temp+st+1)
					st:=InStr(temp,' ',0)
					temp[st]:=0
					e1:=Val(temp,0)
					temp:=TrimStr(temp+st+1)
					st:=InStr(temp,' ',0)
					temp[st]:=0
					e2:=Val(temp+st+1,0)
					p0:=pt_e[e0].a
					p1:=pt_e[e0].b
					p2:=99999
					/** OK **/
					IF p1=pt_e[e1].a THEN p2:=pt_e[e1].b
					/** PARE QUASi OK **/
					IF p1=pt_e[e1].b 
						p2:=pt_e[e1].b
						pp:=p1
						p1:=p0
						p0:=pp
					ENDIF
					/** OK **/
					IF p0=pt_e[e1].a
						p2:=pt_e[e1].b
						pp:=p1
						p1:=p0
						p0:=pp
					ENDIF
					/** OK **/
					IF p0=pt_e[e1].b
						p2:=pt_e[e1].a
						pp:=p1
						p1:=p0
						p0:=pp
					ENDIF
					w_fcp(out,flag,3,p0,p1,p2,0)
					f_ct:=f_ct+1
					IF f_ct>=n_pol
					    stato:=1000
					ELSE
/*
					    Seek(in,f_pos,OFFSET_BEGINNING)
*/
					ENDIF
				ENDIF
			    ENDIF
			ENDIF
		
	   ENDSELECT		
	ENDIF
UNTIL ((e=NIL) OR (stato=1000))

IF pt_e<>NIL THEN Dispose(pt_e)
IF pt_v<>NIL THEN Dispose(pt_v)

WriteF('stato=\d\n',stato)

IF stato=1000 THEN esi:=1

ENDPROC esi

PROC readX(str:PTR TO CHAR)
DEF i:LONG
DEF l:LONG
DEF c[20]:STRING

i:=InStr(str,'X=',0)+2
l:=InStr(str,' ',i)-i

StrCopy(c,str+i,l)
SetStr(c,StrLen(c))

ENDPROC readf(c)

PROC readY(str:PTR TO CHAR)
DEF i:LONG
DEF l:LONG
DEF c[20]:STRING

i:=InStr(str,'Y=',0)+2
l:=InStr(str,' ',i)-i

StrCopy(c,str+i,l)

ENDPROC readf(c)

PROC readZ(str:PTR TO CHAR)
DEF i:LONG
DEF l:LONG
DEF c[20]:STRING

i:=InStr(str,'Z=',0)+2
l:=InStr(str,' ',i)-i

StrCopy(c,str+i,l)

ENDPROC readf(c)

PROC readf(str:PTR TO CHAR)
DEF i:LONG
DEF c:LONG
DEF s[80]:STRING
DEF v:LONG
DEF di:LONG
DEF dv:LONG
DEF d:double_f
DEF a:double_f
DEF b:double_f
DEF d0:LONG
DEF d1:LONG

i:=InStr(str,'.',0)

IF i<>-1
	StrCopy(s,str,i)
	v:=Val(s,0)
	StrCopy(s,str+i+1,StrLen(str)-i-1)
	di:=Val(s,0)
	dv:=1
	FOR c:=0 TO StrLen(s) DO IF (s[c]>="0") AND (s[c]<="9") THEN dv:=dv*10
	d0,d1:=IeeeDPFlt(di)
	a.a:=d0
	a.b:=d1
	d0,d1:=IeeeDPFlt(dv)
	b.a:=d0
	b.b:=d1
	d0,d1:=IeeeDPDiv(a.a,a.b,b.a,b.b)
	d.a:=d0
	d.b:=d1
ELSE
	d0,d1:=IeeeDPFlt(0)
	d.a:=d0
	d.b:=d1
	v:=Val(str,0)
ENDIF

d0,d1:=IeeeDPFlt(v)
a.a:=d0
a.b:=d1

d0,d1:=IeeeDPAdd(a.a,a.b,d.a,d.b)

ENDPROC d0,d1

/************************************************
 ** legge i dati di un oggetto da un file .PLG **
 ** e li traduce nel nuovo formato .3dgfo      ** 
 ************************************************
 *** INPUT :				        * 
 * in -> file handler oggetto .PLG		* 
 * out -> file handler oggetto .3dgfo		*
 *** OUTPUT:					*
 * >0 tutto ok, oggetto letto.			*
 * =0 operazione fallita.			*
 ************************************************/
PROC plgloadobject(in:LONG,out:LONG,coll:LONG,double:LONG)
DEF total_vertices:LONG,
    total_polys:LONG,
    num_vertices:LONG,
    color_des:LONG,
    index:LONG,
    ln:LONG,
    tempword:LONG,
    v0:LONG,
    v1:LONG,
    p1:LONG,
    p2:LONG,
    p3:LONG,
    p4:LONG,	
    pp:LONG,
    tempbyte:LONG,
    t:LONG,
    k:LONG,
    v:vertex,
    x:double_f,
    y:double_f,
    z:double_f,
    vl:PTR TO LONG,
    pt_v:PTR TO vert,
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
    p:PTR TO CHAR,
   ord:LONG,
   err:LONG,
   esi:LONG

esi:=0
file:=in
ln:=0
cs:=0
err:=0
pt_v:=NIL
WHILE ((err=NIL) AND ((cl:=Read(file,temp,495))>NIL))
	cc:=0
	WHILE (cc<cl)
		sbuffer[cs++]:=temp[cc++]
		IF (sbuffer[cs-1]=$0D) OR (sbuffer[cs-1]=$0A) 
			sbuffer[cs]:=0
/** place here the code of reading datas from file **/
	plggetline(sbuffer)
#ifdef DEBUG
WriteF('Line read by plggetline :\s\n',sbuffer)
#endif
	IF StrLen(sbuffer)>3   /* test if line not empty */
		INC ln
		IF ln=1		
			tempbyte:=lstr(sbuffer,name,0)		
			tempbyte:=lstr(sbuffer,tempstr,tempbyte)
			total_vertices:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Total_vertices:\d\n',total_vertices)
#endif
			pt_v:=New((SIZEOF vert)*total_vertices+100)
			IF pt_v=NIL 
				err:=1
				cc:=cl
				JUMP prox
			ENDIF
			lstr(sbuffer,tempstr,tempbyte)
			total_polys:=Val(tempstr,{i})
#ifdef DEBUG
WriteF('Total_polys:\d\n',total_polys)
#endif
			name[StrLen(name)+1]:=00
			w_header(out,name,total_vertices,total_polys)

		/** valori integer **/
		ELSEIF (ln>=2) AND ((total_vertices+1)>=ln)
			tempbyte:=lstr(sbuffer,tempstr,0)
			v.x:=Val(tempstr,{i})
			tempbyte:=lstr(sbuffer,tempstr,tempbyte)
			v.y:=Val(tempstr,{i})
			lstr(sbuffer,tempstr,tempbyte)
			v.z:=Val(tempstr,{i})

			v0,v1:=IeeeDPFlt(v.x)
			x.a:=v0
			x.b:=v1
			pt_v[ln-2].x.a:=v0
			pt_v[ln-2].x.b:=v1
			v0,v1:=IeeeDPFlt(v.y)
			y.a:=v0
			y.b:=v1
			pt_v[ln-2].y.a:=v0
			pt_v[ln-2].y.b:=v1
			v0,v1:=IeeeDPFlt(v.z)		
			z.a:=v0
			z.b:=v1
			pt_v[ln-2].z.a:=v0
			pt_v[ln-2].z.b:=v1

			w_xyz(out,x,y,z)
			
#ifdef DEBUG
WriteF('Value of vertex n#\d in integer : x=\d y=\d y=\d\n',ln-2,v.x,v.y,v.z) 
#endif

		ELSEIF (total_vertices+2<=ln) AND 
			(total_polys+total_vertices+1>=ln)
			tempbyte:=lstr(sbuffer,tempstr,0)
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
			col:=And($FF,color_des)
/*
			IF col<16 THEN col:=1
			IF col>16 THEN col:=16
*/
#ifdef DEBUG
WriteF('Color :\d\n',col)
#endif
		
	/* make Flag(1 byte) + Color(3 byte) */
	/* Flag :bit 0 - RGB color(0) index color(1)
		 bit 1 - polygon 1 face(0) 2 faces(1)
		 bit 2-7 - reserved for future use they must be set to 0*/	
		tempstr[0]:=$01		/* set always index color */
		IF double<>-1
			IF double=1 THEN tempstr[0]:=tempstr[0]+$02
		ELSE
			IF Shr(color_des,12)<>NIL THEN tempstr[0]:=tempstr[0]+$02
		ENDIF
	/* Color :
		byte 0 - Red value if RGB Color
		byte 1 - Green value if RGB color
		byte 2 - Blue value if RGB color ,Index value if index color */
		tempstr[1]:=$00
		tempstr[2]:=$00
		IF coll<>-1
			tempstr[3]:=coll
		ELSE
			tempstr[3]:=col
		ENDIF

		w_fcp(out,^tempstr,num_vertices,p1,p2,p3,p4)

		ENDIF
	ENDIF
/****************************************/
			cs:=0
		ENDIF
	prox:
	ENDWHILE
ENDWHILE

IF pt_v<>NIL THEN Dispose(pt_v)

esi:=1
IF err<>NIL THEN esi:=0

ENDPROC esi

/******************************************************/
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

/****************************************************/
/** in 'str' place the first sequence of caracters **/
/** other than space that are in 's' from 'start', **/
/** 'str' must be sufficent long , result is the   **/
/** first position after the sequence.             **/ 
/****************************************************/
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
