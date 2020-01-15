*
**      $VER: graphics3D.i 10.01 (01.11.97) 
**
**      main include file (assembler) for graphics3D.library
**
**      (C) Copyright 1997 Patrizio Biancalani
**      All Rights Reserved.
*

	include "vinclude:exec/types.i"

* COSTANTI USATE DALLA LIBRERIA *

JAM1 equ 0
JAM2 equ 1
COMPLEMENT equ 2
INVERSVID equ 4
WIREF equ	0	* modo visualizzazione in wire frame 
SOLID equ	2	* modo visualizzazione in solid 
FLAT equ	1	* modo visualizzazione in flat shading
GORAUD equ	3	* modo visualizzazione in goraud shading
TMAP equ	16	* modo visualizzazione in texture mapping
ZPLANE equ 	0       * #1 modo clippaggio oggetti 
FRUSTUM equ	1       * #2 modo clippaggio oggetti
SFIXV equ   	8       * n# di shift per cal. num. virgola fissa 
FIXV equ   	256	* fattore moltipl. per num. virgola fissa
FIXVM equ  	128	* meta' di FIXV , per effettuare appros. 
PROSP_P equ	0	* tipo proiezione prospettica
PARAL_P equ	1	* tipo proiezione parallela 
MFRAC equ	FIXV    * maschera per estrarre parte frazionaria 
END_T equ	0	* fine array tag3d di dati

* tipi dati per tag3d.tipo riconosciuti attualmente per 
* funzione GD_cascene()
CS_PROJET equ	1	* tipo di proiezione 
CS_SBUFF  equ	2     	* attivazione o meno single buffering 
CS_GCOLOR equ	3	* nuovo colore sfondo box di visualizzazione
CS_VDIST  equ	4	* nuovo valore distanza da piano di proiezione
CS_NPX0	  equ	5     	* nuova posizione X per box di visualizzazione
CS_NPY0   equ	6     	* nuova posizione Y per box di visualizzazione
CS_ZOOM   equ	7	* nuovo valore per zoom scena 
CS_ZBUF	  equ   8 	* flag per abilitare disbilitare z-buffering
CS_VIEWP  equ	9	* ritorna posizione attuale camera 

* tipi dati per tag3d.tipo riconosciuti attualmente per
* funzione GD_genpalette()
GP_RCOL   equ	1	* set n# colori da riservare per altri usi 
GP_NCOL   equ	2	* set n# colori base da usare 
GP_NLIV	  equ	3	* set n# livelli d'intensita' per ogni colore 
GP_COL	  equ	4	* set n# colore a cui associare i prossimi GP_HRBG e GP_LRGB 
GP_HRGB   equ	5	* definisce i valori RGB massimi per un colore (def.15,15,15) 
GP_LRGB   equ	6	* definisce i valori RGB minimi per un colore (def. 0,0,0) 
GP_PALET  equ	7	* assegna uno specifico registro della palette al colore GP_COL
GP_INFO	  equ	8	* restituisce il n# registro della palette del colore GP_COL
GP_TRASP  equ	9	* assegno colore trasparente ad ultimo e lo ignoro per i livelli

* tipi dati per tag3d.tipo riconosciuti attualmente per
* funzione GD_modobj()
MO_STATE  equ	1	* attiva(1) o disattiva(0) l'oggetto attuale
MO_VMODE  equ	2	* setta il nuovo viewmode dell'oggetto attuale

* tipi dati per tag3d.tipo riconosciuti attualmente per
* funzione GD_modpoly()
MP_POLY   equ	1	* set n# poligono su cui far operare le modifiche
MP_COLOR  equ	2	* modifica il colore del poligono
MP_2SIDE  equ	3	* setta a 2(1) o 1(0) faccia il poligono
MP_TMAP   equ	4	* assegna una texture map al poligono
MP_VTMAP  equ	5	* definisce i vertici della texture map del poligono
MP_VTAUTO equ	6	* definisce i vertici automaticamente 
MP_ACTIV  equ	7	* attiva(1) o disattiva(0) il poligono selezionato 

** STRUTTURE DATI DI USO ESTERNO ED INTERNO 
* vertice, usa formato float a virgola fissa ,(val*FIXV)
	STRUCTURE vertex,0
	LONG vx_x
	LONG vx_y
	LONG vx_z
	LABEL vx_SIZEOF

* vertice su texture map (valori in pixel intero corto)
	STRUCTURE vtmap,0
	WORD vt_x1
	WORD vt_y1
	WORD vt_x2
	WORD vt_y2
	WORD vt_x3
	WORD vt_y3
	WORD vt_x4
	WORD vt_y4
	LABEL vt_SIZEOF

* struttura per definizione colore
	STRUCTURE rgbtype,0
	WORD rt_r
	WORD rt_g
	WORD rt_b
	LABEL rt_SIZEOF

* struttura tag3d per definire un array di valori estendibile 
* analogo alla struttura TagItem dell' Amiga O.S.            
	STRUCTURE tag3d,0
	UWORD t3_tipo
	LONG t3_val
	LABEL t3_SIZEOF 

