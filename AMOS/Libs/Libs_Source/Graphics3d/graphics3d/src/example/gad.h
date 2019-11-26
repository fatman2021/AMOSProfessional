/****************************************************
 ** Routin per la gestione semplificata di eventi  **
 ** dai gadget , menu', mouse e tastiera, in stile **
 ** 2.0 il tutto scritto per il linguaggio E.      **
 ** (c) 1994,1995 BIANCA HARD&SOFT Vers:1.09       **
 ****************************************************/

MODULE 'graphics','gadtools','libraries/gadtools','intuition/intuition',
'intuition/screens','intuition/gadgetclass','graphics/text',
'keymap','devices/inputevent','intuition','exec/lists','exec/nodes',
'graphics/gfx','graphics/rastport'

/** COSTANTI DI USO INTERNO ED ESTERNO **/

ENUM STRINGA,NUMERO,TASTO,TASTO_MX,TESTO,CK_BOX,POTX,POTY,LIST_VW

CONST F1=$130,F2=$131,F3=$132,F4=$133
CONST F6=$135,F7=$136,F8=$137,F9=$138
CONST F10=$139

CONST CSU=$238,CGIU=$232
CONST CSI=$234,CDE=$236

CONST HLP=$237

/** COSTANTI DI USO ESCLUSIVAMENTE INTERNO **/

CONST N_ADD=20
CONST UGAD=8

/* strutture globali di uso esclusivamente interno */
/*** !! NON USARLE MAI ESTERNAMENTE !!! ***/

OBJECT ugadget
   scr:LONG,        /* puntatore a screen usato per i gadget */
   fpub:LONG,       /* flag che indica se schermo pubblico (0=no 1=si) */
   visual:LONG,     /* puntatore a struttura di info sugli screen */
   menu:LONG,       /* puntatore a struttura menu */
   offy:LONG,       /* offset per evitare bordi e margini */
   pgad:LONG,       /* puntatore a struttura gadget precedente */
   fgad:LONG,       /* puntatore a primo gadget */
   wind:LONG,       /* puntatore a finestra con gadget */
   bmp:LONG,	    /* punt. a bitmap finestra se superbitmap (NULL se no)*/ 
   tattr:LONG,      /* puntatore a font usato */
   ortp:LONG,       /* vecchio valore variabile stdrast */
   class:LONG,      /* classe dell'evento registrato */
   code:LONG,       /* codice evento registrato */
   qual:LONG,       /* qualificatore evento registrato */
   iadd:LONG        /* puntatore a struttura interessata dall'evento */
ENDOBJECT

/* fine. */

/**********************************************
 **********************************************
 *** !!! N O T A !!!                        ***
 *** Il primo parametro di ogni funzione,   ***
 *** (eccetto start_e()) deve essere il     ***
 *** valore >0 ritornato da start_e().      ***
 **********************************************
 **********************************************/

/***********************************************
 ****  FUNZIONI DI CREAZIONE E DISTRUZIONE  ****
 ***********************************************/
/**************************************************
 ** Inizializza tutto il necessario, va lanciato **
 ** come prima cosa .                            **
 *** INPUT :                                     **
 ** Puntatore a screen da usare.                 **
 *** OUTPUT :                                    **
 ** =<0 - Codice errore.                         **
 ** >0  - indirizzo struttura ugadget.           **
 **************************************************/
PROC start_es(scr:PTR TO screen)
   DEF p:LONG
   DEF p1:PTR TO screen
   DEF r:PTR TO LONG
   DEF r1:PTR TO textattr
   DEF ugad:PTR TO ugadget

   r1:=New(SIZEOF textattr)
   IF r1=NIL THEN RETURN 00
   r1:=['topaz.font',8,0,0]:textattr
  
   r:=New((SIZEOF ugadget)+UGAD+10)
   IF r=NIL THEN RETURN 00

   ugad:=r+UGAD

   IF gadtoolsbase=NIL 
      IF (gadtoolsbase:=OpenLibrary('gadtools.library',37))=NIL THEN RETURN -1
   ENDIF

   IF keymapbase=NIL
      IF (keymapbase:=OpenLibrary('keymap.library',37))=NIL THEN RETURN -4
   ENDIF

   ugad.scr:=scr
   ugad.fpub:=0
   IF (p:=GetVisualInfoA(ugad.scr,NIL))=NIL THEN RETURN -3

   ugad.visual:=p
   p1:=ugad.scr
   ugad.offy:=p1.wbortop+Int(p1.rastport+58)-10
   ugad.tattr:=r1
/*
   ugad.tattr:=['topaz.font',8,0,0]:textattr
*/
   ugad.ortp:=NIL /* indico rastport invariato */
   ugad.pgad:=NIL /* indica gadget ancora non definiti */
   ugad.menu:=NIL /* indica menu non ancora definiti */
   ugad.wind:=NIL /* indica finestra non ancora definita */
   ^r:=NIL        /* inizializzo valore puntatore a gadget fittizio */

ENDPROC r

/******************************************************
 ** Esegue l'opposto della precedente, ovvero libera **
 ** tutte le strutture necessarie.                   **
 *** INPUT :                                         **
 **  u - valore restituito da start_e().             **
 **  f - se <>0 chiude anche le librerie aperte.     **
 *** OUTPUT:                                         **
 ** nessuno.                                         **
 ******************************************************/
PROC end(u:PTR TO LONG,f:LONG)
DEF ugad:PTR TO ugadget

   IF u=NIL THEN RETURN

   ugad:=u+UGAD

   IF ugad.tattr THEN Dispose(ugad.tattr)
   IF ugad.visual THEN FreeVisualInfo(ugad.visual)
   IF (ugad.scr AND ugad.fpub) THEN UnlockPubScreen(NIL,ugad.scr)
   IF (f AND gadtoolsbase)
      CloseLibrary(gadtoolsbase)
      gadtoolsbase:=NIL
   ENDIF
   IF (f AND keymapbase)
      CloseLibrary(keymapbase)
      keymapbase:=NIL
   ENDIF
   Dispose(u)
ENDPROC

/*******************************************************
 ** Apro una finestra in cui metto i gadget definiti. **
 *** INPUT :                                          **
 **  u    : valore restituito da start_e().           **
 ** x,y   : posizione origine finestra.               **
 ** dx,dy : dimensione finestra.                      **
 ** titolo: puntatore a stringa titolo.               **
 ** tipo  : tipo di finestra aperta ,                 **
 **        bit 0 - Closegad   ; bit 1 - SizeGadget    **
 **        bit 2 - Dragbar    ; bit 3 - Depthgadget   **
 **        bit 4 - Gimmezerozero                      **
 **        bit 5 - Superbitmap (x double buffering)   **
 *** OUTPUT:                                          **
 ** puntatore a finestra aperta , 00 se rilevato un   **
 ** errore durante l'apertura.                        **
 *******************************************************/
PROC gad_w(u:PTR TO LONG,
           x,y,dx,dy,titolo:PTR TO CHAR,tipo)
   DEF  i ,
     idcmp,
       wfl
   DEF  win:PTR TO window
   DEF ugad:PTR TO ugadget
   DEF sc:PTR TO screen
   DEF bm:PTR TO bitmap
   DEF bm1:PTR TO bitmap
   DEF rp:PTR TO rastport

   IF u=NIL THEN RETURN 0

   ugad:=u+UGAD
   IF ugad.scr=0 THEN RETURN 0

   bm:=0

/* per default la finestra rileva eventi tastiera */
   idcmp:=IDCMP_REFRESHWINDOW OR IDCMP_VANILLAKEY OR IDCMP_RAWKEY

   wfl:=WFLG_SMART_REFRESH OR WFLG_ACTIVATE OR WFLG_REPORTMOUSE

   /** setto idcmp e wfl in base a tipo **/
   IF (tipo AND $1)>0  /* closegadget */
      wfl:=wfl OR WFLG_CLOSEGADGET
      idcmp:=idcmp OR IDCMP_CLOSEWINDOW
   ENDIF

   IF (tipo AND $2)>0  /* sizegadget */
      wfl:=wfl OR WFLG_SIZEGADGET OR WFLG_HASZOOM
      idcmp:=idcmp OR IDCMP_NEWSIZE
   ENDIF

   IF (tipo AND $4)>0  /* dragbar */
      wfl:=wfl OR WFLG_DRAGBAR
   ENDIF

   IF (tipo AND $8)>0  /* depthgadget */
      wfl:=wfl OR WFLG_DEPTHGADGET
   ENDIF

   IF (tipo AND $10)>0 /* gimmezerozero, i bordi non vengono toccati */
      wfl:=wfl OR WFLG_GIMMEZEROZERO
   ENDIF

/*   IF ugad.scr=NIL THEN i:=1 ELSE i:=15 */
/*   win:=OpenW(x,y,dx,dy,idcmp,wfl,titolo,ugad.scr,i,^u) */
   IF ugad.fpub=0
      win:=OpenWindowTagList(NIL,[  WA_LEFT,x,
               WA_TOP,y,
               WA_WIDTH,dx,
               WA_HEIGHT,dy,
               WA_IDCMP,idcmp,
               WA_POINTER,NIL,
               WA_FLAGS,wfl,
               WA_TITLE,titolo,
               WA_CUSTOMSCREEN,ugad.scr,
               WA_GADGETS,^u,
               NIL]) 
   ELSE
      win:=OpenWindowTagList(NIL,[  WA_LEFT,x,
               WA_TOP,y,
               WA_WIDTH,dx,
               WA_HEIGHT,dy,
               WA_IDCMP,idcmp,
               WA_POINTER,NIL,
               WA_FLAGS,wfl,
               WA_TITLE,titolo,
               WA_PUBSCREEN,ugad.scr,
               WA_GADGETS,^u,
               NIL]) 
            
   ENDIF 
   IF win=NIL 
	RETURN 0
   ENDIF

   ugad.bmp:=NIL 

   Gt_RefreshWindow(win,NIL)

   ugad.ortp:=SetStdRast(win.rport)
       /* setto nuovo rastport per le funzioni grafiche E */
   ugad.wind:=win
/*
WriteF('win=\d\n',ugad.wind)
*/
ENDPROC win

/***********************************************
 ** chiudo la finestra e gli eventuali gadget **
 *** INPUT :                                  **
 **  u - valore restituito da start_e().      **
 *** OUTPUT:                                  **
 ** nessuno.                                  **
 ***********************************************/
PROC gad_cw(u:PTR TO LONG)
DEF ugad:PTR TO ugadget
DEF w:PTR TO window
DEF rp:PTR TO rastport

   IF u=NIL THEN RETURN

   ugad:=u+UGAD
   IF ugad.wind<>NIL 
	w:=ugad.wind
	CloseWindow(ugad.wind)   
   ugad.wind:=NIL
   ENDIF
   IF ugad.ortp THEN 
      SetStdRast(ugad.ortp) /* ripristino vecchio stdrast per le funzioni E */
   IF ugad.pgad<>NIL
      FreeGadgets(^u)
      ugad.pgad:=NIL
      ugad.fgad:=NIL
   ENDIF
   IF ugad.menu<>NIL
      FreeMenus(ugad.menu)
      ugad.menu:=NIL
   ENDIF
ENDPROC

/***********************************
 *** FUNZIONI DI GESTIONE EVENTI ***
 ***********************************/
/***********************************************
 ** Attesa sospensiva evento.                 **
 *** INPUT :                                  **
 **  u - valore restituito da start_e().      **
 *** OUTPUT:                                  **
 ** 0 - evento normale.                       **
 ** 1 - chiusura finestra                     **
 ***********************************************/
PROC pause(u:PTR TO LONG)
DEF ugad:PTR TO ugadget,
    imsg:PTR TO intuimessage,
     win:PTR TO window

   IF u=NIL THEN RETURN 1

   ugad:=u+UGAD

   win:=ugad.wind

   WHILE ((imsg:=Gt_GetIMsg(win.userport))=NIL) DO  WaitPort(win.userport)

   ugad.class:=imsg.class
   ugad.code:=imsg.code
   ugad.qual:=imsg.qualifier
   ugad.iadd:=imsg.iaddress

   Gt_ReplyIMsg(imsg)

   IF ugad.class=IDCMP_CLOSEWINDOW THEN RETURN 01
   IF ugad.class=IDCMP_REFRESHWINDOW
      Gt_BeginRefresh(win)
      Gt_EndRefresh(win,TRUE)
   ENDIF

ENDPROC

/*** GESTIONE MOUSE E TASTIERA ***/
/*************************************
 ** Attivo la gestione del mouse .  **
 *** INPUT :                        **
 **  u - valore restituito da       **
 **      start_e().                 **
 *** OUTPUT:                        **
 ** nessuno                         **
 *************************************/
PROC mouse_ON(u:PTR TO LONG)
DEF ugad:PTR TO ugadget,
    win:PTR TO window

   IF u=NIL THEN RETURN

   ugad:=u+UGAD
   win:=ugad.wind
   ModifyIDCMP(win,win.idcmpflags OR IDCMP_MOUSEBUTTONS OR IDCMP_MOUSEMOVE)

ENDPROC
/*************************************
 ** Disattivo la gestione del mouse.**
 *** INPUT :                        **
 **  u - valore restituito da       **
 **      start_e().                 **
 *** OUTPUT:                        **
 ** nessuno                         **
 *************************************/
PROC mouse_OFF(u:PTR TO LONG)
DEF ugad:PTR TO ugadget,
    win:PTR TO window,
    flg:LONG	

   IF u=NIL THEN RETURN

   ugad:=u+UGAD
   win:=ugad.wind
   flg:=Eor(win.idcmpflags,IDCMP_MOUSEBUTTONS)
   flg:=Eor(win.idcmpflags,IDCMP_MOUSEMOVE)
   ModifyIDCMP(win,flg)

ENDPROC
/**********************************************
 ** Restituisco valore tasto premuto.        **
 *** INPUT :                                 **
 ** u  - valore restituito da start.         **
 *** OUTPUT:                                 **
 ** 0<         - tasto non premuto.          **
 ** =>0 e <255 - codice ascii tasto premuto. **
 **  >255      - allora e' o tasto funzione  **
 **              ($130,$131-$139) o tasto    **
 **              cursore.                    **
 **              ($234,$236,$238,$232)       **
 **********************************************/
PROC inkey(u:PTR TO LONG)
DEF ugad:PTR TO ugadget
DEF   ie:inputevent
DEF b[80]:ARRAY 
DEF   ct:LONG
DEF    i:LONG
DEF   es:LONG

   IF u=NIL THEN RETURN -1

   ugad:=u+UGAD
   IF ugad.class = IDCMP_VANILLAKEY THEN RETURN ugad.code
   IF ugad.class <> IDCMP_RAWKEY THEN RETURN -1

/*   ie.ie_class:=IECLASS_RAWKEY */
   ie.class:=IECLASS_RAWKEY
/*   ie.ie_subclass:=0 */
   ie.subclass:=0
/*   ie.ie_code:=ugad.code */
   ie.code:=ugad.code
/*   ie.ie_eventaddress:=ugad.iadd */
   ie.prev1downcode:=ugad.iadd

   ie.qualifier:=ugad.qual

   ct:=MapRawKey(ie,b,75,0)
   IF (ct=-1) OR (ct=0) THEN RETURN -1

   es:=-1

   IF b[0]=$9B          /** test se tipo riconosciuto **/
      IF (ct=2)            /** test se tasti mov. cursore alto basso **/
         i:=b[1]
         SELECT i
            CASE $41       /* su */
               es:=CSU
            CASE $42       /* giu */
               es:=CGIU
	    CASE $44	   /* sinistra */
	       es:=CSI
	    CASE $43	   /* destra */
	       es:=CDE
         ENDSELECT
      ELSEIF (ct=3)
			/** test se tasto HELP **/
	   IF (b[1]=$3F) AND (b[2]=$7E) 
		es:=HLP	
                        /** test se tasti funzione **/
           ELSEIF ((b[1]>$2F) AND (b[1]<$3A)) AND (b[2]=$7E)
         	es:=$100+b[1]
	   ENDIF
      ENDIF
   ENDIF
ENDPROC es

/**********************************************
 ** Restituisco stato tasto sinistro         **
 ** del mouse.                               **
 *** INPUT :                                 **
 ** u  - valore restituito da start.         **
 *** OUTPUT:                                 **
 ** 0< - tasto non premuto.                  **
 ** 01 - tasto premuto.                      **
 ** 02 - tasto rilasciato.                   **
 **********************************************/
PROC mouse(u:PTR TO LONG)
DEF ugad:PTR TO ugadget,
    c,es

   IF u=NIL THEN RETURN -1

   ugad:=u+UGAD
   c:=ugad.code

   IF ugad.class<>IDCMP_MOUSEBUTTONS THEN RETURN -1

   SELECT c
      CASE SELECTUP
         es:=02
      CASE SELECTDOWN
         es:=01
   ENDSELECT

ENDPROC es

/******************************************
 ** Restituisce posizione X del mouse.   **
 *** INPUT :                             **
 ** u  - valore restituito da start_e(). **
 *** OUTPUT:                             **
 ** pos. x mouse.                        **
 ******************************************/
PROC mouseX(u:PTR TO LONG)
DEF ugad:PTR TO ugadget

   IF u=NIL THEN RETURN -1

   ugad:=u+UGAD

ENDPROC MouseX(ugad.wind)

/******************************************
 ** Restituisce posizione Y del mouse.   **
 *** INPUT :                             **
 ** u  - valore restituito da start_e(). **
 *** OUTPUT:                             **
 ** pos. y mouse.                        **
 ******************************************/
PROC mouseY(u:PTR TO LONG)
DEF ugad:PTR TO ugadget

   IF u=NIL THEN RETURN -1

   ugad:=u+UGAD

ENDPROC MouseY(ugad.wind)
/** FINE GESTIONE MOUSE E TASTIERA ***/

/************************************************
 ** restituisco il puntatore al RastPort usato **
 *** INPUT :                                   **
 ** u  - valore restituito da start_e().       **
 *** OUTPUT:                                   **
 ** puntatore alla rastport usata dai gadget.   **
 ** se <=0 valore non valido.                  **
 ************************************************/
PROC rport(u:PTR TO LONG)
DEF ugad:PTR TO ugadget,
    win:PTR TO window

   IF u=NIL THEN RETURN -1

   ugad:=u+UGAD
   win:=ugad.wind

ENDPROC win.rport

/***************************************************
 ** Disegna un rettangolo col look 3D del S.O:2.0 **
 *** INPUT :                                      **
 ** u     - valore restituito da start_e().       **
 ** x,y   - posizione angolo alto a sinistra box. **
 ** dx,dy - dimensioni box.                       **
 ** tipo  - tipo rettangolo,                      **
 **         0=rilievo, 1=incassato.               **
 *** OUTPUT:                                      **
 ** nessuno.                                      **
 ***************************************************/
PROC box3d(u:PTR TO LONG,x,y,dx,dy,tipo)
DEF ugad:PTR TO ugadget,
    win:PTR TO window,
    xx,yy

   IF u=NIL THEN RETURN

   ugad:=u+UGAD
   win:=ugad.wind

   xx:=x
   yy:=y

   IF tipo=0
      DrawBevelBoxA(win.rport,xx,yy,dx,dy,[GT_VISUALINFO,ugad.visual,NIL])
   ELSE
      DrawBevelBoxA(win.rport,xx,yy,dx,dy,
                    [GTBB_RECESSED,1,GT_VISUALINFO,ugad.visual,NIL])
   ENDIF

ENDPROC 
/******  FINE FUNZIONI VARIE  ******/


