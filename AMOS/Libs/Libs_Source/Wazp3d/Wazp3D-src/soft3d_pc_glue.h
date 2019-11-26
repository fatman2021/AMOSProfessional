/* Wazp3D - Alain THELLIER - Paris - FRANCE 							*/
/* Adaptation to AROS from Matthias Rustler							*/
/* Code clean-up and library enhancements from Gunther Nikl					*/
/* LICENSE: GNU General Public License (GNU GPL) for this file				*/

/* This file contain the PC glue functions for the WinUAE's soft3d.dll 			*/
/* SOFT3D_StartUAE() is the PC glue function called from WinUAE	 			*/
/* SOFT3D_Start() is the classic soft3d function just compiled for x86			*/

#include "winuaenative.h"					/* winuaexxx functions*/

void *winuaewnd=NULL;		/* winuae's window		*/
ULONG z3offset;			/* winuae's memory offset 	*/
/*==========================================================================*/
APTR  SOFT3D_StartUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
APTR sc;

	z3offset=a6->z3offset;
	winuaewnd=a6->winuaewnd;
	sc=SOFT3D_Start(AmigaAPTR(a1));
	return(PcAPTR(sc));
}
/*==========================================================================*/
void SOFT3D_ClearImageBufferUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae* a6)
{
	SOFT3D_ClearImageBuffer(AmigaAPTR(a1),d1,d2,d3,d4);
}
/*==========================================================================*/
void SOFT3D_ClearZBufferUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
union uae32 z;

	z.U32=d1;			/* mandatory as d1 store a float but is defined as an ULONG */
	SOFT3D_ClearZBuffer(AmigaAPTR(a1),z.f);
}
/*==========================================================================*/
APTR  SOFT3D_CreateTextureUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
APTR st;
	st=SOFT3D_CreateTexture(AmigaAPTR(a1),AmigaAPTR(a2),d1,d2,d3,d4);
	return(PcAPTR(st));
}
/*==========================================================================*/
UBYTE SOFT3D_DoUpdateUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
UBYTE res;
	res=SOFT3D_DoUpdate(AmigaAPTR(a1));
	return(res);
}
/*==========================================================================*/
void SOFT3D_DrawPrimitiveUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
struct point3D *P=AmigaAPTR(a2);
ULONG Pnb=d1;
ULONG n;

/* Convert the datas stored in struct point3D to PC ordering */
	NLOOP(Pnb)
	{
	reorderPt4(&P->x);
	reorderPt4(&P->y);
	reorderPt4(&P->z);
	reorderPt4(&P->w);
	reorderPt4(&P->u);
	reorderPt4(&P->v);
	P++;
	}

	SOFT3D_DrawPrimitive(AmigaAPTR(a1),AmigaAPTR(a2),d1,d2);
}
/*==========================================================================*/
void SOFT3D_EndUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_End(AmigaAPTR(a1));
}
/*==========================================================================*/
void SOFT3D_FlushUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_Flush(AmigaAPTR(a1));
}
/*==========================================================================*/
void SOFT3D_FogUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
union uae32 FogZmin,FogZmax,FogDensity;

	FogZmin.U32		=d2;	/* mandatory as d2/d3/d4 store a float but is defined as an ULONG */
	FogZmax.U32		=d3;
	FogDensity.U32	=d4;
	SOFT3D_Fog(AmigaAPTR(a1),d1,FogZmin.f,FogZmax.f,FogDensity.f,AmigaAPTR(a2));
}
/*==========================================================================*/
void SOFT3D_FreeTextureUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_FreeTexture(AmigaAPTR(a1),AmigaAPTR(a2));
}
/*==========================================================================*/
void SOFT3D_AllocImageBufferUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_AllocImageBuffer(AmigaAPTR(a1),d1,d2);
}
/*==========================================================================*/
void SOFT3D_SetBackColorUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetBackColor(AmigaAPTR(a1),AmigaAPTR(a2));
}
/*==========================================================================*/
void SOFT3D_SetBitmapUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetBitmap(AmigaAPTR(a1),AmigaAPTR(a2),AmigaAPTR(a3),d1,d2,d3,d4,d5);
}
/*==========================================================================*/
void SOFT3D_SetClippingUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetClipping(AmigaAPTR(a1),d1,d2,d3,d4);
}
/*==========================================================================*/
void SOFT3D_SetCullingUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetCulling(AmigaAPTR(a1),d1);
}
/*==========================================================================*/
void SOFT3D_SetCurrentColorUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetCurrentColor(AmigaAPTR(a1),AmigaAPTR(a2));
}
/*==========================================================================*/
void SOFT3D_SetDrawStatesUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetDrawStates(AmigaAPTR(a1),AmigaAPTR(a2),d1,d2,d3,d4,d5,d6);
}
/*==========================================================================*/
void SOFT3D_SetEnvColorUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetEnvColor(AmigaAPTR(a1),AmigaAPTR(a2));
}
/*==========================================================================*/
void SOFT3D_SetPointSizeUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_SetPointSize(AmigaAPTR(a1),d1);
}
/*==========================================================================*/
APTR SOFT3D_AllocZbufferUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
APTR zb;
	zb=SOFT3D_AllocZbuffer(AmigaAPTR(a1),d1,d2);
	return(PcAPTR(zb));
}
/*==========================================================================*/
void SOFT3D_ReadZSpanUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
double *dz=AmigaAPTR(a2);
ULONG n=d3;
ULONG x;

	SOFT3D_ReadZSpan(AmigaAPTR(a1),d1,d2,d3,AmigaAPTR(a2));
/* Convert all z values to Amiga ordering */
	XLOOP(n)
		reorderPt8(&dz[x]);
}
/*==========================================================================*/
void SOFT3D_WriteZSpanUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
double *dz=AmigaAPTR(a2);
ULONG n=d3;
ULONG x;

/* Convert all z values to PC ordering */
	XLOOP(n)
		reorderPt8(&dz[x]);

	SOFT3D_WriteZSpan(AmigaAPTR(a1),d1,d2,d3,AmigaAPTR(a2),AmigaAPTR(a3));
}
/*==========================================================================*/
void SOFT3D_UpdateTextureUAE(ULONG d1,ULONG d2,ULONG d3,ULONG d4,ULONG d5,ULONG d6,ULONG d7,ULONG a1,ULONG a2,ULONG a3,ULONG a4,ULONG a5,struct winuae *a6)
{
	SOFT3D_UpdateTexture(AmigaAPTR(a1),AmigaAPTR(a2),AmigaAPTR(a3));
}
/*==========================================================================*/





