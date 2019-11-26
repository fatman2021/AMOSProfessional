/*
**      $VER: graphics3D2d.h 11.00 (10.05.98)
**
**      External 2d functions for graphics3D.library
**
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
*/

extern struct grafica *ini_g(struct Window *win,long int mxv,long int dx,
	long int dy);

extern long int c_zbuf(struct ambient3d *in);

extern void close_g(struct grafica *graf);

extern void switch_rp(struct grafica *graf);

extern long int clipbox(struct grafica *graf,long int minx,
	   long int miny,long int dx,long int dy);
/*
extern void cls_b(struct grafica *graf,long int x0,
	long int y0,long int x1,long int y1);
*/
extern void cls_f(struct ambient3d *amb3d);

extern void over(struct grafica *graf,long int mod);

extern void pixel( struct ambient3d *amb3d, struct polytemp *buf);

extern void line( struct ambient3d *amb3d, struct polytemp *buf);

extern void drw_tg( struct ambient3d *amb3d, struct polytemp *buf, long int bordo);

extern void drw_qg( struct ambient3d *amb3d, struct polytemp *buf, long int bordo);
