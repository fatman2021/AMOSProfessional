*
**      $VER: graphics3Dm.c 10.00 (03.04.98)
**
**      Math functions for graphics3D.library 
**
**	Note: this code is take from math lib sources of C Compiler VBCC 
**	      
*

* moltiplicazione fra 2 numeri double float *
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

* divisione fra 2 numeri double float *
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

* somma tra 2 numeri double float *
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

* sembra equivalente al fix ma non ho capito bene a cosa serve 
* pero' il compilatore lo richiede  
 xref _MathIeeeDoubBasBase

 xdef __ieeefltsld
__ieeefltsld:
 move.l  4(sp),d0
 move.l  a6,-(sp)
 move.l  _MathIeeeDoubBasBase,a6
 jsr     -36(a6)
 move.l  (sp)+,a6
 rts

* restituisce parte intera di un numero double float con segno *
 xref _MathIeeeDoubBasBase

 xdef __ieeefixds
__ieeefixds:
 movem.l 4(sp),d0-d1
 move.l  a6,-(sp)
 move.l  _MathIeeeDoubBasBase,a6
 jsr     -30(a6)
 move.l  (sp)+,a6
 rts

* restituisce parte intera di un numero single float con segno *
 xref _MathIeeeSingBasBase

 xdef __ieeefixls
__ieeefixls:
 move.l  4(sp),d0
 move.l  a6,-(sp)
 move.l  _MathIeeeSingBasBase,a6
 jsr     -30(a6)
 move.l  (sp)+,a6
 rts

* moltiplicazione fra 2 numeri single float *
 xref _MathIeeeSingBasBase

 xdef __ieeemull
__ieeemull:
 move.l a6,-(sp)
 move.l  _MathIeeeSingBasBase,a6
 move.l 8(sp),d1
 move.l 12(sp),d0
 jsr     -78(a6)
 move.l (sp)+,a6
 rts

* sembra equivalente al fix ma non ho capito bene a cosa serve 
* pero' il compilatore lo richiede  
 xref _MathIeeeSingBasBase

 xdef __ieeefltsll
__ieeefltsll:
 move.l  4(sp),d0
 move.l  a6,-(sp)
 move.l  _MathIeeeSingBasBase,a6
 jsr     -36(a6)
 move.l  (sp)+,a6
 rts

* divisione fra 2 numeri single float *
 xref _MathIeeeSingBasBase

 xdef __ieeedivl
__ieeedivl:
 move.l a6,-(sp)
 move.l  _MathIeeeSingBasBase,a6
 move.l 8(sp),d0
 move.l 12(sp),d1
 jsr     -84(a6)
 move.l (sp)+,a6
 rts

* somma tra 2 numeri single float *
 xref _MathIeeeSingBasBase

 xdef __ieeeaddl
__ieeeaddl:
 move.l a6,-(sp)
 move.l  _MathIeeeSingBasBase,a6
 move.l 8(sp),d1
 move.l 12(sp),d0
 jsr     -66(a6)
 move.l (sp)+,a6
 rts
