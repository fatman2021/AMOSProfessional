/*
**      $VER: graphics3Dm.c 10.00 (03.03.98)
**
**      Math functions for graphics3D.library 
**
**	Note: this code is take from math lib sources of C Compiler VBCC 
**	      
*/

/* moltiplicazione fra 2 numeri double float */
 xref _MathIeeeDoubBasBase

 xdef __ieeemuld
__ieeemuld:
 movem.l a6/d2-d3,-(sp)
 move.l  _MathIeeeDoubBasBase,a6
 movem.l 16(sp),d2-d3
 movem.l 24(sp),d0-d1
 jsr     -78(a6)
 movem.l (sp)+,a6/d2-d3
 rts

/* divisione fra 2 numeri double float */
 xref _MathIeeeDoubBasBase

 xdef __ieeedivd
__ieeedivd:
 movem.l a6/d2-d3,-(sp)
 move.l  _MathIeeeDoubBasBase,a6
 movem.l 16(sp),d0-d1
 movem.l 24(sp),d2-d3
 jsr     -84(a6)
 movem.l (sp)+,a6/d2-d3
 rts

/* somma tra 2 numeri double float */
 xref _MathIeeeDoubBasBase

 xdef __ieeeaddd
__ieeeaddd:
 movem.l a6/d2-d3,-(sp)
 move.l  _MathIeeeDoubBasBase,a6
 movem.l 16(sp),d2-d3
 movem.l 24(sp),d0-d1
 jsr     -66(a6)
 movem.l (sp)+,a6/d2-d3
 rts
