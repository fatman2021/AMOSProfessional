#ifndef _WINUAENATIVE_H
#define _WINUAENATIVE_H

/*==========================================================================*/
struct winuae		/*this struct is put in a6 if you call execute native function */
{
APTR			winuaewnd;		/* HWND adress for global UAE window 			*/
unsigned int	changenum;   	/* number to detect screen close/open			*/
unsigned int	z3offset;		/* the offset to add to access Z3 mem from DLL side	*/
int			causeint6;   	/* if set a interrupt Level 6 is generate for 68k side*/
long			(*call68k)();	/* Call: (*uaepar->call68k)(par ....)  			*/
};
/*==========================================================================*/
union uae32{		/* to read/write a 32bits as ULONG or float */
	ULONG U32;
	float f;
};
/*==========================================================================*/
/*
winuae* uaepar;
oldnum=0;
BOOL screenlost(void)
{
	if (oldnum == uaepar->changenum)
		return 0;
	oldnum=uaepar->changenum;
	return 1;
}
*/
/*==========================================================================*/
#define SWAP(x,y) {temp=x;x=y;y=temp;}
/*==========================================================================*/
void reorderPt8(void *pt)
{
register UBYTE *ub=(UBYTE *)pt;
register UBYTE temp;

	SWAP(ub[0],ub[7])
	SWAP(ub[1],ub[6])
	SWAP(ub[2],ub[5])
	SWAP(ub[3],ub[4])
}
/*==========================================================================*/
void reorderPt4(void *pt)
{
register UBYTE *ub=(UBYTE *)pt;
register UBYTE temp;

	SWAP(ub[0],ub[3])
	SWAP(ub[1],ub[2])
}
/*==========================================================================*/
void reorderPt2(void *pt)
{
register UBYTE *ub=(UBYTE *)pt;
register UBYTE temp;

	SWAP(ub[0],ub[1])
}
/*==========================================================================*/
ULONG reorderL(ULONG ul)
{
ULONG localul=ul;

	reorderPt4(&localul);
	return(localul);
}
/*==========================================================================*/
float reorderF(float f)
{
float localf=f;

	reorderPt4(&localf);
	return(localf);
}
/*==========================================================================*/
UWORD reorderW(UWORD uw)
{
UWORD localuw=uw;

	reorderPt2(&localuw);
	return(localuw);
}
/*==========================================================================*/
double reorderD(double d)
{
double locald=d;

	reorderPt8(&locald);
	return(locald);
}
/*==========================================================================*/
#define NativeAPTR(ad)	(APTR)   ad
#define NativeUBYTE(ub)	(UBYTE)  ub
#define NativeUWORD(uw)	(UWORD)  uw
#define NativeULONG(ul)	(ULONG)  ul
#define NativeBYTE(b)	(BYTE)   b
#define NativeWORD(w)	(WORD)   w
#define NativeLONG(l)	(LONG)   l
#define NativeFLOAT(f)	(float)  f
#define NativeDOUBLE(d)	(double) d
/*==========================================================================*/
#define AmigaAPTR(ad)	(APTR)  (((char *)ad ) + a6->z3offset)
#define AmigaUBYTE(ub)	(UBYTE)  ub
#define AmigaUWORD(uw)	(UWORD)  reorderW(uw)
#define AmigaULONG(ul)	(ULONG)  reorderL(ul)
#define AmigaBYTE(b)	(BYTE)   b
#define AmigaWORD(w)	(WORD)   reorderW(w)
#define AmigaLONG(l)	(LONG)   reorderL(l)
#define AmigaFLOAT(f)	(float)  reorderF(f)
#define AmigaDOUBLE(d)	(double) reorderD(d)
/*==========================================================================*/
#define PcAPTR(ad)	(APTR)  (((char *)ad ) - a6->z3offset)
#define PcUBYTE(ub)	(UBYTE)  ub
#define PcUWORD(uw)	(UWORD)  reorderW(uw)
#define PcULONG(ul)	(ULONG)  reorderL(ul)
#define PcBYTE(b)		(BYTE)   b
#define PcWORD(w)		(WORD)   reorderW(w)
#define PcLONG(l)		(LONG)   reorderL(l)
#define PcFLOAT(f)	(float)  reorderF(f)
#define PcDOUBLE(d)	(double) reorderD(d)
#if defined(AMIGA)
/*==========================================================================*/
#define OPENDLL 			100
#define GETNATIVEADRESSE	101
#define CALLNATIVE 		102
#define CLOSEDLL 			103
#define SCREENLOST		104
#define MEMOFFSET			105
/*==========================================================================*/
 /* This macro contain the only ASM instructions used in full source */
#define WINUAENATIVE(rd0,rd1,ra0) register ULONG D0 __asm("d0")=rd0; register ULONG D1 __asm("d1")=rd1; register ULONG A0 __asm("a0")=ra0; asm volatile ("jsr 0xf0ffc0");D0++; return(D0-1);
/*==========================================================================*/
ULONG winuae_opendll( APTR dllname )
{
	WINUAENATIVE(OPENDLL,0,(ULONG)dllname);
}
/*==========================================================================*/
ULONG  winuae_closedll( ULONG dllbase )
{
	WINUAENATIVE(CLOSEDLL,dllbase,0);
}
/*==========================================================================*/
ULONG winuae_getnativeaddr( ULONG dllbase, APTR funcname )
{
	WINUAENATIVE(GETNATIVEADRESSE,dllbase,(ULONG)funcname);
}
/*==========================================================================*/
void winuae_getnativeaddrall( ULONG dllbase, APTR *funcnames, ULONG *funcptrs,ULONG nb )
{
register ULONG D0 __asm("d0")=GETNATIVEADRESSE;
register ULONG D1 __asm("d1")=dllbase;
register ULONG A0 __asm("a0");

register ULONG D2	__asm("d2");
	
	for(D2=0;D2<nb;D2++)
	{
	D0=GETNATIVEADRESSE;
	D1=dllbase;
	A0=(ULONG)funcnames[0];
	asm volatile ("jsr 0xf0ffc0");
	D0++;					/* only to avoid d0 to be otimized away */
	funcptrs[0]= D0-1;		/* only to avoid d0 to be otimized away like that: funcptrs[0]=GETNATIVEADRESSE */
	funcnames++;
	funcptrs++;
	}
}
/*==========================================================================*/
ULONG winuae_callnative12( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7, ULONG v8, ULONG v9, ULONG v10, ULONG v11, ULONG v12 )
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;
register ULONG A1	__asm("a1")=v8;
register ULONG A2	__asm("a2")=v9;
register ULONG A3	__asm("a3")=v10;
register ULONG A4	__asm("a4")=v11;
register ULONG A5	__asm("a5")=v12;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative11( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7, ULONG v8, ULONG v9, ULONG v10, ULONG v11)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;
register ULONG A1	__asm("a1")=v8;
register ULONG A2	__asm("a2")=v9;
register ULONG A3	__asm("a3")=v10;
register ULONG A4	__asm("a4")=v11;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative10( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7, ULONG v8, ULONG v9, ULONG v10)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;
register ULONG A1	__asm("a1")=v8;
register ULONG A2	__asm("a2")=v9;
register ULONG A3	__asm("a3")=v10;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative9( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7, ULONG v8, ULONG v9)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;
register ULONG A1	__asm("a1")=v8;
register ULONG A2	__asm("a2")=v9;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative8( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7, ULONG v8)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;
register ULONG A1	__asm("a1")=v8;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative7( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6, ULONG v7)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;
register ULONG D7	__asm("d7")=v7;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative6( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5, ULONG v6)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;
register ULONG D6	__asm("d6")=v6;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative5( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4, ULONG v5)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;
register ULONG D5	__asm("d5")=v5;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative4( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3, ULONG v4)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;
register ULONG D4	__asm("d4")=v4;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative3( ULONG funcptr, ULONG v1, ULONG v2, ULONG v3)
{
register ULONG D2	__asm("d2")=v2;
register ULONG D3	__asm("d3")=v3;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative2( ULONG funcptr, ULONG v1, ULONG v2)
{
register ULONG D2	__asm("d2")=v2;

	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative1( ULONG funcptr, ULONG v1)
{
	WINUAENATIVE(CALLNATIVE,v1,funcptr);
}
/*==========================================================================*/
ULONG winuae_callnative0( ULONG funcptr)
{
register ULONG D0 __asm("d0")=CALLNATIVE;		/* let d1 unchanged */
register ULONG A0 __asm("a0")=funcptr;

	asm volatile ("jsr 0xf0ffc0");
	D0++; 
	return(D0-1);
}
/*==========================================================================*/
#endif

#endif /*  _WINUAENATIVE_H  */
