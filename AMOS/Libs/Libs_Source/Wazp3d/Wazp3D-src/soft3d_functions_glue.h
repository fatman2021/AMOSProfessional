/* Wazp3D - Alain THELLIER - Paris - FRANCE 							*/
/* Adaptation to AROS from Matthias Rustler							*/
/* Code clean-up and library enhancements from Gunther Nikl					*/
/* LICENSE: GNU General Public License (GNU GPL) for this file				*/

/* This file contain the glue functions for soft3d.library & soft3d.dll			*/

/* LibSOFT3D_Start is the soft3d.library function called from AmigaOS with parameters in registers    */
/* SOFT3D_Start() is the classic soft3d function just compiled for AmigaOS		*/
/* if WinuAE can open soft3d.dll (ie dllbase!=0) then it will call instead		*/
/* funcptrs[SOFT3D_StartUAE] the entry point to the DLL's glue-function			*/
/* then WinUAE will call SOFT3D_Start() compiled for PC 				      */
/* d0 & a0 are reserved for the UAE native calls.                         		*/
/* We use callnative0 because the parameters are already stored in the registers for the library	*/

#include "soft3d_open_dll.h"
#include "soft3d_protos.h"
#include "winuaenative.h"					/* winuaexxx functions*/

#define SOFT3D_ClearImageBufferUAE 0
#define SOFT3D_ClearZBufferUAE 1
#define SOFT3D_CreateTextureUAE 2
#define SOFT3D_DoUpdateUAE 3
#define SOFT3D_DrawPrimitiveUAE 4
#define SOFT3D_EndUAE 5
#define SOFT3D_FogUAE 6
#define SOFT3D_FreeTextureUAE 7
#define SOFT3D_ReadZSpanUAE 8
#define SOFT3D_AllocImageBufferUAE 9
#define SOFT3D_SetBackColorUAE 10
#define SOFT3D_SetBitmapUAE 11
#define SOFT3D_SetClippingUAE 12
#define SOFT3D_SetCullingUAE 13
#define SOFT3D_SetCurrentColorUAE 14
#define SOFT3D_SetDrawStatesUAE 15
#define SOFT3D_SetEnvColorUAE 16
#define SOFT3D_SetPointSizeUAE 17
#define SOFT3D_AllocZbufferUAE 18
#define SOFT3D_StartUAE 19
#define SOFT3D_WriteZSpanUAE 20
#define SOFT3D_FlushUAE 21
#define SOFT3D_UpdateTextureUAE 22

#define DLLFUNCTION(x) winuae_callnative0(funcptrs[x]) 

ASM(APTR)  LibSOFT3D_CreateTexture(A1(APTR sc),A2(APTR pt),D1(UWORD large),D2(UWORD high),D3(UWORD bits),D4(UBYTE MipMode))
	{if(dllbase) {DLLFUNCTION(SOFT3D_CreateTextureUAE);}	else	{return((APTR)  SOFT3D_CreateTexture(sc,pt,large,high,bits,MipMode));}	}

ASM(APTR)  LibSOFT3D_Start(A1(APTR PrefsWazp3D)) 
	{if(dllbase) {DLLFUNCTION(SOFT3D_StartUAE);}	else	{return((APTR)  SOFT3D_Start(PrefsWazp3D));} }

ASM(UBYTE) LibSOFT3D_DoUpdate(A1(APTR sc))
	{if(dllbase) {DLLFUNCTION(SOFT3D_DoUpdateUAE);}	else	{return((UBYTE) SOFT3D_DoUpdate(sc));}	}

ASM(void)  LibSOFT3D_ClearImageBuffer(A1(APTR sc),D1(UWORD x),D2(UWORD y),D3(UWORD large),D4(UWORD high))
	{if(dllbase) {DLLFUNCTION(SOFT3D_ClearImageBufferUAE);}	else	{SOFT3D_ClearImageBuffer(sc,x,y,large,high);}	}

ASM(void)  LibSOFT3D_ClearZBuffer(A1(APTR sc),D1(float fz))
	{if(dllbase) {DLLFUNCTION(SOFT3D_ClearZBufferUAE);}	else	{SOFT3D_ClearZBuffer(sc,fz);}	}

ASM(void)  LibSOFT3D_DrawPrimitive(A1(APTR sc),A2(APTR p),D1(ULONG Pnb),D2(ULONG primitive))
	{if(dllbase) {DLLFUNCTION(SOFT3D_DrawPrimitiveUAE);}	else	{SOFT3D_DrawPrimitive(sc,p,Pnb,primitive);}	}

ASM(void)  LibSOFT3D_End(A1(APTR sc))
	{if(dllbase) {DLLFUNCTION(SOFT3D_EndUAE);}	else	{SOFT3D_End(sc);}	}

ASM(void)  LibSOFT3D_Fog(A1(APTR sc),D1(UBYTE FogMode),D2(float FogZmin),D3(float FogZmax),D4(float FogDensity),A2(APTR FogRGBA))
	{if(dllbase) {DLLFUNCTION(SOFT3D_FogUAE);}	else	{SOFT3D_Fog(sc,FogMode,FogZmin,FogZmax,FogDensity,FogRGBA);}	}

ASM(void)  LibSOFT3D_FreeTexture(A1(APTR sc),A2(APTR st))
	{if(dllbase) {DLLFUNCTION(SOFT3D_FreeTextureUAE);}	else	{SOFT3D_FreeTexture(sc,st);}	}

ASM(void)  LibSOFT3D_ReadZSpan(A1(APTR sc),D1(UWORD x),D2(UWORD y),D3(ULONG n),A2(APTR dz))
	{if(dllbase) {DLLFUNCTION(SOFT3D_ReadZSpanUAE);}	else	{SOFT3D_ReadZSpan(sc,x,y,n,dz);}	}	

ASM(void)  LibSOFT3D_AllocImageBuffer(A1(APTR sc),D1(UWORD large),D2(UWORD high))
	{if(dllbase) {DLLFUNCTION(SOFT3D_AllocImageBufferUAE);}	else	{SOFT3D_AllocImageBuffer(sc,large,high);}	}

ASM(void)  LibSOFT3D_SetBackColor(A1(APTR sc),A2(APTR RGBA))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetBackColorUAE);}	else	{SOFT3D_SetBackColor(sc,RGBA);}	}

ASM(void)  LibSOFT3D_SetBitmap(A1(APTR sc),A2(APTR bm),A3(APTR bmdata),D1(ULONG bmformat),D2(UWORD x),D3(UWORD y),D4(UWORD large),D5(UWORD high))	
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetBitmapUAE);}	else	{SOFT3D_SetBitmap(sc,bm,bmdata,bmformat,x,y,large,high);} }	

ASM(void)  LibSOFT3D_SetClipping(A1(APTR sc),D1(UWORD xmin),D2(UWORD xmax),D3(UWORD ymin),D4(UWORD ymax))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetClippingUAE);}	else	{SOFT3D_SetClipping(sc,xmin,xmax,ymin,ymax);}	}

ASM(void)  LibSOFT3D_SetCulling(A1(APTR sc),D1(UBYTE CullingMode))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetCullingUAE);}	else	{SOFT3D_SetCulling(sc,CullingMode);}	}

ASM(void)  LibSOFT3D_SetCurrentColor(A1(APTR sc),A2(APTR RGBA))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetCurrentColorUAE);}	else	{SOFT3D_SetCurrentColor(sc,RGBA);}	}

ASM(void)  LibSOFT3D_SetDrawStates(A1(APTR sc),A2(APTR st),D1(UBYTE ZMode),D2(UBYTE BlendMode),D3(UBYTE TexEnvMode),D4(UBYTE UseGouraud),D5(UBYTE UseFog),D6(UBYTE PerspMode))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetDrawStatesUAE);}	else	{SOFT3D_SetDrawStates(sc,st,ZMode,BlendMode,TexEnvMode,UseGouraud,UseFog,PerspMode);}	}

ASM(void)  LibSOFT3D_SetEnvColor(A1(APTR sc),A2(APTR RGBA))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetEnvColorUAE);}	else	{SOFT3D_SetEnvColor(sc,RGBA);}	}

ASM(void)  LibSOFT3D_SetPointSize(A1(APTR sc),D1(UWORD PointSize))
	{if(dllbase) {DLLFUNCTION(SOFT3D_SetPointSizeUAE);}	else	{SOFT3D_SetPointSize(sc,PointSize);}	}

ASM(void)  LibSOFT3D_AllocZbuffer(A1(APTR sc),D1(UWORD large),D2(UWORD high))
	{if(dllbase) {DLLFUNCTION(SOFT3D_AllocZbufferUAE);}	else	{SOFT3D_AllocZbuffer(sc,large,high);}	}

ASM(void)  LibSOFT3D_WriteZSpan(A1(APTR sc),D1(UWORD x),D2(UWORD y),D3(ULONG n),A2(APTR dz),A3(APTR mask))
	{if(dllbase) {DLLFUNCTION(SOFT3D_WriteZSpanUAE);}	else	{SOFT3D_WriteZSpan(sc,x,y,n,dz,mask);}	}

ASM(UBYTE) LibSOFT3D_Flush(A1(APTR sc))
	{if(dllbase) {DLLFUNCTION(SOFT3D_FlushUAE);}	else	{SOFT3D_Flush(sc);}	}

ASM(void)  LibSOFT3D_UpdateTexture(A1(APTR sc),A2(APTR st),A3(APTR pt))
	{if(dllbase) {DLLFUNCTION(SOFT3D_UpdateTextureUAE);}	else	{SOFT3D_UpdateTexture(sc,st,pt);}	}


static const APTR LibVectors[] = {
	(APTR) LibOpen,
	(APTR) LibClose,
	(APTR) LibExpunge,
	(APTR) LibReserved,
	(APTR) LibSOFT3D_Start,   
	(APTR) LibSOFT3D_ClearImageBuffer,   
	(APTR) LibSOFT3D_ClearZBuffer,   
	(APTR) LibSOFT3D_CreateTexture,   
	(APTR) LibSOFT3D_DoUpdate,   
	(APTR) LibSOFT3D_DrawPrimitive,   
	(APTR) LibSOFT3D_End,   
	(APTR) LibSOFT3D_Fog,   
	(APTR) LibSOFT3D_FreeTexture,   
	(APTR) LibSOFT3D_ReadZSpan,   
	(APTR) LibSOFT3D_AllocImageBuffer,   
	(APTR) LibSOFT3D_SetBackColor,   
	(APTR) LibSOFT3D_SetBitmap,   
	(APTR) LibSOFT3D_SetClipping,   
	(APTR) LibSOFT3D_SetCulling,   
	(APTR) LibSOFT3D_SetCurrentColor,   
	(APTR) LibSOFT3D_SetDrawStates,   
	(APTR) LibSOFT3D_SetEnvColor,   
	(APTR) LibSOFT3D_SetPointSize,   
	(APTR) LibSOFT3D_AllocZbuffer,   
	(APTR) LibSOFT3D_WriteZSpan,
	(APTR) LibSOFT3D_Flush,
	(APTR) LibSOFT3D_UpdateTexture,
	(APTR) -1
};
