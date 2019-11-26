#ifndef _INLINE_SOFT3D_H
#define _INLINE_SOFT3D_H

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif

#ifndef SOFT3D_BASE_NAME
#define SOFT3D_BASE_NAME Soft3DBase
#endif

#define SOFT3D_Start(PrefsWazp3D)						LP1(  0x1e,APTR,SOFT3D_Start,APTR,PrefsWazp3D,a1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_ClearImageBuffer(sc,x,y,large,high)			LP5NR(0x24,SOFT3D_ClearImageBuffer,APTR,sc,a1,UWORD,x,d1,UWORD,y,d2,UWORD,large,d3,UWORD,high,d4, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_ClearZBuffer(sc,fz)						LP2NR(0x2a,SOFT3D_ClearZBuffer,APTR,sc,a1,float,fz,d1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_CreateTexture(sc,pt,large,high,bits,TexMode)		LP6(  0x30,APTR,SOFT3D_CreateTexture,APTR,sc,a1,APTR,pt,a2,UWORD,large,d1,UWORD,high,d2,UWORD,bits,d3,UBYTE,TexMode,d4, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_DoUpdate(sc)							LP1(  0x36,UBYTE,SOFT3D_DoUpdate,APTR,sc,a1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_DrawPrimitive(sc,p,Pnb,primitive)			LP4NR(0x3c,SOFT3D_DrawPrimitive,APTR,sc,a1,APTR,p,a2,ULONG,Pnb,d1,ULONG,primitive,d2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_End(sc)								LP1NR(0x42,SOFT3D_End,APTR,sc,a1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_Fog(sc,FogMode,FogZmin,FogZmax,FogDensity,FogRGBA)	LP6NR(0x48,SOFT3D_Fog,APTR,sc,a1,UBYTE,FogMode,d1,float,FogZmin,d2,float,FogZmax,d3,float,FogDensity,d4,APTR,FogRGBA,a2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_FreeTexture(sc,st)						LP2NR(0x4e,SOFT3D_FreeTexture,APTR,sc,a1,APTR,st,a2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_ReadZSpan(sc,x,y,n,dz)					LP5NR(0x54,SOFT3D_ReadZSpan,APTR,sc,a1,UWORD,x,d1,UWORD,y,d2,ULONG,n,d3,APTR,dz,a2, ,SOFT3D_BASE_NAME)	  
#define SOFT3D_AllocImageBuffer(sc,large,high)				LP3NR(0x5a,SOFT3D_AllocImageBuffer,APTR,sc,a1,UWORD,large,d1,UWORD,high,d2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetBackColor(sc,RGBA)					LP2NR(0x60,SOFT3D_SetBackColor,APTR,sc,a1,APTR,RGBA,a2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetBitmap(sc,bm,bmdata,bmformat,x,y,large,high)	LP8NR(0x66,SOFT3D_SetBitmap,APTR,sc,a1,APTR,bm,a2,APTR,bmdata,a3,ULONG,bmformat,d1,UWORD,x,d2,UWORD,y,d3,UWORD,large,d4,UWORD,high,d5, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetClipping(sc,xmin,xmax,ymin,ymax)			LP5NR(0x6c,SOFT3D_SetClipping,APTR,sc,a1,UWORD,xmin,d1,UWORD,xmax,d2,UWORD,ymin,d3,UWORD,ymax,d4, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetCulling(sc,CullingMode)					LP2NR(0x72,SOFT3D_SetCulling,APTR,sc,a1,UBYTE,CullingMode,d1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetCurrentColor(sc,RGBA)					LP2NR(0x78,SOFT3D_SetCurrentColor,APTR,sc,a1,APTR,RGBA,a2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetDrawStates(sc,st,ZMode,BlendMode,TexEnvMode,UseGouraud,UseFog,PerspMode)	LP8NR(0x7e,SOFT3D_SetDrawStates,APTR,sc,a1,APTR,st,a2,UBYTE,ZMode,d1,UBYTE,BlendMode,d2,UBYTE,TexEnvMode,d3,UBYTE,UseGouraud,d4,UBYTE,UseFog,d5,UBYTE,PerspMode,d6, ,SOFT3D_BASE_NAME);
#define SOFT3D_SetEnvColor(sc,RGBA)						LP2NR(0x84,SOFT3D_SetEnvColor,APTR,sc,a1,APTR,RGBA,a2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_SetPointSize(sc,PointSize)					LP2NR(0x8a,SOFT3D_SetPointSize,APTR,sc,a1,UWORD,PointSize,d1, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_AllocZbuffer(sc,large,high)				LP3(  0x90,APTR,SOFT3D_AllocZbuffer,APTR,sc,a1,UWORD,large,d1,UWORD,high,d2, ,SOFT3D_BASE_NAME)	 
#define SOFT3D_WriteZSpan(sc,x,y,n,dz,mask)				LP6NR(0x96,SOFT3D_WriteZSpan,APTR,sc,a1,UWORD,x,d1,UWORD,y,d2,ULONG,n,d3,APTR,dz,a2,APTR,mask,a3, ,SOFT3D_BASE_NAME) 
#define SOFT3D_Flush(sc)							LP1NR(0x9c,SOFT3D_Flush,APTR,sc,a1, ,SOFT3D_BASE_NAME)
#define SOFT3D_UpdateTexture(sc,st,pt)					LP3NR(0xa2,SOFT3D_UpdateTexture,APTR,sc,a1,APTR,st,a2,APTR,pt,a3, ,SOFT3D_BASE_NAME)	 


#endif /*  _INLINE_SOFT3D_H  */
