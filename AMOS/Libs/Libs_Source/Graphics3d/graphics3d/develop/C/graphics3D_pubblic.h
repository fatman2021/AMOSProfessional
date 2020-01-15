/*
**      $VER: graphics3d.h 10.02 (02.03.98) 
** 
**      main include file for graphics3d.library
**
**      (C) Copyright 1997 Patrizio Biancalani
**      All Rights Reserved.
*/

#ifndef GRAPHICS3D_GRAPHICS3D_H
#define GRAPHICS3D_GRAPHICS3D_H

#define JAM1 0
#define JAM2 1
#define COMPLEMENT 2
#define INVERSVID 4
#define PROSP_P 0	/* tipo proiezione prospettica */
#define PARAL_P 1	/* tipo proiezione parallela */
#define WIREF	0	/* modo visualizzazione in wire frame */
#define SOLID	2	/* modo visualizzazione in solid */
#define FLAT 	1	/* modo visualizzazione in flat shading */
#define GORAUD  3	/* modo visualizzazione in goraud shading */
#define TMAP	0x10	/* modo visualizzazione in texture mapping */
#define ZPLANE  0       /* #1 modo clippaggio oggetti */
#define FRUSTUM 1       /* #2 modo clippaggio oggetti */
#define FIXV    256	/* fattore moltipl. per num. virgola fissa */
#define END_T  0	/* fine array tag3d di dati */
#define TRASP  1000	/* valore registro colore che indica trasparente */

/* 
  tipi dati per tag3d.tipo riconosciuti attualmente per 
  funzione GD_cascene()
*/
#define CS_PROJET 1	/* tipo di proiezione */
#define CS_SBUFF  2     /* attivazione o meno single buffering */
#define CS_GCOLOR 3	/* nuovo colore sfondo box di visualizzazione */
#define CS_VDIST  4	/* nuovo valore distanza da piano di proiezione */
#define CS_NPX0	  5     /* nuova posizione X per box di visualizzazione */
#define CS_NPY0   6     /* nuova posizione Y per box di visualizzazione */
#define CS_ZOOM   7	/* nuovo valore per zoom scena */
#define CS_ZBUF	  8	/* attivazione o meno z-buffering */
#define CS_VIEWP  9	/* ritorna posizione attuale camera */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_genpalette()
*/
#define GP_RCOL   1	/* set n# colori da riservare per altri usi */
#define GP_NCOL   2	/* set n# colori base da usare */
#define GP_NLIV	  3	/* set n# livelli d'intensita' per ogni colore */
#define GP_COL	  4	/* set n# colore a cui associare i prossimi GP_HRBG e GP_LRGB */
#define GP_HRGB   5	/* definisce i valori RGB massimi per un colore (def.15,15,15) */
#define GP_LRGB   6	/* definisce i valori RGB minimi per un colore (def. 0,0,0) */
#define GP_PALET  7	/* assegna uno specifico registro della palette al colore GP_COL */
#define GP_INFO	  8	/* restituisce il n# registro della palette del colore GP_COL */
#define GP_TRASP  9 	/* assegno colore trasparente ad ultimo e lo ignoro per i livelli */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_modobj()
*/
#define MO_STATE  1	/* attiva(1) o disattiva(0) l'oggetto attuale */
#define MO_VMODE  2	/* setta il nuovo viewmode dell'oggetto attuale */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_modpoly()
*/
#define MP_POLY   1	/* set n# poligono su cui far operare le modifiche */
#define MP_COLOR  2	/* modifica il colore del poligono */
#define MP_2SIDE  3	/* setta a 2(1) o 1(0) faccia il poligono */
#define MP_TMAP   4	/* assegna una texture map al poligono */
#define MP_VTMAP  5	/* definisce i vertici della texture map del poligono */
#define MP_VTAUTO 6	/* definisce i vertici automaticamente */
#define MP_ACTIV  7	/* attiva(1) o disattiva(0) il poligono selezionato */

/** STRUTTURE DATI DI USO ESTERNO ED INTERNO **/
/* vertice, usa formato float a virgola fissa ,(val*FIXV) */ 
struct vertex
{
long int x;
long int y;
long int z;
};

/* vertice su texture map (valori in pixel intero corto)*/
struct vtmap
{
short int x1;
short int y1;
short int x2;
short int y2;
short int x3;
short int y3;
short int x4;
short int y4;
};

/* struttura per definizione colore */
struct rgbtype
{
short int r;
short int g;
short int b;
};

/* struttura tag3d per definire un array di valori estendibile */
/* analogo alla struttura TagItem dell' Amiga O.S.             */
struct tag3d
{
short unsigned int tipo;	/* flag che identifica valore 
						(se=0 fine array) */
long int val;			/* valore effettivo */
};		 

#endif /* GRAPHICS3D_GRAPHICS3D_H */
