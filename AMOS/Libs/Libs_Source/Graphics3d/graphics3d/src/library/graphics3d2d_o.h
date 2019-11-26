/*
**      $VER: graphics3D2d_o.h 10.00 (10.05.98)
**
**      Internal 2d optimized functions for graphics3D.library
**
**      (C) Copyright 98 Patrizio Biancalani
**      All Rights Reserved.
*/

extern void drw_t( REG(a0)struct ambient3d *amb3d, REG(a1)short int *buf,
	REG(d0)short int col, REG(d1)short int bordo);

extern void drw_q( REG(a0)struct ambient3d *amb3d, REG(a1)short int *buf,
	REG(d0)short int col, REG(d1)short int bordo);
