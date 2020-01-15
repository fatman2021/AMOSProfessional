/*
**      $VER: graphics3Dm68k.c 10.00 (01.02.98)
**
**      Functions for graphics3D.library on a 68000
**
**	Note: this code is take from lib sources of C Compiler VBCC 
**	      
*/

/** divisione con segno tra numeri a 32bit **/
long _ldivs(long z,long n)
{
    unsigned long uz,un,t=1;long q=0;int s=1;
    if(!n) return(0);
    if(z>=0) uz=z; else {uz=-z;s=-s;}
    if(n>=0) un=n; else {un=-n;s=-s;}
    while(un<=0xffffffff/2&&un<=uz/2){
        t*=2;
        un*=2;
    }
    while(t){
        if(uz>=un){ q+=t; uz-=un;}
        t/=2;
        un/=2;
    }
    if(s>0) return(q); else return(-q);
}
