/* Wazp3D PPC  need Warp3D v5 functions */
#define WARP3DV5 1   

#include <utility/tagitem.h>
#include <stdarg.h>
int printf(char *string,...);
/*==========================================================================*/
W3D_Context *        VARARGS68K LibW3D_CreateContextTags(struct Warp3DIFace  *Self, ULONG * error, Tag tag1, ...)
{
static ULONG tag[100];
va_list va;
WORD n=0;


	tag[n] = tag1; va_start (va, tag1);
	do	{
		n++;	tag[n]= va_arg(va, ULONG);

		if(n&1) if (tag[n] == TAG_DONE) break;
		}
	while (n<100);
	va_end(va);

	return W3D_CreateContext(error,(struct TagItem *)&tag[1]);		/*  patch: seems that Wazp3D v5 PPC for AmigaOS4.1 send an empty tag at first */
}
/*==========================================================================*/
W3D_Texture *        VARARGS68K LibW3D_AllocTexObjTags(struct Warp3DIFace  *Self, W3D_Context * context, ULONG * error, Tag tag1, ...)
{
static ULONG tag[100];
va_list va;
WORD n=0;


	tag[n] = tag1; va_start (va, tag1);
	do	{
		n++;	tag[n]= va_arg(va, ULONG);

		if(n&1) if (tag[n] == TAG_DONE) break;
		}
	while (n<100);
	va_end(va);

	return W3D_AllocTexObj(context,error,(struct TagItem *)&tag[1]);		/*  patch: seems that Wazp3D v5 PPC for AmigaOS4.1 send an empty tag at first */
}
/*==========================================================================*/
ULONG                VARARGS68K LibW3D_RequestModeTags(struct Warp3DIFace  *Self, Tag tag1, ...)
{
static ULONG tag[100];
va_list va;
WORD n=0;


	tag[n] = tag1; va_start (va, tag1);
	do	{
		n++;	tag[n]= va_arg(va, ULONG);

		if(n&1) if (tag[n] == TAG_DONE) break;
		}
	while (n<100);
	va_end(va);

	return W3D_RequestMode((struct TagItem *)&tag[1]);		/*  patch: seems that Wazp3D v5 PPC for AmigaOS4.1 send an empty tag at first */
}
/*==========================================================================*/
ULONG                VARARGS68K LibW3D_BestModeIDTags(struct Warp3DIFace  *Self, Tag tag1, ...)
{
static ULONG tag[100];
va_list va;
WORD n=0;


	tag[n] = tag1; va_start (va, tag1);
	do	{
		n++;	tag[n]= va_arg(va, ULONG);

		if(n&1) if (tag[n] == TAG_DONE) break;
		}
	while (n<100);
	va_end(va);

	return W3D_BestModeID((struct TagItem *)&tag[1]);		/*  patch: seems that Wazp3D v5 PPC for AmigaOS4.1 send an empty tag at first */
}
/*==========================================================================*/
#ifdef WARP3DV5
ULONG               VARARGS68K LibW3D_SetTextureBlendTags(struct Warp3DIFace  *Self,W3D_Context * context, Tag tag1, ...)
{
static ULONG tag[100];
va_list va;
WORD n=0;


	tag[n] = tag1; va_start (va, tag1);
	do	{
		n++;	tag[n]= va_arg(va, ULONG);

		if(n&1) if (tag[n] == TAG_DONE) break;
		}
	while (n<100);
	va_end(va);

	return W3D_SetTextureBlend(context,(struct TagItem *)&tag[1]);		/*  patch: seems that Wazp3D v5 PPC for AmigaOS4.1 send an empty tag at first */
}
#endif
/*==========================================================================*/
W3D_Context *        VARARGS68K LibW3D_CreateContext(void *Self, ULONG * error, struct TagItem * CCTags)	{return(W3D_CreateContext(error, CCTags));}	   
void                 VARARGS68K LibW3D_DestroyContext(void *Self, W3D_Context * context)	{       W3D_DestroyContext(context);}	   
ULONG                VARARGS68K LibW3D_GetState(void *Self, W3D_Context * context, ULONG state)	{return(W3D_GetState(context,state));}	   
ULONG                VARARGS68K LibW3D_SetState(void *Self, W3D_Context * context, ULONG state, ULONG action)	{return(W3D_SetState(context,state,action));}	   
ULONG                VARARGS68K LibW3D_CheckDriver(struct Warp3DIFace *Self)	{return(W3D_CheckDriver());}	   
ULONG                VARARGS68K LibW3D_LockHardware(void *Self, W3D_Context * context)	{return(W3D_LockHardware(context));}	   
void                 VARARGS68K LibW3D_UnLockHardware(void *Self, W3D_Context * context)	{       W3D_UnLockHardware(context);}	   
void                 VARARGS68K LibW3D_WaitIdle(void *Self, W3D_Context * context)	{       W3D_WaitIdle(context);}	   
ULONG                VARARGS68K LibW3D_CheckIdle(void *Self, W3D_Context * context)	{return(W3D_CheckIdle(context));}	   
ULONG                VARARGS68K LibW3D_Query(void *Self, W3D_Context * context, ULONG query, ULONG destfmt)	{return(W3D_Query(context,query,destfmt));}	   
ULONG                VARARGS68K LibW3D_GetTexFmtInfo(void *Self, W3D_Context * context, ULONG format, ULONG destfmt)	{return(W3D_GetTexFmtInfo(context,format,destfmt));}	   
W3D_Texture *        VARARGS68K LibW3D_AllocTexObj(void *Self, W3D_Context * context, ULONG * error, struct TagItem * ATOTags)	{return(W3D_AllocTexObj(context,error,ATOTags));}	   
void                 VARARGS68K LibW3D_FreeTexObj(void *Self, W3D_Context * context, W3D_Texture * texture)	{       W3D_FreeTexObj(context,texture);}	   
void                 VARARGS68K LibW3D_ReleaseTexture(void *Self, W3D_Context * context, W3D_Texture * texture)	{       W3D_ReleaseTexture(context,texture);}	   
void                 VARARGS68K LibW3D_FlushTextures(void *Self, W3D_Context * context)	{       W3D_FlushTextures(context);}	   
ULONG                VARARGS68K LibW3D_SetFilter(void *Self, W3D_Context * context, W3D_Texture * texture, ULONG min, ULONG mag)	{return(W3D_SetFilter(context,texture,min,mag));}	   
ULONG                VARARGS68K LibW3D_SetTexEnv(void *Self, W3D_Context * context, W3D_Texture * texture, ULONG envparam, W3D_Color * envcolor)	{return(W3D_SetTexEnv(context,texture,envparam,envcolor));}	   
ULONG                VARARGS68K LibW3D_SetWrapMode(void *Self, W3D_Context * context, W3D_Texture * texture, ULONG mode_s, ULONG mode_t, W3D_Color * bordercolor)	{return(W3D_SetWrapMode(context,texture,mode_s,mode_t,bordercolor));}	   
ULONG                VARARGS68K LibW3D_UpdateTexImage(void *Self, W3D_Context * context, W3D_Texture * texture, void * teximage, int level, ULONG * palette)	{return(W3D_UpdateTexImage(context,texture,teximage,level,palette));}	   
ULONG                VARARGS68K LibW3D_UploadTexture(void *Self, W3D_Context * context, W3D_Texture * texture)	{return(W3D_UploadTexture(context,texture));}	   
ULONG                VARARGS68K LibW3D_DrawLine(void *Self, W3D_Context * context, W3D_Line * line)	{return(W3D_DrawLine(context,line));}	   
ULONG                VARARGS68K LibW3D_DrawPoint(void *Self, W3D_Context * context, W3D_Point * point)	{return(W3D_DrawPoint(context,point));}	   
ULONG                VARARGS68K LibW3D_DrawTriangle(void *Self, W3D_Context * context, W3D_Triangle * triangle)	{return(W3D_DrawTriangle(context,triangle));}	   
ULONG                VARARGS68K LibW3D_DrawTriFan(void *Self, W3D_Context * context, W3D_Triangles * triangles)	{return(W3D_DrawTriFan(context,triangles));}	   
ULONG                VARARGS68K LibW3D_DrawTriStrip(void *Self, W3D_Context * context, W3D_Triangles * triangles)	{return(W3D_DrawTriStrip(context,triangles));}	   
ULONG                VARARGS68K LibW3D_SetAlphaMode(void *Self, W3D_Context * context, ULONG mode, W3D_Float * refval)	{return(W3D_SetAlphaMode(context,mode,refval));}	   
ULONG                VARARGS68K LibW3D_SetBlendMode(void *Self, W3D_Context * context, ULONG srcfunc, ULONG dstfunc)	{return(W3D_SetBlendMode(context,srcfunc,dstfunc));}	   
ULONG                VARARGS68K LibW3D_SetDrawRegion(void *Self, W3D_Context * context, struct BitMap * bm, int yoffset, W3D_Scissor * scissor)	{return(W3D_SetDrawRegion(context,bm,yoffset,scissor));}	   
ULONG                VARARGS68K LibW3D_SetFogParams(void *Self, W3D_Context * context, W3D_Fog * fogparams, ULONG fogmode)	{return(W3D_SetFogParams(context,fogparams,fogmode));}	   
ULONG                VARARGS68K LibW3D_SetColorMask(void *Self, W3D_Context * context, W3D_Bool red, W3D_Bool green, W3D_Bool blue, W3D_Bool alpha)	{return(W3D_SetColorMask(context,red,green,blue,alpha));}	   
ULONG                VARARGS68K LibW3D_SetStencilFunc(void *Self, W3D_Context * context, ULONG func, ULONG refvalue, ULONG mask)	{return(W3D_SetStencilFunc(context,func,refvalue,mask));}	   
ULONG                VARARGS68K LibW3D_AllocZBuffer(void *Self, W3D_Context * context)	{return(W3D_AllocZBuffer(context));}	   
ULONG                VARARGS68K LibW3D_FreeZBuffer(void *Self, W3D_Context * context)	{return(W3D_FreeZBuffer(context));}	   
ULONG                VARARGS68K LibW3D_ClearZBuffer(void *Self, W3D_Context * context, W3D_Double * clearvalue)	{return(W3D_ClearZBuffer(context,clearvalue));}	   
ULONG                VARARGS68K LibW3D_ReadZPixel(void *Self, W3D_Context * context, ULONG x, ULONG y, W3D_Double * z)	{return(W3D_ReadZPixel(context,x,y,z));}	   
ULONG                VARARGS68K LibW3D_ReadZSpan(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, W3D_Double * z)	{return(W3D_ReadZSpan(context,x,y,n,z));}	   
ULONG                VARARGS68K LibW3D_SetZCompareMode(void *Self, W3D_Context * context, ULONG mode)	{return(W3D_SetZCompareMode(context,mode));}	   
ULONG                VARARGS68K LibW3D_AllocStencilBuffer(void *Self, W3D_Context * context)	{return(W3D_AllocStencilBuffer(context));}	   
ULONG                VARARGS68K LibW3D_ClearStencilBuffer(void *Self, W3D_Context * context, ULONG * clearval)	{return(W3D_ClearStencilBuffer(context,clearval));}	   
ULONG                VARARGS68K LibW3D_FillStencilBuffer(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG width, ULONG height, ULONG depth, void * data)	{return(W3D_FillStencilBuffer(context,x,y,width,height,depth,data));}	   
ULONG                VARARGS68K LibW3D_FreeStencilBuffer(void *Self, W3D_Context * context)	{return(W3D_FreeStencilBuffer(context));}	   
ULONG                VARARGS68K LibW3D_ReadStencilPixel(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG * st)	{return(W3D_ReadStencilPixel(context,x,y,st));}	   
ULONG                VARARGS68K LibW3D_ReadStencilSpan(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, ULONG * st)	{return(W3D_ReadStencilSpan(context,x,y,n,st));}	   
ULONG                VARARGS68K LibW3D_SetLogicOp(void *Self, W3D_Context * context, ULONG operation)	{return(W3D_SetLogicOp(context,operation));}	   
ULONG                VARARGS68K LibW3D_Hint(void *Self, W3D_Context * context, ULONG mode, ULONG quality)	{return(W3D_Hint(context,mode,quality));}	   
ULONG                VARARGS68K LibW3D_SetDrawRegionWBM(void *Self, W3D_Context * context, W3D_Bitmap * bitmap, W3D_Scissor * scissor)	{return(W3D_SetDrawRegionWBM(context,bitmap,scissor));}	   
ULONG                VARARGS68K LibW3D_GetDriverState(void *Self, W3D_Context * context)	{return(W3D_GetDriverState(context));}	   
ULONG                VARARGS68K LibW3D_Flush(void *Self, W3D_Context * context)	{return(W3D_Flush(context));}	   
ULONG                VARARGS68K LibW3D_SetPenMask(void *Self, W3D_Context * context, ULONG pen)	{return(W3D_SetPenMask(context,pen));}	   
ULONG                VARARGS68K LibW3D_SetStencilOp(void *Self, W3D_Context * context, ULONG sfail, ULONG dpfail, ULONG dppass)	{return(W3D_SetStencilOp(context,sfail,dpfail,dppass));}	   
ULONG                VARARGS68K LibW3D_SetWriteMask(void *Self, W3D_Context * context, ULONG mask)	{return(W3D_SetWriteMask(context,mask));}	   
ULONG                VARARGS68K LibW3D_WriteStencilPixel(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG st)	{return(W3D_WriteStencilPixel(context,x,y,st));}	    
ULONG                VARARGS68K LibW3D_WriteStencilSpan(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, ULONG * st, UBYTE * mask)	{return(W3D_WriteStencilSpan(context,x,y,n,st,mask));}	   
void                 VARARGS68K LibW3D_WriteZPixel(void *Self, W3D_Context * context, ULONG x, ULONG y, W3D_Double * z)	{       W3D_WriteZPixel(context,x,y,z);}	   
void                 VARARGS68K LibW3D_WriteZSpan(void *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, W3D_Double * z, UBYTE * maks)	{       W3D_WriteZSpan(context,x,y,n,z,maks);}	   
ULONG                VARARGS68K LibW3D_SetCurrentColor(void *Self, W3D_Context * context, W3D_Color * color)	{return(W3D_SetCurrentColor(context,color));}	   
ULONG                VARARGS68K LibW3D_SetCurrentPen(void *Self, W3D_Context * context, ULONG pen)	{return(W3D_SetCurrentPen(context,pen));}	   
ULONG                VARARGS68K LibW3D_UpdateTexSubImage(void *Self, W3D_Context * context, W3D_Texture * texture, void * teximage, ULONG lev, ULONG * palette, W3D_Scissor * scissor, ULONG srcbpr)	{return(W3D_UpdateTexSubImage(context,texture,teximage,lev,palette,scissor,srcbpr));}	   
ULONG                VARARGS68K LibW3D_FreeAllTexObj(void *Self, W3D_Context * context)	{return(W3D_FreeAllTexObj(context));}	   
ULONG                VARARGS68K LibW3D_GetDestFmt(void *Self)	{return(W3D_GetDestFmt());}	   
ULONG                VARARGS68K LibW3D_DrawLineStrip(void *Self, W3D_Context * context, W3D_Lines * lines)	{return(W3D_DrawLineStrip(context,lines));}	   
ULONG                VARARGS68K LibW3D_DrawLineLoop(void *Self, W3D_Context * context, W3D_Lines * lines)	{return(W3D_DrawLineLoop(context,lines));}	   
W3D_Driver **        VARARGS68K LibW3D_GetDrivers(void *Self)	{return(W3D_GetDrivers());}	   
ULONG                VARARGS68K LibW3D_QueryDriver(void *Self, W3D_Driver * driver, ULONG query, ULONG destfmt)	{return(W3D_QueryDriver(driver,query,destfmt));}	   
ULONG                VARARGS68K LibW3D_GetDriverTexFmtInfo(void *Self, W3D_Driver * driver, ULONG format, ULONG destfmt)	{return(W3D_GetDriverTexFmtInfo(driver,format,destfmt));}	   
ULONG                VARARGS68K LibW3D_RequestMode(void *Self, struct TagItem * taglist)	{return(W3D_RequestMode(taglist));}	   
void                 VARARGS68K LibW3D_SetScissor(void *Self, W3D_Context * context, W3D_Scissor * scissor)	{       W3D_SetScissor(context,scissor);}	   
void                 VARARGS68K LibW3D_FlushFrame(void *Self, W3D_Context * context)	{       W3D_FlushFrame(context);}	   
W3D_Driver *         VARARGS68K LibW3D_TestMode(void *Self, ULONG ModeID)	{return(W3D_TestMode(ModeID));}	   
ULONG                VARARGS68K LibW3D_SetChromaTestBounds(void *Self, W3D_Context * context, W3D_Texture * texture, ULONG rgba_lower, ULONG rgba_upper, ULONG mode)	{return(W3D_SetChromaTestBounds(context,texture,rgba_lower,rgba_upper,mode));}	   
ULONG                VARARGS68K LibW3D_ClearDrawRegion(void *Self, W3D_Context * context, ULONG color)	{return(W3D_ClearDrawRegion(context,color));}	   
ULONG                VARARGS68K LibW3D_DrawTriangleV(void *Self, W3D_Context * context, W3D_TriangleV * triangle)	{return(W3D_DrawTriangleV(context,triangle));}	   
ULONG                VARARGS68K LibW3D_DrawTriFanV(void *Self, W3D_Context * context, W3D_TrianglesV * triangles)	{return(W3D_DrawTriFanV(context,triangles));}	   
ULONG                VARARGS68K LibW3D_DrawTriStripV(void *Self, W3D_Context * context, W3D_TrianglesV * triangles)	{return(W3D_DrawTriStripV(context,triangles));}	   
W3D_ScreenMode *     VARARGS68K LibW3D_GetScreenmodeList(void *Self)	{return(W3D_GetScreenmodeList());}	   
void                 VARARGS68K LibW3D_FreeScreenmodeList(void *Self, W3D_ScreenMode * list)	{       W3D_FreeScreenmodeList(list);}	   
ULONG                VARARGS68K LibW3D_BestModeID(void *Self, struct TagItem * tags)	{return(W3D_BestModeID(tags));}	   
ULONG                VARARGS68K LibW3D_VertexPointer(void *Self, W3D_Context * context, void * pointer, int stride, ULONG mode, ULONG flags)	{return(W3D_VertexPointer(context,pointer,stride,mode,flags));}	   
ULONG                VARARGS68K LibW3D_TexCoordPointer(void *Self, W3D_Context * context, void * pointer, int stride, int unit, int off_v, int off_w, ULONG flags)	{return(W3D_TexCoordPointer(context,pointer,stride,unit,off_v,off_w,flags));}	   
ULONG                VARARGS68K LibW3D_ColorPointer(void *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG mode, ULONG flags)	{return(W3D_ColorPointer(context,pointer,stride,format,mode,flags));}	   
ULONG                VARARGS68K LibW3D_BindTexture(void *Self, W3D_Context * context, ULONG tmu, W3D_Texture * texture)	{return(W3D_BindTexture(context,tmu,texture));}	   
ULONG                VARARGS68K LibW3D_DrawArray(void *Self, W3D_Context * context, ULONG primitive, ULONG base, ULONG count)	{return(W3D_DrawArray(context,primitive,base,count));}	   
ULONG                VARARGS68K LibW3D_DrawElements(void *Self, W3D_Context * context, ULONG primitive, ULONG type, ULONG count, void * indices)	{return(W3D_DrawElements(context,primitive,type,count,indices));}	   
void                 VARARGS68K LibW3D_SetFrontFace(void *Self, W3D_Context * context, ULONG direction)	{       W3D_SetFrontFace(context,direction);}	   

#ifdef WARP3DV5
ULONG               VARARGS68K LibW3D_SetTextureBlend(void *Self, W3D_Context * context, struct TagItem * tagList)	{return(W3D_SetTextureBlend(context, tagList));}	   
ULONG                VARARGS68K LibW3D_SecondaryColorPointer(void *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG mode, ULONG flags)	{return(W3D_SecondaryColorPointer(context,pointer,stride,format,mode,flags));}	   
ULONG                VARARGS68K LibW3D_FogCoordPointer(void *Self, W3D_Context * context, void * pointer, int stride, ULONG mode, ULONG flags)	{return(W3D_FogCoordPointer(context,pointer,stride,mode,flags));}	   
ULONG                VARARGS68K LibW3D_InterleavedArray(void *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG flags)	{return(W3D_InterleavedArray(context,pointer,stride,format,flags));}	   
ULONG                VARARGS68K LibW3D_ClearBuffers(void *Self, W3D_Context * context, W3D_Color * color, W3D_Double * depth, ULONG * stencil)	{return(W3D_ClearBuffers(context,color,depth,stencil));}	   
ULONG               VARARGS68K LibW3D_SetParameter(void *Self, W3D_Context * context, ULONG target, void * pattern)	{return(W3D_SetParameter(context,target,pattern));}	   
ULONG               VARARGS68K LibW3D_PinTexture(void *Self, W3D_Context * context, W3D_Texture * texture, BOOL pinning)	{return(W3D_PinTexture(context,texture,pinning));}	   
ULONG                VARARGS68K LibW3D_SetDrawRegionTexture(void *Self, W3D_Context * context, W3D_Texture * texture, W3D_Scissor * scissor)	{return(W3D_SetDrawRegionTexture(context,texture,scissor));}	 
#endif

STATIC CONST APTR main_vectors[] =
{
    LibObtain,
    LibRelease,
    NULL,
    NULL,
    LibW3D_CreateContext,
    LibW3D_CreateContextTags,
    LibW3D_DestroyContext,
    LibW3D_GetState,
    LibW3D_SetState,
    LibW3D_CheckDriver,
    LibW3D_LockHardware,
    LibW3D_UnLockHardware,
    LibW3D_WaitIdle,
    LibW3D_CheckIdle,
    LibW3D_Query,
    LibW3D_GetTexFmtInfo,
    LibW3D_AllocTexObj,
    LibW3D_AllocTexObjTags,
    LibW3D_FreeTexObj,
    LibW3D_ReleaseTexture,
    LibW3D_FlushTextures,
    LibW3D_SetFilter,
    LibW3D_SetTexEnv,
    LibW3D_SetWrapMode,
    LibW3D_UpdateTexImage,
    LibW3D_UploadTexture,
    LibW3D_DrawLine,
    LibW3D_DrawPoint,
    LibW3D_DrawTriangle,
    LibW3D_DrawTriFan,
    LibW3D_DrawTriStrip,
    LibW3D_SetAlphaMode,
    LibW3D_SetBlendMode,
    LibW3D_SetDrawRegion,
    LibW3D_SetFogParams,
    LibW3D_SetColorMask,
    LibW3D_SetStencilFunc,
    LibW3D_AllocZBuffer,
    LibW3D_FreeZBuffer,
    LibW3D_ClearZBuffer,
    LibW3D_ReadZPixel,
    LibW3D_ReadZSpan,
    LibW3D_SetZCompareMode,
    LibW3D_AllocStencilBuffer,
    LibW3D_ClearStencilBuffer,
    LibW3D_FillStencilBuffer,
    LibW3D_FreeStencilBuffer,
    LibW3D_ReadStencilPixel,
    LibW3D_ReadStencilSpan,
    LibW3D_SetLogicOp,
    LibW3D_Hint,
    LibW3D_SetDrawRegionWBM,
    LibW3D_GetDriverState,
    LibW3D_Flush,
    LibW3D_SetPenMask,
    LibW3D_SetStencilOp,
    LibW3D_SetWriteMask,
    LibW3D_WriteStencilPixel,
    LibW3D_WriteStencilSpan,
    LibW3D_WriteZPixel,
    LibW3D_WriteZSpan,
    LibW3D_SetCurrentColor,
    LibW3D_SetCurrentPen,
    LibW3D_UpdateTexSubImage,
    LibW3D_FreeAllTexObj,
    LibW3D_GetDestFmt,
    LibW3D_DrawLineStrip,
    LibW3D_DrawLineLoop,
    LibW3D_GetDrivers,
    LibW3D_QueryDriver,
    LibW3D_GetDriverTexFmtInfo,
    LibW3D_RequestMode,
    LibW3D_RequestModeTags,
    LibW3D_SetScissor,
    LibW3D_FlushFrame,
    LibW3D_TestMode,
    LibW3D_SetChromaTestBounds,
    LibW3D_ClearDrawRegion,
    LibW3D_DrawTriangleV,
    LibW3D_DrawTriFanV,
    LibW3D_DrawTriStripV,
    LibW3D_GetScreenmodeList,
    LibW3D_FreeScreenmodeList,
    LibW3D_BestModeID,
    LibW3D_BestModeIDTags,
    LibW3D_VertexPointer,
    LibW3D_TexCoordPointer,
    LibW3D_ColorPointer,
    LibW3D_BindTexture,
    LibW3D_DrawArray,
    LibW3D_DrawElements,
    LibW3D_SetFrontFace,

#ifdef WARP3DV5
    LibW3D_SetTextureBlend,
    LibW3D_SetTextureBlendTags,
    LibW3D_SecondaryColorPointer,
    LibW3D_FogCoordPointer,
    LibW3D_InterleavedArray,
    LibW3D_ClearBuffers,
    LibW3D_SetParameter,
    LibW3D_PinTexture,
    LibW3D_SetDrawRegionTexture,
#endif

    (APTR)-1
};


