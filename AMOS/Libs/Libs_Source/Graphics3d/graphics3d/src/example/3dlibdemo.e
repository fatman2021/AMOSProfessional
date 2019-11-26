
/*** Routin of test for graphics3d.library **/
/** SEE 3dlib.h also **/

PROC main()
DEF a3d:LONG
DEF g:LONG
DEF w:LONG
DEF i:LONG
DEF in:LONG
DEF out:LONG
DEF ob:LONG
DEF np:LONG
DEF d:LONG
DEF s:LONG
DEF esi:LONG
DEF cb:LONG
DEF tmap1:LONG
DEF tmap2:LONG
DEF tmap3:LONG
DEF mode:LONG
DEF c1:rgbtype
DEF c2:rgbtype
DEF vdist:LONG
DEF gcolor:LONG
DEF x0:LONG
DEF y0:LONG
DEF pjt:LONG
DEF id:LONG
DEF px:LONG
DEF py:LONG
DEF ay:LONG
DEF ax:LONG
DEF az:LONG
DEF lx:LONG
DEF ly:LONG
DEF lz:LONG
DEF il:LONG
DEF vx:LONG
DEF sx:LONG
DEF ds:LONG
DEF sl:LONG
DEF fa:LONG
DEF fd:LONG
DEF ar:LONG
DEF fm:LONG
DEF sid:LONG
DEF dw:LONG
DEF dh:LONG
DEF dp:LONG
DEF xx:LONG
DEF xxx:LONG
DEF yy:LONG
DEF yyy:LONG
DEF oassi:LONG
DEF dts:datestamp
DEF dts1:datestamp
DEF mvert:vtmap
DEF time:LONG
DEF scrr:PTR TO screenmoderequester
DEF buf[100]:STRING
DEF coll[10]:ARRAY OF LONG
DEF zbuf:LONG

WriteF('INIZIALIZZAZIONE ...\n')
sid:=$8000
dw:=640
dh:=240

aslbase:=NIL
IF ((aslbase:=OpenLibrary('asl.library',38))<=NIL) THEN JUMP no_asl

scrr:=AllocAslRequest(ASL_SCREENMODEREQUEST,
	[ASLSM_MAXDEPTH,8,
	 ASLSM_MINDEPTH,5,
	 ASLSM_MINWIDTH,640,
	 NIL])
IF scrr=NIL THEN JUMP abort_b1 

IF AslRequest(scrr,[NIL])=FALSE THEN JUMP abort_b1

dw:=scrr.displaywidth
dh:=scrr.displayheight
sid:=scrr.displayid

dp:=5

xx:=550
xxx:=350
yy:=200
yyy:=150

IF dw>640 
	xx:=dw-70
	xxx:=xx-200
ENDIF
IF dh>256
	yy:=dh-86
	yyy:=yy-50
ENDIF

IF InStr(arg,'256',0)<>-1 THEN dp:=8

WriteF('Colour depth :\d\n',dp)

ar:=FIXV
IF (dw>400)
	IF dh<300 THEN ar:=ar/2
	IF dh<400 THEN ar:=((dh+90)*FIXV)/dw
ENDIF
WriteF('aspect ratio =\d\n',ar)

no_asl:

WriteF('mode_id:$\h  width:\d height:\d\n',sid,dw,dh)

/*s:=OpenS(dw,dh,5,sid,'TEST 3DLIBS VERS. IN E')*/
s:=OpenScreenTagList(NIL,
	[SA_TITLE,'TEST 3DLIBS VERS. IN E',
	 SA_DEPTH,dp,
	 SA_TYPE,CUSTOMSCREEN,
	 SA_DISPLAYID,sid,
	 SA_WIDTH,dw,
	 SA_HEIGHT,dh,
	 NIL])
IF s<=NIL THEN JUMP abort_b1 

g:=start_es(s)
IF g<=NIL 
	CloseScreen(s)
	JUMP abort_b1
ENDIF

w:=gad_w(g,20,20,xx,yy,'prova 3dlib',13)

WriteF('window=\d\n',w)

/** set mode cursor for object and initial light position **/
fm:=0
sl:=16
il:=1*FIXV
lx:=0
ly:=0
lz:=-sl*9
/********************************/

/** set off z-buffering **/
zbuf:=0

/** OPEN AND INITIALIZE A NEW 3D SPACE **/
a3d:=display3d(w,0,0,xxx,yyy,300)
IF a3d=NIL THEN JUMP abort_b
/***************************************/

/** TEST FUNCTION INTEGER <-> FIXPOINT ***/
i:=12
WriteF('i2f=\d\n',Gd_int2fix({i},{out}))
WriteF('f2i=\d\n',Gd_fix2int({out},{in}))
WriteF('orig=\d int=\d fix=\d \n',i,in,out)
/****************************************/

/** DEFINE TWO SFUMATE COLOURS, FOR SHADING AND ONE TRASPARENT COLOUR **/ 
Gd_genpalette(a3d,[GP_RCOL,4,
		   GP_NCOL,4,
		   GP_NLIV,200,
		   GP_TRASP,0,
		   GP_COL,2,
		   END_T,NIL]:tag3d)
IF dp=5 
	c1.r:=0
	c1.g:=0
	c1.b:=0
	c2.r:=15
	c2.g:=2
	c2.b:=0
/* obsoleta */
/*	Gd_touchpalette(a3d,16,30,c1,c2)*/
	Gd_genpalette(a3d,
		 [GP_COL,0,
 		  GP_HRGB,c2,
		  GP_LRGB,c1,
		  END_T,NIL]:tag3d)	
	WriteF('touch1\n')
	c1.r:=0
	c1.g:=0
	c1.b:=0
	c2.r:=0 
	c2.g:=2
	c2.b:=15
/* obsoleta */
/*	Gd_touchpalette(a3d,1,15,c1,c2) */
	Gd_genpalette(a3d,
		 [GP_COL,1,
		  GP_HRGB,c2,
		  GP_LRGB,c1,
		  END_T,NIL]:tag3d)	
	WriteF('touch2\n')
ELSE
	c1.r:=0
	c1.g:=0
	c1.b:=0
	c2.r:=255
	c2.g:=28
	c2.b:=0
/* obsoleta */
/*	Gd_touchpalette(a3d,31,60,c1,c2)*/
	Gd_genpalette(a3d,
		 [GP_COL,0,
		  GP_HRGB,c2,
		  GP_LRGB,c1,
		  END_T,NIL]:tag3d)	
	WriteF('touch1\n')
	c1.r:=0
	c1.g:=0
	c1.b:=0
	c2.r:=0 
	c2.g:=28
	c2.b:=255
/* obsoleta */
/*	Gd_touchpalette(a3d,1,30,c1,c2)*/
	Gd_genpalette(a3d,
		 [GP_COL,1,
		  GP_HRGB,c2,
		  GP_LRGB,c1,
		  END_T,NIL]:tag3d)	
	WriteF('touch2\n')
ENDIF
/**************************************************/

/** SET DEFAULT SOLID SHADING **/
cb:=1
mode:=SOLID
/*******************************/

/** DEFINE A NEW ASPECT RATIO FOR SELECTED SCREEN **/
Gd_aspectratio(a3d,ar)
WriteF('change aspect ratio\n')
/****************************************************/

/** DEFINE ALL TEXTURED MAPS **/
tmap1:=Gd_newtmap(a3d,12,12,[1,0,1,0,1,0,1,0,1,0,1,0,
			     0,0,0,0,0,0,0,0,0,0,0,0,
			     0,1,0,1,0,1,0,1,0,1,0,1,
			     0,0,0,0,0,0,0,0,0,0,0,0,
			     1,0,1,0,1,0,1,0,1,0,1,0,
			     1,1,1,1,1,1,1,1,1,1,1,1,
			     0,1,0,1,0,1,0,1,0,1,0,1,
			     1,1,1,1,1,1,1,1,1,1,1,1,
			     1,0,0,0,0,0,0,0,0,0,0,1,
			     1,0,0,0,0,2,2,0,0,0,0,1,
			     1,0,0,0,0,0,0,0,0,0,0,1,
			     1,1,1,1,1,1,1,1,1,1,1,1]:CHAR)
WriteF('Tmap1=\d\n',tmap1)
tmap2:=Gd_newtmap(a3d,6,6,[1,1,1,1,1,1,
			   0,1,0,0,0,0,
			   0,0,1,0,0,0,
			   0,0,0,1,0,0,
			   0,0,0,0,1,0,
			   1,1,1,1,1,1]:CHAR)
WriteF('Tmap2=\d\n',tmap2)
tmap3:=Gd_newtmapf(a3d,'prova.iff')
WriteF('Tmap3=\d\n',tmap3)

/*******************************/
esi:=0
oassi:=0
/** CREATE AND POSITION OF #1 OBJECT *****/
WriteF('Leggo oggetto assi ...\n')
/*
i:=plgloadobject(a3d,'assi.plg',1*FIXV)
*/
oassi:=Gd_loadobject(a3d,'assi.3dgfo',1*FIXV)
WriteF('result plgloadobject assi :\d\n',oassi)
IF oassi<>0 THEN Gd_positionobject(a3d,0,0,0)
esi:=esi+oassi

WriteF('Leggo #1 oggetto...\n')
/*
i:=plgloadobject(a3d,'pyramid.plg',1*FIXV)
i:=Gd_loadobject(a3d,'pyramid.3dgfo',1*FIXV)
WriteF('result plgloadobject #1 :\d\n',i)
IF i<>0 THEN Gd_positionobject(a3d,500*FIXV,0,560*FIXV)
esi:=esi+i
*/

/** CREATE AND POSITION OF 2# OBJECT *****/
WriteF('Leggo #2 oggetto...\n')
/*
i:=plgloadobject(a3d,'sfera.plg',2*FIXV)
*/
i:=Gd_loadobject(a3d,'sfera.3dgfo',2*FIXV)
WriteF('result plgloadobject #2 :\d\n',i)
IF i<>0 THEN Gd_positionobject(a3d,200*FIXV,0,800*FIXV)
esi:=esi+i

Gd_modobj(a3d,[MO_VMODE,FLAT,END_T,0]:tag3d)

/** CREATE AND POSITION OF #3 OBJECT *****/
WriteF('Leggo #3 oggetto...\n')
/*
i:=plgloadobject(a3d,'cube.plg',1*FIXV)
*/
i:=Gd_loadobject(a3d,'cube.3dgfo',1*FIXV)
WriteF('result plgloadobject #3 :\d\n',i)
IF i<>0 THEN Gd_positionobject(a3d,-50*FIXV,0,0)
esi:=esi+i
/** PLACE THE TEXTURE MAPS ON THIS OBJECT **/
IF i<>0
	mvert.x1:=0
	mvert.y1:=0
	mvert.x2:=5
	mvert.y2:=0
	mvert.x3:=5
	mvert.y3:=5
	mvert.x4:=0
	mvert.y4:=5	
	/* #2 texture map on polygon #5 ,#2 texture map on polygon #0 and 
	   #3 texture map on polygon #1 */
	Gd_modpoly(a3d,
	[MP_POLY,5,		
	 MP_TMAP,tmap2,
	 MP_VTMAP,mvert,
	 MP_POLY,0,
	 MP_TMAP,tmap2,
	 MP_VTMAP,mvert,
	 MP_POLY,1,
	 MP_TMAP,tmap3,
	 MP_VTAUTO,0,
	 MP_POLY,2,
	 MP_TMAP,tmap3,
	 MP_VTAUTO,0,
       	 END_T,0]:tag3d)
ENDIF

/** CREATE AND POSITION OF #4 OBJECT *****/
WriteF('Leggo #4 oggetto...\n')
/*
i:=plgloadobject(a3d,'pyramid.plg',2*FIXV)
*/
i:=Gd_loadobject(a3d,'pyramid.3dgfo',2*FIXV)
WriteF('result plgloadobject #4 :\d\n',i)
IF i<>0 THEN i:=Gd_positionobject(a3d,400*FIXV,0,750*FIXV)
/** PLACE THE TEXTURE MAPS ON THIS OBJECT **/
IF i<>0
	mvert.x1:=0
	mvert.y1:=0
	mvert.x2:=11
	mvert.y2:=0
	mvert.x3:=11
	mvert.y3:=11
	mvert.x4:=0
	mvert.y4:=11
	Gd_modpoly(a3d,[MP_POLY,4,MP_TMAP,tmap1,MP_VTMAP,mvert,END_T,0]:tag3d)
ENDIF
/*****************************************/
esi:=esi+i
IF esi=NIL THEN JUMP abort_b

Gd_frustum(a3d,-1005,16000)           /* CHANGE SOME SETTINGS */
Gd_clipmode(a3d,ZPLANE)             /* EITHER #FRUSTUM OR #ZPLANE */
Gd_createlightsource(a3d,lx,ly,lz)  /* PLACE THE LIGHT SOURCES */
Gd_ambientlight(a3d,il)             /* SET THE INITIAL LIGHT INTENSITY */ 
Gd_positioncamera(a3d,0,0,-1000*FIXV)
			/* CAMERA AT SOME HEIGHT OFF THE GROUND */

/** SET OFF ALL SCENE 3D PARAMETERS **/
/** CHANGE COLOUR OF VISUALIZATION BOX **/
gcolor:=3
/** CHANGE OBSERVER DISTANCE **/
vdist:=500
/** CHANGE BOX ORIGIN **/
x0:=10
y0:=15
/** CHANGE TYPE OF PROJECTION (experimental) **/
pjt:=PARAL_P

WriteF('cp. esi=\d\n',Gd_cascene(a3d,[ CS_GCOLOR,gcolor,
	CS_VDIST,vdist,
	CS_NPX0,x0,
	CS_NPY0,y0,
	END_T,NIL]:tag3d))
/*****************************************/

/** DISPLAY THE BORDERS OF VISUALIZATION BOX **/
Box(x0-1,y0-1,350+x0+1,150+y0+1,1)

DateStamp(dts)
/*** RECALC THE VIEWING ***/
Gd_newview(a3d)
/*** REDRAW THE VIEWING ***/
Gd_paintframe(a3d)
/*** VISUALIZING THE VIEWING ***/ 
Gd_switch_rp(a3d)
DateStamp(dts1)

mouse_ON(g)

IF fm=0 THEN StringF(buf,'objects')
IF fm=1 THEN StringF(buf,'lights ')
TextF(380,60,'c_mode :\s',buf)
TextF(380,70,'x=\d y=\d z=\d ',lx,ly,lz)
TextF(380,80,'light int.:\d ',il)

ay:=0
ax:=0
az:=0
vx:=0
sx:=FIXV
ds:=Shr(FIXV,4)
d:=0
ob:=-1
time:=0
WHILE (pause(g)=NIL)

	fa:=0
	d:=0
	i:=inkey(g)
	SELECT i
		/** switch on-off z-buffering **/
		CASE "z"
			zbuf:=zbuf+1
			IF zbuf>1 THEN zbuf:=0
			Gd_cascene(a3d,[CS_ZBUF,zbuf,END_T,NIL]:tag3d)			
		/** switch object-light mode cursor **/
		CASE "l"
			fm:=fm+1
			IF fm>1 THEN fm:=0
			fa:=1
		/** SWITCH ON-OFF POLIGONS BORDER ***/ 
		CASE "b"
			IF cb=1 THEN cb:=-1 ELSE cb:=1
			Gd_changeviewmode(a3d,mode,cb)
		/** SET WIRE FRAME SHADING ***/
		CASE "w"
			mode:=WIREF	
			Gd_changeviewmode(a3d,mode,cb)
		/** SET SOLID SHADING **/
		CASE "s"
			mode:=SOLID	
			Gd_changeviewmode(a3d,mode,cb)
		/** SET FLAT SHADING **/
		CASE "f"
			mode:=FLAT 	
			Gd_changeviewmode(a3d,mode,cb)
		/** SET GORAUD SHADING **/
		CASE "g"
			mode:=GORAUD
			Gd_changeviewmode(a3d,mode,cb)
		/** SET TEXTURE MAP ON **/
		CASE "t"
			mode:=mode+TMAP
			Gd_changeviewmode(a3d,mode,cb)
		CASE CDE
			IF fm=NIL
				ay:=ay+2
			ELSE
				lx:=lx-sl
			ENDIF
			fa:=1
		CASE CSI
			IF fm=NIL
				ay:=ay-2
			ELSE
				lx:=lx+sl
			ENDIF
			fa:=1
		CASE CSU
			IF fm=NIL
				ax:=ax+2
			ELSE
				ly:=ly+sl
			ENDIF
			fa:=1
		CASE CGIU
			IF fm=NIL
				ax:=ax-2
			ELSE
				ly:=ly-sl
			ENDIF
			fa:=1
		CASE "7"
			az:=az+2
			fa:=1
		CASE "1"
			az:=az-2
			fa:=1	
		CASE "i"
			IF fm=NIL
				sx:=sx+ds
			ELSE
				il:=il+(FIXV/2)
				IF il>(14*FIXV) THEN il:=14*FIXV
			ENDIF
			fa:=1
		CASE "o"
			IF fm=NIL
				sx:=sx-ds
				IF sx<=0 THEN sx:=sx+ds ELSE fa:=1
			ELSE
				il:=il-(FIXV/2)
				IF il<0 THEN il:=0
				fa:=1
			ENDIF
		CASE "8"
		/** MOVE THE VIEWER TO THE SCREEN ***/
			IF fm=0	
				d:=40*FIXV
				Gd_moveforward(a3d,d)
			ELSE
				lz:=lz+sl
				fa:=1
			ENDIF
		CASE "2"
		/** MOVE THE VIEWER FROM THE SCREEN ***/
			IF fm=0
				d:=-40*FIXV		
				Gd_moveforward(a3d,d)
			ELSE
				lz:=lz-sl
				fa:=1
			ENDIF
		CASE "4"
		/** CHANGE THE ANGLE OF VIEW TO LEFT **/
			vx:=vx+1
			Gd_viewangle(a3d,0,vx,0)
		CASE "6"
		/** CHANGE THE ANGLE OF VIEW TO RIGHT **/
			vx:=vx-1
			Gd_viewangle(a3d,0,vx,0)
	ENDSELECT	

	np:=mouse(g)
	IF np=1
		px:=mouseX(g)
		py:=mouseY(g)
		TextF(380,20,'oggetto id#   ',ob)
		TextF(380,30,'poligono n#   ',np)
		TextF(380,40,'Ax=\d Ay=\d sx=\d  ',ax,ay,sx)
		TextF(380,50,'\d X=\d y=\d ',mode,px,py)
	/** TEST IF AT POINT(px,py) IS PRESENT A POLIGON AND AN OBJECT **/ 
		ob:=Gd_pickobj(a3d,{np},px,py)
		IF (ob>NIL) AND (ob<>oassi)
			TextF(380,20,'oggetto id#\d ',ob)
			TextF(380,30,'poligono n#\d ',np)
		ENDIF					
	ENDIF
		
	IF fa 
		IF fm=0 THEN StringF(buf,'objects')
		IF fm=1 THEN StringF(buf,'lights ')
		TextF(380,60,'c_mode :\s',buf)
		IF (fm=0) AND (ob>0)
	/** SET THE TRASFORMATION TO THE EVENTUALLY PICKED OBJECT **/
			TextF(380,40,'Ax=\d Ay=\d Az=\d sx=\d  ',ax,ay,az,sx)
			Gd_setobj(a3d,ob)
			Gd_rotateobject(a3d,ax,ay,az)
			Gd_scaleobject(a3d,sx,sx,sx)
		ENDIF
		IF fm 
	/** CHANGE LIGHT POSITION **/
			TextF(380,70,'x=\d y=\d z=\d ',lx,ly,lz)
			Gd_createlightsource(a3d,lx,ly,lz)
	/** CHANGE LIGHT INTENSITY **/
			TextF(380,80,'light int.:\d ',il)
			Gd_ambientlight(a3d,il)
		ENDIF
	ENDIF	
	IF i>=NIL 
		DateStamp(dts)
	/*** RECALC THE VIEWING ***/
		Gd_newview(a3d)
	/*** REDRAW THE VIEWING ***/
/*** funzione maggiormente bisognosa di ottimizzazione ***/
		Gd_paintframe(a3d)
	/*** VISUALIZING THE VIEWING ***/ 
		Gd_switch_rp(a3d)
		DateStamp(dts1)
		time:=(TICKS_PER_SECOND*60*dts1.minute)-(TICKS_PER_SECOND*60*dts.minute)+
		     dts1.tick-dts.tick
	ENDIF
	TextF(380,90,'ticks:\d  ',time)
	coll[0]:=0
	coll[1]:=0
	coll[2]:=0
	coll[3]:=0
	TextF(380,100,'ZBuff:\d Coll:\d',zbuf,Gd_colldetect(a3d,5,coll))
	TextF(380,110,'\d \d \d \d',coll[0],coll[1],coll[2],coll[3])	
ENDWHILE

WriteF('termino.. \n')
/** CLOSE AND DESTROY ALL DEFINITION CREATE BY display3d **/
abort_b:
close_display3d(a3d)
gad_cw(g)
end(g,1)
CloseScreen(s)
abort_b1:
IF aslbase<>NIL THEN CloseLibrary(aslbase)

ENDPROC	
