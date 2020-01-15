/*
**      $VER: graphics3Df_proto.h 10.01 (01.11.97)
**
**      Functions prototypes for graphics3D.library
**
**      (C) Copyright 97 Patrizio Biancalani
**      All Rights Reserved.
*/

struct ambient3d *GD_display3d(REG(a0)struct Window *win,REG(d0)long int x0,
		REG(d1)long int y0,REG(d2)long int scrw, 
		REG(d3)long int scrh,REG(d4)long int vdist);

long int GD_clipbox(REG(a0)struct ambient3d *in,REG(d0)long int minx,
	   REG(d1)long int miny,REG(d2)long int dx,REG(d3)long int dy);

void GD_cls_b(REG(a0)struct ambient3d *in,REG(d0)long int x0,
	REG(d1)long int y0,REG(d2)long int x1,REG(d3)long int y1);

void GD_over(REG(a0)struct ambient3d *in,REG(d0)long int mod);

void GD_close_display3d(REG(a0)struct ambient3d *in);

long int GD_changeviewmode(REG(a0)struct ambient3d *in,
	REG(d0)long int modo,REG(d1)long int b_col);

long int GD_changeviewmodeobj(REG(a0)struct ambient3d *in,
	REG(d0)long int modo);

long int GD_colldetect(REG(a0)struct ambient3d *in, REG(d0)long int n, REG(a1)long int *buf);

long int GD_genpalette(REG(a0)struct ambient3d *in, REG(a1)struct tag3d *new);

void GD_touchpalette(REG(a0)struct ambient3d *in,REG(d0)long int fr,
	REG(d1)long int lr,REG(a1)struct rgbtype *init_color,
	REG(a2)struct rgbtype *last_color);

void GD_moveforward(REG(a0)struct ambient3d *in,REG(d0)long int dist);

void GD_viewangle(REG(a0)struct ambient3d *in,REG(d0)long int ax,
	REG(d1)long int ay,REG(d2)long int az);

void GD_frustum(REG(a0)struct ambient3d *in,REG(d0)long int near,
	REG(d1)long int far);

void GD_createlightsource(REG(a0)struct ambient3d *in,REG(d0)long int x,
	REG(d1)long int y,REG(d2)long int z);

void GD_ambientlight(REG(a0)struct ambient3d *in,REG(d0)long int inte);

void GD_positioncamera(REG(a0)struct ambient3d *in,REG(d0)long int x,
	REG(d1)long int y,REG(d2)long int z);
 
void GD_aspectratio(REG(a0)struct ambient3d *in,REG(d0)long int ratio);

void GD_clipmode(REG(a0)struct ambient3d *in,REG(d0)long int mode);

long int GD_newobj(REG(a0)struct ambient3d *in,
	REG(a1)char *name,REG(d0)long int pol,REG(d1)long int vert); 

void GD_deleteobject(REG(a0)struct ambient3d *in);

long int GD_addobjvertex(REG(a0)struct ambient3d *in,
	REG(d0)long int num,REG(d1)long int x,REG(d2)long int y,
	REG(d3)long int z);

long int GD_addobjpoly(REG(a0)struct ambient3d *in, 
	REG(d0)long int num,REG(d1)long int p1,REG(d2)long int p2,
	REG(d3)long int p3,REG(d4)long int p4);

long int GD_modobj(REG(a0)struct ambient3d *in, REG(a1)struct tag3d *new);

long int GD_modpoly(REG(a0)struct ambient3d *in, REG(a1)struct tag3d *new);

long int GD_cattpoly(REG(a0)struct ambient3d *in,
	REG(d0)long int num,REG(d1)long int color,REG(d2)long int twoside);

long int GD_setobj(REG(a0)struct ambient3d *in,REG(d0)long int num);

long int GD_getobj(REG(a0)struct ambient3d *in);

void GD_translateobject(REG(a0)struct ambient3d *in,
	REG(d0)long int dx,REG(d1)long int dy,REG(d2)long int dz);

void GD_positionobject(REG(a0)struct ambient3d *in,
	REG(d0)long int x,REG(d1)long int y,REG(d2)long int z);

void GD_scaleobject(REG(a0)struct ambient3d *in,
	REG(d0)long int xscale_fact,REG(d1)long int yscale_fact,
	REG(d2)long int zscale_fact);

void GD_rotateobject(REG(a0)struct ambient3d *in,
	REG(d0)long int angle_x,REG(d1)long int angle_y,
	REG(d2)long int angle_z);

long int GD_pickobj(REG(a0)struct ambient3d *in,REG(a1)long int *np,
	REG(d0)long int x,REG(d1)long int y);

long int GD_newtmap(REG(a0)struct ambient3d *in, REG(d0)short int dx,
	REG(d1)short int dy, REG(a1)unsigned char *buf);

long int GD_newtmapf(REG(a0)struct ambient3d *in, REG(a1)unsigned char *name);

void GD_rmtmap(REG(a0)struct ambient3d *in, REG(a1)struct buftmap *id);

void GD_rgb4(REG(a0)struct ambient3d *in,REG(d0)long int n,
	REG(d1)long int red,REG(d2)long int green,REG(d3)long int blue); 

struct RastPort *GD_paintframe(REG(a0)struct ambient3d *in);

void GD_newview(REG(a0)struct ambient3d *in);

void GD_recalcobj(REG (a0)struct ambient3d *in);

long int GD_cascene( REG(a0)struct ambient3d *in, REG(a1)struct tag3d *new);

long int GD_int2fix( REG(a0)long int *in, REG(a1)long int *out);

long int GD_fix2int( REG(a0)long int *in, REG(a1)long int *out);

long int GD_sfl2fix( REG(a0)float  *in, REG(a1)long int *out);

long int GD_fix2sfl( REG(a0)long int *in, REG(a1)float  *out);

long int GD_dfl2fix( REG(a0)double *in, REG(a1)long int *out);

long int GD_fix2dfl( REG(a0)long int *in, REG(a1)double *out);
