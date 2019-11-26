@DATABASE "graphics3D.h"
@MASTER   "Ram Disk:graphics3D.h"
@REMARK   This file was created by ADtoHT 2.1 on 21-Gen-99 23:47:50
@REMARK   Do not edit
@REMARK   ADtoHT is © 1993-1995 Christian Stieber

@NODE MAIN "graphics3D.h"

@{"graphics3D.h" LINK File}


@{b}Structures@{ub}

@{"ambient3d" LINK "graphics3D.h/File" 334}  @{"buftmap" LINK "graphics3D.h/File" 230}    @{"dir3d" LINK "graphics3D.h/File" 203}
@{"edge" LINK "graphics3D.h/File" 221}       @{"grafica" LINK "graphics3D.h/File" 409}    @{"line" LINK "graphics3D.h/File" 196}
@{"matrix1x4" LINK "graphics3D.h/File" 158}  @{"matrix4x4" LINK "graphics3D.h/File" 136}  @{"objectnode" LINK "graphics3D.h/File" 271}
@{"pixel" LINK "graphics3D.h/File" 188}      @{"pixl" LINK "graphics3D.h/File" 211}       @{"poltmap" LINK "graphics3D.h/File" 239}
@{"polygon" LINK "graphics3D.h/File" 253}    @{"polytemp" LINK "graphics3D.h/File" 298}   @{"rgbtype" LINK "graphics3D.h/File" 96}
@{"tag3d" LINK "graphics3D.h/File" 105}      @{"vector" LINK "graphics3D.h/File" 168}     @{"vert1" LINK "graphics3D.h/File" 177}
@{"vertex" LINK "graphics3D.h/File" 75}     @{"vtmap" LINK "graphics3D.h/File" 83}      


@{b}Typedefs@{ub}

@{"Sambient3d" LINK "graphics3D.h/File" 403}  @{"SAreaInfo" LINK "graphics3D.h/File" 392}    @{"Sbuftmap" LINK "graphics3D.h/File" 405}
@{"Sdir3d" LINK "graphics3D.h/File" 401}      @{"Sedge" LINK "graphics3D.h/File" 404}        @{"Sgrafica" LINK "graphics3D.h/File" 391}
@{"Smatrix4x4" LINK "graphics3D.h/File" 402}  @{"Sobjectnode" LINK "graphics3D.h/File" 395}  @{"Spolygon" LINK "graphics3D.h/File" 398}
@{"Spolytemp" LINK "graphics3D.h/File" 400}   @{"SRastPort" LINK "graphics3D.h/File" 394}    @{"STmpRas" LINK "graphics3D.h/File" 393}
@{"Svector" LINK "graphics3D.h/File" 399}     @{"Svert1" LINK "graphics3D.h/File" 397}       @{"Svertex" LINK "graphics3D.h/File" 396}


@{b}#defines@{ub}

@{"ATMP" LINK "graphics3D.h/File" 132}       @{"COMPLEMENT" LINK "graphics3D.h/File" 15}  @{"CS_GCOLOR" LINK "graphics3D.h/File" 35}
@{"CS_NPX0" LINK "graphics3D.h/File" 37}    @{"CS_NPY0" LINK "graphics3D.h/File" 38}     @{"CS_PROJET" LINK "graphics3D.h/File" 33}
@{"CS_SBUFF" LINK "graphics3D.h/File" 34}   @{"CS_VDIST" LINK "graphics3D.h/File" 36}    @{"CS_VIEWP" LINK "graphics3D.h/File" 41}
@{"CS_ZBUF" LINK "graphics3D.h/File" 40}    @{"CS_ZOOM" LINK "graphics3D.h/File" 39}     @{"END_T" LINK "graphics3D.h/File" 26}
@{"FIXV" LINK "graphics3D.h/File" 116}       @{"FIXVM" LINK "graphics3D.h/File" 117}       @{"FLAT" LINK "graphics3D.h/File" 21}
@{"FRUSTUM" LINK "graphics3D.h/File" 25}    @{"GORAUD" LINK "graphics3D.h/File" 22}      @{"GP_COL" LINK "graphics3D.h/File" 49}
@{"GP_HRGB" LINK "graphics3D.h/File" 50}    @{"GP_INFO" LINK "graphics3D.h/File" 53}     @{"GP_LRGB" LINK "graphics3D.h/File" 51}
@{"GP_NCOL" LINK "graphics3D.h/File" 47}    @{"GP_NLIV" LINK "graphics3D.h/File" 48}     @{"GP_PALET" LINK "graphics3D.h/File" 52}
@{"GP_RCOL" LINK "graphics3D.h/File" 46}    @{"GP_TRASP" LINK "graphics3D.h/File" 54}    @{"INVERSVID" LINK "graphics3D.h/File" 16}
@{"JAM1" LINK "graphics3D.h/File" 13}       @{"JAM2" LINK "graphics3D.h/File" 14}        @{"LEN_TABC" LINK "graphics3D.h/File" 126}
@{"LTMP" LINK "graphics3D.h/File" 131}       @{"MAXDX" LINK "graphics3D.h/File" 123}       @{"MAXDY" LINK "graphics3D.h/File" 124}
@{"MAXOBJECT" LINK "graphics3D.h/File" 121}  @{"MAXPOINT" LINK "graphics3D.h/File" 120}    @{"MAXVER()" LINK "graphics3D.h/File" 386}
@{"MAXVERT" LINK "graphics3D.h/File" 122}    @{"MFRAC" LINK "graphics3D.h/File" 118}       @{"MINT" LINK "graphics3D.h/File" 119}
@{"MO_STATE" LINK "graphics3D.h/File" 59}   @{"MO_VMODE" LINK "graphics3D.h/File" 60}    @{"MP_2SIDE" LINK "graphics3D.h/File" 67}
@{"MP_ACTIV" LINK "graphics3D.h/File" 71}   @{"MP_COLOR" LINK "graphics3D.h/File" 66}    @{"MP_POLY" LINK "graphics3D.h/File" 65}
@{"MP_TMAP" LINK "graphics3D.h/File" 68}    @{"MP_VTAUTO" LINK "graphics3D.h/File" 70}   @{"MP_VTMAP" LINK "graphics3D.h/File" 69}
@{"PARAL_P" LINK "graphics3D.h/File" 18}    @{"PROSP_P" LINK "graphics3D.h/File" 17}     @{"SFIXV" LINK "graphics3D.h/File" 115}
@{"SMARG" LINK "graphics3D.h/File" 129}      @{"SMARGM" LINK "graphics3D.h/File" 130}      @{"SOLID" LINK "graphics3D.h/File" 20}
@{"TMAP" LINK "graphics3D.h/File" 23}       @{"TRASP" LINK "graphics3D.h/File" 27}       @{"TTMAP" LINK "graphics3D.h/File" 125}
@{"WIREF" LINK "graphics3D.h/File" 19}      @{"ZPLANE" LINK "graphics3D.h/File" 24}      

@ENDNODE
@NODE File "graphics3D.h"
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
#define PROSP_P 0       /* tipo proiezione prospettica */
#define PARAL_P 1       /* tipo proiezione parallela */
#define WIREF   0       /* modo visualizzazione in wire frame */
#define SOLID   2       /* modo visualizzazione in solid */
#define FLAT    1       /* modo visualizzazione in flat shading */
#define GORAUD  3       /* modo visualizzazione in goraud shading */
#define TMAP    0x10    /* modo visualizzazione in texture mapping */
#define ZPLANE  0       /* #1 modo clippaggio oggetti */
#define FRUSTUM 1       /* #2 modo clippaggio oggetti */
#define END_T  0        /* fine array tag3d di dati */
#define TRASP  1000     /* valore registro colore che indica trasparente */

/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_cascene()
*/
#define CS_PROJET 1     /* tipo di proiezione */
#define CS_SBUFF  2     /* attivazione o meno single buffering */
#define CS_GCOLOR 3     /* nuovo colore sfondo box di visualizzazione */
#define CS_VDIST  4     /* nuovo valore distanza da piano di proiezione */
#define CS_NPX0   5     /* nuova posizione X per box di visualizzazione */
#define CS_NPY0   6     /* nuova posizione Y per box di visualizzazione */
#define CS_ZOOM   7     /* nuovo valore per zoom scena */
#define CS_ZBUF   8     /* attivazione o meno z-buffering */
#define CS_VIEWP  9     /* ritorna posizione attuale camera */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_genpalette()
*/
#define GP_RCOL   1     /* set n# colori da riservare per altri usi */
#define GP_NCOL   2     /* set n# colori base da usare */
#define GP_NLIV   3     /* set n# livelli d'intensita' per ogni colore */
#define GP_COL    4     /* set n# colore a cui associare i prossimi GP_HRBG e @{"GP_LRGB" LINK File 51} */
#define GP_HRGB   5     /* definisce i valori RGB massimi per un colore (def.15,15,15) */
#define GP_LRGB   6     /* definisce i valori RGB minimi per un colore (def. 0,0,0) */
#define GP_PALET  7     /* assegna uno specifico registro della palette al colore @{"GP_COL" LINK File 49} */
#define GP_INFO   8     /* restituisce il n# registro della palette del colore @{"GP_COL" LINK File 49} */
#define GP_TRASP  9     /* assegno colore trasparente ad ultimo e lo ignoro per i livelli */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_modobj()
*/
#define MO_STATE  1     /* attiva(1) o disattiva(0) l'oggetto attuale */
#define MO_VMODE  2     /* setta il nuovo viewmode dell'oggetto attuale */
/*
  tipi dati per tag3d.tipo riconosciuti attualmente per
  funzione GD_modpoly()
*/
#define MP_POLY   1     /* set n# poligono su cui far operare le modifiche */
#define MP_COLOR  2     /* modifica il colore del poligono */
#define MP_2SIDE  3     /* setta a 2(1) o 1(0) faccia il poligono */
#define MP_TMAP   4     /* assegna una texture map al poligono */
#define MP_VTMAP  5     /* definisce i vertici della texture map del poligono */
#define MP_VTAUTO 6     /* definisce i vertici automaticamente */
#define MP_ACTIV  7     /* attiva(1) o disattiva(0) il poligono selezionato */

/** STRUTTURE DATI DI USO ESTERNO ED INTERNO **/
/* vertice, usa formato float a virgola fissa ,(val*@{"FIXV" LINK File 116}) */
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
short unsigned int tipo;        /* flag che identifica valore
                                                (se=0 fine array) */
long int val;                   /* valore effettivo */
};

/* !!! STRUTTURE E DEFINIZIONI GLOBALI DI USO ESCLUSIVAMENTE INTERNO !!! */

/** COSTANTI DI USO SOLO INTERNO **/
#define SFIXV   8       /* n# di shift per cal. num. virgola fissa */
#define FIXV    256     /* fattore moltipl. per num. virgola fissa */
#define FIXVM   128     /* meta' di @{"FIXV" LINK File 116} , per effettuare appros.  */
#define MFRAC   @{"FIXV" LINK File 116}    /* maschera per estrarre parte frazionaria */
#define MINT 0xFFFFFFFF /* maschera per estrarre parte intera */
#define MAXPOINT  4     /* massimo numero di punti per poligono */
#define MAXOBJECT 200   /* massimo numero oggetti per mondo 3D (max. 65535)*/
#define MAXVERT   6300  /* massimo numero vertici in un poligono */
#define MAXDX     3000  /* massima larghezza box di visualizzazione */
#define MAXDY     3000  /* massima altezza box di visualizzazione */
#define TTMAP     200   /* n# massimo di texture map definibili per una scena */
#define LEN_TABC 300*4  /* dimensioni tabella colori */

/************ macro solo locali *******/
#define SMARG  16
#define SMARGM 8
#define LTMP 1000
#define ATMP 1000

/* matrice di trasformazione (4x4) */
/* usa formato float a virgola fissa ,(val*@{"FIXV" LINK File 116}) */
struct matrix4x4
{
long int r0c0;
long int r0c1;
long int r0c2;
long int r0c3;
long int r1c0;
long int r1c1;
long int r1c2;
long int r1c3;
long int r2c0;
long int r2c1;
long int r2c2;
long int r2c3;
long int r3c0;
long int r3c1;
long int r3c2;
long int r3c3;
};

/* matrice di trasformazione (1x4) */
/* usa formato float a virgola fissa ,(val*@{"FIXV" LINK File 116}) */
struct matrix1x4
{
long int r0c0;
long int r0c1;
long int r0c2;
long int r0c3;
};

/* vettore */
/* usa formato float a virgola fissa ,(val*@{"FIXV" LINK File 116}) */
struct vector
{
long int x;
long int y;
long int z;
long int w;
};

/* vertice + colore, usa formato float a virgola fissa ,(val*@{"FIXV" LINK File 116}) */
struct vert1
{
long int x;
long int y;
long int z;
short int color;        /* colore vertice in flat shading */
short int npol;         /* n# di volte vertice usato */
};

/* pixel */
/* usa formato intero a 2 bytes */
struct pixel
{
short int x;
short int y;
};

/* struttura per definire una linea */
/* usa due riferimenti a strutture vertice */
struct line
{
@{"struct vertex" LINK File 75} *a;               /* puntatore a st. vertex di partenza */
@{"struct vertex" LINK File 75} *b;               /* puntatore a st. vertex d'arrivo */
};

/* struttura per definire direzione in spazio 3d */
struct dir3d
{
long int angx;
long int angy;
long int angz;
};

/* struttura pixel usata nella versione _CPU per disegnare i poligoni */
struct pixl {
        long int x;
        long int y;
        long int z;
        long int u;     /* (x) */
        long int v;     /* (y) */
        long int color;
        };

/* elementi tabelle scan line nel goraud shading */
struct edge {
        short int x;
        short int color;
        long int z;
        long int u;     /* (x) */
        long int v;     /* (y) */
        };

/* struttura per definire un'area per buffer di una texture map */
struct buftmap
{
unsigned char *chunky;  /* area di memoria per buffer chunky se=0 allora vuota */
long int lung;          /* lunghezza buffer di memoria */
short int larg;         /* larghezza texture map (in pixel) */
short int alt;          /* altezza texture map (in pixel) */
};

/* struttura per definizione texture in un poligono */
struct poltmap
{
short int u1;           /* coord u #1 vertice su texture (in pixel) */
short int v1;           /* coord v #1 vertice su texture (in pixel) */
short int u2;           /* coord u #2 vertice su texture (in pixel) */
short int v2;           /* coord v #2 vertice su texture (in pixel) */
short int u3;           /* coord u #3 vertice su texture (in pixel) */
short int v3;           /* coord v #3 vertice su texture (in pixel) */
short int u4;           /* coord u #4 vertice su texture (in pixel) */
short int v4;           /* coord v #4 vertice su texture (in pixel) */
@{"struct buftmap" LINK File 230} *dtmap;  /* puntatore a struttura con dati texture */
};

/* struttura per definizione di un poligono */
struct polygon
{
char numpoints;
short int color;
short int shade;
char twosided;
char visible;
char clipped;
char active;
@{"struct poltmap" LINK File 239} ptmap;   /* struttura descritrice texture poligono */
long int vertexlist0;   /* puntatore a #1 indice vertici */
long int vertexlist1;   /* puntatore a #2 indice vertici */
long int vertexlist2;   /* puntatore a #3 indice vertici */
long int vertexlist3;   /* puntatore a #4 indice vertici */
char dummy;             /* per far si che la lunghezza sia pari */
};

/* struttura di descrizione di un oggetto */
struct objectnode
{
long int id;            /* identificativo univoco per oggetto */
long int dummy;         /* pad per poter usare name con StringF */
char name[22];
long int numverts;
@{"struct vertex" LINK File 75} *vorig;   /* puntatore a elenco vertici loc. orig. */
@{"struct vertex" LINK File 75} *vlocal;  /* puntatore a elenco vertici locali */
@{"struct vert1" LINK File 177}  *vcamera; /* puntatore a elenco vertici camera */
long int numpolys;
@{"struct polygon" LINK File 253} *polys;  /* puntatore a elenco poligoni */
char shade;             /* metodo di visualiz. (WIRE,@{"SOLID" LINK File 20},@{"FLAT" LINK File 21},@{"GORAUD" LINK File 22}) */
char state;             /* segnala se oggetto da visualizzare */
char clipped;           /* segnala se oggetto clippato interamente*/
char trasf;             /* flag per segnalare eventuale trasf. avv.*/
long int worldposx;     /* coord. x punto d'inserzione oggetto */
long int worldposy;     /* coord. y  "        "          "     */
long int worldposz;     /* coord. z  "        "          "     */
long int xmax;          /* vertici bounding box oggetto */
long int ymax;          /*              "               */
long int zmax;          /*              "               */
long int xmin;          /*              "               */
long int ymin;          /*              "               */
long int zmin;          /*              "               */
};

/* struttura per definizione di un poligono proiettato da visualizzare */
struct polytemp
{
short int       x1;
short int       y1;
short int       x2;
short int       y2;
short int       x3;
short int       y3;
short int       x4;
short int       y4;
short int       x5;
short int       y5;
short int numpoints;
@{"struct poltmap" LINK File 239} *tmap;   /* puntatore a struttura descritrice texture map poligono */
short int     color;
short int     shade;
short int       obj;
long  int      npol;
long  int    svalue;
char          vmode;
char          clp1;
char          clp2;
char          clp3;
char          clp4;
long   int      z1;
long   int      z2;
long   int      z3;
long   int      z4;
char         dummy;
};

/**
        struttura di descrizione generale ambiente, il puntatore ad essa
        va dato come primo parametro al richiamo di ogni funzione
        dall'esterno
**/
struct ambient3d
{
@{"struct grafica" LINK File 409} *graf;           /* valore ritornato da PE_ini_g */
struct Window *win;             /* punt. a finestra usata */
long int half_screen_width;
long int half_screen_height;
long int viewing_distance;
short int gl_triangle_color;
short int minx;
short int miny;
short int maxx;
short int maxy;
short int maxintensity;
long int near_z;
long int far_z;
long int zoom;                  /* num. reale a virgola fissa (val*@{"FIXV" LINK File 116}) */
long int aspect_ratio;          /* num. reale a virgola fissa (val*@{"FIXV" LINK File 116}) */
long int ambient_light;         /* num. reale a virgola fissa (val*@{"FIXV" LINK File 116}) */
long int inv_aspect_ratio;      /* num. reale a virgola fissa (val*@{"FIXV" LINK File 116}) */
long int bord_col;              /* colore bordo poligoni (se <0 no bordo)*/
long int gcolor;                /* colore sfondo scena */
char projection_type;           /* tipo di proiezione (0=pros. 1=paral.) */
char view_mode;                 /* modo vis. (1=flat 0=wire 2=solid 3=goraud) */
char fzbuf;                     /* flag attivazione zbuffer (1=si 0=no) */
char clip_mode;
char agg_all;                   /* flag per forzare aggiornamento scena */
long int dummy;
@{"struct vector" LINK File 168} light_source;     /* puntatore a struttura vector */
long int dummy1;
@{"struct vector" LINK File 168} view_point;       /* puntatore a struttura vector */
@{"struct dir3d" LINK File 203} view_angle;        /* puntatore a struttura dir3d */
@{"struct matrix4x4" LINK File 136} global_view;   /* puntatore a struttura matrix4x4 */
char *temp;                     /* puntatore ad area per uso temporaneo */
long int ltemp;                 /* lunghezza area temp */
long int *iobjects;             /* punt. ad array con indici su objects */
@{"struct objectnode" LINK File 271} *objects;     /* punt. ad array di strutture objectnode */
long int *iwpolys;              /* punt. ad array puntatori su worldpolys */
@{"struct polytemp" LINK File 298} *worldpolys;    /* punt. ad array di strutture polytemp */
long int *sintable;             /* punt. ad array di reali a virg. fissa */
long int *costable;             /* punt. ad array di reali a virg. fissa */
long int total_polys;           /* n# totale poligoni da tracciare */
short int total_objects;        /* n# totale oggetti presenti */
long int max_polys;             /* n# massimo poligoni presenti */
long int old_mpoly;             /* vecchio valore per n# massimo poligoni presenti */
long int attuale;               /* oggetto attualmente selezionato */
long int numero;                /* numero inc. alla creazione di un oggetto*/
long int iterazioni;            /* n# iterazioni per sorting */
char dummyy;
};

/* !!! STRUTTURE E DEFINIZIONI GLOBALI DI USO ESCLUSIVAMENTE INTERNO !!! */

#define MAXVER(vert) (vert*5+30)

/**** dichiarazioni per poter usare sizeof con queste strutture  ****/
/**** probabilmente utile solo se si usa VBCC v0.5 ****/

typedef @{"struct grafica" LINK File 409} Sgrafica;
typedef struct AreaInfo SAreaInfo;
typedef struct TmpRas STmpRas;
typedef struct RastPort SRastPort;
typedef @{"struct objectnode" LINK File 271} Sobjectnode;
typedef @{"struct vertex" LINK File 75} Svertex;
typedef @{"struct vert1" LINK File 177} Svert1;
typedef @{"struct polygon" LINK File 253} Spolygon;
typedef @{"struct vector" LINK File 168} Svector;
typedef @{"struct polytemp" LINK File 298} Spolytemp;
typedef @{"struct dir3d" LINK File 203} Sdir3d;
typedef @{"struct matrix4x4" LINK File 136} Smatrix4x4;
typedef @{"struct ambient3d" LINK File 334} Sambient3d;
typedef @{"struct edge" LINK File 221} Sedge;
typedef @{"struct buftmap" LINK File 230} Sbuftmap;

/********************************************************************/

struct grafica
{
 struct AreaInfo *o_ai; /* valore originale puntatore ad areainfo */
 struct TmpRas *o_tr;   /* valore originale puntatore ad tmprast */
 struct AreaInfo n_ai;  /* nuova areainfo */
 struct TmpRas n_tr;    /* nuova tmpras */
 long int *t_color;     /* puntatore a tabella colori virtuali base */
 @{"struct buftmap" LINK File 230} *a_tmap;/* puntatore ad array di strutture per definizione texture map */
 char *pras;            /* puntatore a area di memoria grafica */
 char *b_af;            /* puntatore a buffer vettori per areafill */
 short int r_color;     /* n# colori da non usare nella gen. palette */
 short int n_level;     /* n# livelli intensita' per ogni colore */
 short int n_color;     /* n# colori base nella palette */
 long int depth;        /* n# colori disponibili nella palette dello schermo usato */
 long int lb_af;        /* dimensioni area precedente */
 struct ViewPort *vpor; /* puntatore a viewport dello schermo della fin.*/
 struct RastPort *rast; /* puntatore a rastport usato dalle routin */
 struct Window *wind;   /* puntatore a finestra su cui agire */
 long int larg;         /* larghezza box in cui lavorera' areafill */
 long int alte;         /* altezza box in cui lavorera' areafill */
 short int clipx;       /* origine x clip box */
 short int clipy;       /* origine y clip box */
 short int clipdx;      /* larghezza clip box */
 short int clipdy;      /* altezza clip box */
 long int *zbuf;        /* puntatore ad area per z-buffering */
 long int lzbuf;        /* lunghezza area precedente */
/** estensioni per double buffering **/
 char   fdouble;        /* flag per attivare double buffer (0=off 1=on)*/
/** campi usati da libreria ottimizzata **/
 char *dbuf;            /* puntatore ad display buffer chunky*/
 long int ldbuf;        /* lunghezza in bytes di area dbuf */
 struct RastPort tmp_rp;/* rastport temporanea */
/******************************************/
 struct RastPort *rast1;/* puntatore a rastport della finestra*/
 struct RastPort *rast2;/* puntatore a rastport nascosto */
/** campi usati da libreria normale **/
 struct RasInfo    *NB_rinfo;
 struct BitMap     *NB_bmap;
 struct Layer_Info *NB_layerinfo;
 struct Layer      *NB_layer;
/*************************************/
};


#endif /* GRAPHICS3D_GRAPHICS3D_H */
@ENDNODE
